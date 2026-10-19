#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 rest : 8;
} DefFlags021b8014;

typedef struct {
    u8 pad[0x18];
    VecFx32 pos;
    u16 rot[3];
    s16 sx;
    s16 sy;
    s16 sz;
    s16 unk_30;
    DefFlags021b8014 flags;
} Def021b8014;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Bits8;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} Bits16;

typedef struct {
    u8 pad[0x8];
    const Def021b8014 *def;
    const char *ext;
    s16 unk_10;
    u16 flags;
    u8 pad14[0x94];
    VecFx32 pos;
    MtxFx33 mtx;
    s32 sx;
    s32 sy;
    s32 sz;
    s16 unk_e4;
    u8 unk_e6[3];
    u8 flags_e9;
    u8 pad_ea[6];
    s32 unk_f0;
    u8 unk_f4;
    u8 pad_f5;
    u8 flags_f6;
} Obj021b8014;

extern "C" {

const char *func_02039674(const void *path);

static inline void RotZYX(MtxFx33 *m, const u16 *rot) {
    MtxFx33 t;
    BOOL any;
    u16 rz;
    u16 rx;
    u16 ry;
    any = FALSE;
    rz = rot[2];
    ry = rot[1];
    rx = rot[0];
    MTX_Identity33_(m);
    if (rz != 0) {
        MTX_RotZ33_(m, SC(rz));
        any = TRUE;
    }
    if (ry != 0) {
        if (any) {
            MTX_RotY33_(&t, SC(ry));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotY33_(m, SC(ry));
            any = TRUE;
        }
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX33_(&t, SC(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, SC(rx));
        }
    }
}

void func_ov000_021b8014(Obj021b8014 *self, const Def021b8014 *def, s32 a, u8 b) {
    LFLD(Bits16, self, 0x12).b0 = 1;
    self->flags |= 4;
    if (def->flags.b2) {
        self->flags |= 0x100;
    }
    self->unk_f0 = a;
    self->unk_f4 = b;
    if (def->flags.b3) {
        self->flags |= 0x10;
    }
    if (def->flags.b0) {
        self->flags |= 0x40;
        if (def->flags.b1) {
            self->flags_e9 |= 2;
        }
        if (def->unk_30 != 0x1000) {
            self->unk_e4 = def->unk_30;
        }
    }
    self->unk_10 = 0;
    self->def = def;
    self->ext = func_02039674(def);
    self->pos = def->pos;
    RotZYX(&self->mtx, def->rot);
    if (def->flags.b5) {
        self->flags_e9 |= 0x20;
    }
    self->sx = def->sx << 4;
    self->sy = def->sy << 4;
    self->sz = def->sz << 4;
    if (def->flags.b4) {
        LFLD(Bits8, self, 0xf6).b0 = 1;
    }
    if (def->flags.b6) {
        self->flags_f6 |= 2;
    }
    if (def->flags.b7) {
        self->flags_e9 |= 0x10;
    }
}

}
