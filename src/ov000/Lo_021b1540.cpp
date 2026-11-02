#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 5;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 rest : 6;
} Bits0214a424_1540;

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
extern char data_ov000_021cc5e3[];
extern u8 *data_0214a424;
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void func_02062764(s32 a, s32 b);

static inline void Enter(Robo021ca458 *self, BOOL flag) {
    Anm021b1540 *anm;
    self->unk_b24_1 = 1;
    self->unk_b24_2 = 0;
    self->vfunc_18();
    self->unk_75c = self->pos;
    self->unk_76c = self->rot_x;
    self->unk_76e = self->rot_y;
    self->unk_770 = self->rot_z;
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
    anm = ((Anm021b1540 *)self->unk_384);
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
        data_ov000_021ccd54->unk_ac = 1;
    }
}

void func_ov000_021b1540(Robo021ca458 *self, BOOL flag, s32 mode) {
    u32 st;
    if ((self->unk_b22_0 != 0 || self->unk_b22_9 != 0) && mode == 0) {
        return;
    }
    if (self->unk_b24_1 == 0) {
        Enter(self, flag);
    }
    st = 1;
    if (mode == 1 || mode == 3) {
        st = mode;
    } else if (LFLD(Bits0214a424_1540, data_0214a424, 0x18).b1 == 1) {
        st = 3;
    }
    if (self->unk_b22_9 < 2) {
        self->unk_b22_6 = (u16)st;
        self->unk_b22_9 = 1;
        self->unk_40->flags |= 0x80000000;
        func_ov000_02198360(self->unk_40, 0x1f, 0);
    }
    func_02062764(0x30, 0x20);
    if (flag) {
        data_ov000_021ccd54->unk_ac = 1;
    }
}

}
