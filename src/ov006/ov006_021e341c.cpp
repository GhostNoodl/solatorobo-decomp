#include "ov006/Caption.h"

extern "C" {

void ov006_CaptionPanel_PlayText(ov006_CaptionPanel *self, int a) {
    ov006_TextHolder_Play((ov006_TextHolder *)self->title, a, 4);
}

}
