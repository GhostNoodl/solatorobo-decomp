#include "ov010/ov010.h"

struct Ov010Node {
    u16 id;
    u16 unk_02;
    Ov010Node *next;
};

struct Ov010Coll {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 count;
    u16 ids[0x11];
    Ov010Node *list;
    Ov010V *handler;
    u8 pool[1];
};

struct Ov010SpawnDesc {
    u16 kind;
    u16 flags;
    u16 arr[4];
    s16 last;
};

struct Ov010Rot3s {
    u16 x;
    u16 y;
    u16 z;
};

typedef s32 (*Ov010CollFn)(void *obj);

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021d7848(void *p);
extern void *func_ov003_021d7858(void *p);
extern void func_ov003_021d7948(void *p);
extern BOOL func_ov003_021d7894(void *p, s32 a, s32 b);
extern void func_ov003_021d79ac(void *p, Ov010Node *n);
extern Ov010Node *func_ov003_021d7980(void *p);
extern void *func_ov000_0218bf1c(void *mgr, Ov010SpawnDesc *d, s32 a, Ov010Rot3s *r, s32 b);
extern void func_ov010_0220a948(void *obj, s32 a, s32 b, s32 c, u16 d, u16 e);

static inline void *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return NULL;
}

static inline Ov010Node *Ov010_NodePush(Ov010Node *head, Ov010Node *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

static inline void Ov010SpawnDesc_Init(Ov010SpawnDesc *d, u16 kind, u16 flags) {
    s32 i;
    d->kind = kind;
    d->flags = flags;
    for (i = 0; i < 4; i++) {
        d->arr[i] = 0;
    }
    d->last = -1;
}

BOOL func_ov010_0220d77c(void *p) {
    if (p != NULL && FLD(s32, p, 0xd8) == 6) {
        return TRUE;
    }
    return FALSE;
}

Ov010Coll *func_ov010_0220d79c(Ov010Coll *self) {
    func_ov003_021d7848(self->pool + 0);
    self->b0 = 0;
    return self;
}

Ov010Coll *func_ov010_0220d7c0(Ov010Coll *self) {
    if (self->b0) {
        self->b0 = 0;
        func_ov003_021d7948(self->pool);
    }
    func_ov003_021d7858(self->pool);
    return self;
}

BOOL func_ov010_0220d7f8(Ov010Coll *self) {
    self->b0 = 1;
    self->count = 0;
    self->list = NULL;
    self->handler = NULL;
    func_ov003_021d7894(self->pool, 8, 0x10);
    return TRUE;
}

void func_ov010_0220d834(Ov010Coll *self) {
    if (!self->b0) {
        return;
    }
    self->b0 = 0;
    func_ov003_021d7948(self->pool);
}

void func_ov010_0220d858(Ov010Coll *self) {
    Ov010Node *prev;
    Ov010Node *next;
    Ov010Node *n;
    if (!self->b0) {
        return;
    }
    n = self->list;
    prev = NULL;
    while (n != NULL) {
        next = n->next;
        if (Ov010_FindObjById(n->id) == NULL) {
            if (prev != NULL) {
                prev->next = next;
            } else {
                self->list = next;
            }
            func_ov003_021d79ac(self->pool, n);
        } else {
            prev = n;
        }
        n = next;
    }
    if (self->handler != NULL) {
        if (!self->handler->v14()) {
            self->handler = NULL;
            return;
        }
        self->handler->v10();
    }
}

void func_ov010_0220d918(Ov010Coll *self, Ov010CollFn fn) {
    Ov010Node *n;
    if (self->b0 && fn != NULL) {
        self->count = 0;
        for (n = self->list; n != NULL; n = n->next) {
            if (fn(Ov010_FindObjById(n->id)) == 1) {
                self->ids[self->count] = n->id;
                self->count++;
            }
        }
    }
}

s32 func_ov010_0220d9a4(Ov010Coll *self) {
    s32 r = 0;
    if (self->b0) {
        r = self->count;
    }
    return r;
}

void func_ov010_0220d9c0(Ov010Coll *self, Ov010V *h) {
    if (self->b0 && h != NULL) {
        if (self->handler != NULL) {
            self->handler->v0c();
        }
        self->handler = h;
        h->v08(self);
    }
}

void func_ov010_0220da14(Ov010Coll *self) {
    if (self->b0 && self->handler != NULL) {
        self->handler->v0c();
        self->handler = NULL;
    }
}

BOOL func_ov010_0220da4c(Ov010Coll *self) {
    BOOL r = FALSE;
    if (self->b0) {
        r = self->handler == NULL;
    }
    return r;
}

Ov010Node *func_ov010_0220da74(Ov010Coll *self, s32 a, s32 b, s32 c, s32 d, u16 e, u16 f) {
    Ov010Node *n = NULL;
    if (self->b0) {
        n = func_ov003_021d7980(self->pool);
        if (n != NULL) {
            Ov010SpawnDesc desc;
            Ov010Rot3s rot;
            void *obj;
            Ov010SpawnDesc_Init(&desc, 0x4817, 0x4000);
            rot.x = 0;
            rot.y = 0;
            rot.z = 0;
            obj = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, a, &rot, 0xffff);
            func_ov010_0220a948(obj, b, c, d, e, f);
            FLD(Ov010Flags8, obj, 0x16).b0 = 1;
            n->id = FLD(u16, obj, 0xc);
            self->list = Ov010_NodePush(self->list, n);
        }
    }
    return n;
}

