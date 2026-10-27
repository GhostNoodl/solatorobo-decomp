// NNS_G2dMakeCellToOams: expands a cell's OAM attributes into an OAM buffer, applying an optional
// rotation/scale matrix and base translation to each OBJ.

#include "nnsys/g2d/g2d_Load.h"
#include "nnsys/g2d/g2d_OAM.h"
#include "nnsys/g2d/g2d_SRTControl.h"
#include "nitro/fx.h"

// OBJ height and width in pixels, [shape][size] (g2d_ObjSize_rodata.c).
extern const u16 data_02075614[3][4];
extern const u16 data_0207562c[3][4];

#define GX_OAM_EFFECT_AFFINE        0x0100
#define GX_OAM_EFFECT_AFFINE_DOUBLE 0x0300

// attr0 | (attr1 << 16), as the G2 OAM inlines read it.
#define OAM_ATTR01(oam) (*(u32 *)(oam))

// The attr0 shape and attr1 size bits.
typedef int GXOamShape;

static inline u32 G2_GetOBJEffect(const GXOamAttr *oam) {
    u32 attr = OAM_ATTR01(oam);
    u32 effect = attr & 0x300;
    if (effect != GX_OAM_EFFECT_AFFINE && effect != GX_OAM_EFFECT_AFFINE_DOUBLE) {
        effect |= attr & 0x30000000;
    }
    return effect;
}

static inline void G2_SetOBJEffect(GXOamAttr *oam, u32 effect, int rsParam) {
    if (effect != GX_OAM_EFFECT_AFFINE && effect != GX_OAM_EFFECT_AFFINE_DOUBLE) {
        OAM_ATTR01(oam) = (OAM_ATTR01(oam) & 0xc1fffcff) | effect;
    } else {
        OAM_ATTR01(oam) = (OAM_ATTR01(oam) & 0xc1fffcff) | effect | (rsParam << 25);
    }
}

static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y) {
    OAM_ATTR01(oam) = (OAM_ATTR01(oam) & 0xfe00ff00) | (y & 0xff) | ((x & 0x1ff) << 16);
}

static inline GXOamShape NNSi_G2dGetOamShape(const GXOamAttr *pOam) {
    return (GXOamShape)(OAM_ATTR01(pOam) & 0xc000c000);
}

static inline u16 NNSi_G2dGetOamSizeX(const GXOamShape *pShape) {
    return data_0207562c[(*pShape & 0xc000) >> 14][(*pShape & 0xc0000000) >> 30];
}

static inline u16 NNSi_G2dGetOamSizeY(const GXOamShape *pShape) {
    return data_02075614[(*pShape & 0xc000) >> 14][(*pShape & 0xc0000000) >> 30];
}

static inline void CopyCellAsOamAttr(const NNSG2dCellData *pCell, u16 idx, GXOamAttr *pDst) {
    const NNSG2dCellOAMAttrData *src = &pCell->pOamAttrArray[idx];
    pDst->attr0 = src->attr0;
    pDst->attr1 = src->attr1;
    pDst->attr2 = src->attr2;
}

// The OBJ position (9-bit x, 8-bit y, both signed) in fx32.
static inline void GetOamTransFx32(const GXOamAttr *pOam, NNSG2dFVec2 *pTrans) {
    s16 x = (s16)((OAM_ATTR01(pOam) & 0x01ff0000) >> 16);
    s16 y;
    if (x > 0xff) {
        x = (s16)(x | 0xff00);
    }
    pTrans->x = x << FX32_SHIFT;
    y = (s16)(OAM_ATTR01(pOam) & 0xff);
    if (y > 0x7f) {
        y = (s16)(y | 0xff00);
    }
    pTrans->y = y << FX32_SHIFT;
}

static inline void MulMtx22(const MtxFx22 *m, const NNSG2dFVec2 *v, NNSG2dFVec2 *out) {
    NNSG2dFVec2 tmp;
    NNSG2dFVec2 *p;
    p = out;
    if (v == out) {
        p = &tmp;
    }
    p->x = (fx32)(((fx64)m->_10 * v->y + 0x1000 + (fx64)m->_00 * v->x) >> FX32_SHIFT);
    p->y = (fx32)(((fx64)m->_11 * v->y + 0x1000 + (fx64)m->_01 * v->x) >> FX32_SHIFT);
    if (p == &tmp) {
        *out = tmp;
    }
}

u16 NNS_G2dMakeCellToOams(GXOamAttr *pDstOams, u16 numDstOam, const NNSG2dCellData *pCell, const MtxFx22 *pMtxSR,
                  const NNSG2dFVec2 *pBaseTrans, u16 affineIndex, BOOL bDoubleAffine) {
    u16 i;
    NNSG2dFVec2 objTrans;
    GXOamAttr *pDstOam;

    if (numDstOam >= pCell->numOAMAttrs) {
        numDstOam = pCell->numOAMAttrs;
    }
    for (i = 0; i < numDstOam; i++) {
        pDstOam = &pDstOams[i];
        CopyCellAsOamAttr(pCell, i, pDstOam);
        if (pMtxSR != NULL || pBaseTrans != NULL) {
            GetOamTransFx32(pDstOam, &objTrans);
            if (pMtxSR != NULL) {
                u32 effect;
                BOOL bDouble;

                // A double-size affine OBJ in the cell: move to its centre first.
                if (G2_GetOBJEffect(pDstOam) == GX_OAM_EFFECT_AFFINE_DOUBLE) {
                    GXOamShape shape = NNSi_G2dGetOamShape(pDstOam);
                    objTrans.x += NNSi_G2dGetOamSizeX(&shape) << (FX32_SHIFT - 1);
                    objTrans.y += NNSi_G2dGetOamSizeY(&shape) << (FX32_SHIFT - 1);
                }
                effect = bDoubleAffine ? GX_OAM_EFFECT_AFFINE_DOUBLE : GX_OAM_EFFECT_AFFINE;
                bDouble = effect == GX_OAM_EFFECT_AFFINE_DOUBLE;
                MulMtx22(pMtxSR, &objTrans, &objTrans);
                G2_SetOBJEffect(pDstOam, effect, affineIndex);

                // The OBJ rotates about its centre: add (M - I) * halfSize, and for a
                // double-size OBJ move back by another half size.
                {
                    GXOamShape shape = NNSi_G2dGetOamShape(pDstOam);
                    NNSG2dFVec2 half;
                    NNSG2dFVec2 off;
                    fx32 y;

                    half.x = NNSi_G2dGetOamSizeX(&shape) >> 1;
                    half.y = NNSi_G2dGetOamSizeY(&shape) >> 1;

                    off.x = half.x << FX32_SHIFT;
                    off.x = -off.x;
                    off.x = objTrans.x + (off.x + pMtxSR->_00 * half.x + pMtxSR->_10 * half.y);

                    off.y = half.y << FX32_SHIFT;
                    y = objTrans.y;
                    objTrans.x = off.x;
                    off.y = -off.y;
                    off.y = y + (off.y + pMtxSR->_01 * half.x + pMtxSR->_11 * half.y);
                    objTrans.y = off.y;

                    if (bDouble) {
                        objTrans.x -= half.x << FX32_SHIFT;
                        objTrans.y -= half.y << FX32_SHIFT;
                    }
                }
            }
            if (pBaseTrans != NULL) {
                objTrans.x += pBaseTrans->x;
                objTrans.y += pBaseTrans->y;
            }
            G2_SetOBJPosition(pDstOam, (objTrans.x + 0x800) >> FX32_SHIFT, (objTrans.y + 0x800) >> FX32_SHIFT);
        }
    }
    return numDstOam;
}
