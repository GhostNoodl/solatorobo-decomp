#include "ov000/VObj.h"

extern "C" {

BOOL func_ov000_0217bfe4(void *self) {
    if (*(void **)((u8 *)self + 0x64) != NULL) {
        return (BOOL)self;
    }
    return (*(u32 *)((u8 *)self + 0x4) & 0x10000) ? TRUE : FALSE;
}

void func_ov000_0217c004(void) {
}

}
