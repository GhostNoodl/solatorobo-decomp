#include "ov006/Tasks.h"
#include "nitro/fx.h"
#include "Main/Net/Wh.h"


extern "C" {


void ov006_Slot_Pack(ov006_Slot *self, void *buf);
void ov006_Menu_SetOwnEntry(ov006_Menu *self, u16 a, int b, const void *src, u32 size);
void ModelViewer_Update(ov006_Actor58 *self);
void ModelViewer_Draw(ov006_Actor58 *self);
void ov006_Caption_Update(ov006_Caption *self);
void func_ov006_021e0b80(ov006_Caption *self);
void ov006_Gauge_Update(ov006_Gauge *self);
void ov006_Gauge_Draw(ov006_Gauge *self);
void ov006_Menu_ReleaseObj(ov006_Menu *self);
void ov006_Manager_DispatchMenuCb(int a, int b, int c);
void func_ov006_021d2ff0(ov006_TaskD1F *self);
void func_ov006_021d30d4(ov006_TaskD1F *self);
void func_ov006_021d3224(ov006_TaskD1F *self);
void ov006_UpdateNetSlots(void);
u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask);
void ov006_Menu_ShowObj(ov006_Menu *self);

void ov006_TaskD1F_UpdateActive(ov006_TaskD1F *self) {
    u16 trg;
    if (self->step != 0) {
        return;
    }
    trg = gPad->trig;
    if (trg & 2) {
        if (self->unk48) {
            if (self->param == 0) {
                SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
            }
            self->step = 5;
            self->subStep = 0;
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
        }
        return;
    }
    if (!(trg & 1)) {
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
    self->step = 1;
    self->subStep = 0;
}

static inline void ov006_Actor58_SetPos(ov006_Actor58 *self, s32 x, s32 y, s32 z) {
    self->pos.x = x;
    self->pos.y = y;
    self->pos.z = z;
}

static inline void ov006_Actor58_SetRot(ov006_Actor58 *self, s16 x, s16 y, s16 z) {
    self->rot.x = x;
    self->rot.y = y;
    self->rot.z = z;
}

void ov006_TaskD1F_PreUpdate(ov006_TaskD1F *self) {
    u8 buf[0x18];
    int i;
    if (self->state == 0xd) {
        if (self->param != 0) {
            ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5)->unkC = self->unk4A;
            ov006_Slot_Pack(ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5), buf);
            ov006_Menu_SetOwnEntry(data_ov006_021ec888, self->unk49, 1, buf, 0x18);
        } else {
            ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5)->unkC = self->unk4A;
        }
    }
    self->unk54->vfunc_1c();
    ModelViewer_Update(self->unk58);
    {
        ov006_Actor58 *a = self->unk58;
        // x is read through a const view, so it is not merged with the earlier read of a->pos.
        ov006_Actor58_SetPos(a, ((const ov006_Actor58 *)a)->pos.x, FX_Mul(FX_SinCosTable_[((u16)(self->unk44 << 8) >> 4) * 2], 0x4cd), a->pos.z);
    }
    ov006_Actor58_SetRot(self->unk58, 0, self->unk44 * 0x90, 0);
    self->unk44 = (u16)(self->unk44 + 1);
    if (self->unk58->unk6B8 / 10 == 1) {
        self->unk44 = 0;
    }
    self->unk5C->vfunc_1c();
    self->unk60->vfunc_1c();
    self->unk64->vfunc_1c();
    ov006_Caption_Update(self->unk68);
    for (i = 0; i < 4; i++) {
        ov006_Gauge_Update(self->gauges[i]);
    }
}

}
