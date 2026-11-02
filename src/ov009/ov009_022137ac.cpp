#include "ov009/ov009.h"

extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);

void Ov009ActVt_02217cb0_Start(Ov009ActVt_02217cb0 *self) {
    GroupNode *p;
    Ov003Actor *a;
    Ov003Actor_Start(self);
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
    }
    self->target = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->target = a->id;
    }
    self->unk_f0.x = 0;
    self->unk_f0.y = 0;
    self->unk_f0.z = 0;
    self->unk_b6 = 0x78;
}

}
