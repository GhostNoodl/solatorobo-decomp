#ifndef OV006_RACER_H
#define OV006_RACER_H

// The ov006 race actor (round acC): the racer class (vtable data_ov006_021ec4f4, ctor
// Ov006ActVt_021ec4f4_Ctor, 0x228 bytes, allocated by func_ov006_021ea430) and the marker it
// keeps above itself (vtable data_ov006_021ec28c, ctor Ov006Vt_021ec28c_Ctor, 0x34 bytes).

#include "types.h"
#include "ov000/ActorBase.h"
#include "Main/Math/Rot16.h"
#include "nitro/fx.h"
#include "ov006/SlotManager.h"

struct Model;

// The marker drawn over a racer (Ov006Racer::marker): follows target, smoothly when smooth is set
// (func_ov006_021dc9c8), and is drawn at cur + ofs (func_ov006_021dca94).
typedef struct Ov006Marker {
    void *vtbl;
    u8 active : 1; // set once the model is loaded
    u8 smooth : 1;
    u8 alt : 1;
    u8 unk_04_3 : 5;
    u8 frame; // 0..4 (func_ov006_021dcc9c)
    u8 unk_06[2];
    VecFx32 target; // func_ov006_021dccc8 fills it from a world position
    VecFx32 cur;
    VecFx32 ofs;
    struct Model *model; // loaded by func_ov006_021dc8f8
    struct Model *unk_30;
} Ov006Marker;
SIZE_ASSERT(Ov006Marker, 0x34);

extern "C" {
Ov006Marker *Ov006Vt_021ec28c_Ctor(Ov006Marker *self);
void func_ov006_021dc8f8(Ov006Marker *self); // loads the model
void func_ov006_021dc9c8(Ov006Marker *self); // moves cur toward target
void func_ov006_021dca94(Ov006Marker *self); // draws it
void func_ov006_021dcc9c(Ov006Marker *self, int frame, u8 alt);
void func_ov006_021dccc8(Ov006Marker *self, const VecFx32 *pos, const MtxFx43 *cam, const MtxFx44 *proj, u8 snap);
}

// A racer's parameter record (Ov006Racer::prm, the 0xa-byte table entry func_020706a0 returns).
typedef struct Ov006RacerPrm {
    s16 unk_00; // scales the model's anim speed (func_ov006_021e81e0)
    s16 unk_02; // engine sound (func_02049afc)
    s8 unk_04; // acceleration
    s8 unk_05; // top speed
    s8 unk_06; // steering
    s8 unk_07; // boost
    s8 unk_08; // collision slowdown kind
    s8 unk_09;
} Ov006RacerPrm;
SIZE_ASSERT(Ov006RacerPrm, 0xa);

// A course point (Ov006Racer::pts, ::goal).
typedef struct Ov006RacerPt {
    VecFx32 pos;
    u16 rotY;
    u16 unk_0e;
} Ov006RacerPt;

class Ov006Racer : public Actor {
public:
    Ov006RacerPrm *prm;
    Model0218fe1c mdl;
    Ov006Marker *marker;
    union {
        u16 unk_19c;
        struct {
            u16 unk_19c_0 : 2; // bit 0: on screen (cleared and set by the draw)
            u16 turnMode : 4;
            u16 boosting : 1;
            u16 unk_19c_7 : 1; // inside the goal box
            u16 swap : 1; // up and down swapped
            u16 toggle : 1; // flipped by key 4
            u16 phase : 3; // colour cycle step
            u16 unk_19c_13 : 1; // marker shown
            u16 unk_19c_14 : 1;
            u16 unk_19c_15 : 1;
        };
    };
    u8 idx; // slot index (func_ov006_021db060)
    u8 unk_19f; // goal crossings; over once past the race's count
    s32 runSpeed;
    u16 held;
    u16 trig;
    u16 release;
    u8 unk_1aa; // the slot's 3-bit kind (func_ov006_021e6eb0)
    u8 unk_1ab;
    u8 unk_1ac;
    u8 rank; // 0 = first; the last place gets the catch-up bonuses
    Rot16 look;
    u16 lookVX;
    u16 lookVY;
    u16 unk_1b8;
    Rot16 look2;
    VecFx32 unk_1c0;
    u32 unk_1cc; // frames since the start
    // effect ids (EffectObj::id)
    u32 unk_1d0;
    u32 unk_1d4;
    u32 unk_1d8;
    u32 unk_1dc;
    u32 unk_1e0;
    u32 unk_1e4;
    u32 unk_1e8;
    u32 unk_1ec;
    u32 unk_1f0;
    u8 unk_1f4;
    u8 unk_1f5;
    u16 boost;
    u16 unk_1f8;
    u16 unk_1fa;
    u16 unk_1fc;
    s16 seq; // engine sound handle (func_02049afc); -1 for none
    Ov006RacerPt *pts;
    Ov006RacerPt *goal;
    u8 ptCount;
    u8 lastPt;
    u8 nextPt;
    u8 laps;
    Rot16 courseRot; // direction from pts[lastPt] to pts[nextPt]
    Rot16 aim; // pitch (x) and yaw (y) toward pts[nextPt]
    u8 unk_218[6];
    u8 unk_21e[8]; // counters, each capped at 99
    u8 unk_226;
    u8 unk_227;
};
SIZE_ASSERT(Ov006Racer, 0x228);

extern "C" {
BOOL func_ov006_021ea3e8(Ov006Racer *self); // the racer is over (Ov006Racer_IsOver)
void func_ov006_021ea410(Ov006Racer *self); // ends the racer's race
}

// The racer has crossed the goal more often than the race counts.
static inline BOOL Ov006Racer_IsOver(Ov006Racer *self) {
    BOOL result = FALSE;
    if (self->unk_19f > data_ov006_021ec884->info->unkB) {
        result = TRUE;
    }
    return result;
}

#endif
