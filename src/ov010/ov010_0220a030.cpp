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

struct Ov010Tmr {
    void *vtbl;
    u8 on;
    u8 unk_05;
    u16 unk_06;
    s32 unk_08;
};

struct Ov010IdNode {
    u16 id;
    Ov010IdNode *next;
};

struct Ov010IdList {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x10];
    Ov010IdNode *head;
};

struct Ov010TblF534 {
    u8 unk_00[0x60];
    Ov010Vec v60;
};

extern "C" {

extern u8 data_ov010_02210260[];

BOOL func_ov010_0220a030(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_0220a040(Ov010Trig *self, u16 a, s32 b, s32 c, s32 d, u16 e, u16 f) {
    self->b1 = 1;
    self->unk_0a = a;
    self->unk_1c = b;
    self->unk_14 = c;
    self->unk_18 = d;
    self->unk_06 = e;
    self->unk_08 = f;
}

Ov010Tmr *func_ov010_0220a078(Ov010Tmr *self) {
    self->vtbl = data_ov010_02210260;
    self->on = 0;
    return self;
}

void *func_ov010_0220a090(void *self) {
    FLD(void *, self, 0) = data_ov010_02210260;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_0220a0b8(void *self) {
    FLD(void *, self, 0) = data_ov010_02210260;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_0220a0e8(Ov010Tmr *self, s32 a) {
    self->on = 1;
    self->unk_06 = 0;
    self->unk_08 = a;
    return 1;
}

void func_ov010_0220a104(Ov010Tmr *self) {
    if (self->on) {
        self->on = 0;
    }
}


extern void *data_ov000_021ccd68;
extern Ov010TblF534 data_ov010_0220f534;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021da48c(void *p, s32 a);

static inline void *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u8 Ov010IdList_Count(Ov010IdList *l) {
    u8 c = 0;
    if (l->b0) {
        c = l->count;
    }
    return c;
}

static inline u16 Ov010IdList_Get(Ov010IdList *l, s32 i) {
    u16 id = 0xffff;
    if (l->b0 && i < l->count) {
        id = l->ids[i];
    }
    return id;
}

void func_ov010_0220a118(Ov010Tmr *self) {
    Ov010IdList *l;
    if (!self->on) {
        return;
    }
    l = (Ov010IdList *)self->unk_08;
    if (l->b0) {
        Ov010IdNode *n;
        l->count = 0;
        for (n = l->head; n != NULL; n = n->next) {
            void *a = Ov010_FindActor(n->id);
            if (a != NULL && FLD(s32, a, 0xd8) == 2) {
                l->ids[l->count] = n->id;
                l->count++;
            }
        }
    }
    l = (Ov010IdList *)self->unk_08;
    if (Ov010IdList_Count(l) == 0) {
        ((Ov010V *)self)->v0c();
    } else if (self->unk_06 % 3 == 0) {
        void *a = Ov010_FindActor(Ov010IdList_Get(l, 0));
        if (a != NULL && FLD(u8, a, 0x14) != 1 && !FLD(Ov010Flags8, a, 0xce).b1) {
            FLD(Ov010Flags8, a, 0xce).b1 = 1;
            func_ov003_021da48c((u8 *)a + 0x16c, 3);
            Ov010_VecCopy(&FLD(Ov010Vec, a, 0xfc), &data_ov010_0220f534.v60);
        }
    }
    self->unk_06++;
}
}
