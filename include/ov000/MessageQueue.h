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
SIZE_ASSERT(ListBuffer, 0x20);

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

// Vtable data_ov000_021cb920 (methods TimedBuffer021cb920_DtorDelete, 02172bb4, 02172be8): a timed buffer
// that owns another buffer.
class TimedBuffer021cb920 : public TimedBuffer {
public:
    ListBuffer *unk_30;
};

struct LoTicker;
struct SlideWin; // Main/Gfx/SlideWin.h
struct LoTimer;
struct Lo021cb0b8; // list dialog, ov000/ObjLayouts.h
struct Lo021cb6f0; // the bar displays, ov000/ObjLayouts.h
struct Lo021cb744;
struct Lo021cb798;
struct Lo021cb7ec;
struct Lo021cb840;
struct Lo021cb894;
struct Model;

// 0x1c bytes, ListBuffer021cb940::unk_68 (init func_ov000_0216b474, release func_ov000_0216b490): a 2D model
// that slides in while something keeps asking for it each frame (func_ov000_0216b508, from the robot's
// update) and slides out once it stops. func_ov000_0216b550 updates it, func_ov000_0216b880 places it.
struct Lo0216b474 {
    union {
        u32 flags;
        struct {
            u32 opening : 1; // sliding in (else out)
            u32 want : 1; // set by func_ov000_0216b508; cleared when the field is busy
            u32 asked : 1; // set by each func_ov000_0216b508 call; want is dropped after a frame without one
            u32 part22 : 1; // show model part 0x22 (else 0x23)
            u32 unk_00_4 : 28;
        };
    };
    s32 state; // 0x04 2: start, 3: free the model, 4: wait for want, 5: load, 6: wait for the load, 7/8: slide
    Model *model; // 0x08
    u8 unk_0c[0x8];
    s32 frame; // 0x14 frames into the slide (0xc frames)
    s32 ratio; // 0x18 fx32 slide position, 0..0x1000
};

// Vtable data_ov000_021cb940 (0x80 bytes; base vtable data_ov000_021cb6d0, init func_ov000_0216faac,
// dtor func_ov000_0216fb14): the field's sub-object holder, data_ov000_021ccd30's 0x11c buffer, made by
// func_ov000_02171478 / func_ov000_021854d4. func_ov000_02170a58 updates the object state selects (each
// is deleted once it reports done) and draws the always-present ones; func_ov000_02171270 draws.
class ListBuffer021cb940 : public ListBuffer {
public:
    union {
        u32 unk_20;
        struct {
            u32 unk_20_0 : 1;
            u32 ready : 1; // set by func_ov000_02170a58 when its setup states (0..2) are done
            u32 unk_20_2 : 30;
        };
    };
    s32 state;
    SlideWin *win; // message window, made by func_ov000_02170188
    void *unk_2c;
    VObj *unk_30;
    void *unk_34;
    void *unk_38;
    void *unk_3c;
    void *unk_40;
    void *unk_44;
    Lo021cb0b8 *dialog; // list dialog, made by func_ov000_02170620
    void *unk_4c;
    void *unk_50;
    struct LoTimer *unk_54; // the stage timer
    Lo021cb798 *unk_58;
    Lo021cb798 *unk_5c;
    Lo021cb7ec *unk_60;
    Lo021cb744 *unk_64;
    Lo0216b474 *unk_68;
    Lo021cb6f0 *unk_6c;
    Lo021cb840 *unk_70;
    Lo021cb894 *unk_74;
    void *unk_78;
    LoTicker *ticker;
};
SIZE_ASSERT(ListBuffer021cb940, 0x80);

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

// The field's message queue (vtable data_ov000_021cb980, 0x120 bytes, base MessageQueue with vtable
// data_ov000_021cb9b0, init func_ov000_02171464): data_ov000_021ccd30, made by func_ov000_021814dc.
// func_ov000_02171478 creates its two buffers. Main reads it as FieldPlayer (Main/Sys/Field.h).
class MessageQueue021cb980 : public MessageQueue {
public:
    union {
        u32 flags;
        struct {
            u32 flag0 : 1;
            u32 flag1 : 1;
            u32 unk_114_2 : 30;
        };
    };
    TimedBuffer021cb920 *unk_118;
    ListBuffer021cb940 *unk_11c;
};
SIZE_ASSERT(MessageQueue021cb980, 0x120);

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
