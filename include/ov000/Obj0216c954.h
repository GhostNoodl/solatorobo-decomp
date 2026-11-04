#ifndef OV000_OBJ0216C954_H
#define OV000_OBJ0216C954_H

#include "types.h"
#include "nitro/fx.h"
#include "ov000/Model0218fe1c.h"

struct ActorRes;      // ov000/ActorParts.h
struct Model;         // Main/Gfx/Model.h

// The 0x54-byte 3D effect of Obj0216c954 (ctor Obj021c2114_Ctor, release Obj021c2114_Release,
// update Obj021c2114_Update, draw Obj021c2114_Draw; the update is a NONMATCHING draft, see
// docs/UNMATCHED.md). Once active it loads its own model,
// turns from pos toward target and fades in; while it is shown its alpha pulses.
typedef struct Obj021c2114 {
    union {
        u32 flags;
        struct {
            u32 pulseUp : 1; // the pulse counts up (else down); flipped at the ends
            u32 active : 1; // set by the owner while it is shown; the effect fades out without it
            u32 useOfs : 1; // the draw points data_ov000_021ccd74.unk_10 at ofs
            u32 rotate : 1; // the draw sets data_ov000_021ccd74.unk_08 to the rot matrix
            u32 unk_00_4 : 28;
        };
    };
    s32 state; // 0x04 1: load, 7: wait for the load, 4: hidden, 10: shown
    struct ActorRes *res; // 0x08 ctor ResSet_Init
    Model0218fe1c *model; // 0x0c
    VecFx32 pos; // 0x10
    u16 rx; // 0x1c the model's turn toward target (Obj021c2114_Update)
    u16 ry;
    u16 rz;
    u16 unk_22;
    VecFx32 ofs; // 0x24
    u16 rot[3]; // 0x30 x, y, z angles of the draw's extra rotation (rotate)
    u16 unk_36;
    VecFx32 target; // 0x38
    s32 fadeFrame; // 0x44 0..0xf000
    s32 fade; // 0x48 fx32 fade ratio (sine of fadeFrame)
    s32 pulseFrame; // 0x4c
    s32 pulse; // 0x50 fx32 pulse ratio (sine of pulseFrame); the alpha is 0x1f * fade * pulse
} Obj021c2114;
SIZE_ASSERT(Obj021c2114, 0x54);

// The 0x3c-byte object of ListBuffer021cb940::unk_50 (ctor Obj0216c954_Init, update
// Obj0216c954_Update, draw Obj0216c954_Draw, release Obj0216c9b0_Release). Field message 11
// makes it (kind and mode), message 12 stops it. While the field is idle it slides a 2D model in
// that shows count and total as two-digit numbers (Obj0216c954_OamCallback), and its effect points at
// the nearest spawn position of kind.
typedef struct Obj0216c954 {
    union {
        u32 flags;
        struct {
            u32 stop : 1; // set by message 12: the object ends once it is hidden
            u32 opening : 1; // sliding in (else out)
            u32 show : 1; // the field has been idle for more than four frames
            u32 idleFrames : 4;
            u32 unk_00_7 : 25;
        };
    };
    s32 state; // 0x04 2: start, 3: done, 4: hidden, 5: load, 6: wait for the load, 7: shown, 8: slide
    s32 mode; // 0x08 0: no effect; 2: no range limit (func_ov000_0216d474)
    struct Model *model; // 0x0c
    Obj021c2114 *effect; // 0x10
    s32 range; // 0x14 squared distance within which a spawn position is pointed at
    s32 unk_18;
    u16 kind; // 0x1c
    u8 unk_1e[0x2];
    s32 count; // 0x20 shown by Obj0216c954_OamCallback (Obj0216c954_SetCount sets both)
    s32 total; // 0x24
    u16 part; // 0x28 model part played between parts 13 and 14 (0xffff: no model)
    u16 findKind; // 0x2a the kind whose spawn positions are searched
    s32 frame; // 0x2c frames into the slide
    s32 ratio; // 0x30 fx32 slide position
    s32 bounceFrame; // 0x34 0..0x40
    s32 bounce; // 0x38 fx32 y offset of the bouncing part
} Obj0216c954;
SIZE_ASSERT(Obj0216c954, 0x3c);

#ifdef __cplusplus
extern "C" {
#endif

void Obj0216c954_Init(Obj0216c954 *self, u16 kind, s32 mode);
void Obj0216c9b0_Release(Obj0216c954 *self);
void Obj0216c954_SetCount(Obj0216c954 *self, s32 count, s32 total);
BOOL Obj0216c954_Update(Obj0216c954 *self);
void Obj0216c954_Draw(Obj0216c954 *self);
void func_ov000_0216d474(Obj0216c954 *self);
void Obj021c2114_Draw(Obj021c2114 *self);
void Obj021c2114_Ctor(Obj021c2114 *self);
void Obj021c2114_Release(Obj021c2114 *self);

#ifdef __cplusplus
}
#endif

#endif
