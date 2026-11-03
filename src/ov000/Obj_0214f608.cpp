#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
} Sub0214f770;

typedef struct {
    u8 unk_00[0x50];
    Sub0214f770 *unk_50;
    u8 unk_54[0xc];
    Sub0214f770 *unk_60;
} Obj0214f770;

extern "C" {

extern u8 TextWin_vtbl[];
extern u8 Menu021ca94c_vtbl[];
extern u8 Lo021caac8_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 Lo021cb5a8_vtbl[];
void Heap_Free(void *ptr);

VObj *Menu021ca94c_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Menu021ca94c_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x148), TextWin_vtbl);
    VOBJ_AT(self, 0x148)->vfunc_08();
    VOBJ_SET_VTABLE(VOBJ_AT(self, 0x90), TextWin_vtbl);
    VOBJ_AT(self, 0x90)->vfunc_08();
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

VObj *Lo021cb5a8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb5a8_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiList_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

VObj *Lo021caac8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021caac8_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiList021cb4a8_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiList_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

void Lo021caa44_UpdateActive(Obj0214f770 *self) {
    if (self->unk_60 == NULL) {
        return;
    }
    if (self->unk_60->unk_0c & 0x30000) {
        return;
    }
    if (self->unk_50 != NULL) {
        self->unk_50->unk_0c &= ~4;
    }
}

void Lo021caa44_PreUpdate(void) {
}

}
