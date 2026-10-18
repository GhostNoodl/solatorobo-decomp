#include "ov006/Tasks.h"

extern "C" {

extern void *data_ov006_021ebd40;

void func_ov006_021cf360(ov006_TaskCE *self, u16 a);

static inline void ov006_TaskCE_Init(ov006_TaskCE *self) {
    OV006_TASKBASE_CTOR(&self->base);
    self->base.vtbl = &data_ov006_021ebd40;
    self->base.state = 0;
    self->base.subState = 0;
    self->unk44 = NULL;
    self->unk48 = NULL;
    self->unk4C = NULL;
    self->unk50 = NULL;
    self->unk54 = NULL;
}

ov006_TaskCE *func_ov006_021ce6bc(void) {
    ov006_TaskCE *self = (ov006_TaskCE *)func_0203dd9c(sizeof(ov006_TaskCE));
    if (self != NULL) {
        ov006_TaskCE_Init(self);
    }
    VCALL(self, 08, 0x26, 200);
    return self;
}

static inline void ov006_TaskCE_Open(ov006_TaskCE *self, int id) {
    OV006_DELETE_OBJECT(self->unk4C);
    self->unk4C = ov006_MsgBox_New();
    func_ov000_021632f0(self->unk4C, id, data_ov006_021ebbd1, data_ov006_021ebbde, 1);
    self->unk44->flags |= 4;
    self->unk48->flags |= 2;
}

BOOL func_ov006_021ce734(ov006_TaskOwner *owner, ov006_ListNode *arg) {
    ov006_TaskCE *self = (ov006_TaskCE *)owner->task;
    if (arg != NULL) {
        u16 id;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        id = arg->id;
        if (self->base.state == 3) {
            switch (id) {
            case 0:
                self->base.state = 4;
                self->base.subState = 0;
                break;
            case 1:
                self->base.state = 5;
                self->base.subState = 0;
                break;
            case 2:
                ov006_TaskCE_Open(self, 0);
                break;
            case 3:
                ov006_TaskCE_Open(self, 2);
                break;
            case 4:
                ov006_TaskCE_Open(self, 3);
                break;
            case 5:
                self->base.state = 6;
                self->base.subState = 0;
                break;
            }
        }
    }
    return TRUE;
}

BOOL func_ov006_021ce954(ov006_TaskOwner *owner, ov006_ListNode *arg) {
    ov006_TaskCE *self = (ov006_TaskCE *)owner->task;
    if (arg != NULL) {
        func_ov006_021cf360(self, arg->id);
    }
    return TRUE;
}

static inline void ov006_TaskCE_Dtor(ov006_TaskCE *self) {
    self->base.vtbl = &data_ov006_021ebd40;
    OV006_DELETE_OBJECT(self->unk44);
    OV006_DELETE_OBJECT(self->unk48);
    OV006_DELETE_OBJECT(self->unk4C);
    OV006_DELETE_OBJECT(self->unk50);
    OV006_DELETE_OBJECT(self->unk54);
    OV006_TASKBASE_DTOR(&self->base);
}

ov006_TaskCE *func_ov006_021ce974(ov006_TaskCE *self) {
    ov006_TaskCE_Dtor(self);
    return self;
}

ov006_MsgBox *func_ov006_021cead0(ov006_MsgBox *self) {
    self->vtbl = &data_ov006_021ebc70;
    func_ov000_02163254(self);
    func_0203de1c(self);
    return self;
}

ov006_TaskCE *func_ov006_021ceaf8(ov006_TaskCE *self) {
    ov006_TaskCE_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
