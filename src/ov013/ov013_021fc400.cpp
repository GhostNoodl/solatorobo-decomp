#include "ov013/ov013.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5ca[];
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern s32 func_ov000_0218dfb4(Ov013Actor *a, u16 id);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);

s32 func_ov013_021fc400(Ov013Actor *self) {
    s32 r = 0x10;
    s32 a = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000), 0x4823);
    s32 b = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 0x5c17);
    if (b >= 2 || a >= 4 || func_ov000_021983b0(self->unk_40, r, 3, 1)) {
        s32 rnd = func_02040498(0x63);
        u16 pct = self->unk_50[0] * 100 / self->unk_50[1];
        FLD(u8, self, 0xf1) = 0;
        if (pct >= 0x4b) {
            r = 0xf;
        } else if (pct >= 0x32) {
            if (rnd % 2 == 0) {
                r = 0xf;
            } else {
                r = 0xe;
            }
        } else {
            if ((u32)rnd % pct < 0x19) {
                FLD(u8, self, 0xf1) = 2;
                FLD(u8, self, 0xf0) = 1;
            }
            r = 0xe;
        }
    }
    if (!func_ov000_021983b0(self->unk_40, 0x10, 7, 1)) {
        r = 0x10;
    }
    return r;
}

void func_ov013_021fc518(Ov013Actor *self) {
    Ov013Sub48 *m;
    s32 n;
    Ov013Actor *a;
    func_ov003_021d112c(self);
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    FLD(u8, self, 0xf0) = 0;
    FLD(s32, self, 0xf4) = -1;
    n = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 0x5c17);
    FLD(u8, self, 0xf8) = n % 2;
    if (n == 2) {
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x5000, 0x5c17);
        }
        if (a != NULL && a == self) {
            FLD(u8, self, 0xf8) = 1;
        }
    }
    func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x1000, 0);
    func_ov000_021915a0(self->unk_38);
    func_ov000_02198360(self->unk_40, 0xf, 0);
    self->unk_ea_6 = 1;
    self->unk_93_4 = 1;
    self->unk_b6 = 100;
}

void func_ov013_021fc624(Ov013Actor *self) {
    Ov013Actor *p;
    u8 k;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    k = self->unk_40->unk_13;
    if (FLD(u8, self, 0xf0) != 0 && k != 0x15 && k != 9) {
        self->unk_40->flags |= 4;
    }
    if (k != 1 || self->unk_40->state != 0x63) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    self->unk_40->flags |= 0x8000;
    self->unk_b6 = 300;
}

void func_ov013_021fc71c(Ov013Actor *self) {
    Ov013Sub40 *s = self->unk_40;
    Ov013Actor *t;
    if (s->unk_0c[0] == 4 && s->unk_0c[1] == 10 && s->unk_0c[2] == 9) {
        func_ov000_02198360(s, 0xf, 0);
        return;
    }
    if (s->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
    }
    self->rot[1] = func_01ffc128(0, self->rot[1], 0xcd, 1, 0x8000);
    t = func_ov000_0218d240(self);
    if (t != NULL) {
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
    }
}

}
