#include "ov002/ov002.h"


// The resource-name table (Ov002ResNames in ov002.h) read by ov002_021d2410.cpp .. ov002_021d36b8.cpp. The original TU also
// held those functions and the string pool at 0x021ef5c4; here the strings stay extern. Round dtD
// folded in 0x021d2410..0x021d36b8 (12 files, each in its own namespace). ov002_021d36b8.cpp
// stays outside: in this TU its cepct load is scheduled after the num stores (24 lines).
extern "C" {
extern const char data_ov002_021ef5cb[];
extern const char data_ov002_021ef5d2[];
extern const char data_ov002_021ef5e9[];
extern const char data_ov002_021ef626[];
extern const char data_ov002_021ef606[];
}

extern "C" Ov002ResNames data_ov002_021ef5ac;
Ov002ResNames data_ov002_021ef5ac = {
    data_ov002_021ef5cb, data_ov002_021ef5d2, data_ov002_021ef5e9, data_ov002_021ef626,
    FX_Div(256 * FX32_ONE, 15 * FX32_ONE), data_ov002_021ef606,
};

// ---- merged from ov002_021d2410.cpp
namespace m_021d2410 {
extern "C" {


u32 func_ov002_021e4c30(int which);

u32 Ov002LevelTable_GetLevel(Ov002LevelTable *self, s32 val);

void Obj0215c1bc_SetText(void *a, int b, void *c);

extern VFunc Lo021cad50_vtbl[];

extern void *data_ov002_021ef634[];

BOOL LibraryMenu_List3cOnDecide(UiObj *self, ListRow *ev) {
    Task021ef99c *owner = (Task021ef99c *)self->owner;
    if (ev != NULL) {
        u16 idx = ev->index;
        s32 n = Ov002LevelTable_GetLevel(&owner->unk_4c[idx], func_ov002_021e4c30(idx));
        if (n <= 0) {
            UiObj *p;
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            p = (UiObj *)Heap_Alloc(0xe8);
            if (p != NULL) {
                *(VFunc **)p = UiObj_vtbl;
                p->vfunc_28();
                *(VFunc **)p = Lo021cad50_vtbl;
                p->vfunc_28();
            }
            owner->unk_48 = p;
            Obj0215c1bc_SetText(owner->unk_48, 0x11, MsgRes_GetString(gMsgRes, 0xf6));
            owner->unk_48->flags &= ~0x10000;
            owner->unk_48->vfunc_08();
            owner->unk_48->vfunc_70();
        } else {
            Task021ef91c *w = (Task021ef91c *)TaskHost_RequestSwitch(gTaskHost, 0x19, 0);
            if (idx < 7) {
                int mode = LangData_GetLang();
                Ov002_MakeLangFileName(w->unk_44, 0x20, data_ov002_021ef5ac.param, data_ov002_021ef650, mode);
                Ov002_MakeLangFileName(w->unk_64, 0x18, data_ov002_021ef634[idx], data_ov002_021ef5ac.bmExt, mode);
                Ov002_MakeLangFileName(w->unk_7c, 0x18, data_ov002_021ef634[idx], data_ov002_021ef5ac.hdExt, mode);
                w->unk_bc = idx;
                w->unk_c0 = (u16)n;
                LibraryViewer_LoadPage(w, (u16)(idx * 3));
            }
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
        }
    }
    return TRUE;
}

}
}  // namespace m_021d2410

// ---- merged from ov002_021d25ec.cpp
namespace m_021d25ec {
extern "C" {


void LibraryMenu_FreeWindows(Task021ef99c *self) {
    void *saved;
    int i;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_44);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_48);
    HEAP_POP(saved);
    for (i = 0; i < 7; i++) {
        func_ov002_021e4904(&self->unk_4c[i]);
    }
    ResMgr_ReleaseByName(gResMgr, self->unk_f4, 7, 0);
}

void LibraryMenu_Load(Task021ef99c *self) {
    Ov002_MakeLangFileName(self->unk_f4, 0x20, data_ov002_021ef5ac.param, data_ov002_021ef650, LangData_GetLang());
    ResMgr_Load(self->unk_f4, 7, 0);
}

bool LibraryMenu_IsLoaded(Task021ef99c *self) {
    return ResMgr_IsLoaded(self->unk_f4, 7) != 0;
}

}
}  // namespace m_021d25ec

