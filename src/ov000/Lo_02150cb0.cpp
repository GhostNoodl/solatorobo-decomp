#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021ccd24[];
void func_ov000_02153fd8(void *p);

struct Obj02150cb0 {
    u8 unk_00[0x42];
    u16 unk_42;
    u8 unk_44[0x10];
    void *unk_54;
    u8 unk_58[0x8];
    VObj unk_60;
    u8 unk_64[0xb4];
    VObj unk_118;
    u8 unk_11c[0xb4];
    VObj unk_1d0;
    u8 unk_1d4[0xb4];
    VObj unk_288;
    u8 unk_28c[0xb4];
    VObj unk_340;
    u8 unk_344[0xb4];
    VObj unk_3f8;
};

void func_ov000_02150cb0(Obj02150cb0 *self) {
    self->unk_60.vfunc_08();
    self->unk_118.vfunc_08();
    self->unk_1d0.vfunc_08();
    self->unk_288.vfunc_08();
    self->unk_340.vfunc_08();
    self->unk_3f8.vfunc_08();
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_54 != NULL) {
            void *p = self->unk_54;
            if (p != NULL) {
                func_ov000_02153fd8(p);
                Heap_Free(p);
            }
            self->unk_54 = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x58);
    LO_FREE_V(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LO_FREE_M(self, 0x48);
    LO_FREE_M(self, 0x44);
    LO_FREE_V(self, 0x3c);
    if (self->unk_42 == 0xffff) {
        LO_FREE_V(data_ov000_021ccd24, 8);
    }
}

}
