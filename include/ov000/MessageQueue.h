#ifndef OV000_MESSAGEQUEUE_H
#define OV000_MESSAGEQUEUE_H

#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

class ListBuffer : public VObj {
public:
    u32 flags;
    u32 priority;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    ListBuffer *prev;
    ListBuffer *next;
};

typedef struct {
    ListBuffer *head;
} BufferList;

class TimedBuffer : public ListBuffer {
public:
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
};

typedef struct {
    u32 unk_00;
    s32 id;
    u32 unk_08;
    u32 unk_0c;
} Message;

#define MESSAGE_QUEUE_LEN 16

class MessageQueue : public VObj {
public:
    u8 unk_04;
    u8 unk_05[0x3];
    BufferList list;
    Message messages[MESSAGE_QUEUE_LEN];
    u32 readIndex;
    u32 writeIndex;
};

static inline ListBuffer *BufferList_Remove(BufferList *list, ListBuffer *buf) {
    ListBuffer *next;
    if (!(buf->flags & 2)) {
        return NULL;
    }
    buf->flags &= ~2;
    next = buf->next;
    if (buf->prev != NULL) {
        buf->prev->next = next;
    } else {
        list->head = next;
    }
    if (buf->next != NULL) {
        buf->next->prev = buf->prev;
    }
    buf->prev = NULL;
    buf->next = NULL;
    return next;
}

static inline Message *MessageQueue_FindById(MessageQueue *self, s32 id) {
    s32 end;
    s32 read;
    s32 i;
    read = self->readIndex;
    end = self->writeIndex;
    if (end == read) {
        return NULL;
    }
    if (end <= read) {
        end += MESSAGE_QUEUE_LEN;
    }
    for (i = read; i < end; i++) {
        u32 index = i;
        if (index >= MESSAGE_QUEUE_LEN) {
            index = i - MESSAGE_QUEUE_LEN;
        }
        if (id == self->messages[index].id) {
            return &self->messages[index];
        }
    }
    return NULL;
}

static inline Message *MessageQueue_Find(MessageQueue *self, s32 id, u32 a, u32 b) {
    s32 end;
    s32 read;
    s32 i;
    read = self->readIndex;
    end = self->writeIndex;
    if (end == read) {
        return NULL;
    }
    if (end <= read) {
        end += MESSAGE_QUEUE_LEN;
    }
    for (i = read; i < end; i++) {
        u32 index = i;
        if (index >= MESSAGE_QUEUE_LEN) {
            index = i - MESSAGE_QUEUE_LEN;
        }
        if (id == self->messages[index].id && a == self->messages[index].unk_08 && b == self->messages[index].unk_0c) {
            return &self->messages[index];
        }
    }
    return NULL;
}

#endif
