#include "ov000/LoCommon.h"

extern "C" {

BOOL func_02054f10(void *a, s32 b);
extern u8 *data_02097dc8;
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
void func_ov000_02151664(void);
void func_ov000_0215f334(void *p);

void func_ov000_02158a58(VObj *self, s32 unused, s32 *pos) {
    s32 px;
    s32 a;
    s32 y;
    s32 z;
    u8 *q;
    px = pos[0];
    a = self->vfunc_8c();
    a += self->vfunc_30() + (px >> 12);
    y = (pos[1] >> 12) - 2;
    if (LFLD(void *, self, 0xd4)) {
        s32 c = self->vfunc_f0();
        z = LFLD(s16, self, 0x68);
        q = LFLD(u8 *, self, 0xd4);
        LFLD(s32, q, 8) = a + c;
        LFLD(s32, q, 0xc) = y;
        LFLD(s32, q, 0x10) = z - 0x40;
        func_ov000_0215f334(LFLD(void *, self, 0xd4));
    }
    if (LFLD(void *, self, 0xd8)) {
        px = pos[0];
        a = self->vfunc_88();
        a = self->vfunc_94() + (px >> 12) + (a >> 1);
        if (LFLD(u32, self, 0xc) & 0x800000) {
            a += 10;
        }
        z = LFLD(s16, self, 0x68) - 0x40;
        q = LFLD(u8 *, self, 0xd8);
        LFLD(s32, q, 8) = a;
        LFLD(s32, q, 0xc) = y;
        LFLD(s32, q, 0x10) = z;
        func_ov000_0215f334(LFLD(void *, self, 0xd8));
    }
}

}
