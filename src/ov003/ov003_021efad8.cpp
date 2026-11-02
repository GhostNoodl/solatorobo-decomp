#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"


typedef struct {
    s16 id;
    s16 size;
    u16 unk_04;
    u8 unk_06;
    s16 ox, oy, oz;
    s16 unk_0e;
    s16 unk_10;
    u16 rx, ry, rz;
    s16 unk_18;
    s16 unk_1a;
} Ov003BxDef;

extern "C" {

extern char data_ov003_021fa1a4[];
extern void func_ov000_02196c40(ActorEx *self);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void func_0203f364(ActorSub48 *ctl);
extern void Ov003Pickup_Update(ActorEx *self, s32 a);
extern BOOL func_ov000_02198360(ActorSub40 *p, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(Model0218fe1c *model);
extern void func_ov000_021987b8(ActorSub48 *ctl, s32 a, s32 b, s32 c);

extern const Ov003BxDef data_ov003_021f6e60[];
extern Actor *func_ov000_0219bf90(void); // the player

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline s32 Ov003Bx_MaxDist(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dx < dy) {
        dx = dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    if (dx < dz) {
        dx = dz;
    }
    return dx;
}

// The kind record func_0206fef8 returns (only the field read here).
typedef struct {
    u8 unk_00[0x10];
    s16 scale; // model scale once the actor appears
} Ov003BxKindInfo;

typedef struct {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
} Ov003BxSpawnInfo;

extern void *data_ov000_021ccd64;
extern s32 Rand_PlusMinus(s32 n);
extern u32 Rand_UpTo(u32 n);
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, s32 r, s32 h);
extern void HitSphere_Link(ActorSub48 *ctl);
extern void *func_0206fef8(u16 id);
extern Actor *Group_SpawnActor(void *mgr, Ov003BxSpawnInfo *info, VecFx32 *pos, Rot16 *rot, u16 a);

static inline void Ov003Bx_SetScale(Model0218fe1c *m, s32 s) {
    m->scale.x = s;
    m->scale.y = s;
    m->scale.z = s;
}

void Ov003ActVt_021fa07c_State20(ActorEx *self) {
    BOOL ok = FALSE;
    Actor *pl;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s;
        ActorSub48 *ctl;
        self->model->visible = 0;
        self->model->boxTest = 0;
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        ctl = self->hit;
        ctl->unk_9a_0 = 0;
        ctl->unk_9a_3 = 0;
        func_0203f364(ctl);
        self->hit->unk_30 = 0;
        self->hit->unk_4c = 0x14000;
        self->unk_3c->unk_0c = 0x14000;
        if (self->unk_1a >= 1) {
            s32 r = self->unk_1c << 4;
            self->pos.x += Rand_PlusMinus(r);
            self->pos.z += Rand_PlusMinus(r);
        }
        if (self->param->unk_01 == 0) {
            self->rot.y = Rand_UpTo(0xffff);
        }
        self->fsm->st++;
    }
    case 1:
        if (self->unk_1e != 0) {
            self->fsm->timer = Rand_UpTo(0x15);
            ok = TRUE;
        } else {
            pl = func_ov000_0219bf90();
            if (pl != NULL) {
                VecFx32 v;
                v.x = self->pos.x;
                v.y = self->pos.y;
                v.z = self->pos.z;
                v.y -= 0x4000;
                if (Hit_DiffInCylinder(&pl->pos, &v, pl->radius + 0x8000, 0x8000)) {
                    func_ov000_0218996c(6, 0x16);
                    func_02049f44(data_02097e4c, 0x53, &self->pos, 0);
                    if (self->unk_1a < 0) {
                        self->pos = pl->pos;
                    }
                    ok = TRUE;
                }
            }
        }
        if (!ok) {
            return;
        }
        self->model->visible = true;
        Ov003Bx_SetScale(self->model, 0);
        self->pos.y += 0x7800;
        self->fsm->st++;
        return;
    case 2: {
        ActorSub44 *s;
        ActorSub48 *ctl;
        self->fsm->timer++;
        if (self->fsm->timer == 0x16) {
            func_ov000_0218996c(10, 0x19);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            return;
        }
        if (self->fsm->timer <= 0x23) {
            return;
        }
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = true;
            s->unk_22_1 = 1;
        }
        ctl = self->hit;
        ctl->unk_9a_0 = true;
        ctl->unk_9a_3 = 1;
        HitSphere_Link(ctl);
        {
            Ov003BxKindInfo *info = (Ov003BxKindInfo *)func_0206fef8(self->kind);
            Model0218fe1c *m = self->model;
            Ov003Bx_SetScale(m, info->scale);
        }
        self->targetObj->target = self->id;
        self->velY = -0x59a;
        self->gravity = 0x52;
        func_ov000_02198360(self->fsm, 4, 0);
        if (self->unk_1a > 1) {
            Ov003BxSpawnInfo info;
            Actor *o;
            s32 i;
            info.id = self->kind;
            info.kind = self->kind & 0xf000;
            for (i = 0; i < 4; i++) {
                info.unk_04[i] = 0;
            }
            info.unk_0c = -1;
            info.unk_04[1] = self->unk_1a - 1;
            info.unk_04[2] = self->unk_1c;
            info.unk_04[3] = 1;
            o = Group_SpawnActor(data_ov000_021ccd64, &info, &self->unk_84, &self->rot, 0xffff);
            if (o != NULL) {
                o->flags_0 = true;
            }
        }
        return;
    }
    }
}

static inline BOOL Ov003Bx_Flag(ActorSub4c *p) {
    return p->unk_18_2 ? TRUE : FALSE;
}

