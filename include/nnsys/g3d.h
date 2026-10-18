#ifndef NNSYS_G3D_H
#define NNSYS_G3D_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/gx.h"
#include "nitro/mi.h"
#include "nnsys/gfd.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem G3D: 3D model resources (nsbmd/nsbtx/animations), render objects and the SBC interpreter.

#define NNS_G3D_ANMFMT_MAX 10
#define NNS_G3D_SIZE_JNT_MAX 64
#define NNS_G3D_SIZE_MAT_MAX 64
#define NNS_G3D_SIZE_SHP_MAX 64
#define NNS_G3D_SIZE_COMBUFFER 192
#define NNS_G3D_SIZE_SHP_VTBL_NUM 4
#define NNS_G3D_SIZE_MAT_VTBL_NUM 4
#define NNS_G3D_FUNC_SENDJOINTSRT_MAX 3
#define NNS_G3D_FUNC_SENDTEXSRT_MAX 4

/* ---- Binary resources ---- */

#define NNS_G3D_SIGNATURE_NSBMD       '0DMB'
#define NNS_G3D_SIGNATURE_NSBTX       '0XTB'
#define NNS_G3D_SIGNATURE_NSBCA       '0ACB'
#define NNS_G3D_SIGNATURE_NSBVA       '0AVB'
#define NNS_G3D_SIGNATURE_NSBMA       '0AMB'
#define NNS_G3D_SIGNATURE_NSBTP       '0PTB'
#define NNS_G3D_SIGNATURE_NSBTA       '0ATB'

#define NNS_G3D_DATABLK_MDLSET        '0LDM'
#define NNS_G3D_DATABLK_TEX           '0XET'
#define NNS_G3D_DATABLK_JNT_ANM       '0TNJ'
#define NNS_G3D_DATABLK_VIS_ANM       '0SIV'
#define NNS_G3D_DATABLK_MATC_ANM      '0TAM'
#define NNS_G3D_DATABLK_TEXPAT_ANM    '0TAP'
#define NNS_G3D_DATABLK_TEXSRT_ANM    '0TRS'

typedef struct NNSG3dResFileHeader_ {
    union {
        char signature[4];
        u32 sigVal;
    };
    u16 byteOrder;  // 0x04
    u16 version;    // 0x06
    u32 fileSize;   // 0x08
    u16 headerSize; // 0x0c
    u16 dataBlocks; // 0x0e
} NNSG3dResFileHeader;

typedef struct NNSG3dResDataBlockHeader_ {
    union {
        u32 kind;
        char chr[4];
    };
    u32 size;
} NNSG3dResDataBlockHeader;

// Patricia tree dictionary, followed by an entry header and the entries' data and names.
typedef struct NNSG3dResDictTreeNode_ {
    u8 refBit;
    u8 idxLeft;
    u8 idxRight;
    u8 idxEntry;
} NNSG3dResDictTreeNode;

typedef struct NNSG3dResDict_ {
    u8 revision;                  // 0x0
    u8 numEntry;                  // 0x1
    u16 sizeDictBlk;              // 0x2
    u16 dummy_;                   // 0x4
    u16 ofsEntry;                 // 0x6
    NNSG3dResDictTreeNode node[1]; // 0x8
} NNSG3dResDict;

#define NNS_G3D_RESNAME_SIZE 16
#define NNS_G3D_RESNAME_VALSIZE (NNS_G3D_RESNAME_SIZE / sizeof(u32))

typedef union NNSG3dResName {
    char name[NNS_G3D_RESNAME_SIZE];
    u32 val[NNS_G3D_RESNAME_VALSIZE];
} NNSG3dResName;

typedef struct NNSG3dResDictEntryHeader_ {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} NNSG3dResDictEntryHeader;


#ifndef NNS_GFD_TEXKEY_ADDR_SHIFT
#define NNS_GFD_TEXKEY_ADDR_SHIFT 3
#endif
typedef enum {
    NNS_G3D_TEXIMAGE_PARAM_TEX_ADDR_MASK  = 0x0000ffff,
    NNS_G3D_TEXIMAGE_PARAM_S_SIZE_MASK    = 0x00700000,
    NNS_G3D_TEXIMAGE_PARAM_T_SIZE_MASK    = 0x03800000,
    NNS_G3D_TEXIMAGE_PARAM_TEXFMT_MASK    = 0x1c000000,
    NNS_G3D_TEXIMAGE_PARAM_TR_MASK        = 0x20000000,
    NNS_G3D_TEXIMAGE_PARAM_TEX_ADDR_SHIFT = 0,
    NNS_G3D_TEXIMAGE_PARAM_S_SIZE_SHIFT   = 20,
    NNS_G3D_TEXIMAGE_PARAM_T_SIZE_SHIFT   = 23,
    NNS_G3D_TEXIMAGE_PARAM_TEXFMT_SHIFT   = 26,
    NNS_G3D_TEXIMAGE_PARAM_TR_SHIFT       = 29
} NNSG3dTexImageParam;

typedef enum {
    NNS_G3D_TEXIMAGE_PARAMEX_ORIGW_MASK   = 0x000007ff,
    NNS_G3D_TEXIMAGE_PARAMEX_ORIGH_MASK   = 0x003ff800,
    NNS_G3D_TEXIMAGE_PARAMEX_WHSAME_MASK  = 0x80000000,
    NNS_G3D_TEXIMAGE_PARAMEX_ORIGW_SHIFT  = 0,
    NNS_G3D_TEXIMAGE_PARAMEX_ORIGH_SHIFT  = 11,
    NNS_G3D_TEXIMAGE_PARAMEX_WHSAME_SHIFT = 31
} NNSG3dTexImageParamEx;

typedef enum {
    NNS_G3D_RESTEX_LOADED = 0x0001
} NNSG3dResTexFlag;

typedef enum {
    NNS_G3D_RESTEX4x4_LOADED = 0x0001
} NNSG3dResTex4x4Flag;

typedef enum {
    NNS_G3D_RESPLTT_LOADED   = 0x0001,
    NNS_G3D_RESPLTT_USEPLTT4 = 0x8000
} NNSG3dResPlttFlag;

typedef enum {
    NNS_G3D_MATFLAG_TEXMTX_USE       = 0x0001,
    NNS_G3D_MATFLAG_TEXMTX_SCALEONE  = 0x0002,
    NNS_G3D_MATFLAG_TEXMTX_ROTZERO   = 0x0004,
    NNS_G3D_MATFLAG_TEXMTX_TRANSZERO = 0x0008,
    NNS_G3D_MATFLAG_ORIGWH_SAME      = 0x0010,
    NNS_G3D_MATFLAG_WIREFRAME        = 0x0020,
    NNS_G3D_MATFLAG_DIFFUSE          = 0x0040,
    NNS_G3D_MATFLAG_AMBIENT          = 0x0080,
    NNS_G3D_MATFLAG_VTXCOLOR         = 0x0100,
    NNS_G3D_MATFLAG_SPECULAR         = 0x0200,
    NNS_G3D_MATFLAG_EMISSION         = 0x0400,
    NNS_G3D_MATFLAG_SHININESS        = 0x0800,
    NNS_G3D_MATFLAG_TEXPLTTBASE      = 0x1000,
    NNS_G3D_MATFLAG_EFFECTMTX        = 0x2000
} NNSG3dMatFlag;

typedef enum {
    NNS_G3D_SHPFLAG_USE_NORMAL     = 0x00000001,
    NNS_G3D_SHPFLAG_USE_COLOR      = 0x00000002,
    NNS_G3D_SHPFLAG_USE_TEXCOORD   = 0x00000004,
    NNS_G3D_SHPFLAG_USE_RESTOREMTX = 0x00000008
} NNSG3dShpFlag;

typedef enum {
    NNS_G3D_SBCTYPE_NORMAL = 0
} NNSG3dSbcType;

typedef enum {
    NNS_G3D_SCALINGRULE_STANDARD = 0,
    NNS_G3D_SCALINGRULE_MAYA     = 1,
    NNS_G3D_SCALINGRULE_SI3D     = 2
} NNSG3dScalingRule;

typedef enum {
    NNS_G3D_TEXMTXMODE_MAYA   = 0x00,
    NNS_G3D_TEXMTXMODE_SI3D   = 0x01,
    NNS_G3D_TEXMTXMODE_3DSMAX = 0x02,
    NNS_G3D_TEXMTXMODE_XSI    = 0x03
} NNSG3dTexMtxMode;

typedef enum {
    NNS_G3D_SRTFLAG_TRANS_ZERO        = 0x0001,
    NNS_G3D_SRTFLAG_ROT_ZERO          = 0x0002,
    NNS_G3D_SRTFLAG_SCALE_ONE         = 0x0004,
    NNS_G3D_SRTFLAG_PIVOT_EXIST       = 0x0008,
    NNS_G3D_SRTFLAG_IDXPIVOT_MASK     = 0x00f0,
    NNS_G3D_SRTFLAG_PIVOT_MINUS       = 0x0100,
    NNS_G3D_SRTFLAG_SIGN_REVC         = 0x0200,
    NNS_G3D_SRTFLAG_SIGN_REVD         = 0x0400,
    NNS_G3D_SRTFLAG_IDXMTXSTACK_MASK  = 0xf800,
    NNS_G3D_SRTFLAG_IDENTITY          = NNS_G3D_SRTFLAG_TRANS_ZERO |
                                        NNS_G3D_SRTFLAG_ROT_ZERO |
                                        NNS_G3D_SRTFLAG_SCALE_ONE,
    NNS_G3D_SRTFLAG_IDXPIVOT_SHIFT    = 4,
    NNS_G3D_SRTFLAG_IDXMTXSTACK_SHIFT = 11
} NNSG3dSRTFlag;

typedef enum {
    NNS_G3D_SBC_NODEDESC_FLAG_MAYASSC_APPLY  = 0x01,
    NNS_G3D_SBC_NODEDESC_FLAG_MAYASSC_PARENT = 0x02
} NNSG3dSbcNodeDescFlag;

typedef struct NNSG3dResDictTexData_ {
    u32 texImageParam;
    u32 extraParam;
} NNSG3dResDictTexData;


typedef struct NNSG3dResTexInfo_ {
    NNSGfdTexKey vramKey; // 0x0
    u16 sizeTex;          // 0x4
    u16 ofsDict;          // 0x6
    u16 flag;             // 0x8
    u16 dummy_;           // 0xa
    u32 ofsTex;           // 0xc
} NNSG3dResTexInfo;

typedef struct NNSG3dResTex4x4Info_ {
    NNSGfdTexKey vramKey; // 0x00
    u16 sizeTex;          // 0x04
    u16 ofsDict;          // 0x06
    u16 flag;             // 0x08
    u16 dummy_;           // 0x0a
    u32 ofsTex;           // 0x0c
    u32 ofsTexPlttIdx;    // 0x10
} NNSG3dResTex4x4Info;

