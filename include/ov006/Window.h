#ifndef OV006_WINDOW_H
#define OV006_WINDOW_H

#include "ov006/Model.h"
#include "ov000/TaskList.h"
#include "ov000/ObjLayouts.h"

// The overlay's windows are ov000's UI classes (ov000/UiObj.h, ov000/ObjLayouts.h), typed by the
// vtable their constructor stores: UiList (021caec8), UiList021cb4a8, Lo021cadcc, Lo021cad50,
// Lo021cae48, Lo021cb5a8 and Lo021cb0b8 (and ov006's subclass ov006_ListWin).

// ov000's 0x100-byte list with vtable Ov000Vt_021ccb54_vtbl (Lo021ccb54_ClearLabels clears unk_f4..unk_fc);
// the ov006 menus fill it with LoBase021ccb54_021ccbe0_AppendRow.
struct ov006_HudList : public LoBase021ccb54_021ccbe0 {
    s32 unk_f4;
    s32 unk_f8;
    s32 unk_fc;
};

// ov006's subclass of ov000's list dialog Lo021cb0b8 (vtable ov006_Window_vtbl, 0x1e8 bytes,
// ov006_Window_Ctor; its own slots are in ov006_021e3934.cpp).
struct ov006_ListWin : public Lo021cb0b8 {
    u16 unk_1e4;
};

extern "C" {
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 Ov000Vt_021cb0b8_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 Lo021cb5a8_vtbl[];
extern u8 Lo021cadcc_vtbl[];
extern u8 Lo021cad50_vtbl[];
extern u8 Lo021cae48_vtbl[];
extern u8 Ov000Vt_021ccbe0_vtbl[];
extern u8 Ov000Vt_021ccb54_vtbl[];
void LoBase021ccb54_021ccbe0_CtorBase(LoBase021ccb54_021ccbe0 *self);
void Lo021ccb54_ClearLabels(ov006_HudList *self);

// The ov000 window methods the ov006 menus call (text arguments are message strings).
UiListItem *UiList_GetItemById(UiList *self, u16 id);
void Obj02153c48_CreateText(UiListItem *item, s32 a, BOOL show, BOOL center, u8 d);
void UiList_SetIconModel(UiList *self, const char *file, const char *name, u32 b);
void UiList_SetPanelColor(UiList *self, u32 value);
void UiList021cb4a8_SetLabel(UiList021cb4a8 *self, const void *text);
void UiList021cb4a8_SetCenteredLabel(UiList021cb4a8 *self, const void *text);
void Obj0215bb14_SetText(Lo021cadcc *self, const void *text);
void Obj0215c1bc_SetText(Lo021cad50 *self, u32 flags, const void *text);
void Lo021cae48_SetValue(Lo021cae48 *self, s32 value, BOOL both);
void LoBase021ccb54_021ccbe0_AppendRow(ov006_HudList *self, void *item);
void Obj021c55e8_SetLabel1(ov006_HudList *self, const void *text);
void Obj021c55e8_SetLabel2(ov006_HudList *self, const void *text);
void Obj021c55e8_SetLabel3(ov006_HudList *self, const void *text);
}

// The window constructors, inlined at each use: each class stores its vtable and calls slot 0x28
// (its init), from UiObj down.
static inline UiList *ov006_NewUiList(void) {
    UiList *w = (UiList *)Heap_Alloc(sizeof(UiList));
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = UiList_vtbl;
        w->vfunc_28();
    }
    return w;
}

static inline UiList021cb4a8 *ov006_NewUiList021cb4a8(void) {
    UiList021cb4a8 *w = (UiList021cb4a8 *)Heap_Alloc(sizeof(UiList021cb4a8));
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = UiList_vtbl;
        w->vfunc_28();
        *(void **)w = UiList021cb4a8_vtbl;
        w->vfunc_28();
    }
    return w;
}

