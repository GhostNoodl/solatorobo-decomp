#ifndef OV000_LOTIMER_H
#define OV000_LOTIMER_H

// The field's stage timer (0x54 bytes, ctor LoTimer_Init; ListBuffer021cb940::unk_54, made by
// MessageQueue021cb980_HandleMsg). LoTimer_Setup starts it counting up to `limit` (mode 1) or down from it
// to 0 (mode 2); LoTimer_Update runs it (state 0..9), LoTimer_Draw draws it with its two
// models (built by func_ov000_0216e67c, freed by LoTimer_FreeModels). Times are in frames
// (0x57e40: 99:59.99).

#include "types.h"
#include "Main/Gfx/Model.h"

typedef struct LoTimer {
    union {
        u32 flags;
        struct {
            u32 b0 : 1; // set by the field task to stop it
            u32 built : 1; // the models were made (func_ov000_0216e67c)
            u32 b2 : 1;
            u32 b3 : 1;
            u32 b4 : 1;
            u32 b5 : 1;
            u32 b6 : 1; // the end reports to the stage (func_020627fc / func_ov000_02182590)
            u32 b7 : 1; // counting
            u32 b8 : 1;
            u32 b9 : 1;
            u32 b10 : 1;
            u32 b11 : 1;
            u32 b12 : 1;
            u32 b13 : 1;
            u32 b14 : 1; // the time reached its end
            u32 b15 : 1;
            u32 b16 : 1;
            u32 b17 : 1;
            u32 f18 : 4;
            u32 b22 : 1;
            u32 rest : 9;
        };
    };
    s32 state;
    s32 mode; // 1 count up, 2 count down
    s32 result; // 1 .. 3, given to func_020627fc
    Model *unk_10;
    Model *unk_14;
    s32 step; // frames counted per frame
    s32 time;
    s32 shownTime;
    s32 limit;
    s32 unk_28;
    s32 slideTime;
    s32 slide; // 0 .. 0x1000 slide-in of the display
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    u16 unk_44;
    u8 unk_46[0x2];
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
} LoTimer;

#ifdef __cplusplus
extern "C" {
#endif

void LoTimer_Init(LoTimer *self);
void LoTimer_Setup(LoTimer *self, s32 mode, s32 limit, s32 c);
BOOL LoTimer_Update(LoTimer *self);
void LoTimer_Draw(LoTimer *self);
void LoTimer_FreeModels(LoTimer *self);
void func_ov000_0216e67c(LoTimer *self);
void LoTimer_Finish(LoTimer *self);
void func_ov000_0216e968(LoTimer *self);
void func_ov000_0216eaf8(LoTimer *self);

#ifdef __cplusplus
}
#endif

#endif
