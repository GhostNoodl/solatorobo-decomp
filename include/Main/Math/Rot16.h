#ifndef MAIN_MATH_ROT16_H
#define MAIN_MATH_ROT16_H

#include "types.h"

// Three binary angles (0x10000 = one turn), the rotation effects and actors keep
// (EffectObj::rot, Actor::rot). EffectRot and ActorRot are this type.
typedef struct Rot16 {
    u16 x;
    u16 y;
    u16 z;
} Rot16;

#endif
