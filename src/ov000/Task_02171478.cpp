#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "ov000/CmdQueue.h"

typedef struct {
    u32 b0 : 1;
} Bit02171478;

typedef struct {
    u8 pad[0x24];
    s32 state;
    u8 pad28[0xc];
    void *unk_34;
    void *unk_38;
    void *unk_3c;
    void *unk_40;
    void *unk_44;
    u8 pad48[4];
    void *unk_4c;
    void *unk_50;
    void *unk_54;
} Task02171478;

class Mgr02171478 : public MessageQueue {
public:
    Bit02171478 flags;
    ListBuffer *unk_118;
    Task02171478 *unk_11c;
};

extern "C" {

extern u8 data_0214b105[];
extern void *data_0208cca0;
extern void *data_0208cc94;
extern u8 data_0208b318[];
extern u8 data_ov000_021cb6d0[];
extern u8 data_ov000_021cb920[];
extern u8 data_ov000_021cb940[];
extern CmdQueue *data_ov000_021ccd54;
extern Mgr02171478 *data_ov000_021ccd30;
extern s32 data_02097d78[];
void *func_0203dd9c(u32 size);
void *func_020359d0(void *a, s32 b, s32 c);
void func_ov000_0216f1ac(ListBuffer *buf, BufferList *list);
void func_ov000_0216faac(void *p);
VObj *func_ov000_0219bf90(void);
void func_ov000_021848d0(CmdQueue *q);
BOOL func_ov000_02170188(Task02171478 *t, s32 b, s32 c);
BOOL func_ov000_0217032c(Task02171478 *t, s32 b, s32 c);
BOOL func_ov000_02170448(Task02171478 *t, s32 b, s32 c);
BOOL func_ov000_02170620(Task02171478 *t, s32 b, s32 c);
BOOL func_ov000_021708ec(Task02171478 *t, s32 b, s32 c);
void func_ov000_021b87d8(void *p, u16 a);
void func_ov000_0216c954(void *p, u16 a, s32 b);
void func_ov000_0216ca64(void *p, s32 a, s32 b);
void func_ov000_0216e574(void *p);
void func_ov000_0216da2c(void *p, u8 a, s32 b, u32 c);
void func_ov000_021b8884(void *p, u16 a);
void func_ov000_021bacb8(void *p, u16 a);
void func_ov000_021bbc68(void *p, u8 a, u8 b, u8 c);
void func_ov000_021b8e80(void *p, s32 a, u16 b);
void func_ov000_021bb810(void *p, s32 a);
void func_ov000_021bb2b0(void *p, u16 a, s32 b, BOOL c);

}

static inline void ListBuffer_Init02171478(ListBuffer *b) {
    VOBJ_SET_VTABLE(b, data_ov000_021cb6d0);
    b->flags = 0;
    b->priority = 0;
    b->unk_0c = 0;
    b->unk_10 = 0;
    b->unk_14 = 0;
    b->prev = NULL;
    b->next = NULL;
}

