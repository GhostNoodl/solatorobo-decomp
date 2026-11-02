#include "ov006/ov006.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"
#include "Main/Res/DataRes.h"

extern "C" {

typedef void (*ov006_StateFunc)(int a, int b, int c);

extern void *data_ov006_021ebb58;
extern void *data_ov006_021ebb48;
extern char data_ov006_021ebb88[];
extern char data_ov006_021ebb78[];
extern char data_ov006_021ec864[];
extern ov006_StateFunc data_ov006_021eb6d8[];

void ov006_Menu_Delete(void);
int func_02044b20(void);
void ov006_DeleteSlotManager(void);
void Wh_Create(void);
void ov006_Menu_Create(void);
void ov006_SlotManager_Create(void);
void ov006_Menu_Load(ov006_Unk021ec888 *a);
void ov006_Menu_DrawHolder(ov006_Unk021ec888 *a);
BOOL ov006_Menu_RequestShutdown(ov006_Unk021ec888 *a);
ov006_Task *func_ov006_021d54b0(void *mem);
ov006_Task *func_ov006_021d5b04(void *mem);
ov006_Task *Ov006Vt_021ec040_Ctor(void *mem);
int ov006_Manager_SwitchTask(ov006_Manager *self);
int func_ov006_021cd4c0(ov006_Manager *self);

void ov006_Task_Ctor(ov006_Task *self) {
    *(void **)self = &data_ov006_021ebb58;
    self->type = 3;
    self->state = 0;
    self->subState = 0;
}

void func_ov006_021ccdc4(void) {
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

int ov006_Task_Setup(void) {
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
    self->vtbl = &data_ov006_021ebb48;
    OV006_DELETE_OBJECT(self->task);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, data_ov006_021ebb88, 7, 0);
    ov006_Menu_Delete();
    func_02044b20();
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
    OV006_DELETE_OBJECT(data_ov006_021ec860);
    obj = (ov006_Manager *)Heap_Alloc(sizeof(ov006_Manager));
    if (obj != NULL) {
        obj->vtbl = &data_ov006_021ebb48;
        func_0201bbfc(0);
        func_0206e900(data_ov006_021ec864, data_ov006_021ebb78);
        obj->state = 0;
        obj->subState = 0;
        obj->taskType = 4;
        obj->task = NULL;
        obj->unk14 = 0;
        obj->unk18 = 0;
        obj->unk1C = 0;
        obj->unk20 = 0;
    }
    data_ov006_021ec860 = obj;
}

// Only referenced from overlay 0 through an ambiguous relocation, so keep it from being dead-stripped.
#pragma force_active on
void ov006_Manager_Delete(void) {
    OV006_DELETE_OBJECT(data_ov006_021ec860);
}
#pragma force_active reset

static inline BOOL ov006_IsLoaded(void) {
    return ((func_02035b90(data_0208cca0, 7) != 0) & func_02035b90(data_ov006_021ebb88, 7)) != 0;
}

int ov006_Manager_LoadRes(ov006_Manager *self) {
    int one = 1;
    int zero = 0;
    BOOL result = TRUE;
    BOOL done;

    switch (self->state) {
    case 0:
        func_020359d0(data_0208cca0, 7, zero);
        func_020359d0(data_ov006_021ebb88, 7, zero);
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
            ov006_Menu_Load(data_ov006_021ec888);
            if (data_ov006_021ec888->state == 0) {
                break;
            }
            data_ov006_021eb6d8[data_ov006_021ec860->unk14](1, done, done);
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
        if (func_ov006_021cd4c0(self) != 0) {
            self->state = 5;
            self->subState = zero;
        }
        break;
    case 5:
        result = FALSE;
        break;
    }
    if (data_ov006_021ec888 != NULL && data_ov006_021ec888->state != 0 && data_ov006_021ec888->state != 1) {
        data_02097dd0->unk_1f = one;
    }
    return result;
}

void ov006_Manager_Draw(ov006_Manager *self) {
    ov006_Task *task = self->task;
    if (task != NULL && task->state >= 3) {
        task->vfunc_1c();
    }
    if (data_ov006_021ec888 != NULL) {
        ov006_Menu_DrawHolder(data_ov006_021ec888);
    }
}

static inline BOOL ov006_Manager_HasUnk14(ov006_Manager *self) {
    return self->unk14 != 0;
}

BOOL func_ov006_021cd2a8(ov006_Manager *self) {
    return ov006_Manager_HasUnk14(self) ? TRUE : FALSE;
}

static inline void ov006_Update021ec888(void) {
    ov006_Menu_Load(data_ov006_021ec888);
    if (data_ov006_021ec888->unk15F != 0) {
        data_ov006_021ec888->unk15F--;
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
                task = func_ov006_021d54b0(task);
            }
            break;
        case 1:
            task = (ov006_Task *)Heap_Alloc(0x88);
            if (task != NULL) {
                task = func_ov006_021d5b04(task);
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

BOOL func_ov006_021cd4c0(ov006_Manager *self) {
    BOOL result = FALSE;
    switch (self->subState) {
    case 0:
        if (data_ov006_021ec888->state != 1) {
            ov006_Menu_RequestShutdown(data_ov006_021ec888);
        }
        self->subState++;
    case 1:
        ov006_Update021ec888();
        if (data_ov006_021ec888->state == 1) {
            ov006_Menu_Delete();
            ov006_DeleteSlotManager();
            self->subState++;
        }
        break;
    case 2:
        if (func_02044b20()) {
            result = TRUE;
            self->subState++;
        }
        break;
    }
    return result;
}

void ov006_Manager_DispatchMenuCb(int a, int b, int c) {
    data_ov006_021eb6d8[data_ov006_021ec860->unk14](a, b, c);
}

}
