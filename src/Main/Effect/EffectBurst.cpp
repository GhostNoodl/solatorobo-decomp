#include "Main/Effect/Effect.h"

extern "C" {

extern u32 data_0208c23c[];
extern u32 data_0208c290[];
extern u32 data_0208c2e4[];
extern char data_0208c4da[];
extern void func_02063a34(EffectObj *obj);
extern void func_02063f90(Effect3D *e);
extern void func_02064d3c(EffectObj *obj, EffectObj *child);
extern void func_02064dd8(EffectGroup *g);
extern s32 func_02040528(s32 range);

// Keeps the NULL check on a string address, which the compiler would otherwise fold.
#define EFFECT_STR(s) ((const char *)(u32)(s))

static inline void Effect_SetStr(char *dst, const char *src) {
    if (src == NULL) {
        dst[0] = 0;
    } else {
        STD_CopyString(dst, src);
    }
}

static inline Effect3D *Effect3D_New(void) {
    Effect3D *e = (Effect3D *)func_0203dd9c(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = data_0208c2e4;
        func_02063a34(e);
        *(u32 **)e = data_0208c290;
        func_02063f90(e);
    }
    return e;
}

static inline EffectGroup *EffectGroup_New(void) {
    EffectGroup *g = (EffectGroup *)func_0203dd9c(sizeof(EffectGroup));
    if (g != NULL) {
        *(u32 **)g = data_0208c2e4;
        func_02063a34(g);
        *(u32 **)g = data_0208c23c;
        func_02064dd8(g);
    }
    return g;
}

EffectGroup *func_02067984(const EffectVec *pos) {
    EffectGroup *g = EffectGroup_New();
    s32 i;
    for (i = 0; i < 3; i++) {
        Effect3D *e = Effect3D_New();
        Effect_SetStr(e->mdlName, EFFECT_STR(data_0208c4da));
        e->unk_28 = 0;
        switch (i) {
        case 0:
            e->SetRotXYZ(func_02040528(0xffff), func_02040528(0xffff), func_02040528(0xffff));
            break;
        case 1:
            e->SetRotXYZ(0, func_02040528(0x1000), 0x2000);
            break;
        case 2:
            e->SetRotXYZ(0, func_02040528(0x1000), 0xe000);
            break;
        }
        func_02064d3c(g, e);
    }
    g->unk_20 = 0x69;
    g->SetPos(pos);
    return g;
}

}
