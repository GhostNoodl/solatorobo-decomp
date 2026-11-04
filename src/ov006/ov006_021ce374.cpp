// One source file for 0x021ce374..0x021d23d0, plus the static initialiser at 0x021ebabc.
// Its functions share the string pool at 0x021ebbb0 (@stringBase0), and two of them read
// the file-local separator string pointer at 0x021ebbac, so they have to be compiled
// together. The former files are kept as they were, each in its own namespace, so that
// their local typedefs, inlines and extern declarations do not clash.
#pragma pool_strings on
#pragma dont_reuse_strings off
#include <nitro/fx.h>
#include "ov006/Emblem.h"
#include "ov006/Tasks.h"
#include "ov006/Caption.h"
#include "ov006/ov006.h"
#include "ov006/SlotManager.h"
#include "Main/Res/ResArc.h"
#include "nitro/mi.h"
#include "Main/Res/ArcName.h"
#include "Main/Gfx/GfxMgr.h"

// ---- merged from ov006_021ebabc.cpp
static const fx32 data_ov006_021ebba8 = FX_Div(256 * FX32_ONE, 15 * FX32_ONE);
static const char *data_ov006_021ebbac = "--------------------";

// ---- merged from ov006_021ce374.cpp
namespace m_021ce374 {

extern "C" {

extern char data_ov006_021ec864[];
extern char *data_0208ccc0;

void ov006_DrawSprite3D(void *self, s32 x, s32 y, s32 z, s32 unused, void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs);
void ov006_Emblem_LoadModels(ov006_Emblem *self);
void TaskList_Insert(Task *self);
void TexObj_SetOamFuncArg(Model *self, int a, void *b);
BOOL Model_IsReady(Model *a, int b);

void ov006_Emblem_Load(void) {
}

BOOL ov006_Emblem_IsLoaded(void) {
    return TRUE;
}

void ov006_Emblem_Start(ov006_Emblem *self) {
    self->unk_04_1 = 0;
    if (self->vfunc_28()) {
        return;
    }
    ov006_Emblem_LoadModels(self);
    self->unk44 = 1;
    self->parent = NULL;
    TaskList_Insert(self);
}

static inline BOOL ov006_Emblem_Bit4(ov006_Emblem *self) {
    return self->unk_04_4 != 0;
}

BOOL Ov006Task_GetFlag4(ov006_Emblem *self) {
    return ov006_Emblem_Bit4(self) ? TRUE : FALSE;
}

void ov006_Emblem_LoadModels(ov006_Emblem *self) {
    Model *model;
    Model *model2;

    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = "cefly1pic00";
        PlttRes_Init_02041218(&model->pltt);
        TexObj_Init(model, name, 0);
        STD_CopyString(model->name, data_ov006_021ec864);
    }
    self->unk3C = model;
    TexObj_SetRes(self->unk3C, ResMgr_FindArcType2(data_ov006_021ec864, "cefly1pic00"));
    self->unk3C->flags |= 2;
    self->unk3C->flags |= 0x80000;
    TexObj_SelectImage(self->unk3C, 2, 0xffff);
    model2 = (Model *)Heap_Alloc(sizeof(Model));
    if (model2 != NULL) {
        const char *file = data_0208cca0;
        const char *name = data_0208ccc0;
        PlttRes_Init_02041218(&model2->pltt);
        TexObj_Init(model2, name, 0);
        STD_CopyString(model2->name, file);
    }
    self->unk40 = model2;
    TexObj_SetRes(self->unk40, ResList_FindType2(ResMgr_GetArcList(data_0208cca0), data_0208ccc0));
    self->unk40->flags |= 2;
    TexObj_SelectImage(self->unk40, 0, 0);
    ov006_Model_SetPos(self->unk40, 0, 0, 0);
    self->unk40->unk_150 = 0xfffe019a;
    self->unk40->unk_158 = (void *)ov006_DrawSprite3D;
    TexObj_SetOamFuncArg(self->unk40, 0, &self->unk48);
}

}
}  // namespace m_021ce374

// ---- merged from ov006_021ce560.cpp
namespace m_021ce560 {

extern "C" {

extern char data_ov006_021ec864[];
extern char *data_0208ccc0;

void ov006_Emblem_LoadModels(ov006_Emblem *self);
void ov006_DrawSprite3D(void *self, s32 x, s32 y, s32 z, s32 unused, void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs);
void TaskList_Insert(Task *self);
void TexObj_SetOamFuncArg(Model *self, int a, void *b);
BOOL Model_IsReady(Model *a, int b);

void ov006_Emblem_PreUpdate(void) {
}

void ov006_Emblem_PostUpdate(ov006_Emblem *self) {
    int v = 0;
    if (self->unk48 < 0x1000000) {
        v = self->unk48 + 0x8000;
    }
    self->unk48 = v;
    self->unk4C = self->unk4C >= 0x1000000 ? 0 : self->unk4C + 0x8000;
}

void ov006_Emblem_Draw(ov006_Emblem *self) {
    if (!self->unk44) {
        return;
    }
    if (self->unk40 != NULL && Model_IsReady(self->unk40, 0xffff)) {
        Model_PlayPart(self->unk40, 0);
    }
    if (self->unk3C != NULL && Model_IsReady(self->unk3C, 0xffff)) {
        Model_PlayPart(self->unk3C, 0);
    }
}

BOOL func_ov006_021ce6ac(void) {
    return FALSE;
}

BOOL func_ov006_021ce6b4(void) {
    return FALSE;
}

}
}  // namespace m_021ce560

