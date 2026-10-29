#include "card_private.h"
#include "nitro/os_alarm.h"

#pragma force_active on


#define REG_MI_MCCNT0_E_MASK   0x8000
#define REG_MI_MCCNT0_I_MASK   0x4000
#define REG_MI_MCCNT0_SEL_MASK 0x2000

#define REG_MI_MCCNT1_START_MASK 0x80000000
#define REG_MI_MCCNT1_RDY_MASK   0x00800000
#define REG_MI_MCCNT1_PC_MASK    0x07000000
#define REG_MI_MCCNT1_CT_MASK    0x08000000
#define REG_MI_MCCNT1_RESB_MASK  0x20000000
#define REG_MI_MCCNT1_WR_MASK    0x40000000
#define REG_MI_MCCNT1_SCR_MASK   0x00002000

#define CARD_ROM_HEADER_CTRL (*(u32 *)0x02fffae0)
#define CARD_ROM_STATUS_FLAG (*(u32 *)0x02fffc00)

extern BOOL data_0208ec30;
void OS_Sleep(u32 msec);

typedef struct {
    u8 unk_00[0x1b4];
    u32 unk_0_4 : 5;
    u32 game_card_nitro_mode : 1;
    u32 unk_6_7 : 2;
    u32 game_card_on : 1;
    u32 unk_9_31 : 23;
} CARDRomHeaderTWLFlags;

static inline u32 CARDi_SwapEndian32(u32 v) {
    return ((v & 0xff000000) >> 24) | ((v & 0x00ff0000) >> 8) | ((v & 0x0000ff00) << 8) | (v << 24);
}

void func_0200d0dc(u32 command1, u32 command2) {
    u32 hi = (command2 >> 8) | (command1 << 24);
    u32 lo = command2 << 24;

    while (reg_MI_MCCNT1 & REG_MI_MCCNT1_START_MASK) {
    }

    reg_MI_MCCNT0 = (u16)((reg_MI_MCCNT0 & ~REG_MI_MCCNT0_SEL_MASK) | (REG_MI_MCCNT0_E_MASK | REG_MI_MCCNT0_I_MASK));
    reg_MI_MCCMD0 = CARDi_SwapEndian32(hi);
    reg_MI_MCCMD1 = CARDi_SwapEndian32(lo);
}

BOOL func_0200d15c(void) {
    const CARDRomHeaderTWLFlags *header = (const CARDRomHeaderTWLFlags *)CARD_GetOwnRomHeaderTWL();

    if (OS_IsRunOnTwl() && OS_GetBootType() != 1 && header->game_card_nitro_mode && !header->game_card_on) {
        return TRUE;
    }
    return FALSE;
}

void func_0200d1a8(u32 src) {
    u32 cmd = 0xb7;

    if (func_0200d15c()) {
        cmd = 0x00;
    }
    func_0200d0dc(cmd, src);
    reg_MI_MCCNT1 = (CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK | 0x01000000);
}

u32 func_0200d1f0(void) {
    u32 cmd = 0xb8;

    if (func_0200d15c()) {
        cmd = 0x90;
    }
    func_0200d0dc(cmd, 0);
    reg_MI_MCCNT1 = ((CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK | REG_MI_MCCNT1_PC_MASK)) & ~0x1fff;
    while (!(reg_MI_MCCNT1 & REG_MI_MCCNT1_RDY_MASK)) {
    }
    return reg_MI_MCD1;
}

u32 func_0200d258(void) {
    if (!(CARD_ROM_STATUS_FLAG & 0x20000000)) {
        return 0x20;
    }
    func_0200d0dc(0xd6, 0);
    reg_MI_MCCNT1 = ((CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK | REG_MI_MCCNT1_PC_MASK)) & ~0x1fff;
    while (!(reg_MI_MCCNT1 & REG_MI_MCCNT1_RDY_MASK)) {
    }
    return reg_MI_MCD1;
}

void func_0200d320(void);

