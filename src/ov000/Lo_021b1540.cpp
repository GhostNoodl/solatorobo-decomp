#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 rest : 28;
} Bits021b1540;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 5;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 rest : 6;
} Bits0214a424_1540;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 3;
    u16 st : 3;
    u16 b9 : 2;
    u16 b11 : 2;
    u16 b13 : 1;
    u16 b14 : 2;
} Bits21b1540b;

typedef struct {
    u8 unk_00[0x108];
    u8 unk_108;
    u8 unk_109[7];
    u8 unk_110;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
} Anm021b1540;

extern "C" {
extern u8 data_ov000_021cc5e3[];
extern u8 *data_0214a424;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void func_02062764(s32 a, s32 b);

static inline void Enter(VObj *self, BOOL flag) {
    Anm021b1540 *anm;
    LFLD(Bits021b1540, self, 0xb24).b1 = 1;
    LFLD(Bits021b1540, self, 0xb24).b2 = 0;
    self->vfunc_18();
    LFLD(VecFx32, self, 0x75c) = LFLD(VecFx32, self, 0x70);
    LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
    LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
    LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
    anm = LFLD(Anm021b1540 *, self, 0x384);
    if (anm != NULL) {
        NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
        anm->unk_108 = 0;
        anm->unk_110 = 0xff;
        anm->b0 = 0;
        anm->b1 = 0;
    }
    LFLD(s16, self, 0x178) = -1;
    LFLD(Bits0214a424_1540, data_0214a424, 0x18).b8 = 0;
    LFLD(Bits0214a424_1540, data_0214a424, 0x18).b9 = 0;
    func_02062764(3, 1);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}

void func_ov000_021b1540(VObj *self, BOOL flag, s32 mode) {
    u32 st;
    if ((LFLD(Bits21b1540b, self, 0xb22).b0 != 0 || LFLD(Bits21b1540b, self, 0xb22).b9 != 0) && mode == 0) {
        return;
    }
    if (LFLD(Bits021b1540, self, 0xb24).b1 == 0) {
        Enter(self, flag);
    }
    st = 1;
    if (mode == 1 || mode == 3) {
        st = mode;
    } else if (LFLD(Bits0214a424_1540, data_0214a424, 0x18).b1 == 1) {
        st = 3;
    }
    if (LFLD(Bits21b1540b, self, 0xb22).b9 < 2) {
        LFLD(Bits21b1540b, self, 0xb22).st = (u16)st;
        LFLD(Bits21b1540b, self, 0xb22).b9 = 1;
        LFLD(ActorSub40 *, self, 0x40)->flags |= 0x80000000;
        func_ov000_02198360(LFLD(void *, self, 0x40), 0x1f, 0);
    }
    func_02062764(0x30, 0x20);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}

}
