#include "ov000/ObjLayouts.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"

extern "C" {

extern u8 Ov000Vt_021cbac8_vtbl[];
extern u8 Ov000Vt_021cca28_vtbl[];
extern u8 Lo021cca40_vtbl[];
void Heap_Free(void *ptr);

static inline void ListRow_Dtor(ListRow *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cbac8_vtbl);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
}

static inline void Obj02041558_Delete(Model *obj) {
    if (obj != NULL) {
        TexObj_Release(obj);
        PlttRes_Release(&obj->pltt);
        Heap_Free(obj);
    }
}

static inline void DeleteModel(Model **p) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (*p != NULL) {
        Obj02041558_Delete(*p);
        *p = NULL;
    }
    gSysState->cur = saved;
}

static inline void DeleteText(TextWin **p) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (*p != NULL) {
        if (*p != NULL) {
            (*p)->unk_vf04();
        }
        *p = NULL;
    }
    gSysState->cur = saved;
}

ListRowLabel *Ov000Vt_021cca28_DtorDelete(ListRowLabel *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cca28_vtbl);
    DeleteText(&self->text);
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

ListRowLabel *Ov000Vt_021cca28_Dtor(ListRowLabel *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cca28_vtbl);
    DeleteText(&self->text);
    ListRow_Dtor(self);
    return self;
}

Lo021cca40 *Lo021cca40_DtorDelete(Lo021cca40 *self) {
    VOBJ_SET_VTABLE(self, Lo021cca40_vtbl);
    DeleteText(&self->text);
    DeleteModel(&self->unk_34);
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

Lo021cca40 *Lo021cca40_Dtor(Lo021cca40 *self) {
    VOBJ_SET_VTABLE(self, Lo021cca40_vtbl);
    DeleteText(&self->text);
    DeleteModel(&self->unk_34);
    ListRow_Dtor(self);
    return self;
}

}
