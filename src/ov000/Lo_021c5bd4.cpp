#include "ov000/LoCommon.h"
#include "Main/Gfx/FieldMsg.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *data_02149ef8;
extern void *data_0208cc88;
extern void *data_0208cc94;
void *MsgRes_GetString(void *a, s32 b);
void *ResMgr_GetArcList(void *a);
void *ResList_FindType2(void *a, void *b);
void TexObj_SetAllOamFuncs(void *model, void *fn);
void *func_ov000_021c5a0c(u8 *self, u16 *cmd, void *arr, u16 *count);

void func_ov000_021c5bd4(Lo021cca40 *self) {
    void *res;
    TextWin *p;
    u8 *m;
    if (self->built != 0) {
        return;
    }
    res = data_02149ef8;
    p = (TextWin *)Heap_Alloc(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        TextWin_Init(p);
    }
    self->text = p;
    p->font = 8;
    {
        void *t = self->unk_38;
        if (t == NULL) {
            t = MsgRes_GetString(res, 0x50);
        }
        p = self->text;
        p->str = (u32)t;
    }
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = p->font;
    self->text->unk_2c = 0;
    self->text->flags |= 0x40;
    self->text->flags |= 0x1000000;
    self->text->flags |= 0x400000;
    self->text->flags |= 0x4;
    m = (u8 *)Heap_Alloc(0x160);
    if (m != NULL) {
        void *arc;
        void *name;
        name = data_0208cc88;
        arc = data_0208cc94;
        PlttRes_Init_02041218((struct PlttRes *)(m + 0x88));
        TexObj_Init((Model *)m, (const char *)name, 0);
        STD_CopyString((char *)m + 0x2c, (const char *)arc);
    }
    self->unk_34 = (Model *)(m);
    TexObj_SetRes(self->unk_34, ResList_FindType2(ResMgr_GetArcList(m + 0x2c), (u8 *)self->unk_34 + 0x4c));
    self->unk_34->flags |= 2;
    TexObj_SelectImage(self->unk_34, 0, 6);
    TexObj_SelectImage(self->unk_34, 0, 7);
    TexObj_SetAllOamFuncs((u8 *)self->unk_34, (void *)func_ov000_021c5a0c);
    self->built = 1;
}

}

