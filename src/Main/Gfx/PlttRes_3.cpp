#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {


extern u32 (*data_0208afdc)(u32 size, int is4pltt, int opt);
extern void func_0203e134(const char *name, u32 value);
extern void func_020241c4(PlttSub *sub, int idx, u32 addr);
extern u16 func_0203bdb0(GfxSys *sys, int count, int idx);
u32 func_02041080(PlttRes *res, int idx, u32 mask, int load);
u16 func_02041000(int count);
u16 func_02041020(int count);
u16 func_02041040(int count);
u16 func_02041060(int count);


extern u32 func_0203e458(int type, u32 src, u32 dst, u32 size, u32 chunk);
extern void func_020243f4(int *fmt, u16 *count, u32 addr, int idx, PlttSub *sub);


extern void func_0203e58c(u32 id);
extern void func_0203be50(GfxSys *sys, int shift, int count, int idx);
extern void (*data_0208afe0)(u32 key);

void func_02041218(PlttRes *res) {
    PlttRes_Init(res);
}

void func_02041278(PlttRes *res) {
    u16 i;
    s8 *map;
    func_0203e58c(res->transfer);
    map = res->maps[1];
    res->transfer = 0;
    if (map != NULL) {
        for (i = 0; i < 16; i++) {
            if (map[i] != -1) {
                if (res->unk_28 == 0) {
                    if (res->fmt == 3) {
                        func_0203be50(data_02097d48, (u16)map[i], 1, 0);
                    } else {
                        func_0203be50(data_02097d48, (u16)map[i], 16, 0);
                    }
                } else {
                    func_0203be50(data_02097d48, (u16)map[i], 1, 1);
                }
            }
        }
        if (res->maps[1] != NULL) {
            func_0203df0c(res->maps[1]);
            res->maps[1] = NULL;
        }
    }
    map = res->maps[2];
    if (map != NULL) {
        for (i = 0; i < 16; i++) {
            if (map[i] != -1) {
                if (res->unk_28 == 0) {
                    if (res->fmt == 3) {
                        func_0203be50(data_02097d48, (u16)map[i], 1, 2);
                    } else {
                        func_0203be50(data_02097d48, (u16)map[i], 16, 2);
                    }
                } else {
                    func_0203be50(data_02097d48, (u16)map[i], 1, 3);
                }
            }
        }
        if (res->maps[2] != NULL) {
            func_0203df0c(res->maps[2]);
            res->maps[2] = NULL;
        }
    }
    if (res->key != 0) {
        data_0208afe0(res->key);
        if (res->maps[0] != NULL) {
            func_0203df0c(res->maps[0]);
            res->maps[0] = NULL;
        }
    }
    if (res->loaded) {
        func_0203df0c(res->buf);
    }
}

}
