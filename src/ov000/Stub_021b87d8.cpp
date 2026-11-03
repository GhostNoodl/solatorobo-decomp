#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"

typedef struct {
    s32 unk_00;
    u8 unk_04[0x40];
    s32 unk_44;
    u16 unk_48;
    Model *unk_4c;
    s32 unk_50;
    s32 unk_54;
    u16 unk_58;
} Obj021b87d8;
SIZE_ASSERT(Obj021b87d8, 0x5c);


extern "C" {

void Heap_Free(void *ptr);

static inline void Obj021b87d8_DeleteMember(Model *obj) {
    if (obj != NULL) {
        TexObj_Release(obj);
        PlttRes_Release(&obj->pltt);
        Heap_Free(obj);
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
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_4c != NULL) {
        Obj021b87d8_DeleteMember(self->unk_4c);
        self->unk_4c = NULL;
    }
    gSysState->cur = saved;
    self->unk_00 = 0;
    self->unk_44 = 1;
    self->unk_48 = 0;
    self->unk_4c = NULL;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
}

}
