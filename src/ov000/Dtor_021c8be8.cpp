#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "ov000/HeapScope.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ListRow.h"

extern "C" {

extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cca58[];
extern u8 data_ov000_021cca70[];
extern u8 data_ov000_021cc9f8[];
extern u8 data_ov000_021cca10[];
void Heap_Free(void *ptr);
void ListRow021cca70_Release(ListRow021cca70 *self);
void Hud021cca10_Release(Hud021cca10 *self);

static inline void ListRow_Dtor(ListRow *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
}

ListRowText *Ov000Vt_021cca58_DtorDelete(ListRowText *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca58);
    HEAP_DELETE_VOBJ(self->win);
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

ListRowText *Ov000Vt_021cca58_Dtor(ListRowText *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca58);
    HEAP_DELETE_VOBJ(self->win);
    ListRow_Dtor(self);
    return self;
}

ListRow021cca70 *Ov000Vt_021cca70_DtorDelete(ListRow021cca70 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca70);
    ListRow021cca70_Release(self);
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

ListRow021cca70 *Ov000Vt_021cca70_Dtor(ListRow021cca70 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca70);
    ListRow021cca70_Release(self);
    ListRow_Dtor(self);
    return self;
}

ListRowGauge *Ov000Vt_021cc9f8_DtorDelete(ListRowGauge *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc9f8);
    HEAP_DELETE_VOBJ(self->bar);
    HEAP_DELETE(TextWin *, self->label, p->unk_vf04());
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

ListRowGauge *Ov000Vt_021cc9f8_Dtor(ListRowGauge *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc9f8);
    HEAP_DELETE_VOBJ(self->bar);
    HEAP_DELETE(TextWin *, self->label, p->unk_vf04());
    ListRow_Dtor(self);
    return self;
}

Hud021cca10 *Hud021cca10_DtorDelete(Hud021cca10 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca10);
    Hud021cca10_Release(self);
    ListRow_Dtor(self);
    Heap_Free(self);
    return self;
}

Hud021cca10 *Hud021cca10_Dtor(Hud021cca10 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca10);
    Hud021cca10_Release(self);
    ListRow_Dtor(self);
    return self;
}

}
