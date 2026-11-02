#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212ee8[];
extern u8 data_ov015_02212eb0[];
extern void *data_ov015_02212db8[];
extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);
extern u8 data_ov015_02212e0d[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 func_02040528(s32 max);
void VEC_Normalize(void *src, void *dst);
void func_0203f324(void *a);

Ov015FishState40 *Ov015FishState40_Ctor(Ov015FishState40 *self) {
    SET_VT(self, data_ov015_02212ee8);
    self->unk_04 = 0;
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
    Ov015V *o;
    u32 saved;
    SET_VT(self, data_ov015_02212ee8);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = func_020657b0(data_0214a420, self->unk_08);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, data_ov015_02212eb0);

    return self;
}

void *Ov015FishState40_DtorDelete(Ov015FishState40 *self) {
    s32 i;
    Ov015V *o;
    u32 saved;
    SET_VT(self, data_ov015_02212ee8);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = func_020657b0(data_0214a420, self->unk_08);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

static inline void Ov015_SetXZ(s32 *v, s32 x, s32 z) { v[0] = x; v[2] = z; }
BOOL Ov015FishState40_Enter(Ov015FishState40 *self, Ov015Fish *p) {
    s32 a;
    s32 x, z;
    func_ov000_02190cb0(&p->unk_244, data_ov015_02212e0d, 0x19a, 0);
    p->unk_104 = 0x59a;
    func_ov000_021915a0(&p->unk_244);
    p->unk_108 = 1;
    self->unk_0c = Ov015_FxMul(p->unk_c0.unk_0a << 4, 0x19a) + 0x23d;
    a = func_02040528(0x1000);
    self->unk_1c.x = func_02040528(0x1000);
    self->unk_1c.z = a;
    self->unk_1c.y = 0;
    VEC_Normalize(&self->unk_1c, &self->unk_1c);
    VEC_Normalize(&self->unk_1c, &p->unk_9c);
    p->unk_40.y = -0x32000;
    Ov015_SetXZ((s32 *)&p->unk_40, p->unk_40.x, p->unk_40.z);
    func_0203f324(&p->unk_568);
    self->unk_14 = p->unk_c0.unk_0c;
    self->unk_18 = p->unk_c0.unk_0e;
    self->unk_04 = 0;
    self->unk_10 = self->unk_18;
    return TRUE;
}

s32 FX_Div(s32 a, s32 b);
void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Add(const void *a, const void *b, void *out);
u16 FX_Atan2(s32 x, s32 z);
BOOL func_ov015_0220d7d0(Ov015FishState40 *self, Ov015Vec *out, Ov015Vec *pos);
void func_ov015_0220d328(Ov015FishState40 *self, Ov015Fish *o);
void func_ov015_0220d578(Ov015FishState40 *self, Ov015Fish *o);
u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e34[];

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
    self->unk_3c = p;
    if (self->unk_34 > 0) {
        s32 t = FX_Div(self->unk_34 << 12, 0x3c000);
        s32 s = self->unk_38;
        s32 x = self->unk_28.x;
        s32 ang = Ov015_FxMul(-(s << 12), t) + (s << 12);
        s32 idx = (u16)(ang >> 12) >> 4;
        s32 sn = FX_SinCosTable_[idx * 2];
        s32 cs = FX_SinCosTable_[idx * 2 + 1];
        s32 z = self->unk_28.z;
        self->unk_1c.x = Ov015_FxMul(x, cs) - Ov015_FxMul(z, sn);
        self->unk_1c.y = 0;
        self->unk_1c.z = Ov015_FxMul(x, sn) + Ov015_FxMul(z, cs);
        self->unk_34--;
    } else {
        self->unk_34 = 0;
        if (p->unk_568.unk_44 != 0) {
            Ov015Sub568 *sub = &((Ov015Owner568 *)p)->sub;
            v0 = p->unk_40;
            VEC_MultAdd(self->unk_0c, &self->unk_1c, &v0, &v0);
            p->unk_40 = v0;
            self->unk_28.x = self->unk_1c.x;
            self->unk_28.z = self->unk_1c.z;
            self->unk_28.y = 0;
            VEC_Normalize(&self->unk_28, &self->unk_28);
            a = sub->dir;
            VEC_Normalize(&a, &a);
            VEC_Add(&a, &self->unk_1c, &b);
            b.y = 0;
            VEC_Normalize(&b, &b);
            Ov015_Turn(self, &b);
        } else {
            s32 dot;
            VEC_MultAdd(self->unk_0c, &self->unk_1c, &p->unk_40, &q);
            if (func_ov015_0220d7d0(self, &n, &q)) goto clamp;
            self->unk_28.x = self->unk_1c.x;
            self->unk_28.y = self->unk_1c.y;
            self->unk_28.z = self->unk_1c.z;
            w = p->unk_9c;
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
    pos = p->unk_40;
    if (pos.x > p->unk_b0) {
        pos.x = 0x32000;
    } else if (pos.x < p->unk_ac) {
        pos.x = -0x32000;
    }
    if (pos.z > p->unk_b4) {
        pos.z = -0x4b000;
    } else if (pos.z < p->unk_b8) {
        pos.z = -0x8c000;
    }
    p->unk_40 = pos;
    switch (self->unk_04) {
    case 0: {
        BOOL found;
        p->unk_a8 = self->unk_0c;
        v1 = pos;
        VEC_MultAdd(self->unk_0c, &self->unk_1c, &v1, &v1);
        VEC_Normalize(&self->unk_1c, &p->unk_9c);
        if (v1.y > -0x32000) {
            v1.y -= 0x80;
        } else {
            v1.y = -0x32000;
        }
        p->unk_40 = v1;
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
                self->unk_04 = 1;
                self->unk_10 = 0x5a;
                p->unk_108 = 2;
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
            self->unk_04 = 2;
            self->unk_10 = self->unk_14;
        }
        break;
    case 2: {
        Ov015V *e;
        p->unk_a8 = self->unk_0c;
        v2 = pos;
        VEC_MultAdd(self->unk_0c, &self->unk_1c, &v2, &v2);
        if (v2.y < 0) {
            v2.y += 0x19a;
        } else {
            v2.y = 0;
        }
        p->unk_40 = v2;
        VEC_Normalize(&self->unk_1c, &p->unk_9c);
        e = func_020657b0(data_0214a420, self->unk_08);
        if (e == NULL) {
            e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, &p->unk_40);
            FLD(s32, e, 0xd4) = 3;
            FLD(u8, e, 0x28) = 0;
            FLD(s32, e, 0xc8) = -1;
            FLD(s32, e, 0x50) = -0xc8000;
            self->unk_08 = FLD(void *, e, 0x24);
        }
        v3.x = p->unk_40.x;
        v3.y = p->unk_40.y > 0 ? 0 : p->unk_40.y;
        v3.z = p->unk_40.z;
        e->v18(&v3);
        e->v10(&p->unk_70);
        e->v34(0, FX_Atan2(p->unk_9c.x, p->unk_9c.z), 0);
        if (self->unk_10 == 0) {
            self->unk_04 = 3;
            self->unk_10 = 0x5a;
        }
        break;
    }
    case 3:
        func_ov015_0220d578(self, p);
        if (self->unk_10 == 0) {
            self->unk_04 = 0;
            self->unk_10 = self->unk_18 = p->unk_c0.unk_0e;
            p->unk_108 = 1;
            Ov015_DeleteFound(data_0214a420, self->unk_08);
            for (i = 0; i < 1; i++) {
                if (data_ov015_02212db8[i] == self) {
                    data_ov015_02212db8[i] = NULL;
                    break;
                }
            }
        }
        break;
    }
    self->unk_3c = NULL;
    if (--self->unk_10 <= 0) {
        self->unk_10 = 0;
    }
    return TRUE;
}

}
