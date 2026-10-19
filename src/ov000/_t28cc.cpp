#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 b1 : 7;
} Bits021c28cc;

extern "C" {

//@ func_ov000_021c28cc
void func_ov000_021c28cc(u8 *self) {
    s32 x;
    s32 y;
    s32 z;
    VObj *t;
    if (LFLD(u8, self, 0x44) == 0) {
        return;
    }
    if (!LFLD(Bits021c28cc, self, 0x20).b0) {
        return;
    }
    s32 fx, fy;
    fy = LFLD(s32, self, 0x10) + ((LFLD(s32, self, 0x18) - 8) << 12);
    fx = LFLD(s32, self, 0xc) + 0xa000;
    x = (fx >> 12) - 0x80;
    y = (fy >> 12) - 0x60;
    z = LFLD(s32, self, 0x14);
    Model_SetPos(LFLD(Model *, self, 0x34), x << 12, (y + 7) << 12);
    LFLD(Model *, self, 0x34)->unk_150 = z;
    Model_PlayPart(LFLD(Model *, self, 0x34), 4);
    Model_SetPos(LFLD(Model *, self, 0x30), (x + 0x10) << 12, (y - 2) << 12);
    LFLD(Model *, self, 0x30)->unk_150 = z;
    Model_PlayPart(LFLD(Model *, self, 0x30), 6);
    LFLD(VObj *, self, 0x38)->vfunc_20((LFLD(s32, self, 0xc) + 0x40000) >> 12,
        (LFLD(s32, self, 0x10) + ((LFLD(s32, self, 0x18) - LFLD(s32, LFLD(VObj *, self, 0x38), 0x48)) << 11)) >> 12);
    LFLD(s32, LFLD(VObj *, self, 0x38), 0x70) = z;
    LFLD(VObj *, self, 0x38)->vfunc_90();
}

//@end
}
