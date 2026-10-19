#include "ov014/ov014.h"

extern "C" {

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
extern void func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
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
