#include "ov002/ov002.h"

extern "C" {

typedef struct BgmInfo {
    u16 id : 14;
    u16 type : 2;
} BgmInfo;

BgmInfo *func_0206ee58(u16 id);

void func_0204aab0(void *p);

BOOL func_ov002_021d0270(void *self, void *ev) {
    BgmInfo *info = func_0206ee58(FIELD(ev, 0x8, u32));
    if (info != NULL) {
        {
            SndQueue *m = data_02097e48.queue;
            m->unk_80 = 0x8000;
            m->unk_7c = 0;
        }
        {
            SndQueue *m = data_02097e48.queue;
            if (m->flag3) {
                m->unk_06 = 0x8000;
                m->unk_08 = 0;
                m->unk_02 = 0;
            }
        }
        if (info->type == 0) {
            u16 id = info->id;
            SndQueue *m = data_02097e48.queue;
            if (m->unk_80 != 0xffff || m->unk_7e != id) {
                m->unk_80 = id;
                m->unk_7c = 0;
            }
        } else if (info->type == 1) {
            SndQueue *m;
            u16 id;
            data_02097e48.queue->flag0 = 1;
            FIELD(data_02097e48.queue, 0x0, u16) |= 8;
            m = data_02097e48.queue;
            id = info->id;
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
    return TRUE;
}

}
