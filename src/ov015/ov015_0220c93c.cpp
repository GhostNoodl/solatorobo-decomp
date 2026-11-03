#include "ov015/ov015.h"

extern "C" {

extern u8 Ov015FishState40_vtbl[];
extern u8 Ov015FishState_vtbl[];
extern void *data_ov015_02212db8[];
extern u8 data_ov015_02212e0d[];
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
s32 Rand_PlusMinus(s32 max);
void HitSphere_Link(void *a);

Ov015FishState40 *Ov015FishState40_Ctor(Ov015FishState40 *self) {
    SET_VT(self, Ov015FishState40_vtbl);
    self->step = 0;
    self->unk_08 = 0;
    self->unk_0c = 0x1000;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c.x = 0;
    self->unk_1c.y = 0;
    self->unk_1c.z = 0;
    self->unk_28.x = 0;
    self->unk_28.y = 0;
    self->unk_28.z = 0;
    self->unk_34 = 0;
    self->unk_38 = 0;
    return self;
}

void *Ov015FishState40_Dtor(Ov015FishState40 *self) {
    s32 i;
    EffectObj *o;
    void *saved;
    SET_VT(self, Ov015FishState40_vtbl);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = Effect_Find_020657b0(gEffectMgr, self->unk_08);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, Ov015FishState_vtbl);

    return self;
}

void *Ov015FishState40_DtorDelete(Ov015FishState40 *self) {
    s32 i;
    EffectObj *o;
    void *saved;
    SET_VT(self, Ov015FishState40_vtbl);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = Effect_Find_020657b0(gEffectMgr, self->unk_08);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, Ov015FishState_vtbl);
    Heap_Free(self);
    return self;
}

static inline void Ov015_SetXZ(s32 *v, s32 x, s32 z) { v[0] = x; v[2] = z; }
BOOL Ov015FishState40_Enter(Ov015FishState40 *self, Ov015Fish *p) {
    s32 a;
    s32 x, z;
    Model0218fe1c_SetAnim(&p->model, data_ov015_02212e0d, 0x19a, 0);
    p->animSpeed = 0x59a;
    Model0218fe1c_SetLoop(&p->model);
    p->drawMode = 1;
    self->unk_0c = FX_Mul(p->info.unk_0a << 4, 0x19a) + 0x23d;
    a = Rand_PlusMinus(0x1000);
    self->unk_1c.x = Rand_PlusMinus(0x1000);
    self->unk_1c.z = a;
    self->unk_1c.y = 0;
    VEC_Normalize((&self->unk_1c), (&self->unk_1c));
    VEC_Normalize((&self->unk_1c), (&p->dir));
    p->pos.y = -0x32000;
    Ov015_SetXZ((s32 *)&p->pos, p->pos.x, p->pos.z);
    HitSphere_Link(&p->hit);
    self->unk_14 = p->info.unk_0c;
    self->unk_18 = p->info.unk_0e;
    self->step = 0;
    self->unk_10 = self->unk_18;
    return TRUE;
}

BOOL func_ov015_0220d7d0(Ov015FishState40 *self, Ov015Vec *out, Ov015Vec *pos);
void func_ov015_0220d328(Ov015FishState40 *self, Ov015Fish *o);
void func_ov015_0220d578(Ov015FishState40 *self, Ov015Fish *o);
extern char data_ov015_02212e20[];
extern char data_ov015_02212e34[];

static inline void Ov015_Turn(Ov015FishState40 *self, Ov015Vec *v) {
    s32 r;
    self->unk_34 = 0x3c;
    r = FX_Atan2(self->unk_28.z, self->unk_28.x);
    self->unk_38 = FX_Atan2(v->z, v->x) - r;
    if (self->unk_38 > 0x7fff) {
        self->unk_38 -= 0x7fff + 0x8000;
    }
}

/* A sub-object at p + 0x568 (not an ARM immediate). */
typedef struct {
    u8 pad[0x18];
    Ov015Vec dir;
} Ov015Sub568;

typedef struct {
    u8 pad[0x568];
    Ov015Sub568 sub;
} Ov015Owner568;

