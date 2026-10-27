// DSProtect: RC4 key schedule. The identity permutation is written a word at a time.
// Built at a lower optimization level than the game code.
#pragma optimization_level 3

#include "ov004/dsprot.h"

#pragma force_active on

void func_ov004_021cd750(Rc4 *c, const u8 *key, u32 len) {
    s32 k;
    u32 j;
    u32 *p;
    u32 *e;
    u32 v;
    u8 t;
    u32 n = 0;
    u8 u;
    c->x = 0xaa;
    v = 0x03020100;
    j = 0;
    c->i = 0;
    c->j = 0;
    p = (u32 *)c->s;
    e = (u32 *)(c->s + 0x100);
    do {
        *p++ = v;
        v += 0x04040404;
    } while (p < e);
    for (k = 0xff; k >= 0; k--) {
        t = c->s[k];
        j = (t + (j + key[n])) & 0xff;
        u = c->s[j];
        c->s[j] = t;
        c->s[k] = u;
        n++;
        if (n >= len) {
            n = 0;
        }
    }
}

#pragma force_active reset
