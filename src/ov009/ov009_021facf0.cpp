#include "ov009/ov009.h"

extern "C" {

extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);

void func_ov009_021facf0(Ov009ActVt_02216a00 *self) {
    if (self->fsm->st == 0) {
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x5401, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x541f, 0x15);
        self->unk_ea_10 = 1;
    }
    func_ov003_021d6054(self);
}

void func_ov009_021fad54(Ov003Actor *self) {
    Ov003Actor *a;
    func_ov003_021d112c(self);
    if (self->unk_1a == 0) {
        return;
    }
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = ActorMgr_FindKind(data_ov000_021ccd68, 0x1000, 0x1001);
    }
    if (a != NULL) {
        self->target = a->id;
    }
    self->unk_c8 = 0x50000;
}

extern void *data_02097e4c;
extern char data_ov009_02216ab0[];
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void func_ov009_021fada8(Ov009ActVt_022164a0 *self) {
    ActorSub40 *st = self->fsm;
    ActorSub44 *s44;
    switch (st->st) {
    case 0:
        if (self->unk_1a != 0) {
            func_ov000_02198360(st, 1, 0);
            return;
        }
        self->pos.y += 0x5000;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->velY = -0x19a;
        self->gravity = 0x52;
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
        self->fsm->st++;
    case 1:
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 0, 0, 0);
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov009_02216ab0, 0x200, 0);
        func_02065f88(0x12e, &self->pos)->SetScaleAll(0x1400);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->fsm->st++;
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x2d) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_021911c8(void *model, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern Ov003Actor *ActorMgr_GetGroup(void *mgr, u16 id);
extern void func_01ffc9fc(VecFx32 *out, const void *a, s32 b);
static inline Ov003Actor *Ov009_FindActor5(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_021faf48(Ov009ActVt_022164a0 *self) {
    Ov003Actor *t = Ov009_FindActor5(self->target);
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_02216ab0, 0x200, 0);
        {
            Model0218fe1c *m = self->model;
            FLD(s32, m, 0xd8) = 0;
            FLD(s32, m, 0xdc) = 0;
        }
        func_ov000_021911c8(self->model, 0x800);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        switch (self->kind) {
        case 0x5032:
            self->unk_f0 = 0xb4;
            break;
        case 0x5402:
            self->unk_f0 = 100;
            break;
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x28) {
            self->velY = 0x400;
            self->gravity = 0x29;
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    case 2: {
        u16 a;
        Ov003Actor *g;
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 0, 0, 0);
        if (self->velY < 0) {
            self->gravity = 0x52;
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov009_02216ab0, 0x800, 1);
        if (t != NULL) {
            func_ov000_0219aae8(self, self, self->unk_f0, 0x20, (u16)(1 << (t->id >> 12)), NULL, 0, 0x3400, 0x2800, 0x64, 0x1000);
        }
        func_02065f88(0x66, &self->pos)->SetScaleAll(0x1c00);
        g = ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000);
        if (g != NULL && FLD(u16, g, 0x16) <= 3) {
            do {
                Actor *o = func_ov003_021d69a0(self, 0x5404, 4);
                if (o != NULL) {
                    VecFx32 v;
                    v.z = self->radius;
                    v.x = 0;
                    v.y = 0x2000;
                    a = self->rot_y + 0xe800 + Rand_UpTo(0x3000);
                    func_01ffc9fc(&v, &v, a);
                    VEC_Add(&v, &self->pos, &v);
                    o->pos.x = v.x;
                    o->pos.y = v.y;
                    o->pos.z = v.z;
                    o->speed = Rand_UpTo(0x80) + 0x19a;
                    o->velY = 0x333;
                    o->friction = 0;
                    o->gravity = 0x52;
                    o->moveYaw = a;
                }
            } while (FLD(u16, g, 0x16) <= 3);
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    }
    case 3:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x1e) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        self->hit->unk_9a_5 = 1;
        break;
    }
}

}
