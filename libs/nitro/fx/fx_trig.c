#include "nitro/fx.h"

u16 FX_AsinIdx(fx32 x) {
    s32 left, right, mid;
    fx16 val;
    fx16 xs;

    if (x >= 0) {
        left = 0;
        right = 1024;
    } else {
        left = 3072;
        right = 4096;
    }
    xs = (fx16)x;
    while (left <= right) {
        mid = (left + right) / 2;
        val = FX_SinCosTable_[mid * 2];
        if (xs == val) {
            break;
        }
        if (val < xs) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return (u16)(((mid * 2) << 16) / 8192);
}

u16 FX_AcosIdx(fx32 x) {
    s32 left, right, mid;
    fx16 val;
    fx16 xs;

    if (x >= 0) {
        left = 0;
        right = 1024;
    } else {
        left = 1024;
        right = 2048;
    }
    xs = (fx16)x;
    while (left <= right) {
        mid = (left + right) / 2;
        val = FX_SinCosTable_[mid * 2 + 1];
        if (xs == val) {
            break;
        }
        if (val < xs) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return (u16)(((mid * 2 + 1) << 16) / 8192);
}
