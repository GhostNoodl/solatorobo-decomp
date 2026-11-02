#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov003/Unit.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"

typedef struct {
    u8 unk_00[0x3c];
    s32 unk_3c;
} Ov003DfEffectData;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern const VecFx32 data_ov003_021f4c58;
extern const u8 data_ov003_021f4c50[];
extern Actor *func_ov000_0219be1c(s32 id, const void *pos, const void *rot, u16 a, u16 b);
extern Actor *ActorMgr_FindKind(ActorMgr *mgr, s32 a, s32 b);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern u16 Camera_GetYaw(Camera *cam);
extern void func_01ffc9fc(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void func_ov000_02191008(void *p);
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void *data_ov000_021ccd64;
extern char data_ov003_021f8350[];
extern void Heap_Free(void *p);
extern void ActorMgr_BroadcastKind(ActorMgr *mgr, u16 a, s32 b);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void SndMgr_StopSeqArc(SndMgr *mgr, s32 id);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0218b700(Ov003Unit *u, s32 a, s32 b);

void func_ov003_021df0c8(ActorEx *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        w->timer++;
        if (w->timer > 0x3c) {
            EffectObj *e;
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4035, 0x15);
            func_ov000_0218996c(0x3c, 0x78);
            e = func_02065f88(5, &self->pos);
            if (e != NULL) {
                e->SetScaleXYZ(0x9800, 0x9800, 0x9800);
                e->AddPosXYZ(0, -0x32000, 0x1e000);
                ((Ov003DfEffectData *)e)->unk_3c = 0xccd;
            }
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02049a48(data_02097e4c, 0x53, -1, -1, -1);
            self->fsm->timer = 0;
            self->fsm->st++;
        } else {
            self->pos.y -= 0xa8f;
        }
        break;
    case 1:
        if (w->timer == 0x5a) {
            func_ov000_02197dec(self, 0xf, 4);
        }
        if (self->fsm->timer > 0x96) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        if ((self->fsm->timer & 0xf) == 0) {
            VecFx32 p;
            VecFx32 sc;
            s32 a = -1;
            s32 b = 100;
            switch (self->fsm->timer & 0x3f) {
            case 0:
                func_02049a48(data_02097e4c, 0x19, a, a, a);
                func_ov000_0218996c(0xf, 0x1e);
                a = 3;
                break;
            case 0x10:
                b = 100;
                break;
            case 0x30:
                b = 100;
                break;
            case 0x20:
                func_02049a48(data_02097e4c, 0x19, a, a, a);
                func_ov000_0218996c(0xf, 0x1e);
                break;
            }
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y -= 0x32000;
            p.z += 0x28000;
            sc.x = 0x5000;
            sc.y = 0x2800;
            sc.z = 0x1800;
            func_ov000_0219b71c(&p, &sc, 0x2800, 0x3800, a, b);
        }
        self->fsm->timer++;
        self->pos.y -= 0xcd;
        self->rot_z += 3;
        break;
    }
}

Ov003ActExSeq *Ov003ActVt_021f8350_Dtor(Ov003ActExSeq *self) {
    *(void **)self = data_ov003_021f8350;
    if (self->seq >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->seq);
    }
    func_ov000_0219429c(self);
    return self;
}

Ov003ActExSeq *Ov003ActVt_021f8350_DtorDelete(Ov003ActExSeq *self) {
    *(void **)self = data_ov003_021f8350;
    if (self->seq >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->seq);
    }
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f8350_Start(Ov003ActExSeq *self) {
    Ov003Unit *u;
    s32 s;
    func_ov000_02194758(self);
    s = self->unk_1a;
    if (s != 0) {
        Model0218fe1c *m = self->model;
        m->scale.x = s;
        m->scale.y = s;
        m->scale.z = s;
    }
    self->unk_84.x = self->pos.x;
    self->unk_84.y = self->pos.y;
    self->unk_84.z = self->pos.z;
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
        func_ov000_0218b700(u, 0x5000, 0);
    }
    self->seq = func_02049afc(data_02097e4c, 0x3f);
}

