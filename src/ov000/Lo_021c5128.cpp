#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 5;
    u32 unk_18 : 1;
    u32 unk_19 : 1;
    u32 unk_20 : 1;
    u32 unk_21 : 1;
    u32 unk_22 : 10;
} Flags021c5128;

#define FLAGSX(m) ((Flags021c5128 *)&(m)->flags)

extern "C" {

void func_02041c20(Model *model, s32 a, void *b);
void func_ov000_021c79a0(void);

void func_ov000_021c5128(u8 *self, s32 unused, s32 *pos) {
    s16 z = LFLD(s16, self, 0x68) + 0x80;
    LFLD(void *, LFLD(Model *, self, 0x10), 0x158) = (void *)func_ov000_021c79a0;
    LFLD(Model *, self, 0x10)->flags |= 0x80000;
    LFLD(Model *, self, 0x10)->flags |= 0x200000;
    FLAGSX(LFLD(Model *, self, 0x10))->alpha = 0x1e;
    {
        s32 x = pos[0];
        s32 y = pos[1];
        x += (LFLD(s32, self, 0x24) << 12) - LFLD(s32, self, 0xb8);
        y += ((LFLD(s32, self, 0x28) << 12) - LFLD(s32, self, 0xc0)) >> 1;
        Model_SetPos(LFLD(Model *, self, 0x10), x, y);
    }
    LFLD(Model *, self, 0x10)->unk_150 = z;
    func_02041c20(LFLD(Model *, self, 0x10), 6, self + 0xc0);
    Model_PlayPart(LFLD(Model *, self, 0x10), 6);
    LFLD(void *, LFLD(Model *, self, 0x10), 0x158) = NULL;
}

}
