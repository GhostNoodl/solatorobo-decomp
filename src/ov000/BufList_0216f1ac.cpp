#include "ov000/MessageQueue.h"

extern "C" {

extern HeapState *data_02097dd0;
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb960[];

void *func_0203dd9c(u32 size);
void func_ov000_0216f1ac(ListBuffer *buf, BufferList *list);

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

void func_ov000_0216f1ac(ListBuffer *buf, BufferList *list) {
    ListBuffer *cur;
    ListBuffer *prev;
    if (buf->flags & 2) {
        return;
    }
    buf->flags |= 2;
    cur = list->head;
    if (cur == NULL) {
        list->head = buf;
        return;
    }
    prev = NULL;
    while (cur != NULL) {
        if (buf->priority > cur->priority) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        buf->prev = prev;
        buf->next = NULL;
        prev->next = buf;
        return;
    }
    buf->prev = cur->prev;
    buf->next = cur;
    cur->prev = buf;
    if (buf->prev != NULL) {
        buf->prev->next = buf;
    } else {
        list->head = buf;
    }
}

void func_ov000_0216f23c(BufferList *list, BOOL mode) {
    ListBuffer *buf;
    ListBuffer *next;
    for (buf = list->head; buf != NULL; buf = buf->next) {
        if (!(buf->flags & 4)) {
            if (!mode) {
                if (!(buf->flags & 8)) {
                    buf->vfunc_10();
                }
            } else {
                buf->vfunc_14();
            }
        }
    }
    if (mode) {
        return;
    }
    buf = list->head;
    if (buf == NULL) {
        return;
    }
    do {
        if (buf->flags & 4) {
            next = BufferList_Remove(list, buf);
            if (buf->flags & 0x10) {
                void *saved = data_02097dd0->current;
                data_02097dd0->current = data_02097dd0->unk_08;
                if (buf != NULL) {
                    if (buf != NULL) {
                        buf->vfunc_04();
                    }
                }
                data_02097dd0->current = saved;
            }
        } else {
            next = buf->next;
        }
        buf = next;
    } while (buf != NULL);
}

void func_ov000_0216f360(MessageQueue *self) {
    u32 i;
    self->unk_04 = 0;
    self->list.head = NULL;
    for (i = 0; i < MESSAGE_QUEUE_LEN; i++) {
        self->messages[i].id = -1;
    }
    self->readIndex = 0;
    self->writeIndex = 0;
}

void func_ov000_0216f394(void) {
}

ListBuffer *func_ov000_0216f398(MessageQueue *self, ListBuffer *buf, u32 priority, void *owner) {
    return MessageQueue_AddBuffer(self, buf, priority, owner);
}

void func_ov000_0216f42c(MessageQueue *self, ListBuffer *buf) {
    if (buf == NULL) {
        return;
    }
    BufferList_Remove(&self->list, buf);
    if (buf != NULL) {
        buf->vfunc_04();
    }
}

void func_ov000_0216f498(MessageQueue *self, Message *msg) {
    if (msg->id == -1) {
        return;
    }
    self->vfunc_18(msg->unk_00, msg->id, msg->unk_08, msg->unk_0c);
}

void func_ov000_0216f4cc(MessageQueue *self, u32 a, u32 b, u32 c, u32 d) {
    TimedBuffer *buf = (TimedBuffer *)func_0203dd9c(sizeof(TimedBuffer));
    if (buf != NULL) {
        buf->flags = 0;
        buf->priority = 0;
        buf->unk_0c = 0;
        buf->unk_10 = 0;
        buf->unk_14 = 0;
        buf->prev = NULL;
        buf->next = NULL;
        VOBJ_SET_VTABLE(buf, data_ov000_021cb960);
    }
    MessageQueue_AddBuffer(self, buf, 0, self);
    buf->unk_20 = a;
    buf->unk_24 = b;
    buf->unk_28 = c;
    buf->unk_2c = d;
    buf->flags |= 0x10;
}

void func_ov000_0216f5c4(MessageQueue *self, u32 a, s32 id, u32 b, u32 c) {
    u32 index = self->writeIndex;
    Message *msg = &self->messages[index];
    if (++self->writeIndex >= MESSAGE_QUEUE_LEN) {
        self->writeIndex = 0;
    }
    msg->unk_00 = a;
    msg->id = id;
    msg->unk_08 = b;
    msg->unk_0c = c;
}

}
