#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov006_021ec860[];
extern u8 data_ov015_02213320[];
u32 func_ov004_021cd050();
void func_ov015_021fa868();
int func_ov006_021cd0ac(void *a);
void func_ov006_021cd264(void *a);
BOOL func_ov015_021faba0(void *a);
void func_ov015_021fb088(void *a);

void func_ov000_021860e0(void) {
    func_ov015_021fa868();
}

void func_ov000_021860ec(void) {
    func_ov015_021faba0(*(void **)(data_ov015_02213320 + 0x0));
}

void func_ov000_02186104(void) {
    func_ov015_021fb088(*(void **)(data_ov015_02213320 + 0x0));
}

void func_ov000_0218611c(void) {
    func_ov004_021cd050();
}

void func_ov000_02186128(void) {
    func_ov006_021cd0ac(*(void **)(data_ov006_021ec860 + 0x0));
}

void func_ov000_02186140(void) {
    func_ov006_021cd264(*(void **)(data_ov006_021ec860 + 0x0));
}

}
