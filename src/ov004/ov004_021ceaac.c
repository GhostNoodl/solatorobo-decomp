#include "types.h"

#pragma force_active on

// DSProtect ROM checks: read the same ROM blocks once straight through the card registers
// (command 0xB7) and once through the SDK, and compare the checksums. The first six direct
// reads use pos + chip size, past the end of the ROM.

typedef struct {
    u32 (*ok)(u32 a, u32 b);
    u32 (*fn)(u32 a, u32 b);
    u32 a;
    u32 b;
    u32 result;
    u32 code;
} Ov004Call;

typedef struct {
    u8 unk_00[0x14];
    u8 deviceSize;
} Ov004RomHeader;

// DSProtect keeps a few hardware constants in an enum-typed local. MWCC does not propagate
// enum-typed locals, so 0x04000000 is built as `k << 26` and 0x1ff as `0x204 - k` at run time.
typedef enum {
    DSPROT_KEY_IO = 1,
    DSPROT_KEY_BLOCK = 5
} DSProtKey;

extern s32 OS_GetLockID(void);
extern void OS_ReleaseLockID(u16 id);
extern void CARD_LockRom(u16 id);
extern void CARD_UnlockRom(u16 id);
extern Ov004RomHeader *CARD_GetRomHeader(void);
extern void func_0200d6d4(s32 dma, u32 src, void *dst, u32 len, u32 e, u32 f, u32 g);
extern u32 func_ov004_021cea18(const void *p, u32 n);

#define REG_EXMEMCNT (*(vu16 *)0x04000204)
#define REG_MCCNT0_HI (*(vu8 *)(reg + 0x1a1))
#define REG_MCCNT1 (*(vu32 *)(reg + 0x1a4))
#define REG_MCCMD(i) (io[0x1a8 + (i)])
#define REG_MCDATA (*(vu32 *)(reg + 0x100010))
#define REG_SCFG_A9ROM (*(vu8 *)(reg + 0x4000))

// Reads the 0x200-byte block at `pos` into `dst` with the CPU, saving and restoring the
// command registers in `cmd`. The ROMCTRL value comes from the ROM header copy at the end of
// main memory (0x027ffe60 on NITRO, 0x02fffe60 on TWL).
#define DSPROT_READ_ROM_DIRECT(pos, dst, cmd)                                                       \
    {                                                                                               \
        vu8 *io = (vu8 *)0x04000000;                                                                \
        u32 p;                                                                                      \
        u8 *reg;                                                                                    \
        u32 ctrl;                                                                                   \
        s32 idx;                                                                                    \
        s32 j;                                                                                      \
        DSProtKey k;                                                                                \
        u16 saved;                                                                                  \
        u32 addr;                                                                                   \
        k = DSPROT_KEY_IO;                                                                          \
        p = (pos);                                                                                  \
        saved = REG_EXMEMCNT;                                                                       \
        REG_EXMEMCNT &= ~0x0800;                                                                    \
        reg = (u8 *)(k << 26);                                                                      \
        k = DSPROT_KEY_BLOCK;                                                                       \
        ctrl = (*(u32 *)(((((REG_SCFG_A9ROM & 1) + 5) << 18) - 13) << 5) & ~0x7000000) | 0xa1000000; \
        idx = -(s32)(p & (0x204 - k));                                                              \
        while (REG_MCCNT1 & 0x80000000) {                                                           \
        }                                                                                           \
        REG_MCCNT0_HI = 0x80;                                                                       \
        for (j = 0; j < 8; j++) {                                                                   \
            (cmd)[j] = REG_MCCMD(j);                                                                \
        }                                                                                           \
        for (addr = p + idx; idx < 0x200; addr += 0x200) {                                          \
            REG_MCCMD(0) = 0xb7;                                                                    \
            REG_MCCMD(1) = addr >> 24;                                                              \
            REG_MCCMD(2) = addr >> 16;                                                              \
            REG_MCCMD(3) = addr >> 8;                                                               \
            REG_MCCMD(4) = addr;                                                                    \
            REG_MCCMD(5) = 0;                                                                       \
            REG_MCCMD(6) = 0;                                                                       \
            REG_MCCMD(7) = 0;                                                                       \
            REG_MCCNT1 = ctrl;                                                                      \
            do {                                                                                    \
                if (REG_MCCNT1 & 0x800000) {                                                        \
                    u32 v = REG_MCDATA;                                                             \
                    if (idx >= 0 && idx < 0x200) {                                                  \
                        *(u32 *)((u8 *)(dst) + idx) = v;                                            \
                    }                                                                               \
                    idx += 4;                                                                       \
                }                                                                                   \
            } while (REG_MCCNT1 & 0x80000000);                                                      \
        }                                                                                           \
        for (j = 0; j < 8; j++) {                                                                   \
            REG_MCCMD(j) = (cmd)[j];                                                                \
        }                                                                                           \
        *(vu16 *)(reg + 0x204) = saved;                                                             \
    }

