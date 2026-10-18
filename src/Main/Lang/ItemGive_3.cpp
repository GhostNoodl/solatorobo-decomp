#include "Main/Res/StageCmd.h"
#include "Main/Res/DataRes.h"

extern "C" {

extern u8 *data_0208d268[];
extern s32 func_0206d2ec(StageFlags *f, u16 id, u32 n);
extern s32 func_0206d2a4(StageFlags *f, u16 id, u8 n);
extern u8 func_0206d1d4(StageFlags *f, u16 id);
extern void func_02059280(DataRes *res, SaveRef *ref, u32 idx, u16 unk);
extern u16 func_0205973c(DataRes *res, SaveRef *ref, u32 id);
extern void func_02059428(DataRes *res, SaveRef *ref, u32 id, u16 val);
extern u32 func_0205975c(DataRes *res, u32 idx);
extern SaveEntry *func_0205976c(DataRes *res, u32 idx);
extern u16 func_02059544(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id);
extern int func_0201e7b0(const char *a, const char *b);

static inline u16 Item_Cat(u32 id) {
    return id >> 12;
}

static inline u16 Item_Idx(u32 id) {
    return id & 0xfff;
}

void func_0206f518(SaveRef *ref, u32 id);

static inline void Item_Notify(u16 id, u16 val) {
    SaveRef ref;
    func_0206f518(&ref, id);
    if (ref.idx == -1) {
        return;
    }
    func_0205973c(data_02fe152c, &ref, id);
    func_02059428(data_02fe152c, &ref, id, val);
}

static inline BOOL Item_Set(u16 id, u16 val) {
    SaveRef ref;
    BOOL ok;
    u16 old;
    func_0206f518(&ref, id);
    if (ref.idx == -1) {
        return FALSE;
    }
    old = func_0205973c(data_02fe152c, &ref, id);
    func_02059428(data_02fe152c, &ref, id, val);
    ok = TRUE;
    if (old != 0) {
        ok = FALSE;
    }
    return ok ? TRUE : FALSE;
}

BOOL func_0206f21c(u16 id, int n);

void func_0206f3f0(u16 id, int n);

void func_0206f518(SaveRef *ref, u32 id);

BOOL func_0206f5e4(u16 id, int n);

BOOL func_0206f66c(u16 id);

typedef struct ItemDef {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ s16 parts[4];
} ItemDef;

u16 func_0206f6d4(s32 id, s32 *slot);

u16 func_0206f788(u16 id);

BOOL func_0206f85c(u32 n);

BOOL func_0206f954(void) {
    return func_0206f85c(9);
}

typedef struct NamedEntry {
    /* 0x0 */ u32 nameOffset;
    /* 0x4 */ u32 dataOffset;
} NamedEntry;

typedef struct NamedTable {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u32 count;
    /* 0x10 */ NamedEntry entries[1];
} NamedTable;

void *func_0206f964(NamedTable *t, const char *name) {
    u32 i;
    for (i = 0; i < t->count; i++) {
        const char *s = (const char *)t + t->entries[i].nameOffset;
        if (s[0] == name[0] && s[1] == name[1] && func_0201e7b0(s, name) == 0) {
            return (u8 *)t + t->entries[i].dataOffset;
        }
    }
    return NULL;
}

}
