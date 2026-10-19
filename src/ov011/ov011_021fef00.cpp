#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov011Small6 {
    Ov011Bit01 f;
    u8 pad;
    u16 a;
    u16 b;
};

struct Ov011Small4 {
    Ov011Bit01 f;
    u8 pad;
    u16 a;
};

extern "C" {

extern u8 data_ov011_0220726e[];
void func_ov003_021d112c(void *self);
void func_ov000_02198328(void *p);
void func_ov011_02201510(void *p);
void func_ov011_02201c18(void *p);
void func_ov011_02202edc(void *p);
void func_ov011_02202c54(void *p);
BOOL func_ov011_021fd4d8(void *p, void *owner);
BOOL func_020621c4(void);
void func_ov003_021d6bac(void *p, void *data);

void func_ov011_021fef00(Ov011Actor *self) {
    u8 *p;
    u8 *q;
    func_ov003_021d112c(self);
    p = (u8 *)func_0203dd9c(0x23c);
    if (p != NULL) {
        FLD(Ov011Bit01, p, 0x10).b0 = 0;
        func_ov000_02198328(p + 0x20);
        func_ov011_02201510(p + 0x34);
        func_ov000_02198328(p + 0xc8);
        func_ov011_02201c18(p + 0xdc);
        func_ov011_02202edc(p + 0x194);
        FLD(Ov011Bit01, p, 0xb4).b0 = 0;
        func_ov000_02198328(p + 0x1c0);
        FLD(Ov011Bit01, p, 0x1b4).b0 = 0;
        func_ov000_02198328(p + 0x1f0);
        FLD(Ov011Bit01, p, 0x1d4).b0 = 0;
        FLD(Ov011Bit01, p, 0x204).b0 = 0;
        FLD(Ov011Bit01, p, 0).b0 = 0;
    }
    FLD(u8 *, self, 0x100) = p;
    func_ov011_021fd4d8(p, self);
    q = (u8 *)func_0203dd9c(0x3c);
    if (q != NULL) {
        func_ov000_02198328(q);
        func_ov011_02202c54(q + 0x14);
    }
    FLD(u8 *, self, 0x104) = q;
    FLD(void *, self, 0x108) = func_0203dd9c(6);
    FLD(void *, self, 0x10c) = func_0203dd9c(4);
    {
        u8 *s = FLD(u8 *, self, 0x104);
        func_ov003_021da48c(s, 0);
        FLD(s32, s, 0x38) = 0;
    }
    {
        Ov011Small6 *s = FLD(Ov011Small6 *, self, 0x108);
        s->f.b0 = 0;
        s->f.b1 = 0;
        s->a = 0x1000;
        s->b = 0x1000;
    }
    {
        Ov011Small4 *s = FLD(Ov011Small4 *, self, 0x10c);
        s->f.b0 = 0;
        s->f.b1 = 0;
        s->f.b2 = 1;
        s->a = 0;
    }
    self->unk_48->unk_30 = 0x60000000;
    self->unk_90 = FLD(u16, func_ov000_0219bf90(), 0xc);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov011_0220726e);
    }
    FLD(u8, self, 0x15) = 2;
}

extern void *data_02097e4c;
extern const char *const data_ov011_02207258[];
extern void func_0204a028(void *a, s32 b, Ov011Vec *c, s32 d);
extern void func_02049f44(void *a, s32 b, Ov011Vec *c, s32 d);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov003_021d1c00(Ov011Actor *self, u8 *msg);

BOOL func_ov011_021ff084(Ov011Actor *self, u8 *msg) {
    if (msg[5] == 0xe) {
        switch (FLD(s32, msg, 0x8)) {
        case 1: {
            Ov011Sub40 *st;
            s32 sub = FLD(s32, msg, 0xc);
            if (sub == 0) {
                st = FLD(Ov011Sub40 *, self, 0x104);
                if (st->unk_13 == 0) {
                    st->flags |= 2;
                    func_0204a028(data_02097e4c, 9, &self->pos, -2);
                }
            } else if (sub == 1) {
                st = FLD(Ov011Sub40 *, self, 0x104);
                if (st->unk_13 == 1) {
                    st->flags |= 4;
                    func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
                }
            } else if (sub == 2) {
                st = FLD(Ov011Sub40 *, self, 0x104);
                if (st->unk_13 == 2) {
                    st->flags |= 8;
                }
            }
            break;
        }
        case 2: {
            u8 *p = FLD(u8 *, self, 0x108);
            if (p != NULL) {
                FLD(u8, p, 0) = msg[0xc];
                FLD(s16, p, 2) = FLD(s16, msg, 0xe);
                FLD(s16, p, 4) = FLD(s16, msg, 0x10);
            }
            break;
        }
        case 3:
            if (msg[0xc] != 0) {
                Ov011Small4 *s = FLD(Ov011Small4 *, self, 0x10c);
                s->f.b0 = 1;
                s->f.b1 = 1;
                s->f.b2 = 1;
                s->a = 0;
            } else {
                Ov011Small4 *s = FLD(Ov011Small4 *, self, 0x10c);
                s->f.b0 = 0;
                s->f.b1 = 0;
                s->f.b2 = 0;
                s->a = 0;
                func_ov000_02190cb0(self->unk_38, data_ov011_02207258[0], 0x1000, 0);
                func_ov000_021915a0(self->unk_38);
            }
            break;
        }
        self->unk_30 |= 1 << msg[5];
        msg[5] = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

}
