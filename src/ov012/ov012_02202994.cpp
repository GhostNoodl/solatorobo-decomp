#include "ov012/ov012.h"

extern "C" {
void func_ov012_02202994(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = FLD(u16, self, 0xe0);
        self->unk_48->unk_30 = 0x40000000;
    }
    func_ov000_02196860(self);
}
}

extern "C" {
void func_ov012_022029c8(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_64 = 0x1800;
        func_02065f88(0x69, &self->pos);
    }
    func_ov000_0219763c(self);
}
}

extern "C" {
void func_ov012_02202a00(Ov012Actor *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40((u8 *)self + 0x24));
    }
}
}

extern "C" {
void func_ov012_02202a2c(void) {
}
}

extern "C" {
void func_ov012_02202a30(void) {
}
}

extern "C" {
void func_ov012_02202a34(void) {
}
}

extern "C" {
void func_ov012_02202a38(void) {
}
}

extern "C" {
void func_ov012_02202a3c(void) {
}
}

extern "C" {
void func_ov012_02202a40(void) {
}
}

extern "C" {
void func_ov012_02202a44(void) {
}
}

extern "C" {
void *func_ov012_02202a48(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void *func_ov012_02202a64(void *self) {
    func_ov000_0219429c(self);
    return self;
}
}

extern "C" {
void func_ov012_02202a78(Ov012Actor *self, Ov012Actor *other) {
    u16 *hp = other->unk_50;
    s32 pct = (u16)(hp[0] * 100 / hp[1]);
    u16 *st = FLD(u16 *, self, 0xc);
    if (pct >= 70) {
        if (st[2] != 0) {
            func_ov003_021cf278(self, 0, 0);
        }
    } else if (pct >= 35) {
        if (st[2] != 1) {
            func_ov003_021cf278(self, 1, 0);
        }
    } else {
        if (st[2] != 2) {
            func_ov003_021cf278(self, 2, 0);
        }
    }
}
}

extern "C" {
extern u8 data_ov012_0220afe4[];
#pragma force_active on
Ov012Actor *func_ov012_02202b10(Ov012Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220afe4;
    func_ov003_021ceedc((u8 *)self + 0x108);
    FLD(u8, self, 0xf8) = 0;
    FLD(s16, self, 0xf6) = 0;
    FLD(s32, self, 0xf0) = 0x200000;
    FLD(u8, self, 0xf9) = 0;
    FLD(s32, self, 0x100) = 0;
    FLD(s32, self, 0x104) = 0;
    FLD(u8, self, 0xfa) = 0;
    FLD(u8, self, 0xfb) = 0;
    FLD(u8, self, 0xfc) = 0;
    FLD(u8, self, 0xfd) = 0;
    FLD(u16, self, 0x124) = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern u8 data_ov012_0220afe4[];
void *func_ov012_02202b74(void *self) {
    FLD(void *, self, 0) = data_ov012_0220afe4;
    Ov012_FreeFx(self, 0x100);
    func_ov003_021cef0c((u8 *)self + 0x108);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
extern u8 data_ov012_0220afe4[];
void *func_ov012_02202bec(void *self) {
    FLD(void *, self, 0) = data_ov012_0220afe4;
    Ov012_FreeFx(self, 0x100);
    func_ov003_021cef0c((u8 *)self + 0x108);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void func_ov012_02202c6c(Ov012Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    func_02049678(data_02097e4c, 4, 4, -1);
}
}

extern "C" {
BOOL func_ov012_02202ca4(Ov012Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (r && !func_0204985c(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
s32 func_ov012_02202cd4(Ov012Actor *self, Ov012Msg *msg) {
    s32 r = 0;
    if (msg->type == 6) {
        FLD(u8, self, 0xf8) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov003_021d1c00(self, msg);
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a59a[];
extern const u8 data_ov012_0220a63c[];
extern const u8 data_ov012_0220a6c8[];
extern const u8 data_ov012_0220a708[];
void func_ov012_02202a78(Ov012Actor *self, Ov012Actor *other);
void func_ov012_02202d1c(Ov012Actor *self) {
    Ov012Sub48 *m;
    u8 v;
    func_ov003_021d112c(self);
    FLD(s32 *, self, 0x100) = Ov012_NewFx();
    Ov012_ClearOwnerFlag(self);
    m = self->unk_48;
    FLD(s32, m, 0x5c) = 0;
    FLD(s32, m, 0x60) = 0x1800;
    FLD(s32, m, 0x64) = 0;
    v = FLD(u8, data_ov000_021ccd54, 0xca);
    FLD(u8, self, 0xf4) = v;
    if (v == 3) {
        self->unk_50[1] = 700;
        self->unk_50[0] = 700;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a59a);
        FLD(s16, self, 0x124) = 0x1800;
    }
    func_ov003_021cf1f0((u8 *)self + 0x108, 0, 4, data_ov012_0220a63c);
    func_ov003_021cf1f0((u8 *)self + 0x108, 1, 8, data_ov012_0220a6c8);
    func_ov003_021cf1f0((u8 *)self + 0x108, 2, 8, data_ov012_0220a708);
    FLD(void *, self, 0x11c) = self;
    FLD(void *, self, 0x118) = (void *)func_ov012_02202a78;
}
}
