#include "ov006/ov006.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"
#include "Main/Res/DataRes.h"

extern "C" {

typedef void (*ov006_StateFunc)(int a, int b, int c);

extern void *ov006_Task_vtbl;
extern void *Ov006Vt_021ebb48_vtbl;
extern char data_ov006_021ebb88[];
extern char data_ov006_021ebb78[];
extern char data_ov006_021ec864[];
extern ov006_StateFunc ov006_Manager_ModeTable[];

void ov006_Menu_Delete(void);
int WH_Destroy_02044b20(void);
void ov006_DeleteSlotManager(void);
void Wh_Create(void);
void ov006_Menu_Create(void);
void ov006_SlotManager_Create(void);
void ov006_Menu_Load(ov006_Menu *a);
void ov006_Menu_DrawHolder(ov006_Menu *a);
BOOL ov006_Menu_RequestShutdown(ov006_Menu *a);
ov006_Task *Ov006Vt_021ebc98_Ctor(void *mem);
ov006_Task *Ov006Vt_021ebfc0_Ctor(void *mem);
ov006_Task *Ov006Vt_021ec040_Ctor(void *mem);
int ov006_Manager_SwitchTask(ov006_Manager *self);
int ov006_Manager_ShutdownNet(ov006_Manager *self);

void ov006_Task_Ctor(ov006_Task *self) {
    *(void **)self = &ov006_Task_vtbl;
    self->type = 3;
    self->state = 0;
    self->subState = 0;
}

void ov006_Task_Dtor(void) {
}

ov006_Task *ov006_Task_DtorDelete(ov006_Task *self) {
    Heap_Free(self);
    return self;
}

void func_ov006_021ccddc(ov006_Task *self) {
}

int ov006_Task_Load(void) {
    return 1;
}

int ov006_Task_IsLoaded(void) {
    return 1;
}

int ov006_Task_Start(void) {
    return 1;
}

int ov006_Task_Update(void) {
    return 0;
}

int ov006_Task_Exit(void) {
    return 1;
}

void ov006_Task_Draw(void) {
}

static inline void ov006_Manager_Dtor(ov006_Manager *self) {
    self->vtbl = &Ov006Vt_021ebb48_vtbl;
    OV006_DELETE_OBJECT(self->task);
    ResMgr_ReleaseByName(gResMgr, ArcPath_Menu, 7, 0);
    ResMgr_ReleaseByName(gResMgr, data_ov006_021ebb88, 7, 0);
    ov006_Menu_Delete();
    WH_Destroy_02044b20();
    ov006_DeleteSlotManager();
    func_0201bbfc(1);
}

ov006_Manager *Ov006Vt_021ebb48_Dtor(ov006_Manager *self) {
    ov006_Manager_Dtor(self);
    return self;
}

ov006_Manager *Ov006Vt_021ebb48_DtorDelete(ov006_Manager *self) {
    ov006_Manager_Dtor(self);
    Heap_Free(self);
    return self;
}

void ov006_Manager_Create(void) {
    ov006_Manager *obj;
    OV006_DELETE_OBJECT(gOv006Manager);
    obj = (ov006_Manager *)Heap_Alloc(sizeof(ov006_Manager));
    if (obj != NULL) {
        obj->vtbl = &Ov006Vt_021ebb48_vtbl;
        func_0201bbfc(0);
        LangData_LocalizePath(data_ov006_021ec864, data_ov006_021ebb78);
        obj->state = 0;
        obj->subState = 0;
        obj->taskType = 4;
        obj->task = NULL;
        obj->unk14 = 0;
        obj->unk18 = 0;
        obj->unk1C = 0;
        obj->unk20 = 0;
    }
    gOv006Manager = obj;
}

// Only referenced from overlay 0 through an ambiguous relocation, so keep it from being dead-stripped.
#pragma force_active on
void ov006_Manager_Delete(void) {
    OV006_DELETE_OBJECT(gOv006Manager);
}
#pragma force_active reset

static inline BOOL ov006_IsLoaded(void) {
    return ((ResMgr_IsLoaded(ArcPath_Menu, 7) != 0) & ResMgr_IsLoaded(data_ov006_021ebb88, 7)) != 0;
}

int ov006_Manager_LoadRes(ov006_Manager *self) {
    int one = 1;
    int zero = 0;
    BOOL result = TRUE;
    BOOL done;

    switch (self->state) {
    case 0:
        ResMgr_Load(ArcPath_Menu, 7, zero);
        ResMgr_Load(data_ov006_021ebb88, 7, zero);
        self->state = 1;
        self->subState = zero;
    case 1:
        if (ov006_IsLoaded()) {
            self->state = 2;
            self->subState = zero;
        }
        break;
    case 2:
        done = zero;
        switch (self->subState) {
        case 0:
            Wh_Create();
            ov006_Menu_Create();
            ov006_SlotManager_Create();
            self->subState++;
            break;
        case 1:
            ov006_Menu_Load(gOv006Menu);
            if (gOv006Menu->state == 0) {
                break;
            }
            ov006_Manager_ModeTable[gOv006Manager->unk14](1, done, done);
            self->subState++;
        case 2:
            done = TRUE;
            break;
        }
        if (done) {
            self->state = 3;
            self->subState = zero;
        }
        break;
    case 3:
        if (ov006_Manager_SwitchTask(self) == 0) {
            self->state = 4;
            self->subState = zero;
        }
        break;
    case 4:
        if (ov006_Manager_ShutdownNet(self) != 0) {
            self->state = 5;
            self->subState = zero;
        }
        break;
    case 5:
        result = FALSE;
        break;
    }
    if (gOv006Menu != NULL && gOv006Menu->state != 0 && gOv006Menu->state != 1) {
        gSysState->unk_1f = one;
    }
    return result;
}

void ov006_Manager_Draw(ov006_Manager *self) {
    ov006_Task *task = self->task;
    if (task != NULL && task->state >= 3) {
        task->vfunc_1c();
    }
    if (gOv006Menu != NULL) {
        ov006_Menu_DrawHolder(gOv006Menu);
    }
}

static inline BOOL ov006_Manager_HasUnk14(ov006_Manager *self) {
    return self->unk14 != 0;
}

BOOL func_ov006_021cd2a8(ov006_Manager *self) {
    return ov006_Manager_HasUnk14(self) ? TRUE : FALSE;
}

static inline void ov006_Update021ec888(void) {
    ov006_Menu_Load(gOv006Menu);
    if (gOv006Menu->unk15F != 0) {
        gOv006Menu->unk15F--;
    }
}

}


