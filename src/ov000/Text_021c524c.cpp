#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    s32 x;
    s32 y;
} Pos021c524c;

extern "C" {

static inline s32 PosX021c524c(Pos021c524c *p) {
    return p->x;
}

void func_ov000_021c524c(u8 *self, s32 unused, Pos021c524c *pos) {
    s32 x = (PosX021c524c(pos) >> 12) + ((LFLD(s32, self, 0x24) << 12) - LFLD(s32, self, 0xb8) >> 12) + 6;
    s32 y = pos->y >> 12;
    Model *m;
    LFLD(Model *, self, 0x10)->flags &= ~0x40000;
    LFLD(Model *, self, 0x10)->flags = (LFLD(Model *, self, 0x10)->flags & ~0x7c) | (0x1e << 2);
    m = LFLD(Model *, self, 0x10);
    Model_SetPos(m, (x - 0x80) << 12, (y - 0x60) << 12);
    Model_PlayPart(LFLD(Model *, self, 0x10), 2);
}

}
