#include "ov000/TextList.h"

extern "C" {

// Raises the list (TextListFlags::raise) and stops its input (UiObj::flag2); func_ov000_021c701c undoes it.
void func_ov000_021c7000(TextList *self) {
    self->flag2 = 1;
    self->listFlags.raise = 1;
}

void func_ov000_021c701c(TextList *self) {
    self->listFlags.raise = 0;
    self->flag2 = 0;
}

}
