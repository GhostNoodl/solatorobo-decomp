#include "ov000/VObj.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 2;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 rest : 25;
} FadeFlags021732a8;

class Fade021732a8 : public VObj {
public:
    FadeFlags021732a8 flags;
    s32 state;
    u8 unk_0c[0xc];
    s32 unk_18;
    s32 cur;
    s32 len;
    s32 ratio;
};

extern "C" {

extern u8 data_ov000_021ccd34[];
s32 FX_Div(s32 a, s32 b);

static inline BOOL Fade_IsOff(Fade021732a8 *self) {
    return self->flags.b0 == 0 ? TRUE : FALSE;
}

static inline BOOL Fade_IsIdle(Fade021732a8 *self) {
    BOOL r = FALSE;
    if (data_ov000_021ccd34[0] == 0 && Fade_IsOff(self)) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Fade_IsReady(Fade021732a8 *self) {
    BOOL r = FALSE;
    if (Fade_IsIdle(self) && self->vfunc_54()) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Fade_CanShow(Fade021732a8 *self) {
    BOOL r = FALSE;
    if (Fade_IsReady(self) && !self->flags.b2) {
        r = TRUE;
    }
    return r;
}

void func_ov000_021732a8(Fade021732a8 *self) {
    self->vfunc_6c();
    switch (self->state) {
    case 0:
        self->flags.b6 = 0;
        self->flags.b5 = self->flags.b6;
        if (!self->flags.b1) {
            if (self->vfunc_1c()) {
                self->state = 8;
            }
        }
        break;
    case 8:
        self->flags.b0 = 1;
        self->state = 9;
    case 9:
        self->cur += 0x1000;
        self->ratio = FX_Div(self->cur, self->len);
        if (self->ratio >= 0x1000) {
            self->cur = self->len;
            self->ratio = 0x1000;
            self->state = 12;
        }
        break;
    case 10:
        self->flags.b0 = 1;
        self->state = 11;
    case 11:
        self->cur -= 0x1000;
        self->ratio = FX_Div(self->cur, self->len);
        if (self->ratio <= 0) {
            self->cur = 0;
            self->ratio = 0;
            if (self->vfunc_4c()) {
                self->state = 0;
            }
        }
        break;
    case 12:
        self->flags.b0 = 0;
        self->state = 13;
    case 13:
        self->cur = self->len;
        self->ratio = 0x1000;
        if (self->flags.b1) {
            self->flags.b0 = 1;
            self->state = 10;
        }
        break;
    }
    if (self->unk_18 != 0 && self->vfunc_54()) {
        self->vfunc_60(self->unk_18, 0);
        self->unk_18 = 0;
    }
    if (Fade_CanShow(self)) {
        self->vfunc_64();
    }
    self->vfunc_70();
}

}
