#include "ov009/ov009.h"

extern "C" {

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

extern Ov003Actor *ActorMgr_FindPlayer(void);

void Ov009ActVt_02217d5c_Update(Ov009ActVt_02217d5c *self) {
    Ov003Actor *t;
    if (!Ov009_GameIdle()) {
        return;
    }
    t = ActorMgr_FindPlayer();
    if (t == NULL) {
        return;
    }
    if (Ov009_DistXZ(&self->pos, &t->pos) > 0x32000) {
        self->unk_93_4 = 0;
        self->unk_ea_6 = 1;
    } else {
        if (*self->hp == 0) {
            self->unk_93_4 = 0;
        } else {
            self->unk_93_4 = 1;
        }
        self->unk_ea_6 = 0;
    }
    if (self->fsm->current != 1) {
        return;
    }
    if (!self->unk_93_4) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    if (t != NULL) {
        self->target = t->id;
    }
    self->fsm->flags |= 0x4000;
    self->unk_b6 = 0x96;
}

}
