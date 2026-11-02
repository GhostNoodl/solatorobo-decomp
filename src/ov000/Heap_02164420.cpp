#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MapCtx.h"

extern "C" {

extern char data_ov000_021cb8e0[];
void func_0206e900(char *dst, const char *src);
void func_ov000_021658e8(Lo021cb6b0 *self);

void func_ov000_02164420(Lo021cb6b0 *self) {
    Ctx0216607c *s = self->unk_30;
    if (s != NULL && s->anim != NULL) {
        Heap_FreeHi(s->anim);
        s->anim = NULL;
    }
    func_ov000_021658e8(self);
    if (self->unk_20 >= 1) {
        char buf[0x20];
        func_0206e900(buf, data_ov000_021cb8e0);
        func_02036838(data_02097cdc, buf, 7, 0);
    }
    HEAP_DELETE_VOBJ(self->unk_40);
    HEAP_DELETE_MODEL(self->unk_24);
    HEAP_DELETE_MODEL(self->unk_28);
    HEAP_DELETE_MODEL(self->unk_2c);
}

}
