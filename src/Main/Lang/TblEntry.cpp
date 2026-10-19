#include "types.h"

extern "C" {

typedef struct TblRange {
    /* 0x0 */ u16 start;
    /* 0x2 */ u16 base;
} TblRange;

typedef struct TblCat {
    /* 0x0 */ u8 *data;
    /* 0x4 */ TblRange *ranges;
    /* 0x8 */ u32 unk_8;
} TblCat;

typedef struct TblEntry {
    /* 0x00 */ u32 offsets[6];
} TblEntry;

extern TblCat data_0208d6d0[];
extern TblEntry *data_0214b164[];

// Unlike the TblRes.cpp lookups, this one re-reads cat->ranges at each use.
static inline TblEntry *Tbl_FindEntry(s32 id) {
    TblCat *cat = &data_0208d6d0[(u16)((id >> 12) - 1)];
    TblEntry *entries = data_0214b164[id >> 12];
    u16 idx = id & 0xfff;
    if (cat->ranges != NULL) {
        int i = 0;
        while (cat->ranges[i].start <= idx) {
            i++;
        }
        if (i != 0) {
            idx = idx - cat->ranges[i - 1].start + cat->ranges[i - 1].base;
        }
    }
    return &entries[idx];
}

static inline void *Tbl_GetOffset(TblEntry *e, int i) {
    return e->offsets[i] != 0 ? (u8 *)e + e->offsets[i] : NULL;
}

TblEntry *func_0206fef8(s32 id) {
    return Tbl_FindEntry(id);
}

void *func_0206ffa0(s32 id) {
    return Tbl_GetOffset(Tbl_FindEntry(id), 0);
}

void *func_0207005c(s32 id, int i) {
    TblEntry *e = Tbl_FindEntry(id);
    u32 *o = &e->offsets[1];
    return o[i] != 0 ? (u8 *)e + o[i] : NULL;
}

void *func_0207011c(s32 id) {
    return Tbl_GetOffset(Tbl_FindEntry(id), 3);
}

}
