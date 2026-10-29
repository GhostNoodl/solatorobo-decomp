#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
void func_02041c18(Model *m, s32 a);

void func_ov000_02161798(VObj *self, s32 a1, s32 *pos, s32 a3) {
    s32 x;
    s32 y;
    s32 w;
    s32 n;
    if (LFLD(Model *, self, 0x84) == NULL) {
        return;
    }
    x = (pos[0] >> 12) - 0x80;
    y = (pos[1] >> 12) - 0x65;
    Model_SetPos(LFLD(Model *, self, 0x84), (x - 8) << 12, y << 12);
    func_02041c18(LFLD(Model *, self, 0x84), LFLD(u16, self, 0x88));
    Model_PlayPart(LFLD(Model *, self, 0x84), 6);
    Model_SetPos(LFLD(Model *, self, 0x84), x << 12, y << 12);
    Model_PlayPart(LFLD(Model *, self, 0x84), 8);
    w = 10;
    for (n = LFLD(u16, self, 0x8a) / 10; n != 0; n /= 10) {
        w += 8;
    }
    Model_SetPos(LFLD(Model *, self, 0x84), (x + w) << 12, y << 12);
    func_02041c18(LFLD(Model *, self, 0x84), LFLD(u16, self, 0x8a));
    Model_PlayPart(LFLD(Model *, self, 0x84), 6);
}

}
