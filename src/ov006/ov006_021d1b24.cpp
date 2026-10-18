#include "ov006/Tasks.h"

typedef struct ov006_Unk020706a0 {
    u8 unk0[4];
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
} ov006_Unk020706a0;

extern "C" {

extern void *data_02149ef8;
extern const int data_ov006_021eb77c[];
extern const u8 data_ov006_021eb6fe[];
extern const u8 data_ov006_021eb710[][3];
extern const u16 data_ov006_021eb78c[];
extern ov006_Unk021ebba8 data_ov006_021ebba8;
extern void *data_ov006_021ebec0;

void func_ov006_021e463c(ov006_Unk021ec888 *self);
void func_02040b0c(void *dst, int *dstLen, const void *src, int *srcLen);
void func_ov000_02153c48(ov006_ListNode *a, int b, int c, int d, int e);
void func_ov000_021548cc(void *a, int b);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021d3498(ov006_TaskD1F *self, u16 id, BOOL dir);
ov006_Unk020706a0 *func_020706a0(u16 id);
void func_ov006_021e139c(ov006_Unk021e139c *self, int a, int b, u8 c);
ov006_TaskD1F *func_ov006_021d1f68(ov006_TaskD1F *self);

void func_ov006_021d1b24(ov006_TaskD0C *self) {
    if (!VCALL(self, 28)) {
        return;
    }
    VCALL(self->unk11C, 20);
    VCALL(self->unk120, 20);
    VCALL(self->unk124, 20);
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

static inline bool ov006_Window_Bit1(ov006_Window *self) {
    return (self->flags << 30) >> 31;
}

static inline BOOL ov006_Window_IsBit1(ov006_Window *self) {
    return ov006_Window_Bit1(self) ? TRUE : FALSE;
}

void func_ov006_021d1b8c(ov006_TaskD0C *self) {
    u8 i;
    ov006_Slot *slot;
    ov006_ListNode *item;
    for (i = 0; i < 4; i++) {
        slot = func_ov006_021db060(data_ov006_021ec884, i);
        item = (ov006_ListNode *)func_ov000_02154b58(self->unk11C, i);
        if (slot->active) {
            int srcLen = 0xb;
            int dstLen = 0x30;
            func_02040b0c(self->names[i], &dstLen, slot->name, &srcLen);
            OV006_LISTNODE_SETTEXT(item, self->names[i]);
            item->unk24 = data_ov006_021eb77c[i];
            func_ov000_02153c48(item, 8, 0, 1, 1);
            item->unkC = (u16)(i + 1);
            if (i == data_ov006_021ec884->unk5) {
                ov006_Window *w = self->unk11C;
                if (!(ov006_Window_IsBit1(w) ? TRUE : FALSE)) {
                    w->flags |= 0x2000000;
                }
                VCALL(self->unk11C, A8, item);
                func_ov000_021548cc(self->unk11C, data_ov006_021eb6fe[i]);
                {
                    const u8 *c = data_ov006_021eb710[i];
                    self->unk11C->unk48 = c[0] | (c[1] << 5) | (c[2] << 10);
                }
            }
        } else {
            OV006_LISTNODE_SETTEXT(item, data_ov006_021ebba8.unk4);
            item->unk24 = 0;
            func_ov000_02153c48(item, 8, 0, 0, 0);
            item->unkC = 0xffff;
        }
    }
}

ov006_TaskD1F *func_ov006_021d1dbc(void) {
    ov006_TaskD1F *obj = (ov006_TaskD1F *)func_0203dd9c(sizeof(ov006_TaskD1F));
    if (obj != NULL) {
        obj = func_ov006_021d1f68(obj);
    }
    VCALL(obj, 08, 0x29, 0xc8);
    return obj;
}

BOOL func_ov006_021d1df8(ov006_Window *window, ov006_ListNode *node) {
    ov006_TaskD1F *t;
    u16 id;
    u16 old;
    const void *str;
    ov006_Unk020706a0 *p;
    if (node != NULL) {
        id = node->id;
        t = (ov006_TaskD1F *)window->owner;
        old = t->unk4A;
        t->unk4A = id;
        str = func_0204c0e8(data_02149ef8, data_ov006_021eb78c[(u16)(id & 0xfff)]);
        if (t->unk5C != NULL && str != NULL) {
            func_ov000_0215bb14(t->unk5C, str);
            VCALL(t->unk5C, 70);
        }
        func_ov006_021d3498(t, id, old > id);
        p = func_020706a0(id);
        func_ov006_021e139c(t->gauges[0], p->unk4 << 12, 0xa000, 1);
        func_ov006_021e139c(t->gauges[1], p->unk5 << 12, 0xa000, 1);
        func_ov006_021e139c(t->gauges[2], p->unk6 << 12, 0xa000, 1);
        func_ov006_021e139c(t->gauges[3], p->unk7 << 12, 0xa000, 1);
    }
    return TRUE;
}

BOOL func_ov006_021d1f00(ov006_Window *window, ov006_ListNode *node) {
    int *out = (int *)window->owner;
    if (node != NULL) {
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        *out = node->id;
    } else {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        *out = -1;
    }
    return FALSE;
}

ov006_TaskD1F *func_ov006_021d1f68(ov006_TaskD1F *self) {
    ov006_Slot *slot;
    OV006_TASKBASE_CTOR(&self->base);
    self->base.vtbl = &data_ov006_021ebec0;
    self->base.state = 0;
    self->base.subState = 0;
    self->unk44 = 0;
    self->unk48 = 1;
    self->unk49 = 0;
    self->unk4A = 0xffff;
    slot = func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5);
    if (slot != NULL) {
        self->unk4A = slot->unkC;
    }
    self->unk4C = 0;
    self->unk50 = 0;
    self->unk54 = NULL;
    self->unk58 = NULL;
    self->unk5C = NULL;
    self->unk60 = NULL;
    self->unk64 = NULL;
    return self;
}

static inline void ov006_TaskD1F_Dtor(ov006_TaskD1F *self) {
    int i;
    self->base.vtbl = &data_ov006_021ebec0;
    OV006_DELETE_OBJECT(self->unk54);
    OV006_DELETE_OBJECT(self->unk58);
    OV006_DELETE_OBJECT(self->unk5C);
    OV006_DELETE_OBJECT(self->unk60);
    OV006_DELETE_OBJECT(self->unk64);
    OV006_DELETE_OBJECT(self->unk68);
    for (i = 0; i < 4; i++) {
        OV006_DELETE_OBJECT(self->gauges[i]);
    }
    OV006_TASKBASE_DTOR(&self->base);
}

ov006_TaskD1F *func_ov006_021d2000(ov006_TaskD1F *self) {
    ov006_TaskD1F_Dtor(self);
    return self;
}

ov006_TaskD1F *func_ov006_021d21e4(ov006_TaskD1F *self) {
    ov006_TaskD1F_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
