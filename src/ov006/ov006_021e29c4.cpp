#include "ov006/ov006.h"
#include "ov006/Caption.h"

extern "C" {


ov006_CaptionPanel *Ov006Vt_021ec29c_Ctor(ov006_CaptionPanel *self) {
    int i;
    self->vtbl = Ov006Vt_021ec29c_vtbl;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->model = 0;
    self->title = 0;
    for (i = 0; i < 3; i++) {
        self->captions[i] = 0;
    }
    return self;
}

}
