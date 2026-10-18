#include "Main/Gfx/Obj3D.h"

extern "C" {

extern int func_02043d48(void *obj);
extern s8 data_02149ef4;

void func_02051f3c(Obj3DLayer *layer, u32 v);

void func_020520fc(Obj3DRender *render) {
    GfxSys *sys;
    s32 limit;
    u32 attr;
    u32 alpha;
    Obj3DMtl *mtl;
    mtl = render->mtl;
    attr = mtl->polyAttr;
    alpha = (attr & 0x1f0000) >> 16;
    limit = data_02149ef4;
    sys = data_02097d48;
    if ((u32)limit < alpha) {
        alpha = limit;
    }
    if (alpha > 30) {
        alpha = 30;
    }
    mtl->polyAttr = (attr & 0xc0e0ffbf) | 0xc0 | (alpha << 16) | (func_02043d48(sys->unk_8b0) << 24);
}

void func_02052160(Obj3DRender *render) {
    render->callback = func_020520fc;
    render->callbackMode = 2;
}

s32 func_020534c4(s32 x);

s32 func_020534d4(void);

}
