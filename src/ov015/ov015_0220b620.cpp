#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212f20[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e47[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191618(void *a);

void *Ov015FishState18_Dtor(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *Ov015FishState18_DtorDelete(void *self) {
    SET_VT(self, data_ov015_02212f20);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    Heap_Free(self);
    return self;
}

BOOL Ov015FishState18_Enter(Ov015FishState18 *self, Ov015Fish *p) {
    self->step = 0;
    self->timer = 0x50;
    self->duration = p->info.unk_14;
    func_ov000_02190cb0(&p->model, data_ov015_02212e47, 0x19a, 0);
    func_ov000_02191618(&p->model);
    p->animSpeed = 0x800;
    p->unk_bc = 1;
    return TRUE;
}

u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e55[];
extern u8 data_ov015_02212e4e[];
extern u8 data_ov015_02212e61[];
BOOL func_ov000_02191120(void *p);
void func_ov000_021915a0(void *a);
void func_ov015_0220bb68(Ov015FishState18 *self, Ov015Fish *p);
void func_ov015_0220be38(Ov015FishState18 *self, Ov015Fish *p);
static inline void Ov015_SpeedB6f0(Ov015Fish *p) {
    s32 r;
    s32 sp = p->info.unk_28;
    s32 s = p->info.unk_10 << 12;
    if (sp < 0xe10000) {
        r = FX_Mul(s, 0x1000);
    } else if (sp < 0x1c20000) {
        r = FX_Mul(s, 0xccd);
    } else {
        r = FX_Mul(s, 0xb33);
    }
    p->info.unk_1c = r;
}
BOOL Ov015FishState18_Update(Ov015FishState18 *self, Ov015Fish *p) {
    Ov015Vec b;
    Ov015Vec a;
    self->fish = p;
    switch (self->step) {
    case 0:
        func_ov015_0220bb68(self, p);
        if (func_ov000_02191120(&p->model)) {
            func_ov000_02190cb0(&p->model, data_ov015_02212e4e, 0x19a, 0);
            func_ov000_021915a0(&p->model);
            p->animSpeed = 0x1000;
            self->step = 1;
            self->timer = self->duration;
        }
        break;
    case 1: {
        Ov015V *e;
        Ov015Fish *q;
        {
            s32 c = self->timer;
            s32 t = self->duration;
            Ov015VecC v(*(Ov015VecC *)&p->pos);
            if (t - c >= 0x3c) {
                s32 r = FX_Div(c << 12, t >> 12);
                u16 idx = FX_Mul(0x1000 - r, 0x2ffff) >> 12;
                v.y = FX_Mul(FX_SinCosTable_[(idx >> 4) * 2], 0xccd) + 0x4000;
            }
            *(Ov015VecC *)&p->pos = v;
        }
        q = self->fish;
        a.x = q->pos.x;
        a.y = q->pos.y > 0 ? 0 : q->pos.y;
        a.z = q->pos.z;
        e = func_020657b0(data_0214a420, self->fxKey);
        if (e == NULL) {
            e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e55, 0, &self->fish->pos);
            FLD(s32, e, 0xd4) = 1;
            FLD(u8, e, 0x28) = 0;
            FLD(s32, e, 0x3c) = 0x800;
            FLD(s32, e, 0xc8) = -1;
            FLD(s32, e, 0x50) = -0xc8000;
            e->v34(0, 0x3fff, 0);
            self->fxKey = FLD(void *, e, 0x24);
        }
        e->v18(&a);
        q = self->fish;
        {
            s32 k = q->scaleMul;
            b.x = FX_Mul(q->scaleX, k);
            b.y = FX_Mul(q->scaleY, k);
            b.z = FX_Mul(q->scaleZ, k);
        }
        e->v10(&b);
        if (self->timer % 50 == 0) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (self->timer <= 0) {
            p->animSpeed = 0x800;
            self->step = 2;
            self->timer = 0x50;
            func_ov000_02190cb0(&p->model, data_ov015_02212e61, 0x19a, 0);
            func_ov000_02191618(&p->model);
            p->animSpeed = 0x800;
            e = func_020657b0(data_0214a420, self->fxKey);
            if (e != NULL) {
                void *saved;
                HEAP_PUSH(saved);
                if (e != NULL) {
                    if (e != NULL) {
                        e->v04();
                    }
                }
                HEAP_POP(saved);
            }
        }
        break;
    }
    case 2:
        func_ov015_0220be38(self, p);
        if (func_ov000_02191120(&p->model)) {
            Ov015_SpeedB6f0(p);
            return FALSE;
        }
        break;
    }
    self->timer--;
    if (self->timer <= 0) {
        self->timer = 0;
    }
    p->unk_bc = 1;
    return TRUE;
}

}
