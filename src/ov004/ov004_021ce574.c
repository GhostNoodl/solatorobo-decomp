#include "types.h"

#pragma force_active on

// DSProtect runtime: decrypts protected code in place and flushes the caches.

extern u8 DSProt_BSS[];
extern u8 *data_ov004_021cf7a0;
extern u8 *data_ov004_021cf7b8;

typedef s32 (*Ov004CryptFn)(const u32 *key, u8 *src, u8 *dst, u32 len);

static inline void FlushCaches(void) {
    asm {
        mov ip, #0
        mov r1, #0
    @set:
        mov r0, #0
    @line:
        orr r2, r1, r0
        mcr p15, 0, ip, c7, c10, 4
        mcr p15, 0, r2, c7, c14, 2
        add r0, r0, #0x20
        cmp r0, #0x400
        blt @line
        add r1, r1, #0x40000000
        cmp r1, #0
        bne @set
        mov r0, #0
        mcr p15, 0, r0, c7, c5, 0
        mcr p15, 0, ip, c7, c10, 4
    }
}

void func_ov004_021ce574(u32 *t) {
    u32 *h = t - 3;
    h[2] = 0;
    h[1] = 0;
    h[0] = 0;
    do {
        u32 *p, *end, key;
        key = 0x976afcc;
        p = (u32 *)(t[0] - 0x3200);
        end = p + ((t[1] - (u32)DSProt_BSS - 0x3200) >> 2);
        for (; p < end; p++) {
            u32 v = *p ^ key;
            *p = v;
            key ^= v - (v >> 8);
        }
        t[1] = 0;
        t[0] = 0;
        t += 2;
    } while (*t != 0);
    FlushCaches();
}

u8 *func_ov004_021ce634(u32 key, u8 *enc, u32 len) {
    u32 k[4];
    len -= (u32)DSProt_BSS + 0x3200;
    k[0] = key ^ len;
    k[1] = len ^ ((key << 8) | (key >> 24));
    k[2] = len ^ ((key << 16) | (key >> 16));
    k[3] = len ^ ((key << 24) | (key >> 8));
    enc -= 0x3200;
    ((Ov004CryptFn)(data_ov004_021cf7b8 - 0x3200))(k, enc, enc, len);
    FlushCaches();
    return enc;
}

u32 func_ov004_021ce6f8(u32 key, u32 arg, u32 len) {
    u32 k[4];
    u8 *p = (u8 *)arg;
    len -= (u32)DSProt_BSS + 0x3200;
    k[0] = key ^ len;
    k[1] = len ^ ((key << 8) | (key >> 24));
    k[2] = len ^ ((key << 16) | (key >> 16));
    k[3] = len ^ ((key << 24) | (key >> 8));
    p -= 0x3200;
    ((Ov004CryptFn)(data_ov004_021cf7a0 - 0x3200))(k, p, p, len);
    FlushCaches();
    return key + ((u32)DSProt_BSS + 0x3200 + (arg & 0xffff));
}

#pragma force_active reset
