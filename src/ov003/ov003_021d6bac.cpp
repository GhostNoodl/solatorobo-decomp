#include "types.h"
#include "ov003/Actor.h"

typedef struct Ov003StSub {
    u16 atk;
    u16 unk_0a;
    u32 unk_0c;
    Ov003StSub() {}
} Ov003StSub;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 hp;
    u16 unk_06;
    Ov003StSub sub;
} Ov003Stat;

typedef struct {
    s16 hp;
    s16 atk;
    s16 mdl;
    s16 gauge;
} Ov003StScale;

static inline void Ov003_ScaleU16(u16 *v, s16 f) {
    if (f != 0 && f != 0x1000) {
        *v = ((s64)*v * f + 0x800) >> 12;
    }
}

extern "C" void Ov003Actor_ScaleStats(Ov003Actor *self, const void *scale) {
    const Ov003StScale *sc = (const Ov003StScale *)scale;
    Ov003Stat *p = (Ov003Stat *)self->targetObj;
    ActorHp *g;
    Model0218fe1c *m;
    if (p != NULL) {
        u8 b0 = p->unk_00;
        u8 b1 = p->unk_01;
        u8 b2 = p->unk_02;
        u8 b3 = p->unk_03;
        u16 hp = p->hp;
        u16 h6 = p->unk_06;
        Ov003Stat s;
        s.sub = p->sub;
        if (sc->hp != 0 && sc->hp != 0x1000) {
            hp = ((s64)hp * sc->hp + 0x800) >> 12;
        }
        Ov003_ScaleU16(&s.sub.atk, sc->atk);
        p->unk_00 = b0;
        p->unk_01 = b1;
        p->unk_02 = b2;
        p->unk_03 = b3;
        p->hp = hp;
        p->unk_06 = h6;
        p->sub = s.sub;
    }
    g = self->hpObj;
    if (g != NULL && sc->gauge != 0 && sc->gauge != 0x1000) {
        u16 v = ((s64)g->max * sc->gauge + 0x800) >> 12;
        g->cur = v;
        self->hpObj->max = v;
    }
    m = self->model;
    if (m != NULL && sc->mdl != 0 && sc->mdl != 0x1000) {
        m->unk_ce = sc->mdl;
    }
}
