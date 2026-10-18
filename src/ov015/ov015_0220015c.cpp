#include "ov015/ov015.h"

extern "C" {

extern void **data_0214a420;
s32 func_02065748(void *a, void *b);
s32 func_ov015_02209fb8(s32 x);
u8 *func_02066774(void *a, void *b, int c, void *d);
void *func_ov015_0220a0c8(u8 *self);
extern char data_ov015_022128c1[];
extern char data_ov015_022128d5[];
u8 *func_02066df0(void);
void func_ov015_02207c30(u8 *p);
BOOL func_ov015_022003ec(u8 *self);
void func_ov015_02209b80(u8 *self, s32 a, s32 b);
void func_ov015_021fd00c(u8 *self, s32 mode, const Ov015VecC *v);

void func_ov015_0220015c(Ov015Obj34 *self) {
    self->unk_04 = NULL;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
}

void func_ov015_02200194(Ov015Obj34 *self) {
    u32 saved;
    if (func_02065748(data_0214a420, self->unk_04) == 0) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(self->unk_04);
    HEAP_POP(saved);
}

BOOL func_ov015_02200204(u8 *self, u8 *a, u8 *b, u8 *c, s32 d) {
    BOOL r = TRUE;
    FLD(s32, self, 0x30) = d;
    FLD(u8 *, self, 0x24) = a;
    FLD(u8 *, self, 0x28) = b;
    FLD(u8 *, self, 0x2c) = c;
    switch (FLD(s32, self, 0x8)) {
    case 0: {
        u8 *m;
        FLD(u16, a, 0xd3c) = 1;
        FLD(Ov015Vec, a, 0xd4c) = FLD(Ov015Vec, b, 0x40);
        m = (u8 *)func_0203dd9c(0x2c);
        if (m != NULL) m = (u8 *)func_ov015_0220a0c8(m);
        func_ov015_02209b80(b, (s32)m, 2);
        FLD(s32, b, 0xac) = -0x32000;
        FLD(s32, b, 0xb0) = 0x32000;
        FLD(s32, b, 0xb4) = 0x32000 - 0x69000;
        FLD(s32, b, 0xb8) = 0x32000 - 0xdc000;
        data_ov015_0221332c.unk_00 = func_ov015_02209fb8(FLD(s32, b, 0x48));
        FLD(s32, self, 0x8) = 1;
    }
    case 1: {
        BOOL busy;
        if (FLD(s32, self, 0xc) > 0x78000) {
            busy = FALSE;
        } else {
            if (FLD(s32, self, 0xc) == 0x28000) {
                FLD(s32, func_02066df0(), 0xd4) = 1;
            }
            func_ov015_02207c30(a);
            busy = TRUE;
            func_ov015_021fd00c(c, busy, (const Ov015VecC *)(b + 0x40));
            FLD(s32, self, 0xc) += 0x1000;
        }
        if (!busy) {
            Ov015Vec v = FLD(Ov015Vec, a, 0xd08);
            FLD(u8 *, self, 0x4) = func_02066774(data_ov015_022128c1, data_ov015_022128d5, 0, &v);
            FLD(s32, FLD(u8 *, self, 0x4), 0xd4) = 3;
            FLD(s32, FLD(u8 *, self, 0x4), 0x50) = -0x32000;
            VCALL(FLD(u8 *, self, 0x4))->v14(0x333, 0x333, 0x333);
            FLD(s32, FLD(u8 *, self, 0x4), 0xc8) = -1;
            FLD(s32, self, 0xc) = 0;
            FLD(s32, self, 0x8) = 2;
        }
        break;
    }
    case 2:
        if (!func_ov015_022003ec(self)) FLD(s32, self, 0x8) = 3;
        break;
    case 3:
        r = FALSE;
        break;
    }
    FLD(u8 *, self, 0x24) = NULL;
    FLD(u8 *, self, 0x28) = NULL;
    FLD(u8 *, self, 0x2c) = NULL;
    FLD(s32, self, 0x30) = 0;
    return r;
}

}
