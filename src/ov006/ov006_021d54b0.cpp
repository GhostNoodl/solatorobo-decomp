#include "ov006/ov006.h"
#include "ov006/Window.h"
#include "ov006/Emblem.h"
#include "ov006/MsgBox.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

struct ov006_Task0 : public ov006_Task {
    int unk10;
};

typedef struct ov006_Unk02097e48 {
    u16 active : 1;
    u16 unk0_1 : 15;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} ov006_Unk02097e48;


struct ov006_Task1 : public ov006_Task {
    u16 unk10;
    u16 unk12;
    u16 unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    u8 unk40[0x28];
    int unk68;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    int unk70[6];
};

extern "C" {

extern void *Ov006Vt_021ebc98_vtbl;
extern void *ov006_Emblem_vtbl;
extern void *Ov006Vt_021ebc80_vtbl;
extern void *ov006_MsgBox_vtbl;
extern void *Ov006Vt_021ebfc0_vtbl;
extern char data_ov006_021ec864[];
extern ov006_Unk02097e48 *gSndQueue;
extern Task *gFinishingTask;
extern int gLastTaskId;

void ov006_Task_Ctor(ov006_Task *self);
void func_ov006_021ccddc(ov006_Task *self);
void ov006_Manager_DispatchMenuCb(int a, int b, int c);
void TaskHost_Destroy(void);
void TaskHost_Create(int a, int b);
bool TaskList_HasTasks_021735e8(void);
void ListRow_Unlink(void *self);
void SndQueue_Push_0204aab0(ov006_Unk02097e48 *a);

ov006_Task0 *func_ov006_021d54b0(ov006_Task0 *self) {
    ov006_Task_Ctor(self);
    *(void **)self = &Ov006Vt_021ebc98_vtbl;
    self->unk10 = 1;
    return self;
}

static inline void ov006_Task0_Dtor(ov006_Task0 *self) {
    *(void **)self = &Ov006Vt_021ebc98_vtbl;
    TaskHost_Destroy();
    ResMgr_ReleaseByName(gResMgr, data_0208cc94, 7, 0);
    ResMgr_ReleaseByName(gResMgr, data_ov006_021ec864, 7, 0);
    func_ov006_021ccddc(self);
}

ov006_Task0 *Ov006Vt_021ebc98_Dtor(ov006_Task0 *self) {
    ov006_Task0_Dtor(self);
    return self;
}

ov006_Task0 *Ov006Vt_021ebc98_DtorDelete(ov006_Task0 *self) {
    ov006_Task0_Dtor(self);
    Heap_Free(self);
    return self;
}

BOOL Ov006Vt_021ebc98_Load(void) {
    ov006_Unk02097e48 *p = gSndQueue;
    if (p->active) {
        if (p->unk6 != 0xffff || p->unk4 != 0x25) {
            u16 v;
            if (p->unk2 != 10 && p->unk2 != 0) {
                if (p->unk6 != 0xffff) {
                    SndQueue_Push_0204aab0(p);
                }
                v = 1;
            } else {
                v = 0;
            }
            p->unk2 = v;
            p->unk6 = 0x25;
            p->unk8 = 10;
        }
    }
    ResMgr_Load(data_0208cc94, 7, 0);
    ResMgr_Load(data_ov006_021ec864, 7, 0);
    return TRUE;
}

BOOL Ov006Vt_021ebc98_IsLoaded(void) {
    return ((ResMgr_IsLoaded(data_0208cc94, 7) != 0) & ResMgr_IsLoaded(data_ov006_021ec864, 7)) != 0;
}

BOOL Ov006Vt_021ebc98_Start(ov006_Task0 *self) {
    switch (self->subState) {
    case 0:
        TaskHost_Create(0x23, 0);
        self->subState++;
    case 1:
        if (gFinishingTask != NULL) {
            gFinishingTask->vfunc_4c();
            ov006_Manager_DispatchMenuCb(2, 0, 0);
            data_ov006_021ec888->unk15E = 2;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL Ov006Vt_021ebc98_Update(void) {
    BOOL result = TRUE;
    if (!TaskList_HasTasks_021735e8()) {
        result = FALSE;
    }
    return result;
}

BOOL Ov006Vt_021ebc98_Exit(void) {
    gOv006Manager->taskType = 3;
    return TRUE;
}

void Ov006Vt_021ebc98_Draw(void) {
}

static inline void ov006_SetUnk021ccd40(Task *p) {
    if (gFinishingTask != NULL) {
        gLastTaskId = gFinishingTask->id;
    } else {
        gLastTaskId = 0;
    }
    gFinishingTask = p;
}

void Ov006Task_SetCurrent(Task *p) {
    ov006_SetUnk021ccd40(p);
}

void Ov006Task_ReleaseCurrent(Task *self) {
    if (self->vfunc_54()) {
        ov006_SetUnk021ccd40(NULL);
    }
}

static inline BOOL Task_Test(Task *self, u32 mask) {
    return (self->unk_04 & mask) != 0;
}

BOOL Ov006Task_TestFlags(Task *self, u32 mask) {
    return Task_Test(self, mask) ? TRUE : FALSE;
}

void Ov006Task_ClearFlag7(Task *self) {
    self->unk_04_7 = 0;
}

static inline BOOL Task_Bit6(Task *self) {
    return self->unk_04_6 != 0;
}

BOOL Ov006Task_GetFlag6(Task *self) {
    return Task_Bit6(self) ? TRUE : FALSE;
}

void Ov006Task_SetFlag6(Task *self) {
    self->unk_04_6 = 1;
}

static inline BOOL Task_Bit5(Task *self) {
    return self->unk_04_5 != 0;
}

BOOL Ov006Task_GetFlag5(Task *self) {
    return Task_Bit5(self) ? TRUE : FALSE;
}

void Ov006Task_SetFlag5(Task *self) {
    self->unk_04_5 = 1;
}

void Ov006Task_ClearFlag4(Task *self) {
    self->unk_04_4 = 0;
}

void Ov006Task_SetFlag4(Task *self) {
    self->unk_04_4 = 1;
}

BOOL Ov006Task_IsReady(void) {
    return TRUE;
}

void ov006_Emblem_UpdateActive(void) {
}

static inline void ov006_Emblem_Dtor(ov006_Emblem *self) {
    *(void **)self = &ov006_Emblem_vtbl;
    OV006_DELETE_MODEL(self->unk3C);
    OV006_DELETE_MODEL(self->unk40);
    self->unk44 = 0;
    OV006_TASKBASE_DTOR(self);
}

ov006_Emblem *ov006_Emblem_DtorDelete(ov006_Emblem *self) {
    ov006_Emblem_Dtor(self);
    Heap_Free(self);
    return self;
}

ov006_Emblem *ov006_Emblem_Dtor_021d59b4(ov006_Emblem *self) {
    ov006_Emblem_Dtor(self);
    return self;
}

void *Ov006Vt_021ebc80_DtorDelete(void **self) {
    *self = &Ov006Vt_021ebc80_vtbl;
    ListRow_Unlink(self);
    Heap_Free(self);
    return self;
}

void func_ov006_021d5abc(void) {
}

void func_ov006_021d5ac0(void) {
}

void *Ov006Vt_021ebc80_Dtor(void **self) {
    *self = &Ov006Vt_021ebc80_vtbl;
    ListRow_Unlink(self);
    return self;
}

ov006_MsgBox *ov006_MsgBox_Dtor(ov006_MsgBox *self) {
    self->vtbl = &ov006_MsgBox_vtbl;
    MsgBox_Release(self);
    return self;
}

ov006_Task1 *func_ov006_021d5b04(ov006_Task1 *self) {
    int i;
    ov006_Task_Ctor(self);
    *(void **)self = &Ov006Vt_021ebfc0_vtbl;
    self->unk10 = 0;
    self->unk12 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    MIi_CpuClear32(0, self->unk40, sizeof(self->unk40));
    self->unk68 = 0;
    self->unk6C = 1;
    self->unk6D = 0;
    self->unk6E = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    for (i = 0; i < 6; i++) {
        self->unk70[i] = 0;
    }
    return self;
}

}
