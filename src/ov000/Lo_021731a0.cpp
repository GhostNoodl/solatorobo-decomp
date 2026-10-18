#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"

extern "C" {

extern u8 data_ov000_021cb920[];
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb9b0[];
void func_0203df0c(void *p);

static inline void LoListBufferDtor(ListBuffer *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    if ((self->flags & 0x20) && self->unk_0c != 0) {
        func_0203df0c((void *)self->unk_0c);
    }
    self->flags = 0;
    self->priority = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->prev = NULL;
    self->next = NULL;
}

static inline void LoMQRemove(MessageQueue *self, ListBuffer *buf) {
    if (buf == NULL) {
        return;
    }
    BufferList_Remove(&self->list, buf);
    if (buf != NULL) {
        buf->vfunc_04();
    }
}

static inline void LoTimedBufferDtor(TimedBuffer *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb920);
    if (LFLD(ListBuffer *, self, 0x30) != NULL) {
        LoMQRemove((MessageQueue *)self->unk_0c, LFLD(ListBuffer *, self, 0x30));
    }
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    LFLD(u32, self, 0x30) = 0;
    LoListBufferDtor(self);
}

static inline void LoMessageQueueDtor(MessageQueue *self) {
    ListBuffer *buf;
    u32 i;
    VOBJ_SET_VTABLE(self, data_ov000_021cb9b0);
    buf = self->list.head;
    if (buf != NULL) {
        do {
            ListBuffer *next = BufferList_Remove(&self->list, buf);
            if (buf->flags & 0x10) {
                u32 saved;
                LO_HEAP_PUSH(saved);
                if (buf != NULL) {
                    if (buf != NULL) {
                        buf->vfunc_04();
                    }
                }
                LO_HEAP_POP(saved);
            }
            buf = next;
        } while (buf != NULL);
    }
    self->unk_04 = 0;
    self->list.head = NULL;
    for (i = 0; i < MESSAGE_QUEUE_LEN; i++) {
        self->messages[i].id = -1;
    }
    self->readIndex = 0;
    self->writeIndex = 0;
}

void func_ov000_021731a0(void *self) {
    LFLD(s32, self, 0x4) = 0;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x10) = 0;
    LFLD(s32, self, 0x14) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x1c) = 0;
    LFLD(s32, self, 0x20) = 0xc000;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
    LFLD(s32, self, 0x2c) = 0;
    LFLD(s32, self, 0x30) = 0;
    LFLD(s32, self, 0x34) = 0;
    LFLD(s32, self, 0x38) = 0;
}

}
