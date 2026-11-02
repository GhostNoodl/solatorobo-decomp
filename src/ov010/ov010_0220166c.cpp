#include "ov010/ov010.h"
#include "ov000/ObjLayouts.h"

struct Ov010PlFlags {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 18;
};

extern "C" {

extern BOOL func_ov000_02198360(ActorSub40 *a, u8 b, BOOL c);
extern void Ov010Beam_Draw(Ov010Beam *o);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);

static inline void Ov010Fx_Free(Ov010FxObj *s) {
    if (s->b0) {
        s->b0 = 0;
        EffectMgr_Kill(data_0214a420, s->fx0);
        EffectMgr_Kill(data_0214a420, s->fx1);
        EffectMgr_Kill(data_0214a420, s->fx2);
        s->fx0 = 0;
        s->fx1 = 0;
        s->fx2 = 0;
    }
}

static inline void Ov010Beam_Reset(Ov010Beam *b) {
    if (b->on != 0) {
        Ov010Fx_Free(&b->fx);
        b->on = 0;
    }
}

void Ov010BeamSet_Draw(Ov010BeamSet *o) {
    Ov010BeamNode *n;
    if (!o->flags.b0) {
        return;
    }
    for (n = o->beams; n != NULL; n = n->next) {
        Ov010Beam_Draw(&n->beam);
    }
}

void Ov010BeamSet_Start(Ov010BeamSet *o, const VecFx32 *a, const VecFx32 *b, u16 c) {
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

void Ov010BeamSet_Stop(Ov010BeamSet *o) {
    if (o->flags.b0 && o->st.st != 0x64 && o->st.st != 0x65) {
        o->st.timer = 0;
        o->st.st = 0x64;
    }
}

void Ov010BeamSet_StopAll(Ov010BeamSet *o) {
    Ov010BeamNode *n;
    if (!o->flags.b0) {
        return;
    }
    Ov003ActorSub40_ForceState(&o->st, 0);
    o->st.st = 0x65;
    for (n = o->beams; n != NULL; n = n->next) {
        if (n->beam.on != 0) {
            Ov003ActorSub40_ForceState(&n->beam.st, 0);
            func_ov000_02198360(&n->beam.st, 5, 0);
            if (n->beam.fx.b0) {
                EffectMgr_Kill(data_0214a420, n->beam.fx.fx0);
                EffectMgr_Kill(data_0214a420, n->beam.fx.fx1);
                EffectMgr_Kill(data_0214a420, n->beam.fx.fx2);
                n->beam.fx.fx0 = 0;
                n->beam.fx.fx1 = 0;
                n->beam.fx.fx2 = 0;
                Ov003ActorSub40_ForceState(&n->beam.fx.st, 0);
                func_ov000_02198360(&n->beam.fx.st, 0, 1);
            }
        }
    }
}

BOOL Ov010BeamSet_IsDone(Ov010BeamSet *o) {
    BOOL r = TRUE;
    if (o->flags.b0 && o->st.st != 0x65) {
        r = FALSE;
    }
    return r;
}

void Ov010BeamSet_SetOrigin(Ov010BeamSet *o, const VecFx32 *v) {
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

void Ov010BeamSet_SetTarget(Ov010BeamSet *o, const VecFx32 *v) {
    if (!o->flags.b0) {
        return;
    }
    o->unk_14 = *v;
}

BOOL Ov010_IsPlayerNear(u16 id, const VecFx32 *a, const VecFx32 *b) {
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
