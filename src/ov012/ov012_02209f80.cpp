#include "ov012/ov012.h"

extern "C" {
extern char data_ov012_0220b406[];
extern char data_ov012_0220b40c[];
extern char data_ov012_0220b412[];
extern char data_ov012_0220b418[];
extern Ov012Actor *func_ov003_021d69a0(Ov012Actor *self, u16 kind, s32 a);

static inline u16 Ov012_AngTo(Ov012Actor *self, Ov012Actor *t) {
    if (t == NULL || t == self) {
        return self->rot[1];
    }
    return FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
}

void func_ov012_02209bd4(Ov012Actor *self) {
    Ov012Actor *o = Ov012_FindActor(self->unk_d0->target_id);
    Ov012Actor *pl = Actor_GetTarget(self);
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        self->unk_9c = 0;
        self->unk_96 = self->rot[1];
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0x701, &self->pos, 0);
        if (self->unk_d0->target_id != 0xffff) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220b40c, 0x400, 0);
            self->unk_40->state = 10;
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220b412, 0x400, 0);
            self->unk_40->state++;
        }
        break;
    case 1:
        if (self->unk_38->unk_c4 == 1) {
            Ov012Actor *n = func_ov003_021d69a0(self, 0x4009, 9);
            if (n != NULL) {
                self->unk_d0->target_id = n->id;
            }
            self->unk_40->state++;
        }
        Actor_TurnToActor(self, pl, 0x400);
        break;
    case 2:
        if (o != NULL && o->unk_14 != 2) {
            break;
        }
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220b40c, 0x400, 0);
        self->unk_40->state = 10;
        break;
    case 10:
        if (pl != NULL) {
            self->unk_96 = Ov012_AngTo(self, pl);
            self->rot[1] = func_01ffc128(self->unk_96, self->rot[1], 0x59a, 1, 0x8000);
        }
        if (self->unk_38->unk_c4 != 1) {
            break;
        }
        if (o != NULL) {
            func_ov000_0218d46c((StageObj3D *)o, self->id, 0xe);
        }
        self->unk_40->state++;
        break;
    case 11:
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        if (o != NULL && o->unk_4c != NULL && o->unk_4c->unk_1e == 0) {
            Ov012Actor *n = Ov012_FindActor(self->unk_d0->target_id);
            if (n != NULL) {
                func_ov000_0218d46c((StageObj3D *)n, self->id, 10);
                if (n->unk_4c != NULL) {
                    FLD(Ov012Flags8, n->unk_4c, 0x18).b0 = 0;
                }
                self->unk_d0->target_id = 0xffff;
            }
            func_02049f44(data_02097e4c, 0x700, &self->pos, 0);
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220b418, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 12:
        s->timer++;
        if (s->timer <= 0x3c) {
            break;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 13:
        s->timer++;
        if (s->timer > 0x3c) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        Actor_TurnToActor(self, pl, 0x400);
        break;
    }
}

void func_ov012_02209f80(Ov012Actor *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220b406, 0x400, 0);
        self->unk_9c = 0x59a;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0x700, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 0x2d || VEC_Distance(&self->pos, &self->unk_b8) < 0x1800) {
            self->unk_a4 = 0xc00;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        {
            Ov012Vec v;
            v.x = self->unk_b8.x;
            v.y = self->unk_b8.y;
            v.z = self->unk_b8.z;
            Actor_MoveToPos(self, &v, 0);
        }
        break;
    case 2:
        s->timer++;
        if (s->timer > 0x3c) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        Actor_Move((Actor *)self, 0);
        break;
    }
    Actor_TurnToActor(self, Actor_GetTarget(self), 0x400);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}
}

extern "C" {
void func_ov012_0220a0f4(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012Actor *o = Ov012_FindActor(self->unk_d0->target_id);
        if (o != NULL) {
            void *p;
            func_ov000_0218d46c((StageObj3D *)o, self->id, 10);
            p = o->unk_4c;
            if (p != NULL) {
                FLD(Ov012Flags8, p, 0x18).b0 = 0;
            }
            self->unk_d0->target_id = 0xffff;
        }
        if (*self->unk_50 == 0) {
            func_02049f44(data_02097e4c, 0x704, &self->pos, 0);
        }
    }
    func_ov003_021d5900(self);
}
}

extern "C" {
void func_ov012_0220a1ac(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012V *e;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4009, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4801, 0x15);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x2400);
            e->v24(0, self->unk_6c, 0);
        }
    }
    func_ov003_021d6054(self);
}
}

extern "C" {
void func_ov012_0220a244(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012Actor *o = Ov012_FindActor(self->unk_d0->target_id);
        if (o != NULL) {
            void *p;
            func_ov000_0218d46c((StageObj3D *)o, self->id, 10);
            p = o->unk_4c;
            if (p != NULL) {
                FLD(Ov012Flags8, p, 0x18).b0 = 0;
            }
            self->unk_d0->target_id = 0xffff;
        }
        func_02049f44(data_02097e4c, 0x703, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
}
}

extern "C" {
void func_ov012_0220a2ec(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012Actor *o = Ov012_FindActor(self->unk_d0->target_id);
        if (o != NULL) {
            void *p;
            func_ov000_0218d46c((StageObj3D *)o, self->id, 10);
            p = o->unk_4c;
            if (p != NULL) {
                FLD(Ov012Flags8, p, 0x18).b0 = 0;
            }
            self->unk_d0->target_id = 0xffff;
        }
        func_02049f44(data_02097e4c, 0x704, &self->pos, 0);
    }
    func_ov003_021d5348(self);
}
}

extern "C" {
void *func_ov012_0220a394(void *self) {
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
void *func_ov012_0220a3a8(void *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}
}
