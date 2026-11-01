#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    char s[16];
} LoName16;

extern "C" {

extern void *data_0208cc88;
extern void *data_0208cc94;
extern void *data_02149ef8;
extern u8 *data_02097ce0;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void *func_02035f30(void *a, void *b, s32 c);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void *STD_CopyString(void *dst, void *src);
BOOL func_ov000_02152e5c(void *self);
void *func_ov000_0214c084(u8 *self, u16 *cmd, void *arr, u16 *count);
void func_020708fc(s32 a, LoName16 *out);
void func_02070b98(s32 a, LoName16 *out, s32 b, s32 c);
s32 func_0206ffa0(s32 a);
s32 func_0204c0e8(void *p, s32 a);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void func_0204ca70(void *win);

typedef struct {
    u32 lo : 2;
    u32 k : 5;
    u32 hi : 25;
} Bits0214c2d0;

void func_ov000_0214c2d0(Menu021ca94c *self) {
    LoName16 a;
    LoName16 b;
    void *res;
    u8 *m;
    void *fnt;

    self->unk_0c |= 0x10;
    self->unk_24 = 0x8c;
    self->unk_28 = 0x2b;
    self->unk_64 = 0;
    self->unk_66 = 0xc0 - self->unk_28;
    self->unk_68 = -0x1000;
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(self->unk_10, 0, 0xb);
        func_02041d9c(self->unk_10, 0, 0xc);
        func_02041d9c(self->unk_10, 0, 0xd);
        func_02041d9c(self->unk_10, 0, 0xe);
    }
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        void *arc;
        void *name;
        name = data_0208cc88;
        arc = data_0208cc94;
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString(m + 0x2c, arc);
    }
    self->unk_88 = m;
    {
        void *x = func_02035d5c(self->unk_88 + 0x2c);
        void *y = func_02034d88(x, self->unk_88 + 0x4c);
        func_020417e0(self->unk_88, y);
    }
    LFLD(u32, self->unk_88, 0x6c) |= 2;
    func_02041d9c(self->unk_88, 0, 6);
    func_02041c5c(self->unk_88, (void *)func_ov000_0214c084);
    func_02041c20(self->unk_88, 6, self);

    func_020708fc(0x1000, &a);
    func_02070b98(0x1000, &b, 1, 2);
    res = func_02034d88(func_02035f30(&a, &b, 2), &b);
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        func_02041218(m + 0x88);
        func_02041440(m, &b, 0);
        STD_CopyString(m + 0x2c, &a);
    }
    self->unk_84 = m;
    func_020417e0(m, res);
    LFLD(u32, self->unk_84, 0x6c) |= 2;
    func_02041d9c((u8 *)self->unk_84, 0, 0xffff);
    LFLD(u32, self->unk_84, 0x6c) |= 0x80000;
    LFLD(Bits0214c2d0, self->unk_84, 0x6c).k = 0x1e;
    LFLD(u32, self->unk_84, 0x6c) |= 0x100000;
    LFLD(u32, self->unk_84, 0x6c) |= 0x200000;
    LFLD(u32, self->unk_84, 0x6c) |= 0x20000;
    self->unk_2c = 1;
    self->unk_58 = 0;
    self->unk_5c = self->unk_28 + 0x40;
    self->unk_60 = 0;

    fnt = data_02149ef8;
    self->unk_b8 = 8;
    self->unk_b4 = func_0206ffa0(0x1000);
    self->unk_dc = func_0204c4fc(self->unk_b8, self->unk_c8, self->unk_b4, (u8 *)self + 0xd4, (u8 *)self + 0xd8, self->unk_c7 != 0 ? 1 : 0);
    LFLD(s32, data_02097ce0, 4) = self->unk_b8;
    self->unk_104 = 0x7fff;
    self->unk_106 = 0x67f;
    self->unk_108 = 0x9000;
    self->unk_94 |= 0x40;
    self->unk_94 |= 0x1000000;
    self->unk_94 |= 0x40000004;
    func_0204ca70((u8 *)self + 0x90);

    self->unk_170 = 4;
    self->unk_16c = func_0204c0e8(fnt, 0x117);
    self->unk_194 = func_0204c4fc(self->unk_170, self->unk_180, self->unk_16c, (u8 *)self + 0x18c, (u8 *)self + 0x190, self->unk_17f != 0);
    LFLD(s32, data_02097ce0, 4) = self->unk_170;
    self->unk_14c |= 0x40;
    self->unk_14c |= 0x1000000;
    self->unk_14c |= 0x40000004;
    func_0204ca70((u8 *)self + 0x148);
    LBIT(self, 0xc).b0 = 1;
}

}
