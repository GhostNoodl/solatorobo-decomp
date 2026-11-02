#include "ov000/VObj.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

class Task021cbac8 : public VObj {
public:
    u8 unk_04[0x24];
    Task021cbac8 *next;
    Task021cbac8 *prev;
    VObj *unk_30;
    u8 *unk_34;
};

extern "C" {

extern HeapState *data_02097dd0;
extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cca28[];
extern u8 data_ov000_021cca40[];
void func_02041558(void *obj);
void func_02041278(void *obj);
void Heap_Free(void *ptr);

static inline void Task021cbac8_Dtor(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
}

static inline void Obj02041558_Delete(u8 *obj) {
    if (obj != NULL) {
        func_02041558(obj);
        func_02041278(obj + 0x88);
        Heap_Free(obj);
    }
}

static inline void DeleteModel(u8 **p) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (*p != NULL) {
        Obj02041558_Delete(*p);
        *p = NULL;
    }
    data_02097dd0->current = saved;
}

static inline void DeleteMember(VObj **p) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (*p != NULL) {
        if (*p != NULL) {
            (*p)->vfunc_04();
        }
        *p = NULL;
    }
    data_02097dd0->current = saved;
}

Task021cbac8 *Ov000Vt_021cca28_DtorDelete(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca28);
    DeleteMember(&self->unk_30);
    Task021cbac8_Dtor(self);
    Heap_Free(self);
    return self;
}

Task021cbac8 *Ov000Vt_021cca28_Dtor(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca28);
    DeleteMember(&self->unk_30);
    Task021cbac8_Dtor(self);
    return self;
}

Task021cbac8 *Lo021cca40_DtorDelete(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca40);
    DeleteMember(&self->unk_30);
    DeleteModel(&self->unk_34);
    Task021cbac8_Dtor(self);
    Heap_Free(self);
    return self;
}

Task021cbac8 *Lo021cca40_Dtor(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca40);
    DeleteMember(&self->unk_30);
    DeleteModel(&self->unk_34);
    Task021cbac8_Dtor(self);
    return self;
}

}
