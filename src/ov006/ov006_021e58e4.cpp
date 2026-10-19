#include "ov006/ov006.h"
#include "nitro/mi.h"

typedef struct ov006_Dialog021e58e4 {
    ObjectVtbl *vtbl;
    int state;
    u8 unk8[4];
    u32 flags;
    u8 unk10[0x58];
    s16 unk68;
} ov006_Dialog021e58e4;

typedef struct ov006_Net021e58e4 {
    u8 unk0[0x2c];
    int state;
} ov006_Net021e58e4;

extern "C" {

extern ov006_Net021e58e4 *data_02097e40;
extern void *data_02149ef8;
extern void *data_ov000_021cac60[];
extern void *data_ov000_021cad50[];

void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(void *a, int b, void *c);
void func_02045094(ov006_Net021e58e4 *net);
BOOL func_02044f70(ov006_Net021e58e4 *net);

static inline void ov006_Menu_Advance(ov006_Unk021ec888 *self) {
    if (self->unkC < 0xff) {
        self->unkC++;
    }
}

static inline void ov006_Menu_SetState(ov006_Unk021ec888 *self, int state) {
    self->unk8 = state;
    self->unkC = 0;
}

static inline BOOL ov006_Dialog_IsDone(ov006_Dialog021e58e4 *d) {
    return d->state == 5 ? TRUE : FALSE;
}

static inline void ov006_ObjectHolder_Clear(ov006_ObjectHolder *h) {
    OV006_DELETE_OBJECT(h->obj);
}

static inline void ov006_MenuNode_Delete(ov006_MenuNode *node) {
    OV006_DELETE_OBJECT(node);
}

static inline Object *ov006_NewDialog(void) {
    Object *obj = (Object *)func_0203dd9c(0xe8);
    if (obj != NULL) {
        obj->vtbl = (ObjectVtbl *)data_ov000_021cac60;
        ((VObj *)obj)->v28();
        obj->vtbl = (ObjectVtbl *)data_ov000_021cad50;
        ((VObj *)obj)->v28();
    }
    return obj;
}

static inline void ov006_Menu_OpenDialog(ov006_Unk021ec888 *self) {
    ov006_ObjectHolder *h = self->unk1D8;
    ov006_ObjectHolder_Clear(h);
    h->obj = ov006_NewDialog();
    func_ov000_0215c1bc(h->obj, 0x11, func_0204c0e8(data_02149ef8, 0x172));
    ((ov006_Dialog021e58e4 *)h->obj)->unk68 = -0x666;
    ((VObj *)h->obj)->v08();
    ((ov006_Dialog021e58e4 *)h->obj)->flags |= 0x10000;
    ((VObj *)h->obj)->v70();
    ov006_Menu_Advance(self);
    data_02097dd0->unk18 = 0;
    func_02045094(data_02097e40);
}

static inline void ov006_Menu_WaitReady(ov006_Unk021ec888 *self) {
    if (data_02097e40->state != 1) {
        return;
    }
    if (!func_02044f70(data_02097e40)) {
        return;
    }
    ov006_Menu_Advance(self);
}

static inline void ov006_Menu_Close(ov006_Unk021ec888 *self) {
    BOOL done = TRUE;
    ov006_MenuNode *node;
    int i;
    if (self->unk1D8->obj != NULL && !ov006_Dialog_IsDone((ov006_Dialog021e58e4 *)self->unk1D8->obj)) {
        done = FALSE;
    }
    if (!done) {
        return;
    }
    if (self->unk8 != 1 && self->unk8 != 7) {
        ov006_Menu_SetState(self, 7);
    }
    node = self->nodes;
    while (node != NULL) {
        ov006_MenuNode *next = node->next;
        ov006_MenuNode_Delete(node);
        node = next;
    }
    self->unk26 = 1;
    self->nodes = NULL;
    self->unk24 = 0;
    for (i = 0; i < 4; i++) {
        ov006_MenuEntry *e = &self->entries[i];
        e->unk0_0 = 0;
        e->unk0_4 = 0;
        MIi_CpuClear16(0, e->unk2, 0x1a);
    }
    self->unk1C = 0;
}

void func_ov006_021e58e4(ov006_Unk021ec888 *self) {
    switch (self->unk1C) {
    case 1:
    case 4:
        switch (self->unkC) {
        case 0:
            ov006_Menu_OpenDialog(self);
            break;
        case 1:
            ov006_Menu_WaitReady(self);
            break;
        case 2:
            ov006_Menu_Close(self);
            break;
        }
        break;
    case 2:
    case 3:
        switch (self->unkC) {
        case 0:
            ov006_Menu_OpenDialog(self);
        case 1:
            ov006_Menu_WaitReady(self);
            break;
        case 2:
            ov006_Menu_Close(self);
            break;
        }
        break;
    default:
        self->unk1C = 0;
        if (self->unk8 != 3 && self->unk8 != 8 && self->unk8 != 1 && self->unk8 != 7) {
            ov006_Menu_SetState(self, 8);
        }
        break;
    }
}

}
