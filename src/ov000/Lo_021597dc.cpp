#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 unk_00[0x10];
    u16 cont;
    u16 trig;
} LoPad021597dc;

extern "C" {

extern LoPad021597dc *data_02097dc8;

static inline BOOL Lo_Active021597dc(Lo021cb3a8 *self) {
    return LBIT(self, 0xc).b0 ? FALSE : TRUE;
}

static inline BOOL Lo_Settled021597dc(Lo021cb3a8 *self) {
    BOOL r = FALSE;
    if (self->unk_98 == self->unk_a4 && self->unk_b3 == 0) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Lo_Busy021597dc(Lo021cb3a8 *self) {
    return Lo_Settled021597dc(self) ? FALSE : TRUE;
}

// The list input handler of Lo_02155770.cpp without the item and sub-menu cases.
void func_ov000_021597dc(Lo021cb3a8 *self) {
    u16 cont;
    u16 trig;
    if (!Lo_Active021597dc(self)) {
        return;
    }
    if (self->unk_98 == self->unk_a4 && LBIT(self, 0xc).b1) {
        LBIT(self, 0xc).b0 = 1;
        self->unk_04 = 1;
        return;
    }
    if (self->unk_94 == NULL) {
        return;
    }
    if (LBIT(self, 0xc).b2) {
        return;
    }
    if (LBIT(self, 0xc).b1) {
        return;
    }
    cont = data_02097dc8->cont;
    trig = data_02097dc8->trig;
    if (cont == 0) {
        self->unk_b3 = 0;
    }
    self->unk_b2--;
    if (self->unk_9e == 0) {
        if (self->unk_b2 < (self->unk_b3 >> 1)) {
            self->unk_b2 = 0;
            if (cont & 0x40) {
                self->vfunc_ac(1, 0);
            } else if (cont & 0x80) {
                self->vfunc_b4(1, 0);
            } else {
                if (self->unk_9c > self->unk_20 && (self->unk_0c & 0x10000)) {
                    if (cont & 0x200) {
                        self->vfunc_b0(self->unk_20, 0);
                    } else if (cont & 0x100) {
                        self->vfunc_b8(self->unk_20, 0);
                    }
                }
                self->unk_b3 = 0;
            }
        } else if (trig & 3) {
            self->unk_b3 = 0;
        }
    }
    if (Lo_Busy021597dc(self)) {
        return;
    }
    if (trig & 2) {
        if (!self->vfunc_98(NULL)) {
            self->unk_0c |= 2;
        }
        return;
    }
}

}
