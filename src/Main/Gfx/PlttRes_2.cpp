#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {


extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 size, int is4pltt, int opt);
extern void func_0203e134(const char *name, u32 value);
extern void NNS_G2dSetImagePaletteLocation(PlttSub *sub, int idx, u32 addr);
extern u16 func_0203bdb0(GfxSys *sys, int count, int idx);
u32 func_02041080(PlttRes *res, int idx, u32 mask, int load);
u16 func_02041000(int count);
u16 func_02041020(int count);
u16 func_02041040(int count);
u16 func_02041060(int count);

u16 func_02041000(int count) {
    return func_0203bdb0(data_02097d48, count, 0);
}

u16 func_02041020(int count) {
    return func_0203bdb0(data_02097d48, count, 2);
}

u16 func_02041040(int count) {
    return func_0203bdb0(data_02097d48, count, 1);
}

u16 func_02041060(int count) {
    return func_0203bdb0(data_02097d48, count, 3);
}


extern u32 func_0203e458(int type, u32 src, u32 dst, u32 size, u32 chunk);
extern void NNS_G2dLoadPaletteEx(int *fmt, u16 *count, u32 addr, int idx, PlttSub *sub);


extern void func_0203e58c(u32 id);
extern void func_0203be50(GfxSys *sys, int shift, int count, int idx);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(u32 key);

// Bytes loaded per palette slot: one 16-colour palette, or a whole 256-colour one.
// The enum type keeps `size` a user variable through the `if` (round jkK, jkI's
// rule); as a `u32` it becomes a temp and the function is 1 / 36 off.
typedef enum { PLTT_SIZE_16 = 0x20, PLTT_SIZE_256 = 0x200 } PlttSize;

u32 func_02041080(PlttRes *res, int idx, u32 mask, int load) {
    u16 tbl[16];
    u32 ret;
    u16 *orig;
    u32 addr;
    u16 count;
    u16 i;
    if (res->maps[idx] == NULL) {
        return 0;
    }
    addr = (u16)res->key << 3;
    ret = 0;
    count = res->count;
    orig = res->table;
    for (i = 0; i < count; i++) {
        tbl[i] = res->maps[idx][orig[i]];
    }
    if (load) {
        int type;
        u16 j;
        PlttSize size;
        if (idx == 1) {
            if (res->unk_28 == 1) {
                type = 4;
            } else {
                type = 3;
            }
        } else if (idx == 2) {
            if (res->unk_28 == 1) {
                type = 7;
            } else {
                type = 6;
            }
        } else {
            type = 1;
        }
        size = PLTT_SIZE_16;
        if (res->fmt != 3) {
            size = PLTT_SIZE_256;
        }
        if (idx == 0 && mask == 0xffff) {
            ret = func_0203e458(type, (u32)res->buf, addr, size * count, 0);
        } else {
            for (j = 0; j < count; j++) {
                if (mask & (1 << j)) {
                    ret = func_0203e458(type, (u32)res->buf + size * j, addr + size * tbl[j], size, 0);
                }
            }
        }
    } else {
        res->table = tbl;
        NNS_G2dLoadPaletteEx(&res->fmt, &res->count, addr, idx, &res->sub);
        res->table = orig;
    }
    return ret;
}

}
