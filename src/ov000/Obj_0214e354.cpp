#include "ov000/VObj.h"
#include "ov000/UiObj.h"

typedef struct {
    u32 unk_00;
    u32 unk_04;
} Data02097ce0;

class Obj0214e354 : public UiObj {
public:
    u8 unk_84[0x34];
    void *unk_b8;
};

extern "C" {

extern Data02097ce0 *data_02097ce0;

s8 **GfxMgr_GetFont(Data02097ce0 *a);

s32 func_ov000_0214e354(Obj0214e354 *self) {
    return self->unk_b8 != NULL ? 0x15 : 0;
}

s32 func_ov000_0214e368(Obj0214e354 *self) {
    s32 base;
    data_02097ce0->unk_04 = self->font;
    base = (*GfxMgr_GetFont(data_02097ce0))[1];
    return base + self->vfunc_3c();
}

s32 func_ov000_0214e3ac(void) {
    return 0;
}

}
