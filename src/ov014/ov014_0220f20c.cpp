#include "ov014/ov014.h"

struct Ov014Bits93 {
    u8 b0 : 1;
    u8 b1 : 3;
    u8 b4 : 1;
    u8 b5 : 2;
    u8 b7 : 1;
};

static inline u8 Ov014_Kind13(Ov014Actor *a) {
    if (a->unk_40 != NULL) {
        return a->unk_40->unk_13;
    }
    return 0;
}

extern "C" {

extern Ov014Actor *func_ov000_0219bf90(void);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern BOOL func_ov000_0219a8bc(void *p, Ov014Actor *a, Ov014Actor *b, s32 c, s32 d, const Ov014Vec *pos, s32 e, s32 f, s32 g);
extern s32 func_ov014_0220f3f0(Ov014Vec *v, s32 a, s32 b, s32 c);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_020639d4(void *e, s32 a, s32 b);

void func_ov014_0220f20c(Ov014Actor *self, s32 a, s32 b, s32 c) {
    Ov014Actor *pl = func_ov000_0219bf90();
    Ov014Vec v;
    s32 rad;
    if (pl == NULL) {
        return;
    }
    if (Ov014_Kind13(pl) == 0x13 || Ov014_Kind13(pl) == 0x12 || Ov014_Kind13(pl) == 0x14) {
        return;
    }
    if (pl->unk_50[5] != 0) {
        return;
    }
    if (!Ov014_GameIdle()) {
        return;
    }
    v.x = pl->pos.x;
    v.y = pl->pos.y;
    v.z = pl->pos.z;
    rad = pl->unk_64;
    if (rad <= func_ov014_0220f3f0(&v, a, b, c)) {
        return;
    }
    {
        void *p44;
        u8 *s;
        s = FLD(u8 *, self, 0x4c);
        p44 = pl->unk_44;
        if (!func_ov000_0219a8bc(p44, self, func_ov000_02199ba0(s), FLD(u16, s, 8), (u8)FLD(u16, s, 0xa), &v, -1, rad, 0x1000)) {
            return;
        }
    }
    if (FLD(Ov014Bits93, pl, 0x93).b5) {
        func_02065f88(0x327, &v)->v0c(pl->unk_64 * 2);
    } else {
        Ov014Actor *e = func_02065f88(0x325, &v);
        e->v0c(0x1400);
        FLD(s32, e, 0x50) = -0x64000;
        func_020639d4(e, 0x19, 4);
    }
}

}
