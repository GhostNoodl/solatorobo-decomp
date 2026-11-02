#include "ov011/ov011.h"

extern "C" {


static inline void Ov011_FreeSub48(Ov003Actor *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->hit != NULL) {
        void *p = self->hit;
        if (p != NULL) {
            func_0203f2b8(p);
            Heap_Free(p);
        }
        self->hit = NULL;
    }
    data_02097dd0->cur = saved;
}

void Ov011Act7e50_Start(Ov011Act7e50 *self) {
    Ov003Actor_Start(self);
    Ov011_FreeSub48(self);
    Ov011_VecSet(&self->unk_44->unk_0c, 0, -0xccd, -self->radius >> 1);
    self->unk_f0.x = 0;
    self->unk_f0.y = 0;
    self->unk_f0.z = 0;
    self->unk_84.x = 0;
    self->unk_84.y = 0;
    self->unk_84.z = 0;
    self->unk_fc = 0;
    self->unk_ea_6 = 1;
}

void Ov011Act7e50_SelectState(Ov011Act7e50 *self) {
    ActorSub40 *s = self->fsm;
    u64 f = s->flags;
    if (f == 0) {
        return;
    }
    if (f & 0x200000) {
        func_ov000_02198360(s, 0x15, 0);
        return;
    }
    if (f & 0x40000) {
        self->unk_fc = 20;
    }
}

}
