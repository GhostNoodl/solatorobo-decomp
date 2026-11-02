#include "ov000/VObj.h"
#include "ov000/Bss021ccd74.h"
#include "nitro/mi.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
    u8 unk_04[0x24];
    MtxFx33 unk_28;
    VecFx32 unk_4c;
    u8 unk_58[0x24];
} Sub021c2090;

typedef struct {
    u8 unk_00[0x24];
    void *unk_24;
    u8 unk_28[0x6a];
    u8 unk_92;
    u8 unk_93[0x21];
    Sub021c2090 *unk_b4;
} Obj021c2090;

extern "C" {

void func_ov000_021c2090(Obj021c2090 *self) {
    Sub021c2090 *sub = self->unk_b4;
    if (data_ov000_021ccd74.unk_08 != NULL) {
        sub->b1 = 0;
        MI_Copy36B(data_ov000_021ccd74.unk_08, &sub->unk_28);
        data_ov000_021ccd74.unk_08 = NULL;
    }
    if (data_ov000_021ccd74.unk_10 != NULL) {
        sub->b2 = 0;
        VEC_Add(&sub->unk_4c, data_ov000_021ccd74.unk_10, &sub->unk_4c);
        data_ov000_021ccd74.unk_10 = NULL;
    }
    self->unk_24 = NULL;
    self->unk_92 = 0;
}

}
