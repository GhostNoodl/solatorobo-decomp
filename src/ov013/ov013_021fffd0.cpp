#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

extern "C" {

extern const Ov013Spot data_ov013_0220b900[];
extern const Ov013Spot data_ov013_0220b958[];
extern void func_ov013_021fe948(Ov013Vec *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude);
extern BOOL func_ov013_02203ea4(Ov013Actor *self, Ov013Vec *pos);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov013Actor *func_ov000_0219bf90(void);
extern void func_0203f324(Ov013Sub48 *p);

static inline u32 Ov013_Nearest(const Ov013Vec *p, const Ov013Spot *tbl, u32 n) {
    u32 best = 0;
    u32 i;
    for (i = 0; i < n; i++) {
        if (VEC_Distance(p, &tbl[best].pos) > VEC_Distance(p, &tbl[i].pos)) {
            best = i;
        }
    }
    return best;
}

void func_ov013_021fffd0(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        Ov013Vec p;
        u32 best;
        Ov013Sub48 *m;
        Ov013Actor *pl = func_ov000_0219bf90();
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        switch (FLD(u8, self, 0x15d)) {
        case 1:
            best = Ov013_Nearest(&p, data_ov013_0220b900, 3);
            FLD(Ov013Vec, self, 0x114) = data_ov013_0220b900[best].pos;
            FLD(u16, self, 0xfc) = data_ov013_0220b900[best].rot;
            break;
        case 3:
            best = Ov013_Nearest(&p, data_ov013_0220b958, 4);
            FLD(Ov013Vec, self, 0x114) = data_ov013_0220b958[best].pos;
            FLD(u16, self, 0xfc) = data_ov013_0220b958[best].rot;
            break;
        case 2:
            func_ov013_021fe948(&FLD(Ov013Vec, self, 0x114), &FLD(u16, self, 0xfc), data_ov013_0220b900, 3, (u8 *)self + 0x108);
            break;
        case 4:
            func_ov013_021fe948(&FLD(Ov013Vec, self, 0x114), &FLD(u16, self, 0xfc), data_ov013_0220b958, 4, (u8 *)self + 0x108);
            break;
        }
    }
    if (func_ov013_02203ea4(self, &FLD(Ov013Vec, self, 0x114))) {
        FLD(Ov013Vec, self, 0x108) = FLD(Ov013Vec, self, 0x114);
        FLD(u16, self, 0xfa) = FLD(u16, self, 0xfc);
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
    }
}

extern void func_ov013_02202dc8(Ov013Actor *self, u16 a, s32 b, BOOL c, u16 d);

void func_ov013_022001b8(Ov013Actor *self) {
    BOOL m;
    if (FLD(u8, self, 0x15d) != 1) {
        m = FALSE;
        if ((u32)self & 3) {
            m = FALSE;
        }
    } else {
        m = TRUE;
    }
    func_ov013_02202dc8(self, 0xa00, 0x1000, m, 0);
}

}
