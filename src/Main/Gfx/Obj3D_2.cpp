// Built at optimization level 3: at O4 the 0xc/0xd/0xe test in func_020528ec
// becomes a range check that the target doesn't have.
#pragma optimization_level 3

#include "Main/Gfx/Obj3D.h"

class Obj3DAnimCls;
struct Obj3DAnimSlot;

// Per-state handler of an animation slot (pointer to member of the owner).
typedef s32 (Obj3DAnimCls::*Obj3DAnimHandler)(s32 state, struct Obj3DAnimSlot *slot);

extern "C" {

extern int func_02043d48(void *obj);
extern s8 data_02149ef4;

void func_02051f3c(Obj3DLayer *layer, u32 v);

void func_020520fc(Obj3DRender *render) {
    GfxSys *sys;
    s32 limit;
    u32 attr;
    u32 alpha;
    Obj3DMtl *mtl;
    mtl = render->mtl;
    attr = mtl->polyAttr;
    alpha = (attr & 0x1f0000) >> 16;
    sys = data_02097d48;
    limit = data_02149ef4;
    if ((u32)limit < alpha) {
        alpha = limit;
    }
    if (alpha > 30) {
        alpha = 30;
    }
    mtl->polyAttr = (attr & 0xc0e0ffbf) | 0xc0 | (alpha << 16) | (func_02043d48(sys->unk_8b0) << 24);
}

void func_02052160(Obj3DRender *render) {
    render->callback = func_020520fc;
    render->callbackMode = 2;
}

// 0x138-byte model resource.
typedef struct Obj3DAnimMdl {
    /* 0x00 */ s16 frame;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 flags;
    /* 0x04 */ u8 unk_04[0xc];
    /* 0x10 */ char arc0[0x20];
    /* 0x30 */ char name0[0x1c];
    /* 0x4c */ char arc1[0x20];
    /* 0x6c */ char name1[0x20];
} Obj3DAnimMdl;

// 0xe8-byte render object.
typedef struct Obj3DAnimObj {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ void *mdl;
    /* 0x08 */ u8 unk_08[0x1c];
    /* 0x24 */ u8 renderObj[0x90];
    /* 0xb4 */ u16 unk_b4;
    /* 0xb6 */ u8 unk_b6[0xc];
    /* 0xc2 */ u16 unk_c2_0 : 5;
    /* 0xc2 */ u16 unk_c2_5 : 1;
    /* 0xc2 */ u16 unk_c2_6 : 10;
} Obj3DAnimObj;

typedef struct Obj3DAnimSlot {
    /* 0x00 */ u32 b0 : 1;
    /* 0x00 */ u32 b1 : 1;
    /* 0x00 */ u32 b2 : 1;
    /* 0x00 */ u32 b3 : 29;
    /* 0x04 */ s32 state;
    /* 0x08 */ u16 idx;
    /* 0x0a */ u16 cur;
    /* 0x0c */ u16 next;
    /* 0x10 */ Obj3DAnimMdl *mdl;
    /* 0x14 */ Obj3DAnimObj *obj;
    /* 0x18 */ Obj3DAnimMdl *oldMdl;
    /* 0x1c */ Obj3DAnimObj *oldObj;
    /* 0x20 */ s32 ofsX;
    /* 0x24 */ s32 ofsY;
    /* 0x28 */ s32 ofsZ;
    /* 0x2c */ u8 unk_2c[0x14];
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ u8 unk_48;
    /* 0x49 */ u8 unk_49[3];
} Obj3DAnimSlot; // size 0x4c

typedef struct Obj3DAnimGroupObj {
    /* 0x00 */ u8 unk_00[0xfc];
    /* 0xfc */ s32 x;
} Obj3DAnimGroupObj;

typedef struct Obj3DAnimGroup {
    /* 0x000 */ u32 unk_00_0 : 22;
    /* 0x000 */ u32 flip : 1;
    /* 0x000 */ u32 unk_00_23 : 9;
    /* 0x004 */ u8 unk_04[4];
    /* 0x008 */ u16 dir;
    /* 0x00a */ u8 unk_0a[0x22];
    /* 0x02c */ Obj3DAnimGroupObj *unk_2c;
    /* 0x030 */ u8 unk_030[0x14];
    /* 0x044 */ Obj3DAnimSlot slots[3];
    /* 0x128 */ u8 unk_128[0x20];
} Obj3DAnimGroup; // size 0x148

typedef struct Obj3DAnim {
    /* 0x000 */ u8 unk_000[0xb8];
    /* 0x0b8 */ u32 unk_b8_0 : 9;
    /* 0x0b8 */ u32 hasExtra : 1;
    /* 0x0b8 */ u32 unk_b8_10 : 22;
    /* 0x0bc */ struct {
        /* 0x000 */ u8 unk_000[0x368];
        /* 0x368 */ Obj3DAnimSlot extra[2];
        /* 0x400 */ Obj3DAnimGroup groups[5];
    } sub;
} Obj3DAnim;

typedef struct Obj3DAnimEnt {
    /* 0x00 */ const char *name;
    /* 0x04 */ u8 flip;
    /* 0x06 */ s16 ofs;
    /* 0x08 */ u8 unk_08[4];
    /* 0x0c */ Obj3DAnimHandler fn;
} Obj3DAnimEnt; // size 0x14

extern const Obj3DAnimEnt data_0208bc80[];
extern const char *data_0208cb80;
extern char data_0208ba17[];
extern char data_0208ba1b[];

extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern BOOL func_0203e688(Obj3DAnimObj *o);
extern char *STD_CopyString(char *dst, const char *src);
extern s32 FX_Div(s32 a, s32 b);
extern Obj3DAnimMdl *func_ov000_0218e9c4(void *p);
extern void func_ov000_0218ea20(void *p);
extern BOOL func_ov000_0218f110(Obj3DAnimMdl *m);
extern Obj3DAnimObj *func_ov000_0218fe1c(void *p);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ffdc(Obj3DAnimObj *a, Obj3DAnimMdl *b, s32 c, s32 d);
extern void func_ov000_02190a80(Obj3DAnimObj *a, s32 b);
extern void func_ov000_02190cb0(Obj3DAnimObj *a, const char *b, s32 c, s32 d);
extern BOOL func_ov000_02191120(Obj3DAnimObj *a);
extern void func_ov000_021915a0(Obj3DAnimObj *a);
extern void func_ov000_02191618(Obj3DAnimObj *a);
extern void NNS_G3dRenderObjSetInitFunc(void *ro, void (*fn)(Obj3DRender *));
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, u32 mat, u32 mask);
extern void NNSi_G3dModifyMatFlag(void *mdl, u32 mat, u32 flag);

