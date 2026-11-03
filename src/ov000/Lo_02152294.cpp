#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"
#include "ov000/ObjLayouts.h"
#include "nitro/std.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 c : 9;
    u32 d : 7;
    u32 f : 10;
    u32 rest : 22;
} LoGlyphEnt;

extern "C" {

extern void *gMsgRes;
void *MsgRes_GetString(void *a, s32 b);
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 Ov000Vt_021cb0b8_vtbl[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

void func_ov000_02152294(UiObj *self, u16 a, s32 b, UiItemFn c) {
    Lo021cb0b8 *p;
    void *res = gMsgRes;
    p = (Lo021cb0b8 *)Heap_Alloc(sizeof(Lo021cb0b8));
    if (p) {
        *(void **)p = UiObj_vtbl;
        p->vfunc_28();
        *(void **)p = UiList_vtbl;
        p->vfunc_28();
        *(void **)p = Ov000Vt_021cb1b0_vtbl;
        p->vfunc_28();
        *(void **)p = Ov000Vt_021cb0b8_vtbl;
        p->vfunc_28();
    }
    self->child = p;
    p->msgId = a;
    ((Lo021cb0b8 *)self->child)->text = (char *)MsgRes_GetString(res, b);
    ((Lo021cb0b8 *)self->child)->key = 0;
    ((Lo021cb0b8 *)self->child)->owner = self->owner;
    ((Lo021cb0b8 *)self->child)->onDecide = c;
    self->child->vfunc_08();
    ((Lo021cb0b8 *)self->child)->posZ = self->posZ + 0x200;
    self->busy = 1;
}

}
