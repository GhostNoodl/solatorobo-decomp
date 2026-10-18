#include "ov006/ov006.h"

extern "C" {

static inline BOOL ov006_Task_IsState2(ov006_Task *self) {
    return self->type == 2;
}

BOOL func_ov006_021cfa60(ov006_Task *self) {
    return ov006_Task_IsState2(self) ? TRUE : FALSE;
}

}
