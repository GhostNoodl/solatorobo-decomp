#include "ov000/ObjLayouts.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"

extern "C" {

extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cca28[];
extern u8 data_ov000_021cca40[];
void Heap_Free(void *ptr);

static inline void ListRow_Dtor(ListRow *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
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
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*p != NULL) {
        Obj02041558_Delete(*p);
        *p = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void DeleteText(TextWin **p) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*p != NULL) {
        if (*p != NULL) {
            (*p)->unk_vf04();
        }
        *p = NULL;
    }
    data_02097dd0->cur = saved;
}

ListRowLabel *Ov000Vt_021cca28_DtorDelete(ListRowLabel *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca28);
    DeleteText(&self->text);
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

ListRowLabel *Ov000Vt_021cca28_Dtor(ListRowLabel *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca28);
    DeleteText(&self->text);
    ListRow_Dtor(self);
    return self;
}

Lo021cca40 *Lo021cca40_DtorDelete(Lo021cca40 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca40);
    DeleteText(&self->text);
    DeleteModel(&self->unk_34);
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

Lo021cca40 *Lo021cca40_Dtor(Lo021cca40 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca40);
    DeleteText(&self->text);
    DeleteModel(&self->unk_34);
    ListRow_Dtor(self);
    return self;
}

}
