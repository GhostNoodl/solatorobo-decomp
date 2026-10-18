#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_0220c09c(Ov014Actor *self);
extern void func_ov014_0220cd74(Ov014Actor *self);

void func_ov014_0220afb8(Ov014Actor *self) {
    switch (*FLD(s16 *, self, 0xf0)) {
    case 9:
        func_ov014_0220c09c(self);
        break;
    case 10:
        func_ov014_0220cd74(self);
        break;
    }
}

}
