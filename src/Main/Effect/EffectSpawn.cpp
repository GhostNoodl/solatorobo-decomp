#include "Main/Effect/Effect.h"

extern "C" {

extern u32 data_0208c23c[];
extern u32 data_0208c290[];
extern u32 data_0208c2e4[];
extern char data_0208c380[];
extern char data_0208c4a8[];
extern char data_0208c4af[];
extern char data_0208c5a6[];
extern char data_0208c6a5[];
extern char data_0208c6b7[];
extern char data_0208c6c3[];
extern char data_0208c6cf[];
extern char data_0208c6db[];
extern char data_0208c6e7[];
extern char data_0208c6ed[];
extern char data_0208c6f3[];
extern char data_0208c6f9[];
extern char data_0208c6ff[];
extern char data_0208c705[];
extern char data_0208c70b[];
extern char data_0208c711[];
extern char data_0208c717[];
extern char data_0208c71d[];
extern char data_0208c723[];
extern char data_0208c729[];
extern char data_0208c72f[];
extern char data_0208c735[];
extern char data_0208c73b[];
extern char data_0208c741[];
extern char data_0208c747[];
extern void func_02063a34(EffectObj *obj);
extern void func_02063f90(Effect3D *e);
extern void func_020639d4(EffectObj *obj, s32 id, s32 frame);
extern void func_02064d3c(EffectObj *obj, EffectObj *child);
extern void func_02064d74(EffectGroup *g, const char *prefix, const char *name, const char *suffix);
extern void func_02064dd8(EffectGroup *g);
extern void func_0206e900(char *dst, const char *src);
extern u32 data_0208c1d8[];
extern char data_0208c74d[];
extern char data_0208c75f[];
extern char data_0208c771[];
extern char data_0208c783[];
extern char data_0208c795[];
extern char data_0208c7a7[];
extern char data_0208c7b9[];
extern char data_0208c7cb[];
extern char data_0208c7dd[];
extern char data_0208c7ef[];
extern EffectFile *func_02034b98(void *arc, const char *name);
extern EffectObj *func_02068544(EffectSetup *setup);

typedef struct EffectSetupBuf {
    u32 *vt;
    u8 *data;
    EffectVec pos;
    u8 *objChunk;
    u8 *chunk18;
    u8 *chunk1c;
    u8 *chunk20;
    u8 *chunk24;
} EffectSetupBuf;

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

static inline EffectFile *Effect_GetFile(const char *name) {
    return func_02034b98(func_02035d5c(data_0208c7ef), name);
}

EffectObj *func_02067e9c(s32 id, const EffectVec *pos) {
    EffectGroup *g = NULL;
    if (id == 0x191) {
        Effect3D *e;
        char buf[0x20];
        g = EffectGroup_New();
        Effect_SetStr(g->name, EFFECT_STR(data_0208c6a5));
        e = Effect3D_New();
        func_0206e900(buf, data_0208c380);
        STD_CopyString(e->arcName, buf);
        Effect_SetStr(e->mdlName, EFFECT_STR(data_0208c6b7));
        e->unk_50 = -0x14000;
        e->unk_54 = -0x14000;
        func_02064d3c(g, e);
        func_020639d4(g, 0x85, 0);
    }
    g->SetPos(pos);
    g->unk_20 = id;
    return g;
}

Effect3D *func_02067fd4(s32 id, const EffectVec *pos) {
    Effect3D *e = Effect3D_New();
    switch (id) {
    case 0x44c:
        Effect_SetStr(e->mdlName, EFFECT_STR(data_0208c6c3));
        e->unk_28 = 1;
        break;
    case 0x44d:
    case 0x44e:
        Effect_SetStr(e->mdlName, EFFECT_STR(data_0208c6cf));
        e->unk_28 = 1;
        if (id == 0x44e) {
            e->loopCount = -1;
        }
        break;
    case 0x44f:
        Effect_SetStr(e->arcName, EFFECT_STR(data_0208c5a6));
        Effect_SetStr(e->mdlName, EFFECT_STR(data_0208c6db));
        e->unk_28 = 1;
        e->unk_50 = -0x14000;
        e->unk_54 = -0x14000;
        break;
    }
    e->unk_20 = id;
    e->SetPos(pos);
    return e;
}

EffectGroup *func_0206811c(s32 id, const EffectVec *pos) {
    EffectGroup *g = EffectGroup_New();
    const char *name;
    g->SetPos(pos);
    g->unk_20 = id;
    name = NULL;
    switch (id) {
    case 0x578:
        name = data_0208c6e7;
        break;
    case 0x579:
        name = data_0208c6ed;
        break;
    case 0x57a:
        name = data_0208c6f3;
        break;
    case 0x57b:
        name = data_0208c6f9;
        break;
    case 0x57c:
        name = data_0208c6ff;
        break;
    case 0x57d:
        name = data_0208c705;
        break;
    case 0x57e:
        name = data_0208c70b;
        break;
    case 0x57f:
        name = data_0208c711;
        break;
    }
    func_02064d74(g, data_0208c4a8, name, data_0208c4af);
    return g;
}

EffectGroup *func_02068228(s32 id, const EffectVec *pos) {
    EffectGroup *g = EffectGroup_New();
    const char *name;
    g->SetPos(pos);
    g->unk_20 = id;
    name = NULL;
    switch (id) {
    case 0x5dc:
        name = data_0208c717;
        break;
    case 0x5dd:
        name = data_0208c71d;
        break;
    case 0x5de:
        name = data_0208c723;
        break;
    case 0x5df:
        name = data_0208c729;
        break;
    case 0x5e0:
        name = data_0208c72f;
        break;
    case 0x5e1:
        name = data_0208c735;
        break;
    case 0x5e2:
        name = data_0208c73b;
        break;
    case 0x5e3:
        name = data_0208c741;
        break;
    case 0x5e4:
        name = data_0208c747;
        break;
    }
    func_02064d74(g, data_0208c4a8, name, data_0208c4af);
    func_020639d4(g, 0x36, 0);
    return g;
}

EffectGroup *func_02068354(s32 id, const EffectVec *pos) {
    const char *name = NULL;
    EffectFile *file;
    EffectGroup *g;
    EffectObj *c;
    EffectSetupBuf setup;
    switch (id) {
    case 0x640:
        name = data_0208c74d;
        break;
    case 0x641:
        name = data_0208c75f;
        break;
    case 0x642:
        name = data_0208c771;
        break;
    case 0x643:
        name = data_0208c783;
        break;
    case 0x644:
        name = data_0208c795;
        break;
    case 0x645:
        name = data_0208c7a7;
        break;
    case 0x646:
        name = data_0208c7b9;
        break;
    case 0x647:
        name = data_0208c7cb;
        break;
    case 0x648:
        name = data_0208c7dd;
        break;
    }
    file = Effect_GetFile(name);
    g = EffectGroup_New();
    g->SetPos(pos);
    setup.vt = data_0208c1d8;
    setup.data = (u8 *)file->data;
    setup.pos = *pos;
    setup.objChunk = NULL;
    setup.chunk18 = NULL;
    setup.chunk1c = NULL;
    setup.chunk20 = NULL;
    setup.chunk24 = NULL;
    func_02064d3c(g, func_02068544((EffectSetup *)&setup));
    setup.vt = data_0208c1d8;
    g->unk_20 = id;
    for (c = g->child; c != NULL; c = c->child) {
        if (c->unk_14 == 2) {
            *(s32 *)((u8 *)c + 0x170) = 0x14000;
        }
    }
    func_020639d4(g, 0x36, 0);
    return g;
}

}
