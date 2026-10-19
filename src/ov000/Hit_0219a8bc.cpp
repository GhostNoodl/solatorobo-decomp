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
}
