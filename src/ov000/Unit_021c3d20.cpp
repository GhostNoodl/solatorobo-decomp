#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *data_0208cc88;
extern void *data_0208cc94;
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void *STD_CopyString(void *dst, void *src);
BOOL func_ov000_02152e5c(void *self);
void func_ov000_0215ec44(void *self);
void func_ov000_0215e8b0(void *self);
void *func_ov000_021c77bc(u8 *self, u16 *cmd, void *arr, u16 *count);
void *func_ov000_021c782c(u8 *self, void *req, void *buf, u16 *count);

void func_ov000_021c3d20(UnitBase021ccb54_021ccbe0 *self) {
    void *p;
    u8 *m;
    u8 *o;

    LBIT(self, 0xc).b1 = 0;
    self->unk_2c = 1;
    {
        s32 z = self->unk_68;
        self->unk_58 = -(self->unk_24 + 0x20);
        self->unk_60 = z;
    }
    self->unk_5c = 0;
    p = self->unk_94;
    if (p != NULL) {
        self->unk_28 = self->unk_20 * LFLD(s32, p, 0x18);
    } else {
        self->unk_28 = self->unk_20 * 0xc;
    }
    self->unk_28 += 0xf;
    self->unk_c0 = (self->unk_28 - 0x14) << 12;
    if (self->unk_98 < self->unk_20) {
        self->unk_c8 = 0x1000;
    } else {
        self->unk_c8 = FX_Div(self->unk_20 << 12, self->unk_98 << 12);
    }
    self->unk_c4 = FX_Div(self->unk_9c << 12, self->unk_98 << 12);
    if (self->unk_b4 == (s32)0x80000000) {
        self->unk_b4 = 0x4000;
    }
    if (self->unk_b0 == (s32)0x80000000) {
        if (self->unk_0c & 0x40000) {
            self->unk_b0 = (((self->unk_24 << 12) - 0x20000) >> 12) - 4;
        } else {
            self->unk_b0 = self->unk_24 - 4;
        }
    }
    if (self->unk_b8 == (s32)0x80000000) {
        self->unk_b8 = 0x20000;
    }
    self->unk_a0 = self->unk_94;
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(self->unk_10, 0, 2);
        func_02041d9c(self->unk_10, 0, 4);
        func_02041d9c(self->unk_10, 0, 6);
        func_02041c5c(self->unk_10, (void *)func_ov000_021c77bc);
        func_02041c20(self->unk_10, 2, self);
    }
    if (self->unk_0c & 0x400000) {
        m = (u8 *)Heap_Alloc(0x160);
        if (m) {
            void *arc;
            void *name;
            name = data_0208cc88;
            arc = data_0208cc94;
            func_02041218((struct PlttRes *)(m + 0x88));
            func_02041440(m, name, 0);
            STD_CopyString(m + 0x2c, arc);
        }
        self->unk_84 = m;
        func_020417e0(self->unk_84, func_02034d88(func_02035d5c(m + 0x2c), self->unk_84 + 0x4c));
        LFLD(u32, self->unk_84, 0x6c) |= 2;
        func_02041d9c(self->unk_84, 0, 6);
        func_02041c20(self->unk_84, 6, self);
        if (self->unk_0c & 0x800000) {
            func_02041d9c(self->unk_84, 0, 7);
        }
        func_02041c5c(self->unk_84, (void *)func_ov000_021c782c);
    }
    if ((void *)self->unk_90 == NULL) {
        o = (u8 *)Heap_Alloc(0x2c);
        if (o != NULL) {
            func_ov000_0215ec44(o);
        }
        self->unk_90 = o;
        func_ov000_0215e8b0(o);
        LFLD(s32, self->unk_90, 0x10) = self->unk_b0 << 12;
        LFLD(u32, LFLD(u8 *, self->unk_90, 0x28), 0x6c) &= ~0x200000;
    }
    LBIT(self, 0xc).b0 = 1;
}
}
