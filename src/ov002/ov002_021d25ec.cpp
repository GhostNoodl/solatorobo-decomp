#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d25ec(Task50 *self) {
    u32 saved;
    int i;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_44);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x48));
    HEAP_POP(saved);
    for (i = 0; i < 7; i++) {
        func_ov002_021e4904((u8 *)self + 0x4c + i * 0x18);
    }
    func_02036838(data_02097cdc, (u8 *)self + 0xf4, 7, 0);
}

void func_ov002_021d2720(void *self) {
    func_ov002_021d4540((u8 *)self + 0xf4, 0x20, data_ov002_021ef5ac[3], data_ov002_021ef650, func_0206e8f0());
    func_020359d0((u8 *)self + 0xf4, 7, 0);
}

bool func_ov002_021d276c(void *self) {
    return func_02035b90((u8 *)self + 0xf4, 7) != 0;
}

}
