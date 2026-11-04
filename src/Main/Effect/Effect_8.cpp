#include "Main/Effect/EffectInt.h"

extern "C" {

extern char data_0208c7fe[];
extern char data_0208c806[];
extern char data_0208c80e[];
extern char data_0208c816[];
extern char data_0208c81e[];
extern char data_0208c826[];
extern char data_0208c82e[];

EffectObj *EffectSetup_NewObj(EffectSetup *setup, EffectDef *def);

void EffectSetup_FindChunks(EffectSetup *setup) {
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

extern u32 MainVt_0208c290_vtbl[];
extern u32 EffectObj_vtbl[];
extern u32 MainVt_0208c354_vtbl[];
extern u32 MainVt_0208c364_vtbl[];
extern u32 MainVt_0208c850_vtbl[];
extern u32 MainVt_0208c868_vtbl[];
extern u32 MainVt_0208c8bc_vtbl[];
extern void EffectObj_Register(EffectObj *obj);
extern void Effect3D_Init(Effect3D *e);
extern void EffectObj_AddSndCue(EffectObj *obj, s32 id, s32 frame);
extern void EffectEmitterSub_InitFuncs(EffectEmitterSub *sub);
extern void EffectEmitter_Reset(EffectEmitter *em);
extern void EffectEmitter_ResetParams(EffectEmitter *em);
extern void EffectPartSet_Init(EffectPartSet *parts);
extern void EffectPartSet_Reset(EffectPartSet *parts);
extern void EffectPartSet_DtorBase(EffectPartSet *parts);
extern BOOL EffectPartSet_AddSlot(EffectPartSet *parts, const u8 *data);
extern void EffectEmitterSub_DtorBase(EffectEmitterSub *sub);

void EffectSetup_LoadSndCues(EffectSetup *setup, EffectObj *obj, s32 id);
void EffectSetup_SetEmitterByName(EffectSetup *setup, EffectEmitter *em, const char *name);
void EffectSetup_SetupEmitter(EffectSetup *setup, EffectEmitter *em, s32 id);
void EffectSetup_AddPartSlots(EffectSetup *setup, EffectPartSet *parts, u8 *ids);

static inline void Effect_SetStr(char *dst, const char *src) {
    if (src == NULL) {
        dst[0] = 0;
    } else {
        STD_CopyString(dst, src);
    }
}

EffectObj *EffectSetup_NewObj(EffectSetup *setup, EffectDef *def) {
    EffectObj *ret = NULL;
    switch (def->type) {
    case 0: {
        Effect3D *e = (Effect3D *)Heap_Alloc(sizeof(Effect3D));
        if (e != NULL) {
            *(u32 **)e = EffectObj_vtbl;
            EffectObj_Register(e);
            *(u32 **)e = MainVt_0208c290_vtbl;
            Effect3D_Init(e);
        }
        ret = e;
        Effect_SetStr(e->arcName, def->arcName[0] != 0 ? def->arcName : NULL);
        Effect_SetStr(e->mdlName, def->mdlName);
        e->time = -def->delay;
        e->unk_28 = def->unk_38;
        e->loopCount = def->loopCount;
        EffectSetup_LoadSndCues(setup, e, def->cueId);
        break;
    }
    case 1: {
        EffectEmitter *em = (EffectEmitter *)Heap_Alloc(0x1d8);
        EffectPartSet *parts;
        if (em != NULL) {
            *(u32 **)em = EffectObj_vtbl;
            EffectObj_Register(em);
            *(u32 **)em = MainVt_0208c868_vtbl;
            *(u32 **)&em->sub = MainVt_0208c354_vtbl;
            EffectEmitterSub_InitFuncs(&em->sub);
            EffectEmitter_Reset(em);
            *(u32 **)em = MainVt_0208c8bc_vtbl;
            EffectEmitter_ResetParams(em);
        }
        ret = em;
        em->time = -def->delay;
        EffectSetup_LoadSndCues(setup, em, def->cueId);
        em->nameDef = def->arcName[0] != 0 ? def : NULL;
        em->def = def;
        em->unk_28 = def->unk_38;
        em->loopCount = def->loopCount;
        EffectSetup_SetEmitterByName(setup, em, def->emitName);
        EffectSetup_SetupEmitter(setup, em, def->paramId);
        parts = (EffectPartSet *)Heap_Alloc(0x12c);
        if (parts != NULL) {
            *(u32 **)parts = MainVt_0208c364_vtbl;
            EffectPartSet_Init(parts);
            *(u32 **)parts = MainVt_0208c850_vtbl;
            EffectPartSet_Reset(parts);
        }
        EffectSetup_AddPartSlots(setup, parts, def->partIds);
        em->parts = parts;
        break;
    }
    }
    return ret;
}

EffectEmitterSub *MainVt_0208c354_Dtor(EffectEmitterSub *sub) {
    *(u32 **)sub = MainVt_0208c354_vtbl;
    EffectEmitterSub_DtorBase(sub);
    return sub;
}

static inline void EffectEmitter_SetData(EffectEmitter *em, u8 *data, s32 count) {
    em->emitData = (EffectPtclCmd *)data;
    em->emitCount = count;
}

void EffectSetup_SetEmitterByName(EffectSetup *setup, EffectEmitter *em, const char *name) {
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

void EffectSetup_SetupEmitter(EffectSetup *setup, EffectEmitter *em, s32 id) {
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

void EffectSetup_AddPartSlots(EffectSetup *setup, EffectPartSet *parts, u8 *ids) {
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

void EffectSetup_LoadSndCues(EffectSetup *setup, EffectObj *obj, s32 id) {
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
    *(u32 **)parts = MainVt_0208c364_vtbl;
    EffectPartSet_DtorBase(parts);
    Heap_Free(parts);
    return parts;
}

BOOL MainVt_0208c364_Step(EffectPartSet *parts) {
    return TRUE;
}

void MainVt_0208c364_Draw(EffectPartSet *parts) {
}

EffectPartSet *MainVt_0208c364_Dtor(EffectPartSet *parts) {
    *(u32 **)parts = MainVt_0208c364_vtbl;
    EffectPartSet_DtorBase(parts);
    return parts;
}

EffectEmitterSub *MainVt_0208c354_DtorDelete(EffectEmitterSub *sub) {
    *(u32 **)sub = MainVt_0208c354_vtbl;
    EffectEmitterSub_DtorBase(sub);
    Heap_Free(sub);
    return sub;
}

}
