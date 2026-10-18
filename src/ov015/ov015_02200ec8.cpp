#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
extern u8 data_ov015_022128ec[];
void func_ov015_0220f4d4(void *p);
void func_ov015_02207738(void *p);
extern u8 data_ov015_0221294c[];
void func_ov000_0218fee4(void *p);
void func_ov000_0218ea20(void *p);
extern u8 data_ov015_0221293c[];
extern char data_ov015_022128ab[];
extern void *data_02097cdc;
void func_02036838(void *a, void *b, int c, int d);
void func_0206e900(char *buf, const char *name);
void func_02041558(void *p);
void func_02041278(void *p);
extern u8 data_ov015_02213198[];
void func_ov015_02210b58(void *p);

s32 func_ov015_02200ec8(u8 *self, Ov015Stat *st, s32 base) {
    s32 m = st->unk_28;
    s32 b = st->unk_14;
    s32 a = st->unk_10;
    switch (m) {
    case 3:
        base += 0x7b;
        break;
    case 2:
        base = 0x333;
        break;
    default:
        if (a == 0) {
            base = 0;
        } else {

            if (b == 4) {
                base = 0x333;
            } else {
                base += 0x1e;
            }
            if ((FLD(s32, self, 0xc) >> 12) % 20 == 0) {

                func_02049a48(data_02097e4c, 0x48, -1, -1, -1);
            }
        }
        break;
    }
    return base;
}

void func_ov015_02200f74(u8 *self) {
    FLD(s32, self, 0x8) = 2;
    FLD(s32, self, 0xc) = 0;
    FLD(u8, self, 0x10) = 0;
    FLD(s32, self, 0x14) = 1;
    FLD(s32, self, 0x18) = 0;
    FLD(s32, self, 0x1c) = 0;
    FLD(s32, self, 0x20) = 0;
    FLD(s32, self, 0x24) = 0;
    FLD(s32, self, 0x28) = 0;
    FLD(s32, self, 0x2c) = 0;
    FLD(s32, self, 0x90) = 0;
    data_ov015_0221332c.unk_00 = 0x1f4000;
    data_ov015_0221332c.unk_04 = 0;
    data_ov015_0221332c.unk_08 = 1;
    data_ov015_0221332c.unk_0c = 0;
    data_ov015_0221332c.unk_14 = 1;
    data_ov015_0221332c.unk_10 = 1;
    data_ov015_0221332c.unk_18 = 0;
    data_ov015_0221332c.unk_1c = 0;
    data_ov015_0221332c.unk_1d = 0;
    data_ov015_0221332c.unk_20 = 0;
    data_ov015_0221332c.unk_24 = 0;
    data_ov015_0221332c.unk_28 = 0;
    data_ov015_0221332c.unk_2c = 0;
    data_ov015_0221332c.unk_30 = -1;
}

void *func_ov015_02200ff4(void *self) {
    SET_VT(self, data_ov015_022128ec);
    func_ov015_0220f4d4(self);
    func_0203de1c(self);
    return self;
}

void func_ov015_0220101c(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    {
    u8 *o = FLD(u8 *, self, 0x18);
    if (o != NULL) {
        if (o != NULL) {
            func_ov015_02207738(o);
            func_0203de1c(o);
        }
        FLD(void *, self, 0x18) = NULL;
    }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x20));
    HEAP_POP(saved);
    if (FLD(u8 *, self, 0x1c) != NULL) {
        u8 *n;
        for (n = FLD(u8 *, FLD(u8 *, self, 0x1c), 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
            if (FLD(void *, n, 0x4) != NULL) VCALL(FLD(void *, n, 0x4))->v04();
        }
        HEAP_PUSH(saved);
        DELETE_V(FLD(void *, self, 0x1c));
        HEAP_POP(saved);
    }
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x24));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x28));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x90));
    HEAP_POP(saved);
}

void *func_ov015_022011c4(u8 *self) {
    SET_VT(self, data_ov015_0221294c);
    func_ov000_0218fee4(self + 0x57c);
    func_ov000_0218ea20(self + 0x444);
    func_ov000_0218fee4(self + 0x35c);
    func_ov000_0218ea20(self + 0x224);
    func_ov000_0218fee4(self + 0x13c);
    func_ov000_0218ea20(self + 0x4);
    func_0203de1c(self);
    return self;
}

void *func_ov015_02201220(u8 *self) {
    char buf[0x20];
    SET_VT(self, data_ov015_0221293c);
    {
        u32 saved;
        HEAP_PUSH(saved);
        {
            u8 *o = FLD(u8 *, self, 0x24);
            if (o != NULL) {
                if (o != NULL) {
                    func_02041558(o);
                    func_02041278(o + 0x88);
                    func_0203de1c(o);
                }
                FLD(void *, self, 0x24) = NULL;
            }
        }
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        {
            u8 *o = FLD(u8 *, self, 0x28);
            if (o != NULL) {
                if (o != NULL) {
                    func_02041558(o);
                    func_02041278(o + 0x88);
                    func_0203de1c(o);
                }
                FLD(void *, self, 0x28) = NULL;
            }
        }
        HEAP_POP(saved);
    }
    func_0206e900(buf, data_ov015_022128ab);
    func_02036838(data_02097cdc, buf, 7, 0);
    func_0203de1c(self);
    return self;
}

void *func_ov015_0220131c(void *self) {
    SET_VT(self, data_ov015_02213198);
    func_ov015_02210b58(self);
    func_0203de1c(self);
    return self;
}

}
