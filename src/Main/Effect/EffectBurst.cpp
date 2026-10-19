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
extern char data_0208c5e5[];
extern char data_0208c5eb[];
extern char data_0208c5f1[];
extern char data_0208c5f7[];
extern char data_0208c5fd[];
extern char data_0208c603[];
extern char data_0208c609[];
extern char data_0208c60f[];
extern char data_0208c615[];
extern char data_0208c61b[];
extern char data_0208c621[];
extern char data_0208c627[];
extern char data_0208c62d[];
extern char data_0208c633[];
extern char data_0208c639[];
extern char data_0208c63f[];
extern char data_0208c645[];
extern char data_0208c64b[];
extern char data_0208c651[];
extern char data_0208c657[];
extern char data_0208c65d[];
extern char data_0208c663[];
extern char data_0208c669[];
extern char data_0208c66f[];
extern char data_0208c675[];
extern char data_0208c67b[];
extern char data_0208c681[];
extern char data_0208c687[];
extern char data_0208c68d[];
extern char data_0208c693[];
extern char data_0208c699[];
extern char data_0208c69f[];
extern char data_0208c4a8[];
extern char data_0208c4af[];
extern void func_020639d4(EffectObj *obj, s32 id, s32 frame);
extern void func_02064d74(EffectGroup *g, const char *prefix, const char *name, const char *suffix);

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

EffectGroup *func_02067b08(s32 id, const EffectVec *pos) {
    EffectGroup *g = EffectGroup_New();
    const char *name = NULL;
    switch (id) {
    case 0x12c:
        name = data_0208c5e5;
        break;
    case 0x12d:
        name = data_0208c5eb;
        break;
    case 0x12e:
        name = data_0208c5f1;
        break;
    case 0x12f:
        name = data_0208c5f7;
        break;
    case 0x130:
        name = data_0208c5fd;
        break;
    case 0x131:
        name = data_0208c603;
        break;
    case 0x258:
        name = data_0208c609;
        break;
    case 0x259:
        name = data_0208c60f;
        break;
    case 0x25a:
        name = data_0208c615;
        break;
    case 0x25b:
        name = data_0208c61b;
        break;
    case 0x25c:
        name = data_0208c621;
        break;
    case 0x25d:
        name = data_0208c627;
        break;
    case 0x25e:
        name = data_0208c62d;
        break;
    case 0x25f:
        name = data_0208c633;
        break;
    case 0x260:
        name = data_0208c639;
        break;
    case 0x261:
        name = data_0208c63f;
        break;
    case 0x38a:
        name = data_0208c645;
        break;
    case 0x38b:
        name = data_0208c64b;
        break;
    case 0x38c:
        name = data_0208c651;
        break;
    case 0x38d:
        name = data_0208c657;
        break;
    case 0x38e:
        name = data_0208c65d;
        break;
    case 0x38f:
        name = data_0208c663;
        break;
    case 0x390:
        name = data_0208c669;
        break;
    case 0x325:
        name = data_0208c66f;
        break;
    case 0x2bc:
        name = data_0208c675;
        break;
    case 0x320:
        name = data_0208c67b;
        break;
    case 0x321:
        name = data_0208c681;
        break;
    case 0xca:
        g->loopCount = -1;
        name = data_0208c687;
        break;
    case 0xc8:
        name = data_0208c687;
        break;
    case 0xcb:
        name = data_0208c68d;
        break;
    case 0xcc:
        name = data_0208c693;
        break;
    case 0xcd:
        g->loopCount = -1;
        name = data_0208c693;
        break;
    case 0x190:
        name = data_0208c699;
        func_020639d4(g, 0x11, 0);
        break;
    case 0x193:
        name = data_0208c69f;
        break;
    }
    func_02064d74(g, data_0208c4a8, name, data_0208c4af);
    g->SetPos(pos);
    g->unk_20 = id;
    return g;
}

}
