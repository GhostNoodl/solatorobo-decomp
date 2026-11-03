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
    func_ov002_021da184(self, node);
    if (data_0214a424->bits18.mode == 1) {
        func_ov000_021c9544(self->unk_76, self->pieces);
        Obj021c95ac_Init_021c95ac(self->unk_76, data_0214a424->bits18.unk_3 | 0x8000);
    } else {
        func_ov000_021c9544(self->unk_76, self->pieces);
    }
}

}
