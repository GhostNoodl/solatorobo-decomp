#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov011FreeNode {
    u8 pad[0xc];
    Ov011FreeNode *next;
};

extern "C" {

void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void *func_ov011_021fb66c(void *self);
void func_ov011_02201b28(void *p);
void func_ov011_0220205c(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_021fab74(void *p);
void func_ov000_0218d46c(void *o, u16 id, s32 c);

void func_ov011_021febd8(u8 *self) {
    Ov011Node *n;
    if (FLD(u16, self, 0x20) != 0) {
        return;
    }
    func_ov011_02201b28(self + 0x34);
    FLD(Ov011Bit01, self, 0xb4).b1 = 0;
    FLD(u16, self, 0xb6) = 0;
    FLD(s32, self, 0xb8) = -1;
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (FLD(void *, self, 0xbc) != NULL) {
            __cxa_vec_delete(FLD(void *, self, 0xbc), 0x40, 8, func_ov011_021fb66c);
            FLD(void *, self, 0xbc) = NULL;
        }
        data_02097dd0->cur = saved;
    }
    func_ov003_021da48c(self + 0xc8, 0);
    func_ov011_0220205c(self + 0xdc);
    func_ov011_02202fbc(self + 0x194);
    FLD(Ov011Bit01, self, 0x1b4).b1 = 0;
    FLD(u16, self, 0x1b6) = 0xffff;
    FLD(s32, self, 0x1bc) = 0;
    func_ov003_021da48c(self + 0x1c0, 1);
    func_ov011_021fab74(self + 0x1d4);
    if (FLD(Ov011Bit01, self, 0x204).b0) {
        Ov011FreeNode *p = FLD(Ov011FreeNode *, self, 0x208);
        while (p != NULL) {
            Ov011FreeNode *next = p->next;
            if (p != NULL) {
                func_0203de1c(p);
            }
            p = next;
        }
        FLD(Ov011FreeNode *, self, 0x208) = NULL;
    }
    for (n = FLD(Ov011Node *, self, 0xc); n != NULL; n = n->next) {
        void *a = Ov011_FindActor(n->id);
        if (a != NULL) {
            func_ov000_0218d46c(a, 0xffff, 0x15);
        }
    }
    FLD(Ov011Bit01, self, 0).b2 = 1;
    FLD(u16, self, 0x20) = 1;
}


extern u8 data_ov011_022078f0[];
void func_ov011_0220068c(void *self);
void *func_ov003_021d0edc(void *self);

void func_ov003_021d0c1c(void *self);
u32 func_ov011_02202ecc(void *p);
void func_ov011_02202260(void *p);
void func_ov011_0220192c(void *p);
u16 func_ov003_021d16cc(void *p);
extern s32 data_ov011_02207258[];

struct Ov011Fed {
    u8 pad[0xf0];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 padf1;
    u16 unk_f2;
    s32 unk_f4;
    s32 unk_f8;
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10c;
};

#pragma force_active on
Ov011Fed *func_ov011_021fed5c(Ov011Fed *self) {
    func_ov003_021d0c1c(self);
    *(void **)self = data_ov011_022078f0;
    self->b0 = 0;
    self->b1 = 0;
    self->unk_f2 = 0;
    self->unk_f4 = data_ov011_02207258[8];
    self->unk_f8 = data_ov011_02207258[9];
    self->unk_fc = data_ov011_02207258[10];
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_108 = 0;
    self->unk_10c = 0;
    return self;
}

void *func_ov011_021fedc8(void *self) {
    *(void **)self = data_ov011_022078f0;
    func_ov011_0220068c(self);
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov011_021fedf0(void *self) {
    *(void **)self = data_ov011_022078f0;
    func_ov011_0220068c(self);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

struct Ov011FeeObj {
    u8 pad[0x14];
    Ov011V obj;
};

struct Ov011FeeChr {
    u8 b0 : 1;
    u8 rest0 : 7;
    u8 pad1[0x33];
    u8 fx[0x80];
    u8 b4_0 : 1;
    u8 b4_1 : 1;
    u8 rest4 : 6;
    u8 padb5[0x27];
    u8 chr[4];
};

struct Ov011FeeSub {
    u8 pad[0x14];
    s32 unk_14;
};

struct Ov011Fee {
    u8 pad[0x3c];
    Ov011FeeSub *unk_3c;
    u8 pad40[0x30];
    Ov011Vec pos;
    u8 pad7c[0x84];
    Ov011FeeChr *unk_100;
    Ov011FeeObj *unk_104;
};

s32 func_ov011_021fee20(Ov011Fee *self) {
    Ov011Vec save = self->pos;
    s32 old;
    s32 ret;
    Ov011FeeChr *c;
    if (self->unk_104 != NULL && func_ov011_02202ecc(&self->unk_104->obj)) {
        self->pos.y += ((s32 *)self->unk_104->obj.v10())[1];
    }
    old = self->unk_3c->unk_14;
    self->unk_3c->unk_14 = old >> 1;
    ret = func_ov003_021d16cc(self);
    self->unk_3c->unk_14 = old;
    c = self->unk_100;
    if (c->b0) {
        if (c->b4_0 && c->b4_1) {
            func_ov011_02202260(c->chr);
        }
        func_ov011_0220192c(c->fx);
    }
    self->pos.x = save.x;
    self->pos.y = save.y;
    self->pos.z = save.z;
    return ret;
}
#pragma force_active reset
}
