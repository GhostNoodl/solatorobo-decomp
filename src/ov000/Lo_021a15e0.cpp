#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

typedef struct {
    u8 b0, b1, b2, b3;
    u16 h4, h6, h8, ha;
    s32 wc;
} S0219bebc;
static inline void SetS(S0219bebc *p, S0219bebc v) {
    *p = v;
}

extern "C" {
void func_ov000_0215eab4(void *p);
void MTX_FrustumW(s32 t, s32 b, s32 l, s32 r, s32 n, s32 f, s32 scaleW, void *mtx);
Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id);

typedef struct {
    u32 b0 : 5;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 11;
    u32 b21 : 1;
    u32 b22 : 3;
    u32 b25 : 1;
    u32 b26 : 6;
} Bits021a15e0;

static inline Actor *FindA(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

void func_ov000_021a15e0(Actor *self) {
    ActorSub40 *s = (ActorSub40 *)self->unk_40;
    Actor *a;
    ActorSub4c *p;
    if (s != NULL) {
        s->flags |= 2;
    }
    LFLD(Bits021a15e0, self, 0xb24).b25 = 1;
    LFLD(Bits021a15e0, self, 0xb24).b21 = 0;
    if (LFLD(Bits021a15e0, self, 0xb24).b5 == 0) {
        return;
    }
    a = FindA(LFLD(u16, self, 0xb1c));
    p = NULL;
    if (a != NULL) {
        p = a->unk_4c;
    }
    if (p != NULL && p->unk_1c == self->id) {
        return;
    }
    if (p != NULL) {
        p->unk_1c = 0xffff;
    }
    LFLD(u16, self, 0xb1c) = 0xffff;
    LFLD(u16, self, 0xb1e) = 0xffff;
    LFLD(Bits021a15e0, self, 0xb24).b5 = 0;
    LFLD(Bits021a15e0, self, 0xb24).b7 = LFLD(Bits021a15e0, self, 0xb24).b9;
}

}
