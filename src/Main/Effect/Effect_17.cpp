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

EffectEmitter *func_0206c2dc(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    func_0203de1c(em);
    return em;
}

void func_0206c324(EffectEmitter *em) {
    em->Loop();
}

EffectEmitter *func_0206c338(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    return em;
}

EffectEmitter *func_0206c378(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    func_0203de1c(em);
    return em;
}

EffectEmitter *func_0206c3c0(EffectEmitter *em) {
    EffectEmitter_Dtor(em);
    return em;
}

EffectPartSet *func_0206c400(EffectPartSet *s) {
    *(u32 **)s = data_0208c364;
    func_0203de1c(s);
    return s;
}

void func_0206c420(EffectPartSet *s) {
    func_0206ab0c(s);
}

EffectPartSet *func_0206c42c(EffectPartSet *s) {
    *(u32 **)s = data_0208c364;
    return s;
}

EffectPtcl *func_0206c43c(EffectPtcl *p) {
    *(u32 **)p = data_0208c840;
    return p;
}

}
