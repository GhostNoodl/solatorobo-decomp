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

struct Obj021b1540 : public VObj {
    u8 unk_04[0x3c];
    ActorSub40 *unk_40;
    u8 unk_44[0x2c];
    VecFx32 unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0xf6];
    s16 unk_178;
    u8 unk_17a[0x20a];
    Anm021b1540 *unk_384;
    u8 unk_388[0x3d4];
    VecFx32 unk_75c;
    u8 unk_768[0x4];
    u16 unk_76c;
    u16 unk_76e;
    u16 unk_770;
    u8 unk_772[0x3b0];
    Bits21b1540b unk_b22;
    Bits021b1540 unk_b24;
};

static inline void Enter(Obj021b1540 *self, BOOL flag) {
    Anm021b1540 *anm;
    self->unk_b24.b1 = 1;
    self->unk_b24.b2 = 0;
    self->vfunc_18();
    self->unk_75c = self->unk_70;
    self->unk_76c = self->unk_7c;
    self->unk_76e = self->unk_7e;
    self->unk_770 = self->unk_80;
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
    anm = self->unk_384;
    if (anm != NULL) {
        NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
        anm->unk_108 = 0;
        anm->unk_110 = 0xff;
        anm->b0 = 0;
        anm->b1 = 0;
    }
    self->unk_178 = -1;
    LFLD(Bits0214a424_1540, data_0214a424, 0x18).b8 = 0;
    LFLD(Bits0214a424_1540, data_0214a424, 0x18).b9 = 0;
    func_02062764(3, 1);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}

void func_ov000_021b1540(Obj021b1540 *self, BOOL flag, s32 mode) {
    u32 st;
    if ((self->unk_b22.b0 != 0 || self->unk_b22.b9 != 0) && mode == 0) {
        return;
    }
    if (self->unk_b24.b1 == 0) {
        Enter(self, flag);
    }
    st = 1;
    if (mode == 1 || mode == 3) {
        st = mode;
    } else if (LFLD(Bits0214a424_1540, data_0214a424, 0x18).b1 == 1) {
        st = 3;
    }
    if (self->unk_b22.b9 < 2) {
        self->unk_b22.st = (u16)st;
        self->unk_b22.b9 = 1;
        self->unk_40->flags |= 0x80000000;
        func_ov000_02198360(self->unk_40, 0x1f, 0);
    }
    func_02062764(0x30, 0x20);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}

}