// ---- merged from ov002_021d278c.cpp
namespace m_021d278c {
extern "C" {


extern void *data_ov002_021ef634[];
extern VFunc Ov000Vt_021cc9f8_vtbl[];
extern VFunc Lo021cadcc_vtbl[];
extern VFunc Lo021cb5a8_vtbl[];
void *ResMgr_FindArcType0(void *a, void *b);
void Ov002LevelTable_Load(Ov002LevelTable *self, u8 *src);
u32 func_ov002_021e4c30(int which);
u32 Ov002LevelTable_GetLevel(Ov002LevelTable *self, s32 val);
void LoBase021ccb54_021ccbe0_CtorBase(Ov002RowList *self);
void ListRow_Init(ListRow *self);
void ListRowGauge_Init(ListRowGauge *self);
void ListRowGauge_SetText(ListRowGauge *self, void *a);
void LoBase021ccb54_021ccbe0_AppendRow(void *list, void *item);
BOOL LibraryMenu_List3cOnCursor(UiObj *self, ListRow *arg);
BOOL LibraryMenu_List3cOnDecide(UiObj *self, ListRow *ev);

static inline s32 ov002_Thresh(Ov002LevelTable *e, s32 idx) {
    s32 *arr = e->thresholds;
    if (arr == NULL) {
        return -1;
    }
    if ((u32)idx < e->count) {
        return arr[idx];
    }
    return -1;
}

void LibraryMenu_Start(Task021ef99c *self) {
    void *g;
    u16 i;
    u8 buf[0x18];
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    g = gMsgRes;
    for (i = 0; i < 7; i++) {
        Ov002_MakeLangFileName(buf, 0x18, data_ov002_021ef634[i], data_ov002_021ef5ac.hdExt, ((int (*)(void))LangData_GetLang)());
        Ov002LevelTable_Load(&self->unk_4c[i], *(u8 **)ResMgr_FindArcType0(self->unk_f4, buf));
    }
    {
        Ov002RowList *p = (Ov002RowList *)Heap_Alloc(sizeof(Ov002RowList));
        if (p != NULL) {
            *(VFunc **)p = UiObj_vtbl;
            p->vfunc_28();
            *(VFunc **)p = Ov000Vt_021ccbe0_vtbl;
            LoBase021ccb54_021ccbe0_CtorBase(p);
        }
        self->unk_3c = p;
        p->width = 0xdb;
    }
    self->unk_3c->rows = 7;
    {
        UiObj *s = self->unk_3c;
        s->posX = 0x12;
        s->posY = 0x14;
        s->posZ = -0x199a;
    }
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xe5));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xe7));
    self->unk_3c->flags &= ~0x40000;
    for (i = 0; i < 7; i++) {
        u32 val;
        u32 lvl;
        ListRowGauge *q;
        q = (ListRowGauge *)Heap_Alloc(sizeof(ListRowGauge));
        if (q != NULL) {
            *(VFunc **)q = Ov002Vt_021ef684_vtbl;
            ListRow_Init(q);
            *(VFunc **)q = Ov000Vt_021cc9f8_vtbl;
            ListRowGauge_Init(q);
        }
        q->index = i;
        ListRowGauge_SetText(q, self->unk_4c[i].label);
        val = func_ov002_021e4c30(i);
        lvl = Ov002LevelTable_GetLevel(&self->unk_4c[i], val);
        if (lvl != 3) {
            s32 lo = 0;
            s32 hi;
            if (lvl != 0) {
                lo = ov002_Thresh(&self->unk_4c[i], lvl - 1);
            }
            hi = ov002_Thresh(&self->unk_4c[i], lvl);
            q->value = (s32)((val - lo) * 100) / (hi - lo) + lvl * 100;
        } else {
            q->value = 300;
        }
        q->max = 300;
        LoBase021ccb54_021ccbe0_AppendRow(self->unk_3c, q);
    }
    self->unk_3c->owner = self;
    self->unk_3c->onCursor = (void *)LibraryMenu_List3cOnCursor;
    self->unk_3c->onDecide = (void *)LibraryMenu_List3cOnDecide;
    self->unk_3c->vfunc_08();
    {
        Lo021cadcc *p = (Lo021cadcc *)Heap_Alloc(sizeof(Lo021cadcc));
        if (p != NULL) {
            *(VFunc **)p = UiObj_vtbl;
            p->vfunc_28();
            *(VFunc **)p = Lo021cadcc_vtbl;
            p->vfunc_28();
        }
        self->unk_40 = p;
        p->width = 0xf5;
    }
    self->unk_40->rows = 1;
    {
        Lo021cadcc *s = self->unk_40;
        s->posX = 4;
        s->posY = 0x8e;
        s->posZ = -0x199a;
    }
    {
        Lo021cadcc *s = self->unk_40;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_40->slideMode = 1;
    self->unk_40->flags |= 0x10000;
    self->unk_40->color = 0xb;
    self->unk_40->vfunc_08();
    {
        Lo021cb5a8 *p = (Lo021cb5a8 *)Heap_Alloc(sizeof(Lo021cb5a8));
        if (p != NULL) {
            *(VFunc **)p = UiObj_vtbl;
            p->vfunc_28();
            *(VFunc **)p = UiList_vtbl;
            p->vfunc_28();
            *(VFunc **)p = Lo021cb5a8_vtbl;
            p->vfunc_28();
        }
        self->unk_44 = p;
        p->flags |= 0x4000000;
    }
    self->unk_44->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_44;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_44->flags |= 0x20000000;
    self->unk_44->flags |= 0x80000000;
    self->unk_44->vfunc_f4(1, MsgRes_GetString(g, 0x34));
    self->unk_44->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_44->vfunc_08();
    TaskList_Insert(self);
}

}
}  // namespace m_021d278c

