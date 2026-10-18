#include "ov000/TaskList.h"

extern "C" {

void func_ov000_02173528(void) {
}

BOOL func_ov000_0217352c(Task *self) {
    if (self->vfunc_54()) {
        if (data_ov000_021ccd34.unk_0c != NULL) {
            data_ov000_021ccd34.unk_04 = data_ov000_021ccd34.unk_0c->id;
        } else {
            data_ov000_021ccd34.unk_04 = 0;
        }
        data_ov000_021ccd34.unk_0c = NULL;
    }
    return TRUE;
}

void func_ov000_02173574(void) {
}

void func_ov000_02173578(void) {
}

}
