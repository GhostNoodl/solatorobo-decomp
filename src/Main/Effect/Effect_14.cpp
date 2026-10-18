#include "Main/Effect/Effect.h"

extern "C" {

extern char data_0208c980[];
extern u32 data_0208c840[];

void func_0206ad84(EffectEmitter *em) {
    em->unk_14 = 2;
    em->nameDef = NULL;
    em->arc = NULL;
    em->file = NULL;
    em->def = NULL;
    em->tex = NULL;
    em->ptcls = NULL;
    em->loopCount = 0;
    em->emitData = NULL;
    em->emitCount = 0;
    em->parts = NULL;
}

void func_0206adbc(EffectEmitter *em) {
    EffectPtcl *p;
    EffectPtcl *next;
    if (em->file != NULL) {
        func_0203f0b4(em->file->data);
    }
    if (em->nameDef != NULL && em->unk_34) {
        func_02036838(data_02097cdc, em->nameDef->arcName, 7, 0);
    }
    for (p = em->ptcls; p != NULL; p = next) {
        next = p->next;
        EFFECT_DELETE(p);
    }
    {
        void *saved_ = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        if (em->parts != NULL) {
            if (em->parts != NULL) {
                em->parts->Delete();
            }
            em->parts = NULL;
        }
        data_02097dd0->cur = saved_;
    }
}

EffectPtcl *func_0206aea0(EffectPtcl *p) {
    *(u32 **)p = data_0208c840;
    func_0203de1c(p);
    return p;
}

BOOL func_0206aec0(EffectEmitter *em) {
    BOOL ret = FALSE;
    switch (em->unk_2c) {
    case 0:
        if (em->nameDef == NULL) {
            em->nameDef = (EffectDef *)data_0208c980;
        }
        func_020359d0(em->nameDef->arcName, 7, 0);
        em->unk_34 = 1;
        em->unk_2c++;
    case 1:
        if (!func_02035b90(em->nameDef->arcName, 7)) {
            break;
        }
        em->unk_2c = 10;
    case 10: {
        EffectDef *def;
        EffectFile *f;
        em->arc = func_02035d5c(em->nameDef->arcName);
        def = em->def;
        f = func_02034ec0(em->arc, def->mdlName);
        if (f != NULL) {
            func_0203ed04(def->mdlName, f->data);
        }
        em->file = f;
        em->tex = (EffectResTex *)NNS_G3dGetTex(f->data);
        em->unk_2c = 30;
        break;
    }
    case 30:
        ret = TRUE;
        em->unk_2c = -1;
        break;
    }
    return ret;
}

BOOL func_0206afb0(EffectEmitter *em) {
    em->Loop();
    return TRUE;
}

extern BOOL func_0206b1cc(EffectEmitter *em);

BOOL func_0206afc8(EffectEmitter *em) {
    return func_0206b1cc(em);
}


extern void func_02068da8(EffectPtcl *p);

static inline void *Effect_ResDataByIdx(EffectResDict *dict, u32 idx) {
    if (dict != NULL && idx < dict->numEntry) {
        u16 *e = (u16 *)((u8 *)dict + dict->ofsEntry);
        return (u8 *)e + 4 + e[0] * idx;
    }
    return NULL;
}

static inline u32 *Effect_GetTexData(EffectResTex *tex, u32 idx) {
    if (tex != NULL) {
        return (u32 *)Effect_ResDataByIdx(&tex->dict, idx);
    }
    return NULL;
}

static inline u16 *Effect_GetPlttData(EffectResTex *tex, u32 idx) {
    if (tex != NULL && tex->plttOfsDict != 0) {
        return (u16 *)Effect_ResDataByIdx((EffectResDict *)((u8 *)tex + tex->plttOfsDict), idx);
    }
    return NULL;
}

#define EFFECT_TEXCOORD(s, t) ((u16)(s16)((s) >> 8) | ((u16)(s16)((t) >> 8) << 16))

static inline u32 Effect_GetTexImageParam(EffectResTex *tex, u32 idx) {
    u32 *data = Effect_GetTexData(tex, idx);
    u32 param = data[0];
    u16 key;
    if ((param & 0x1c000000) != 0x14000000) {
        key = tex->texVramKey;
    } else {
        key = tex->tex4x4VramKey;
    }
    return param + key;
}

static inline void EffectPtcl_SetPltt(EffectPtcl *p, s32 idx, u32 param) {
    u16 *pltt = Effect_GetPlttData(p->tex, idx);
    s32 w = 0x1000 << (((param & 0x700000) >> 20) + 3);
    s32 h = 0x1000 << (((param & 0x3800000) >> 23) + 3);
    p->texAddr = (pltt[0] + (u16)p->tex->plttVramKey) << 3;
    p->texIdx = idx;
    p->dl[3] = EFFECT_TEXCOORD(w, 0);
    p->dl[6] = EFFECT_TEXCOORD(0, 0);
    p->dl[9] = EFFECT_TEXCOORD(0, h);
    p->dl[11] = EFFECT_TEXCOORD(w, h);
}

static inline void EffectPtcl_SetTex(EffectPtcl *p, EffectResTex *tex) {
    p->tex = tex;
    if (tex != NULL) {
        u32 param = Effect_GetTexImageParam(tex, 0);
        p->polyAttr = param;
        EffectPtcl_SetPltt(p, p->texIdx, param);
    }
}

static inline void EffectPtcl_SetCmds(EffectPtcl *p, EffectPtclCmd *cmds, s32 num) {
    p->cmds = cmds;
    p->numCmds = num;
}

static inline s32 EffectPtcl_LastEnd(EffectPtclCmd *cmds, s32 num) {
    EffectPtclCmd *c = &cmds[num - 1];
    return c->start + c->len;
}
static inline s32 EffectPtcl_LastEnd2(EffectEmitter *em) {
    EffectPtclCmd *c = &em->emitData[em->emitCount - 1];
    return c->start + c->len;
}

static inline void EffectEmitter_AddPtcl(EffectEmitter *em, EffectPtcl *p) {
    if (p != NULL) {
        if (em->ptcls == NULL) {
            em->ptcls = p;
        } else {
            EffectPtcl *last = p;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = em->ptcls;
            em->ptcls->prev = last;
            em->ptcls = p;
        }
    }
}

BOOL func_0206afd4(EffectEmitter *em) {
    EffectPtcl *p = (EffectPtcl *)func_0203dd9c(0xc4);
    if (p != NULL) {
        *(u32 **)p = data_0208c840;
        func_02068da8(p);
    }
    EffectPtcl_SetTex(p, em->tex);
    p->unk_50 = 0;
    EffectPtcl_SetCmds(p, em->emitData, em->emitCount);
    p->origin = em->pos;
    p->unk_b8 = EffectPtcl_LastEnd2(em);
    EffectEmitter_AddPtcl(em, p);
    func_0206b1cc(em);
    return TRUE;
}


extern void VEC_MultAdd(s32 scale, const EffectVec *dir, const EffectVec *base, EffectVec *out);
extern void func_0206924c(EffectEmitterSub *sub, EffectPtcl *p);

static inline BOOL EffectPtcl_Move(EffectPtcl *p) {
    if (p->time > p->unk_b8 && p->unk_b8 >= 0) {
        return FALSE;
    }
    VEC_MultAdd(p->speed, &p->dir, &p->pos, &p->pos);
    p->rot.x += p->unk_14;
    p->rot.y += p->unk_16;
    p->rot.z += p->unk_18;
    return TRUE;
}

static inline void EffectPtcl_Delete(EffectPtcl *o) {
    EFFECT_DELETE(o);
}

static inline void EffectEmitter_Unlink(EffectEmitter *em, EffectPtcl *p) {
    EffectPtcl *next = p->next;
    EffectPtcl *prev = p->prev;
    if (next != NULL) {
        next->prev = prev;
    }
    if (prev != NULL) {
        prev->next = next;
    } else {
        em->ptcls = next;
    }
}

BOOL func_0206b1cc(EffectEmitter *em) {
    BOOL ret = FALSE;
    EffectPtcl *p = em->ptcls;
    EffectPtcl *next;
    while (p != NULL) {
        p->unk_b4 = em->speed;
        if (EffectPtcl_Move(p)) {
            func_0206924c(&em->sub, p);
            ret = TRUE;
            p->time += p->unk_b4;
            p = p->next;
        } else {
            next = p->next;
            EffectEmitter_Unlink(em, p);
            EffectPtcl_Delete(p);
            p = next;
        }
    }
    if (em->parts != NULL) {
        em->parts->pos = em->pos;
        em->parts->ptcls = em->ptcls;
        em->parts->time = em->time;
        em->parts->Step();
    }
    return ret;
}


EffectPtcl *func_0206b340(EffectEmitter *em) {
    EffectPtcl *p;
    EffectPtcl *q;
    EffectPtcl *next;
    EffectPtcl *last = NULL;
    s32 *m;
    if (em->ptcls == NULL) {
        return NULL;
    }
    m = (s32 *)data_02092844;
    for (p = em->ptcls; p != NULL; p = p->next) {
        p->depth = Effect_FxMul(p->pos.x + p->origin.x, m[2]) + Effect_FxMul(p->pos.y + p->origin.y, m[5]) +
                    Effect_FxMul(p->pos.z + p->origin.z, m[8]);
    }
    for (p = em->ptcls->next; p != NULL; p = next) {
        EffectPtcl *prev = p->prev;
        next = p->next;
        prev->next = next;
        if (next != NULL) {
            next->prev = prev;
        }
        for (q = p->prev; q != NULL && q->depth >= p->depth; q = q->prev) {
            last = q;
        }
        if (q == NULL) {
            p->prev = NULL;
            p->next = last;
            last->prev = p;
            em->ptcls = p;
        } else {
            p->prev = q;
            p->next = q->next;
            if (q->next != NULL) {
                q->next->prev = p;
            }
            q->next = p;
        }
    }
    return em->ptcls;
}

}
