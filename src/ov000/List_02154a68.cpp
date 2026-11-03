#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"
#include "ov000/UiObj.h"
#include "Main/Res/ResArc.h"


typedef struct {
    s32 unk_00;
    u8 unk_04[0x18];
    VObj *unk_1c;
} ListArg;





extern "C" {


void Heap_Free(void *ptr);
void *Heap_Alloc(u32 size);

static inline UiListItem *FindById(UiList *self, u16 id) {
    UiListItem *entry;
    for (entry = self->items; entry != NULL; entry = entry->next) {
        if (entry->id == id) {
            break;
        }
    }
    return entry;
}

static inline UiListItem *FindByName(UiList *self, const char *name) {
    UiListItem *entry;
    for (entry = self->items; entry != NULL; entry = entry->next) {
        if (!STD_CompareString(entry->name, name)) {
            break;
        }
    }
    return entry;
}

static inline UiListItem *GetNth(UiListItem *entry, s32 n) {
    while (n-- != 0) {
        entry = entry->next;
    }
    return entry;
}

static inline s32 ListOwner_CalcSize(UiList *self) {
    s32 a = self->vfunc_40() * self->rows;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 UiList_GetHeight(UiList *self) {
    if (*(u32 *)((u8 *)self + 0xc) & 0x20000) {
        s32 ret;
        self->rows += 2;
        ret = ListOwner_CalcSize(self);
        self->rows -= 2;
        return ret;
    }
    return ListOwner_CalcSize(self);
}

void UiList_SetIconModel(UiList *self, const char *name, void *a, u32 b) {
    void *saved = gSysState->cur;
    Model *model;
    gSysState->cur = gSysState->heapHi;
    model = self->unk_b8;
    if (model != NULL) {
        if (model != NULL) {
            TexObj_Release(model);
            PlttRes_Release(&model->pltt);
            Heap_Free(model);
        }
        self->unk_b8 = NULL;
    }
    gSysState->cur = saved;
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        PlttRes_Init_02041218(&model->pltt);
        TexObj_Init(model, (const char *)a, 0);
        STD_CopyString(model->name, name);
    }
    self->unk_b8 = model;
    TexObj_SetRes(self->unk_b8, ResList_FindType2(ResMgr_GetArcList(model->name), self->unk_b8->unk_04c));
    self->unk_b8->flags |= 2;
    if (b != 0xffff) {
        TexObj_SelectImage(self->unk_b8, 0, 0xffff);
    } else {
        TexObj_SelectImage(self->unk_b8, 0, b);
    }
}

void UiList_SetMarkModel(UiList *self, const char *name, void *a, void *b) {
    void *saved = gSysState->cur;
    Model *model;
    gSysState->cur = gSysState->heapHi;
    model = self->unk_bc;
    if (model != NULL) {
        if (model != NULL) {
            TexObj_Release(model);
            PlttRes_Release(&model->pltt);
            Heap_Free(model);
        }
        self->unk_bc = NULL;
    }
    gSysState->cur = saved;
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        PlttRes_Init_02041218(&model->pltt);
        TexObj_Init(model, (const char *)a, 0);
        STD_CopyString(model->name, name);
    }
    self->unk_bc = model;
    TexObj_SetRes(self->unk_bc, ResList_FindType2(ResMgr_GetArcList(model->name), self->unk_bc->unk_04c));
    self->unk_bc->flags |= 2;
    TexObj_SelectImage(self->unk_bc, 0, (int)b);
}

void UiList_SetPanelColor(UiList *self, u32 value) {
    if (self->panel != NULL) {
        self->panel->bits.b1 = value;
    }
}

static inline void ListOwner_ResetFlag0(UiList *self) {
    self->busy = 1;
}

void UiList_RemoveItem(UiList *self, ListArg *arg) {
    s16 index = self->topItem->index;
    void *saved;
    self->unk_a8 = (void *)arg;
    self->unk_a0 = 0;
    arg->unk_00 = 0;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (arg->unk_1c != NULL) {
        if (arg->unk_1c != NULL) {
            arg->unk_1c->vfunc_04();
        }
        arg->unk_1c = NULL;
    }
    gSysState->cur = saved;
    if (self->itemCount > self->rows && index + self->rows >= self->itemCount) {
        self->flag21 = 1;
    } else {
        self->flag20 = 1;
    }
    ListOwner_ResetFlag0(self);
}

void UiList_AddItem(UiList *self, const char *name, u16 id, u16 a, u32 b) {
    UiListItem *entry = (UiListItem *)Heap_Alloc(sizeof(UiListItem));
    UiListItem *last;
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
        entry->label = 0;
        entry->unk_20 = 0;
        entry->unk_24 = 0;
        entry->prev = NULL;
        entry->next = NULL;
    }
    entry->name = name;
    entry->index = self->itemCount++;
    entry->id = id;
    entry->unk_08 = a;
    entry->unk_0c = b;
    if (self->items == NULL) {
        self->items = entry;
        self->topItem = entry;
        return;
    }
    last = self->items;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = entry;
    entry->prev = last;
}

void UiList_SetItemArgsById(UiList *self, u16 id, u16 a, u32 b) {
    UiListItem *entry = FindById(self, id);
    entry->unk_08 = a;
    entry->unk_0c = b;
}

void UiList_SetItemArgsByName(UiList *self, const char *name, u16 a, u32 b) {
    UiListItem *entry = FindByName(self, name);
    entry->unk_08 = a;
    entry->unk_0c = b;
}

void UiList_SetItemArgsByIdRev(UiList *self, u16 id, u32 b, u16 a) {
    UiListItem *entry = FindById(self, id);
    entry->unk_0c = b;
    entry->unk_08 = a;
}

void UiList_SetItemArgsByNameRev(UiList *self, const char *name, u32 b, u16 a) {
    UiListItem *entry = FindByName(self, name);
    entry->unk_0c = b;
    entry->unk_08 = a;
}

UiListItem *UiList_GetItemById(UiList *self, u16 id) {
    return FindById(self, id);
}

UiListItem *ListOwner_GetNth(UiList *self, s32 n) {
    UiListItem *entry = self->items;
    if (n <= 0) {
        return entry;
    }
    return GetNth(entry, n);
}

void UiList_Init(UiList *self) {
    *(u32 *)&((u8 *)self)[0xc] = 0x2070000;
    self->onDecide = 0;
    self->onCursor = 0;
    self->unk_8c = 0;
    self->unk_90 = 0;
    self->items = NULL;
    self->topItem = NULL;
    self->itemCount = 0;
    self->unk_a4 = 0;
    self->unk_9e = 0;
    self->unk_a8 = 0;
    self->unk_a0 = 0;
    self->cursor = 0;
    self->unk_b0 = -1;
    self->panel = 0;
    self->unk_b2 = 0;
    self->unk_b3 = 0;
    self->unk_b8 = NULL;
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
