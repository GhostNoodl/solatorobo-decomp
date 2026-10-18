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


extern u32 func_0203e458(int type, u32 src, u32 dst, u32 size, u32 chunk);
extern void NNS_G2dLoadPaletteEx(int *fmt, u16 *count, u32 addr, int idx, PlttSub *sub);


extern void func_0203e58c(u32 id);
extern void func_0203be50(GfxSys *sys, int shift, int count, int idx);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(u32 key);

}
