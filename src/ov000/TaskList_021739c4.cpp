#include "ov000/TaskList.h"

extern "C" {

void func_ov000_021739c4(Task *self) {
    self->unk_20 = 0x10000;
    self->unk_3c = -0xcd;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = NULL;
    MTX_Identity44_(self->unk_50);
}

void func_ov000_021739f8(Task *self) {
    void *saved;
    Model *model;
    func_ov000_0214c210(self);
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    model = self->unk_4c;
    if (model != NULL) {
        if (model != NULL) {
            func_02041558(model);
            func_02041278(model->unk_88);
            func_0203de1c(model);
        }
        self->unk_4c = NULL;
    }
    data_02097dd0->current = saved;
}

}
