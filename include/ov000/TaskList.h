#ifndef OV000_TASKLIST_H
#define OV000_TASKLIST_H

#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct {
    u8 unk_00[0x2c];
    u8 unk_2c[0x40];
    u32 unk_6c;
    u8 unk_70[0x18];
    u8 unk_88[0xd0];
    void *unk_158;
    u8 unk_15c[0x4];
} Model;

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

typedef struct {
    u8 unk_00;
    u32 unk_04;
    Task *head;
    Task *unk_0c;
} TaskList;

typedef struct {
    u8 unk_00[0x54];
    Task *unk_54;
} Data021ccd30Sub;

typedef struct {
    u8 unk_00[0x11c];
    Data021ccd30Sub *unk_11c;
} Data021ccd30;

extern "C" {

extern HeapState *data_02097dd0;
extern TaskList data_ov000_021ccd34;
extern Data021ccd30 *data_ov000_021ccd30;
extern u8 *data_02097d48;
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbce0[];
extern const char *data_0208cca0;
extern void *data_0208ccc0;

void *func_0203dd9c(u32 size);
void func_0203de1c(void *ptr);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_ov000_0214c1ac(void *a);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, void *b);
void func_02041218(void *a);
void func_02041440(Model *model, void *a, s32 b);
void func_0201e520(void *a, const char *b);
void func_020417e0(Model *model, void *a);
void func_02041d9c(Model *model, s32 a, s32 b);
void func_02041c20(Model *model, s32 a, void *b);
void func_02041558(Model *model);
void func_02041278(void *a);
void func_ov000_02173d9c(void);
void func_ov000_02173648(Task *task);
void func_ov000_0214c210(Task *task);
void MTX_Identity44_(void *a);

}

static inline BOOL TaskList_HasTasks(void) {
    return data_ov000_021ccd34.head != NULL ? TRUE : FALSE;
}

static inline BOOL Task_IsState4(Task *task) {
    return task->unk_04_0 == 0 && *(s32 *)((u8 *)task + 4) == 4 ? TRUE : FALSE;
}

static inline Model *Model_NewDefault(void) {
    Model *model = (Model *)func_0203dd9c(sizeof(Model));
    if (model != NULL) {
        void *a = data_0208ccc0;
        const char *name = data_0208cca0;
        func_02041218(model->unk_88);
        func_02041440(model, a, 0);
        func_0201e520(model->unk_2c, name);
    }
    return model;
}

#endif
