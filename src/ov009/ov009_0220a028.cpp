#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0219864c(Ov009Sub48 *p, s32 a, s32 b);

void func_ov009_0220a028(Ov009Actor *self) {
    Ov009Actor *a;
    Ov009Sub44 *s44;
    func_ov003_021d112c(self);
    self->unk_ea_6 = 1;
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    FLD(u16, self, 0xf4) = self->rot[1];
    FLD(Ov009Vec, self, 0xf8) = self->pos;
    self->unk_b8 = self->pos;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    FLD(u16, self, 0xf2) = 0;
    FLD(u16, self, 0xf0) = 0;
    if (self->unk_1a == 1) {
        self->unk_b6 = func_02040498(0x3c) + 0x3c;
    }
    if (self->unk_48 != NULL) {
        self->unk_48->unk_48 = self->unk_64 << 1;
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
    func_ov000_02198360(self->unk_40, 0x20, 0);
    self->unk_38->unk_c2_0 = 0;
    FLD(u8, self, 0x93) |= 0x80;
}

struct Ov009RotS {
    u16 x;
    u16 y;
    u16 z;
};

extern void *data_02097e4c;
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern BOOL func_01ffc624(const Ov009Vec *a, const Ov009Vec *b, Ov009RotS *r, s32 c, s32 d);
extern void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);

static inline void Ov009_CountDown(Ov009Actor *self) {
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 == 0) {
        FLD(u16, self, 0xb4)++;
    }
}

static inline BOOL Ov009_Skip(u8 st, u32 f) {
    BOOL flag = FALSE;
    if (st != 0x15 && st != 9 && (f & 0x20000000)) {
        if (!(f & 0x400)) {
            flag = TRUE;
        }
        if (st == 0x13) {
            flag = TRUE;
        }
        if (st == 4) {
            flag = TRUE;
        }
    }
    return flag;
}

void func_ov009_0220a128(Ov009Actor *self, u8 st) {
    Ov009Vec v;
    Ov009RotS r;
    Ov009Sub40 *s;
    s32 z;
    s32 y;
    if (!Ov009_GameIdle() || (st = (s = self->unk_40)->unk_13) == 0x20) {
        return;
    }
    u32 f = self->unk_48->unk_50;
    BOOL flag = Ov009_Skip(st, f);
    if (flag) {
        s->flags |= 0x200000;
        func_02049a48(data_02097e4c, 0x6c, -1, -1, -1);
        return;
    }
    Ov009Actor *pl = func_ov000_0218d240(self);
    if (pl == NULL) {
        return;
    }
    {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    v = self->unk_b8;
    switch (self->unk_1a) {
    case 0:
        switch (FLD(u16, self, 0xb4)) {
        case 0:
            Ov009_CountDown(self);
            break;
        case 1:
            if ((f & 0x40000000) || func_01ffc198(&self->pos, &v, self->unk_64 + 0xc00)) {
                {
                    s32 z = func_02040528(0x800) + 0x2400;
                    v.x = 0;
                    v.y = 0;
                    v.z = z;
                }
                func_01ffc9fc(&v, &v, (u16)(FLD(u16, self, 0xf4) - 0x4000));
                VEC_Add(&v, &FLD(Ov009Vec, self, 0xf8), &v);
                self->unk_b8 = v;
                self->unk_b6 = func_02040498(0x1e) + 0x14;
                FLD(u16, self, 0xb4) = 10;
            } else {
                self->unk_40->flags |= 4;
            }
            break;
        case 10:
            Ov009_CountDown(self);
            break;
        case 11:
            if ((f & 0x40000000) || func_01ffc198(&self->pos, &v, self->unk_64 + 0xc00)) {
                {
                    s32 z = func_02040528(0x800) + 0x2400;
                    v.x = 0;
                    v.y = 0;
                    v.z = z;
                }
                func_01ffc9fc(&v, &v, (u16)(FLD(u16, self, 0xf4) + 0x4000));
                VEC_Add(&v, &FLD(Ov009Vec, self, 0xf8), &v);
                self->unk_b8 = v;
                self->unk_b6 = func_02040498(0x1e) + 0x14;
                FLD(u16, self, 0xb4) = 0;
            } else {
                self->unk_40->flags |= 4;
            }
            break;
        }
        if ((u8)(st + 0xff) > 1) {
            return;
        }
        {
            u16 ry = FLD(u16, self, 0xf4);
            r.x = 0x4000;
            r.y = ry;
            r.z = 0;
        }
        if (!func_01ffc624(&pl->pos, &self->pos, &r, pl->unk_64 + 0x1800, 0x6000)) {
            return;
        }
        self->unk_40->flags |= 0x8000;
        break;
    case 1:
        if (st != 1) {
            return;
        }
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        {
            s32 t = self->pos.z;
            z = t;
            y = self->pos.y;
            s32 px = pl->pos.x;
            v.x = px + func_02040528(0x3000);
            v.y = y;
            v.z = z;
            if (v.x < -0xa000) {
                v.x = -0xa000;
            }
            if (v.x > 0xa800) {
                v.x = 0xa800;
            }
            self->pos = v;
        }
        self->unk_b6 = func_02040498(0x1e) + 0x3c;
        func_ov000_02198360(self->unk_40, 0x20, 0);
        break;
    }
}


}
