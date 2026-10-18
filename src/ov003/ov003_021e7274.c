#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u8 unk_00[0xca];
    u8 area;
    u8 room;
    u8 part;
} Ov003Game54;

typedef struct {
    u8 unk_00[0x70];
    Ov003Vec pos;
} Ov003Spot;

extern Ov003Game54 *data_ov000_021ccd54;
extern void func_ov000_02194758(void *self);

void func_ov003_021e7274(Ov003Spot *self) {
    Ov003Game54 *g;
    func_ov000_02194758(self);
    g = data_ov000_021ccd54;
    if (g->area == 9 && g->room == 2 && g->part == 1) {
        self->pos.x = -0x10000;
        self->pos.y = 0;
        self->pos.z = 0x5ccd;
    }
}
