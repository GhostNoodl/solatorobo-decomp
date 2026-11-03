#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/Actor.h"
#include "nitro/mi.h"

#pragma pool_strings on
#pragma dont_reuse_strings off

struct Ov003Act : public Ov003Actor {
    u32 unk_f0;
};

typedef struct {
    u8 pad_00[0x70];
    VecFx32 pos;
    u8 pad_7c[0xaa8];
    u32 unk_b24_0 : 1;
} Ov003Pl;

extern "C" {

extern Ov003Pl *ActorMgr_FindPlayer(void);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s16 a, u8 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);

typedef struct {
    s16 v[9];
} Ov003Route;

extern const Ov003Route data_ov003_021f484c[];
extern u16 FX_Atan2(s32 x, s32 z);
extern void VEC_MultAdd(s32 scale, const VecFx32 *dir, const VecFx32 *base, VecFx32 *out);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 a, u16 b);

void Ov003ActVt_021f7c0c_State20(Ov003Act *self) {
    const char *run = "run00";
    const Ov003Route *r;
    VecFx32 t;
    VecFx32 d;
    VecFx32 d2;
    EffectObj *fx;
    ActorSub44 *s;
    ActorSub40 *w;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, run, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        r = &data_ov003_021f484c[self->unk_1a - 1];
        self->pos.x = r->v[0] << 4;
        self->pos.y = r->v[1] << 4;
        self->pos.z = r->v[2] << 4;
        t.x = r->v[3] << 4;
        t.y = r->v[4] << 4;
        t.z = r->v[5] << 4;
        self->rot_y = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
        s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
        self->fsm->st++;
        break;
    case 1:
        r = &data_ov003_021f484c[self->unk_1a - 1];
        t.x = r->v[3] << 4;
        t.y = r->v[4] << 4;
        t.z = r->v[5] << 4;
        d.x = t.x - self->pos.x;
        d.y = t.y - self->pos.y;
        d.z = t.z - self->pos.z;
        VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
        if (!Hit_DiffInSphere(&self->pos, &t, self->radius + 0x800)) {
            return;
        }
        r = &data_ov003_021f484c[self->unk_1a - 1];
        t.x = r->v[6] << 4;
        t.y = r->v[7] << 4;
        t.z = r->v[8] << 4;
        Model0218fe1c_SetAnim(self->model, "nut00", 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        self->rot_y = func_01ffc128(FX_Atan2(t.x - self->pos.x, t.z - self->pos.z), self->rot_y, 0x200, 1, 0x8000);
        w = self->fsm;
        w->timer++;
        if (w->timer <= 0x14) {
            return;
        }
        fx = Effect_SpawnId(0x192, &self->pos);
        fx->AddPosXYZ(0, self->centerY, 0);
        fx->SetRotXYZ(0, FX_Atan2(t.x - self->pos.x, t.z - self->pos.z), 0);
        SndMgr_PlayAt(data_02097e4c, 0x57, &self->pos, 0);
        Model0218fe1c_SetAnim(self->model, run, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
        break;
    case 2:
        r = &data_ov003_021f484c[self->unk_1a - 1];
        t.x = r->v[6] << 4;
        t.y = r->v[7] << 4;
        t.z = r->v[8] << 4;
        d2.x = t.x - self->pos.x;
        d2.y = t.y - self->pos.y;
        d2.z = t.z - self->pos.z;
        VEC_MultAdd(0xcd, &d2, &self->pos, &self->pos);
        if (!Hit_DiffInSphere(&self->pos, &t, self->radius + 0x800)) {
            return;
        }
        s = self->unk_44;
        s->unk_22_0 = 1;
        s->unk_22_1 = 1;
        History_SetState(self->fsm, 1, 0);
        break;
    }
}

void Ov003ActVt_021f7c0c_StateDie(Ov003Act *self) {
    if (self->fsm->st == 0 && self->kind == 0x5815) {
        EffectObj *fx = Effect_SpawnId(6, &self->pos);
        fx->AddPosXYZ(0, self->centerY, 0);
        fx->speed = 0xc00;
        fx = Effect_SpawnId(0x69, &self->pos);
        fx->AddPosXYZ(0, self->centerY, 0);
        SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
    }
    Ov003Actor_StateDie(self);
}

void Ov003ActVt_021f7b60_Update(Ov003Act *self) {
    u8 a;
    Ov003Pl *p;
    Ov003Actor_Update(self);
    if (self->fsm->current == 0x15) {
        return;
    }
    a = self->model->alpha;
    p = ActorMgr_FindPlayer();
    if (p == NULL || p->unk_b24_0) {
        if (self->fsm->current != 1) {
            self->targetObj->target = 0xffff;
            self->fsm->flags |= 2;
        }
        if (a != 0) {
            ActorSub40 *w = self->fsm;
            w->timer++;
            if (w->timer & 1) {
                a--;
            }
        }
    } else if (a < 0x1f) {
        a++;
    }
    self->model->alpha = a;
}

void Ov003ActVt_021f7b60_State20(Ov003Act *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
    case 1: {
        Ov003Pl *p = ActorMgr_FindPlayer();
        VecFx32 v;
        v.x = p->pos.x;
        v.y = p->pos.y;
        v.z = p->pos.z;
        v.y = self->pos.y;
        if (VEC_Distance(&self->pos, &v) < 0xc000) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    default:
        return;
    }
}

extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 v);
extern void HitSphere_Unlink_0203f364(ActorSub48 *ctl);
extern EffectObj *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void Field_ShakeCamera(u8 a, u8 b);

