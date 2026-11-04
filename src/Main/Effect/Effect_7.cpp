#include "Main/Effect/EffectInt.h"

extern "C" {

extern void EffectSetup_FindChunks(EffectSetup *setup);
extern EffectObj *EffectSetup_NewObj(EffectSetup *setup, EffectDef *def);
extern char data_0208c7fe[];
extern char data_0208c806[];
extern char data_0208c80e[];
extern char data_0208c816[];
extern char data_0208c81e[];
extern char data_0208c826[];
extern char data_0208c82e[];

void EffectSetup_Init(EffectSetup *setup, u8 *data, const VecFx32 *pos) {
    setup->data = data;
    setup->pos = *pos;
    setup->objChunk = NULL;
    setup->chunk18 = NULL;
    setup->chunk1c = NULL;
    setup->chunk20 = NULL;
    setup->chunk24 = NULL;
}

void EffectSetup_DtorBase(EffectSetup *setup) {
}

EffectObj *EffectSetup_SpawnObjs(EffectSetup *setup) {
    EffectObj *prev = NULL;
    s32 count;
    s32 size;
    u8 *p;
    s32 i;
    EffectObj *o;
    EffectSetup_FindChunks(setup);
    MI_CpuCopy8(setup->objChunk + 8, &count, 4);
    MI_CpuCopy8(setup->objChunk + 0xc, &size, 4);
    size /= count;
    p = setup->objChunk + 0x10;
    for (i = 0; i < count; i++) {
        o = EffectSetup_NewObj(setup, (EffectDef *)p);
        o->SetPos(&setup->pos);
        if (prev != NULL) {
            prev->parent = o;
            o->child = prev;
            prev = o;
        } else {
            prev = o;
        }
        p += size;
    }
    return prev;
}

}
