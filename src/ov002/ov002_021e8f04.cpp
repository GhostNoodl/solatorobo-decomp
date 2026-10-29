#include "ov002/ov002.h"

extern "C" {


extern u8 data_ov002_021f0878[];
extern u8 data_ov002_021f087c[];
extern u8 data_ov002_021f0880[];
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

typedef struct Glob021f0f98 { void *a; u8 *g; } Glob021f0f98;
#define GAME (((Glob021f0f98 *)data_ov002_021f0f98)->g)

void func_ov002_021e8f04(s32 idx) {
    void *p;
    void *name;
    u8 *g;
    u8 m;
    s32 v;
    float f;
    s32 off;
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(*(VObject **)&data_ov002_021f0f98[1]);
        HEAP_POP(saved);
    }
    p = func_0203dd9c(0x2cc);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0674;
        *(VFunc **)((u8 *)p + 0x6c) = data_ov002_021f0684;
        func_ov002_021eacd0((u8 *)p + 0x6c);
        func_02043858((u8 *)p + 0x14c);
        func_ov002_021e7cb4(p);
    }
    off = idx * 0xc;
    GAME = (u8 *)p;
    FIELD(p, 0x1c, s32) = idx;
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
        f = (float)(v << 12) + 0.5f;
    } else {
        f = (float)(v << 12) - 0.5f;
    }
    v = (s32)f;
    {
        u8 *g3 = GAME;
        FIELD(g3, 0x14, s32) = v;
        FIELD(g3, 0x18, s16) = 1;
    }
}

}
