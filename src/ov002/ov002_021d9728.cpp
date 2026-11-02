#include "ov002/ov002.h"

extern "C" {

void func_ov000_02190a80(void *a, s32 b);

s32 **func_ov000_02190a30(void *a, int b);

void func_ov002_021d7320(void *self, s32 t, s32 range);

void Interp_SinLerpVec(VecFx32 *out, s32 t, void *a, void *b);

void func_ov002_021d9728(void *self) {
    VecFx32 a;
    VecFx32 b;
    u8 *o;
    s32 x;
    void *n;
    void *t;
    o = FIELD(self, 0x4, u8 *);
    func_ov000_02190a80(FIELD(o, 0x8, void *), 0x1000);
    func_ov000_02190a80(FIELD(o, 0x10, void *), 0x1000);
    {
        s32 **pp = func_ov000_02190a30(FIELD(o, 0x10, void *), 0);
        x = 0;
        if (*pp != NULL) {
            x = **pp;
        }
    }
    func_ov002_021d7320(o, x, 0x1000);
    for (n = FIELD(self, 0x6c, void *); n != NULL; n = FIELD(n, 0x70, void *)) {
        ((VObj *)n)->vfunc_0c();
    }
    t = Task_FindById(0x1b);
    if (t != NULL && FIELD(self, 0x75, u8)) {
        void *m = FIELD(t, 0x3c, void *);
        u8 k = FIELD(self, 0x74, u8);
        if (m != NULL) {
            func_ov002_021e2690(m, k, 0);
        }
        FIELD(self, 0x75, u8) = 0;
    }
    t = Task_FindById(0x1b);
    if (t != NULL && FIELD(t, 0x3c, void *) != NULL) {
        MI_CpuCopy8((u8 *)self + 0x76, FIELD(t, 0x3c, u8 *) + 0x2c, 0x14);
    }
    if (FIELD(self, 0x90, s32) < 0) {
        return;
    }
    {
        s32 f = FX_Div((FIELD(self, 0x94, s32) - FIELD(self, 0x90, s32)) << 12, FIELD(self, 0x94, s32) << 12);
        Interp_SinLerpVec(&a, f, (u8 *)self + 0x98, (u8 *)self + 0xb0);
        Interp_SinLerpVec(&b, f, (u8 *)self + 0xa4, (u8 *)self + 0xbc);
    }
    FIELD(self, 0x8c, VecFx32 *)[0] = a;
    FIELD(self, 0x8c, VecFx32 *)[1] = b;
    FIELD(self, 0x90, s32)--;
}

}
