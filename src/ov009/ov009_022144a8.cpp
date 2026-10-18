#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_02195d88(Ov009Actor *self);
extern void func_ov000_02196c40(Ov009Actor *self);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_022144a8(Ov009Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov009_022144c0(Ov009Actor *self) {
    func_ov000_02195d88(self);
    if (Ov009_FindActor(FLD(u16, self, 0xd2)) == NULL) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

void func_ov009_02214508(Ov009Actor *self) {
    if (self->unk_40->state == 0 && self->unk_9c == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov000_02196c40(self);
}

}