// ---- merged from ov002_021d2c2c.cpp
namespace m_021d2c2c {
extern "C" {

void LibraryMenu_UpdateActive(Task021ef99c *self) {
    if (!(gPad->trig & 2)) {
        return;
    }
    if (self->unk_48 != 0) {
        self->unk_48->flags |= 2;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    self->vfunc_0c(0);
}

}
}  // namespace m_021d2c2c

// ---- merged from ov002_021d2ca4.cpp
namespace m_021d2ca4 {
extern "C" {

static inline bool ov002_Task_getFlag1(Task *self) {
    return self->unk_04_1;
}

static inline BOOL ov002_isDone2ca4(UiObj *o) {
    return o->state == 5;
}

void LibraryMenu_PreUpdate(Task021ef99c *self) {
    switch (self->state) {
    case 8:
        SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
        self->unk_3c->flags &= ~2;
        self->unk_40->flags &= ~2;
        self->unk_44->flags &= ~2;
        break;
    case 12: {
        void *x = self->unk_4c[self->unk_3c->unk_a0->index].desc;
        if (self->unk_40 != NULL) {
            Obj0215bb14_SetText(self->unk_40, x);
            self->unk_40->vfunc_70();
        }
        break;
    }
    case 10:
        SndMgr_PlayVolume(gSndMgr, 0x28, -1, -1, -1);
        self->unk_3c->flags |= 2;
        self->unk_40->flags |= 2;
        self->unk_44->flags |= 2;
        break;
    }
    if (self->unk_48 != NULL) {
        gTaskSwitchPending = 1;
        self->unk_3c->flags |= 4;
        self->unk_48->vfunc_1c();
        if (ov002_isDone2ca4(self->unk_48)) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(self->unk_48);
            HEAP_POP(saved);
            gTaskSwitchPending = 0;
            self->unk_3c->flags &= ~4;
        }
    } else if (self->unk_3c != NULL) {
        if (self->vfunc_54()) {
            BOOL f = ov002_Task_getFlag1(self);
            if (!f) {
                self->unk_3c->flags &= ~4;
                goto done;
            }
        }
        self->unk_3c->flags |= 4;
    }

done:
    ((VObj *)self->unk_3c)->vfunc_1c();
    self->unk_40->vfunc_1c();
    self->unk_44->vfunc_1c();
}

}
}  // namespace m_021d2ca4

// ---- merged from ov002_021d2ef4.cpp
namespace m_021d2ef4 {
extern "C" {

void LibraryMenu_PostUpdate(void) {
}

void LibraryMenu_Draw(Task021ef99c *self) {
    if (self->unk_3c != NULL) {
        self->unk_3c->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
    if (self->unk_44 != NULL) {
        self->unk_44->vfunc_20();
    }
    if (self->unk_48 != NULL) {
        self->unk_48->vfunc_20();
    }
}

Task021ef91c *LibraryViewer_New(void) {
    Task021ef91c *p = (Task021ef91c *)Heap_Alloc(0xd0);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = Ov002TaskVt_021ef91c_vtbl;
        Ov002LevelTable_Ctor(&p->unk_94);
        Ov002StrTable_Ctor(&p->unk_ac);
        p->vfunc_58();
    }
    p->vfunc_08(0x19, 0xc8);
    return p;
}

}
}  // namespace m_021d2ef4

