#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be94[];
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);

void func_ov013_022074fc(Ov003Actor *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220be94, 0x2ab, 0);
        func_ov000_02191418(self->model, 5, 1);
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        func_0204a028(data_02097e4c, 0x6a, &self->pos, -3);
        self->fsm->st = 10;
        self->fsm->timer = 0;
        break;
    case 10:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02198360(self->fsm, 1, 0);
            self->unk_b6 = 0x3c;
        }
        break;
    }
}

extern char data_ov013_0220be7c[];
extern char data_ov013_0220be9a[];
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 c);
extern void func_0203f364(void *p);
extern Ov013V *func_02065f88(s32 id, VecFx32 *pos);
extern void func_ov000_021911c8(void *a, s32 b);
extern void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);

void func_ov013_022075b8(Ov003Actor *self) {
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0: {
        Ov013V *e;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x540c, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4811, 10);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4813, 10);
        func_ov000_02190cb0(self->model, data_ov013_0220be94, 0x19a, 0);
        self->hp[0] = 0;
        {
            ActorSub48 *c = self->hit;
            c->unk_9a_0 = 0;
            c->unk_9a_3 = 0;
            func_0203f364(c);
        }
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        self->targetObj->target = 0xffff;
        func_0204a028(data_02097e4c, 0x6a, &self->pos, -3);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x5800);
            e->v24(0, self->centerY, 0);
        }
        self->fsm->timer = 0;
        self->fsm->st = 1;
    }
    case 1:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        self->fsm->st = 9;
        self->fsm->timer = 0;
        func_ov000_02190cb0(self->model, data_ov013_0220be7c, 0x89, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0xccd);
        break;
    case 9:
        st->timer++;
        if (st->timer > 0xb4) {
            func_02049a48(data_02097e4c, 0x53, -1, -1, -1);
            func_ov000_02190cb0(self->model, data_ov013_0220be9a, 0x19a, 0);
            func_ov000_021911c8(self->model, 0xccd);
            self->fsm->st = 8;
            self->fsm->timer = 0;
        }
        if (self->fsm->timer % 20 == 0) {
            VecFx32 v;
            VecFx32 r;
            v = self->pos;
            v.y -= self->height >> 1;
            r.x = self->radius + (self->radius >> 1);
            r.y = self->height >> 2;
            r.z = self->radius;
            func_ov000_0219b71c(&v, &r, 0xccd, 0x1666, 0x38b, 0x32);
            func_ov000_0218996c(10, 0xf);
            func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        }
        break;
    case 8:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_0204a028(data_02097e4c, 0x42, &self->pos, -2);
        func_ov000_0218996c(10, 0x3c);
        self->fsm->st = 10;
        self->fsm->timer = 0;
        break;
    case 10:
        st->timer++;
        if (st->timer > 0x50) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            return;
        }
        func_ov003_021d6954(self, 0x1f - (self->fsm->timer >> 1));
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
}

}
