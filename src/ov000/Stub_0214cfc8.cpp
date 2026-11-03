#include "ov000/ObjLayouts.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

void Lo021cad50_DeleteTexts(Lo021cad50 *self) {
    s32 i;
    for (i = 0; i < 12; i++) {
        TextWin *p = (TextWin *)self->unk_98[i];
        if (p != NULL) {
            p->flags |= 4;
        }
    }
}

}
