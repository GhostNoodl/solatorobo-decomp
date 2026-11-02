#include "ov015/ov015.h"

extern "C" {

extern void *data_ov015_02212db8[];
void func_0203f364(void *a);
extern void *data_02097e4c;
void *func_02049a48(void *a, int b, int c, int d, int e);
u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e34[];
s32 FX_Div(s32 a, s32 b);
void VEC_Normalize(void *src, void *dst);
void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
s32 Interp_SinLerp(s32 t, s32 a, s32 b);
u16 FX_Atan2(s32 x, s32 z);
extern u8 data_ov015_02212ecc[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e47[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void *func_ov000_02191318(void *a, s32 b);
extern u8 data_ov015_02212e68[];
extern u8 data_ov015_02212e0d[];
BOOL func_ov000_02191120(void *p);
void *Ov015FishState2c_Ctor(Ov015FishState2c *self);
void func_ov000_021915a0(void *a);

BOOL Ov015FishState40_Exit(Ov015FishState40 *self, Ov015Fish *p) {
    s32 i;
    p->unk_108 = 0;
    func_0203f364(&p->unk_568);
    Ov015_DeleteFound(data_0214a420, self->unk_08);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    return TRUE;
}

void func_ov015_0220d328(Ov015FishState40 *self, Ov015Fish *o) {
    Ov015Vec d;
    Ov015Vec p;
    Ov015Vec q;
    Ov015V *e;
    s32 t = 0x1000 - FX_Div(self->unk_10 << 12, 0x5a000);
    d = self->unk_1c;
    d.y = Ov015_FxMul(FX_SinCosTable_[((Ov015_FxMul(t, 0x7fff000) >> 12) >> 4) * 2], 0x800);
    VEC_Normalize(&d, &d);
    VEC_Normalize(&d, &o->unk_9c);
    p = o->unk_40;
    VEC_MultAdd(self->unk_0c, &self->unk_1c, &p, &p);
    p.y = Interp_SinLerp(t, -0x32000, 0x1ccd);
    if (p.y > 0) p.y = 0;
    o->unk_40 = p;
    o->unk_108 = 2;
    e = func_020657b0(data_0214a420, self->unk_08);
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, &o->unk_40);
        FLD(s32, e, 0xd4) = 3;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        self->unk_08 = FLD(void *, e, 0x24);
    }
    q.x = o->unk_40.x;
    q.y = o->unk_40.y > 0 ? 0 : o->unk_40.y;
    q.z = o->unk_40.z;
    e->v18(&q);
    e->v10(&o->unk_70);
    e->v34(0, FX_Atan2(o->unk_9c.x, o->unk_9c.z), 0);
    if (self->unk_10 == 0x3c) {
        func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x55, -1, -1, -1);
    }
}

void func_ov015_0220d578(Ov015FishState40 *self, Ov015Fish *o) {
    Ov015Vec d;
    Ov015Vec p;
    Ov015Vec q;
    Ov015V *e;
    s32 t = 0x1000 - FX_Div(self->unk_10 << 12, 0x5a000);
    d = self->unk_1c;
    d.y = Ov015_FxMul(FX_SinCosTable_[(((Ov015_FxMul(t, 0x7fff000) >> 12) + 0x7fff) >> 4) * 2], 0x800);
    VEC_Normalize(&d, &d);
    VEC_Normalize(&d, &o->unk_9c);
    p = o->unk_40;
    VEC_MultAdd(self->unk_0c, &self->unk_1c, &p, &p);
    p.y = Interp_SinLerp(t, 0x1ccd, -0x32000);
    if (p.y < -0x32000) p.y = -0x32000;
    o->unk_40 = p;
    o->unk_108 = 2;
    if (self->unk_10 == 0x3c) {
        func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x55, -1, -1, -1);
    }
    e = func_020657b0(data_0214a420, self->unk_08);
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, &o->unk_40);
        FLD(s32, e, 0xd4) = 3;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        self->unk_08 = FLD(void *, e, 0x24);
    }
    q.x = o->unk_40.x;
    q.y = o->unk_40.y > 0 ? 0 : o->unk_40.y;
    q.z = o->unk_40.z;
    e->v18(&q);
    e->v10(&o->unk_70);
    e->v34(0, FX_Atan2(o->unk_9c.x, o->unk_9c.z), 0);
}

