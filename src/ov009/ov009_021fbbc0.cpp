#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov003_021d69a0(Ov009Actor *self, u16 kind, s32 a);
extern void func_ov003_021d36fc(Ov009Actor *self);
extern u8 data_ov009_02216ab6[];
extern void func_ov000_02190758(Ov009Sub38 *m, u16 *rot, s32 a);
extern void func_0203f364(Ov009Sub48 *p);
extern u8 data_ov009_02216ac2[];
extern u8 data_ov009_02216aaa[];
extern u8 data_ov009_02216abc[];
extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

struct Ov009Pair {
    volatile u8 a;
    u8 b;
};

static inline void Ov009Pair_Set(Ov009Pair *p, u8 a, u8 b) {
    p->a = a;
    p->b = b;
}

static inline void Ov009_SpawnChild(Ov009Actor *self) {
    Ov009Actor *o = func_ov003_021d69a0(self, 0x4011, 0);
    if (o != NULL) {
        ((Ov009Byte *)&FLD(u8, o, 0x16))->b1 = 1;
    }
    self->unk_ea_3 = 0;
}

void func_ov009_021fbbc0(Ov009Actor *self) {
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
        self->pos.y += Ov009_FxMul(self->unk_b8.y + 0x2400 - self->pos.y, 0xcd);
        break;
    }
    func_ov003_021d4b68(self);
}

void func_ov009_021fbc9c(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_1a = 1;
        if (self->unk_ea_3) {
            Ov009_SpawnChild(self);
        }
    }
    func_ov003_021d36fc(self);
}

void func_ov009_021fbd04(Ov009Actor *self) {
    if ((self->unk_50[2] >> 12) != 5 && self->unk_40->state == 0 && self->unk_ea_3) {
        Ov009_SpawnChild(self);
    }
    func_ov003_021d6054(self);
}

void func_ov009_021fbd78(Ov009Actor *self) {
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

void func_ov009_021fbe3c(Ov009Actor *self) {
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
            Ov009Pair_Set(q, q->a, 0x20);
        }
    }
    func_ov003_021d5348(self);
    if (self->unk_40->unk_13 == 4) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

void func_ov009_021fbf50(Ov009Actor *self) {
    func_ov003_021d112c(self);
    func_ov000_02198360(self->unk_40, 0x20, 0);
}

BOOL func_ov009_021fbf70(Ov009Actor *self) {
    Ov009Vec t;
    if (FLD(u8, self, 0xf0) != 0 || self->unk_ec_1) {
        FLD(s32, self, 0xf4) += Ov009_FxMul(-0xccd - FLD(s32, self, 0xf4), 0x148);
    } else {
        FLD(s32, self, 0xf4) += Ov009_FxMul(-FLD(s32, self, 0xf4), 0xf6);
    }
    t = self->pos;
    t.y += FLD(s32, self, 0xf4);
    self->unk_38->unk_78 = t;
    func_ov000_02190758(self->unk_38, self->rot, 0);
    self->unk_93_0 = 1;
    return func_ov003_021d16cc(self);
}

void func_ov009_021fc03c(Ov009Actor *self) {
    func_ov003_021d1e8c(self);
    if (self->unk_30 & 0x200) {
        FLD(u8, self, 0xf0) = 0;
    }
}

void func_ov009_021fc05c(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov009Sub44 *s44;
        FLD(u8, self, 0xf0) = 1;
        s44 = self->unk_44;
        FLD(s32, self, 0xf4) = -0xccd;
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

void func_ov009_021fc164(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub44 *s44;
        FLD(u8, self, 0xf0) = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    func_ov003_021d3524(self);
}

void func_ov009_021fc1a4(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub44 *s44;
        FLD(u8, self, 0xf0) = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    func_ov003_021d3600(self);
}

void func_ov009_021fc1e4(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub44 *s44;
        FLD(u8, self, 0xf0) = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
    }
    func_ov003_021d4b68(self);
}

void func_ov009_021fc228(Ov009Actor *self) {
    Ov009Sub48 *s48;
    u32 saved;
    func_ov003_021d112c(self);
    s48 = self->unk_48;
    FLD(u8, self, 0xf0) = 0;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_44 != NULL) {
        func_0203de1c(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
    self->unk_ea_6 = 1;
}

}
