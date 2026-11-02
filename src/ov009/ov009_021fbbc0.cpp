#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_02216ab6[];
extern void func_ov000_02190758(Model0218fe1c *m, u16 *rot, s32 a);
extern void func_0203f364(ActorSub48 *p);
extern char data_ov009_02216ac2[];
extern u8 data_ov009_02216aaa[];
extern u8 data_ov009_02216abc[];
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

static inline void Ov009_SpawnChild(Ov009ActVt_022166a4 *self) {
    Actor *o = func_ov003_021d69a0(self, 0x4011, 0);
    if (o != NULL) {
        ((Ov009Byte *)&FLD(u8, o, 0x16))->b1 = 1;
    }
    self->unk_ea_3 = 0;
}

void func_ov009_021fbbc0(Ov009ActVt_022166a4 *self) {
    switch (self->fsm->st) {
    case 0x33:
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        func_ov000_02190cb0(self->model, data_ov009_02216ab6, 0x200, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        self->unk_ec_0 = 1;
    case 0x34:
        self->pos.y += FX_Mul(self->unk_b8.y + 0x2400 - self->pos.y, 0xcd);
        break;
    }
    func_ov003_021d4b68(self);
}

void func_ov009_021fbc9c(Ov009ActVt_022166a4 *self) {
    if (self->fsm->st == 0) {
        self->unk_1a = 1;
        if (self->unk_ea_3) {
            Ov009_SpawnChild(self);
        }
    }
    func_ov003_021d36fc(self);
}

void func_ov009_021fbd04(Ov009ActVt_022166a4 *self) {
    if ((self->hp[2] >> 12) != 5 && self->fsm->st == 0 && self->unk_ea_3) {
        Ov009_SpawnChild(self);
    }
    func_ov003_021d6054(self);
}

void func_ov009_021fbd78(Ov009ActVt_022166a4 *self) {
    if ((self->hp[2] >> 12) == 5) {
        func_ov000_02198360(self->fsm, 0x15, 0);
        return;
    }
    if (self->fsm->st == 0) {
        self->unk_1a = 1;
        self->unk_b8 = self->pos;
        if (self->unk_ea_3) {
            Ov009_SpawnChild(self);
        }
    }
    func_ov003_021d5900(self);
    if (self->fsm->current == 4) {
        func_ov000_02198360(self->fsm, 1, 0);
    }
}

void func_ov009_021fbe3c(Ov009ActVt_022166a4 *self) {
    if ((self->hp[2] >> 12) == 5) {
        func_ov000_02198360(self->fsm, 0x15, 0);
        return;
    }
    if (self->fsm->st == 0) {
        Ov009Pair *q;
        self->unk_1a = 1;
        self->unk_b8 = self->pos;
        if (self->unk_ea_3) {
            Ov009_SpawnChild(self);
        }
        if (self->kind == 0x5425) {
            func_ov000_02190cb0(self->model, data_ov009_02216ac2, 0x800, 1);
        }
        q = (Ov009Pair *)&self->hp[4];
        if ((u8)(q->b + 0xf0) <= 1) {
            Ov009Pair_SetB(q, 0x20);
        }
    }
    func_ov003_021d5348(self);
    if (self->fsm->current == 4) {
        func_ov000_02198360(self->fsm, 1, 0);
    }
}

void Ov009ActVt_022163f4_Start(Ov009ActVt_022163f4 *self) {
    func_ov003_021d112c(self);
    func_ov000_02198360(self->fsm, 0x20, 0);
}

BOOL Ov009ActVt_022163f4_Draw(Ov009ActVt_022163f4 *self) {
    VecFx32 t;
    if (self->unk_f0 != 0 || self->unk_ec_1) {
        self->unk_f4 += FX_Mul(-0xccd - self->unk_f4, 0x148);
    } else {
        self->unk_f4 += FX_Mul(-self->unk_f4, 0xf6);
    }
    t = self->pos;
    t.y += self->unk_f4;
    self->model->trans = t;
    func_ov000_02190758(self->model, &self->rot_x, 0);
    self->unk_93_0 = 1;
    return func_ov003_021d16cc(self);
}

void Ov009ActVt_022163f4_Update(Ov009ActVt_022163f4 *self) {
    func_ov003_021d1e8c(self);
    if (self->msg_flags & 0x200) {
        self->unk_f0 = 0;
    }
}

void func_ov009_021fc05c(Ov009ActVt_022163f4 *self) {
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0: {
        ActorSub44 *s44;
        self->unk_f0 = 1;
        s44 = self->unk_44;
        self->unk_f4 = -0xccd;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        func_ov000_02190cb0(self->model, data_ov009_02216ab6, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
        break;
    }
    case 1:
        if (Ov009_GameIdle()) {
            st->timer++;
            if (st->timer > 0x78) {
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        break;
    }
}

void func_ov009_021fc164(Ov009ActVt_022163f4 *self) {
    if (self->fsm->st == 0) {
        ActorSub44 *s44;
        self->unk_f0 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    func_ov003_021d3524(self);
}

void func_ov009_021fc1a4(Ov009ActVt_022163f4 *self) {
    if (self->fsm->st == 0) {
        ActorSub44 *s44;
        self->unk_f0 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    func_ov003_021d3600(self);
}

void func_ov009_021fc1e4(Ov009ActVt_022163f4 *self) {
    if (self->fsm->st == 0) {
        ActorSub44 *s44;
        self->unk_f0 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
    func_ov003_021d4b68(self);
}

void Ov009ActVt_02216348_Start(Ov009ActVt_02216348 *self) {
    ActorSub48 *s48;
    void *saved;
    func_ov003_021d112c(self);
    s48 = self->hit;
    self->unk_f0 = 0;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_44 != NULL) {
        Heap_Free(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
    self->unk_ea_6 = 1;
}

extern void *data_02097e4c;
extern void *func_0204a028(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern BOOL Hit_DiffInCylinder(const VecFx32 *a, const VecFx32 *b, s32 r, s32 h);
struct Ov009HitMsg {
    u8 a;
    u16 b;
    u16 c;
};

void Ov009ActVt_02216348_Update(Ov009ActVt_02216348 *self) {
    Ov003Actor *p;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (self->unk_f0 == 0) {
        func_ov003_021d1e8c(self);
    }
    p = Actor_GetTarget(self);
    if (p != NULL && *p->hp != 0 && self->fsm->current != 0x13) {
        VecFx32 a;
        a.x = self->pos.x;
        a.y = self->pos.y;
        a.z = self->pos.z;
        a.y -= 0x1000;
        if (Hit_DiffInCylinder(&p->pos, &a, self->radius + p->radius, self->height + 0x1000)) {
            s32 m = p->fsm != NULL ? p->fsm->current : 0;
            if (m == 7 || m == 0x16 || m == 0x17 || (u8)(m + 0xf1) <= 2) {
                self->fsm->flags |= 0x80000;
                func_0204a028(data_02097e4c, 0x1e, &self->pos, 0xc);
                self->unk_f0 = 0x3c;
            } else if (Ov009_GameIdle() && self->unk_f0 == 0) {
                Ov009HitMsg msg;
                VecFx32 d;
                msg.a = 1;
                msg.b = 0x333;
                msg.c = 0xf;
                Actor_SendMsg(p, self->id, 0xb, TRUE, 6, &msg);
                {
                    s32 x = p->pos.x;
                    s32 y = p->pos.y;
                    s32 z = p->pos.z;
                    d.x = x - self->pos.x;
                    d.y = y - self->pos.y;
                    d.z = z - self->pos.z;
                }
                VEC_MultAdd(0x59a, &d, &self->pos, &self->pos);
            }
        }
        if (self->unk_f0 != 0) {
            self->unk_f0--;
        }
    }
    if (self->model->anim_state == 1) {
        func_0204a028(data_02097e4c, 0x1e, &self->pos, 0xc);
    }
}

}
