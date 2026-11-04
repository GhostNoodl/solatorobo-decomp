#include "ov006/ov006.h"
#include "nitro/mi.h"

typedef struct ov006_NetParam021e51f8 {
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
} ov006_NetParam021e51f8;

typedef struct ov006_Net021e51f8 {
    u8 unk0[4];
    ov006_NetParam021e51f8 param;
    u8 unk1A[0x12];
    int state;
    u8 unk30[2];
    u16 unk32;
    u8 unk34[0x18ac];
    u8 buf[0x200];
} ov006_Net021e51f8;

extern "C" {

extern ov006_Net021e51f8 *gWhMgr;

BOOL WH_StateInEndScan_020463c8(ov006_Net021e51f8 *net);
BOOL Wh_StartMeasureChannel(ov006_Net021e51f8 *net);
int Wh_GetError(ov006_Net021e51f8 *net);
u16 Wh_SelectChannel(ov006_Net021e51f8 *net);
void WH_CalcBufferSizes_02044a0c(ov006_NetParam021e51f8 *param);
void Wh_SetGameInfo(ov006_Net021e51f8 *net, void *data, u32 size);
void Wh_UpdateGameInfo(ov006_Net021e51f8 *net, void *data, u32 size);
BOOL Wh_ParentConnect(ov006_Net021e51f8 *net, int a, u16 tgid, u16 b);
BOOL Wh_SetEntry(ov006_Net021e51f8 *net, BOOL enabled);
u16 WM_GetNextTgid(void);
void ov006_Menu_VBlankA(void);

static inline void ov006_Menu_Advance(ov006_Menu *self) {
    if (self->stateTime < 0xff) {
        self->stateTime++;
    }
}

static inline void ov006_Menu_Error(int code) {
    ov006_Menu *menu = gOv006Menu;
    if (menu->state == 9) {
        return;
    }
    menu->state = 9;
    menu->stateTime = 0;
    menu->unk1C = code;
}

static inline BOOL ov006_Net_StartParent(u16 channel) {
    u16 tgid = WM_GetNextTgid();
    return Wh_ParentConnect(gWhMgr, 3, tgid, channel);
}

static inline BOOL ov006_Menu_HasPeer(ov006_Menu *menu) {
    return menu->unk160 != 0 ? TRUE : FALSE;
}

/* ov006_Menu_SendEntry inlined: set whether the parent accepts entries. */
static inline BOOL ov006_Menu_SetEntry(ov006_Menu *self, u8 enabled) {
    BOOL result;
    self->unk18 = enabled;
    result = Wh_SetEntry(gWhMgr, enabled);
    if (result) {
        if (enabled == 0) {
            self->unk15C = gWhMgr->unk32;
        } else {
            self->unk15C = 0;
        }
    }
    return result;
}

void ov006_Menu_State06(ov006_Menu *self) {
    switch (self->stateTime) {
    case 0:
        gSysState->vblankFunc = NULL;
        if (gWhMgr->state == 3) {
            return;
        }
        if (gWhMgr->state == 2) {
            WH_StateInEndScan_020463c8(gWhMgr);
        }
        ov006_Menu_Advance(self);
        return;
    case 1:
        if (gWhMgr->state != 1) {
            return;
        }
        Wh_StartMeasureChannel(gWhMgr);
        ov006_Menu_Advance(self);
        return;
    case 2: {
        int state = gWhMgr->state;
        if (state == 3) {
            return;
        }
        if (state == 6) {
            self->stateTime = 20;
            return;
        }
        if (state == 8) {
            self->stateTime = 10;
        }
        return;
    }
    case 10: {
        int err = Wh_GetError(gWhMgr);
        if (err == 0x18 || err == 0x16) {
            ov006_Menu_Error(2);
            return;
        }
        if (Wh_GetError(gWhMgr) == 3) {
            self->stateTime = 0;
            return;
        }
        ov006_Menu_Error(2);
        return;
    }
    case 20: {
        ov006_Net021e51f8 *net;
        ov006_Menu *menu;
        int i;
        self->unk15A = Wh_SelectChannel(gWhMgr);
        net = gWhMgr;
        net->param.unk2 = 0x66;
        net->param.unkE = 8;
        net->param.unk4 = 3;
        net->param.unk6 = 0x1c;
        net->param.unk14 = 0;
        net->param.unkA = 0x20;
        net->param.unk8 = 0x74;
        net->param.unkC = 1;
        WH_CalcBufferSizes_02044a0c(&net->param);
        Wh_SetGameInfo(gWhMgr, self->unkF4, 0x66);
        MI_CpuFill8(gWhMgr->buf, 0, 0x200);
        menu = gOv006Menu;
        for (i = 0; i < 4; i++) {
            ov006_MenuEntry *e = &menu->entries[i];
            e->unk0_0 = 0;
            e->unk0_4 = 0;
            MIi_CpuClear16(0, e->unk2, 0x1a);
        }
        ov006_Menu_Advance(self);
        return;
    }
    case 21:
        if (!ov006_Net_StartParent(self->unk15A)) {
            return;
        }
        self->unk10 = 0;
        ov006_Menu_Advance(self);
    case 22: {
        if (gWhMgr->state != 5) {
            return;
        }
        ov006_Menu_SetEntry(gOv006Menu, TRUE);
        gSysState->vblankFunc = ov006_Menu_VBlankA;
        self->stateTime = 0x1e;
        return;
    }
    case 0x1e:
        if (self->unk18 == 0) {
            ov006_Menu_Advance(self);
        } else {
            u8 n = 0;
            u16 mask = gWhMgr->unk32;
            while (mask != 0) {
                n += mask & 1;
                mask >>= 1;
            }
            if (self->unkF4[0x17] != n) {
                self->unkF4[0x17] = n;
                Wh_UpdateGameInfo(gWhMgr, self->unkF4, 0x66);
            }
        }
        return;
    case 0x1f:
        if (!ov006_Menu_HasPeer(gOv006Menu)) {
            ov006_Menu_Error(4);
        }
        if (self->unk15C != gWhMgr->unk32 || gWhMgr->unk32 <= 1) {
            ov006_Menu_Error(4);
        }
        return;
    }
}

}
