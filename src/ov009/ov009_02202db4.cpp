#include "ov009/ov009.h"

extern "C" {

extern void *func_ov000_0219bf90(void);

void func_ov009_02202db4(Ov009Actor *self) {
    u16 *p;
    u16 v;
    Ov009Sub38 *m;
    func_ov003_021d1e8c(self);
    if (!self->unk_93_4) {
        return;
    }
    func_ov000_0219bf90();
    p = self->unk_50;
    v = self->unk_b0->unk_08;
    if (*p >= v) {
        return;
    }
    *p = v;
    m = self->unk_38;
    FLD(u16, m, 0xb6) = 0x14bf;
    FLD(u16, m, 0xb8) = 0x14bf;
    FLD(u16, m, 0xba) = 1;
    FLD(u16, m, 0xbc) = 0;
}

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d398(Ov009Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void func_0203f9dc(void *mesh, const void *mtx);
extern void MI_Copy48B(const void *src, void *dst);
extern void func_ov003_021d3008(Ov009Actor *self);
static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov009Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

struct Ov009PosMsg {
    Ov009Vec pos;
    u16 rot[3];
    u32 unk_14;
};

void func_ov009_02202e18(Ov009Actor *self) {
    Ov009PosMsg msg;
    u8 mtx[0x30];
    Ov009Actor *a;
    func_ov003_021d3008(self);
    a = Ov009_FindActor(FLD(u16, self, 0xf0));
    if (a == NULL || Ov009_Mode(a) == 9) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
    if (a == NULL || self->unk_40->unk_13 == 0x15) {
        return;
    }
    if (FLD(void *, self, 0x58) != NULL) {
        func_0203f9dc(FLD(void *, self, 0x58), &FLD(u8, self, 0xfc));
    }
    if (Ov009_Mode(a) != 1) {
        return;
    }
    if (self->unk_1e == 0) {
        return;
    }
    msg.pos = FLD(Ov009Vec, self, 0x120);
    msg.rot[0] = self->rot[0];
    msg.rot[1] = self->rot[1];
    msg.rot[2] = self->rot[2];
    msg.unk_14 = 0;
    func_ov000_0218d398(a, self->id, 7, TRUE, 0x18, &msg);
    MI_Copy48B(&FLD(u8, self, 0xfc), mtx);
    func_ov000_0218d398(a, self->id, 8, TRUE, 0x30, mtx);
}

}
