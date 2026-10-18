#include "ov006/Tasks.h"
#include "ov006/SlotManager.h"


extern "C" {

extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021cad50;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cb4a8;
extern void *data_ov000_021cadcc;
extern char data_ov006_021ebc02[];
extern ov006_Unk021ebba8 data_ov006_021ebba8;
extern void *data_ov006_021ebf40;

BOOL func_0201fd04(void);
void func_ov006_021e4c38(ov006_Unk021ec888 *self);
void func_ov006_021e4c84(ov006_Unk021ec888 *self);
void func_ov006_021e4c5c(ov006_Unk021ec888 *self);
void func_ov006_021e4cb4(ov006_Unk021ec888 *self);
void func_ov006_021e4ce8(ov006_Unk021ec888 *self, ov006_MenuData *data);
void func_ov006_021e463c(ov006_Unk021ec888 *self);
ov006_MenuNode *func_ov006_021e48c0(ov006_Unk021ec888 *self, int id);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(void *a, int b, const void *c);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov000_02157c90(void *a, const void *b);
void func_ov000_02157d2c(void *a, const void *b);
void func_ov000_02173648(void *self);
void func_ov000_02153c48(ov006_ListNode *a, int b, int c, int d, int e);
void MIi_CpuClear32(int value, void *dst, u32 size);
void func_02040b0c(void *dst, int *dstLen, const void *src, int *srcLen);
void func_0201e5a0(void *dst, const void *src, u32 size);
void func_ov006_021d0ab8(ov006_TaskD0 *self);

BOOL func_ov006_021d01ac(ov006_TaskD0 *self) {
    BOOL r = FALSE;
    switch (self->base.state) {
    case 0:
        if (!func_0201fd04()) {
            self->base.state = 0;
            r = TRUE;
            self->unk110 = TRUE;
        } else if (data_ov006_021ec888->unk8 == 1) {
            func_ov006_021e4c38(data_ov006_021ec888);
            self->base.state = 1;
        }
        break;
    case 1:
        if (data_ov006_021ec888->unk8 == 3) {
            func_ov006_021e4c84(data_ov006_021ec888);
            self->base.state = 2;
        }
        break;
    default:
        r = TRUE;
        break;
    }
    return r;
}

static inline ov006_Window *ov006_NewWindow_cad50(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe8);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cad50;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cb4a8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe0);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb4a8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cadcc(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x8c);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cadcc;
        VCALL(w, 28);
    }
    return w;
}

void func_ov006_021d023c(ov006_TaskD0 *self) {
    ov006_ListNode *item;
    u16 i;
    void *res;
    if (VCALL(self, 28)) {
        return;
    }
    res = data_02149ef8;
    if (self->unk110) {
        self->unk10C = ov006_NewWindow_cad50();
        VCALL(self->unk10C, 08);
        func_ov000_0215c1bc(self->unk10C, 0x8000, func_0204c0e8(res, 0x19e));
        VCALL(self->unk10C, 70);
        self->base.flags &= ~2;
        func_ov000_02173648(self);
        return;
    }
    self->unk104 = ov006_NewWindow_cb4a8();
    VCALL(self->unk104, 10, func_0204c0e8(res, 0x12d));
    VCALL(self->unk104, 14, func_0204c0e8(res, 0x12e));
    func_ov000_02157c90(self->unk104, func_0204c0e8(res, 0x12f));
    func_ov000_02157d2c(self->unk104, func_0204c0e8(res, 0x130));
    self->unk104->unk4A = 0x2c00;
    self->unk104->unk20 = 5;
    ov006_Window_SetRot(self->unk104, 0, 0x2c, -0x1ccd);
    ov006_Window_SetPos(self->unk104, -0x100, 0, -0x1ccd);
    self->unk104->flags |= 0x400000;
    self->unk104->flags &= ~0x800000;
    self->unk104->unkC0 = 0x8c;
    self->unk104->unkC1 = 1;
    self->unk104->flags &= ~0x20000;
    self->unk104->flags &= ~0x40000;
    self->unk104->flags &= ~0x10000;
    for (i = 0; i < 4; i++) {
        item = (ov006_ListNode *)VCALL(self->unk104, 74, data_ov006_021ebc02, i, 0xffff, 0);
        item->unk10 = 0;
    }
    item = (ov006_ListNode *)VCALL(self->unk104, 74, func_0204c0e8(res, 0x131), i, 0xffff, 0xffff);
    item->unk24 = 4;
    item->unk10 = 0;
    {
        ov006_Window *w = self->unk104;
        VCALL(w, A8, func_ov000_02154b58(w, 0));
    }
    VCALL(self->unk104, 08);
    self->unk104->flags &= ~2;
    self->unk108 = ov006_NewWindow_cadcc();
    self->unk108->unk24 = 0xf8;
    self->unk108->unk20 = 2;
    ov006_Window_SetRot(self->unk108, 4, 0x95, -0x199a);
    ov006_Window_SetPos(self->unk108, -0x100, 0, -0x199a);
    self->unk108->unk2C = 1;
    VCALL(self->unk108, 08);
    func_ov000_0215bb14(self->unk108, func_0204c0e8(res, 0x132));
    VCALL(self->unk108, 70);
    self->base.unk20 = self->unk104->unk34;
    self->base.flags &= ~2;
    func_ov000_02173648(self);
}

