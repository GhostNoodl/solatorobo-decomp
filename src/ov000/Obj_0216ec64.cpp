#include "ov000/VObj.h"
#include "Main/Gfx/PlttRes.h"

typedef struct {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    s32 unk_0c;
} Data02097d78;

typedef struct {
    void *vtbl;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void (*unk_10)(void *self);
    void (*unk_14)(void *self);
    u32 unk_18;
    u32 unk_1c;
} Buffer0216f144;

extern "C" {

extern u8 Lo021cb6f0_vtbl[];
extern u8 Lo021cb744_vtbl[];
extern u8 Lo021cb798_vtbl[];
extern u8 Lo021cb7ec_vtbl[];
extern u8 Lo021cb840_vtbl[];
extern u8 Lo021cb894_vtbl[];
extern u8 Ov000Vt_021cac0c_vtbl[];
extern u8 Lo021cb6b0_vtbl[];
extern u8 Ov000Vt_021cb6d0_vtbl[];
extern Data02097d78 gFadeState;

void Heap_Free(void *ptr);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);
void func_ov000_02164420(void *self);
void Buffer0216f144_Free(Buffer0216f144 *self);

VObj *Lo021cb744_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb744_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

BOOL Lo021cb744_IsLoaded(void) {
    return TRUE;
}

void Lo021cb744_Load(void) {
}

VObj *Lo021cb744_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb744_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    return self;
}

VObj *Lo021cb798_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb798_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

BOOL Lo021cb798_IsLoaded(void) {
    return TRUE;
}

void Lo021cb798_Load(void) {
}

VObj *Lo021cb798_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb798_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    return self;
}

VObj *Lo021cb7ec_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb7ec_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

BOOL Lo021cb7ec_IsLoaded(void) {
    return TRUE;
}

void Lo021cb7ec_Load(void) {
}

VObj *Lo021cb7ec_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb7ec_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    return self;
}

VObj *Lo021cb840_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb840_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

BOOL Lo021cb840_IsLoaded(void) {
    return TRUE;
}

void Lo021cb840_Load(void) {
}

VObj *Lo021cb840_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb840_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    return self;
}

VObj *Lo021cb894_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb894_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

BOOL Lo021cb894_IsLoaded(void) {
    return TRUE;
}

void Lo021cb894_Load(void) {
}

VObj *Lo021cb894_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb894_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    return self;
}

VObj *Lo021cb6f0_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb6f0_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

BOOL Lo021cb6f0_IsLoaded(void) {
    return TRUE;
}

void Lo021cb6f0_Load(void) {
}

VObj *Lo021cb6f0_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cb6f0_vtbl);
    self->vfunc_18();
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    return self;
}

BOOL func_ov000_0216f00c(void) {
    return FALSE;
}

Buffer0216f144 *Lo021cb6b0_DtorDelete(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, Lo021cb6b0_vtbl);
    func_ov000_02164420(self);
    VOBJ_SET_VTABLE(self, Ov000Vt_021cb6d0_vtbl);
    Buffer0216f144_Free(self);
    Heap_Free(self);
    return self;
}

Buffer0216f144 *Lo021cb6b0_Dtor(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, Lo021cb6b0_vtbl);
    func_ov000_02164420(self);
    VOBJ_SET_VTABLE(self, Ov000Vt_021cb6d0_vtbl);
    Buffer0216f144_Free(self);
    return self;
}

Buffer0216f144 *Ov000Vt_021cb6d0_DtorDelete(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cb6d0_vtbl);
    Buffer0216f144_Free(self);
    Heap_Free(self);
    return self;
}

void func_ov000_0216f0ac(Buffer0216f144 *self) {
    if (self->unk_14 != NULL) {
        self->unk_14(self);
    }
}

void func_ov000_0216f0c4(Buffer0216f144 *self) {
    if (self->unk_10 != NULL) {
        self->unk_10(self);
    }
}

static inline BOOL func_0216f0dc_Check(void) {
    if (gFadeState.unk_0c == 4) {
        return TRUE;
    }
    return gFadeState.unk_04 == 4;
}

void func_ov000_0216f0dc(void) {
    if (func_0216f0dc_Check()) {
        GfxSys_StartFadeIn(0xa000, 0, 1);
    }
}

Buffer0216f144 *Ov000Vt_021cb6d0_Dtor(Buffer0216f144 *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cb6d0_vtbl);
    Buffer0216f144_Free(self);
    return self;
}

void Buffer0216f144_Init(Buffer0216f144 *self) {
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

void Buffer0216f144_Free(Buffer0216f144 *self) {
    if ((self->unk_04 & 0x20) && self->unk_0c != NULL) {
        Heap_FreeHi(self->unk_0c);
    }
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

}
