#pragma pool_strings on
#pragma dont_reuse_strings off
#include "Main/Lang/LangData.h"
#include "Main/Res/ResMgr.h"

struct LangRes2 {
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

extern LangTbl2 data_0214b160;
extern const u32 data_0208b318[];
extern const char *data_0208ccb0;
extern const char *data_0208cca4;
extern void *func_0203dd9c(u32 size);
extern void func_0206e900(char *dst, const char *src);

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
    LangRes2 *res = (LangRes2 *)func_0203dd9c(sizeof(LangRes2));
    if (res != NULL) {
        *(const u32 **)res = data_0208b318;
        res->Clear();
    }
    return res;
}

void func_0206f9dc(void) {
    char arcName[0x20];
    char name[0x20];
    LangRes2 *res = LangRes2_New();
    data_0214b160.res = res;
    res->type = 0;
    func_0206e900(arcName, data_0208ccb0);
    func_0206e900(name, data_0208cca4);
    data_0214b160.res->Open(arcName, name);
}

void func_0206fa70(void) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (data_0214b160.res != NULL) {
        if (data_0214b160.res != NULL) {
            data_0214b160.res->DeletingDtor();
        }
        data_0214b160.res = NULL;
    }
    data_02097dd0->cur = saved;
}

void func_0206facc(void) {
    data_0214b160.res->Load();
}


void func_0206faec(void) {
    LangNamedTable *t;
    void **data;
    if (data_0214b160.res->IsLoaded()) {
        return;
    }
    data_0214b160.res->unk_vf30();
    data = data_0214b160.res->GetData();
    data_0214b160.items[0] = LangTbl_Find(data, "mc");
    data_0214b160.items[1] = LangTbl_Find(data, "sc");
    data_0214b160.items[2] = LangTbl_Find(data, "nc");
    data_0214b160.items[3] = LangTbl_Find(data, "gm");
    data_0214b160.items[4] = LangTbl_Find(data, "en");
    data_0214b160.items[5] = LangTbl_Find(data, "so");
    data_0214b160.items[6] = LangTbl_Find(data, "ac");
    data_0214b160.items[7] = LangTbl_Find(data, "fs");
}

}
