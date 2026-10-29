#include "ov000/ModelPart.h"
#include "ov000/VObj.h"
#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
u8 func_02043d48(void *p);

void func_ov000_021bcd08(u8 *self) {
    Model *m;
    s32 y;
    VObj *obj;
    s32 w;
    s32 h;
    if (LFLD(s32, self, 0xc) != 2) {
        return;
    }
    y = (LFLD(s32, self, 0x1c) + LO_FX_MUL(0x1000 - FX_SinCosTable_[((LFLD(s32, self, 0x28) << 14) >> 16) * 2], -0x40000)) >> 12;
    MODEL_FLAGS(LFLD(Model *, self, 0x14))->polygon_id = func_02043d48(data_02097d48 + 0x8b0);
    LFLD(Model *, self, 0x14)->unk_150 = -0x99a;
    Model_SetPos(LFLD(Model *, self, 0x14), 0x54000, (y - 0x4e) << 12);
    m = LFLD(Model *, self, 0x14);
    Model_PlayPart(m, 0x1d);
    obj = LFLD(VObj *, self, 0x10);
    w = LFLD(s32, obj, 0x44);
    h = LFLD(s32, obj, 0x48) >> 1;
    LFLD(s32, obj, 0x70) = -0x98a;
    LFLD(VObj *, self, 0x10)->vfunc_20(0xd4 - (w >> 1), y + (0x12 - h));
    LFLD(VObj *, self, 0x10)->vfunc_90();
}

}
