#include "types.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 8;
    u32 b8 : 8;
    u32 rest : 16;
} Bits02179ab8;

extern "C" {
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021c9c46[];
void *func_0203dd9c(u32 size);
void func_0204c030(void *p);
void *func_0204c0e8(void *g, u32 id);
void func_ov000_0215bb14(void *o, void *s);
void func_ov000_02173648(void *self);

void func_ov000_02179ab8(VObj *self) {
    VObj *o;
    void *g;
    u16 n;
    LFLD(u32, self, 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    func_0204c030(LFLD(void *, self, 0x3c));
    g = data_02149ef8;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x44) = o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x44), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x44);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x44);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 0x20000000;
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 0x80000000;
    LFLD(VObj *, self, 0x44)->vfunc_f4(2, func_0204c0e8(g, 0x33));
    LFLD(VObj *, self, 0x44)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = o;
    LFLD(s32, o, 0x88) = 0xe;
    LFLD(s32, LFLD(void *, self, 0x40), 0x24) = 0xf8;
    LFLD(s32, LFLD(void *, self, 0x40), 0x20) = 6;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s16, s, 0x64) = 4;
        LFLD(s16, s, 0x66) = 0x2e;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    LFLD(s16, LFLD(void *, self, 0x40), 0x48) = 0;
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) |= 0x10;
    LFLD(s32, LFLD(void *, self, 0x40), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    LFLD(VObj *, self, 0x40)->vfunc_10(func_0204c0e8(g, 0xc2));
    LFLD(VObj *, self, 0x40)->vfunc_14(func_0204c0e8(g, 0xc3));
    LFLD(VObj *, self, 0x40)->vfunc_08();
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) |= 0x80000;
    n = LFLD(Bits02179ab8, data_0214a424, 0x518).b8;
    if (n != 0) {
        func_ov000_0215bb14(LFLD(void *, self, 0x40), func_0204c0e8(LFLD(void *, self, 0x3c), (u16)(n - 1)));
    }
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(void *, s, 0x6c) = data_ov000_021c9c46;
        LFLD(s32, s, 0x70) = 6;
    }
    func_ov000_02173648(self);
}
}
