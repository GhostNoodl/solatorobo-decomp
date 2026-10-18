#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u8 pad[4];
    s32 unk_04;
    u8 unk_08;
    u8 pad09[0x1b];
} Ev0216bcbc;

typedef struct {
    u32 flags;
    s32 idx;
    VObj *obj;
    u8 pad0c[0x20];
} Slot0216bcbc;

typedef struct {
    s32 ref;
    s32 unk_04;
    VObj *obj;
} Res0216bcbc;

typedef struct {
    s32 a;
    s32 b;
} Pair0216bcbc;

typedef struct {
    Ev0216bcbc evs[16];
    s32 unk_240;
    s32 unk_244;
    s32 unk_248;
    s32 unk_24c;
    s32 unk_250;
    Slot0216bcbc slots[6];
    s32 unk_35c;
    Res0216bcbc res[1];
} Obj0216bcbc;

extern "C" {

extern const Pair0216bcbc data_ov000_021c9bb4[];
void MI_CpuFill8(void *dst, u8 val, u32 size);

static inline void Res_Release(Res0216bcbc *r) {
    if (r->obj != NULL) {
        if (--r->ref == 0) {
            HEAP_DELETE_VOBJ(r->obj);
        }
    }
}

void func_ov000_0216bcbc(Obj0216bcbc *self) {
    s32 i;
    Slot0216bcbc *slot;
    for (i = 0; i < 16; i++) {
        self->evs[i].unk_04 = -1;
        self->evs[i].unk_08 = 0;
    }
    self->unk_244 = 0;
    self->unk_248 = 0;
    slot = self->slots;
    for (i = 0; i < 6; i++, slot++) {
        if (slot->flags & 1) {
            Res_Release(&self->res[data_ov000_021c9bb4[slot->idx].a]);
            Res_Release(&self->res[data_ov000_021c9bb4[slot->idx].b]);
            HEAP_DELETE_VOBJ(slot->obj);
        }
    }
    self->unk_24c = 0;
    self->unk_250 = 0;
    MI_CpuFill8(self->slots, 0, sizeof(self->slots));
    self->unk_35c = 0;
}

}
