#include "ov002/ov002.h"

extern "C" {


void func_02065f0c(void *p);

void func_ov002_021da430(void *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 8, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 4, VObject *));
    HEAP_POP(saved);
    func_02036838(data_02097cdc, (char *)data_ov002_021efdf6, 7, 0);
    if (FIELD(self, 0x10, u8)) {
        func_02065f0c(data_0214a420);
        if (data_ov000_021ccd54 != NULL) {
            *(u8 **)data_0214a420 = (u8 *)data_ov000_021ccd54 + 8;
        }
    }
}

}
