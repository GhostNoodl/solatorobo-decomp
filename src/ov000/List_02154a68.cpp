#include "ov000/VObj.h"

typedef struct ListEntry {
    const char *name;
    s16 index;
    u16 id;
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    struct ListEntry *prev;
    struct ListEntry *next;
} ListEntry;

typedef struct {
    s32 unk_00;
    u8 unk_04[0x18];
    VObj *unk_1c;
} ListArg;

typedef struct {
    u32 unk_00_0 : 1;
    u32 unk_00_1 : 2;
    u32 unk_00_3 : 29;
} ListSub;

typedef struct {
    u8 unk_00[0x2c];
    u8 unk_2c[0x20];
    u8 unk_4c[0x20];
    u32 unk_6c;
    u8 unk_70[0x18];
    u8 unk_88[0xd8];
} Model;

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

class ListOwner : public VObj {
public:
    u8 unk_04[0x8];
    u32 unk_0c_0 : 1;
    u32 unk_0c_1 : 16;
    u32 unk_0c_17 : 1;
    u32 unk_0c_18 : 2;
    u32 unk_0c_20 : 1;
    u32 unk_0c_21 : 1;
    u32 unk_0c_22 : 10;
    u8 unk_10[0x10];
    s32 unk_20;
    u8 unk_24[0x60];
    u32 unk_84;
    u32 unk_88;
    u32 unk_8c;
    u32 unk_90;
    ListEntry *entries;
    ListEntry *unk_98;
    s16 count;
    u16 unk_9e;
    u16 unk_a0;
    u8 unk_a2[0x2];
    u32 unk_a4;
    ListArg *unk_a8;
    ListSub *unk_ac;
    s8 unk_b0;
    s8 unk_b1;
    u8 unk_b2;
    u8 unk_b3;
    u32 unk_b4;
    Model *unk_b8_model;
    Model *unk_bc;
    u8 unk_c0;
    s8 unk_c1;
    u8 unk_c2;
    u8 unk_c3;
    u32 unk_c4;
    u32 unk_c8;
    u32 unk_cc;
    u32 unk_d0;
};


