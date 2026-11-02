#include "Main/Effect/EffectInt.h"

extern "C" {

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
        if (STD_CompareNString((const char *)p, data_0208c7fe, 8) == 0) {
            setup->chunk20 = p;
            p += 8;
            while (STD_CompareNString((const char *)p, data_0208c806, 8) != 0) {
                MI_CpuCopy8(p + 0x14, &entrySize, 4);
                p += entrySize + 0x18;
            }
            p += 8;
        } else if (STD_CompareNString((const char *)p, data_0208c80e, 8) == 0) {
            u32 size;
            setup->chunk24 = p;
            MI_CpuCopy8(p + 0xc, &size, 4);
            p = p + 0x18 + size;
        } else if (STD_CompareNString((const char *)p, data_0208c816, 8) == 0) {
            u32 size;
            setup->chunk1c = p;
            MI_CpuCopy8(p + 0xc, &size, 4);
            p = p + 0x18 + size;
        } else if (STD_CompareNString((const char *)p, data_0208c81e, 8) == 0) {
            setup->chunk18 = p;
            p += 8;
            while (STD_CompareNString((const char *)p, data_0208c806, 8) != 0) {
                MI_CpuCopy8(p + 0x8, &entrySize2, 4);
                p += entrySize2 + 0xc;
            }
            p += 8;
        } else if (STD_CompareNString((const char *)p, data_0208c826, 8) == 0) {
            u32 size;
            setup->objChunk = p;
            MI_CpuCopy8(p + 0xc, &size, 4);
            p = p + 0x18 + size;
        } else if (STD_CompareNString((const char *)p, data_0208c82e, 8) == 0) {
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
extern void EffectObj_AddSndCue(EffectObj *obj, s32 id, s32 frame);
extern void func_02069184(EffectEmitterSub *sub);
extern void EffectEmitter_Reset(EffectEmitter *em);
extern void EffectEmitter_ResetParams(EffectEmitter *em);
extern void EffectPartSet_Init(EffectPartSet *parts);
extern void func_0206a138(EffectPartSet *parts);
extern void func_0206a0d8(EffectPartSet *parts);
extern BOOL EffectPartSet_AddSlot(EffectPartSet *parts, const u8 *data);
extern void func_02069248(EffectEmitterSub *sub);

void func_02068c40(EffectSetup *setup, EffectObj *obj, s32 id);
void func_020689ec(EffectSetup *setup, EffectEmitter *em, const char *name);
void func_02068ab8(EffectSetup *setup, EffectEmitter *em, s32 id);
void func_02068b6c(EffectSetup *setup, EffectPartSet *parts, u8 *ids);

static inline void Effect_SetStr(char *dst, const char *src) {
    if (src == NULL) {
        dst[0] = 0;
    } else {
        STD_CopyString(dst, src);
    }
}

EffectObj *func_020687f8(EffectSetup *setup, EffectDef *def) {
    EffectObj *ret = NULL;
    switch (def->type) {
    case 0: {
        Effect3D *e = (Effect3D *)Heap_Alloc(sizeof(Effect3D));
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
        EffectEmitter *em = (EffectEmitter *)Heap_Alloc(0x1d8);
        EffectPartSet *parts;
        if (em != NULL) {
            *(u32 **)em = data_0208c2e4;
            func_02063a34(em);
            *(u32 **)em = data_0208c868;
            *(u32 **)&em->sub = data_0208c354;
            func_02069184(&em->sub);
            EffectEmitter_Reset(em);
            *(u32 **)em = data_0208c8bc;
            EffectEmitter_ResetParams(em);
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
        parts = (EffectPartSet *)Heap_Alloc(0x12c);
        if (parts != NULL) {
            *(u32 **)parts = data_0208c364;
            EffectPartSet_Init(parts);
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

EffectEmitterSub *MainVt_0208c354_Dtor(EffectEmitterSub *sub) {
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
    while (STD_CompareNString((const char *)p, data_0208c806, 8) != 0) {
        if (STD_CompareNString((const char *)p, name, 0x10) == 0) {
            break;
        }
        MI_CpuCopy8(p + 0x14, &size, 4);
        p += size + 0x18;
    }
    MI_CpuCopy8(p + 0x10, &count, 4);
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
    MI_CpuCopy8(setup->chunk1c + 8, &count, 4);
    MI_CpuCopy8(setup->chunk1c + 0xc, &size, 4);
    size = size / count;
    for (i = 0; i < size; i++) {
        MI_CpuCopy8(p, &v, 4);
        if (v == id) {
            break;
        }
        p += size;
    }
    MIi_CpuCopy32(p, &em->params, 0x50);
}

void func_02068b6c(EffectSetup *setup, EffectPartSet *parts, u8 *ids) {
    s32 count;
    s32 size;
    u32 v;
    s32 j;
    u8 *p;
    s32 i;
    MI_CpuCopy8(setup->chunk24 + 8, &count, 4);
    MI_CpuCopy8(setup->chunk24 + 0xc, &size, 4);
    size = size / count;
    for (j = 0; j < 4; j++) {
        if (ids[j] == 0xff) {
            continue;
        }
        p = setup->chunk24 + 0x10;
        for (i = 0; i < count; i++) {
            MI_CpuCopy8(p, &v, 4);
            if (v == ids[j]) {
                break;
            }
            p += size;
        }
        EffectPartSet_AddSlot(parts, p);
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
    while (STD_CompareNString((const char *)p, data_0208c806, 8) != 0) {
        MI_CpuCopy8(p, &v, 4);
        if (v == id) {
            break;
        }
        MI_CpuCopy8(p + 8, &size, 4);
        p += size;
    }
    MI_CpuCopy8(p + 4, &n, 4);
    cues = (s32 *)(p + 0xc);
    for (i = 0; i < n; i++) {
        EffectObj_AddSndCue(obj, cues[i * 2], cues[i * 2 + 1]);
    }
}

EffectPartSet *MainVt_0208c364_DtorDelete(EffectPartSet *parts) {
    *(u32 **)parts = data_0208c364;
    func_0206a0d8(parts);
    Heap_Free(parts);
    return parts;
}

BOOL func_02068d54(EffectPartSet *parts) {
    return TRUE;
}

void func_02068d5c(EffectPartSet *parts) {
}

EffectPartSet *MainVt_0208c364_Dtor(EffectPartSet *parts) {
    *(u32 **)parts = data_0208c364;
    func_0206a0d8(parts);
    return parts;
}

EffectEmitterSub *MainVt_0208c354_DtorDelete(EffectEmitterSub *sub) {
    *(u32 **)sub = data_0208c354;
    func_02069248(sub);
    Heap_Free(sub);
    return sub;
}

}
