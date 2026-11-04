#include "ov002/ov002.h"

extern "C" {

void MenuScript_Close(void);

void ComposeMenu_FreeWindows(Task021ef81c *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_44);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_48);
    HEAP_POP(saved);
    MenuScript_Close();
}

}