void func_0200d2c0(u32 mask) {
    if (func_0200d258() & mask) {
        func_0200d320();
        if (!(func_0200d258() & 0x20)) {
            do {
                if (data_0208ec30 && OS_IsAlarmAvailable()) {
                    OS_Sleep(1);
                }
            } while (!(func_0200d258() & 0x20));
        }
    }
}

void func_0200d320(void) {
    func_0200d0dc(0xb5, 0);
    reg_MI_MCCNT1 = ((CARD_ROM_HEADER_CTRL & ~REG_MI_MCCNT1_PC_MASK) | (REG_MI_MCCNT1_START_MASK | REG_MI_MCCNT1_RESB_MASK)) & ~0x1fff;
    while (reg_MI_MCCNT1 & REG_MI_MCCNT1_START_MASK) {
    }
}


#ifdef NONMATCHING
// func_0200d36c (CARDi_ReadRomWithCPU, round raB): 5 / 0 (raw / register-masked), honest.
// The SDK read loop at -O2 with opt_propagation off (only that pair gives the target's loop shape and
// the `mov r0, r7; cmp r8, r0` page-size compare). Left: the read loop's word/data/ctrl are coloured
// r1/r0/r2 here and r3/r1/r2 in the ROM, so in the ROM some node coloured r0 interferes with all three
// across the loop, although nothing in the target's loop reads r0 (rounds svA, frC, raB).
// This file's .text ends at 0x0200d36c, so the function belongs here once it matches.
// Round raC: the word loop as an inline (any parameter/return form) shifts word/ctrl/data to r2/r1/r0
// (8 / 0), one register below the ROM's r3/r2/r1; without the cacheBuffer local it is still 5 / 0.
// Round raE: the page-read argument in a named local (5), a u32 *dst for ptr (15), word++ in the
// subscript (8), const data (5).
#define CARD_ROM_PAGE_SIZE 0x200

typedef struct CARDiRomCache {
    BOOL flush_dc;  // 0x00
    u32 cache_page; // 0x04
} CARDiRomCache;

extern CARDiRomCache data_0208af30;
extern u32 data_0208e600[CARD_ROM_PAGE_SIZE / sizeof(u32)];
void func_0200da28(u32 id);

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
int func_0200d36c(void *userdata, void *buffer, u32 offset, u32 length) {
    int retval = (int)length;
    u32 cachedPage = data_0208af30.cache_page;
    u8 *const cacheBuffer = (u8 *)data_0208e600;

    (void)userdata;
    while (length > 0) {
        u8 *ptr = (u8 *)buffer;
        u32 n = CARD_ROM_PAGE_SIZE;
        const u32 pos = offset & ~(CARD_ROM_PAGE_SIZE - 1);

        if (pos == cachedPage) {
            ptr = cacheBuffer;
        } else {
            if (pos != offset || ((u32)buffer & 3) != 0 || length < n) {
                cachedPage = pos;
                ptr = cacheBuffer;
            }
            func_0200d1a8(pos);
            {
                u32 word = 0;
                for (;;) {
                    const u32 ctrl = reg_MI_MCCNT1;
                    if ((ctrl & REG_MI_MCCNT1_RDY_MASK) != 0) {
                        u32 data = reg_MI_MCD1;
                        if (word < CARD_ROM_PAGE_SIZE / sizeof(u32)) {
                            ((u32 *)ptr)[word] = data;
                            word++;
                        }
                    }
                    if ((ctrl & REG_MI_MCCNT1_START_MASK) == 0) {
                        break;
                    }
                }
            }
        }
        if (ptr == cacheBuffer) {
            const u32 mod = offset - pos;
            n = (length <= CARD_ROM_PAGE_SIZE - mod) ? length : (CARD_ROM_PAGE_SIZE - mod);
            MI_CpuCopy8(cacheBuffer + mod, buffer, n);
        }
        buffer = (u8 *)buffer + n;
        offset += n;
        length -= n;
    }
    func_0200da28(func_0200d1f0());
    data_0208af30.cache_page = cachedPage;
    return retval;
}
#pragma pop
#endif
