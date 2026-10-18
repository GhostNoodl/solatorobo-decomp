#include "types.h"

typedef struct {
    u8 unk_00[0xb6];
    u16 unk_b6;
    u16 unk_b8;
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be;
} Ov003Anim;

typedef struct {
    u8 unk_00[0x68];
    Ov003Anim *unk_68[2];
} Ov003SubAnims;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
} Ov003Spawn;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x2a];
    Ov003Anim *unk_38;
    u8 unk_3c[0x34];
    u8 unk_70[0xc];
    u8 unk_7c[0x54];
    Ov003SubAnims *unk_d0;
    u8 unk_d4[0xa];
    u16 unk_de;
    u8 unk_e0[0xa];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 3;
} Ov003AnimObj;

extern Ov003Spawn *func_ov000_0219be1c(s32 id, void *pos, void *rot, u16 a, u16 b);
extern void func_ov000_0218d46c(Ov003Spawn *p, u16 id, s32 v);

void func_ov003_021d6868(Ov003AnimObj *self, u16 v) {
    Ov003Anim *a = self->unk_38;
    s32 i;
    a->unk_b6 = v;
    a->unk_b8 = v;
    a->unk_ba = 2;
    a->unk_bc = 1;
    if (self->unk_d0 == NULL) {
        return;
    }
    if (self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        a = self->unk_d0->unk_68[i];
        if (a != NULL) {
            a->unk_b6 = v;
            a->unk_b8 = v;
            a->unk_ba = 2;
            a->unk_bc = 1;
        }
    }
}

void func_ov003_021d68e0(Ov003AnimObj *self, u16 v0, u16 v1, u16 v2) {
    Ov003Anim *a = self->unk_38;
    s32 i;
    a->unk_b6 = v0;
    a->unk_b8 = v1;
    a->unk_ba = v2 + 1;
    a->unk_bc = v2;
    if (self->unk_d0 == NULL) {
        return;
    }
    if (self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        a = self->unk_d0->unk_68[i];
        if (a != NULL) {
            a->unk_b6 = v0;
            a->unk_b8 = v1;
            a->unk_ba = v2 + 1;
            a->unk_bc = v2;
        }
    }
}

void func_ov003_021d6954(Ov003AnimObj *self, u8 v) {
    Ov003Anim *a = self->unk_38;
    s32 i;
    a->unk_be = v;
    if (self->unk_d0 == NULL) {
        return;
    }
    if (self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        a = self->unk_d0->unk_68[i];
        if (a != NULL) {
            a->unk_be = v;
        }
    }
}

Ov003Spawn *func_ov003_021d69a0(Ov003AnimObj *self, s32 id, s32 v) {
    Ov003Spawn *p = func_ov000_0219be1c(id, self->unk_70, self->unk_7c, 0xffff, 0xffff);
    if (p != NULL && v != 0) {
        func_ov000_0218d46c(p, self->unk_0c, v);
    }
    return p;
}

Ov003Spawn *func_ov003_021d69f0(Ov003AnimObj *self, s32 id, void *pos, void *rot, Ov003Spawn *other) {
    u16 o = 0xffff;
    Ov003Spawn *p;
    if (other != NULL) {
        o = other->unk_0c;
    }
    p = func_ov000_0219be1c(id, pos, rot, self->unk_0c, o);
    if (p != NULL) {
        self->unk_de = p->unk_0c;
    }
    return p;
}
