#include "types.h"

extern "C" {

typedef struct {
    u16 w, h;
} Sub0219bebc;

typedef struct {
    u8 a, b, c, d;
    u16 e, f;
    Sub0219bebc s;
    s32 i;
} Rec0219bebc;


struct Obj0219bebc {
    u8 unk_00[0x4c];
    Rec0219bebc *unk_4c;
};

void func_ov000_0219bebc(Obj0219bebc *self, s32 scale) {
    Rec0219bebc *o = self->unk_4c;
    Rec0219bebc t;
    if (o == NULL) {
        return;
    }
    if ((u8)(o->d + 0xff) > 1) {
        return;
    }
    if (scale == 0 || scale == 0x1000) {
        return;
    }
    t = *o;
    t.s.w = (u16)(((s64)t.s.w * scale + 0x800) >> 12);
    *o = t;
}
}
