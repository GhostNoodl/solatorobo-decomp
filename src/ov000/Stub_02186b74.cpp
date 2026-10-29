#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov008_021d0500[];
void func_ov008_021cd48c();
s32 func_ov008_021ce518(void *a);
void func_ov008_021cec20(void *a);

void func_ov000_02186b74(void) {
    func_ov008_021cd48c();
}

void func_ov000_02186b80(void) {
    func_ov008_021ce518(*(void **)(data_ov008_021d0500 + 0x0));
}

void func_ov000_02186b98(void) {
    func_ov008_021cec20(*(void **)(data_ov008_021d0500 + 0x0));
}

}
