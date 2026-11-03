#include "ov011/ov011.h"

extern "C" {


void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
s32 Rand_PlusMinus(s32 max);
extern const VecFx32 data_02092a50;
extern void *data_02097e4c;
void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
void Field_ShakeCamera(u8 a, u8 b);
void *Spawn_ScatterEffect(VecFx32 *base, VecFx32 *range, s32 min, s32 max, s32 kind, s32 chance);

struct Ov011RotB {
    u16 x, y, z;
};

void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
Actor *Actor_SpawnKind(s32 kind, VecFx32 *pos, u16 *rot, u16 a, u16 b);
extern u8 data_ov011_02207658[];

struct Ov011Tbl63 {
    u8 b[6][3];
};

extern const Ov011Tbl63 data_ov011_0220752c;
extern u8 data_ov011_02207610[];
u32 Rand_UpTo(u32 max);

void Ov011Act7da4_StateAttack(Ov011Act7da4 *self) {
    VecFx32 v;
    Ov011Tbl63 tbl;
    VecFx32 w;
    Ov011RotB r;
    ActorSub40 *s;
    tbl = data_ov011_0220752c;
    s = self->fsm;
    switch (s->st) {
    case 0:
        self->target_id = 0xffff;
        self->unk_36e = 0;
        self->unk_36f = Rand_UpTo(5);
        self->fsm->st++;
    case 1: {
        EffectObj *e;
        ActorSub40 *s1 = self->fsm;
        VecFx32 *arr;
        u8 c;
        if (s1->timer != 0) {
            s1->timer--;
        }
        if (s1->timer != 0) {
            return;
        }
        {
            VecFx32 *p;
            s32 y;
            c = tbl.b[self->unk_36f][self->unk_36e];
            Ov011_VecSet(&self->unk_370[self->unk_36e], (c << 14) - 0x4000, Rand_PlusMinus(0x1800) + 0x3000, -0xf000);
            p = &self->unk_370[self->unk_36e];
            Ov011_MulVec33(p, NNS_G3dGlbGetInvV(), &v);
        }
        VEC_Add(&v, &data_02092a50, &v);
        e = Effect_SpawnId(0x389, &v);
        if (e != NULL) {
            e->SetScaleAll(0x3000);
            e->speed = 0xccd;
        }
        e = Effect_SpawnId(0x5e4, &v);
        if (e != NULL) {
            e->SetScaleAll(0x2000);
        }
        SndMgr_PlayAt(data_02097e4c, 0x5b, &v, 0);
        if (++self->unk_36e >= 3) {
            self->unk_36e = 0;
            self->fsm->st = 10;
            return;
        }
        self->fsm->timer = ((u32)(u16)(self->hp[0] * 100 / self->hp[1]) >> 2) + 0x16;
        break;
    }
    case 10: {
        VecFx32 *p;
        Actor *o;
        u16 h;
        if (self->target_id != 0xffff) {
            return;
        }
        r = *(Ov011RotB *)&self->rot_x;
        r.x += 0xa00;
        p = &self->unk_370[self->unk_36e];
        Ov011_MulVec33(p, NNS_G3dGlbGetInvV(), &w);
        VEC_Add(&w, &data_02092a50, &w);
        h = 0xffff;
        o = Actor_SpawnKind(0x4838, &w, &r.x, self->id, self->target);
        if (o != NULL) {
            o->unk_60 = data_ov011_02207610;
            h = o->id;
        }
        self->target_id = h;
        self->fsm->timer = 3;
        self->fsm->st++;
        break;
    }
    case 11:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 12: {
        Ov003Actor *o = (Ov003Actor *)Ov011_FindActor(self->target_id);
        if (o != NULL) {
            ActorSub40 *t;
            r = *(Ov011RotB *)&o->rot_x;
            t = self->fsm;
            t->timer++;
            r.x -= (u16)(t->timer * 5 + 0x10);
            *(Ov011RotB *)&o->rot_x = r;
        } else {
            self->fsm->timer = ((u32)(u16)(self->hp[0] * 100 / self->hp[1]) >> 4) + 1;
            self->fsm->st++;
        }
        break;
    }
    case 13:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            return;
        }
        self->target_id = 0xffff;
        self->unk_36e++;
        if (self->unk_36e < 3) {
            self->fsm->st = 10;
        } else {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

void Ov011Act7da4_StateAttack2(Ov011Act7da4 *self) {
    VecFx32 v;
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0: {
        EffectObj *e;
        Ov011_VecSet(&self->unk_84, 0, 0x3000, -0xf000);
        Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
        VEC_Add(&v, &data_02092a50, &v);
        e = Effect_SpawnId(0x389, &v);
        if (e != NULL) {
            e->SetScaleAll(0x5000);
            e->speed = 0xccd;
        }
        e = Effect_SpawnId(0x5e4, &v);
        if (e != NULL) {
            e->SetScaleAll(0x3800);
        }
        e = Effect_SpawnId(0x322, &v);
        if (e != NULL) {
            e->SetScaleAll(0x3000);
        }
        SndMgr_PlayAtPitch(data_02097e4c, 0x5b, &v, -2);
        self->fsm->st++;
        self->fsm->timer = 0x5a;
        break;
    }
    case 1: {
        VecFx32 w;
        Actor *o;
        u16 h;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            break;
        }
        h = 0xffff;
        Ov011_MulVec33(&self->unk_84, NNS_G3dGlbGetInvV(), &w);
        VEC_Add(&w, &data_02092a50, &w);
        o = Actor_SpawnKind(0x4839, &w, &self->rot_x, self->id, self->target);
        if (o != NULL) {
            o->unk_60 = data_ov011_02207658;
            h = o->id;
        }
        self->target_id = h;
        self->unk_370[0] = self->unk_84;
        self->fsm->st++;
        self->fsm->timer = 0xf;
        break;
    }
    case 2:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->fsm->st++;
        }
        break;
    case 3: {
        Ov003Actor *o;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            Robo021ca458 *pl;
            self->fsm->timer = 0x28;
            pl = (Robo021ca458 *)ActorMgr_FindPlayer();
            if (pl != NULL) {
                self->unk_370[0].x = pl->unk_af0.x;
                self->unk_370[0].y = pl->unk_af0.y;
                self->unk_370[0].z = pl->unk_af0.z;
            }
            Ov011_MulVec33(&self->unk_370[0], NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            SndMgr_PlayAt(data_02097e4c, 0x5c, &v, 0);
        }
        o = (Ov003Actor *)Ov011_FindActor(self->target_id);
        if (o != NULL) {
            Ov011RotB r;
            v.x = self->unk_370[0].x;
            v.y = self->unk_370[0].y;
            v.z = self->unk_370[0].z;
            v.y += 0x4000;
            v.x -= self->unk_84.x;
            v.y -= self->unk_84.y;
            v.z -= self->unk_84.z;
            VEC_Normalize(&v, &v);
            r = *(Ov011RotB *)&o->rot_x;
            r.x = Angle_Approach(FX_Atan(-v.y), r.x, 0x21, 1, 0x8000);
            r.y = Angle_Approach(FX_Atan2(v.x, v.z), r.y, 0x21, 1, 0x8000);
            *(Ov011RotB *)&o->rot_x = r;
        } else {
            self->target_id = 0xffff;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    }
}

void Ov011Act7da4_StateDie(Ov011Act7da4 *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0: {
        ActorSub44 *p;
        Actor *o;
        EffectObj *e;
        *self->hp = 0;
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        Ov011_VecSet((VecFx32 *)&self->speed, Rand_PlusMinus(0x29), -0x71, Rand_PlusMinus(0x29));
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4804, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4805, 0x15);
        o = Ov011_FindActor(self->target_id);
        if (o != NULL) {
            o->unk_1a = 1;
        }
        e = Effect_SpawnId(0x69, &self->pos);
        e->SetScaleXYZ(0x7800, 0x7800, 0x7800);
        self->fsm->st++;
    }
    case 1: {
        u16 t = self->fsm->timer;
        if (t > 0x78) {
            EffectObj *e;
            Field_ShakeCamera(0xf, 0x3c);
            SndMgr_PlayVolume(data_02097e4c, 0x56, -1, -1, -1);
            e = Effect_SpawnId(0x322, &self->pos);
            e->SetScaleXYZ(0x5800, 0x5800, 0x5800);
            self->fsm->timer = 0x29;
            self->fsm->st++;
            return;
        }
        if ((t & 0xf) == 0) {
            VecFx32 w;
            VecFx32 v;
            s32 kind = -1;
            s32 chance = 100;
            switch (t & 0x3f) {
            case 0:
                kind = 0x38a;
                SndMgr_PlayVolume(data_02097e4c, 0x35, -1, -1, -1);
                Field_ShakeCamera(10, 0x14);
                break;
            case 0x10:
                kind = 0x38a;
                chance = 0x19;
                break;
            case 0x20:
                SndMgr_PlayVolume(data_02097e4c, 0x35, -1, -1, -1);
                Field_ShakeCamera(10, 0x14);
                break;
            case 0x30:
                kind = 0x38a;
                chance = 0x32;
                break;
            }
            w.x = 0x3000;
            w.y = 0x2800;
            w.z = 0x1800;
            v.x = 0;
            v.y = 0x3000;
            v.z = -0xf000;
            Ov011_MulVec33(&v, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            Spawn_ScatterEffect(&v, &w, 0x1000, 0x1c00, kind, chance);
        }
        self->fsm->timer++;
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    }
    case 2:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            Ov003Actor_Defeat(self, 0, 1, 1);
            self->fsm->st = 0xffff;
        }
        break;
    }
}

#pragma force_active on
void Ov011Act7da4_StateKnockBack(Ov011Act7da4 *self) {
    self->vfunc_7c();
}

void *Ov011Act7cf8_Dtor(Ov011Act7cf8 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

void *Ov011Act7cf8_DtorDelete(Ov011Act7cf8 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void *Ov011Act7e50_Dtor(Ov011Act7e50 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

void *Ov011Act7e50_DtorDelete(Ov011Act7e50 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void *Ov011Act7c4c_Dtor(Ov011Act7c4c *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

void *Ov011Act7c4c_DtorDelete(Ov011Act7c4c *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}
#pragma force_active reset
}
