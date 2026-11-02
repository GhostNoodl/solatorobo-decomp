#include "ov002/ov002.h"

extern "C" {

void func_ov000_021764c4(void);

void Task021ef81c_FreeWindows(Task021ef81c *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x3c, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x40, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x44, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x48, VObj *));
    HEAP_POP(saved);
    func_ov000_021764c4();
}

}
