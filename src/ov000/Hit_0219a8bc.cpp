#include "ov000/Actor.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 5;
    u8 b5 : 2;
    u8 b7 : 1;
} Bits93_0219a8bc;

typedef struct {
    u16 val;
    u8 d;
    u8 pad;
    u16 id;
} Hit0219a8bc;

typedef s32 (*Fn0219a8bc)(s32 v);

extern "C" {
Actor *func_ov000_021985c0(void *hit);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
VObj *func_02065f88(s32 id, VecFx32 *pos);

static inline BOOL IsLocked(u8 *s) {
    return LFLD(u16, s, 0xa) != 0 ? TRUE : FALSE;
}

BOOL func_ov000_0219a8bc(void *hit, Actor *a, Actor *b, s32 c, u8 d, VecFx32 *pos, s16 h, s32 i, s32 scale) {
    BOOL ret = FALSE;
    Actor *t;
    u8 *s50;
    t = func_ov000_021985c0(hit);
    if (t != NULL && t != b && t->vfunc_14()) {
        s50 = LFLD(u8 *, t, 0x50);
        if (s50 == NULL || !IsLocked(s50)) {
            if (LFLD(u8 *, b, 0x50) != NULL && LFLD(Fn0219a8bc, LFLD(u8 *, b, 0x50), 0x10) != NULL) {
                c = LFLD(Fn0219a8bc, LFLD(u8 *, b, 0x50), 0x10)(c);
            }
            if (s50 != NULL && LFLD(Fn0219a8bc, s50, 0x18) != NULL) {
                c = LFLD(Fn0219a8bc, s50, 0x18)(c);
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
                func_ov000_0218d398(t, b->id, 9, 0, 6, &msg);
            }
            if (h != -1) {
                if (LFLD(Bits93_0219a8bc, t, 0x93).b5 != 0) {
                    h = 0x327;
                    i = t->unk_64 << 1;
                }
                ActorSub4c *s4c = t->unk_4c;
                if (s50 != NULL || s4c == NULL || *(u8 *)s4c == 0xb) {
                    VecFx32 p;
                    VObj *e;
                    u16 ang;
                    p = *(VecFx32 *)hit;
                    if (scale != 0x1000) {
                        VecFx32 dv;
                        VEC_Subtract(&p, pos, &dv);
                        VEC_MultAdd(scale, &dv, pos, &p);
                    }
                    e = func_02065f88(h, &p);
                    if (i != 0x1000) {
                        e->vfunc_14(i, i, i);
                    }
                    if (t == NULL || t == b) {
                        ang = b->rot_y;
                    } else {
                        ang = FX_Atan2(t->pos.x - b->pos.x, t->pos.z - b->pos.z);
                    }
                    e->vfunc_34(0, ang, 0);
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

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 14;
} Bits22_0219aca8;

void *func_ov000_0218d240(Actor *a);
u8 *func_ov000_0218d2e0(Actor *a);
BOOL func_01ffc584(void *hit, VecFx32 *pos, s32 r, s32 h);
BOOL func_01ffc624(void *hit, VecFx32 *pos, u16 *box, s32 r, s32 h);

static inline BOOL IsSolid0219aca8(u8 *hit) {
    BOOL ret = FALSE;
    if (LFLD(Bits22_0219aca8, hit, 0x22).b0 == 1 && LFLD(Bits22_0219aca8, hit, 0x22).b1 == 1) {
        ret = TRUE;
    }
    return ret;
}

BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, VecFx32 *ofs, u16 *box, s32 r, s32 hgt, s16 h, s32 i) {
    VecFx32 pos;
    u8 *hit;
    BOOL ok;
    u16 ang;
    if (a == NULL || b == NULL) {
        return FALSE;
    }
    if (func_ov000_0218d240(b) == NULL) {
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
            ok = func_01ffc198(hit, &pos, r + LFLD(s32, hit, 0x1c));
        }
    } else if (box == NULL || (box[0] == 0 && box[1] == 0 && box[2] == 0)) {
        if (!IsSolid0219aca8(hit)) {
            ok = FALSE;
        } else {
            ok = func_01ffc584(hit, &pos, r + LFLD(s32, hit, 0x1c), hgt);
        }
    } else {
        if (!IsSolid0219aca8(hit)) {
            ok = FALSE;
        } else {
            ok = func_01ffc624(hit, &pos, box, r + LFLD(s32, hit, 0x1c), hgt);
        }
    }
    if (!ok) {
        return ok;
    }
    return func_ov000_0219a8bc(hit, a, b, c, d, &pos, h, i, 0x1000);
}
}
