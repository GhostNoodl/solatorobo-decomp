#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov014_02217a4e[];
extern u8 data_ov014_02217a72[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov014_0220a2d0(Ov014Actor *self, s32 a);

struct Ov014Prm {
    s16 a;
    u16 b;
    u16 c;
};

struct Ov014G190A {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

static inline void Ov014_TickA(Ov014Sub40 *st) {
    u16 t = Ov014Sub40_Timer(st);
    if (t != 0) {
        st->timer = t - 1;
    }
}

void func_ov014_0220abf8(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        u32 mask = 0;
        Ov014Prm *p;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a72, 0x2ab, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        p = FLD(Ov014Prm *, self, 0xf0);
        FLD(u8, self, 0xfc) = 1;
        FLD(u16, self, 0xf8) = p->c;
        switch (p->a) {
        case 0:
            FLD(u32, self, 0xf4) = 0xffff;
            break;
        case 1:
            FLD(u32, self, 0xf4) = mask;
            break;
        case 2: {
            u8 n = p->c - 1;
            if (n <= 31) {
                mask |= 1 << (u8)func_02040498(n);
            }
            FLD(u32, self, 0xf4) = mask;
            break;
        }
        case 3: {
            u8 n = p->c - 1;
            if (n <= 31) {
                u8 k;
                for (k = 2; k != 0; k--) {
                    u8 r = func_02040498(n);
                    while (mask & (1 << r)) {
                        r++;
                        r %= n + 1;
                    }
                    mask |= 1 << r;
                }
            }
            FLD(u32, self, 0xf4) = mask;
            break;
        }
        case 4: {
            u8 n = p->c - 1;
            if (n <= 31) {
                u8 k;
                for (k = 3; k != 0; k--) {
                    u8 r = func_02040498(n);
                    while (mask & (1 << r)) {
                        r++;
                        r %= n + 1;
                    }
                    mask |= 1 << r;
                }
            }
            FLD(u32, self, 0xf4) = mask;
            break;
        }
        default:
            FLD(u32, self, 0xf4) = 0;
            break;
        }
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014Game54 *g;
        Ov014V *e;
        if (FLD(s16, self->unk_38, 0xc4) == 3) {
            e = func_02065f88(0x648, &self->pos);
            e->v0c(0x3000);
            FLD(s32, e, 0xc8) = 2;
            func_02049f44(data_02097e4c, 0xc00, &self->pos, 0);
        }
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        e = func_02065f88(0x66, &self->pos);
        e->v24(0, 0x4000, 0);
        e->v0c(0x4000);
        e->v34(0x3fff, 0, 0);
        func_02049f44(data_02097e4c, 0xc06, &self->pos, 0);
        g = data_ov000_021ccd54;
        FLD(Ov014G190A, g, 0x190).b2 = 1;
        FLD(Ov014G190A, g, 0x190).b3 = 1;
        FLD(Ov014G190A, g, 0x190).b4 = 1;
        FLD(u8, g, 0x18d) = 10;
        FLD(u8, g, 0x18e) = 10;
        FLD(u8, g, 0x18f) = 10;
        self->unk_40->state++;
        break;
    }
    case 2:
        func_ov014_0220a2d0(self, (FLD(u32, self, 0xf4) & (1 << (FLD(u16, self, 0xf8) - 1))) ? 1 : 0);
        FLD(u16, self, 0xf8)--;
        if (FLD(u16, self, 0xf8) == 0) {
            self->unk_40->state = 4;
            return;
        }
        self->unk_40->state++;
        self->unk_40->timer = FLD(u16 *, self, 0xf0)[1];
        break;
    case 3: {
        Ov014Sub40 *st = self->unk_40;
        if (st->timer == 0) {
            if (func_ov000_02191120(self->unk_38)) {
                func_ov000_02190cb0(self->unk_38, data_ov014_02217a4e, 0xcd, 0);
                func_ov000_021915a0(self->unk_38);
            }
            self->unk_40->state--;
            break;
        }
        Ov014_TickA(st);
        break;
    }
    case 4:
        self->unk_40->state = 0xffff;
        FLD(u8, self, 0xfc) = 1;
        break;
    }
}

