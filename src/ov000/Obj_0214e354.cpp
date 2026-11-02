#include "ov000/VObj.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"
#include "nnsys/g2d/g2d_Font.h"

class Obj0214e354 : public UiObj {
public:
    u8 unk_84[0x34];
    void *unk_b8;
};

extern "C" {

s32 func_ov000_0214e354(Obj0214e354 *self) {
    return self->unk_b8 != NULL ? 0x15 : 0;
}

s32 func_ov000_0214e368(Obj0214e354 *self) {
    s32 base;
    data_02097ce0->unk_004 = self->font;
    base = ((NNSG2dFont *)GfxMgr_GetFont(data_02097ce0))->pRes->linefeed;
    return base + self->vfunc_3c();
}

s32 func_ov000_0214e3ac(void) {
    return 0;
}

}
