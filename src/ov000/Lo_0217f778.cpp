#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

typedef struct {
    u8 pad_00[0x24];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0x20];
    Model *unk_4c;
    u8 pad_50[4];
    Model *unk_54;
} Obj0217f778;

extern "C" {
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02043d20(void *obj, int a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

void func_ov000_0217f778(Obj0217f778 *self) {
    Model *m;
    if (self->unk_24 == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    self->unk_28 = FX_SinCosTable_[((s32)(self->unk_24 << 14) >> 16) * 2];
    m = self->unk_4c;
    if (m != NULL) {
        Model_PlayPart(m, 0);
    }
    {
        Model *m2 = self->unk_54;
        if (m2 != NULL) {
            Model_PlayPart(m2, 0);
        }
    }
}

}
