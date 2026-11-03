#include "ov002/ov002.h"

extern "C" {

bool Ov002UiObj_IsShown(void *self) {
    BOOL r = func_ov002_isState2(self);
    return r;
}

}
