#include "Main/Effect/Effect.h"

extern "C" {

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

}
