#ifndef OV003_FXLIST_H
#define OV003_FXLIST_H

// A list of effect handles by id (ov003 021da788, 021dacfc).

#include "types.h"
#include "ov003/Vec.h"
#include "Main/Effect/Effect.h"

struct Ov003FxNode {
    u8 id;
    u32 handle; // EffectObj::id
    Ov003FxNode *next;
};

struct Ov003FxList {
    Ov003FxNode *head;
};

extern "C" {
Ov003FxList *func_ov003_021da940(Ov003FxList *self);
void func_ov003_021da9ac(Ov003FxList *self, u8 id, EffectObj *obj);
BOOL Ov003FxList_Has(Ov003FxList *self, u8 id);
u32 Ov003FxList_Get(Ov003FxList *self, u8 id);
void Ov003FxList_Kill(Ov003FxList *self, u8 id);
void Ov003FxList_KillAll(Ov003FxList *self);
// Moves the effects with this id to pos (+ ofs turned by angles[0] about x and angles[1] about y,
// less their own base position), and sets their rotation and scale when given.
void func_ov003_021daae4(Ov003FxList *self, u8 id, const VecFx32 *pos, const EffectRot *rot, const VecFx32 *scale,
                         const VecFx32 *ofs, const u16 *angles);
}

#endif
