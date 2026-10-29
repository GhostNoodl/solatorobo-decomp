#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 rest : 28;
} Bits021b12c0;

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
extern u8 *data_ov000_021ccd54;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_02190a80(void *a, s32 b);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void func_02062764(s32 a, s32 b);

void func_ov000_021b12c0(VObj *self, BOOL flag) {
    Anm021b12c0 *anm;
    LFLD(Bits021b12c0, self, 0xb24).b1 = 1;
    LFLD(Bits021b12c0, self, 0xb24).b2 = 0;
    self->vfunc_18();
    LFLD(VecFx32, self, 0x75c) = LFLD(VecFx32, self, 0x70);
    LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
    LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
    LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
    anm = LFLD(Anm021b12c0 *, self, 0x384);
    if (anm != NULL) {
        NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
        anm->unk_108 = 0;
        anm->unk_110 = 0xff;
        anm->b0 = 0;
        anm->b1 = 0;
    }
    LFLD(s16, self, 0x178) = -1;
    LFLD(Bits0214a424, data_0214a424, 0x18).b8 = 0;
    LFLD(Bits0214a424, data_0214a424, 0x18).b9 = 0;
    func_02062764(3, 1);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}
}

typedef struct {
    u8 c[3];
} Rgb021b13cc;

static inline void SetRgb(u8 *g, u8 r, u8 gr, u8 b) {
    LFLD(u8, g, 0x134) = r;
    LFLD(u8, g, 0x135) = gr;
    LFLD(u8, g, 0x136) = b;
}

extern "C" void func_ov000_021b13cc(VObj *self, BOOL flag) {
    LFLD(Bits021b12c0, self, 0xb24).b1 = 0;
    LFLD(Bits021b12c0, self, 0xb24).b2 = 0;
    self->vfunc_18();
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e9, 0x1000, 1);
    func_ov000_02190a80((u8 *)self + 0x368, 0x1000);
    LFLD(u16, self, 0x178) = 0x320;
    if (LFLD(Bits021b12c0, self, 0xb24).b1 == 1) {
        LFLD(Rgb021b13cc, self, 0x772) = LFLD(Rgb021b13cc, data_ov000_021ccd54, 0xca);
    }
    LFLD(Bits0214a424, data_0214a424, 0x18).b8 = 1;
    LFLD(VecFx32, data_0214a424, 0x148) = LFLD(VecFx32, self, 0x75c);
    LFLD(u16, data_0214a424, 0x156) = LFLD(u16, self, 0x76e);
    SetRgb(data_0214a424, LFLD(u8, self, 0x772), LFLD(u8, self, 0x773), LFLD(u8, self, 0x774));
    func_02062764(3, 2);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}
