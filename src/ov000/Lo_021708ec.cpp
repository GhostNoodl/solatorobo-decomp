#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"

extern "C" {

extern s32 data_02097d78[];
extern MessageQueue *data_ov000_021ccd30;
void func_ov000_021bb810(void *self, s32 a);
void func_ov000_021bb840(void *self);

static inline BOOL Lo_SysIdle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline Message *Lo_FindMsg(MessageQueue *self, s32 id) {
    s32 end;
    s32 i;
    end = self->writeIndex;
    i = self->readIndex;
    if (end == i) {
        return NULL;
    }
    end = end <= i ? end + MESSAGE_QUEUE_LEN : end;
    for (; i < end; i++) {
        u32 index = i;
        if ((u32)i >= MESSAGE_QUEUE_LEN) {
            index = i - MESSAGE_QUEUE_LEN;
        }
        if (id == self->messages[index].id) {
            return &self->messages[index];
        }
    }
    return NULL;
}

static inline BOOL Lo_TalkBusy(MessageQueue *mq) {
    if (mq == NULL) {
        return FALSE;
    }
    if (Lo_FindMsg(mq, 6) != NULL) {
        return TRUE;
    }
    {
        void *o = LFLD(void *, mq, 0x11c);
        if (o == NULL) {
            return FALSE;
        }
        return LFLD(s32, o, 0x24) == 4 ? TRUE : FALSE;
    }
}

BOOL func_ov000_021708ec(void *self, s32 arg, s32 arg2) {
    void *p;
    if (LFLD(s32, self, 0x24) != 3) {
        return FALSE;
    }
    if (!Lo_SysIdle()) {
        return FALSE;
    }
    if (Lo_TalkBusy(data_ov000_021ccd30)) {
        return FALSE;
    }
    if (LFLD(void *, self, 0x4c) != NULL) {
        return FALSE;
    }
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(void *, self, 0x4c) != NULL) {
            void *q = LFLD(void *, self, 0x4c);
            if (q != NULL) {
                func_ov000_021bb840(q);
                func_0203de1c(q);
            }
            LFLD(void *, self, 0x4c) = NULL;
        }
        LO_HEAP_POP(saved);
    }
    p = func_0203dd9c(0x20);
    if (p != NULL) {
        func_ov000_021bb810(p, arg);
    }
    LFLD(void *, self, 0x4c) = p;
    return TRUE;
}

}
