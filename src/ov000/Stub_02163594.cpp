#include "ov000/MsgBox.h"

extern "C" {

void func_ov000_02163594(MsgBox *self) {
    SlideWin *win = self->win;
    if (win != NULL) {
        win->Render();
    }
}

}
