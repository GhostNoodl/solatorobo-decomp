#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {


extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 size, int is4pltt, int opt);
extern void NamePool_SetPlttKey(const char *name, u32 value);
extern void NNS_G2dSetImagePaletteLocation(PlttSub *sub, int idx, u32 addr);
extern u16 GfxSys_AllocSlots(GfxSys *sys, int count, int idx);
u32 func_02041080(PlttRes *res, int idx, u32 mask, int load);
u16 func_02041000(int count);
u16 func_02041020(int count);
u16 func_02041040(int count);
u16 func_02041060(int count);


extern u32 Vram_QueueTransfer(int type, u32 src, u32 dst, u32 size, u32 chunk);
extern void NNS_G2dLoadPaletteEx(int *fmt, u16 *count, u32 addr, int idx, PlttSub *sub);


extern void Vram_CancelTransfer(u32 id);
extern void GfxSys_FreeSlots(GfxSys *sys, int shift, int count, int idx);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(u32 key);

void PlttRes_Init_02041218(PlttRes *res) {
    PlttRes_Init(res);
}

void PlttRes_Release(PlttRes *res) {
    u16 i;
    s8 *map;
    Vram_CancelTransfer(res->transfer);
    map = res->maps[1];
    res->transfer = 0;
    if (map != NULL) {
        for (i = 0; i < 16; i++) {
            if (map[i] != -1) {
                if (res->unk_28 == 0) {
                    if (res->fmt == 3) {
                        GfxSys_FreeSlots(gGfxSys, (u16)map[i], 1, 0);
                    } else {
                        GfxSys_FreeSlots(gGfxSys, (u16)map[i], 16, 0);
                    }
                } else {
                    GfxSys_FreeSlots(gGfxSys, (u16)map[i], 1, 1);
                }
            }
        }
        if (res->maps[1] != NULL) {
            Heap_FreeHi(res->maps[1]);
            res->maps[1] = NULL;
        }
    }
    map = res->maps[2];
    if (map != NULL) {
        for (i = 0; i < 16; i++) {
            if (map[i] != -1) {
                if (res->unk_28 == 0) {
                    if (res->fmt == 3) {
                        GfxSys_FreeSlots(gGfxSys, (u16)map[i], 1, 2);
                    } else {
                        GfxSys_FreeSlots(gGfxSys, (u16)map[i], 16, 2);
                    }
                } else {
                    GfxSys_FreeSlots(gGfxSys, (u16)map[i], 1, 3);
                }
            }
        }
        if (res->maps[2] != NULL) {
            Heap_FreeHi(res->maps[2]);
            res->maps[2] = NULL;
        }
    }
    if (res->key != 0) {
        NNS_GfdDefaultFuncFreePlttVram(res->key);
        if (res->maps[0] != NULL) {
            Heap_FreeHi(res->maps[0]);
            res->maps[0] = NULL;
        }
    }
    if (res->loaded) {
        Heap_FreeHi(res->buf);
    }
}

}
