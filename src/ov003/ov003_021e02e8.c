#include "types.h"

typedef struct {
    u8 unk_00[0xd0];
    u8 unk_d0[0x30];
    u8 unk_100;
} Ov003Spot;

typedef struct {
    void *vtbl;
    void *owner;
    u32 flags;
    u8 unk_0c[0x18];
    void (*func)(void *);
    u8 unk_28[0x6a];
    u8 unk_92;
    u8 unk_93[0x1b];
    u8 unk_ae;
} Ov003Obj;

extern void *data_ov000_021ccd68;
extern Ov003Spot *func_ov000_0218e6d0(void *mgr, s32 a, s32 b);
extern void func_0202a4c8(void *p, s32 a);
extern void func_02016dd8(void *a, void *b);

void func_ov003_021e02e8(Ov003Obj *self) {
    u8 buf[0x30];
    Ov003Spot *p;
    s32 id;
    u8 b;
    if (data_ov000_021ccd68 == NULL) {
        p = NULL;
    } else {
        p = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x404f);
    }
    if (p == NULL || (b = p->unk_100) == 0xff) {
        return;
    }
    if (self->flags & 0x10) {
        id = self->unk_ae;
    } else {
        id = -1;
    }
    if (b != id) {
        return;
    }
    func_0202a4c8(buf, 0);
    func_02016dd8(buf, p->unk_d0);
}

void func_ov003_021e0370(Ov003Obj *self) {
    self->func = (void (*)(void *))func_ov003_021e02e8;
    self->unk_92 = 3;
}