// ---- merged from ov002_021d2fdc.cpp
namespace m_021d2fdc {
extern "C" {

extern VFunc Lo021cb5a8_vtbl[];
extern VFunc Ov000Vt_021ccadc_vtbl[];
extern VFunc Ov000Vt_021cca58_vtbl[];
void *ResMgr_FindArcType0(void *a, void *b);
void Ov002LevelTable_Load(Ov002LevelTable *self, u8 *src);
void Ov002StrTable_Load(Ov002StrTable *self, u8 *src);
char *Ov002StrTable_GetLabel(Ov002StrTable *self, u32 idx);
char *Ov002StrTable_GetDesc(Ov002StrTable *self, u32 idx);
void ListRow_Init(ListRow *self);
void ListRowText_Init(ListRowText *self);
void TextList_Init(TextList *self);
void List021c6474_Append(TextList *self, ListRow *row);

static inline bool ov002_IsActive(TimedBuffer021cb920 *p) {
    return p->unk_28 != 1 ? 0 : (s32)p->unk_30;
}

static inline bool ov002_HasActive(FieldPlayer *t) {
    TimedBuffer021cb920 *p = t->unk_118;
    if (p == NULL) {
        return false;
    }
    return ov002_IsActive(p) != 0;
}

void LibraryViewer_Start(Task021ef91c *self) {
    UiObj *p;
    void *g;
    u32 i;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    g = gMsgRes;
    Ov002LevelTable_Load(&self->unk_94, *(u8 **)ResMgr_FindArcType0(self->unk_44, self->unk_7c));
    Ov002StrTable_Load(&self->unk_ac, *(u8 **)ResMgr_FindArcType0(self->unk_44, self->unk_64));
    {
        p = (UiObj *)Heap_Alloc(0xe0);
        if (p != NULL) {
            *(VFunc **)p = UiObj_vtbl;
            p->vfunc_28();
            *(VFunc **)p = UiList_vtbl;
            p->vfunc_28();
            *(VFunc **)p = Lo021cb5a8_vtbl;
            p->vfunc_28();
        }
        self->unk_40 = (Lo021cb5a8 *)p;
        p->flags |= 0x4000000;
    }
    self->unk_40->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_40;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = 0;
    }
    {
        Lo021cb5a8 *s = self->unk_40;
        s->posX = 0;
        s->posY = 0;
        s->posZ = -0x199a;
    }
    self->unk_40->flags |= 0x20000000;
    self->unk_40->flags |= 0x80000000;
    self->unk_40->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_40->vfunc_08();
    {
        p = (UiObj *)Heap_Alloc(0xd4);
        if (p != NULL) {
            *(VFunc **)p = UiObj_vtbl;
            p->vfunc_28();
            *(VFunc **)p = Ov000Vt_021ccadc_vtbl;
            TextList_Init((TextList *)p);
        }
        self->unk_3c = (TextList *)p;
        p->vfunc_10(self->unk_94.label);
    }
    self->unk_3c->vfunc_14(self->unk_94.desc);
    self->unk_3c->posZ = -0x199a;
    self->unk_3c->listFlags.showCursor = 0;
    self->unk_3c->listFlags.wrap = 0;
    for (i = 0; i < ((u32)self->unk_c0); i++) {
        ListRowText *q = (ListRowText *)Heap_Alloc(sizeof(ListRowText));
        if (q != NULL) {
            *(VFunc **)q = Ov002Vt_021ef684_vtbl;
            ListRow_Init(q);
            *(VFunc **)q = Ov000Vt_021cca58_vtbl;
            ListRowText_Init(q);
        }
        q->unk_38 = Ov002StrTable_GetLabel(&self->unk_ac, i);
        q->unk_34 = Ov002StrTable_GetDesc(&self->unk_ac, i);
        List021c6474_Append(self->unk_3c, q);
    }
    self->unk_3c->vfunc_08();
    TaskList_Insert(self);
    {
        FieldPlayer *t = gMessageQueue;
        if (t != NULL) {
            if (ov002_HasActive(t) && t->unk_118 != NULL) {
                // Read as a u32, so MWCC does not reuse the pointer load from the test above.
                func_ov000_0216f844((TimedBuffer021cb920 *)FIELD(t, 0x118, u32), 0);
            }
        }
    }
}

}
}  // namespace m_021d2fdc

