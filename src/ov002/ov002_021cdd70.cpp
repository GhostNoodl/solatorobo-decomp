#include "ov002/ov002.h"

extern "C" {

void func_ov002_021cdd70(void *p) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = FIELD(data_ov000_021ccd40, 0x14, void *);
    } else {
        data_ov000_021ccd38 = NULL;
    }
    data_ov000_021ccd40 = p;
}

}
