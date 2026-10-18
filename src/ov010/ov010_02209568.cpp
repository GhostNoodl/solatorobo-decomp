#include "ov010/ov010.h"

struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
};

extern "C" {

extern u8 data_ov010_022102c0[];
extern void func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

BOOL func_ov010_02209568(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_02209578(Ov010Trig *self, s32 a, s32 b, s32 c, u16 d, u16 e) {
    self->b1 = 1;
    self->unk_18 = a;
    self->unk_10 = b;
    self->unk_14 = c;
    self->unk_06 = d;
    self->unk_08 = e;
}

Ov010Trig *func_ov010_022095a8(Ov010Trig *self) {
    self->vtbl = data_ov010_022102c0;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *func_ov010_022095e0(void *self) {
    FLD(void *, self, 0) = data_ov010_022102c0;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_02209608(void *self) {
    FLD(void *, self, 0) = data_ov010_022102c0;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_02209638(Ov010Trig *self, s32 a) {
    FLD(s32, self, 8) = a;
    self->b0 = 1;
    func_ov003_021da48c((u8 *)self + 0xc, 0);
    return TRUE;
}

void func_ov010_02209664(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

struct Ov010IdNode {
    u16 id;
    Ov010IdNode *next;
};

struct Ov010IdList {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010IdNode *head;
};

extern void *data_ov000_021ccd68;
extern const Ov010Blk12 data_ov010_0220f558;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);

static inline u8 *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov010_02209684(Ov010Trig *self) {
    if (!self->b0) {
        return;
    }
    switch (FLD(u16, self, 0xc)) {
    case 0: {
        Ov010IdList *l = FLD(Ov010IdList *, self, 8);
        u16 id;
        u8 *a;
        u8 *s;
        if (l->b0) {
            Ov010IdNode *n;
            l->count = 0;
            for (n = l->head; n != NULL; n = n->next) {
                u8 *e = Ov010_FindActor(n->id);
                if (e != NULL && FLD(s32, e, 0xd8) == 1) {
                    l->ids[l->count] = n->id;
                    l->count++;
                }
            }
        }
        l = FLD(Ov010IdList *, self, 8);
        id = 0xffff;
        if (l->b0 && (s32)l->count > 0) {
            id = l->ids[0];
        }
        a = Ov010_FindActor(id);
        s = Ov010_FindActor(self->unk_06);
        if (a != NULL) {
            Ov010Blk12 t = data_ov010_0220f558;
            Ov010Vec v;
            func_ov003_021d9980(&v, FLD(u16, s, 0x7e), (Ov010Vec *)&t);
            if (FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
                FLD(Ov010Flags8, a, 0xce).b1 = 1;
                func_ov003_021da48c(a + 0x16c, 1);
                Ov010_VecCopy(&FLD(Ov010Vec, a, 0xfc), &v);
            }
        }
        FLD(u16, self, 0xc) = 1;
        break;
    }
    case 1:
        ((Ov010V *)self)->v0c();
        break;
    }
}

}