typedef struct NNSG3dResDictPlttData_ {
    u16 offset;
    u16 flag;
} NNSG3dResDictPlttData;

typedef struct NNSG3dResPlttInfo_ {
    NNSGfdPlttKey vramKey; // 0x0
    u16 sizePltt;          // 0x4
    u16 flag;              // 0x6
    u16 ofsDict;           // 0x8
    u16 dummy_;            // 0xa
    u32 ofsPlttData;       // 0xc
} NNSG3dResPlttInfo;

typedef struct NNSG3dResTex_ {
    NNSG3dResDataBlockHeader header;  // 0x00
    NNSG3dResTexInfo texInfo;         // 0x08
    NNSG3dResTex4x4Info tex4x4Info;   // 0x18
    NNSG3dResPlttInfo plttInfo;       // 0x2c
    NNSG3dResDict dict;               // 0x3c
} NNSG3dResTex;

typedef struct NNSG3dResDictMatData_ {
    u32 offset;
} NNSG3dResDictMatData;

typedef struct NNSG3dResDictTexToMatIdxData_ {
    u16 offset;
    u8 numIdx;
    u8 flag;
} NNSG3dResDictTexToMatIdxData;

typedef struct NNSG3dResDictPlttToMatIdxData_ {
    u16 offset;
    u8 numIdx;
    u8 flag;
} NNSG3dResDictPlttToMatIdxData;


typedef struct NNSG3dResMatData_ {
    u16 itemTag;           // 0x00
    u16 size;              // 0x02
    u32 diffAmb;           // 0x04
    u32 specEmi;           // 0x08
    u32 polyAttr;          // 0x0c
    u32 polyAttrMask;      // 0x10
    u32 texImageParam;     // 0x14
    u32 texImageParamMask; // 0x18
    u16 texPlttBase;       // 0x1c
    u16 flag;              // 0x1e
    u16 origWidth;         // 0x20
    u16 origHeight;        // 0x22
    fx32 magW;             // 0x24
    fx32 magH;             // 0x28
} NNSG3dResMatData;

typedef struct NNSG3dResMat_ {
    u16 ofsDictTexToMatList;
    u16 ofsDictPlttToMatList;
    NNSG3dResDict dict;
} NNSG3dResMat;

typedef struct NNSG3dResDictShpData_ {
    u32 offset;
} NNSG3dResDictShpData;


typedef struct NNSG3dResShpData_ {
    u16 itemTag;
    u16 size;
    u32 flag;
    u32 ofsDL;
    u32 sizeDL;
} NNSG3dResShpData;

typedef struct NNSG3dResShp_ {
    NNSG3dResDict dict;
} NNSG3dResShp;

typedef struct NNSG3dResEvpMtx_ {
    MtxFx43 invM;
    MtxFx33 invN;
} NNSG3dResEvpMtx;



typedef struct NNSG3dResMdlInfo_ {
    u8 sbcType;               // 0x00
    u8 scalingRule;           // 0x01
    u8 texMtxMode;            // 0x02
    u8 numNode;               // 0x03
    u8 numMat;                // 0x04
    u8 numShp;                // 0x05
    u8 firstUnusedMtxStackID; // 0x06
    u8 dummy_;                // 0x07
    fx32 posScale;            // 0x08
    fx32 invPosScale;         // 0x0c
    u16 numVertex;            // 0x10
    u16 numPolygon;           // 0x12
    u16 numTriangle;          // 0x14
    u16 numQuad;              // 0x16
    fx16 boxX, boxY, boxZ;    // 0x18
    fx16 boxW, boxH, boxD;    // 0x1e
    fx32 boxPosScale;         // 0x24
    fx32 boxInvPosScale;      // 0x28
} NNSG3dResMdlInfo;

typedef struct NNSG3dResDictNodeData_ {
    u32 offset;
} NNSG3dResDictNodeData;


typedef struct NNSG3dResNodeData_ {
    u16 flag;
    fx16 _00;
} NNSG3dResNodeData;

typedef struct NNSG3dResNodeInfo_ {
    NNSG3dResDict dict;
} NNSG3dResNodeInfo;

typedef struct NNSG3dResMdl_ {
    u32 size;                   // 0x00
    u32 ofsSbc;                 // 0x04
    u32 ofsMat;                 // 0x08
    u32 ofsShp;                 // 0x0c
    u32 ofsEvpMtx;              // 0x10
    NNSG3dResMdlInfo info;      // 0x14
    NNSG3dResNodeInfo nodeInfo; // 0x40
} NNSG3dResMdl;

typedef struct NNSG3dResDictMdlSetData_ {
    u32 offset;
} NNSG3dResDictMdlSetData;

typedef struct NNSG3dResMdlSet_ {
    NNSG3dResDataBlockHeader header;
    NNSG3dResDict dict;
} NNSG3dResMdlSet;

// SBC (structure byte code) commands
#define NNS_G3D_SBC_NOP      0x00
#define NNS_G3D_SBC_RET      0x01
#define NNS_G3D_SBC_NODE     0x02
#define NNS_G3D_SBC_MTX      0x03
#define NNS_G3D_SBC_MAT      0x04
#define NNS_G3D_SBC_SHP      0x05
#define NNS_G3D_SBC_NODEDESC 0x06
#define NNS_G3D_SBC_BB       0x07
#define NNS_G3D_SBC_BBY      0x08
#define NNS_G3D_SBC_NODEMIX  0x09
#define NNS_G3D_SBC_CALLDL   0x0a
#define NNS_G3D_SBC_POSSCALE 0x0b
#define NNS_G3D_SBC_ENVMAP   0x0c
#define NNS_G3D_SBC_PRJMAP   0x0d
#define NNS_G3D_SBC_NOCMD    0x1f
#define NNS_G3D_SBC_COMMAND_NUM 0x20

#define NNS_G3D_SBCFLG_000 0x00
#define NNS_G3D_SBCFLG_001 0x20
#define NNS_G3D_SBCFLG_010 0x40
#define NNS_G3D_SBCFLG_011 0x60
#define NNS_G3D_SBCFLG_100 0x80
#define NNS_G3D_SBCFLG_101 0xa0
#define NNS_G3D_SBCFLG_110 0xc0
#define NNS_G3D_SBCFLG_111 0xe0
#define NNS_G3D_SBCCMD_MASK 0x1f
#define NNS_G3D_SBCFLG_MASK 0xe0


#define NNS_G3D_GET_SBCCMD(x) ((x) & NNS_G3D_SBCCMD_MASK)
#define NNS_G3D_GET_SBCFLG(x) ((u32)((x) & NNS_G3D_SBCFLG_MASK))

typedef struct NNSG3dResAnmHeader_ {
    u8 category0; // 'M', 'J' or 'V'
    u8 revision;
    u16 category1;
} NNSG3dResAnmHeader;

typedef struct NNSG3dResAnmCommon_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u16 dummy_;
} NNSG3dResAnmCommon;

typedef struct NNSG3dResDictAnmSetData_ {
    u32 offset;
} NNSG3dResDictAnmSetData;

typedef struct NNSG3dResAnmSet_ {
    NNSG3dResDataBlockHeader header;
    NNSG3dResDict dict;
} NNSG3dResAnmSet;

typedef struct NNSG3dResVisAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u16 numNode;
    u16 size;
    u16 dummy_;
    u32 visData[1];
} NNSG3dResVisAnm;

typedef NNSG3dResDictAnmSetData NNSG3dResDictVisAnmSetData;
typedef NNSG3dResAnmSet NNSG3dResVisAnmSet;

typedef enum {
    NNS_G3D_MATCANM_ELEM_CONST                 = 0x20000000,
    NNS_G3D_MATCANM_ELEM_STEP_1                = 0x00000000,
    NNS_G3D_MATCANM_ELEM_STEP_2                = 0x40000000,
    NNS_G3D_MATCANM_ELEM_STEP_4                = 0x80000000,
    NNS_G3D_MATCANM_ELEM_STEP_MASK             = 0xc0000000,
    NNS_G3D_MATCANM_ELEM_LAST_INTERP_MASK      = 0x1fff0000,
    NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK  = 0x0000ffff,
    NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_SHIFT = 0,
    NNS_G3D_MATCANM_ELEM_LAST_INTERP_SHIFT     = 16
} NNSG3dMatCElem;

typedef struct NNSG3dResDictMatCAnmData_ {
    u32 diffuse;
    u32 ambient;
    u32 specular;
    u32 emission;
    u32 polygon_alpha;
} NNSG3dResDictMatCAnmData;

typedef enum {
    NNS_G3D_MATCANM_OPTION_INTERPOLATION = 0x0001,
    NNS_G3D_MATCANM_OPTION_END_TO_START_INTERPOLATION = 0x0002
} NNSG3dMatCAnmOption;

typedef struct NNSG3dResMatCAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u16 flag;
    NNSG3dResDict dict;
} NNSG3dResMatCAnm;

typedef NNSG3dResDictAnmSetData NNSG3dResDictMatCAnmSetData;
typedef NNSG3dResAnmSet NNSG3dResMatCAnmSet;

typedef struct NNSG3dResTexPatAnmFV_ {
    u16 idxFrame;
    u8 idTex;
    u8 idPltt;
} NNSG3dResTexPatAnmFV;

typedef enum {
    NNS_G3D_TEXPATANM_OPTION_NOPLTT = 0x0001
} NNSG3dTexPatAnmOption;

typedef struct NNSG3dResDictTexPatAnmData_ {
    u16 numFV;
    u16 flag;
    fx16 ratioDataFrame;
    u16 offset;
} NNSG3dResDictTexPatAnmData;

typedef struct NNSG3dResTexPatAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u8 numTex;
    u8 numPltt;
    u16 ofsTexName;
    u16 ofsPlttName;
    NNSG3dResDict dict;
} NNSG3dResTexPatAnm;

typedef NNSG3dResDictAnmSetData NNSG3dResDictTexPatAnmSetData;
typedef NNSG3dResAnmSet NNSG3dResTexPatAnmSet;

typedef enum {
    NNS_G3D_TEXSRTANM_ELEM_FX16              = 0x10000000,
    NNS_G3D_TEXSRTANM_ELEM_CONST             = 0x20000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_1            = 0x00000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_2            = 0x40000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_4            = 0x80000000,
    NNS_G3D_TEXSRTANM_ELEM_STEP_MASK         = 0xc0000000,
    NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_MASK  = 0x0000ffff,
    NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_SHIFT = 0
} NNSG3dTexSRTElem;

