#include "ov010/ov010.h"
#include "ov000/ObjLayouts.h"

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010PlFlags {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 18;
};

extern "C" {

extern void *data_0214a420;
extern Ov010Heap *data_02097dd0;
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov010_02200a00(Ov010Beam *o);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern s32 Ov003Vec_DistSq(const Ov010Vec *a, const Ov010Vec *b);

static inline void Ov010Fx_Free(Ov010FxObj *s) {
    if (s->b0) {
        s->b0 = 0;
        func_02065804(data_0214a420, s->unk_14);
        func_02065804(data_0214a420, s->unk_18);
        func_02065804(data_0214a420, s->unk_1c);
        s->unk_14 = 0;
        s->unk_18 = 0;
        s->unk_1c = 0;
    }
}

static inline void Ov010Beam_Reset(Ov010Beam *b) {
    if (b->on != 0) {
        Ov010Fx_Free(&b->fx);
        b->on = 0;
    }
}

void func_ov010_0220166c(Ov010BeamSet *o) {
    Ov010BeamNode *n;
    if (!o->flags.b0) {
        return;
    }
    for (n = o->beams; n != NULL; n = n->next) {
        func_ov010_02200a00(&n->beam);
    }
}

void func_ov010_022016a0(Ov010BeamSet *o, const Ov010Vec *a, const Ov010Vec *b, u16 c) {
    if (!o->flags.b0) {
        return;
    }
    if (o->st.st != 0x65) {
        return;
    }
    o->st.st = 0;
    o->unk_14 = *a;
    o->unk_20 = *b;
    o->unk_08 = c;
}

void func_ov010_02201700(Ov010BeamSet *o) {
    if (o->flags.b0 && o->st.st != 0x64 && o->st.st != 0x65) {
        o->st.timer = 0;
        o->st.st = 0x64;
    }
}

void func_ov010_0220172c(Ov010BeamSet *o) {
    Ov010BeamNode *n;
    if (!o->flags.b0) {
        return;
    }
    func_ov003_021da48c(&o->st, 0);
    o->st.st = 0x65;
    for (n = o->beams; n != NULL; n = n->next) {
        if (n->beam.on != 0) {
            func_ov003_021da48c(&n->beam.st, 0);
            func_ov000_02198360(&n->beam.st, 5, 0);
            if (n->beam.fx.b0) {
                func_02065804(data_0214a420, n->beam.fx.unk_14);
                func_02065804(data_0214a420, n->beam.fx.unk_18);
                func_02065804(data_0214a420, n->beam.fx.unk_1c);
                n->beam.fx.unk_14 = 0;
                n->beam.fx.unk_18 = 0;
                n->beam.fx.unk_1c = 0;
                func_ov003_021da48c(&n->beam.fx.st, 0);
                func_ov000_02198360(&n->beam.fx.st, 0, 1);
            }
        }
    }
}

BOOL func_ov010_0220180c(Ov010BeamSet *o) {
    BOOL r = TRUE;
    if (o->flags.b0 && o->st.st != 0x65) {
        r = FALSE;
    }
    return r;
}

void func_ov010_02201830(Ov010BeamSet *o, const Ov010Vec *v) {
    Ov010BeamNode *n;
    if (!o->flags.b0) {
        return;
    }
    o->unk_20 = *v;
    for (n = o->beams; n != NULL; n = n->next) {
        if (n->beam.on != 0) {
            n->beam.pos = o->unk_20;
        }
    }
}

void func_ov010_02201898(Ov010BeamSet *o, const Ov010Vec *v) {
    if (!o->flags.b0) {
        return;
    }
    o->unk_14 = *v;
}

BOOL func_ov010_022018c4(u16 id, const Ov010Vec *a, const Ov010Vec *b) {
    BOOL r = FALSE;
    Robo021ca458 *pl = func_ov000_0219bf90();
    if (id == pl->id && pl->unk_b24_12 == 0) {
        if (Ov003Vec_DistSq(a, b) < 0x51000) {
            r = TRUE;
        }
    }
    return r;
}

}
