#include "types.h"
#include "Main/Res/StageFlags.h"
#include "nitro/std.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 b1 : 3;
    u8 rest : 4;
} Bits8_02195d88;

typedef struct {
    u16 x, y, z;
} Rot02195d88;

extern "C" {
extern char data_ov000_021cc45c[];
void func_ov000_02191008(void *a);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_0203f364(void *a);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
u8 *Target_Get(void *a);
u16 func_ov000_02199bc8(void *a, void *pos, u16 t, s32 n);
Robo021ca458 *func_ov000_0219bf90(void);
void func_ov003_021f0c60(void *self, s32 a);

void func_ov000_02195d88(ActorEx *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        self->unk_93_1 = 1;
        if (self->model != NULL) {
            char *name = self->targetObj->unk_0c;
            if (name != NULL) {
                if (STD_CompareString(name, data_ov000_021cc45c) == 0) {
                    func_ov000_02191008(self->model);
                } else {
                    func_ov000_02190cb0(self->model, name, 0x1000, 0);
                    func_ov000_021915a0(self->model);
                }
            }
            self->model->alpha = 0x1f;
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *p = self->hit;
            p->unk_50 = 0;
            p->unk_54 = 0;
            p->unk_58 = 0;
            p = self->hit;
            p->unk_9a_0 = 0;
            p->unk_9a_3 = 0;
            func_0203f364(p);
            p = self->hit;
            p->unk_9a_1 = 0;
            p->unk_9a_4 = 0;
        }
        self->target = 0xffff;
        if (self->hitMesh != NULL) {
            self->unk_cc_0 = 0;
        }
        if (self->param->unk_02_8) {
            LFLD(Bits8_02195d88, ((u8 *)self->targetObj), 0x18).b0 = 1;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 2;
        self->fsm->st++;
        break;
    case 1: {
        u8 *t = Target_Get(((u8 *)self->targetObj));
        u16 r;
        Robo021ca458 *pl;
        if (t != NULL) {
            r = func_ov000_02199bc8(((u8 *)self->targetObj), &self->pos, self->fsm->timer, 10);
            LFLD(Rot02195d88, self, 0x7c) = LFLD(Rot02195d88, t, 0x7c);
            self->fsm->timer = r;
            if (self->targetObj->unk_01 != 3) {
                break;
            }
            if (r < 10) {
                break;
            }
            pl = func_ov000_0219bf90();
            if (pl->id == self->targetObj->target) {
                u32 n = data_0214a424->unk_016 + 1;
                if (n >= 0xffff) {
                    n = 0xffff;
                }
                data_0214a424->unk_016 = n;
                if (self->unk_44 != NULL) {
                    ActorSub44 *q = self->unk_44;
                    q->unk_22_0 = 0;
                    q->unk_22_1 = 0;
                }
                if (self->hit != NULL) {
                    ActorSub48 *p = self->hit;
                    p->unk_9a_0 = 0;
                    p->unk_9a_3 = 0;
                    func_0203f364(p);
                    p = self->hit;
                    p->unk_9a_1 = 0;
                    p->unk_9a_4 = 0;
                }
                if (self->targetObj->unk_03 != 0) {
                    self->targetObj->target = 0xffff;
                    func_ov003_021f0c60(self, 0);
                }
            }
            func_ov000_02198360(self->fsm, 0x15, 0);
        } else {
            func_ov000_02198360(self->fsm, 4, 0);
        }
        break;
    }
    }
}
}
