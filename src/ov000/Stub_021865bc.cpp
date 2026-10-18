#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov002_021f0f80[];
void func_ov002_021ccde4();
void func_ov002_021cceb4(void *a);
void func_ov002_021cd068(void *a);

void func_ov000_021865bc(void) {
    func_ov002_021ccde4();
}

void func_ov000_021865c8(void) {
    func_ov002_021cceb4(*(void **)(data_ov002_021f0f80 + 0x0));
}

void func_ov000_021865e0(void) {
    func_ov002_021cd068(*(void **)(data_ov002_021f0f80 + 0x0));
}

}
