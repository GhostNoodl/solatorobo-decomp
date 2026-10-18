#include "ov002/ov002.h"

extern "C" {

bool func_ov002_021e90ac(void) {
    BOOL r;
    if (data_ov002_021f0f98[1] == NULL) {
        r = FALSE;
    } else {
        r = func_ov002_021e7ea8(data_ov002_021f0f98[1]);
    }
    return r;
}

void func_ov002_021e90dc(void) {
    VObject *self = (VObject *)data_ov002_021f0f98[1];
    u32 mask;
    if (self == NULL) {
        return;
    }
    if (FIELD(self, 4, s32) != 4 && FIELD(self, 4, s32) != 5) {
        return;
    }
    mask = FIELD(self, 0xc, u32);
    if ((FIELD(self, 0x128, u32) & mask) && FIELD(self, 0xd0, s32) > 0) {
        func_ov002_021e8cc4(self);
    }
    for (self = FIELD(self, 0xdc, VObject *); self != NULL; self = FIELD(self, 0x24, VObject *)) {
        if ((FIELD(self, 8, u32) & mask) && FIELD(self, 0xc, s32) == 3) {
            self->v0x1c();
        }
    }
}

void func_ov002_021e916c(void) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(*(VObject **)&data_ov002_021f0f98[1]);
    HEAP_POP(saved);
}

static inline void func_ov002_021e4cd8_inline5(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    func_02016cd8(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f98[1];
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}
void *func_ov002_021e91c8(s32 a, s32 b, s32 c, bool d, u8 e) {
    void *p = func_0203dd9c(0x1f4);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline5(p);
        *(VFunc **)p = data_ov002_021f07d4;
        func_ov002_021e5140(p);
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = c;
    FIELD(p, 0x1f0, Bits8).b0 = e;
    FIELD(p, 0x1f0, Bits8).b1 = d;
    return p;
}

static inline void func_ov002_021e4cd8_inline2(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    func_02016cd8(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f98[1];
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}
void *func_ov002_021e92b0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    void *p = func_0203dd9c(0xec);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f075c;
        func_ov002_021e5d0c(p);
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = c;
    FIELD(p, 0x78, s32) = d;
    FIELD(p, 0x88, s32) = e;
    return p;
}

}
