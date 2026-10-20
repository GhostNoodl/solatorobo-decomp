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

extern "C" {
extern void func_ov003_021ceff4(void *p);
static inline BOOL Ov012_HasFlag(Ov012Sub40 *s, u64 f) {
    return (s->flags & f) != 0;
}
void func_ov012_02202e30(Ov012Actor *self) {
    Ov012Vec v;
    u8 *pl;
    u8 kind;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = (u8 *)func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = ((Ov012Actor *)pl)->id;
    }
    kind = self->unk_40->unk_13;
    self->unk_93_4 = 1;
    if (kind == 1) {
        u32 f0 = FLD(u32, self, 0xf0);
        if (f0 == 0) {
            u8 *t = FLD(u8 *, self, 0x114);
            u16 k = FLD(u16, t, 8);
            u8 *ent = FLD(u8 *, t, 0xc);
            s16 mode;
            FLD(u8 *, self, 0x104) = ent + k * 8;
            mode = *(s16 *)(ent + k * 8);
            v = ((Ov012Actor *)pl)->pos;
            if (VEC_Distance(&self->pos, &v) <= 0x7000 && mode != 0 && mode != 4) {
                mode = 3;
            } else {
                func_ov003_021ceff4((u8 *)self + 0x108);
            }
            self->unk_40->timer = 0;
            switch (mode) {
            case 0:
                FLD(u32, self, 0xf0) |= 0x80;
                FLD(u8, self, 0xfb) = 0;
                self->unk_40->flags |= 0x400000;
                break;
            case 1:
                FLD(u32, self, 0xf0) |= 0x20;
                FLD(u8, self, 0xfb) = 0;
                self->unk_40->flags |= 0x4000;
                break;
            case 2:
                FLD(u32, self, 0xf0) |= 4;
                self->unk_40->flags |= 0x8000;
                break;
            case 3:
                FLD(u32, self, 0xf0) |= 8;
                FLD(u8, self, 0xfb) = 0;
                FLD(u8, self, 0xfc) = 0;
                self->unk_40->flags |= 0x10000;
                break;
            case 4:
                FLD(u32, self, 0xf0) |= 0x10;
                FLD(u8, self, 0xfb) = 0;
                FLD(u8, self, 0xfc) = 0;
                self->unk_40->flags |= 0x20000;
                break;
            }
        } else if (f0 & 1) {
            u8 *p = FLD(u8 *, self, 0x104);
            if (p != NULL) {
                FLD(u16, self, 0xb6)++;
                if (FLD(u16, self, 0xb6) >= FLD(u16, p, 6)) {
                    FLD(u32, self, 0xf0) = f0 ^ 1;
                    FLD(u16, self, 0xb6) = 0;
                }
            } else {
                FLD(u16, self, 0xb6)++;
                if (FLD(u16, self, 0xb6) >= 10) {
                    FLD(u32, self, 0xf0) = f0 ^ 1;
                    FLD(u16, self, 0xb6) = 0;
                }
            }
        } else if ((f0 & 0x200000) && !(f0 & 1) && self->unk_50[0] != 0) {
            f0 ^= 0x200000;
            f0 |= 0x80;
            FLD(u8 *, self, 0x104) = NULL;
            FLD(u8, self, 0xfb) = 0;
            FLD(u32, self, 0xf0) = f0;
            self->unk_40->flags |= 0x400000;
        }
    }
    if (self->unk_30 & 0x200) {
        if (self->unk_50[0] != 0) {
            BOOL f = FALSE;
            func_02049f44(data_02097e4c, 0x405, &self->pos, 0);
            if (FLD(u8, FLD(u8 *, self, 0x4c), 0x19) != 0) {
                f = TRUE;
            }
            if (kind != 0x16 && kind != 0xf && kind != 0x10 && kind != 0x11 && !f) {
                func_ov003_021daab0(FLD(void *, self, 0x100));
                FLD(u8 *, self, 0x104) = NULL;
                FLD(u8, self, 0xf8) = 0;
                if (!(FLD(u32, self, 0xf0) & 0x400000)) {
                    FLD(u32, self, 0xf0) = 1;
                    FLD(u32, self, 0xf0) |= 0x200000;
                }
            }
        } else {
            self->unk_40->flags = 0;
            self->unk_40->flags |= 0x100000;
        }
    }
    if (FLD(u8, self, 0xf4) == 3) {
        if (FLD(u32, self, 0xf0) != 0x400000) {
            u16 *hp = self->unk_50;
            s32 pct = (u16)(hp[0] * 100 / hp[1]);
            if ((self->unk_18 == 0 && pct < 0x46) || (self->unk_18 == 1 && pct < 0x32)) {
                u8 k;
                hp[5] = 10;
                k = self->unk_40->unk_13;
                if (k == 1 || k == 2 || k == 0x14) {
                    if (!Ov012_HasFlag(self->unk_40, 0x100000)) {
                        if (FLD(u16, self, 0xe8) != 0) {
                            FLD(u16, self, 0xe8) = 0;
                            FLD(u8, FLD(u8 *, self, 0x4c), 0x1a) = 0;
                            FLD(u8, FLD(u8 *, self, 0x4c), 0) = *func_02070558((void *)self->kind);
                        }
                        FLD(u32, self, 0xf0) = 0x400000;
                        self->unk_40->flags |= 2;
                    }
                }
            }
        } else {
            if (pl != NULL && FLD(u8, pl, 0xb2e) < 2) {
                FLD(u8, pl, 0xb2e) = 2;
            }
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
    }
    if (func_ov003_021daa0c(FLD(void *, self, 0x100), 0xfe) && pl != NULL && FLD(u16, pl, 0xb1e) == self->id) {
        func_ov003_021daa6c(FLD(void *, self, 0x100), 0xfe);
    }
    if (pl != NULL) {
        FLD(Ov012Vec, pl, 0xb90) = self->pos;
        FLD(s32, pl, 0xb9c) = 0x59a;
    }
    func_ov003_021dacfc(FLD(void *, self, 0x100));
}
}