extern "C" {

BOOL ov006_Manager_SwitchTask(ov006_Manager *self) {
    int zero = 0;
    BOOL result = TRUE;
    ov006_Task *task;
    int type;

    if (self->taskType != 4) {
        OV006_DELETE_OBJECT(self->task);
        type = self->taskType;
        switch (type) {
        case 0:
            task = (ov006_Task *)Heap_Alloc(0x14);
            if (task != NULL) {
                task = Ov006Vt_021ebc98_Ctor(task);
            }
            break;
        case 1:
            task = (ov006_Task *)Heap_Alloc(0x88);
            if (task != NULL) {
                task = Ov006Vt_021ebfc0_Ctor(task);
            }
            break;
        case 2:
            task = (ov006_Task *)Heap_Alloc(0x44);
            if (task != NULL) {
                task = Ov006Vt_021ec040_Ctor(task);
            }
            break;
        default:
            task = NULL;
            break;
        }
        if (task != NULL) {
            task->type = type;
        }
        self->task = task;
        self->taskType = 4;
    }
    task = self->task;
    if (task != NULL) {
        switch (task->state) {
        case 0:
            if (!task->vfunc_08()) {
                break;
            }
            task->state = 1;
            task->subState = zero;
        case 1:
            if (!task->vfunc_0c()) {
                break;
            }
            task->state = 2;
            task->subState = zero;
        case 2:
            if (!task->vfunc_10()) {
                break;
            }
            task->state = 3;
            task->subState = zero;
        case 3:
            if (task->vfunc_14()) {
                break;
            }
            task->state = 4;
            task->subState = zero;
        case 4:
            if (task->vfunc_18()) {
                task->state = 5;
                task->subState = zero;
            }
            break;
        case 5:
            break;
        }
    } else {
        result = FALSE;
    }
    ov006_Update021ec888();
    return result;
}

BOOL ov006_Manager_ShutdownNet(ov006_Manager *self) {
    BOOL result = FALSE;
    switch (self->subState) {
    case 0:
        if (gOv006Menu->state != 1) {
            ov006_Menu_RequestShutdown(gOv006Menu);
        }
        self->subState++;
    case 1:
        ov006_Update021ec888();
        if (gOv006Menu->state == 1) {
            ov006_Menu_Delete();
            ov006_DeleteSlotManager();
            self->subState++;
        }
        break;
    case 2:
        if (WH_Destroy_02044b20()) {
            result = TRUE;
            self->subState++;
        }
        break;
    }
    return result;
}

void ov006_Manager_DispatchMenuCb(int a, int b, int c) {
    ov006_Manager_ModeTable[gOv006Manager->unk14](a, b, c);
}

}
