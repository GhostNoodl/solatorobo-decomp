#include "ov009/ov009.h"

extern "C" {

extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern void Field_ShakeCamera(u8 a, u8 b);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);

void Ov009ActVt_022164a0_StateDown(Ov009ActVt_022164a0 *self) {
    if (self->fsm->st == 0 && *self->hp == 0) {
        ActorMgr_BroadcastKind(gActorMgr, 0x5404, 0x15);
    }
    Ov003Actor_StateDown(self);
}

void Ov009ActVt_022168a8_StateAttack(Ov003Actor *self) {
    s32 range;
    ActorGroup *g;
    Actor *o;
    Ov003Actor_StateAttack(self);
    if (self->fsm->current != 0x13) {
        return;
    }
    Field_ShakeCamera(0xc, 0x19);
    range = 0xa000;
    if (gSceneCmd->unk_ca.c[0] == 0x11) {
        range = 0x5000;
    }
    g = ActorMgr_GetGroup(gActorMgr, 0x5000);
    if (g == NULL) {
        return;
    }
    if (g->count > 2) {
        return;
    }
    do {
        o = Ov003Actor_SpawnAtSelf(self, 0x5407, 4);
        if (o != NULL) {
            s32 z = Rand_PlusMinus(range);
            s32 x = Rand_PlusMinus(range);
            o->pos.x = x;
            o->pos.y = 0x8000;
            o->pos.z = z;
        }
    } while (g->count <= 2);
}

void Ov009ActVt_022168a8_StateDown(Ov003Actor *self) {
    if (self->fsm->st == 0 && *self->hp == 0) {
        ActorMgr_BroadcastKind(gActorMgr, 0x5407, 0x15);
    }
    Ov003Actor_StateDown(self);
}

extern char data_ov009_02216ab6[];

void Ov009ActVt_022166a4_Start(Ov009ActVt_022166a4 *self) {
    VecFx32 *v = &self->unk_f4;
    Ov003Actor_Start(self);
    self->unk_f0 = self->rot_y + Rand_PlusMinus(0x3400);
    *v = self->pos;
    if ((u16)(self->kind + 0xabf6) <= 1) {
        s32 d = Rand_UpTo(0x800) + 0x3800;
        v->x += FX_Mul(d, OV009_SIN(self->rot_y));
        v->z += FX_Mul(d, OV009_COS(self->rot_y));
    }
    self->unk_100 = *v;
    self->unk_b8 = *v;
    if (self->kind == 0x5417) {
        self->unk_1c = 0;
    } else {
        self->unk_1c = 0x96;
        self->unk_ea_6 = 1;
    }
    {
        ActorSub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    self->hit->unk_48 = 0x1000;
}

}
