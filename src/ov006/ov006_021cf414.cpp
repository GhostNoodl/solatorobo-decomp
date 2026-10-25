#include "ov006/Tasks.h"

extern "C" {

// Both tests have no effect, so MWCC drops the second load and compare but keeps the first.
void func_ov006_021cf414(ov006_TaskCE *self) {
    if (self->unk4C == NULL) {
        return;
    }
    if (self->unk50 == NULL) {
        return;
    }
}

}