static inline void Ov015_VecSet(Ov015Vec *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
BOOL func_ov015_0220d7d0(Ov015FishState40 *self, Ov015Vec *out, Ov015Vec *pos) {
    Ov015Fish *a = self->unk_3c;
    BOOL r = TRUE;
    if (pos->x > a->unk_b0) {
        Ov015_VecSet(out, -0x1000, 0, 0);
        r = FALSE;
    } else if (pos->x < a->unk_ac) {
        r = FALSE;
        Ov015_VecSet(out, 0x1000, 0, 0);
    } else if (pos->z > a->unk_b4) {
        r = FALSE;
        Ov015_VecSet(out, 0, 0, -0x1000);
    } else if (pos->z < a->unk_b8) {
        r = FALSE;
        Ov015_VecSet(out, 0, 0, 0x1000);
    } else {
        Ov015_VecSet(out, 0, 0, 0);
    }
    return r;
}

Ov015FishState08 *Ov015FishState08_Ctor(Ov015FishState08 *self) {
    SET_VT(self, data_ov015_02212ecc);
    self->unk_04 = 0;
    return self;
}

void *Ov015FishState08_Dtor(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *Ov015FishState08_DtorDelete(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    Heap_Free(self);
    return self;
}

BOOL Ov015FishState08_Enter(Ov015FishState08 *self, Ov015Fish *p) {
    Ov015VecC v;
    func_ov000_02190cb0(&p->unk_244, data_ov015_02212e47, 0x19a, 0);
    func_ov000_02191318(&p->unk_244, 0x7000);
    p->unk_104 = 0x800;
    v = *(Ov015VecC *)&p->unk_9c;
    v.y = 0;
    VEC_Normalize(&v, &p->unk_9c);
    self->unk_04 = 1;
    return TRUE;
}

BOOL Ov015FishState08_Update(Ov015FishState08 *self, Ov015Fish *p) {
    switch (self->unk_04) {
    case 1: {
        s32 z = p->unk_40.z;
        s32 x = p->unk_40.x;
        p->unk_108 = 0;
        p->unk_40.x = x;
        p->unk_40.y = 0;
        p->unk_40.z = z;
        if (p->unk_244.unk_c4 == 1) {
            u8 *o;
            Ov015Vec v;
            p->unk_244.unk_c4 = 0;
            v.x = x;
            v.z = z;
            v.y = 0;
            o = func_02066774(data_ov015_02212e20, data_ov015_02212e68, 0, &v);
            VCALL(o)->v10(&p->unk_70);
            FLD(s32, o, 0xd4) = 3;
            FLD(u8, o, 0x28) = 0;
            FLD(s32, o, 0x50) = -0xc8000;
            FLD(s32, o, 0x3c) = 0x800;
            func_02049a48(data_02097e4c, 0x1b, -1, -1, -1);
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (func_ov000_02191120(&p->unk_244)) {
            func_ov000_02190cb0(&p->unk_244, data_ov015_02212e0d, 0x19a, 0);
            p->unk_104 = 0x800;
            self->unk_04 = 2;
        }
        break;
    }
    case 2:
        if (func_ov000_02191120(&p->unk_244)) {
            void *q = Heap_Alloc(0x2c);
            if (q != NULL) {
                q = Ov015FishState2c_Ctor((Ov015FishState2c *)q);
            }
            p->unk_f0 = (Ov015V *)q;
            p->unk_ec = 2;
        }
        break;
    }
    return TRUE;
}

BOOL Ov015FishState08_Exit(u8 *self, Ov015Fish *p) {
    func_ov000_02190cb0(&p->unk_244, data_ov015_02212e0d, 0x19a, 0);
    p->unk_104 = 0x800;
    func_ov000_021915a0(&p->unk_244);
    p->unk_108 = 0;
    return TRUE;
}

extern u8 *data_02097d48;
u8 Gfx3DState_NextPolyId(void *p);
void MTX_Identity33_(void *a);
void MTX_Concat33(void *a, void *b, void *out);
void MI_Copy36B(const void *src, void *dst);
void MTX_RotX33_(void *mtx, s32 sin, s32 cos);
void MTX_RotY33_(void *mtx, s32 sin, s32 cos);
void NNS_G3dGlbSetBaseScale(const void *v);
void NNS_G3dGlbSetBaseTrans(const void *v);
void NNS_G3dGlbFlushVP(void);
void NNS_G3dMdlSetMdlAlpha(void *mdl, s32 a, s32 b);
void NNS_G3dMdlSetMdlPolygonID(void *mdl, s32 a, s32 b);
void NNS_G3dMdlSetMdlCullMode(void *mdl, s32 a, s32 b);
void NNS_G3dDraw1Mat1Shp(void *mdl, s32 a, s32 b, s32 c);
extern u8 data_020928b4[];
struct Ov015ResDict0daf4 {
    u8 revision;
    u8 num_entry;
    u16 size_dict;
    u16 unk_04;
    u16 ofs_entry;
};
struct Ov015ResEntry0daf4 {
    u16 size_unit;
    u16 size_data;
    u8 data[4];
};
struct Ov015MdlSet0daf4 {
    u8 unk_00[0x8];
    Ov015ResDict0daf4 dict;
};
Ov015MdlSet0daf4 *NNS_G3dGetMdlSet(void *file);
static inline void *Ov015_DictGet0daf4(const Ov015ResDict0daf4 *dict, u32 idx) {
    if (dict != NULL && idx < dict->num_entry) {
        const Ov015ResEntry0daf4 *entry = (const Ov015ResEntry0daf4 *)((const u8 *)dict + dict->ofs_entry);
        return (void *)((const u8 *)entry->data + entry->size_unit * idx);
    }
    return NULL;
}
static inline void *Ov015_GetMdl0daf4(Ov015MdlSet0daf4 *set, u32 idx) {
    u32 *data = (u32 *)Ov015_DictGet0daf4(&set->dict, idx);
    if (data != NULL) {
        return (u8 *)set + *data;
    } else {
        return NULL;
    }
}
static inline void *Ov015_Find0daf4(void *file, u32 idx) {
    Ov015MdlSet0daf4 *set = NNS_G3dGetMdlSet(file);
    if (set != NULL) {
        u32 *data = (u32 *)Ov015_DictGet0daf4(&set->dict, idx);
        if (data != NULL) {
            return (u8 *)set + *data;
        }
    }
    return NULL;
}
void func_ov015_0220daf4(Ov015Shadow *self, const Ov015Vec *pos, s32 sx, s32 sz, u16 ry, u16 rx) {
    if (self->mdl == NULL || self->type != self->prev) {
        if (self->res != NULL) {
            u32 idx = self->type;
            self->mdl = Ov015_Find0daf4(*(void **)self->res, idx);
        }
    }
    if (self->mdl == NULL) {
        return;
    }
    if (self->unk_10 > self->unk_0c) {
        return;
    }
    {
        Ov015Vec s;
        s.x = sx;
        s.y = 0x1000;
        s.z = sz;
        NNS_G3dGlbSetBaseScale(&s);
    }
    {
        Ov015VecC t(*(const Ov015VecC *)pos);
        if (self->type <= 1) {
            t.y += 0x800 - self->unk_10;
        } else {
            t.y += 0xcd - self->unk_10;
        }
        NNS_G3dGlbSetBaseTrans(&t);
    }
    {
        s32 m[9];
        BOOL f;
        f = FALSE;
        MTX_Identity33_(m);
        if (ry != 0) {
            MTX_RotY33_(m, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
            f = TRUE;
        }
        if (rx != 0) {
            if (f) {
                s32 m2[9];
                MTX_RotX33_(m2, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
                MTX_Concat33(m2, m, m);
            } else {
                MTX_RotX33_(m, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            }
        }
        MI_Copy36B(m, data_020928b4);
    }
    NNS_G3dGlb.fc &= ~0xa4;
    NNS_G3dGlbFlushVP();
    NNS_G3dMdlSetMdlAlpha(self->mdl, 0, self->alpha);
    if (self->type <= 1) {
        NNS_G3dMdlSetMdlPolygonID(self->mdl, 0, 0);
        NNS_G3dMdlSetMdlCullMode(self->mdl, 0, 1);
        NNS_G3dDraw1Mat1Shp(self->mdl, 0, 0, 1);
        NNS_G3dMdlSetMdlPolygonID(self->mdl, 0, 2);
        NNS_G3dMdlSetMdlCullMode(self->mdl, 0, 3);
        NNS_G3dDraw1Mat1Shp(self->mdl, 0, 0, 1);
    } else {
        NNS_G3dMdlSetMdlPolygonID(self->mdl, 0, Gfx3DState_NextPolyId(data_02097d48 + 0x8b0));
        NNS_G3dDraw1Mat1Shp(self->mdl, 0, 0, 1);
    }
}

}
