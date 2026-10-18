#include "Main/Lang/LangData.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/fx.h"

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

u8 func_0206e8f0(void);

typedef struct LangId {
    u8 group;
    u8 num;
    u8 num2;
} LangId;

u8 *func_0206dd6c(LangSecFlags *flags, u8 *p);

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

void func_0206dde4(char *dst, const LangId *id);

void func_0206dedc(char *dst, const LangId *id);

void func_0206dfd4(char *dst, const LangId *id);

u8 *func_0206e150(LangBlockA *b);

u8 *func_0206e180(LangBlockA *b);

u8 *func_0206e1bc(LangBlockA *b);

u8 *func_0206e200(LangBlockB *b);

u8 *func_0206e230(LangBlockB *b);

u8 *func_0206e264(LangBlockB *b);

u8 *func_0206e2a4(LangBlockB *b);

u8 *func_0206e2ec(LangBlockB *b);

u8 *func_0206e340(LangBlockB *b);

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

typedef struct LangGame54 {
    u8 unk_00[0x11c];
    LangCamera camera;
} LangGame54;

extern LangGame54 *data_ov000_021ccd54;

void G3X_SetClearColor(u16 color, int a, int b, u8 alpha, int c);
void G3X_SetToonTable(const void *p);
void G3X_SetEdgeColorTable(const void *p);
void G3X_SetFogTable(const void *p);
void G3X_SetFog(BOOL enable, int mode, int slope, int offset);
void MIi_CpuCopyFast(const void *src, void *dst, u32 size);

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

void func_0206e3a0(LangSecFlags *flags, const u8 *p);

void func_0206e648(LangBlockB *b) {
    func_0206e3a0(&b->flags, b->data);
}

void func_0206e660(LangBlockA *b) {
    func_0206e3a0(&b->flags, b->data);
}

void func_0206e900(char *dst, const char *src);
void func_0206e6e4(void);

typedef struct LangArc {
    /* 0x00 */ u8 unk_00[0x44];
    /* 0x44 */ u32 unk_44;
} LangArc;

extern LangArc data_0214b0b8;
void func_02038638(LangArc *arc, const char *name);
void func_02038520(LangArc *arc);
void *func_02038dbc(LangArc *arc);
LangTable **func_02034b98(void *res, const char *name);

void func_0206e678(void) {
    char buf[0x20];
    data_0214b0b8.unk_44 = 7;
    func_0206e900(buf, data_02082bf8[2]);
    func_02038638(&data_0214b0b8, buf);
    func_0206e6e4();
}

void func_0206e6c0(void) {
    func_02038520(&data_0214b0b8);
    data_0214b0a8 = NULL;
}

void func_0206e6e4(void) {
    char buf[0x18];
    void *res = func_02038dbc(&data_0214b0b8);
    LangTable *table;
    LangGroup *group;
    char *str;
    u8 i;

    STD_CopyString(buf, data_02082bf8[0]);
    STD_ConcatenateString(buf, data_02082bf8[1]);
    func_0206e900(buf, buf);
    table = *func_02034b98(res, buf);
    data_0214b0a8 = table;
    group = table->groups;
    str = (char *)table + table->strOffset + 4;
    i = 0;
    if (i < table->numGroups) {
        for (; i < data_0214b0a8->numGroups; i++) {
            group->name = str;
            str += STD_GetStringLength(str) + 1;
            group->dir = str;
            str += STD_GetStringLength(str) + 1;
            group->unk_08 = str;
            str += STD_GetStringLength(str) + 1;
            group++;
        }
    }
}

LangGroup *func_0206e7d0(int i) {
    return &data_0214b0a8->groups[i];
}

u16 func_0206e7ec(int group, int index) {
    u16 sum;
    int i;
    LangGroup *groups;
    if (group == 0xff || index == 0xff) {
        return 0xffff;
    }
    sum = 0;
    groups = data_0214b0a8->groups;
    for (i = 0; i < group; i++) {
        sum += groups[i].count;
    }
    return sum + index;
}

typedef struct OSOwnerInfo {
    u8 language;
    u8 unk_01[0x53];
} OSOwnerInfo;

void OS_GetOwnerInfo(OSOwnerInfo *info);
extern const char *data_0208cb88;
extern char data_0214b105[];

void func_0206e858(void);

u8 func_0206e8f0(void);

extern char data_0208cc6f[];
extern char data_0208cc73[];
extern char data_0208cc77[];
extern char data_0208cc7b[];
extern char data_0208cc7f[];
extern char data_0208cc83[];

void func_0206e900(char *dst, const char *src);

}

struct LangRes {
    /* 0x00 */ // vtable (data_0208b318)
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

extern LangMsgTbl data_0214b128;
extern const u32 data_0208b318[];
extern const char *data_0208ccb0;
extern const char *data_0208cca8;
extern void *func_0203dd9c(u32 size);
void *func_0206f964(void *data, const char *name);

static inline LangRes *LangRes_New(void) {
    LangRes *res = (LangRes *)func_0203dd9c(sizeof(LangRes));
    if (res != NULL) {
        *(const u32 **)res = data_0208b318;
        res->Clear();
    }
    return res;
}

void func_0206e9e8(void);

void func_0206ea7c(void);

void func_0206ead8(void);

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

void func_0206eaf8(void);

}
