#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    u8 unk_04[0x40];
    s32 unk_44;
    u16 unk_48;
    u8 *unk_4c;
    s32 unk_50;
    s32 unk_54;
    u16 unk_58;
} Obj021b87d8;

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;


extern "C" {

extern HeapState *data_02097dd0;
void func_02041558(void *obj);
void func_02041278(void *obj);
void func_0203de1c(void *ptr);

static inline void Obj021b87d8_DeleteMember(u8 *obj) {
    if (obj != NULL) {
        func_02041558(obj);
        func_02041278(obj + 0x88);
        func_0203de1c(obj);
    }
}

void func_ov000_021b87d8(Obj021b87d8 *self, u16 a) {
    self->unk_00 = 0;
    self->unk_44 = 1;
    self->unk_48 = a;
    self->unk_4c = NULL;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
}

void func_ov000_021b8800(Obj021b87d8 *self) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (self->unk_4c != NULL) {
        Obj021b87d8_DeleteMember(self->unk_4c);
        self->unk_4c = NULL;
    }
    data_02097dd0->current = saved;
    self->unk_00 = 0;
    self->unk_44 = 1;
    self->unk_48 = 0;
    self->unk_4c = NULL;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
}

}
