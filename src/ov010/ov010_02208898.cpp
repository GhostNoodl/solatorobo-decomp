#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220f394[];
extern u8 data_ov010_0220f310[];
extern u8 data_ov010_0220f1d0[];
extern BOOL func_ov003_021d984c(void *p, void *a);
extern void func_ov003_021d95e8(void *p, void *a, s32 b);

static inline void Ov010_PlayAnim(void *self, void *anim, s32 n) {
    if (!func_ov003_021d984c((u8 *)self + 0x160, anim)) {
        func_ov003_021d95e8((u8 *)self + 0x160, anim, n);
    }
}

void func_ov010_02208898(void *self) {
    u16 *hp = FLD(u16 *, self, 0x50);
    s32 r = (hp[0] << 12) / hp[1];
    if (r <= 0x733) {
        Ov010_PlayAnim(self, data_ov010_0220f394, 0x1e);
    } else if (r <= 0xccd) {
        Ov010_PlayAnim(self, data_ov010_0220f310, 0x16);
    } else if (r <= 0x1000) {
        Ov010_PlayAnim(self, data_ov010_0220f1d0, 0xd);
    }
}


extern void func_ov010_022046ac(void *self);

BOOL func_ov010_02208968(void *self, s32 *out) {
    *out = 9;
    return TRUE;
}

void func_ov010_02208978(void *self, s32 *out) {
    out[0] = 0x905;
    out[1] = 0x906;
    out[2] = 0x904;
    out[3] = 0x900;
    out[4] = 0x903;
    out[5] = 0x900;
    out[7] = 0x902;
}

void func_ov010_022089b4(void *self) {
    func_ov010_022046ac(self);
    FLD(u8, self, 0xf3) = FLD(s16, self, 0x18) == 2;
}

}
