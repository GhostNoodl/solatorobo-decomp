#include "ov000/Actor.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 val;
    u8 d;
    u8 pad;
    u16 id;
} Hit0219a8bc;

extern "C" {
Actor *func_ov000_021985c0(void *hit);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);

static inline BOOL IsLocked(ActorHp *s) {
    return s->unk_0a != 0 ? TRUE : FALSE;
}

BOOL func_ov000_0219a8bc(void *hit, Actor *a, Actor *b, s32 c, u8 d, VecFx32 *pos, s16 h, s32 i, s32 scale) {
    BOOL ret = FALSE;
    Actor *t;
    ActorHp *s50;
    t = func_ov000_021985c0(hit);
    if (t != NULL && t != b && t->vfunc_14()) {
        s50 = t->hpObj;
        if (s50 == NULL || !IsLocked(s50)) {
            if (b->hp != NULL && b->hpObj->unk_10 != NULL) {
                c = b->hpObj->unk_10(c);
            }
            if (s50 != NULL && s50->unk_18 != NULL) {
                c = s50->unk_18(c);
            }
            {
                Hit0219a8bc msg;
                msg.val = c;
                msg.d = d;
                if (a != NULL) {
                    msg.id = a->id;
                } else {
                    msg.id = 0xffff;
                }
                Actor_SendMsg(t, b->id, 9, 0, 6, &msg);
            }
            if (h != -1) {
                if (t->unk_93_5 != 0) {
                    h = 0x327;
                    i = t->radius << 1;
                }
                ActorSub4c *s4c = t->targetObj;
                if (s50 != NULL || s4c == NULL || *(u8 *)s4c == 0xb) {
                    VecFx32 p;
                    EffectObj *e;
                    u16 ang;
                    p = *(VecFx32 *)hit;
                    if (scale != 0x1000) {
                        VecFx32 dv;
                        VEC_Subtract(&p, pos, &dv);
                        VEC_MultAdd(scale, &dv, pos, &p);
                    }
                    e = func_02065f88(h, &p);
                    if (i != 0x1000) {
                        e->SetScaleXYZ(i, i, i);
                    }
                    if (t == NULL || t == b) {
                        ang = b->rot_y;
                    } else {
                        ang = FX_Atan2(t->pos.x - b->pos.x, t->pos.z - b->pos.z);
                    }
                    e->SetRotXYZ(0, ang, 0);
                }
            }
            ret = TRUE;
        }
    }
    return ret;
}

s32 func_ov000_0219a5c8(Actor *self, u16 mask, const VecFx32 *pos, void *rot, s32 r, s32 a, void **list);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline s32 FxMul0219aae8(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

BOOL func_ov000_0219aae8(Actor *a, Actor *b, u16 c, u8 d, u16 mask, VecFx32 *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i) {
    BOOL ret = FALSE;
    VecFx32 pos;
    void *list[32];
    s32 n;
    s32 k;
    u16 ang;
    if (a == NULL || b == NULL) {
        return FALSE;
    }
    pos = a->pos;
    ang = a->rot_y;
    if (ofs != NULL) {
        s32 idx = ang >> 4;
        s32 sn = FX_SinCosTable_[idx * 2];
        s32 cs = FX_SinCosTable_[idx * 2 + 1];
        s32 x = 0;
        s32 z = 0;
        VecFx32 dv;
        if (ofs->x != 0) {
            x += FxMul0219aae8(cs, ofs->x);
            z += FxMul0219aae8(-sn, ofs->x);
        }
        if (ofs->z != 0) {
            x += FxMul0219aae8(sn, ofs->z);
            z += FxMul0219aae8(cs, ofs->z);
        }
        {
            s32 y = ofs->y;
            dv.x = x;
            dv.y = y;
            dv.z = z;
        }
        VEC_Add(&pos, &dv, &pos);
    }
    n = func_ov000_0219a5c8(a, mask, &pos, rot, r, rr, list);
    for (k = 0; k < n; k++) {
        if (list[k] != NULL) {
            if (func_ov000_0219a8bc(list[k], a, b, c, d, &pos, h, i, 0x1000)) {
                ret = TRUE;
            }
        }
    }
    return ret;
}

void *Actor_GetTarget(Actor *a);
ActorSub44 *func_ov000_0218d2e0(Actor *a);
BOOL Hit_DiffInCylinder(void *hit, VecFx32 *pos, s32 r, s32 h);
BOOL func_01ffc624(void *hit, VecFx32 *pos, u16 *box, s32 r, s32 h);

static inline BOOL IsSolid0219aca8(ActorSub44 *hit) {
    BOOL ret = FALSE;
    if (hit->unk_22_0 == 1 && hit->unk_22_1 == 1) {
        ret = TRUE;
    }
    return ret;
}

BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, VecFx32 *ofs, u16 *box, s32 r, s32 hgt, s16 h, s32 i) {
    VecFx32 pos;
    ActorSub44 *hit;
    BOOL ok;
    u16 ang;
    if (a == NULL || b == NULL) {
        return FALSE;
    }
    if (Actor_GetTarget(b) == NULL) {
        return FALSE;
    }
    hit = func_ov000_0218d2e0(b);
    if (hit == NULL) {
        return FALSE;
    }
    pos = a->pos;
    ang = a->rot_y;
    if (ofs != NULL) {
        s32 idx = ang >> 4;
        s32 sn = FX_SinCosTable_[idx * 2];
        s32 cs = FX_SinCosTable_[idx * 2 + 1];
        s32 x = 0;
        s32 z = 0;
        VecFx32 dv;
        if (ofs->x != 0) {
            x += FxMul0219aae8(cs, ofs->x);
            z += FxMul0219aae8(-sn, ofs->x);
        }
        if (ofs->z != 0) {
            x += FxMul0219aae8(sn, ofs->z);
            z += FxMul0219aae8(cs, ofs->z);
        }
        {
            s32 y = ofs->y;
            dv.x = x;
            dv.y = y;
            dv.z = z;
        }
        VEC_Add(&pos, &dv, &pos);
    }
    if (hgt == 0) {
        if (!IsSolid0219aca8(hit)) {
            ok = FALSE;
        } else {
            ok = Hit_DiffInSphere(&hit->pos, &pos, r + hit->unk_1c);
        }
    } else if (box == NULL || (box[0] == 0 && box[1] == 0 && box[2] == 0)) {
        if (!IsSolid0219aca8(hit)) {
            ok = FALSE;
        } else {
            ok = Hit_DiffInCylinder(hit, &pos, r + hit->unk_1c, hgt);
        }
    } else {
        if (!IsSolid0219aca8(hit)) {
            ok = FALSE;
        } else {
            ok = func_01ffc624(hit, &pos, box, r + hit->unk_1c, hgt);
        }
    }
    if (!ok) {
        return ok;
    }
    return func_ov000_0219a8bc(hit, a, b, c, d, &pos, h, i, 0x1000);
}
}
