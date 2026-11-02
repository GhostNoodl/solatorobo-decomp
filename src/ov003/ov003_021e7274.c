#include "types.h"
#include "Main/Sys/FieldState.h"


typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
} Ov003Spot;

extern void func_ov000_02194758(void *self);

void Ov003ActVt_021f8d58_Start(Ov003Spot *self) {
    FieldState *g;
    func_ov000_02194758(self);
    g = data_ov000_021ccd54;
    if (g->unk_ca.c[0] == 9 && g->unk_ca.c[1] == 2 && g->unk_ca.c[2] == 1) {
        self->pos.x = -0x10000;
        self->pos.y = 0;
        self->pos.z = 0x5ccd;
    }
}
