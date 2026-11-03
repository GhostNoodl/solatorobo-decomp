#include "ov006/ov006.h"
#include "Main/Effect/Effect.h"

typedef struct ov006_Game021d6bc8 {
    u8 unk0[0xf4];
    VObj sub;
} ov006_Game021d6bc8;

typedef struct ov006_Scene021d6bc8 {
    u8 unk0[0x1c];
    void *unk1C;
    void *unk20;
    u8 unk24[4];
    void *unk28;
    void *unk2C;
    void *unk30;
    int unk34;
    u8 unk38[0x35];
    u8 unk6D;
} ov006_Scene021d6bc8;

extern "C" {

extern ov006_Game021d6bc8 *gSceneCmd;
extern void *gFieldMgr;
extern void *gGroup;
extern void *gActorMgr;

u8 ov006_Scene_UpdateFade(ov006_Scene021d6bc8 *self);
void ov006_SyncSlotEntries(void);
void ov006_Unk021de2e0_Update(void *p);
void ov006_Unk021e000c_Update(void *p);
void ov006_Unk021e1af0_Update(void *p);
void ov006_MarkerSet_Update(void *p);
void ov006_Unk021e2878_Update(void *p);
void FieldMgr_Update(void *p);
void func_ov000_0218be54(void *p);
void ActorMgr_Update(void *p);
int ov006_Race_Update(ov006_Scene021d6bc8 *self);
void *ActorMgr_GetGroup(void *mgr, u16 kind);
void func_ov000_0218e0bc(void *p);
void ov006_ComputeRanks(void);
void ov006_BroadcastSlotEntries(u16 a);

int Ov006Vt_021ebfc0_Update(ov006_Scene021d6bc8 *self) {
    int r = 0;
    u8 state = 0;

    if (gOv006Manager->unk1C) {
        state = ov006_Scene_UpdateFade(self);
        if (state == 4) {
            return r;
        }
        if (state == 0 && data_ov006_021ec888->unk15F == 0) {
            return 1;
        }
    }
    if (state == 0) {
        ov006_SyncSlotEntries();
    }
    if (self->unk34 == 0) {
        ov006_Unk021de2e0_Update(self->unk1C);
        if (self->unk20 != NULL) {
            ov006_Unk021e000c_Update(self->unk20);
        }
        ov006_Unk021e1af0_Update(self->unk28);
        ov006_MarkerSet_Update(self->unk2C);
        ov006_Unk021e2878_Update(self->unk30);
        {
            VObj *sub = &gSceneCmd->sub;
            if (sub != NULL) {
                sub->vfunc_00();
            }
        }
        if (gFieldMgr != NULL) {
            FieldMgr_Update(gFieldMgr);
        }
        if (gGroup != NULL) {
            func_ov000_0218be54(gGroup);
        }
        if (gActorMgr != NULL) {
            ActorMgr_Update(gActorMgr);
        }
        EffectMgr_Update(gEffectMgr);
    }
    r = ov006_Race_Update(self);
    if (state == 0 && data_ov006_021ec888->state != 9) {
        void *obj = ActorMgr_GetGroup(gActorMgr, 0x7000);
        if (obj != NULL) {
            func_ov000_0218e0bc(obj);
        }
        ov006_ComputeRanks();
        ov006_BroadcastSlotEntries(self->unk6D);
    }
    return r;
}

}
