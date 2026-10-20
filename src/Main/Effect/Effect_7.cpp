#include "Main/Effect/Effect.h"

extern "C" {

extern s32 STD_CompareNString(const void *a, const char *b, u32 n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern s32 _s32_div_f(s32 a, s32 b);
extern void func_02068600(EffectSetup *setup);
extern EffectObj *func_020687f8(EffectSetup *setup, EffectDef *def);
extern char data_0208c7fe[];
extern char data_0208c806[];
extern char data_0208c80e[];
extern char data_0208c816[];
extern char data_0208c81e[];
extern char data_0208c826[];
extern char data_0208c82e[];

void func_02068508(EffectSetup *setup, u8 *data, const EffectVec *pos) {
    setup->data = data;
    setup->pos = *pos;
    setup->objChunk = NULL;
    setup->chunk18 = NULL;
    setup->chunk1c = NULL;
    setup->chunk20 = NULL;
    setup->chunk24 = NULL;
}

void func_02068540(EffectSetup *setup) {
}

EffectObj *func_02068544(EffectSetup *setup) {
    EffectObj *prev = NULL;
    s32 count;
    s32 size;
    u8 *p;
    s32 i;
    EffectObj *o;
    func_02068600(setup);
    MI_CpuCopy8(setup->objChunk + 8, &count, 4);
    MI_CpuCopy8(setup->objChunk + 0xc, &size, 4);
    size /= count;
    p = setup->objChunk + 0x10;
    for (i = 0; i < count; i++) {
        o = func_020687f8(setup, (EffectDef *)p);
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
