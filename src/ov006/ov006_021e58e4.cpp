#include "ov006/Window.h"
#include "nitro/mi.h"

typedef struct ov006_Net021e58e4 {
    u8 unk0[0x2c];
    int state;
} ov006_Net021e58e4;

extern "C" {

extern ov006_Net021e58e4 *data_02097e40;
extern void *data_02149ef8;

void *MsgRes_GetString(void *a, int id);
void func_02045094(ov006_Net021e58e4 *net);
BOOL Wh_End(ov006_Net021e58e4 *net);

static inline void ov006_Menu_Advance(ov006_Unk021ec888 *self) {
    if (self->stateTime < 0xff) {
        self->stateTime++;
    }
}

static inline void ov006_Menu_SetState(ov006_Unk021ec888 *self, int state) {
    self->state = state;
    self->stateTime = 0;
}

static inline BOOL ov006_Dialog_IsDone(Lo021cad50 *d) {
    return d->state == 5 ? TRUE : FALSE;
}

static inline void ov006_ObjectHolder_Clear(ov006_ObjectHolder *h) {
    OV006_DELETE_OBJECT(h->obj);
}

static inline void ov006_MenuNode_Delete(ov006_MenuNode *node) {
    OV006_DELETE_OBJECT(node);
}

static inline void ov006_Menu_OpenDialog(ov006_Unk021ec888 *self) {
    ov006_ObjectHolder *h = self->unk1D8;
    ov006_ObjectHolder_Clear(h);
    h->obj = ov006_NewLo021cad50();
    func_ov000_0215c1bc(h->obj, 0x11, MsgRes_GetString(data_02149ef8, 0x172));
    h->obj->posZ = -0x666;
    h->obj->vfunc_08();
    h->obj->flags |= 0x10000;
    h->obj->vfunc_70();
    ov006_Menu_Advance(self);
    data_02097dd0->vblankFunc = NULL;
    func_02045094(data_02097e40);
}

static inline void ov006_Menu_WaitReady(ov006_Unk021ec888 *self) {
    if (data_02097e40->state != 1) {
        return;
    }
    if (!Wh_End(data_02097e40)) {
        return;
    }
    ov006_Menu_Advance(self);
}

static inline void ov006_Menu_Close(ov006_Unk021ec888 *self) {
    BOOL done = TRUE;
    ov006_MenuNode *node;
    int i;
    if (self->unk1D8->obj != NULL && !ov006_Dialog_IsDone(self->unk1D8->obj)) {
        done = FALSE;
    }
    if (!done) {
        return;
    }
    if (self->state != 1 && self->state != 7) {
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
        switch (self->stateTime) {
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
        switch (self->stateTime) {
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
        if (self->state != 3 && self->state != 8 && self->state != 1 && self->state != 7) {
            ov006_Menu_SetState(self, 8);
        }
        break;
    }
}

}
