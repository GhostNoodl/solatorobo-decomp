#ifndef OV000_TASKLIST_H
#define OV000_TASKLIST_H

#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/HeapScope.h"
#include "Main/Gfx/Model.h"
#include "nitro/std.h"

// The ov000 task base (vtable data_ov000_021cc060, 0x3c bytes; func_ov000_021731a0 clears it).
// Tasks are kept in a list sorted by priority (data_ov000_021ccd3c, func_ov000_02173648) and
// looked up by id (Task_FindById). The shared update (slot 0x68, func_ov000_021732a8) runs the
// fade state machine below. The menu task classes derived from it are in ov000/MenuTask.h.
class Task : public VObj {
public:
    union {
        u32 unk_04;
        struct {
            u32 unk_04_0 : 1; // fading (func_ov000_021732a8)
            u32 unk_04_1 : 1; // fade out requested
            u32 unk_04_2 : 1; // removed: func_ov000_02173784 unlinks and deletes the task
            u32 unk_04_3 : 1;
            u32 unk_04_4 : 1; // Task_SetFlag4 / ClearFlag4
            u32 unk_04_5 : 1;
            u32 unk_04_6 : 1;
            u32 unk_04_7 : 1;
            u32 unk_04_8 : 24;
        };
    };
    s32 state; // fade state (func_ov000_021732a8): 0 idle, 8..9 fading in, 10..11 out, 12..13 shown
    s32 param; // set by the creator (LoSwitchTaskC)
    u32 priority;
    s32 id;
    s32 pendingId; // task to switch to (slot 0x60) once the task is idle
    s32 fadeCur;
    s32 fadeLen;
    s32 fadeRatio; // fadeCur / fadeLen
    s32 fadeSin;   // sine of fadeRatio (slot 0x74)
    Task *parent;  // the task that was finishing when this one was created; returned to on exit
    s32 (*callback)(void *self, s32 arg); // set by the creator; Task021cbfe0 calls it (0 on start)
    Task *prev;
    Task *next;
};
SIZE_ASSERT(Task, 0x3c);

// The task host data_ov000_021ccd44 (0x58 bytes, built by func_ov000_02180660 and freed by
// func_ov000_02180754, updated by func_ov000_02180900): a pending task switch and the task it
// switches to. Its state (unk_04) runs the switch: 5 calls the task's vfunc_10, 6 waits for its
// vfunc_14, 7 starts it once no task is finishing.
struct TaskHost {
    union {
        u32 unk_00;
        struct {
            u32 unk_00_0 : 1;
            u32 unk_00_1 : 1;
            u32 mode : 2; // pending switch: 1 to a new task, 2 to one already in the list
            u32 unk_00_4 : 28;
        };
    };
    s32 unk_04;
    VObj res; // vtable data_0208b318; its vfunc_1c loads (func_ov000_02180900)
    u8 unk_0c[0x40];
    s32 unk_4c; // inside res
    u8 unk_50[0x4];
    Task *task; // the task being switched to
};
SIZE_ASSERT(TaskHost, 0x58);

extern "C" {

extern void *data_ov000_021ccd3c;
extern struct GfxSys *data_02097d48; // Main/Gfx/GfxMgr.h
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbce0[];
extern const char *data_0208cca0;
extern void *data_0208ccc0;

void *Heap_Alloc(u32 size);
void Heap_Free(void *ptr);
void func_02043d20(void *a, s32 b);
void func_ov000_0214c1ac(void);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, void *b);
void func_02041c20(Model *model, s32 a, void *b);
void func_ov000_02173d9c(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);
void func_ov000_0214c210(void);

}

static inline BOOL TaskList_HasTasks(void) {
    return data_ov000_021ccd3c != NULL ? TRUE : FALSE;
}

#endif
