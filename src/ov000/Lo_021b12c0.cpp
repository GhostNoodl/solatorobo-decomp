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

struct Obj021b12c0 : public VObj {
    u8 unk_04[0x6c];
    VecFx32 unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0xf6];
    s16 unk_178;
    u8 unk_17a[0x20a];
    Anm021b12c0 *unk_384;
    u8 unk_388[0x3d4];
    VecFx32 unk_75c;
    u8 unk_768[0x4];
    u16 unk_76c;
    u16 unk_76e;
    u16 unk_770;
    u8 unk_772[0x3b2];
    Bits021b12c0 unk_b24;
};

void func_ov000_021b12c0(Obj021b12c0 *self, BOOL flag) {
    Anm021b12c0 *anm;
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

struct Obj021b13cc : public VObj {
    u8 unk_04[0x174];
    u16 unk_178;
    u8 unk_17a[0x5e2];
    VecFx32 unk_75c;
    u8 unk_768[0x6];
    u16 unk_76e;
    u8 unk_770[0x2];
    Rgb021b13cc unk_772;
    u8 unk_775[0x3af];
    Bits021b12c0 unk_b24;
};

extern "C" void func_ov000_021b13cc(Obj021b13cc *self, BOOL flag) {
    self->unk_b24.b1 = 0;
    self->unk_b24.b2 = 0;
    self->vfunc_18();
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e9, 0x1000, 1);
    func_ov000_02190a80((u8 *)self + 0x368, 0x1000);
    self->unk_178 = 0x320;
    if (self->unk_b24.b1 == 1) {
        self->unk_772 = LFLD(Rgb021b13cc, data_ov000_021ccd54, 0xca);
    }
    LFLD(Bits0214a424, data_0214a424, 0x18).b8 = 1;
    LFLD(VecFx32, data_0214a424, 0x148) = self->unk_75c;
    LFLD(u16, data_0214a424, 0x156) = self->unk_76e;
    SetRgb(data_0214a424, LFLD(u8, self, 0x772), LFLD(u8, self, 0x773), LFLD(u8, self, 0x774));
    func_02062764(3, 2);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}
