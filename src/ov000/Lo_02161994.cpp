#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 5;
    u32 unk_18 : 1;
    u32 unk_19 : 13;
} Flags02161994;

#define FLAGS02161994(m) ((Flags02161994 *)&(m)->flags)

extern "C" {
extern const s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);

void func_ov000_02161994(VObj *self, s32 a1, s32 *pos, s32 y) {
    s32 t;
    s32 off;
    u8 alpha;
    s32 x;
    t = FX_Div(LFLD(s32, self, 0x94) << 12, 0x3c000);
    off = LO_FX_MUL(FX_SinCosTable_[(LO_FX_MUL(t, 0x7fff000) >> 16) * 2], 0x4000);
    alpha = FLAGS02161994(LFLD(Model *, self, 0x10))->alpha;
    if (LFLD(s32, self, 0x98) != 0) {
        FLAGS02161994(LFLD(Model *, self, 0x10))->unk_18 = 1;
        x = pos[0];
        y = pos[1];
        FLAGS02161994(LFLD(Model *, self, 0x10))->alpha = (u8)LFLD(s32, self, 0x98);
        s32 py = y - 0x60000;
        py -= off + 0x4000;
        Model_SetPos(LFLD(Model *, self, 0x10), x - 0x9c000, py);
        Model_PlayPart(LFLD(Model *, self, 0x10), 10);
        FLAGS02161994(LFLD(Model *, self, 0x10))->unk_18 = 0;
    }
    if (LFLD(s32, self, 0x9c) != 0) {
        x = pos[0];
        x -= 0x9c000;
        y = pos[1] - 0x60000;
        FLAGS02161994(LFLD(Model *, self, 0x10))->alpha = (u8)LFLD(s32, self, 0x9c);
        s32 py2 = y;
        py2 += off + 0x4000;
        Model_SetPos(LFLD(Model *, self, 0x10), x, py2);
        Model_PlayPart(LFLD(Model *, self, 0x10), 10);
    }
    FLAGS02161994(LFLD(Model *, self, 0x10))->alpha = alpha;
}

}
