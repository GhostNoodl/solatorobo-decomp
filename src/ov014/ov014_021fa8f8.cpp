#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_022170d8[];
extern const u8 data_ov014_0221643a[];
extern const u8 data_ov014_02216480[];
extern const char *const data_ov014_02216430[];
extern void *data_02097e4c;
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_ov000_021903b4(void *p);
extern void func_0203f364(Ov014Sub48 *p);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *p);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
extern Ov014Actor *func_ov000_0219bf90(void);
extern void func_ov003_021ceff4(void *p);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);

BOOL func_ov014_021fa8f8(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0x124) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0x124)) ? TRUE : FALSE;
    }
    return (r & func_02035b90(data_ov014_022170d8, 7)) ? TRUE : FALSE;
}

BOOL func_ov014_021fa94c(Ov014Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    FLD(Ov014Vec, self, 0x2d4) = FLD(Ov014Vec, self, 0x104);
    func_ov000_021903b4((u8 *)self + 0x25c);
    return r;
}

void func_ov014_021fa984(Ov014Actor *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80((u8 *)self + 0x25c, func_0203db40((u8 *)self + 0x24));
}

void func_ov014_021fa9a8(Ov014Actor *self) {
    Ov014Sub48 *m;
    Ov014Sub44 *n;
    func_ov003_021d112c(self);
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    FLD(s32, m, 0x5c) = -0x1800;
    FLD(s32, m, 0x60) = 0x2000;
    FLD(s32, m, 0x64) = 0;
    n = self->unk_44;
    Ov014_VecSet(&FLD(Ov014Vec, n, 0xc), -0x1000, FLD(Ov014Vec, n, 0xc).y, 0);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov014_0221643a);
        FLD(s16, self, 0x364) = 0x1800;
    }
    self->pos = FLD(Ov014Vec, self, 0xf8);
    self->rot[1] = 0;
    func_ov000_0218ffdc((u8 *)self + 0x25c, (u8 *)self + 0x124, 0, 1);
    FLD(s32, self, 0x304) = 0x2000;
    FLD(s32, self, 0x308) = 0x2000;
    FLD(s32, self, 0x30c) = 0x1000;
    FLD(Ov014Flags, self, 0x31e).b0 = 1;
    func_ov003_021cf1f0((u8 *)self + 0x348, 0, 4, data_ov014_02216480);
}

}
