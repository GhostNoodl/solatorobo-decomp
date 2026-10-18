#include "ov000/VObj.h"

class Node021824d0 : public VObj {
public:
    u8 unk_04[0xd0];
    Node021824d0 *next;
};

extern "C" {

Node021824d0 *func_ov000_021824d0(void *self, u16 index) {
    Node021824d0 *n = *(Node021824d0 **)((u8 *)self + 0x10);
    u16 i = 0;
    while (n != NULL) {
        if (index == i) {
            break;
        }
        if (n->vfunc_34()) {
            i++;
        }
        n = n->next;
    }
    return n;
}

}
