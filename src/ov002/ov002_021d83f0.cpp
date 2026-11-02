#include "ov002/ov002.h"

extern "C" {

void Interp_SinLerpVec(void *out, s32 t, void *a, void *b);
s32 Interp_SinLerp(s32 t, s32 a, s32 b);
void func_ov002_021d8860(Obj021efe9c *self);

static inline void ov002_SetState(Obj021efe9c *self, s32 st) {
    if (self->unk_ac != st) {
        self->unk_ac = st;
        self->unk_a4 = 0;
        self->unk_a8 = 5;
    }
}

static inline s32 ov002_GetT(Obj021efe9c *self) {
    return FX_Div(self->unk_a4 << 12, self->unk_a8 << 12);
}

void func_ov002_021d83f0(Obj021efe9c *self) {
    switch (self->unk_ac) {
    case 1:
        self->trans.y = 0x400;
        self->scale.z = 0x119a;
        self->scale.x = 0x119a;
        break;
    case 2:
        self->trans.y = 0x29;
        self->scale.z = 0x1000;
        self->scale.x = 0x1000;
        if (self->unk_cd == 0) {
            self->unk_9c = 0x1000;
        } else {
            self->unk_9c = FX_MUL(FX_SINCOS(((FIELD(self, 0xd0, s32) * 0x444) >> 4) * 2), 0xb5c) + 0x429;
        }
        break;
    case 4: {
        s32 t = ov002_GetT(self);
        Interp_SinLerpVec((u8 *)self + 0x4, t, (u8 *)self + 0xb0, (u8 *)self + 0xbc);
        if (self->unk_a4 == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 5: {
        s32 t = ov002_GetT(self);
        s32 to;
        s32 from;
        u16 ang;
        self->unk_10 = 0;
        to = self->unk_cc * 0x3fff << 12;
        from = (self->unk_c8 << 12) + to;
        ang = (from + FX_Mul(to - from, t)) >> 12;
        self->unk_12 = ang;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        if (ang != 0) {
            MTX_RotY33_(&self->rot, FX_SINCOS((ang >> 4) * 2), FX_SINCOS((ang >> 4) * 2 + 1));
        }
        if (self->unk_a4 == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 6: {
        s32 t = ov002_GetT(self);
        s32 v;
        self->trans.y = Interp_SinLerp(t, 0x29, 0x400);
        v = Interp_SinLerp(t, 0x1000, 0x119a);
        self->scale.x = v;
        self->scale.z = v;
        self->unk_9c = FX_Div((u8)(Interp_SinLerp(t, 0x1f000, 0xd000) >> 12) << 12, 0x1f000);
        if (self->unk_a4 == 0) {
            ov002_SetState(self, 2);
        }
        break;
    }
    case 7: {
        s32 t = ov002_GetT(self);
        s32 v;
        self->trans.y = Interp_SinLerp(t, 0x400, 0x29);
        v = Interp_SinLerp(t, 0x119a, 0x1000);
        self->scale.x = v;
        self->scale.z = v;
        self->unk_9c = FX_Div((u8)(Interp_SinLerp(t, 0xd000, 0x1f000) >> 12) << 12, 0x1f000);
        if (self->unk_a4 == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 8: {
        s32 t = ov002_GetT(self);
        s32 v;
        Interp_SinLerpVec((u8 *)self + 0x4, t, (u8 *)self + 0xb0, (u8 *)self + 0xbc);
        self->trans.y = 0x400;
        v = Interp_SinLerp(t, 0, 0x119a);
        self->scale.x = v;
        self->scale.z = v;
        self->unk_9c = FX_Div((u8)(Interp_SinLerp(t, 0x1f000, 0xd000) >> 12) << 12, 0x1f000);
        if (self->unk_a4 == 0) {
            ov002_SetState(self, 0);
        }
        break;
    }
    case 9: {
        s32 t = ov002_GetT(self);
        s32 v;
        Interp_SinLerpVec((u8 *)self + 0x4, t, (u8 *)self + 0xb0, (u8 *)self + 0xbc);
        self->trans.y = 0x400;
        v = Interp_SinLerp(t, 0x119a, 0);
        self->scale.x = v;
        self->scale.z = v;
        self->unk_9c = FX_Div((u8)(Interp_SinLerp(t, 0xd000, 0x1f000) >> 12) << 12, 0x1f000);
        if (self->unk_a4 == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 10:
        func_ov002_021d8860(self);
        if (self->unk_a4 == 0) {
            ov002_SetState(self, 3);
        }
        break;
    }
    if (--self->unk_a4 < 0) {
        self->unk_a4 = 0;
    }
    if (self->unk_cd) {
        self->unk_d0++;
        self->unk_d0 %= 30;
    }
}

}
