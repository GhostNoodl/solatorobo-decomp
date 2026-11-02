#include "ov000/VObj.h"

extern "C" {

void Heap_FreeHi(void *p);

void func_ov000_02165d78(void *self) {
    u8 *p = *(u8 **)((u8 *)self + 0x30);
    if (p != NULL && *(void **)(p + 0xcdc) != NULL) {
        Heap_FreeHi(*(void **)(p + 0xcdc));
        *(void **)(p + 0xcdc) = NULL;
    }
}

}
