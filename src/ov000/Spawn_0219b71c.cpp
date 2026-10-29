#include "ov000/VObj.h"
#include "ov000/Vec.h"

extern "C" {

s32 func_02040528(s32 max);
s32 func_02040498(s32 max);
void *NNS_G3dGlbGetInvV(void);
void MTX_MultVec33(const VecFx32 *v, const void *m, VecFx32 *out);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
VObj *func_02065f88(s32 kind, VecFx32 *pos);

VObj *func_ov000_0219b71c(VecFx32 *base, VecFx32 *range, s32 min, s32 max, s32 kind, u8 chance) {
    VecFx32 v;
    s32 scale;
    BOOL big;
    VObj *obj;
    s32 z = range->z;
    s32 y = func_02040528(range->y);
    v.x = func_02040528(range->x);
    v.y = y;
    v.z = z;
    MTX_MultVec33(&v, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, base, &v);
    scale = min + func_02040498(max - min);
    big = FALSE;
    if (kind == -1 || chance == 0) {
        big = TRUE;
    }
    if (chance < 100 && chance < func_02040498(100)) {
        big = TRUE;
    }
    if (big) {
        kind = 4;
        scale += scale >> 2;
    }
    obj = func_02065f88(kind, &v);
    obj->vfunc_14(scale, scale, scale);
    return obj;
}

}

#ifdef NONMATCHING
// func_ov000_0219b808: 0 register-masked / 4 raw diffs (round cmA; was 4 / 6). The message's rot is copied
// x, y, z in field order with the q->unk_30 read in a named local first; this gives the ROM's instruction
// order. Left: the x and y copies take r2/lr where the ROM has r1/r3 (the arguments' registers).
#include "ov000/Actor.h"
namespace m_Spawn_0219b808 {
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 r, g, b;
} Rgb0219b808;

typedef struct {
    u16 x, y, z;
} Rot0219b808;

typedef struct {
    VecFx32 min;
    VecFx32 max;
    Rot0219b808 rot;
    u16 mask;
    u32 flags;
    VecFx32 ofs;
    s32 unk_30;
} Shape0219b808;

typedef struct {
    VecFx32 pos;
    Rot0219b808 rot;
    u8 pad[2];
    s32 unk_14;
} Msg0219b808;

extern "C" {

u8 *func_ov000_0219bf90(void);
ActorGroup *func_ov000_0218e4cc(ActorMgr *mgr, u16 kind);
BOOL func_01ffc318(VecFx32 *pos, void *a, VecFx32 *min, VecFx32 *max, Rot0219b808 *rot);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline Rgb0219b808 *PlCol0219b808(u8 *pl) {
    return &LFLD(Rgb0219b808, pl, 0x772);
}

static inline BOOL SameCol0219b808(const Rgb0219b808 *a, const Rgb0219b808 *b) {
    BOOL r = FALSE;
    if (a->r == b->r && a->g == b->g && a->b == b->b) {
        r = TRUE;
    }
    return r;
}

u16 func_ov000_0219b808(u16 id, void *a1, Shape0219b808 *q, u16 *out, u32 max) {
    u8 *pl;
    u16 n = 0;
    s32 i;
    VecFx32 p1;
    VecFx32 p2;
    Msg0219b808 m;
    u8 *sub;
    ActorGroup *grp;
    Actor *a;
    if (q->mask & 2) {
        pl = func_ov000_0219bf90();
        if (pl != NULL && !(LFLD(u32, pl, 0xb24) << 30 >> 31 ? TRUE : FALSE) &&
            SameCol0219b808(&LFLD(Rgb0219b808, data_ov000_021ccd54, 0xca), PlCol0219b808(pl)) &&
            q->flags == (q->flags & LFLD(u32, pl, 0x710))) {
            p1.x = LFLD(VecFx32, pl, 0x75c).x;
            p1.y = LFLD(VecFx32, pl, 0x75c).y;
            p1.z = LFLD(VecFx32, pl, 0x75c).z;
            if (func_01ffc318(&p1, a1, &q->min, &q->max, &q->rot)) {
                VEC_Add(&p1, &q->ofs, &p1);
                LFLD(VecFx32, pl, 0x75c) = p1;
                LFLD(u32, pl, 0xb24) |= 0x1000000;
                if (out != NULL && max != 0) {
                    out[n] = LFLD(u16, pl, 0xc);
                }
                n++;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (!(q->mask & (1 << i))) {
            continue;
        }
        grp = func_ov000_0218e4cc(data_ov000_021ccd68, i << 12);
        if (grp == NULL || grp->count == 0 || (a = grp->head) == NULL) {
            continue;
        }
        do {
            if (id != a->id && (sub = LFLD(u8 *, a, 0x48)) != NULL &&
                q->flags == (q->flags & LFLD(u32, sub, 0x50))) {
                p2.x = LFLD(VecFx32, a, 0x70).x;
                p2.y = LFLD(VecFx32, a, 0x70).y;
                p2.z = LFLD(VecFx32, a, 0x70).z;
                if (func_01ffc318(&p2, a1, &q->min, &q->max, &q->rot) && a->vfunc_14()) {
                    m.pos.x = LFLD(VecFx32, a, 0x70).x;
                    m.pos.y = LFLD(VecFx32, a, 0x70).y;
                    m.pos.z = LFLD(VecFx32, a, 0x70).z;
                    VEC_Add(&m.pos, &q->ofs, &m.pos);
                    {
                        s32 v = q->unk_30;
                        m.rot.x = LFLD(Rot0219b808, a, 0x7c).x;
                        m.rot.y = LFLD(Rot0219b808, a, 0x7c).y;
                        m.rot.z = LFLD(Rot0219b808, a, 0x7c).z;
                        m.unk_14 = v;
                        func_ov000_0218d398(a, id, 7, TRUE, sizeof(Msg0219b808), &m);
                    }
                    if (out != NULL && n < max) {
                        out[n] = a->id;
                    }
                    n++;
                }
            }
            a = a != NULL ? a->next : grp->head;
        } while (a != NULL);
    }
    return n;
}

}

}  // namespace m_Spawn_0219b808
#endif
