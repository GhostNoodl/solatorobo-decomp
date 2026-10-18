#ifndef NITRO_GX_H
#define NITRO_GX_H

// GX definitions from the NitroSDK (gxcommon.h, g3.h, g3imm.h, g3x.h)
#include "types.h"
#include "nitro/fx.h"
#include "nitro/ioreg.h"

#ifndef SDK_ASSERT
#define SDK_ASSERT(x) ((void)0)
#endif
#ifndef SDK_MINMAX_ASSERT
#define SDK_MINMAX_ASSERT(x, lo, hi) ((void)0)
#endif
#ifndef SDK_NULL_ASSERT
#define SDK_NULL_ASSERT(x) ((void)0)
#endif

// ---- gxcommon.h ----
#define GX_DEFAULT_DMAID    (3)
#define GX_DMA_NOT_USE      ((u32) ~0)

#define GX_DMAID            (GXi_DmaId)

extern u32 GXi_DmaId;

typedef u16 GXRgb;

#define GXRGB_ASSERT(gxrgb)       SDK_ASSERT(((gxrgb) & 0x8000) == 0)
#define GX_RGB_R_SHIFT            (0)
#define GX_RGB_R_MASK             (0x001f)
#define GX_RGB_G_SHIFT            (5)
#define GX_RGB_G_MASK             (0x03e0)
#define GX_RGB_B_SHIFT            (10)
#define GX_RGB_B_MASK             (0x7c00)
#define GX_RGB(r, g, b)           ((GXRgb)(((r) << GX_RGB_R_SHIFT) | \
	                                       ((g) << GX_RGB_G_SHIFT) | \
	                                       ((b) << GX_RGB_B_SHIFT)))

typedef u16 GXRgba;

#define GX_RGBA_R_SHIFT           (0)
#define GX_RGBA_R_MASK            (0x001f)
#define GX_RGBA_G_SHIFT           (5)
#define GX_RGBA_G_MASK            (0x03e0)
#define GX_RGBA_B_SHIFT           (10)
#define GX_RGBA_B_MASK            (0x7c00)
#define GX_RGBA_A_SHIFT           (15)
#define GX_RGBA_A_MASK            (0x8000)
#define GX_RGBA(r, g, b, a)       ((GXRgba)(((r) << GX_RGBA_R_SHIFT) | \
	                                        ((g) << GX_RGBA_G_SHIFT) | \
	                                        ((b) << GX_RGBA_B_SHIFT) | \
	                                        ((a) << GX_RGBA_A_SHIFT)))

#define GX_POLYGONID_ASSERT(x)    SDK_ASSERT((x) >= 0 && (x) <= 63)
#define GX_ALPHA_ASSERT(x)        SDK_ASSERT((x) >= 0 && (x) <= 31)
#define GX_DEPTH_ASSERT(x)        SDK_ASSERT((x) >= 0 && (x) <= 0x7fff)

#define GX_VECFX10(x, y, z) \
	((VecFx10)(((((x) >> (FX32_DEC_SIZE - GX_FX10_DEC_SIZE)) & GX_FX10_MASK) << GX_VEC_FX10_X_SHIFT) | \
	           ((((y) >> (FX32_DEC_SIZE - GX_FX10_DEC_SIZE)) & GX_FX10_MASK) << GX_VEC_FX10_Y_SHIFT) | \
	           ((((z) >> (FX32_DEC_SIZE - GX_FX10_DEC_SIZE)) & GX_FX10_MASK) << GX_VEC_FX10_Z_SHIFT)))

typedef u32 VecFx10;

#define GX_FX10_SHIFT             9
#define GX_FX10_INT_SIZE          0
#define GX_FX10_DEC_SIZE          9

#define GX_FX10_INT_MASK          0x0000
#define GX_FX10_DEC_MASK          0x01ff
#define GX_FX10_SIGN_MASK         0x0200
#define GX_FX10_MASK              (GX_FX10_INT_MASK | GX_FX10_DEC_MASK | GX_FX10_SIGN_MASK)

#define GX_FX16_FX10_MAX          (fx16)(0x0fff)
#define GX_FX16_FX10_MIN          (fx16)(0xf000)

#define GX_FX32_FX10_MAX          (fx32)(0x00000fff);
#define GX_FX32_FX10_MIN          (fx32)(0xfffff000);

#define GX_VEC_FX10_X_SHIFT       0
#define GX_VEC_FX10_Y_SHIFT       10
#define GX_VEC_FX10_Z_SHIFT       20

// ---- g3.h ----
#define G3OP_NOP                0x00

#define G3OP_MTX_MODE           0x10
#define G3OP_MTX_PUSH           0x11
#define G3OP_MTX_POP            0x12
#define G3OP_MTX_STORE          0x13
#define G3OP_MTX_RESTORE        0x14
#define G3OP_MTX_IDENTITY       0x15
#define G3OP_MTX_LOAD_4x4       0x16
#define G3OP_MTX_LOAD_4x3       0x17
#define G3OP_MTX_MULT_4x4       0x18
#define G3OP_MTX_MULT_4x3       0x19
#define G3OP_MTX_MULT_3x3       0x1a
#define G3OP_MTX_SCALE          0x1b
#define G3OP_MTX_TRANS          0x1c

#define G3OP_COLOR              0x20
#define G3OP_NORMAL             0x21
#define G3OP_TEXCOORD           0x22
#define G3OP_VTX_16             0x23
#define G3OP_VTX_10             0x24
#define G3OP_VTX_XY             0x25
#define G3OP_VTX_XZ             0x26
#define G3OP_VTX_YZ             0x27
#define G3OP_VTX_DIFF           0x28
#define G3OP_POLYGON_ATTR       0x29
#define G3OP_TEXIMAGE_PARAM     0x2a
#define G3OP_TEXPLTT_BASE       0x2b

#define G3OP_DIF_AMB            0x30
#define G3OP_SPE_EMI            0x31
#define G3OP_LIGHT_VECTOR       0x32
#define G3OP_LIGHT_COLOR        0x33
#define G3OP_SHININESS          0x34

#define G3OP_BEGIN              0x40
#define G3OP_END                0x41

#define G3OP_SWAP_BUFFERS       0x50

#define G3OP_VIEWPORT           0x60

#define G3OP_BOX_TEST           0x70
#define G3OP_POS_TEST           0x71
#define G3OP_VEC_TEST           0x72

#define G3OP_DUMMY_COMMAND      0xFF

#define G3OP_NOP_NPARAMS                0

