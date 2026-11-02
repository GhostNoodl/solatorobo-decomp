#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern void SndMgr_LoadHeapState(SndMgr *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov000_0216912c(void *p, u16 id, s32 a, u16 b, u16 c, const VecFx32 *pos);

void Ov009ActVt_02216750_Init(Ov009ActVt_02216750 *self) {
    GroupNode *p;
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    if (self->kind != 0x5038 && self->kind != 0x5044) {
        return;
    }
    func_ov000_02187a20(data_ov000_021ccd54, 0xd);
    self->unk_18 = 1;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        p->flags.unk_5 = 1;
    }
    if (self->kind != 0x5044) {
        return;
    }
    self->pos.y += 0x1000;
    if (data_ov000_021ccd54->unk_ca.c[0] == 0x11) {
        self->pos.y += 0x1000;
    }
}

void Ov009ActVt_02216750_Start(Ov009ActVt_02216750 *self) {
    ActorSub48 *s48;
    Ov003Actor_Start(self);
    self->unk_f0 = self->pos;
    self->unk_fc = self->pos;
    if (data_ov000_021ccd54->unk_ca.c[0] != 0x11) {
        s48 = self->hit;
        s48->unk_9a_1 = 0;
        s48->unk_9a_4 = 0;
    }
    s48 = self->hit;
    s48->unk_9a_2 = 0;
    s48->unk_9a_5 = 0;
    if (self->kind != 0x5012) {
        self->unk_44->unk_1c += 0x800;
        self->unk_44->unk_0c.y = -0x1000;
        self->hit->offset.y = -0x1000;
    }
    self->unk_ea_6 = 1;
    if (self->unk_1a != 0) {
        self->fsm->flags |= 0x100000000ULL;
    }
}

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

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

extern Ov003Actor *ActorMgr_FindPlayer(void);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern void func_01ffc9fc(VecFx32 *dst, VecFx32 *src, u16 angle);
extern void Actor_TurnToActor(Actor *self, Actor *other, s32 step);

void Ov009ActVt_02216750_Update(Ov009ActVt_02216750 *self) {
    Robo021ca458 *pl;
    s32 dist;
    s32 dy;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    self->unk_93_4 = 0;
    if (*self->hp == 0) {
        return;
    }
    self->target = 0xffff;
    pl = (Robo021ca458 *)ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    self->target = pl->id;
    dy = pl->pos.y - self->pos.y;
    self->unk_cc = 0x7800;
    dist = 0x7fffffff;
    if (dy <= self->unk_cc && dy >= -self->unk_cc) {
        dist = Ov009_DistXZ(&self->pos, &pl->pos);
    }
    if (dist > 0x28000) {
        self->unk_93_4 = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        return;
    }
    self->unk_93_4 = 1;
    if (pl->hp[5] != 0) {
        return;
    }
    switch (self->unk_b4) {
    case 0: {
        s32 time;
        u32 max;
        s32 id;
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0 || self->fsm->current != 1) {
            return;
        }
        time = 0x3c;
        max = 3;
        if (self->kind == 0x5012) {
            max = 2;
            if (pl->unk_b1e != 0xffff) {
                time = 0x1a4;
            } else {
                time = 0x12c;
                if (data_ov000_021ccd54->unk_ca.c[0] != 2) {
                    time = 0x5a;
                }
            }
        }
        {
            ActorGroup *o = ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000);
            if (o != NULL && o->count < max) {
                VecFx32 ofs;
                Actor *e;
                ofs.x = 0;
                ofs.y = 0;
                ofs.z = 0;
                switch (self->kind) {
                case 0x5012:
                    ofs.x = 0;
                    ofs.y = 0;
                    ofs.z = -0x3000;
                    id = 0x5013;
                    time = 0x1f4;
                    break;
                case 0x5038:
                    id = 0x5045;
                    time = 0x3c;
                    break;
                case 0x5044:
                    id = 0x5045;
                    time = 0x190;
                    break;
                }
                e = Ov003Actor_SpawnAtSelf(self, id, 0x20);
                if (e != NULL) {
                    func_01ffc9fc(&ofs, &ofs, self->rot_y);
                    VEC_Add(&ofs, &self->pos, &ofs);
                    e->pos = ofs;
                    e->unk_1a = 1;
                }
            }
        }
        self->unk_b6 = time;
        self->unk_b4++;
        break;
    }
    case 1:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0 && self->fsm->current == 1) {
            self->fsm->flags |= 0x4000;
            self->unk_b6 = 0x78;
            self->unk_b4 = 0;
            return;
        }
        if (self->kind == 0x5012) {
            return;
        }
        if (self->unk_b6 >= 0x28) {
            return;
        }
        Actor_TurnToActor(self, pl, self->unk_b0->unk_02);
        break;
    }
}

}
