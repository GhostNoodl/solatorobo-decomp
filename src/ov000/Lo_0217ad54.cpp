#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ad54(void *self) {
    s32 i;
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
    LFLD(s32, self, 0x58) = 0;
    LFLD(s32, self, 0x5c) = 0;
    LFLD(s32, self, 0x60) = 0;
    LFLD(s32, self, 0x64) = 0;
    LFLD(s32, self, 0x68) = 0;
    LFLD(s32, self, 0x6c) = 0;
    LFLD(u8, self, 0x70) = 0;
    LFLD(u8, self, 0x71) = 0;
    LFLD(s32, self, 0x74) = 0;
    LFLD(s32, self, 0x78) = 0;
    LFLD(s32, self, 0x80) = 0;
    LFLD(s32, self, 0x7c) = 0;
    LFLD(s32, self, 0x88) = 0;
    LFLD(s32, self, 0x84) = 0;
    LFLD(s32, self, 0x90) = 0;
    LFLD(s32, self, 0x8c) = 0;
    LFLD(s32, self, 0x98) = 0;
    LFLD(s32, self, 0x94) = 0;
    LFLD(s32, self, 0x9c) = 0;
    LFLD(s32, self, 0xa0) = 0;
    LFLD(s32, self, 0xa4) = 0;
    for (i = 0; i < 4; i++) {
        ((s32 *)((u8 *)self + 0xa8))[i] = 0;
    }
    LFLD(u16, self, 0xb8) = 0;
    LFLD(u16, self, 0xba) = 0;
    LFLD(s32, self, 0xbc) = 0;
    LFLD(s32, self, 0xc0) = 0;
}

}
