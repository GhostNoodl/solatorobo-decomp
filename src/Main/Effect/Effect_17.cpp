#include "Main/Effect/EffectInt.h"

extern "C" {

extern u32 EffectObj_vtbl[];
extern u32 MainVt_0208c354_vtbl[];
extern u32 MainVt_0208c364_vtbl[];
extern u32 MainVt_0208c840_vtbl[];
extern u32 MainVt_0208c868_vtbl[];
extern void EffectObj_Unregister(EffectObj *obj);
extern void EffectEmitter_Release(EffectEmitter *em);
extern void EffectPartSet_DrawSlots(EffectPartSet *s);

static inline void EffectEmitter_Dtor(EffectEmitter *em) {
    *(u32 **)em = MainVt_0208c868_vtbl;
    EffectEmitter_Release(em);
    *(u32 **)&em->sub = MainVt_0208c354_vtbl;
    *(u32 **)em = EffectObj_vtbl;
    EffectObj_Unregister(em);
}

EffectEmitter *MainVt_0208c8bc_DtorDelete(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    Heap_Free(em);
    return em;
}

void MainVt_0208c8bc_Setup(EffectEmitter *em) {
    em->Loop();
}

EffectEmitter *MainVt_0208c8bc_Dtor(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    return em;
}

EffectEmitter *MainVt_0208c868_DtorDelete(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    Heap_Free(em);
    return em;
}

EffectEmitter *MainVt_0208c868_Dtor(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    return em;
}

EffectPartSet *MainVt_0208c850_DtorDelete(EffectPartSet *s) {
    *(u32 **)s = MainVt_0208c364_vtbl;
    Heap_Free(s);
    return s;
}

void MainVt_0208c850_Draw(EffectPartSet *s) {
    EffectPartSet_DrawSlots(s);
}

EffectPartSet *MainVt_0208c850_Dtor(EffectPartSet *s) {
    *(u32 **)s = MainVt_0208c364_vtbl;
    return s;
}

EffectPtcl *MainVt_0208c840_Dtor(EffectPtcl *p) {
    *(u32 **)p = MainVt_0208c840_vtbl;
    return p;
}

}
