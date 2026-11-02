#include "Main/Effect/Effect.h"

extern "C" {

extern u32 data_0208c2e4[];
extern u32 data_0208c354[];
extern u32 data_0208c364[];
extern u32 data_0208c840[];
extern u32 data_0208c868[];
extern void func_02063bd0(EffectObj *obj);
extern void func_0206adbc(EffectEmitter *em);
extern void func_0206ab0c(EffectPartSet *s);

static inline void EffectEmitter_Dtor(EffectEmitter *em) {
    *(u32 **)em = data_0208c868;
    func_0206adbc(em);
    *(u32 **)&em->sub = data_0208c354;
    *(u32 **)em = data_0208c2e4;
    func_02063bd0(em);
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
    *(u32 **)s = data_0208c364;
    Heap_Free(s);
    return s;
}

void func_0206c420(EffectPartSet *s) {
    func_0206ab0c(s);
}

EffectPartSet *MainVt_0208c850_Dtor(EffectPartSet *s) {
    *(u32 **)s = data_0208c364;
    return s;
}

EffectPtcl *MainVt_0208c840_Dtor(EffectPtcl *p) {
    *(u32 **)p = data_0208c840;
    return p;
}

}
