#include "ov000/LoCommon.h"
#include "ov000/SceneCmd.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Task.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/SceneRes.h"
#include "ov000/MsgEntry.h"

extern "C" {

extern void *gDataRes;
extern void *gSndMgr;
void *DataRes_GetTable(void *a, s32 b);
u32 DataRes_GetCount(void *a, s32 b);
u32 Quest_GetOptFlags(u16 a);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL StageRes_IsAllLoaded(void *p);
void TextWin_Init(void *p);
void *Task_FindById(s32 kind);
Robo021ca458 *ActorMgr_FindPlayer(void);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(gSceneResSet.unk_08)) {
        r = FALSE;
    }
    return r;
}

BOOL QuestWin_IsLoaded(Lo021ca9c4 *self) {
    BOOL r = TRUE;
    if (self->unk_42 == 0xffff) {
        if (!LoIsLoaded24()) {
            r = FALSE;
        }
    }
    if (!self->unk_3c->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}


extern "C" {
extern void *gMsgRes;
extern const char *data_ov000_021ca8d8[];
extern const char *data_0208cca0;
extern const char *data_0208cb74;
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 Lo021cb5a8_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 Lo021caac8_vtbl[];
extern char data_ov000_021ca93e[];
void *MsgRes_GetString(void *g, u32 id);
BOOL StageRes_Bind(void *p);
void *ResList_FindType2(void *a, void *b);
void *ResMgr_GetArcList(void *a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void TextWin_RenderToVram(void *p);
s32 StageTbl_GetQuestName(u16 a);
void *MsgRes_GetLines(void *a, u16 id, void *out, s32 n);
void Text_ScanTags(void *a, void *b, void *c, void *fn);
void Str_FormatInt(char *buf, s32 n);
SceneScript *SceneStage_GetScript(SceneStage *self, u16 index);
s32 func_ov000_02151610(VObj *self, s32 a, s32 b, s32 c);
void func_ov000_0215158c(void *self);

static inline void LoTextInit(TextWin *t) {
    t->unk_4c = Text_Measure(t->font, t->spacing, t->str, &t->width, &t->height, (s8)t->unk_37 != 0);
    gGfxMgr->unk_004 = t->font;
}

void QuestWin_Start(Lo021ca9c4 *self) {
    Model *m;
    const char *arc;
    const char *name;
        VObj *o;
    void *g;
    MsgEntryEx *p;
    void *out[2];
    char buf[0x100];
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    TaskList_Insert(self);
    if (self->unk_42 == 0xffff) {
        if (!gSceneResSet.unk_08->vfunc_34()) {
            StageRes_Bind(gSceneResSet.unk_08);
        }
    }
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        arc = data_ov000_021ca8d8[0];
        name = data_ov000_021ca8d8[1];
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, name, 0);
        STD_CopyString(m->name, arc);
    }
    self->unk_44 = m;
    TexObj_SetRes(self->unk_44, ResList_FindType2((void *)self->unk_3c->vfunc_10(), (u8 *)self->unk_44 + 0x4c));
    self->unk_44->flags |= 2;
    TexObj_SelectImage(self->unk_44, 0, 0);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        arc = data_0208cca0;
        name = data_0208cb74;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, name, 0);
        STD_CopyString(m->name, arc);
    }
    self->unk_48 = m;
    TexObj_SetRes(self->unk_48, ResList_FindType2(ResMgr_GetArcList(m->name), self->unk_48->unk_04c));
    self->unk_48->flags |= 2;
    TexObj_SelectImage(self->unk_48, 0, 0xb);
    g = gMsgRes;
    if (self->unk_42 == 0xffff) {
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
        self->unk_4c->openLen = 0x6000;
        {
            UiList *t = (UiList *)self->unk_4c;
            t->posX = 0;
            t->posY = 0x11;
            t->posZ = -0x1ccd;
        }
        self->unk_4c->flags |= 0x20000000;
        self->unk_4c->flags |= 0x80000000;
        self->unk_4c->vfunc_f4(2, MsgRes_GetString(g, 0x33));
        self->unk_4c->vfunc_08();
    }
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
    if (self->unk_42 == 0xffff) {
        self->unk_50->vfunc_10(MsgRes_GetString(g, 0x112));
        self->unk_50->vfunc_14(MsgRes_GetString(g, 0x113));
    }
    self->unk_50->owner = self;
    self->unk_50->rows = 3;
    {
        UiList *t = (UiList *)self->unk_50;
        t->posX = 0;
        t->posY = 0;
        t->posZ = -0x199a;
    }
    self->unk_50->unk_dc = 0x20;
    self->unk_50->openLen = 0x6000;
    LFLD(void *, self->unk_50, 0x7c) = (void *)func_ov000_02151610;
    LFLD(void *, self->unk_50, 0x78) = (void *)func_ov000_0215158c;
    self->unk_50->vfunc_a8(LFLD(s32, self->unk_50, 0x98));
    self->unk_50->vfunc_08();
    {
        UiList *t = (UiList *)self->unk_50;
        t->posX = 0;
        t->posY = 0;
        t->posZ = -0x199a;
    }
    p = (MsgEntryEx *)Heap_Alloc(sizeof(MsgEntryEx));
    if (p != NULL) {
        MsgEntry_Init(p);
        p->vals[0] = 0;
        p->vals[1] = 0;
        p->vals[2] = 0;
        p->vals[3] = 0;
    }
    self->unk_54 = p;
    if (self->unk_42 != 0xffff) {
        p->id = self->unk_42;
    } else {
        self->unk_54->id = SceneStage_GetScript(&SceneCmd_Get()->stage, 0)->id;
    }
    {
        void *r = MsgRes_GetLines(gSceneResSet.unk_08->sub, self->unk_54->id, out, 2);
        Text_ScanTags(out[0], r, self->unk_54, (void *)func_ov000_0214dc20);
    }

    self->text[0].font = 8;
    self->text[0].str = StageTbl_GetQuestName(self->unk_54->id);
    LoTextInit(&self->text[0]);
    self->text[0].color0 = 0x7fff;
    self->text[0].color1 = 0x67f;
    self->text[0].unk_78 = 0x9000;
    self->text[0].flags |= 0x40;
    self->text[0].flags |= 0x1400000;
    self->text[0].flags |= 0x40000004;
    TextWin_RenderToVram(&self->text[0]);

    self->text[1].spacing = 3;
    self->text[1].font = 8;
    self->text[1].str = (u32)MsgRes_GetString(gSceneResSet.unk_08->sub, self->unk_54->id);
    LoTextInit(&self->text[1]);
    self->text[1].flags |= 0x40;
    self->text[1].flags |= 0x1000000;
    self->text[1].flags |= 0x40000004;
    TextWin_RenderToVram(&self->text[1]);

    self->text[2].font = 8;
    self->text[2].str = (u32)MsgRes_GetString(g, 0x115);
    LoTextInit(&self->text[2]);
    self->text[2].color0 = 0x7fff;
    self->text[2].color1 = 0x67f;
    self->text[2].unk_78 = 0x9000;
    self->text[2].flags |= 0x40;
    self->text[2].flags |= 0x1400000;
    self->text[2].flags |= 0x40000004;
    TextWin_RenderToVram(&self->text[2]);

    if (self->unk_54->vals[1] != 0) {
        Str_FormatInt(buf, self->unk_54->vals[1]);
        STD_ConcatenateString(buf, data_ov000_021ca93e);
        STD_ConcatenateString(buf, (const char *)MsgRes_GetString(g, 0x3e));
    } else {
        STD_CopyString(buf, (const char *)out[1]);
    }
    self->text[3].strPtr = buf;
    self->text[3].font = 8;
    LoTextInit(&self->text[3]);
    self->text[3].flags |= 0x40;
    self->text[3].flags |= 0x1000000;
    self->text[3].flags |= 0x4;
    TextWin_RenderToVram(&self->text[3]);

    self->text[4].font = 8;
    self->text[4].str = (u32)MsgRes_GetString(g, 0x116);
    LoTextInit(&self->text[4]);
    self->text[4].color0 = 0x7fff;
    self->text[4].color1 = 0x67f;
    self->text[4].unk_78 = 0x9000;
    self->text[4].flags |= 0x40;
    self->text[4].flags |= 0x1400000;
    self->text[4].flags |= 0x40000004;
    TextWin_RenderToVram(&self->text[4]);

    {
        u16 n = self->unk_54->vals[2];
        if (n == 0) {
            n = 1;
        }
        Str_FormatInt(buf, n);
    }
    self->text[5].font = 8;
    self->text[5].strPtr = buf;
    LoTextInit(&self->text[5]);
    self->text[5].flags |= 0x40;
    self->text[5].flags |= 0x1000000;
    self->text[5].flags |= 0x40000004;
    TextWin_RenderToVram(&self->text[5]);
}

}
