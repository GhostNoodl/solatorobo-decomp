#include "ov000/Actor.h"

typedef struct {
    u16 id;
    u16 kind;
    u16 args[4];
    s16 unk_0c;
} Spawn0219b5dc;

extern "C" {
BOOL func_020621f8(void);
Actor *func_ov000_0218bf1c(void *mgr, Spawn0219b5dc *desc, s32 a, s32 b, u16 c);

void func_ov000_0219b5dc(u16 amount, s32 a, s32 b) {
    s32 n;
    if (func_020621f8()) {
        return;
    }
    for (n = 0; n < 3; n++) {
        u16 id;
        if (amount >= 50) {
            amount -= 50;
            id = 0x4c3d;
        } else if (amount >= 20) {
            amount -= 20;
            id = 0x4c3c;
        } else if (amount >= 10) {
            amount -= 10;
            id = 0x4c02;
        } else if (amount >= 5) {
            amount -= 5;
            id = 0x4c01;
        } else if (amount >= 1) {
            amount -= 1;
            id = 0x4c00;
        } else {
            return;
        }
        if (id != 0xffff) {
            Spawn0219b5dc desc;
            s32 i;
            Actor *o;
            desc.id = id;
            desc.kind = id & 0xf000;
            for (i = 0; i < 4; i++) {
                desc.args[i] = 0;
            }
            desc.unk_0c = -1;
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, a, b, 0xffff);
            if (o != NULL) {
                o->flags_0 = 1;
            }
        }
    }
}
}
