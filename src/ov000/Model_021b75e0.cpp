#include "ov000/Vec.h"

typedef struct {
    u8 unk_00[0x18];
    s32 boxPos[3];
    s32 boxScale;
    s32 boxInvScale;
} MdlInfo021b75e0;

typedef struct {
    void *res;
    u8 *mdl;
} RObj021b75e0;

typedef struct {
    u8 unk_00[0x20];
    RObj021b75e0 *obj;
    u8 unk_24[0x58];
    VecFx32 trans;
    u8 rot[0x24];
    VecFx32 scale;
    u8 unk_b8[4];
    u8 alpha;
    u8 on : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 invV : 1;
    u8 addInvTrans : 1;
    u8 boxTest : 1;
    u8 rest : 2;
} Model021b75e0;

extern "C" {

extern u8 data_020928b4[];
typedef struct {
    u8 pad[0xfc];
    u32 flag;
} Glb021b75e0;

extern Glb021b75e0 NNS_G3dGlb;
extern u8 *data_02097d48;
void *NNS_G3dGlbGetInvV(void);
void MI_Copy36B(const void *src, void *dst);
void NNS_G3dGlbSetBaseScale(const VecFx32 *s);
void NNS_G3dGlbSetBaseTrans(const VecFx32 *t);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, BOOL on, u32 mask);
void NNS_G3dGlbPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc);
void NNS_G3dGlbFlushP(void);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeFlushBuffer(void);
int G3X_GetBoxTestResult(s32 *in);
void NNS_G3dDraw(void *obj);
void func_02043d48(void *p);

static inline void G3_Scale021b75e0(s32 x, s32 y, s32 z) {
    s32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(0x1b, v, 3);
}

BOOL func_ov000_021b75e0(Model021b75e0 *self) {
    BOOL drawn = FALSE;
    u8 *mdl;
    MdlInfo021b75e0 *info;
    VecFx32 t;
    s32 res;
    if (!self->on) {
        return FALSE;
    }
    if (self->alpha == 0) {
        return FALSE;
    }
    mdl = self->obj->mdl;
    if (self->invV) {
        MI_Copy36B(NNS_G3dGlbGetInvV(), data_020928b4);
    } else {
        MI_Copy36B(self->rot, data_020928b4);
    }
    NNS_G3dGlb.flag &= ~0xa4;
    if (self->addInvTrans) {
        VEC_Add(&self->trans, (VecFx32 *)((u8 *)NNS_G3dGlbGetInvV() + 0x24), &t);
        NNS_G3dGlbSetBaseTrans(&t);
    } else {
        NNS_G3dGlbSetBaseTrans(&self->trans);
    }
    NNS_G3dGlbSetBaseScale(&self->scale);
    if (self->alpha != 0x1f) {
        u8 id;
        NNSi_G3dModifyPolygonAttrMask(mdl, FALSE, 0x1f0000);
        NNSi_G3dModifyPolygonAttrMask(mdl, FALSE, 0xc0);
        NNSi_G3dModifyPolygonAttrMask(mdl, FALSE, 0x3f000000);
        id = data_02097d48[0x8b1];
        func_02043d48(data_02097d48 + 0x8b0);
        NNS_G3dGlbPolygonAttr(0, 0, 2, id, self->alpha, 0x1000);
    } else {
        NNS_G3dGlbPolygonAttr(0, 0, 3, 0x14, 0x1f, 0x1000);
    }
    NNS_G3dGlbFlushP();
    if (self->boxTest) {
        info = mdl != NULL ? (MdlInfo021b75e0 *)(mdl + 0x14) : NULL;
        G3_Scale021b75e0(info->boxScale, info->boxScale, info->boxScale);
        NNS_G3dGeBufferOP_N(0x70, info->boxPos, 3);
        NNS_G3dGeFlushBuffer();
        while (G3X_GetBoxTestResult(&res) != 0) {
        }
        if (res != 0) {
            G3_Scale021b75e0(info->boxInvScale, info->boxInvScale, info->boxInvScale);
            NNS_G3dDraw(self->obj);
            drawn = TRUE;
        }
    } else {
        NNS_G3dDraw(self->obj);
        drawn = TRUE;
    }
    if (self->alpha != 0x1f) {
        NNSi_G3dModifyPolygonAttrMask(mdl, TRUE, 0x1f0000);
        NNSi_G3dModifyPolygonAttrMask(mdl, TRUE, 0xc0);
        NNSi_G3dModifyPolygonAttrMask(mdl, TRUE, 0x3f000000);
    }
    return drawn;
}

}
