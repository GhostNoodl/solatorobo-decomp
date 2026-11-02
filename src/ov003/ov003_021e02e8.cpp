#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk_14;
} Ov003LampMsg;

// The lamp (vtable data_ov003_021f80f0, 0x104 bytes: NEW_BASIC in Factory_New4000). Its
// model's render callback (Ov003Obj_StartLampCapture / 021e02e8) copies the matrix of node joint into
// mtx; the actor of kind 0x404f is found and read the same way.
class Ov003Lamp : public ActorEx {
public:
    union {
        MtxFx43 mtx;
        struct {
            u8 unk_d0[0x24];
            VecFx32 mtxTrans; // mtx._30.._32
        };
    };
    u8 joint; // func_ov000_021909a8's index of node data_ov003_021f851c
};
SIZE_ASSERT(Ov003Lamp, 0x104);

extern "C" {

typedef struct {
    void *vtbl;
    void *owner;
    u32 flags;
    u8 unk_0c[0x18];
    void (*func)(void *);
    u8 unk_28[0x6a];
    u8 unk_92;
    u8 unk_93[0x1b];
    u8 unk_ae;
} Ov003Obj;

extern Ov003Lamp *ActorMgr_FindKind(ActorMgr *mgr, s32 a, s32 b);



extern const s16 FX_SinCosTable_[];
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern BOOL Model021903b4_Draw(Model0218fe1c *model);

static inline void Ov003Ln_Draw(ActorEx *self, const VecFx32 *p) {
    Model0218fe1c *m = self->model;
    m->trans.x = p->x;
    m->trans.y = p->y;
    m->trans.z = p->z;
    Model021903b4_Draw(self->model);
}

static inline void Ov003Ln_Sub(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

BOOL Ov003ActVt_021f8220_Draw(ActorEx *self) {
    VecFx32 p;
    VecFx32 d;
    MtxFx33 m;
    VEC_Add(&self->pos, &self->unk_84, &p);
    MTX_RotY33_(&m, FX_SinCosTable_[(self->rot_y >> 4) * 2], FX_SinCosTable_[(self->rot_y >> 4) * 2 + 1]);
    d.x = 0xc800;
    d.y = 0;
    d.z = 0;
    MTX_MultVec33(&d, &m, &d);
    switch (self->fsm->current) {
    default:
        ActorEx_Draw(self);
        break;
    case 0x21:
        Ov003Ln_Draw(self, &p);
        VEC_Add(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        VEC_Add(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        break;
    case 0x22:
        Ov003Ln_Draw(self, &p);
        Ov003Ln_Sub(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        Ov003Ln_Sub(&p, &d, &p);
        Ov003Ln_Draw(self, &p);
        break;
    }
    return TRUE;
}

void Ov003Obj_CaptureLampMtx(Ov003Obj *self) {
    MtxFx43 buf;
    Ov003Lamp *p;
    s32 id;
    u8 b;
    if (data_ov000_021ccd68 == NULL) {
        p = NULL;
    } else {
        p = ActorMgr_FindKind(data_ov000_021ccd68, 0x4000, 0x404f);
    }
    if (p == NULL || (b = p->joint) == 0xff) {
        return;
    }
    if (self->flags & 0x10) {
        id = self->unk_ae;
    } else {
        id = -1;
    }
    if (b != id) {
        return;
    }
    NNS_G3dGetCurrentMtx(&buf, NULL);
    MI_Copy48B(&buf, &p->mtx);
}

void Ov003Obj_StartLampCapture(Ov003Obj *self) {
    self->func = (void (*)(void *))Ov003Obj_CaptureLampMtx;
    self->unk_92 = 3;
}

extern char data_ov003_021f851c[];
extern char data_ov003_021f8525[];
extern s32 func_ov000_021909a8(void *model, s32 a, const char *name);
extern BOOL Model0218fe1c_SetAnim(void *model, const void *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(void *model);

void Ov003ActVt_021f80f0_Start(Ov003Lamp *self) {
    Model0218fe1c *m;
    SndQueue *g;
    ActorEx_Start(self);
    self->joint = func_ov000_021909a8(self->model, 0, data_ov003_021f851c);
    m = self->model;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)m->renderObj, (NNSG3dSbcCallBackFunc)Ov003Obj_StartLampCapture);
    m->clearInit = 0;
    self->model->flushVP = 1;
    Model0218fe1c_SetAnim(self->model, data_ov003_021f8525, 0x1000, 0);
    Model0218fe1c_SetLoop(self->model);
    g = data_02097e48.queue;
    if (g->flag0 != 1 || g->unk_74 != 0xffff || g->unk_72 != 0x4e) {
        g->unk_74 = 0x4e;
        g->unk_70 = 0;
    }
}

extern s32 Rand_PlusMinus(s32 max);
extern void HitMesh_SetMtx(void *p, MtxFx43 *m);
extern void Actor_SendMsg(void *p, u16 a, s32 b, s32 c, s32 d, void *e);

void Ov003ActVt_021f80f0_StateIdle(Ov003Lamp *self) {
    Ov003Lamp *p;
    ActorSub40 *w;
    MtxFx43 m;
    Ov003LampMsg msg;
    MtxFx43 m2;
    u8 k;
    if (data_ov000_021ccd68 == NULL) {
        p = NULL;
    } else {
        p = ActorMgr_FindKind(data_ov000_021ccd68, 0x4000, 0x404e);
    }
    w = self->fsm;
    switch (w->st) {
    case 0:
        if (p != NULL && p->unk_93_1 != 0) {
            w->timer = 0;
            self->fsm->st++;
            break;
        }
        w->timer++;
        if ((w->timer & 0x3f) == 0) {
            EffectObj *fx = Effect_SpawnId(0x325, &self->mtxTrans);
            fx->AddPosXYZ(Rand_PlusMinus(0x1800), Rand_PlusMinus(0x800) - 0x800, Rand_PlusMinus(0x1800));
            fx->SetRotXYZ(0, 0x4000, 0);
        }
        break;
    case 1:
        if ((w->timer & 0x3f) == 0) {
            EffectObj *fx = Effect_SpawnId(0x322, &self->mtxTrans);
            fx->AddPosXYZ(Rand_PlusMinus(0x1800), Rand_PlusMinus(0x800) - 0x800, Rand_PlusMinus(0x1800));
        }
        self->fsm->timer++;
        break;
    }
    MI_Copy48B(&self->mtx, &m);
    m._31 -= 0x800;
    HitMesh_SetMtx(self->hitMesh, &m);
    if (p == NULL) {
        return;
    }
    if (p->fsm != NULL) {
        k = p->fsm->current;
    } else {
        k = 0;
    }
    if (k != 1) {
        return;
    }
    msg.pos.x = self->mtxTrans.x;
    msg.pos.y = self->mtxTrans.y;
    msg.pos.z = self->mtxTrans.z;
    msg.rx = self->rot_x;
    msg.ry = self->rot_y;
    msg.rz = self->rot_z;
    msg.unk_14 = 0;
    Actor_SendMsg(p, self->id, 7, 1, sizeof(msg), &msg);
    MI_Copy48B(&self->mtx, &m2);
    Actor_SendMsg(p, self->id, 8, 1, sizeof(m2), &m2);
}

extern void func_ov000_0218996c(u8 a, u8 b);
extern EffectObj *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);

void Ov003ActVt_021f80f0_State21(Ov003Lamp *self) {
    ActorSub40 *w = self->fsm;
    s32 a;
    s32 b;
    VecFx32 sc;
    VecFx32 p;
    Rot16 r;
    EffectObj *fx;
    w->timer++;
    if (w->timer & 0xf) {
        return;
    }
    a = -1;
    b = 100;
    switch (self->fsm->timer & 0x3f) {
    case 0:
        func_ov000_0218996c(6, 10);
        a = 0x131;
        break;
    case 0x10:
        a = 0x322;
        b = 0x4b;
        break;
    case 0x20:
        func_ov000_0218996c(8, 0xf);
        a = 0x131;
        break;
    case 0x30:
        SndMgr_PlayAt(data_02097e4c, 0x35, &self->pos, 0);
        a = 3;
        b = 0x19;
        break;
    }
    sc.x = 0x3800;
    sc.y = 0x3000;
    sc.z = 0x3800;
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    p.y += 0x5800;
    fx = Spawn_ScatterEffect(&p, &sc, 0x800, 0x1000, a, b);
    r.x = self->rot_x;
    r.y = self->rot_y;
    r.z = self->rot_z;
    r.y += 0x8000;
    fx->SetRot(&r);
}

}
