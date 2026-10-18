#include "types.h"

typedef void (*VFunc)(void *);

typedef struct Ov003Entry {
    void *vtbl;
    u16 id;
    u16 max;
    u16 val;
    u16 unk_0a;
    u32 unk_0c;
    struct Ov003Entry *next;
} Ov003Entry;

typedef struct {
    u32 unk_00;
    Ov003Entry *head;
    u16 count;
    u16 unk_0a;
    Ov003Entry *cur;
} Ov003EntryList;

class Ov003FlagObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
};

typedef struct {
    void **vtbl;
} Ov003VObj;

typedef struct {
    u32 unk_00;
    Ov003VObj *obj;
} Ov003Item;

typedef struct Ov003Link {
    u32 unk_00;
    Ov003Item *item;
    struct Ov003Link *next;
} Ov003Link;

typedef struct {
    u8 active : 1;
    u16 unk_02;
    Ov003Link *list4;
    Ov003Link *list8;
} Ov003Group;

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

extern "C" {

extern u32 data_ov003_021f79a8;
extern Ov003HeapCtx *data_02097dd0;
extern u32 func_0201e708(const char *s);
extern void *func_0203dddc(u32 size);
extern void func_0201e5a0(void *dst, const void *src, u32 size);
extern void func_0203de1c(void *p);
extern void func_ov003_021cf5e8(Ov003Group *self);

Ov003Entry *func_ov003_021cf278(Ov003EntryList *self, u16 id, u16 val) {
    Ov003Entry *e;
    for (e = self->head; e != NULL; e = e->next) {
        if (id == e->id) {
            break;
        }
    }
    if (e != NULL) {
        self->cur = e;
        if (val < e->max) {
            e->val = val;
        }
    }
    return self->cur;
}

Ov003FlagObj *func_ov003_021cf2bc(Ov003FlagObj *self) {
    *(void **)self = &data_ov003_021f79a8;
    self->active = 0;
    return self;
}

Ov003FlagObj *func_ov003_021cf2d8(Ov003FlagObj *self) {
    *(void **)self = &data_ov003_021f79a8;
    self->Release();
    return self;
}

Ov003FlagObj *func_ov003_021cf300(Ov003FlagObj *self) {
    *(void **)self = &data_ov003_021f79a8;
    self->Release();
    func_0203de1c(self);
    return self;
}

int func_ov003_021cf330() {
    return 1;
}

void func_ov003_021cf338() {
}

void func_ov003_021cf33c() {
}

void func_ov003_021cf340(const char *str) {
    void *old = data_02097dd0->cur;
    void *buf;
    u32 n;
    data_02097dd0->cur = data_02097dd0->alt;
    data_02097dd0->cur = old;
    n = func_0201e708(str) + 1;
    buf = func_0203dddc(n * 2 - n);
    func_0201e5a0(buf, str, func_0201e708(str) + 1);
}

void func_ov003_021cf39c(void *self, const char *str) {
    void *old = data_02097dd0->cur;
    void *buf;
    u32 n;
    data_02097dd0->cur = data_02097dd0->alt;
    data_02097dd0->cur = old;
    n = func_0201e708(str) + 1;
    buf = func_0203dddc(n * 2 - n);
    func_0201e5a0(buf, str, func_0201e708(str) + 1);
}

void func_ov003_021cf3fc() {
}

void func_ov003_021cf400() {
}

#pragma force_active on
void func_ov003_021cf404() {
}
#pragma force_active reset

int func_ov003_021cf408() {
    return 0;
}

void func_ov003_021cf410() {
}

void func_ov003_021cf414() {
}

void func_ov003_021cf418(Ov003Group *self) {
    self->active = 0;
}

Ov003Group *func_ov003_021cf428(Ov003Group *self) {
    if (self->active) {
        func_ov003_021cf5e8(self);
        self->active = 0;
    }
    return self;
}

#pragma force_active on
BOOL func_ov003_021cf458(Ov003Group *self) {
    self->active = 1;
    self->unk_02 = 0;
    self->list4 = NULL;
    self->list8 = NULL;
    return TRUE;
}
#pragma force_active reset

void func_ov003_021cf480(Ov003Group *self) {
    if (self->active) {
        func_ov003_021cf5e8(self);
        self->active = 0;
    }
}

#pragma force_active on
void func_ov003_021cf4ac(Ov003Group *self) {
    Ov003Link *l;
    if (self->active) {
        for (l = self->list4; l != NULL; l = l->next) {
            ((VFunc)l->item->obj->vtbl[3])(l->item->obj);
        }
    }
}
#pragma force_active reset

void func_ov003_021cf4ec(Ov003Group *self) {
    Ov003Link *l;
    if (self->active) {
        for (l = self->list8; l != NULL; l = l->next) {
            ((VFunc)l->item->obj->vtbl[4])(l->item->obj);
        }
    }
}

}
