#include "Main/Effect/Effect.h"

extern "C" {

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
    EffectMgr *mgr = data_0214a41c.mgr;
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
    mgr = data_0214a41c.mgr;
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
    EffectMgr *mgr = data_0214a41c.mgr;
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

typedef struct EffectResName {
    u32 val[4];
} EffectResName;

void func_02063e24(Effect3D *e) {
    EffectResName name;
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
    e->resMdl = mdl;
    e->resTex = NNS_G3dGetTex(e->mdlFile->data);
    NNS_G3dRenderObjInit(&e->renderObj, e->resMdl);
    if (e->initCallback != NULL) {
        NNS_G3dRenderObjSetInitFunc(&e->renderObj, e->initCallback);
    } else {
        NNS_G3dRenderObjSetInitFunc(&e->renderObj, (void (*)(void *))func_02063e0c);
    }
    e->renderObj.ptrUser = e;
    if (e->anmFiles != NULL) {
        if (e->anmFiles[0].data != NULL) {
            e->anmObjs[0] = (EffectAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[1].data != NULL) {
            e->anmObjs[1] = (EffectAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[2].data != NULL) {
            e->anmObjs[2] = (EffectAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[3].data != NULL) {
            e->anmObjs[3] = (EffectAnmObj *)func_0203de84(0x80, 4);
        }
        if (e->anmFiles[4].data != NULL) {
            e->anmObjs[4] = (EffectAnmObj *)func_0203de84(0x80, 4);
        }
    }
    func_02063e24(e);
    return TRUE;
}

static inline void Effect_SetAnmFrame(EffectAnmObj *a, s32 frame, BOOL *ret) {
    s32 max;
    if (a != NULL) {
        max = (a->resAnm->numFrame << 12) - 0x1000;
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

}
