#include "ov015/ov015.h"

extern "C" {

s32 func_02065748(void *a, void *b);
void func_ov000_021bd228(void *p);
extern u8 data_ov015_022132ac[];
void *func_020359d0(void *a, int b, int c);
int func_02035b90(void *a, int b);
extern u8 data_ov015_022132bb[];
u8 *func_02066774(void *a, void *b, int c, void *d);
void func_ov000_021bd198(void *p);
void func_ov015_02212430(u8 *self);
void *NNS_G3dGlbGetInvV(void *p);
void MTX_MultVec33(void *a, void *b, void *c);
void VEC_Add(void *a, void *b, void *c);
u16 FX_Atan2(s32 x, s32 z);
void func_ov000_021bd624(void *p);
void func_ov000_021bd7a0(void *p);
extern void *data_02097e4c;
s32 func_02049bdc(void *a, s32 b, s32 c);
BOOL func_ov000_021bd314(void *o, s32 a);
extern u8 *data_02097dc8;
extern u8 data_ov015_022132e0[];
void *func_ov000_0218fee4(void *a);
void *func_ov000_0218ea20(void *a);

void func_ov015_022120c0(u8 *self) {
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x8) = 0;
    FLD(s32, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 0;
    FLD(s32, self, 0x14) = 0;
    FLD(s32, self, 0x18) = 0x1000;
    FLD(s32, self, 0x1c) = 0x1000;
    FLD(s32, self, 0x20) = 0x1000;
    FLD(s32, self, 0x24) = 0;
    FLD(s32, self, 0x28) = 0;
    FLD(s32, self, 0x2c) = 0;
    FLD(s32, self, 0x30) = 0;
}

void func_ov015_022120fc(u8 *self) {
    u32 saved;
    void *o;
    if (func_02065748(data_0214a420, FLD(void *, self, 0x4))) {
        FLD(s32, FLD(u8 *, self, 0x4), 0x1c) = 4;
        FLD(void *, self, 0x4) = NULL;
    }
    HEAP_PUSH(saved);
    o = FLD(void *, self, 0x8);
    if (o != NULL) {
        if (o != NULL) {
            func_ov000_021bd228(o);
            func_0203de1c(o);
        }
        FLD(void *, self, 0x8) = NULL;
    }
    HEAP_POP(saved);
}

void func_ov015_02212180(void) {
    func_020359d0(data_ov015_022132ac, 7, 0);
}

int func_ov015_0221219c(void) {
    return func_02035b90(data_ov015_022132ac, 7);
}

BOOL func_ov015_022121b4(u8 *self) {
    u8 *q;
    FLD(u8 *, self, 0x4) = func_02066774(data_ov015_022132ac, data_ov015_022132bb, 0, self + 0xc);
    FLD(s32, FLD(u8 *, self, 0x4), 0xd4) = 3;
    FLD(s32, FLD(u8 *, self, 0x4), 0x54) = 0;
    FLD(s32, FLD(u8 *, self, 0x4), 0x50) = -0xc8000;
    FLD(s32, FLD(u8 *, self, 0x4), 0xc8) = -1;
    FLD(u8, FLD(u8 *, self, 0x4), 0x28) = 0;
    FLD(s32, FLD(u8 *, self, 0x4), 0x3c) = 0x800;
    q = (u8 *)func_0203dd9c(0xa8);
    if (q != NULL) {
        func_ov000_021bd198(q);
    }
    FLD(u8 *, self, 0x8) = q;
    FLD(u32, q, 0x0) &= ~2;
    FLD(s32, self, 0x30) = 0x800;
    return TRUE;
}

void func_ov015_02212250(u8 *self, s32 a) {
    if (a == 0) {
        func_ov015_02212430(self);
    }
}

void func_ov015_02212264(u8 *self) {
    u8 *o;
    if (FLD(void *, self, 0x4) != NULL) {
        void *m = NNS_G3dGlbGetInvV(FLD(void *, self, 0x4));
        Ov015Vec w;
        Ov015Vec v;

        v.x = 0;
        v.y = 0;
        v.z = 0xa000;
        MTX_MultVec33(&v, m, &v);
        VEC_Add(&v, self + 0xc, &w);
        VCALL(FLD(void *, self, 0x4))->v18(&w);
        VCALL(FLD(void *, self, 0x4))->v10(self + 0x18);
        VCALL(FLD(void *, self, 0x4))->v34(0xe00, FX_Atan2(v.x, v.z), 0);
    }
    o = FLD(u8 *, self, 0x8);
    if (o != NULL) {
        FLD(s32, o, 0x50) = FLD(s32, self, 0x24);
        FLD(s32, o, 0x54) = FLD(s32, self, 0x28);
        FLD(s32, o, 0x58) = FLD(s32, self, 0x2c);
        func_ov000_021bd624(FLD(void *, self, 0x8));
        func_ov000_021bd7a0(FLD(void *, self, 0x8));
    }
}

void func_ov015_0221234c(u8 *self) {
    Ov015ObjFlags *o = FLD(Ov015ObjFlags *, self, 0x8);
    if (o == NULL) {
        return;
    }
    if (Ov015_ObjIsB1(o)) {
        return;
    }
    func_ov000_021bd314(o, 4);
    FLD(Ov015ObjFlags *, self, 0x8)->b1 = 1;
    func_02049bdc(data_02097e4c, 0xe, 5);
    if (FLD(u8 *, self, 0x4) != NULL) {
        FLD(s32, FLD(u8 *, self, 0x4), 0x3c) = 0x2000;
    }
}

void func_ov015_022123c4(u8 *self) {
    Ov015ObjFlags *o = FLD(Ov015ObjFlags *, self, 0x8);
    if (o == NULL) {
        return;
    }
    if (!Ov015_ObjIsB1(o)) {
        return;
    }
    o->b1 = 0;
    func_02049bdc(data_02097e4c, 0x1f, -3);
    if (FLD(u8 *, self, 0x4) != NULL) {
        FLD(s32, FLD(u8 *, self, 0x4), 0x3c) = 0x800;
    }
}

void func_ov015_02212430(u8 *self) {
    u16 pad = FLD(u16, data_02097dc8, 0x10);
    if (pad & 0x20) {
        FLD(s32, self, 0xc) -= FLD(s32, self, 0x30);
        if (FLD(s32, self, 0xc) < -0x32000) FLD(s32, self, 0xc) = -0x32000;
    } else if (pad & 0x10) {
        FLD(s32, self, 0xc) += FLD(s32, self, 0x30);
        if (FLD(s32, self, 0xc) > 0x32000) FLD(s32, self, 0xc) = 0x32000;
    }
    if (pad & 0x40) {
        FLD(s32, self, 0x14) -= FLD(s32, self, 0x30);
        if (FLD(s32, self, 0x14) < -0x8c000) FLD(s32, self, 0x14) = -0x8c000;
    } else if (pad & 0x80) {
        FLD(s32, self, 0x14) += FLD(s32, self, 0x30);
        if (FLD(s32, self, 0x14) > -0x4b000) FLD(s32, self, 0x14) = -0x4b000;
    }
}

BOOL func_ov015_022124e4(u8 *self) {
    return FLD(s32, self, 0x8) == 4 ? TRUE : FALSE;
}

void *func_ov015_022124f8(u8 *self) {
    SET_VT(self, data_ov015_022132e0);
    func_ov000_0218fee4(self + 0x14c);
    func_ov000_0218ea20(self + 0x14);
    return self;
}

}
