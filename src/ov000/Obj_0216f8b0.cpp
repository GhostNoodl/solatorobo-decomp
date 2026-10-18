#include "ov000/MessageQueue.h"

typedef struct {
    u8 pad_00[0xc];
    MessageQueue *unk_0c;
    u8 pad_10[0x10];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    ListBuffer *unk_30;
} Obj0216f8b0;

extern "C" {
extern s32 data_02097d78[];
extern u8 data_ov000_021cb6b0[];
extern u8 data_ov000_021cb6d0[];
void *func_0203dd9c(u32 size);
void func_ov000_0216f1ac(ListBuffer *buf, BufferList *list);
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_ov000_021643e8(void *self);

}

static inline BOOL Fade0216f8b0_Idle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[1] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL Fade0216f8b0_Busy(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[1] == 4 ? TRUE : FALSE;
}

static inline ListBuffer *MessageQueue_AddBuffer(MessageQueue *self, ListBuffer *buf, u32 priority, void *owner) {
    ListBuffer *b = buf;
    BOOL allocated = FALSE;
    if (b == NULL) {
        allocated = TRUE;
        b = (ListBuffer *)func_0203dd9c(0x20);
        if (b != NULL) {
            VOBJ_SET_VTABLE(b, data_ov000_021cb6d0);
            b->flags = 0;
            b->priority = 0;
            b->unk_0c = 0;
            b->unk_10 = 0;
            b->unk_14 = 0;
            b->prev = NULL;
            b->next = NULL;
        }
    }
    b->flags = 1;
    b->priority = priority;
    b->unk_10 = 0;
    b->unk_14 = 0;
    b->unk_0c = (u32)owner;
    func_ov000_0216f1ac(b, &self->list);
    if (allocated) {
        b->flags |= 0x10;
    }
    return b;
}

extern "C" {

void func_ov000_0216f8b0(Obj0216f8b0 *self) {
    MessageQueue *q = self->unk_0c;
    switch (self->unk_20) {
    case 3:
        switch (self->unk_24) {
        case 0:
            if (Fade0216f8b0_Idle()) {
                func_0203c9e8(0x3f, 1);
                func_0203cc58(0x1e000, 2, 1);
            }
            self->unk_24 = 1;
        case 1:
            if (!Fade0216f8b0_Busy()) {
                return;
            }
            self->unk_24 = 2;
        case 2:
            if (self->unk_30 != NULL) {
                self->unk_30->flags |= 4;
                self->unk_30 = NULL;
            }
            self->unk_24 = 3;
        case 3:
            self->unk_24 = 0;
            if (self->unk_2c == 1) {
                ListBuffer *o = (ListBuffer *)func_0203dd9c(0x54);
                if (o != NULL) {
                    VOBJ_SET_VTABLE(o, data_ov000_021cb6d0);
                    o->flags = 0;
                    o->priority = 0;
                    o->unk_0c = 0;
                    o->unk_10 = 0;
                    o->unk_14 = 0;
                    o->prev = NULL;
                    o->next = NULL;
                    VOBJ_SET_VTABLE(o, data_ov000_021cb6b0);
                    func_ov000_021643e8(o);
                }
                self->unk_30 = o;
            }
            self->unk_20 = 2;
            break;
        }
        break;
    case 2:
        if (self->unk_24 != 0) {
            return;
        }
        if (self->unk_30 != NULL) {
            MessageQueue_AddBuffer(q, self->unk_30, 0xffff, q);
            self->unk_30->flags |= 0x10;
        } else {
            self->unk_20 = 0;
        }
        self->unk_28 = self->unk_2c;
        self->unk_2c = 0;
        self->unk_24 = 4;
        break;
    }
}
}
