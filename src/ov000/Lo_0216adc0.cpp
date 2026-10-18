#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 timer;
    s32 unk_04;
    VObj *obj;
} LoTimedObj;

typedef struct {
    u8 pad[0x360];
    LoTimedObj objs[10];
} LoTimedHost;

extern void *data_ov000_021ccd54;
extern u8 *data_02097d48;
void *func_ov000_0219bf90(void *self);
void VEC_Add(void *a, void *b, void *c);
BOOL func_0203dc9c(void *a, s32 b);
void func_ov000_0216c018(void *self);
void func_ov000_0216c310(void *self);
void func_ov000_0216c6fc(void *self);
s32 func_02043d84(void *a);
void MI_CpuFill8(void *dst, s32 v, s32 size);
void func_ov000_0216bcbc(void *self);

void func_ov000_0216adc0(void *self, s32 a, s32 b) {
    if (LFLD(s32, self, 8) == a) {
        LFLD(u32, self, 0) |= 6;
    } else {
        LFLD(u32, self, 0) &= ~2;
    }
    if (b < 0) {
        b = 0;
    } else if (b > 0x63) {
        b = 0x63;
    }
    LFLD(s32, self, 8) = a;
    LFLD(s32, self, 0x10) = b;
}

}
