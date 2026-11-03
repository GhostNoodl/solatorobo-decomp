#include "ov000/LoCommon.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Res/StageFlags.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Task.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/SceneRes.h"

typedef struct {
    u8 unk_00[0x68];
    u16 unk_68;
    u8 unk_6a[0x6];
    u16 unk_70;
    u8 unk_72[0x8];
    u16 unk_7a;
} Shared02fe1534;

extern "C" {
extern void *gMsgRes;
extern Shared02fe1534 data_02fe1534;
extern void *gDataRes;
extern const char *data_ov000_021ca8d8[];
extern u8 TextWin_vtbl[];
extern const char *data_0208cca0;
extern const char *data_0208cb74;
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 Lo021cb5a8_vtbl[];
extern u8 Menu021ca94c_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 Lo021caac8_vtbl[];
void *MsgRes_GetString(void *g, u32 id);
BOOL StageRes_Bind(void *p);
void *ResList_FindType2(void *a, void *b);
void TexObj_SetOamFuncArg(void *model, s32 a, void *b);
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void UiList021cb4a8_SetLabel(UiList021cb4a8 *self, void *a);
void UiList_SetIconModel(void *a, const char *b, const char *c, u16 d);
void *Task_FindById(s32 kind);
u32 DataRes_GetCount(void *a, s32 b);
u16 func_ov000_0214bcc4(u16 id, u16 index);
s32 func_02061e7c(u16 a);
void func_ov000_0214fcfc(void *self, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, const void *mtx);
BOOL func_ov000_0214ffac(void *self, void *msg);
BOOL func_ov000_02150104(void *self, void *p);

static inline void Setup0214e9e4(Lo021caa44 *self) {
    VObj *t;
    void *g;
    u32 n;
    u16 k;
    const char *name;
    TextWin *p;
    const char *arc;
    Model *m;
    VObj *o;
    void *s;
    u16 i;
    u16 id;
    g = gMsgRes;
    if (!gSceneResSet.unk_08->vfunc_34()) {
        StageRes_Bind(gSceneResSet.unk_08);
    }
    {
        u16 v = gStageFlags->unk_639;
        data_02fe1534.unk_70 = 1;
        data_02fe1534.unk_7a = v;
        gSceneResSet.unk_08->vfunc_38(1);
        data_02fe1534.unk_7a = 0;
    }
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        name = data_ov000_021ca8d8[1];
        arc = data_ov000_021ca8d8[0];
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, name, 0);
        STD_CopyString(m->name, arc);
    }
    self->unk_40 = m;
    TexObj_SetRes(self->unk_40, ResList_FindType2((void *)self->unk_3c->vfunc_10(), (u8 *)self->unk_40 + 0x4c));
    self->unk_40->flags |= 2;
    TexObj_SelectImage(self->unk_40, 0, 1);
    self->unk_40->unk_158 = (void *)func_ov000_0214fcfc;
    TexObj_SetOamFuncArg(self->unk_40, 1, self);
    self->unk_40->flags |= 0x80000;
    self->unk_40->flags |= 0x200000;
    self->unk_40->unk_150 = -0x1ccd;
    s = MsgRes_GetString(g, 0x114);
    p = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, TextWin_vtbl);
        TextWin_Init(p);
    }
    p->font = 8;
    p->str = (u32)s;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    gGfxMgr->unk_004 = ((s32)p->font);
    p->unk_2c = 0;
    p->color0 = 0x77df;
    p->color1 = 0x67e;
    p->flags |= 0x40;
    p->flags |= 0x1400000;
    ((VObj *)p)->vfunc_14();
    p->unk_78 = 0x9000;
    p->posZ = -0x1ccd;
    p->flags |= 0x40000004;
    self->unk_44 = p;
    o = (VObj *)Heap_Alloc(0xe0);
    if (o != NULL) {
        *(void **)o = UiObj_vtbl;
        o->vfunc_28();
        *(void **)o = UiList_vtbl;
        o->vfunc_28();
        *(void **)o = Lo021cb5a8_vtbl;
        o->vfunc_28();
    }
    self->unk_4c = (Lo021cb5a8 *)o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    self->unk_4c->slideMode = 1;
    {
        UiList *t = (UiList *)self->unk_4c;
        t->slideX = 0x100;
        t->slideY = 0;
        t->slideZ = 0;
    }
    self->unk_4c->openLen = 0xc000;
    {
        UiList *t = (UiList *)self->unk_4c;
        t->posX = 0;
        t->posY = 0x66;
        t->posZ = -0x1ccd;
    }
    self->unk_4c->flags |= 0x20000000;
    self->unk_4c->vfunc_f4(1, MsgRes_GetString(g, 0x37));
    self->unk_4c->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_4c->vfunc_08();
    o = (VObj *)Heap_Alloc(0x21c);
    if (o != NULL) {
        *(void **)o = UiObj_vtbl;
        o->vfunc_28();
        *(void **)o = Menu021ca94c_vtbl;
        VOBJ_SET_VTABLE((u8 *)o + 0x90, TextWin_vtbl);
        TextWin_Init((u8 *)o + 0x90);
        VOBJ_SET_VTABLE((u8 *)o + 0x148, TextWin_vtbl);
        TextWin_Init((u8 *)o + 0x148);
        o->vfunc_28();
    }
    self->unk_60 = (Menu021ca94c *)o;
    o->vfunc_08();
    self->unk_60->posZ = -0x1bcd;
    o = (VObj *)Heap_Alloc(0xe4);
    if (o != NULL) {
        *(void **)o = UiObj_vtbl;
        o->vfunc_28();
        *(void **)o = UiList_vtbl;
        o->vfunc_28();
        *(void **)o = UiList021cb4a8_vtbl;
        o->vfunc_28();
        *(void **)o = Lo021caac8_vtbl;
        o->vfunc_28();
    }
    self->unk_50 = (Lo021caac8 *)o;
    ((VObj *)self->unk_50)->vfunc_10(MsgRes_GetString(g, 0x10f));
    ((VObj *)self->unk_50)->vfunc_14(MsgRes_GetString(g, 0x110));
    UiList021cb4a8_SetLabel(self->unk_50, MsgRes_GetString(g, 0x111));
    UiList_SetIconModel(self->unk_50, data_0208cca0, data_0208cb74, 0xb);
    self->unk_50->owner = self;
    self->unk_50->rows = 4;
    {
        UiList *t = (UiList *)self->unk_50;
        t->posX = 0;
        t->posY = 0x18;
        t->posZ = -0x1ccd;
    }
    self->unk_50->unk_c0 = 0x94;
    self->unk_50->openLen = 0xc000;
    self->unk_50->flags |= 0x400000;
    self->unk_50->unk_c1 = 2;
    LFLD(void *, self->unk_50, 0x84) = (void *)func_ov000_0214ffac;
    LFLD(void *, self->unk_50, 0x88) = (void *)func_ov000_02150104;
    id = self->param;
    data_02fe1534.unk_70 = 0;
    data_02fe1534.unk_7a = id;
    gSceneResSet.unk_08->vfunc_38(1);
    data_02fe1534.unk_7a = 0;
    n = DataRes_GetCount(gDataRes, 1);
    for (i = 0; i < n; i++) {
        k = func_ov000_0214bcc4(id, i);
        if (k != 0xffff) {
            t = LFLD(VObj *, Task_FindById(0xe), 0x50);
            t->vfunc_74(func_02061e7c(k), k, 0xffff, 0xffff);
        }
    }
    self->unk_64 = data_02fe1534.unk_68;
    ((VObj *)self->unk_50)->vfunc_a8(LFLD(s32, self->unk_50, 0x98));
    ((VObj *)self->unk_50)->vfunc_08();
    {
        UiList *t = (UiList *)self->unk_50;
        t->slideX = 0x100;
        t->slideY = 0;
        t->slideZ = 0;
    }
}

void Lo021caa44_Start(Lo021caa44 *self) {
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    TaskList_Insert(self);
    Setup0214e9e4(self);
}

}
