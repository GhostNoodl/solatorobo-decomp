#include "ov010/ov010.h"

extern "C" {

extern const Ov010Vec data_ov010_0220fa88;
extern const char *const data_ov010_0220ebc0[];
extern s32 STD_CompareString(const char *a, const char *b);

Ov010Vec func_ov010_021fa6a0(const char *name) {
    Ov010Vec v = data_ov010_0220fa88;
    if (STD_CompareString(name, data_ov010_0220ebc0[4]) == 0) {
        v.x = 0x333;
        v.y = 0x84ee;
        v.z = 0x266f;
    } else if (STD_CompareString(name, data_ov010_0220ebc0[5]) == 0) {
        v.x = -0x2008;
        v.y = 0x6819;
        v.z = 0x266f;
    }
    return v;
}

Ov010Vec func_ov010_021fa740(const char *name) {
    Ov010Vec v = data_ov010_0220fa88;
    if (STD_CompareString(name, data_ov010_0220ebc0[4]) == 0) {
        v.x = 0x2008;
        v.y = 0x6819;
        v.z = 0x266f;
    } else if (STD_CompareString(name, data_ov010_0220ebc0[5]) == 0) {
        v.x = -0x333;
        v.y = 0x84ee;
        v.z = 0x266f;
    }
    return v;
}

Ov010Vec func_ov010_021fa7e0(void *obj) {
    return Ov010_AttachOffset(obj);
}

}