typedef struct NNSG3dResDictTexSRTAnmData_ {
    u32 scaleS;
    u32 scaleSEx;
    u32 scaleT;
    u32 scaleTEx;
    u32 rot;
    u32 rotEx;
    u32 transS;
    u32 transSEx;
    u32 transT;
    u32 transTEx;
} NNSG3dResDictTexSRTAnmData;

typedef enum NNSG3dTexSRTAnmOption_ {
    NNS_G3D_TEXSRTANM_OPTION_INTERPOLATION = 0x01,
    NNS_G3D_TEXSRTANM_OPTION_END_TO_START_INTERPOLATION = 0x02
} NNSG3dTexSRTAnmOption;

typedef struct NNSG3dResTexSRTAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u8 flag;
    u8 texMtxMode;
    NNSG3dResDict dict;
} NNSG3dResTexSRTAnm;

typedef NNSG3dResDictAnmSetData NNSG3dResDictTexSRTAnmSetData;
typedef NNSG3dResAnmSet NNSG3dResTexSRTAnmSet;

typedef enum {
    NNS_G3D_JNTANM_SRTINFO_IDENTITY   = 0x00000001,
    NNS_G3D_JNTANM_SRTINFO_IDENTITY_T = 0x00000002,
    NNS_G3D_JNTANM_SRTINFO_BASE_T     = 0x00000004,
    NNS_G3D_JNTANM_SRTINFO_CONST_TX   = 0x00000008,
    NNS_G3D_JNTANM_SRTINFO_CONST_TY   = 0x00000010,
    NNS_G3D_JNTANM_SRTINFO_CONST_TZ   = 0x00000020,
    NNS_G3D_JNTANM_SRTINFO_IDENTITY_R = 0x00000040,
    NNS_G3D_JNTANM_SRTINFO_BASE_R     = 0x00000080,
    NNS_G3D_JNTANM_SRTINFO_CONST_R    = 0x00000100,
    NNS_G3D_JNTANM_SRTINFO_IDENTITY_S = 0x00000200,
    NNS_G3D_JNTANM_SRTINFO_BASE_S     = 0x00000400,
    NNS_G3D_JNTANM_SRTINFO_CONST_SX   = 0x00000800,
    NNS_G3D_JNTANM_SRTINFO_CONST_SY   = 0x00001000,
    NNS_G3D_JNTANM_SRTINFO_CONST_SZ   = 0x00002000,
    NNS_G3D_JNTANM_SRTINFO_NODE_MASK  = 0xff000000,
    NNS_G3D_JNTANM_SRTINFO_NODE_SHIFT = 24
} NNSG3dJntAnmSRTTag;

typedef enum {
    NNS_G3D_JNTANM_TINFO_STEP_1            = 0x00000000,
    NNS_G3D_JNTANM_TINFO_STEP_2            = 0x40000000,
    NNS_G3D_JNTANM_TINFO_STEP_4            = 0x80000000,
    NNS_G3D_JNTANM_TINFO_FX16ARRAY         = 0x20000000,
    NNS_G3D_JNTANM_TINFO_LAST_INTERP_MASK  = 0x1fff0000,
    NNS_G3D_JNTANM_TINFO_STEP_MASK         = 0xc0000000,
    NNS_G3D_JNTANM_TINFO_LAST_INTERP_SHIFT = 16,
    NNS_G3D_JNTANM_TINFO_STEP_SHIFT        = 30
} NNSG3dJntAnmTInfo;

typedef enum {
    NNS_G3D_JNTANM_RINFO_STEP_1            = 0x00000000,
    NNS_G3D_JNTANM_RINFO_STEP_2            = 0x40000000,
    NNS_G3D_JNTANM_RINFO_STEP_4            = 0x80000000,
    NNS_G3D_JNTANM_RINFO_LAST_INTERP_MASK  = 0x1fff0000,
    NNS_G3D_JNTANM_RINFO_STEP_MASK         = 0xc0000000,
    NNS_G3D_JNTANM_RINFO_LAST_INTERP_SHIFT = 16,
    NNS_G3D_JNTANM_RINFO_STEP_SHIFT        = 30
} NNSG3dJntAnmRInfo;

typedef enum {
    NNS_G3D_JNTANM_PIVOTINFO_IDXPIVOT_MASK   = 0x000f,
    NNS_G3D_JNTANM_PIVOTINFO_MINUS           = 0x0010,
    NNS_G3D_JNTANM_PIVOTINFO_SIGN_REVC       = 0x0020,
    NNS_G3D_JNTANM_PIVOTINFO_SIGN_REVD       = 0x0040,
    NNS_G3D_JNTANM_PIVOT_INFO_IDXPIVOT_SHIFT = 0
} NNSG3dJntAnmPivotInfo;

typedef enum {
    NNS_G3D_JNTANM_RIDX_PIVOT         = 0x8000,
    NNS_G3D_JNTANM_RIDX_IDXDATA_MASK  = 0x7fff,
    NNS_G3D_JNTANM_RIDX_IDXDATA_SHIFT = 0
} NNSG3dJntAnmRIdx;

typedef enum {
    NNS_G3D_JNTANM_SINFO_STEP_1            = 0x00000000,
    NNS_G3D_JNTANM_SINFO_STEP_2            = 0x40000000,
    NNS_G3D_JNTANM_SINFO_STEP_4            = 0x80000000,
    NNS_G3D_JNTANM_SINFO_FX16ARRAY         = 0x20000000,
    NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK  = 0x1fff0000,
    NNS_G3D_JNTANM_SINFO_STEP_MASK         = 0xc0000000,
    NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT = 16,
    NNS_G3D_JNTANM_SINFO_STEP_SHIFT        = 30
} NNSG3dJntAnmSInfo;

typedef struct NNSG3dResJntAnmSRTInfo_ {
    u32 info;
    u32 offset;
} NNSG3dResJntAnmSRTInfo;

typedef struct NNSG3dResJntAnmSRTTag_ {
    u32 tag;
} NNSG3dResJntAnmSRTTag;

typedef enum {
    NNS_G3D_JNTANM_OPTION_INTERPOLATION = 0x01,
    NNS_G3D_JNTANM_OPTION_END_TO_START_INTERPOLATION = 0x02
} NNSG3dJntAnmOption;

typedef struct NNSG3dResJntAnm_ {
    NNSG3dResAnmHeader anmHeader;
    u16 numFrame;
    u16 numNode;
    u32 flag;
    u32 ofsRot3;
    u32 ofsRot5;
} NNSG3dResJntAnm;

typedef NNSG3dResDictAnmSetData NNSG3dResDictJntAnmSetData;
typedef NNSG3dResAnmSet NNSG3dResJntAnmSet;

/* ---- Resource accessors ---- */

void *NNS_G3dGetResDataByName(const NNSG3dResDict *dict, const NNSG3dResName *name);
int NNS_G3dGetResDictIdxByName(const NNSG3dResDict *dict, const NNSG3dResName *name);
NNSG3dResMdlSet *NNS_G3dGetMdlSet(const NNSG3dResFileHeader *header);
NNSG3dResTex *NNS_G3dGetTex(const NNSG3dResFileHeader *header);

const void * NNSi_G3dGetBinaryBlockFromFile(const u8 * pFileHead, u32 fileSignature, u32 blockSignature);
BOOL NNSi_G3dIsValidAnmRes(const void * pRes);
void * NNS_G3dGetAnmByIdx(const void * pRes, u32 idx);
void * NNS_G3dGetAnmByName(const void * pRes, const NNSG3dResName * pName);
const NNSG3dResVisAnm * NNS_G3dGetVisAnmByIdx(const NNSG3dResVisAnmSet * pAnmSet, u8 idx);
const NNSG3dResVisAnmSet * NNS_G3dGetVisAnmSet(const u8 * pFileHead);
const NNSG3dResName * NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm * pPatAnm, u8 texIdx);
const NNSG3dResName * NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm * pPatAnm, u8 plttIdx);
const NNSG3dResTexPatAnmFV * NNSi_G3dGetTexPatAnmFVByFVIndex(const NNSG3dResTexPatAnm * pPatAnm, u32 idx, u32 fvIdx);
const NNSG3dResTexPatAnmFV * NNSi_G3dGetTexPatAnmFV(const NNSG3dResTexPatAnm * pPatAnm, u32 idx, u32 frame);
const NNSG3dResDictTexPatAnmData * NNSi_G3dGetTexPatAnmDataByIdx(const NNSG3dResTexPatAnm * pPatAnm, u32 idx);
const NNSG3dResTexPatAnm * NNS_G3dGetTexPatAnmByIdx(const NNSG3dResTexPatAnmSet * pAnmSet, u8 idx);
const NNSG3dResTexPatAnmSet * NNS_G3dGetTexPatAnmSet(const u8 * pFileHead);
const NNSG3dResTexSRTAnm * NNS_G3dGetTexSRTAnmByIdx(const NNSG3dResTexSRTAnmSet * pTexSRTSet, u8 idx);
const NNSG3dResTexSRTAnmSet * NNS_G3dGetTexSRTAnmSet(const u8 * pFileHead);
const NNSG3dResMatCAnm * NNS_G3dGetMatCAnmByIdx(const NNSG3dResMatCAnmSet * pAnmSet, u8 idx);
const NNSG3dResMatCAnmSet * NNS_G3dGetMatCAnmSet(const u8 * pFileHead);
const NNSG3dResJntAnmSRTTag * NNS_G3dGetJntAnmSRTTag(const NNSG3dResJntAnm * pJntAnm, int nodeIdx);
const NNSG3dResJntAnm * NNS_G3dGetJntAnmByIdx(const NNSG3dResJntAnmSet * pJntAnmSet, int idx);
const NNSG3dResJntAnmSet * NNS_G3dGetJntAnmSet(const u8 * pFileHead);

static inline const NNSG3dResName * NNS_G3dGetResNameByIdx (const NNSG3dResDict * dict, u32 idx)
{
    NNSG3dResDictEntryHeader * hdr;

    if (dict != NULL && idx < dict->numEntry) {
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (NNSG3dResName *)((u8 *)hdr +
                                 hdr->ofsName +
                                 sizeof(NNSG3dResName) * idx);
    } else {
        return NULL;
    }
}

static inline void * NNS_G3dGetResDataByIdx (const NNSG3dResDict * dict, u32 idx)
{
    NNSG3dResDictEntryHeader * hdr;

    if (dict != NULL && idx < dict->numEntry) {
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)(&hdr->data[0] + hdr->sizeUnit * idx);
    } else {
        return NULL;
    }
}

static inline const NNSG3dResName * NNS_G3dGetTexNameByIdx (const NNSG3dResTex * tex, u32 idx)
{

    if (tex)
        return NNS_G3dGetResNameByIdx(&tex->dict, idx);
    else
        return NULL;
}

