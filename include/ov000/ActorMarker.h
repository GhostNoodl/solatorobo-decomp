#ifndef OV000_ACTORMARKER_H
#define OV000_ACTORMARKER_H

#include "types.h"
#include "ov000/Vec.h"
#include "ov000/Model0218fe1c.h"

// The 2D marker shown over an actor (Actor::unk_5c) or the robot (Robo021ca458::unk_9b0 / unk_9b4).
// It is allocated with 0xa8 bytes and set up by ActorMarker_Init; ActorMarker_Release releases it
// before the free. ActorMarker_SetKind requests a kind; ActorMarker_Update loads the kind's models
// (func_ov000_021bd8ac), waits for them and the fade out of the old kind, then installs the kind's
// update / draw pair from the table ActorMarker_KindTable. Each kind keeps its own fields after the
// common block, from 0x8c (see the kind's source file).

struct ActorMarker;
typedef void (*ActorMarkerFn)(struct ActorMarker *self);

struct Model;
struct ActorRes;

// The per-kind state, cleared when the kind changes (0x24 bytes at 0x68).
typedef struct ActorMarkerWork {
    /* 0x00 */ s32 state; // 1: set up, 4: fading in, 5: release, 10: shown
    /* 0x04 */ VecFx32 pos; // ActorMarker_SetPos
    /* 0x10 */ s32 x; // screen position (fx32), ActorMarker_UpdateScreenPos
    /* 0x14 */ s32 y;
    /* 0x18 */ s32 z; // depth: Model::unk_150 of the 2D kinds, the draw z of kind 11
    /* 0x1c */ s32 fade; // ActorMarker_UpdateFade
    /* 0x20 */ s32 alpha; // sine of fade / len
} ActorMarkerWork;

struct ActorMarker {
    /* 0x00 */ union {
        u32 flags;
        struct {
            u32 unk_00_0 : 1;
            u32 show : 1; // cleared to fade the marker out
            u32 snap : 1; // set by ActorMarker_SetPos: the next follow jumps to the new position
            u32 change : 1; // a new kind is requested (ActorMarker_SetKind)
            u32 unk_00_4 : 28;
        };
    };
    /* 0x04 */ struct ActorRes *res; // kind 11's resources (0x138, ResSet_Init)
    /* 0x08 */ struct Model *mdl[8]; // 4..7: loaded by func_ov000_021bd8ac, handed to the kind
    /* 0x28 */ s32 unk_28[6];
    /* 0x40 */ s32 step; // kind change: 7 load, 8 wait models, 9 wait fade out, 10 done
    /* 0x44 */ s32 kind;
    /* 0x48 */ s32 nextKind; // -1: none
    /* 0x4c */ s32 rate; // follow rate (0x1000: by distance)
    /* 0x50 */ VecFx32 unk_50;
    /* 0x5c */ s32 height; // added to the y of the followed position
    /* 0x60 */ ActorMarkerFn update;
    /* 0x64 */ ActorMarkerFn draw;
    /* 0x68 */ ActorMarkerWork work;
};

// The kinds that show up to three 2D models, taken over from mdl[4..6] when the kind is set up.
struct ActorMarker2D : ActorMarker {
    /* 0x8c */ struct Model *unk_8c;
    /* 0x90 */ struct Model *unk_90;
    /* 0x94 */ struct Model *unk_94;
};

// Kind 11 (ActorMarker_UpdateKind0b, drawn by ActorMarker_DrawKind0b): a 3D model built from the marker's
// own resources.
struct ActorMarker3D : ActorMarker {
    /* 0x8c */ struct ActorRes *unk_8c; // ActorMarker::res, taken over
    /* 0x90 */ Model0218fe1c *unk_90;
};

#ifdef __cplusplus
extern "C" {
#endif

void ActorMarker_Init(ActorMarker *self);
void ActorMarker_Release(ActorMarker *self);
void func_ov000_021bd300(ActorMarker *self);
BOOL ActorMarker_SetKind(ActorMarker *self, s32 kind);
BOOL ActorMarker_UpdateFade(ActorMarker *self, s32 len);
void ActorMarker_SetPos(ActorMarker *self, VecFx32 *pos, s32 dy);
void ActorMarker_UpdateScreenPos(ActorMarker *self, VecFx32 *pos);
void ActorMarker_Update(ActorMarker *self);
void ActorMarker_Draw(ActorMarker *self);
void ActorMarker_FreeRes(ActorMarker *self);
BOOL func_ov000_021bd8ac(ActorMarker *self);

#ifdef __cplusplus
}
#endif

// Releases and frees a marker field (ov000/HeapScope.h's HEAP_DELETE).
#define HEAP_DELETE_MARKER(field) HEAP_DELETE(ActorMarker *, field, ActorMarker_Release(p); Heap_Free(p))

#endif
