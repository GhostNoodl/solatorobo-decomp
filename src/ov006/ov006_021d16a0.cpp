#include "ov006/Tasks.h"

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021ccd34;

u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021e4bec(ov006_Unk021ec888 *self, int a);
void func_ov006_021e4c5c(ov006_Unk021ec888 *self);
void func_ov006_021e5e00(ov006_Unk021ec888 *self);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(ov006_Window *w, int a, void *str);

static inline void ov006_TaskD0C_ShowAll(ov006_TaskD0C *self) {
    self->unk11C->flags &= ~0x2000000;
    self->unk11C->flags |= 2;
    self->unk120->flags |= 2;
    self->unk124->flags |= 2;
}

static inline u8 ov006_SlotManager_MinUnk10(void) {
    u8 i;
    u8 mn;
    mn = 0;
    for (i = 0; i < data_ov006_021ec884->numActive; i++) {
        ov006_Slot *slot = func_ov006_021db060(data_ov006_021ec884, i);
        u8 v;
        if (slot == NULL) {
            continue;
        }
        v = slot->unk10;
        if (v == 0) {
            continue;
        }
        if (mn == 0 || mn > v) {
            mn = v;
        }
    }
    return mn;
}

// The original reloads data_ov006_021ec884 after every block, so this function is built without CSE
#pragma opt_common_subs off
void func_ov006_021d16a0(ov006_TaskD0C *self) {
    switch (self->unk3C) {
    case 0:
        if (data_ov006_021ec888->unk8 == 9) {
            data_ov000_021ccd34 = 1;
            self->unk11C->flags |= 4;
            self->unk120->flags |= 4;
            self->unk3C = 30;
        }
        if (self->unkC != 2) {
            return;
        }
        if (!func_ov006_021e60e8(1, 1)) {
            return;
        }
        self->unk3C = 5;
    case 5:
        self->unk101 = 1;
        func_ov006_021e4bec(data_ov006_021ec888, 0);
        self->unk3C = 10;
        ov006_TaskD0C_ShowAll(self);
        break;
    case 10: {
        u8 mn = ov006_SlotManager_MinUnk10();
        if (mn == 0) {
            self->unk3C = 20;
            return;
        }
        if (mn == 1) {
            data_ov006_021ec884->unk14A[0] = 9;
        } else if (mn == 2) {
            data_ov006_021ec884->unk14A[0] = 10;
            func_ov000_0215c1bc(self->unk124, 0x8000, func_0204c0e8(data_02149ef8, 0x199));
        }
        VCALL(self->unk124, 70);
        self->unk124->flags &= ~2;
        *(u16 *)self->unk3E = 0;
        func_02049a48(data_02097e4c, 0x26, -1, -1, -1);
        self->unk3C++;
        break;
    }
    case 11:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk124->flags |= 2;
            self->unk3C = 30;
            return;
        }
        if ((*(u16 *)self->unk3E)++ > 0xb4) {
            self->unk3C = 20;
        }
        break;
    case 20:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk3C = 30;
            return;
        }
        if (!VCALL(self, 54)) {
            return;
        }
        func_0203cc58(0x14000, 0, 0);
        func_0203cc58(0x14000, 0, 1);
        *(int *)&self->unk10[0x10] = 0x50000;
        self->unk3C = 60;
        break;
    case 30:
        func_ov006_021e5e00(data_ov006_021ec888);
        self->unk3C++;
    case 31:
        if (data_ov006_021ec888->unk8 != 9) {
            self->unk3C = 50;
        }
        break;
    case 50:
        ov006_TaskD0C_ShowAll(self);
        self->flags |= 6;
        func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
        func_ov006_021e4c5c(data_ov006_021ec888);
        self->unk3C = 70;
        break;
    case 60:
        ov006_TaskD0C_ShowAll(self);
        self->flags |= 6;
        func_ov000_0218084c(data_ov000_021ccd44, 0x29, self->unkC);
        self->unk3C = 70;
        break;
    }
}

#pragma opt_common_subs reset
}
