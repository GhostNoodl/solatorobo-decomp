#include "ov000/LoCommon.h"
#include "ov000/Bss021ccd74.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMarker.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"

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
extern u8 data_02092800[];
extern u8 data_02092844[];
extern Ofs021c17dc data_ov000_021cc8f0[];
void NNS_G3dGlbPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc);
BOOL Model021903b4_Draw(void *m);

/* NNS_G3dGlbSetProjectionMtx on the split-out projection matrix symbol. */
static inline void SetProj021c17dc(const void *m) {
    MIi_CpuCopyFast(m, data_02092800, sizeof(MtxFx44));
    NNS_G3dGlb.flag &= ~0x50;
}

/* NNS_G3dGlbGetCameraMtx. */
static inline MtxFx43 *GetCam021c17dc(void) {
    return (MtxFx43 *)data_02092844;
}

static inline void SetScale021c17dc(Model0218fe1c *model, s32 x, s32 y, s32 z) {
    model->scale.x = x;
    model->scale.y = y;
    model->scale.z = z;
}

void func_ov000_021c17dc(ActorMarker3D *self) {
    u8 proj[0x40];
    u8 cam[0x30];
    Ofs021c17dc *o;
    VecFx32 p;
    u8 *g;
    MtxFx43 *cm;

    if (self->work.state != 10) {
        return;
    }
    cm = GetCam021c17dc();
    g = gGfxSys->unk_8b0;
    MI_Copy64B(data_02092800, proj);
    MI_Copy48B(cm, cam);
    SetProj021c17dc(g + 0x13c);
    MTX_Identity43_(cm);
    cm->m[3][2] = 0;
    NNS_G3dGlbPolygonAttr(0, 0, 3, 0, 0, 0);
    o = &data_ov000_021cc8f0[self->kind - 0xc];
    p.x = self->work.x + o->x;
    p.y = self->work.y + o->y;
    p.z = self->work.z;
    data_ov000_021ccd74.alpha = LO_FX_MUL(self->work.alpha, 0x1e000) >> 12;
    self->unk_90->trans = p;
    SetScale021c17dc(self->unk_90, 0x1000, -0x1000, 0x1000);
    Model021903b4_Draw(self->unk_90);
    SetProj021c17dc(proj);
    MI_Copy48B(cam, cm);
}

}
