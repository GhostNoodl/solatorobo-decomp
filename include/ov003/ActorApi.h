#ifndef OV003_ACTORAPI_H
#define OV003_ACTORAPI_H

// The ov000 actor functions the ov003 actors call, declared once and typed (round acF), in place of
// the per-file `void *self` prototypes. The parameter types are those of the ov000 definitions and of
// the same declarations in ov010.h, ov013.h and ov014.h.

#include "ov000/ObjLayouts.h"
#include "ov003/ActEx.h"

#ifdef __cplusplus
extern "C" {
ActorEx *ActorEx_Ctor(ActorEx *self);
ActorEx *func_ov000_0219429c(ActorEx *self);
void func_ov000_0219433c(ActorEx *self);
BOOL func_ov000_021946f8(ActorEx *self);
void func_ov000_02194758(ActorEx *self);
BOOL func_ov000_02194c08(ActorEx *self);
void func_ov000_02195d88(ActorEx *self);
void func_ov000_02196060(ActorEx *self);
void func_ov000_02196860(ActorEx *self);
void func_ov000_02197d80(ActorEx *self);
void func_ov000_02197dec(ActorEx *self, u8 value, s16 sfx);
void func_ov000_02196c40(ActorEx *self);
void func_ov000_021953b4(ActorEx *self);
BOOL func_ov000_021950e8(ActorEx *self, ActorMsg *msg);
void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
void Actor_MoveToPos(Actor *self, const VecFx32 *target, s32 turn);
void Actor_Move(Actor *self, s32 rate);
Actor *Actor_GetTarget(Actor *self);
void func_ov000_02197ad0(Actor *self, BOOL b);
void func_ov000_0219763c(Actor *self);
void func_ov000_02197ee0(Actor *self, Ov003AiState *st, s32 near, s32 arg, s32 radius);
void func_ov000_02195848(VObj *obj);
BOOL func_ov000_0218cea4(Actor *self);
}
#endif

#endif
