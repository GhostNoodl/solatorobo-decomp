#ifndef OV000_TASK_H
#define OV000_TASK_H

#include "ov000/VObj.h"

#ifdef __cplusplus

// The ov000 task base (vtable Task_vtbl, 0x3c bytes; Task_Init clears it).
// Tasks are kept in a list sorted by priority (data_ov000_021ccd3c, TaskList_Insert) and
// looked up by id (Task_FindById). The shared update (slot 0x68, Task_Update) runs the
// fade state machine below. The menu task classes derived from it are in ov000/MenuTask.h.
typedef s32 (*TaskCallback)(void *self, s32 arg);

class Task : public VObj {
public:
    union {
        u32 unk_04;
        struct {
            u32 unk_04_0 : 1; // fading (Task_Update)
            u32 unk_04_1 : 1; // fade out requested
            u32 unk_04_2 : 1; // removed: TaskList_DeleteFlagged unlinks and deletes the task
            u32 unk_04_3 : 1;
            u32 unk_04_4 : 1; // Task_SetFlag4 / ClearFlag4
            u32 unk_04_5 : 1;
            u32 unk_04_6 : 1;
            u32 unk_04_7 : 1;
            u32 unk_04_8 : 24;
        };
    };
    s32 state; // fade state (Task_Update): 0 idle, 8..9 fading in, 10..11 out, 12..13 shown
    s32 param; // set by the creator (LoSwitchTaskC)
    u32 priority;
    s32 id;
    s32 pendingId; // task to switch to (slot 0x60) once the task is idle
    s32 fadeCur;
    s32 fadeLen;
    s32 fadeRatio; // fadeCur / fadeLen
    s32 fadeSin;   // sine of fadeRatio (slot 0x74)
    Task *parent;  // the task that was finishing when this one was created; returned to on exit
    TaskCallback callback; // set by the creator; Task021cbfe0 calls it (0 on start)
    Task *prev;
    Task *next;
};
SIZE_ASSERT(Task, 0x3c);

#endif

#endif
