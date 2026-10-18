#include "ov006/Tasks.h"

extern "C" {

extern void *data_ov006_021ebcc0;

void func_ov006_021e309c(Object *a);
void func_02016e28(void *dst, int value, u32 size);

void func_ov006_021cfe84(ov006_TaskCE *self) {
    if (self->unk44 != NULL) {
        VCALL(self->unk44, 20);
    }
    if (self->unk48 != NULL) {
        VCALL(self->unk48, 20);
    }
    if (self->unk4C != NULL) {
        func_ov000_02163594(self->unk4C);
    }
    if (self->unk50 != NULL) {
        VCALL(self->unk50, 20);
    }
    if (self->base.state == 3) {
        func_ov006_021e309c(self->unk54);
    }
}

static inline void ov006_TaskD0_Init(ov006_TaskD0 *self) {
    OV006_TASKBASE_CTOR(&self->base);
    self->base.vtbl = &data_ov006_021ebcc0;
    self->base.state = 0;
    self->base.subState = 0;
    func_02016e28(self->names, 0, sizeof(self->names));
    self->unk104 = NULL;
    self->unk108 = NULL;
    self->unk10C = NULL;
    self->unk110 = 0;
}

ov006_TaskD0 *func_ov006_021cfefc(void) {
    ov006_TaskD0 *self = (ov006_TaskD0 *)func_0203dd9c(sizeof(ov006_TaskD0));
    if (self != NULL) {
        ov006_TaskD0_Init(self);
    }
    VCALL(self, 08, 0x27, 200);
    return self;
}

static inline void ov006_TaskD0_Dtor(ov006_TaskD0 *self) {
    self->base.vtbl = &data_ov006_021ebcc0;
    OV006_DELETE_OBJECT(self->unk104);
    OV006_DELETE_OBJECT(self->unk108);
    OV006_DELETE_OBJECT(self->unk10C);
    OV006_TASKBASE_DTOR(&self->base);
}

ov006_TaskD0 *func_ov006_021cff80(ov006_TaskD0 *self) {
    ov006_TaskD0_Dtor(self);
    return self;
}

ov006_TaskD0 *func_ov006_021d0080(ov006_TaskD0 *self) {
    ov006_TaskD0_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
