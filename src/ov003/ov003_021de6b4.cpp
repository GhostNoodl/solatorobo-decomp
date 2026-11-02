#include "ov003/ActEx.h"
#include "nitro/fx.h"
extern "C" {
#include "types.h"

VObj *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *sc, s32 a, s32 b, s32 c, s32 d);
u32 Rand_UpTo(u32 max);

typedef enum { OV003_SPARK_KIND = 0x325 } Ov003SparkKind;

/* Bomb fuse tick: every 128 frames spawn a spark and give it a random spin.
   The spark kind is an enum-typed local: the optimizer does not constant-propagate
   enum variables, so it stays a named value and is coloured after the scale vector
   constants (docs/MATCHING.md, round lfA). */
void Ov003ActVt_021f8480_StateIdle(Ov003Bomb *self) {
    VecFx32 sc;
    VObj *e;
    ActorSub40 *w;
    Ov003SparkKind kind;
    if (self->kind != 0x4032) {
        return;
    }
    w = self->fsm;
    w->timer++;
    if ((w->timer & 0x7f) != 0) {
        return;
    }
    kind = OV003_SPARK_KIND;
    sc.x = 0x5000;
    sc.y = 0x3000;
    sc.z = 0x3800;
    e = func_ov000_0219b71c(&self->pos, &sc, 0x1800, 0x2000, kind, 100);
    if (e == NULL) {
        return;
    }
    e->vfunc_34((u16)(0xb800 - Rand_UpTo(0x400)), 0, 0);
}

}
