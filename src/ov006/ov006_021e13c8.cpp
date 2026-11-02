#include "ov006/Anim.h"
#include "ov006/Gauge.h"

extern "C" {

void ov006_Gauge_SetText(ov006_Gauge *self, int a) {
    if (self->text == NULL) {
        return;
    }
    self->text->unk_vf08();
    self->text->font = 3;
    self->text->unk_2c = 4;
    self->text->unk_34 = 0;
    ov006_TextWin_Start(self->text, a);
    TextWin_InitLines(self->text, 8);
    self->text->flags |= 4;
}

}
