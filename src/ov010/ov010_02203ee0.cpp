#include "ov010/ov010.h"

class Ov010Fx {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    s32 timer;
    s32 scale;
};

extern "C" {

extern u8 data_ov010_0220fe30[];
extern Ov010Fx *func_02065f88(s32 a, void *b);
extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(void *p, s32 a);
void func_ov010_02203f08(Ov010Fx *fx);

extern void *data_0214a420;
extern u8 data_ov010_0220fe50[];
extern void *data_ov000_021ccd68;
extern Ov010V *func_020657b0(void *a, s32 b);
extern void func_02065860(void *a, s32 b);
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);

struct Ov010Glow {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 rest : 4;
    u8 pad_01;
    u16 id;
    s16 cur;
    s16 tgt;
    s16 scale;
    u16 pad_0a;
    s32 keyA;
    s32 keyB;
    Ov010Vec off;
};

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

void func_ov010_02203bf8(Ov010Glow *self) {
    u8 *actor;
    Ov010V *o;
    u16 ry;
    u16 rx;
    Ov010Vec base;
    if (!self->b0) {
        return;
    }
    {
        u16 id = self->id;
        actor = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    if (actor == NULL) {
        self->id = 0xffff;
        func_02065860(data_0214a420, self->keyA);
        func_02065860(data_0214a420, self->keyB);
        self->keyA = 0;
        self->keyB = 0;
        return;
    }
    if (self->b1 && self->keyA == 0) {
        self->keyA = FLD(s32, func_02065f88(0x324, data_ov010_0220fe50), 0x24);
    }
    if (self->b2 && self->keyB == 0) {
        Ov010Fx *fx = func_02065f88(self->b3 ? 0x25e : 0x25d, data_ov010_0220fe50);
        fx->v14(self->scale, self->scale, self->scale);
        self->keyB = FLD(s32, fx, 0x24);
    }
    if (self->b1 && self->tgt != self->cur) {
        s32 d = self->tgt - self->cur;
        if ((d < 0 ? -d : d) <= 0x19a) {
            self->cur = self->tgt;
        } else if (self->tgt > self->cur) {
            self->cur += 0x19a;
        } else {
            self->cur -= 0x19a;
        }
    }
    if (self->cur < 0) {
        self->cur = 0;
    }
    base = FLD(Ov010Vec, actor, 0x70);
    ry = FLD(u16, actor, 0x7c);
    rx = FLD(u16, actor, 0x7e);
    if (self->keyA != 0) {
        o = func_020657b0(data_0214a420, self->keyA);
        if (o == NULL) {
            self->keyA = 0;
            self->b1 = 0;
        } else {
            Ov010Vec v;
            func_ov003_021d9900(&v, ry, &self->off);
            func_ov003_021d9980(&v, rx, &v);
            VEC_Add(&v, &base, &v);
            o->v18(&v);
            o->v14(self->cur, self->cur, self->cur);
        }
    }
    if (self->keyB == 0) {
        return;
    }
    o = func_020657b0(data_0214a420, self->keyB);
    if (o == NULL) {
        self->keyB = 0;
        self->b2 = 0;
        return;
    }
    {
        Ov010Vec v;
        func_ov003_021d9900(&v, ry, &self->off);
        func_ov003_021d9980(&v, rx, &v);
        VEC_Add(&v, &base, &v);
        o->v18(&v);
        o->v34((u16)(ry + 0x7fff), rx, 0);
    }
}

Ov010Fx *func_ov010_02203ee0(s32 a, void *b) {
    Ov010Fx *fx = func_02065f88(a, b);
    if (fx != NULL) {
        fx->timer = 0;
        fx->scale = 0;
    }
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02203f08;
    return fx;
}

}
