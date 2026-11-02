#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov003/ActorApi.h"

extern "C" {



void Ov003ActVt_021f8d58_Start(ActorEx *self) {
    FieldState *g;
    func_ov000_02194758(self);
    g = data_ov000_021ccd54;
    if (g->unk_ca.c[0] == 9 && g->unk_ca.c[1] == 2 && g->unk_ca.c[2] == 1) {
        self->pos.x = -0x10000;
        self->pos.y = 0;
        self->pos.z = 0x5ccd;
    }
}

} // extern "C"
