#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e68[];
void func_02049a48(void *a, int b, int c, int d, int e);
s32 FX_Div(s32 a, s32 b);
u8 *func_02066774(void *a, void *b, int c, void *d);

BOOL func_ov015_0220c6b4(u8 *self, u8 *p) {
    FLD(u8 *, self, 0x18) = p;
    FLD(s32, p, 0x108) = 0;
    return TRUE;
}

void func_ov015_0220c6c8(u8 *self, u8 *p) {
    Ov015VecC pos(*(Ov015VecC *)(p + 0x40));
    if (pos.y >= 0) {
        pos.y = 0;
    } else {
        pos.y += FX_Div(0x28000, 0x5a000);
    }
    *(Ov015VecC *)(p + 0x40) = pos;
    if (FLD(s32, self, 0x8) == 0x5a) {
        u8 *o;
        Ov015Vec v;
        func_02049a48(data_02097e4c, 0x19, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        o = func_02066774(data_ov015_02212e20, data_ov015_02212e68, 0, FLD(u8 *, self, 0x18) + 0x40);
        FLD(s32, o, 0xd4) = 1;
        FLD(u8, o, 0x28) = 1;
        FLD(s32, o, 0x50) = -0xc8000;
        v = *(Ov015Vec *)(FLD(u8 *, self, 0x18) + 0x40);
        v.y = 0;
        VCALL(o)->v18(&v);
        VCALL(o)->v10(FLD(u8 *, self, 0x18) + 0x70);
    } else if (FLD(s32, self, 0x8) == 1) {
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
    }
}

}
