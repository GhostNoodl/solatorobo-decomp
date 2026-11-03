#include "ov006/ov006.h"

extern "C" {

extern void *Ov006Vt_021ec404_vtbl;

ov006_Unk021ec888 *Ov006Vt_021ec404_Ctor(ov006_Unk021ec888 *self);

static inline void ov006_Menu_ClearNodes(ov006_Unk021ec888 *self) {
    ov006_MenuNode *node = self->nodes;
    while (node != NULL) {
        void *saved;
        ov006_MenuNode *next;
        next = node->next;
        saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        gSysState->cur = saved;
        node = next;
    }
    self->nodes = NULL;
    self->unk24 = 0;
    self->unk26 = 1;
}

static inline void ov006_Menu_Dtor(ov006_Unk021ec888 *self) {
    self->vtbl = &Ov006Vt_021ec404_vtbl;
    gSysState->vblankFunc = NULL;
    ov006_Menu_ClearNodes(self);
    OV006_DELETE_OBJECT(self->unk1D4);
    OV006_DELETE_OBJECT(self->unk1D8);
}

ov006_Unk021ec888 *Ov006Vt_021ec404_Dtor(ov006_Unk021ec888 *self) {
    ov006_Menu_Dtor(self);
    return self;
}

ov006_Unk021ec888 *Ov006Vt_021ec404_DtorDelete(ov006_Unk021ec888 *self) {
    ov006_Menu_Dtor(self);
    Heap_Free(self);
    return self;
}

void ov006_Menu_Create(void) {
    if (data_ov006_021ec888 == NULL) {
        ov006_Unk021ec888 *obj = (ov006_Unk021ec888 *)Heap_Alloc(sizeof(ov006_Unk021ec888));
        if (obj != NULL) {
            obj = Ov006Vt_021ec404_Ctor(obj);
        }
        data_ov006_021ec888 = obj;
    }
}

void ov006_Menu_Delete(void) {
    OV006_DELETE_OBJECT(data_ov006_021ec888);
}

}
