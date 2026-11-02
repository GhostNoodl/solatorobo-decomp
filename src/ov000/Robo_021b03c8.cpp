#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern VecFx32 data_ov000_021ca000;
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void func_01ffc9fc(VecFx32 *out, const VecFx32 *in, u16 ang);
void *func_ov000_0219be1c(s32 kind, VecFx32 *pos, void *rot, u16 a, u16 b);
void func_ov000_0218996c(u8 a, u8 b);
void *func_0204a028(void *a, s32 b, void *c, s32 d);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void func_ov000_021b2b08(void *self);

static inline Actor *FindActor021b03c8(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline void Next021b03c8(Robo021ca458 *self) {
    self->unk_40->timer = 0xd;
    self->unk_40->st++;
}

void func_ov000_021b03c8(Robo021ca458 *self) {
    ActorSub40 *s = self->unk_40;
    Actor *a;
    u8 *sub;
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
            sub = ((u8 *)a->unk_4c);
        }
        if (sub == NULL || LFLD(u16, sub, 0x1e) == 0) {
            func_0204a028(data_02097e4c, 0x48, &self->pos, -5);
            Next021b03c8(self);
            return;
        }
        func_01ffc9fc(&v, &data_ov000_021ca000, self->rot_y);
        VEC_Add(&v, (VecFx32 *)((u8 *)self + 0x70), &v);
        o = func_ov000_0219be1c(0x4800, &v, (u8 *)self + 0x7c, self->id, 0xffff);
        if (o == NULL) {
            return;
        }
        LFLD(u16, o, 0x18) = 1;
        if (LFLD(u8 *, o, 0x4c) != NULL) {
            LFLD(u8, LFLD(u8 *, o, 0x4c), 0x18) |= 0x40;
        }
        LFLD(u16, sub, 0x1e)--;
        func_ov000_0218996c(3, 6);
        func_02049f44(data_02097e4c, 0x66, &self->pos, 0);
        Next021b03c8(self);
        break;
    case 1:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            if (self->unk_b36 != 0) {
                self->unk_40->st = 0;
            } else {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        func_ov000_021b2b08(self);
        break;
    }
}
}
