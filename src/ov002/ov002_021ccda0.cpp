#include "ov002/ov002.h"

extern "C" {

void Ov002Session_Create(void) {
    Ov002Session *p;
    if (gOv002Session != NULL) {
        return;
    }
    p = (Ov002Session *)Heap_Alloc(sizeof(Ov002Session));
    if (p != NULL) {
        p->unk_00 = 0;
        p->state = 0;
        p->unk_08 = -1;
    }
    gOv002Session = p;
}

void Ov002Session_Delete(void) {
    void *saved;
    Ov002Session *p;
    if (gOv002Session == NULL) {
        return;
    }
    HEAP_PUSH(saved);
    p = gOv002Session;
    if (p != NULL) {
        if (p != NULL) {
            if (p->state >= 1) {
                ResMgr_ReleaseByName(gResMgr, data_0208cca0, 7, 0);
                ResMgr_ReleaseByName(gResMgr, data_0208cc94, 7, 0);
                ResMgr_ReleaseByName(gResMgr, data_0214b105, 7, 0);
            }
            Heap_Free(p);
        }
        gOv002Session = NULL;
    }
    HEAP_POP(saved);
}

void Ov002Session_Update(Ov002Session *self) {
    switch (self->state) {
    case 0:
        if (DataRes_ReadEntry(gDataRes, 5, 1, 0) == 1) {
            gStageFlags->bits18.flag8 = 0;
            gStageFlags->bits18.flag9 = 0;
        }
        ResMgr_Load(data_0208cca0, 7, 0);
        ResMgr_Load(data_0208cc94, 7, 0);
        ResMgr_Load(data_0214b105, 7, 0);
        self->state = 1;
    case 1:
        ResMgr_IsLoaded(data_0208cca0, 7);
        ResMgr_IsLoaded(data_0208cc94, 7);
        if (ResMgr_IsLoaded(data_0214b105, 7) == 0) {
            return;
        }
        self->state = 2;
    case 2:
        TaskHost_Create(0x10, 0);
        {
            BitByte *b = (BitByte *)(gGfxSys->unk_8b0);
            b->b4 = 0;
            b->b5 = 1;
        }
        *(vu16 *)0x4000060 &= 0xcfdf;
        self->state = 3;
        return;
    case 3:
        BOOL r = func_ov002_inline_flag1();
        if (r) {
            TaskHost_Destroy();
            GfxSys_StartFadeOut(0x1e000, 2, -1);
            self->done = 1;
            self->state = 4;
        }
        return;
    }
}

void Ov002Session_Draw(Ov002Session *self) {
}

Task021ef530 *Task021ef530_New(void) {
    Task021ef530 *p = (Task021ef530 *)Heap_Alloc(sizeof(Task021ef530));
    if (p != NULL) {
        Task_021cd06c_ctor(p);
    }
    p->vfunc_08(0x10, 0);
    return p;
}

void Task021ef530_Load(Task021ef530 *self) {
    ResMgr_LoadArchive(data_ov002_021ef3e4, data_ov002_021ef3ec, 2, 0);
    self->unk_4d = 1;
}

int Task021ef530_IsLoaded(void) {
    return ResMgr_IsArchiveLoaded(data_ov002_021ef3e4, data_ov002_021ef3ec, 2);
}

}

