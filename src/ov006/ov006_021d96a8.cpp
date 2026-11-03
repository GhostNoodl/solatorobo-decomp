#include "ov006/Tasks.h"
#include "Main/Sys/Pad.h"


extern "C" {

extern u8 *gWhMgr;
void *Wh_GetSharedData(void *a, int idx);
u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask);
BOOL ov006_Menu_RequestShutdown(ov006_Menu *self);
void ov006_Menu_ShowObj(ov006_Menu *p);
void ov006_Menu_SetOwnEntry(ov006_Menu *self, u16 a, int b, const void *src, u32 size);

static inline BOOL ov006_FadeIdle(void) {
    BOOL r;
    if (gFadeState[3] == 0 && gFadeState[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov006_FadeDone(int ch) {
    BOOL r;
    if (gFadeState[3] == 4) {
        r = TRUE;
    } else {
        r = gFadeState[ch] == 4;
    }
    return r;
}

static inline BOOL ov006_PartIs5(UiObj *p) {
    return p->state == 5;
}

static inline void ov006_HideAll(ov006_Task021ec040 *self) {
    self->unk20->flags |= 2;
    self->unk10->flags |= 2;
    self->unk14->flags |= 2;
    self->unk18->flags |= 2;
    self->unk1C->flags |= 2;
    self->unk24->flags |= 2;
    self->unk28->flags |= 2;
}

BOOL Ov006Vt_021ec040_Update(ov006_Task021ec040 *self) {
    BOOL ret = TRUE;
    BOOL send = FALSE;
    if (gOv006Manager->unk1C != 0 && gOv006Menu->state != 9) {
        send = TRUE;
        Wh_GetSharedData(gWhMgr, 0);
    }
    switch (self->subState) {
    case 0:
        if (!ov006_FadeIdle()) {
            GfxSys_StartFadeIn(0x14000, 0, 0);
            GfxSys_StartFadeIn(0x14000, 0, 1);
        }
        self->subState++;
        break;
    case 1:
        if (ov006_FadeIdle()) {
            self->unk20->flags &= ~2;
            self->unk34 = 0;
            self->subState++;
        }
        break;
    case 2:
        if (self->unk34 >= 0x3c) {
            if (gPad->trig & 1) {
                {
                    StageFlags *g = gStageFlags;
                    if ((g->unk_020 += self->unk38) > 99999) {
                        g->unk_020 = 99999;
                    }
                }
                {
                    u32 n = self->unk38;
                    StageFlags *g = gStageFlags;
                    if (g->unk_00c + n >= 999999) {
                        g->unk_00c = 999999;
                    } else {
                        g->unk_00c = g->unk_00c + n;
                    }
                }
                Lo021cae48_SetValue(self->unk18, 0, 0);
                Lo021cae48_SetValue(self->unk1C, gStageFlags->unk_020, 0);
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
                self->unk34 = 0;
                self->subState++;
            }
        } else {
            self->unk34++;
        }
        break;
    case 3:
        if (self->unk1C->value != self->unk1C->shown || self->unk18->value != self->unk18->shown) {
            if ((gPad->trig & 1) || gOv006Menu->state == 9) {
                Lo021cae48_SetValue(self->unk18, 0, 1);
                Lo021cae48_SetValue(self->unk1C, gStageFlags->unk_020, 1);
            } else {
                if (++self->unk34 % 4 == 0) {
                    SndMgr_PlayVolume(gSndMgr, 0x18, -1, -1, -1);
                }
                break;
            }
        }
        SndMgr_PlayVolume(gSndMgr, 0x4a, -1, -1, -1);
        self->unk34 = 0;
        self->subState++;
        break;
    case 4:
        if (self->unk34 >= 0x14) {
            if (gOv006Menu->state == 9) {
                self->subState = 0x32;
            } else if (gPad->trig & 1) {
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
                self->unk20->flags |= 2;
                self->subState = 10;
            }
        } else {
            self->unk34++;
        }
        break;
    case 10:
        self->unk28->flags &= ~2;
        self->subState++;
        break;
    case 11:
        if (gOv006Menu->state == 9) {
            self->subState = 0x32;
        } else if (ov006_PartIs5(self->unk28)) {
            if (self->unk2C != 0) {
                ov006_HideAll(self);
                if (send) {
                    ov006_Menu_RequestShutdown(gOv006Menu);
                }
                gOv006Manager->unk20 = 1;
                self->subState = 0x1e;
            } else if (!send) {
                ov006_HideAll(self);
                gOv006Manager->unk20 = 2;
                self->subState = 0x1e;
            } else {
                self->subState = 0x14;
            }
        }
        break;
    case 0x14:
        self->unk24->flags &= ~2;
        self->unk24->vfunc_70();
        self->unk30 = (self->unk24->openLen >> 12) + 0x14;
        self->subState++;
    case 0x15:
        if (self->unk30 < 0) {
            self->unk30 = 0;
            self->unk3C = 10;
            self->subState++;
        } else {
            self->unk30--;
            break;
        }
    case 0x16:
        if (gOv006Menu->state == 9) {
            self->subState = 0x32;
        } else if (ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5)->aid == 0) {
            u16 k = *(u16 *)(gWhMgr + 0x32);
            if (k == ov006_Menu_GetEntryMask_021e60e8(10, k)) {
                self->unk3C = 0xb;
                self->subState++;
            }
        } else {
            self->subState++;
        }
        break;
    case 0x17:
        if (gOv006Menu->state == 9) {
            self->subState = 0x32;
        } else if (ov006_Menu_GetEntryMask_021e60e8(0xb, 1) != 0) {
            ov006_HideAll(self);
            gOv006Manager->unk20 = 2;
            self->subState = 0x1e;
        }
        break;
    case 0x1e:
        GfxSys_StartFadeOut(0x14000, 0, 0);
        GfxSys_StartFadeOut(0x14000, 0, 1);
        self->subState++;
    case 0x1f:
        if (gOv006Menu->state == 9) {
            self->subState = 0x32;
        } else if (ov006_FadeDone(0) && ov006_FadeDone(1)) {
            ret = FALSE;
            gOv006Manager->taskType = 0;
        }
        break;
    case 0x32:
        self->unk24->flags |= 2;
        self->unk28->flags |= 2;
        GfxSys_StartFadeIn(0x1000, 0, 0);
        GfxSys_StartFadeIn(0x1000, 0, 1);
        ov006_Menu_ShowObj(gOv006Menu);
        self->subState++;
    case 0x33:
        if (gOv006Menu->state != 9) {
            ov006_HideAll(self);
            GfxSys_StartFadeOut(0x1e000, 0, 0);
            GfxSys_StartFadeOut(0x1e000, 0, 1);
            self->subState++;
        }
        break;
    case 0x34:
        if (ov006_FadeDone(0) && ov006_FadeDone(1)) {
            gOv006Manager->unk20 = 1;
            gOv006Manager->taskType = 0;
        }
        break;
    }
    self->unk10->vfunc_1c();
    self->unk14->vfunc_1c();
    self->unk18->vfunc_1c();
    self->unk1C->vfunc_1c();
    self->unk20->vfunc_1c();
    self->unk28->vfunc_1c();
    self->unk24->vfunc_1c();
    if (send) {
        ov006_Menu_SetOwnEntry(gOv006Menu, self->unk3C, 2, self->unk3E, 4);
    }
    return ret;
}

}
