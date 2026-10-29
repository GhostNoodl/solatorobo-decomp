#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022179b4[];
extern void func_ov000_0218ddd4(Ov009Actor *self, const Ov009Vec *v, s32 a);

void func_ov009_0221134c(Ov009Actor *self) {
    Ov009Vec v;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    self->unk_9c = self->unk_b0->unk_00;
    if (FLD(u8, self, 0xff) != 0) {
        self->unk_9c = self->unk_9c + (self->unk_9c >> 3);
    }
    v = self->unk_b8;
    if (self->pos.y > v.y) {
        self->unk_a0 = -self->unk_b0->unk_00 >> 2;
    } else if (self->pos.y < v.y) {
        self->unk_a0 = self->unk_b0->unk_00 >> 2;
    } else {
        self->unk_a0 = 0;
    }
    func_ov000_0218ddd4(self, &v, self->unk_b0->unk_02);
    if ((self->unk_a0 > 0 && self->pos.y > v.y) || (self->unk_a0 < 0 && self->pos.y < v.y)) {
        self->pos.y = v.y;
    }
}

extern void *data_02097e4c;
extern u8 data_ov009_022160b8[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0219a210(Ov009Vec *v, const void *a, u16 b);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
typedef u16 Ov009Row3[3];

void func_ov009_02211470(Ov009Actor *self) {
    Ov009Actor *t = func_ov000_0218d240(self);
    Ov009Sub40 *st;
    if (t == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        u16 pct;
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        pct = (self->unk_50[0] * 100) / self->unk_50[1];
        if (pct >= 0x4b) {
            FLD(u8, self, 0xfd) = 1;
            self->unk_40->state = 1;
            return;
        }
        if (pct >= 0x28) {
            FLD(u8, self, 0xfd) = 2;
            self->unk_40->state = 2;
            return;
        }
        FLD(u8, self, 0xfd) = 3;
        self->unk_40->state = 2;
        return;
    }
    case 1:
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            self->unk_40->state = 3;
            self->unk_40->timer = 0;
        }
        return;
    case 2:
        self->rot[1] = func_01ffc128((FLD(u16 *, self, 0x104) + FLD(u8, self, 0xfc) * 3)[FLD(u8, self, 0xfd) - 1], self->rot[1], self->unk_b0->unk_02, 1, 0x8000);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x14) {
            self->unk_40->state = 3;
            self->unk_40->timer = 0;
        }
        return;
    case 3: {
        Ov009Vec p;
        Ov009Actor *h;
        func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        func_ov000_0219a210(&p, data_ov009_022160b8, self->rot[1]);
        h = func_ov003_021d69f0(self, 0x4802, &p, self->rot, t);
        if (h != NULL) {
            func_ov000_0218d46c(h, self->id, 0xb);
            func_02065f88(0x12c, &p)->v34(0, self->rot[1], 0);
        }
        if (--FLD(u8, self, 0xfd) == 0) {
            if (++FLD(u8, self, 0xfe) >= 2) {
                FLD(u8, self, 0xfe) = 0;
                self->unk_40->timer = 0xb4;
                if (FLD(u8, self, 0xff) != 0) {
                    self->unk_40->timer = 100;
                }
                self->unk_40->state = 4;
                return;
            }
            func_ov000_02198360(self->unk_40, 1, 0);
            self->unk_b6 = 0xb4;
            if (FLD(u8, self, 0xff) != 0) {
                self->unk_b6 = 0x96;
            }
            return;
        }
        self->unk_40->state = 2;
        return;
    }
    case 4:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            FLD(u8, self, 0xfc) = FLD(u8, FLD(u8 *, self, 0x100) + FLD(u8, self, 0xfc) * 16, 0xc);
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