static inline int NNS_G3dGetTexIdxByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{

    if (tex)
        return NNS_G3dGetResDictIdxByName(&tex->dict, name);
    else
        return -1;
}

static inline const NNSG3dResName * NNS_G3dGetPlttNameByIdx (const NNSG3dResTex * tex, u32 idx)
{
    const NNSG3dResDict * dict;


    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (const NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return NNS_G3dGetResNameByIdx(dict, idx);
    } else {
        return NULL;
    }
}

static inline int NNS_G3dGetPlttIdxByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{
    const NNSG3dResDict * dict;


    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (const NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return NNS_G3dGetResDictIdxByName(dict, name);
    } else {
        return -1;
    }
}

static inline const NNSG3dResName * NNS_G3dGetNodeNameByIdx (const NNSG3dResNodeInfo * nodeinfo, u32 idx)
{

    if (nodeinfo)
        return NNS_G3dGetResNameByIdx(&nodeinfo->dict, idx);
    else
        return NULL;
}

static inline int NNS_G3dGetNodeIdxByName (const NNSG3dResNodeInfo * nodeinfo, const NNSG3dResName * name)
{

    if (nodeinfo)
        return NNS_G3dGetResDictIdxByName(&nodeinfo->dict, name);
    else
        return -1;
}

static inline const NNSG3dResName * NNS_G3dGetMatNameByIdx (const NNSG3dResMat * mat, u32 idx)
{

    if (mat)
        return NNS_G3dGetResNameByIdx(&mat->dict, idx);
    else
        return NULL;
}

static inline int NNS_G3dGetMatIdxByName (const NNSG3dResMat * mat, const NNSG3dResName * name)
{

    if (mat)
        return NNS_G3dGetResDictIdxByName(&mat->dict, name);
    else
        return -1;
}

static inline const NNSG3dResName * NNS_G3dGetShpNameByIdx (const NNSG3dResShp * shp, u32 idx)
{

    if (shp)
        return NNS_G3dGetResNameByIdx(&shp->dict, idx);
    else
        return NULL;
}

static inline int NNS_G3dGetShpIdxByName (const NNSG3dResShp * shp, const NNSG3dResName * name)
{

    if (shp)
        return NNS_G3dGetResDictIdxByName(&shp->dict, name);
    else
        return -1;
}

static inline NNSG3dResMdlInfo * NNS_G3dGetMdlInfo (const NNSG3dResMdl * mdl)
{

    if (mdl)
        return (NNSG3dResMdlInfo *)&mdl->info;
    else
        return NULL;
}

static inline NNSG3dResNodeInfo * NNS_G3dGetNodeInfo (const NNSG3dResMdl * mdl)
{

    if (mdl)
        return (NNSG3dResNodeInfo *)&mdl->nodeInfo;
    else
        return NULL;
}

static inline u8 * NNS_G3dGetSbc (const NNSG3dResMdl * mdl)
{

    if (mdl && mdl->ofsSbc != 0)
        return (u8 *)((u8 *)mdl + mdl->ofsSbc);
    else
        return NULL;
}

static inline NNSG3dResMat * NNS_G3dGetMat (const NNSG3dResMdl * mdl)
{

    if (mdl && mdl->ofsMat != 0)
        return (NNSG3dResMat *)((u8 *)mdl + mdl->ofsMat);
    else
        return NULL;
}

static inline NNSG3dResShp * NNS_G3dGetShp (const NNSG3dResMdl * mdl)
{

    if (mdl && mdl->ofsShp != 0)
        return (NNSG3dResShp *)((u8 *)mdl + mdl->ofsShp);
    else
        return NULL;
}

static inline NNSG3dResMdl * NNS_G3dGetMdlByIdx (const NNSG3dResMdlSet * mdlSet, u32 idx)
{
    NNSG3dResDictMdlSetData * data;

    if (mdlSet) {
        data = (NNSG3dResDictMdlSetData *)NNS_G3dGetResDataByIdx(&mdlSet->dict, idx);
        if (data) {
            return (NNSG3dResMdl *)((u8 *)mdlSet + data->offset);
        }
    }
    return NULL;
}

static inline const NNSG3dResName * NNS_G3dGetMdlNameByIdx (const NNSG3dResMdlSet * mdlSet, u32 idx)
{

    if (mdlSet)
        return NNS_G3dGetResNameByIdx(&mdlSet->dict, idx);
    else
        return NULL;
}

static inline NNSG3dResMdl * NNS_G3dGetMdlByName (const NNSG3dResMdlSet * mdlSet, const NNSG3dResName * name)
{
    NNSG3dResDictMdlSetData * data;

    if (mdlSet) {
        data = (NNSG3dResDictMdlSetData *)NNS_G3dGetResDataByName(&mdlSet->dict, name);
        if (data) {
            return (NNSG3dResMdl *)((u8 *)mdlSet + data->offset);
        }
    }

    return NULL;
}

static inline int NNS_G3dGetMdlIdxByName (const NNSG3dResMdlSet * mdlSet, const NNSG3dResName * name)
{

    if (mdlSet)
        return NNS_G3dGetResDictIdxByName(&mdlSet->dict, name);
    else
        return -1;
}

static inline NNSG3dResMdlSet * NNS_G3dCheckMdlSet (const NNSG3dResDataBlockHeader * dataBlkHeader)
{

    if (dataBlkHeader->kind == NNS_G3D_DATABLK_MDLSET) {
        return (NNSG3dResMdlSet *)dataBlkHeader;
    } else {
        return NULL;
    }
}

static inline NNSG3dResTex * NNS_G3dCheckTex (const NNSG3dResDataBlockHeader * dataBlkHeader)
{

    if (dataBlkHeader->kind == NNS_G3D_DATABLK_TEX) {
        return (NNSG3dResTex *)dataBlkHeader;
    } else {
        return NULL;
    }
}

static inline NNSG3dResNodeData * NNS_G3dGetNodeDataByIdx (const NNSG3dResNodeInfo * info, u32 idx)
{
    NNSG3dResDictNodeData * data;

    if (info) {
        data = (NNSG3dResDictNodeData *)NNS_G3dGetResDataByIdx(&info->dict, idx);
        if (data) {
            return (NNSG3dResNodeData *)((u8 *)info + data->offset);
        }
    }

    return NULL;
}

static inline NNSG3dResMatData * NNS_G3dGetMatDataByIdx (const NNSG3dResMat * mat, u32 idx)
{
    NNSG3dResDictMatData * data;

    if (mat) {
        data = (NNSG3dResDictMatData *)NNS_G3dGetResDataByIdx(&mat->dict, idx);
        if (data) {
            return (NNSG3dResMatData *)((u8 *)mat + data->offset);
        }
    }

    return NULL;
}

static inline NNSG3dResShpData * NNS_G3dGetShpDataByIdx (const NNSG3dResShp * shp, u32 idx)
{
    NNSG3dResDictShpData * data;

    if (shp) {
        data = (NNSG3dResDictShpData *)NNS_G3dGetResDataByIdx(&shp->dict, idx);
        if (data) {
            return (NNSG3dResShpData *)((u8 *)shp + data->offset);
        }
    }

    return NULL;
}

static inline NNSG3dResDictTexData * NNS_G3dGetTexDataByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{

    if (tex)
        return (NNSG3dResDictTexData *)NNS_G3dGetResDataByName(&tex->dict, name);
    else
        return NULL;
}

static inline NNSG3dResDictTexData * NNS_G3dGetTexDataByIdx (const NNSG3dResTex * tex, u32 idx)
{

    if (tex)
        return (NNSG3dResDictTexData *)NNS_G3dGetResDataByIdx(&tex->dict, idx);
    else
        return NULL;
}

static inline NNSG3dResDictPlttData * NNS_G3dGetPlttDataByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{
    NNSG3dResDict * dict;

    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return (NNSG3dResDictPlttData *)NNS_G3dGetResDataByName(dict, name);
    } else {
        return NULL;
    }
}

static inline NNSG3dResDictPlttData * NNS_G3dGetPlttDataByIdx (const NNSG3dResTex * tex, u32 idx)
{
    NNSG3dResDict * dict;

    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return (NNSG3dResDictPlttData *)NNS_G3dGetResDataByIdx(dict, idx);
    } else {
        return NULL;
    }
}

static inline const void * NNS_G3dGetTexData (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->texInfo.ofsTex;
}

static inline const void * NNS_G3dGetTex4x4Data (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->tex4x4Info.ofsTex;
}

static inline const void * NNS_G3dGetTex4x4PlttIdxData (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->tex4x4Info.ofsTexPlttIdx;
}

static inline const void * NNS_G3dGetPlttData (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->plttInfo.ofsPlttData;
}

static inline const void * NNS_G3dGetShpDLPtr (const NNSG3dResShpData * shp)
{
    return (u8 *)shp + shp->ofsDL;
}

static inline u32 NNS_G3dGetShpDLSize (const NNSG3dResShpData * shp)
{
    return shp->sizeDL;
}

static inline BOOL NNS_G3dIsMatAnm (const void * pAnm)
{
    const NNSG3dResAnmHeader * hdr = (const NNSG3dResAnmHeader *) pAnm;
    return hdr != NULL && hdr->category0 == 'M';
}

static inline BOOL NNS_G3dIsJntAnm (const void * pAnm)
{
    const NNSG3dResAnmHeader * hdr = (const NNSG3dResAnmHeader *) pAnm;
    return hdr != NULL && hdr->category0 == 'J';
}

static inline BOOL NNS_G3dIsVisAnm (const void * pAnm)
{
    const NNSG3dResAnmHeader * hdr = (const NNSG3dResAnmHeader *) pAnm;
    return hdr != NULL && hdr->category0 == 'V';
}

/* ---- Animation objects and render objects ---- */

typedef u32 NNSG3dTexKey;
typedef u32 NNSG3dPlttKey;

typedef struct NNSG3dAnmObj_ {
    fx32 frame;                    // 0x00
    fx32 ratio;                    // 0x04
    void *resAnm;                  // 0x08
    void *funcAnm;                 // 0x0c
    struct NNSG3dAnmObj_ *next;     // 0x10
    const NNSG3dResTex *resTex;    // 0x14
    u8 priority;                   // 0x18
    u8 numMapData;                 // 0x19
    u16 mapData[1];                // 0x1a
} NNSG3dAnmObj;

#define NNS_G3D_ANMOBJ_SIZE_MATANM(pMdl) ((sizeof(NNSG3dAnmObj) + sizeof(u16) * pMdl->info.numMat) & ~3)
#define NNS_G3D_ANMOBJ_SIZE_JNTANM(pMdl) ((sizeof(NNSG3dAnmObj) + sizeof(u16) * pMdl->info.numNode) & ~3)

