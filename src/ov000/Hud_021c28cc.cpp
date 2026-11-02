#include "types.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} F021c28cc;

class V021c28cc {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void f20(s32 x, s32 y);
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void f90();
};

extern "C" {

static inline void SetPos021c28cc(void *o, s32 x, s32 y) {
    LFLD(s32, o, 0xfc) = x;
    LFLD(s32, o, 0x100) = y;
}

// World position to screen cell coordinates; x and y are adjusted in place
static inline void ScreenPos021c28cc(s32 *ox, s32 *oy, s32 x, s32 y, s32 h) {
    x += 0xa000;
    y += (h - 8) << 12;
    *ox = (x >> 12) - 0x80;
    *oy = (y >> 12) - 0x60;
}

void func_ov000_021c28cc(Hud021cca10 *self) {
    s32 x;
    s32 y;
    Model *m;
    s32 z;
    Model *n;
    if (self->unk_44 == 0) {
        return;
    }
    if (!LFLD(F021c28cc, self, 0x20).b0) {
        return;
    }
    ScreenPos021c28cc(&x, &y, self->unk_0c, self->unk_10, self->unk_18);
    z = self->unk_14;
    SetPos021c28cc(self->unk_34, x << 12, (y + 7) << 12);
    self->unk_34->unk_150 = z;
    m = self->unk_34;
    Model_PlayPart(m, 4);
    SetPos021c28cc(self->unk_30, (x + 0x10) << 12, (y - 2) << 12);
    self->unk_30->unk_150 = z;
    n = self->unk_30;
    Model_PlayPart(n, 6);
    ((V021c28cc *)self->unk_38)->f20((self->unk_0c + 0x40000) >> 12, (self->unk_10 + ((self->unk_18 - LFLD(s32, self->unk_38, 0x48)) << 11)) >> 12);
    LFLD(s32, self->unk_38, 0x70) = z;
    ((V021c28cc *)self->unk_38)->f90();
}
}
