#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e4ec0(void) {
    return TRUE;
}

BOOL func_ov002_021e4ec8(void) {
    return TRUE;
}

BOOL func_ov002_021e4ed0(void) {
    return TRUE;
}

BOOL func_ov002_021e4ed8(void) {
    return FALSE;
}

void func_ov002_021e4ee0(void) {
}

void *func_ov002_021e4ee4(void *self, s32 kind, s32 min) {
    s32 limit;
    void *best = NULL;
    limit = FIELD(data_ov002_021f0f98[1], 0xd0, s32);
    int i;
    for (i = 0; i < 8; i++) {
        u8 *item = ((u8 **)((u8 *)self + 0x28))[i];
        if (item != NULL && kind == FIELD(item, 0x4, s32)) {
            s32 v = FIELD(item, 0x18, s32);
            if (min + 1 <= v && v <= limit) {
                best = item;
                limit = v;
            }
        }
    }
    return best;
}

void func_ov002_021e4f48(void *self) {
    u8 *ctx;
    s32 v;
    if (FIELD(self, 0x8, u32) & 0x10) {
        v = FIELD(self, 0xae, u8);
    } else {
        v = -1;
    }
    if (v != 0) {
        return;
    }
    ctx = (u8 *)data_ov002_021f0f98[0];
    if (FIELD(ctx, 0x1ec, s32) != 0) {
        func_ov002_021e4fac(self);
    }
    if (FIELD(ctx, 0x1f0, Bits8).b1) {
        self = FIELD(self, 0xb4, void *);
        MI_Copy36B(NNS_G3dGlbGetInvV(), (u8 *)self + 0x28);
    }
}

}
