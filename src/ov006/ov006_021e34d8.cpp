#include "ov006/Caption.h"

typedef struct ov006_CaptionSet {
    u8 unk0[0x18];
    ov006_Caption *captions[1];
} ov006_CaptionSet;

extern "C" {



void ov006_CaptionSet_SetText(ov006_CaptionSet *self, const char *text, int idx) {
    OV006_DELETE_OBJECT(self->captions[idx]);
    self->captions[idx] = ov006_Caption_New();
    self->captions[idx]->kind = 2;
    ov006_Caption_Init(self->captions[idx]);
    ov006_TextHolder_Play((ov006_TextHolder *)self->captions[idx], (int)text, 5);
}

}
