#include "ov000/HeapScope.h"
#include "ov000/Vec.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/ActorMarker.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

struct Marker021be5dc : ActorMarker {
    void *unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
};

// Depth-range block of the camera (same layout as in ov000_021c14f4.cpp).
typedef struct {
    u8 pad[0xa14];
    s32 a;
    u8 pad2[0xc];
    s32 b;
    s32 c;
} DepthCam021be5dc;

extern "C" {

void *func_ov000_021be564(ActorMarkerWork *work, void *src, void *out, u16 *count);
void TexObj_SetOamFunc(void *model, s32 a, void *cb, void *arg);
extern u8 data_02092800[]; // NNS_G3dGlb.projMtx
extern u8 data_02092844[];  // NNS_G3dGlb.cameraMtx

static inline s32 FxMulL(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline BOOL Obj021be5dc_Wait(Marker021be5dc *self) {
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->work.state = 10;
    return FALSE;
}

static inline s32 DepthFromW(DepthCam021be5dc *s, s32 q) {
    s32 r = q - 0x1000;
    r = FX_MUL(r, s->c);
    return FX_Div(r - s->b, s->a);
}

static inline s32 CalcDepth(VecFx32 *pos) {
    VecFx32 v;
    s32 w;
    s32 q;
    s32 *m = (s32 *)data_02092800;
    MTX_MultVec43(pos, (const MtxFx43 *)data_02092844, &v);
    v.z += 0x3000;
    w = FxMulL(v.z, -0x1000);
    q = m[14] + FX_MUL(m[10], v.z);
    q = FX_Div(q + w, w * 2);
    return DepthFromW((DepthCam021be5dc *)gGfxSys, FxMulL(q, 0x2000));
}

void ActorMarker_UpdateKind01(Marker021be5dc *self) {
    VecFx32 pos;
    switch (self->work.state) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        return;
    case 1:
        {
            void *model = self->mdl[4];
            self->mdl[4] = NULL;
            self->unk_8c = model;
            self->unk_90 = 0;
            self->unk_94 = 0;
            self->unk_98 = self->unk_28[0];
            TexObj_SetOamFunc(model, 4, (void *)func_ov000_021be564, &self->work);
        }
        self->work.state = 4;
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021be5dc_Wait(self)) {
            return;
        }
    case 10:
        if (ActorMarker_UpdateFade(self, 0x1000)) {
            return;
        }
        if (++self->unk_90 < 0x12) {
            self->unk_94 += FX_MUL(0x3000 - self->unk_94, 0x19a);
        } else if (self->unk_90 >= 0x30) {
            self->unk_90 = 0;
            self->unk_94 = 0;
        } else {
            self->unk_94 += FX_MUL(-self->unk_94, 0xcd);
        }
        pos = self->unk_50;
        ActorMarker_UpdateScreenPos(self, &pos);
        self->work.z = CalcDepth(&pos);
        break;
    case 0:
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}

}