#define G3OP_MTX_MODE_NPARAMS           1
#define G3OP_MTX_PUSH_NPARAMS           0
#define G3OP_MTX_POP_NPARAMS            1
#define G3OP_MTX_STORE_NPARAMS          1
#define G3OP_MTX_RESTORE_NPARAMS        1
#define G3OP_MTX_IDENTITY_NPARAMS       0
#define G3OP_MTX_LOAD_4x4_NPARAMS       16
#define G3OP_MTX_LOAD_4x3_NPARAMS       12
#define G3OP_MTX_MULT_4x4_NPARAMS       16
#define G3OP_MTX_MULT_4x3_NPARAMS       12
#define G3OP_MTX_MULT_3x3_NPARAMS       9
#define G3OP_MTX_SCALE_NPARAMS          3
#define G3OP_MTX_TRANS_NPARAMS          3

#define G3OP_COLOR_NPARAMS              1
#define G3OP_NORMAL_NPARAMS             1
#define G3OP_TEXCOORD_NPARAMS           1
#define G3OP_VTX_16_NPARAMS             2
#define G3OP_VTX_10_NPARAMS             1
#define G3OP_VTX_XY_NPARAMS             1
#define G3OP_VTX_XZ_NPARAMS             1
#define G3OP_VTX_YZ_NPARAMS             1
#define G3OP_VTX_DIFF_NPARAMS           1
#define G3OP_POLYGON_ATTR_NPARAMS       1
#define G3OP_TEXIMAGE_PARAM_NPARAMS     1
#define G3OP_TEXPLTT_BASE_NPARAMS       1

#define G3OP_DIF_AMB_NPARAMS            1
#define G3OP_SPE_EMI_NPARAMS            1
#define G3OP_LIGHT_VECTOR_NPARAMS       1
#define G3OP_LIGHT_COLOR_NPARAMS        1
#define G3OP_SHININESS_NPARAMS          32

#define G3OP_BEGIN_NPARAMS              1
#define G3OP_END_NPARAMS                0

#define G3OP_SWAP_BUFFERS_NPARAMS       1

#define G3OP_VIEWPORT_NPARAMS           1

#define G3OP_BOX_TEST_NPARAMS           3
#define G3OP_POS_TEST_NPARAMS           2
#define G3OP_VEC_TEST_NPARAMS           1

#define GX_VALID_OPCODE_ASSERT(x)       SDK_ASSERT((x == 0xFF) || ((x >= 0) && (x <= 0x72)))

typedef enum {
	GX_MTXMODE_PROJECTION      = 0,
	GX_MTXMODE_POSITION        = 1,
	GX_MTXMODE_POSITION_VECTOR = 2,
	GX_MTXMODE_TEXTURE         = 3
} GXMtxMode;

#define GX_MTXMODE_ASSERT(x)                    \
	SDK_MINMAX_ASSERT(x, GX_MTXMODE_PROJECTION, GX_MTXMODE_TEXTURE)

#define GX_MTX_POP_NUM_ASSERT(x) SDK_MINMAX_ASSERT(x, -30, 31)

#define GX_MTX_STORE_NUM_ASSERT(x) SDK_MINMAX_ASSERT(x, 0, 30)

#define GX_MTX_RESTORE_NUM_ASSERT(x) SDK_MINMAX_ASSERT(x, 0, 30)

typedef enum {
	GX_BEGIN_TRIANGLES      = 0,
	GX_BEGIN_QUADS          = 1,
	GX_BEGIN_TRIANGLE_STRIP = 2,
	GX_BEGIN_QUAD_STRIP     = 3
} GXBegin;

#define GX_BEGIN_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_BEGIN_TRIANGLES, GX_BEGIN_QUAD_STRIP)

typedef enum {
	GX_SORTMODE_AUTO   = 0,
	GX_SORTMODE_MANUAL = 1
} GXSortMode;

#define GX_SORTMODE_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_SORTMODE_AUTO, GX_SORTMODE_MANUAL)

typedef enum {
	GX_BUFFERMODE_Z = 0,
	GX_BUFFERMODE_W = 1
} GXBufferMode;

#define GX_BUFFERMODE_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_BUFFERMODE_Z, GX_BUFFERMODE_W)

#define GX_VIEWPORT_ASSERT(x1, y1, x2, y2)     \
	SDK_ASSERT((x1) < (x2) && (y1) < (y2) &&   \
	           (x1) >= 0 && (x2) < 256 &&      \
	           (y1) >= 0 && (y2) < 192)

#define GX_POLYGON_ATTR_POLYGONID_ASSERT(x) GX_POLYGONID_ASSERT(x)
#define GX_POLYGON_ATTR_ALPHA_ASSERT(x) GX_ALPHA_ASSERT(x)

typedef enum {
	GX_LIGHTMASK_NONE    = 0,
	GX_LIGHTMASK_0       = 1,
	GX_LIGHTMASK_1       = 2,
	GX_LIGHTMASK_01      = 3,
	GX_LIGHTMASK_2       = 4,
	GX_LIGHTMASK_02      = 5,
	GX_LIGHTMASK_12      = 6,
	GX_LIGHTMASK_012     = 7,
	GX_LIGHTMASK_3       = 8,
	GX_LIGHTMASK_03      = 9,
	GX_LIGHTMASK_13      = 10,
	GX_LIGHTMASK_013     = 11,
	GX_LIGHTMASK_23      = 12,
	GX_LIGHTMASK_023     = 13,
	GX_LIGHTMASK_123     = 14,
	GX_LIGHTMASK_0123    = 15
} GXLightMask;

#define GX_LIGHTMASK_ASSERT(x) SDK_MINMAX_ASSERT(x, 0, 15)

typedef enum {
	GX_POLYGONMODE_MODULATE    = 0,
	GX_POLYGONMODE_DECAL       = 1,
	GX_POLYGONMODE_TOON        = 2,
	GX_POLYGONMODE_SHADOW      = 3
} GXPolygonMode;

#define GX_POLYGONMODE_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_POLYGONMODE_MODULATE, GX_POLYGONMODE_SHADOW)

typedef enum {
	GX_CULL_ALL      = 0,
	GX_CULL_FRONT    = 1,
	GX_CULL_BACK     = 2,
	GX_CULL_NONE     = 3
} GXCull;

#define GX_CULL_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_CULL_ALL, GX_CULL_NONE)

