#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"

typedef struct {
    char s[16];
} LoName16;

extern "C" {

extern const char *ResName_BattleCells;
extern const char *ArcPath_MenuBattle;
extern void *gMsgRes;
void *ResList_FindType2(void *a, void *b);
void *ResMgr_GetArcList(void *a);
void *ResMgr_GetArchiveList(void *a, void *b, s32 c);
void TexObj_SetAllOamFuncs(void *m, void *fn);
void TexObj_SetOamFuncArg(void *m, s32 a, void *b);
BOOL Obj02152e5c_LoadModel(UiObj *self);
void *Menu021ca94c_OamCallback(u8 *self, u16 *cmd, void *arr, u16 *count);
void Tbl_MakeFacePath(s32 a, LoName16 *out);
void Tbl_MakeFaceName(s32 a, LoName16 *out, s32 b, s32 c);
s32 Tbl_GetText(s32 a);
s32 MsgRes_GetString(void *p, s32 a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void TextWin_RenderToVram(void *win);


void Menu021ca94c_Setup(Menu021ca94c *self) {
    LoName16 a;
    LoName16 b;
    void *res;
    Model *m;
    void *fnt;

    self->flags |= 0x10;
    self->width = 0x8c;
    self->height = 0x2b;
    self->posX = 0;
    self->posY = 0xc0 - self->height;
    self->posZ = -0x1000;
    if (Obj02152e5c_LoadModel(self)) {
        TexObj_SelectImage(self->model, 0, 0xb);
        TexObj_SelectImage(self->model, 0, 0xc);
        TexObj_SelectImage(self->model, 0, 0xd);
        TexObj_SelectImage(self->model, 0, 0xe);
    }
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *arc;
        const char *name;
        name = ResName_BattleCells;
        arc = ArcPath_MenuBattle;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, name, 0);
        STD_CopyString(m->name, arc);
    }
    self->unk_88 = m;
    {
        void *x = ResMgr_GetArcList(self->unk_88->name);
        void *y = ResList_FindType2(x, self->unk_88->unk_04c);
        TexObj_SetRes(self->unk_88, y);
    }
    self->unk_88->flags |= 2;
    TexObj_SelectImage(self->unk_88, 0, 6);
    TexObj_SetAllOamFuncs(self->unk_88, (void *)Menu021ca94c_OamCallback);
    TexObj_SetOamFuncArg(self->unk_88, 6, self);

    Tbl_MakeFacePath(0x1000, &a);
    Tbl_MakeFaceName(0x1000, &b, 1, 2);
    res = ResList_FindType2(ResMgr_GetArchiveList(&a, &b, 2), &b);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, b.s, 0);
        STD_CopyString(m->name, a.s);
    }
    self->unk_84 = m;
    TexObj_SetRes(m, res);
    self->unk_84->flags |= 2;
    TexObj_SelectImage(self->unk_84, 0, 0xffff);
    self->unk_84->flags |= 0x80000;
    MODEL_FLAGS(self->unk_84)->alpha = 0x1e;
    self->unk_84->flags |= 0x100000;
    self->unk_84->flags |= 0x200000;
    self->unk_84->flags |= 0x20000;
    self->slideMode = 1;
    self->slideX = 0;
    self->slideY = self->height + 0x40;
    self->slideZ = 0;

    fnt = gMsgRes;
    self->unk_b8 = 8;
    self->unk_b4 = Tbl_GetText(0x1000);
    self->unk_dc = Text_Measure(self->unk_b8, self->unk_c8, self->unk_b4, (u8 *)self + 0xd4, (u8 *)self + 0xd8, self->unk_c7 != 0 ? 1 : 0);
    gGfxMgr->unk_004 = self->unk_b8;
    self->unk_104 = 0x7fff;
    self->unk_106 = 0x67f;
    self->unk_108 = 0x9000;
    self->unk_94 |= 0x40;
    self->unk_94 |= 0x1000000;
    self->unk_94 |= 0x40000004;
    TextWin_RenderToVram((u8 *)self + 0x90);

    self->unk_170 = 4;
    self->unk_16c = MsgRes_GetString(fnt, 0x117);
    self->unk_194 = Text_Measure(self->unk_170, self->unk_180, self->unk_16c, (u8 *)self + 0x18c, (u8 *)self + 0x190, self->unk_17f != 0);
    gGfxMgr->unk_004 = self->unk_170;
    self->unk_14c |= 0x40;
    self->unk_14c |= 0x1000000;
    self->unk_14c |= 0x40000004;
    TextWin_RenderToVram((u8 *)self + 0x148);
    self->busy = 1;
}

}
