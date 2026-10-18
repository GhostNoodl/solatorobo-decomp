#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern s32 data_02097d78[];

typedef struct {
    u32 a : 1;
    u32 b : 1;
    u32 rest : 30;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
} Timer021bc3ec;

static inline BOOL IsMode4(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

void func_ov000_021bc3ec(Timer021bc3ec *t, s32 v, s32 n) {
    if (n == 0) {
        n = 1;
    }
    t->b = 0;
    t->a = 1;
    t->unk_04 = 1;
    t->unk_0c = 0;
    t->unk_24 = n;
    t->unk_18 = 0;
    t->unk_1c = 0;
    t->unk_08 = v;
    if (IsMode4()) {
        t->unk_20 = t->unk_24;
    }
}

typedef struct {
    s32 a, b, c, d;
} Ent0216f5f8;

}
