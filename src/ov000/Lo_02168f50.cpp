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

void func_ov000_02168f50(void *self) {
    void *p = func_ov000_0219bf90(self);
    if (p == NULL) {
        return;
    }
    LFLD(s32, self, 0x80) = LFLD(s32, p, 0x70);
    LFLD(s32, self, 0x84) = LFLD(s32, p, 0x74);
    LFLD(s32, self, 0x88) = LFLD(s32, p, 0x78);
    VEC_Add((u8 *)self + 0x80, (u8 *)self + 0x9c, (u8 *)self + 0x80);
}

}
