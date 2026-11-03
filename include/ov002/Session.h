#ifndef OV002_SESSION_H
#define OV002_SESSION_H

#include "types.h"

// The overlay 2 session object gOv002Session: made by Ov002Session_Create and freed by
// Ov002Session_Delete (the scene commands of ov000's Lo_021814dc.cpp start and stop it), stepped by
// Ov002Session_Update (load the resources, start task 0x10, wait for the fade, then set done).
typedef struct Ov002Session {
    /* 0x00 */ union {
        s32 unk_00;
        struct {
            u32 done : 1; // set by Ov002Session_Update when the session ends (ov000 waits for it)
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
extern Ov002Session *gOv002Session;
void Ov002Session_Create(void);
void Ov002Session_Delete(void);
void Ov002Session_Update(Ov002Session *self);
void Ov002Session_Draw(Ov002Session *self);
#ifdef __cplusplus
}
#endif

#endif
