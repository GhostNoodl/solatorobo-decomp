#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern char data_ov013_0220ae4e[];
extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5ca[];
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov013Actor *self, const void *p);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov003_021d1c00(Ov013Actor *self, Ov013Msg *msg);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern s32 func_ov000_0218dfb4(Ov013Actor *a, u16 id);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
s32 func_ov013_021fc400(Ov013Actor *self);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

void func_ov013_021fa6a0(Ov013Actor *self) {
    Ov013Sub48 *m;
    Ov013Sub44 *n;
    Ov013Actor *p;
    func_ov003_021d112c(self);
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_48, 0x5c), 0, 0x2000, 0);
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_44, 0xc), 0, 0x2000, 0);
    self->unk_93_4 = 1;
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = -0x14000;
    FLD(s32, self->unk_3c, 0x14) = self->unk_64 << 1;
    FLD(u8, self, 0xf1) = 0;
    FLD(u8, self, 0xf0) = 0;
    FLD(u8, self, 0xf2) = 0;
    FLD(u16, self, 0xf4) = 0x1000;
    FLD(s32, self, 0xf8) = 0;
    self->unk_b6 = 0x3c;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov013_0220ae4e);
        FLD(u16, self, 0xf4) = 0x1800;
    }
}

void func_ov013_021fa78c(Ov013Actor *self) {
    Ov013Actor *p;
    s32 n;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    n = func_ov013_021fc400(self);
    self->unk_40->flags |= 1ull << n;
    self->unk_b6 = 0x96;
    if (n == 0x10) {
        self->unk_b6 = 0xb4;
    }
}

void func_ov013_021fa888(Ov013Actor *self, Ov013Msg *msg) {
    if (msg->type == 9) {
        func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x40, &self->pos, 0);
    }
    func_ov003_021d1c00(self, msg);
}

void func_ov013_021fa8e4(Ov013Actor *self) {
    Ov013Sub40 *s = self->unk_40;
    Ov013Sub44 *n;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u8, self->unk_38, 0xbe) = 0;
        self->rot[1] = 0;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    case 0x14: {
        u8 a = FLD(u8, self->unk_38, 0xbe);
        if (a < 0x1f) {
            s->timer++;
            if (s->timer % 6 == 0) {
                FLD(u8, self->unk_38, 0xbe) = a + 1;
            }
        } else {
            s->state = 0x63;
            n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        break;
    }
    case 0x63:
        s->timer++;
        if (s->timer > 0x14) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov013_021faa40(Ov013Actor *self) {
    Ov013Actor *t;
    if (self->unk_40->state == 0) {
        Ov013Sub44 *n;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
    }
    t = func_ov000_0218d240(self);
    if (t != NULL) {
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
    }
}

}
