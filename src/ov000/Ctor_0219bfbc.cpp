#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "ov000/ObjLayouts.h"
#include "types.h"
#include "nitro/fx.h"

extern "C" {
extern u8 data_ov000_021cc774[];
void *Actor_Ctor(Actor *self);
void *Model0218fe1c_Init(void *p);
void *ResSet_Init(void *p);
void *ActorSub48_Init(void *p);
void TouchQuad_Init(void *q, u16 a, u16 b, u16 c, u16 d);

Robo021ca458 *Robo021ca458_Ctor(Robo021ca458 *self) {
    u32 mode;
    Actor_Ctor(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cc774);
    Model0218fe1c_Init(&self->mdl0);
    ResSet_Init(&self->res0);
    ActorSub48_Init(&self->hit0);
    Model0218fe1c_Init(&self->mdl1);
    ResSet_Init(&self->res1);
    ResSet_Init(&self->res2);
    ActorSub48_Init(&self->hit1);
    Model0218fe1c_Init(&self->mdl2);
    ResSet_Init(&self->res3);
    self->unk_ae8 = 0;
    self->unk_aea = 0;
    self->unk_aec = 0;
    self->unk_99c = NULL;
    self->unk_998 = NULL;
    self->unk_9b0 = NULL;
    self->unk_9b4 = NULL;
    self->unk_b28 = 0;
    self->unk_b29 = 0;
    self->unk_b2a = 0;
    self->unk_b2e = 0;
    self->unk_b2f = 0;
    self->unk_b30 = 0;
    self->unk_b31 = 0;
    self->rot_x = 0;
    self->unk_b22 = 0;
    self->unk_b2c = 0;
    self->unk_b32 = 0;
    self->unk_b36 = 0;
    self->unk_b38 = 0;
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b20 = 0xffff;
    // The flag word is cleared and its fields set last in this group, after the 0xffff stores.
    self->unk_b24 = 0;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
    self->unk_b24_12 = 0;
    if (data_0214a424->bits18.flag8) {
        self->unk_b24_1 = 0;
    } else {
        self->unk_b24_1 = 1;
    }
    if (!self->unk_b24_1) {
        self->unk_75c = data_0214a424->target;
        u16 v = data_0214a424->targetRotY;
        self->unk_76c = 0;
        self->unk_76e = v;
        self->unk_770 = 0;
        self->unk_772 = data_0214a424->color.r;
        self->unk_773 = data_0214a424->color.g;
        self->unk_774 = data_0214a424->color.b;
    }
    self->unk_768 = 0;
    self->unk_af0.x = 0;
    self->unk_af0.y = 0;
    self->unk_af0.z = 0;
    self->unk_afc.x = 0;
    self->unk_afc.y = 0;
    self->unk_afc.z = 0;
    self->unk_b40 = 0;
    self->unk_b44 = 0;
    self->unk_b48 = 0;
    self->seSlot = -1;
    self->unk_b66 = -1;
    self->padCur = 0;
    self->padTrig = 0;
    self->padRelease = 0;
    self->padDir = 0;
    TouchQuad_Init(self->unk_b70, 0, 0x4000, 0x8000, 0xc000);
    self->unk_b0c = 0x1000;
    self->unk_b9c = 0;
    mode = data_0214a424->bits18.mode;
    self->unk_b22_6 = 0;
    if (mode == 1) {
        self->unk_b22_6 = 2;
    } else if (mode == 2) {
        self->unk_b22_6 = 5;
    }
    self->unk_ba4 = NULL;
    self->unk_ba0 = NULL;
    self->unk_ba8 = 0;
    self->unk_bac = 0xffff;
    self->unk_16 |= 4;
    return self;
}
}
