#include "ov006/Tasks.h"

extern "C" {

void func_ov006_021e4c5c(ov006_Unk021ec888 *self);
void func_ov006_021cf360(ov006_TaskCE *self, u16 id);

void func_ov006_021cf7c8(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        func_ov006_021e4c5c(data_ov006_021ec888);
        self->base.subState++;
        break;
    case 1:
        if (data_ov006_021ec888->unk8 == 1) {
            self->base.subState++;
        }
        break;
    case 2:
        if (!data_0214a424->unk620_0) {
            data_0214a424->unk620_0 = 1;
            self->base.state = 1;
            self->base.subState = 0;
        } else if (self->unk50 == NULL) {
            self->base.state = 3;
            self->base.subState = 0;
        } else {
            self->base.state = 2;
            self->base.subState = 0;
        }
        self->base.unk20 = self->unk44->unk34;
        break;
    }
}

void func_ov006_021cf89c(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->unk50->flags &= ~2;
        func_02049a48(data_02097e4c, 0x26, -1, -1, -1);
        self->base.subState++;
        break;
    case 1:
        if (!VCALL(self->unk50, 0C)) {
            return;
        }
        if (!(data_02097dc8->unk12 & 1)) {
            return;
        }
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        self->unk50->flags |= 2;
        self->base.subState++;
        break;
    case 2:
        if (!ov006_Window_IsState5(self->unk50)) {
            return;
        }
        ov006_TaskCE_HideMenus(self);
        func_ov006_021cf360(self, ov006_Window_GetSelected(self->unk44)->id);
        self->base.state = 3;
        self->base.subState = 0;
        break;
    }
}

static inline BOOL ov006_Task_IsState2(ov006_Window *self) {
    return self->state == 2;
}

BOOL func_ov006_021cfa60(ov006_Window *self) {
    return ov006_Task_IsState2(self) ? TRUE : FALSE;
}

void func_ov006_021cfa80(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        ov006_TaskCE_HideMenus(self);
        func_ov006_021cf360(self, ov006_Window_GetSelected(self->unk44)->id);
        self->base.subState++;
        break;
    case 1:
        if (self->unk4C != NULL) {
            self->base.subState++;
            return;
        }
        if (!(data_02097dc8->unk12 & 2)) {
            return;
        }
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        {
            ov006_Window *w = self->unk44;
            VCALL(w, A8, func_ov000_02154b58(w, 5));
        }
        break;
    case 2:
        if (func_ov000_021633ac(self->unk4C)) {
            return;
        }
        OV006_DELETE_OBJECT(self->unk4C);
        self->unk44->flags &= ~4;
        self->unk48->flags &= ~2;
        func_ov006_021cf360(self, ov006_Window_GetSelected(self->unk44)->id);
        self->base.subState = 1;
        break;
    }
}

void func_ov006_021cfc60(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        ov006_TaskCE_ShowMenus(self);
        self->base.subState++;
        break;
    case 1:
        if (!ov006_Window_IsState5(self->unk44)) {
            return;
        }
        if (!ov006_Window_IsState5(self->unk48)) {
            return;
        }
        func_ov000_0218084c(data_ov000_021ccd44, 7, 1);
        VCALL(self, 4C);
        self->base.subState++;
        break;
    case 2:
        if (!VCALL(self, 54)) {
            return;
        }
        self->base.flags |= 6;
        self->base.subState++;
        break;
    case 3:
        if (self->base.unk8 != 0) {
            return;
        }
        func_0203cc58(0x14000, 1, 0);
        func_0203cc58(0x14000, 1, 1);
        self->base.subState++;
        break;
    case 4:
        if (!ov006_IsMode4()) {
            return;
        }
        data_ov006_021ec860->taskType = 3;
        self->base.state = 7;
        self->base.subState = 0;
        break;
    }
}

BOOL func_ov006_021cfe08(ov006_TaskCE *self) {
    if (VCALL(self, 54)) {
        ov006_SetCurrent021ccd40(NULL);
    }
    return TRUE;
}

static inline BOOL ov006_IsCurrent(void *p) {
    return data_ov000_021ccd40 == p;
}

BOOL func_ov006_021cfe5c(void *p) {
    return ov006_IsCurrent(p) ? TRUE : FALSE;
}

}
