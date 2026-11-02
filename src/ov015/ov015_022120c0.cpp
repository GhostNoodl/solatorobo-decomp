#include "ov015/ov015.h"

extern "C" {

void func_ov000_021bd228(void *p);
extern char data_ov015_022132ac[];
extern char data_ov015_022132bb[];
void func_ov000_021bd198(void *p);
void func_ov015_02212430(Ov015Obj292c *self);
void func_ov000_021bd624(void *p);
void func_ov000_021bd7a0(void *p);
s32 func_02049bdc(void *a, s32 b, s32 c);
BOOL func_ov000_021bd314(void *o, s32 a);
extern u8 data_ov015_022132e0[];
void *func_ov000_0218fee4(void *a);
void *func_ov000_0218ea20(void *a);

void func_ov015_022120c0(Ov015Obj292c *self) {
    self->fx = NULL;
    self->unk_08 = NULL;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    self->unk_24.x = 0;
    self->unk_24.y = 0;
    self->unk_24.z = 0;
    self->unk_30 = 0;
}

void func_ov015_022120fc(Ov015Obj292c *self) {
    void *saved;
    void *o;
    if (EffectMgr_Contains(data_0214a420, self->fx)) {
        self->fx->state = 4;
        self->fx = NULL;
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
    self->fx = Effect3D_Create(data_ov015_022132ac, data_ov015_022132bb, 0, &self->pos);
    self->fx->unk_d4 = 3;
    self->fx->unk_54 = 0;
    self->fx->unk_50 = -0xc8000;
    self->fx->loopCount = -1;
    self->fx->unk_28 = 0;
    self->fx->speed = 0x800;
    q = (u8 *)Heap_Alloc(0xa8);
    if (q != NULL) {
        func_ov000_021bd198(q);
    }
    self->unk_08 = (void *)q;
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
    if (self->fx != NULL) {
        const MtxFx43 *m = NNS_G3dGlbGetInvV();
        Ov015Vec w;
        Ov015Vec v;

        v.x = 0;
        v.y = 0;
        v.z = 0xa000;
        MTX_MultVec33(&v, (MtxFx33 *)m, &v);
        VEC_Add(&v, (&self->pos), &w);
        self->fx->SetPos(&w);
        self->fx->SetScale(&self->scale);
        self->fx->SetRotXYZ(0xe00, FX_Atan2(v.x, v.z), 0);
    }
    o = ((u8 *)self->unk_08);
    if (o != NULL) {
        FLD(s32, o, 0x50) = self->unk_24.x;
        FLD(s32, o, 0x54) = self->unk_24.y;
        FLD(s32, o, 0x58) = self->unk_24.z;
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
    if (self->fx != NULL) {
        self->fx->speed = 0x2000;
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
    if (self->fx != NULL) {
        self->fx->speed = 0x800;
    }
}

void func_ov015_02212430(Ov015Obj292c *self) {
    u16 pad = data_02097dc8->cur;
    if (pad & 0x20) {
        self->pos.x -= self->unk_30;
        if (self->pos.x < -0x32000) self->pos.x = -0x32000;
    } else if (pad & 0x10) {
        self->pos.x += self->unk_30;
        if (self->pos.x > 0x32000) self->pos.x = 0x32000;
    }
    if (pad & 0x40) {
        self->pos.z -= self->unk_30;
        if (self->pos.z < -0x8c000) self->pos.z = -0x8c000;
    } else if (pad & 0x80) {
        self->pos.z += self->unk_30;
        if (self->pos.z > -0x4b000) self->pos.z = -0x4b000;
    }
}

BOOL func_ov015_022124e4(Ov015Obj290 *self) {
    return self->step == 4 ? TRUE : FALSE;
}

void *Ov015Obj290_Dtor(Ov015Obj290 *self) {
    SET_VT(self, data_ov015_022132e0);
    func_ov000_0218fee4(&self->model);
    func_ov000_0218ea20(&self->res);
    return self;
}

}
