#ifndef MAIN_GFX_PLTTRES_H
#define MAIN_GFX_PLTTRES_H

#include "types.h"
#include "Main/Res/ResMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PlttResHeader {
    /* 0x00 */ int fmt;
    /* 0x04 */ int unk_04;
    /* 0x08 */ u32 size;
    /* 0x0c */ void *data;
} PlttResHeader;

typedef struct PlttResTable {
    /* 0x00 */ u16 count;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 *table;
} PlttResTable;

typedef struct PlttResInfo {
    /* 0x00 */ u8 unk_00[0x24];
    /* 0x24 */ PlttResHeader *header;
    /* 0x28 */ PlttResTable *table;
} PlttResInfo;

typedef struct PlttResSrc {
    /* 0x00 */ u8 unk_00[0x28];
    /* 0x28 */ PlttResInfo *info;
    /* 0x2c */ u8 unk_2c[0x20];
    /* 0x4c */ char name[0x20];
} PlttResSrc;

typedef struct PlttSub {
    /* 0x00 */ int fmt;
    /* 0x04 */ int unk_04;
    /* 0x08 */ u8 unk_08[0xc];
} PlttSub;

typedef struct PlttRes {
    /* 0x00 */ char name[0x20];
    /* 0x20 */ u8 loaded;
    /* 0x24 */ int fmt;
    /* 0x28 */ int unk_28;
    /* 0x2c */ u32 size;
    /* 0x30 */ void *buf;
    /* 0x34 */ u16 count;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ u16 *table;
    /* 0x3c */ PlttSub sub;
    /* 0x50 */ s8 *maps[3];
    /* 0x5c */ u32 key;
    /* 0x60 */ u32 transfer;
} PlttRes; // size 0x64

extern void func_02016e28(void *dst, u32 value, u32 size);
extern void func_020241a4(PlttSub *sub);

static inline void PlttRes_Init(PlttRes *res) {
    int i;
    res->name[0] = 0;
    res->loaded = 0;
    func_02016e28(&res->fmt, 0, 0x10);
    func_02016e28(&res->count, 0, 8);
    func_020241a4(&res->sub);
    for (i = 0; i < 3; i++) {
        res->maps[i] = NULL;
    }
    res->key = 0;
    res->transfer = 0;
}

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_02016fa0(const void *src, void *dst, u32 size);
extern void func_02019294(const void *addr, u32 size);

static inline void PlttRes_SetSrc(PlttRes *res, PlttResSrc *src) {
    PlttResHeader *header;
    PlttResTable *table;
    func_0201e520(res->name, src->name);
    header = src->info->header;
    res->fmt = header->fmt;
    res->unk_28 = header->unk_04;
    res->size = header->size;
    res->buf = header->data;
    table = src->info->table;
    res->count = table->count;
    res->unk_36 = table->unk_02;
    res->table = table->table;
}

static inline void PlttRes_Upload(PlttRes *res, const void *data, u32 offset, u32 size) {
    u8 *buf;
    if (res->loaded && data != NULL && (buf = (u8 *)res->buf) != NULL) {
        func_02016fa0(data, buf + offset, size);
        func_02019294(buf + offset, size);
    }
}

static inline void PlttRes_SetData(PlttRes *res, const void *data, u32 size) {
    if (res->loaded) {
        func_0203df0c(res->buf);
    }
    res->size = size;
    res->buf = func_0203de84(size, 4);
    res->loaded = 1;
    if (data == NULL) {
        return;
    }
    PlttRes_Upload(res, data, 0, res->size);
}

void func_02041218(PlttRes *res);
void func_02041278(PlttRes *res);

#ifdef __cplusplus
}
#endif

#endif
