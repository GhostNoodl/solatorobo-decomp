#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct {
    s32 c, d;
} Pair0216f5f8;

// The 8-byte tail is copied as its own unit (ldr, ldr, str, str).
typedef struct {
    s32 a, b;
    Pair0216f5f8 cd;
} Ent0216f5f8;

struct Obj0216f5f8 {
    u8 unk_00[0x10c];
    u32 unk_10c;
};

BOOL func_ov000_0216f5f8(Obj0216f5f8 *self, Ent0216f5f8 *out, BOOL pop) {
    Ent0216f5f8 *e;
    if (((Ent0216f5f8 *)((u8 *)self + 0xc))[self->unk_10c].b == -1) {
        out->b = -1;
        return FALSE;
    }
    e = &((Ent0216f5f8 *)((u8 *)self + 0xc))[self->unk_10c];
    *out = *e;
    if (pop) {
        ((Ent0216f5f8 *)((u8 *)self + 0xc))[self->unk_10c].b = -1;
        if (++self->unk_10c >= 0x10) {
            self->unk_10c = 0;
        }
    }
    return TRUE;
}

}
