#include "ov000/VObj.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MapCtx.h"

extern "C" {

void func_ov000_02165d78(Lo021cb6b0 *self) {
    Ctx0216607c *p = self->unk_30;
    if (p != NULL && p->anim != NULL) {
        Heap_FreeHi(p->anim);
        p->anim = NULL;
    }
}

}
