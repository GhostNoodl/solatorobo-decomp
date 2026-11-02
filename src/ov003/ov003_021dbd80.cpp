#include "types.h"
#include "Main/Effect/Effect.h"
#include "ov003/Shot.h"

extern "C" {

extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern Actor *Target_Get(ActorSub4c *t);
extern BOOL Actor_GetTargetSub44(Actor *self);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, const VecFx32 *pos, s32 r, s32 a, void **list);
extern Actor *Obj021984c8_GetActor(void *p);
extern BOOL Hit_Apply(void *a, Actor *b, Actor *c, u16 d, u8 e, VecFx32 *f, s32 g, s32 h, s32 i);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void Ov003Pickup_Update(Ov003Shot *self, u16 mask);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);

static inline u8 Ov003HtPlayer_Kind(Robo021ca458 *pl) {
    if (pl->fsm != NULL) {
        return pl->fsm->current;
    }
    return 0;
}

BOOL Ov003Shot_CheckHits(Ov003Shot *self) {
    void *list[32];
    Robo021ca458 *pl = ActorMgr_FindPlayer();
    Actor *part = Target_Get(self->targetObj);
    s32 hit = 0;
    u16 mask = self->def->hitMask;
    u16 team;
    s32 t;
    if (mask == 0) {
        mask = 0xffff;
    }
    team = self->targetObj->target & 0xf000; // the group nibble of the id
    mask &= ~(1 << (team >> 12));
    if (self->def->life != 0) {
        self->age++;
        t = self->def->life;
        if (t < 0) {
            if (self->age >= -t) {
                hit = -1;
            }
        } else if (self->age >= t) {
            hit = 1;
        }
    }
    if (hit == 0 && self->hit != NULL) {
        u32 fl = self->def->stopFlags;
        if (self->def->flags & 2) {
            if (!Actor_GetTargetSub44(self)) {
                fl = 0xe0000000;
            }
        }
        if (fl & self->hit->unk_50) {
            hit = 2;
        }
    }
    if (hit == 0) {
        s32 r = self->radius;
        s32 n;
        s32 i;
        if (self->targetObj->type != 0x14 || part->kind == 0x1000) {
            r += 0x4cd;
        } else if (pl != NULL) {
            if (pl->unk_b1e == self->id || (Ov003HtPlayer_Kind(pl) == 0x18 && pl->target == self->id)) {
                r >>= 2;
                self->age--;
            }
        }
        n = Actor_FindInRadius(self, mask, &self->pos, r, 0, list);
        if (n != 0) {
        for (i = 0; i < n; i++) {
            Actor *o;
            if (list[i] == NULL) {
                continue;
            }
            o = Obj021984c8_GetActor(list[i]);
            if (o == NULL) {
                continue;
            }
            if (o->targetObj != NULL && team == (u16)(o->targetObj->target & 0xf000)) {
                continue;
            }
            if (!(self->def->flags & 1) || part->kind == 0x1000) {
                hit = 2;
                break;
            }
            {
                s32 a = 100;
                ActorSub4c *def = self->targetObj;
                if (def->unk_18_6) {
                    a = -1;
                }
                Hit_Apply(list[i], self, part, def->unk_08, (u8)def->unk_0a, &self->pos, a, 0x1000, 0x1000);
            }
        }
        }
    }
    if (hit != 0) {
        if (self->unk_bc != NULL) {
            EffectMgr_Kill(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        if (hit == 2 && self->def->hitShakeA != 0 && self->def->hitShakeB != 0) {
            func_ov000_0218996c(self->def->hitShakeA, self->def->hitShakeB);
        }
        if (hit > 0) {
            s32 v;
            v = self->def->hitRadius;
            if (v >= 0) {
                self->radius = v << 4;
            } else {
                self->radius = self->radius * 2;
            }
            v = self->def->hitHeight;
            if (v >= 0) {
                v <<= 4;
                self->height = v;
                self->centerY = v >> 1;
            }
            Ov003Pickup_Update(self, mask);
            History_SetState(self->fsm, 0x15, 0);
        } else {
            self->vfunc_08();
        }
    }
    return hit != 0;
}

}
