#include "ov006/ov006.h"

extern "C" {

typedef void (*ov006_StateFunc)(int a, int b, int c);

extern void *data_ov006_021ebb58;
extern void *data_ov006_021ebb48;
extern void *data_02097cdc;
extern void *data_0208cca0;
extern char data_ov006_021ebb88[];
extern char data_ov006_021ebb78[];
extern u8 data_ov006_021ec864[];
extern ov006_StateFunc data_ov006_021eb6d8[];

void func_02036838(void *a, void *b, int c, int d);
void func_ov006_021e42ec(void);
int func_02044b20(void);
void func_ov006_021dae34(void);
void func_0206e900(void *a, void *b);
void *func_020359d0(void *a, int b, int c);
int func_02035b90(void *a, int b);
void func_02044ac4(void);
void func_ov006_021e42b4(void);
void func_ov006_021dacb0(void);
void func_ov006_021e4348(ov006_Unk021ec888 *a);
void func_ov006_021e4574(ov006_Unk021ec888 *a);
BOOL func_ov006_021e4c5c(ov006_Unk021ec888 *a);
ov006_Task *func_ov006_021d54b0(void *mem);
ov006_Task *func_ov006_021d5b04(void *mem);
ov006_Task *func_ov006_021d908c(void *mem);
int func_ov006_021cd2c8(ov006_Manager *self);
int func_ov006_021cd4c0(ov006_Manager *self);

typedef struct {
    void *vtbl;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} ov006_Unk021ccda0;

void func_ov006_021ccda0(ov006_Unk021ccda0 *self) {
    self->vtbl = &data_ov006_021ebb58;
    self->unk4 = 3;
    self->unk8 = 0;
    self->unkC = 0;
}

void func_ov006_021ccdc4(void) {
}

void *func_ov006_021ccdc8(void *self) {
    func_0203de1c(self);
    return self;
}

void func_ov006_021ccddc(void *self) {
}

int func_ov006_021ccde0(void) {
    return 1;
}

int func_ov006_021ccde8(void) {
    return 1;
}

int func_ov006_021ccdf0(void) {
    return 1;
}

int func_ov006_021ccdf8(void) {
    return 0;
}

int func_ov006_021cce00(void) {
    return 1;
}

void func_ov006_021cce08(void) {
}

static inline void ov006_Manager_Dtor(ov006_Manager *self) {
    self->vtbl = &data_ov006_021ebb48;
    OV006_DELETE_OBJECT(self->task);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, data_ov006_021ebb88, 7, 0);
    func_ov006_021e42ec();
    func_02044b20();
    func_ov006_021dae34();
    func_0201bbfc(1);
}

ov006_Manager *func_ov006_021cce0c(ov006_Manager *self) {
    ov006_Manager_Dtor(self);
    return self;
}

ov006_Manager *func_ov006_021ccec8(ov006_Manager *self) {
    ov006_Manager_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov006_021ccf8c(void) {
    ov006_Manager *obj;
    OV006_DELETE_OBJECT(data_ov006_021ec860);
    obj = (ov006_Manager *)func_0203dd9c(sizeof(ov006_Manager));
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
void func_ov006_021cd050(void) {
    OV006_DELETE_OBJECT(data_ov006_021ec860);
}
#pragma force_active reset

static inline BOOL ov006_IsLoaded(void) {
    return ((func_02035b90(data_0208cca0, 7) != 0) & func_02035b90(data_ov006_021ebb88, 7)) != 0;
}

int func_ov006_021cd0ac(ov006_Manager *self) {
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
            func_02044ac4();
            func_ov006_021e42b4();
            func_ov006_021dacb0();
            self->subState++;
            break;
        case 1:
            func_ov006_021e4348(data_ov006_021ec888);
            if (data_ov006_021ec888->unk8 == 0) {
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
        if (func_ov006_021cd2c8(self) == 0) {
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
    if (data_ov006_021ec888 != NULL && data_ov006_021ec888->unk8 != 0 && data_ov006_021ec888->unk8 != 1) {
        data_02097dd0->unk1F = one;
    }
    return result;
}

void func_ov006_021cd264(ov006_Manager *self) {
    ov006_Task *task = self->task;
    if (task != NULL && task->state >= 3) {
        task->vtbl->unk1C((Object *)task);
    }
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e4574(data_ov006_021ec888);
    }
}

static inline BOOL ov006_Manager_HasUnk14(ov006_Manager *self) {
    return self->unk14 != 0;
}

BOOL func_ov006_021cd2a8(ov006_Manager *self) {
    return ov006_Manager_HasUnk14(self) ? TRUE : FALSE;
}

static inline void ov006_Update021ec888(void) {
    func_ov006_021e4348(data_ov006_021ec888);
    if (data_ov006_021ec888->unk15F != 0) {
        data_ov006_021ec888->unk15F--;
    }
}

}

struct TaskV {
    virtual void v0();
    virtual void v1();
    virtual int unk8();
    virtual int unkC();
    virtual int unk10();
    virtual int unk14();
    virtual int unk18();
    virtual int unk1C();
};
#define ov006_Task_Call(t, fn) (((TaskV *)(t))->fn())

extern "C" {

BOOL func_ov006_021cd2c8(ov006_Manager *self) {
    int zero = 0;
    BOOL result = TRUE;
    ov006_Task *task;
    int type;

    if (self->taskType != 4) {
        OV006_DELETE_OBJECT(self->task);
        type = self->taskType;
        switch (type) {
        case 0:
            task = (ov006_Task *)func_0203dd9c(0x14);
            if (task != NULL) {
                task = func_ov006_021d54b0(task);
            }
            break;
        case 1:
            task = (ov006_Task *)func_0203dd9c(0x88);
            if (task != NULL) {
                task = func_ov006_021d5b04(task);
            }
            break;
        case 2:
            task = (ov006_Task *)func_0203dd9c(0x44);
            if (task != NULL) {
                task = func_ov006_021d908c(task);
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
            if (!ov006_Task_Call(task, unk8)) {
                break;
            }
            task->state = 1;
            task->subState = zero;
        case 1:
            if (!ov006_Task_Call(task, unkC)) {
                break;
            }
            task->state = 2;
            task->subState = zero;
        case 2:
            if (!ov006_Task_Call(task, unk10)) {
                break;
            }
            task->state = 3;
            task->subState = zero;
        case 3:
            if (ov006_Task_Call(task, unk14)) {
                break;
            }
            task->state = 4;
            task->subState = zero;
        case 4:
            if (ov006_Task_Call(task, unk18)) {
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
        if (data_ov006_021ec888->unk8 != 1) {
            func_ov006_021e4c5c(data_ov006_021ec888);
        }
        self->subState++;
    case 1:
        ov006_Update021ec888();
        if (data_ov006_021ec888->unk8 == 1) {
            func_ov006_021e42ec();
            func_ov006_021dae34();
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

void func_ov006_021cd580(int a, int b, int c) {
    data_ov006_021eb6d8[data_ov006_021ec860->unk14](a, b, c);
}

}
