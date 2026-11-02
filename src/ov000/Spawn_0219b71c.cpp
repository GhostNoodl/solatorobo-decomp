#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Vec.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"

extern "C" {

s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);
const MtxFx43 *NNS_G3dGlbGetInvV(void);

EffectObj *Spawn_ScatterEffect(VecFx32 *base, VecFx32 *range, s32 min, s32 max, s32 kind, u8 chance) {
    VecFx32 v;
    s32 scale;
    BOOL big;
    EffectObj *obj;
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
    obj = Effect_SpawnId(kind, &v);
    obj->SetScaleXYZ(scale, scale, scale);
    return obj;
}

}

// func_ov000_0219b808 (round swB): q is read-only, so it is `const` (the ITCM test func_01ffc318 reads
// min/max/rot only). With the const parameter the unk_30 load is no longer ordered behind the m.rot
// stores, and the plain field order gives the ROM's list (rounds raA-raH needed it between x and y).
#include "ov000/Actor.h"
namespace m_Spawn_0219b808 {
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

extern "C" {

Robo021ca458 *ActorMgr_FindPlayer(void);
ActorGroup *ActorMgr_GetGroup(ActorMgr *mgr, u16 kind);
BOOL func_01ffc318(VecFx32 *pos, void *a, const VecFx32 *min, const VecFx32 *max, const Rot0219b808 *rot);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline FieldId *PlId0219b808(Robo021ca458 *pl) {
    return &pl->fieldId;
}

static inline BOOL SameId0219b808(const FieldId *a, const FieldId *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
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
    MsgData7 m;
    ActorSub48 *sub;
    ActorGroup *grp;
    Actor *a;
    if (q->mask & 2) {
        pl = ActorMgr_FindPlayer();
        if (pl != NULL && !(pl->unk_b24 << 30 >> 31 ? TRUE : FALSE) &&
            SameId0219b808(&data_ov000_021ccd54->unk_ca, PlId0219b808(pl)) &&
            q->flags == (q->flags & pl->hit1.unk_50)) {
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
            if (id != a->id && (sub = a->hit) != NULL &&
                q->flags == (q->flags & sub->unk_50)) {
                p2.x = a->pos.x;
                p2.y = a->pos.y;
                p2.z = a->pos.z;
                if (func_01ffc318(&p2, a1, &q->min, &q->max, &q->rot) && a->vfunc_14()) {
                    m.pos.x = a->pos.x;
                    m.pos.y = a->pos.y;
                    m.pos.z = a->pos.z;
                    VEC_Add(&m.pos, &q->ofs, &m.pos);
                    m.rot_x = a->rot_x;
                    m.rot_y = a->rot_y;
                    m.rot_z = a->rot_z;
                    m.unk_1c = q->unk_30;
                    Actor_SendMsg(a, id, 7, TRUE, sizeof(MsgData7), &m);
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
