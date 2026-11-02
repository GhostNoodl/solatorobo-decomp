#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "nitro/mi.h"
#include "ov000/ActorMarker.h"

extern "C" {

void *func_ov000_0218ea20(void *p);

void func_ov000_021bd198(ActorMarker *self) {
    s32 i;
    self->flags = 0;
    self->res = NULL;
    for (i = 0; i < 8; i++) {
        self->mdl[i] = NULL;
    }
    for (i = 0; i < 6; i++) {
        self->unk_28[i] = 0;
    }
    self->step = 10;
    self->kind = -1;
    self->nextKind = -1;
    self->rate = 0x1000;
    self->unk_50.x = 0;
    self->unk_50.y = 0;
    self->unk_50.z = 0;
    self->height = 0;
    self->update = NULL;
    self->draw = NULL;
    MI_CpuFill8(&self->work, 0, sizeof(self->work));
    self->work.state = 4;
}

void func_ov000_021bd228(ActorMarker *self) {
    s32 i;
    self->work.state = 5;
    if (self->update != NULL) {
        self->update(self);
    }
    HEAP_DELETE_FN(self->res, func_ov000_0218ea20);
    for (i = 4; i < 8; i++) {
        void *saved = data_02097dd0->cur;
        void *p;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->mdl[(u32)i];
        if (p != NULL) {
            if (p != NULL) {
                MODEL_DELETE(p);
            }
            self->mdl[i] = NULL;
        }
        data_02097dd0->cur = saved;
    }
    func_ov000_021bd198(self);
}

}
