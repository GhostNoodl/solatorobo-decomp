#include "ov002/ov002.h"

extern "C" {

void func_0204aab0(void *p);
void func_ov002_021ce724(Task021ef4b0 *p);
void func_ov002_021ce660(Task021ef4b0 *p, void *a);
BOOL func_ov002_021d166c(Task021ef71c *self);
BOOL func_ov002_021d178c(Task021ef71c *self);

static inline void ov002_FreeParts(void *t) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(t, 0x3c, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(t, 0x40, VObj *));
    HEAP_POP(saved);
}

static inline bool ov002_IsActive(void *p) {
    return FIELD(p, 0x28, s32) != 1 ? 0 : FIELD(p, 0x30, s32);
}

static inline bool ov002_HasActive(void *t) {
    void *p = FIELD(t, 0x118, void *);
    if (p == NULL) {
        return false;
    }
    return ov002_IsActive(p) != 0;
}

static inline void ov002_PlayBgm(u16 id) {
    u8 *m = (u8 *)data_02097e48.queue;
    if (FIELD(m, 0x0, Bits16).b0) {
        if (FIELD(m, 0x6, u16) != 0xffff || FIELD(m, 0x4, u16) != id) {
            if (FIELD(m, 0x2, u16) != 10 && FIELD(m, 0x2, u16) != 0) {
                if (FIELD(m, 0x6, u16) != 0xffff) {
                    func_0204aab0(m);
                }
                FIELD(m, 0x2, u16) = 1;
            } else {
                FIELD(m, 0x2, u16) = 0;
            }
            FIELD(m, 0x6, u16) = id;
            FIELD(m, 0x8, u16) = 10;
        }
    }
}

void func_ov002_021d1258(Task021ef71c *self) {
    switch (self->state) {
    case 8: {
        void *t = Task_FindById(0x15);
        void *o;
        if (t != NULL) {
            ov002_FreeParts(t);
        }
        o = Task_FindById(0x12);
        if (o != NULL) {
            self->unk_6c = FIELD(o, 0x44, void *);
            func_ov002_021ce724((Task021ef4b0 *)o);
        }
        o = Task_FindById(0x11);
        if (o != NULL) {
            FIELD(o, 0x4d, u8) = 1;
        }
        if (data_ov000_021ccd30 != NULL) {
            self->unk_69 = ov002_HasActive(data_ov000_021ccd30);
            if (self->unk_69 && FIELD(data_ov000_021ccd30, 0x118, void *) != NULL) {
                func_ov000_0216f844(FIELD(data_ov000_021ccd30, 0x118, void *), 0);
            }
        }
        {
            u8 *m;
            data_02097e48.queue->flag0 = 1;
            FIELD(data_02097e48.queue, 0x0, u16) |= 8;
            m = (u8 *)data_02097e48.queue;
            if (FIELD(m, 0x0, Bits16).b3) {
                FIELD(m, 0x6, u16) = 0x8000;
                FIELD(m, 0x8, u16) = 10;
                FIELD(m, 0x2, u16) = 0;
            }
        }
        {
            u8 *m = (u8 *)data_02097e48.queue;
            FIELD(m, 0x80, u16) = 0x8000;
            FIELD(m, 0x7c, u16) = 0;
        }
        if (self->unk_60 >= 0) {
            ov002_PlayBgm(self->unk_60);
        }
        break;
    }
    case 13:
        if (self->unk_68 ? func_ov002_021d166c(self) : func_ov002_021d178c(self)) {
            break;
        }
        self->fadeLen = 0x1e000;
        self->vfunc_0c(0);
        break;
    case 10: {
        void *saved;
        void *t = Task_FindById(0x15);
        void *o;
        if (t != NULL) {
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(t, 0x3c, VObj *));
            HEAP_POP(saved);
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(t, 0x40, VObj *));
            HEAP_POP(saved);
            func_ov002_021d0b98((Task021ef89c *)t);
            FIELD(FIELD(t, 0x3c, void *), 0xc, u32) |= 2;
            FIELD(FIELD(t, 0x40, void *), 0xc, u32) |= 2;
        }
        o = Task_FindById(0x12);
        if (o != NULL) {
            func_ov002_021ce660((Task021ef4b0 *)o, self->unk_6c);
        }
        o = Task_FindById(0x11);
        if (o != NULL) {
            FIELD(o, 0x4c, u8) = 1;
        }
        if (self->unk_69 && FIELD(data_ov000_021ccd30, 0x118, void *) != NULL) {
            func_ov000_0216f844(FIELD(data_ov000_021ccd30, 0x118, void *), 1);
        }
        ov002_PlayBgm(0xd);
        break;
    }
    }
}

}
