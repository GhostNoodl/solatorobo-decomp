#include "ov002/ov002.h"

extern "C" {

void func_0204aab0(SndQueue *p);

static inline BOOL ov002_isState5(void *o) {
    return FIELD(o, 0x4, s32) == 5 ? TRUE : FALSE;
}

void Task021efa1c_PreUpdate(Task021efa1c *self) {
    switch (self->state) {
    case 8:
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        self->unk_3c->flags &= ~2;
        self->unk_40->flags &= ~2;
        break;
    case 10:
        self->unk_3c->flags |= 2;
        self->unk_40->flags |= 2;
        SndMgr_PlayVolume(data_02097e4c, 0x28, -1, -1, -1);
        break;
    case 11:
        if (ov002_isState5(self->unk_3c) && ov002_isState5(self->unk_40)) {
            {
                SndQueue *m = data_02097e48.queue;
                m->unk_80 = 0x8000;
                m->unk_7c = 0;
            }
            {
                SndQueue *m;
                u16 id;
                data_02097e48.queue->flag0 = 1;
                data_02097e48.queue->flag3 = 1;
                m = data_02097e48.queue;
                id = 0xd;
                if (m->flag0) {
                    if (m->unk_06 != 0xffff || m->unk_04 != id) {
                        u16 st;
                        if (m->unk_02 != 10 && m->unk_02 != 0) {
                            if (m->unk_06 != 0xffff) {
                                func_0204aab0(m);
                            }
                            st = 1;
                        } else {
                            st = 0;
                        }
                        m->unk_02 = st;
                        m->unk_06 = id;
                        m->unk_08 = 10;
                    }
                }
            }
        }
        break;
    case 13:
        break;
    }
    ((VObj *)self->unk_3c)->vfunc_1c();
    self->unk_40->vfunc_1c();
}

}
