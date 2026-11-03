#ifndef OV000_OBJ0216AD04_H
#define OV000_OBJ0216AD04_H

#include "types.h"

struct Model; // Main/Gfx/Model.h

// The 0x20-byte object of ListBuffer021cb940::unk_78 (init func_ov000_0216ad04, release
// func_ov000_0216ad34, update func_ov000_0216adf8, draw func_ov000_0216b1b4). Like Lo0216b474,
// a 2D model slides in while someone keeps asking for it each frame (func_ov000_0216adc0, from
// the robot's update) and slides out once it stops; its OAM callback (func_ov000_0216ac14)
// draws value as up to two digits.
typedef struct Obj0216ad04 {
    union {
        u32 flags;
        struct {
            u32 opening : 1; // sliding in (else out)
            u32 want : 1; // set by func_ov000_0216adc0; cleared when the field is busy
            u32 asked : 1; // set by each func_ov000_0216adc0 call with the same kind; want is
                           // dropped after a frame without one
            u32 unk_00_3 : 29;
        };
    };
    s32 state; // 0x04 2: start, 3: free the model, 4: wait for want, 5: load, 6: wait for the load, 7/8: slide
    s32 kind; // 0x08 the first argument of func_ov000_0216adc0 (-1 after the init)
    struct Model *model; // 0x0c
    s32 value; // 0x10 0..99
    u16 part; // 0x14 the model part of the digits
    u8 unk_16[0x2];
    s32 frame; // 0x18 frames into the slide (0xc frames)
    s32 ratio; // 0x1c fx32 slide position, 0..0x1000
} Obj0216ad04;
SIZE_ASSERT(Obj0216ad04, 0x20);

#ifdef __cplusplus
extern "C" {
#endif

void func_ov000_0216ad04(Obj0216ad04 *self);
void func_ov000_0216ad34(Obj0216ad04 *self);
void func_ov000_0216adc0(Obj0216ad04 *self, s32 kind, s32 value);
void func_ov000_0216adf8(Obj0216ad04 *self);
void func_ov000_0216b1b4(Obj0216ad04 *self);

#ifdef __cplusplus
}
#endif

#endif