extern "C" {
extern VFunc Lo021cadcc_vtbl[];
extern VFunc TimedBuffer021cb920_vtbl[];
void SndQueue_Push_0204aab0(SndQueue *queue, u16 value);
void UiList_SetMarkModel(void *a, void *b, const char *c, int d);
BOOL func_020624d8(void);
BOOL func_ov000_02188dfc(void);
void Buffer0216f144_Init(void *p);
void func_ov000_0216f828(void *p);
void *MessageQueue_AddBuffer_0216f398(void *a, void *b, s32 c, void *d);

void Task021ef530_Start(Task021ef530 *self) {
    void *g;
    void *res;
    Model *m;
    UiObj *o;
    {
        SndQueue *mm = gSndQueue.queue;
        if (mm->flag0) {
            if (mm->unk_06 != 0xffff || mm->unk_04 != 13) {
                if (mm->unk_02 != 10 && mm->unk_02 != 0) {
                    if (mm->unk_06 != 0xffff) {
                        SndQueue_Push_0204aab0(mm, mm->unk_06);
                    }
                    mm->unk_02 = 1;
                } else {
                    mm->unk_02 = 0;
                }
                mm->unk_06 = 13;
                mm->unk_08 = 10;
            }
        }
    }
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    g = gMsgRes;
    res = ResList_FindType2(ResMgr_GetArchiveList(data_ov002_021ef3e4, data_ov002_021ef3ec, 2), data_ov002_021ef3ec);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, NULL, 0);
    }
    self->unk_3c = m;
    TexObj_SetRes(m, res);
    self->unk_3c->flags |= 2;
    TexObj_SelectImage(self->unk_3c, 0, 0);
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = UiObj_vtbl;
        o->vfunc_28();
        *(VFunc **)o = UiList_vtbl;
        o->vfunc_28();
    }
    self->unk_40 = (UiList *)o;
    self->unk_40->vfunc_10(MsgRes_GetString(g, 0xd7));
    self->unk_40->vfunc_14(MsgRes_GetString(g, 0xd8));
    self->unk_40->width = 0x92;
    self->unk_40->rows = 6;
    {
        UiList *s = self->unk_40;
        s->posX = 0;
        s->posY = 0x1e;
        s->posZ = -0x1ccd;
    }
    {
        UiList *s = self->unk_40;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x1ccd;
    }
    self->unk_40->slideMode = 1;
    self->unk_40->flags &= ~0x400000;
    self->unk_40->flags &= ~0x800000;
    self->unk_40->flags &= ~0x20000;
    self->unk_40->flags &= ~0x80000;
    self->unk_40->flags &= ~0x40000;
    self->unk_40->flags &= ~0x10000;
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0x96), 0, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xba), 1, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xc2), 2, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0x4f), 3, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xd9), 4, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xdd), 5, 0xffff, 0xffff);
    self->unk_4c = gOv002Session->unk_08;
    gOv002Session->unk_08 = -1;
    if (self->unk_4c == -1) {
        self->unk_4c = 0;
    }
    {
        VObj *mm = self->unk_40;
        mm->vfunc_a8(UiList_GetItemById(mm, self->unk_4c));
    }
    UiList_SetMarkModel(self->unk_40, data_0214b105, data_0208cb7c, 0xb);
    self->unk_40->vfunc_08();
    self->unk_40->flags &= ~0x10;
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = UiObj_vtbl;
        o->vfunc_28();
        *(VFunc **)o = Lo021cadcc_vtbl;
        o->vfunc_28();
    }
    self->unk_44 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_44->rows = 2;
    {
        Lo021cadcc *s = self->unk_44;
        s->posX = 4;
        s->posY = 0x95;
        s->posZ = -0x199a;
    }
    {
        Lo021cadcc *s = self->unk_44;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_44->slideMode = 1;
    self->unk_44->vfunc_08();
    self->unk_48_1 = !func_020624d8();
    self->unk_48_0 = func_ov000_02188dfc() != 0;
    if (DataRes_ReadEntry(gDataRes, 5, 1, 0) == 0) {
        self->unk_48_2 = 1;
    }
    if (self->unk_48_0) {
        UiList_GetItemById(self->unk_40, 0)->unk_24 = 0xe;
    }
    if (self->unk_48_2) {
        UiList_GetItemById(self->unk_40, 1)->unk_24 = 0xe;
    }
    if (self->unk_48_1) {
        UiList_GetItemById(self->unk_40, 5)->unk_24 = 0xe;
    }
    self->vfunc_78(self->unk_4c);
    {
        FieldPlayer *t = gMessageQueue;
        if (t != NULL) {
            if (t->unk_118 == NULL) {
                TimedBuffer021cb920 *task = (TimedBuffer021cb920 *)Heap_Alloc(sizeof(TimedBuffer021cb920));
                if (task != NULL) {
                    *(VFunc **)task = Ov002Vt_021ef410_vtbl;
                    Buffer0216f144_Init(task);
                    *(VFunc **)task = TimedBuffer021cb920_vtbl;
                    func_ov000_0216f828(task);
                }
                t->unk_118 = task;
                MessageQueue_AddBuffer_0216f398(t, task, 0x10000, t);
                t->unk_118->flags |= 0x10;
            }
            if (gMessageQueue->unk_118 != NULL) {
                func_ov000_0216f844(gMessageQueue->unk_118, 1);
            }
        }
    }
    if (func_ov002_isMode4()) {
        GfxSys_StartFadeIn(self->fadeLen, 0, 0);
    }
    TaskList_Insert(self);
}
}