// ---- merged from ov006_021ce6bc.cpp
namespace m_021ce6bc {

extern "C" {

extern void *ov006_ModeMenu_vtbl;

void ov006_ModeMenu_ShowHelp(ov006_TaskCE *self, u16 a);

static inline void ov006_TaskCE_Init(ov006_TaskCE *self) {
    OV006_TASKBASE_CTOR(self);
    *(void **)self = &ov006_ModeMenu_vtbl;
    self->step = 0;
    self->subStep = 0;
    self->unk44 = NULL;
    self->unk48 = NULL;
    self->unk4C = NULL;
    self->unk50 = NULL;
    self->unk54 = NULL;
}

ov006_TaskCE *ov006_ModeMenu_New(void) {
    ov006_TaskCE *self = (ov006_TaskCE *)Heap_Alloc(sizeof(ov006_TaskCE));
    if (self != NULL) {
        ov006_TaskCE_Init(self);
    }
    self->vfunc_08(0x26, 200);
    return self;
}

static inline void ov006_TaskCE_Open(ov006_TaskCE *self, int id) {
    OV006_DELETE_OBJECT(self->unk4C);
    self->unk4C = ov006_MsgBox_New();
    MsgBox_Open(self->unk4C, id, "script/other", "skyhelp.ccmes", 1);
    self->unk44->flags |= 4;
    self->unk48->flags |= 2;
}

BOOL ov006_ModeMenu_List44OnDecide(UiList *list, UiListItem *arg) {
    ov006_TaskCE *self = (ov006_TaskCE *)list->owner;
    if (arg != NULL) {
        u16 id;
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
        id = arg->id;
        if (self->step == 3) {
            switch (id) {
            case 0:
                self->step = 4;
                self->subStep = 0;
                break;
            case 1:
                self->step = 5;
                self->subStep = 0;
                break;
            case 2:
                ov006_TaskCE_Open(self, 0);
                break;
            case 3:
                ov006_TaskCE_Open(self, 2);
                break;
            case 4:
                ov006_TaskCE_Open(self, 3);
                break;
            case 5:
                self->step = 6;
                self->subStep = 0;
                break;
            }
        }
    }
    return TRUE;
}

BOOL ov006_ModeMenu_List44OnCursor(UiList *list, UiListItem *arg) {
    ov006_TaskCE *self = (ov006_TaskCE *)list->owner;
    if (arg != NULL) {
        ov006_ModeMenu_ShowHelp(self, arg->id);
    }
    return TRUE;
}

static inline void ov006_TaskCE_Dtor(ov006_TaskCE *self) {
    *(void **)self = &ov006_ModeMenu_vtbl;
    OV006_DELETE_OBJECT(self->unk44);
    OV006_DELETE_OBJECT(self->unk48);
    OV006_DELETE_OBJECT(self->unk4C);
    OV006_DELETE_OBJECT(self->unk50);
    OV006_DELETE_OBJECT(self->unk54);
    OV006_TASKBASE_DTOR(self);
}

ov006_TaskCE *ov006_ModeMenu_Dtor_021ce974(ov006_TaskCE *self) {
    ov006_TaskCE_Dtor(self);
    return self;
}

ov006_MsgBox *ov006_MsgBox_DtorDelete(ov006_MsgBox *self) {
    self->vtbl = &ov006_MsgBox_vtbl;
    MsgBox_Release(self);
    Heap_Free(self);
    return self;
}

ov006_TaskCE *ov006_ModeMenu_DtorDelete(ov006_TaskCE *self) {
    ov006_TaskCE_Dtor(self);
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021ce6bc

// ---- merged from ov006_021cec5c.cpp
namespace m_021cec5c {

extern "C" {

void ov006_ModeMenu_Load(void) {
}

BOOL ov006_ModeMenu_IsLoaded(void) {
    return TRUE;
}

}
}  // namespace m_021cec5c

// ---- merged from ov006_021cec68.cpp
namespace m_021cec68 {


typedef struct ov006_Entry021cec68 {
    u16 name;
} ov006_Entry021cec68;

extern "C" {

extern void *gMsgRes;
extern void *UiObj_vtbl;
extern void *UiList_vtbl;
extern void *Lo021cadcc_vtbl;
extern void *Ov000Vt_021ccbe0_vtbl;
extern void *Ov000Vt_021ccb54_vtbl;
extern void *Ov000Vt_021cca28_vtbl;
extern void *Ov006Vt_021ebc80_vtbl;

void *MsgRes_GetString(void *a, int id);
void Gfx3DState_SetDefaults(void *p);
void Gfx3DState_Apply(void *p);
void TaskList_Insert(Task *self);
void ov006_SlotManager_Reset_021daea0(ov006_SlotManager *a);
u8 ov006_SlotManager_CountItems(ov006_SlotManager *self);
void ov006_InitOwnerSlot(void);
ov006_Entry021cec68 *ov006_GetPriceEntry(u32 id);
void ListRow_Init(void *self);
void ListRowLabel_Init(void *self);
void func_ov000_021c5fd0(void *self, const void *s);
void ov006_CaptionPanel_PlayText(ov006_CaptionPanel *self, const void *s);
BOOL ov006_ModeMenu_List44OnDecide(UiList *list, UiListItem *arg);
BOOL ov006_ModeMenu_List44OnCursor(UiList *list, UiListItem *arg);
}


extern "C" {

static inline u8 ov006_SlotManager_Get14A(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->items[i];
    }
    return 0;
}

// The list items are constructed in place through `item` (round jkH): with a `NewItem` inline
// the inline's result is a compiler temp, numbered below `res`, and the two swap registers.
void ov006_ModeMenu_Start(ov006_TaskCE *self) {
    u8 n;
    u8 i;
    u8 k;
    ov006_Entry021cec68 *e;
    void *item;
    GfxSys *g;
    if (self->vfunc_28()) {
        return;
    }
    {
        g = gGfxSys;
        Gfx3DState_SetDefaults(g->unk_8b0);
        g->unk_8b0_4 = 1;
        g->unk_8b0_5 = 1;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        Gfx3DState_Apply(g->unk_8b0);
    }
    self->unk_04 &= ~2;
    ov006_SlotManager_Reset_021daea0(gOv006SlotManager);
    self->fadeLen = 0x19000;
    self->vfunc_3c();
    void *res = gMsgRes;
    self->unk44 = ov006_NewUiList();
    self->unk44->vfunc_10(MsgRes_GetString(res, 0x122));
    self->unk44->vfunc_14(MsgRes_GetString(res, 0x123));
    self->unk44->unk_4a = 0x2c00;
    self->unk44->width = 0xac;
    self->unk44->rows = 4;
    ov006_Window_SetPos(self->unk44, 0, 0x1e, -0x2000);
    ov006_Window_SetSlide(self->unk44, 0, -0x100, -0x2000);
    self->unk44->slideMode = 1;
    self->unk44->flags &= ~0x400000;
    self->unk44->flags &= ~0x800000;
    self->unk44->flags &= ~0x20000;
    self->unk44->flags &= ~0x80000;
    self->unk44->flags &= ~0x40000;
    self->unk44->flags &= ~0x10000;
    UiList_SetIconModel(self->unk44, "menu/net", "wireless_on", 0xffff);
    self->unk44->vfunc_74(MsgRes_GetString(res, 0x124), 0, 0xffff, 0xffff);
    self->unk44->vfunc_74(MsgRes_GetString(res, 0x126), 1, 0, 0xffff);
    self->unk44->vfunc_74(MsgRes_GetString(res, 0x140), 2, 0xffff, 0xffff);
    self->unk44->vfunc_74(MsgRes_GetString(res, 0x142), 3, 0xffff, 0xffff);
    self->unk44->vfunc_74(MsgRes_GetString(res, 0x144), 4, 0xffff, 0xffff);
    self->unk44->vfunc_74(MsgRes_GetString(res, 0x146), 5, 0xffff, 0xffff);
    {
        UiList *w = self->unk44;
        w->vfunc_a8(UiList_GetItemById(w, 0));
    }
    self->unk44->onDecide = ov006_ModeMenu_List44OnDecide;
    self->unk44->onCursor = ov006_ModeMenu_List44OnCursor;
    self->unk44->owner = self;
    self->unk44->vfunc_08();
    self->unk48 = ov006_NewLo021cadcc();
    self->unk48->width = 0xf8;
    self->unk48->rows = 2;
    ov006_Window_SetPos(self->unk48, 4, 0x95, -0x2000);
    ov006_Window_SetSlide(self->unk48, -0x100, 0, -0x2000);
    self->unk48->slideMode = 1;
    self->unk48->vfunc_08();
    self->unk48->flags |= 4;
    ov006_TaskCE_ShowMenus(self);
    ov006_InitOwnerSlot();
    n = ov006_SlotManager_CountItems(gOv006SlotManager);
    if (n != 0) {
        if (gOv006SlotManager->unk149 == 0) {
            self->unk50 = ov006_NewHudList();
            Obj021c55e8_SetLabel1(self->unk50, MsgRes_GetString(res, 0x183));
            self->unk50->rows = (n == 1) ? 2 : n;
            self->unk50->width = 0xc0;
            ov006_Window_SetPos(self->unk50, 0x20, 0x3c, -0x1ccd);
            for (i = 0; i < 3; i++) {
                e = ov006_GetPriceEntry(ov006_SlotManager_Get14A(gOv006SlotManager, i));
                if (e != NULL) {
                    item = Heap_Alloc(0x34);
                    if (item != NULL) {
                        *(void **)item = &Ov006Vt_021ebc80_vtbl;
                        ListRow_Init(item);
                        *(void **)item = &Ov000Vt_021cca28_vtbl;
                        ListRowLabel_Init(item);
                    }
                    func_ov000_021c5fd0(item, MsgRes_GetString(res, e->name));
                    LoBase021ccb54_021ccbe0_AppendRow(self->unk50, item);
                }
            }
            self->unk50->flags &= ~0x40000;
            self->unk50->unk_f0 = 0;
            self->unk50->flags |= 4;
            self->unk50->vfunc_08();
            self->unk50->flags |= 2;
        }
        {
            ov006_CaptionPanel *p = (ov006_CaptionPanel *)Heap_Alloc(0x24);
            if (p != NULL) {
                p = Ov006Vt_021ec29c_Ctor(p);
            }
            self->unk54 = p;
        }
        ov006_CaptionPanel_Load(self->unk54);
        ov006_CaptionPanel_PlayText(self->unk54, MsgRes_GetString(res, 0x183));
        {
            k = 0;
            for (i = 0; i < 3; i++) {
                e = ov006_GetPriceEntry(ov006_SlotManager_Get14A(gOv006SlotManager, i));
                if (e != NULL) {
                    ov006_CaptionSet_SetText(self->unk54, (const char *)MsgRes_GetString(res, e->name), k);
                    k++;
                }
            }
        }
    }
    gOv006SlotManager->unk149 = 1;
    self->step = 0;
    self->subStep = 0;
    GfxSys_StartFadeIn(0x14000, 0, 0);
    GfxSys_StartFadeIn(0x14000, 0, 1);
    TaskList_Insert(self);
}

}
}  // namespace m_021cec68

// ---- merged from ov006_021cf350.cpp
namespace m_021cf350 {

extern "C" {

void Ov006Task_SetFlag7(Task *self) {
    self->unk_04_7 = 1;
}

}
}  // namespace m_021cf350

// ---- merged from ov006_021cf360.cpp
namespace m_021cf360 {

typedef struct ov006_DataRes {
    u8 unk0[0x4c];
    u8 *unk4C;
} ov006_DataRes;

extern "C" {

extern void *gMsgRes;
extern ov006_DataRes *gDataRes;

void *MsgRes_GetString(void *a, int id);
void ov006_ModeMenu_Step00(ov006_TaskCE *self);
void ov006_ModeMenu_Step02(ov006_TaskCE *self);
void ov006_ModeMenu_Step03(ov006_TaskCE *self);
void ov006_ModeMenu_Step06(ov006_TaskCE *self);
void ov006_SetupDefaultSlots(void);
void *DataRes_GetTable(ov006_DataRes *res, u32 idx);
u32 DataRes_GetCount(ov006_DataRes *res, u32 idx);
u16 DataRes_ReadBitsAt_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx);
void ov006_Unk021e2f3c_Update(ov006_CaptionPanel *a);

void ov006_ModeMenu_ShowHelp(ov006_TaskCE *self, u16 id) {
    const void *str;
    void *res = gMsgRes;
    switch (id) {
    case 0:
        str = MsgRes_GetString(res, 0x125);
        break;
    case 1:
        str = MsgRes_GetString(res, 0x127);
        break;
    case 2:
        str = MsgRes_GetString(res, 0x141);
        break;
    case 3:
        str = MsgRes_GetString(res, 0x143);
        break;
    case 4:
        str = MsgRes_GetString(res, 0x145);
        break;
    case 5:
        str = MsgRes_GetString(res, 0x147);
        break;
    default:
        str = "";
        break;
    }
    if (self->unk48 != NULL) {
        Obj0215bb14_SetText(self->unk48, str);
        self->unk48->vfunc_70();
    }
}

}
}  // namespace m_021cf360

// ---- merged from ov006_021cf414.cpp
namespace m_021cf414 {

extern "C" {

// Both tests have no effect, so MWCC drops the second load and compare but keeps the first.
void ov006_ModeMenu_UpdateActive(ov006_TaskCE *self) {
    if (self->unk4C == NULL) {
        return;
    }
    if (self->unk50 == NULL) {
        return;
    }
}

}
}  // namespace m_021cf414

// ---- merged from ov006_021cf420.cpp
namespace m_021cf420 {

typedef struct ov006_DataRes {
    u8 unk0[0x4c];
    u8 *unk4C;
} ov006_DataRes;

extern "C" {

extern ov006_DataRes *gDataRes;
void ov006_ModeMenu_Step00(ov006_TaskCE *self);
void ov006_ModeMenu_Step02(ov006_TaskCE *self);
void ov006_ModeMenu_Step03(ov006_TaskCE *self);
void ov006_ModeMenu_Step06(ov006_TaskCE *self);
void ov006_SetupDefaultSlots(void);
void *DataRes_GetTable(ov006_DataRes *res, u32 idx);
u32 DataRes_GetCount(ov006_DataRes *res, u32 idx);
u16 DataRes_ReadBitsAt_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx);
void ov006_Unk021e2f3c_Update(ov006_CaptionPanel *a);

void ov006_ModeMenu_PreUpdate(ov006_TaskCE *self) {
    u8 *block;
    u16 n;
    u16 i;
    void *ent;
    switch (self->step) {
    case 0:
        ov006_ModeMenu_Step00(self);
        break;
    case 1:
        switch (self->subStep) {
        case 0:
            OV006_DELETE_OBJECT(self->unk4C);
            self->unk4C = ov006_MsgBox_New();
            MsgBox_Open(self->unk4C, 1, "script/other", "skyhelp.ccmes", 0);
            self->unk44->flags |= 4;
            self->unk48->flags |= 2;
            self->unk44->flags |= 4;
            self->unk44->flags |= 2;
            self->unk48->flags |= 2;
            self->subStep++;
            break;
        case 1:
            if (!MsgBox_Update(self->unk4C)) {
                OV006_DELETE_OBJECT(self->unk4C);
                self->unk44->flags &= ~4;
                self->unk48->flags &= ~2;
                if (self->unk50 == NULL) {
                    self->step = 3;
                    self->subStep = 0;
                } else {
                    self->step = 2;
                    self->subStep = 0;
                }
            }
            break;
        }
        break;
    case 2:
        ov006_ModeMenu_Step02(self);
        break;
    case 3:
        ov006_ModeMenu_Step03(self);
        break;
    case 4: {
        ov006_SetupDefaultSlots();
        block = gDataRes->unk4C + 0x1d0;
        ent = DataRes_GetTable(gDataRes, 0xe);
        n = DataRes_GetCount(gDataRes, 0xe);
        for (i = 0; i < n; i++) {
            if (DataRes_ReadBitsAt_02059544(gDataRes, block, ent, 1, i)) {
                ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5)->unkC = i | 0x7000;
                break;
            }
        }
        TaskHost_RequestSwitch(gTaskHost, 0x29, 0);
        gOv006Manager->unk1C = 0;
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->step = 7;
        self->unk_04 |= 6;
        self->subStep = 0;
        break;
    }
    case 5:
        TaskHost_RequestSwitch(gTaskHost, 0x27, TRUE);
        gOv006Manager->unk1C = TRUE;
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->unk_04 |= 6;
        self->step = 7;
        self->subStep = 0;
        break;
    case 6:
        ov006_ModeMenu_Step06(self);
        break;
    case 7:
        break;
    }
    self->unk44->vfunc_1c();
    self->unk48->vfunc_1c();
    if (self->unk50 != NULL) {
        self->unk50->vfunc_1c();
    }
    ov006_Unk021e2f3c_Update(self->unk54);
}

}
}  // namespace m_021cf420

