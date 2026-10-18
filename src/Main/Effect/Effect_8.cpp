#include "Main/Effect/Effect.h"

extern "C" {

extern s32 func_0201e868(const void *a, const char *b, u32 n);
extern void func_02016fa0(const void *src, void *dst, u32 size);
extern s32 _s32_div_f(s32 a, s32 b);
extern char data_0208c7fe[];
extern char data_0208c806[];
extern char data_0208c80e[];
extern char data_0208c816[];
extern char data_0208c81e[];
extern char data_0208c826[];
extern char data_0208c82e[];

EffectObj *func_020687f8(EffectSetup *setup, EffectDef *def);

void func_02068600(EffectSetup *setup) {
    u32 entrySize;
    u32 entrySize2;
    u8 *p = setup->data + 0xc;
    for (;;) {
        if (func_0201e868(p, data_0208c7fe, 8) == 0) {
            setup->chunk20 = p;
            p += 8;
            while (func_0201e868(p, data_0208c806, 8) != 0) {
                func_02016fa0(p + 0x14, &entrySize, 4);
                p += entrySize + 0x18;
            }
            p += 8;
        } else if (func_0201e868(p, data_0208c80e, 8) == 0) {
            u32 size;
            setup->chunk24 = p;
            func_02016fa0(p + 0xc, &size, 4);
            p = p + 0x18 + size;
        } else if (func_0201e868(p, data_0208c816, 8) == 0) {
            u32 size;
            setup->chunk1c = p;
            func_02016fa0(p + 0xc, &size, 4);
            p = p + 0x18 + size;
        } else if (func_0201e868(p, data_0208c81e, 8) == 0) {
            setup->chunk18 = p;
            p += 8;
            while (func_0201e868(p, data_0208c806, 8) != 0) {
                func_02016fa0(p + 0x8, &entrySize2, 4);
                p += entrySize2 + 0xc;
            }
            p += 8;
        } else if (func_0201e868(p, data_0208c826, 8) == 0) {
            u32 size;
            setup->objChunk = p;
            func_02016fa0(p + 0xc, &size, 4);
            p = p + 0x18 + size;
        } else if (func_0201e868(p, data_0208c82e, 8) == 0) {
            return;
        }
    }
}

extern u32 data_0208c290[];
extern u32 data_0208c2e4[];
extern u32 data_0208c354[];
extern u32 data_0208c364[];
extern u32 data_0208c850[];
extern u32 data_0208c868[];
extern u32 data_0208c8bc[];
extern void func_02063a34(EffectObj *obj);
extern void func_02063f90(Effect3D *e);
extern void func_020639d4(EffectObj *obj, s32 id, s32 frame);
extern void func_02069184(EffectEmitterSub *sub);
extern void func_0206ad84(EffectEmitter *em);
extern void func_0206b744(EffectEmitter *em);
extern void func_0206a0cc(EffectPartSet *parts);
extern void func_0206a138(EffectPartSet *parts);
extern void func_0206a0d8(EffectPartSet *parts);
extern void func_0206a0dc(EffectPartSet *parts, u8 *data);
extern void func_02069248(EffectEmitterSub *sub);
extern void func_02016cec(const void *src, void *dst, u32 size);

void func_02068c40(EffectSetup *setup, EffectObj *obj, s32 id);
void func_020689ec(EffectSetup *setup, EffectEmitter *em, const char *name);
void func_02068ab8(EffectSetup *setup, EffectEmitter *em, s32 id);
void func_02068b6c(EffectSetup *setup, EffectPartSet *parts, u8 *ids);

static inline void Effect_SetStr(char *dst, const char *src) {
    if (src == NULL) {
        dst[0] = 0;
    } else {
        func_0201e520(dst, src);
    }
}

EffectObj *func_020687f8(EffectSetup *setup, EffectDef *def) {
    EffectObj *ret = NULL;
    switch (def->type) {
    case 0: {
        Effect3D *e = (Effect3D *)func_0203dd9c(sizeof(Effect3D));
        if (e != NULL) {
            *(u32 **)e = data_0208c2e4;
            func_02063a34(e);
            *(u32 **)e = data_0208c290;
            func_02063f90(e);
        }
        ret = e;
        Effect_SetStr(e->arcName, def->arcName[0] != 0 ? def->arcName : NULL);
        Effect_SetStr(e->mdlName, def->mdlName);
        e->time = -def->delay;
        e->unk_28 = def->unk_38;
        e->loopCount = def->loopCount;
        func_02068c40(setup, e, def->cueId);
        break;
    }
    case 1: {
        EffectEmitter *em = (EffectEmitter *)func_0203dd9c(0x1d8);
        EffectPartSet *parts;
        if (em != NULL) {
            *(u32 **)em = data_0208c2e4;
            func_02063a34(em);
            *(u32 **)em = data_0208c868;
            *(u32 **)&em->sub = data_0208c354;
            func_02069184(&em->sub);
            func_0206ad84(em);
            *(u32 **)em = data_0208c8bc;
            func_0206b744(em);
        }
        ret = em;
        em->time = -def->delay;
        func_02068c40(setup, em, def->cueId);
        em->nameDef = def->arcName[0] != 0 ? def : NULL;
        em->def = def;
        em->unk_28 = def->unk_38;
        em->loopCount = def->loopCount;
        func_020689ec(setup, em, def->emitName);
        func_02068ab8(setup, em, def->paramId);
        parts = (EffectPartSet *)func_0203dd9c(0x12c);
        if (parts != NULL) {
            *(u32 **)parts = data_0208c364;
            func_0206a0cc(parts);
            *(u32 **)parts = data_0208c850;
            func_0206a138(parts);
        }
        func_02068b6c(setup, parts, def->partIds);
        em->parts = parts;
        break;
    }
    }
    return ret;
}

EffectEmitterSub *func_020689cc(EffectEmitterSub *sub) {
    *(u32 **)sub = data_0208c354;
    func_02069248(sub);
    return sub;
}

static inline void EffectEmitter_SetData(EffectEmitter *em, u8 *data, s32 count) {
    em->emitData = (EffectPtclCmd *)data;
    em->emitCount = count;
}

void func_020689ec(EffectSetup *setup, EffectEmitter *em, const char *name) {
    u32 count;
    u32 size;
    u8 *p;
    if (name[0] == 0) {
        return;
    }
    p = setup->chunk20 + 8;
    while (func_0201e868(p, data_0208c806, 8) != 0) {
        if (func_0201e868(p, name, 0x10) == 0) {
            break;
        }
        func_02016fa0(p + 0x14, &size, 4);
        p += size + 0x18;
    }
    func_02016fa0(p + 0x10, &count, 4);
    EffectEmitter_SetData(em, p + 0x18, count);
}

void func_02068ab8(EffectSetup *setup, EffectEmitter *em, s32 id) {
    s32 size;
    s32 count;
    s32 v;
    u8 *p;
    s32 i;
    if (id < 0) {
        return;
    }
    p = setup->chunk1c + 0x10;
    func_02016fa0(setup->chunk1c + 8, &count, 4);
    func_02016fa0(setup->chunk1c + 0xc, &size, 4);
    size = size / count;
    for (i = 0; i < size; i++) {
        func_02016fa0(p, &v, 4);
        if (v == id) {
            break;
        }
        p += size;
    }
    func_02016cec(p, &em->params, 0x50);
}

void func_02068b6c(EffectSetup *setup, EffectPartSet *parts, u8 *ids) {
    s32 count;
    s32 size;
    u32 v;
    s32 j;
    u8 *p;
    s32 i;
    func_02016fa0(setup->chunk24 + 8, &count, 4);
    func_02016fa0(setup->chunk24 + 0xc, &size, 4);
    size = size / count;
    for (j = 0; j < 4; j++) {
        if (ids[j] == 0xff) {
            continue;
        }
        p = setup->chunk24 + 0x10;
        for (i = 0; i < count; i++) {
            func_02016fa0(p, &v, 4);
            if (v == ids[j]) {
                break;
            }
            p += size;
        }
        func_0206a0dc(parts, p);
    }
}

void func_02068c40(EffectSetup *setup, EffectObj *obj, s32 id) {
    s32 v;
    s32 size;
    s32 n;
    s32 *cues;
    s32 i;
    u8 *p;
    if (id < 0) {
        return;
    }
    p = setup->chunk18 + 8;
    while (func_0201e868(p, data_0208c806, 8) != 0) {
        func_02016fa0(p, &v, 4);
        if (v == id) {
            break;
        }
        func_02016fa0(p + 8, &size, 4);
        p += size;
    }
    func_02016fa0(p + 4, &n, 4);
    cues = (s32 *)(p + 0xc);
    for (i = 0; i < n; i++) {
        func_020639d4(obj, cues[i * 2], cues[i * 2 + 1]);
    }
}

EffectPartSet *func_02068d2c(EffectPartSet *parts) {
    *(u32 **)parts = data_0208c364;
    func_0206a0d8(parts);
    func_0203de1c(parts);
    return parts;
}

BOOL func_02068d54(EffectPartSet *parts) {
    return TRUE;
}

void func_02068d5c(EffectPartSet *parts) {
}

EffectPartSet *func_02068d60(EffectPartSet *parts) {
    *(u32 **)parts = data_0208c364;
    func_0206a0d8(parts);
    return parts;
}

EffectEmitterSub *func_02068d80(EffectEmitterSub *sub) {
    *(u32 **)sub = data_0208c354;
    func_02069248(sub);
    func_0203de1c(sub);
    return sub;
}

}