typedef enum {
	GX_POLYGON_ATTR_MISC_NONE                = 0,
	GX_POLYGON_ATTR_MISC_XLU_DEPTH_UPDATE    = 1 << REG_G3_POLYGON_ATTR_XL_SHIFT,
	GX_POLYGON_ATTR_MISC_FAR_CLIPPING        = 1 << REG_G3_POLYGON_ATTR_FC_SHIFT,
	GX_POLYGON_ATTR_MISC_DISP_1DOT           = 1 << REG_G3_POLYGON_ATTR_D1_SHIFT,
	GX_POLYGON_ATTR_MISC_DEPTHTEST_DECAL     = 1 << REG_G3_POLYGON_ATTR_DT_SHIFT,
	GX_POLYGON_ATTR_MISC_FOG                 = 1 << REG_G3_POLYGON_ATTR_FE_SHIFT
} GXPolygonAttrMisc;

typedef enum {
	GX_TEXREPEAT_NONE    = 0,
	GX_TEXREPEAT_S       = 1,
	GX_TEXREPEAT_T       = 2,
	GX_TEXREPEAT_ST      = 3
} GXTexRepeat;

#define GX_TEXREPEAT_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_TEXREPEAT_NONE, GX_TEXREPEAT_ST)

typedef enum {
	GX_TEXFLIP_NONE    = 0,
	GX_TEXFLIP_S       = 1,
	GX_TEXFLIP_T       = 2,
	GX_TEXFLIP_ST      = 3
} GXTexFlip;

#define GX_TEXFLIP_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_TEXFLIP_NONE, GX_TEXFLIP_ST)

typedef enum {
	GX_TEXSIZE_S8       = 0,
	GX_TEXSIZE_S16      = 1,
	GX_TEXSIZE_S32      = 2,
	GX_TEXSIZE_S64      = 3,
	GX_TEXSIZE_S128     = 4,
	GX_TEXSIZE_S256     = 5,
	GX_TEXSIZE_S512     = 6,
	GX_TEXSIZE_S1024    = 7
} GXTexSizeS;

#define GX_TEXSIZE_S_ASSERT(x)          \
	SDK_MINMAX_ASSERT(x, GX_TEXSIZE_S8, GX_TEXSIZE_S1024)

typedef enum {
	GX_TEXSIZE_T8       = 0,
	GX_TEXSIZE_T16      = 1,
	GX_TEXSIZE_T32      = 2,
	GX_TEXSIZE_T64      = 3,
	GX_TEXSIZE_T128     = 4,
	GX_TEXSIZE_T256     = 5,
	GX_TEXSIZE_T512     = 6,
	GX_TEXSIZE_T1024    = 7
} GXTexSizeT;

#define GX_TEXSIZE_T_ASSERT(x)          \
	SDK_MINMAX_ASSERT(x, GX_TEXSIZE_T8, GX_TEXSIZE_T1024)

typedef enum {
	GX_TEXFMT_NONE       = 0,
	GX_TEXFMT_A3I5       = 1,
	GX_TEXFMT_PLTT4      = 2,
	GX_TEXFMT_PLTT16     = 3,
	GX_TEXFMT_PLTT256    = 4,
	GX_TEXFMT_COMP4x4    = 5,
	GX_TEXFMT_A5I3       = 6,
	GX_TEXFMT_DIRECT     = 7
} GXTexFmt;

#define GX_TEXFMT_ALPHA ((GXTexFmt)GX_TEXFMT_A5I3)

#define GX_TEXFMT_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_TEXFMT_NONE, GX_TEXFMT_DIRECT)

typedef enum {
	GX_TEXPLTTCOLOR0_USE  = 0,
	GX_TEXPLTTCOLOR0_TRNS = 1
} GXTexPlttColor0;

#define GX_TEXPLTTCOLOR0_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_TEXPLTTCOLOR0_USE, GX_TEXPLTTCOLOR0_TRNS)

typedef enum {
	GX_TEXGEN_NONE        = 0,
	GX_TEXGEN_TEXCOORD    = 1,
	GX_TEXGEN_NORMAL      = 2,
	GX_TEXGEN_VERTEX      = 3
} GXTexGen;

#define GX_TEXGEN_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_TEXGEN_NONE, GX_TEXGEN_VERTEX)

#define GX_TEXIMAGE_PARAM_ADDR_ASSERT(addr)    \
	SDK_ASSERT(((addr) & 0x7) == 0 && (addr) >= 0 && (addr) < 0x80000)

typedef enum {
	GX_LIGHTID_0 = 0,
	GX_LIGHTID_1 = 1,
	GX_LIGHTID_2 = 2,
	GX_LIGHTID_3 = 3
} GXLightId;

#define GX_LIGHTID_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_LIGHTID_0, GX_LIGHTID_3)

#ifdef SDK_ADS
    typedef struct {
        u32 val[3];
    } GXBoxTestParam;
#else
    typedef union {
        u32 val[3];
        struct {
            fx16 x;
            fx16 y;
            fx16 z;
            fx16 width;
            fx16 height;
            fx16 depth;
        };
    } GXBoxTestParam;
#endif

typedef struct {
	u8 * curr_cmd;
	u32 * curr_param;
	u32 * bottom;
	u32 length;
	BOOL param0_cmd_flg;
} GXDLInfo;

typedef u32 GXSt;
typedef u32 GXTexPlttBaseParam;

#define GX_TEXPLTTBASEPARAM_ASSERT(x)     SDK_ASSERT((x) < 0xe000)

typedef u32 VecVtx10;

#define GX_VTX10_SHIFT                 6
#define GX_VTX10_INT_SIZE              3
#define GX_VTX10_DEC_SIZE              6

#define GX_VTX10_INT_MASK              0x01c0
#define GX_VTX10_DEC_MASK              0x003f
#define GX_VTX10_SIGN_MASK             0x0200
#define GX_VTX10_MASK                  (GX_VTX10_INT_MASK | GX_VTX10_DEC_MASK | GX_VTX10_SIGN_MASK)

#define GX_VTX10_MAX                   ((fx32)(0x00007fc0))
#define GX_VTX10_MIN                   ((fx32)(0xffff8000))

#define GX_VEC_VTX10_X_SHIFT           0
#define GX_VEC_VTX10_Y_SHIFT           10
#define GX_VEC_VTX10_Z_SHIFT           20

#define GX_FX16PAIR(a, b)              ((u32)((u32)(u16)(a) | ((u32)(u16)(b) << 16)))

