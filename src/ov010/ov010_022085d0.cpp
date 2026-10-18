#include "ov010/ov010.h"

struct Ov010Rot {
    s16 v[3];
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd54;
extern u8 data_ov010_0220f024[];
extern Ov010Vec data_ov010_0220f114;
extern Ov010Vec data_ov010_0220f120;
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void *func_ov003_021da32c(s32 id);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);

void func_ov010_022085d0(void *self) {
    u16 *w = FLD(u16 *, self, 0x40);
    switch (w[0]) {
    case 0:
        w[1] = 0;
        FLD(u16 *, self, 0x40)[0] = 0x1e;
        break;
    case 0x1e:
        func_02065f88(0x389, &data_ov010_0220f114)->v0c(0x2000);
        func_02065f88(0x322, &data_ov010_0220f114)->v0c(0x1800);
        func_02065f88(0x389, &data_ov010_0220f120)->v0c(0x2000);
        func_02065f88(0x322, &data_ov010_0220f114)->v0c(0x1800);
        func_02049f44(data_02097e4c, 0x79, &FLD(Ov010Vec, self, 0x70), 0);
        FLD(u16 *, self, 0x40)[0] = 0x1f;
        FLD(u16 *, self, 0x40)[1] = 0x28;
        break;
    case 0x1f:
        if (w[1] != 0) {
            w[1]--;
        }
        if (w[1] == 0) {
            FLD(u16 *, self, 0x40)[0] = 0x28;
        }
        break;
    case 0x28: {
        Ov010Rot r;
        void *o;
        r = FLD(Ov010Rot, data_ov010_0220f024, 0x3e);
        o = func_ov003_021da32c(0x5816);
        Ov010_VecSet(&FLD(Ov010Vec, o, 0x70), 0x2ee1, -0xc000, -0x2000);
        FLD(u16, o, 0x7c) = r.v[0]; FLD(u16, o, 0x7e) = r.v[1]; FLD(u16, o, 0x80) = r.v[2];
        o = func_ov003_021da32c(0x5816);
        Ov010_VecSet(&FLD(Ov010Vec, o, 0x70), -0x2571, -0xc000, -0x2000);
        FLD(u16, o, 0x7c) = r.v[0]; FLD(u16, o, 0x7e) = r.v[1]; FLD(u16, o, 0x80) = r.v[2];
        func_02065f88(0x579, &data_ov010_0220f114)->v0c(0x2000);
        func_02065f88(0x579, &data_ov010_0220f120)->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x5c, &FLD(Ov010Vec, self, 0x70), 0);
        FLD(u16 *, self, 0x40)[0] = 100;
        break;
    }
    case 100:
        func_020627a0(FLD(u16, self, 0xe), FLD(u16, self, 0xc));
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        FLD(u16 *, self, 0x40)[0] = 0x65;
        FLD(u8, self, 0x1fc) = 1;
        break;
    case 0x65:
        break;
    }
}
}
