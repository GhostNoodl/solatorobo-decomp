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
struct Ov014Mtx33 {
    s32 m[9];
};
extern s32 func_ov014_0220f3f0(const Ov014Vec *a, const Ov014Vec *b, const u16 *rot, const s32 *ext);
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
    if (rad <= func_ov014_0220f3f0(&v, (const Ov014Vec *)a, (const u16 *)b, (const s32 *)c)) {
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

extern void MTX_Identity33_(Ov014Mtx33 *m);
extern void MTX_RotX33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(const Ov014Mtx33 *a, const Ov014Mtx33 *b, Ov014Mtx33 *out);
extern void MTX_MultVec33(const Ov014Vec *v, const Ov014Mtx33 *m, Ov014Vec *out);
extern void VEC_Normalize(const Ov014Vec *a, Ov014Vec *b);
extern s32 FX_Div(s32 a, s32 b);
extern s32 VEC_Mag(const Ov014Vec *v);
extern const s16 FX_SinCosTable_[];

static inline s32 Ov014_Dot(const Ov014Vec *a, const Ov014Vec *b, const Ov014Vec *n) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    return (s32)(((s64)dx * n->x + (s64)dy * n->y + (s64)dz * n->z + 0x800) >> 12);
}
static inline s32 Ov014_AxisDist(const Ov014Vec *ax, const Ov014Vec *a, const Ov014Vec *b, s32 e) {
    Ov014Vec n;
    s32 d;
    VEC_Normalize(ax, &n);
    d = FX_Div(Ov014_Dot(a, b, &n), e / 2);
    if (d < 0) {
        d = -d;
    }
    return d;
}
s32 func_ov014_0220f3f0(const Ov014Vec *a, const Ov014Vec *b, const u16 *rot, const s32 *ext) {
    Ov014Vec acc;
    Ov014Mtx33 m;
    Ov014Vec ax;
    Ov014Mtx33 t;
    BOOL set;
    u16 rz, ry, rx;
    if (ext[0] <= 0 || ext[1] <= 0 || ext[2] <= 0) {
        return -1;
    }
    set = FALSE;
    acc.x = 0;
    acc.y = 0;
    acc.z = 0;
    ry = rot[1];
    rz = rot[2];
    rx = rot[0];
    MTX_Identity33_(&m);
    if (ry != 0) {
        MTX_RotY33_(&m, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
        set = TRUE;
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX33_(&t, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            MTX_Concat33(&t, &m, &m);
        } else {
            MTX_RotX33_(&m, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            set = TRUE;
        }
    }
    if (rz != 0) {
        if (set) {
            MTX_RotZ33_(&t, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
            MTX_Concat33(&t, &m, &m);
        } else {
            MTX_RotZ33_(&m, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
        }
    }
    ax.x = 0x1000;
    ax.y = 0;
    ax.z = 0;
    MTX_MultVec33(&ax, &m, &ax);
    {
        s32 e = ext[0];
        s32 d = e != 0 ? Ov014_AxisDist(&ax, a, b, e) : 0;
        if (d > 0x1000) {
            VEC_MultAdd((s32)(((s64)(0x1000 - d) * (ext[0] / 2) + 0x800) >> 12), &ax, &acc, &acc);
        }
    }
    ax.x = 0;
    ax.y = 0x1000;
    ax.z = 0;
    MTX_MultVec33(&ax, &m, &ax);
    {
        s32 e = ext[1];
        s32 d = e != 0 ? Ov014_AxisDist(&ax, a, b, e) : 0;
        if (d > 0x1000) {
            VEC_MultAdd((s32)(((s64)(0x1000 - d) * (ext[1] / 2) + 0x800) >> 12), &ax, &acc, &acc);
        }
    }
    ax.x = 0;
    ax.y = 0;
    ax.z = 0x1000;
    MTX_MultVec33(&ax, &m, &ax);
    {
        s32 e = ext[2];
        s32 d = e != 0 ? Ov014_AxisDist(&ax, a, b, e) : 0;
        if (d > 0x1000) {
            VEC_MultAdd((s32)(((s64)(0x1000 - d) * (ext[2] / 2) + 0x800) >> 12), &ax, &acc, &acc);
        }
    }
    return VEC_Mag(&acc);
}

}
