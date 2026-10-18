#include "ov000/VObj.h"

typedef struct {
    u32 unk_00;
    u32 unk_04;
} Data02097ce0;

class Obj0214e354 : public VObj {
public:
    u8 unk_04[0x18];
    u32 unk_1c;
    u8 unk_20[0x98];
    void *unk_b8;
};

extern "C" {

extern Data02097ce0 *data_02097ce0;

s8 **func_0203a4c0(Data02097ce0 *a);

s32 func_ov000_0214e354(Obj0214e354 *self) {
    return self->unk_b8 != NULL ? 0x15 : 0;
}

s32 func_ov000_0214e368(Obj0214e354 *self) {
    s32 base;
    data_02097ce0->unk_04 = self->unk_1c;
    base = (*func_0203a4c0(data_02097ce0))[1];
    return base + self->vfunc_3c();
}

s32 func_ov000_0214e3ac(void) {
    return 0;
}

}