void Ov003ActVt_021f7b60_StateDie(Ov003Act *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *ctl;
        ActorSub44 *s;
        Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0xccd);
        ctl = self->hit;
        ctl->unk_9a_0 = 0;
        ctl->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(ctl);
        s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        self->fsm->st++;
    }
    case 1: {
        EffectObj *e;
        if (self->fsm->timer % 20 == 0) {
            VecFx32 p;
            VecFx32 v;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += self->centerY;
            v.x = self->radius;
            v.y = self->height >> 2;
            v.z = self->radius + (self->radius >> 2);
            Spawn_ScatterEffect(&p, &v, 0x733, 0xccd, 6, 100);
            Field_ShakeCamera(8, 10);
            SndMgr_PlayAt(data_02097e4c, 0x35, &p, 0);
        }
        self->fsm->timer++;
        if (self->fsm->timer <= 0x78) {
            return;
        }
        e = Effect_SpawnId(0x384, &self->pos);
        e->AddPosXYZ(0, self->centerY, 0);
        e->SetScaleAll(0x1800);
        MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
        EffectObj_AddSndCue(e, 0x42, 5);
        self->unk_f0 = e->id;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 2: {
        ActorSub40 *w;
        if (self->unk_1a == 0 && Effect_Find_020657b0(data_0214a420, self->unk_f0) == NULL) {
            EffectObj *e = Effect_SpawnId(6, &self->pos);
            e->AddPosXYZ(0, self->centerY, 0);
            e->SetScaleAll(0x2000);
            e->speed = 0xc00;
            e = Effect_SpawnId(0x69, &self->pos);
            e->AddPosXYZ(0, self->centerY, 0);
            e->SetScaleAll(0x2000);
            e = Effect_SpawnId(0x57d, &self->pos);
            e->AddPosXYZ(0, self->centerY, 0);
            e->SetScaleAll(0x2000);
            SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
            Field_ShakeCamera(0xc, 0x14);
            self->unk_1a = 1;
        }
        w = self->fsm;
        w->timer++;
        if (w->timer > 0x3c) {
            Ov003Actor_Defeat(self, 1, 1, 1);
            return;
        }
        Ov003Actor_SetAlpha(self, 0x1f - (self->fsm->timer >> 1));
        break;
    }
    }
}

}
