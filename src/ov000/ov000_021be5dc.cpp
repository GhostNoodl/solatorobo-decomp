#include "ov000/HeapScope.h"
#include "ov000/Vec.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 unk_00_0 : 1;
    u32 unk_00_1 : 1;
    u32 unk_00_2 : 1;
    u32 unk_00_3 : 1;
    u32 unk_00_4 : 28;
    u8 pad_04[0x14];
    void *unk_18;
    u8 pad_1c[0xc];
    s32 unk_28;
    u8 pad_2c[0x24];
    VecFx32 unk_50;
    u8 pad_5c[0xc];
    s32 unk_68;
    u8 pad_6c[0x14];
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    void *unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
} Obj021be5dc;

// Depth-range block of the camera (same layout as in ov000_021c14f4.cpp).
typedef struct {
    u8 pad[0xa14];
    s32 a;
    u8 pad2[0xc];
    s32 b;
    s32 c;
} DepthCam021be5dc;

extern "C" {

BOOL func_ov000_021bd374(Obj021be5dc *self, s32 len);
void func_ov000_021bd474(Obj021be5dc *self, VecFx32 *pos);
void *func_ov000_021be564(void *self, void *src, void *out, u16 *count);
void MTX_MultVec43(const VecFx32 *vec, const void *m, VecFx32 *dst);
s32 FX_Div(s32 a, s32 b);
void func_02041c34(void *model, s32 a, void *cb, void *arg);
extern u8 data_02092800[]; // NNS_G3dGlb.projMtx
extern u8 data_02092844[];  // NNS_G3dGlb.cameraMtx
extern u8 *data_02097d48;

static inline s32 FxMulL(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline BOOL Obj021be5dc_Wait(Obj021be5dc *self) {
    if (!(self->unk_00_1 == 1 ? TRUE : FALSE) || (self->unk_00_3 == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->unk_68 = 10;
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
    MTX_MultVec43(pos, data_02092844, &v);
    v.z += 0x3000;
    w = FxMulL(v.z, -0x1000);
    q = m[14] + FX_MUL(m[10], v.z);
    q = FX_Div(q + w, w * 2);
    return DepthFromW((DepthCam021be5dc *)data_02097d48, FxMulL(q, 0x2000));
}

void func_ov000_021be5dc(Obj021be5dc *self) {
    VecFx32 pos;
    switch (self->unk_68) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        return;
    case 1:
        {
            void *model = self->unk_18;
            self->unk_18 = NULL;
            self->unk_8c = model;
            self->unk_90 = 0;
            self->unk_94 = 0;
            self->unk_98 = self->unk_28;
            func_02041c34(model, 4, (void *)func_ov000_021be564, &self->unk_68);
        }
        self->unk_68 = 4;
    case 4:
        self->unk_84 = 0;
        self->unk_88 = 0;
        if (Obj021be5dc_Wait(self)) {
            return;
        }
    case 10:
        if (func_ov000_021bd374(self, 0x1000)) {
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
        func_ov000_021bd474(self, &pos);
        self->unk_80 = CalcDepth(&pos);
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