extern "C" {

extern HeapState *data_02097dd0;

BOOL func_0201e7b0(const char *a, const char *b);
void func_0203de1c(void *ptr);
void *func_0203dd9c(u32 size);
void func_02041558(Model *model);
void func_02041278(void *a);
void func_02041218(void *a);
void func_02041440(Model *model, void *a, s32 b);
void STD_CopyString(void *a, const char *b);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(Model *model, void *a);
void func_02041d9c(Model *model, s32 a, void *b);

static inline ListEntry *FindById(ListOwner *self, u16 id) {
    ListEntry *entry;
    for (entry = self->entries; entry != NULL; entry = entry->next) {
        if (entry->id == id) {
            break;
        }
    }
    return entry;
}

static inline ListEntry *FindByName(ListOwner *self, const char *name) {
    ListEntry *entry;
    for (entry = self->entries; entry != NULL; entry = entry->next) {
        if (!func_0201e7b0(entry->name, name)) {
            break;
        }
    }
    return entry;
}

static inline ListEntry *GetNth(ListEntry *entry, s32 n) {
    while (n-- != 0) {
        entry = entry->next;
    }
    return entry;
}

static inline s32 ListOwner_CalcSize(ListOwner *self) {
    s32 a = self->vfunc_40() * self->unk_20;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 func_ov000_02154638(ListOwner *self) {
    if (*(u32 *)((u8 *)self + 0xc) & 0x20000) {
        s32 ret;
        self->unk_20 += 2;
        ret = ListOwner_CalcSize(self);
        self->unk_20 -= 2;
        return ret;
    }
    return ListOwner_CalcSize(self);
}

void func_ov000_021546ec(ListOwner *self, const char *name, void *a, u32 b) {
    void *saved = data_02097dd0->current;
    Model *model;
    data_02097dd0->current = data_02097dd0->unk_08;
    model = self->unk_b8_model;
    if (model != NULL) {
        if (model != NULL) {
            func_02041558(model);
            func_02041278(model->unk_88);
            func_0203de1c(model);
        }
        self->unk_b8_model = NULL;
    }
    data_02097dd0->current = saved;
    model = (Model *)func_0203dd9c(sizeof(Model));
    if (model != NULL) {
        func_02041218(model->unk_88);
        func_02041440(model, a, 0);
        STD_CopyString(model->unk_2c, name);
    }
    self->unk_b8_model = model;
    func_020417e0(self->unk_b8_model, func_02034d88(func_02035d5c(model->unk_2c), self->unk_b8_model->unk_4c));
    self->unk_b8_model->unk_6c |= 2;
    if (b != 0xffff) {
        func_02041d9c(self->unk_b8_model, 0, (void *)0xffff);
    } else {
        func_02041d9c(self->unk_b8_model, 0, (void *)b);
    }
}

void func_ov000_021547e8(ListOwner *self, const char *name, void *a, void *b) {
    void *saved = data_02097dd0->current;
    Model *model;
    data_02097dd0->current = data_02097dd0->unk_08;
    model = self->unk_bc;
    if (model != NULL) {
        if (model != NULL) {
            func_02041558(model);
            func_02041278(model->unk_88);
            func_0203de1c(model);
        }
        self->unk_bc = NULL;
    }
    data_02097dd0->current = saved;
    model = (Model *)func_0203dd9c(sizeof(Model));
    if (model != NULL) {
        func_02041218(model->unk_88);
        func_02041440(model, a, 0);
        STD_CopyString(model->unk_2c, name);
    }
    self->unk_bc = model;
    func_020417e0(self->unk_bc, func_02034d88(func_02035d5c(model->unk_2c), self->unk_bc->unk_4c));
    self->unk_bc->unk_6c |= 2;
    func_02041d9c(self->unk_bc, 0, b);
}

void func_ov000_021548cc(ListOwner *self, u32 value) {
    if (self->unk_ac != NULL) {
        self->unk_ac->unk_00_1 = value;
    }
}

static inline void ListOwner_ResetFlag0(ListOwner *self) {
    self->unk_0c_0 = 1;
}

void func_ov000_021548ec(ListOwner *self, ListArg *arg) {
    s16 index = self->unk_98->index;
    void *saved;
    self->unk_a8 = arg;
    self->unk_a0 = 0;
    arg->unk_00 = 0;
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (arg->unk_1c != NULL) {
        if (arg->unk_1c != NULL) {
            arg->unk_1c->vfunc_04();
        }
        arg->unk_1c = NULL;
    }
    data_02097dd0->current = saved;
    if (self->count > self->unk_20 && index + self->unk_20 >= self->count) {
        self->unk_0c_21 = 1;
    } else {
        self->unk_0c_20 = 1;
    }
    ListOwner_ResetFlag0(self);
}

void func_ov000_021549a0(ListOwner *self, const char *name, u16 id, u16 a, u32 b) {
    ListEntry *entry = (ListEntry *)func_0203dd9c(sizeof(ListEntry));
    ListEntry *last;
    if (entry != NULL) {
        entry->name = NULL;
        entry->index = 0;
        entry->id = 0;
        entry->unk_08 = 0xffff;
        entry->unk_0a = 0xffff;
        entry->unk_0c = 0;
        entry->unk_10 = 0;
        entry->unk_14 = 0;
        entry->unk_18 = 0;
        entry->unk_1c = 0;
        entry->unk_20 = 0;
        entry->unk_24 = 0;
        entry->prev = NULL;
        entry->next = NULL;
    }
    entry->name = name;
    entry->index = self->count++;
    entry->id = id;
    entry->unk_08 = a;
    entry->unk_0c = b;
    if (self->entries == NULL) {
        self->entries = entry;
        self->unk_98 = entry;
        return;
    }
    last = self->entries;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = entry;
    entry->prev = last;
}

void func_ov000_02154a68(ListOwner *self, u16 id, u16 a, u32 b) {
    ListEntry *entry = FindById(self, id);
    entry->unk_08 = a;
    entry->unk_0c = b;
}

void func_ov000_02154a98(ListOwner *self, const char *name, u16 a, u32 b) {
    ListEntry *entry = FindByName(self, name);
    entry->unk_08 = a;
    entry->unk_0c = b;
}

void func_ov000_02154ae0(ListOwner *self, u16 id, u32 b, u16 a) {
    ListEntry *entry = FindById(self, id);
    entry->unk_0c = b;
    entry->unk_08 = a;
}

void func_ov000_02154b10(ListOwner *self, const char *name, u32 b, u16 a) {
    ListEntry *entry = FindByName(self, name);
    entry->unk_0c = b;
    entry->unk_08 = a;
}

ListEntry *func_ov000_02154b58(ListOwner *self, u16 id) {
    return FindById(self, id);
}

ListEntry *func_ov000_02154b80(ListOwner *self, s32 n) {
    ListEntry *entry = self->entries;
    if (n <= 0) {
        return entry;
    }
    return GetNth(entry, n);
}

void func_ov000_02154bac(ListOwner *self) {
    *(u32 *)&((u8 *)self)[0xc] = 0x2070000;
    self->unk_84 = 0;
    self->unk_88 = 0;
    self->unk_8c = 0;
    self->unk_90 = 0;
    self->entries = NULL;
    self->unk_98 = NULL;
    self->count = 0;
    self->unk_a4 = 0;
    self->unk_9e = 0;
    self->unk_a8 = 0;
    self->unk_a0 = 0;
    self->unk_b1 = 0;
    self->unk_b0 = -1;
    self->unk_ac = 0;
    self->unk_b2 = 0;
    self->unk_b3 = 0;
    self->unk_b8_model = NULL;
    self->unk_bc = 0;
    self->unk_b4 = 0;
    self->unk_c0 = 0;
    self->unk_c1 = 5;
    self->unk_c4 = 0;
    self->unk_c8 = 0;
    self->unk_c2 = 0;
    self->unk_c3 = 0;
    self->unk_cc = 0;
    self->unk_d0 = 0;
}

}
