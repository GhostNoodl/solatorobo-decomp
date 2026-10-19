#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern void func_ov003_021daab0(void *p);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d87d0(void *p, s32 a);
extern void *data_ov014_02216500[];
extern void func_0203f324(Ov014Sub48 *p);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *target, s32 a);

extern void func_ov000_021911c8(void *a, s32 b);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void func_ov003_021daa6c(void *p, s32 a);

static inline s32 Ov014e_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_02202330(Ov014Actor *self) {
    u8 *m38 = (u8 *)self->unk_38;
    Ov014Sub40 *s = self->unk_40;
    s32 hp = Ov014e_FxMul64(FLD(s32, m38, 0xa8), 0x1333);
    s32 v = FLD(s32, self, 0x330);
    switch (*(volatile u16 *)&s->state) {
    case 0: {
        void *anim = data_ov014_02216500[3];
        Ov014V *e;
        func_ov000_02190cb0((u8 *)self + 0x288, anim, 0x1000, 0);
        func_ov000_021911c8((u8 *)self + 0x288, 0xb33);
        func_ov000_021915a0((u8 *)self + 0x288);
        func_ov000_02190cb0(self->unk_38, anim, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u32, self, 0xf4) |= 0x300000;
        e = func_02065f88(0x648, &self->pos);
        hp >>= 1;
        e->v0c(hp);
        e = func_02065f88(0x322, &self->pos);
        e->v0c(hp + 0x800);
        FLD(s32, e, 0xc8) = -1;
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xff, e);
        self->unk_40->state++;
        break;
    }
    case 1:
        if (v >= hp) {
            break;
        }
        v += Ov014e_FxMul64(hp >> 1, 0x1ec);
        if (v >= hp) {
            s->state++;
        }
        FLD(s32, self, 0x330) = v;
        FLD(s32, self, 0x334) = v;
        FLD(s32, self, 0x338) = v;
        break;
    case 2:
        s->timer++;
        if (s->timer != 0x1e) {
            break;
        }
        func_02065f88(0x38a, &self->pos)->v0c(hp >> 1);
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        func_ov003_021daa6c(FLD(void *, self, 0xfc), 0xff);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 3: {
        u8 c = FLD(u8, m38, 0xbe);
        if (c < 0x1f) {
            c = c + 1;
            if (c >= 0x1f) {
                FLD(u32, self, 0xf4) ^= 0x100000;
                c = 0x1f;
                FLD(u8, m38, 0xbe) = c;
            }
            FLD(u8, self->unk_38, 0xbe) = c;
        }
        if (v > 0) {
            v -= Ov014e_FxMul64(hp >> 1, 0x266);
            if (v <= 0) {
                v = 0;
                FLD(u32, self, 0xf4) ^= 0x200000;
                FLD(Ov014Flags, self, 0x34a).b0 = 0;
            }
            FLD(s32, self, 0x330) = v;
            FLD(s32, self, 0x334) = v;
            FLD(s32, self, 0x338) = v;
        }
        if (FLD(u32, self, 0xf4) & 0x100000) {
            break;
        }
        if (FLD(u32, self, 0xf4) & 0x200000) {
            break;
        }
        self->unk_40->state++;
        break;
    }
    case 4:
        switch (FLD(s16, self, 0xf0)) {
        case 0:
            s->timer++;
            if (s->timer != 10) {
                break;
            }
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x52;
            self->unk_a0 = -0x148;
            self->unk_40->timer = 0;
            self->unk_40->state++;
            break;
        case 1: {
            Ov014Sub44 *n;
            s->timer++;
            if (s->timer != 10) {
                break;
            }
            self->unk_48->unk_30 = 0;
            n = self->unk_44;
            n->unk_22_0 = true;
            n->unk_22_1 = true;
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_a0 = -0x133;
            self->unk_40->timer = 0;
            self->unk_40->state++;
            break;
        }
        case 2:
            FLD(u32, self, 0xf4) ^= 0x40;
            func_ov000_02198360(s, 1, 0);
            break;
        }
        break;
    case 5:
        switch (FLD(s16, self, 0xf0)) {
        case 0: {
            Ov014Sub40 *w;
            func_ov000_0218dbe0(self, 0);
            w = self->unk_40;
            w->timer++;
            if (w->timer != 0x19) {
                break;
            }
            self->unk_40->timer = 0;
            FLD(u32, self, 0xf4) ^= 0x40;
            func_ov000_02198360(self->unk_40, 1, 0);
            break;
        }
        case 1: {
            Ov014Sub40 *w;
            Ov014Sub48 *m;
            func_ov000_0218dbe0(self, 0);
            w = self->unk_40;
            w->timer++;
            if (w->timer != 0x37) {
                break;
            }
            m = self->unk_48;
            m->unk_9a_0 = true;
            m->unk_9a_3 = true;
            func_0203f324(m);
            self->unk_40->timer = 0;
            FLD(u32, self, 0xf4) ^= 0x40;
            func_ov000_02198360(self->unk_40, 1, 0);
            break;
        }
        }
        break;
    }
}

void func_ov014_022027d0(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Sub44 *n;
        Ov014Sub48 *m;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        switch (FLD(s16, self, 0xf0)) {
        case 0:
            self->unk_48->unk_60 = -0x800;
            break;
        case 1:
            self->unk_48->unk_60 = -0x4cd;
            break;
        }
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    case 1: {
        u32 f = FLD(u32, self, 0xf4);
        if (!(f & 1) && f != 0) {
            s32 off = 0;
            switch (FLD(s16, self, 0xf0)) {
            case 0:
                off = 0x1000;
                break;
            case 1:
                off = 0x800;
                break;
            }
            if (self->pos.y < off + (self->unk_64 + 0x4719a)) {
                self->unk_a0 = 0x333;
                func_ov000_0218dbe0(self, 0);
            } else {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
                FLD(u32, self, 0xf4) = 1;
            }
        }
        break;
    }
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), 0xcd);
}

void func_ov014_02202964(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

void func_ov014_02202988(Ov014Actor *self) {
    func_ov003_021daab0(FLD(void *, self, 0xfc));
    self->unk_48->unk_30 = 0x40000000;
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        self->unk_48->unk_60 = 0;
        if (!func_ov003_021d8820((u8 *)self + 0x100)) {
            func_ov003_021d87d0((u8 *)self + 0x100, 1);
        }
    }
    func_ov003_021d5900(self);
    if (self->unk_40->state == 0 && FLD(u16, self, 0xe8) == 0) {
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0x29;
    }
}

}
