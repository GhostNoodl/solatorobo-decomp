#include "ov000/Vec.h"

typedef struct {
    u8 unk_00[0x18];
    s32 boxPos[3];
    s32 boxScale;
    s32 boxInvScale;
} MdlInfo021903b4;

typedef struct {
    void *res;
    u8 *mdl;
    u8 unk_08[0x1c];
    u8 renderObj[0x54];
    VecFx32 trans;
    u8 rot[0x24];
    VecFx32 scale;
    u16 unk_b4;
    u16 color;
    u16 color2;
    u16 blend;
    u16 blendMax;
    u8 alpha;
    u8 bright;
    u8 unk_c0;
    u8 polyId;
    u16 on : 1;
    u16 b1 : 1;
    u16 invV : 1;
    u16 flipX : 1;
    u16 boxTest : 1;
    u16 clearInit : 1;
    u16 b6 : 1;
    u16 restoreMat : 1;
    u16 flushVP : 1;
    u16 cull : 2;
    u16 rest : 5;
} Model021903b4;

extern "C" {

extern u8 data_020928b4[];
typedef struct {
    u8 pad[0xfc];
    u32 flag;
} Glb021903b4;

extern Glb021903b4 NNS_G3dGlb;
extern u8 *data_02097d48;
void *NNS_G3dGlbGetInvV(void);
void MI_Copy36B(const void *src, void *dst);
void NNS_G3dGlbSetBaseScale(const VecFx32 *s);
void NNS_G3dGlbSetBaseTrans(const VecFx32 *t);
u16 func_0203d144(u16 a, u16 b, s16 ratio);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, BOOL on, u32 mask);
void NNSi_G3dModifyMatFlag(void *mdl, BOOL on, u32 mask);
void NNS_G3dGlbMaterialColorDiffAmb(u16 diffuse, u16 ambient, BOOL setVtxColor);
void NNS_G3dGlbMaterialColorSpecEmi(u16 specular, u16 emission, BOOL shininess);
void NNS_G3dGlbPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc);
void NNS_G3dGlbFlushVP(void);
void NNS_G3dGlbFlushP(void);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeFlushBuffer(void);
int G3X_GetBoxTestResult(s32 *in);
void NNS_G3dDraw(void *obj);
void NNS_G3dRenderObjSetInitFunc(void *obj, void *func);
void func_02043578(void *light);

static inline void G3_Scale(s32 x, s32 y, s32 z) {
    s32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(0x1b, v, 3);
}

BOOL func_ov000_021903b4(Model021903b4 *self) {
    BOOL drawn = FALSE;
    BOOL restore;
    s32 polyId;
    u16 color;
    MdlInfo021903b4 *info;
    VecFx32 scale;
    s32 res;
    if (self->mdl == NULL || !self->on) {
        return FALSE;
    }
    scale = self->scale;
    if (self->invV) {
        MI_Copy36B(NNS_G3dGlbGetInvV(), data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
        if (self->flipX) {
            scale.x = -scale.x;
        }
    } else {
        MI_Copy36B(self->rot, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
    }
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbSetBaseTrans(&self->trans);
    polyId = self->polyId;
    restore = FALSE;
    if (polyId == 0) {
        polyId = 5;
    }
    if (self->blend != 0) {
        color = self->color;
        if (self->blend != 0) {
            if (color != self->color2) {
                color = func_0203d144(self->color2, color, (self->blend << 12) / self->blendMax);
            }
            restore = TRUE;
        }
        NNSi_G3dModifyPolygonAttrMask(self->mdl, FALSE, 0xf);
        NNSi_G3dModifyPolygonAttrMask(self->mdl, FALSE, 0x30);
        NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x40);
        NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x80);
        NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x200);
        NNSi_G3dModifyMatFlag(self->mdl, FALSE, 0x400);
        NNS_G3dGlbMaterialColorDiffAmb(color, color, FALSE);
        NNS_G3dGlbMaterialColorSpecEmi(color, color, FALSE);
        NNS_G3dGlbPolygonAttr(0, 0, self->cull, polyId, self->alpha, 0x1000);
    } else {
        if (self->bright < 0x1f) {
            NNS_G3dGlbMaterialColorDiffAmb(self->bright | (self->bright << 5) | (self->bright << 10), 0, FALSE);
            restore = TRUE;
        }
        NNS_G3dGlbPolygonAttr(1, 0, self->cull, polyId, self->alpha, 0x9000);
    }
    if (self->flushVP) {
        NNS_G3dGlbFlushVP();
    } else {
        NNS_G3dGlbFlushP();
    }
    info = self->mdl != NULL ? (MdlInfo021903b4 *)(self->mdl + 0x14) : NULL;
    if (self->boxTest) {
        G3_Scale(info->boxScale, info->boxScale, info->boxScale);
        NNS_G3dGeBufferOP_N(0x70, info->boxPos, 3);
        NNS_G3dGeFlushBuffer();
        while (G3X_GetBoxTestResult(&res) != 0) {
        }
        if (res != 0) {
            G3_Scale(info->boxInvScale, info->boxInvScale, info->boxInvScale);
            NNS_G3dDraw(self->renderObj);
            drawn = TRUE;
        }
    } else {
        NNS_G3dDraw(self->renderObj);
        drawn = TRUE;
    }
    if (self->clearInit) {
        NNS_G3dRenderObjSetInitFunc(self->renderObj, NULL);
    }
    if (restore) {
        NNSi_G3dModifyPolygonAttrMask(self->mdl, TRUE, 0xf);
        NNSi_G3dModifyPolygonAttrMask(self->mdl, TRUE, 0x30);
        if (self->restoreMat) {
            NNSi_G3dModifyMatFlag(self->mdl, TRUE, 0x40);
            NNSi_G3dModifyMatFlag(self->mdl, TRUE, 0x80);
            NNSi_G3dModifyMatFlag(self->mdl, TRUE, 0x200);
            NNSi_G3dModifyMatFlag(self->mdl, TRUE, 0x400);
        }
        func_02043578(data_02097d48 + 0x93c);
    }
    return drawn;
}

}
