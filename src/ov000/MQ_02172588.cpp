#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Res/ResMgr.h"
#include "Main/Res/ResArc.h"

class MQ021727b0 : public MessageQueue {
public:
    u8 unk_110[0x4];
    ListBuffer *unk_118;
    ListBuffer *unk_11c;
};

extern "C" {

extern u8 data_ov000_021cb980[];
extern u8 data_ov000_021cb9b0[];
extern const char *data_0208cc94;
extern const char *data_0208cca0;
extern char data_0214b105[];
void func_ov000_021bd09c(void);

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

#define DTOR_021727B0(self) \
    do { \
        VOBJ_SET_VTABLE(self, data_ov000_021cb980); \
        if (self->unk_11c != NULL) { \
            ListBuffer *b = self->unk_11c; \
            BufferList_Remove(&self->list, b); \
            if (b != NULL) { \
                b->vfunc_04(); \
            } \
        } \
        self->unk_11c = NULL; \
        if (self->unk_118 != NULL) { \
            ListBuffer *b = self->unk_118; \
            BufferList_Remove(&self->list, b); \
            if (b != NULL) { \
                b->vfunc_04(); \
            } \
        } \
        self->unk_118 = NULL; \
        func_ov000_021bd09c(); \
        ResMgr_ReleaseByName(data_02097cdc, data_0208cc94, 7, 0); \
        ResMgr_ReleaseByName(data_02097cdc, data_0208cca0, 7, 0); \
        ResMgr_ReleaseByName(data_02097cdc, data_0214b105, 7, 0); \
        LoMessageQueueDtor(self); \
    } while (0)

MQ021727b0 *Ov000Vt_021cb980_DtorDelete(MQ021727b0 *self) {
    DTOR_021727B0(self);
    Heap_Free(self);
    return self;
}

MQ021727b0 *Ov000Vt_021cb980_Dtor(MQ021727b0 *self) {
    DTOR_021727B0(self);
    return self;
}

}