BOOL Ov015FishState40_Update(Ov015FishState40 *self, Ov015Fish *p) {
    Ov015Vec v0;
    Ov015Vec b;
    Ov015Vec a;
    Ov015Vec q;
    Ov015Vec n;
    Ov015Vec u;
    Ov015Vec w;
    Ov015Vec v1;
    Ov015Vec v3;
    Ov015Vec v2;
    Ov015Vec pos;
    s32 i;
    self->fish = p;
    if (self->unk_34 > 0) {
        s32 t = FX_Div(self->unk_34 << 12, 0x3c000);
        s32 s = self->unk_38;
        s32 x = self->unk_28.x;
        s32 ang = FX_Mul(-(s << 12), t) + (s << 12);
        s32 idx = (u16)(ang >> 12) >> 4;
        s32 sn = FX_SinCosTable_[idx * 2];
        s32 cs = FX_SinCosTable_[idx * 2 + 1];
        s32 z = self->unk_28.z;
        self->unk_1c.x = FX_Mul(x, cs) - FX_Mul(z, sn);
        self->unk_1c.y = 0;
        self->unk_1c.z = FX_Mul(x, sn) + FX_Mul(z, cs);
        self->unk_34--;
    } else {
        self->unk_34 = 0;
        if (p->hit.unk_44 != 0) {
            Ov015Sub568 *sub = &((Ov015Owner568 *)p)->sub;
            v0 = p->pos;
            VEC_MultAdd(self->unk_0c, (&self->unk_1c), &v0, &v0);
            p->pos = v0;
            self->unk_28.x = self->unk_1c.x;
            self->unk_28.z = self->unk_1c.z;
            self->unk_28.y = 0;
            VEC_Normalize((&self->unk_28), (&self->unk_28));
            a = sub->dir;
            VEC_Normalize(&a, &a);
            VEC_Add(&a, (&self->unk_1c), &b);
            b.y = 0;
            VEC_Normalize(&b, &b);
            Ov015_Turn(self, &b);
        } else {
            s32 dot;
            VEC_MultAdd(self->unk_0c, (&self->unk_1c), (&p->pos), &q);
            if (func_ov015_0220d7d0(self, &n, &q)) goto clamp;
            self->unk_28.x = self->unk_1c.x;
            self->unk_28.y = self->unk_1c.y;
            self->unk_28.z = self->unk_1c.z;
            w = p->dir;
            w.y = 0;
            VEC_Normalize(&w, &w);
            dot = (s32)(((s64)n.x * w.x + (s64)n.y * w.y + (s64)n.z * w.z + 0x800) >> 12);
            if (dot < 0) dot = -dot;
            VEC_MultAdd(dot * 2, &n, &w, &u);
            VEC_Normalize(&u, &u);
            Ov015_Turn(self, &u);
        }
    }
clamp:
    pos = p->pos;
    if (pos.x > p->maxX) {
        pos.x = 0x32000;
    } else if (pos.x < p->minX) {
        pos.x = -0x32000;
    }
    if (pos.z > p->maxZ) {
        pos.z = -0x4b000;
    } else if (pos.z < p->minZ) {
        pos.z = -0x8c000;
    }
    p->pos = pos;
    switch (self->step) {
    case 0: {
        BOOL found;
        p->unk_a8 = self->unk_0c;
        v1 = pos;
        VEC_MultAdd(self->unk_0c, (&self->unk_1c), &v1, &v1);
        VEC_Normalize((&self->unk_1c), (&p->dir));
        if (v1.y > -0x32000) {
            v1.y -= 0x80;
        } else {
            v1.y = -0x32000;
        }
        p->pos = v1;
        if (self->unk_10 == 0) {
            found = FALSE;
            for (i = 0; i < 1; i++) {
                if (data_ov015_02212db8[i] == NULL) {
                    found = TRUE;
                    data_ov015_02212db8[i] = self;
                    break;
                }
            }
            if (found) {
                self->step = 1;
                self->unk_10 = 0x5a;
                p->drawMode = 2;
            } else {
                self->unk_18 >>= 1;
                self->unk_10 = self->unk_18;
            }
        }
        break;
    }
    case 1:
        func_ov015_0220d328(self, p);
        if (self->unk_10 == 0) {
            self->step = 2;
            self->unk_10 = self->unk_14;
        }
        break;
    case 2: {
        EffectObj *e;
        p->unk_a8 = self->unk_0c;
        v2 = pos;
        VEC_MultAdd(self->unk_0c, (&self->unk_1c), &v2, &v2);
        if (v2.y < 0) {
            v2.y += 0x19a;
        } else {
            v2.y = 0;
        }
        p->pos = v2;
        VEC_Normalize((&self->unk_1c), (&p->dir));
        e = Effect_Find_020657b0(gEffectMgr, self->unk_08);
        if (e == NULL) {
            e = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e34, 0, &p->pos);
            e->unk_d4 = 3;
            e->unk_28 = 0;
            e->loopCount = -1;
            e->unk_50 = -0xc8000;
            self->unk_08 = e->id;
        }
        v3.x = p->pos.x;
        v3.y = p->pos.y > 0 ? 0 : p->pos.y;
        v3.z = p->pos.z;
        e->SetPos(&v3);
        e->SetScale(&p->scale);
        e->SetRotXYZ(0, FX_Atan2(p->dir.x, p->dir.z), 0);
        if (self->unk_10 == 0) {
            self->step = 3;
            self->unk_10 = 0x5a;
        }
        break;
    }
    case 3:
        func_ov015_0220d578(self, p);
        if (self->unk_10 == 0) {
            self->step = 0;
            self->unk_10 = self->unk_18 = p->info.unk_0e;
            p->drawMode = 1;
            Ov015_DeleteFound(gEffectMgr, self->unk_08);
            for (i = 0; i < 1; i++) {
                if (data_ov015_02212db8[i] == self) {
                    data_ov015_02212db8[i] = NULL;
                    break;
                }
            }
        }
        break;
    }
    self->fish = NULL;
    if (--self->unk_10 <= 0) {
        self->unk_10 = 0;
    }
    return TRUE;
}

}
