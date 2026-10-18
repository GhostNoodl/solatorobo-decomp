#include "types.h"
#include "nitro/fx.h"

typedef struct {
    u16 c0;
    u16 c1;
    u16 mode;
    u16 on;
} Fade021b3bd8;

typedef struct {
    u8 pad[0x13];
    u8 key;
} Sub40_021b3bd8;

typedef struct {
    u8 pad[0x50];
    u32 flags;
} Sub48_021b3bd8;

typedef struct {
    u8 pad[0xb6];
    Fade021b3bd8 fade;
} Sub998_021b3bd8;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 rest : 27;
} Flags021b3bd8;

typedef struct {
    u8 pad[0x40];
    Sub40_021b3bd8 *unk_40;
    u8 pad44[4];
    Sub48_021b3bd8 *unk_48;
    u8 pad4c[0x18];
    s32 unk_64;
    u8 pad68[8];
    u8 unk_70[0x41e - 0x70];
    Fade021b3bd8 fade;
    u8 pad426[0x75c - 0x426];
    VecFx32 pos;
    u8 pad768[0x772 - 0x768];
    u8 ids[3];
    u8 pad775[0x998 - 0x775];
    Sub998_021b3bd8 *unk_998;
    u8 pad99c[0xb22 - 0x99c];
    u16 b22_0 : 3;
    u16 b22_rest : 13;
    Flags021b3bd8 flags;
} Mgr021b3bd8;

typedef struct {
    u8 pad[0xca];
    u8 ids[3];
} Player021b3bd8;

typedef struct {
    u8 pad[0x18];
    u16 b0 : 9;
    u16 b9 : 1;
    u16 rest : 6;
} Cfg021b3bd8;

extern "C" {

extern Cfg021b3bd8 *data_0214a424;
extern Player021b3bd8 *data_ov000_021ccd54;
BOOL func_01ffc584(void *a, VecFx32 *b, s32 c, s32 d);

static inline void Fade_Set(Fade021b3bd8 *f) {
    f->c0 = 0x73ff;
    f->c1 = 0x73ff;
    f->mode = 2;
    f->on = 1;
}

void func_ov000_021b3bd8(Mgr021b3bd8 *self) {
    BOOL same;
    u8 key;
    VecFx32 v;
    BOOL hit;
    self->flags.b4 = 0;
    if (self->flags.b2 != 0) {
        return;
    }
    if (self->flags.b1) {
        return;
    }
    if (data_0214a424->b9 ? TRUE : FALSE) {
        return;
    }
    same = FALSE;
    if (data_ov000_021ccd54->ids[0] == self->ids[0] && data_ov000_021ccd54->ids[1] == self->ids[1] && data_ov000_021ccd54->ids[2] == self->ids[2]) {
        same = TRUE;
    }
    if (!same) {
        return;
    }
    key = self->unk_40->key;
    if (key != 1 && key != 2 && key != 4) {
        return;
    }
    v = self->pos;
    v.y -= 0x3800;
    hit = func_01ffc584(self->unk_70, &v, self->unk_64 + 0x3000, 0x6000);
    if (!hit && !(self->unk_48->flags & 0x20000000)) {
        hit = func_01ffc584(self->unk_70, &v, self->unk_64 + 0x5000, 0x3800);
    }
    if (!hit) {
        return;
    }
    self->flags.b4 = 1;
    Fade_Set(&self->fade);
    if (self->b22_0 != 0 && self->unk_998 != NULL) {
        Fade_Set(&self->unk_998->fade);
    }
}

}
