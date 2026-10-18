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
extern void func_020243f4(int *fmt, u16 *count, u32 addr, int idx, PlttSub *sub);


extern void func_0203e58c(u32 id);
extern void func_0203be50(GfxSys *sys, int shift, int count, int idx);
extern void (*data_0208afe0)(u32 key);

}