void func_0205221c(Obj3DAnim *anim, int kind, Obj3DAnimSlot *slot);

void func_02052178(Obj3DAnim *anim) {
    Obj3DAnimGroup *g;
    int i;
    int j;
    if (anim->hasExtra == 1) {
        func_0205221c(anim, 1, &anim->sub.extra[0]);
    }
    for (i = 0; i < 3; i++) {
        g = anim->sub.groups;
        for (j = 0; j < 5; j++, g++) {
            Obj3DAnimSlot *slot = &g->slots[i];
            slot->idx = j;
            func_0205221c(anim, i, slot);
        }
    }
    if (anim->hasExtra == 1) {
        func_0205221c(anim, 2, &anim->sub.extra[1]);
    }

}

static inline Obj3DAnimMdl *AnimMdl_New(void) {
    void *p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    return (Obj3DAnimMdl *)p;
}

static inline Obj3DAnimObj *AnimObj_New(void) {
    void *p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    return (Obj3DAnimObj *)p;
}

static inline void AnimMdl_Set0(Obj3DAnimMdl *m, const char *name) {
    STD_CopyString(m->arc0, data_0208cb80);
    STD_CopyString(m->name0, name);
    m->flags |= 2;
}

static inline void AnimMdl_Set1(Obj3DAnimMdl *m, const char *name) {
    STD_CopyString(m->arc1, data_0208cb80);
    STD_CopyString(m->name1, name);
    m->flags |= 4;
}



static inline s32 FxMulL(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline void AnimSlot_DeleteObj(Obj3DAnimSlot *slot) {
    Obj3DAnimObj *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->obj;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218fee4(p);
                func_0203de1c(p);
            }
            slot->obj = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_DeleteMdl(Obj3DAnimSlot *slot) {
    Obj3DAnimMdl *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->mdl;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218ea20(p);
                func_0203de1c(p);
            }
            slot->mdl = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_SetupObj(Obj3DAnimSlot *slot) {
    Obj3DAnimObj *o;
    void *mdl;
    slot->obj = AnimObj_New();
    func_ov000_0218ffdc(slot->obj, slot->mdl, 0, 1);
    slot->obj->unk_b4 = 0;
    o = slot->obj;
    NNS_G3dRenderObjSetInitFunc(o->renderObj, func_02052160);
    o->unk_c2_5 = 0;
    func_ov000_02191618(slot->obj);
    mdl = slot->obj->mdl;
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x8000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x1f0000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x3f000000);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x400);
}


