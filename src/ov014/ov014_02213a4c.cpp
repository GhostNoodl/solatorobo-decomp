#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov014_02217d7c[];
extern void func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *data_ov000_021ccd64;
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern s32 FX_Div(s32 a, s32 b);
extern s32 func_02049130(s32 a, s32 b, s32 c);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

void func_ov014_02213a4c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d7c, 0x1000, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->state = 0xffff;
        }
        break;
    default:
        self->unk_40->state = 0xffff;
        break;
    }
}

void func_ov014_02213afc(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        u8 c;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d7c, 0x19a, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x800);
        self->unk_40->state++;
        self->unk_40->timer = 120;
        c = 0x15;
        func_ov000_0219bd20(0x483a, self->id, 2, 1, 1, &c);
        func_ov000_0219bd20(0x483b, self->id, 2, 1, 1, &c);
        func_02049f44(data_02097e4c, 0x68, &self->pos, 0);
        break;
    }
    case 1: {
        u8 b;
        if (self->unk_40->timer % 30 == 0) {
            func_02065f88(0x38a, &self->pos);
        }
        b = func_02049130(FX_Div(self->unk_40->timer << 12, 0x78000), 0, 0x1f000) >> 12;
        FLD(u8, self->unk_38, 0xbe) = b;
        FLD(u8, self, 0x2e6) = b;
        if (self->unk_40->timer == 0) {
            self->unk_40->state++;
        }
        if (self->unk_40->timer != 0) {
            self->unk_40->timer--;
        }
        break;
    }
    case 2:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        self->unk_40->state = 0xffff;
        break;
    }
}

}
