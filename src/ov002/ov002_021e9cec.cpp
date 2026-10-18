#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e9cec(void *dst, u32 size, void *src, int mode, u8 idx) {
    void *s;
    func_02016e28(dst, 0, size);
    func_0201e5a0(dst, src, size);
    switch (mode) {
    case 0:
        s = data_ov002_021f0624[idx];
        break;
    case 1:
        s = data_ov002_021f064c;
        break;
    case 2:
        s = data_ov002_021f0624[idx];
        break;
    default:
        s = data_ov002_021f064c;
        break;
    }
    func_0201ea94(dst, size, data_ov002_021f0647, src, s);
}

void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx) {
    void *a;
    void *b;
    func_02016e28(dst, 0, size);
    func_0201e5a0(dst, src, size);
    switch (mode) {
    case 0:
        a = data_ov002_021f0624[idx];
        b = data_ov002_021f064d;
        break;
    case 1:
        b = data_ov002_021f0654;
        a = data_ov002_021f064c;
        break;
    case 2:
        a = data_ov002_021f0624[idx];
        b = data_ov002_021f065e;
        break;
    default:
        b = data_ov002_021f064c;
        a = b;
        break;
    }
    func_0201ea94(dst, size, data_ov002_021f0665, src, a, b);
}

}
