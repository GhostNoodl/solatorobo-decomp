#include "ov000/VObj.h"

extern "C" {

void func_0203df0c(void *p);

void func_ov000_0215a04c(void *self) {
    *(s32 *)((u8 *)self + 0xd4) = -1;
    *(s32 *)((u8 *)self + 0xd8) = 0;
    *(s32 *)((u8 *)self + 0xdc) = 0;
}

void func_ov000_0215a064(void *self) {
    if (*(void **)((u8 *)self + 0xd8) != NULL) {
        func_0203df0c(*(void **)((u8 *)self + 0xd8));
        *(void **)((u8 *)self + 0xd8) = NULL;
    }
}

}
