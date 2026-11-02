#include "ov015/ov015.h"

extern "C" {

extern void *data_ov015_02212db8[];
void HitSphere_Unlink_0203f364(void *a);
extern char data_ov015_02212e20[];
extern char data_ov015_02212e34[];
s32 Interp_SinLerp(s32 t, s32 a, s32 b);
extern u8 data_ov015_02212ecc[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e47[];
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
extern char data_ov015_02212e68[];
extern u8 data_ov015_02212e0d[];
BOOL Model0218fe1c_IsAnimDone(void *p);
void *Ov015FishState2c_Ctor(Ov015FishState2c *self);
void Model0218fe1c_SetLoop(void *a);

BOOL Ov015FishState40_Exit(Ov015FishState40 *self, Ov015Fish *p) {
    s32 i;
    p->drawMode = 0;
    HitSphere_Unlink_0203f364(&p->hit);
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
    EffectObj *e;
    s32 t = 0x1000 - FX_Div(self->unk_10 << 12, 0x5a000);
    d = self->unk_1c;
    d.y = FX_Mul(FX_SinCosTable_[((FX_Mul(t, 0x7fff000) >> 12) >> 4) * 2], 0x800);
    VEC_Normalize(&d, &d);
    VEC_Normalize(&d, (&o->dir));
    p = o->pos;
    VEC_MultAdd(self->unk_0c, (&self->unk_1c), &p, &p);
    p.y = Interp_SinLerp(t, -0x32000, 0x1ccd);
    if (p.y > 0) p.y = 0;
    o->pos = p;
    o->drawMode = 2;
    e = Effect_Find_020657b0(data_0214a420, self->unk_08);
    if (e == NULL) {
        e = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e34, 0, &o->pos);
        e->unk_d4 = 3;
        e->unk_28 = 0;
        e->loopCount = -1;
        e->unk_50 = -0xc8000;
        self->unk_08 = e->id;
    }
    q.x = o->pos.x;
    q.y = o->pos.y > 0 ? 0 : o->pos.y;
    q.z = o->pos.z;
    e->SetPos(&q);
    e->SetScale(&o->scale);
    e->SetRotXYZ(0, FX_Atan2(o->dir.x, o->dir.z), 0);
    if (self->unk_10 == 0x3c) {
        SndMgr_PlayVolume(data_02097e4c, 0x3e, -1, -1, -1);
        SndMgr_PlayVolume(data_02097e4c, 0x55, -1, -1, -1);
    }
}

void func_ov015_0220d578(Ov015FishState40 *self, Ov015Fish *o) {
    Ov015Vec d;
    Ov015Vec p;
    Ov015Vec q;
    EffectObj *e;
    s32 t = 0x1000 - FX_Div(self->unk_10 << 12, 0x5a000);
    d = self->unk_1c;
    d.y = FX_Mul(FX_SinCosTable_[(((FX_Mul(t, 0x7fff000) >> 12) + 0x7fff) >> 4) * 2], 0x800);
    VEC_Normalize(&d, &d);
    VEC_Normalize(&d, (&o->dir));
    p = o->pos;
    VEC_MultAdd(self->unk_0c, (&self->unk_1c), &p, &p);
    p.y = Interp_SinLerp(t, 0x1ccd, -0x32000);
    if (p.y < -0x32000) p.y = -0x32000;
    o->pos = p;
    o->drawMode = 2;
    if (self->unk_10 == 0x3c) {
        SndMgr_PlayVolume(data_02097e4c, 0x3e, -1, -1, -1);
        SndMgr_PlayVolume(data_02097e4c, 0x55, -1, -1, -1);
    }
    e = Effect_Find_020657b0(data_0214a420, self->unk_08);
    if (e == NULL) {
        e = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e34, 0, &o->pos);
        e->unk_d4 = 3;
        e->unk_28 = 0;
        e->loopCount = -1;
        e->unk_50 = -0xc8000;
        self->unk_08 = e->id;
    }
    q.x = o->pos.x;
    q.y = o->pos.y > 0 ? 0 : o->pos.y;
    q.z = o->pos.z;
    e->SetPos(&q);
    e->SetScale(&o->scale);
    e->SetRotXYZ(0, FX_Atan2(o->dir.x, o->dir.z), 0);
}