// ---- merged from ov002_021d32d4.cpp
namespace m_021d32d4 {
extern "C" {

void LibraryViewer_Init(Task021ef91c *self) {
    self->fadeLen = 0x1000;
    self->unk_3c = NULL;
    self->unk_40 = NULL;
    func_ov002_021e4904(&self->unk_94);
    Ov002StrTable_Clear(&self->unk_ac);
    self->unk_bc = 0;
    self->unk_c0 = 0;
    self->unk_c4 = NULL;
    self->unk_c8 = NULL;
    self->unk_cc = -1;
}

}
}  // namespace m_021d32d4

// ---- merged from ov002_021d331c.cpp
namespace m_021d331c {
extern "C" {

void LibraryViewer_Release(Task021ef91c *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    {
        Model *p = self->unk_c4;
        if (p != NULL) {
            if (p != NULL) {
                TexObj_Release(p);
                PlttRes_Release(&p->pltt);
                Heap_Free(p);
            }
            self->unk_c4 = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_c8);
    HEAP_POP(saved);
    Ov002StrTable_Clear(&self->unk_ac);
}

}
}  // namespace m_021d331c

// ---- merged from ov002_021d3434.cpp
namespace m_021d3434 {
extern "C" {

static inline bool func_ov002_021d3434_idle(void) {
    BOOL r;
    if (gFadeState[3] == 0 && gFadeState[1] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}
void LibraryViewer_UpdateActive(Task021ef91c *self) {
    FieldPlayer *t;
    if (!(gPad->trig & 2) || self->unk_c4 == NULL) {
        return;
    }
    if (!func_ov002_021d3434_idle()) {
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    if (self->unk_3c != NULL) {
        self->unk_3c->flags |= 2;
    }
    if (self->unk_40 != NULL) {
        self->unk_40->flags |= 2;
    }
    self->unk_04_0 = 1;
    t = gMessageQueue;
    if (t != NULL && t->unk_118 != NULL) {
        func_ov000_0216f844(t->unk_118, 1);
    }
}

void LibraryViewer_PreUpdate(Task021ef91c *self) {
    if (self->state == 0xd) {
        LibraryViewer_ShowPage(self);
    }
}

}
}  // namespace m_021d3434

// ---- merged from ov002_021d3530.cpp
namespace m_021d3530 {
extern "C" {

void LibraryViewer_PostUpdate(Task021ef91c *self) {
    s32 cnt;
    if (self->state != 0xd) {
        return;
    }
    cnt = 0;
    if (self->unk_3c != NULL && self->unk_3c->vfunc_1c()) {
        s32 n = self->unk_3c->index + self->unk_bc * 3;
        cnt++;
        if (self->unk_cc != n) {
            LibraryViewer_LoadPage(self, n);
        }
    }
    if (self->unk_40 != NULL && self->unk_40->vfunc_1c()) {
        cnt++;
    }
    if (cnt == 0) {
        self->vfunc_0c(0);
    }
}

}
}  // namespace m_021d3530

// ---- merged from ov002_021d35d4.cpp
namespace m_021d35d4 {
extern "C" {

void LibraryViewer_Draw(Task021ef91c *self) {
    Model *model;
    ModelRes *res;
    ModelPart *anim;
    void *arg;
    ModelPartRes *t;
    if (self->fadeRatio == 0 || self->state == 0) {
        return;
    }
    if (self->state != 0xc && self->state != 0xd) {
        return;
    }
    if (self->unk_3c != NULL) {
        ((VObj *)self->unk_3c)->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
    if (self->unk_c4 == NULL) {
        return;
    }
    if (Model_IsReady(self->unk_c4, 0xffff) == 0) {
        return;
    }
    model = self->unk_c4;
    if ((res = model->res) == NULL) {
        return;
    }
    anim = NULL;
    if (model->numParts > 0) {
        anim = model->parts;
    }
    if (anim != NULL && (t = anim->res) != NULL) {
        arg = t->tex;
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0);
        arg = NNS_G2dGetCellDataByIdx(res->texRes, **(u16 **)FIELD(e, 0xc, void *));
    }
    TexObj_DrawCell(model, arg, anim, 0);
}

}
}  // namespace m_021d35d4