static inline Lo021cb5a8 *ov006_NewLo021cb5a8(void) {
    Lo021cb5a8 *w = (Lo021cb5a8 *)Heap_Alloc(sizeof(Lo021cb5a8));
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = UiList_vtbl;
        w->vfunc_28();
        *(void **)w = Lo021cb5a8_vtbl;
        w->vfunc_28();
    }
    return w;
}

static inline Lo021cb0b8 *ov006_NewLo021cb0b8(void) {
    Lo021cb0b8 *w = (Lo021cb0b8 *)Heap_Alloc(sizeof(Lo021cb0b8));
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = UiList_vtbl;
        w->vfunc_28();
        *(void **)w = Ov000Vt_021cb1b0_vtbl;
        w->vfunc_28();
        *(void **)w = Ov000Vt_021cb0b8_vtbl;
        w->vfunc_28();
    }
    return w;
}

static inline Lo021cadcc *ov006_NewLo021cadcc(void) {
    Lo021cadcc *w = (Lo021cadcc *)Heap_Alloc(sizeof(Lo021cadcc));
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = Lo021cadcc_vtbl;
        w->vfunc_28();
    }
    return w;
}

// 0xe8 bytes: Lo021cad50 declares only the members ov000 names (to 0xc8).
static inline Lo021cad50 *ov006_NewLo021cad50(void) {
    Lo021cad50 *w = (Lo021cad50 *)Heap_Alloc(0xe8);
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = Lo021cad50_vtbl;
        w->vfunc_28();
    }
    return w;
}

static inline Lo021cae48 *ov006_NewLo021cae48(void) {
    Lo021cae48 *w = (Lo021cae48 *)Heap_Alloc(sizeof(Lo021cae48));
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = Lo021cae48_vtbl;
        w->vfunc_28();
    }
    return w;
}

static inline ov006_HudList *ov006_NewHudList(void) {
    ov006_HudList *w = (ov006_HudList *)Heap_Alloc(sizeof(ov006_HudList));
    if (w != NULL) {
        *(void **)w = UiObj_vtbl;
        w->vfunc_28();
        *(void **)w = Ov000Vt_021ccbe0_vtbl;
        LoBase021ccb54_021ccbe0_CtorBase(w);
        *(void **)w = Ov000Vt_021ccb54_vtbl;
        Lo021ccb54_ClearLabels(w);
    }
    return w;
}

static inline void ov006_Window_SetPos(UiObj *self, s16 x, s16 y, s16 z) {
    self->posX = x;
    self->posY = y;
    self->posZ = z;
}

static inline void ov006_Window_SetSlide(UiObj *self, int x, int y, int z) {
    self->slideX = x;
    self->slideY = y;
    self->slideZ = z;
}

#define OV006_LISTNODE_SETTEXT(node, str)    \
    do {                                      \
        (node)->name = NULL;                  \
        OV006_DELETE_OBJECT((node)->label);   \
        (node)->name = (str);                 \
    } while (0)

static inline BOOL ov006_Window_IsState5(UiObj *self) {
    return self->state == 5 ? TRUE : FALSE;
}

// The base of the overlay's menu tasks: ov000 Task (vtable Task_vtbl) with a step
// machine (step, subStep: the per-task update switches on them). Tasks that keep their own step
// fields (ov006_TaskD0C, ov006_TaskD37, ov006_TaskCDF) derive from Task directly.
class ov006_TaskBase : public Task {
public:
    int step;
    int subStep;
};

// The Task constructor and destructor bodies, inlined in each task's: store the base vtable and
// call its slot 0x58 (init) or 0x5c (release).
#define OV006_TASKBASE_CTOR(self)                 \
    do {                                          \
        *(void **)(self) = Task_vtbl;   \
        (self)->vfunc_58();                       \
    } while (0)

#define OV006_TASKBASE_DTOR(self)                 \
    do {                                          \
        *(void **)(self) = Task_vtbl;   \
        (self)->vfunc_5c();                       \
    } while (0)

#endif
