#include "ov006/ov006.h"

extern "C" {

extern void *data_0208cc94;
extern u8 data_ov006_021ec864[];
BOOL func_02035b90(void *a, int b);

BOOL func_ov006_021d95a8(void) {
    BOOL a = func_02035b90(data_0208cc94, 7) != 0;
    return (a & func_02035b90(data_ov006_021ec864, 7)) ? TRUE : FALSE;
}

}
