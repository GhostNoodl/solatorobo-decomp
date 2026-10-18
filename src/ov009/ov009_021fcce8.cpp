#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd30;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov000_0216912c(void *p, u16 id, s32 a, u16 b, u16 c, const Ov009Vec *pos);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_021fcce8(Ov009Actor *self) {
    u8 *p;
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    if (self->kind != 0x5038 && self->kind != 0x5044) {
        return;
    }
    func_ov000_02187a20(data_ov000_021ccd54, 0xd);
    self->unk_18 = 1;
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b5 = 1;
    }
    if (self->kind != 0x5044) {
        return;
    }
    self->pos.y += 0x1000;
    if (FLD(u8, data_ov000_021ccd54, 0xca) == 0x11) {
        self->pos.y += 0x1000;
    }
}

void func_ov009_021fcda8(Ov009Actor *self) {
    Ov009Sub48 *s48;
    func_ov003_021d112c(self);
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    FLD(Ov009Vec, self, 0xfc) = self->pos;
    if (FLD(u8, data_ov000_021ccd54, 0xca) != 0x11) {
        s48 = self->unk_48;
        s48->unk_9a_1 = 0;
        s48->unk_9a_4 = 0;
    }
    s48 = self->unk_48;
    s48->unk_9a_2 = 0;
    s48->unk_9a_5 = 0;
    if (self->kind != 0x5012) {
        self->unk_44->unk_1c += 0x800;
        self->unk_44->unk_10 = -0x1000;
        self->unk_48->unk_60 = -0x1000;
    }
    self->unk_ea_6 = 1;
    if (self->unk_1a != 0) {
        self->unk_40->flags |= 0x100000000ULL;
    }
}

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0219bf90(void);
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern Ov009Actor *func_ov003_021d69a0(Ov009Actor *self, s32 id, s32 a);
extern void func_01ffc9fc(Ov009Vec *dst, Ov009Vec *src, u16 angle);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

void func_ov009_021fce9c(Ov009Actor *self) {
    Ov009Actor *pl;
    s32 dist;
    s32 dy;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    self->unk_93_4 = 0;
    if (*self->unk_50 == 0) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    self->unk_90 = pl->id;
    dy = pl->pos.y - self->pos.y;
    self->unk_cc = 0x7800;
    dist = 0x7fffffff;
    if (dy <= self->unk_cc && dy >= -self->unk_cc) {
        dist = Ov009_DistXZ(&self->pos, &pl->pos);
    }
    if (dist > 0x28000) {
        self->unk_93_4 = 0;
        FLD(u16, self, 0xb4) = 0;
        self->unk_b6 = 0;
        return;
    }
    self->unk_93_4 = 1;
    if (pl->unk_50[5] != 0) {
        return;
    }
    switch (FLD(u16, self, 0xb4)) {
    case 0: {
        s32 time;
        u32 max;
        s32 id;
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0 || self->unk_40->unk_13 != 1) {
            return;
        }
        time = 0x3c;
        max = 3;
        if (self->kind == 0x5012) {
            max = 2;
            if (FLD(u16, pl, 0xb1e) != 0xffff) {
                time = 0x1a4;
            } else {
                time = 0x12c;
                if (FLD(u8, data_ov000_021ccd54, 0xca) != 2) {
                    time = 0x5a;
                }
            }
        }
        {
            Ov009Actor *o = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
            if (o != NULL && FLD(u16, o, 0x16) < max) {
                Ov009Vec ofs;
                Ov009Actor *e;
                ofs.x = 0;
                ofs.y = 0;
                ofs.z = 0;
                switch (self->kind) {
                case 0x5012:
                    ofs.x = 0;
                    ofs.y = 0;
                    ofs.z = -0x3000;
                    id = 0x5013;
                    time = 0x1f4;
                    break;
                case 0x5038:
                    id = 0x5045;
                    time = 0x3c;
                    break;
                case 0x5044:
                    id = 0x5045;
                    time = 0x190;
                    break;
                }
                e = func_ov003_021d69a0(self, id, 0x20);
                if (e != NULL) {
                    func_01ffc9fc(&ofs, &ofs, self->rot[1]);
                    VEC_Add(&ofs, &self->pos, &ofs);
                    e->pos = ofs;
                    e->unk_1a = 1;
                }
            }
        }
        self->unk_b6 = time;
        FLD(u16, self, 0xb4)++;
        break;
    }
    case 1:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0 && self->unk_40->unk_13 == 1) {
            self->unk_40->flags |= 0x4000;
            self->unk_b6 = 0x78;
            FLD(u16, self, 0xb4) = 0;
            return;
        }
        if (self->kind == 0x5012) {
            return;
        }
        if (self->unk_b6 >= 0x28) {
            return;
        }
        func_ov000_0218d988(self, pl, self->unk_b0->unk_02);
        break;
    }
}

}
