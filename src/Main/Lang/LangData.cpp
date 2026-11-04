#include "Main/Lang/LangData.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"

extern "C" {

extern char data_0208cb68[];
extern char data_0208cb6b[];
extern char data_0208cb6d[];
extern char data_0208cb70[];

typedef struct LangBlockA {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ LangSecFlags flags;
    /* 0x0a */ u8 count0;
    /* 0x0b */ u8 count1;
    /* 0x0c */ u8 count2;
    /* 0x0d */ u8 unk_0d[3];
    /* 0x10 */ u8 data[1];
} LangBlockA;

typedef struct LangBlockB {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ LangSecFlags flags;
    /* 0x0a */ u8 unk_0a[0xa];
    /* 0x14 */ u8 count0;
    /* 0x15 */ u8 count1;
    /* 0x16 */ u8 count2;
    /* 0x17 */ u8 count3;
    /* 0x18 */ u8 count4;
    /* 0x19 */ u8 unk_19[3];
    /* 0x1c */ u8 data[1];
} LangBlockB;

u8 LangData_GetLang(void);

typedef struct LangId {
    u8 group;
    u8 num;
    u8 num2;
} LangId;

u8 *LangSec_SkipGfxEnv(LangSecFlags *flags, u8 *p) {
    if (flags->sec0) {
        p += 4;
    }
    if (flags->sec1) {
        p += 0x40;
    }
    if (flags->sec2) {
        p += 0x10;
    }
    if (flags->sec3) {
        p += 0x28;
    }
    if (flags->sec4) {
        p += 8;
    }
    if (flags->sec5) {
        p += 8;
    }
    if (flags->sec6) {
        p += 0xc;
    }
    return p;
}

#define LANGDATA_PUTNUM(dst, len, num) \
    {                                   \
        u8 n = (num);                   \
        u8 d;                           \
        d = n / 100;                    \
        if (d != 0) {                   \
            dst[len] = d + '0';         \
            len++;                      \
        }                               \
        n -= (u8)(d * 100);             \
        d = n / 10;                     \
        if (d != 0) {                   \
            dst[len] = d + '0';         \
            len++;                      \
        }                               \
        n -= (u8)(d * 10);              \
        dst[len] = n + '0';             \
        len++;                          \
    }

#define LANGDATA_PUTNUM2(dst, len, n, d) \
    d = n / 100;                        \
    if (d != 0) {                       \
        dst[len] = d + '0';             \
        len++;                          \
    }                                   \
    n -= (u8)(d * 100);                 \
    d = n / 10;                         \
    if (d != 0) {                       \
        dst[len] = d + '0';             \
        len++;                          \
    }                                   \
    n -= (u8)(d * 10);                  \
    dst[len] = n + '0';                 \
    len++;

void LangData_MakeAreaInfoPath(char *dst, const LangId *id) {
    LangGroup *group = &gWorldInfo->groups[id->group];
    int len;

    STD_CopyString(dst, data_0208cb68);
    STD_ConcatenateString(dst, group->dir);
    STD_ConcatenateString(dst, data_0208cb6b);
    len = STD_GetStringLength(dst);
    LANGDATA_PUTNUM(dst, len, id->num);
    {
        const char *ext = LangData_PathTable[1];
        dst[len] = 0;
        STD_ConcatenateString(dst, ext);
    }
}

void LangData_MakeRadarPath(char *dst, const LangId *id) {
    LangGroup *group = &gWorldInfo->groups[id->group];
    int len;

    STD_CopyString(dst, data_0208cb6d);
    STD_ConcatenateString(dst, group->dir);
    STD_ConcatenateString(dst, data_0208cb6b);
    len = STD_GetStringLength(dst);
    LANGDATA_PUTNUM(dst, len, id->num);
    dst[len] = 0;
    STD_ConcatenateString(dst, LangData_PathTable[1]);
}

void LangData_MakeBlockPath(char *dst, const LangId *id) {
    LangGroup *group = &gWorldInfo->groups[id->group];
    int len;

    STD_CopyString(dst, data_0208cb70);
    STD_ConcatenateString(dst, group->dir);
    STD_ConcatenateString(dst, data_0208cb6b);
    len = STD_GetStringLength(dst);
    LANGDATA_PUTNUM(dst, len, id->num);
    dst[len] = '_';
    {
        u8 n; int len2; u8 d;
        n = id->num2;
        len2 = len + 1;
        LANGDATA_PUTNUM2(dst, len2, n, d)
        dst[len2] = 0;
    }
    STD_ConcatenateString(dst, LangData_PathTable[1]);
}

u8 *LangBlockA_GetData(LangBlockA *b);

u8 *LangBlockA_GetData1(LangBlockA *b);

u8 *LangBlockA_GetData2(LangBlockA *b);

u8 *LangBlockB_GetLangEntry(LangBlockB *b);

u8 *LangBlockB_GetData0(LangBlockB *b);

u8 *LangBlockB_GetData(LangBlockB *b);

u8 *LangBlockB_GetData2(LangBlockB *b);

u8 *LangBlockB_GetData3(LangBlockB *b);

u8 *LangBlockB_GetData4(LangBlockB *b);

typedef struct GfxEnv {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 unk_01[4];
    /* 0x05 */ u8 alpha;
    /* 0x06 */ u16 color;
    /* 0x08 */ u32 fogShift;
    /* 0x0c */ u32 fogOffset;
    /* 0x10 */ u16 fogMode;
    /* 0x12 */ u16 fogAlpha;
    /* 0x14 */ u16 fogColor;
    /* 0x16 */ u8 unk_16[2];
    /* 0x18 */ u8 fogTable[0x20];
    /* 0x38 */ u32 toonMode;
    /* 0x3c */ u8 toonTable[0x40];
    /* 0x7c */ u8 edgeTable[0x10];
    /* 0x8c */ VecFx16 lightDir;
    /* 0x92 */ u8 unk_92[0x12];
    /* 0xa4 */ u16 lightColor;
    /* 0xa6 */ u8 unk_a6[6];
    /* 0xac */ u16 unk_ac;
    /* 0xae */ u16 unk_ae;
    /* 0xb0 */ u16 unk_b0;
    /* 0xb2 */ u16 unk_b2;
} GfxEnv;

typedef struct LangCamera {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s16 sin;
    /* 0x0a */ s16 cos;
    /* 0x0c */ s16 dist;
    /* 0x0e */ u16 angle;
    /* 0x10 */ s32 deg;
    /* 0x14 */ u8 unk_14[2];
    /* 0x16 */ u8 dirty;
} LangCamera;


#define REG_DISP3DCNT (*(vu16 *)0x04000060)
#define REG_FOG_COLOR (*(vu32 *)0x04000358)

static inline void LangCamera_SetPos(LangCamera *cam, s32 x, s32 y) {
    cam->x = x;
    cam->y = y;
    cam->dirty = 1;
}

static inline void LangCamera_SetDist(LangCamera *cam, s16 dist) {
    cam->dist = dist;
    cam->dirty = 1;
}

static inline void LangCamera_SetAngle(LangCamera *cam, u16 angle) {
    cam->angle = angle;
    cam->deg = (s32)(((u64)angle * 0x1680000 + 0x80000) >> 20);
    cam->sin = FX_SinCosTable_[((angle / 2) >> 4) * 2];
    cam->cos = FX_SinCosTable_[((angle / 2) >> 4) * 2 + 1];
    cam->dirty = 1;
}

static inline void LangData_SetFogColor(u16 color, u16 alpha) {
    REG_FOG_COLOR = color | (alpha << 16);
}

void LangSec_ApplyGfxEnv(LangSecFlags *flags, const u8 *p);

void LangBlockB_ApplyGfxEnv(LangBlockB *b);

void LangBlockA_ApplyGfxEnv(LangBlockA *b);

void LangData_LocalizePath(char *dst, const char *src);
void LangData_BindWorldInfo(void);

typedef struct LangArc {
    /* 0x00 */ u8 unk_00[0x44];
    /* 0x44 */ u32 unk_44;
} LangArc;

extern LangArc gWorldInfoRes;
void ResHandle_LoadSync(LangArc *arc, const char *name);
void ResHandle_Unload(LangArc *arc);
void *ResHandle_GetData(LangArc *arc);
LangTable **ResList_FindType0(void *res, const char *name);

void LangData_LoadWorldInfo(void);

void LangData_UnloadWorldInfo(void);

void LangData_BindWorldInfo(void);

LangGroup *Lang_GetGroup(int i);

u16 LangData_GetIndex(int group, int index);

typedef struct OSOwnerInfo {
    u8 language;
    u8 unk_01[0x53];
} OSOwnerInfo;

void OS_GetOwnerInfo(OSOwnerInfo *info);
extern const char *ArcPath_MenuCmnText;
extern char gCommonTextPath[];

void LangData_InitLanguage(void);

u8 LangData_GetLang(void);

extern char data_0208cc6f[];
extern char data_0208cc73[];
extern char data_0208cc77[];
extern char data_0208cc7b[];
extern char data_0208cc7f[];
extern char data_0208cc83[];

void LangData_LocalizePath(char *dst, const char *src);

}

