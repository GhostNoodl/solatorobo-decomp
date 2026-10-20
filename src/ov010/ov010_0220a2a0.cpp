#include "ov010/ov010.h"

struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    s32 unk_08;
};

typedef struct Ov010CNode Ov010CNode;

struct Ov010CNode {
    u16 id;
    u16 unk_02;
    Ov010CNode *next;
};

struct Ov010CColl {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010CNode *list;
    void *handler;
    u8 pool[1];
};

struct Ov010Trig2 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    Ov010CColl *coll;
    u16 state;
};

extern "C" {

extern u8 data_ov010_02210240[];
extern void func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

u8 func_ov010_0220a2a0(void *self) {
    return FLD(u8, self, 4);
}

Ov010Trig *func_ov010_0220a2a8(Ov010Trig *self) {
    self->vtbl = data_ov010_02210240;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    return self;
}

void *func_ov010_0220a2d8(void *self) {
    FLD(void *, self, 0) = data_ov010_02210240;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_0220a300(void *self) {
    FLD(void *, self, 0) = data_ov010_02210240;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_0220a330(Ov010Trig *self, s32 a) {
    self->unk_08 = a;
    self->b0 = 1;
    func_ov003_021da48c((u8 *)self + 0xc, 0);
    return TRUE;
}

void func_ov010_0220a35c(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}


extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern Ov010CNode *func_ov010_0220db74(Ov010CNode *head, Ov010CNode *node);
extern void func_ov003_021d79ac(void *p, Ov010CNode *n);

static inline void *Ov010t_Find(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return NULL;
}

static inline void Ov010t_Collect(Ov010CColl *c) {
    Ov010CNode *n;
    if (c->b0) {
        c->count = 0;
        for (n = c->list; n != NULL; n = n->next) {
            Ov010t_Find(n->id);
            c->ids[c->count] = n->id;
            c->count++;
        }
    }
}

static inline long Ov010t_Count(Ov010CColl *c) {
    u8 r = 0;
    if (c->b0) {
        r = c->count;
    }
    return r;
}

static inline u16 Ov010t_Id(Ov010CColl *c, s32 i) {
    u16 r = 0xffff;
    if (c->b0 && i >= 0 && i < c->count) {
        r = c->ids[i];
    }
    return r;
}

static inline void Ov010t_Remove(Ov010CColl *c, u16 id) {
    Ov010CNode *n;
    if (c->b0) {
        for (n = c->list; n != NULL; n = n->next) {
            if (n->id == id) {
                if (c->b0 && n != NULL) {
                    void *o = Ov010t_Find(n->id);
                    if (o != NULL) {
                        ((Ov010V *)o)->v08();
                    }
                    c->list = func_ov010_0220db74(c->list, n);
                    func_ov003_021d79ac(c->pool, n);
                }
                return;
            }
        }
    }
}

void func_ov010_0220a374(Ov010Trig2 *self) {
    BOOL done;
    s32 i;
    if (!self->b0) {
        return;
    }
    switch (self->state) {
    case 0:
        done = FALSE;
        Ov010t_Collect(self->coll);
        for (i = 0; i < Ov010t_Count(self->coll); i++) {
            u8 *obj = (u8 *)Ov010t_Find(Ov010t_Id(self->coll, i));
            if (obj != NULL) {
                s32 kind = FLD(s32, obj, 0xd8);
                BOOL a = kind == 6 ? TRUE : FALSE;
                BOOL b = kind == 8 ? TRUE : FALSE;
                BOOL c = kind == 5 ? TRUE : FALSE;
                if (a || b || c) {
                    u8 f = 0;
                    func_ov000_0218d398(obj, 0xffff, 0xe, 1, 1, &f);
                } else if (kind == 7) {
                    if (!done) {
                        u8 f = 2;
                        Ov010Vec p;
                        done = TRUE;
                        func_ov000_0218d398(obj, 0xffff, 0xe, 1, 1, &f);
                        p = FLD(Ov010Vec, obj, 0x70);
                        func_02049f44(data_02097e4c, 0x77, &p, 0);
                    }
                } else {
                    Ov010t_Remove(self->coll, FLD(u16, obj, 0xc));
                }
            }
        }
        self->state = 1;
        break;
    case 1:
        Ov010t_Collect(self->coll);
        if (Ov010t_Count(self->coll) == 0) {
            ((Ov010V *)self)->v0c();
        }
        break;
    }
}

}
