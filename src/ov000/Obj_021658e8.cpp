#include "ov000/HeapScope.h"

typedef struct {
    u32 unk_00;
    void *unk_04;
} Ent021658e8;

typedef struct {
    u8 pad_00[9];
    u8 count;
    u8 pad_0a[0xc72];
    void *unk_c7c;
    void *unk_c80;
    void *unk_c84;
    Ent021658e8 *unk_c88;
    void *unk_c8c;
} Data021658e8;

typedef struct {
    u8 pad_00[0x30];
    Data021658e8 *unk_30;
} Obj021658e8;

extern "C" {
void func_0203df0c(void *p);

void func_ov000_021658e8(Obj021658e8 *self) {
    s32 i;
    if (self->unk_30 == NULL) {
        return;
    }
    for (i = 0; i < self->unk_30->count; i++) {
        if (self->unk_30->unk_c88[i].unk_04 != NULL) {
            func_0203df0c(self->unk_30->unk_c88[i].unk_04);
            self->unk_30->unk_c88[i].unk_04 = NULL;
        }
    }
    if (self->unk_30->unk_c88 != NULL) {
        func_0203df0c(self->unk_30->unk_c88);
        self->unk_30->unk_c88 = NULL;
    }
    if (self->unk_30->unk_c84 != NULL) {
        func_0203df0c(self->unk_30->unk_c84);
        self->unk_30->unk_c84 = NULL;
    }
    if (self->unk_30->unk_c80 != NULL) {
        func_0203df0c(self->unk_30->unk_c80);
        self->unk_30->unk_c80 = NULL;
    }
    if (self->unk_30->unk_c7c != NULL) {
        func_0203df0c(self->unk_30->unk_c7c);
        self->unk_30->unk_c7c = NULL;
    }
    HEAP_DELETE(void *, self->unk_30->unk_c8c, func_02041278(p); func_0203de1c(p));
    if (self->unk_30 != NULL) {
        func_0203df0c(self->unk_30);
        self->unk_30 = NULL;
    }
}
}
