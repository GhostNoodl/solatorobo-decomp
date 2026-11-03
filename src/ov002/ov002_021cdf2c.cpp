#include "ov002/ov002.h"

extern "C" {

bool Ov002Task_IsCurrent(void *p) {
    BOOL r = func_ov002_isCurrent021ccd40(p);
    return r;
}

void Task021ef530_PostUpdate(void) {
}

}
