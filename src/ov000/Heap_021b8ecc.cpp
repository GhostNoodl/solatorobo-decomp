#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u8 pad_00[4];
    VObj *unk_04;
    u8 pad_08[0xc];
    VObj *unk_14;
    VObj *unk_18;
    VObj *unk_1c;
    void *unk_20;
} Obj021b8ecc;

extern "C" {

void func_ov000_0214bc10(void);
void func_ov000_0214c210(void);

void func_ov000_021b8ecc(Obj021b8ecc *self) {
    HEAP_DELETE_VOBJ(self->unk_18);
    HEAP_DELETE_VOBJ(self->unk_1c);
    HEAP_DELETE_VOBJ(self->unk_14);
    HEAP_DELETE_MODEL(self->unk_20);
    HEAP_DELETE_VOBJ(self->unk_04);
    func_ov000_0214bc10();
    func_ov000_0214c210();
}

}