#define DSPROT_FAIL(c, v, ret)                 \
    do {                                       \
        (c)->result = (c)->fn((c)->a, (c)->b); \
        (c)->code = (v);                       \
        return (ret);                          \
    } while (0)

s32 func_ov004_021ceaac(Ov004Call *c) {
    u8 cmd1[8];
    u8 cmd0[8];
    u32 crc[16];
    u32 buf[0x80];
    u32 off = 0x7000;
    u32 base = 0x1000;
    s32 i;
    Ov004RomHeader *hdr;
    u16 lock;
    u32 *dst;
    lock = OS_GetLockID();
    CARD_LockRom(lock);
    dst = buf;
    for (i = 0; i < 6; i++) {
        hdr = CARD_GetRomHeader();
        DSPROT_READ_ROM_DIRECT(base + (1 << (hdr->deviceSize + 17)), dst, cmd0);
        crc[i] = func_ov004_021cea18(buf, 0x200);
        func_0200d6d4(-1, base + off, buf, 0x200, 0, 0, 0);
        crc[i + 6] = func_ov004_021cea18(buf, 0x200);
        if (i < 3) {
            base += 0x200;
        } else if (i == 3) {
            off = 0;
            base = 0xa000;
        } else if (i > 3) {
            base = 0x9000 + i * 0x1000;
        }
    }
    base += 0x1e000;
    for (; i < 8; i++) {
        DSPROT_READ_ROM_DIRECT(base, dst, cmd1);
        crc[i + 6] = func_ov004_021cea18(buf, 0x200);
        func_0200d6d4(-1, base, buf, 0x200, 0, 0, 0);
        crc[i + 8] = func_ov004_021cea18(buf, 0x200);
        base += 0x1000;
    }
    CARD_UnlockRom(lock);
    OS_ReleaseLockID(lock);
    for (i = 0; i < 0x80; i++) {
        buf[i] = i;
    }
    for (i = 0; i < 3; i++) {
        if (crc[6] != crc[i]) {
            DSPROT_FAIL(c, 0xef, 0xbb45);
        }
    }
    if (crc[6] == crc[7] && crc[6] == crc[8]) {
        DSPROT_FAIL(c, 0xad, 0xbb45);
    }
    if (crc[4] != crc[10] || crc[5] != crc[11]) {
        DSPROT_FAIL(c, 0xde, 0xbb45);
    }
    if (crc[12] != crc[14] || crc[13] != crc[15]) {
        DSPROT_FAIL(c, 0xde, 0xbb45);
    }
    return 0xb3cf;
}

s32 func_ov004_021ceff8(Ov004Call *c) {
    u8 cmd1[8];
    u8 cmd0[8];
    u32 crc[16];
    u32 buf[0x80];
    u32 off = 0x7000;
    u32 base = 0x1000;
    s32 i;
    Ov004RomHeader *hdr;
    u16 lock;
    u32 *dst;
    lock = OS_GetLockID();
    CARD_LockRom(lock);
    dst = buf;
    for (i = 0; i < 6; i++) {
        hdr = CARD_GetRomHeader();
        DSPROT_READ_ROM_DIRECT(base + (1 << (hdr->deviceSize + 17)), dst, cmd0);
        crc[i] = func_ov004_021cea18(buf, 0x200);
        func_0200d6d4(-1, base + off, buf, 0x200, 0, 0, 0);
        crc[i + 6] = func_ov004_021cea18(buf, 0x200);
        if (i < 3) {
            base += 0x200;
        } else if (i == 3) {
            off = 0;
            base = 0xa000;
        } else if (i > 3) {
            base = 0x9000 + i * 0x1000;
        }
    }
    base += 0x1e000;
    for (; i < 8; i++) {
        DSPROT_READ_ROM_DIRECT(base, dst, cmd1);
        crc[i + 6] = func_ov004_021cea18(buf, 0x200);
        func_0200d6d4(-1, base, buf, 0x200, 0, 0, 0);
        crc[i + 8] = func_ov004_021cea18(buf, 0x200);
        base += 0x1000;
    }
    CARD_UnlockRom(lock);
    OS_ReleaseLockID(lock);
    for (i = 0; i < 0x80; i++) {
        buf[i] = i;
    }
    for (i = 0; i < 3; i++) {
        if (crc[6] != crc[i]) {
            DSPROT_FAIL(c, 0xbe, 0xa883);
        }
    }
    if (crc[6] == crc[7] && crc[6] == crc[8]) {
        DSPROT_FAIL(c, 0xde, 0xa883);
    }
    if (crc[4] != crc[10] || crc[5] != crc[11]) {
        DSPROT_FAIL(c, 0xad, 0xa883);
    }
    if (crc[12] != crc[14] || crc[13] != crc[15]) {
        DSPROT_FAIL(c, 0xad, 0xa883);
    }
    return 0xaf81;
}

#pragma force_active reset
