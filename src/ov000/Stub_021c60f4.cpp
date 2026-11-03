#include "ov000/ListRow.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

void ListRowLabel_Draw(ListRowLabel *self) {
    if (self->text == NULL) {
        return;
    }
    self->text->unk_vf20((self->x >> 12) + 10, (self->y >> 12) + 2);
    self->text->Render();
}

}