// ---- merged from ov006_021cf7c4.cpp
namespace m_021cf7c4 {

extern "C" {

void ov006_ModeMenu_PostUpdate(void) {
}

}
}  // namespace m_021cf7c4

// ---- merged from ov006_021cf7c8.cpp
namespace m_021cf7c8 {

extern "C" {

BOOL ov006_Menu_RequestShutdown(ov006_Menu *self);
void ov006_ModeMenu_ShowHelp(ov006_TaskCE *self, u16 id);

void ov006_ModeMenu_Step00(ov006_TaskCE *self) {
    switch (self->subStep) {
    case 0:
        ov006_Menu_RequestShutdown(gOv006Menu);
        self->subStep++;
        break;
    case 1:
        if (gOv006Menu->state == 1) {
            self->subStep++;
        }
        break;
    case 2:
        if (!gStageFlags->unk_620_0) {
            gStageFlags->unk_620_0 = 1;
            self->step = 1;
            self->subStep = 0;
        } else if (self->unk50 == NULL) {
            self->step = 3;
            self->subStep = 0;
        } else {
            self->step = 2;
            self->subStep = 0;
        }
        self->fadeLen = self->unk44->openLen;
        break;
    }
}

void ov006_ModeMenu_Step02(ov006_TaskCE *self) {
    switch (self->subStep) {
    case 0:
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->unk50->flags &= ~2;
        SndMgr_PlayVolume(gSndMgr, 0x26, -1, -1, -1);
        self->subStep++;
        break;
    case 1:
        if (!self->unk50->vfunc_0c()) {
            return;
        }
        if (!(gPad->trig & 1)) {
            return;
        }
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
        self->unk50->flags |= 2;
        self->subStep++;
        break;
    case 2:
        if (!ov006_Window_IsState5(self->unk50)) {
            return;
        }
        ov006_TaskCE_HideMenus(self);
        ov006_ModeMenu_ShowHelp(self, UiList_GetCurrent(self->unk44)->id);
        self->step = 3;
        self->subStep = 0;
        break;
    }
}

static inline BOOL ov006_Task_IsState2(UiList *self) {
    return self->state == 2;
}

BOOL ov006_Window_IsShown(UiList *self) {
    return ov006_Task_IsState2(self) ? TRUE : FALSE;
}

void ov006_ModeMenu_Step03(ov006_TaskCE *self) {
    switch (self->subStep) {
    case 0:
        ov006_TaskCE_HideMenus(self);
        ov006_ModeMenu_ShowHelp(self, UiList_GetCurrent(self->unk44)->id);
        self->subStep++;
        break;
    case 1:
        if (self->unk4C != NULL) {
            self->subStep++;
            return;
        }
        if (!(gPad->trig & 2)) {
            return;
        }
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        {
            UiList *w = self->unk44;
            w->vfunc_a8(UiList_GetItemById(w, 5));
        }
        break;
    case 2:
        if (MsgBox_Update(self->unk4C)) {
            return;
        }
        OV006_DELETE_OBJECT(self->unk4C);
        self->unk44->flags &= ~4;
        self->unk48->flags &= ~2;
        ov006_ModeMenu_ShowHelp(self, UiList_GetCurrent(self->unk44)->id);
        self->subStep = 1;
        break;
    }
}

void ov006_ModeMenu_Step06(ov006_TaskCE *self) {
    switch (self->subStep) {
    case 0:
        ov006_TaskCE_ShowMenus(self);
        self->subStep++;
        break;
    case 1:
        if (!ov006_Window_IsState5(self->unk44)) {
            return;
        }
        if (!ov006_Window_IsState5(self->unk48)) {
            return;
        }
        TaskHost_RequestSwitch(gTaskHost, 7, 1);
        self->vfunc_4c();
        self->subStep++;
        break;
    case 2:
        if (!self->vfunc_54()) {
            return;
        }
        self->unk_04 |= 6;
        self->subStep++;
        break;
    case 3:
        if (self->state != 0) {
            return;
        }
        GfxSys_StartFadeOut(0x14000, 1, 0);
        GfxSys_StartFadeOut(0x14000, 1, 1);
        self->subStep++;
        break;
    case 4:
        if (!ov006_IsMode4()) {
            return;
        }
        gOv006Manager->taskType = 3;
        self->step = 7;
        self->subStep = 0;
        break;
    }
}

BOOL Ov006Task_TryReleaseCurrent(ov006_TaskCE *self) {
    if (self->vfunc_54()) {
        ov006_SetCurrent021ccd40(NULL);
    }
    return TRUE;
}

static inline BOOL ov006_IsCurrent(void *p) {
    return gFinishingTask == p;
}

BOOL Ov006Task_IsCurrent(void *p) {
    return ov006_IsCurrent(p) ? TRUE : FALSE;
}

}
}  // namespace m_021cf7c8

