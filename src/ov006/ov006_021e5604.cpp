#include "ov006/ov006.h"
#include "nitro/mi.h"

typedef struct ov006_NetParam021e5604 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
} ov006_NetParam021e5604;

typedef struct ov006_Net021e5604 {
    u8 unk0[4];
    ov006_NetParam021e5604 param;
    u8 unk1A[0x12];
    int state;
    u8 unk30[0x18b0];
    u8 buf[0x200];
} ov006_Net021e5604;

extern "C" {

extern ov006_Net021e5604 *data_02097e40;

BOOL func_020463c8(ov006_Net021e5604 *net);
void func_02044a0c(ov006_NetParam021e5604 *param);
BOOL func_020464e0(ov006_Net021e5604 *net, int a, ov006_MenuData *data);
void func_02045094(ov006_Net021e5604 *net);
int func_02046abc(ov006_Net021e5604 *net);
void func_ov006_021e5fec(void);

static inline void ov006_Menu_Advance(ov006_Unk021ec888 *self) {
    if (self->unkC < 0xff) {
        self->unkC++;
    }
}

static inline void ov006_Menu_Error(int code) {
    ov006_Unk021ec888 *menu = data_ov006_021ec888;
    if (menu->unk8 == 9) {
        return;
    }
    menu->unk8 = 9;
    menu->unkC = 0;
    menu->unk1C = code;
}

void func_ov006_021e5604(ov006_Unk021ec888 *self) {
    switch (self->unkC) {
    case 0:
        data_02097dd0->unk18 = 0;
        if (data_02097e40->state == 3) {
            return;
        }
        if (data_02097e40->state == 2) {
            func_020463c8(data_02097e40);
        }
        self->unkC = 10;
        return;
    case 10: {
        ov006_Net021e5604 *net = data_02097e40;
        ov006_Unk021ec888 *menu;
        int i;
        if (net->state != 1) {
            return;
        }
        net->param.unk2 = 0x66;
        net->param.unkE = 8;
        net->param.unk4 = 3;
        net->param.unk6 = 0x1c;
        net->param.unk14 = 0;
        net->param.unkA = 0x20;
        net->param.unk8 = 0x74;
        net->param.unkC = 1;
        func_02044a0c(&net->param);
        MI_CpuFill8(data_02097e40->buf, 0, 0x200);
        menu = data_ov006_021ec888;
        for (i = 0; i < 4; i++) {
            ov006_MenuEntry *e = &menu->entries[i];
            e->unk0_0 = 0;
            e->unk0_4 = 0;
            MIi_CpuClear16(0, e->unk2, 0x1a);
        }
        ov006_Menu_Advance(self);
        return;
    }
    case 11:
        if (func_020464e0(data_02097e40, 4, &self->unk34)) {
            ov006_Menu_Advance(self);
        } else {
            func_02045094(data_02097e40);
            self->unkC = 10;
            return;
        }
    case 12:
        if (data_02097e40->state == 5) {
            data_02097dd0->unk18 = (int)func_ov006_021e5fec;
            self->unkC = 0x1e;
        } else if (data_02097e40->state == 8) {
            func_02046abc(data_02097e40);
            ov006_Menu_Error(3);
            return;
        } else if (data_02097e40->state == 7) {
            func_02046abc(data_02097e40);
            ov006_Menu_Error(3);
            return;
        } else {
            return;
        }
    case 0x1e:
        if (data_02097e40->state == 8) {
            func_02046abc(data_02097e40);
            ov006_Menu_Error(3);
        }
        if (self->unk18 != 0) {
            return;
        }
        ov006_Menu_Advance(self);
        return;
    case 0x1f:
        if (data_02097e40->state == 8) {
            func_02046abc(data_02097e40);
            ov006_Menu_Error(4);
        }
        return;
    }
}

}
