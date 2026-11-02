#include "ov000/MessageQueue.h"
#include "Main/Gfx/SlideWin.h"
#include "ov000/ObjLayouts.h"
#include "ov000/LoTimer.h"
#include "ov000/LoTicker.h"

extern "C" {
void func_ov000_021b9a84(void *p);
void func_ov000_021bac78(void *p);
void func_ov000_021bbbdc(void *p);
void func_0204ffdc(void *p);
void func_ov000_021b8db4(void *p);
void func_ov000_021b86a4(void *p);
void func_ov000_0216d14c(void *p);
void func_ov000_0216b880(void *p);
void func_ov000_0216b1b4(void *p);

void func_ov000_02171270(ListBuffer021cb940 *self) {
    switch (self->state) {
    case 4:
        if (self->win != NULL) {
            self->win->Render();
        }
    case 10:
        if (self->unk_3c != NULL) {
            func_ov000_021b9a84(self->unk_3c);
        }
    case 11:
        if (self->dialog != NULL) {
            self->dialog->vfunc_20();
        }
        break;
    case 8:
        if (self->unk_40 != NULL) {
            func_ov000_021bac78(self->unk_40);
        }
        break;
    case 9:
        if (self->unk_44 != NULL) {
            func_ov000_021bbbdc(self->unk_44);
        }
        break;
    case 5:
        if (self->unk_2c != NULL) {
            func_0204ffdc(self->unk_2c);
        }
        break;
    case 6:
        if (self->unk_30 != NULL) {
            self->unk_30->vfunc_20();
        }
        break;
    case 7:
        if (self->unk_38 != NULL) {
            func_ov000_021b8db4(self->unk_38);
        }
        break;
    }
    if (self->unk_34 != NULL) {
        func_ov000_021b86a4(self->unk_34);
    }
    if (self->unk_50 != NULL) {
        func_ov000_0216d14c(self->unk_50);
    }
    if (self->unk_54 != NULL) {
        func_ov000_0216df28(self->unk_54);
    }
    if (self->unk_58 != NULL) {
        self->unk_58->vfunc_10();
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_10();
    }
    if (self->unk_60 != NULL) {
        self->unk_60->vfunc_10();
    }
    if (self->unk_64 != NULL) {
        self->unk_64->vfunc_10();
    }
    if (self->unk_68 != NULL) {
        func_ov000_0216b880(self->unk_68);
    }
    if (self->unk_78 != NULL) {
        func_ov000_0216b1b4(self->unk_78);
    }
    if (self->unk_6c != NULL) {
        self->unk_6c->vfunc_10();
    }
    if (self->unk_70 != NULL) {
        self->unk_70->vfunc_10();
    }
    if (self->unk_74 != NULL) {
        self->unk_74->vfunc_10();
    }
    if (self->ticker != NULL) {
        func_ov000_0216be94(self->ticker);
    }
}
}
