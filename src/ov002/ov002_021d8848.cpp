#include "ov002/ov002.h"

extern "C" {

s32 Ov002_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

}
