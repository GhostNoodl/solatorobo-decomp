#include "types.h"

extern "C" {

s16 *func_ov000_02192a28(s16 *p) {
    switch (*p++) {
    case 0:
        p += 1;
        break;
    case 2:
    case 25:
        p += 1;
        break;
    case 3:
    case 26:
        p += 2;
        break;
    case 4:
        p += 1;
        break;
    case 5:
        p += 1;
        break;
    case 6:
        p += 1;
        break;
    case 7:
        p += 5;
        break;
    case 8:
    case 11:
        p += 6;
        break;
    case 9:
    case 12:
        p += 7;
        break;
    case 10:
    case 13:
        p += 10;
        break;
    case 14:
    case 17:
        p += 7;
        break;
    case 15:
    case 18:
        p += 8;
        break;
    case 16:
    case 19:
        p += 11;
        break;
    case 20:
        p += 10;
        break;
    case 21:
        p += 2;
        break;
    case 22:
        p += 3;
        break;
    }
    return p;
}

}
