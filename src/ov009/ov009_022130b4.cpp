#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern u8 data_ov009_022160ac[];
extern u8 data_ov009_022160c4[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_0219a210(VecFx32 *v, const void *a, u16 b);
extern Ov003Actor *func_ov000_0219be1c(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_022130b4(Ov009ActVt_02217d5c *self) {
    if (Actor_GetTarget(self) == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0:
    case 2:
    case 4: {
        ActorSub40 *st;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4092, 6);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x1e) {
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    }
    case 1:
    case 3:
    case 5: {
        VecFx32 p;
        Ov009Rot r;
        Ov003Actor *a;
        Ov003Actor *o;
        u16 s;
        p = self->pos;
        func_ov000_0219a210(&p, data_ov009_022160ac, self->rot_y);
        a = Ov009_FindActor(self->unk_f0);
        r.x = a->rot_x;
        r.y = a->rot_y;
        r.z = a->rot_z;
        r.x += (u16)Rand_UpTo(0x200);
        s = self->fsm->st;
        {
            s32 t = Rand_UpTo(0x400);
            r.y += (u16)(t + (s * 0x600 + 0xee00));
        }
        func_ov000_0219a210(&p, data_ov009_022160c4, r.y);
        o = func_ov000_0219be1c(0x483f, &p, &r, self->id, self->target);
        if (o != NULL) {
            o->unk_1a = 1;
        }
        if (ActorSub40_State(self->fsm) < 5) {
            self->fsm->st++;
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
    }
}

}
