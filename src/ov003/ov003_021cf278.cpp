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

class Ov003RelObj {
public:
    virtual void v00();
    virtual void Release();
};

typedef struct {
    u8 flag : 1;
    u16 unk_02;
    Ov003VObj *obj;
} Ov003Item;

typedef struct Ov003Link {
    u16 key;
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
extern u32 STD_GetStringLength(const char *s);
extern void *func_0203dddc(u32 size);
extern void STD_CopyLString(void *dst, const void *src, u32 size);
extern void func_0203de1c(void *p);
void func_ov003_021cf5e8(Ov003Group *self);

extern u8 data_ov003_021f7984[];
extern void *func_0203dd9c(u32 size);

void func_ov003_021cf1f0(Ov003EntryList *self, u16 id, u16 max, u32 c) {
    Ov003Entry *e = (Ov003Entry *)func_0203dd9c(sizeof(Ov003Entry));
    Ov003Entry *p;
    if (e != NULL) {
        e->vtbl = data_ov003_021f7984;
        e->id = id;
        e->max = max;
        e->val = 0;
        e->unk_0c = c;
        e->next = NULL;
    }
    if (self->head == NULL) {
        self->head = e;
        self->cur = e;
    } else {
        p = self->head;
        while (p != NULL) {
            if (p->next == NULL) {
                break;
            }
            p = p->next;
        }
        p->next = e;
    }
    self->count++;
}

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
    n = STD_GetStringLength(str) + 1;
    buf = func_0203dddc(n * 2 - n);
    STD_CopyLString(buf, str, STD_GetStringLength(str) + 1);
}

void func_ov003_021cf39c(void *self, const char *str) {
    void *old = data_02097dd0->cur;
    void *buf;
    u32 n;
    data_02097dd0->cur = data_02097dd0->alt;
    data_02097dd0->cur = old;
    n = STD_GetStringLength(str) + 1;
    buf = func_0203dddc(n * 2 - n);
    STD_CopyLString(buf, str, STD_GetStringLength(str) + 1);
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

Ov003Link *func_ov003_021cf6e8(Ov003Link *head, Ov003Link *n);

void *func_ov003_021cf52c(Ov003Group *self, void *obj, u16 key4, u16 key8) {
    void *ret = NULL;
    if (self->active) {
        Ov003Item *item;
        Ov003Link *a;
        Ov003Link *b;
        ret = obj;
        item = (Ov003Item *)func_0203dd9c(sizeof(Ov003Item));
        a = (Ov003Link *)func_0203dd9c(sizeof(Ov003Link));
        b = (Ov003Link *)func_0203dd9c(sizeof(Ov003Link));
        item->flag = 0;
        item->unk_02 = self->unk_02;
        item->obj = (Ov003VObj *)obj;
        a->item = item;
        a->key = key4;
        a->next = NULL;
        b->item = item;
        b->key = key8;
        b->next = NULL;
        self->unk_02++;
        self->list4 = func_ov003_021cf6e8(self->list4, a);
        self->list8 = func_ov003_021cf6e8(self->list8, b);
    }
    return ret;
}

void func_ov003_021cf5e8(Ov003Group *self) {
    Ov003Link *next;
    Ov003Link *l;
    if (!self->active) {
        return;
    }
    for (l = self->list4; l != NULL; l = next) {
        void *old;
        next = l->next;
        if (l->item->flag) {
            old = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->alt;
            if (l->item->obj != NULL) {
                Ov003RelObj *o = (Ov003RelObj *)l->item->obj;
                if (o != NULL) {
                    o->Release();
                }
                l->item->obj = NULL;
            }
            data_02097dd0->cur = old;
        }
        old = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->alt;
        if (l->item != NULL) {
            func_0203de1c(l->item);
            l->item = NULL;
        }
        data_02097dd0->cur = old;
        func_0203de1c(l);
    }
    self->list4 = NULL;
    for (l = self->list8; l != NULL; l = next) {
        next = l->next;
        func_0203de1c(l);
    }
    self->list8 = NULL;
    self->unk_02 = 0;
}

Ov003Link *func_ov003_021cf6e8(Ov003Link *head, Ov003Link *n) {
    Ov003Link *ret = NULL;
    Ov003Link *prev = NULL;
    Ov003Link *cur;
    if (n == NULL) {
        ret = head;
    } else if (head == NULL) {
        ret = n;
        n->next = prev;
    } else {
        for (cur = head; cur != NULL; cur = cur->next) {
            if (n->key >= cur->key) {
                if (prev == NULL) {
                    n->next = head;
                    ret = n;
                } else {
                    prev->next = n;
                    ret = head;
                    n->next = cur;
                }
                break;
            }
            prev = cur;
        }
        if (prev != NULL && prev->next == NULL) {
            prev->next = n;
            ret = head;
            n->next = NULL;
        }
    }
    return ret;
}

}
