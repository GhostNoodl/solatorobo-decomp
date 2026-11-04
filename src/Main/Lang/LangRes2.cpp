#pragma pool_strings on
#pragma dont_reuse_strings off
#include "Main/Lang/LangData.h"
#include "Main/Res/ResMgr.h"

struct LangRes2 {
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

typedef struct LangNamedEntry {
    /* 0x0 */ u32 nameOffset;
    /* 0x4 */ u32 dataOffset;
} LangNamedEntry;

typedef struct LangNamedTable {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u32 count;
    /* 0x10 */ LangNamedEntry entries[1];
} LangNamedTable;

typedef struct LangTbl2 {
    /* 0x00 */ LangRes2 *res;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ void *items[8];
} LangTbl2;

extern LangTbl2 gTblRes;
extern const u32 ResHandle_vtbl[];
extern const char *ArcPath_GameParam;
extern const char *ResName_GoParam;
extern void *Heap_Alloc(u32 size);
extern void LangData_LocalizePath(char *dst, const char *src);

static inline void *LangTbl_Find(void **data, const char *name) {
    const char *nm = name;
    LangNamedTable *t = (LangNamedTable *)*data;
    u32 i;
    for (i = 0; i < t->count; i++) {
        const char *s = (const char *)t + t->entries[i].nameOffset;
        if (s[0] == nm[0] && s[1] == nm[1] && STD_CompareString(s, nm) == 0) {
            return (u8 *)t + t->entries[i].dataOffset;
        }
    }
    return NULL;
}

static inline LangRes2 *LangRes2_New(void) {
    LangRes2 *res = (LangRes2 *)Heap_Alloc(sizeof(LangRes2));
    if (res != NULL) {
        *(const u32 **)res = ResHandle_vtbl;
        res->Clear();
    }
    return res;
}

void LangRes2_Create(void) {
    char arcName[0x20];
    char name[0x20];
    LangRes2 *res = LangRes2_New();
    gTblRes.res = res;
    res->type = 0;
    LangData_LocalizePath(arcName, ArcPath_GameParam);
    LangData_LocalizePath(name, ResName_GoParam);
    gTblRes.res->Open(arcName, name);
}

void LangRes2_Delete(void) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (gTblRes.res != NULL) {
        if (gTblRes.res != NULL) {
            gTblRes.res->DeletingDtor();
        }
        gTblRes.res = NULL;
    }
    gSysState->cur = saved;
}

BOOL LangRes2_Load(void) {
    return gTblRes.res->Load();
}


void LangRes2_BindTables(void) {
    void **data;
    if (gTblRes.res->IsLoaded()) {
        return;
    }
    gTblRes.res->unk_vf30();
    data = gTblRes.res->GetData();
    gTblRes.items[0] = LangTbl_Find(data, "mc");
    gTblRes.items[1] = LangTbl_Find(data, "sc");
    gTblRes.items[2] = LangTbl_Find(data, "nc");
    gTblRes.items[3] = LangTbl_Find(data, "gm");
    gTblRes.items[4] = LangTbl_Find(data, "en");
    gTblRes.items[5] = LangTbl_Find(data, "so");
    gTblRes.items[6] = LangTbl_Find(data, "ac");
    gTblRes.items[7] = LangTbl_Find(data, "fs");
}

}
