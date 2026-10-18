#include "ov000/VObj.h"
#include "nitro/fx.h"

typedef struct {
    u8 pad[8];
    s32 x;
    s32 y;
    s32 z;
    s32 w;
} Txt021c588c;

class Win021c588c : public VObj {
public:
    u8 pad04[8];
    u32 flags;
    u8 pad10[0xe0];
    u8 unk_f0;
    u8 padf1[3];
    Txt021c588c *t0;
    Txt021c588c *t1;
    Txt021c588c *t2;
};

extern "C" {

void func_ov000_0215f334(Txt021c588c *t);

void func_ov000_021c588c(Win021c588c *self, s32 a, VecFx32 *pos, s32 c) {
    s32 z;
    s32 x;
    s32 y;
    Txt021c588c *t;
    self->vfunc_60(a, pos, c);
    self->vfunc_64(a, pos, c);
    if (self->unk_f0 != 0) {
        self->vfunc_74(a, pos, c);
    }
    self->vfunc_70(a, pos, c);
    if (self->flags & 0x40000) {
        self->vfunc_78(a, pos, c);
        self->vfunc_7c(a, pos, c);
        self->vfunc_80(a, pos, c);
    }
    z = pos->z >> 12;
    x = pos->x >> 12;
    y = pos->y >> 12;
    t = self->t0;
    if (t != NULL) {
        t->x = x + 0x18;
        t->y = y - 3;
        t->z = z;
        func_ov000_0215f334(self->t0);
    }
    t = self->t1;
    if (t != NULL) {
        t->x = x + 0x94 - (t->w >> 1);
        t->y = y - 3;
        t->z = z;
        func_ov000_0215f334(self->t1);
    }
    t = self->t2;
    if (t != NULL) {
        t->x = x + 0xe2 - t->w;
        t->y = y - 3;
        t->z = z;
        func_ov000_0215f334(self->t2);
    }
}

}