void Ov003ActVt_021fa07c_StateFly(ActorEx *self) {
    ActorSub40 *w;
    u32 flags;
    if (self->param->unk_01 == 0) {
        func_ov000_02196c40(self);
        return;
    }
    self->hit->unk_9a_6 = 0;
    w = self->fsm;
    switch (w->st) {
    case 0:
        self->unk_92 = 0;
        self->unk_cc_6 = 0;
        self->moveYaw = self->rot.y;
        w->st++;
    case 1:
        flags = self->hit->unk_50;
        if (flags & 0x400) {
            EffectObj *e;
            if (self->unk_cc_6) {
                break;
            }
            self->unk_cc_6 = 1;
            self->speed = 0;
            self->unk_92 = 3;
            func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
            e = func_02065f88(0x2bd, &self->pos);
            if (self->radius > 0x1000) {
                e->SetScaleAll(self->radius);
            }
            break;
        }
        if ((flags & 0x20000000) && self->velY < 0) {
            if (self->unk_92 < 3) {
                if (self->unk_92 == 0) {
                    self->speed = 0x266 - self->unk_92 * 0x29;
                }
                self->velY = (3 - self->unk_92) * 0x133 + 0x266;
                func_ov000_0218996c(8, 0xc);
                func_02065f88(0x12e, &self->pos)->SetScaleAll(self->radius);
                func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            }
            self->unk_92++;
        }
        if (self->unk_92 >= 3 || ((flags & 0x40000000) && !Ov003Bx_Flag(self->targetObj)) || self->hit->unk_58 != 0) {
            ActorSub44 *s = self->unk_44;
            ActorSub48 *ctl;
            if (s != NULL) {
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
            }
            ctl = self->hit;
            if (ctl != NULL) {
                ctl->unk_9a_0 = 0;
                ctl->unk_9a_3 = 0;
                func_0203f364(ctl);
                ctl = self->hit;
                ctl->unk_9a_1 = 0;
                ctl->unk_9a_4 = 0;
            }
            if (self->targetObj->unk_03 != 0) {
                Ov003Pickup_Update(self, 0);
            }
            self->radius *= 2;
            func_ov000_02198360(self->fsm, 0x15, 0);
        } else if (self->velY < 0) {
            func_ov000_02190cb0(self->model, data_ov003_021fa1a4, 0x1000, 0);
            func_ov000_021915a0(self->model);
            w = self->fsm;
            w->timer++;
            if (w->timer > 0x46) {
                self->fsm->timer = 0x46;
                if (!(self->hit->unk_54 & 0x20000000)) {
                    func_ov000_02198360(self->fsm, 0x15, 0);
                }
            }
        }
        break;
    }
    Actor_Move(self, 0);
    func_ov000_021987b8(self->hit, 1, 0, 0);
}

static inline s32 Ov003Bx_MaxDist2(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = b->x;
    s32 dy = b->y;
    s32 dz = b->z;
    dx = a->x - dx;
    dy = a->y - dy;
    dz = a->z - dz;
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dx < dy) {
        dx = dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    if (dx < dz) {
        dx = dz;
    }
    return dx;
}

void Ov003ActVt_021fa114_StateIdle(ActorEx *self) {
    const Ov003BxDef *def = &data_ov003_021f6e60[self->param->unk_01];
    Actor *pl = func_ov000_0219bf90();
    s32 d = Ov003Bx_MaxDist2(&self->pos, &pl->pos);
    ActorSub40 *w;
    if (d > 0x20000) {
        if (self->unk_bc != NULL) {
            EffectMgr_StopLoop(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        self->fsm->st = 0;
    }
    w = self->fsm;
    switch (w->st) {
    case 0:
        if (self->unk_1a < 0 && VEC_Distance(&self->pos, &pl->pos) > 0x3000) {
            return;
        }
        self->fsm->st = 10;
        return;
    case 10: {
        EffectObj *e = func_02065f88(def->id, &self->pos);
        if (e == NULL) {
            return;
        }
        self->unk_bc = e->id;
        e->SetRot(&self->rot);
        e->SetScaleAll(def->size);
        if (self->unk_1a != 0 && d <= 0xc000 && Ov003_GameIdle()) {
            s32 snd = 0x54;
            s32 a = 3;
            if (def->id == 0x25a) {
                snd = 0x80;
                a = -0xc;
            }
            func_0204a028(data_02097e4c, snd, &self->pos, a);
        }
        self->fsm->st++;
        return;
    }
    case 11: {
        s32 n = self->unk_1a;
        if (n > 0 && ++w->timer > n) {
            {
                if (self->unk_bc != NULL) {
                    EffectMgr_StopLoop(data_0214a420, self->unk_bc);
                }
                self->unk_bc = NULL;
                self->fsm->st++;
                self->fsm->timer = 0;
            }
        }
        if (!Ov003_GameIdle()) {
            return;
        }
        {
            VecFx32 pos;
            Rot16 rot;
            rot.x = self->rot.x + def->rx;
            rot.y = self->rot.y + def->ry;
            rot.z = self->rot.z + def->rz;
            pos.x = def->ox << 4;
            pos.y = def->oy << 4;
            pos.z = def->oz << 4;
            func_ov000_0219aae8(self, self, def->unk_04, def->unk_06, 2, &pos, &rot, def->unk_0e << 4, def->unk_10 << 4, def->unk_18, def->unk_1a);
        }
        return;
    }
    case 12: {
        s32 lim = self->unk_1c;
        w->timer++;
        if (lim == 0) {
            lim = 0x3c;
        }
        if (w->timer > lim) {
            self->fsm->st = 10;
            self->fsm->timer = 0;
        }
        return;
    }
    }
}

}
