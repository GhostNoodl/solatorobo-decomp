#include "ov000/LoCommon.h"

typedef struct {
    u8 unk_00[0x10];
    u16 cont;
    u16 trig;
} LoPad021597dc;

extern "C" {

extern LoPad021597dc *data_02097dc8;

static inline BOOL Lo_Active021597dc(VObj *self) {
    return LBIT(self, 0xc).b0 ? FALSE : TRUE;
}

static inline BOOL Lo_Settled021597dc(VObj *self) {
    BOOL r = FALSE;
    if (LFLD(void *, self, 0x98) == LFLD(void *, self, 0xa4) && LFLD(s8, self, 0xb3) == 0) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Lo_Busy021597dc(VObj *self) {
    return Lo_Settled021597dc(self) ? FALSE : TRUE;
}

// The list input handler of Lo_02155770.cpp without the item and sub-menu cases.
void func_ov000_021597dc(VObj *self) {
    u16 cont;
    u16 trig;
    if (!Lo_Active021597dc(self)) {
        return;
    }
    if (LFLD(void *, self, 0x98) == LFLD(void *, self, 0xa4) && LBIT(self, 0xc).b1) {
        LBIT(self, 0xc).b0 = 1;
        LFLD(s32, self, 4) = 1;
        return;
    }
    if (LFLD(void *, self, 0x94) == NULL) {
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
        LFLD(s8, self, 0xb3) = 0;
    }
    LFLD(s8, self, 0xb2)--;
    if (LFLD(s16, self, 0x9e) == 0) {
        if (LFLD(s8, self, 0xb2) < (LFLD(s8, self, 0xb3) >> 1)) {
            LFLD(s8, self, 0xb2) = 0;
            if (cont & 0x40) {
                self->vfunc_ac(1, 0);
            } else if (cont & 0x80) {
                self->vfunc_b4(1, 0);
            } else {
                if (LFLD(s16, self, 0x9c) > LFLD(s32, self, 0x20) && (LFLD(u32, self, 0xc) & 0x10000)) {
                    if (cont & 0x200) {
                        self->vfunc_b0(LFLD(s32, self, 0x20), 0);
                    } else if (cont & 0x100) {
                        self->vfunc_b8(LFLD(s32, self, 0x20), 0);
                    }
                }
                LFLD(s8, self, 0xb3) = 0;
            }
        } else if (trig & 3) {
            LFLD(s8, self, 0xb3) = 0;
        }
    }
    if (Lo_Busy021597dc(self)) {
        return;
    }
    if (trig & 2) {
        if (!self->vfunc_98(NULL)) {
            LFLD(u32, self, 0xc) |= 2;
        }
        return;
    }
}

}
