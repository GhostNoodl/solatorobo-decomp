#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    s32 x, y, z;
} Vec_021a19a0;

extern "C" {

extern char data_ov000_021cc61e[];
extern char data_ov000_021cc624[];
extern char data_ov000_021cc62a[];
extern char *data_ov000_021ca050[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_021911c8(void *a, s32 b);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
u16 FX_Atan2(s32 y, s32 x);

void func_ov000_021a19a0(Robo021ca458 *self) {
    BOOL turned;
    s32 rate;
    char *name;
    s32 target;
    s16 spd;
    s32 speed;
    s32 frame;
    LBIT(self, 0xb24).b17 = 0;
    rate = 0x400;
    frame = rate;
    target = self->unk_b08;
    name = data_ov000_021cc61e;
    speed = 0x1000;
    if (LBIT(self, 0xb24).b1) {
        if (!self->unk_b22_3) {
            name = data_ov000_021ca050[self->unk_b24_5];
        } else {
            if (self->unk_b24_5 != 0) {
                name = data_ov000_021cc624;
            }
            rate = 0x111;
        }
    } else if (LFLD(u32, self->unk_48, 0x50) & 0x400) {
        name = data_ov000_021cc624;
        if (self->unk_b36 == 1) {
            target = 0x1c3;
            frame = speed;
        } else {
            target = 0x10a;
            speed -= 0xb8;
            frame = 0xcd;
        }
    }
    func_ov000_02190cb0(self->unk_38, name, rate, 0);
    if (!self->unk_b22_3) {
        func_ov000_021915a0(self->unk_38);
    }
    LFLD(u16, self->unk_48, 0x9a) |= 0x20;
    func_ov000_021b1dd8((u8 *)self, target, frame, speed, 0x466, 1);
    spd = 0x1000;
    if (!self->unk_b22_3) {
        // The repeated (s16)(v * 2) terms keep MWCC from folding the else branch into one multiply.
        s16 v = self->unk_9c;
        if (LBIT(self, 0xb24).b1) {
            spd = (s16)(v * 2) * 5;
        } else {
            spd = (s16)(v * 2) * 4 + (s16)(v * 2) * 2 + (s16)(v * 2);
        }
    }
    func_ov000_021911c8(self->unk_38, spd);
    if (self->unk_b28_0 == 3) {
        self->unk_b28_0 = 2;
        LFLD(Vec_021a19a0, self, 0xb10) = LFLD(Vec_021a19a0, self, 0x70);
    }
    turned = FALSE;
    if (LBIT(self, 0xb24).b1 && (LFLD(u32, self->unk_48, 0x54) & 0x400)) {
        self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x,
                                         self->unk_af8 - self->pos.z);
        self->unk_9c = 0x66;
        self->unk_a4 = 0;
        if (!LBIT(self, 0xb24).b17 || (LFLD(u32, self->unk_48, 0x50) & 0x40000000)) {
            self->unk_a0 = 0x200;
        }
        self->unk_a8 = 0x52;
        LBIT(self, 0xb24).b17 = 1;
        turned = TRUE;
    }
    if (!turned) {
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov000_021cc62a, 0x800, 0);
    func_ov000_02198360(self->unk_40, 4, 0);
}

}
