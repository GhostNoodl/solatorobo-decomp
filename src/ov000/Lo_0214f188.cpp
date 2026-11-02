#include "ov000/LoCommon.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {
extern u8 data_0208ba70[];
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
u32 *Lang_GetGroup(u8 id);

struct Obj0214f188 : public VObj {
    u8 unk_04[0x44];
    TextWin *unk_48;
};

void func_ov000_0214f188(Obj0214f188 *self, s32 idx) {
    u32 *info;
    u32 val;
    TextWin *p;

    if (idx == -1) {
        LO_FREE_V(self, 0x48);
        return;
    }
    info = Lang_GetGroup(idx);
    if (self->unk_48 != NULL && idx + 1 == self->unk_48->code) {
        return;
    }
    if (self->unk_48 != NULL) {
        LO_FREE_V(self, 0x48);
    }
    val = info[0];
    p = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        TextWin_Init(p);
    }
    p->font = 8;
    p->str = val;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = ((s32)p->font);
    p->unk_2c = 0;
    p->color0 = 0x77df;
    p->color1 = 0x67e;
    p->flags |= 0x40;
    p->flags |= 0x1400000;
    ((VObj *)p)->vfunc_14();
    p->unk_78 = 0x9000;
    p->posZ = -0x1ccd;
    p->flags |= 0x40000004;
    self->unk_48 = p;
    p->code = idx + 1;
}
}
