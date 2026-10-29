#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215d0c[];
extern void *data_02097e4c;
extern const Ov009Vec data_ov009_02215da8;
extern const Ov009Vec data_ov009_02215d9c;
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218999c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, const Ov009Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_02191690(void *p);

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov009_Ground(Ov009Vec *out, Ov009Actor *self) {
    *out = self->pos;
    func_ov000_0219a2f4(out, self->pos.y + 0x2000, -0xa000);
}

static inline s32 Ov009_Hover(Ov009Actor *self, s32 h, s64 rate) {
    Ov009Vec p;
    Ov009_Ground(&p, self);
    s32 d = p.y + h;
    d -= self->pos.y;
    self->pos.y += Ov009_FxMulL(d, rate);
    p.y += h;
    return VEC_Distance(&self->pos, &p);
}

void func_ov009_021ffa40(Ov009Actor *self) {
    Ov009Vec tp;
    Ov009Vec b;
    Ov009Vec p3;
    Ov009Actor *t;
    Ov009Param *prm;
    Ov009Sub40 *st;
    t = func_ov000_0218d240(self);
    tp.x = t->pos.x;
    tp.y = t->pos.y;
    tp.z = t->pos.z;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[8], 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        prm = self->unk_b0;
        self->unk_9c = prm->unk_00 * 2;
        func_ov000_0218ddd4(self, &tp, prm->unk_02);
        Ov009_Hover(self, 0x4800, 0xcd);
        tp.y = self->pos.y;
        if (VEC_Distance(&self->pos, &tp) < 0x1000) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[0], 0x400, 0);
            self->unk_b8.x = tp.x;
            self->unk_b8.y = tp.y;
            self->unk_b8.z = tp.z;
            func_02049f44(data_02097e4c, 0x39, &self->pos, 0x280);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 200) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    case 2:
        b.x = self->unk_b8.x;
        b.y = self->unk_b8.y;
        b.z = self->unk_b8.z;
        prm = self->unk_b0;
        self->unk_9c = prm->unk_00;
        func_ov000_0218ddd4(self, &b, prm->unk_02);
        Ov009_Hover(self, 0x6000, 0x148);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov009_Ground(&self->unk_84, self);
            func_02049f44(data_02097e4c, 0x54, &self->pos, 0);
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_a0 = -0x800;
            self->unk_40->state++;
        }
        break;
    case 3:
        if (self->pos.y <= self->unk_84.y + 0x1b33) {
            func_ov000_0218999c(0xf, 0xf);
            Ov009_Ground(&p3, self);
            func_02065f88(0x68, &p3)->v20(&data_ov009_02215da8);
            func_02049f44(data_02097e4c, 0x7b, &self->pos, 0);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        } else {
            func_ov000_0218dbe0(self, 0);
            if (*func_ov000_0219bf90()->unk_50 != 0 && Ov009_GameIdle()) {
                func_ov000_0219aae8(self, self, FLD(u16, self, 0xf2), FLD(u16, FLD(u8 *, self, 0x4c), 0xa), 2, &data_ov009_02215d9c, 0, 0x800, 0x2000, 0x64, 0x1000);
            }
        }
        break;
    case 4: {
        u16 tm;
        st = self->unk_40;
        st->timer++;
        tm = st->timer;
        if (tm > 200) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        if (tm == 0xbe) {
            func_ov000_02191690(self->unk_38);
        }
        break;
    }
    case 5:
        if (Ov009_Hover(self, 0x5000, 0x333) <= 0x333) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

}
