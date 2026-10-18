#include "ov000/VObj.h"
#include "ov000/CmdQueue.h"

typedef struct {
    u8 unk_00[0x4];
    CmdQueue *unk_04;
} Data021ccd50;

typedef struct {
    void *vtable;
    u32 unk_04;
} Task021854d4;

typedef struct {
    u8 unk_00[0x11c];
    Task021854d4 *unk_11c;
} Mgr021854d4;

extern "C" {

extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb940[];
void *func_0203dd9c(u32 size);
void func_ov000_0216f144(Task021854d4 *self);
void func_ov000_0216faac(Task021854d4 *self);
void func_ov000_0216f398(Mgr021854d4 *mgr, Task021854d4 *task, s32 a, Mgr021854d4 *b);
void func_ov000_02172240(void *mgr, s32 a, s32 b);

extern Mgr021854d4 *data_ov000_021ccd30;
extern Data021ccd50 data_ov000_021ccd50;
void func_ov000_02172218(Mgr021854d4 *p);

void func_ov000_0218547c(void) {
    func_ov000_02172218(data_ov000_021ccd30);
    CmdQueue_Push(data_ov000_021ccd50.unk_04, 0x11, 0);
}

void func_ov000_021854d4(CmdQueue *self, s32 a, s32 b) {
    Mgr021854d4 *mgr = data_ov000_021ccd30;
    if (mgr->unk_11c == NULL) {
        Task021854d4 *task = (Task021854d4 *)func_0203dd9c(0x80);
        if (task != NULL) {
            task->vtable = data_ov000_021cb6d0;
            func_ov000_0216f144(task);
            task->vtable = data_ov000_021cb940;
            func_ov000_0216faac(task);
        }
        mgr->unk_11c = task;
        func_ov000_0216f398(mgr, task, 0x10000, mgr);
        mgr->unk_11c->unk_04 |= 0x10;
    }
    func_ov000_02172240(data_ov000_021ccd30, a, b);
    CmdQueue_Push(self, 0x12, 0);
}

}
