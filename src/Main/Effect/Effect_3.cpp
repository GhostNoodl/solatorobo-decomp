#include "Main/Effect/Effect.h"

extern "C" {

extern EffectFile *func_02034b98(void *arc, const char *name);
extern void func_02068508(struct EffectSetup *setup, void *data, EffectVec *pos);
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
        setup = (EffectSetup *)func_0203dd9c(0x28);
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

void func_0206500c(EffectObj *obj, const EffectVec *pos) {
    obj->pos = *pos;
}

void func_02065028(EffectObj *obj, const EffectRot *rot) {
    obj->rot = *rot;
}

void func_02065044(EffectObj *obj, const EffectVec *scale) {
    obj->scale = *scale;
}

void func_02065060(EffectObj *obj, s32 param) {
    obj->unk_d4 = param;
}

EffectSetup *func_02065068(EffectSetup *setup) {
    *(u32 **)setup = data_0208c1d8;
    func_02068540(setup);
    func_0203de1c(setup);
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

void func_020650e0(EffectGroup *g, const EffectVec *pos) {
    EffectVec d;
    EffectObj *c;
    d.x = pos->x - g->pos.x;
    d.y = pos->y - g->pos.y;
    d.z = pos->z - g->pos.z;
    for (c = g->child; c != NULL; c = c->child) {
        c->AddPos(&d);
    }
    g->pos = *pos;
}

void func_0206516c(EffectObj *obj, const EffectVec *delta) {
    VEC_Add(&obj->pos, delta, &obj->pos);
}

void func_02065184(EffectObj *obj, s32 x, s32 y, s32 z) {
    EffectVec v;
    v.x = x;
    v.y = y;
    v.z = z;
    obj->SetPos(&v);
}

void func_020651b0(EffectGroup *g, const EffectVec *delta) {
    EffectObj *c;
    for (c = g->child; c != NULL; c = c->child) {
        c->AddPos(delta);
    }
    VEC_Add(&g->pos, delta, &g->pos);
}

void func_020651fc(EffectObj *obj, s32 x, s32 y, s32 z) {
    EffectVec v;
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

void func_02065310(EffectGroup *g, const EffectVec *scale) {
    s32 fx = FX_Div(scale->x, g->scale.x);
    s32 fy = FX_Div(scale->y, g->scale.y);
    s32 fz = FX_Div(scale->z, g->scale.z);
    EffectObj *c;
    EffectVec v;
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
    EffectVec v;
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

extern void func_0203db10(void *task);
extern void func_02043548(EffectCamera *camera);
extern void MTX_Identity44_(void *mtx);

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
    MTX_Identity44_(m->proj);
}

void func_020654b8(void) {
    EffectMgr *m;
    if (data_0214a41c.mgr != NULL) {
        return;
    }
    m = (EffectMgr *)func_0203dd9c(sizeof(EffectMgr));
    if (m != NULL) {
        func_0203db10(m);
        func_02043548(&m->camera);
        EffectMgr_Reset(m);
    }
    data_0214a41c.mgr = m;
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
    if (data_0214a41c.mgr != NULL) {
        EffectMgr *m = data_0214a41c.mgr;
        if (m != NULL) {
            EffectMgr_Dtor(m);
            func_0203de1c(m);
        }
        data_0214a41c.mgr = NULL;
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

EffectObj *func_02065720(EffectObj *obj) {
    *(u32 **)obj = data_0208c2e4;
    func_02063bd0(obj);
    func_0203de1c(obj);
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

extern BOOL func_0203dbb0(void *task, s32 arg);

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
        if (func_0203dbb0(m, 1)) {
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