#define NNS_G3D_ANMOBJ_MAPDATA_EXIST     0x0100
#define NNS_G3D_ANMOBJ_MAPDATA_DISABLED  0x0200
#define NNS_G3D_ANMOBJ_MAPDATA_DATAFIELD 0x00ff

struct NNSG3dMatAnmResult_;
struct NNSG3dJntAnmResult_;
struct NNSG3dVisAnmResult_;

typedef BOOL (*NNSG3dFuncAnmBlendMat)(struct NNSG3dMatAnmResult_ *, const NNSG3dAnmObj *, u32);
typedef BOOL (*NNSG3dFuncAnmBlendJnt)(struct NNSG3dJntAnmResult_ *, const NNSG3dAnmObj *, u32);
typedef BOOL (*NNSG3dFuncAnmBlendVis)(struct NNSG3dVisAnmResult_ *, const NNSG3dAnmObj *, u32);

#define NNS_G3D_RENDEROBJ_FLAG_RECORD           0x00000001
#define NNS_G3D_RENDEROBJ_FLAG_NOGECMD          0x00000002
#define NNS_G3D_RENDEROBJ_FLAG_SKIP_SBC_DRAW    0x00000004
#define NNS_G3D_RENDEROBJ_FLAG_SKIP_SBC_MTXCALC 0x00000008
#define NNS_G3D_RENDEROBJ_FLAG_HINT_OBSOLETE    0x00000010

struct NNSG3dRS_;
typedef void (*NNSG3dSbcCallBackFunc)(struct NNSG3dRS_ *);

typedef enum NNSG3dSbcCallBackTiming {
    NNS_G3D_SBC_CALLBACK_TIMING_NONE = 0x00,
    NNS_G3D_SBC_CALLBACK_TIMING_A = 0x01,
    NNS_G3D_SBC_CALLBACK_TIMING_B = 0x02,
    NNS_G3D_SBC_CALLBACK_TIMING_C = 0x03
} NNSG3dSbcCallBackTiming;

typedef struct NNSG3dRenderObj_ {
    u32 flag;                                         // 0x00
    NNSG3dResMdl *resMdl;                             // 0x04
    NNSG3dAnmObj *anmMat;                             // 0x08
    NNSG3dFuncAnmBlendMat funcBlendMat;               // 0x0c
    NNSG3dAnmObj *anmJnt;                             // 0x10
    NNSG3dFuncAnmBlendJnt funcBlendJnt;               // 0x14
    NNSG3dAnmObj *anmVis;                             // 0x18
    NNSG3dFuncAnmBlendVis funcBlendVis;               // 0x1c
    NNSG3dSbcCallBackFunc cbFunc;                     // 0x20
    u8 cbCmd;                                         // 0x24
    u8 cbTiming;                                      // 0x25
    u16 dummy_;                                       // 0x26
    NNSG3dSbcCallBackFunc cbInitFunc;                 // 0x28
    void *ptrUser;                                    // 0x2c
    u8 *ptrUserSbc;                                   // 0x30
    struct NNSG3dJntAnmResult_ *recJntAnm;             // 0x34
    struct NNSG3dMatAnmResult_ *recMatAnm;             // 0x38
    u32 hintMatAnmExist[NNS_G3D_SIZE_MAT_MAX / 32];   // 0x3c
    u32 hintJntAnmExist[NNS_G3D_SIZE_JNT_MAX / 32];   // 0x44
    u32 hintVisAnmExist[NNS_G3D_SIZE_JNT_MAX / 32];   // 0x4c
} NNSG3dRenderObj; // size 0x54

static inline void NNS_G3dRenderObjSetFlag(NNSG3dRenderObj *pRenderObj, u32 flag) {
    pRenderObj->flag |= flag;
}

static inline void NNS_G3dRenderObjResetFlag(NNSG3dRenderObj *pRenderObj, u32 flag) {
    pRenderObj->flag &= ~flag;
}

static inline BOOL NNS_G3dRenderObjTestFlag(const NNSG3dRenderObj *pRenderObj, u32 flag) {
    return (pRenderObj->flag & flag) == flag;
}

u32 NNS_G3dAnmObjCalcSizeRequired(const void *pAnm, const NNSG3dResMdl *pMdl);
void NNS_G3dAnmObjInit(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl, const NNSG3dResTex *pResTex);
void NNS_G3dRenderObjInit(NNSG3dRenderObj *pRenderObj, NNSG3dResMdl *pResMdl);
void NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj);
void NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj);
void NNS_G3dRenderObjSetCallBack(NNSG3dRenderObj *pRenderObj, NNSG3dSbcCallBackFunc func, u8 *, u8 cmd, NNSG3dSbcCallBackTiming timing);
void NNS_G3dRenderObjResetCallBack(NNSG3dRenderObj *pRenderObj);
void NNS_G3dRenderObjSetInitFunc(NNSG3dRenderObj *pRenderObj, NNSG3dSbcCallBackFunc func);
u32 NNS_G3dTexGetRequiredSize(const NNSG3dResTex *pTex);
u32 NNS_G3dTex4x4GetRequiredSize(const NNSG3dResTex *pTex);
u32 NNS_G3dPlttGetRequiredSize(const NNSG3dResTex *pTex);
BOOL NNS_G3dBindMdlTex(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex);
void NNS_G3dReleaseMdlTex(NNSG3dResMdl *pMdl);
BOOL NNS_G3dBindMdlPltt(NNSG3dResMdl *pMdl, const NNSG3dResTex *pTex);
void NNS_G3dReleaseMdlPltt(NNSG3dResMdl *pMdl);
BOOL NNS_G3dBindMdlSet(NNSG3dResMdlSet *pMdlSet, const NNSG3dResTex *pTex);
void NNS_G3dReleaseMdlSet(NNSG3dResMdlSet *pMdlSet);

/* ---- Animation results ---- */

typedef void (*NNSG3dAnimInitFunc)(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);

typedef struct NNSG3dAnmObjInitFunc_ {
    u8 category0;
    u8 dummy_;
    u16 category1;
    NNSG3dAnimInitFunc func;
} NNSG3dAnmObjInitFunc;

#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE  0x00000001
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO   0x00000002
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO 0x00000004
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET       0x00000008
#define NNS_G3D_MATANM_RESULTFLAG_TEXMTX_MULT      0x00000010
#define NNS_G3D_MATANM_RESULTFLAG_WIREFRAME        0x00000020
typedef u32 NNSG3dMatAnmResultFlag;

typedef struct NNSG3dMatAnmResult_ {
    NNSG3dMatAnmResultFlag flag; // 0x00
    u32 prmMatColor0;            // 0x04
    u32 prmMatColor1;            // 0x08
    u32 prmPolygonAttr;          // 0x0c
    u32 prmTexImage;             // 0x10
    u32 prmTexPltt;              // 0x14
    fx32 scaleS, scaleT;         // 0x18
    fx16 sinR, cosR;             // 0x20
    fx32 transS, transT;         // 0x24
    u16 origWidth, origHeight;   // 0x2c
    fx32 magW, magH;             // 0x30
} NNSG3dMatAnmResult; // size 0x38

#define NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE    0x00000001
#define NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO     0x00000002
#define NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO   0x00000004
#define NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE 0x00000008
#define NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE 0x00000010
#define NNS_G3D_JNTANM_RESULTFLAG_MAYA_SSC     0x00000020
typedef u32 NNSG3dJntAnmResultFlag;

typedef struct NNSG3dJntAnmResult_ {
    NNSG3dJntAnmResultFlag flag; // 0x00
    VecFx32 scale;               // 0x04
    VecFx32 scaleEx0;            // 0x10
    VecFx32 scaleEx1;            // 0x1c
    MtxFx33 rot;                 // 0x28
    VecFx32 trans;               // 0x4c
} NNSG3dJntAnmResult; // size 0x58

typedef struct NNSG3dVisAnmResult_ {
    BOOL isVisible;
} NNSG3dVisAnmResult;

typedef void (*NNSG3dFuncAnmMat)(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);
typedef void (*NNSG3dFuncAnmJnt)(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);
typedef void (*NNSG3dFuncAnmVis)(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);

BOOL NNSi_G3dAnmBlendMat(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 matID);
BOOL NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);
BOOL NNSi_G3dAnmBlendVis(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);

extern NNSG3dFuncAnmBlendMat NNS_G3dFuncBlendMatDefault;
extern NNSG3dFuncAnmBlendJnt NNS_G3dFuncBlendJntDefault;
extern NNSG3dFuncAnmBlendVis NNS_G3dFuncBlendVisDefault;
extern NNSG3dFuncAnmMat NNS_G3dFuncAnmMatNsBmaDefault;
extern NNSG3dFuncAnmMat NNS_G3dFuncAnmMatNsBtpDefault;
extern NNSG3dFuncAnmMat NNS_G3dFuncAnmMatNsBtaDefault;
extern NNSG3dFuncAnmJnt NNS_G3dFuncAnmJntNsBcaDefault;
extern NNSG3dFuncAnmVis NNS_G3dFuncAnmVisNsBvaDefault;
extern u32 NNS_G3dAnmFmtNum;
extern NNSG3dAnmObjInitFunc NNS_G3dAnmObjInitFuncArray[NNS_G3D_ANMFMT_MAX];


// ---- gecom ----

typedef struct NNSG3dGeBuffer_ {
    u32 idx;
    u32 data[NNS_G3D_SIZE_COMBUFFER];
} NNSG3dGeBuffer;

// gecom.c state block (NNS_G3dGeBuffer, NNS_G3dFlagGXDmaAsync, NNS_G3dFlagUseFastDma)
typedef struct NNSiG3dGeState {
    NNSG3dGeBuffer *buffer;
    volatile int flagGXDmaAsync;
    BOOL flagUseFastDma;
} NNSiG3dGeState;

extern NNSiG3dGeState NNSi_G3dGeState;

BOOL NNS_G3dGeIsSendDLBusy(void);
BOOL NNS_G3dGeIsBufferExist(void);
BOOL NNS_G3dGeIsImmOK(void);
BOOL NNS_G3dGeIsBufferOK(u32 numWord);
void NNS_G3dGeWaitSendDL(void);
void NNS_G3dGeSetBuffer(NNSG3dGeBuffer *p);
NNSG3dGeBuffer *NNS_G3dGeReleaseBuffer(void);
void NNS_G3dGeFlushBuffer(void);
void NNS_G3dGeSendDL(const void *src, u32 szByte);
void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num);
void NNS_G3dGeUseFastDma(BOOL cond);

static inline void NNS_G3dGeBufferData_N (const u32 * args, u32 num)
{
    NNS_G3dGeBufferOP_N(*args, args + 1, num - 1);
}

