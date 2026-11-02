#include "ov012/ov012.h"
#include "Main/Math/Rot16.h"

extern "C" {
extern u16 ActorGroup_CountKind(void *p, s32 kind);

static inline u16 Ov012_HpPct(Ov003Actor *self) {
    return self->hp[0] * 100 / self->hp[1];
}

static inline s32 Ov012_Kind(Ov003Actor *o) {
    return o->fsm != NULL ? o->fsm->current : 0;
}

static inline u16 Ov012_FaceAng(Ov003Actor *self, Ov003Actor *o) {
    if (o == NULL || o == self) {
        return self->rot_y;
    }
    return FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
}

static inline s32 Ov012_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void Ov012ActVt_0220b35c_Update(Ov003Actor *self) {
    Ov003Actor *pl;
    Ov003Actor *o;
    VecFx32 v;
    s32 dist;
    u8 kind;
    s32 hp;
    s32 lvl;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = (Ov003Actor *)func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (func_ov000_021b4738(pl)) {
        return;
    }
    self->target = pl->id;
    self->unk_93_4 = 1;
    o = Ov012_FindRes(0x4000, 0x4801);
    v = pl->pos;
    dist = VEC_Distance(&self->pos, &v);
    kind = self->fsm->current;
    if (!func_ov000_021983b0(self->fsm, 0x16, 2, 1)) {
        if (func_ov000_021983b0(self->fsm, 0x13, 5, 1) || func_ov000_021983b0(self->fsm, 0x12, 5, 1) || Ov012_HpPct(self) < 0x1e) {
            if (o != NULL && Ov012_Kind(o) == 0xb) {
                u16 ang = Ov012_FaceAng(self, o);
                if ((u16)(o->rot_y - ang - 0x4000) <= 0x8000) {
                    u16 r;
                    v.x = 0;
                    v.y = 0;
                    v.z = 0;
                    if ((u16)(FX_Atan2(v.x - self->pos.x, v.z - self->pos.z) - ang) > 0x8000) {
                        r = ang - 0x3000;
                    } else {
                        r = ang + 0x3000;
                    }
                    {
                        s32 s = FX_SinCosTable_[(r >> 4) * 2];
                        s32 c = FX_SinCosTable_[(r >> 4) * 2 + 1];
                        dist = 0x4800;
                        v.x = self->pos.x + Ov012_FxMul64(s, dist);
                        v.z = self->pos.z + Ov012_FxMul64(c, dist);
                    }
                    self->unk_b8 = v;
                    self->fsm->flags |= 0x400000;
                    self->unk_b6 = 0x5a;
                }
            }
        }
    }
    if (kind == 2 && VEC_Distance(&self->pos, &self->unk_b8) > 0x1800) {
        self->fsm->flags |= 4;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    lvl = 0;
    hp = Ov012_HpPct(self);
    if (hp < 0xf) {
        lvl = 3;
    } else if (hp < 0x28) {
        lvl = 2;
    }
    if (lvl != 0 && func_ov000_021983b0(self->fsm, 0x12, lvl, 1)) {
        self->fsm->flags |= 0x10000;
    } else if (dist < 0x6000) {
        self->fsm->flags |= 0x8000;
        if (hp < 0x1e) {
            self->unk_b6 = 100;
        } else {
            self->unk_b6 = 0x78;
        }
    } else if (dist < 0xc000) {
        void *m = ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000);
        if (m == NULL || ActorGroup_CountKind(m, 0x4009) <= 2) {
            ActorSub4c *t = NULL;
            if (o != NULL) {
                t = o->targetObj;
            }
            if (t != NULL && t->target != self->id) {
                t = NULL;
            }
            if (t == NULL) {
                self->fsm->flags |= 0x4000;
            }
        }
    }
    if (dist >= 0x7800) {
        self->fsm->flags |= 4;
        self->unk_b8 = v;
        self->unk_b6 = 0x4b;
    }
}

void Ov012ActVt_0220b35c_StateAttack(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        func_02049f44(data_02097e4c, 0x701, &self->pos, 0);
    }
    Ov003Actor_StateAttack(self);
}
extern char data_ov012_0220b400[];
extern char data_ov012_0220b406[];
extern void func_ov000_021911c8(Model0218fe1c *p, s16 a);


void Ov012ActVt_0220b35c_StateAttack2(Ov003Actor *self) {
    Ov003Actor *pl = Ov012_FindActor(self->target);
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov012_0220b400, 0x19a, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        self->unk_94_1 = 1;
        self->unk_ea_0 = 3;
        func_02049f44(data_02097e4c, 0x702, &self->pos, 0);
        break;
    case 1:
        Actor_TurnToActor(self, pl, 0x400);
        self->fsm->timer++;
        if (self->fsm->timer == 1 || self->fsm->timer == 0x1e) {
            EffectObj *e = func_02065f88(0x384, &self->pos);
            e->AddPosXYZ(0, 0x1333, 0);
            e->SetScaleAll(0xe66);
        }
        if (self->model->anim_state == 1) {
            EffectObj *e = func_02065f88(0x192, &self->pos);
            e->AddPosXYZ(0, 0x1333, 0);
            e->SetScaleAll(0x1333);
            e->SetRotXYZ(0, self->rot_y, 0);
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        self->unk_94_1 = 1;
        break;
    case 2:
        if (self->model->anim_state == 1 || Hit_DiffInSphere(&pl->pos, &self->pos, pl->radius + 0x3000)) {
            func_ov000_02191418(self->model, 0, 1);
            self->friction = 0xc00;
            self->fsm->timer = 0;
            self->fsm->st++;
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            func_02049f44(data_02097e4c, 0x701, &self->pos, 0);
        }
        self->unk_94_1 = 1;
        break;
    case 3:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov012_0220b406, 0x19a, 0);
            func_ov000_021911c8(self->model, 0x666);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 4:
        s->timer++;
        if (s->timer > 0x14) {
            EffectObj *e;
            Rot16 r;
            func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
            e = func_02065f88(0x25d, &self->pos);
            e->AddPosXYZ(0, 0x1333, 0);
            e->SetScaleAll(0xb33);
            r.y = self->rot_y + 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->SetRot(&r);
            e = func_02065f88(0x25d, &self->pos);
            e->AddPosXYZ(0, 0x1333, 0);
            e->SetScaleAll(0xb33);
            r.y = self->rot_y - 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->SetRot(&r);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 5:
        s->timer++;
        if (s->timer > 0x96) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    Actor_Move(self, 0);
    self->hit->unk_9a_5 = 1;
    func_ov000_021987b8(self->hit, 0, 0, 0);
    if (self->hit->unk_50 & 0x20000000) {
        self->velY = 0;
    }
}
}
