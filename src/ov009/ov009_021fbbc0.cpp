#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov003_021d69a0(Ov009Actor *self, u16 kind, s32 a);
extern void func_ov003_021d36fc(Ov009Actor *self);
extern char data_ov009_02216ab6[];
extern void func_ov000_02190758(Ov009Sub38 *m, u16 *rot, s32 a);
extern void func_0203f364(Ov009Sub48 *p);
extern char data_ov009_02216ac2[];
extern u8 data_ov009_02216aaa[];
extern u8 data_ov009_02216abc[];
extern void Actor_MoveToPos(Ov009Actor *self, Ov009Vec *v, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

static inline void Ov009_SpawnChild(Ov009ActVt_022166a4 *self) {
    Ov009Actor *o = func_ov003_021d69a0(self, 0x4011, 0);
    if (o != NULL) {
        ((Ov009Byte *)&FLD(u8, o, 0x16))->b1 = 1;
    }
    self->unk_ea_3 = 0;
}

void func_ov009_021fbbc0(Ov009ActVt_022166a4 *self) {
    switch (self->unk_40->state) {
    case 0x33:
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x200, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        self->unk_ec_0 = 1;
    case 0x34:
        self->pos.y += FX_Mul(self->unk_b8.y + 0x2400 - self->pos.y, 0xcd);
        break;
    }
    func_ov003_021d4b68(self);
}

void func_ov009_021fbc9c(Ov009ActVt_022166a4 *self) {
    if (self->unk_40->state == 0) {
        self->unk_1a = 1;
        if (self->unk_ea_3) {
            Ov009_SpawnChild(self);
        }
    }
    func_ov003_021d36fc(self);
}

void func_ov009_021fbd04(Ov009ActVt_022166a4 *self) {
    if ((self->unk_50[2] >> 12) != 5 && self->unk_40->state == 0 && self->unk_ea_3) {
        Ov009_SpawnChild(self);
    }
    func_ov003_021d6054(self);
}

void func_ov009_021fbd78(Ov009ActVt_022166a4 *self) {
    if ((self->unk_50[2] >> 12) == 5) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (self->unk_40->state == 0) {
        self->unk_1a = 1;
        self->unk_b8 = self->pos;
        if (self->unk_ea_3) {
            Ov009_SpawnChild(self);
        }
    }
    func_ov003_021d5900(self);
    if (self->unk_40->unk_13 == 4) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

void func_ov009_021fbe3c(Ov009ActVt_022166a4 *self) {
    if ((self->unk_50[2] >> 12) == 5) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (self->unk_40->state == 0) {
        Ov009Pair *q;
        self->unk_1a = 1;
        self->unk_b8 = self->pos;
        if (self->unk_ea_3) {
            Ov009_SpawnChild(self);
        }
        if (self->kind == 0x5425) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02216ac2, 0x800, 1);
        }
        q = (Ov009Pair *)&self->unk_50[4];
        if ((u8)(q->b + 0xf0) <= 1) {
            Ov009Pair_SetB(q, 0x20);
        }
    }
    func_ov003_021d5348(self);
    if (self->unk_40->unk_13 == 4) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

void Ov009ActVt_022163f4_Start(Ov009ActVt_022163f4 *self) {
    func_ov003_021d112c(self);
    func_ov000_02198360(self->unk_40, 0x20, 0);
}

BOOL Ov009ActVt_022163f4_Draw(Ov009ActVt_022163f4 *self) {
    Ov009Vec t;
    if (self->unk_f0 != 0 || self->unk_ec_1) {
        self->unk_f4 += FX_Mul(-0xccd - self->unk_f4, 0x148);
    } else {
        self->unk_f4 += FX_Mul(-self->unk_f4, 0xf6);
    }
    t = self->pos;
    t.y += self->unk_f4;
    self->unk_38->unk_78 = t;
    func_ov000_02190758(self->unk_38, self->rot, 0);
    self->unk_93_0 = 1;
    return func_ov003_021d16cc(self);
}

void Ov009ActVt_022163f4_Update(Ov009ActVt_022163f4 *self) {
    func_ov003_021d1e8c(self);
    if (self->unk_30 & 0x200) {
        self->unk_f0 = 0;
    }
}

void func_ov009_021fc05c(Ov009ActVt_022163f4 *self) {
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov009Sub44 *s44;
        self->unk_f0 = 1;
        s44 = self->unk_44;
        self->unk_f4 = -0xccd;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        break;
    }
    case 1:
        if (Ov009_GameIdle()) {
            st->timer++;
            if (st->timer > 0x78) {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
}

void func_ov009_021fc164(Ov009ActVt_022163f4 *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub44 *s44;
        self->unk_f0 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    func_ov003_021d3524(self);
}

void func_ov009_021fc1a4(Ov009ActVt_022163f4 *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub44 *s44;
        self->unk_f0 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    func_ov003_021d3600(self);
}

void func_ov009_021fc1e4(Ov009ActVt_022163f4 *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub44 *s44;
        self->unk_f0 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
    func_ov003_021d4b68(self);
}

void Ov009ActVt_02216348_Start(Ov009ActVt_02216348 *self) {
    Ov009Sub48 *s48;
    void *saved;
    func_ov003_021d112c(self);
    s48 = self->unk_48;
    self->unk_f0 = 0;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (self->unk_44 != NULL) {
        Heap_Free(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
    self->unk_ea_6 = 1;
}

extern void *data_02097e4c;
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);
struct Ov009HitMsg {
    u8 a;
    u16 b;
    u16 c;
};

void Ov009ActVt_02216348_Update(Ov009ActVt_02216348 *self) {
    Ov009Actor *p;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (self->unk_f0 == 0) {
        func_ov003_021d1e8c(self);
    }
    p = Actor_GetTarget(self);
    if (p != NULL && *p->unk_50 != 0 && self->unk_40->unk_13 != 0x13) {
        Ov009Vec a;
        a.x = self->pos.x;
        a.y = self->pos.y;
        a.z = self->pos.z;
        a.y -= 0x1000;
        if (func_01ffc584(&p->pos, &a, self->unk_64 + p->unk_64, self->unk_68 + 0x1000)) {
            s32 m = p->unk_40 != NULL ? p->unk_40->unk_13 : 0;
            if (m == 7 || m == 0x16 || m == 0x17 || (u8)(m + 0xf1) <= 2) {
                self->unk_40->flags |= 0x80000;
                func_0204a028(data_02097e4c, 0x1e, &self->pos, 0xc);
                self->unk_f0 = 0x3c;
            } else if (Ov009_GameIdle() && self->unk_f0 == 0) {
                Ov009HitMsg msg;
                Ov009Vec d;
                msg.a = 1;
                msg.b = 0x333;
                msg.c = 0xf;
                Actor_SendMsg((Actor *)p, self->id, 0xb, TRUE, 6, &msg);
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
    if (self->unk_38->anim_state == 1) {
        func_0204a028(data_02097e4c, 0x1e, &self->pos, 0xc);
    }
}

}
