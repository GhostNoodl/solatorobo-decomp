#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

typedef struct {
    u8 pad_00[0x3c];
    VObj *unk_3c;
    VObj *unk_40;
    VObj *unk_44;
    VObj *unk_48;
    Model *unk_4c;
} Obj021805a8;

extern "C" {

void func_ov000_021805a8(Obj021805a8 *self) {
    Model *m = self->unk_4c;
    if (m != NULL) {
        Model_PlayPart(m, 0);
    }
    self->unk_3c->vfunc_20();
    self->unk_40->vfunc_20();
    self->unk_48->vfunc_20();
    self->unk_44->vfunc_20();
}

}
