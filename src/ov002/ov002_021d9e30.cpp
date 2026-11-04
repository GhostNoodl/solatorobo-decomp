#include "ov002/ov002.h"

extern "C" {

u16 func_ov002_021d9e30(Obj021efeb8 *self) {
    return self->unk_48;
}

void Obj021efe6c_AppendPiece(Obj021efe6c *self, Obj021efeb8 *node) {
    Obj021efeb8 *p = self->pieces;
    if (p != NULL) {
        if (p != NULL) {
            Obj021efeb8 *q;
            do {
                q = p->next;
                if (q == NULL) {
                    break;
                }
                p = q;
            } while (p != NULL);
        }
        p->next = node;
        node->prev = p;
    } else {
        self->pieces = node;
    }
    Obj021efe6c_MarkPieceCells(self, node);
    if (gStageFlags->bits18.mode == 1) {
        Parts_SumStats(self->unk_76, self->pieces);
        Obj021c95ac_Init_021c95ac(self->unk_76, gStageFlags->bits18.unk_3 | 0x8000);
    } else {
        Parts_SumStats(self->unk_76, self->pieces);
    }
}

}
