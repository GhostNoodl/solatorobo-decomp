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

extern ov006_Net021e5604 *gWhMgr;

BOOL WH_StateInEndScan_020463c8(ov006_Net021e5604 *net);
void WH_CalcBufferSizes_02044a0c(ov006_NetParam021e5604 *param);
BOOL func_020464e0(ov006_Net021e5604 *net, int a, ov006_MenuData *data);
void func_02045094(ov006_Net021e5604 *net);
int Wh_GetError(ov006_Net021e5604 *net);
void ov006_Menu_VBlankB(void);

static inline void ov006_Menu_Advance(ov006_Menu *self) {
    if (self->stateTime < 0xff) {
        self->stateTime++;
    }
}

static inline void ov006_Menu_Error(int code) {
    ov006_Menu *menu = data_ov006_021ec888;
    if (menu->state == 9) {
        return;
    }
    menu->state = 9;
    menu->stateTime = 0;
    menu->unk1C = code;
}

void func_ov006_021e5604(ov006_Menu *self) {
    switch (self->stateTime) {
    case 0:
        gSysState->vblankFunc = NULL;
        if (gWhMgr->state == 3) {
            return;
        }
        if (gWhMgr->state == 2) {
            WH_StateInEndScan_020463c8(gWhMgr);
        }
        self->stateTime = 10;
        return;
    case 10: {
        ov006_Net021e5604 *net = gWhMgr;
        ov006_Menu *menu;
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
        WH_CalcBufferSizes_02044a0c(&net->param);
        MI_CpuFill8(gWhMgr->buf, 0, 0x200);
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
        if (func_020464e0(gWhMgr, 4, &self->unk34)) {
            ov006_Menu_Advance(self);
        } else {
            func_02045094(gWhMgr);
            self->stateTime = 10;
            return;
        }
    case 12:
        if (gWhMgr->state == 5) {
            gSysState->vblankFunc = ov006_Menu_VBlankB;
            self->stateTime = 0x1e;
        } else if (gWhMgr->state == 8) {
            Wh_GetError(gWhMgr);
            ov006_Menu_Error(3);
            return;
        } else if (gWhMgr->state == 7) {
            Wh_GetError(gWhMgr);
            ov006_Menu_Error(3);
            return;
        } else {
            return;
        }
    case 0x1e:
        if (gWhMgr->state == 8) {
            Wh_GetError(gWhMgr);
            ov006_Menu_Error(3);
        }
        if (self->unk18 != 0) {
            return;
        }
        ov006_Menu_Advance(self);
        return;
    case 0x1f:
        if (gWhMgr->state == 8) {
            Wh_GetError(gWhMgr);
            ov006_Menu_Error(4);
        }
        return;
    }
}

}
