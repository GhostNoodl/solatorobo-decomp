#include "ov000/VObj.h"
#include "ov000/ListRow.h"

extern "C" {

extern char data_ov000_021cc9bc[];

void ListRowText_Init(ListRowText *self) {
    self->width = 0xf4;
    self->height = 0xb8;
    self->win = 0;
    self->unk_34 = data_ov000_021cc9bc;
    self->unk_38 = data_ov000_021cc9bc;
    self->state = 0;
    self->unk_40 = 0;
}

}
