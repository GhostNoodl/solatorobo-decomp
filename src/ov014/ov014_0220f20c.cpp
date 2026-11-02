#include "ov014/ov014.h"

struct Ov014Bits93 {
    u8 b0 : 1;
    u8 b1 : 3;
    u8 b4 : 1;
    u8 b5 : 2;
    u8 b7 : 1;
};

static inline u8 Ov014_Kind13(Ov003Actor *a) {
    if (a->fsm != NULL) {
        return a->fsm->current;
    }
    return 0;
}

extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);
extern Ov003Actor *Target_Get(void *p);
extern BOOL func_ov000_0219a8bc(void *p, Actor *a, Actor *b, s32 c, s32 d, const VecFx32 *pos, s32 e, s32 f, s32 g);
struct Ov014Mtx33 {
    s32 m[9];
};
extern s32 func_ov014_0220f3f0(const VecFx32 *a, const VecFx32 *b, const u16 *rot, const s32 *ext);

void func_ov014_0220f20c(Actor *self, s32 a, s32 b, s32 c) {
    Ov003Actor *pl = func_ov000_0219bf90();
    VecFx32 v;
    s32 rad;
    if (pl == NULL) {
        return;
    }
    if (Ov014_Kind13(pl) == 0x13 || Ov014_Kind13(pl) == 0x12 || Ov014_Kind13(pl) == 0x14) {
        return;
    }
    if (pl->hp[5] != 0) {
        return;
    }
    if (!Ov014_GameIdle()) {
        return;
    }
    v.x = pl->pos.x;
    v.y = pl->pos.y;
    v.z = pl->pos.z;
    rad = pl->radius;
    if (rad <= func_ov014_0220f3f0(&v, (const VecFx32 *)a, (const u16 *)b, (const s32 *)c)) {
        return;
    }
    {
        void *p44;
        ActorSub4c *s;
        s = self->targetObj;
        p44 = pl->unk_44;
        if (!func_ov000_0219a8bc(p44, self, Target_Get(s), s->unk_08, (u8)s->unk_0a, &v, -1, rad, 0x1000)) {
            return;
        }
    }
    if (FLD(Ov014Bits93, pl, 0x93).b5) {
        func_02065f88(0x327, &v)->SetScaleAll(pl->radius * 2);
    } else {
        EffectObj *e = func_02065f88(0x325, &v);
        e->SetScaleAll(0x1400);
        e->unk_50 = -0x64000;
        EffectObj_AddSndCue(e, 0x19, 4);
    }
}


static inline s32 Ov014_Dot(const VecFx32 *a, const VecFx32 *b, const VecFx32 *n) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    return (s32)(((s64)dx * n->x + (s64)dy * n->y + (s64)dz * n->z + 0x800) >> 12);
}
static inline s32 Ov014_AxisDist(const VecFx32 *ax, const VecFx32 *a, const VecFx32 *b, s32 e) {
    VecFx32 n;
    s32 d;
    VEC_Normalize(ax, &n);
    d = FX_Div(Ov014_Dot(a, b, &n), e / 2);
    if (d < 0) {
        d = -d;
    }
    return d;
}
s32 func_ov014_0220f3f0(const VecFx32 *a, const VecFx32 *b, const u16 *rot, const s32 *ext) {
    VecFx32 acc;
    Ov014Mtx33 m;
    VecFx32 ax;
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
    MTX_Identity33_((MtxFx33 *)&m);
    if (ry != 0) {
        MTX_RotY33_((MtxFx33 *)&m, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
        set = TRUE;
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX33_((MtxFx33 *)&t, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
        } else {
            MTX_RotX33_((MtxFx33 *)&m, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            set = TRUE;
        }
    }
    if (rz != 0) {
        if (set) {
            MTX_RotZ33_((MtxFx33 *)&t, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
            MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
        } else {
            MTX_RotZ33_((MtxFx33 *)&m, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
        }
    }
    ax.x = 0x1000;
    ax.y = 0;
    ax.z = 0;
    MTX_MultVec33(&ax, (MtxFx33 *)&m, &ax);
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
    MTX_MultVec33(&ax, (MtxFx33 *)&m, &ax);
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
    MTX_MultVec33(&ax, (MtxFx33 *)&m, &ax);
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
