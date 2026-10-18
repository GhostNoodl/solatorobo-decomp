#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern Ov009Actor *func_ov003_021d69a0(Ov009Actor *self, u16 kind, s32 a);
extern void func_ov003_021d452c(Ov009Actor *self);

void func_ov009_021fb298(Ov009Actor *self) {
    if (self->unk_40->state == 0 && *self->unk_50 == 0) {
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x5404, 0x15);
    }
    func_ov003_021d5900(self);
}

void func_ov009_021fb2e4(Ov009Actor *self) {
    s32 range;
    Ov009Actor *g;
    Ov009Actor *o;
    func_ov003_021d452c(self);
    if (self->unk_40->unk_13 != 0x13) {
        return;
    }
    func_ov000_0218996c(0xc, 0x19);
    range = 0xa000;
    if (FLD(u8, data_ov000_021ccd54, 0xca) == 0x11) {
        range = 0x5000;
    }
    g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
    if (g == NULL) {
        return;
    }
    if (FLD(u16, g, 0x16) > 2) {
        return;
    }
    do {
        o = func_ov003_021d69a0(self, 0x5407, 4);
        if (o != NULL) {
            s32 z = func_02040528(range);
            s32 x = func_02040528(range);
            o->pos.x = x;
            o->pos.y = 0x8000;
            o->pos.z = z;
        }
    } while (FLD(u16, g, 0x16) <= 2);
}

void func_ov009_021fb3a8(Ov009Actor *self) {
    if (self->unk_40->state == 0 && *self->unk_50 == 0) {
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x5407, 0x15);
    }
    func_ov003_021d5900(self);
}

extern u8 data_ov009_02216ab6[];
extern s32 func_02040498(s32 max);

void func_ov009_021fb3f4(Ov009Actor *self) {
    Ov009Vec *v = &FLD(Ov009Vec, self, 0xf4);
    func_ov003_021d112c(self);
    FLD(u16, self, 0xf0) = self->rot[1] + func_02040528(0x3400);
    *v = self->pos;
    if ((u16)(self->kind + 0xabf6) <= 1) {
        s32 d = func_02040498(0x800) + 0x3800;
        v->x += Ov009_FxMul(d, OV009_SIN(self->rot[1]));
        v->z += Ov009_FxMul(d, OV009_COS(self->rot[1]));
    }
    FLD(Ov009Vec, self, 0x100) = *v;
    self->unk_b8 = *v;
    if (self->kind == 0x5417) {
        self->unk_1c = 0;
    } else {
        self->unk_1c = 0x96;
        self->unk_ea_6 = 1;
    }
    {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    self->unk_48->unk_48 = 0x1000;
}

}