struct LangRes {
    /* 0x00 */ // vtable (ResHandle_vtbl)
    virtual void unk_vf00();
    virtual void DeletingDtor();
    virtual void Clear();
    virtual void Unload();
    virtual void **GetData();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20();
    virtual void Open(char *arcName, char *name);
    virtual void unk_vf28();
    virtual void Load();
    virtual void unk_vf30();
    virtual BOOL IsLoaded();
    /* 0x04 */ char arcName[0x20];
    /* 0x24 */ char name[0x20];
    /* 0x44 */ int type;
    /* 0x48 */ u8 loaded;
};

extern "C" {

typedef struct LangMsgTbl {
    /* 0x00 */ LangRes *res;
    /* 0x04 */ void *items[13];
} LangMsgTbl;

extern LangMsgTbl gParamRes;
extern const u32 ResHandle_vtbl[];
extern const char *ArcPath_GameParam;
extern const char *ResName_ItemParam;
extern void *Heap_Alloc(u32 size);
void *NamedTable_Find(void *data, const char *name);

static inline LangRes *LangRes_New(void) {
    LangRes *res = (LangRes *)Heap_Alloc(sizeof(LangRes));
    if (res != NULL) {
        *(const u32 **)res = ResHandle_vtbl;
        res->Clear();
    }
    return res;
}

void LangData_CreateRes(void);

void LangData_DeleteRes(void);

BOOL Param_LoadRes(void);

extern char data_0208cccc[];
extern char data_0208ccd0[];
extern char data_0208ccd7[];
extern char data_0208ccdf[];
extern char data_0208cced[];
extern char data_0208ccfd[];
extern char data_0208cd0d[];
extern char data_0208cd19[];
extern char data_0208cd24[];
extern char data_0208cd2f[];
extern char data_0208cd39[];
extern char data_0208cd47[];
extern char data_0208cd4f[];

void Param_BindTables(void);

}
