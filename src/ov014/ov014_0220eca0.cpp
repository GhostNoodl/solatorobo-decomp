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
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02194c08(void *self);
extern void func_02049de8(void *a, s32 b);
extern u8 func_02043d48(void *p);
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

}
