#ifndef MAIN_LANG_LANGDATA_H
#define MAIN_LANG_LANGDATA_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Strings
extern char *STD_CopyString(char *dst, const char *src);
extern char *STD_SearchString(char *str, const char *sub);
extern u32 STD_GetStringLength(const char *str);
extern char *STD_ConcatenateString(char *dst, const char *src);

// Which sections a data block holds; the sections follow each other in this order.
typedef struct LangSecFlags {
    u16 sec0 : 1; // 0x04 bytes
    u16 sec1 : 1; // 0x40 bytes
    u16 sec2 : 1; // 0x10 bytes
    u16 sec3 : 1; // 0x28 bytes
    u16 sec4 : 1; // 0x08 bytes
    u16 sec5 : 1; // 0x08 bytes
    u16 sec6 : 1; // 0x0c bytes
} LangSecFlags;

typedef struct LangGroup {
    /* 0x00 */ const char *name;
    /* 0x04 */ const char *dir;
    /* 0x08 */ const char *unk_08;
    /* 0x0c */ u8 count;
    /* 0x0d */ u8 unk_0d[0xf];
} LangGroup; // size 0x1c

typedef struct LangTable {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u32 strOffset;
    /* 0x0c */ u8 numGroups;
    /* 0x10 */ LangGroup groups[1];
} LangTable;

extern LangTable *data_0214b0a8;
extern const char *const data_02082bf8[];
typedef struct LangState {
    /* 0x00 */ u8 lang;
    /* 0x01 */ char name[0x23];
} LangState;

extern LangState data_0214b104;

#ifdef __cplusplus
}
#endif

#endif
