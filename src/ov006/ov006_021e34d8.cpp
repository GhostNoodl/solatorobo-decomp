#include "ov006/Caption.h"

typedef struct ov006_CaptionSet {
    u8 unk0[0x18];
    ov006_Caption *captions[1];
} ov006_CaptionSet;

extern "C" {



void func_ov006_021e34d8(ov006_CaptionSet *self, const char *text, int idx) {
    OV006_DELETE_OBJECT(self->captions[idx]);
    self->captions[idx] = ov006_Caption_New();
    self->captions[idx]->unk20 = 2;
    ov006_Caption_Init(self->captions[idx]);
    ov006_AnimHolder_Play((ov006_AnimHolder *)self->captions[idx], (int)text, 5);
}

}
