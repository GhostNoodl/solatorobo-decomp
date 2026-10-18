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

void func_ov000_0216be58(void *self) {
    if (func_0203dc9c((u8 *)data_ov000_021ccd54 + 8, 1)) {
        return;
    }
    func_ov000_0216c018(self);
    func_ov000_0216c310(self);
}

void func_ov000_0216be94(void *self) {
    if (func_0203dc9c((u8 *)data_ov000_021ccd54 + 8, 1)) {
        return;
    }
    func_ov000_0216c6fc(self);
}

void func_ov000_0216bec8(void *self) {
    void *p = LFLD(void *, self, 0xb0);
    u8 *g = data_02097d48;
    u32 w = LFLD(u32, p, 0xc);
    u32 lv = (w & 0x1f0000) >> 16;
    if (lv > 0x1e) {
        lv = 0x1e;
    }
    LFLD(u32, p, 0xc) = (w & 0xc0e0f7ff) | (lv << 16) | (func_02043d84(g + 0x8b0) << 24) | 0x800;
}

}
