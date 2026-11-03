#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "Main/Res/StageFlags.h"

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
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc5e9[];
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void Shared_ChangeFlags(s32 a, s32 b);

void func_ov000_021b12c0(Robo021ca458 *self, BOOL flag) {
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
        NNS_G3dRenderObjRemoveAnmObj(self->mdl1.renderObj, *(void **)anm);
        anm->unk_108 = 0;
        anm->unk_110 = 0xff;
        anm->b0 = 0;
        anm->b1 = 0;
    }
    self->mdl0.unk_cc = -1;
    gStageFlags->bits18.flag8 = 0;
    gStageFlags->bits18.flag9 = 0;
    Shared_ChangeFlags(3, 1);
    if (flag) {
        gSceneCmd->stageFlags = 1;
    }
}
}

static inline void SetRgb(StageFlags *g, u8 r, u8 gr, u8 b) {
    g->color.r = r;
    g->color.g = gr;
    g->color.b = b;
}

extern "C" void func_ov000_021b13cc(Robo021ca458 *self, BOOL flag) {
    self->unk_b24_1 = 0;
    self->unk_b24_2 = 0;
    self->vfunc_18();
    Model0218fe1c_SetAnim(&self->mdl1, data_ov000_021cc5e9, 0x1000, 1);
    Model0218fe1c_UpdateAnim(&self->mdl1, 0x1000);
    self->mdl0.unk_cc = 0x320;
    if (self->unk_b24_1 == 1) {
        self->fieldId = gSceneCmd->unk_ca;
    }
    gStageFlags->bits18.flag8 = 1;
    gStageFlags->target = self->unk_75c;
    gStageFlags->targetRotY = self->unk_76e;
    SetRgb(gStageFlags, self->unk_772, self->unk_773, self->unk_774);
    Shared_ChangeFlags(3, 2);
    if (flag) {
        gSceneCmd->stageFlags = 1;
    }
}
