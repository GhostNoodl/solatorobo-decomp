#include "Main/Gfx/Obj3D.h"

extern "C" {

extern int func_02043d48(void *obj);
extern s8 data_02149ef4;

void func_02051f3c(Obj3DLayer *layer, u32 v) {
    if (layer->cur == 0) {
        layer->prev = v;
    } else {
        layer->prev = layer->cur;
    }
    layer->cur = v;
}

void func_020520fc(Obj3DRender *render);

void func_02052160(Obj3DRender *render);

s32 func_020534c4(s32 x);

s32 func_020534d4(void);

}
