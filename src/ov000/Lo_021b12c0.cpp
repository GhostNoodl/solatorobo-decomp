#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 rest : 6;
} Bits0214a424;

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
extern u8 *data_0214a424;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_02190a80(void *a, s32 b);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void func_02062764(s32 a, s32 b);

void func_ov000_021b12c0(Robo021ca458 *self, BOOL flag) {
    Anm021b12c0 *anm;
    self->unk_b24_1 = 1;
    self->unk_b24_2 = 0;
    self->vfunc_18();
    self->unk_75c = self->pos;
    self->unk_76c = self->rot_x;
    self->unk_76e = self->rot_y;
    self->unk_770 = self->rot_z;
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
    anm = ((Anm021b12c0 *)self->unk_384);
    if (anm != NULL) {
        NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
        anm->unk_108 = 0;
        anm->unk_110 = 0xff;
        anm->b0 = 0;
        anm->b1 = 0;
    }
    self->unk_178 = -1;
    LFLD(Bits0214a424, data_0214a424, 0x18).b8 = 0;
    LFLD(Bits0214a424, data_0214a424, 0x18).b9 = 0;
    func_02062764(3, 1);
    if (flag) {
        data_ov000_021ccd54->stageFlags = 1;
    }
}
}

static inline void SetRgb(u8 *g, u8 r, u8 gr, u8 b) {
    LFLD(u8, g, 0x134) = r;
    LFLD(u8, g, 0x135) = gr;
    LFLD(u8, g, 0x136) = b;
}

extern "C" void func_ov000_021b13cc(Robo021ca458 *self, BOOL flag) {
    self->unk_b24_1 = 0;
    self->unk_b24_2 = 0;
    self->vfunc_18();
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e9, 0x1000, 1);
    func_ov000_02190a80((u8 *)self + 0x368, 0x1000);
    self->unk_178 = 0x320;
    if (self->unk_b24_1 == 1) {
        LFLD(FieldId, self, 0x772) = data_ov000_021ccd54->unk_ca;
    }
    LFLD(Bits0214a424, data_0214a424, 0x18).b8 = 1;
    LFLD(VecFx32, data_0214a424, 0x148) = self->unk_75c;
    LFLD(u16, data_0214a424, 0x156) = self->unk_76e;
    SetRgb(data_0214a424, self->unk_772, self->unk_773, self->unk_774);
    func_02062764(3, 2);
    if (flag) {
        data_ov000_021ccd54->stageFlags = 1;
    }
}
