#include "ov000/Task.h"

extern "C" {

void func_ov000_02172f70(Task *self, s32 a, s32 b) {
    self->id = a;
    self->priority = b;
}

}
