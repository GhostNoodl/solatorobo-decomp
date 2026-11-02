#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern u8 data_02fe1534[];
extern void *data_02fe152c;
void func_ov000_0215eab4(void *p);
void func_020592c4(void *a, s32 b, s32 c, u16 d, s32 e);

void func_ov000_021589bc(LoBase021caac8_021cb2a8 *self, s32 unused, s32 *pos) {
    s32 cur;
    s32 xoff;
    s32 h;
    s32 z;
    s32 y;
    s32 px;
    s32 py;
    void *t;
    if (self->unk_94 == NULL) {
        return;
    }
    if (!(self->unk_0c & 0x2000000)) {
        return;
    }
    h = self->vfunc_40() << 12;
    if (self->unk_0c & 0x1000000) {
        xoff = (0x80 - self->unk_64) << 12;
    } else {
        xoff = -0x8000;
    }
    cur = self->unk_b1;
    z = self->posZ - 0xc0;
    y = self->vfunc_34();
    px = pos[0];
    py = pos[1];
    {
    s32 yy = h * cur + (py + (y << 12));
    t = self->unk_ac;
    LFLD(s32, t, 4) = px + xoff;
    LFLD(s32, t, 8) = yy - 0x2000;
    }
    LFLD(s32, t, 0xc) = z;
    func_ov000_0215eab4(self->unk_ac);
}

}
