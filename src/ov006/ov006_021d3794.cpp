#include "ov006/ov006.h"

extern "C" {

void *func_ov006_021d3874(void *self);

void *func_ov006_021d3794(void) {
    void *obj = func_0203dd9c(0x140);
    if (obj != NULL) {
        obj = func_ov006_021d3874(obj);
    }
    VCALL(obj, 08, 0x2a, 0xc8);
    return obj;
}

}
