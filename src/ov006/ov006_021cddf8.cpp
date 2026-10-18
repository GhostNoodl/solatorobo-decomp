#include "ov006/ov006.h"

extern "C" {

extern void *data_ov000_021ccd44;
void func_ov000_0218084c(void *a, int b, int c);
void func_ov000_021736dc(void);
void *func_0206ec48(u16 id);
void func_0203cb78(s32 a, int b, int c);
void func_ov006_021db65c(void);
void func_ov006_021cd5a8(int type, void *obj);

void func_ov006_021cddf8(int type, void *obj, int arg) {
    switch (type) {
    case 2:
        func_ov006_021db65c();
        func_ov000_0218084c(data_ov000_021ccd44, 0x29, 0);
        break;
    case 3:
        func_ov006_021cd5a8(type, obj);
        func_0203cb78(0x1e000, 0, 0);
        func_0203cb78(0x1e000, 0, 1);
        break;
    case 4:
        if (obj != NULL) {
            func_ov000_0218084c(data_ov000_021ccd44, 0x2a, arg);
        } else {
            func_ov000_021736dc();
        }
        break;
    case 5:
        VCALL(obj, 74, func_0206ec48(0xb005), 0xb005, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb006), 0xb006, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb007), 0xb007, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb008), 0xb008, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb009), 0xb009, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb00a), 0xb00a, 0xffff, 0xffff);
        break;
    default:
        func_ov006_021cd5a8(type, obj);
        break;
    }
}

}
