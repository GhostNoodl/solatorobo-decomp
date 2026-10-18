#include "ov000/VObj.h"

typedef struct {
    u8 pad_00[0x24];
    s32 unk_24;
    VObj *unk_28;
    void *unk_2c;
    VObj *unk_30;
    void *unk_34;
    void *unk_38;
    void *unk_3c;
    void *unk_40;
    void *unk_44;
    VObj *unk_48;
    u8 pad_4c[4];
    void *unk_50;
    void *unk_54;
    VObj *unk_58;
    VObj *unk_5c;
    VObj *unk_60;
    VObj *unk_64;
    void *unk_68;
    VObj *unk_6c;
    VObj *unk_70;
    VObj *unk_74;
    void *unk_78;
    void *unk_7c;
} Scene02171270;

extern "C" {
void func_ov000_021b9a84(void *p);
void func_ov000_021bac78(void *p);
void func_ov000_021bbbdc(void *p);
void func_0204ffdc(void *p);
void func_ov000_021b8db4(void *p);
void func_ov000_021b86a4(void *p);
void func_ov000_0216d14c(void *p);
void func_ov000_0216df28(void *p);
void func_ov000_0216b880(void *p);
void func_ov000_0216b1b4(void *p);
void func_ov000_0216be94(void *p);

void func_ov000_02171270(Scene02171270 *self) {
    switch (self->unk_24) {
    case 4:
        if (self->unk_28 != NULL) {
            self->unk_28->vfunc_90();
        }
    case 10:
        if (self->unk_3c != NULL) {
            func_ov000_021b9a84(self->unk_3c);
        }
    case 11:
        if (self->unk_48 != NULL) {
            self->unk_48->vfunc_20();
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
    if (self->unk_7c != NULL) {
        func_ov000_0216be94(self->unk_7c);
    }
}
}
