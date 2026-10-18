#include "ov002/ov002.h"

extern "C" {

int func_ov002_021e4674(void *a, void *b) {
    u8 ca;
    u16 ia;
    u16 ib;
    u8 cb;
    int r;
    ia = FIELD(a, 0x38, u16);
    ib = FIELD(b, 0x38, u16);
    ca = func_0206ede8(ia)[2];
    cb = func_0206ede8(ib)[2];
    if (ca == cb) {
        if (ia < ib) {
            r = 1;
        } else if (ia == ib) {
            r = 0;
        } else {
            r = -1;
        }
    } else if (ca < cb) {
        r = 1;
    } else {
        r = -1;
    }
    return r;
}

int func_ov002_021e46c4(void *a, void *b) {
    u8 ca;
    u16 ia;
    u16 ib;
    u8 cb;
    int r;
    ia = FIELD(a, 0x38, u16);
    ib = FIELD(b, 0x38, u16);
    ca = func_0206ede8(ia)[2];
    cb = func_0206ede8(ib)[2];
    if (ca == cb) {
        if (ia > ib) {
            r = 1;
        } else if (ia == ib) {
            r = 0;
        } else {
            r = -1;
        }
    } else if (ca > cb) {
        r = 1;
    } else {
        r = -1;
    }
    return r;
}

}
