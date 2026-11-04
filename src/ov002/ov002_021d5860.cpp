#include "ov002/ov002.h"

extern "C" {

VObj *Ov002Vt_021efca4_DtorDelete(VObj *self) {
    *(VFunc **)self = UiList_vtbl;
    self->vfunc_2c();
    *(VFunc **)self = UiObj_vtbl;
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

void RobotTypeMenu_Load(void) {
}

BOOL RobotTypeMenu_IsLoaded(void) {
    return TRUE;
}

}

extern "C" {
extern VFunc Lo021cadcc_vtbl[];
extern VFunc Ov002Vt_021efca4_vtbl[];
extern char data_ov002_021efaf1[];
extern u8 data_ov002_021eef54[];
void *ResMgr_FindArcType2(void *a, void *b);
void UiList_SetMarkModel(void *a, void *b, const char *c, int d);
void *ModelViewer_Ctor(void *p);
void ModelViewer_InitCamera(void *p);
void StageFlags_SumPartStats(void *p);
BOOL RobotTypeMenu_List50OnDecide(UiList *self, UiListItem *ev);
BOOL RobotTypeMenu_List50OnCursor(UiList *self, UiListItem *ev);
void RobotTypeMenu_OamDraw(void *self, s32 x, s32 y, s32 z, s32 unused, void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs);

static inline UiListItem *ov002_021d58b8_sel(UiList *g) {
    UiListItem *p = g->topItem;
    if (p == NULL) {
        p = NULL;
    } else {
        s32 n = g->cursor;
        while (n-- != 0) {
            p = p->next;
        }
    }
    return p;
}

static inline void ov002_021d58b8_setName(Task021efc24 *self, u16 id) {
    if (self->unk_54 != NULL) {
        Obj0215bb14_SetText(self->unk_54, Param_GetDesc(id));
        self->unk_54->vfunc_70();
    }
}

static inline void ov002_021d58b8_setInfo(Task021efc24 *self, u16 id) {
    if (self->unk_58 != NULL) {
        Param0206ef10 *info = Param_GetRecord(id);
        ModelViewer_SetModel(self->unk_58, info->def.name[0], info->def.name[1], data_ov002_021efae1,
                            info->def.unk_1c, data_ov002_021efaeb, info->def.unk_18, 0x1000);
    }
}

static inline void ov002_021d58b8_setId(Ov002Hud *x, u16 id) {
    if (x != NULL) {
        Ov002Hud_SetInfo(x, id);
    }
}

void RobotTypeMenu_Start(Task021efc24 *self) {
    void *res;
    void *m;
    UiObj *o;
    void *g = gMsgRes;
    u8 *base;
    void *tbl;
    u16 i;
    u16 id;
    u32 count;
    UiListItem *e;
    self->unk_74 = gStageFlags->bits18.unk_3 + 0x8000;
    res = ResMgr_FindArcType2(data_ov002_021efaf1, ResName_CommonModel2);
    m = Heap_Alloc(0x160);
    if (m != NULL) {
        PlttRes_Init_02041218((PlttRes *)((u8 *)m + 0x88));
        TexObj_Init((Model *)m, NULL, 0);
    }
    self->unk_3c = (Model *)m;
    TexObj_SetRes((Model *)m, res);
    self->unk_3c->flags |= 2;
    TexObj_SelectImage((Model *)self->unk_3c, 0, 0);
    self->unk_3c->unk_150 = -0x1fe66;
    self->unk_3c->unk_158 = (void *)RobotTypeMenu_OamDraw;
    TexObj_SetOamFuncArg((Model *)self->unk_3c, 0, (u8 *)self + 0x40);
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = UiObj_vtbl;
        o->vfunc_28();
        *(VFunc **)o = Lo021cadcc_vtbl;
        o->vfunc_28();
    }
    self->unk_4c = (Lo021cadcc *)o;
    o->rows = 1;
    {
        Lo021cadcc *s = self->unk_4c;
        s->posX = 0;
        s->posY = 0x12;
        s->posZ = -0x199a;
    }
    self->unk_4c->width = 0x5a;
    self->unk_4c->posZ = -0x199a;
    {
        Lo021cadcc *s = self->unk_4c;
        s->slideX = -0xff;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_4c->slideMode = 1;
    {
        Lo021cadcc *s = self->unk_4c;
        s->shape = (VecFx16 *)data_ov002_021eef54;
        s->shapeCount = 5;
    }
    self->unk_4c->flags |= 0x80000;
    self->unk_4c->vfunc_08();
    Obj0215bb14_SetText(self->unk_4c, Param_Get(self->unk_74));
    self->unk_4c->vfunc_70();
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = UiObj_vtbl;
        o->vfunc_28();
        *(VFunc **)o = UiList_vtbl;
        o->vfunc_28();
        *(VFunc **)o = Ov002Vt_021efca4_vtbl;
    }
    self->unk_50 = (UiList *)o;
    self->unk_50->vfunc_10(MsgRes_GetString(g, 0xbe));
    self->unk_50->vfunc_14(MsgRes_GetString(g, 0xbf));
    self->unk_50->rows = 2;
    self->unk_50->width = 0x74;
    {
        UiList *s = self->unk_50;
        s->posX = 0;
        s->posY = 0x30;
        s->posZ = -0x199a;
    }
    self->unk_50->posZ = -0x199a;
    {
        UiList *s = self->unk_50;
        s->slideX = -0xff;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    UiList_SetMarkModel(self->unk_50, gCommonTextPath, ResName_TextCells, 0xb);
    self->unk_50->flags &= ~0x400000;
    self->unk_50->flags &= ~0x80000;
    self->unk_50->flags |= 0x40000;
    self->unk_50->flags &= ~0x800000;
    self->unk_50->flags |= 0x10000;
    self->unk_50->vfunc_08();
    base = gDataRes->data;
    tbl = DataRes_GetTable(gDataRes, 12);
    count = DataRes_GetCount(gDataRes, 12);
    for (i = 0; i < count; i++) {
        if (DataRes_ReadBitsAt_02059544(gDataRes, base + 0x190, tbl, 1, i)) {
            id = i + 0x8000;
            e = (UiListItem *)self->unk_50->vfunc_74(Param_Get(id), id, 0xffff, 0xffff);
            if (self->unk_74 == id) {
                e->unk_24 = 4;
            }
        }
    }
    self->unk_50->onDecide = RobotTypeMenu_List50OnDecide;
    self->unk_50->onCursor = RobotTypeMenu_List50OnCursor;
    self->unk_50->owner = self;
    {
        VObj *mm = self->unk_50;
        mm->vfunc_a8(UiList_GetItemById(mm, self->unk_74));
    }
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = UiObj_vtbl;
        o->vfunc_28();
        *(VFunc **)o = Lo021cadcc_vtbl;
        o->vfunc_28();
    }
    self->unk_54 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_54->rows = 3;
    {
        Lo021cadcc *s = self->unk_54;
        s->posX = 4;
        s->posY = 0x87;
        s->posZ = -0x199a;
    }
    {
        Lo021cadcc *s = self->unk_54;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_54->slideMode = 1;
    self->unk_54->vfunc_08();
    {
        UiListItem *p = NULL;
        UiListItem *it = self->unk_50->topItem;
        if (it != NULL) {
            s32 n = self->unk_50->cursor;
            while (n-- != 0) {
                it = it->next;
            }
            p = it;
        }
        if (p != NULL) {
            ov002_021d58b8_setName(self, p->id);
        }
    }
    {
        void *q = Heap_Alloc(0x708);
        if (q != NULL) {
            q = ModelViewer_Ctor(q);
        }
        self->unk_58 = (VObj *)q;
        ModelViewer_InitCamera(q);
    }
    {
        UiListItem *p = ov002_021d58b8_sel(self->unk_50);
        if (p != NULL) {
            ov002_021d58b8_setInfo(self, p->id);
        }
    }
    {
        Task021efba4 *t = (Task021efba4 *)Task_FindById(0x1b);
        if (t != NULL) {
            if (t->hud != NULL) {
                Ov002Hud_SetRow(t->hud, 9, 0);
            }
            StageFlags_SumPartStats((u8 *)self + 0x60);
            if (t->hud != NULL) {
                MI_CpuCopy8((u8 *)self + 0x60, t->hud->unk_2c, 0x14);
            }
            ov002_021d58b8_setId(t->hud, self->unk_74);
        }
    }
    if (func_ov002_isMode4()) {
        GfxSys_StartFadeIn(0x14000, 0, -1);
    }
    TaskList_Insert(self);
}
}
