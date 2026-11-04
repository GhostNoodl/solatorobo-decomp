#include "types.h"
#include "ov000/ModelViewer.h"

extern "C" {

void ResSet_SetName0(ActorRes *t, void *a, void *b, s32 c, s32 d);
void ResSet_SetName1(ActorRes *t, void *a, void *b, s32 c, s32 d);
BOOL ResSet_UpdateLoad(ActorRes *t);
BOOL Vram_IsIdle(void);

void ModelViewerRes_UpdateLoad(ModelViewerRes *self) {
    u8 idx;
    switch (self->state) {
    case 0:
        idx = (self->cur & 1) ^ 1;
        ResSet_SetName0(&self->a[idx], self->mdlArc, self->mdlName, 1, 0);
        ResSet_SetName1(&self->a[idx], self->anmArc, self->anmName, 1, 0);
        if (self->useMdlForB != 0) {
            ResSet_SetName1(&self->b[idx], self->mdlArc, self->mdlName, 1, 0);
        } else {
            ResSet_SetName1(&self->b[idx], NULL, NULL, 1, 0);
            self->b[idx].unk_00 = 0;
        }
        self->reload = 0;
        self->state = 10;
        break;
    case 10:
        idx = (self->cur & 1) ^ 1;
        ResSet_UpdateLoad(&self->a[idx]);
        ResSet_UpdateLoad(&self->b[idx]);
        if (self->a[idx].unk_00 < 0 && self->b[idx].unk_00 < 0) {
            if (Vram_IsIdle()) {
                if (self->reload != 0) {
                    self->state = 0;
                } else {
                    self->state = 20;
                }
            }
        }
        break;
    case 20:
        if (self->reload != 0) {
            self->state = 0;
        }
        break;
    }
}

}