#define GX_VECVTX10(x, y, z) \
	((VecVtx10) (((((x) >> (FX32_DEC_SIZE - GX_VTX10_DEC_SIZE)) & GX_VTX10_MASK) << GX_VEC_VTX10_X_SHIFT) | \
	             ((((y) >> (FX32_DEC_SIZE - GX_VTX10_DEC_SIZE)) & GX_VTX10_MASK) << GX_VEC_VTX10_Y_SHIFT) | \
	             ((((z) >> (FX32_DEC_SIZE - GX_VTX10_DEC_SIZE)) & GX_VTX10_MASK) << GX_VEC_VTX10_Z_SHIFT)))

typedef u32 VecVtxDiff;

#define GX_VTXDIFF_MASK                0x03ff

#define GX_VTXDIFF_MAX                 ((fx32)(0x000001ff))
#define GX_VTXDIFF_MIN                 ((fx32)(0xfffffe00))

#define GX_VEC_VTXDIFF_X_SHIFT         0
#define GX_VEC_VTXDIFF_Y_SHIFT         10
#define GX_VEC_VTXDIFF_Z_SHIFT         20

#define GX_VECVTXDIFF(x, y, z) \
	((VecVtxDiff) ((((x) & GX_VTXDIFF_MASK) << GX_VEC_VTXDIFF_X_SHIFT) | \
	               (((y) & GX_VTXDIFF_MASK) << GX_VEC_VTXDIFF_Y_SHIFT) | \
	               (((z) & GX_VTXDIFF_MASK) << GX_VEC_VTXDIFF_Z_SHIFT)))

#define GX_FX16ST(x)                   ((s16)((x) >> 8))

#define GX_ST(s, t)                    ((GXSt)((u16)GX_FX16ST(s) | ((u16)GX_FX16ST(t) << 16)))

#define GX_COMP4x4_PLTT_IDX(image)                                                      \
	((u32)(0x20000 + (((image) & 0x1ffff) >> 1) + (((image) & 0x40000) >> 2)))

#define GX_PACK_OP(op1, op2, op3, op4)                                                  \
	((u32)((op1) | ((op2) << 8) | ((op3) << 16) | ((op4) << 24)))

#define GX_PACK_SWAPBUFFERS_PARAM(am, zw)                                               \
	((u32) (((am) << REG_G3_SWAP_BUFFERS_XS_SHIFT) |                                    \
	        ((zw) << REG_G3_SWAP_BUFFERS_DP_SHIFT)))

#define GX_PACK_MTXMODE_PARAM(mode)    ((u32) ((mode) << REG_G3_MTX_MODE_M_SHIFT))
#define GX_PACK_POPMTX_PARAM(num)      ((u32) (num))
#define GX_PACK_STOREMTX_PARAM(num)    ((u32) (num))
#define GX_PACK_RESTOREMTX_PARAM(num)  ((u32) (num))

#define GX_PACK_LIGHTVECTOR_PARAM(lightID, x, y, z)                                     \
	((u32)GX_VECFX10((x), (y), (z)) |                                                   \
	 ((u32)(lightID) << REG_G3_LIGHT_VECTOR_LNUM_SHIFT))

#define GX_PACK_LIGHTCOLOR_PARAM(lightID, rgb)                                          \
	((u32)((rgb) |                                                                      \
	       ((u32)(lightID) << REG_G3_LIGHT_COLOR_LNUM_SHIFT)))

#define GX_PACK_DIFFAMB_PARAM(diffuse, ambient, IsSetVtxColor)                          \
	((u32)((diffuse) |                                                                  \
	       ((ambient) << REG_G3_DIF_AMB_AMBIENT_RED_SHIFT) |                            \
	       (((IsSetVtxColor) != FALSE) << REG_G3_DIF_AMB_C_SHIFT)))

#define GX_PACK_SPECEMI_PARAM(specular, emission, IsShininess)                          \
	((u32)((specular) |                                                                 \
	       ((emission) << REG_G3_SPE_EMI_EMISSION_RED_SHIFT) |                          \
	       (((IsShininess) != FALSE) << REG_G3_SPE_EMI_S_SHIFT)))

#define GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc)    \
	((u32)(((light) << REG_G3_POLYGON_ATTR_LE_SHIFT) |                                  \
	       ((polyMode) << REG_G3_POLYGON_ATTR_PM_SHIFT) |                               \
	       ((cullMode) << REG_G3_POLYGON_ATTR_BK_SHIFT) |                               \
	       (misc) |                                                                     \
	       ((polygonID) << REG_G3_POLYGON_ATTR_ID_SHIFT) |                              \
	       ((alpha) << REG_G3_POLYGON_ATTR_ALPHA_SHIFT)))

#define GX_PACK_BEGIN_PARAM(primitive)                                                  \
	((u32)((primitive) << REG_G3_BEGIN_VTXS_TYPE_SHIFT))

#define GX_PACK_COLOR_PARAM(rgb)          ((u32)(rgb))
#define GX_PACK_NORMAL_PARAM(x, y, z)     ((u32)GX_VECFX10((x), (y), (z)))
#define GX_PACK_VTX10_PARAM(x, y, z)      ((u32)GX_VECVTX10((x), (y), (z)))
#define GX_PACK_VTXXY_PARAM(x, y)         (GX_FX16PAIR((x), (y)))
#define GX_PACK_VTXXZ_PARAM(x, z)         (GX_FX16PAIR((x), (z)))
#define GX_PACK_VTXYZ_PARAM(y, z)         (GX_FX16PAIR((y), (z)))
#define GX_PACK_VTXDIFF_PARAM(x, y, z)    (GX_VECVTXDIFF((x), (y), (z)))
#define GX_PACK_TEXCOORD_PARAM(s, t)      (GX_ST((s), (t)))

#define GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr)         \
	((u32)(((addr) >> 3) |                                                              \
	       ((texFmt) << REG_G3_TEXIMAGE_PARAM_TEXFMT_SHIFT) |                           \
	       ((texGen) << REG_G3_TEXIMAGE_PARAM_TGEN_SHIFT) |                             \
	       ((s) << REG_G3_TEXIMAGE_PARAM_V_SIZE_SHIFT) |                                \
	       ((t) << REG_G3_TEXIMAGE_PARAM_T_SIZE_SHIFT) |                                \
	       ((repeat) << REG_G3_TEXIMAGE_PARAM_RS_SHIFT) |                               \
	       ((flip) << REG_G3_TEXIMAGE_PARAM_FS_SHIFT) |                                 \
	       ((pltt0) << REG_G3_TEXIMAGE_PARAM_TR_SHIFT)))

