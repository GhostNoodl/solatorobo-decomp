#include "ov002/ov002.h"

extern "C" {

extern u32 func_0200aeec(s32 v);
extern u32 _fadd(u32 a, u32 b);
extern u32 _fsub(u32 a, u32 b);
extern s32 _ffix(u32 v);

extern u8 data_ov002_021f0878[];
extern u8 data_ov002_021f087c[];
extern u8 data_ov002_021f0880[];
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

typedef struct Glob021f0f98 { void *a; u8 *g; } Glob021f0f98;
#define GAME (((Glob021f0f98 *)data_ov002_021f0f98)->g)
void func_ov002_021e9e40(int idx) {
    void *name;
    u8 *g;
    u8 m;
    s32 v;
    u32 f;
    s32 off = idx * 0xc;
    FIELD(GAME, 0x1c, s32) = idx;
    name = *(void **)(data_ov002_021f0878 + off);
    g = (u8 *)GAME;
    FIELD(g, 0x20, void *) = name;
    m = ((u8 (*)(void))func_0206e8f0)();
    MI_CpuFill8(g + 0x24, 0, 0x20);
    STD_CopyLString(g + 0x24, name, 0x20);
    STD_TSNPrintf(g + 0x24, 0x20, data_ov002_021f0647, name, data_ov002_021f0624[m]);
    {
        void *desc;
        u8 *g2;
        g2 = GAME;
        desc = *(void **)(data_ov002_021f087c + off);
        FIELD(g2, 0x44, void *) = desc;
        func_ov002_021e9d7c(g2 + 0x48, 0x20, desc, 0, ((u8 (*)(void))func_0206e8f0)());
    }
    v = *(s16 *)(data_ov002_021f0880 + off);
    if (v > 0) {
        f = _fadd(0x3f000000, func_0200aeec(v << 12));
    } else {
        f = _fsub(func_0200aeec(v << 12), 0x3f000000);
    }
    v = _ffix(f);
    {
        u8 *g3 = GAME;
        FIELD(g3, 0x14, s32) = v;
        FIELD(g3, 0x18, s16) = 1;
    }
}

}
