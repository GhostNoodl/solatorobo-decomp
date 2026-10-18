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
    VObj *unk_34;
};

extern "C" {

extern HeapState *data_02097dd0;
extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cca58[];
extern u8 data_ov000_021cca70[];
extern u8 data_ov000_021cc9f8[];
extern u8 data_ov000_021cca10[];
void func_0203de1c(void *ptr);
void func_ov000_021c2f90(Task021cbac8 *self);
void func_ov000_021c2364(Task021cbac8 *self);

static inline void Task021cbac8_Dtor(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cbac8);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
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

Task021cbac8 *func_ov000_021c8be8(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca58);
    DeleteMember(&self->unk_30);
    Task021cbac8_Dtor(self);
    func_0203de1c(self);
    return self;
}

Task021cbac8 *func_ov000_021c8c80(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca58);
    DeleteMember(&self->unk_30);
    Task021cbac8_Dtor(self);
    return self;
}

Task021cbac8 *func_ov000_021c8d10(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca70);
    func_ov000_021c2f90(self);
    Task021cbac8_Dtor(self);
    func_0203de1c(self);
    return self;
}

Task021cbac8 *func_ov000_021c8d64(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca70);
    func_ov000_021c2f90(self);
    Task021cbac8_Dtor(self);
    return self;
}

Task021cbac8 *func_ov000_021c8db0(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc9f8);
    DeleteMember(&self->unk_30);
    DeleteMember(&self->unk_34);
    Task021cbac8_Dtor(self);
    func_0203de1c(self);
    return self;
}

Task021cbac8 *func_ov000_021c8e88(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cc9f8);
    DeleteMember(&self->unk_30);
    DeleteMember(&self->unk_34);
    Task021cbac8_Dtor(self);
    return self;
}

Task021cbac8 *func_ov000_021c8f58(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca10);
    func_ov000_021c2364(self);
    Task021cbac8_Dtor(self);
    func_0203de1c(self);
    return self;
}

Task021cbac8 *func_ov000_021c8fac(Task021cbac8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cca10);
    func_ov000_021c2364(self);
    Task021cbac8_Dtor(self);
    return self;
}

}
