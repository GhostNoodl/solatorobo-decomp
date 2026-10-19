#include "types.h"

#define __HI(x) *(1 + (int *)&x)
#define __LO(x) *(int *)&x

double fabs(double x) {
    __HI(x) &= 0x7fffffff;
    return x;
}