#define GX_PACK_TEXPLTTBASE_PARAM(addr, texFmt)                                         \
	((u32)((addr) >> (4 - ((texFmt) == GX_TEXFMT_PLTT4))))

#define GX_PACK_VIEWPORT_PARAM(x1, y1, x2, y2)                                          \
	((u32)((x1) | ((y1) << 8) | ((x2) << 16) | ((y2) << 24)))

#define GX_PACK_VECTORTEST_PARAM(x, y, z) ((u32)GX_VECFX10((x), (y), (z)))

#if 1
    void G3_BeginMakeDL(GXDLInfo * info, void * ptr, u32 length);
    u32 G3_EndMakeDL(GXDLInfo * info);
    static void * G3_GetDLStart(const GXDLInfo * info);
    static u32 G3_GetDLLength(const GXDLInfo * info);
    static u32 G3_GetDLSize(const GXDLInfo * info);

    static GXTexPlttBaseParam G3_MakeTexPlttBaseParam(u32 plttBaseAddr, GXTexFmt texfmt);

    static inline void * G3_GetDLStart (const GXDLInfo * info)
    {
        return (void *)info->bottom;
    }

    static inline u32 G3_GetDLLength (const GXDLInfo * info)
    {
        return info->length;
    }

    static inline u32 G3_GetDLSize (const GXDLInfo * info)
    {
        SDK_ASSERT((u32)info->bottom < (u32)info->curr_param);
        if ((u32)info->curr_cmd & 3) {
            return (u32)((u32)info->curr_param - (u32)info->bottom);
        } else {
            return (u32)((u32)info->curr_cmd - (u32)info->bottom);
        }
    }

    static inline GXTexPlttBaseParam G3_MakeTexPlttBaseParam (u32 plttBaseAddr, GXTexFmt texfmt)
    {
        SDK_ASSERT(GX_TEXFMT_NONE != texfmt);

        if (GX_TEXFMT_PLTT4 == texfmt) {

            SDK_ASSERT((plttBaseAddr & 0x7) == 0);
            return (GXTexPlttBaseParam)(plttBaseAddr >> 3);
        } else {

            SDK_ASSERT((plttBaseAddr & 0xf) == 0);
            return (GXTexPlttBaseParam)(plttBaseAddr >> 4);
        }
    }
#endif

// ---- g3imm.h ----
static void G3_Direct0(int op);
static void G3_Direct1(int op, u32 param0);
static void G3_Direct2(int op, u32 param0, u32 param1);
static void G3_Direct3(int op, u32 param0, u32 param1, u32 param2);

static void G3_MtxMode(GXMtxMode mode);
static void G3_PushMtx(void);
static void G3_PopMtx(int num);
static void G3_StoreMtx(int num);
static void G3_RestoreMtx(int num);
static void G3_Identity(void);

void G3_LoadMtx44(const MtxFx44 * m);
void G3_LoadMtx43(const MtxFx43 * m);
void G3_MultMtx44(const MtxFx44 * m);
void G3_MultMtx43(const MtxFx43 * m);
void G3_MultMtx33(const MtxFx33 * m);
void G3_MultTransMtx33(const MtxFx33 * mtx, const VecFx32 * trans);

static void G3_Scale(fx32 x, fx32 y, fx32 z);
static void G3_Translate(fx32 x, fx32 y, fx32 z);
static void G3_Color(GXRgb rgb);
static void G3_Normal(fx16 x, fx16 y, fx16 z);
static void G3_TexCoord(fx32 s, fx32 t);
static void G3_Vtx(fx16 x, fx16 y, fx16 z);
static void G3_Vtx10(fx16 x, fx16 y, fx16 z);
static void G3_VtxXY(fx16 x, fx16 y);
static void G3_VtxXZ(fx16 x, fx16 z);
static void G3_VtxYZ(fx16 y, fx16 z);
static void G3_VtxDiff(fx16 x, fx16 y, fx16 z);
static void G3_PolygonAttr(int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc);
static void G3_TexImageParam(GXTexFmt texFmt,
                             GXTexGen texGen,
                             GXTexSizeS s,
                             GXTexSizeT t,
                             GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr);

static void G3_TexPlttBase(u32 addr, GXTexFmt texfmt);
static void G3_MaterialColorDiffAmb(GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor);
static void G3_MaterialColorSpecEmi(GXRgb specular, GXRgb emission, BOOL IsShininess);
static void G3_LightVector(GXLightId lightID, fx16 x, fx16 y, fx16 z);
static void G3_LightColor(GXLightId lightID, GXRgb rgb);
void G3_Shininess(const u32 * table);
static void G3_Begin(GXBegin primitive);
static void G3_End(void);
static void G3_SwapBuffers(GXSortMode am, GXBufferMode zw);
static void G3_ViewPort(int x1, int y1, int x2, int y2);
static void G3_BoxTest(const GXBoxTestParam * box);
static void G3_PositionTest(fx16 x, fx16 y, fx16 z);
static void G3_VectorTest(fx16 x, fx16 y, fx16 z);

static inline void G3_Direct0 (int op)
{
	*(REGType32v *)(REG_MTX_MODE_ADDR + ((op - G3OP_MTX_MODE) * 4)) = 0;
}

static inline void G3_Direct1 (int op, u32 param0)
{
	*(REGType32v *)(REG_MTX_MODE_ADDR + ((op - G3OP_MTX_MODE) * 4)) = param0;
}

static inline void G3_Direct2 (int op, u32 param0, u32 param1)
{
	*(REGType32v *)(REG_MTX_MODE_ADDR + ((op - G3OP_MTX_MODE) * 4)) = param0;
	*(REGType32v *)(REG_MTX_MODE_ADDR + ((op - G3OP_MTX_MODE) * 4)) = param1;
}

static inline void G3_Direct3 (int op, u32 param0, u32 param1, u32 param2)
{
	*(REGType32v *)(REG_MTX_MODE_ADDR + ((op - G3OP_MTX_MODE) * 4)) = param0;
	*(REGType32v *)(REG_MTX_MODE_ADDR + ((op - G3OP_MTX_MODE) * 4)) = param1;
	*(REGType32v *)(REG_MTX_MODE_ADDR + ((op - G3OP_MTX_MODE) * 4)) = param2;
}

static inline void G3_MtxMode (GXMtxMode mode)
{
	GX_MTXMODE_ASSERT(mode);
	reg_G3_MTX_MODE = GX_PACK_MTXMODE_PARAM(mode);
}

