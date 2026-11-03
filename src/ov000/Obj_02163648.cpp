#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"

typedef struct {
    u32 unk_00;
    u32 unk_04_0 : 6;
    u32 unk_04_6 : 1;
    u32 unk_04_7 : 25;
    u8 unk_08[0x64];
    void *unk_6c;
    u8 unk_70[0x18];
    u8 unk_88[0xd8];
} Model;

typedef struct {
    u32 unk_00;
    u32 unk_04;
} Sub02163b58;

class Obj02163648 : public VObj {
public:
    u8 unk_04[0xc];
    void *unk_10;
    s32 unk_14_pad[3];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x5c];
    Model *unk_84;
    u8 unk_88[0x8];
    void *unk_90;
    Model *unk_94;
    u8 unk_98[0x3c];
    Model *unk_d4;
};

extern "C" BOOL Vram_IsTransferDone(void *a);

static inline BOOL Model_IsIdle(Model *model) {
    if (model->unk_6c == NULL) {
        return TRUE;
    }
    if (Vram_IsTransferDone(model->unk_6c)) {
        model->unk_6c = NULL;
    } else {
        return !model->unk_04_6;
    }
    return TRUE;
}

extern "C" {

extern u8 data_ov000_021cac0c[];
extern u8 data_ov000_021cad50[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cafc0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb3a8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];

void Heap_Free(void *ptr);
void TexObj_Release(Model *model);
void PlttRes_Release(void *a);
s32 UiList_IsLoaded(Obj02163648 *self);
BOOL Model_IsReady(void *a, u32 b);

Obj02163648 *Lo021cacd8_Dtor(Obj02163648 *self) {
    void *saved;
    Model *model;
    VOBJ_SET_VTABLE(self, data_ov000_021cacd8);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    model = self->unk_84;
    if (model != NULL) {
        if (model != NULL) {
            TexObj_Release(model);
            PlttRes_Release(model->unk_88);
            Heap_Free(model);
        }
        self->unk_84 = NULL;
    }
    data_02097dd0->cur = saved;
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Ov000Vt_021cac0c_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

static inline BOOL IsState10(void *self) {
    return *(s32 *)((u8 *)self + 4) == 10 ? TRUE : FALSE;
}

bool Ov000Vt_021cac0c_IsShown(void *self) {
    return IsState10(self);
}

VObj *Ov000Vt_021cac0c_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

s32 LoBase021cafc0_021cb0b8_GetLineSpacing(void) {
    return 0x4;
}

s32 LoBase021cafc0_021cb0b8_GetPadBottom(void) {
    return 0x4;
}

s32 LoBase021cafc0_021cb0b8_IsLoaded(Obj02163648 *self) {
    s32 ret = UiList_IsLoaded(self);
    Model *model = self->unk_d4;
    if (model != NULL && !Model_IsIdle(model)) {
        ret = 0;
    }
    return ret;
}

VObj *Ov000Vt_021cafc0_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cafc0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

VObj *Ov000Vt_021cafc0_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cafc0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Ov000Vt_021cb0b8_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Lo021cae48_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cae48);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

s32 func_ov000_021639c8(void) {
    return 0x10;
}

BOOL Lo021cae48_IsLoaded(Obj02163648 *self) {
    BOOL ret = TRUE;
    Model *model;
    if (self->unk_10 != NULL && !Model_IsReady(self->unk_10, 0xffff)) {
        ret = FALSE;
    }
    if (self->unk_90 != NULL && !Model_IsReady(self->unk_90, 0xffff)) {
        ret = FALSE;
    }
    model = self->unk_94;
    if (model != NULL && !Model_IsIdle(model)) {
        ret = FALSE;
    }
    return ret;
}

VObj *Lo021cae48_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cae48);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

s32 Lo021cad50_GetLineSpacing(void) {
    return 0x2;
}

VObj *Lo021cad50_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cad50);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Lo021cadcc_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cadcc);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

s32 Lo021cadcc_GetPadBottom(void) {
    return 0x3;
}

void func_ov000_02163b58(Obj02163648 *self) {
    ((Sub02163b58 *)self->unk_84)->unk_04 |= 4;
}

VObj *Lo021cadcc_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cadcc);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Ov000Vt_021cb1b0_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

VObj *Ov000Vt_021cb1b0_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

s32 Lo021cb5a8_GetLineSpacing(void) {
    return 0x4;
}

s32 Lo021cb5a8_GetPadBottom(void) {
    return 0x1;
}

VObj *Lo021cb5a8_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb5a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Lo021cb3a8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb3a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

s32 Lo021cb3a8_GetHeight(Obj02163648 *self) {
    s32 a = self->vfunc_40() * self->unk_20;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 Lo021cb3a8_GetLineSpacing(void) {
    return 0x4;
}

s32 Lo021cb3a8_GetPadBottom(void) {
    return 0x5;
}

s32 func_ov000_02163dc8(Obj02163648 *self) {
    return (s32)(((s64)(self->unk_24 << 12) * 0xe7a + 0x800) >> 12) >> 12;
}

VObj *Lo021cb3a8_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb3a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *UiList021cb4a8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

VObj *UiList021cb4a8_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *UiList_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

s32 UiList_GetLineSpacing(void) {
    return 0x4;
}

VObj *UiList_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *UiObj_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

void UiObj_Setup(void) {
}

VObj *UiObj_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Ov000Vt_021cb2a8_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Ov000Vt_021cb2a8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb4a8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

}
