#ifndef OV002_SESSION_H
#define OV002_SESSION_H

#include "types.h"

// The overlay 2 session object data_ov002_021f0f80: made by func_ov002_021ccda0 and freed by
// func_ov002_021ccde4 (the scene commands of ov000's Lo_021814dc.cpp start and stop it), stepped by
// func_ov002_021cceb4 (load the resources, start task 0x10, wait for the fade, then set done).
typedef struct Ov002Session {
    /* 0x00 */ union {
        s32 unk_00;
        struct {
            u32 done : 1; // set by func_ov002_021cceb4 when the session ends (ov000 waits for it)
            u32 flag1 : 1;
            u32 rest : 30;
        };
    };
    /* 0x04 */ s32 state;
    /* 0x08 */ s8 unk_08; // a choice: -1 until set (0..4 by the board task 0x11/0x1a paths)
} Ov002Session;

#ifdef __cplusplus
extern "C" {
#endif
extern Ov002Session *data_ov002_021f0f80;
void func_ov002_021ccda0(void);
void func_ov002_021ccde4(void);
void func_ov002_021cceb4(Ov002Session *self);
void func_ov002_021cd068(Ov002Session *self);
#ifdef __cplusplus
}
#endif

#endif
