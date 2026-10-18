#include "ov006/ov006.h"

extern "C" {

void *func_ov006_021d1f68(void *self);

void *func_ov006_021d1dbc(void) {
    void *obj = func_0203dd9c(0x7c);
    if (obj != NULL) {
        obj = func_ov006_021d1f68(obj);
    }
    VCALL(obj, 08, 0x29, 0xc8);
    return obj;
}

}
