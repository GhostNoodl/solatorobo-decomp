#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

void func_02040be0(PlttRes *res, PlttResSrc *src) {
    PlttRes_SetSrc(res, src);
}

void func_02040c40(PlttRes *res, PlttResSrc *src) {
    PlttRes_SetSrc(res, src);
    PlttRes_SetData(res, src->info->header->data, res->size);
}

void func_02040d14(PlttRes *res, const void *data, u32 size) {
    PlttRes_SetData(res, data, size);
}

void func_02040d94(PlttRes *res, const void *data, u32 offset, u32 size) {
    PlttRes_Upload(res, data, offset, size);
}


extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 size, int is4pltt, int opt);
extern void func_0203e134(const char *name, u32 value);
extern void NNS_G2dSetImagePaletteLocation(PlttSub *sub, int idx, u32 addr);
extern u16 func_0203bdb0(GfxSys *sys, int count, int idx);
u32 func_02041080(PlttRes *res, int idx, u32 mask, int load);
u16 func_02041000(int count);
u16 func_02041020(int count);
u16 func_02041040(int count);
u16 func_02041060(int count);


void func_02040dd8(PlttRes *res, int idx, bool load) {
    u32 addr;
    u16 *saved;
    u16 (*alloc)(int);
    u16 tmp[0x10];
    u16 i;
    if (res->maps[idx] != NULL) {
        return;
    }
    if (res->fmt == 4) {
        res->unk_28 = 1;
    }
    if (res->unk_28 == 0) {
        switch (idx) {
        case 1:
            alloc = func_02041000;
            break;
        case 2:
            alloc = func_02041020;
            break;
        }
    } else {
        switch (idx) {
        case 1:
            alloc = func_02041040;
            break;
        case 2:
            alloc = func_02041060;
            break;
        }
    }
    addr = 0;
    res->maps[idx] = (s8 *)func_0203de84(0x10, 4);
    for (i = 0; i < 0x10; i++) {
        res->maps[idx][i] = -1;
    }
    saved = res->table;
    res->table = tmp;
    if (idx == 0) {
        u16 n;
        func_0203e134(res->name, res->loaded);
        n = res->count;
        if (res->fmt == 3) {
            res->key = NNS_GfdDefaultFuncAllocPlttVram(n << 5, 0, 0);
        } else {
            res->key = NNS_GfdDefaultFuncAllocPlttVram(n << 9, 0, 0);
        }
        for (i = 0; i < res->count; i++) {
            res->maps[idx][saved[i]] = i;
            tmp[i] = i;
        }
        addr = (u16)res->key << 3;
    } else {
        for (i = 0; i < res->count; i++) {
            u16 v = alloc(1);
            res->maps[idx][saved[i]] = v;
            tmp[i] = v;
        }
    }
    res->table = saved;
    {
        u32 t = func_02041080(res, idx, 0xffff, load);
        if (load) {
            res->transfer = t;
            res->sub.fmt = res->fmt;
            res->sub.unk_04 = res->unk_28;
            NNS_G2dSetImagePaletteLocation(&res->sub, idx, addr);
        }
    }
}

}
