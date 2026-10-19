#include "types.h"

#define __HI(x) *(1 + (int *)&x)
#define __LO(x) *(int *)&x

double copysign(double x, double y) {
    __HI(x) = (__HI(x) & 0x7fffffff) | (__HI(y) & 0x80000000);
    return x;
}
