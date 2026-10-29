#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    s32 x;
    s32 y;
} Pos021c524c;

typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 5;
    u32 unk_18 : 1;
    u32 unk_19 : 1;
    u32 unk_20 : 1;
    u32 unk_21 : 1;
    u32 unk_22 : 10;
} Flags021c524c;

#define FLAGSX(m) ((Flags021c524c *)&(m)->flags)

extern "C" {

static inline s32 PosX021c524c(Pos021c524c *p) {
    return p->x;
}

void func_ov000_021c524c(u8 *self, s32 unused, Pos021c524c *pos, s32 arg) {
    s32 x = (PosX021c524c(pos) >> 12) + ((LFLD(s32, self, 0x24) << 12) - LFLD(s32, self, 0xb8) >> 12) + 6;
    s32 y = pos->y >> 12;
    Model *m;
    LFLD(Model *, self, 0x10)->flags &= ~0x40000;
    LFLD(Model *, self, 0x10)->flags = (LFLD(Model *, self, 0x10)->flags & ~0x7c) | (0x1e << 2);
    m = LFLD(Model *, self, 0x10);
    Model_SetPos(m, (x - 0x80) << 12, (y - 0x60) << 12);
    Model_PlayPart(LFLD(Model *, self, 0x10), 2);
}

static inline void SetOfs(Model *m, s32 x, s32 y) {
    Model_SetPos(m, (x - 0x80) << 12, (y - 0x60) << 12);
}

static inline s32 GetD0(u8 *self) {
    return LFLD(s32, self, 0xd0);
}

void func_ov000_021c5324(u8 *self, s32 unused, s32 *pos) {
    Model *m;
    s32 x = (LFLD(s32, self, 0x24) >> 1) + (pos[0] >> 12) + 4;
    if (LFLD(s8, self, 0xcc) > 0) {
        s32 y = (pos[1] >> 12) - 2 - (LFLD(s32, self, 0xd0) >> 12);
        FLAGSX(LFLD(Model *, self, 0x10))->unk_18 = 1;
        FLAGSX(LFLD(Model *, self, 0x10))->alpha = LFLD(u8, self, 0xcc);
        SetOfs(LFLD(Model *, self, 0x10), x, y);
        m = LFLD(Model *, self, 0x10);
        Model_PlayPart(m, 4);
    }
    if (LFLD(s8, self, 0xcd) > 0) {
        s32 y = LFLD(s32, self, 0x28) + (pos[1] >> 12) + 2 + (GetD0(self) >> 12);
        FLAGSX(LFLD(Model *, self, 0x10))->unk_18 = 0;
        FLAGSX(LFLD(Model *, self, 0x10))->alpha = LFLD(u8, self, 0xcd);
        SetOfs(LFLD(Model *, self, 0x10), x, y);
        Model_PlayPart(LFLD(Model *, self, 0x10), 4);
    }
}

}
