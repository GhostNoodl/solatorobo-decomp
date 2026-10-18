#include "ov014/ov014.h"

struct Ov014Wave {
    s16 kind;
    u16 wait;
    u16 count;
};

extern "C" {

extern u8 data_ov014_02217d3a[];
extern u8 data_ov014_02217d40[];
extern u8 data_ov014_02217d46[];
extern void func_ov000_021911c8(void *a, s32 b);
extern Ov014Actor *func_ov000_0219bf90(void);
extern u16 FX_Atan2(s32 x, s32 z);
extern u8 data_ov014_02217d4c[];
extern void func_ov000_02191318(void *a, s32 b);
extern s32 func_02040498(s32 max);
extern void func_ov014_02210878(Ov014Actor *self);
extern void *data_02097e4c;
extern u8 data_ov014_02217d1d[];
extern u8 data_ov014_02217d52[];
extern u8 data_ov014_02217d5e[];
extern u8 data_ov014_02217d64[];
extern void func_ov000_02191618(void *a);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern Ov014V *func_02066774(const void *a, const void *b, s32 c, Ov014Vec *pos);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014Actor *func_ov014_02210d9c(Ov014Actor *self);
extern Ov014Actor *func_ov014_02210a78(Ov014Actor *self);
extern Ov014Actor *func_ov014_02210c5c(Ov014Actor *self);

static inline void Ov014_TimerTick(Ov014Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_02210ecc(Ov014Actor *self) {
    self->unk_40->state = 0xffff;
}

void func_ov014_02210ee0(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 1;
        self->unk_40->state = 40;
        break;
    }
    case 10:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 40;
        break;
    case 20:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d40, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 40;
        break;
    case 30:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d46, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 40;
        break;
    case 40:
        if (func_ov000_02191120(self->unk_38)) {
            Ov014Actor *a = func_ov000_0219bf90();
            u16 ang;
            if (a == NULL || a == self) {
                ang = self->rot[1];
            } else {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            }
            if (ang < 0x71c || ang > 0xf8e3) {
                self->unk_40->state = 10;
            } else if (ang < 0x3fff) {
                self->unk_40->state = 20;
            } else {
                self->unk_40->state = 30;
            }
        }
        break;
    }
}

void func_ov014_022110bc(Ov014Actor *self) {
    Ov014Sub40 *s = self->unk_40;
    Ov014Wave *p = FLD(Ov014Wave *, self, 0x140);
    switch (*(volatile u16 *)&s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02191318(self->unk_38, 0);
        self->unk_40->state = 20;
        FLD(u16, self, 0x14c) = p->count;
        FLD(s32, self, 0x144) = func_02040498(0xffff);
        break;
    case 20:
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        switch (p->kind) {
        case 0:
            func_ov014_02210878(self);
            break;
        case 1:
            func_ov014_02210a78(self);
            break;
        case 2:
            func_ov014_02210c5c(self);
            break;
        default:
            func_ov014_02210878(self);
            break;
        }
        FLD(s16, self->unk_38, 0xc4) = 0;
        FLD(u16, self, 0x14c)--;
        if (FLD(u16, self, 0x14c) == 0) {
            self->unk_40->state = 30;
            self->unk_40->timer = 30;
        } else {
            self->unk_40->state++;
            self->unk_40->timer = p->wait;
        }
        break;
    case 21:
        if (*(volatile u16 *)&s->timer != 0) {
            Ov014_TimerTick(s);
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        if (p->wait <= 35) {
            func_ov000_02191318(self->unk_38, 0x24000);
        } else {
            func_ov000_02191318(self->unk_38, 0);
        }
        self->unk_40->state--;
        break;
    case 30:
        if (*(volatile u16 *)&s->timer == 0) {
            s->state = 0xffff;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    default:
        s->state = 0xffff;
        break;
    }
}

void func_ov014_022112b8(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 0xcd;
    case 1: {
        Ov014Vec v;
        u16 t = self->unk_40->timer;
        if (t != 0) {
            if (t == 200) {
                Ov014Actor *e;
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
                e = func_02065f88(0x5e2, &v);
                e->v14(0x3000, 0x3000, 0x3000);
                FLD(s32, e, 0xc8) = 1;
            } else if (t == 100) {
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
                func_02066774(data_ov014_02217d1d, data_ov014_02217d52, 0, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, (Ov014Vec *)((u8 *)self + 0x118), 0);
                func_02049f44(data_02097e4c, 0x50, (Ov014Vec *)((u8 *)self + 0x118), 0);
            }
            Ov014_TimerTick(self->unk_40);
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d5e, 0x1000, 0);
            func_ov000_02191318(self->unk_38, 0);
            func_ov000_02191618(self->unk_38);
            self->unk_40->state++;
        }
        break;
    }
    case 2:
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        func_ov014_02210d9c(self);
        func_02066774(data_ov014_02217d1d, data_ov014_02217d64, 0, (Ov014Vec *)((u8 *)self + 0x118));
        func_02049f44(data_02097e4c, 0x1b, (Ov014Vec *)((u8 *)self + 0x118), 0);
        func_02049f44(data_02097e4c, 0x3e, (Ov014Vec *)((u8 *)self + 0x118), 0);
        FLD(s16, self->unk_38, 0xc4) = 0;
        self->unk_40->state++;
        break;
    case 3: {
        s32 t = 0;
        s32 **q = func_ov000_02190a30(self->unk_38, 0);
        if (*q != NULL) {
            t = **q;
        }
        if (t >= 0x3c000) {
            self->unk_40->state = 0xffff;
        }
        break;
    }
    }
}

}
