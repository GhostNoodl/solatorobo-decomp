#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 pad[0xfc];
    u32 flag;
} Glb021c17dc;

typedef struct {
    s32 unk_00;
    s32 x;
    s32 y;
} Ofs021c17dc;

extern "C" {
extern Glb021c17dc NNS_G3dGlb;
extern u8 *data_02097d48;
extern u8 data_02092800[];
extern u8 data_02092844[];
extern Ofs021c17dc data_ov000_021cc8f0[];
extern u8 data_ov000_021ccd74;
void MI_Copy64B(const void *src, void *dst);
void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
void NNS_G3dGlbPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc);
BOOL func_ov000_021903b4(void *m);

/* NNS_G3dGlbSetProjectionMtx on the split-out projection matrix symbol. */
static inline void SetProj021c17dc(const void *m) {
    MIi_CpuCopyFast(m, data_02092800, sizeof(MtxFx44));
    NNS_G3dGlb.flag &= ~0x50;
}

/* NNS_G3dGlbGetCameraMtx. */
static inline MtxFx43 *GetCam021c17dc(void) {
    return (MtxFx43 *)data_02092844;
}

static inline void SetScale021c17dc(u8 *model, s32 x, s32 y, s32 z) {
    LFLD(s32, model, 0xa8) = x;
    LFLD(s32, model, 0xac) = y;
    LFLD(s32, model, 0xb0) = z;
}

void func_ov000_021c17dc(Lo021cc938 *self) {
    u8 proj[0x40];
    u8 cam[0x30];
    Ofs021c17dc *o;
    VecFx32 p;
    u8 *g;
    MtxFx43 *cm;

    if (self->unk_68 != 10) {
        return;
    }
    cm = GetCam021c17dc();
    g = data_02097d48 + 0x8b0;
    MI_Copy64B(data_02092800, proj);
    MI_Copy48B(cm, cam);
    SetProj021c17dc(g + 0x13c);
    MTX_Identity43_(cm);
    cm->m[3][2] = 0;
    NNS_G3dGlbPolygonAttr(0, 0, 3, 0, 0, 0);
    o = &data_ov000_021cc8f0[self->unk_44 - 0xc];
    p.x = self->unk_78 + o->x;
    p.y = self->unk_7c + o->y;
    p.z = self->unk_80;
    data_ov000_021ccd74 = LO_FX_MUL(self->unk_88, 0x1e000) >> 12;
    LFLD(VecFx32, self->unk_90, 0x78) = p;
    SetScale021c17dc((u8 *)self->unk_90, 0x1000, -0x1000, 0x1000);
    func_ov000_021903b4((u8 *)self->unk_90);
    SetProj021c17dc(proj);
    MI_Copy48B(cam, cm);
}

}
