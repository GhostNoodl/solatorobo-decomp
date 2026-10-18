#include "types.h"

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
    u8 pad_14[8];
    s32 unk_1c;
} Sub0219e8bc;

typedef struct {
    u8 pad_00[0x44];
    Sub0219e8bc *unk_44;
    u8 pad_48[0x1c];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    u8 pad_70[0xab2];
    u16 unk_b22_0 : 3;
    u16 unk_b22_3 : 1;
    u16 unk_b22_4 : 2;
    u16 unk_b22_6 : 3;
    u16 unk_b22_9 : 7;
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
    u32 unk_b24_2 : 3;
    u32 unk_b24_5 : 2;
    u32 unk_b24_7 : 5;
    u32 unk_b24_12 : 2;
    u32 unk_b24_14 : 18;
} Robo0219e8bc;

extern "C" {

void func_ov000_021984f4(Sub0219e8bc *p, s32 a, s32 b);

void func_ov000_0219e8bc(Robo0219e8bc *self) {
    if (self->unk_b24_1) {
        s32 x = 0;
        s32 y = 0;
        if (self->unk_b22_3) {
            if (self->unk_b24_5) {
                x = 0x4cd;
                y = 0x4cd + 0x29;
            } else {
                x = 0x400;
                y = 0x400 + 0x29;
            }
        } else if (self->unk_b22_6 == 5) {
            x = 0xc00;
            y = 0x1800;
        } else if (self->unk_b24_5 && !self->unk_b24_12) {
            x = 0x333;
            y = 0x35c;
        }
        self->unk_44->unk_1c = x + self->unk_64;
        self->unk_44->unk_10 = y + self->unk_6c;
    } else {
        self->unk_44->unk_1c = self->unk_64 >> 1;
        self->unk_44->unk_10 = self->unk_68 >> 2;
    }
    func_ov000_021984f4(self->unk_44, 0, 0);
}

}