static inline void ov006_TaskD0_HideWindows(ov006_TaskD0 *self) {
    if (self->unk110) {
        self->unk10C->flags |= 2;
        return;
    }
    self->unk104->flags |= 2;
    self->unk108->flags |= 2;
}

static inline void ov006_TaskD0_Close(ov006_TaskD0 *self) {
    self->base.flags |= 6;
    self->base.f.b0 = 1;
}

void func_ov006_021d065c(ov006_TaskD0 *self) {
    u16 trg = data_02097dc8->unk12;
    if (self->unk110) {
        if (trg & 1) {
            ov006_TaskD0_Close(self);
            ov006_TaskD0_HideWindows(self);
        }
    } else if (trg & 2) {
        self->base.subState = 0;
        self->unk104->flags &= ~0x2000000;
        ov006_TaskD0_Close(self);
        ov006_TaskD0_HideWindows(self);
        func_ov006_021e4c5c(data_ov006_021ec888);
    } else if (trg & 1) {
        ov006_ListNode *node = ov006_Window_GetSelected(self->unk104);
        if (node->unk10 == 0) {
            if (node->id == 4) {
                func_ov006_021e4cb4(data_ov006_021ec888);
                data_ov006_021ec888->unk15E = 2;
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                ov006_TaskD0_Close(self);
                self->base.subState = 2;
                ov006_TaskD0_HideWindows(self);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
        } else if (node->unkC >= 4) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            ov006_MenuNode *menu = func_ov006_021e48c0(data_ov006_021ec888, node->unk10);
            if (menu != NULL) {
                func_ov006_021e4ce8(data_ov006_021ec888, &menu->data);
                data_ov006_021ec888->unk15E = 2;
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                self->base.subState = 1;
                ov006_TaskD0_Close(self);
                ov006_TaskD0_HideWindows(self);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
                func_ov006_021d0ab8(self);
            }
        }
    }
}

void func_ov006_021d0938(ov006_TaskD0 *self) {
    if (self->unk110) {
        VCALL(self->unk10C, 1C);
        return;
    }
    if (!data_ov006_021ec888->unk2C && data_ov006_021ec888->unk26) {
        func_ov006_021d0ab8(self);
        data_ov006_021ec888->unk26 = 0;
    }
    VCALL(self->unk104, 1C);
    VCALL(self->unk108, 1C);
}

