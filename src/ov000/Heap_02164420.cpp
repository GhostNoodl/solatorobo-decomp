#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MapCtx.h"

extern "C" {

extern char data_ov000_021cb8e0[];
void LangData_LocalizePath(char *dst, const char *src);
void Lo021cb6b0_FreeSlots(Lo021cb6b0 *self);

void func_ov000_02164420(Lo021cb6b0 *self) {
    Ctx0216607c *s = self->unk_30;
    if (s != NULL && s->anim != NULL) {
        Heap_FreeHi(s->anim);
        s->anim = NULL;
    }
    Lo021cb6b0_FreeSlots(self);
    if (self->unk_20 >= 1) {
        char buf[0x20];
        LangData_LocalizePath(buf, data_ov000_021cb8e0);
        ResMgr_ReleaseByName(gResMgr, buf, 7, 0);
    }
    HEAP_DELETE_VOBJ(self->unk_40);
    HEAP_DELETE_MODEL(self->unk_24);
    HEAP_DELETE_MODEL(self->unk_28);
    HEAP_DELETE_MODEL(self->unk_2c);
}

}
