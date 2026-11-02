#include "ov000/Task.h"

static inline BOOL Task_TestFlag4(Task *self) { return self->unk_04_4 != 0; }

extern "C" {

bool Task_GetFlag4(Task *self) {
    return Task_TestFlag4(self);
}

}
