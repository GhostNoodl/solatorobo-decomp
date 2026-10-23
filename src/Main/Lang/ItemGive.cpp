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
extern int STD_CompareString(const char *a, const char *b);

static inline u16 Item_Cat16(u16 id) {
    return id >> 12;
}

static inline u16 Item_Idx16(u16 id) {
    return id & 0xfff;
}

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

BOOL func_0206f21c(u16 id, int n) {
    BOOL ok = TRUE;
    switch (Item_Cat(id) - 1) {
    case 1: {
        s32 v = -1;
        if (n != 0) {
            if (data_0214a424->itemTotal >= 100) {
                ok = FALSE;
            } else {
                v = func_0206d2ec(data_0214a424, id, 1);
            }
        } else {
            v = func_0206d2ec(data_0214a424, id, -1);
        }
        if (v == -1) {
            break;
        }
        if (v == 0) {
            Item_Notify(id, 0);
        } else {
            Item_Notify(id, 1);
        }
        break;
    }
    case 3:
    case 4:
    case 5:
    case 6:
        ok = Item_Set(id, n);
        break;
    case 7:
        ok = Item_Set(id, n);
        break;
    }
    return ok;
}

void func_0206f3f0(u16 id, int n) {
    if (Item_Cat(id) - 1 != 1) {
        return;
    }
    if (n < 0) {
        n = 0;
    }
    if (func_0206d2a4(data_0214a424, id, n) == -1) {
        return;
    }
    if (data_0214a424->items[Item_Idx(id)] + func_0206d1d4(data_0214a424, id) == 0) {
        Item_Notify(id, 0);
    } else {
        Item_Notify(id, 1);
    }
}

void func_0206f518(SaveRef *ref, u32 id) {
    u32 idx = -1;
    u16 unk = 0;
    switch (Item_Cat((u16)(id & 0xf000) - 1)) {
    case 1:
        idx = 7;
        unk = 1;
        break;
    case 3:
        idx = 8;
        unk = 0x101;
        break;
    case 4:
        idx = 9;
        unk = 0x101;
        break;
    case 5:
        idx = 10;
        unk = 1;
        break;
    case 6:
        idx = 11;
        unk = 0x101;
        break;
    case 7:
        idx = 12;
        unk = 1;
        break;
    case 11:
        idx = 13;
        unk = 1;
        break;
    }
    if (idx == -1) {
        ref->idx = -1;
        return;
    }
    func_02059280(data_02fe152c, ref, idx, unk);
}

BOOL func_0206f5e4(u16 id, int n) {
    return Item_Set(id, n);
}

BOOL func_0206f66c(u16 id) {
    SaveRef ref;
    BOOL ret;
    func_0206f518(&ref, id);
    if (ref.idx == -1) {
        return FALSE;
    }
    ret = func_0205973c(data_02fe152c, &ref, id) ? TRUE : FALSE;
    return ret ? TRUE : FALSE;
}

typedef struct ItemDef {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ s16 parts[4];
} ItemDef;

u16 func_0206f6d4(s32 id, s32 *slot) {
    u16 found = 0;
    int k;
    int j;
    if (Item_Cat(id) != 6) {
        return found;
    }
    for (k = 0; k < 16; k++) {
        u16 item = k + 0x7000;
        s16 *parts = ((ItemDef *)data_0208d268[(u16)(Item_Cat16(item) - 1)])[Item_Idx16(item)].parts;
        for (j = 0; j < 4; j++) {
            if (id == parts[j]) {
                found = item;
                if (slot != NULL) {
                    *slot = j;
                }
                goto end;
            }
        }
    }
end:
    return found;
}

u16 func_0206f788(u16 id);

BOOL func_0206f85c(u32 n);

BOOL func_0206f954(void);

typedef struct NamedEntry {
    /* 0x0 */ u32 nameOffset;
    /* 0x4 */ u32 dataOffset;
} NamedEntry;

typedef struct NamedTable {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u32 count;
    /* 0x10 */ NamedEntry entries[1];
} NamedTable;

void *func_0206f964(NamedTable *t, const char *name);

}
