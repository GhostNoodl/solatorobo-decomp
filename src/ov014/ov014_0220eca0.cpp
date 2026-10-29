#include "ov014/ov014.h"

extern "C" {

extern void *data_0214a420;
extern void *data_02097e4c;
extern u8 *data_02097d48;
extern u8 data_ov014_02217aac[];
extern u8 data_ov014_02217c6c[];
extern void func_02065860(void *a, void *b);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_0219763c(void *self);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern Ov014Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern s32 func_ov000_02191318(void *a, s32 b);
extern s32 func_ov000_02191f18(void *a, void *b);
extern s32 func_ov014_0220ec18(s16 *a, u8 *b);
extern void *func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02194c08(void *self);
extern void func_02049de8(void *a, s32 b);
extern int func_02043d48(void *p);
extern void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
extern void func_ov000_02191618(void *p);
extern void func_ov000_02191708(void *p);

#pragma force_active on
Ov014Actor *func_ov014_0220eca0(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217aac;
    FLD(s16, self, 0xce) = 0;
    FLD(s32, self, 0xd0) = 0x1000;
    FLD(s32, self, 0xd4) = 0x1000;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = 0;
    FLD(s32, self, 0xe0) = 0;
    FLD(s16, self, 0xf0) = 0;
    FLD(s16, self, 0xf2) = 0;
    FLD(s16, self, 0xf4) = 0;
    FLD(s32, self, 0xe4) = 0x1000;
    FLD(s32, self, 0xe8) = 0x1000;
    FLD(s32, self, 0xec) = 0x1000;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_0220ecf8(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217aac;
    func_02049de8(data_02097e4c, 0x38);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_0220ed30(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217aac;
    func_02049de8(data_02097e4c, 0x38);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_0220ed70(Ov014Actor *self) {
    FLD(u8, self->unk_38, 0xc1) = func_02043d48(data_02097d48 + 0x8b0);
    func_ov000_02194c08(self);
}

void func_ov014_0220eda0(Ov014Actor *self) {
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    FLD(s16, self, 0xce) = self->unk_18;
    FLD(s32, self, 0xd0) = self->unk_1a << 4;
    FLD(s32, self, 0xd4) = self->unk_1c << 4;
    FLD(Ov014Flags, self->unk_38, 0xc2).b6 = 0;
    func_ov000_02191920(self->unk_38, 0, 0x1000, 0);
    FLD(Ov014Flags8, func_ov000_02190a30(self->unk_38, 3), 0x111).b3 = 0;
    FLD(Ov014Flags8, func_ov000_02190a30(self->unk_38, 3), 0x111).b2 = 1;
    func_ov000_02190cb0(self->unk_38, data_ov014_02217c6c, 0x1000, 1);
    func_ov000_02191618(self->unk_38);
    func_ov000_02191708(self->unk_38);
    Ov014_VecSet(&FLD(Ov014Vec, self->unk_38, 0xa8), FLD(s32, self, 0xd0), FLD(s32, self, 0xd4), 0x99a);
    FLD(void *, self->unk_38, 0xe0) = (void *)func_ov014_0220ec18;
    func_ov000_02198360(self->unk_40, 1, 0);
}

extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern BOOL func_ov000_021b4738(Ov014Actor *p);
extern BOOL func_ov000_02191120(void *p);

extern void func_ov014_0220f20c(Ov014Actor *self, void *a, void *b, void *c);

static inline void Ov014_Flash(u8 c) {
    u8 *g = (u8 *)data_ov000_021ccd54;
    FLD(Ov014Flags8, g, 0x190).b2 = 0;
    FLD(Ov014Flags8, g, 0x190).b3 = 1;
    FLD(Ov014Flags8, g, 0x190).b4 = 0;
    g[0x18d] = c;
    g[0x18e] = 0xf;
    g[0x18f] = 0xf;
}

static inline void Ov014_Release(Ov014Actor *self) {
    s32 t = 0;
    s32 **p;
    FLD(s16, self->unk_38, 0xc4) = 0;
    p = func_ov000_02190a30(self->unk_38, 0);
    if (*p != NULL) {
        t = **p;
    }
    func_ov000_02191318(self->unk_38, t + 0x2000);
}

void func_ov014_0220ee9c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        self->unk_40->timer = 0x1e;
        self->unk_40->state++;
        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
    case 1: {
        Ov014Sub40 *w = self->unk_40;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0 && FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov014_Release(self);
            Ov014_Flash(0x28);
            func_02049f44(data_02097e4c, 0x1b, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x38, &self->pos, 0);
            self->unk_40->timer = FLD(u16, self, 0xce);
            self->unk_40->state++;
        }
        break;
    }
    case 2: {
        Ov014Actor *pl = func_ov000_0219bf90();
        s32 t;
        Ov014Sub40 *w;
        if (pl == NULL || func_ov000_021b4738(pl)) {
            self->unk_40->timer = 0;
            func_02049de8(data_02097e4c, 0x38);
        }
        t = self->unk_40->timer;
        if (t % 4 == 1) {
            s32 h = Ov014_FxMul(FLD(s32, self, 0x68), FLD(s32, self, 0xd4));
            FLD(s32, self, 0xe4) = Ov014_FxMul(self->unk_64, FLD(s32, self, 0xd0));
            FLD(s32, self, 0xe8) = h;
            FLD(s32, self, 0xec) = 0x1000;
            FLD(Ov014Vec, self, 0xd8) = self->pos;
            FLD(s32, self, 0xdc) += h / 2;

            FLD(u16, self, 0xf0) = self->rot[0];
            FLD(u16, self, 0xf2) = self->rot[1];
            FLD(u16, self, 0xf4) = self->rot[2];
            func_ov014_0220f20c(self, (u8 *)self + 0xd8, (u8 *)self + 0xf0, (u8 *)self + 0xe4);
        }

        if (t < FLD(u16, self, 0xce) - 0xf && t % 15 == 1) {
            Ov014_Flash(0xc);
        }
        w = self->unk_40;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0 && FLD(s16, self->unk_38, 0xc4) == 2) {
            Ov014_Release(self);
            func_02049de8(data_02097e4c, 0x38);
            self->unk_40->state++;
        }
        break;
    }
    case 3: {
        BOOL done = FALSE;
        Ov014Actor *pl = func_ov000_0219bf90();
        if (pl == NULL || func_ov000_021b4738(pl)) {
            done = TRUE;
        }
        if (func_ov000_02191120(self->unk_38) || done) {
            func_02049de8(data_02097e4c, 0x38);
            self->unk_38->unk_c2_0 = 0;
            func_ov000_02198360(self->unk_40, 0x15, 0);
            self->unk_40->state++;
        }
        break;
    }
    }
}
}
