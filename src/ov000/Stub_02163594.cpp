#include "ov000/MsgBox.h"

extern "C" {

void MsgBox_Render(MsgBox *self) {
    SlideWin *win = self->win;
    if (win != NULL) {
        win->Render();
    }
}

}
