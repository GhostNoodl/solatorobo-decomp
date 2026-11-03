#ifndef OV000_TASKLIST_H
#define OV000_TASKLIST_H

#include "ov000/VObj.h"
#include "ov000/Task.h"
#include "ov000/Vec.h"
#include "ov000/HeapScope.h"
#include "Main/Gfx/Model.h"
#include "nitro/std.h"
#include "Main/Res/ResArc.h"


// The task host gTaskHost (0x58 bytes, built by TaskHost_Create and freed by
// TaskHost_Destroy, updated by TaskHost_Update): a pending task switch and the task it
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
    VObj res; // vtable ResHandle_vtbl; its vfunc_1c loads (TaskHost_Update)
    u8 unk_0c[0x40];
    s32 unk_4c; // inside res
    u8 unk_50[0x4];
    Task *task; // the task being switched to
};
SIZE_ASSERT(TaskHost, 0x58);

extern "C" {

extern void *data_ov000_021ccd3c;
extern struct GfxSys *gGfxSys; // Main/Gfx/GfxMgr.h
extern u8 Task_vtbl[];
extern u8 Task021cbce0_vtbl[];
extern const char *data_0208cca0;
extern void *data_0208ccc0;

void *Heap_Alloc(u32 size);
void Heap_Free(void *ptr);
void Gfx3D_SendDL(void *a, s32 b);
void func_ov000_0214c1ac(void);
void TexObj_SetOamFuncArg(Model *model, s32 a, void *b);
void func_ov000_02173d9c(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);
void func_ov000_0214c210(void);

}

static inline BOOL TaskList_HasTasks(void) {
    return data_ov000_021ccd3c != NULL ? TRUE : FALSE;
}

#endif