static inline ListBuffer *AddBuffer02171478(MessageQueue *self, ListBuffer *buf, u32 priority, void *owner) {
    ListBuffer *b = buf;
    BOOL allocated = FALSE;
    if (b == NULL) {
        allocated = TRUE;
        b = (ListBuffer *)func_0203dd9c(0x20);
        if (b != NULL) {
            ListBuffer_Init02171478(b);
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

static inline BOOL IsMode0_02171478(void) {
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline Message *FindById02171478(MessageQueue *self, s32 id) {
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

static inline BOOL QueueBusy02171478(void) {
    Mgr02171478 *q = data_ov000_021ccd30;
    Message *m;
    if (q == NULL) {
        return FALSE;
    }
    m = FindById02171478(q, 6);
    if (m != NULL) {
        return TRUE;
    }
    if (q->unk_11c == NULL) {
        return FALSE;
    }
    return q->unk_11c->state == 4 ? TRUE : FALSE;
}

static inline BOOL CmdQueue_Empty02171478(CmdQueue *q) {
    return q->unk_90 != q->index ? TRUE : FALSE;
}

static inline BOOL CmdQueue_Flag0_02171478(CmdQueue *q) {
    return LFLD(void *, q, 0xd4) != NULL ? TRUE : FALSE;
}

static inline BOOL CmdQueue_Flag02171478(CmdQueue *q) {
    return CmdQueue_Flag0_02171478(q) ? TRUE : FALSE;
}

static inline BOOL Pl_Busy02171478(VObj *pl) {
    return LFLD(u8, pl, 0xb2e) != 0 ? TRUE : FALSE;
}

static inline BOOL Task_Start34(Task02171478 *t, u32 b) {
    void *p;
    if (t->unk_34 != NULL) {
        return FALSE;
    }
    p = func_0203dd9c(0x5c);
    if (p != NULL) {
        func_ov000_021b87d8(p, b);
    }
    t->unk_34 = p;
    return TRUE;
}

static inline BOOL Task_Stop(void *p) {
    if (p == NULL) {
        return FALSE;
    }
    LFLD(Bit02171478, p, 0).b0 = 1;
    return TRUE;
}

static inline BOOL Task_Start50(Task02171478 *t, u32 b, u32 c) {
    void *p;
    u16 bh;
    s32 bl;
    s32 cl;
    s32 ch;
    if (t->unk_50 != NULL) {
        return FALSE;
    }
    bh = b >> 16;
    bl = (u16)b;
    cl = (u16)c;
    ch = (u16)(c >> 16);
    p = func_0203dd9c(0x3c);
    if (p != NULL) {
        func_ov000_0216c954(p, bh, bl);
    }
    t->unk_50 = p;
    func_ov000_0216ca64(p, cl, ch);
    return TRUE;
}

static inline BOOL Task_Start54(Task02171478 *t, u32 b, s32 c) {
    void *p;
    u8 lo;
    u32 hi;
    if (t->unk_54 != NULL) {
        return FALSE;
    }
    lo = b;
    hi = (b >> 8) & 0xffffff;
    p = func_0203dd9c(0x54);
    if (p != NULL) {
        func_ov000_0216e574(p);
    }
    t->unk_54 = p;
    func_ov000_0216da2c(p, lo, c, hi);
    LFLD(u32, t->unk_54, 0) |= 0x40;
    LFLD(u32, t->unk_54, 0) |= 4;
    return TRUE;
}

static inline BOOL Task_Stop54(void *p) {
    if (p == NULL) {
        return TRUE;
    }
    LFLD(Bit02171478, p, 0).b0 = 1;
    return TRUE;
}

static inline BOOL Task_Start38(Task02171478 *t, u32 b) {
    void *p;
    if (t->state != 3) {
        return FALSE;
    }
    if (t->unk_38 != NULL) {
        return FALSE;
    }
    p = func_0203dd9c(0x34);
    if (p != NULL) {
        func_ov000_021b8884(p, b);
    }
    t->unk_38 = p;
    t->state = 7;
    return TRUE;
}

static inline BOOL Task_Start40(Task02171478 *t, u32 b) {
    void *p;
    if (t->unk_40 != NULL) {
        return FALSE;
    }
    p = func_0203dd9c(0x30);
    if (p != NULL) {
        func_ov000_021bacb8(p, b);
    }
    t->unk_40 = p;
    t->state = 8;
    return TRUE;
}

static inline BOOL Task_Start44(Task02171478 *t, u32 b) {
    void *p;
    u8 x2;
    u8 x1;
    u8 x0;
    if (t->unk_44 != NULL) {
        return FALSE;
    }
    x1 = b >> 8;
    x2 = b >> 16;
    x0 = b;
    p = func_0203dd9c(0x78);
    if (p != NULL) {
        LFLD(void *, p, 4) = data_0208b318;
        ((VObj *)((u8 *)p + 4))->vfunc_08();
        func_ov000_021bbc68(p, x2, x1, x0);
    }
    t->unk_44 = p;
    t->state = 9;
    return TRUE;
}

static inline BOOL Task_Start3c(Task02171478 *t, s32 b, u32 c) {
    void *p;
    if (t->unk_3c != NULL) {
        return FALSE;
    }
    p = func_0203dd9c(0x3c);
    if (p != NULL) {
        func_ov000_021b8e80(p, b, c);
    }
    t->unk_3c = p;
    if (t->state != 4) {
        t->state = 10;
    }
    return TRUE;
}

static inline BOOL Task_Start4c(Task02171478 *t, u32 b, s32 c) {
    void *p;
    u16 lo;
    BOOL f;
    if (t->state != 3) {
        return FALSE;
    }
    if (!IsMode0_02171478()) {
        return FALSE;
    }
    if (QueueBusy02171478()) {
        return FALSE;
    }
    if (t->unk_4c != NULL) {
        return FALSE;
    }
    lo = b;
    f = (b >> 16) & 1 ? TRUE : FALSE;
    p = func_0203dd9c(0x20);
    if (p != NULL) {
        func_ov000_021bb810(p, 4);
    }
    t->unk_4c = p;
    func_ov000_021bb2b0(p, lo, c, f);
    return TRUE;
}

extern "C" {

void func_ov000_02171478(Mgr02171478 *self, s32 a, s32 kind, s32 b, s32 c) {
    switch (kind) {
    case 1:
        self->flags.b0 = 1;
        func_020359d0(data_0214b105, 7, 0);
        func_020359d0(data_0208cca0, 7, 0);
        func_020359d0(data_0208cc94, 7, 0);
        if (self->unk_118 == NULL) {
            TimedBuffer *t = (TimedBuffer *)func_0203dd9c(0x34);
            if (t != NULL) {
                ListBuffer_Init02171478(t);
                VOBJ_SET_VTABLE(t, data_ov000_021cb920);
                t->unk_20 = 0;
                t->unk_24 = 0;
                t->unk_28 = 0;
                t->unk_2c = 0;
                LFLD(u32, t, 0x30) = 0;
            }
            self->unk_118 = t;
            AddBuffer02171478(self, t, 0x10000, self);
            self->unk_118->flags |= 0x10;
        }
        if (self->unk_11c == NULL) {
            Task02171478 *t = (Task02171478 *)func_0203dd9c(0x80);
            if (t != NULL) {
                ListBuffer_Init02171478((ListBuffer *)t);
                VOBJ_SET_VTABLE(t, data_ov000_021cb940);
                func_ov000_0216faac(t);
            }
            self->unk_11c = t;
            AddBuffer02171478(self, (ListBuffer *)t, 0x10000, self);
            LFLD(u32, self->unk_11c, 4) |= 0x10;
        }
        break;
    case 5: {
        VObj *pl;
        BOOL ok;
        if (a != 0) {
            return;
        }
        pl = func_ov000_0219bf90();
        if (pl == NULL) {
            return;
        }
        if (CmdQueue_Empty02171478(data_ov000_021ccd54)) {
            return;
        }
        if (CmdQueue_Flag02171478(data_ov000_021ccd54)) {
            return;
        }
        ok = FALSE;
        if (pl->vfunc_14() && !Pl_Busy02171478(pl)) {
            ok = TRUE;
        }
        if (!ok) {
            return;
        }
        func_ov000_021848d0(data_ov000_021ccd54);
        break;
    }
    case 6:
        if (a != 0) {
            return;
        }
        if (func_ov000_02170188(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 7:
        if (a != 0) {
            return;
        }
        if (func_ov000_0217032c(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 8:
        if (a != 0) {
            return;
        }
        if (func_ov000_02170448(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 9:
        if (a != 0) {
            return;
        }
        if (Task_Start34(self->unk_11c, b)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 10:
        if (a != 0) {
            return;
        }
        if (Task_Stop(self->unk_11c->unk_34)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 11:
        if (a != 0) {
            return;
        }
        if (Task_Start50(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 12:
        if (a != 0) {
            return;
        }
        if (Task_Stop(self->unk_11c->unk_50)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 13:
        if (a != 0) {
            return;
        }
        if (Task_Start54(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 14:
        if (a != 0) {
            return;
        }
        if (Task_Stop54(self->unk_11c->unk_54)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 15:
        if (a != 0) {
            return;
        }
        if (func_ov000_02170620(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 16:
        if (a != 0) {
            return;
        }
        if (Task_Start38(self->unk_11c, b)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 17:
        if (a != 0) {
            return;
        }
        if (Task_Start40(self->unk_11c, b)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 18:
        if (a != 0) {
            return;
        }
        if (Task_Start44(self->unk_11c, b)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 19:
        if (a != 0) {
            return;
        }
        if (Task_Start3c(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 20:
        if (a != 0) {
            return;
        }
        if (self->unk_11c == NULL) {
            return;
        }
        if (func_ov000_021708ec(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    case 21:
        if (a != 0) {
            return;
        }
        if (self->unk_11c == NULL) {
            return;
        }
        if (Task_Start4c(self->unk_11c, b, c)) {
            return;
        }
        self->vfunc_08(a, kind, b, c);
        break;
    }
}

}