static inline void G3_PushMtx ()
{
	reg_G3_MTX_PUSH = 0;
}

static inline void G3_PopMtx (int num)
{
	GX_MTX_POP_NUM_ASSERT(num);
	reg_G3_MTX_POP = GX_PACK_POPMTX_PARAM(num);
}

static inline void G3_StoreMtx (int num)
{
	GX_MTX_STORE_NUM_ASSERT(num);
	reg_G3_MTX_STORE = GX_PACK_STOREMTX_PARAM(num);
}

static inline void G3_RestoreMtx (int num)
{
	GX_MTX_RESTORE_NUM_ASSERT(num);
	reg_G3_MTX_RESTORE = GX_PACK_RESTOREMTX_PARAM(num);
}

static inline void G3_Identity ()
{
	reg_G3_MTX_IDENTITY = 0;
}

static inline void G3_Scale (fx32 x, fx32 y, fx32 z)
{
	reg_G3_MTX_SCALE = (u32)x;
	reg_G3_MTX_SCALE = (u32)y;
	reg_G3_MTX_SCALE = (u32)z;
}

static inline void G3_Translate (fx32 x, fx32 y, fx32 z)
{
	reg_G3_MTX_TRANS = (u32)x;
	reg_G3_MTX_TRANS = (u32)y;
	reg_G3_MTX_TRANS = (u32)z;
}

static inline void G3_Color (GXRgb rgb)
{
	GXRGB_ASSERT(rgb);
	reg_G3_COLOR = GX_PACK_COLOR_PARAM(rgb);
}

static inline void G3_Normal (fx16 x, fx16 y, fx16 z)
{
	SDK_MINMAX_ASSERT(x, -FX16_ONE, FX16_ONE - 1);
	SDK_MINMAX_ASSERT(y, -FX16_ONE, FX16_ONE - 1);
	SDK_MINMAX_ASSERT(z, -FX16_ONE, FX16_ONE - 1);

	reg_G3_NORMAL = GX_PACK_NORMAL_PARAM(x, y, z);
}

static inline void G3_TexCoord (fx32 s, fx32 t)
{
	SDK_MINMAX_ASSERT(s, -2048 * FX32_ONE, 2048 * FX32_ONE - 1);
	SDK_MINMAX_ASSERT(t, -2048 * FX32_ONE, 2048 * FX32_ONE - 1);

	reg_G3_TEXCOORD = GX_PACK_TEXCOORD_PARAM(s, t);
}

static inline void G3_Vtx (fx16 x, fx16 y, fx16 z)
{
	reg_G3_VTX_16 = GX_FX16PAIR(x, y);
	reg_G3_VTX_16 = (u32)(u16)z;
}

static inline void G3_Vtx10 (fx16 x, fx16 y, fx16 z)
{
	reg_G3_VTX_10 = GX_PACK_VTX10_PARAM(x, y, z);
}

static inline void G3_VtxXY (fx16 x, fx16 y)
{
	reg_G3_VTX_XY = GX_PACK_VTXXY_PARAM(x, y);
}

static inline void G3_VtxXZ (fx16 x, fx16 z)
{
	reg_G3_VTX_XZ = GX_PACK_VTXXZ_PARAM(x, z);
}

static inline void G3_VtxYZ (fx16 y, fx16 z)
{
	reg_G3_VTX_YZ = GX_PACK_VTXYZ_PARAM(y, z);
}

static inline void G3_VtxDiff (fx16 x, fx16 y, fx16 z)
{
	SDK_MINMAX_ASSERT(x, (fx16)0xfe00, (fx16)0x1ff);
	SDK_MINMAX_ASSERT(y, (fx16)0xfe00, (fx16)0x1ff);
	SDK_MINMAX_ASSERT(z, (fx16)0xfe00, (fx16)0x1ff);

	reg_G3_VTX_DIFF = GX_PACK_VTXDIFF_PARAM(x, y, z);
}

static inline void G3_PolygonAttr (int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc
                                   )
{
	GX_LIGHTMASK_ASSERT(light);
	GX_POLYGONMODE_ASSERT(polyMode);
	GX_CULL_ASSERT(cullMode);
	GX_POLYGON_ATTR_POLYGONID_ASSERT(polygonID);
	GX_POLYGON_ATTR_ALPHA_ASSERT(alpha);

	reg_G3_POLYGON_ATTR = GX_PACK_POLYGONATTR_PARAM(light,
	                                                polyMode, cullMode, polygonID, alpha, misc);
}

static inline void G3_TexImageParam (GXTexFmt texFmt,
                                     GXTexGen texGen,
                                     GXTexSizeS s,
                                     GXTexSizeT t,
                                     GXTexRepeat repeat,
                                     GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
	GX_TEXREPEAT_ASSERT(repeat);
	GX_TEXFLIP_ASSERT(flip);
	GX_TEXSIZE_S_ASSERT(s);
	GX_TEXSIZE_T_ASSERT(t);
	GX_TEXFMT_ASSERT(texFmt);
	GX_TEXPLTTCOLOR0_ASSERT(pltt0);
	GX_TEXGEN_ASSERT(texGen);
	GX_TEXIMAGE_PARAM_ADDR_ASSERT(addr);

	reg_G3_TEXIMAGE_PARAM = GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr);
}

static inline void G3_TexPlttBase (u32 addr, GXTexFmt texfmt)
{
	u32 param = GX_PACK_TEXPLTTBASE_PARAM(addr, texfmt);
	GX_TEXPLTTBASEPARAM_ASSERT(param);

	reg_G3_TEXPLTT_BASE = param;
}

static inline void G3_MaterialColorDiffAmb (GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor)
{
	GXRGB_ASSERT(diffuse);
	GXRGB_ASSERT(ambient);

	reg_G3_DIF_AMB = GX_PACK_DIFFAMB_PARAM(diffuse, ambient, IsSetVtxColor);
}

static inline void G3_MaterialColorSpecEmi (GXRgb specular, GXRgb emission, BOOL IsShininess)
{
	GXRGB_ASSERT(specular);
	GXRGB_ASSERT(emission);

	reg_G3_SPE_EMI = GX_PACK_SPECEMI_PARAM(specular, emission, IsShininess);
}

