#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212ee8[];
extern u8 data_ov015_02212eb0[];
extern void *data_ov015_02212db8[];
extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);
extern u8 data_ov015_02212e0d[];
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 func_02040528(s32 max);
void func_02012d78(void *src, void *dst);
void func_0203f324(void *a);

u8 *func_ov015_0220c93c(u8 *self) {
    SET_VT(self, data_ov015_02212ee8);
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x8) = 0;
    FLD(s32, self, 0xc) = 0x1000;
    FLD(s32, self, 0x10) = 0;
    FLD(s32, self, 0x14) = 0;
    FLD(s32, self, 0x18) = 0;
    FLD(s32, self, 0x1c) = 0;
    FLD(s32, self, 0x20) = 0;
    FLD(s32, self, 0x24) = 0;
    FLD(s32, self, 0x28) = 0;
    FLD(s32, self, 0x2c) = 0;
    FLD(s32, self, 0x30) = 0;
    FLD(s32, self, 0x34) = 0;
    FLD(s32, self, 0x38) = 0;
    return self;
}

void *func_ov015_0220c98c(u8 *self) {
    s32 i;
    Ov015V *o;
    u32 saved;
    SET_VT(self, data_ov015_02212ee8);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = func_020657b0(data_0214a420, FLD(void *, self, 0x8));
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, data_ov015_02212eb0);

    return self;
}

void *func_ov015_0220ca38(u8 *self) {
    s32 i;
    Ov015V *o;
    u32 saved;
    SET_VT(self, data_ov015_02212ee8);
    for (i = 0; i < 1; i++) {
        if (data_ov015_02212db8[i] == self) {
            data_ov015_02212db8[i] = NULL;
            break;
        }
    }
    o = func_020657b0(data_0214a420, FLD(void *, self, 0x8));
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

static inline void Ov015_SetXZ(s32 *v, s32 x, s32 z) { v[0] = x; v[2] = z; }
BOOL func_ov015_0220caec(u8 *self, u8 *p) {
    s32 a;
    s32 x, z;
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e0d, 0x19a, 0);
    FLD(u16, p, 0x104) = 0x59a;
    func_ov000_021915a0(p + 0x244);
    FLD(s32, p, 0x108) = 1;
    FLD(s32, self, 0xc) = Ov015_FxMul(FLD(s16, p, 0xca) << 4, 0x19a) + 0x23d;
    a = func_02040528(0x1000);
    FLD(s32, self, 0x1c) = func_02040528(0x1000);
    FLD(s32, self, 0x24) = a;
    FLD(s32, self, 0x20) = 0;
    func_02012d78(self + 0x1c, self + 0x1c);
    func_02012d78(self + 0x1c, p + 0x9c);
    FLD(s32, p, 0x44) = -0x32000;
    Ov015_SetXZ((s32 *)(p + 0x40), FLD(s32, p, 0x40), FLD(s32, p, 0x48));
    func_0203f324(p + 0x568);
    FLD(s32, self, 0x14) = FLD(u16, p, 0xcc);
    FLD(s32, self, 0x18) = FLD(u16, p, 0xce);
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x10) = FLD(s32, self, 0x18);
    return TRUE;
}

}
