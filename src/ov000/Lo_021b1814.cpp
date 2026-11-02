#include "ov000/LoCommon.h"
#include "Main/Res/StageFlags.h"
#include "ov000/Vec.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 unk_00[0x108];
    u8 unk_108;
    u8 unk_109[7];
    u8 unk_110;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
} Anm021b12c0;

extern "C" {
extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc5e9[];
void Model0218fe1c_UpdateAnim(void *a, s32 b);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void func_02062764(s32 a, s32 b);

static inline void Reset12c0(Robo021ca458 *self, BOOL flag) {
    Anm021b12c0 *anm;
    self->unk_b24_1 = 1;
    self->unk_b24_2 = 0;
    self->vfunc_18();
    self->unk_75c = self->pos;
    self->unk_76c = self->rot_x;
    self->unk_76e = self->rot_y;
    self->unk_770 = self->rot_z;
    Model0218fe1c_SetAnim(&self->mdl1, data_ov000_021cc5e3, 0x1000, 1);
    anm = ((Anm021b12c0 *)self->mdl1.unk_1c);
    if (anm != NULL) {
        NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
        anm->unk_108 = 0;
        anm->unk_110 = 0xff;
        anm->b0 = 0;
        anm->b1 = 0;
    }
    self->mdl0.unk_cc = -1;
    data_0214a424->bits18.flag8 = 0;
    data_0214a424->bits18.flag9 = 0;
    func_02062764(3, 1);
    if (flag) {
        data_ov000_021ccd54->stageFlags = 1;
    }
}

void func_ov000_021b1814(Robo021ca458 *self, BOOL flag, BOOL mode) {
    if (self->unk_b22_3) {
        return;
    }
    if (self->unk_b22_9) {
        return;
    }
    if (!self->unk_b24_1) {
        Reset12c0(self, flag);
    }
    if (data_0214a424->bits18.mode == 2) {
        data_0214a424->bits18.mode = 1;
    }
    if (mode) {
        self->unk_b22_4 = 1;
        self->unk_b22_5 = 0;
        self->unk_b22_13 = 1;
    } else {
        self->unk_b22_4 = 0;
        if (self->unk_b22_6 == 1 || self->unk_b22_6 == 3) {
            self->unk_b22_5 = 1;
        }
        self->unk_b22_13 = 0;
    }
    if (self->unk_b22_9 < 2) {
        self->unk_b22_6 = 4;
        self->unk_b22_9 = 1;
        self->fsm->flags |= 0x80000000;
        History_SetState(self->fsm, 0x1f, 0);
    }
    func_02062764(0xc00, 0x800);
    if (flag) {
        data_ov000_021ccd54->stageFlags = 1;
    }
}

static inline void SetSt(Robo021ca458 *self, u16 st) {
    if (self->unk_b22_9 < 2) {
        self->unk_b22_6 = st;
        self->unk_b22_9 = 1;
        self->fsm->flags |= 0x80000000;
        History_SetState(self->fsm, 0x1f, 0);
    }
}

void func_ov000_021b1a54(Robo021ca458 *self, BOOL flag) {
    u32 st;
    if (!self->unk_b22_3) {
        return;
    }
    if (self->unk_b22_9) {
        return;
    }
    st = 0;
    if (data_0214a424->bits18.mode == 1) {
        if (self->unk_b22_5) {
            st = 3;
        } else {
            st = 2;
        }
    } else if (self->unk_b22_5) {
        st = 1;
    }
    if (self->unk_b22_4) {
        self->unk_b22_13 = 1;
    }
    self->unk_b22_4 = 0;
    self->unk_b22_5 = 0;
    SetSt(self, st);
    func_02062764(0xc00, 0x400);
    if (flag) {
        data_ov000_021ccd54->stageFlags = 1;
    }
}

void func_ov000_021b1b88(Robo021ca458 *self, s32 mode) {
    u32 st;
    switch (mode) {
    default:
        st = 0;
        break;
    case 1:
        st = 2;
        break;
    case 2:
        if (!self->unk_b24_1) {
            Anm021b12c0 *anm;
            self->unk_b24_1 = 1;
            self->unk_b24_2 = 0;
            self->vfunc_18();
            self->unk_75c = self->pos;
            self->unk_76c = self->rot_x;
            self->unk_76e = self->rot_y;
            self->unk_770 = self->rot_z;
            Model0218fe1c_SetAnim(&self->mdl1, data_ov000_021cc5e3, 0x1000, 1);
            anm = (Anm021b12c0 *)self->mdl1.unk_1c;
            if (anm != NULL) {
                NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
                anm->unk_108 = 0;
                anm->unk_110 = 0xff;
                anm->b0 = 0;
                anm->b1 = 0;
            }
            self->mdl0.unk_cc = -1;
            data_0214a424->bits18.flag8 = 0;
            data_0214a424->bits18.flag9 = 0;
            func_02062764(3, 1);
        }
        st = 5;
        break;
    }
    self->unk_b22_13 = 1;
    SetSt(self, st);
}

void func_ov000_021b1d28(Robo021ca458 *self) {
    u32 st = self->unk_b22_6;
    switch (st) {
    case 4:
    case 5:
        return;
    }
    if (st != 2 && st != 3) {
        st = 2;
    }
    self->unk_b22_13 = 0;
    SetSt(self, st);
}
}
