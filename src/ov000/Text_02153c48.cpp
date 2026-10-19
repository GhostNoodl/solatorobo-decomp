#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 8;
    u32 f8 : 5;
    u32 rest : 19;
} TwBits02153c48;

extern "C" {
extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
extern void *data_02149ef8;
void func_0204c7d0(void *p);
s32 func_0204c0e8(void *p, s32 a);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void func_0204ca70(void *p);

static inline u8 *NewTw02153c48(void) {
    u8 *o = (u8 *)func_0203dd9c(0xb8);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208ba70);
        func_0204c7d0(o);
    }
    return o;
}

void func_ov000_02153c48(u8 *self, s32 a, BOOL show, BOOL center, u8 d) {
    u8 *w;
    LO_FREE_V(self, 0x1c);
    LO_FREE_V(self, 0x20);
    w = NewTw02153c48();
    LFLD(u8 *, self, 0x1c) = w;
    if (d) {
        LFLD(s8, w, 0x37) = 1;
    }
    LFLD(s32, LFLD(u8 *, self, 0x1c), 0x28) = a;
    LFLD(s32, LFLD(u8 *, self, 0x1c), 0x2c) = LFLD(s32, self, 0x24);
    w = LFLD(u8 *, self, 0x1c);
    LFLD(s32, w, 0x24) = LFLD(s32, self, 0);
    LFLD(s32, w, 0x4c) = func_0204c4fc(LFLD(s32, w, 0x28), LFLD(s32, w, 0x38), LFLD(s32, w, 0x24), w + 0x44, w + 0x48, LFLD(s8, w, 0x37) ? 1 : 0);
    LFLD(s32, data_02097ce0, 4) = LFLD(s32, w, 0x28);
    LFLD(TwBits02153c48, LFLD(u8 *, self, 0x1c), 4).f8 = 0x1e;
    if (center) {
        LFLD(u8, LFLD(u8 *, self, 0x1c), 0x36) = 1;
    }
    LFLD(u32, LFLD(u8 *, self, 0x1c), 4) |= 0x40;
    LFLD(u32, LFLD(u8 *, self, 0x1c), 4) |= 0x1000000;
    LFLD(u32, LFLD(u8 *, self, 0x1c), 4) |= 0x400000;
    LFLD(u32, LFLD(u8 *, self, 0x1c), 4) |= 0x40000000;
    LFLD(u32, LFLD(u8 *, self, 0x1c), 4) |= 4;
    if (show) {
        func_0204ca70(LFLD(u8 *, self, 0x1c));
    }
    if (!(LFLD(s32, self, 0xc) == -1 ? TRUE : FALSE)) {
        return;
    }
    {
        void *fnt = data_02149ef8;
        w = NewTw02153c48();
        LFLD(u8 *, self, 0x20) = w;
        LFLD(s32, w, 0x28) = 4;
        LFLD(s32, LFLD(u8 *, self, 0x20), 0x2c) = 0xe;
        {
            s32 t = func_0204c0e8(fnt, 0xa0);
            w = LFLD(u8 *, self, 0x20);
            LFLD(s32, w, 0x24) = t;
        }
    }
    LFLD(s32, w, 0x4c) = func_0204c4fc(LFLD(s32, w, 0x28), LFLD(s32, w, 0x38), LFLD(s32, w, 0x24), w + 0x44, w + 0x48, LFLD(s8, w, 0x37) ? 1 : 0);
    LFLD(s32, data_02097ce0, 4) = LFLD(s32, w, 0x28);
    LFLD(TwBits02153c48, LFLD(u8 *, self, 0x20), 4).f8 = 0x1e;
    LFLD(u32, LFLD(u8 *, self, 0x20), 4) |= 0x40;
    LFLD(u32, LFLD(u8 *, self, 0x20), 4) |= 0x1000000;
    LFLD(u32, LFLD(u8 *, self, 0x20), 4) |= 0x400000;
    LFLD(u32, LFLD(u8 *, self, 0x20), 4) |= 0x40000000;
    LFLD(u32, LFLD(u8 *, self, 0x20), 4) |= 4;
    if (show) {
        func_0204ca70(LFLD(u8 *, self, 0x20));
    }
}

}