static inline void Ov015_VecSet(Ov015Vec *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
BOOL func_ov015_0220d7d0(Ov015FishState40 *self, Ov015Vec *out, Ov015Vec *pos) {
    Ov015Fish *a = self->fish;
    BOOL r = TRUE;
    if (pos->x > a->maxX) {
        Ov015_VecSet(out, -0x1000, 0, 0);
        r = FALSE;
    } else if (pos->x < a->minX) {
        r = FALSE;
        Ov015_VecSet(out, 0x1000, 0, 0);
    } else if (pos->z > a->maxZ) {
        r = FALSE;
        Ov015_VecSet(out, 0, 0, -0x1000);
    } else if (pos->z < a->minZ) {
        r = FALSE;
        Ov015_VecSet(out, 0, 0, 0x1000);
    } else {
        Ov015_VecSet(out, 0, 0, 0);
    }
    return r;
}

Ov015FishState08 *Ov015FishState08_Ctor(Ov015FishState08 *self) {
    SET_VT(self, data_ov015_02212ecc);
    self->step = 0;
    return self;
}

void *Ov015FishState08_Dtor(Ov015FishState08 *self) {
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *Ov015FishState08_DtorDelete(Ov015FishState08 *self) {
    SET_VT(self, data_ov015_02212eb0);
    Heap_Free(self);
    return self;
}

BOOL Ov015FishState08_Enter(Ov015FishState08 *self, Ov015Fish *p) {
    Ov015Vec v;
    Model0218fe1c_SetAnim(&p->model, data_ov015_02212e47, 0x19a, 0);
    Model0218fe1c_SetAnimFrame(&p->model, 0x7000);
    p->animSpeed = 0x800;
    v = *(Ov015Vec *)&p->dir;
    v.y = 0;
    VEC_Normalize(&v, (&p->dir));
    self->step = 1;
    return TRUE;
}

BOOL Ov015FishState08_Update(Ov015FishState08 *self, Ov015Fish *p) {
    switch (self->step) {
    case 1: {
        s32 z = p->pos.z;
        s32 x = p->pos.x;
        p->drawMode = 0;
        p->pos.x = x;
        p->pos.y = 0;
        p->pos.z = z;
        if (p->model.unk_c4 == 1) {
            EffectObj *o;
            Ov015Vec v;
            p->model.unk_c4 = 0;
            v.x = x;
            v.z = z;
            v.y = 0;
            o = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e68, 0, &v);
            o->SetScale(&p->scale);
            o->unk_d4 = 3;
            o->unk_28 = 0;
            o->unk_50 = -0xc8000;
            o->speed = 0x800;
            SndMgr_PlayVolume(data_02097e4c, 0x1b, -1, -1, -1);
            SndMgr_PlayVolume(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (Model0218fe1c_IsAnimDone(&p->model)) {
            Model0218fe1c_SetAnim(&p->model, data_ov015_02212e0d, 0x19a, 0);
            p->animSpeed = 0x800;
            self->step = 2;
        }
        break;
    }
    case 2:
        if (Model0218fe1c_IsAnimDone(&p->model)) {
            void *q = Heap_Alloc(0x2c);
            if (q != NULL) {
                q = Ov015FishState2c_Ctor((Ov015FishState2c *)q);
            }
            p->nextState = (VObj *)q;
            p->nextStateId = 2;
        }
        break;
    }
    return TRUE;
}

BOOL Ov015FishState08_Exit(u8 *self, Ov015Fish *p) {
    Model0218fe1c_SetAnim(&p->model, data_ov015_02212e0d, 0x19a, 0);
    p->animSpeed = 0x800;
    Model0218fe1c_SetLoop(&p->model);
    p->drawMode = 0;
    return TRUE;
}

u8 Gfx3DState_NextPolyId(void *p);
void NNS_G3dMdlSetMdlAlpha(void *mdl, s32 a, s32 b);
void NNS_G3dMdlSetMdlPolygonID(void *mdl, s32 a, s32 b);
void NNS_G3dMdlSetMdlCullMode(void *mdl, s32 a, s32 b);
void NNS_G3dDraw1Mat1Shp(void *mdl, s32 a, s32 b, s32 c);
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
    Ov015MdlSet0daf4 *set = (Ov015MdlSet0daf4 *)NNS_G3dGetMdlSet((NNSG3dResFileHeader *)file);
    if (set != NULL) {
        u32 *data = (u32 *)Ov015_DictGet0daf4(&set->dict, idx);
        if (data != NULL) {
            return (u8 *)set + *data;
        }
    }
    return NULL;
}
void Ov015Shadow_DrawAt(Ov015Shadow *self, const Ov015Vec *pos, s32 sx, s32 sz, u16 ry, u16 rx) {
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
        Ov015Vec t(*(const Ov015Vec *)pos);
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
        MTX_Identity33_((MtxFx33 *)m);
        if (ry != 0) {
            MTX_RotY33_((MtxFx33 *)m, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
            f = TRUE;
        }
        if (rx != 0) {
            if (f) {
                s32 m2[9];
                MTX_RotX33_((MtxFx33 *)m2, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
                MTX_Concat33((MtxFx33 *)m2, (MtxFx33 *)m, (MtxFx33 *)m);
            } else {
                MTX_RotX33_((MtxFx33 *)m, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            }
        }
        MI_Copy36B(m, data_020928b4);
    }
    NNS_G3dGlb.flag &= ~0xa4;
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
        NNS_G3dMdlSetMdlPolygonID(self->mdl, 0, Gfx3DState_NextPolyId(data_02097d48->unk_8b0));
        NNS_G3dDraw1Mat1Shp(self->mdl, 0, 0, 1);
    }
}

}
