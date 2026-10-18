#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e391c(s32 *m, int rot) {
    m[0] = 0x1000;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0x1000;
    switch (rot) {
    case 0:
        break;
    case 1:
        m[0] = 0;
        m[1] = -0x1000;
        m[2] = 0x1000;
        m[3] = 0;
        break;
    case 2:
        m[0] = -0x1000;
        m[1] = 0;
        m[2] = 0;
        m[3] = -0x1000;
        break;
    case 3:
        m[0] = 0;
        m[1] = 0x1000;
        m[2] = -0x1000;
        m[3] = 0;
        break;
    }
}

void func_ov002_021e398c(s32 *m, int rot) {
    func_02011340(m);
    switch (rot) {
    case 0:
        break;
    case 1:
        m[0] = 0;
        m[2] = -0x1000;
        m[6] = 0x1000;
        m[8] = 0;
        break;
    case 2:
        m[0] = -0x1000;
        m[2] = 0;
        m[6] = 0;
        m[8] = -0x1000;
        break;
    case 3:
        m[0] = 0;
        m[2] = 0x1000;
        m[6] = -0x1000;
        m[8] = 0;
        break;
    }
}

}
