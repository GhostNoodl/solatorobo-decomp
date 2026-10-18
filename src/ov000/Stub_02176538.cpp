#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021ccd34[];
extern u8 data_02fe1534[];
s32 func_0205a9c8(void *p);
void func_0205aa30(void *p);

BOOL func_ov000_02176538(void) {
    BOOL result = TRUE;
    if (func_0205a9c8(*(void **)(data_ov000_021ccd34 + 0x14)) == 0) {
        result = FALSE;
    }
    return result;
}

void func_ov000_02176560(void) {
    if ((*(VObj **)(data_ov000_021ccd34 + 0x14))->vfunc_34() == 0) {
        func_0205aa30(*(void **)(data_ov000_021ccd34 + 0x14));
    }
}


void func_ov000_02176590(s16 v) {
    *(s16 *)(data_02fe1534 + 0x7a) = v;
    (*(VObj **)(data_ov000_021ccd34 + 0x14))->vfunc_38(1);
    *(s16 *)(data_02fe1534 + 0x7a) = 0;
}
}
