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
void func_02016e28(void *dst, s32 v, s32 size);
void func_ov000_0216bcbc(void *self);

void func_ov000_0216bf30(void *self) {
    s32 i;
    LFLD(s32, self, 0) = 0x1000;
    for (i = 0; i < 0x10; i++) {
        u8 *e = (u8 *)self + i * 0x24;
        LFLD(s32, e, 4) = -1;
        LFLD(u8, e, 8) = 0;
    }
    LFLD(s32, self, 0x244) = 0;
    LFLD(s32, self, 0x248) = 0;
    LFLD(s32, self, 0x24c) = 0;
    LFLD(s32, self, 0x250) = 0;
    func_02016e28((u8 *)self + 0x254, 0, 0x108);
    LFLD(s32, self, 0x35c) = 0;
}

void func_ov000_0216bf90(void *self) {
    s32 i;
    func_ov000_0216bcbc(self);
    for (i = 0; i < 10; i++) {
        if (LFLD(VObj *, (u8 *)self + i * 12, 0x368) != NULL && --LFLD(s32, (u8 *)self + i * 12, 0x360) == 0) {
            LO_FREE_V((u8 *)self + i * 12, 0x368);
        }
    }
}

}
