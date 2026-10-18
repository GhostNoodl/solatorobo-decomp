#include "ov015/ov015.h"

extern "C" {

extern u8 *data_ov015_0221336c;
void func_02016dbc(const void *src, void *dst);
void func_ov000_021903b4(void *a);
extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);
BOOL func_ov000_02191120(void *p);
void func_02011340(void *a);
void func_02011488(void *m, s32 s, s32 c);
void func_020114a4(void *m, s32 s, s32 c);
void func_02011610(void *a, void *b, void *out);
void func_ov000_02190a80(void *a, s32 b);
void *func_02065f88(s32 id, void *pos);
extern u8 data_ov015_02213286[];
extern u8 data_ov015_0221329a[];
extern u8 data_ov015_022132a6[];
u8 *func_02066774(void *a, void *b, int c, void *d);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191318(void *a, s32 b);
void func_ov000_021911c8(void *a, s32 b);
extern u8 data_ov015_02213280[];

BOOL func_ov015_02211bf8(u8 *self) {
    BOOL r = TRUE;
    switch (FLD(s32, self, 0x8)) {
    case 0:
        if (VCALL(self)->v2c() == 0) FLD(s32, self, 0x8) = 1;
        break;
    case 1:
        if (VCALL(self)->v30() == 0) FLD(s32, self, 0x8) = 2;
        break;
    case 2:
        if (VCALL(self)->v34() == 0) FLD(s32, self, 0x8) = 3;
        break;
    case 3:
        if (VCALL(self)->v38() == 0) FLD(s32, self, 0x8) = 4;
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

void func_ov015_02211ca0(u8 *self) {
    *(Ov015VecC *)(self + 0x240) = *(Ov015VecC *)(self + 0x234);
    data_ov015_0221336c = self;
    *(Ov015VecC *)(self + 0x1c4) = *(Ov015VecC *)(self + 0x27c);
    func_02016dbc(self + 0x24c, self + 0x1d0);
    FLD(s32, self, 0x1f4) = 0x1000;
    FLD(s32, self, 0x1f8) = 0x1000;
    FLD(s32, self, 0x1fc) = 0x1000;
    func_ov000_021903b4(self + 0x14c);
    data_ov015_0221336c = NULL;
}

BOOL func_ov015_02211d14(u8 *self) {
    u8 m[0x24];
    BOOL r;
    u16 a = FLD(u16, self, 0x288);
    u16 b = FLD(u16, self, 0x28a);
    r = TRUE;
    BOOL done = FALSE;
    func_02011340(self + 0x24c);
    if (a != 0) {
        func_02011488(self + 0x24c, FX_SinCosTable_[((a) >> 4) * 2], FX_SinCosTable_[((a) >> 4) * 2 + 1]);
        done = r;
    }
    if (b != 0) {
        if (done) {
            func_020114a4(m, FX_SinCosTable_[((b) >> 4) * 2], FX_SinCosTable_[((b) >> 4) * 2 + 1]);
            func_02011610(m, self + 0x24c, self + 0x24c);
        } else {
            func_020114a4(self + 0x24c, FX_SinCosTable_[((b) >> 4) * 2], FX_SinCosTable_[((b) >> 4) * 2 + 1]);
        }
    }
    if (FLD(s32, self, 0x10) % 10 == 0) {
        u8 *e = (u8 *)func_02065f88(0x12d, self + 0x234);
        FLD(s32, e, 0xd4) = 3;
        FLD(s32, e, 0x50) = 0xa000;
    }
    FLD(s32, self, 0x10) = (u16)(FLD(s32, self, 0x10) + 1);
    func_ov000_02190a80(self + 0x14c, 0x1000);
    if (func_ov000_02191120(self + 0x14c)) {
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        r = FALSE;
    }
    return r;
}

BOOL func_ov015_02211e88(u8 *self) {
    Ov015VecC v;
    u8 *o;
    v = *(Ov015VecC *)(self + 0x27c);
    v.y = 0;
    o = func_02066774(data_ov015_02213286, data_ov015_0221329a, 0, &v);
    FLD(s32, o, 0xd4) = 1;
    FLD(u8, o, 0x28) = 1;
    FLD(s32, o, 0x50) = -0xc8000;
    VCALL(o)->v14(0x59a, 0x59a, 0x59a);
    func_ov000_02190cb0(self + 0x14c, data_ov015_022132a6, 0x1000, 0);
    func_ov000_02191318(self + 0x14c, 0);
    func_ov000_021911c8(self + 0x14c, 0x1000);
    FLD(Ov015AnimFlags, self, 0x20e).b0 = 1;
    return FALSE;
}

BOOL func_ov015_02211f54(u8 *self) {
    BOOL r = TRUE;
    func_ov000_02190a80(self + 0x14c, 0x1000);
    if (func_ov000_02191120(self + 0x14c)) {
        r = FALSE;
        func_ov000_02190cb0(self + 0x14c, data_ov015_02213280, 0x1000, 0);
        func_ov000_02191318(self + 0x14c, 0);
        FLD(Ov015Flags18, self, 0x20e).b0 = 0;

    }
    return r;
}

}
