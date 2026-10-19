#include "Main/Effect/Effect.h"

#define EFFECT_STR(s) ((const char *)(u32)(s))

extern "C" {

extern char data_0208c448[];
extern char data_0208c44e[];
extern char data_0208c454[];
extern char data_0208c45a[];
extern char data_0208c460[];
extern char data_0208c466[];
extern char data_0208c46c[];
extern char data_0208c472[];
extern char data_0208c478[];
extern char data_0208c47e[];
extern char data_0208c484[];
extern char data_0208c48a[];
extern char data_0208c490[];
extern char data_0208c496[];
extern char data_0208c49c[];
extern char data_0208c4a2[];
extern char data_0208c4a8[];
extern char data_0208c4af[];
extern u32 data_0208c23c[];
extern u32 data_0208c2e4[];
extern void func_02063a34(EffectObj *obj);
extern void func_02064dd8(EffectGroup *g);
extern void func_02064d74(EffectGroup *g, const char *prefix, const char *name, const char *suffix);
extern char data_0208c4b6[];
extern char data_0208c4c2[];
extern char data_0208c4ce[];
extern char data_0208c4da[];
extern char data_0208c4e6[];
extern char data_0208c4f2[];
extern char data_0208c4fe[];
extern char data_0208c50a[];
extern char data_0208c516[];
extern char data_0208c522[];
extern char data_0208c52e[];
extern char data_0208c53a[];
extern char data_0208c546[];
extern char data_0208c552[];
extern char data_0208c55e[];
extern char data_0208c56a[];
extern char data_0208c576[];
extern char data_0208c582[];
extern char data_0208c58e[];
extern char data_0208c59a[];
extern char data_0208c5a6[];
extern char data_0208c5b5[];
extern char data_0208c5c1[];
extern char data_0208c5cd[];
extern char data_0208c5d9[];
extern u32 data_0208c290[];
extern void func_02063f90(Effect3D *e);
extern char data_0208c427[];
extern char data_0208c436[];
extern void func_020639d4(EffectObj *obj, s32 id, s32 frame);
extern EffectGroup *func_02066900(const char *arc, const char *name, const EffectVec *pos);

EffectGroup *func_020671e8(const EffectVec *pos) {
    EffectGroup *g = func_02066900(data_0208c427, data_0208c436, pos);
    g->unk_20 = 0x2717;
    func_020639d4(g, 0x5e, 2);
    func_020639d4(g, 0x5e, 0x14);
    return g;
}

static inline EffectGroup *Effect6_GroupNew(void) {
    EffectGroup *g = (EffectGroup *)func_0203dd9c(sizeof(EffectGroup));
    if (g != NULL) {
        *(u32 **)g = data_0208c2e4;
        func_02063a34(g);
        *(u32 **)g = data_0208c23c;
        func_02064dd8(g);
    }
    return g;
}

EffectGroup *func_0206723c(s32 id, const EffectVec *pos) {
    EffectGroup *g = Effect6_GroupNew();
    const char *name = NULL;
    s32 scale = 0x1000;
    s32 cue = -1;
    s32 frame = 0;
    switch (id) {
    case 0:
        name = data_0208c448;
        scale = 0x800;
        cue = 0x19;
        frame = 3;
        break;
    case 1:
        name = data_0208c448;
        scale = 0xccd;
        cue = 0x1a;
        frame = 3;
        break;
    case 2:
        name = data_0208c448;
        scale = 0x1333;
        cue = 0x1b;
        frame = 3;
        break;
    case 3:
        name = data_0208c44e;
        cue = 0x1a;
        frame = 3;
        break;
    case 4:
        name = data_0208c454;
        break;
    case 6:
        name = data_0208c45a;
        break;
    case 0x1f4:
        name = data_0208c460;
        cue = 0x15;
        frame = 4;
        break;
    case 0x1f5:
        name = data_0208c466;
        cue = 0x66;
        frame = 4;
        break;
    case 0x1f6:
        name = data_0208c46c;
        cue = 0x5a;
        frame = 4;
        break;
    case 0x1f7:
        name = data_0208c472;
        cue = 0x5a;
        frame = 4;
        break;
    case 0x1f8:
        name = data_0208c478;
        cue = 0x52;
        frame = 4;
        break;
    case 0x1f9:
        name = data_0208c47e;
        cue = 0x5a;
        frame = 4;
        break;
    case 0x64:
        name = data_0208c484;
        scale = 0xb33;
        break;
    case 0x65:
        name = data_0208c48a;
        break;
    case 0x6a:
    case 0x6a4:
        name = data_0208c490;
        break;
    case 0x6c:
        name = data_0208c496;
        break;
    case 0x6d:
        name = data_0208c49c;
        break;
    case 0x328:
        name = data_0208c4a2;
        break;
    }
    func_02064d74(g, data_0208c4a8, name, data_0208c4af);
    if (scale != 0x1000) {
        g->SetScaleXYZ(scale, scale, scale);
    }
    if (cue >= 0) {
        func_020639d4(g, cue, frame);
    }
    g->unk_20 = id;
    g->SetPos(pos);
    return g;
}

static inline Effect3D *Effect6_3DNew(void) {
    Effect3D *e = (Effect3D *)func_0203dd9c(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = data_0208c2e4;
        func_02063a34(e);
        *(u32 **)e = data_0208c290;
        func_02063f90(e);
    }
    return e;
}

static inline void Effect6_SetStr(char *dst, const char *src) {
    if (src == NULL) {
        dst[0] = 0;
    } else {
        STD_CopyString(dst, src);
    }
}

Effect3D *func_020674dc(s32 id, const EffectVec *pos) {
    Effect3D *e = Effect6_3DNew();
    const char *name = NULL;
    switch (id) {
    case 5:
        name = data_0208c4b6;
        break;
    case 0x66:
        e->unk_28 = 0;
        name = data_0208c4c2;
        break;
    case 0x67:
        e->unk_28 = 0;
        name = data_0208c4ce;
        break;
    case 0x68:
        e->unk_28 = 0;
        name = data_0208c4da;
        break;
    case 0x6b:
        name = data_0208c4e6;
        break;
    case 0x326:
        e->unk_28 = 0;
        name = data_0208c4f2;
        break;
    case 0x327:
        e->unk_28 = 0;
        name = data_0208c4fe;
        break;
    case 0x323:
        name = data_0208c50a;
        Effect6_SetStr(e->anmName, EFFECT_STR(data_0208c516));
        break;
    case 0x324:
        name = data_0208c50a;
        Effect6_SetStr(e->anmName, EFFECT_STR(data_0208c516));
        e->loopCount = -1;
        break;
    case 0x2bd:
        e->unk_28 = 0;
        name = data_0208c522;
        break;
    case 0x4b0:
        e->unk_28 = 0;
        name = data_0208c52e;
        func_020639d4(e, 0x35, 0);
        break;
    case 0x322:
        name = data_0208c53a;
        break;
    case 0x384:
        name = data_0208c546;
        func_020639d4(e, 0x36, 4);
        break;
    case 0x391:
        name = data_0208c552;
        break;
    case 0x389:
        name = data_0208c55e;
        func_020639d4(e, 0x36, 4);
        break;
    case 0x385:
        e->unk_28 = 0;
        name = data_0208c56a;
        break;
    case 0x386:
        e->unk_28 = 0;
        name = data_0208c576;
        break;
    case 0x387:
        e->unk_28 = 0;
        e->loopCount = -1;
        name = data_0208c56a;
        break;
    case 0x388:
        e->unk_28 = 0;
        e->loopCount = -1;
        name = data_0208c576;
        break;
    case 0x192:
        e->unk_28 = 0;
        name = data_0208c582;
        break;
    case 0x194:
        e->unk_28 = 1;
        name = data_0208c546;
        break;
    case 0x195:
        e->unk_28 = 1;
        name = data_0208c58e;
        break;
    case 0x196:
        e->unk_28 = 1;
        name = data_0208c59a;
        break;
    case 0xc9:
        e->unk_28 = 0;
        func_020639d4(e, 0x21, 4);
        Effect6_SetStr(e->arcName, EFFECT_STR(data_0208c5a6));
        name = data_0208c5b5;
        break;
    case 0x3e9:
        e->unk_28 = 0;
        func_020639d4(e, 0x64, 6);
        Effect6_SetStr(e->anmName, EFFECT_STR(data_0208c5c1));
        name = data_0208c5c1;
        break;
    case 0x3ea:
        e->unk_28 = 0;
        func_020639d4(e, 0x65, 6);
        Effect6_SetStr(e->anmName, EFFECT_STR(data_0208c5cd));
        name = data_0208c5c1;
        break;
    case 0x3eb:
        e->unk_28 = 0;
        func_020639d4(e, 0x64, 6);
        Effect6_SetStr(e->anmName, EFFECT_STR(data_0208c5d9));
        name = data_0208c5d9;
        break;
    }
    Effect6_SetStr(e->mdlName, name);
    e->unk_20 = id;
    e->SetPos(pos);
    return e;
}

}
