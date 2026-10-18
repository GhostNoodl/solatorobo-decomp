#include "types.h"

typedef struct {
    u8 unk_00[0x30];
} Ov003Slot30;

typedef struct {
    Ov003Slot30 slots[2];
    u8 ids[2];
} Ov003SlotTable;

typedef struct {
    u8 unk_00[0x2c];
    Ov003SlotTable *table;
} Ov003SlotOwner;

typedef struct {
    void *vtbl;
    Ov003SlotOwner *owner;
    u32 flags;
    u8 unk_0c[0x18];
    void (*func)(void *);
    u8 unk_28[0x6a];
    u8 unk_92;
    u8 unk_93[0x19];
    u8 unk_ac;
    u8 unk_ad;
    u8 unk_ae;
    u8 unk_af;
    void *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    u8 unk_b8[0xc];
    void *unk_c4;
    void *unk_c8;
    void *unk_cc;
    void *unk_d0;
    void *unk_d4;
    void *unk_d8;
    u16 unk_dc;
    u16 unk_de;
    void *unk_e0;
    void *unk_e4;
    u16 unk_e8;
    u16 unk_ea;
    u8 unk_ec;
    u8 unk_ed;
    u16 unk_ee;
} Ov003Obj;

extern void func_0202a4c8(void *p, s32 a);
extern void func_ov000_0218c2d4(Ov003Obj *self);
extern char data_ov003_021f7ab4[];

void func_ov003_021d0ba8(Ov003Obj *self) {
    s32 id;
    Ov003SlotTable *t;
    s32 i;
    t = self->owner->table;
    if (self->flags & 0x10) {
        id = self->unk_ae;
    } else {
        id = -1;
    }
    for (i = 0; i < 2; i++) {
        if (t->ids[i] != 0xff && id == t->ids[i]) {
            func_0202a4c8(&t->slots[i], 0);
            return;
        }
    }
}

void func_ov003_021d0c04(Ov003Obj *self) {
    self->func = (void (*)(void *))func_ov003_021d0ba8;
    self->unk_92 = 3;
}

#define OV003_OBJ_CTOR(name)                 \
Ov003Obj *name(Ov003Obj *self) {             \
    func_ov000_0218c2d4(self);               \
    self->vtbl = data_ov003_021f7ab4;        \
    self->unk_b4 = 0;                        \
    self->unk_b6 = 0;                        \
    self->unk_ac = 0xff;                     \
    self->unk_ad = 0xff;                     \
    self->unk_ae = 0xff;                     \
    self->unk_b0 = NULL;                     \
    self->unk_c4 = NULL;                     \
    self->unk_d0 = NULL;                     \
    self->unk_d4 = NULL;                     \
    self->unk_d8 = NULL;                     \
    self->unk_e8 = 0;                        \
    self->unk_de = 0xffff;                   \
    self->unk_ea = 0;                        \
    self->unk_ec = 0;                        \
    self->unk_ee = 0;                        \
    self->unk_c8 = NULL;                     \
    self->unk_cc = NULL;                     \
    self->unk_e4 = NULL;                     \
    self->unk_e0 = NULL;                     \
    return self;                             \
}

OV003_OBJ_CTOR(func_ov003_021d0c1c)
OV003_OBJ_CTOR(func_ov003_021d0c94)