void func_ov006_021d09b8(ov006_TaskD0 *self) {
    if (self->base.unk8 != 0) {
        return;
    }
    if (self->base.subState == 3) {
        return;
    }
    switch (self->base.subState) {
    case 0:
        func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
        break;
    case 1:
        func_ov000_0218084c(data_ov000_021ccd44, 0x28, 2);
        break;
    case 2:
        func_ov000_0218084c(data_ov000_021ccd44, 0x28, 1);
        break;
    }
    self->base.subState = 3;
}

void func_ov006_021d0a40(ov006_TaskD0 *self) {
    if (!VCALL(self, 28)) {
        return;
    }
    if (self->unk110) {
        VCALL(self->unk10C, 20);
        return;
    }
    VCALL(self->unk104, 20);
    VCALL(self->unk108, 20);
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

void func_ov006_021d0ab8(ov006_TaskD0 *self) {
    u16 j;
    ov006_ListNode *item;
    int id;
    u16 i;
    ov006_MenuNode *node;
    int ids[4];
    if (self->unk104 == NULL) {
        return;
    }
    i = 0;
    MIi_CpuClear32(0, ids, sizeof(ids));
    for (node = data_ov006_021ec888->nodes; node != NULL; node = node->next) {
        ids[i] = node->id;
        i++;
        if (i >= 4) {
            break;
        }
    }
    for (j = 0; j < 4; j++) {
        u32 v;
        item = (ov006_ListNode *)func_ov000_02154b58(self->unk104, j);
        id = ids[j];
        if (id != 0) {
            int srcLen;
            int dstLen;
            ov006_MenuNode *menu = func_ov006_021e48c0(data_ov006_021ec888, id);
            srcLen = 0xb;
            dstLen = 0x30;
            func_02040b0c(self->names[j], &dstLen, (u8 *)menu + 0x60, &srcLen);
            v = ((u8 *)menu)[0x77];
        } else {
            func_0201e5a0(self->names[j], data_ov006_021ebba8.unk4, 0x30);
            v = 0;
        }
        item->unkC = v;
        item->unk10 = id;
        item->unk24 = v < 4 ? 0 : 0xe;
        item->text = NULL;
        OV006_DELETE_OBJECT(item->unk1C);
        item->text = self->names[j];
        func_ov000_02153c48(item, 8, 0, 1, 1);
    }
}

static inline void ov006_SlotPacked_Clear(ov006_SlotPacked *self) {
    self->active = 0;
    self->isType1 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk0_8 = 0;
    func_02016e28(self->name, 0, sizeof(self->name));
}

static inline void ov006_TaskD0C_Init(ov006_TaskD0C *self) {
    OV006_TASKBASE_CTOR(self);
    self->vtbl = &data_ov006_021ebf40;
    self->unk3C = 0;
    self->unk3D = 0;
    self->unk40 = 0;
    func_02016e28(self->names, 0, sizeof(self->names));
    self->unk101 = 0;
    ov006_SlotPacked_Clear(&self->unk102);
    self->unk11C = NULL;
    self->unk120 = NULL;
    self->unk124 = NULL;
}

ov006_TaskD0C *func_ov006_021d0c64(void) {
    ov006_TaskD0C *self = (ov006_TaskD0C *)func_0203dd9c(sizeof(ov006_TaskD0C));
    if (self != NULL) {
        ov006_TaskD0C_Init(self);
    }
    VCALL(self, 08, 0x28, 200);
    return self;
}

static inline void ov006_TaskD0C_Dtor(ov006_TaskD0C *self) {
    self->vtbl = &data_ov006_021ebf40;
    OV006_DELETE_OBJECT(self->unk11C);
    OV006_DELETE_OBJECT(self->unk120);
    OV006_DELETE_OBJECT(self->unk124);
    OV006_TASKBASE_DTOR(self);
}

ov006_TaskD0C *func_ov006_021d0d3c(ov006_TaskD0C *self) {
    ov006_TaskD0C_Dtor(self);
    return self;
}

ov006_TaskD0C *func_ov006_021d0e3c(ov006_TaskD0C *self) {
    ov006_TaskD0C_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
