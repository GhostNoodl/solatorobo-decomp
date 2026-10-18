#include "ov002/ov002.h"

extern "C" {

u16 func_ov002_021d9e30(void *self) {
    return FIELD(self, 0x48, u16);
}

void func_ov002_021d9e38(void *self, void *node) {
    void *p = FIELD(self, 0x6c, void *);
    if (p != NULL) {
        if (p != NULL) {
            void *q;
            do {
                q = FIELD(p, 0x70, void *);
                if (q == NULL) {
                    break;
                }
                p = q;
            } while (p != NULL);
        }
        FIELD(p, 0x70, void *) = node;
        FIELD(node, 0x74, void *) = p;
    } else {
        FIELD(self, 0x6c, void *) = node;
    }
    func_ov002_021da184(self);
    if (FIELD(data_0214a424, 0x18, Bits021d9e38).mode == 1) {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
        func_ov000_021c95ac((u8 *)self + 0x76, FIELD(data_0214a424, 0x18, Bits021d9e38).id | 0x8000);
    } else {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
    }
}

}