Ov010Node *func_ov010_0220db74(Ov010Node *head, Ov010Node *node) {
    Ov010Node *p;
    Ov010Node *prev;
    if (head == NULL || node == NULL) {
        return head;
    }
    prev = NULL;
    for (p = head; p != NULL; p = p->next) {
        if (p == node) {
            if (prev == NULL) {
                head = p->next;
            } else {
                prev->next = p->next;
            }
            return head;
        }
        prev = p;
    }
    return head;
}

static inline long Ov010Coll_Count(Ov010Coll *self) {
    u8 r = 0;
    if (self->b0) {
        r = self->count;
    }
    return r;
}

static inline u16 Ov010Coll_Id(Ov010Coll *self, s32 i) {
    u16 r = 0xffff;
    if (self->b0 && i >= 0 && i < self->count) {
        r = self->ids[i];
    }
    return r;
}

static inline BOOL Ov010_ObjGone(void *obj) {
    BOOL r = FALSE;
    if (obj == NULL) {
        r = TRUE;
    } else {
        switch (FLD(s32, obj, 0xd8)) {
        case 0:
        case 1:
        case 2:
        case 3:
            r = TRUE;
            break;
        }
    }
    return r;
}

static inline void Ov010Coll_Kill(Ov010Coll *self, Ov010Node *n) {
    if (self->b0 && n != NULL) {
        Ov010V *obj = (Ov010V *)Ov010_FindObjById(n->id);
        if (obj != NULL) {
            obj->v08();
        }
        self->list = func_ov010_0220db74(self->list, n);
        func_ov003_021d79ac(self->pool, n);
    }
}

static inline void Ov010Coll_KillId(Ov010Coll *self, u16 id) {
    Ov010Node *n;
    if (self->b0) {
        for (n = self->list; n != NULL; n = n->next) {
            if (n->id == id) {
                Ov010Coll_Kill(self, n);
                return;
            }
        }
    }
}

void func_ov010_0220dbc0(Ov010Coll *self) {
    s32 i;
    Ov010Node *n;
    u16 id;
    if (self->b0) {
        self->count = 0;
        for (n = self->list; n != NULL; n = n->next) {
            Ov010_FindObjById(n->id);
            self->ids[self->count] = n->id;
            self->count++;
        }
    }
    for (i = 0; i < Ov010Coll_Count(self); i++) {
        id = Ov010Coll_Id(self, i);
        if (Ov010_ObjGone(Ov010_FindObjById(id))) {
            Ov010Coll_KillId(self, id);
        }
    }
}

}
