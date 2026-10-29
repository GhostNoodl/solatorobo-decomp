#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021ccd34[];
void *func_ov000_021761a0(void);

void func_ov000_021761f0(void) {
    *(void **)(data_ov000_021ccd34 + 0x18) = (void *)func_ov000_021761a0;
}

}
