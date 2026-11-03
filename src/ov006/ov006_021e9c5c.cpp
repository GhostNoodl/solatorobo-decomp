#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "Main/Res/StageCmd.h"
#include "ov006/Racer.h"

typedef struct ov006_Ent021e9c5c {
    u8 kind;
    u8 unk1;
    u16 id;
    u16 unk4;
    s16 se;
    u8 unk8[4];
} ov006_Ent021e9c5c;


extern "C" {

extern const ov006_Ent021e9c5c data_ov006_021eb858[];
extern u16 data_ov006_021eb894[];
extern void *gSndMgr;

s32 func_ov000_0219a5c8(Actor *self, u16 mask, const VecFx32 *pos, Rot16 *rot, s32 r, s32 a, void **list);
Actor *Obj021984c8_GetActor(void *p);
void *Actor_SpawnKind(s32 id, VecFx32 *pos, Rot16 *rot, u16 a, u16 b);
void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
void *ActorMgr_GetGroup(void *mgr, u16 kind);
void ActorGroup_SendMsg(void *obj, u16 a, int b, int c, int d, int e);

void Ov006Racer_UseItem(Ov006Racer *self) {
    u8 a;
    u8 b;
    const ov006_Ent021e9c5c *ent;
    if (!(self->trig & 0x400) || (a = self->unk_1aa) == 0 || (b = self->unk_1ab) == 0) {
        return;
    }
    if (a != b) {
        return;
    }
    ent = &data_ov006_021eb858[a];
    switch (ent->kind) {
    case 1: {
        u16 id = ent->id;
        u16 tgt = 0xffff;
        VecFx32 pos;
        Rot16 rot;
        if (id == 0xffff) {
            break;
        }
        switch (id) {
        case 0x4f43: {
            void *list[0x20];
            rot = self->look2;
            rot.x += 0x4000;
            if (func_ov000_0219a5c8(self, 0x80, &self->pos, &rot, 0x3c000, 0xc8000, list) && list[0] != NULL) {
                tgt = Obj021984c8_GetActor(list[0])->id;
            }
            pos = self->pos;
            VEC_Add(&pos, &self->vel, &pos);
            VEC_Add(&pos, &self->vel, &pos);
            rot = self->look2;
            break;
        }
        case 0x4f44:
            pos = self->pos;
            VEC_Add(&pos, &self->vel, &pos);
            VEC_Add(&pos, &self->vel, &pos);
            rot = self->look2;
            break;
        default:
            id = tgt;
            break;
        }
        if (id == 0xffff) {
            break;
        }
        Actor_SpawnKind(id, &pos, &rot, self->id, tgt);
        {
            EffectObj *e = Effect_SpawnId(0x69, &self->pos);
            if (e != NULL) {
                self->unk_1e4 = e->id;
            }
        }
        if (ent->se >= 0) {
            SndMgr_PlayAt(gSndMgr, ent->se, &self->pos, 0);
        }
        break;
    }
    case 2:
        self->unk_1f8 = data_ov006_021eb894[self->rank];
        if (self->unk_1e8 == 0) {
            EffectObj *e = Effect_SpawnId(0x391, &self->pos);
            if (e != NULL) {
                self->unk_1e8 = e->id;
                e->SetScaleAll(0x199a);
                e->loopCount = -1;
            }
        }
        if (ent->se >= 0) {
            SndMgr_PlayAt(gSndMgr, ent->se, &self->pos, 0);
        }
        self->phase = 0;
        {
            Model0218fe1c *c = self->model;
            c->color = 0x53ff;
            c->color2 = 0x7f94;
            c->blend = 0x15;
            c->blendMax = 0x14;
        }
        break;
    case 3: {
        void *obj = ActorMgr_GetGroup(gActorMgr, self->id & 0xf000);
        EffectObj *e;
        if (obj != NULL) {
            ActorGroup_SendMsg(obj, self->id, 0xb, 1, 0, 0);
        }
        e = Effect_SpawnId(0x389, &self->pos);
        if (e != NULL) {
            self->unk_1e4 = e->id;
            e->SetScaleAll(0x2800);
            e->speed = 0x3000;
        }
        if (ent->se >= 0) {
            SndMgr_PlayAt(gSndMgr, ent->se, &self->pos, 0);
        }
        break;
    }
    }
    self->unk_1ab = 0;
}

}
