#include "ov000/TextList.h"

extern "C" {

// Raises the list (TextListFlags::raise) and stops its input (UiObj::flag2); TextList_Lower undoes it.
void TextList_Raise(TextList *self) {
    self->flag2 = 1;
    self->listFlags.raise = 1;
}

void TextList_Lower(TextList *self) {
    self->listFlags.raise = 0;
    self->flag2 = 0;
}

}
