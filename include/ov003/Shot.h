#ifndef OV003_SHOT_H
#define OV003_SHOT_H

// The ov003 shot and beam actors: two ActorEx classes that the ov000 factory builds directly
// (Factory_New4000 types 12 and 13), each driven by a def record from an ov003 table indexed
// by Actor::unk_18, or by the record a spawner put in Actor::shotDef / Actor::beamDef.

#include "types.h"
#include "ov000/ObjLayouts.h"

// One effect of a shot: effect id (-1: none), offset from the shot (<< 4) and scale (<< 4).
struct Ov003ShotFx {
    s16 id;
    s16 x;
    s16 y;
    s16 z;
    s16 scale;
};

// One step of a shot's speed program (Ov003Shot::steps): after dur frames go to step next.
struct Ov003ShotStep {
    u16 dur; // 0: stay
    s16 speed;
    s16 accel; // eases the speed toward this step's speed (fx32 fraction per frame)
    s16 homing; // steers the velocity toward the target (fx32 fraction per frame)
    s16 next; // < 0: stay
};

// A shot's def record (data_ov003_021f4a34[], 0x3c bytes).
struct Ov003ShotDef {
    Ov003ShotFx fly; // effect that moves with the shot (its handle is ActorEx::unk_bc)
    Ov003ShotFx spawn; // one-off effect where the shot starts
    Ov003ShotFx trail; // effect dropped every trailInterval frames
    u16 trailInterval;
    s16 life; // frames before the shot ends by itself (< 0: ends without exploding)
    s16 sound; // started with the shot (< 0: none)
    u8 hitShakeA; // Field_ShakeCamera arguments on a hit (both non-zero)
    u8 hitShakeB;
    s16 hitRadius; // hit volume once the shot explodes (<< 4; < 0: keep / double)
    s16 hitHeight;
    u16 mode : 3; // 1: straight along rot.y, 2: at the target, else along rot
    u16 slowOnLock : 1; // slows down while the player locks on to it
    u16 stopFly : 1; // the fly effect is killed when the shot explodes
    u16 noAim : 1; // not re-aimed when the player fired it
    u16 billboard : 1; // the model is drawn facing the camera (Model0218fe1c::invV)
    u16 flags : 3; // 1: pierces, 2: without a target it stops at anything (0xe0000000), 4: unk_cc_2
    u16 viewSpace : 1; // moves in view space (Ov003Shot::viewPos)
    u16 unk_2a_11 : 5;
    u16 hitMask; // groups it can hit (0: all), minus its own
    u8 unk_2e[2];
    u32 sphereFlags; // its hit sphere's ActorSub48::unk_30
    u32 stopFlags; // it ends when its hit sphere's ActorSub48::unk_50 has one of these
    Ov003ShotStep *steps; // NULL: data_ov003_021f49c4
};

// The ov003 shot (vtable Ov003ActVt_021f7de4_vtbl, 0xf4 bytes): a projectile that flies by its def
// record, drops trail effects and hits what it touches (start Ov003Shot_Start, update
// Ov003Shot_StateThrown, hit test Ov003Shot_CheckHits, explosion Ov003Shot_StateDie).
class Ov003Shot : public ActorEx {
public:
    Ov003ShotDef *def;
    Ov003ShotStep *steps;
    s16 age; // frames flown (compared with def->life)
    u16 trailTimer;
    u16 lockTimer; // frames the player has locked on to it
    u16 stepTimer;
    s16 step; // index into steps
    u8 unk_e2[2];
    s32 curSpeed;
    VecFx32 viewPos; // position in view space (def->viewSpace)
};
SIZE_ASSERT(Ov003Shot, 0xf4);

// The homing shot (vtable Ov003ActVt_021f9a80_vtbl, def data_ov003_021f6c04, update
// Ov003ActVt_021f9a80_StateThrown): flies after the actor Actor::target, and like Ov003Shot when the player
// fired it.
class Ov003HomingShot : public Ov003Shot {
};
SIZE_ASSERT(Ov003HomingShot, 0xf4);

// One of the two effect layers of a beam: an Effect3D model of the def's archive, or an effect id;
// its scale grows by inc up to max, and shrinks by dec when the beam ends (all << 4).
struct Ov003BeamLayer {
    const char *mdl; // model name in the def's archive
    s16 fx;
    u8 alpha;
    u8 unk_07;
    s16 maxX; // also the y scale
    s16 maxZ;
    s16 incX;
    s16 incZ;
    s16 decX;
    s16 decZ;
};

// A beam's def record (data_ov003_021f49ec[], 0x48 bytes).
struct Ov003BeamDef {
    const char *arc; // effect archive of the layers and the hit effect (NULL: effect ids)
    u16 duration; // frames before it shrinks away
    u8 unk_06[2];
    VecFx32 offset; // from the beam's position (Actor::unk_84)
    s16 sound;
    u8 unk_16[2];
    Ov003BeamLayer layers[2];
    const char *hitFx; // effect group shown on the player when it hits
    s32 hitFxSize;
};

// The ov003 beam (vtable Ov003ActVt_021f7d4c_vtbl, 0xfc bytes): two growing effect layers along rot
// and a hit test along them (start Ov003ActVt_021f7d4c_Start, update Ov003Beam_StateThrown, layers
// Ov003Beam_UpdateLayer, hit test Ov003Beam_Fire).
class Ov003Beam : public ActorEx {
public:
    Ov003BeamDef *def;
    u32 layers[2]; // effect ids (EffectObj::id)
    VecFx32 scales[2]; // current scale of each layer
    u8 unk_f4[8];
};
SIZE_ASSERT(Ov003Beam, 0xfc);

extern "C" {
void Ov003Shot_Start(Ov003Shot *self);
void Ov003Shot_StateThrown(Ov003Shot *self);
BOOL Ov003Shot_CheckHits(Ov003Shot *self);
void Ov003Shot_ResetTimers(Ov003Shot *self);
void Ov003Beam_UpdateLayer(Ov003Beam *self, s32 layer, s32 mode);
BOOL Ov003Beam_Fire(Ov003Beam *self);
}

#endif
