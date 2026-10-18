#include "types.h"

typedef struct {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
} SpawnDesc0219b400;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Flags0219b400;

typedef struct {
    u8 pad_00[0x16];
    Flags0219b400 unk_16;
    u8 pad_17[0x85];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
} Actor0219b400;

extern "C" {
extern void *data_ov000_021ccd64;
BOOL func_020621f8(void);
s32 func_02040498(s32 max);
Actor0219b400 *func_ov000_0218bf1c(void *mgr, SpawnDesc0219b400 *d, void *pos, void *rot, u16 a);
void func_ov000_0218d46c(Actor0219b400 *o, u16 id, s32 m);

static inline void Spawn0219b400_Init(SpawnDesc0219b400 *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline void Actor0219b400_SetPos(Actor0219b400 *o, s32 x, s32 y, s32 z) {
    o->unk_9c = x;
    o->unk_a0 = y;
    o->unk_a4 = z;
}

void func_ov000_0219b400(u16 *ids, u8 *rates, s32 n, void *pos, void *rot, u8 check) {
    s32 w[32];
    SpawnDesc0219b400 desc;
    s32 total;
    s32 i;
    s32 r;
    s32 acc;
    s32 j;
    Actor0219b400 *o;

    if (check && func_020621f8()) {
        return;
    }
    if (n > 32) {
        n = 32;
    }
    total = 0;
    for (i = 0; i < n; i++) {
        w[i] = 0;
        if (ids[i] != 0xffff && rates[i] != 0) {
            w[i] = rates[i];
            total += rates[i];
        }
    }
    if (total == 0) {
        return;
    }
    if (total < 100) {
        total = 100;
    }
    r = func_02040498(total - 1);
    acc = 0;
    for (j = 0; j < n; j++) {
        if (w[j] != 0) {
            s32 lo = acc;
            acc += w[j];
            if (r >= lo && r < acc) {
                Spawn0219b400_Init(&desc, ids[j]);
                o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, pos, rot, 0xffff);
                if (o != NULL) {
                    o->unk_16.b0 = 1;
                    if (desc.flags != 0x5000) {
                        return;
                    }
                    Actor0219b400_SetPos(o, func_02040498(0x7b) + 0xf6, func_02040498(0xb8) + 0x2e1, 0);
                    o->unk_a8 = 0x52;
                    func_ov000_0218d46c(o, 0xffff, 4);
                    return;
                }
            }
        }
    }
}
}
