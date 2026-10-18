#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern const s16 FX_SinCosTable_[];

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 8;
    u32 b10 : 1;
    u32 b11 : 5;
    u32 b16 : 1;
    u32 rest : 15;
} Flags0216a908;

typedef struct {
    u8 pad_00[4];
    s32 state;
    u8 pad_08[4];
    Flags0216a908 flags;
    u8 pad_10[0x4c];
    s32 unk_5c;
    s32 unk_60;
    u8 pad_64[0x40];
    u8 cnt;
    u8 pad_a5;
    u16 ang;
    s32 timer;
    u8 enable;
} Obj0216a908;

static inline BOOL IsB1(Obj0216a908 *o) {
    return o->flags.b1 ? TRUE : FALSE;
}

static inline BOOL IsB16(Obj0216a908 *o) {
    return (*(u32 *)&o->flags & 0x10000) ? TRUE : FALSE;
}

void func_ov000_0216a908(Obj0216a908 *o) {
    s32 t;
    s32 v;
    if (o->state == 1 || o->state == 8 || o->state == 3 || o->state == 10) {
        if (IsB1(o)) {
            o->state = 2;
        }
    }
    if (o->state != 10) {
        return;
    }
    if (++o->cnt > 30) {
        if (!IsB16(o)) {
            o->flags.b1 = 1;
        }
    }
    o->flags.b16 = 0;
    if (o->enable != 0 && o->unk_5c == o->unk_60) {
        t = o->timer;
        if (t < 0) {
            o->timer = t + 1;
            return;
        }
        if (t < 3) {
            o->ang += 0x600;
            v = FX_SinCosTable_[(o->ang >> 4) * 2];
            if (v < 0) {
                v = -v;
            }
            if (v <= 0x800) {
                o->flags.b10 = 1;
                return;
            }
            o->timer += o->flags.b10;
            o->flags.b10 = 0;
            return;
        }
        o->timer = t + 1;
        if (o->timer > 0x78) {
            o->flags.b10 = 1;
            o->ang = 0;
            o->timer = -0x5a;
        }
        return;
    }
    o->flags.b10 = 1;
    o->ang = 0;
    o->timer = 0;
}
}
