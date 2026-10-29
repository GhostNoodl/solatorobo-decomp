#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u32 unk_00;
    void *unk_04;
    void *unk_08[8];
    u8 pad_28[0x18];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
} Obj021bd7b8;

extern "C" {

void *func_ov000_0218ea20(void *p);

void func_ov000_021bd7a0(void *self) {
    void (*fn)(void *) = *(void (**)(void *))((u8 *)self + 0x64);
    if (fn != NULL) {
        fn(self);
    }
}

void func_ov000_021bd7b8(Obj021bd7b8 *self) {
    s32 i;
    HEAP_DELETE_FN(self->unk_04, func_ov000_0218ea20);
    for (i = 0; i < 4; i++) {
        self->unk_08[i] = 0;
    }
    for (i = 4; i < 8; i++) {
        HEAP_DELETE_MODEL(self->unk_08[i]);
    }
    self->unk_40 = 10;
    self->unk_48 = -1;
    self->unk_00 &= ~8;
}

}
