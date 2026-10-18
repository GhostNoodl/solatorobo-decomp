#include "ov015/ov015.h"

extern "C" {

u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e34[];
struct Ov015Blk0afcc { s32 w[3]; };
extern const Ov015Blk0afcc data_ov015_02212650;
void VEC_Normalize(void *src, void *dst);
u16 FX_AcosIdx(s32 x);

#define Ov015_Dot0afcc(a, b) ((s32)(((s64)(a)->x * (b)->x + (s64)(a)->y * (b)->y + (s64)(a)->z * (b)->z + 0x800) >> 12))
void func_ov015_0220afcc(u8 *self) {
    Ov015Vec v;
    Ov015Vec dir;
    Ov015Vec base;
    Ov015Vec sc;
    u16 ang;
    Ov015V *e = func_020657b0(data_0214a420, FLD(void *, self, 0x24));
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, FLD(u8 *, self, 0x20) + 0x40);
        FLD(s32, e, 0xd4) = 1;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        FLD(void *, self, 0x24) = FLD(void *, e, 0x24);
    }
    {
        u8 *o = FLD(u8 *, self, 0x20);
        v.x = FLD(s32, o, 0x40);
        v.y = FLD(s32, o, 0x44) > 0 ? 0 : FLD(s32, o, 0x44);
        v.z = FLD(s32, o, 0x48);
        v.y = v.y < -0x2000 ? -0x2000 : v.y;
    }
    e->v18(&v);
    *(Ov015Blk0afcc *)&base = data_ov015_02212650;
    dir = FLD(Ov015Vec, FLD(u8 *, self, 0x20), 0x9c);
    dir.y = 0;
    VEC_Normalize(&dir, &dir);
    ang = FX_AcosIdx(Ov015_Dot0afcc(&dir, &base));
    if (dir.x < 0) ang = 0xffff - ang;
    e->v34(0, ang, 0);
    {
        u8 *o = FLD(u8 *, self, 0x20);
        s32 s = FLD(s32, o, 0x7c);
        sc.x = Ov015_FxMul(FLD(s32, o, 0x70), s);
        sc.y = Ov015_FxMul(FLD(s32, o, 0x74), s);
        sc.z = Ov015_FxMul(FLD(s32, o, 0x78), s);
        e->v10(&sc);
    }
}

}