static inline void G3_LightVector (GXLightId lightID, fx16 x, fx16 y, fx16 z)
{
	GX_LIGHTID_ASSERT(lightID);
	SDK_MINMAX_ASSERT(x, -FX16_ONE, FX16_ONE - 1);
	SDK_MINMAX_ASSERT(y, -FX16_ONE, FX16_ONE - 1);
	SDK_MINMAX_ASSERT(z, -FX16_ONE, FX16_ONE - 1);

	reg_G3_LIGHT_VECTOR = GX_PACK_LIGHTVECTOR_PARAM(lightID, x, y, z);
}

static inline void G3_LightColor (GXLightId lightID, GXRgb rgb)
{
	GX_LIGHTID_ASSERT(lightID);
	GXRGB_ASSERT(rgb);

	reg_G3_LIGHT_COLOR = GX_PACK_LIGHTCOLOR_PARAM(lightID, rgb);
}

static inline void G3_Begin (GXBegin primitive)
{
	GX_BEGIN_ASSERT(primitive);
	reg_G3_BEGIN_VTXS = GX_PACK_BEGIN_PARAM(primitive);
}

static inline void G3_End (void)
{
	reg_G3_END_VTXS = 0;
}

static inline void G3_SwapBuffers (GXSortMode am, GXBufferMode zw)
{
	GX_SORTMODE_ASSERT(am);
	GX_BUFFERMODE_ASSERT(zw);

	reg_G3_SWAP_BUFFERS = GX_PACK_SWAPBUFFERS_PARAM(am, zw);
}

static inline void G3_ViewPort (int x1, int y1, int x2, int y2)
{
	GX_VIEWPORT_ASSERT(x1, y1, x2, y2);
	reg_G3_VIEWPORT = GX_PACK_VIEWPORT_PARAM(x1, y1, x2, y2);
}

static inline void G3_BoxTest (const GXBoxTestParam * box)
{
	reg_G3_BOX_TEST = box->val[0];
	reg_G3_BOX_TEST = box->val[1];
	reg_G3_BOX_TEST = box->val[2];
}

static inline void G3_PositionTest (fx16 x, fx16 y, fx16 z)
{
	reg_G3_POS_TEST = GX_FX16PAIR(x, y);
	reg_G3_POS_TEST = (u32)(u16)z;
}

static inline void G3_VectorTest (fx16 x, fx16 y, fx16 z)
{
	SDK_MINMAX_ASSERT(x, -FX16_ONE, FX16_ONE - 1);
	SDK_MINMAX_ASSERT(y, -FX16_ONE, FX16_ONE - 1);
	SDK_MINMAX_ASSERT(z, -FX16_ONE, FX16_ONE - 1);

	reg_G3_VEC_TEST = GX_PACK_VECTORTEST_PARAM(x, y, z);
}

// ---- g3x.h ----
typedef enum {
	GX_SHADING_TOON = 0,
	GX_SHADING_HIGHLIGHT = 1
} GXShading;

#define GX_SHADING_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_SHADING_TOON, GX_SHADING_HIGHLIGHT)

typedef enum {
	GX_FOGBLEND_COLOR_ALPHA = 0,
	GX_FOGBLEND_ALPHA = 1
} GXFogBlend;

#define GX_FOGBLEND_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_FOGBLEND_COLOR_ALPHA, GX_FOGBLEND_ALPHA)

typedef enum {
	GX_FOGSLOPE_0x8000 = 0,
	GX_FOGSLOPE_0x4000 = 1,
	GX_FOGSLOPE_0x2000 = 2,
	GX_FOGSLOPE_0x1000 = 3,
	GX_FOGSLOPE_0x0800 = 4,
	GX_FOGSLOPE_0x0400 = 5,
	GX_FOGSLOPE_0x0200 = 6,
	GX_FOGSLOPE_0x0100 = 7,
	GX_FOGSLOPE_0x0080 = 8,
	GX_FOGSLOPE_0x0040 = 9,
	GX_FOGSLOPE_0x0020 = 10
} GXFogSlope;

#define GX_FOGSLOPE_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_FOGSLOPE_0x8000, GX_FOGSLOPE_0x0020)

typedef enum {
	GX_FIFOINTR_COND_DISABLE      = 0,
	GX_FIFOINTR_COND_UNDERHALF    = 1,
	GX_FIFOINTR_COND_EMPTY        = 2
} GXFifoIntrCond;

#define GX_FIFOINTR_COND_ASSERT(x)    \
	SDK_MINMAX_ASSERT(x, GX_FIFOINTR_COND_DISABLE, GX_FIFOINTR_COND_EMPTY)

typedef enum {
	GX_FIFOSTAT_EMPTY        = 6,
	GX_FIFOSTAT_UNDERHALF    = 2,
	GX_FIFOSTAT_OVERHALF     = 0,
	GX_FIFOSTAT_FULL         = 1
} GXFifoStat;

#define GX_RDLINES_COUNT_MAX   46
#define GX_LISTRAM_COUNT_MAX   2048
#define GX_VTXRAM_COUNT_MAX    6144

#if 1
void G3X_Init(void);
void G3X_InitMtxStack(void);
void G3X_ResetMtxStack(void);
void G3X_InitTable(void);
void G3X_Reset(void);

static void G3X_SetShading(GXShading shading);
static void G3X_AlphaTest(BOOL enable, int ref);
static void G3X_AlphaBlend(BOOL enable);
static void G3X_AntiAlias(BOOL enable);
static void G3X_EdgeMarking(BOOL enable);

void G3X_SetFog(BOOL enable, GXFogBlend fogMode, GXFogSlope fogSlope, int fogOffset);

int G3X_GetMtxStackLevelPV(s32 * level);
int G3X_GetMtxStackLevelPJ(s32 * level);

static void G3X_SetFifoIntrCond(GXFifoIntrCond cond);

void G3X_SetDisp1DotDepth(fx32 w);

int G3X_GetBoxTestResult(s32 * in);
int G3X_GetPositionTestResult(VecFx32 * vec, fx32 * w);
int G3X_GetVectorTestResult(fx16 * vec);

int G3X_GetClipMtx(MtxFx44 * m);
int G3X_GetVectorMtx(MtxFx33 * m);

void G3X_SetHOffset(int hOffset);

void G3X_SetEdgeColorTable(const GXRgb * rgb_8);
void G3X_SetFogTable(const u32 * fogTable);
void G3X_SetToonTable(const GXRgb * rgb_32);
void G3X_SetClearColor(GXRgb rgb, int alpha, int depth, int polygonID, BOOL fog);
static void G3X_SetClearImageOffset(int xOffset, int yOffset);
static void G3X_SetFogColor(GXRgb rgb, int alpha);

