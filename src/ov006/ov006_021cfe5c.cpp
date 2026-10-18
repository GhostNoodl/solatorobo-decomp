#include "ov006/ov006.h"

extern "C" {

extern void *data_ov000_021ccd40;

static inline BOOL ov006_IsCurrent(void *p) {
    return data_ov000_021ccd40 == p;
}

BOOL func_ov006_021cfe5c(void *p) {
    return ov006_IsCurrent(p) ? TRUE : FALSE;
}

}
