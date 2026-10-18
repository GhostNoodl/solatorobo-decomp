#include "ov015/ov015.h"

extern "C" {

void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Normalize(void *src, void *dst);
void func_02049244(Ov015Vec *a, s32 b, Ov015Vec *c, Ov015Vec *d, s32 e);

void func_ov015_021fee54(u8 *self) {
    Ov015Vec res1;
    Ov015Vec tgt;
    Ov015Vec prev;
    Ov015Vec res2;
    Ov015Vec d1;
    Ov015Vec d2;
    tgt = FLD(Ov015Vec, self, 0x180);
    if (tgt.x > 0x207ec) {
        tgt.x = 0x207ec;
    } else if (tgt.x < -0x207ec) {
        tgt.x = -0x207ec;
    }
    tgt.y += 0x7000;
    tgt.z = -0x6b800;
    prev = FLD(Ov015Vec, self, 0x14);
    func_02049244(&tgt, 0x7b, &prev, &tgt, 0x1000);
    d1.x = FLD(s32, self, 0x18c) - FLD(s32, self, 0x180);
    d1.y = FLD(s32, self, 0x190) - FLD(s32, self, 0x184);
    d1.z = FLD(s32, self, 0x194) - FLD(s32, self, 0x188);
    VEC_Normalize(&d1, &d1);
    VEC_MultAdd(FLD(s32, self, 0x198), &d1, &FLD(Ov015Vec, self, 0x18c), &res1);
    res1.y += 0x1e000;
    prev = FLD(Ov015Vec, self, 0x8);
    func_02049244(&res1, 0x7b, &prev, &res1, 0x1000);
    FLD(Ov015Vec, self, 0x8) = res1;
    FLD(Ov015Vec, self, 0x14) = tgt;
    d2.x = FLD(s32, self, 0x18c) - tgt.x;
    d2.y = FLD(s32, self, 0x190) - tgt.y;
    d2.z = FLD(s32, self, 0x194) - tgt.z;
    VEC_Normalize(&d2, &d2);
    VEC_MultAdd(FLD(s32, self, 0x198), &d2, &FLD(Ov015Vec, self, 0x18c), &res2);
    res2.z -= 0x1000;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0x1000;
    FLD(s32, self, 0xd8) = -0x1000;
    FLD(Ov015Vec, self, 0xc4) = res2;
}

}
