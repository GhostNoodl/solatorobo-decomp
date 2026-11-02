#include "ov000/LoTicker.h"

extern "C" {

void func_ov000_0216c6fc(LoTicker *self) {
    const LoTickerIcons *tbl = data_ov000_021c9bb4;
    LoTickerSlot *n = self->head;
    if (n == NULL) {
        return;
    }
    do {
        s32 k = n->kind;
        s32 x = n->x;
        s32 y;
        TextWin *o1;
        TextWin *o2;
        o1 = self->res[tbl[k].a].win;
        y = n->y;
        o2 = self->res[tbl[k].b].win;
        if (o1) {
            o1->unk_vf20(x, y);
            o1->Render();
            x = x + o1->width + 8;
        }
        if (n->text) {
            n->text->unk_vf20(x, y);
            n->text->Render();
            x += n->text->width;
        }
        if (o2) {
            o2->unk_vf20(x + 4, y);
            o2->Render();
        }
        n = n->next;
    } while (n);
}

}