static inline void NNS_G3dGeMtxMode (GXMtxMode mode)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_MODE, (u32 *)&mode, G3OP_MTX_MODE_NPARAMS);
}

static inline void NNS_G3dGePushMtx (void)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_PUSH, NULL, G3OP_MTX_PUSH_NPARAMS);
}

static inline void NNS_G3dGePopMtx (int num)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_POP, (u32 *)&num, G3OP_MTX_POP_NPARAMS);
}

static inline void NNS_G3dGeStoreMtx (int num)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_STORE, (u32 *)&num, G3OP_MTX_STORE_NPARAMS);
}

static inline void NNS_G3dGeRestoreMtx (int num)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_RESTORE, (u32 *)&num, G3OP_MTX_RESTORE_NPARAMS);
}

static inline void NNS_G3dGeIdentity (void)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_IDENTITY, NULL, G3OP_MTX_IDENTITY_NPARAMS);
}

static inline void NNS_G3dGeScaleVec (const VecFx32 * vec)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_SCALE, (u32 *)vec, G3OP_MTX_SCALE_NPARAMS);
}

static inline void NNS_G3dGeScale (fx32 x, fx32 y, fx32 z)
{
    VecFx32 vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    NNS_G3dGeBufferOP_N(G3OP_MTX_SCALE, (u32 *)&vec, G3OP_MTX_SCALE_NPARAMS);
}

static inline void NNS_G3dGeTranslateVec (const VecFx32 * vec)
{
    NNS_G3dGeBufferOP_N(G3OP_MTX_TRANS, (u32 *)vec, G3OP_MTX_TRANS_NPARAMS);
}

static inline void NNS_G3dGeTranslate (fx32 x, fx32 y, fx32 z)
{
    VecFx32 vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    NNS_G3dGeBufferOP_N(G3OP_MTX_TRANS, (u32 *)&vec, G3OP_MTX_TRANS_NPARAMS);
}

static inline void NNS_G3dGeColor (GXRgb rgb)
{
    u32 tmp;
    tmp = GX_PACK_COLOR_PARAM(rgb);
    NNS_G3dGeBufferOP_N(G3OP_COLOR, (u32 *)&tmp, G3OP_COLOR_NPARAMS);
}

static inline void NNS_G3dGeNormal (fx16 x, fx16 y, fx16 z)
{
    u32 tmp;

    tmp = GX_PACK_NORMAL_PARAM(x, y, z);

    NNS_G3dGeBufferOP_N(G3OP_NORMAL, (u32 *)&tmp, G3OP_NORMAL_NPARAMS);
}

static inline void NNS_G3dGeTexCoord (fx32 s, fx32 t)
{
    u32 tmp;

    tmp = GX_PACK_TEXCOORD_PARAM(s, t);

    NNS_G3dGeBufferOP_N(G3OP_TEXCOORD, (u32 *)&tmp, G3OP_TEXCOORD_NPARAMS);
}

static inline void NNS_G3dGeVtx (fx16 x, fx16 y, fx16 z)
{
    u32 tmp[2];
    tmp[0] = GX_FX16PAIR(x, y);
    tmp[1] = (u32)(u16) z;

    NNS_G3dGeBufferOP_N(G3OP_VTX_16, tmp, G3OP_VTX_16_NPARAMS);
}

static inline void NNS_G3dGeVtx10 (fx16 x, fx16 y, fx16 z)
{
    u32 tmp = GX_PACK_VTX10_PARAM(x, y, z);
    NNS_G3dGeBufferOP_N(G3OP_VTX_10, &tmp, G3OP_VTX_10_NPARAMS);
}

static inline void NNS_G3dGeVtxXY (fx16 x, fx16 y)
{
    u32 tmp = GX_PACK_VTXXY_PARAM(x, y);
    NNS_G3dGeBufferOP_N(G3OP_VTX_XY, &tmp, G3OP_VTX_XY_NPARAMS);
}

static inline void NNS_G3dGeVtxXZ (fx16 x, fx16 z)
{
    u32 tmp = GX_PACK_VTXXZ_PARAM(x, z);
    NNS_G3dGeBufferOP_N(G3OP_VTX_XZ, &tmp, G3OP_VTX_XZ_NPARAMS);
}

static inline void NNS_G3dGeVtxYZ (fx16 y, fx16 z)
{
    u32 tmp = GX_PACK_VTXYZ_PARAM(y, z);
    NNS_G3dGeBufferOP_N(G3OP_VTX_YZ, &tmp, G3OP_VTX_YZ_NPARAMS);
}

static inline void NNS_G3dGeVtxDiff (fx16 x, fx16 y, fx16 z)
{
    u32 tmp;

    tmp = GX_PACK_VTXDIFF_PARAM(x, y, z);

    NNS_G3dGeBufferOP_N(G3OP_VTX_DIFF, &tmp, G3OP_VTX_DIFF_NPARAMS);
}

static inline void NNS_G3dGePolygonAttr (int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc)
{
    u32 tmp;

    tmp = GX_PACK_POLYGONATTR_PARAM(light,
                                    polyMode,
                                    cullMode,
                                    polygonID,
                                    alpha,
                                    misc);

    NNS_G3dGeBufferOP_N(G3OP_POLYGON_ATTR,
                        &tmp,
                        G3OP_POLYGON_ATTR_NPARAMS);
}

static inline void NNS_G3dGeTexImageParam (GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    u32 tmp;


    tmp = GX_PACK_TEXIMAGE_PARAM(texFmt,
                                 texGen,
                                 s,
                                 t,
                                 repeat,
                                 flip,
                                 pltt0,
                                 addr);

    NNS_G3dGeBufferOP_N(G3OP_TEXIMAGE_PARAM,
                        &tmp,
                        G3OP_TEXIMAGE_PARAM_NPARAMS);
}

static inline void NNS_G3dGeTexPlttBase (u32 addr, GXTexFmt texfmt)
{
    u32 param = GX_PACK_TEXPLTTBASE_PARAM(addr, texfmt);

    NNS_G3dGeBufferOP_N(G3OP_TEXPLTT_BASE,
                        &param,
                        G3OP_TEXPLTT_BASE_NPARAMS);
}

static inline void NNS_G3dGeMaterialColorDiffAmb (GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor)
{
    u32 tmp;

    tmp = GX_PACK_DIFFAMB_PARAM(diffuse, ambient, IsSetVtxColor);

    NNS_G3dGeBufferOP_N(G3OP_DIF_AMB,
                        &tmp,
                        G3OP_DIF_AMB_NPARAMS);
}

static inline void NNS_G3dGeMaterialColorSpecEmi (GXRgb specular, GXRgb emission, BOOL IsShininess)
{
    u32 tmp;

    tmp = GX_PACK_SPECEMI_PARAM(specular, emission, IsShininess);

    NNS_G3dGeBufferOP_N(G3OP_SPE_EMI,
                        &tmp,
                        G3OP_SPE_EMI_NPARAMS);
}

static inline void NNS_G3dGeLightVector (GXLightId lightID, fx16 x, fx16 y, fx16 z)
{
    u32 tmp;

    tmp = GX_PACK_LIGHTVECTOR_PARAM(lightID, x, y, z);

    NNS_G3dGeBufferOP_N(G3OP_LIGHT_VECTOR,
                        &tmp,
                        G3OP_LIGHT_VECTOR_NPARAMS);
}

static inline void NNS_G3dGeLightColor (GXLightId lightID, GXRgb rgb)
{
    u32 tmp;

    tmp = GX_PACK_LIGHTCOLOR_PARAM(lightID, rgb);

    NNS_G3dGeBufferOP_N(G3OP_LIGHT_COLOR,
                        &tmp,
                        G3OP_LIGHT_COLOR_NPARAMS);
}

static inline void NNS_G3dGeBegin (GXBegin primitive)
{

    NNS_G3dGeBufferOP_N(G3OP_BEGIN,
                        (u32 *)&primitive,
                        G3OP_BEGIN_NPARAMS);
}

static inline void NNS_G3dGeEnd (void)
{
    NNS_G3dGeBufferOP_N(G3OP_END, NULL, G3OP_END_NPARAMS);
}

static inline void NNS_G3dGeViewPort (int x1, int y1, int x2, int y2)
{
    u32 tmp;
    tmp = GX_PACK_VIEWPORT_PARAM(x1, y1, x2, y2);

    NNS_G3dGeBufferOP_N(G3OP_VIEWPORT, &tmp, G3OP_VIEWPORT_NPARAMS);
}

static inline void NNS_G3dGeBoxTest (const GXBoxTestParam * box)
{

    NNS_G3dGeBufferOP_N(G3OP_BOX_TEST,
                        (u32 *)&box->val[0],
                        G3OP_BOX_TEST_NPARAMS);
}

static inline void NNS_G3dGePositionTest (fx16 x, fx16 y, fx16 z)
{
    u32 tmp[2];
    tmp[0] = GX_FX16PAIR(x, y);
    tmp[1] = (u32)(u16) z;

    NNS_G3dGeBufferOP_N(G3OP_POS_TEST,
                        (u32 *)&tmp[0],
                        G3OP_POS_TEST_NPARAMS);
}

static inline void NNS_G3dGeVectorTest (fx16 x, fx16 y, fx16 z)
{
    u32 tmp;

    tmp = GX_PACK_VECTORTEST_PARAM(x, y, z);

    NNS_G3dGeBufferOP_N(G3OP_VEC_TEST,
                        &tmp,
                        G3OP_VEC_TEST_NPARAMS);
}

static inline void NNS_G3dGeLoadMtx44 (const MtxFx44 * m)
{

    NNS_G3dGeBufferOP_N(G3OP_MTX_LOAD_4x4,
                        (u32 *) m,
                        G3OP_MTX_LOAD_4x4_NPARAMS);
}

static inline void NNS_G3dGeLoadMtx43 (const MtxFx43 * m)
{

    NNS_G3dGeBufferOP_N(G3OP_MTX_LOAD_4x3,
                        (u32 *) m,
                        G3OP_MTX_LOAD_4x3_NPARAMS);
}

static inline void NNS_G3dGeMultMtx44 (const MtxFx44 * m)
{

    NNS_G3dGeBufferOP_N(G3OP_MTX_MULT_4x4,
                        (u32 *) m,
                        G3OP_MTX_MULT_4x4_NPARAMS);
}

static inline void NNS_G3dGeMultMtx43 (const MtxFx43 * m)
{

    NNS_G3dGeBufferOP_N(G3OP_MTX_MULT_4x3,
                        (u32 *) m,
                        G3OP_MTX_MULT_4x3_NPARAMS);
}

static inline void NNS_G3dGeMultMtx33 (const MtxFx33 * m)
{

    NNS_G3dGeBufferOP_N(G3OP_MTX_MULT_3x3,
                        (u32 *) m,
                        G3OP_MTX_MULT_3x3_NPARAMS);
}

