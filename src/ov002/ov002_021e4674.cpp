#include "ov002/ov002.h"

extern "C" {

// Row comparators of the item list (data_ov002_021eef8c, func_ov002_021e34fc): by the item's
// Param entry byte 2, then by id.
int func_ov002_021e4674(Obj021f002c *a, Obj021f002c *b) {
    u8 ca;
    u16 ia;
    u16 ib;
    u8 cb;
    int r;
    ia = a->id;
    ib = b->id;
    ca = Param_GetEntry(ia)[2];
    cb = Param_GetEntry(ib)[2];
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

int func_ov002_021e46c4(Obj021f002c *a, Obj021f002c *b) {
    u8 ca;
    u16 ia;
    u16 ib;
    u8 cb;
    int r;
    ia = a->id;
    ib = b->id;
    ca = Param_GetEntry(ia)[2];
    cb = Param_GetEntry(ib)[2];
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
