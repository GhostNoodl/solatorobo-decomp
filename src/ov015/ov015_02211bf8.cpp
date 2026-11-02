#include "ov015/ov015.h"

extern "C" {

extern Ov015Obj290 *data_ov015_0221336c;
BOOL func_ov000_021903b4(void *a);
BOOL func_ov000_02191120(void *p);
void func_ov000_02190a80(void *a, s32 b);
void *func_02065f88(s32 id, void *pos);
extern u8 data_ov015_02213286[];
extern u8 data_ov015_0221329a[];
extern u8 data_ov015_022132a6[];
u8 *func_02066774(void *a, void *b, int c, void *d);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_021911c8(void *a, s32 b);
extern u8 data_ov015_02213280[];

BOOL func_ov015_02211bf8(Ov015Obj290 *self) {
    BOOL r = TRUE;
    switch (self->unk_08) {
    case 0:
        if (VCALL(self)->v2c() == 0) self->unk_08 = 1;
        break;
    case 1:
        if (VCALL(self)->v30() == 0) self->unk_08 = 2;
        break;
    case 2:
        if (VCALL(self)->v34() == 0) self->unk_08 = 3;
        break;
    case 3:
        if (VCALL(self)->v38() == 0) self->unk_08 = 4;
        break;
    case 4:
        r = FALSE;
        break;
    }
    return r;
}

BOOL func_ov015_02211c98(void) {
    return TRUE;
}

void func_ov015_02211ca0(Ov015Obj290 *self) {
    self->unk_240 = self->unk_234;
    data_ov015_0221336c = self;
    self->unk_14c.unk_78 = self->unk_27c;
    MI_Copy36B(&self->unk_24c, &self->unk_14c.unk_84);
    self->unk_14c.unk_a8 = 0x1000;
    self->unk_14c.unk_ac = 0x1000;
    self->unk_14c.unk_b0 = 0x1000;
    func_ov000_021903b4(&self->unk_14c);
    data_ov015_0221336c = NULL;
}

BOOL func_ov015_02211d14(Ov015Obj290 *self) {
    u8 m[0x24];
    BOOL r;
    u16 a = self->unk_288;
    u16 b = self->unk_28a;
    r = TRUE;
    BOOL done = FALSE;
    MTX_Identity33_((MtxFx33 *)(&self->unk_24c));
    if (a != 0) {
        MTX_RotY33_((MtxFx33 *)(&self->unk_24c), FX_SinCosTable_[((a) >> 4) * 2], FX_SinCosTable_[((a) >> 4) * 2 + 1]);
        done = r;
    }
    if (b != 0) {
        if (done) {
            MTX_RotZ33_((MtxFx33 *)m, FX_SinCosTable_[((b) >> 4) * 2], FX_SinCosTable_[((b) >> 4) * 2 + 1]);
            MTX_Concat33((MtxFx33 *)m, (MtxFx33 *)(&self->unk_24c), (MtxFx33 *)(&self->unk_24c));
        } else {
            MTX_RotZ33_((MtxFx33 *)(&self->unk_24c), FX_SinCosTable_[((b) >> 4) * 2], FX_SinCosTable_[((b) >> 4) * 2 + 1]);
        }
    }
    if (self->unk_10 % 10 == 0) {
        u8 *e = (u8 *)func_02065f88(0x12d, &self->unk_234);
        FLD(s32, e, 0xd4) = 3;
        FLD(s32, e, 0x50) = 0xa000;
    }
    self->unk_10 = (u16)(self->unk_10 + 1);
    func_ov000_02190a80(&self->unk_14c, 0x1000);
    if (func_ov000_02191120(&self->unk_14c)) {
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        r = FALSE;
    }
    return r;
}

BOOL func_ov015_02211e88(Ov015Obj290 *self) {
    Ov015VecC v;
    u8 *o;
    v = self->unk_27c;
    v.y = 0;
    o = func_02066774(data_ov015_02213286, data_ov015_0221329a, 0, &v);
    FLD(s32, o, 0xd4) = 1;
    FLD(u8, o, 0x28) = 1;
    FLD(s32, o, 0x50) = -0xc8000;
    VCALL(o)->v14(0x59a, 0x59a, 0x59a);
    func_ov000_02190cb0(&self->unk_14c, data_ov015_022132a6, 0x1000, 0);
    func_ov000_02191318(&self->unk_14c, 0);
    func_ov000_021911c8(&self->unk_14c, 0x1000);
    self->unk_14c.unk_c2.b0 = 1;
    return FALSE;
}

BOOL func_ov015_02211f54(Ov015Obj290 *self) {
    BOOL r = TRUE;
    func_ov000_02190a80(&self->unk_14c, 0x1000);
    if (func_ov000_02191120(&self->unk_14c)) {
        r = FALSE;
        func_ov000_02190cb0(&self->unk_14c, data_ov015_02213280, 0x1000, 0);
        func_ov000_02191318(&self->unk_14c, 0);
        FLD(Ov015Flags18, self, 0x20e).b0 = 0;

    }
    return r;
}

void func_ov000_02191618(void *a);
void func_ov015_02211fc0(Ov015Obj290 *self, const Ov015VecC *to, const Ov015VecC *from) {
    Ov015Vec d;
    s32 x, y, z;
    if (from != NULL) {
        self->unk_270 = *from;
    } else {
        self->unk_270.x = 0;
        self->unk_270.y = 0;
        self->unk_270.z = 0;
    }
    Ov015VecC t(*to);
    self->unk_27c = t;
    d.x = t.x - self->unk_270.x;
    d.y = t.y - self->unk_270.y;
    d.z = t.z - self->unk_270.z;
    VEC_Normalize((VecFx32 *)&d, (VecFx32 *)&d);
    self->unk_288 = FX_Atan2(d.x, d.z) + 0x7fff;
    func_ov000_02190cb0(&self->unk_14c, data_ov015_02213280, 0x1000, 0);
    func_ov000_021911c8(&self->unk_14c, (s16)self->unk_28c);
    func_ov000_02191318(&self->unk_14c, 0);
    func_ov000_02191618(&self->unk_14c);
    self->unk_14c.unk_c2.b0 = 1;
    self->unk_08 = 1;
}

}
