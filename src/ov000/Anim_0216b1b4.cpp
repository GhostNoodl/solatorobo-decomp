#include "types.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
    u32 rest : 28;
} Flags0216b1b4;

extern "C" {
extern MessageQueue021cb980 *data_ov000_021ccd30;
void func_02041c34(void *a, int b, void *c, void *d);
void *func_ov000_0216ac14(void *self, u16 *msg, void *arr, u16 *cnt);

static inline void *GetObj0216b1b4(void) {
    ListBuffer021cb940 *o = data_ov000_021ccd30->unk_11c;
    return o != NULL ? o->unk_58 : NULL;
}

static inline BOOL SubFlag0216b1b4(void *s) {
    return LFLD(Flags0216b1b4, s, 0xc).b3 ? TRUE : FALSE;
}

static inline BOOL IsFlag0216b1b4(MessageQueue021cb980 *g) {
    void *s;
    if (g->unk_11c == NULL) {
        return FALSE;
    }
    s = g->unk_11c->unk_64;
    if (s != NULL) {
        return SubFlag0216b1b4(s) != 0 ? TRUE : FALSE;
    }
    return FALSE;
}

static inline void SetPos0216b1b4(void *o, s32 x, s32 y) {
    LFLD(s32, o, 0xfc) = x;
    LFLD(s32, o, 0x100) = y;
}

struct Obj0216b1b4 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    Model *unk_0c;
    u8 unk_10[0x4];
    u16 unk_14;
    u8 unk_16[0x6];
    s32 unk_1c;
};

void func_ov000_0216b1b4(Obj0216b1b4 *self) {
    s32 base;
    if (GetObj0216b1b4() == NULL) {
        return;
    }
    if (self->unk_04 != 7 && self->unk_04 != 8) {
        return;
    }
    base = IsFlag0216b1b4(data_ov000_021ccd30) ? 0xae000 : 0xb6000;
    SetPos0216b1b4(self->unk_0c, -0x53000, (base + (s32)(((s64)self->unk_1c * 0x40000 + 0x800) >> 12) - 0x61000) & ~0xfff);
    func_02041c34(self->unk_0c, 6, (void *)func_ov000_0216ac14, self);
    self->unk_0c->unk_150 = -0x1f80;
    Model_PlayPart(self->unk_0c, 6);
    Model_PlayPart(self->unk_0c, 7);
    Model_PlayPart(self->unk_0c, self->unk_14);
    self->unk_0c->unk_150 = -0x2000;
    Model_PlayPart(self->unk_0c, 0xb);
}
}
