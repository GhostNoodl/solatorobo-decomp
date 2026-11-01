#include "ov000/LoCommon.h"

extern "C" {

BOOL func_02054f10(void *a, s32 b);
extern u8 *data_02097dc8;
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
BOOL func_ov000_02151664(void *p, u8 *msg);
void func_ov000_0215f334(void *p);

struct Obj02158a58 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 unk_10[0x58];
    s16 unk_68;
    u8 unk_6a[0x6a];
    void *unk_d4;
    void *unk_d8;
};

void func_ov000_02158a58(Obj02158a58 *self, s32 unused, s32 *pos) {
    s32 px;
    s32 a;
    s32 y;
    s32 z;
    u8 *q;
    px = pos[0];
    a = self->vfunc_8c();
    a += self->vfunc_30() + (px >> 12);
    y = (pos[1] >> 12) - 2;
    if (self->unk_d4) {
        s32 c = self->vfunc_f0();
        z = self->unk_68;
        q = (u8 *)self->unk_d4;
        LFLD(s32, q, 8) = a + c;
        LFLD(s32, q, 0xc) = y;
        LFLD(s32, q, 0x10) = z - 0x40;
        func_ov000_0215f334(self->unk_d4);
    }
    if (self->unk_d8) {
        px = pos[0];
        a = self->vfunc_88();
        a = self->vfunc_94() + (px >> 12) + (a >> 1);
        if (self->unk_0c & 0x800000) {
            a += 10;
        }
        z = self->unk_68 - 0x40;
        q = (u8 *)self->unk_d8;
        LFLD(s32, q, 8) = a;
        LFLD(s32, q, 0xc) = y;
        LFLD(s32, q, 0x10) = z;
        func_ov000_0215f334(self->unk_d8);
    }
}

}
