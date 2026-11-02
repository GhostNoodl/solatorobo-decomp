#include "ov000/Task.h"

extern "C" {

void Task_SetId(Task *self, s32 a, s32 b) {
    self->id = a;
    self->priority = b;
}

}
