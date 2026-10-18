#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern Ov009Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);

void func_ov009_021facf0(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x5401, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x541f, 0x15);
        self->unk_ea_10 = 1;
    }
    func_ov003_021d6054(self);
}

void func_ov009_021fad54(Ov009Actor *self) {
    Ov009Actor *a;
    func_ov003_021d112c(self);
    if (self->unk_1a == 0) {
        return;
    }
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x1000, 0x1001);
    }
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    self->unk_c8 = 0x50000;
}

extern void *data_02097e4c;
extern u8 data_ov009_02216ab0[];
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void func_ov009_021fada8(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Sub44 *s44;
    switch (st->state) {
    case 0:
        if (self->unk_1a != 0) {
            func_ov000_02198360(st, 1, 0);
            return;
        }
        self->pos.y += 0x5000;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_a0 = -0x19a;
        self->unk_a8 = 0x52;
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
        self->unk_40->state++;
    case 1:
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab0, 0x200, 0);
        func_02065f88(0x12e, &self->pos)->v0c(0x1400);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->unk_40->state++;
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x2d) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_021911c8(void *model, s32 a);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern Ov009Actor *func_ov003_021d69a0(Ov009Actor *self, u16 kind, s32 a);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern s32 func_02040498(s32 max);
static inline Ov009Actor *Ov009_FindActor5(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_021faf48(Ov009Actor *self) {
    Ov009Actor *t = Ov009_FindActor5(self->unk_90);
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab0, 0x200, 0);
        {
            Ov009Sub38 *m = self->unk_38;
            FLD(s32, m, 0xd8) = 0;
            FLD(s32, m, 0xdc) = 0;
        }
        func_ov000_021911c8(self->unk_38, 0x800);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        switch (self->kind) {
        case 0x5032:
            FLD(u16, self, 0xf0) = 0xb4;
            break;
        case 0x5402:
            FLD(u16, self, 0xf0) = 100;
            break;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x28) {
            self->unk_a0 = 0x400;
            self->unk_a8 = 0x29;
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    case 2: {
        u16 a;
        Ov009Actor *g;
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        if (self->unk_a0 < 0) {
            self->unk_a8 = 0x52;
        }
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab0, 0x800, 1);
        if (t != NULL) {
            func_ov000_0219aae8(self, self, FLD(u16, self, 0xf0), 0x20, (u16)(1 << (t->id >> 12)), NULL, 0, 0x3400, 0x2800, 0x64, 0x1000);
        }
        func_02065f88(0x66, &self->pos)->v0c(0x1c00);
        g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
        if (g != NULL && FLD(u16, g, 0x16) <= 3) {
            do {
                Ov009Actor *o = func_ov003_021d69a0(self, 0x5404, 4);
                if (o != NULL) {
                    Ov009Vec v;
                    v.z = self->unk_64;
                    v.x = 0;
                    v.y = 0x2000;
                    a = self->rot[1] + 0xe800 + func_02040498(0x3000);
                    func_01ffc9fc(&v, &v, a);
                    VEC_Add(&v, &self->pos, &v);
                    o->pos.x = v.x;
                    o->pos.y = v.y;
                    o->pos.z = v.z;
                    o->unk_9c = func_02040498(0x80) + 0x19a;
                    o->unk_a0 = 0x333;
                    o->unk_a4 = 0;
                    o->unk_a8 = 0x52;
                    o->unk_98 = a;
                }
            } while (FLD(u16, g, 0x16) <= 3);
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    }
    case 3:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        self->unk_48->unk_9a_5 = 1;
        break;
    }
}

}
