#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 active : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x22];
    u16 enable : 1;
    u16 visible : 1;
} Ov003MvPart;

typedef struct {
    u8 unk_00[0x1a];
    s16 mode;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x1e];
    void *work;
    Ov003MvPart *part;
} Ov003Mover2;

extern void *data_ov000_021ccd64;
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02194758(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e8eb0(Ov003Mover2 *self) {
    Ov003Unit *u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    Ov003MvPart *p;
    if (u != NULL) {
        u->active = 0;
    }
    func_ov000_02194758(self);
    if (self->mode == 0) {
        self->mode = 3;
    }
    p = self->part;
    p->enable = 0;
    p->visible = 0;
    func_ov000_02198360(self->work, 6, 0);
}
