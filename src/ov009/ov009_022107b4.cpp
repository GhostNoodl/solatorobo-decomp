#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_022107b4(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009Actor *a;
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
        a = Ov009_FindActor(FLD(u16, self, 0xde));
        if (a != NULL) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, a);
            a->v08();
        }
    }
    func_ov003_021d5900(self);
}

void func_ov009_02210848(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009Actor *a;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4006, 0x15);
        a = Ov009_FindActor(FLD(u16, self, 0xde));
        if (a != NULL) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, a);
            a->v08();
        }
        FLD(u16, self, 0xea) |= 0x400;
    }
    func_ov003_021d6054(self);
}

extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

void func_ov009_022108e0(Ov009Actor *self) {
    Ov009Sub48 *s48;
    u8 *p;
    func_ov003_021d112c(self);
    s48 = self->unk_48;
    s48->unk_9a_1 = 0;
    s48->unk_9a_4 = 0;
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
    }
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    self->unk_93_4 = 1;
    func_ov000_0219a2f4(&self->pos, 0x5000, -0xa000);
    self->pos.y += 0x4800;
    FLD(u16, self, 0xea) |= 0x400;
}

}
