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

u8 *LangSec_SkipGfxEnv(LangSecFlags *flags, u8 *p);

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

void LangData_MakeAreaInfoPath(char *dst, const LangId *id);

void LangData_MakeRadarPath(char *dst, const LangId *id);

void LangData_MakeBlockPath(char *dst, const LangId *id);

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
extern char gCommonTextPath[];
extern char data_0208cc36[];
void LangData_LocalizePath(char *dst, const char *src);

// The path of the language's base file. It is this TU's .data (only LangData_InitLanguage reads it), and
// that matters for the schedule: a load from an object the TU defines is not disambiguated from the
// store to the extern gLang, so each arm stores the language before it reads the path
// (round bgQ2). As an extern the load is hoisted above the store.
const char *ArcPath_MenuCmnText = data_0208cc36;

// Sets the game language from the owner info (1-5, anything else 1) and builds the language's file
// name into gCommonTextPath from the base path (twice, as the ROM does).
void LangData_InitLanguage(void) {
    OSOwnerInfo info;
    OS_GetOwnerInfo(&info);
    switch (info.language) {
    case 1:
        gLang.lang = 1;
        LangData_LocalizePath(gCommonTextPath, ArcPath_MenuCmnText);
        break;
    case 2:
        gLang.lang = 2;
        LangData_LocalizePath(gCommonTextPath, ArcPath_MenuCmnText);
        break;
    case 3:
        gLang.lang = 3;
        LangData_LocalizePath(gCommonTextPath, ArcPath_MenuCmnText);
        break;
    case 4:
        gLang.lang = 4;
        LangData_LocalizePath(gCommonTextPath, ArcPath_MenuCmnText);
        break;
    case 5:
        gLang.lang = 5;
        LangData_LocalizePath(gCommonTextPath, ArcPath_MenuCmnText);
        break;
    default:
        gLang.lang = 1;
        LangData_LocalizePath(gCommonTextPath, ArcPath_MenuCmnText);
        break;
    }
    LangData_LocalizePath(gCommonTextPath, ArcPath_MenuCmnText);
}

u8 LangData_GetLang(void) {
    return gLang.lang;
}

extern char data_0208cc6f[];
extern char data_0208cc73[];
extern char data_0208cc77[];
extern char data_0208cc7b[];
extern char data_0208cc7f[];
extern char data_0208cc83[];

void LangData_LocalizePath(char *dst, const char *src) {
    char ext[8];
    char buf[0x20];
    const char *suffix;
    char *dot;

    switch (gLang.lang) {
    case 1:
        suffix = data_0208cc6f;
        break;
    case 2:
        suffix = data_0208cc73;
        break;
    case 3:
        suffix = data_0208cc77;
        break;
    case 4:
        suffix = data_0208cc7b;
        break;
    case 5:
        suffix = data_0208cc7f;
        break;
    default:
        suffix = data_0208cc6f;
        break;
    }
    STD_CopyString(buf, src);
    dot = STD_SearchString(buf, data_0208cc83);
    if (dot == NULL) {
        ext[0] = 0;
    } else {
        STD_CopyString(ext, dot);
        *dot = 0;
    }
    STD_ConcatenateString(buf, suffix);
    STD_ConcatenateString(buf, ext);
    STD_CopyString(dst, buf);
}

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
    virtual BOOL Load();
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

void LangData_CreateRes(void) {
    char arcName[0x20];
    char name[0x20];
    LangRes *res = LangRes_New();
    gParamRes.res = res;
    res->type = 0;
    LangData_LocalizePath(arcName, ArcPath_GameParam);
    LangData_LocalizePath(name, ResName_ItemParam);
    gParamRes.res->Open(arcName, name);
}

void LangData_DeleteRes(void) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (gParamRes.res != NULL) {
        if (gParamRes.res != NULL) {
            gParamRes.res->DeletingDtor();
        }
        gParamRes.res = NULL;
    }
    gSysState->cur = saved;
}

BOOL Param_LoadRes(void) {
    return gParamRes.res->Load();
}

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

void Param_BindTables(void) {
    void **data;
    if (gParamRes.res->IsLoaded()) {
        return;
    }
    gParamRes.res->unk_vf30();
    data = gParamRes.res->GetData();
    gParamRes.items[0] = NamedTable_Find(*data, data_0208cccc);
    gParamRes.items[1] = NamedTable_Find(*data, data_0208ccd0);
    gParamRes.items[2] = NamedTable_Find(*data, data_0208ccd7);
    gParamRes.items[3] = NamedTable_Find(*data, data_0208ccdf);
    gParamRes.items[4] = NamedTable_Find(*data, data_0208cced);
    gParamRes.items[5] = NamedTable_Find(*data, data_0208ccfd);
    gParamRes.items[6] = NamedTable_Find(*data, data_0208cd0d);
    gParamRes.items[7] = NamedTable_Find(*data, data_0208cd19);
    gParamRes.items[8] = NamedTable_Find(*data, data_0208cd24);
    gParamRes.items[9] = NamedTable_Find(*data, data_0208cd2f);
    gParamRes.items[10] = NamedTable_Find(*data, data_0208cd39);
    gParamRes.items[11] = NamedTable_Find(*data, data_0208cd47);
    gParamRes.items[12] = NamedTable_Find(*data, data_0208cd4f);
}

}
