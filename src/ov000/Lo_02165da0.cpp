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

void func_ov000_02165da0(void *self) {
    void *o = LFLD(void *, self, 0x30);
    void *q;
    if (o == NULL || (q = LFLD(void *, o, 0xcdc)) == NULL) {
        return;
    }
    if (LFLD(u16, q, 0x10a) != 0) {
        return;
    }
    LFLD(u16, q, 0x10a) = 1;
    LFLD(u16, LFLD(void *, o, 0xcdc), 0x10c) = LFLD(u8, LFLD(void *, o, 0xcdc), 0x108) - 1;
    LFLD(u16, LFLD(void *, o, 0xcdc), 0x10e) = 0;
}

BOOL func_ov000_02165df4(void *self) {
    void *o = LFLD(void *, self, 0x30);
    void *q;
    if (o == NULL || (q = LFLD(void *, o, 0xcdc)) == NULL) {
        return TRUE;
    }
    return LFLD(u16, q, 0x10a) == 0xffff ? TRUE : FALSE;
}

}
