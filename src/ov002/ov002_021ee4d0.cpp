#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ee4d0(void) {
    void *o4 = data_ov002_021f0fa0[1];
    BOOL flag = FIELD(data_02097d48, 0xa30, Bits8).b4 ? TRUE : FALSE;
    VObject *v;
    if (FIELD(o4, 8, s32) != 3 && FIELD(o4, 8, s32) != 7) {
        return;
    }
    for (v = (VObject *)data_ov002_021f0fa0[0]; v != NULL; v = FIELD(v, 0x2c, VObject *)) {
        v->v0xc(flag);
    }
    if (FIELD(o4, 8, s32) == 3) {
        func_ov002_021eea74(o4);
    }
}

}
