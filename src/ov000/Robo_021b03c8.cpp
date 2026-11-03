#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *gSndMgr;
extern VecFx32 data_ov000_021ca000;
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Vec_RotateY(VecFx32 *out, const VecFx32 *in, u16 ang);
void *Actor_SpawnKind(s32 kind, VecFx32 *pos, void *rot, u16 a, u16 b);
void Field_ShakeCamera(u8 a, u8 b);
void *SndMgr_PlayAtPitch(void *a, s32 b, void *c, s32 d);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
BOOL History_SetState(void *s, s32 a, s32 b);
void func_ov000_021b2b08(Robo021ca458 *self);

static inline Actor *FindActor021b03c8(u16 id) {
    ActorMgr *mgr = gActorMgr;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline void Next021b03c8(Robo021ca458 *self) {
    self->fsm->timer = 0xd;
    self->fsm->st++;
}

void func_ov000_021b03c8(Robo021ca458 *self) {
    ActorSub40 *s = self->fsm;
    Actor *a;
    ActorSub4c *sub;
    void *o;
    VecFx32 v;

    if (self->unk_b2f == 0) {
        self->unk_b2f = 1;
    }
    switch (s->st) {
    case 0:
        if (self->unk_b36 != 0) {
            self->unk_b36 = 1;
        }
        a = FindActor021b03c8(self->unk_b20);
        sub = NULL;
        if (a != NULL) {
            sub = a->targetObj;
        }
        if (sub == NULL || sub->unk_1e == 0) {
            SndMgr_PlayAtPitch(gSndMgr, 0x48, &self->pos, -5);
            Next021b03c8(self);
            return;
        }
        Vec_RotateY(&v, &data_ov000_021ca000, self->rot_y);
        VEC_Add(&v, (VecFx32 *)((u8 *)self + 0x70), &v);
        o = Actor_SpawnKind(0x4800, &v, (u8 *)self + 0x7c, self->id, 0xffff);
        if (o == NULL) {
            return;
        }
        LFLD(u16, o, 0x18) = 1;
        if (LFLD(u8 *, o, 0x4c) != NULL) {
            LFLD(u8, LFLD(u8 *, o, 0x4c), 0x18) |= 0x40;
        }
        sub->unk_1e--;
        Field_ShakeCamera(3, 6);
        SndMgr_PlayAt(gSndMgr, 0x66, &self->pos, 0);
        Next021b03c8(self);
        break;
    case 1:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            if (self->unk_b36 != 0) {
                self->fsm->st = 0;
            } else {
                History_SetState(self->fsm, 1, 0);
            }
        }
        func_ov000_021b2b08(self);
        break;
    }
}
}
