#include "types.h"
#include "Main/Res/ResMgr.h"

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
extern const char *func_02039674(const char *path);

static inline u16 Tbl_Index(TblRange *ranges, u16 idx) {
    if (ranges != NULL) {
        int i = 0;
        while (ranges[i].start <= idx) {
            i++;
        }
        if (i != 0) {
            idx = idx - ranges[i - 1].start + ranges[i - 1].base;
        }
    }
    return idx;
}

static inline TblCat *Tbl_GetCat(s32 id) {
    return &data_0208d6d0[(u16)((id >> 12) - 1)];
}

static inline u16 Tbl_Remap2(TblCat *cat, s32 id) {
    TblRange *ranges = cat->ranges;
    u16 idx = id & 0xfff;
    if (ranges != NULL) {
        int i = 0;
        while (ranges[i].start <= idx) {
            i++;
        }
        if (i != 0) {
            idx = idx - ranges[i - 1].start + ranges[i - 1].base;
        }
    }
    return idx;
}

static inline u16 Tbl_Remap(s32 id) {
    TblRange *ranges = Tbl_GetCat(id)->ranges;
    u16 idx = id & 0xfff;
    if (ranges != NULL) {
        int i = 0;
        while (ranges[i].start <= idx) {
            i++;
        }
        if (i != 0) {
            idx = idx - ranges[i - 1].start + ranges[i - 1].base;
        }
    }
    return idx;
}

static inline u8 *Tbl_Elem(s32 id, u32 size) {
    TblCat *cat = &data_0208d6d0[(u16)((id >> 12) - 1)];
    u8 *data = cat->data;
    u16 idx = Tbl_Index(cat->ranges, id & 0xfff);
    return data + idx * size;
}

#define TBL_ENTRY_BODY(id)                                                  \
    TblCat *cat = &data_0208d6d0[(u16)(((id) >> 12) - 1)];                  \
    TblEntry *entries = data_0214b164[(id) >> 12];                          \
    u16 idx = (id) & 0xfff;                                                 \
    TblRange *ranges = cat->ranges;                                         \
    if (ranges != NULL) {                                                   \
        int i = 0;                                                          \
        while (ranges[i].start <= idx) {                                    \
            i++;                                                            \
        }                                                                   \
        if (i != 0) {                                                       \
            idx = idx - ranges[i - 1].start + ranges[i - 1].base;           \
        }                                                                   \
    }                                                                       \
    return &entries[idx];

#define TBL_ELEM_BODY(T, id)                                                \
    TblCat *cat = &data_0208d6d0[(u16)(((id) >> 12) - 1)];                  \
    T *data = (T *)cat->data;                                               \
    u16 idx = (id) & 0xfff;                                                 \
    TblRange *ranges = cat->ranges;                                         \
    if (ranges != NULL) {                                                   \
        int i = 0;                                                          \
        while (ranges[i].start <= idx) {                                    \
            i++;                                                            \
        }                                                                   \
        if (i != 0) {                                                       \
            idx = idx - ranges[i - 1].start + ranges[i - 1].base;           \
        }                                                                   \
    }                                                                       \
    return &data[idx];

static inline TblEntry *Tbl_GetEntry(s32 id) {
    TblEntry *entries = data_0214b164[id >> 12];
    return &entries[Tbl_Remap(id)];
}

