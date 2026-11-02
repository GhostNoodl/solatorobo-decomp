#ifndef OV000_TASKLIST_H
#define OV000_TASKLIST_H

#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/HeapScope.h"
#include "Main/Gfx/Model.h"
#include "nitro/std.h"

class Task : public VObj {
public:
    u32 unk_04_0 : 1;
    u32 unk_04_1 : 1;
    u32 unk_04_2 : 1;
    u32 unk_04_3 : 29;
    u8 unk_08[0x8];
    u32 priority;
    s32 id;
    u8 unk_18[0x8];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x8];
    Task *prev;
    Task *next;
    s32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    Model *unk_4c;
    u8 unk_50[0x4];
};

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
