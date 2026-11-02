#include "ov002/ov002.h"

extern "C" {

void func_0204aab0(SndQueue *p);
void func_ov002_021ce724(Task021ef4b0 *p);
void func_ov002_021ce660(Task021ef4b0 *p, u32 a);
BOOL func_ov002_021d166c(Task021ef71c *self);
BOOL func_ov002_021d178c(Task021ef71c *self);

static inline void ov002_FreeParts(Task021ef89c *t) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(t->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(t->unk_40);
    HEAP_POP(saved);
}

static inline bool ov002_IsActive(TimedBuffer021cb920 *p) {
    return p->unk_28 != 1 ? 0 : (s32)p->unk_30;
}

static inline bool ov002_HasActive(FieldPlayer *t) {
    TimedBuffer021cb920 *p = t->unk_118;
    if (p == NULL) {
        return false;
    }
    return ov002_IsActive(p) != 0;
}

static inline void ov002_PlayBgm(u16 id) {
    SndQueue *m = data_02097e48.queue;
    if (m->flag0) {
        if (m->unk_06 != 0xffff || m->unk_04 != id) {
            if (m->unk_02 != 10 && m->unk_02 != 0) {
                if (m->unk_06 != 0xffff) {
                    func_0204aab0(m);
                }
                m->unk_02 = 1;
            } else {
                m->unk_02 = 0;
            }
            m->unk_06 = id;
            m->unk_08 = 10;
        }
    }
}

void func_ov002_021d1258(Task021ef71c *self) {
    switch (self->state) {
    case 8: {
        Task021ef89c *t = (Task021ef89c *)Task_FindById(0x15);
        Task021ef4b0 *list;
        Task021ef430 *o;
        if (t != NULL) {
            ov002_FreeParts(t);
        }
        list = (Task021ef4b0 *)Task_FindById(0x12);
        if (list != NULL) {
            self->unk_6c = list->unk_44;
            func_ov002_021ce724(list);
        }
        o = (Task021ef430 *)Task_FindById(0x11);
        if (o != NULL) {
            o->unk_4d = 1;
        }
        if (data_ov000_021ccd30 != NULL) {
            self->unk_69 = ov002_HasActive(data_ov000_021ccd30);
            if (self->unk_69 && data_ov000_021ccd30->unk_118 != NULL) {
                func_ov000_0216f844(data_ov000_021ccd30->unk_118, 0);
            }
        }
        {
            SndQueue *m;
            data_02097e48.queue->flag0 = 1;
            data_02097e48.queue->flag3 = 1;
            m = data_02097e48.queue;
            if (m->flag3) {
                m->unk_06 = 0x8000;
                m->unk_08 = 10;
                m->unk_02 = 0;
            }
        }
        {
            SndQueue *m = data_02097e48.queue;
            m->unk_80 = 0x8000;
            m->unk_7c = 0;
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
        Task021ef89c *t = (Task021ef89c *)Task_FindById(0x15);
        Task021ef4b0 *list;
        Task021ef430 *o;
        if (t != NULL) {
            HEAP_PUSH(saved);
            DELETE_VOBJ(t->unk_3c);
            HEAP_POP(saved);
            HEAP_PUSH(saved);
            DELETE_VOBJ(t->unk_40);
            HEAP_POP(saved);
            func_ov002_021d0b98(t);
            t->unk_3c->flags |= 2;
            t->unk_40->flags |= 2;
        }
        list = (Task021ef4b0 *)Task_FindById(0x12);
        if (list != NULL) {
            func_ov002_021ce660(list, self->unk_6c);
        }
        o = (Task021ef430 *)Task_FindById(0x11);
        if (o != NULL) {
            o->unk_4c = 1;
        }
        if (self->unk_69 && data_ov000_021ccd30->unk_118 != NULL) {
            func_ov000_0216f844(data_ov000_021ccd30->unk_118, 1);
        }
        ov002_PlayBgm(0xd);
        break;
    }
    }
}

}
