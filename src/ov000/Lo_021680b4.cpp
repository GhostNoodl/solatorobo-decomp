#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {
extern char data_0214b105[];
extern const char *data_0208cb7c;
void Obj0215fdfc_SetEntry(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);
extern u8 data_ov000_021c9aec[];
extern u8 data_ov000_021c9af2[];

void func_ov000_021680b4(Lo021cb6f0 *self) {
    void *res = ResList_FindType2(ResMgr_GetArcList(data_0214b105), data_0208cb7c);
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *nm = data_0208cb7c;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, nm, 0);
    }
    self->unk_9c = m;
    TexObj_SetRes(m, res);
    self->unk_9c->flags |= 2;
    self->unk_9c->flags |= 0x200000;
    self->unk_9c->flags |= 0x80000;
    TexObj_SelectImage(self->unk_9c, 0, 3);
    self->unk_30 = 0xc000;
    self->unk_50 = 0x44;
    self->unk_54 = 4;
    self->unk_28 = 0;
    self->unk_0c |= 0x240;
    self->unk_58 = 1;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = -0x2000;
    Obj0215fdfc_SetEntry(self, 1, data_ov000_021c9aec);
    Obj0215fdfc_SetEntry(self, 2, data_ov000_021c9af2);
}

}
