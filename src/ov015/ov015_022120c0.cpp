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
void func_ov015_02212430(Ov015Obj292c *self);
void *NNS_G3dGlbGetInvV(void);
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

void func_ov015_022120c0(Ov015Obj292c *self) {
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x8) = 0;
    self->unk_0c.x = 0;
    self->unk_0c.y = 0;
    self->unk_0c.z = 0;
    self->unk_18.x = 0x1000;
    self->unk_18.y = 0x1000;
    self->unk_18.z = 0x1000;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
}

void func_ov015_022120fc(Ov015Obj292c *self) {
    u32 saved;
    void *o;
    if (func_02065748(data_0214a420, self->unk_04)) {
        FLD(s32, self->unk_04, 0x1c) = 4;
        FLD(void *, self, 0x4) = NULL;
    }
    HEAP_PUSH(saved);
    o = self->unk_08;
    if (o != NULL) {
        if (o != NULL) {
            func_ov000_021bd228(o);
            Heap_Free(o);
        }
        self->unk_08 = NULL;
    }
    HEAP_POP(saved);
}

void func_ov015_02212180(Ov015Obj292c *self) {
    func_020359d0(data_ov015_022132ac, 7, 0);
}

int func_ov015_0221219c(Ov015Obj292c *self) {
    return func_02035b90(data_ov015_022132ac, 7);
}

BOOL func_ov015_022121b4(Ov015Obj292c *self) {
    u8 *q;
    self->unk_04 = func_02066774(data_ov015_022132ac, data_ov015_022132bb, 0, &self->unk_0c);
    FLD(s32, self->unk_04, 0xd4) = 3;
    FLD(s32, self->unk_04, 0x54) = 0;
    FLD(s32, self->unk_04, 0x50) = -0xc8000;
    FLD(s32, self->unk_04, 0xc8) = -1;
    FLD(u8, self->unk_04, 0x28) = 0;
    FLD(s32, self->unk_04, 0x3c) = 0x800;
    q = (u8 *)Heap_Alloc(0xa8);
    if (q != NULL) {
        func_ov000_021bd198(q);
    }
    FLD(u8 *, self, 0x8) = q;
    FLD(u32, q, 0x0) &= ~2;
    self->unk_30 = 0x800;
    return TRUE;
}

void func_ov015_02212250(Ov015Obj292c *self, s32 a) {
    if (a == 0) {
        func_ov015_02212430(self);
    }
}

void func_ov015_02212264(Ov015Obj292c *self) {
    u8 *o;
    if (self->unk_04 != NULL) {
        void *m = NNS_G3dGlbGetInvV();
        Ov015Vec w;
        Ov015Vec v;

        v.x = 0;
        v.y = 0;
        v.z = 0xa000;
        MTX_MultVec33(&v, m, &v);
        VEC_Add(&v, &self->unk_0c, &w);
        VCALL(self->unk_04)->v18(&w);
        VCALL(self->unk_04)->v10(&self->unk_18);
        VCALL(self->unk_04)->v34(0xe00, FX_Atan2(v.x, v.z), 0);
    }
    o = ((u8 *)self->unk_08);
    if (o != NULL) {
        FLD(s32, o, 0x50) = self->unk_24;
        FLD(s32, o, 0x54) = self->unk_28;
        FLD(s32, o, 0x58) = self->unk_2c;
        func_ov000_021bd624(self->unk_08);
        func_ov000_021bd7a0(self->unk_08);
    }
}

void func_ov015_0221234c(Ov015Obj292c *self) {
    Ov015ObjFlags *o = ((Ov015ObjFlags *)self->unk_08);
    if (o == NULL) {
        return;
    }
    if (Ov015_ObjIsB1(o)) {
        return;
    }
    func_ov000_021bd314(o, 4);
    ((Ov015ObjFlags *)self->unk_08)->b1 = 1;
    func_02049bdc(data_02097e4c, 0xe, 5);
    if (self->unk_04 != NULL) {
        FLD(s32, self->unk_04, 0x3c) = 0x2000;
    }
}

void func_ov015_022123c4(Ov015Obj292c *self) {
    Ov015ObjFlags *o = ((Ov015ObjFlags *)self->unk_08);
    if (o == NULL) {
        return;
    }
    if (!Ov015_ObjIsB1(o)) {
        return;
    }
    o->b1 = 0;
    func_02049bdc(data_02097e4c, 0x1f, -3);
    if (self->unk_04 != NULL) {
        FLD(s32, self->unk_04, 0x3c) = 0x800;
    }
}

void func_ov015_02212430(Ov015Obj292c *self) {
    u16 pad = FLD(u16, data_02097dc8, 0x10);
    if (pad & 0x20) {
        self->unk_0c.x -= self->unk_30;
        if (self->unk_0c.x < -0x32000) self->unk_0c.x = -0x32000;
    } else if (pad & 0x10) {
        self->unk_0c.x += self->unk_30;
        if (self->unk_0c.x > 0x32000) self->unk_0c.x = 0x32000;
    }
    if (pad & 0x40) {
        self->unk_0c.z -= self->unk_30;
        if (self->unk_0c.z < -0x8c000) self->unk_0c.z = -0x8c000;
    } else if (pad & 0x80) {
        self->unk_0c.z += self->unk_30;
        if (self->unk_0c.z > -0x4b000) self->unk_0c.z = -0x4b000;
    }
}

BOOL func_ov015_022124e4(Ov015Obj290 *self) {
    return self->unk_08 == 4 ? TRUE : FALSE;
}

void *Ov015Obj290_Dtor(Ov015Obj290 *self) {
    SET_VT(self, data_ov015_022132e0);
    func_ov000_0218fee4(&self->unk_14c);
    func_ov000_0218ea20(&self->unk_14);
    return self;
}

}