void func_ov003_021df484(Ov003ActExSeq *self) {
    s32 d;
    s32 diff;
    u16 a;
    u16 shift = 9;
    ActorSub40 *st = self->fsm;
    a = st->timer + 0x80;
    st->timer = a;
    if (self->unk_1a != 0) {
        shift -= 3;
    }
    d = FX_SinCosTable_[(a >> 4) * 2] >> shift;
    if (d > 1 || d < -1) {
        self->pos.y += d;
    }
    diff = self->pos.y - self->unk_84.y;
    if (diff < -0x99a) {
        self->pos.y = self->unk_84.y - 0x99a;
    }
    if (diff > 0x99a) {
        self->pos.y = self->unk_84.y + 0x99a;
    }
}

void func_ov003_021df528(Ov003ActExSeq *self) {
    func_ov003_021df484(self);
}

static inline s32 Ov003DfKind_Get(ActorSub40 *k) {
    return k != NULL ? k->current : 0;
}

void func_ov003_021df534(Ov003ActExSeq *self) {
    switch (self->fsm->st) {
    case 0: {
        VecFx32 v;
        Actor *sp;
        VEC_Add(&self->pos, &data_ov003_021f4c58, &v);
        sp = func_ov000_0219be1c(0x480b, &v, data_ov003_021f4c50, self->id, 0xffff);
        if (sp != NULL) {
            sp->unk_18 = 7;
            func_02065f88(0x325, &v)->SetRotXYZ(0, 0x3800, 0);
        }
        self->fsm->st++;
        break;
    }
    case 1: {
        Actor *a;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_FindKind(data_ov000_021ccd68, 0x4000, 0x480b);
        }
        if (a != NULL && Ov003DfKind_Get(a->fsm) != 0x15) {
            goto end;
        }
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        if (a != NULL) {
            VecFx32 p;
            EffectObj *e;
            p.x = a->pos.x;
            p.y = a->pos.y;
            p.z = a->pos.z;
            e = func_02065f88(0x325, &p);
            if (e != NULL) {
                e->SetScaleAll(0x1c00);
                e->SetRotXYZ(0, 0x3800, 0);
            }
            func_02065f88(3, &p);
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->fsm->st++;
        break;
    }
    }
end:
    func_ov003_021df484(self);
}

static inline u16 Camera_GetAngle(Camera *cam) {
    return cam->mode != 0 ? cam->yaw : Camera_GetYaw(cam);
}

void func_ov003_021df6f4(Ov003ActExSeq *self) {
    Camera *cam = &data_ov000_021ccd54->cam.base;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 v;
        v.x = 0x2c00;
        v.y = -0x1000;
        v.z = 0x4000;
        func_01ffc9fc(&v, &v, Camera_GetAngle(cam));
        VEC_Add(&self->pos, &v, &self->pos);
        self->rot_x = 0xfff0;
        func_ov000_02191008(self->model);
        SndMgr_StopSeqArc(data_02097e4c, self->seq);
        self->seq = -1;
        self->fsm->st++;
    }
    case 1:
        if ((self->fsm->timer & 0xf) == 0) {
            VecFx32 p;
            VecFx32 sc;
            s32 a = -1;
            s32 b = 100;
            switch (self->fsm->timer & 0x3f) {
            case 0:
                a = 3;
                break;
            case 0x10:
                break;
            case 0x20:
                a = 3;
                b = 75;
                break;
            case 0x30:
                a = 3;
                b = 25;
                break;
            }
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += 0x3000;
            sc.x = 0x2800;
            sc.y = 0x2800;
            sc.z = 0x2800;
            func_ov000_0219b71c(&p, &sc, 0xccd, 0x159a, a, b);
        }
        if (self->fsm->timer > 0x1c2) {
            func_ov000_02197dec(self, 0xf, 4);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        self->fsm->timer = ActorSub40_Timer(self->fsm) + 1;
        self->pos.x -= 0x66;
        self->pos.y -= 0x3d;
        if (self->rot_x > 0xe800) {
            self->rot_x -= 0x1c;
        }
        break;
    }
}

}
