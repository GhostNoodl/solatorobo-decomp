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
ActorEx *ActorEx_DtorBase(ActorEx *self);
void ActorEx_Init(ActorEx *self);
BOOL ActorEx_IsReady(ActorEx *self);
void ActorEx_Start(ActorEx *self);
BOOL ActorEx_Draw(ActorEx *self);
void ActorEx_StateHeld(ActorEx *self);
void ActorEx_StateThrown(ActorEx *self);
void ActorEx_State0a(ActorEx *self);
void Obj02197d80_LoadValue(ActorEx *self);
void func_ov000_02197dec(ActorEx *self, u8 value, s16 sfx);
void ActorEx_StateFly(ActorEx *self);
void ActorEx_Update(ActorEx *self);
BOOL ActorEx_HandleMsg(ActorEx *self, ActorMsg *msg);
void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
void Actor_MoveToPos(Actor *self, const VecFx32 *target, s32 turn);
void Actor_TurnToPos(Actor *self, const VecFx32 *target, s32 step);
void Actor_Move(Actor *self, s32 rate);
Actor *Actor_GetTarget(Actor *self);
void func_ov000_02197ad0(Actor *self, BOOL b);
void ActorEx_StateDie(Actor *self);
void func_ov000_02197ee0(Actor *self, Ov003AiState *st, s32 near, s32 arg, s32 radius);
void ActorEx_StateIdle(VObj *obj);
BOOL Actor_Draw(Actor *self);
BOOL Hit_ApplyInArea(Actor *a, Actor *b, u16 c, u8 d, u16 mask, const VecFx32 *ofs, Rot16 *rot, s32 r, s32 rr, s16 h, s32 i);
}
#endif

#endif