// ---- merged from ov006_021cfe84.cpp
namespace m_021cfe84 {

extern "C" {

extern void *ov006_GroupSelect_vtbl;

void ov006_CaptionPanel_Draw(ov006_CaptionPanel *a);

void ov006_ModeMenu_Draw(ov006_TaskCE *self) {
    if (self->unk44 != NULL) {
        self->unk44->vfunc_20();
    }
    if (self->unk48 != NULL) {
        self->unk48->vfunc_20();
    }
    if (self->unk4C != NULL) {
        MsgBox_Render(self->unk4C);
    }
    if (self->unk50 != NULL) {
        self->unk50->vfunc_20();
    }
    if (self->step == 3) {
        ov006_CaptionPanel_Draw(self->unk54);
    }
}

static inline void ov006_TaskD0_Init(ov006_TaskD0 *self) {
    OV006_TASKBASE_CTOR(self);
    *(void **)self = &ov006_GroupSelect_vtbl;
    self->step = 0;
    self->subStep = 0;
    MI_CpuFill8(self->names, 0, sizeof(self->names));
    self->unk104 = NULL;
    self->unk108 = NULL;
    self->unk10C = NULL;
    self->unk110 = 0;
}

ov006_TaskD0 *ov006_GroupSelect_New(void) {
    ov006_TaskD0 *self = (ov006_TaskD0 *)Heap_Alloc(sizeof(ov006_TaskD0));
    if (self != NULL) {
        ov006_TaskD0_Init(self);
    }
    self->vfunc_08(0x27, 200);
    return self;
}

static inline void ov006_TaskD0_Dtor(ov006_TaskD0 *self) {
    *(void **)self = &ov006_GroupSelect_vtbl;
    OV006_DELETE_OBJECT(self->unk104);
    OV006_DELETE_OBJECT(self->unk108);
    OV006_DELETE_OBJECT(self->unk10C);
    OV006_TASKBASE_DTOR(self);
}

ov006_TaskD0 *ov006_GroupSelect_Dtor_021cff80(ov006_TaskD0 *self) {
    ov006_TaskD0_Dtor(self);
    return self;
}

ov006_TaskD0 *ov006_GroupSelect_DtorDelete(ov006_TaskD0 *self) {
    ov006_TaskD0_Dtor(self);
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021cfe84

// ---- merged from ov006_021d0188.cpp
namespace m_021d0188 {

extern "C" {

BOOL ov006_Menu_RequestShutdown(ov006_Menu *self);

void ov006_GroupSelect_Load(void) {
    if (gOv006Menu->state != 1) {
        ov006_Menu_RequestShutdown(gOv006Menu);
    }
}

}
}  // namespace m_021d0188

// ---- merged from ov006_021d01ac.cpp
namespace m_021d01ac {


extern "C" {

extern void *gMsgRes;
extern void *UiObj_vtbl;
extern void *Lo021cad50_vtbl;
extern void *UiList_vtbl;
extern void *UiList021cb4a8_vtbl;
extern void *Lo021cadcc_vtbl;
extern void *ov006_EntryWait_vtbl;

BOOL func_0201fd04(void);
BOOL ov006_Menu_RequestStart(ov006_Menu *self);
BOOL func_ov006_021e4c84(ov006_Menu *self);
BOOL ov006_Menu_RequestShutdown(ov006_Menu *self);
BOOL func_ov006_021e4cb4(ov006_Menu *self);
BOOL func_ov006_021e4ce8(ov006_Menu *self, ov006_MenuData *data);
void ov006_Menu_ReleaseObj(ov006_Menu *self);
ov006_MenuNode *ov006_Menu_FindNode(ov006_Menu *self, int id);
void *MsgRes_GetString(void *a, int id);
void TaskList_Insert(Task *self);
void Str_Utf16ToUtf8Filtered(void *dst, int *dstLen, const void *src, int *srcLen);
void ov006_GroupSelect_RefreshList(ov006_TaskD0 *self);

BOOL ov006_GroupSelect_IsLoaded(ov006_TaskD0 *self) {
    BOOL r = FALSE;
    switch (self->step) {
    case 0:
        if (!func_0201fd04()) {
            self->step = 0;
            r = TRUE;
            self->unk110 = TRUE;
        } else if (gOv006Menu->state == 1) {
            ov006_Menu_RequestStart(gOv006Menu);
            self->step = 1;
        }
        break;
    case 1:
        if (gOv006Menu->state == 3) {
            func_ov006_021e4c84(gOv006Menu);
            self->step = 2;
        }
        break;
    default:
        r = TRUE;
        break;
    }
    return r;
}

void ov006_GroupSelect_Start(ov006_TaskD0 *self) {
    UiListItem *item;
    u16 i;
    void *res;
    if (self->vfunc_28()) {
        return;
    }
    res = gMsgRes;
    if (self->unk110) {
        self->unk10C = ov006_NewLo021cad50();
        self->unk10C->vfunc_08();
        Obj0215c1bc_SetText(self->unk10C, 0x8000, MsgRes_GetString(res, 0x19e));
        self->unk10C->vfunc_70();
        self->unk_04 &= ~2;
        TaskList_Insert(self);
        return;
    }
    self->unk104 = ov006_NewUiList021cb4a8();
    self->unk104->vfunc_10(MsgRes_GetString(res, 0x12d));
    self->unk104->vfunc_14(MsgRes_GetString(res, 0x12e));
    UiList021cb4a8_SetLabel(self->unk104, MsgRes_GetString(res, 0x12f));
    UiList021cb4a8_SetCenteredLabel(self->unk104, MsgRes_GetString(res, 0x130));
    self->unk104->unk_4a = 0x2c00;
    self->unk104->rows = 5;
    ov006_Window_SetPos(self->unk104, 0, 0x2c, -0x1ccd);
    ov006_Window_SetSlide(self->unk104, -0x100, 0, -0x1ccd);
    self->unk104->flags |= 0x400000;
    self->unk104->flags &= ~0x800000;
    self->unk104->unk_c0 = 0x8c;
    self->unk104->unk_c1 = 1;
    self->unk104->flags &= ~0x20000;
    self->unk104->flags &= ~0x40000;
    self->unk104->flags &= ~0x10000;
    for (i = 0; i < 4; i++) {
        item = (UiListItem *)self->unk104->vfunc_74(" ", i, 0xffff, 0);
        item->unk_10 = 0;
    }
    item = (UiListItem *)self->unk104->vfunc_74(MsgRes_GetString(res, 0x131), i, 0xffff, 0xffff);
    item->unk_24 = 4;
    item->unk_10 = 0;
    {
        UiList *w = self->unk104;
        w->vfunc_a8(UiList_GetItemById(w, 0));
    }
    self->unk104->vfunc_08();
    self->unk104->flags &= ~2;
    self->unk108 = ov006_NewLo021cadcc();
    self->unk108->width = 0xf8;
    self->unk108->rows = 2;
    ov006_Window_SetPos(self->unk108, 4, 0x95, -0x199a);
    ov006_Window_SetSlide(self->unk108, -0x100, 0, -0x199a);
    self->unk108->slideMode = 1;
    self->unk108->vfunc_08();
    Obj0215bb14_SetText(self->unk108, MsgRes_GetString(res, 0x132));
    self->unk108->vfunc_70();
    self->fadeLen = self->unk104->openLen;
    self->unk_04 &= ~2;
    TaskList_Insert(self);
}

static inline void ov006_TaskD0_HideWindows(ov006_TaskD0 *self) {
    if (self->unk110) {
        self->unk10C->flags |= 2;
        return;
    }
    self->unk104->flags |= 2;
    self->unk108->flags |= 2;
}

static inline void ov006_TaskD0_Close(ov006_TaskD0 *self) {
    self->unk_04 |= 6;
    self->unk_04_0 = 1;
}

void ov006_GroupSelect_UpdateActive(ov006_TaskD0 *self) {
    u16 trg = gPad->trig;
    if (self->unk110) {
        if (trg & 1) {
            ov006_TaskD0_Close(self);
            ov006_TaskD0_HideWindows(self);
        }
    } else if (trg & 2) {
        self->subStep = 0;
        self->unk104->flags &= ~0x2000000;
        ov006_TaskD0_Close(self);
        ov006_TaskD0_HideWindows(self);
        ov006_Menu_RequestShutdown(gOv006Menu);
    } else if (trg & 1) {
        UiListItem *node = UiList_GetCurrent(self->unk104);
        if (node->unk_10 == 0) {
            if (node->id == 4) {
                func_ov006_021e4cb4(gOv006Menu);
                gOv006Menu->unk15E = 2;
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
                ov006_TaskD0_Close(self);
                self->subStep = 2;
                ov006_TaskD0_HideWindows(self);
            } else {
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            }
        } else if (node->unk_0c >= 4) {
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
        } else {
            ov006_MenuNode *menu = ov006_Menu_FindNode(gOv006Menu, node->unk_10);
            if (menu != NULL) {
                func_ov006_021e4ce8(gOv006Menu, &menu->data);
                gOv006Menu->unk15E = 2;
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
                self->subStep = 1;
                ov006_TaskD0_Close(self);
                ov006_TaskD0_HideWindows(self);
            } else {
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
                ov006_GroupSelect_RefreshList(self);
            }
        }
    }
}

void ov006_GroupSelect_PreUpdate(ov006_TaskD0 *self) {
    if (self->unk110) {
        self->unk10C->vfunc_1c();
        return;
    }
    if (!gOv006Menu->unk2C && gOv006Menu->unk26) {
        ov006_GroupSelect_RefreshList(self);
        gOv006Menu->unk26 = 0;
    }
    self->unk104->vfunc_1c();
    self->unk108->vfunc_1c();
}

void ov006_GroupSelect_PostUpdate(ov006_TaskD0 *self) {
    if (self->state != 0) {
        return;
    }
    if (self->subStep == 3) {
        return;
    }
    switch (self->subStep) {
    case 0:
        TaskHost_RequestSwitch(gTaskHost, 0x26, 0);
        break;
    case 1:
        TaskHost_RequestSwitch(gTaskHost, 0x28, 2);
        break;
    case 2:
        TaskHost_RequestSwitch(gTaskHost, 0x28, 1);
        break;
    }
    self->subStep = 3;
}

void ov006_GroupSelect_Draw(ov006_TaskD0 *self) {
    if (!self->vfunc_28()) {
        return;
    }
    if (self->unk110) {
        self->unk10C->vfunc_20();
        return;
    }
    self->unk104->vfunc_20();
    self->unk108->vfunc_20();
    if (gOv006Menu != NULL) {
        ov006_Menu_ReleaseObj(gOv006Menu);
    }
}

void ov006_GroupSelect_RefreshList(ov006_TaskD0 *self) {
    u16 j;
    UiListItem *item;
    int id;
    u16 i;
    ov006_MenuNode *node;
    int ids[4];
    if (self->unk104 == NULL) {
        return;
    }
    i = 0;
    MIi_CpuClear32(0, ids, sizeof(ids));
    for (node = gOv006Menu->nodes; node != NULL; node = node->next) {
        ids[i] = node->id;
        i++;
        if (i >= 4) {
            break;
        }
    }
    for (j = 0; j < 4; j++) {
        u32 v;
        item = UiList_GetItemById(self->unk104, j);
        id = ids[j];
        if (id != 0) {
            int srcLen;
            int dstLen;
            ov006_MenuNode *menu = ov006_Menu_FindNode(gOv006Menu, id);
            srcLen = 0xb;
            dstLen = 0x30;
            Str_Utf16ToUtf8Filtered(self->names[j], &dstLen, (u8 *)menu + 0x60, &srcLen);
            v = ((u8 *)menu)[0x77];
        } else {
            STD_CopyLString(self->names[j], data_ov006_021ebbac, 0x30);
            v = 0;
        }
        item->unk_0c = v;
        item->unk_10 = id;
        item->unk_24 = v < 4 ? 0 : 0xe;
        item->name = NULL;
        OV006_DELETE_OBJECT(item->label);
        item->name = self->names[j];
        Obj02153c48_CreateText(item, 8, 0, 1, 1);
    }
}

static inline void ov006_SlotPacked_Clear(ov006_SlotPacked *self) {
    self->active = 0;
    self->isType1 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk0_8 = 0;
    MI_CpuFill8(self->name, 0, sizeof(self->name));
}

static inline void ov006_TaskD0C_Init(ov006_TaskD0C *self) {
    OV006_TASKBASE_CTOR(self);
    *(void **)self = &ov006_EntryWait_vtbl;
    self->unk3C = 0;
    self->unk3D = 0;
    self->unk40 = 0;
    MI_CpuFill8(self->names, 0, sizeof(self->names));
    self->unk101 = 0;
    ov006_SlotPacked_Clear(&self->unk102);
    self->unk11C = NULL;
    self->unk120 = NULL;
    self->unk124 = NULL;
}

ov006_TaskD0C *ov006_EntryWait_New(void) {
    ov006_TaskD0C *self = (ov006_TaskD0C *)Heap_Alloc(sizeof(ov006_TaskD0C));
    if (self != NULL) {
        ov006_TaskD0C_Init(self);
    }
    self->vfunc_08(0x28, 200);
    return self;
}

static inline void ov006_TaskD0C_Dtor(ov006_TaskD0C *self) {
    *(void **)self = &ov006_EntryWait_vtbl;
    OV006_DELETE_OBJECT(self->unk11C);
    OV006_DELETE_OBJECT(self->unk120);
    OV006_DELETE_OBJECT(self->unk124);
    OV006_TASKBASE_DTOR(self);
}

ov006_TaskD0C *ov006_EntryWait_Dtor_021d0d3c(ov006_TaskD0C *self) {
    ov006_TaskD0C_Dtor(self);
    return self;
}

ov006_TaskD0C *ov006_EntryWait_DtorDelete(ov006_TaskD0C *self) {
    ov006_TaskD0C_Dtor(self);
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021d01ac

// ---- merged from ov006_021d0f44.cpp
namespace m_021d0f44 {

extern "C" {

void ov006_EntryWait_Load(void) {
}

BOOL ov006_EntryWait_IsLoaded(void) {
    return TRUE;
}

extern void *gMsgRes;
extern void *UiObj_vtbl;
extern void *Lo021cad50_vtbl;
extern void *UiList_vtbl;
extern void *UiList021cb4a8_vtbl;
extern void *Lo021cadcc_vtbl;
extern u8 *gWhMgr;

void *MsgRes_GetString(void *a, int id);
void TaskList_Insert(Task *self);
void ov006_SlotManager_Reset_021daea0(ov006_SlotManager *a);
BOOL ov006_SlotManager_HasItem(ov006_SlotManager *a, int b);
u32 ov006_CopyOwnerInfo(void *a, int b);
void ov006_Menu_SetOwnEntry(ov006_Menu *self, u16 a, int b, const void *src, u32 size);

static inline void ov006_SlotPacked_Clear(ov006_SlotPacked *self) {
    self->active = 0;
    self->isType1 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk0_8 = 0;
    MI_CpuFill8(self->name, 0, sizeof(self->name));
}

static inline void *ov006_GetRes(void) {
    return gMsgRes;
}

void ov006_EntryWait_Start(ov006_TaskD0C *self) {
    u16 i;
    void *res;
    if (self->vfunc_28()) {
        return;
    }
    res = ov006_GetRes();
    self->unk11C = ov006_NewUiList021cb4a8();
    self->unk11C->vfunc_10(MsgRes_GetString(res, 0x133));
    self->unk11C->vfunc_14(MsgRes_GetString(res, 0x134));
    UiList021cb4a8_SetLabel(self->unk11C, MsgRes_GetString(res, 0x135));
    UiList021cb4a8_SetCenteredLabel(self->unk11C, MsgRes_GetString(res, 0x136));
    self->unk11C->unk_4a = 0x2c00;
    self->unk11C->rows = 4;
    ov006_Window_SetPos(self->unk11C, 0, 0x2c, -0x1ccd);
    ov006_Window_SetSlide(self->unk11C, -0x100, 0, -0x1ccd);
    self->unk11C->flags |= 0x400000;
    self->unk11C->flags &= ~0x800000;
    self->unk11C->unk_c0 = 0x8c;
    self->unk11C->unk_c1 = 1;
    self->unk11C->flags &= ~0x20000;
    self->unk11C->flags &= ~0x40000;
    self->unk11C->flags &= ~0x10000;
    self->unk11C->flags |= 4;
    for (i = 0; i < 4; i++) {
        self->unk11C->vfunc_74(" ", i, 0xffff, 0xffff);
    }
    self->unk11C->flags &= ~0x2000000;
    self->unk11C->vfunc_a8(0);
    self->unk11C->vfunc_08();
    self->unk11C->flags &= ~2;
    self->unk120 = ov006_NewLo021cadcc();
    self->unk120->width = 0xf8;
    self->unk120->rows = 2;
    ov006_Window_SetPos(self->unk120, 4, 0x95, -0x199a);
    ov006_Window_SetSlide(self->unk120, -0x100, 0, -0x199a);
    self->unk120->slideMode = 1;
    self->unk120->vfunc_08();
    Obj0215bb14_SetText(self->unk120, MsgRes_GetString(res, 0x138));
    self->unk120->vfunc_70();
    self->unk124 = ov006_NewLo021cad50();
    self->unk124->flags |= 0x10000;
    self->unk124->flags |= 0x20000;
    self->unk124->flags |= 2;
    Obj0215c1bc_SetText(self->unk124, 0x8000, MsgRes_GetString(res, 0x198));
    ov006_SlotManager_Reset_021daea0(gOv006SlotManager);
    gOv006Manager->unk1C = 1;
    MI_CpuFill8(gWhMgr + 0x18e0, 0, 0x200);
    ov006_SlotPacked_Clear(&self->unk102);
    ov006_CopyOwnerInfo(self->unk102.name, sizeof(self->unk102.name));
    self->unk102.active = 1;
    self->unk102.isType1 = 1;
    self->unk102.unkC = 0;
    self->unk102.unk10 = 0;
    if (ov006_SlotManager_HasItem(gOv006SlotManager, 9)) {
        self->unk102.unk10 = 1;
    } else if (ov006_SlotManager_HasItem(gOv006SlotManager, 10)) {
        self->unk102.unk10 = 2;
    }
    ov006_Menu_SetOwnEntry(gOv006Menu, self->unk101, 1, &self->unk102, 0x18);
    if (self->param == 1) {
        self->unk101 = 0;
    } else {
        self->unk101 = 1;
    }
    self->fadeLen = self->unk11C->openLen;
    self->unk_04 &= ~2;
    TaskList_Insert(self);
}

}
}  // namespace m_021d0f44

// ---- merged from ov006_021d1490.cpp
namespace m_021d1490 {

extern "C" {

extern void *gMsgRes;

u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask);
void ov006_Menu_SetOwnEntry(ov006_Menu *self, u16 a, int b, const void *src, u32 size);
void ov006_UpdateNetSlots(void);
void ov006_EntryWait_RefreshSlots(ov006_TaskD0C *self);
void *MsgRes_GetString(void *a, int id);

void ov006_EntryWait_UpdateActive(ov006_TaskD0C *self) {
    u16 trg = gPad->trig;
    if (self->unk3C) {
        return;
    }
    if (trg & 2) {
        if (self->param == 2 && ov006_Menu_GetEntryMask_021e60e8(1, 1)) {
            return;
        }
        self->unk3C = 0x32;
        return;
    }
    if (!(trg & 1)) {
        return;
    }
    if (self->param != 1) {
        return;
    }
    if (self->unk40 < 2) {
        return;
    }
    if (gOv006SlotManager->numActive >= 2) {
        self->unk3C = 5;
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
}

void ov006_EntryWait_PreUpdate(ov006_TaskD0C *self) {
    if (self->state == 9 || self->state == 0xd) {
        if (gOv006Menu->state != 9) {
            u8 n;
            ov006_Menu_SetOwnEntry(gOv006Menu, self->unk101, 1, &self->unk102, 0x18);
            ov006_UpdateNetSlots();
            n = gOv006SlotManager->numActive;
            if (self->unk40 != n) {
                ov006_EntryWait_RefreshSlots(self);
                if (self->param == 1) {
                    void *res = gMsgRes;
                    if (self->unk40 <= 1 && n >= 2) {
                        Obj0215bb14_SetText(self->unk120, MsgRes_GetString(res, 0x137));
                        self->unk120->vfunc_70();
                    } else if (self->unk40 >= 2 && n <= 1) {
                        Obj0215bb14_SetText(self->unk120, MsgRes_GetString(res, 0x138));
                        self->unk120->vfunc_70();
                    }
                }
                self->unk40 = n;
            }
        }
    }
    self->unk11C->vfunc_1c();
    self->unk120->vfunc_1c();
    self->unk124->vfunc_1c();
}

}
}  // namespace m_021d1490

// ---- merged from ov006_021d1694.cpp
namespace m_021d1694 {

extern "C" {

void ov006_EntryWait_UpdateSeq(ov006_TaskD0C *self);

void ov006_EntryWait_PostUpdate(ov006_TaskD0C *self) {
    ov006_EntryWait_UpdateSeq(self);
}

}
}  // namespace m_021d1694

// ---- merged from ov006_021d16a0.cpp
namespace m_021d16a0 {

extern "C" {

extern void *gMsgRes;
extern u8 gTaskSwitchPending;

u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask);
BOOL func_ov006_021e4bec(ov006_Menu *self, int a);
BOOL ov006_Menu_RequestShutdown(ov006_Menu *self);
void ov006_Menu_ShowObj(ov006_Menu *self);
void *MsgRes_GetString(void *a, int id);

static inline void ov006_TaskD0C_ShowAll(ov006_TaskD0C *self) {
    self->unk11C->flags &= ~0x2000000;
    self->unk11C->flags |= 2;
    self->unk120->flags |= 2;
    self->unk124->flags |= 2;
}

static inline u8 ov006_SlotManager_MinUnk10(void) {
    u8 i;
    u8 mn;
    mn = 0;
    for (i = 0; i < gOv006SlotManager->numActive; i++) {
        ov006_Slot *slot = ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, i);
        u8 v;
        if (slot == NULL) {
            continue;
        }
        v = slot->unk10;
        if (v == 0) {
            continue;
        }
        if (mn == 0 || mn > v) {
            mn = v;
        }
    }
    return mn;
}

// The original reloads gOv006SlotManager after every block, so this function is built without CSE
#pragma opt_common_subs off
void ov006_EntryWait_UpdateSeq(ov006_TaskD0C *self) {
    switch (self->unk3C) {
    case 0:
        if (gOv006Menu->state == 9) {
            gTaskSwitchPending = 1;
            self->unk11C->flags |= 4;
            self->unk120->flags |= 4;
            self->unk3C = 30;
        }
        if (self->param != 2) {
            return;
        }
        if (!ov006_Menu_GetEntryMask_021e60e8(1, 1)) {
            return;
        }
        self->unk3C = 5;
    case 5:
        self->unk101 = 1;
        func_ov006_021e4bec(gOv006Menu, 0);
        self->unk3C = 10;
        ov006_TaskD0C_ShowAll(self);
        break;
    case 10: {
        u8 mn = ov006_SlotManager_MinUnk10();
        if (mn == 0) {
            self->unk3C = 20;
            return;
        }
        if (mn == 1) {
            gOv006SlotManager->items[0] = 9;
        } else if (mn == 2) {
            gOv006SlotManager->items[0] = 10;
            Obj0215c1bc_SetText(self->unk124, 0x8000, MsgRes_GetString(gMsgRes, 0x199));
        }
        self->unk124->vfunc_70();
        self->unk124->flags &= ~2;
        *(u16 *)self->unk3E = 0;
        SndMgr_PlayVolume(gSndMgr, 0x26, -1, -1, -1);
        self->unk3C++;
        break;
    }
    case 11:
        if (gOv006Menu->state == 9) {
            self->unk124->flags |= 2;
            self->unk3C = 30;
            return;
        }
        if ((*(u16 *)self->unk3E)++ > 0xb4) {
            self->unk3C = 20;
        }
        break;
    case 20:
        if (gOv006Menu->state == 9) {
            self->unk3C = 30;
            return;
        }
        if (!self->vfunc_54()) {
            return;
        }
        GfxSys_StartFadeOut(0x14000, 0, 0);
        GfxSys_StartFadeOut(0x14000, 0, 1);
        self->fadeLen = 0x50000;
        self->unk3C = 60;
        break;
    case 30:
        ov006_Menu_ShowObj(gOv006Menu);
        self->unk3C++;
    case 31:
        if (gOv006Menu->state != 9) {
            self->unk3C = 50;
        }
        break;
    case 50:
        ov006_TaskD0C_ShowAll(self);
        self->unk_04 |= 6;
        TaskHost_RequestSwitch(gTaskHost, 0x26, 0);
        ov006_Menu_RequestShutdown(gOv006Menu);
        self->unk3C = 70;
        break;
    case 60:
        ov006_TaskD0C_ShowAll(self);
        self->unk_04 |= 6;
        TaskHost_RequestSwitch(gTaskHost, 0x29, self->param);
        self->unk3C = 70;
        break;
    }
}

#pragma opt_common_subs reset
}
}  // namespace m_021d16a0

// ---- merged from ov006_021d1b24.cpp
namespace m_021d1b24 {

typedef struct ov006_Unk020706a0 {
    u8 unk0[4];
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
} ov006_Unk020706a0;

extern "C" {

extern void *gMsgRes;
extern const int data_ov006_021eb77c[];
extern const u8 data_ov006_021eb6fe[4];
extern const u8 data_ov006_021eb710[][3];
extern const u16 data_ov006_021eb78c[];
extern void *ov006_CraftSelect_vtbl;

void ov006_Menu_ReleaseObj(ov006_Menu *self);
void Str_Utf16ToUtf8Filtered(void *dst, int *dstLen, const void *src, int *srcLen);
void *MsgRes_GetString(void *a, int id);
void ov006_CraftSelect_ShowCraft(ov006_TaskD1F *self, u16 id, BOOL dir);
ov006_Unk020706a0 *Tbl_Elem_020706a0(u16 id);
void ov006_Gauge_SetRatio(ov006_Gauge *self, int a, int b, u8 c);
ov006_TaskD1F *ov006_CraftSelect_Ctor(ov006_TaskD1F *self);

void ov006_EntryWait_Draw(ov006_TaskD0C *self) {
    if (!self->vfunc_28()) {
        return;
    }
    self->unk11C->vfunc_20();
    self->unk120->vfunc_20();
    self->unk124->vfunc_20();
    if (gOv006Menu != NULL) {
        ov006_Menu_ReleaseObj(gOv006Menu);
    }
}

static inline bool ov006_Window_Bit1(UiList *self) {
    return (self->flags << 30) >> 31;
}

static inline BOOL ov006_Window_IsBit1(UiList *self) {
    return ov006_Window_Bit1(self) ? TRUE : FALSE;
}

void ov006_EntryWait_RefreshSlots(ov006_TaskD0C *self) {
    u8 i;
    ov006_Slot *slot;
    UiListItem *item;
    for (i = 0; i < 4; i++) {
        slot = ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, i);
        item = (UiListItem *)UiList_GetItemById(self->unk11C, i);
        if (slot->active) {
            int srcLen = 0xb;
            int dstLen = 0x30;
            Str_Utf16ToUtf8Filtered(self->names[i], &dstLen, slot->name, &srcLen);
            OV006_LISTNODE_SETTEXT(item, self->names[i]);
            item->unk_24 = data_ov006_021eb77c[i];
            Obj02153c48_CreateText(item, 8, 0, 1, 1);
            item->unk_0c = (u16)(i + 1);
            if (i == gOv006SlotManager->unk5) {
                UiList *w = self->unk11C;
                if (!(ov006_Window_IsBit1(w) ? TRUE : FALSE)) {
                    w->flags |= 0x2000000;
                }
                self->unk11C->vfunc_a8(item);
                UiList_SetPanelColor(self->unk11C, data_ov006_021eb6fe[i]);
                {
                    const u8 *c = data_ov006_021eb710[i];
                    self->unk11C->color = c[0] | (c[1] << 5) | (c[2] << 10);
                }
            }
        } else {
            OV006_LISTNODE_SETTEXT(item, data_ov006_021ebbac);
            item->unk_24 = 0;
            Obj02153c48_CreateText(item, 8, 0, 0, 0);
            item->unk_0c = 0xffff;
        }
    }
}

ov006_TaskD1F *ov006_CraftSelect_New(void) {
    ov006_TaskD1F *obj = (ov006_TaskD1F *)Heap_Alloc(sizeof(ov006_TaskD1F));
    if (obj != NULL) {
        obj = ov006_CraftSelect_Ctor(obj);
    }
    obj->vfunc_08(0x29, 0xc8);
    return obj;
}

BOOL ov006_CraftSelect_List54OnCursor(UiList *window, UiListItem *node) {
    ov006_TaskD1F *t;
    u16 id;
    u16 old;
    const void *str;
    ov006_Unk020706a0 *p;
    if (node != NULL) {
        id = node->id;
        t = (ov006_TaskD1F *)window->owner;
        old = t->unk4A;
        t->unk4A = id;
        str = MsgRes_GetString(gMsgRes, data_ov006_021eb78c[(u16)(id & 0xfff)]);
        if (t->unk5C != NULL && str != NULL) {
            Obj0215bb14_SetText(t->unk5C, str);
            t->unk5C->vfunc_70();
        }
        ov006_CraftSelect_ShowCraft(t, id, old > id);
        p = Tbl_Elem_020706a0(id);
        ov006_Gauge_SetRatio(t->gauges[0], p->unk4 << 12, 0xa000, 1);
        ov006_Gauge_SetRatio(t->gauges[1], p->unk5 << 12, 0xa000, 1);
        ov006_Gauge_SetRatio(t->gauges[2], p->unk6 << 12, 0xa000, 1);
        ov006_Gauge_SetRatio(t->gauges[3], p->unk7 << 12, 0xa000, 1);
    }
    return TRUE;
}

BOOL ov006_ListCb_StoreId(UiList *window, UiListItem *node) {
    int *out = (int *)window->owner;
    if (node != NULL) {
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
        *out = node->id;
    } else {
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        *out = -1;
    }
    return FALSE;
}

ov006_TaskD1F *ov006_CraftSelect_Ctor(ov006_TaskD1F *self) {
    ov006_Slot *slot;
    OV006_TASKBASE_CTOR(self);
    *(void **)self = &ov006_CraftSelect_vtbl;
    self->step = 0;
    self->subStep = 0;
    self->unk44 = 0;
    self->unk48 = 1;
    self->unk49 = 0;
    self->unk4A = 0xffff;
    slot = ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5);
    if (slot != NULL) {
        self->unk4A = slot->unkC;
    }
    self->unk4C = 0;
    self->unk50 = 0;
    self->unk54 = NULL;
    self->unk58 = NULL;
    self->unk5C = NULL;
    self->unk60 = NULL;
    self->unk64 = NULL;
    return self;
}

static inline void ov006_TaskD1F_Dtor(ov006_TaskD1F *self) {
    int i;
    *(void **)self = &ov006_CraftSelect_vtbl;
    OV006_DELETE_OBJECT(self->unk54);
    OV006_DELETE_OBJECT(self->unk58);
    OV006_DELETE_OBJECT(self->unk5C);
    OV006_DELETE_OBJECT(self->unk60);
    OV006_DELETE_OBJECT(self->unk64);
    OV006_DELETE_OBJECT(self->unk68);
    for (i = 0; i < 4; i++) {
        OV006_DELETE_OBJECT(self->gauges[i]);
    }
    OV006_TASKBASE_DTOR(self);
}

ov006_TaskD1F *ov006_CraftSelect_Dtor_021d2000(ov006_TaskD1F *self) {
    ov006_TaskD1F_Dtor(self);
    return self;
}

ov006_TaskD1F *ov006_CraftSelect_DtorDelete(ov006_TaskD1F *self) {
    ov006_TaskD1F_Dtor(self);
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021d1b24