static inline void AnimSlot_SetupObjS(Obj3DAnimSlot *slot, const char *seq) {
    Obj3DAnimObj *o;
    void *mdl;
    slot->obj = AnimObj_New();
    func_ov000_0218ffdc(slot->obj, slot->mdl, 0, 1);
    func_ov000_02190cb0(slot->obj, seq, 0, 1);
    slot->obj->unk_b4 = 0;
    o = slot->obj;
    NNS_G3dRenderObjSetInitFunc(o->renderObj, func_02052160);
    o->unk_c2_5 = 0;
    func_ov000_02191618(slot->obj);
    mdl = slot->obj->mdl;
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x8000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x1f0000);
    NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x3f000000);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(mdl, 1, 0x400);
}


static inline s32 AnimSlot_Call(Obj3DAnim *anim, Obj3DAnimSlot *slot, u16 id, s32 state) {
    return (((Obj3DAnimCls *)anim)->*data_0208bc80[id].fn)(state, slot);
}

static inline void AnimSlot_DeleteOldObj(Obj3DAnimSlot *slot) {
    Obj3DAnimObj *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->oldObj;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218fee4(p);
                func_0203de1c(p);
            }
            slot->oldObj = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_DeleteOldMdl(Obj3DAnimSlot *slot) {
    Obj3DAnimMdl *p;
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        p = slot->oldMdl;
        if (p != NULL) {
            if (p != NULL) {
                func_ov000_0218ea20(p);
                func_0203de1c(p);
            }
            slot->oldMdl = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

static inline void AnimSlot_Start(Obj3DAnim *anim, Obj3DAnimSlot *slot) {
    if (slot->next == 0xffff) {
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
    } else {
        slot->oldMdl = slot->mdl;
        slot->mdl = NULL;
        slot->oldObj = slot->obj;
        slot->obj = NULL;
        slot->state = 0;
    }
    slot->unk_44 = 0;
    slot->unk_48 = 0x1e;
    slot->cur = slot->next;
    slot->next = 0xffff;
    slot->b1 = 0;
    AnimSlot_Call(anim, slot, slot->cur, 7);
}

void func_0205221c(Obj3DAnim *anim, int kind, Obj3DAnimSlot *slot) {
    if (slot->b2 == 1) {
        AnimSlot_Call(anim, slot, slot->next, 5);
        slot->b2 = 0;
    }
    if (slot->mdl != NULL) {
        func_ov000_0218f110(slot->mdl);
        if (slot->mdl->frame < 0) {
            if (slot->obj == NULL) {
                AnimSlot_Call(anim, slot, slot->next, 6);
            } else if (func_0203e688(slot->obj)) {
                slot->b1 = 1;
            }
        }
    }
    if (slot->cur == 0xffff) {
        if (!slot->b1) {
            return;
        }
        AnimSlot_Start(anim, slot);
    }
    if (kind == 0 && anim->sub.groups[slot->idx].unk_2c == NULL) {
        return;
    }
    if (slot->oldObj == NULL) {
        return;
    }
    slot->state = (((Obj3DAnimCls *)anim)->*data_0208bc80[slot->cur].fn)(slot->state, slot);
    if (slot->state == 8) {
        AnimSlot_DeleteOldObj(slot);
        AnimSlot_DeleteOldMdl(slot);
        slot->cur = 0xffff;
        if (slot->b1) {
            AnimSlot_Start(anim, slot);
        }
    }
    slot->unk_40 += 0x1000;
}

s32 func_02052628(Obj3DAnim *anim, s32 state, Obj3DAnimSlot *slot) {
    const char *name;
    switch (state) {
    case 5: {
        const Obj3DAnimEnt *ent = &data_0208bc80[slot->next];
        Obj3DAnimMdl *m;
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
        m = AnimMdl_New();
        slot->mdl = m;
        name = ent->name;
        AnimMdl_Set0(m, name);
        AnimMdl_Set1(slot->mdl, ent->name);
        slot->mdl->frame = 0;
        if (slot->oldObj != NULL) {
            slot->state = 2;
        }
        return state;
    }
    case 6:
        AnimSlot_SetupObjS(slot, data_0208ba17);
        return state;
    case 0:
        if (func_ov000_02191120(slot->oldObj)) {
            state = 1;
            func_ov000_02190cb0(slot->oldObj, data_0208ba1b, 0, 1);
            func_ov000_021915a0(slot->oldObj);
        }
        break;
    case 1:
        slot->unk_44 += 0x1000;
        break;
    case 2:
    case 4:
        state = 8;
        break;
    }
    func_ov000_02190a80(slot->oldObj, 0x1000);
    return state;
}


s32 func_020528ec(Obj3DAnim *anim, s32 state, Obj3DAnimSlot *slot) {
    s32 r;
    switch (state) {
    case 5: {
        const Obj3DAnimEnt *ent = &data_0208bc80[slot->next];
        Obj3DAnimMdl *m;
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
        m = AnimMdl_New();
        slot->mdl = m;
        AnimMdl_Set0(m, ent->name);
        slot->mdl->frame = 0;
        if (slot->oldObj != NULL) {
            slot->state = 2;
        }
        return state;
    }
    case 6:
        AnimSlot_SetupObj(slot);
        return state;
    case 7:
        slot->unk_48 = 0;
        return state;
    case 0:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 1;
        }
        slot->unk_48 = FxMulL(r, 0x1e000) >> 12;
        break;
    case 1:
        if (slot->cur == 0xc || slot->cur == 0xd || slot->cur == 0xe) {
            slot->unk_48 = 0x1e;
        }
        break;
    case 2:
        slot->unk_44 = 0;
        state = 3;
    case 3:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 4;
        }
        slot->unk_48 = FxMulL(0x1000 - r, 0x1e000) >> 12;
        break;
    case 4:
        state = 8;
        break;
    }
    func_ov000_02190a80(slot->oldObj, 0x1000);
    return state;
}


