#include "ov000/VObj.h"
#include "Main/Res/StageVars.h"
#include "ov000/UiObj.h"

extern "C" {

extern u8 Lo021caac8_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 UiList_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 Menu021ca94c_vtbl[];
extern u8 TextWin_vtbl[];
extern void *gSndMgr;

void StageVars_ClearChoice(void);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);

VObj *Lo021caac8_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021caac8_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiList021cb4a8_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiList_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    return self;
}

BOOL UiObj_OnChildDone(void) {
    return TRUE;
}

BOOL UiObj_GetPadLeft(void) {
    return FALSE;
}

VObj *Menu021ca94c_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Menu021ca94c_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x148), TextWin_vtbl);
    VOBJ_AT(self, 0x148)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x90), TextWin_vtbl);
    VOBJ_AT(self, 0x90)->vfunc_08();
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    return self;
}

// A UiItemFn (decide callback of the list UiList_HandleInput opens): item id 0 sets
// data_02fe1534.unk_7c, id 1 clears it, and no item (cancel) only plays the sound.
BOOL UiList_ChoiceOnDecide(UiList *self, UiListItem *item) {
    if (item == NULL) {
        StageVars_ClearChoice();
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        return FALSE;
    }
    if (item->id == 0) {
        data_02fe1534.unk_7c = 1;
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
    } else if (item->id == 1) {
        data_02fe1534.unk_7c = 0;
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    }
    return FALSE;
}

}
