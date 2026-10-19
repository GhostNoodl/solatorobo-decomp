#include "types.h"
#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct Task02173c30 {
    u8 pad_00[0x14];
    s32 kind;
    u8 pad_18[0x20];
    struct Task02173c30 *next;
} Task02173c30;

typedef struct {
    u8 pad_00[0x24];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0x10];
    s32 unk_3c;
    u8 pad_40[0xc];
    Model *unk_4c;
} Obj02173c30;

extern "C" {
extern u8 *data_02097d48;
extern u8 data_ov000_021ccd34[];
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

static inline Task02173c30 *FindTask(s32 kind) {
    Task02173c30 *t;
    for (t = LFLD(Task02173c30 *, data_ov000_021ccd34, 8); t != NULL; t = t->next) {
        if (t->kind == kind) {
            return t;
        }
    }
    return NULL;
}

void func_ov000_02173c30(Obj02173c30 *self) {
    if (self->unk_24 == 0) {
        return;
    }
    if (FindTask(0x1a) != NULL) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    self->unk_28 = FX_SinCosTable_[((s32)(self->unk_24 << 14) >> 16) * 2];
    {
        s32 c = self->unk_3c;
        Model_SetPos(self->unk_4c, 0, LO_FX_MUL(0x1000 - FX_SinCosTable_[((s32)(self->unk_24 << 14) >> 16) * 2], -0xc0000));
        self->unk_4c->unk_150 = c;
    }
    Model_PlayPart(self->unk_4c, 0);
}

}
