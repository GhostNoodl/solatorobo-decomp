#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Vec.h"
#include "nitro/fx.h"

extern "C" {

s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);
const MtxFx43 *NNS_G3dGlbGetInvV(void);
VObj *func_02065f88(s32 kind, VecFx32 *pos);

VObj *func_ov000_0219b71c(VecFx32 *base, VecFx32 *range, s32 min, s32 max, s32 kind, u8 chance) {
    VecFx32 v;
    s32 scale;
    BOOL big;
    VObj *obj;
    s32 z = range->z;
    s32 y = Rand_PlusMinus(range->y);
    v.x = Rand_PlusMinus(range->x);
    v.y = y;
    v.z = z;
    MTX_MultVec33(&v, (const MtxFx33 *)NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, base, &v);
    scale = min + Rand_UpTo(max - min);
    big = FALSE;
    if (kind == -1 || chance == 0) {
        big = TRUE;
    }
    if (chance < 100 && chance < Rand_UpTo(100)) {
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

// func_ov000_0219b808 (round swB): q is read-only, so it is `const` (the ITCM test func_01ffc318 reads
// min/max/rot only). With the const parameter the unk_30 load is no longer ordered behind the m.rot
// stores, and the plain field order gives the ROM's list (rounds raA-raH needed it between x and y).
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

Robo021ca458 *func_ov000_0219bf90(void);
ActorGroup *ActorMgr_GetGroup(ActorMgr *mgr, u16 kind);
BOOL func_01ffc318(VecFx32 *pos, void *a, const VecFx32 *min, const VecFx32 *max, const Rot0219b808 *rot);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline Rgb0219b808 *PlCol0219b808(Robo021ca458 *pl) {
    return &LFLD(Rgb0219b808, pl, 0x772);
}

static inline BOOL SameCol0219b808(const Rgb0219b808 *a, const Rgb0219b808 *b) {
    BOOL r = FALSE;
    if (a->r == b->r && a->g == b->g && a->b == b->b) {
        r = TRUE;
    }
    return r;
}

u16 func_ov000_0219b808(u16 id, void *a1, const Shape0219b808 *q, u16 *out, u32 max) {
    Robo021ca458 *pl;
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
        if (pl != NULL && !(pl->unk_b24 << 30 >> 31 ? TRUE : FALSE) &&
            SameCol0219b808(&LFLD(Rgb0219b808, data_ov000_021ccd54, 0xca), PlCol0219b808(pl)) &&
            q->flags == (q->flags & pl->unk_710)) {
            p1.x = pl->unk_75c.x;
            p1.y = pl->unk_75c.y;
            p1.z = pl->unk_75c.z;
            if (func_01ffc318(&p1, a1, &q->min, &q->max, &q->rot)) {
                VEC_Add(&p1, &q->ofs, &p1);
                pl->unk_75c = p1;
                pl->unk_b24 |= 0x1000000;
                if (out != NULL && max != 0) {
                    out[n] = pl->id;
                }
                n++;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (!(q->mask & (1 << i))) {
            continue;
        }
        grp = ActorMgr_GetGroup(data_ov000_021ccd68, i << 12);
        if (grp == NULL || grp->count == 0 || (a = grp->head) == NULL) {
            continue;
        }
        do {
            if (id != a->id && (sub = (u8 *)a->hit) != NULL &&
                q->flags == (q->flags & LFLD(u32, sub, 0x50))) {
                p2.x = a->pos.x;
                p2.y = a->pos.y;
                p2.z = a->pos.z;
                if (func_01ffc318(&p2, a1, &q->min, &q->max, &q->rot) && a->vfunc_14()) {
                    m.pos.x = a->pos.x;
                    m.pos.y = a->pos.y;
                    m.pos.z = a->pos.z;
                    VEC_Add(&m.pos, &q->ofs, &m.pos);
                    m.rot.x = LFLD(Rot0219b808, a, 0x7c).x;
                    m.rot.y = LFLD(Rot0219b808, a, 0x7c).y;
                    m.rot.z = LFLD(Rot0219b808, a, 0x7c).z;
                    m.unk_14 = q->unk_30;
                    Actor_SendMsg(a, id, 7, TRUE, sizeof(Msg0219b808), &m);
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
