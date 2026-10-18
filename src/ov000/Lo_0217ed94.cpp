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

void func_ov000_0217ed94(void) {
    LoTaskObj()->vfunc_2c();
}

void func_ov000_0217edb4(VObj *self) {
    LBIT(self, 4).b1 = 0;
    if (self->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
}

void func_ov000_0217ede8(void *self) {
    LFLD(s32, self, 0x20) = 0x8000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = -1;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
}

void func_ov000_0217ee18(void *self) {
    LO_FREE_V(self, 0x48);
    LO_FREE_M(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LO_FREE_M(self, 0x54);
}

}