extern void func_ov014_0220c09c(Ov014Actor *self);
extern void func_ov014_0220cd74(Ov014Actor *self);

void func_ov014_0220afb8(Ov014Actor *self) {
    switch (*FLD(s16 *, self, 0xf0)) {
    case 9:
        func_ov014_0220c09c(self);
        break;
    case 10:
        func_ov014_0220cd74(self);
        break;
    }
}


extern void *data_02097e4c;
extern u8 data_ov014_02217a4e[];
extern u8 data_ov014_02217a78[];
extern u8 data_ov014_02217a7e[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern s32 FX_Div(s32 a, s32 b);
extern void func_ov014_02209fa0(Ov014Actor *self, s32 a, s32 b);

struct Ov014G190 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

void func_ov014_0220afe8(Ov014Actor *self) {
    Ov014Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a4e, 0x2ab, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u8, self, 0xfc) = 1;
        self->unk_40->state++;
        break;
    case 1: {
        Ov014Game54 *g = data_ov000_021ccd54;
        FLD(Ov014G190, g, 0x190).b2 = 1;
        FLD(Ov014G190, g, 0x190).b3 = 1;
        FLD(Ov014G190, g, 0x190).b4 = 1;
        FLD(u8, g, 0x18d) = 10;
        FLD(u8, g, 0x18e) = 10;
        FLD(u8, g, 0x18f) = 10;
        func_02049f44(data_02097e4c, 0xc03, &self->pos, 0);
        self->unk_40->state++;
        self->unk_40->timer = 0x28;
        break;
    }
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_40->state = 10;
        }
        break;
    case 10:
        FLD(s32, self, 0xf4) = 0;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a78, 0x2ab, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        switch (*FLD(s16 *, self, 0xf0)) {
        case 5:
            FLD(u16, self, 0xf8) = 3;
            break;
        case 6:
            FLD(u16, self, 0xf8) = 3;
            break;
        case 7:
            FLD(u16, self, 0xf8) = 2;
            break;
        }
        self->unk_40->state++;
        break;
    case 11: {
        Ov014Game54 *g;
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            break;
        }
        func_02049f44(data_02097e4c, 0xc04, &self->pos, 0);
        FLD(s16, self->unk_38, 0xc4) = 0;
        g = data_ov000_021ccd54;
        FLD(Ov014G190, g, 0x190).b2 = 1;
        FLD(Ov014G190, g, 0x190).b3 = 1;
        FLD(Ov014G190, g, 0x190).b4 = 1;
        FLD(u8, g, 0x18d) = 5;
        FLD(u8, g, 0x18e) = 7;
        FLD(u8, g, 0x18f) = 7;
        func_ov014_02209fa0(self, FLD(s16 *, self, 0xf0)[2], FLD(s16 *, self, 0xf0)[0]);
        FLD(u16, self, 0xf8)--;
        FLD(s32, self, 0xf4) ^= 1;
        self->unk_40->state++;
        self->unk_40->timer = 0;
    }
    case 12:
        if (FLD(u16, self, 0xf8) != 0) {
            s32 v;
            func_ov000_02190cb0(self->unk_38, FLD(s32, self, 0xf4) != 0 ? data_ov014_02217a7e : data_ov014_02217a78, 0xcd, 0);
            v = FX_Div(0x50000, FLD(u16 *, self, 0xf0)[1] << 12);
            if (v > 0x2000) {
                v = 0x2000;
            } else if (v < 0x800) {
                v = 0x800;
            }
            func_ov000_021911c8(self->unk_38, (s16)v);
            func_ov000_02191318(self->unk_38, 0);
            func_ov000_02191618(self->unk_38);
            self->unk_40->state = 11;
        } else if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->state = 0x14;
        }
        break;
    case 20:
        FLD(u8, self, 0xfc) = 0;
        self->unk_40->state = 0xffff;
        break;
    }
}

}
