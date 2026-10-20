#include "ov009/ov009.h"

extern "C" {

extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0219a210(Ov009Vec *v, const void *a, u16 b);
extern const Ov009Vec data_ov009_0221601c;
extern u8 data_ov009_0221610c[];

struct Ov009Bits_cc {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
};

void func_ov009_0220e954(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Vec p;
    Ov009Actor *t;
    Ov009Sub40 *st;
    Ov009Sub44 *s;
    Ov009Actor *a;
    s32 dist;
    u16 tm;
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0:
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = 0x11f;
        self->unk_a0 = 0x52;
        self->unk_98 = 0x4000;
        st->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        func_ov000_0218dbe0(self, 0);
        if (self->pos.y > 0x6000) {
            self->pos.y = 0x6000;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xb4) {
            self->unk_9c = 0xa4;
            self->unk_a0 = 0x52;
            self->unk_98 = 0x58e4;
            self->unk_40->state++;
            self->unk_40->timer = 0;
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        if (self->unk_40->timer > 0x78) {
            func_ov000_0218d988(self, t, 0x29);
            self->rot[2] = func_01ffc128(0x71c, self->rot[2], 0x14, 1, 0x8000);
        } else {
            self->rot[2] = func_01ffc128(0xeaab, self->rot[2], 0x52, 1, 0x8000);
        }
        break;
    case 2:
        func_ov000_0218d988(self, t, 0xa4);
        self->rot[2] = func_01ffc128(0xe39, self->rot[2], 0x52, 1, 0x8000);
        self->rot[0] = func_01ffc128(0x11c7, self->rot[0], 0x29, 1, 0x8000);
        func_ov000_0218dbe0(self, 0);
        if (self->pos.y > 0x6000) {
            self->pos.y = 0x6000;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x5a) {
            return;
        }
        if (self->pos.y < 0x5000) {
            return;
        }
        self->unk_9c = 0x333;
        self->unk_a0 = -0x52;
        self->unk_a4 = 0x1052;
        self->unk_98 = self->rot[1];
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 3:
        st->timer++;
        tm = st->timer;
        if (Ov009_GameIdle() && tm > 10 && tm < 100 && tm % 10 == 0) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            func_ov000_0219a210(&p, &data_ov009_0221601c, self->rot[1]);
            a = func_ov000_0219be1c(0x4800, &p, self->rot, self->id, self->unk_90);
            if (a != NULL) {
                FLD(void *, a, 0x60) = data_ov009_0221610c;
                ((Ov009Bits_cc *)((u8 *)a + 0xcc))->b3 = 0;
            }
        }
        func_ov000_0218dbe0(self, 0);
        if (tm <= 200) {
            return;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->pos.z = FLD(s32, self, 0xf8);
        self->pos.x = FLD(s32, self, 0xf0) - 0xf000;
        self->pos.y = FLD(s32, self, 0xf4) + 0x1e000;
        self->rot[1] = 0xc000;
        self->rot[0] = 0;
        self->rot[2] = 0xeaab;
        self->unk_40->state++;
        break;
    case 4:
        d.x = FLD(s32, self, 0xf0) - self->pos.x;
        d.y = FLD(s32, self, 0xf4) - self->pos.y;
        d.z = FLD(s32, self, 0xf8) - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        dist = VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xf0));
        if (dist < 0x2000) {
            s = self->unk_44;
            s->unk_22_0 = true;
            s->unk_22_1 = 1;
            self->rot[2] = func_01ffc128(0, self->rot[2], 0x29, 1, 0x8000);
        }
        if (dist < 0x19a) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