static inline void NNS_G3dGeShininess (const u32 * table)
{

    NNS_G3dGeBufferOP_N(G3OP_SHININESS,
                        table,
                        G3OP_SHININESS_NPARAMS);
}

// ---- glbstate ----
typedef enum {
    NNS_G3D_GLB_FLAG_FLUSH_WVP              = 0x00000001,
    NNS_G3D_GLB_FLAG_FLUSH_VP               = 0x00000002,
    NNS_G3D_GLB_FLAG_INVBASE_UPTODATE       = 0x00000004,
    NNS_G3D_GLB_FLAG_INVCAMERA_UPTODATE     = 0x00000008,
    NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE       = 0x00000010,
    NNS_G3D_GLB_FLAG_INVBASECAMERA_UPTODATE = 0x00000020,
    NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE = 0x00000040,
    NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE    = 0x00000080,
    NNS_G3D_GLB_FLAG_SRTCAMERA_UPTODATE     = NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE,
    NNS_G3D_GLB_FLAG_FLUSH_ALT              = NNS_G3D_GLB_FLAG_FLUSH_WVP
} NNSG3dGlbFlag;

typedef struct {
    u32 cmd0;
    u32 mtxmode_proj;
    MtxFx44 projMtx;
    u32 mtxmode_posvec;
    MtxFx43 cameraMtx;
    u32 cmd1;
    u32 lightVec[4];
    u32 cmd2;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmViewPort;
    u32 cmd3;
    u32 lightColor[4];
    u32 cmd4;
    MtxFx33 prmBaseRot;
    VecFx32 prmBaseTrans;
    VecFx32 prmBaseScale;
    u32 prmTexImageParam;
    u32 flag;
    MtxFx43 invCameraMtx;
    MtxFx43 srtCameraMtx;
    MtxFx43 invSrtCameraMtx;
    MtxFx43 invBaseMtx;
    MtxFx44 invProjMtx;
    MtxFx44 invCameraProjMtx;
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 camTarget;
} NNSG3dGlb;





void NNS_G3dGlbInit(void);
void NNS_G3dGlbFlushP(void);
void NNS_G3dGlbFlushVP(void);
void NNS_G3dGlbFlushWVP(void);
void NNS_G3dGlbSetBaseTrans(const VecFx32 * pTrans);
void NNS_G3dGlbSetBaseScale(const VecFx32 * pScale);
void NNS_G3dGlbLightVector(GXLightId lightID, fx16 x, fx16 y, fx16 z);
void NNS_G3dGlbLightColor(GXLightId lightID, GXRgb rgb);
void NNS_G3dGlbMaterialColorDiffAmb(GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor);
void NNS_G3dGlbMaterialColorSpecEmi(GXRgb specular, GXRgb emission, BOOL IsShininess);
void NNS_G3dGlbPolygonAttr(int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc);
const MtxFx43 * NNS_G3dGlbGetInvV(void);
const MtxFx43 * NNS_G3dGlbGetInvW(void);
const MtxFx44 * NNS_G3dGlbGetInvP(void);
const MtxFx43 * NNS_G3dGlbGetWV(void);
const MtxFx43 * NNS_G3dGlbGetInvWV(void);
const MtxFx44 * NNS_G3dGlbGetInvVP(void);

void NNS_G3dGlbGetViewPort(int * px1, int * py1, int * px2, int * py2);

extern NNSG3dGlb NNS_G3dGlb;

static inline void NNS_G3dGlbLookAt (const VecFx32 * camPos, const VecFx32 * camUp, const VecFx32 * target)
{
    NNS_G3dGlb.camPos = *camPos;
    NNS_G3dGlb.camUp = *camUp;
    NNS_G3dGlb.camTarget = *target;
    MTX_LookAt(camPos, camUp, target, &NNS_G3dGlb.cameraMtx);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVCAMERA_UPTODATE |
                         NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVBASECAMERA_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);

}

static inline void NNS_G3dGlbFrustum (fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f)
{
    MTX_Frustum(t,
                b,
                l,
                r,
                n,
                f,
                &NNS_G3dGlb.projMtx);

    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);
}

static inline void NNS_G3dGlbFrustumW (fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW)
{
    MTX_FrustumW(t,
                 b,
                 l,
                 r,
                 n,
                 f,
                 scaleW,
                 &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);
}

static inline void NNS_G3dGlbPerspective (fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f)
{
    MTX_Perspective(fovySin,
                    fovyCos,
                    aspect,
                    n,
                    f,
                    &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);
}

static inline void NNS_G3dGlbPerspectiveW (fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW)
{
    MTX_PerspectiveW(fovySin,
                     fovyCos,
                     aspect,
                     n,
                     f,
                     scaleW,
                     &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);
}

static inline void NNS_G3dGlbOrtho (fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f)
{
    MTX_Ortho(t,
              b,
              l,
              r,
              n,
              f,
              &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);
}

static inline void NNS_G3dGlbOrthoW (fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW)
{
    MTX_OrthoW(t,
               b,
               l,
               r,
               n,
               f,
               scaleW,
               &NNS_G3dGlb.projMtx);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);
}

static inline void NNS_G3dGlbSetProjectionMtx (const MtxFx44 * m)
{
    MI_CpuCopyFast(m, &NNS_G3dGlb.projMtx, sizeof(MtxFx44));
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVPROJ_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVCAMERAPROJ_UPTODATE);
}

static inline void NNS_G3dGlbSetBaseRot (const MtxFx33 * pRot)
{

    MTX_Copy33(pRot, &NNS_G3dGlb.prmBaseRot);
    NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVBASE_UPTODATE |
                         NNS_G3D_GLB_FLAG_INVBASECAMERA_UPTODATE);
}

static inline void NNS_G3dGlbSetViewPort (int x1, int y1, int x2, int y2)
{

    NNS_G3dGlb.prmViewPort = GX_PACK_VIEWPORT_PARAM(x1, y1, x2, y2);
}

static inline const MtxFx43 * NNS_G3dGlbGetCameraMtx (void)
{
    return &NNS_G3dGlb.cameraMtx;
}

static inline const MtxFx44 * NNS_G3dGlbGetProjectionMtx (void)
{
    return &NNS_G3dGlb.projMtx;
}

static inline const MtxFx33 * NNS_G3dGlbGetBaseRot (void)
{
    return &NNS_G3dGlb.prmBaseRot;
}

static inline const VecFx32 * NNS_G3dGlbGetBaseScale (void)
{
    return &NNS_G3dGlb.prmBaseScale;
}

static inline const VecFx32 * NNS_G3dGlbGetBaseTrans (void)
{
    return &NNS_G3dGlb.prmBaseTrans;
}

static inline const VecFx32 * NNS_G3dGlbGetCameraPos (void)
{
    return &NNS_G3dGlb.camPos;
}

static inline const VecFx32 * NNS_G3dGlbGetCameraUp (void)
{
    return &NNS_G3dGlb.camUp;
}

static inline const VecFx32 * NNS_G3dGlbGetCameraTarget (void)
{
    return &NNS_G3dGlb.camTarget;
}

static inline void NNS_G3dGlbFlush (void)
{
    NNS_G3dGlbFlushP();
}

static inline void NNS_G3dGlbFlushAlt (void)
{
    NNS_G3dGlbFlushWVP();
}

static inline const MtxFx43 * NNS_G3dGlbGetInvCameraMtx (void)
{
    return NNS_G3dGlbGetInvV();
}

static inline const MtxFx43 * NNS_G3dGlbGetSrtCameraMtx (void)
{
    return NNS_G3dGlbGetWV();
}

static inline const MtxFx43 * NNS_G3dGlbGetInvSrtCameraMtx (void)
{
    return NNS_G3dGlbGetInvWV();
}

// ---- util ----
static inline BOOL NNSi_G3dBitVecCheck(const u32 *vec, u32 idx) {
    return (BOOL)(vec[idx >> 5] & (1 << (idx & 31)));
}

static inline void NNSi_G3dBitVecSet(u32 *vec, u32 idx) {
    vec[idx >> 5] |= 1 << (idx & 31);
}

static inline void NNSi_G3dBitVecReset(u32 *vec, u32 idx) {
    vec[idx >> 5] &= ~(1 << (idx & 31));
}

void NNS_G3dGetCurrentMtx(MtxFx43 *m, MtxFx33 *n);
BOOL NNS_G3dGetResultMtx(const NNSG3dRenderObj *pRenderObj, MtxFx43 *pos, MtxFx33 *nrm, u32 nodeID);
BOOL NNS_G3dSetResultMtx(const NNSG3dRenderObj *pRenderObj, const MtxFx43 *pos, const MtxFx33 *nrm, u32 nodeID);
void NNS_G3dInit(void);
int NNS_G3dGetSbcCmdLen(const u8 *c);
const u8 *NNS_G3dSearchSbcCmd(const u8 *c, u8 cmd);
const u8 *NNS_G3dGetParentNodeID(int *parentID, const u8 *sbc, u32 nodeID);
int NNS_G3dGetChildNodeIDList(u8 *idList, const u8 *sbc, u32 nodeID);
BOOL NNS_G3dResDefaultSetup(void *pResData);
void NNS_G3dResDefaultRelease(void *pResData);
int NNS_G3dLocalOriginToScrPos(int *px, int *py);
int NNS_G3dWorldPosToScrPos(const VecFx32 *pWorld, int *px, int *py);
int NNS_G3dScrPosToWorldLine(int px, int py, VecFx32 *pNear, VecFx32 *pFar);

// ---- cgtool ----
typedef void (*NNSG3dGetJointScale)(NNSG3dJntAnmResult * pResult, const fx32 * p, const u8 * cmd, u32 srtflag);
typedef void (*NNSG3dSendJointSRT)(const NNSG3dJntAnmResult *);
typedef void (*NNSG3dSendTexSRT)(const NNSG3dMatAnmResult *);

extern NNSG3dGetJointScale NNS_G3dGetJointScale_FuncArray[NNS_G3D_FUNC_SENDJOINTSRT_MAX];
extern NNSG3dSendJointSRT NNS_G3dSendJointSRT_FuncArray[NNS_G3D_FUNC_SENDJOINTSRT_MAX];
extern NNSG3dSendTexSRT NNS_G3dSendTexSRT_FuncArray[NNS_G3D_FUNC_SENDTEXSRT_MAX];

// ---- sbc ----
#ifndef NNS_G3D_USE_EVPCACHE
#define NNS_G3D_USE_EVPCACHE 1
#endif

