#include "ov000/VObj.h"

extern "C" {

void func_ov000_021722c4(VObj *o, BOOL en, s32 a, s32 b, s32 c, s32 d) {
    u32 p0 = ((a & 0xffff) << 16) | (b & 0xffff);
    u32 p1 = ((d & 0xffff) << 16) | (c & 0xffff);
    if (en) {
        o->vfunc_0c(0, 0xb, p0, p1);
    } else {
        o->vfunc_0c(0, 0xc, 0, 0);
    }
}

}
