#include "Main/Effect/Effect.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

// The TU's .bss objects (polygon ID base, polygon ID counter, manager), all reached through the
// 0x0214a41c pool literal plus offsets. They are defined before the first function, which
// already reads them that way; MWCC lays out same-size definitions made before the first
// function in reverse, so the counter is written first.
u8 data_0214a41d;
u8 data_0214a41c;
EffectMgr *data_0214a420;

u8 func_0206379c(void) {
    return Effect_NextPolyId();
}

static inline BOOL Effect_Prepare(EffectObj *obj) {
    switch (obj->state) {
    case 0:
        if (!obj->Load()) {
            break;
        }
        obj->state = 2;
    case 2:
        if (obj->Setup()) {
            obj->state = 1;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL func_020637d0(EffectObj *obj) {
    BOOL ret = TRUE;
    if (obj->paused) {
        return ret;
    }
    switch (obj->state) {
    default:
        if (!Effect_Prepare(obj)) {
            break;
        }
        if (obj->onStart != NULL) {
            obj->onStart(obj);
        }
        obj->state = 3;
    case 3:
        if (obj->time < 0) {
            obj->prevTime = obj->time;
            obj->time = obj->time + obj->speed;
            break;
        }
        if (obj->onUpdate != NULL) {
            obj->onUpdate(obj);
        }
        func_02063cac(obj);
        if (!obj->Step()) {
            if (obj->loopCount != 0) {
                if (obj->loopStart < obj->time) {
                    obj->time = obj->loopStart;
                    obj->prevTime = obj->loopStart - obj->speed;
                }
                obj->loopCount = obj->loopCount > 0 ? obj->loopCount - 1 : obj->loopCount;
                obj->Loop();
            } else {
                obj->state = 4;
            }
        } else {
            obj->prevTime = obj->time;
            obj->time = obj->time + obj->speed;
        }
        break;
    case 4:
        ret = FALSE;
        break;
    }
    return ret;
}

BOOL func_02063944(EffectObj *obj) {
    return TRUE;
}

BOOL func_0206394c(EffectObj *obj) {
    return TRUE;
}

void func_02063954(EffectObj *obj) {
    s32 v;
    if (obj->state != 3) {
        return;
    }
    if (obj->time < 0) {
        return;
    }
    if (obj->onDraw != NULL) {
        obj->onDraw(obj);
    }
    v = obj->unk_80;
    if (v < obj->unk_50) {
        obj->unk_4c = FX_Div(v, obj->unk_50);
    } else if (v > obj->unk_54 && v < 0) {
        obj->unk_4c = FX_Div(v, obj->unk_54);
    } else {
        obj->unk_4c = 0x1000;
    }
    obj->Draw();
}

void func_020639d0(EffectObj *obj) {
}

void func_020639d4(EffectObj *obj, s32 id, s32 frame) {
    s32 i;
    EffectSndCue *cues;
    if (id < 0) {
        return;
    }
    cues = obj->cues;
    for (i = 0; i < 8; i++) {
        if (cues[i].id == -1) {
            cues[i].id = id;
            cues[i].frame = frame;
            return;
        }
    }
}

void func_02063a14(EffectObj *obj) {
    for (; obj != NULL; obj = obj->child) {
        obj->loopCount = 0;
    }
}

void func_02063a34(EffectObj *obj) {
    EffectMgr *mgr = data_0214a420;
    u32 id;
    do {
        if (mgr->nextId == 0) {
            mgr->nextId++;
        }
        id = mgr->nextId++;
    } while (Effect_Find(mgr, id) != NULL);
    obj->id = id;
    obj->unk_14 = -1;
    obj->unk_20 = -1;
    obj->unk_18 = 0;
    obj->state = 0;
    obj->unk_28 = 1;
    obj->unk_29 = 1;
    obj->unk_2c = 0;
    obj->time = 0;
    obj->unk_34 = 0;
    obj->prevTime = -1;
    obj->speed = 0x1000;
    obj->scale.x = 0x1000;
    obj->scale.y = 0x1000;
    obj->scale.z = 0x1000;
    obj->unk_4c = 0x1000;
    obj->unk_50 = -0x1e000;
    obj->unk_54 = -0x5000;
    obj->pos.x = 0;
    obj->pos.y = 0;
    obj->pos.z = 0;
    obj->rot.x = 0;
    obj->rot.y = 0;
    obj->rot.z = 0;
    obj->posPtr = NULL;
    obj->offset.x = 0;
    obj->offset.y = 0;
    obj->offset.z = 0;
    obj->unk_80 = 0;
    obj->unk_7c = 0x1000;
    MIi_CpuClear32(-1, obj->cues, sizeof(obj->cues));
    obj->unk_c4 = 1;
    obj->loopCount = 0;
    obj->loopStart = 0;
    obj->paused = 0;
    obj->onStart = NULL;
    obj->onUpdate = NULL;
    obj->onDraw = NULL;
    obj->unk_10 = 0;
    obj->unk_0c = 0;
    obj->unk_08 = 0;
    obj->unk_04 = 0;
    obj->next = NULL;
    obj->drawPrev = NULL;
    obj->drawNext = NULL;
    obj->parent = NULL;
    obj->child = NULL;
    obj->unk_d4 = 2;
    mgr = data_0214a420;
    if (mgr->head != NULL) {
        obj->next = mgr->head;
    } else {
        obj->next = NULL;
    }
    mgr->head = obj;
    mgr->count++;
}

void func_02063bd0(EffectObj *obj) {
    EffectObj *prev;
    EffectMgr *mgr = data_0214a420;
    EffectObj *cur;
    s32 i;
    s32 id;

    if (mgr->head == obj) {
        mgr->head = obj->next;
    } else {
        prev = mgr->head;
        for (cur = prev->next; cur != obj; cur = cur->next) {
            prev = cur;
        }
        prev->next = obj->next;
    }
    obj->next = NULL;
    mgr->count--;
    if (obj->child != NULL) {
        obj->child->parent = obj->parent;
    }
    if (obj->parent != NULL) {
        obj->parent->child = obj->child;
    }
    for (i = 0; i < 8; i++) {
        id = obj->cues[i].id;
        if (id < 0) {
            return;
        }
        if (func_0204a118(data_02097e4c, id)) {
            func_02049de8(data_02097e4c, id);
        }
    }
}

BOOL func_02063c9c(EffectObj *obj) {
    return TRUE;
}

BOOL func_02063ca4(EffectObj *obj) {
    return TRUE;
}

static inline BOOL Effect_CueHit(EffectObj *obj, s32 frame) {
    if (frame == -1 && obj->time == 0) {
        return TRUE;
    }
    if (obj->prevTime < frame << 12 && frame << 12 <= obj->time) {
        return TRUE;
    }
    return FALSE;
}

void func_02063cac(EffectObj *obj) {
    s32 i;
    EffectSndCue *cue;
    s32 id;
    for (i = 0; i < 8; i++) {
        cue = &obj->cues[i];
        id = cue->id;
        if (id < 0) {
            return;
        }
        if (Effect_CueHit(obj, cue->frame)) {
            if (obj->unk_c4) {
                func_02049f44(data_02097e4c, id, &obj->pos, 0);
            } else {
                func_02049a48(data_02097e4c, id, -1, -1, -1);
            }
            if (func_0204a118(data_02097e4c, id)) {
                cue->frame = 0x30000;
            }
        }
    }
}

typedef struct EffectPartRes {
    u8 unk_00[0x7c];
    s32 alpha;
} EffectPartRes;

typedef struct EffectPartOwner {
    u8 unk_00[0x2c];
    EffectPartRes *res;
} EffectPartOwner;

typedef struct EffectPartMat {
    u8 unk_00[0xc];
    u32 polyAttr;
} EffectPartMat;

typedef struct EffectPart {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ EffectPartOwner *owner;
    /* 0x08 */ u8 unk_08[0x14];
    /* 0x1c */ void (*func)(struct EffectPart *part);
    /* 0x20 */ u8 unk_20[0x70];
    /* 0x90 */ u8 unk_90;
    /* 0x91 */ u8 unk_91[0x1f];
    /* 0xb0 */ EffectPartMat *mat;
} EffectPart;

void func_02063d80(EffectPart *part) {
    EffectPartMat *mat = part->mat;
    u32 attr;
    mat->polyAttr = (mat->polyAttr & ~0x3f000000) | (Effect_NextPolyId() << 24);
    attr = mat->polyAttr;
    mat->polyAttr = (attr & ~0x1f0000) | ((u8)((s32)(((s64)part->owner->res->alpha * (((s32)(attr & 0x1f0000) >> 16) << 12) + 0x800) >> 12) >> 12) << 16);
}

void func_02063e0c(EffectPart *part) {
    part->func = func_02063d80;
    part->unk_90 = 2;
}

void func_02063e24(Effect3D *e) {
    NNSG3dResName name;
    u32 i;
    for (i = 0; i < 4; i++) {
        name.val[i] = 0;
    }
    STD_CopyString((char *)&name, e->anmName);
    if (e->anmObjs[0] != NULL) {
        NNS_G3dAnmObjInit(e->anmObjs[0], NNS_G3dGetAnmByName(e->anmFiles[0].data, &name), e->resMdl, NULL);
        NNS_G3dRenderObjAddAnmObj(&e->renderObj, e->anmObjs[0]);
    }
    if (e->anmObjs[1] != NULL) {
        NNS_G3dAnmObjInit(e->anmObjs[1], NNS_G3dGetAnmByName(e->anmFiles[1].data, &name), e->resMdl, NULL);
        NNS_G3dRenderObjAddAnmObj(&e->renderObj, e->anmObjs[1]);
    }
    if (e->anmObjs[2] != NULL) {
        NNS_G3dAnmObjInit(e->anmObjs[2], NNS_G3dGetAnmByName(e->anmFiles[2].data, &name), e->resMdl, NULL);
        NNS_G3dRenderObjAddAnmObj(&e->renderObj, e->anmObjs[2]);
    }
    if (e->anmObjs[3] != NULL) {
        NNS_G3dAnmObjInit(e->anmObjs[3], NNS_G3dGetAnmByName(e->anmFiles[3].data, &name), e->resMdl, e->resTex);
        NNS_G3dRenderObjAddAnmObj(&e->renderObj, e->anmObjs[3]);
    }
    if (e->anmObjs[4] != NULL) {
        NNS_G3dAnmObjInit(e->anmObjs[4], NNS_G3dGetAnmByName(e->anmFiles[4].data, &name), e->resMdl, NULL);
        NNS_G3dRenderObjAddAnmObj(&e->renderObj, e->anmObjs[4]);
    }
}

void func_02063f90(Effect3D *e) {
    e->unk_14 = 0;
    e->arcName[0] = 0;
    e->mdlName[0] = 0;
    e->anmName[0] = 0;
    e->mdlFile = NULL;
    e->anmFiles = NULL;
    e->resMdl = NULL;
    e->resTex = NULL;
    e->anmObjs[0] = NULL;
    e->anmObjs[1] = NULL;
    e->anmObjs[2] = NULL;
    e->anmObjs[3] = NULL;
    e->anmObjs[4] = NULL;
    e->initCallback = NULL;
    e->onDraw = NULL;
}

void func_02063fd4(Effect3D *e) {
    if (e->mdlFile != NULL) {
        func_0203f0b4(e->mdlFile->data);
    }
    if (e->anmObjs[0] != NULL) {
        func_0203df0c(e->anmObjs[0]);
        e->anmObjs[0] = NULL;
    }
    if (e->anmObjs[1] != NULL) {
        func_0203df0c(e->anmObjs[1]);
        e->anmObjs[1] = NULL;
    }
    if (e->anmObjs[2] != NULL) {
        func_0203df0c(e->anmObjs[2]);
        e->anmObjs[2] = NULL;
    }
    if (e->anmObjs[3] != NULL) {
        func_0203df0c(e->anmObjs[3]);
        e->anmObjs[3] = NULL;
    }
    if (e->anmObjs[4] != NULL) {
        func_0203df0c(e->anmObjs[4]);
        e->anmObjs[4] = NULL;
    }
    if (e->unk_34) {
        func_02036838(data_02097cdc, e->arcName, 7, 0);
    }
    func_02063f90(e);
}


BOOL func_0206408c(Effect3D *e) {
    BOOL ret = FALSE;
    void *arc;
    switch (e->unk_2c) {
    case 0:
        if (e->anmName[0] == 0) {
            STD_CopyString(e->anmName, e->mdlName);
        }
        if (e->arcName[0] == 0) {
            STD_CopyString(e->arcName, data_0208c330);
            e->unk_2c += 2;
            break;
        }
        func_020359d0(e->arcName, 7, 0);
        e->unk_34 = 1;
        e->unk_2c++;
    case 1:
        if (!func_02035b90(e->arcName, 7)) {
            break;
        }
        e->unk_2c++;
    case 2:
        arc = func_02035d5c(e->arcName);
        e->mdlFile = func_02034ec0(arc, e->mdlName);
        e->anmFiles = func_02034ff8(arc, e->anmName);
        if (e->mdlFile != NULL) {
            func_0203ed04(e->mdlName, e->mdlFile->data);
        }
        e->unk_2c = 100;
    case 100:
        e->unk_2c = -1;
        ret = TRUE;
        break;
    }
    return ret;
}

static inline void *Effect_GetResDataByIdx(EffectResDict *dict, u32 idx) {
    if (dict != NULL && idx < dict->numEntry) {
        return (u8 *)dict + dict->ofsEntry + 4;
    }
    return NULL;
}

static inline void *Effect_GetMdlByIdx(u8 *mdlSet, u32 idx) {
    u32 *ofs = (u32 *)Effect_GetResDataByIdx((EffectResDict *)(mdlSet + 8), idx);
    if (ofs != NULL) {
        return mdlSet + *ofs;
    }
    return NULL;
}

void func_02063e0c(EffectPart *part);

BOOL func_020641b8(Effect3D *e) {
    u8 *mdlSet = (u8 *)NNS_G3dGetMdlSet(e->mdlFile->data);
    void *mdl;
    u32 *ofs;
    if (mdlSet != NULL && (ofs = (u32 *)Effect_GetResDataByIdx((EffectResDict *)(mdlSet + 8), 0)) != NULL) {
        mdl = mdlSet + *ofs;
    } else {
        mdl = NULL;
    }
    e->resMdl = (NNSG3dResMdl *)mdl;
    e->resTex = NNS_G3dGetTex(e->mdlFile->data);
    NNS_G3dRenderObjInit(&e->renderObj, e->resMdl);
    if (e->initCallback != NULL) {
        NNS_G3dRenderObjSetInitFunc(&e->renderObj, e->initCallback);
    } else {
        NNS_G3dRenderObjSetInitFunc(&e->renderObj, (NNSG3dSbcCallBackFunc)func_02063e0c);
    }
    e->renderObj.ptrUser = e;
    if (e->anmFiles != NULL) {
        if (e->anmFiles[0].data != NULL) {
            e->anmObjs[0] = (NNSG3dAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[1].data != NULL) {
            e->anmObjs[1] = (NNSG3dAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[2].data != NULL) {
            e->anmObjs[2] = (NNSG3dAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[3].data != NULL) {
            e->anmObjs[3] = (NNSG3dAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[4].data != NULL) {
            e->anmObjs[4] = (NNSG3dAnmObj *)func_0203de84(0x80, 4);
        }
    }
    func_02063e24(e);
    return TRUE;
}

static inline void Effect_SetAnmFrame(NNSG3dAnmObj *a, s32 frame, BOOL *ret) {
    s32 max;
    if (a != NULL) {
        max = (((NNSG3dResAnmCommon *)a->resAnm)->numFrame << 12) - 0x1000;
        if (frame >= max) {
            a->frame = max;
        } else {
            a->frame = frame;
            *ret = TRUE;
        }
    }
}

BOOL func_02064308(Effect3D *e, s32 frame) {
    BOOL ret;
    if (e->anmFiles == NULL) {
        return FALSE;
    }
    ret = FALSE;
    Effect_SetAnmFrame(e->anmObjs[0], frame, &ret);
    Effect_SetAnmFrame(e->anmObjs[1], frame, &ret);
    Effect_SetAnmFrame(e->anmObjs[2], frame, &ret);
    Effect_SetAnmFrame(e->anmObjs[3], frame, &ret);
    Effect_SetAnmFrame(e->anmObjs[4], frame, &ret);
    return ret;
}

BOOL func_02064400(Effect3D *e) {
    return func_02064308(e, e->time);
}


// MtxFx33 with its rows as vectors: func_02064410 builds the billboard matrix row by row.
typedef union EfMtx33 {
    MtxFx33 mtx;
    VecFx32 r[3];
} EfMtx33;

#define EF_SIN(a) FX_SinCosTable_[((a) >> 4) * 2]
#define EF_COS(a) FX_SinCosTable_[((a) >> 4) * 2 + 1]

static inline void Ef_VecSet(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline s32 Ef_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Ef_Cross(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    s32 x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    s32 y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    s32 z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline s32 Ef_Dot(const VecFx32 *a, const VecFx32 *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

static inline void Ef_RotYXZ(MtxFx33 *m, const EffectRot *rot) {
    u16 rx;
    u16 ry;
    u16 rz;
    MtxFx33 t;
    BOOL set;
    ry = rot->y;
    rz = rot->z;
    rx = rot->x;
    set = FALSE;
    MTX_Identity33_(m);
    if (ry != 0) {
        MTX_RotY33_(m, EF_SIN(ry), EF_COS(ry));
        set = TRUE;
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX33_(&t, EF_SIN(rx), EF_COS(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, EF_SIN(rx), EF_COS(rx));
            set = TRUE;
        }
    }
    if (rz != 0) {
        if (set) {
            MTX_RotZ33_(&t, EF_SIN(rz), EF_COS(rz));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, EF_SIN(rz), EF_COS(rz));
            set = TRUE;
        }
    }
}

static inline void Ef_RotZYX(MtxFx33 *m, const EffectRot *rot) {
    u16 rx;
    u16 ry;
    u16 rz;
    MtxFx33 t;
    BOOL set;
    ry = rot->y;
    rx = rot->x;
    rz = rot->z;
    set = FALSE;
    MTX_Identity33_(m);
    if (rz != 0) {
        MTX_RotZ33_(m, EF_SIN(rz), EF_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY33_(&t, EF_SIN(ry), EF_COS(ry));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotY33_(m, EF_SIN(ry), EF_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX33_(&t, EF_SIN(rx), EF_COS(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, EF_SIN(rx), EF_COS(rx));
            set = TRUE;
        }
    }
}

void func_02064410(Effect3D *e) {
    VecFx32 trans;
    EfMtx33 rot;
    VecFx32 dir;
    VecFx32 side;
    MtxFx33 r;
    VecFx32 zv;
    VecFx32 up;
    VecFx32 xv;
    VecFx32 scale;
    trans.x = Ef_FxMul(e->offset.x, e->scale.x);
    trans.y = Ef_FxMul(e->offset.y, e->scale.y);
    trans.z = Ef_FxMul(e->offset.z, e->scale.z);
    if (e->posPtr != NULL) {
        VEC_Add(&trans, e->posPtr, &trans);
    } else {
        VEC_Add(&trans, &e->pos, &trans);
    }
    NNS_G3dGlbSetBaseTrans(&trans);
    if (e->unk_28 == 1) {
        MI_Copy36B(NNS_G3dGlbGetInvV(), &rot);
    } else if (e->unk_28 == 2) {
        VecFx32 up2;
        up2.x = 0;
        up2.y = 0x1000;
        up2.z = 0;
        dir.x = ((s32 *)data_02092844)[2];
        dir.y = ((s32 *)data_02092844)[5];
        dir.z = ((s32 *)data_02092844)[8];
        Ef_Cross(&up2, &dir, &side);
        VEC_Normalize(&side, &side);
        Ef_Cross(&side, &up2, &dir);
        VEC_Normalize(&dir, &dir);
        rot.r[0] = side;
        rot.r[1] = up2;
        rot.r[2] = dir;
    } else if (e->unk_28 == 3) {
        const MtxFx43 *inv = NNS_G3dGlbGetInvV();
        Ef_VecSet(&zv, inv->m[2][0], inv->m[2][1], inv->m[2][2]);
        Ef_VecSet(&xv, inv->m[0][0], inv->m[0][1], inv->m[0][2]);
        Ef_VecSet(&up, 0, 0x1000, 0);
        Ef_RotYXZ(&r, &e->rot);
        MTX_MultVec33(&up, &r, &up);
        VEC_MultAdd(-Ef_Dot(&up, &zv), &zv, &up, &up);
        VEC_Normalize(&up, &up);
        Ef_Cross(&up, &zv, &xv);
        VEC_Normalize(&xv, &xv);
        rot.r[0] = xv;
        rot.r[1] = up;
        rot.r[2] = zv;
    } else if (e->unk_29) {
        Ef_RotYXZ(&rot.mtx, &e->rot);
    } else {
        Ef_RotZYX(&rot.mtx, &e->rot);
    }
    MI_Copy36B(&rot, data_020928b4);
    NNS_G3dGlb.flag &= ~0xa4;
    {
        s32 k = e->unk_4c;
        scale.x = Ef_FxMul(e->scale.x, k);
        scale.y = Ef_FxMul(e->scale.y, k);
        scale.z = Ef_FxMul(e->scale.z, k);
    }
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbFlushP();
    NNS_G3dDraw(&e->renderObj);
}

}

// ---- merged from Effect_2.cpp
namespace m_02064b40 {
extern "C" {

void func_02064b40(Effect3D *e) {
    e->unk_14 = 1;
    e->unk_c4 = 0;
}

static inline void Effect_SetProjection(const MtxFx44 *mtx) {
    MIi_CpuCopyFast(mtx, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
}


// Scales all three components; the caller then overwrites z, which keeps
// the target's store order for y and z.
static inline void Effect_VecScale(VecFx32 *d, const VecFx32 *s, s32 k) {
    d->x = Effect_FxMul(s->x, k);
    d->y = Effect_FxMul(s->y, k);
    d->z = Effect_FxMul(s->z, k);
}
void func_02064b54(Effect3D *e) {
    MtxFx44 proj;
    MtxFx43 cam;
    VecFx32 trans;
    VecFx32 scale;
    MtxFx44 ortho;
    MtxFx33 rot;
    MtxFx44 *glbProj = (MtxFx44 *)data_02092800;
    MtxFx43 *glbCam = (MtxFx43 *)data_02092844;
    MI_Copy64B(glbProj, &proj);
    MI_Copy48B(glbCam, &cam);
    MTX_OrthoW(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, &ortho);
    Effect_SetProjection(&ortho);
    MTX_Identity43_(glbCam);
    glbCam->_32 = 0x200;
    trans.x = Effect_FxMul(e->offset.x, e->scale.x);
    trans.y = Effect_FxMul(e->offset.y, e->scale.y);
    trans.z = Effect_FxMul(e->offset.z, e->scale.z);
    if (e->posPtr != NULL) {
        VEC_Add(&trans, e->posPtr, &trans);
    } else {
        VEC_Add(&trans, &e->pos, &trans);
    }
    NNS_G3dGlbSetBaseTrans(&trans);
    MTX_Identity33_(&rot);
    MI_Copy36B(&rot, data_020928b4);
    NNS_G3dGlb.flag &= ~0xa4;
    Effect_VecScale(&scale, &e->scale, 0x64000);
    scale.z = 0x1000;
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbFlushP();
    NNS_G3dDraw(&e->renderObj);
    Effect_SetProjection(&proj);
    MI_Copy48B(&cam, glbCam);
}

}
}  // namespace m_02064b40

// ---- merged from Effect_3.cpp
namespace m_02064d3c {
extern "C" {

extern EffectFile *func_02034b98(void *arc, const char *name);
extern void func_02068508(struct EffectSetup *setup, void *data, VecFx32 *pos);
extern EffectObj *func_02068544(struct EffectSetup *setup);
extern void func_02068540(struct EffectSetup *setup);
extern u32 data_0208c1d8[];
extern u32 data_0208c2e4[];

void func_02064d3c(EffectObj *obj, EffectObj *child) {
    EffectObj *p = obj->child;
    if (p == NULL) {
        obj->child = child;
        child->parent = obj;
        return;
    }
    while (p != NULL) {
        if (p->child == NULL) {
            break;
        }
        p = p->child;
    }
    p->child = child;
    child->parent = p;
}

void func_02064d74(EffectGroup *g, const char *prefix, const char *name, const char *suffix) {
    if (name != NULL) {
        if (prefix != NULL) {
            STD_CopyString(g->name, prefix);
            STD_ConcatenateString(g->name, name);
        } else {
            STD_CopyString(g->name, name);
        }
        if (suffix != NULL) {
            STD_ConcatenateString(g->name, suffix);
        }
    } else {
        g->name[0] = 0;
    }
}

void func_02064dd8(EffectGroup *g) {
    g->unk_14 = 4;
    g->arcName[0] = 0;
    g->name[0] = 0;
    g->arc = NULL;
    g->setup = NULL;
}

BOOL func_02064df8(EffectGroup *g) {
    BOOL ret = FALSE;
    const char *arcName = g->arcName[0] != 0 ? g->arcName : data_0208c33c;
    switch (g->unk_2c) {
    case 0:
        if (g->arcName[0] != 0) {
            func_020359d0(arcName, 7, 0);
        }
        g->unk_2c++;
    case 1:
        if (!func_02035b90(arcName, 7)) {
            break;
        }
        g->arc = func_02035d5c(arcName);
        g->unk_2c = 10;
    case 10:
        ret = TRUE;
        g->unk_2c = -1;
        break;
    }
    return ret;
}


BOOL func_02064e98(EffectGroup *g) {
    EffectFile *file;
    EffectSetup *setup;
    EffectObj *first;
    EffectObj *c;
    s32 a;
    void *saved;

    if (g->name[0] != 0) {
        file = func_02034b98(g->arc, g->name);
        setup = (EffectSetup *)Heap_Alloc(0x28);
        if (setup != NULL) {
            *(u32 **)setup = data_0208c1d8;
        }
        g->setup = setup;
        func_02068508(setup, file->data, &g->pos);
        first = func_02068544(g->setup);
        c = first;
        if (first != NULL) {
            do {
                c->SetPos(&g->pos);
                c->SetRot(&g->rot);
                c->SetScale(&g->scale);
                a = g->unk_7c;
                c->unk_7c = a < 0 ? 0 : a;
                c->unk_7c = a > 0x1000 ? 0x1000 : a;
                c->unk_54 = g->unk_54;
                c->unk_50 = g->unk_50;
                c->SetParam(g->unk_d4);
                c->unk_c4 = g->unk_c4;
                if (c->child == NULL) {
                    break;
                }
                c = c->child;
            } while (c != NULL);
        }
        if (g->child != NULL) {
            c->child = g->child;
            g->child->parent = c;
        }
        g->child = first;
        first->parent = g;
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        if (g->setup != NULL) {
            if (g->setup != NULL) {
                g->setup->Delete();
            }
            g->setup = NULL;
        }
        data_02097dd0->cur = saved;
    }
    return TRUE;
}

void func_0206500c(EffectObj *obj, const VecFx32 *pos) {
    obj->pos = *pos;
}

void func_02065028(EffectObj *obj, const EffectRot *rot) {
    obj->rot = *rot;
}

void func_02065044(EffectObj *obj, const VecFx32 *scale) {
    obj->scale = *scale;
}

void func_02065060(EffectObj *obj, s32 param) {
    obj->unk_d4 = param;
}

EffectSetup *EffectSetup_DtorDelete(EffectSetup *setup) {
    *(u32 **)setup = data_0208c1d8;
    func_02068540(setup);
    Heap_Free(setup);
    return setup;
}

BOOL func_02065090(EffectGroup *g) {
    return g->child != NULL ? TRUE : FALSE;
}

BOOL func_020650a4(EffectGroup *g) {
    EffectObj *c;
    g->Setup();
    for (c = g->child; c != NULL; c = c->child) {
        c->time = g->time;
    }
    return TRUE;
}

void func_020650e0(EffectGroup *g, const VecFx32 *pos) {
    VecFx32 d;
    EffectObj *c;
    d.x = pos->x - g->pos.x;
    d.y = pos->y - g->pos.y;
    d.z = pos->z - g->pos.z;
    for (c = g->child; c != NULL; c = c->child) {
        c->AddPos(&d);
    }
    g->pos = *pos;
}

void func_0206516c(EffectObj *obj, const VecFx32 *delta) {
    VEC_Add(&obj->pos, delta, &obj->pos);
}

void func_02065184(EffectObj *obj, s32 x, s32 y, s32 z) {
    VecFx32 v;
    v.x = x;
    v.y = y;
    v.z = z;
    obj->SetPos(&v);
}

void func_020651b0(EffectGroup *g, const VecFx32 *delta) {
    EffectObj *c;
    for (c = g->child; c != NULL; c = c->child) {
        c->AddPos(delta);
    }
    VEC_Add(&g->pos, delta, &g->pos);
}

void func_020651fc(EffectObj *obj, s32 x, s32 y, s32 z) {
    VecFx32 v;
    v.x = x;
    v.y = y;
    v.z = z;
    obj->AddPos(&v);
}

void func_02065228(EffectGroup *g, const EffectRot *rot) {
    u16 dx = rot->x - g->rot.x;
    u16 dy = rot->y - g->rot.y;
    u16 dz = rot->z - g->rot.z;
    EffectObj *c;
    EffectRot r;
    for (c = g->child; c != NULL; c = c->child) {
        r = c->rot;
        r.x += dx;
        r.y += dy;
        r.z += dz;
        c->SetRot(&r);
    }
    g->rot = *rot;
}

void func_020652e4(EffectObj *obj, u16 x, u16 y, u16 z) {
    EffectRot r;
    r.x = x;
    r.y = y;
    r.z = z;
    obj->SetRot(&r);
}

void func_02065310(EffectGroup *g, const VecFx32 *scale) {
    s32 fx = FX_Div(scale->x, g->scale.x);
    s32 fy = FX_Div(scale->y, g->scale.y);
    s32 fz = FX_Div(scale->z, g->scale.z);
    EffectObj *c;
    VecFx32 v;
    for (c = g->child; c != NULL; c = c->child) {
        v = c->scale;
        v.x = Effect_FxMul(fx, v.x);
        v.y = Effect_FxMul(fy, v.y);
        v.z = Effect_FxMul(fz, v.z);
        c->SetScale(&v);
    }
    g->scale = *scale;
}

void func_02065454(EffectObj *obj, s32 x, s32 y, s32 z) {
    VecFx32 v;
    v.x = x;
    v.y = y;
    v.z = z;
    obj->SetScale(&v);
}

void func_02065480(EffectGroup *g, s32 param) {
    EffectObj *c;
    for (c = g->child; c != NULL; c = c->child) {
        c->SetParam(param);
    }
}

extern void PauseNode_Init(void *task);
extern void *func_02043548(EffectCamera *camera);

static inline void EffectMgr_Reset(EffectMgr *m) {
    m->state = 0;
    m->nextId = 0;
    m->drawFilter = 0;
    m->loadStep = 0;
    m->arc3d = NULL;
    m->arcSetup = NULL;
    m->head = NULL;
    m->count = 0;
    m->head2 = NULL;
    m->count2 = 0;
    m->drawHead = NULL;
    m->useCamera = 0;
    MTX_Identity44_(&m->proj);
}

void func_020654b8(void) {
    EffectMgr *m;
    if (data_0214a420 != NULL) {
        return;
    }
    m = (EffectMgr *)Heap_Alloc(sizeof(EffectMgr));
    if (m != NULL) {
        PauseNode_Init(m);
        func_02043548(&m->camera);
        EffectMgr_Reset(m);
    }
    data_0214a420 = m;
}

static inline void EffectMgr_Clear2(EffectMgr *m) {
    EffectObj *o;
    EffectObj *next;
    for (o = m->head2; o != NULL; o = next) {
        next = o->drawNext;
        Effect_Delete(o);
    }
    m->head2 = NULL;
    m->count2 = 0;
}

static inline void EffectMgr_Dtor(EffectMgr *m) {
    EffectMgr_Clear(m);
    EffectMgr_Clear2(m);
    func_02036838(data_02097cdc, data_0208c330, 7, 0);
    func_02036838(data_02097cdc, data_0208c33c, 7, 0);
    EffectMgr_Reset(m);
}

void func_02065534(void) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (data_0214a420 != NULL) {
        EffectMgr *m = data_0214a420;
        if (m != NULL) {
            EffectMgr_Dtor(m);
            Heap_Free(m);
        }
        data_0214a420 = NULL;
    }
    data_02097dd0->cur = saved;
}

void func_020656b4(EffectMgr *m) {
    EffectObj *o;
    EffectObj *next;
    for (o = m->head; o != NULL; o = next) {
        next = o->next;
        EFFECT_DELETE(o);
    }
    m->head = NULL;
    m->count = 0;
}

void func_02063bd0(EffectObj *obj);

EffectObj *EffectObj_DtorDelete(EffectObj *obj) {
    *(u32 **)obj = data_0208c2e4;
    func_02063bd0(obj);
    Heap_Free(obj);
    return obj;
}

BOOL func_02065748(EffectMgr *m, EffectObj *obj) {
    EffectObj *o;
    for (o = m->head; o != NULL; o = o->next) {
        if (o == obj && o->id == obj->id) {
            return TRUE;
        }
    }
    for (o = m->head2; o != NULL; o = o->next) {
        if (o == obj && o->id == obj->id) {
            return TRUE;
        }
    }
    return FALSE;
}

EffectObj *func_020657b0(EffectMgr *m, u32 id) {
    EffectObj *o;
    for (o = m->head; o != NULL; o = o->next) {
        if (id == o->id) {
            return o;
        }
    }
    for (o = m->head2; o != NULL; o = o->next) {
        if (id == o->id) {
            return o;
        }
    }
    return NULL;
}

void func_02065804(EffectMgr *m, u32 id) {
    EffectObj *o = Effect_Find(m, id);
    if (o != NULL) {
        o->state = 4;
    }
}

void func_02065860(EffectMgr *m, u32 id) {
    EffectObj *o = Effect_Find(m, id);
    if (o == NULL) {
        return;
    }
    for (; o != NULL; o = o->child) {
        o->loopCount = 0;
    }
}

EffectObj *func_020658cc(EffectMgr *m, s32 v) {
    EffectObj *o;
    for (o = m->head; o != NULL; o = o->next) {
        if (v == o->unk_20) {
            return o;
        }
    }
    for (o = m->head2; o != NULL; o = o->next) {
        if (v == o->unk_20) {
            return o;
        }
    }
    return NULL;
}

void func_02065920(EffectMgr *m) {
    EffectObj *o = m->head;
    EffectObj *prev;
    EffectObj *p;
    m->drawHead = o;
    if (o == NULL) {
        return;
    }
    o->drawPrev = NULL;
    o->drawNext = NULL;
    for (o = o->next; o != NULL; o = o->next) {
        prev = NULL;
        for (p = m->drawHead; p != NULL; p = p->drawNext) {
            if (o->unk_80 < p->unk_80) {
                break;
            }
            prev = p;
        }
        if (p == NULL) {
            o->drawPrev = prev;
            o->drawNext = NULL;
            prev->drawNext = o;
        } else {
            o->drawPrev = p->drawPrev;
            o->drawNext = p;
            p->drawPrev = o;
            if (o->drawPrev != NULL) {
                o->drawPrev->drawNext = o;
            } else {
                m->drawHead = o;
            }
        }
    }
}

BOOL func_020659c4(EffectMgr *m) {
    BOOL ret = FALSE;
    BOOL cont;
    do {
        cont = FALSE;
        switch (m->loadStep) {
        case 0:
            func_020359d0(data_0208c330, 7, 0);
            func_020359d0(data_0208c33c, 7, 0);
            m->loadStep++;
        case 1:
            if (!func_02035b90(data_0208c330, 7)) {
                break;
            }
            m->arc3d = func_02035d5c(data_0208c330);
            m->loadStep = 10;
            cont = TRUE;
            break;
        case 10:
            if (!func_02035b90(data_0208c33c, 7)) {
                break;
            }
            m->arcSetup = func_02035d5c(data_0208c33c);
            m->loadStep = 100;
            cont = TRUE;
            break;
        case 100:
            m->loadStep = -1;
            ret = TRUE;
            break;
        }
    } while (cont);
    return ret;
}

extern BOOL PauseNode_IsUpdatePaused(void *task, s32 arg);

void func_02065ac0(EffectMgr *m) {
    EffectObj *o;
    EffectObj *next;
    switch (m->state) {
    case 0:
        if (!func_020659c4(m)) {
            return;
        }
        m->state = 1;
    case 1:
        m->state = 3;
    case 3:
        if (PauseNode_IsUpdatePaused(m, 1)) {
            return;
        }
        for (o = m->head; o != NULL; o = next) {
            next = o->next;
            if (!func_020637d0(o)) {
                EFFECT_DELETE(o);
            }
        }
        break;
    }
}

}

extern "C" {

typedef struct EffectBlk12 {
    s32 w[3];
} EffectBlk12;

extern BOOL PauseNode_IsDrawPaused(void *node, BOOL recurse);
extern int Gfx3DState_TakePolyIds(void *st, int n);

static inline void Effect_GlbLookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target) {
    NNS_G3dGlb.camPos = *camPos;
    NNS_G3dGlb.camUp = *camUp;
    NNS_G3dGlb.camTarget = *target;
    MTX_LookAt(camPos, camUp, target, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
}

static inline void Effect_GlbSetProj(const MtxFx44 *proj) {
    MIi_CpuCopyFast(proj, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
}

static inline void Effect_GlbSetBaseRot(const MtxFx33 *rot) {
    MI_Copy36B(rot, data_020928b4);
    NNS_G3dGlb.flag &= ~0xa4;
}

void func_02065b84(EffectMgr *m) {
    MtxFx33 rot;
    VecFx32 trans;
    VecFx32 scale;
    VecFx32 camPos;
    VecFx32 camTarget;
    VecFx32 camUp;
    u8 proj[0x40];
    EffectObj *o;
    EffectObj *next;
    u8 mask;
    s32 *cam;
    u32 n;
    if (!PauseNode_IsDrawPaused(m, TRUE) && m->state == 3) {
        data_0214a41c = data_02097d48->unk_8b0[1];
        data_0214a41d = 0;
    } else {
        return;
    }
    rot = *(MtxFx33 *)data_020928b4;
    *(EffectBlk12 *)&trans = *(EffectBlk12 *)data_020928d8;
    *(EffectBlk12 *)&scale = *(EffectBlk12 *)data_020928e4;
    camPos = NNS_G3dGlb.camPos;
    camTarget = NNS_G3dGlb.camTarget;
    camUp = NNS_G3dGlb.camUp;
    MI_Copy64B(data_02092800, &proj);
    if (m->useCamera) {
        Effect_GlbSetProj(&m->proj);
        Effect_GlbLookAt(&m->camera.pos, &m->camera.up, &m->camera.target);
    }
    o = m->head;
    if (o != NULL) {
        cam = (s32 *)data_02092844;
        for (; o != NULL; o = o->next) {
            o->unk_80 = ((s64)o->pos.x * cam[2] + (s64)o->pos.y * cam[5] + (s64)o->pos.z * cam[8]) >> 12;
            o->unk_80 += cam[11];
            o->unk_80 += o->unk_18;
        }
    }
    func_02065920(m);
    o = m->drawHead;
    if (!m->drawFilter) {
        for (; o != NULL; o = next) {
            next = o->drawNext;
            func_02063954(o);
        }
    } else {
        mask = data_02097d48->unk_a30_4 ? 1 : 2;
        for (; o != NULL;) {
            EffectObj *n2 = o->drawNext;
            if (mask & (u8)o->unk_d4) {
                func_02063954(o);
            }
            o = n2;
        }
    }
    Effect_GlbSetBaseRot(&rot);
    NNS_G3dGlbSetBaseTrans(&trans);
    NNS_G3dGlbSetBaseScale(&scale);
    if (m->useCamera) {
        Effect_GlbLookAt(&camPos, &camTarget, &camUp);
        Effect_GlbSetProj(&m->proj);
    }
    n = data_0214a41d;
    if (n >= 0x10) {
        n = 0x10;
        data_0214a41d = n;
    }
    Gfx3DState_TakePolyIds(data_02097d48->unk_8b0, (u8)n);
}

}
}  // namespace m_02064d3c