static inline s32 AnimGroup_OfsX(Obj3DAnimGroup *g, const Obj3DAnimEnt *ent) {
    s32 x = g->unk_2c->x;
    s32 ofs = ent->ofs;
    if (g->dir == 0x1000) {
        if (g->flip) {
            x = ent->flip ? x - (ofs << 12) : x + (ofs << 12);
        } else {
            x += ofs << 12;
        }
    } else {
        if (g->flip) {
            x -= ofs << 12;
        } else {
            x = ent->flip ? x - (ofs << 12) : x + (ofs << 12);
        }
    }
    return x;
}

static inline void AnimSlot_CalcOfs(Obj3DAnimSlot *slot, Obj3DAnimGroup *g, const Obj3DAnimEnt *ent) {
    if (g->unk_2c != NULL) {
        slot->ofsX = AnimGroup_OfsX(g, ent);
    }
}

s32 func_02052bec(Obj3DAnim *anim, s32 state, Obj3DAnimSlot *slot) {
    const char *name;
    s32 r;
    BOOL is10 = FALSE;
    if (slot->cur == 0x10) {
        is10 = TRUE;
    }
    slot->ofsX = 0;
    slot->ofsY = 0;
    slot->ofsZ = 0;
    if (is10) {
        AnimSlot_CalcOfs(slot, &anim->sub.groups[slot->idx], &data_0208bc80[slot->cur]);
    }
    switch (state) {
    case 5: {
        const Obj3DAnimEnt *ent = &data_0208bc80[slot->next];
        Obj3DAnimMdl *m;
        AnimSlot_DeleteObj(slot);
        AnimSlot_DeleteMdl(slot);
        m = AnimMdl_New();
        slot->mdl = m;
        name = ent->name;
        AnimMdl_Set0(m, name);
        AnimMdl_Set1(slot->mdl, ent->name);
        slot->mdl->frame = 0;
        if (slot->oldObj != NULL) {
            slot->state = 2;
        }
        return state;
    }
    case 6: {
        Obj3DAnimObj *o;
        void *mdl;
        slot->obj = AnimObj_New();
        func_ov000_0218ffdc(slot->obj, slot->mdl, 0, 1);
        func_ov000_02190cb0(slot->obj, data_0208ba1b, 0, 1);
        slot->obj->unk_b4 = 0;
        o = slot->obj;
        NNS_G3dRenderObjSetInitFunc(o->renderObj, func_02052160);
        o->unk_c2_5 = 0;
        func_ov000_021915a0(slot->obj);
        mdl = slot->obj->mdl;
        NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x8000);
        NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x1f0000);
        NNSi_G3dModifyPolygonAttrMask(mdl, 1, 0x3f000000);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x40);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x80);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x200);
        NNSi_G3dModifyMatFlag(mdl, 1, 0x400);
        return state;
    }
    case 7:
        slot->unk_48 = 0;
        return state;
    case 0:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 1;
        }
        slot->unk_48 = FxMulL(r, 0x1e000) >> 12;
        break;
    case 1:
        slot->unk_48 = 0x1e;
        slot->unk_44 += 0x1000;
        break;
    case 2:
        slot->unk_44 = 0;
        state = 3;
    case 3:
        slot->unk_44 += 0x1000;
        r = FX_Div(slot->unk_44, 0x8000);
        if (r >= 0x1000) {
            r = 0x1000;
            state = 4;
        }
        slot->unk_48 = FxMulL(0x1000 - r, 0x1e000) >> 12;
        break;
    case 4:
        state = 8;
        break;
    }
    func_ov000_02190a80(slot->oldObj, 0x1000);
    return state;
}

s32 func_020534c4(s32 x);

s32 func_020534d4(void);

}
