#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0xc];
    s32 unk_0c;
    s32 unk_10;
    u8 unk_14[0x1c];
    VObj *unk_30;
} Obj021c60f4;

extern "C" {

void func_ov000_021c60f4(Obj021c60f4 *self) {
    if (self->unk_30 == NULL) {
        return;
    }
    self->unk_30->vfunc_20((self->unk_0c >> 12) + 10, (self->unk_10 >> 12) + 2);
    self->unk_30->vfunc_90();
}

}