// These lookups re-read cat->ranges at each use, unlike the TBL_*_BODY ones.
static inline TblEntry *Tbl_FindEntry(s32 id) {
    TblCat *cat = &data_0208d6d0[(u16)((id >> 12) - 1)];
    u16 idx = id & 0xfff;
    TblEntry *entries = data_0214b164[id >> 12];
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

static inline TblEntry *Tbl_FindEntryT(s32 type, s32 id) {
    u16 idx = id & 0xfff;
    TblCat *cat = &data_0208d6d0[(u16)(type - 1)];
    TblEntry *entries = data_0214b164[(int)id >> 12];
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

TblEntry *func_0206fef8(s32 id);

void *func_0206ffa0(s32 id);

void *func_0207005c(s32 id, int i);

void *func_0207011c(s32 id);

static inline u8 *Tbl_GetData(s32 id) {
    return Tbl_GetCat(id)->data;
}

u16 *func_020702c8(s32 id) {
    TBL_ELEM_BODY(u16, id)
}

u16 *func_0207036c(s32 id) {
    TBL_ELEM_BODY(u16, id)
}

u16 *func_02070410(s32 id) {
    TBL_ELEM_BODY(u16, id)
}

u8 *func_020704b4(s32 id) {
    return Tbl_Elem(id, 0x28);
}

u8 *func_02070558(s32 id) {
    return Tbl_Elem(id, 0x44);
}

u8 *func_020705fc(s32 id) {
    TBL_ELEM_BODY(u8, id)
}

u8 *func_020706a0(s32 id) {
    return Tbl_Elem(id, 0xa);
}

u8 *func_02070744(s32 id) {
    TblCat *cat = &data_0208d6d0[(u16)((id >> 12) - 1)];
    u8 *data = cat->data;
    u16 idx = Tbl_Index(cat->ranges, id & 0xfff);
    return data + idx * 0x14;
}

extern char *func_02040ab0(char *str, int c);

void func_020707e8(char *dst, const char *fmt, const char *arg, int c) {
    char buf[0x80];
    char *p;
    STD_GetStringLength(fmt);
    STD_CopyString(buf, fmt);
    p = func_02040ab0(buf, c);
    if (p != NULL) {
        *p = 0;
        STD_CopyString(dst, buf);
        STD_ConcatenateString(dst, arg);
        STD_ConcatenateString(dst, p + 1);
    } else {
        STD_CopyString(dst, fmt);
    }
}

static inline void Tbl_Format(char *dst, const char *fmt, const char *arg) {
    char buf[0x80];
    char *p;
    STD_GetStringLength(fmt);
    STD_CopyString(buf, fmt);
    p = func_02040ab0(buf, '%');
    if (p != NULL) {
        *p = 0;
        STD_CopyString(dst, buf);
        STD_ConcatenateString(dst, arg);
        STD_ConcatenateString(dst, p + 1);
    } else {
        STD_CopyString(dst, fmt);
    }
}

void func_02070874(char *dst, const char *fmt, const char *arg) {
    Tbl_Format(dst, fmt, arg);
}

extern const char *data_0208ccc4;
extern const char *data_0208cc98;
extern const char *data_0208ccb8;

void func_020708fc(s32 id, char *dst) {
    switch (id >> 12) {
    case 1:
        Tbl_Format(dst, data_0208ccc4, (const char *)Tbl_GetOffset(Tbl_FindEntry(id), 1));
        break;
    case 2:
        if (id == 0x2001) {
            STD_CopyString(dst, data_0208cc98);
            break;
        }
        Tbl_Format(dst, data_0208ccb8, (const char *)Tbl_GetOffset(Tbl_FindEntry(id), 1));
        break;
    }
}

extern const char *data_0208ccbc;
extern const char *data_0208ccb4;
extern const char *data_0208ccac;
extern char data_0208d2b4[];
extern char data_0208d2b9[];
extern int func_0200779c(char *dst, const char *fmt, ...);

void func_02070b98(s32 id, char *dst, int unused, int num) {
    char numBuf[8];
    char name[0x20];
    const char *fmt;
    s32 type = id >> 12;
    switch (type) {
    case 1:
        fmt = data_0208ccbc;
        break;
    case 2:
        fmt = data_0208ccb4;
        break;
    }
    func_0200779c(numBuf, data_0208d2b4);
    STD_CopyString(name, (const char *)Tbl_GetOffset(Tbl_FindEntryT(type, id), 1));
    STD_ConcatenateString(name, numBuf);
    Tbl_Format(dst, fmt, name);
    func_0200779c(numBuf, data_0208d2b9, num);
    STD_CopyString(name, data_0208ccac);
    STD_ConcatenateString(name, numBuf);
    Tbl_Format(dst, dst, name);
}

}