static s32 G3X_IsMtxStackOverflow(s32 * overflow);
static s32 G3X_IsLineBufferUnderflow(void);
static s32 G3X_IsListRamOverflow(void);
static s32 G3X_IsGeometryBusy(void);

static void G3X_ResetMtxStackOverflow(void);
static void G3X_ResetLineBufferUnderflow(void);
static void G3X_ResetListRamOverflow(void);
void G3X_ClearFifo(void);

static s32 G3X_GetPolygonListRamCount(void);
static s32 G3X_GetVtxListRamCount(void);
static s32 G3X_GetRenderedLineCount(void);
static s32 G3X_GetCommandFifoCount(void);
static GXFifoStat G3X_GetCommandFifoStatus(void);

static inline void G3X_SetShading (GXShading shading)
{
	reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_THS_MASK |
	                                                 REG_G3X_DISP3DCNT_RO_MASK |
	                                                 REG_G3X_DISP3DCNT_GO_MASK)) |
	                          (shading << REG_G3X_DISP3DCNT_THS_SHIFT));
}

static inline void G3X_AlphaTest (BOOL enable, int ref)
{
	if (enable) {
		GX_ALPHA_ASSERT(ref);
		reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
		                          ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
		                          REG_G3X_DISP3DCNT_ATE_MASK);
		reg_G3X_ALPHA_TEST_REF = (u16)ref;
	} else {
		reg_G3X_DISP3DCNT &= (u16) ~(REG_G3X_DISP3DCNT_ATE_MASK |
		                             REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
	}
}

static inline void G3X_AlphaBlend (BOOL enable)
{
	if (enable) {
		reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
		                          ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
		                          REG_G3X_DISP3DCNT_ABE_MASK);
	} else {
		reg_G3X_DISP3DCNT &= (u16) ~(REG_G3X_DISP3DCNT_ABE_MASK |
		                             REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
	}
}

static inline void G3X_AntiAlias (BOOL enable)
{
	if (enable) {
		reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
		                          ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
		                          REG_G3X_DISP3DCNT_AAE_MASK);
	} else {
		reg_G3X_DISP3DCNT &= (u16) ~(REG_G3X_DISP3DCNT_AAE_MASK |
		                             REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
	}
}

static inline void G3X_EdgeMarking (BOOL enable)
{
	if (enable) {
		reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
		                          ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
		                          REG_G3X_DISP3DCNT_EME_MASK);
	} else {
		reg_G3X_DISP3DCNT &= (u16) ~(REG_G3X_DISP3DCNT_EME_MASK |
		                             REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
	}
}

static inline void G3X_SetFifoIntrCond (GXFifoIntrCond cond)
{
	GX_FIFOINTR_COND_ASSERT(cond);

	reg_G3X_GXSTAT = ((reg_G3X_GXSTAT & ~REG_G3X_GXSTAT_FI_MASK) |
	                  (cond << REG_G3X_GXSTAT_FI_SHIFT));
}

static inline void G3X_SetClearImageOffset (int xOffset, int yOffset)
{
	reg_G3X_CLRIMAGE_OFFSET = (u16)(((xOffset << REG_G3X_CLRIMAGE_OFFSET_OFFSETX_SHIFT) &
	                                 REG_G3X_CLRIMAGE_OFFSET_OFFSETX_MASK) | ((yOffset <<
	                                                                           REG_G3X_CLRIMAGE_OFFSET_OFFSETY_SHIFT)
	                                                                          &
	                                                                          REG_G3X_CLRIMAGE_OFFSET_OFFSETY_MASK));
}

static inline void G3X_SetFogColor (GXRgb rgb, int alpha)
{
	GXRGB_ASSERT(rgb);
	GX_ALPHA_ASSERT(alpha);

	reg_G3X_FOG_COLOR = (u32)((rgb << REG_G3X_FOG_COLOR_FOG_RED_SHIFT) |
	                          (alpha << REG_G3X_FOG_COLOR_FOG_ALPHA_SHIFT));
}

static inline s32 G3X_IsMtxStackOverflow (s32 * overflow)
{
	SDK_NULL_ASSERT(overflow);
	if (reg_G3X_GXSTAT & REG_G3X_GXSTAT_SB_MASK) {
		return -1;
	}

	*overflow = (s32)(reg_G3X_GXSTAT & REG_G3X_GXSTAT_SE_MASK);
	return 0;
}

#define G3X_IsLineBufferOverflow    G3X_IsLineBufferUnderflow

static inline s32 G3X_IsLineBufferUnderflow (void)
{
	return (reg_G3X_DISP3DCNT & REG_G3X_DISP3DCNT_RO_MASK);
}

static inline s32 G3X_IsListRamOverflow (void)
{
	return (reg_G3X_DISP3DCNT & REG_G3X_DISP3DCNT_GO_MASK);
}

static inline s32 G3X_IsGeometryBusy (void)
{
	return (s32)(reg_G3X_GXSTAT & REG_G3X_GXSTAT_B_MASK);
}

static inline void G3X_ResetMtxStackOverflow (void)
{
	reg_G3X_GXSTAT |= REG_G3X_GXSTAT_SE_MASK;
}

#define G3X_ResetLineBufferOverflow    G3X_ResetLineBufferUnderflow

static inline void G3X_ResetLineBufferUnderflow (void)
{
	reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_RO_MASK;
}

static inline void G3X_ResetListRamOverflow (void)
{
	reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_GO_MASK;
}

static inline s32 G3X_GetPolygonListRamCount (void)
{
	return reg_G3X_LISTRAM_COUNT;
}

static inline s32 G3X_GetVtxListRamCount (void)
{
	return reg_G3X_VTXRAM_COUNT;
}

static inline s32 G3X_GetRenderedLineCount (void)
{
	return reg_G3X_RDLINES_COUNT;
}

static inline s32 G3X_GetCommandFifoCount (void)
{
	return (s32)((reg_G3X_GXSTAT & REG_G3X_GXSTAT_FIFOCNT_MASK) >> REG_G3X_GXSTAT_FIFOCNT_SHIFT);
}

static inline GXFifoStat G3X_GetCommandFifoStatus (void)
{
	return (GXFifoStat)((reg_G3X_GXSTAT & (REG_G3X_GXSTAT_F_MASK |
	                                       REG_G3X_GXSTAT_H_MASK |
	                                       REG_G3X_GXSTAT_E_MASK)) >> REG_G3X_GXSTAT_F_SHIFT);
}

#endif

#endif
