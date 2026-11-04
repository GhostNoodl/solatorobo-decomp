#include "ov006/Tasks.h"
#include "nitro/fx.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *gWhMgr;

void ov006_Slot_Pack(const ov006_Slot *self, ov006_SlotPacked *buf);
void ov006_Menu_SetOwnEntry(ov006_Menu *self, u16 a, int b, const void *src, u32 size);
void ModelViewer_Update(ov006_Actor58 *self);
void ModelViewer_Draw(ov006_Actor58 *self);
void ov006_Caption_Update(ov006_Caption *self);
void ov006_Caption_DrawText(ov006_Caption *self);
void ov006_Gauge_Update(ov006_Gauge *self);
void ov006_Gauge_Draw(ov006_Gauge *self);
void ov006_Menu_ReleaseObj(ov006_Menu *self);
void ov006_Manager_DispatchMenuCb(int a, int b, int c);
void ov006_CraftSelect_Step01(ov006_TaskD1F *self);
void ov006_CraftSelect_Step02(ov006_TaskD1F *self);
void ov006_CraftSelect_Step03(ov006_TaskD1F *self);
void ov006_UpdateNetSlots(void);
u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask);
void ov006_Menu_ShowObj(ov006_Menu *self);

static inline void ov006_TaskD1F_Finish(ov006_TaskD1F *self) {
    self->unk54->flags |= 2;
    self->unk5C->flags |= 2;
    self->unk60->flags |= 2;
    self->unk64->flags |= 2;
    self->unk58->unk6B8 = 0x28;
    if (self->unk68->visible == 1) {
        self->unk68->visible = 2;
    }
    self->unk_04 |= 6;
}

static inline void ov006_TaskD1F_Exit(ov006_TaskD1F *self, int a) {
    ov006_TaskD1F_Finish(self);
    ov006_Manager_DispatchMenuCb(4, a, self->param);
    self->step = 6;
    self->subStep = 0;
}

void ov006_CraftSelect_PostUpdate(ov006_TaskD1F *self) {
    if (self->step != 3 && gOv006Menu->state == 9) {
        self->step = 3;
        self->subStep = 0;
        return;
    }
    switch (self->step) {
    case 0:
        break;
    case 1:
        ov006_CraftSelect_Step01(self);
        break;
    case 2:
        ov006_CraftSelect_Step02(self);
        break;
    case 3:
        ov006_CraftSelect_Step03(self);
        break;
    case 4:
        ov006_TaskD1F_Exit(self, 1);
        break;
    case 5:
        ov006_TaskD1F_Exit(self, 0);
        break;
    case 6:
        break;
    }
}

void ov006_CraftSelect_Step01(ov006_TaskD1F *self) {
    switch (self->subStep) {
    case 0:
        self->unk54->flags |= 4;
        self->unk60->flags &= ~2;
        {
            Lo021cb0b8 *w = self->unk60;
            w->vfunc_a8(UiList_GetItemById(w, 1));
        }
        self->subStep++;
        break;
    case 1:
        if (!ov006_Window_IsState5(self->unk60)) {
            return;
        }
        if (self->unk4C == 0) {
            if (self->param == 0) {
                self->step = 4;
                self->subStep = 0;
            } else {
                self->step = 2;
                self->subStep = 0;
            }
        } else {
            self->step = 0;
            self->subStep = 0;
            self->unk54->flags &= ~4;
        }
        break;
    }
}

static inline BOOL ov006_IsReady(int type) {
    BOOL r = TRUE;
    if (!ov006_Menu_GetEntryMask_021e60e8(type, 1)) {
        r = FALSE;
    }
    return r;
}

void ov006_CraftSelect_Step02(ov006_TaskD1F *self) {
    switch (self->subStep) {
    case 0:
        self->unk64->flags &= ~2;
        self->unk64->vfunc_70();
        self->unk50 = (self->unk64->openLen >> 12) + 20;
        self->subStep++;
    case 1:
        if (self->unk50 < 0) {
            self->unk50 = 0;
            self->unk49 = 2;
            self->subStep++;
        } else {
            self->unk50--;
            return;
        }
    case 2:
        ov006_UpdateNetSlots();
        if (self->param == 1) {
            BOOL r = ov006_IsReady(3);
            if (!r) {
                u16 v = gWhMgr->unk32;
                if (v == ov006_Menu_GetEntryMask_021e60e8(2, v)) {
                    self->unk49 = 3;
                }
            }
            if (r) {
                self->step = 4;
                self->subStep = 0;
            }
        } else if (self->param == 2) {
            if (ov006_IsReady(3)) {
                self->step = 4;
                self->subStep = 0;
            }
        } else {
            self->step = 4;
            self->subStep = 0;
        }
        break;
    }
}

void ov006_CraftSelect_Step03(ov006_TaskD1F *self) {
    switch (self->subStep) {
    case 0:
        self->unk54->flags |= 4;
        self->unk5C->flags |= 4;
        self->unk60->flags |= 4;
        self->unk64->flags |= 2;
        self->unk60->flags |= 2;
        ov006_Menu_ShowObj(gOv006Menu);
        self->subStep++;
    case 1:
        if (gOv006Menu->state == 9) {
            return;
        }
        GfxSys_StartFadeOut(0x1e000, 0, 0);
        GfxSys_StartFadeOut(0x1e000, 0, 1);
        self->subStep++;
        break;
    case 2:
        if (!ov006_IsMode4()) {
            return;
        }
        if (!ov006_IsMode4b()) {
            return;
        }
        ov006_TaskD1F_Finish(self);
        TaskHost_RequestSwitch(gTaskHost, 0x26, 0);
        self->step = 6;
        self->subStep = 0;
        break;
    }
}

void ov006_CraftSelect_Draw(ov006_TaskD1F *self) {
    int i;
    if (!self->vfunc_28()) {
        return;
    }
    self->unk54->vfunc_20();
    ModelViewer_Draw(self->unk58);
    self->unk5C->vfunc_20();
    self->unk60->vfunc_20();
    self->unk64->vfunc_20();
    ov006_Caption_DrawText(self->unk68);
    for (i = 0; i < 4; i++) {
        ov006_Gauge_Draw(self->gauges[i]);
    }
    if (gOv006Menu != NULL) {
        ov006_Menu_ReleaseObj(gOv006Menu);
    }
}

}