typedef enum {
    NNS_G3D_RSFLAG_NODE_VISIBLE           = 0x00000001,
    NNS_G3D_RSFLAG_MAT_TRANSPARENT        = 0x00000002,
    NNS_G3D_RSFLAG_CURRENT_NODE_VALID     = 0x00000004,
    NNS_G3D_RSFLAG_CURRENT_MAT_VALID      = 0x00000008,
    NNS_G3D_RSFLAG_CURRENT_NODEDESC_VALID = 0x00000010,
    NNS_G3D_RSFLAG_RETURN                 = 0x00000020,
    NNS_G3D_RSFLAG_SKIP                   = 0x00000040,
    NNS_G3D_RSFLAG_OPT_RECORD             = 0x00000080,
    NNS_G3D_RSFLAG_OPT_NOGECMD            = 0x00000100,
    NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW       = 0x00000200,
    NNS_G3D_RSFLAG_OPT_SKIP_SBCMTXCALC    = 0x00000400
} NNSG3dRSFlag;

typedef struct NNSG3dRS_ {
    u8 * c;
    NNSG3dRenderObj * pRenderObj;
    u32 flag;
    NNSG3dSbcCallBackFunc cbVecFunc[NNS_G3D_SBC_COMMAND_NUM];
    u8 cbVecTiming[NNS_G3D_SBC_COMMAND_NUM];
    u8 currentNode;
    u8 currentMat;
    u8 currentNodeDesc;
    u8 dummy_;
    NNSG3dMatAnmResult * pMatAnmResult;
    NNSG3dJntAnmResult * pJntAnmResult;
    NNSG3dVisAnmResult * pVisAnmResult;
    u32 isMatCached[NNS_G3D_SIZE_MAT_MAX / 32];
    u32 isScaleCacheOne[NNS_G3D_SIZE_JNT_MAX / 32];
#if (NNS_G3D_USE_EVPCACHE)
    u32 isEvpCached[NNS_G3D_SIZE_JNT_MAX / 32];
#endif
    const NNSG3dResNodeInfo * pResNodeInfo;
    const NNSG3dResMat * pResMat;
    const NNSG3dResShp * pResShp;
    fx32 posScale;
    fx32 invPosScale;
    NNSG3dGetJointScale funcJntScale;
    NNSG3dSendJointSRT funcJntMtx;
    NNSG3dSendTexSRT funcTexMtx;
    NNSG3dMatAnmResult tmpMatAnmResult;
    NNSG3dJntAnmResult tmpJntAnmResult;
    NNSG3dVisAnmResult tmpVisAnmResult;
} NNSG3dRS;

typedef struct NNSG3dRSOnGlb_ {
    struct NNSG3dMatAnmResult_ matCache[NNS_G3D_SIZE_MAT_MAX];
    struct {
        VecFx32 s;
        VecFx32 inv;
    } scaleCache[NNS_G3D_SIZE_JNT_MAX];

#if (NNS_G3D_USE_EVPCACHE)
    struct {
        MtxFx44 M;
        MtxFx33 N;
    } evpCache[NNS_G3D_SIZE_JNT_MAX];
#endif
} NNSG3dRSOnGlb;

typedef void (*NNSG3dFuncSbc)(NNSG3dRS *, u32);
typedef void (*NNSG3dFuncSbc_MatInternal)(NNSG3dRS *, u32, const NNSG3dResMatData *, u32);
typedef void (*NNSG3dFuncSbc_ShpInternal)(NNSG3dRS *, u32, const NNSG3dResShpData *, u32);

#define NNS_G3D_MTXSTACK_SYS  (30)
#define NNS_G3D_MTXSTACK_USER (29)


static inline NNSG3dSbcCallBackTiming NNSi_CheckPossibilityOfCallBack(NNSG3dRS *rs, u8 cmd);

void NNS_G3dDraw(struct NNSG3dRenderObj_ * pRenderObj);

void NNSi_G3dFuncSbc_NOP(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_RET(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_NODE(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_MTX(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_MAT(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_SHP(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_BB(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *, u32);
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *, u32);

void NNSi_G3dFuncSbc_SHP_InternalDefault(NNSG3dRS * rs, u32 opt, const NNSG3dResShpData * shp, u32 idxShp);
void NNSi_G3dFuncSbc_MAT_InternalDefault(NNSG3dRS * rs, u32 opt, const NNSG3dResMatData * mat, u32 idxMat);


extern NNSG3dFuncSbc NNS_G3dFuncSbcTable[NNS_G3D_SBC_COMMAND_NUM];
extern NNSG3dFuncSbc_MatInternal NNS_G3dFuncSbcMatTable[NNS_G3D_SIZE_MAT_VTBL_NUM];
extern NNSG3dFuncSbc_ShpInternal NNS_G3dFuncSbcShpTable[NNS_G3D_SIZE_SHP_VTBL_NUM];
extern NNSG3dRS * NNS_G3dRS;
extern NNSG3dRSOnGlb NNS_G3dRSOnGlb;

#ifndef NNS_G3D_SBC_CALLBACK_TIMING_A_DISABLE
static inline BOOL NNSi_G3dCallBackCheck_A (NNSG3dRS * rs, u8 cmd, NNSG3dSbcCallBackTiming * pTiming)
{
    *pTiming = NNSi_CheckPossibilityOfCallBack(rs, cmd);
    if (*pTiming == NNS_G3D_SBC_CALLBACK_TIMING_A) {
        rs->flag &= ~NNS_G3D_RSFLAG_SKIP;
        (*rs->cbVecFunc[cmd])(rs);

        *pTiming = NNSi_CheckPossibilityOfCallBack(rs, cmd);
        return (BOOL)(rs->flag & NNS_G3D_RSFLAG_SKIP);
    } else {
        return FALSE;
    }
}
#else
static inline BOOL NNSi_G3dCallBackCheck_A (NNSG3dRS * rs, u8 cmd, NNSG3dSbcCallBackTiming * pTiming)
{

    *pTiming = NNSi_CheckPossibilityOfCallBack(rs, cmd);
    return FALSE;
}
#endif

#ifndef NNS_G3D_SBC_CALLBACK_TIMING_B_DISABLE
static inline BOOL NNSi_G3dCallBackCheck_B (NNSG3dRS * rs, u8 cmd, NNSG3dSbcCallBackTiming * pTiming)
{
    if (*pTiming == NNS_G3D_SBC_CALLBACK_TIMING_B) {
        rs->flag &= ~NNS_G3D_RSFLAG_SKIP;
        (*rs->cbVecFunc[cmd])(rs);

        *pTiming = NNSi_CheckPossibilityOfCallBack(rs, cmd);
        return (BOOL)(rs->flag & NNS_G3D_RSFLAG_SKIP);
    } else {
        return FALSE;
    }
}
#else
static inline BOOL NNSi_G3dCallBackCheck_B (NNSG3dRS *, u8, NNSG3dSbcCallBackTiming *) {
    return FALSE;
}
#endif

#ifndef NNS_G3D_SBC_CALLBACK_TIMING_C_DISABLE
static inline BOOL NNSi_G3dCallBackCheck_C (NNSG3dRS * rs, u8 cmd, NNSG3dSbcCallBackTiming timing)
{
    if (timing == NNS_G3D_SBC_CALLBACK_TIMING_C) {
        rs->flag &= ~NNS_G3D_RSFLAG_SKIP;
        (*rs->cbVecFunc[cmd])(rs);

        return (BOOL)(rs->flag & NNS_G3D_RSFLAG_SKIP);
    } else {
        return FALSE;
    }
}
#else
static inline BOOL NNSi_G3dCallBackCheck_C (NNSG3dRS *, u8, NNSG3dSbcCallBackTiming) {
    return FALSE;
}
#endif

static inline NNSG3dSbcCallBackTiming NNSi_CheckPossibilityOfCallBack (NNSG3dRS * rs, u8 cmd)
{
    if (rs->cbVecFunc[cmd]) {
        return (NNSG3dSbcCallBackTiming)rs->cbVecTiming[cmd];
    } else {
        return NNS_G3D_SBC_CALLBACK_TIMING_NONE;
    }
}

static inline void NNS_G3dRSSetCallBack (NNSG3dRS * rs, NNSG3dSbcCallBackFunc func, u8 cmd, NNSG3dSbcCallBackTiming timing)
{

    rs->cbVecFunc[cmd] = func;
    rs->cbVecTiming[cmd] = timing;
}

static inline void NNS_G3dRSResetCallBack (NNSG3dRS * rs, u8 cmd)
{

    rs->cbVecFunc[cmd] = NULL;
    rs->cbVecTiming[cmd] = (u8)NNS_G3D_SBC_CALLBACK_TIMING_NONE;
}

static inline NNSG3dRenderObj * NNS_G3dRSGetRenderObj (NNSG3dRS * rs)
{
    return rs->pRenderObj;
}

static inline NNSG3dMatAnmResult * NNS_G3dRSGetMatAnmResult (NNSG3dRS * rs)
{
    return rs->pMatAnmResult;
}

static inline NNSG3dJntAnmResult * NNS_G3dRSGetJntAnmResult (NNSG3dRS * rs)
{
    return rs->pJntAnmResult;
}

static inline NNSG3dVisAnmResult * NNS_G3dRSGetVisAnmResult (NNSG3dRS * rs)
{
    return rs->pVisAnmResult;
}

static inline u8 * NNS_G3dRSGetSbcPtr (NNSG3dRS * rs)
{
    return rs->c;
}

static inline void NNS_G3dRSSetFlag (NNSG3dRS * rs, NNSG3dRSFlag flag)
{
    rs->flag |= flag;
}

static inline void NNS_G3dRSResetFlag (NNSG3dRS * rs, NNSG3dRSFlag flag)
{
    rs->flag &= ~flag;
}

static inline int NNS_G3dRSGetCurrentMatID (const NNSG3dRS * rs)
{
    if (rs->flag & NNS_G3D_RSFLAG_CURRENT_MAT_VALID) {
        return rs->currentMat;
    } else {
        return -1;
    }
}

static inline int NNS_G3dRSGetCurrentNodeID (const NNSG3dRS * rs)
{
    if (rs->flag & NNS_G3D_RSFLAG_CURRENT_NODE_VALID) {
        return rs->currentNode;
    } else {
        return -1;
    }
}

static inline int NNS_G3dRSGetCurrentNodeDescID (const NNSG3dRS * rs)
{
    if (rs->flag & NNS_G3D_RSFLAG_CURRENT_NODEDESC_VALID) {
        return rs->currentNodeDesc;
    } else {
        return -1;
    }
}

static inline fx32 NNS_G3dRSGetPosScale (const NNSG3dRS * rs)
{
    return rs->posScale;
}

static inline fx32 NNS_G3dRSGetInvPosScale (const NNSG3dRS * rs)
{
    return rs->invPosScale;
}

#ifdef __cplusplus
}
#endif

#endif
