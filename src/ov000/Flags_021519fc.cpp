#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 unk_00;
    u32 unk_04_0 : 4;
    u32 unk_04_4 : 1;
    u32 unk_04_5 : 1;
    u32 unk_04_6 : 1;
    u32 unk_04_7 : 1;
} FlagObj;

typedef struct {
    u32 unk_00;
    s32 state;
} StateObj;

class StateOwner : public VObj {
public:
    u8 unk_04[0x48];
    StateObj *unk_4c;
    StateObj *unk_50;
    u8 unk_54[0x4];
    StateObj *unk_58;
    StateObj *unk_5c;
    StateObj *unk_60;
};

extern "C" {

extern void *gFinishingTask;
extern u32 gLastTaskId;
extern u8 TextWin_vtbl[];
extern u8 Lo021ca9c4_vtbl[];
extern u8 Lo021caa44_vtbl[];
extern u8 Task_vtbl[];
void Heap_Free(void *ptr);

static inline BOOL IsState5(StateObj *obj) {
    return obj->state == 5 ? TRUE : FALSE;
}

static inline void UpdateCurrent(void) {
    if (gFinishingTask != NULL) {
        gLastTaskId = *(u32 *)((u8 *)gFinishingTask + 0x14);
    } else {
        gLastTaskId = 0;
    }
    gFinishingTask = NULL;
}

static inline BOOL FlagObj_TestMask(FlagObj *self, u32 mask) {
    return (((u32 *)self)[1] & mask) ? TRUE : FALSE;
}

static inline bool FlagObj_TestBit6(FlagObj *self) {
    return self->unk_04_6;
}

static inline bool FlagObj_TestBit5(FlagObj *self) {
    return self->unk_04_5;
}

void Task_SetFlag7(FlagObj *self) {
    self->unk_04_7 = 1;
}

void Task_SetCurrent(void *obj) {
    if (gFinishingTask != NULL) {
        gLastTaskId = *(u32 *)((u8 *)gFinishingTask + 0x14);
    } else {
        gLastTaskId = 0;
    }
    gFinishingTask = obj;
}

bool Task_TestFlags(FlagObj *self, u32 mask) {
    return FlagObj_TestMask(self, mask);
}

void Task_ClearFlag7(FlagObj *self) {
    self->unk_04_7 = 0;
}

bool Task_GetFlag6(FlagObj *self) {
    return FlagObj_TestBit6(self) != 0;
}

void Task_SetFlag6(FlagObj *self) {
    self->unk_04_6 = 1;
}

bool Task_GetFlag5(FlagObj *self) {
    return FlagObj_TestBit5(self) != 0;
}

void Task_SetFlag5(FlagObj *self) {
    self->unk_04_5 = 1;
}

void Task_ClearFlag4(FlagObj *self) {
    self->unk_04_4 = 0;
}

void Task_SetFlag4(FlagObj *self) {
    self->unk_04_4 = 1;
}

BOOL Task_IsReady(void) {
    return TRUE;
}

Lo021ca9c4 *Lo021ca9c4_DtorDelete(Lo021ca9c4 *self) {
    VOBJ_SET_VTABLE(self, Lo021ca9c4_vtbl);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(&self->text[5], TextWin_vtbl);
    self->text[5].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[4], TextWin_vtbl);
    self->text[4].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[3], TextWin_vtbl);
    self->text[3].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[2], TextWin_vtbl);
    self->text[2].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[1], TextWin_vtbl);
    self->text[1].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[0], TextWin_vtbl);
    self->text[0].unk_vf08();
    VOBJ_SET_VTABLE(self, Task_vtbl);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

BOOL Lo021ca9c4_TryReleaseCurrent(StateOwner *self) {
    BOOL ok = TRUE;
    if (self->unk_50 != NULL && !IsState5(self->unk_50)) {
        ok = FALSE;
    }
    if (self->unk_4c != NULL && !IsState5(self->unk_4c)) {
        ok = FALSE;
    }
    if (self->unk_58 != NULL && !IsState5(self->unk_58)) {
        ok = FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        UpdateCurrent();
    }
    return TRUE;
}

Lo021ca9c4 *Lo021ca9c4_Dtor(Lo021ca9c4 *self) {
    VOBJ_SET_VTABLE(self, Lo021ca9c4_vtbl);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(&self->text[5], TextWin_vtbl);
    self->text[5].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[4], TextWin_vtbl);
    self->text[4].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[3], TextWin_vtbl);
    self->text[3].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[2], TextWin_vtbl);
    self->text[2].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[1], TextWin_vtbl);
    self->text[1].unk_vf08();
    VOBJ_SET_VTABLE(&self->text[0], TextWin_vtbl);
    self->text[0].unk_vf08();
    VOBJ_SET_VTABLE(self, Task_vtbl);
    self->vfunc_5c();
    return self;
}

VObj *Lo021caa44_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021caa44_vtbl);
    self->vfunc_5c();
    VOBJ_SET_VTABLE(self, Task_vtbl);
    self->vfunc_5c();
    Heap_Free(self);
    return self;
}

BOOL Lo021caa44_TryReleaseCurrent(StateOwner *self) {
    BOOL ok = TRUE;
    if (self->unk_50 != NULL && !IsState5(self->unk_50)) {
        ok = FALSE;
    }
    if (self->unk_4c != NULL && !IsState5(self->unk_4c)) {
        ok = FALSE;
    }
    if (self->unk_5c != NULL && !IsState5(self->unk_5c)) {
        ok = FALSE;
    }
    if (self->unk_60 != NULL && !IsState5(self->unk_60)) {
        ok = FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (self->vfunc_54()) {
        UpdateCurrent();
    }
    return TRUE;
}

}
