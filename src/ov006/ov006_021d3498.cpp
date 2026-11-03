// One source file for 0x021d3498..0x021d54b0. Its functions share the string pool at
// 0x021ebc04 (@stringBase0), so they have to be compiled together. The former files are
// kept as they were, each in its own namespace, so that their local typedefs, inlines
// and extern declarations do not clash.
#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/Tasks.h"
#include "ov006/ov006.h"
#include "ov006/SlotManager.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Math/Rot16.h"

// ---- merged from ov006_021d3498.cpp
namespace m_021d3498 {

typedef struct ov006_Chr021d3498 {
    u8 unk0[0x6ec];
    ov006_Vec32 unk6EC;
    ov006_Vec32 unk6F8;
} ov006_Chr021d3498;

typedef struct ov006_Task021d3498 {
    u8 unk0[0x58];
    ov006_Chr021d3498 *unk58;
} ov006_Task021d3498;

extern "C" {

extern const ov006_Vec32 data_ov006_021eb74c;
extern const ov006_Vec32 data_ov006_021eb758;

void VEC_Normalize(const ov006_Vec32 *src, ov006_Vec32 *dst);
const char *Tbl_GetResFile(u16 id);
const char *func_020701d4(u16 id);
s16 *Tbl_Elem_020706a0(u16 id);
void ModelViewer_SetModel(ov006_Chr021d3498 *chr, const char *a, const char *b, const char *c, const char *d,
                         const char *e, int f, int g);

static inline void ov006_Chr_SetVec(ov006_Vec32 *dst, const ov006_Vec32 *src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

#define OV006_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_ov006_021d3498(ov006_Task021d3498 *self, u16 id, BOOL flag) {
    const char *a;
    const char *b;
    const char *c;
    const char *d;
    if (self->unk58 == NULL) {
        return;
    }
    a = Tbl_GetResFile(id);
    b = func_020701d4(id);
    c = Tbl_GetResFile(id);
    d = func_020701d4(id);
    if (flag) {
        ov006_Vec32 v;
        VEC_Normalize(&data_ov006_021eb758, &v);
        v.x = OV006_FX_MUL(v.x, 0x3000);
        v.y = OV006_FX_MUL(v.y, 0x3000);
        v.z = OV006_FX_MUL(v.z, 0x3000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6F8.x = v.x;
            chr->unk6F8.y = v.y;
            chr->unk6F8.z = v.z;
        }
        VEC_Normalize(&data_ov006_021eb74c, &v);
        v.x = OV006_FX_MUL(v.x, 0x2000);
        v.y = OV006_FX_MUL(v.y, 0x2000);
        v.z = OV006_FX_MUL(v.z, 0x2000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6EC.x = v.x;
            chr->unk6EC.y = v.y;
            chr->unk6EC.z = v.z;
        }
    } else {
        ov006_Vec32 v;
        VEC_Normalize(&data_ov006_021eb74c, &v);
        v.x = OV006_FX_MUL(v.x, 0x2000);
        v.y = OV006_FX_MUL(v.y, 0x2000);
        v.z = OV006_FX_MUL(v.z, 0x2000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6F8.x = v.x;
            chr->unk6F8.y = v.y;
            chr->unk6F8.z = v.z;
        }
        VEC_Normalize(&data_ov006_021eb758, &v);
        v.x = OV006_FX_MUL(v.x, 0x3000);
        v.y = OV006_FX_MUL(v.y, 0x3000);
        v.z = OV006_FX_MUL(v.z, 0x3000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6EC.x = v.x;
            chr->unk6EC.y = v.y;
            chr->unk6EC.z = v.z;
        }
    }
    {
        s16 g = *Tbl_Elem_020706a0(id);
        ModelViewer_SetModel(self->unk58, a, b, c, d, "nut00", 0, g);
    }
}

}
}  // namespace m_021d3498
#undef OV006_FX_MUL

// ---- merged from ov006_021d3794.cpp
namespace m_021d3794 {

extern "C" {

ov006_TaskD37 *func_ov006_021d3874(ov006_TaskD37 *self);

ov006_TaskD37 *ov006_TaskD37_New(void) {
    ov006_TaskD37 *obj = (ov006_TaskD37 *)Heap_Alloc(sizeof(ov006_TaskD37));
    if (obj != NULL) {
        obj = func_ov006_021d3874(obj);
    }
    obj->vfunc_08(0x2a, 0xc8);
    return obj;
}

}
}  // namespace m_021d3794

// ---- merged from ov006_021d37d0.cpp
namespace m_021d37d0 {

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

extern "C" {

extern void *ov006_TaskD37_vtbl;

ov006_Info021daaa8 *ov006_GetCourseInfo(u16 id);
const void *func_0206ec8c(u16 id);
const void *Param_Get(u16 id);
void ov006_Label_Set_021dbfb8(ov006_Label *a, const char *b, int c, int d);
void ov006_Unk021e1ddc_SetLabel(ov006_Obj13C *a, const char *b, int c, int d);
void ov006_Unk021e1e6c_PlayText(ov006_Obj13C *a, const void *b);
ActorRes *ResSet_ReleaseAll(ActorRes *self);
Camera *Camera_Ctor(Camera *cam);
void func_0204b420(Camera *cam);
Model0218fe1c *Model0218fe1c_FreeAnims(Model0218fe1c *self);
ActorRes *ResSet_Init(ActorRes *self);
void ResMgr_ReleaseArchive(const char *a, const char *b, int c);
const char *Tbl_GetResFile(u16 id);
const char *func_020701d4(u16 id);
int ResSet_UpdateLoad(ActorRes *self);

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = ov006_GetCourseInfo(id);
    if (self->param != 2) {
        Obj0215bb14_SetText(self->unk54, func_0206ec8c(id));
        self->unk54->vfunc_70();
    }
    ov006_Label_Set_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    ov006_Unk021e1ddc_SetLabel(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    ov006_Unk021e1e6c_PlayText(self->unk13C, Param_Get(id));
}

BOOL func_ov006_021d37d0(UiList *window, UiListItem *node) {
    if (node != NULL) {
        ov006_TaskD37 *t;
        u16 id;
        id = node->id;
        t = (ov006_TaskD37 *)window->owner;
        ov006_TaskD37_Select(t, id);
    }
    return TRUE;
}

ov006_TaskD37 *func_ov006_021d3874(ov006_TaskD37 *self) {
    OV006_TASKBASE_CTOR(self);
    *(void **)self = &ov006_TaskD37_vtbl;
    Camera_Ctor(&self->cam);
    self->step = 0;
    self->unk44 = 0;
    self->unk46 = 0;
    self->unk48 = 0;
    self->unk3D = 1;
    self->unk4C = self->unk4A = gOv006SlotManager->unk6;
    self->unk50 = NULL;
    self->unk54 = NULL;
    self->unk58 = NULL;
    self->unk5C = NULL;
    self->unk60 = NULL;
    self->unk64 = NULL;
    self->unk68 = NULL;
    self->unk6C = NULL;
    self->unk70 = NULL;
    self->anm = NULL;
    self->unk138 = NULL;
    self->unk13C = NULL;
    return self;
}

#define OV006_DELETE_WITH(T, obj, dtor)                          \
    do {                                                         \
        void *saved_ = gSysState->cur;                       \
        gSysState->cur = gSysState->heapHi;              \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                T *p_ = (obj);                                   \
                dtor(p_);                                        \
                Heap_Free(p_);                                   \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        gSysState->cur = saved_;                             \
    } while (0)

static inline void ov006_TaskD37_Dtor(ov006_TaskD37 *self) {
    *(void **)self = &ov006_TaskD37_vtbl;
    OV006_DELETE_OBJECT(self->unk50);
    OV006_DELETE_OBJECT(self->unk54);
    OV006_DELETE_OBJECT(self->unk58);
    OV006_DELETE_OBJECT(self->unk5C);
    OV006_DELETE_WITH(ActorRes, self->unk60, ResSet_ReleaseAll);
    OV006_DELETE_WITH(Model0218fe1c, self->unk64, Model0218fe1c_FreeAnims);
    OV006_DELETE_WITH(ActorRes, self->unk68, ResSet_ReleaseAll);
    OV006_DELETE_WITH(Model0218fe1c, self->unk6C, Model0218fe1c_FreeAnims);
    OV006_DELETE_WITH(ActorRes, self->unk70, ResSet_ReleaseAll);
    if (self->anm != NULL) {
        Heap_FreeHi(self->anm);
        self->anm = NULL;
    }
    OV006_DELETE_OBJECT(self->unk138);
    OV006_DELETE_OBJECT(self->unk13C);
    ResMgr_ReleaseArchive("ac/c1dum1", "c1dum1", 6);
    func_0204b420(&self->cam);
    OV006_TASKBASE_DTOR(self);
}

ov006_TaskD37 *ov006_TaskD37_Dtor_021d3914(ov006_TaskD37 *self) {
    ov006_TaskD37_Dtor(self);
    return self;
}

ov006_TaskD37 *ov006_TaskD37_DtorDelete(ov006_TaskD37 *self) {
    ov006_TaskD37_Dtor(self);
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021d37d0
#undef OV006_DELETE_WITH

// ---- merged from ov006_021d3f04.cpp
namespace m_021d3f04 {


extern "C" {


ActorRes *ResSet_Init(ActorRes *self);
const char *Tbl_GetResFile(u16 id);
const char *func_020701d4(u16 id);

static inline ActorRes *ov006_NewModel60(void) {
    ActorRes *p = (ActorRes *)Heap_Alloc(sizeof(ActorRes));
    if (p != NULL) {
        p = ResSet_Init(p);
    }
    return p;
}

static inline void ActorRes_SetName1(ActorRes *m, const char *a, const char *b) {
    STD_CopyString(m->unk_10, a);
    STD_CopyString(m->unk_30, b);
    m->unk_03_1 = 1;
}

static inline void ActorRes_SetName2(ActorRes *m, const char *a, const char *b) {
    STD_CopyString(m->unk_4c, a);
    STD_CopyString(m->unk_6c, b);
    m->unk_03_2 = 1;
}

void ov006_TaskD37_Load(ov006_TaskD37 *self) {
    ActorRes *m;
    u16 id;
    const char *a;
    const char *b;
    const char *c;
    const char *d;
    m = ov006_NewModel60();
    self->unk60 = m;
    ActorRes_SetName1(m, "menu/worldmap", "u3map1cld00");
    ActorRes_SetName2(self->unk60, "menu/worldmap", "u3map1cld00");
    self->unk60->unk_00 = 0;
    self->unk68 = ov006_NewModel60();
    id = ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5)->unkC;
    a = Tbl_GetResFile(id);
    b = func_020701d4(id);
    c = Tbl_GetResFile(id);
    d = func_020701d4(id);
    ActorRes_SetName1(self->unk68, a, b);
    ActorRes_SetName2(self->unk68, c, d);
    self->unk68->unk_00 = 0;
    m = ov006_NewModel60();
    self->unk70 = m;
    ActorRes_SetName2(m, "ac/c1dum1", "c1dum1");
    self->unk70->unk_00 = 0;
}

}
}  // namespace m_021d3f04

// ---- merged from ov006_021d40a8.cpp
namespace m_021d40a8 {

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

extern "C" {

extern void *ov006_TaskD37_vtbl;

ov006_Info021daaa8 *ov006_GetCourseInfo(u16 id);
const void *func_0206ec8c(u16 id);
const void *Param_Get(u16 id);
void ov006_Label_Set_021dbfb8(ov006_Label *a, const char *b, int c, int d);
void ov006_Unk021e1ddc_SetLabel(ov006_Obj13C *a, const char *b, int c, int d);
void ov006_Unk021e1e6c_PlayText(ov006_Obj13C *a, const void *b);
ActorRes *ResSet_ReleaseAll(ActorRes *self);
Camera *Camera_Ctor(Camera *cam);
void func_0204b420(Camera *cam);
Model0218fe1c *Model0218fe1c_FreeAnims(Model0218fe1c *self);
ActorRes *ResSet_Init(ActorRes *self);
void ResMgr_ReleaseArchive(const char *a, const char *b, int c);
const char *Tbl_GetResFile(u16 id);
const char *func_020701d4(u16 id);
int ResSet_UpdateLoad(ActorRes *self);

BOOL ov006_TaskD37_IsLoaded(ov006_TaskD37 *self) {
    BOOL r = TRUE;
    if (self->unk60->unk_00 >= 0) {
        r = (r & ResSet_UpdateLoad(self->unk60)) ? TRUE : FALSE;
    }
    if (self->unk68->unk_00 >= 0) {
        r = (r & ResSet_UpdateLoad(self->unk68)) ? TRUE : FALSE;
    }
    if (self->unk70->unk_00 >= 0) {
        r = (r & ResSet_UpdateLoad(self->unk70)) ? TRUE : FALSE;
    }
    return r;
}

}
}  // namespace m_021d40a8

// ---- merged from ov006_021d4118.cpp
namespace m_021d4118 {


typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk020706a0 {
    s16 unk0;
} ov006_Unk020706a0;

extern "C" {

extern void *gMsgRes;
extern const u16 data_ov006_021eb6fc;
extern const u8 data_ov006_021eb6fe[4];
extern const Rot16 data_ov006_021eb702;
extern const VecFx32 data_ov006_021eb764;
extern const VecFx32 data_ov006_021eb734;

const u16 data_ov006_021eb6fc = 0x1000;
const u8 data_ov006_021eb6fe[4] = {0, 1, 3, 2};
const Rot16 data_ov006_021eb702 = {0xfa80, 0x8200, 0};

void *MsgRes_GetString(void *a, int id);
void ov006_Manager_DispatchMenuCb(int a, void *b, int c);
UiListItem *ListOwner_GetNth(UiList *self, int n);
BOOL func_ov006_021d37d0(UiList *window, UiListItem *node);
BOOL ov006_ListCb_StoreId(UiList *window, UiListItem *node);
ov006_Label *Ov006Vt_021ec2fc_Ctor(void *p);
Model0218fe1c *Model0218fe1c_Init(void *p);
BOOL Model0218fe1c_SetRes(Model0218fe1c *a, ActorRes *b, int c, int d);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, int c, int d);
void Model0218fe1c_SetLoop(void *a);
AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *a, int b);
void Model0218fe1c_SetAnimSpeed(void *a, int b);
ov006_Unk020706a0 *Tbl_Elem_020706a0(u16 id);
void ov006_TaskD37_PlayAnim(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop);
ov006_Caption *ov006_Caption_Ctor(ov006_Caption *self);
void ov006_Caption_Init_021e0954(ov006_Caption *self);
void ov006_TextHolder_Play_021e0ca8(ov006_Caption *self, void *text, int b);
ov006_Obj13C *Ov006Vt_021ec1fc_Ctor(ov006_Obj13C *self);
void ov006_Unk021e16b0_Load(ov006_Obj13C *p);
ov006_Info021daaa8 *ov006_GetCourseInfo(u16 id);
const void *func_0206ec8c(u16 id);
const void *Param_Get(u16 id);
void ov006_Label_Set_021dbfb8(ov006_Label *a, const char *b, int c, int d);
void ov006_Unk021e1ddc_SetLabel(ov006_Obj13C *a, const char *b, int c, int d);
void ov006_Unk021e1e6c_PlayText(ov006_Obj13C *a, const void *b);
void ov006_Menu_ClearEntries(ov006_Unk021ec888 *self);
void TaskList_Insert(Task *self);

static inline Model0218fe1c *ov006_NewModel64(void) {
    void *p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = Model0218fe1c_Init(p);
    }
    return (Model0218fe1c *)p;
}

static inline void ov006_SetPos3(ov006_Label *p, int x, int y, int z) {
    p->origin.x = x;
    p->origin.y = y;
    p->origin.z = z;
}

static inline void ov006_Obj13C_SetPair(ov006_Obj13C *o, int a, int b) {
    o->unk8 = a;
    o->unkC = b;
}

static inline void ov006_Caption_SetPos(ov006_Caption *c, int x, int y) {
    c->x = x;
    c->y = y;
}

static inline void ov006_Caption_SetTextPos(ov006_Caption *c, int x, int y) {
    c->textX = x;
    c->textY = y;
}

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = ov006_GetCourseInfo(id);
    if (self->param != 2) {
        Obj0215bb14_SetText(self->unk54, func_0206ec8c(id));
        self->unk54->vfunc_70();
    }
    ov006_Label_Set_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    ov006_Unk021e1ddc_SetLabel(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    ov006_Unk021e1e6c_PlayText(self->unk13C, Param_Get(id));
}

static inline void ov006_SetCam(ov006_TaskD37 *self, const VecFx32 *at, const VecFx32 *up, const Rot16 *rot, int dist) {
    self->cam.at = *at;
    self->cam.up = *up;
    self->cam.pitch = rot->x;
    self->cam.yaw = rot->y;
    self->cam.roll = rot->z;
    self->cam.dist = dist;
    self->cam.mode = 1;
}

// Message ids of the window texts, and the "no saved cursor" value of unk4A.
typedef enum { OV006_MSG_D4118_BODY = 0x12b } Ov006MsgD4118;
typedef enum { OV006_CURSOR_NONE = 0xffff } Ov006Cursor;

void ov006_TaskD37_Start(ov006_TaskD37 *self) {
    Ov006MsgD4118 body;
    Ov006Cursor none;
    void *res;
    ov006_Info021daaa8 *info;
    u16 id;
    if (self->vfunc_28()) {
        return;
    }
    res = gMsgRes;
    self->unk50 = ov006_NewUiList();
    self->unk50->vfunc_10(MsgRes_GetString(res, 0x12a));
    body = OV006_MSG_D4118_BODY;
    self->unk50->vfunc_14(MsgRes_GetString(res, body));
    self->unk50->unk_4a = 0x2c00;
    self->unk50->rows = 5;
    self->unk50->width = 0x9c;
    ov006_Window_SetPos(self->unk50, 0, 0x1e, -0x199a);
    self->unk50->posZ = -0x199a;
    ov006_Window_SetSlide(self->unk50, -0xff, 0, -0x199a);
    self->unk50->flags &= ~0x400000;
    self->unk50->flags &= ~0x800000;
    self->unk50->flags &= ~0x80000;
    self->unk50->flags &= ~0x20000;
    self->unk50->flags &= ~0x40000;
    self->unk50->flags &= ~0x10000;
    none = OV006_CURSOR_NONE;
    ov006_Manager_DispatchMenuCb(5, self->unk50, 0);
    self->unk50->vfunc_08();
    UiList_SetPanelColor(self->unk50, data_ov006_021eb6fe[gOv006SlotManager->unk5]);
    if (self->unk4A != none && self->param == 0) {
        UiList *w = self->unk50;
        w->vfunc_a8(UiList_GetItemById(w, self->unk4A));
    } else {
        UiList *w = self->unk50;
        w->vfunc_a8(ListOwner_GetNth(w, 0));
    }
    self->unk50->owner = self;
    self->unk50->onCursor = func_ov006_021d37d0;
    self->unk50->flags |= 4;
    self->unk54 = ov006_NewLo021cadcc();
    self->unk54->width = 0xf8;
    self->unk54->rows = 2;
    ov006_Window_SetPos(self->unk54, 4, 0x95, -0x199a);
    ov006_Window_SetSlide(self->unk54, -0x100, 0, -0x199a);
    self->unk54->slideMode = 1;
    self->unk54->vfunc_08();
    if (self->param == 2) {
        Obj0215bb14_SetText(self->unk54, MsgRes_GetString(res, 0x13f));
        self->unk54->vfunc_70();
    }
    {
        void *p = Heap_Alloc(0xec);
        if (p != NULL) {
            p = Ov006Vt_021ec2fc_Ctor(p);
        }
        self->unk58 = (ov006_Label *)p;
    }
    ov006_SetPos3(self->unk58, 0xbf000, 0x50000, self->unk58->origin.z);
    self->unk58->origin.z = -0x1fccd;
    self->unk64 = ov006_NewModel64();
    Model0218fe1c_SetRes(self->unk64, self->unk60, 0, 1);
    Model0218fe1c_SetAnim(self->unk64, "s00", 0, 1);
    self->unk64->actor_id = 0;
    Model0218fe1c_SetLoop(self->unk64);
    Model0218fe1c_GetAnimCtrl(self->unk64, 0)->speed = 0x400;
    self->unk6C = ov006_NewModel64();
    Model0218fe1c_SetRes(self->unk6C, self->unk68, 0, 1);
    Model0218fe1c_SetAnim(self->unk6C, "nut00", 0, 1);
    self->unk6C->actor_id = 0;
    Model0218fe1c_SetLoop(self->unk6C);
    Model0218fe1c_SetAnimSpeed(self->unk6C, Tbl_Elem_020706a0(ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5)->unkC)->unk0);
    ov006_TaskD37_PlayAnim(self, "s00", 0x400, 1);
    {
        VecFx32 at = data_ov006_021eb764;
        VecFx32 up = data_ov006_021eb734;
        Rot16 rot = data_ov006_021eb702;
        ov006_SetCam(self, &at, &up, &rot, 0x4400);
    }
    {
        ov006_Caption *p = (ov006_Caption *)Heap_Alloc(sizeof(ov006_Caption));
        if (p != NULL) {
            p = ov006_Caption_Ctor(p);
        }
        self->unk138 = p;
    }
    self->unk138->kind = 1;
    ov006_Caption_Init_021e0954(self->unk138);
    ov006_Caption_SetPos(self->unk138, -0xa0, -0x61);
    ov006_Caption_SetTextPos(self->unk138, 0x11, 0);
    ov006_TextHolder_Play_021e0ca8(self->unk138, MsgRes_GetString(res, 0x12a), 4);
    self->unk138->ofsY = -0x1e;
    {
        ov006_Obj13C *p = (ov006_Obj13C *)Heap_Alloc(sizeof(ov006_Obj13C));
        if (p != NULL) {
            p = Ov006Vt_021ec1fc_Ctor(p);
        }
        self->unk13C = p;
    }
    ov006_Obj13C_SetPair(self->unk13C, 0, 0xc);
    ov006_Unk021e16b0_Load(self->unk13C);
    self->unk5C = ov006_NewLo021cb0b8();
    self->unk5C->msgId = 0x12c;
    self->unk5C->text = (char *)MsgRes_GetString(res, 0x18);
    self->unk5C->key = 1;
    self->unk5C->onDecide = ov006_ListCb_StoreId;
    self->unk5C->owner = &self->unk40;
    self->unk5C->vfunc_08();
    self->unk5C->posZ = -0x1666;
    self->unk5C->flags |= 2;
    if (self->param != 0) {
        self->unk3D = 0;
    }
    id = UiList_GetCurrent(self->unk50)->id;
    self->unk4A = id;
    info = ov006_GetCourseInfo(id);
    if (self->param != 2) {
        Obj0215bb14_SetText(self->unk54, func_0206ec8c(id));
        self->unk54->vfunc_70();
    }
    ov006_Label_Set_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    ov006_Unk021e1ddc_SetLabel(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    ov006_Unk021e1e6c_PlayText(self->unk13C, Param_Get(id));
    self->unk4C = self->unk4A;
    ov006_Menu_ClearEntries(data_ov006_021ec888);
    self->unk44 = 4;
    self->unk48 = self->unk4A;
    TaskList_Insert(self);
    self->unk_04 &= ~2;
}

}
}  // namespace m_021d4118
#undef F

// ---- merged from ov006_021d4880.cpp
namespace m_021d4880 {


typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *gWhMgr;

u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask);
void ov006_Label_Close(ov006_Label *p);
void ov006_Menu_ShowObj(ov006_Unk021ec888 *self);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, int c, int d);
AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *a, int b);
void ov006_TaskD37_PlayAnim(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop);
ov006_Info021daaa8 *ov006_GetCourseInfo(u16 id);
const void *func_0206ec8c(u16 id);
const void *Param_Get(u16 id);
void ov006_Label_Set_021dbfb8(ov006_Label *a, const char *b, int c, int d);
void ov006_Unk021e1ddc_SetLabel(ov006_Obj13C *a, const char *b, int c, int d);
void ov006_Unk021e1e6c_PlayText(ov006_Obj13C *a, const void *b);

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = ov006_GetCourseInfo(id);
    if (self->param != 2) {
        Obj0215bb14_SetText(self->unk54, func_0206ec8c(id));
        self->unk54->vfunc_70();
    }
    ov006_Label_Set_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    ov006_Unk021e1ddc_SetLabel(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    ov006_Unk021e1e6c_PlayText(self->unk13C, Param_Get(id));
}

static inline BOOL ov006_IsUnlocked(int type, u16 mask) {
    BOOL r = TRUE;
    if (ov006_Menu_GetEntryMask_021e60e8(type, mask) == 0) {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov006_Anm_InRange(ov006_Anm74 *a, int start, int len) {
    return a->frame >= start && a->frame < start + len;
}

void ov006_TaskD37_UpdateActive(ov006_TaskD37 *self) {
    switch (self->step) {
    case 0:
        if (self->param != 0) {
            if (data_ov006_021ec888->state == 9) {
                self->step = 100;
                return;
            }
            if (self->param == 1) {
                BOOL ok = ov006_IsUnlocked(5, 1);
                if (!ok) {
                    u16 m = gWhMgr->unk32;
                    if (m == ov006_Menu_GetEntryMask_021e60e8(4, m)) {
                        self->unk44 = 5;
                    }
                }
                if (ok) {
                    self->step++;
                }
            } else if (self->param == 2) {
                if (ov006_IsUnlocked(5, 1)) {
                    self->step++;
                }
            }
        } else {
            self->step = 10;
        }
        break;
    case 1:
        self->unk44 = 0;
        if (self->param == 2) {
            self->step = 0x28;
        } else {
            self->step = 10;
        }
        break;
    case 10:
        self->unk50->flags &= ~4;
        self->step++;
    case 11: {
        u16 trg;
        if (data_ov006_021ec888->state == 9) {
            self->unk50->flags |= 4;
            self->step = 100;
            return;
        }
        trg = gPad->trig;
        if (trg & 2) {
            if (self->unk3D) {
                SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
                self->unk50->flags |= 2;
                self->unk54->flags |= 2;
                ov006_Label_Close(self->unk58);
                if (self->unk138->visible == 1) {
                    self->unk138->visible = 2;
                }
                self->unk_04 |= 6;
                self->step = 0x78;
            } else {
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            }
        } else if (trg & 1) {
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            self->step = 0x14;
        }
        break;
    }
    case 20:
        self->unk50->flags |= 4;
        self->unk5C->flags &= ~2;
        {
            Lo021cb0b8 *w = self->unk5C;
            w->vfunc_a8(UiList_GetItemById(w, 1));
        }
        self->step++;
        break;
    case 21:
        if (data_ov006_021ec888->state == 9) {
            self->unk5C->flags |= 2;
            self->step = 100;
            return;
        }
        if (!ov006_Window_IsState5(self->unk5C)) {
            return;
        }
        if (self->unk40 == 0) {
            self->unk44 = 6;
            self->step = 0x1e;
        } else {
            self->step = 10;
        }
        break;
    case 30:
        self->unk50->flags |= 2;
        self->unk54->flags |= 2;
        ov006_Label_Close(self->unk58);
        Model0218fe1c_SetAnim(self->unk64, "s01", 0, 1);
        Model0218fe1c_GetAnimCtrl(self->unk64, 0)->speed = 0xb33;
        ov006_TaskD37_PlayAnim(self, "s01", 0x1000, 0);
        {
            ov006_Info021daaa8 *info = ov006_GetCourseInfo(self->unk4A);
            ov006_SlotManager *m = gOv006SlotManager;
            m->unk6 = self->unk4A;
            m->info = (ov006_SlotManagerInfo *)info;
        }
        self->step++;
        break;
    case 31:
        if (data_ov006_021ec888->state == 9) {
            ov006_Label_Close(self->unk58);
            self->step = 100;
            return;
        }
        {
            int f = self->anm->frame;
            s16 len = self->animSpeed;
            if ((f >= 0x10000 && f < 0x10000 + len) || (f >= 0x1e000 && f < 0x1e000 + len)) {
                SndMgr_PlayVolume(gSndMgr, 0x32, -1, -1, -1);
            } else if (f >= 0xb000 && f < 0xb000 + len) {
                SndMgr_PlayVolume(gSndMgr, 0x35, -1, -1, -1);
            }
        }
        if (self->anm->frame >= (self->anm->res->numFrame << 12) - 0x1000) {
            self->unk_04 |= 6;
            GfxSys_StartFadeOut(0x14000, 0, 0);
            GfxSys_StartFadeOut(0x14000, 0, 1);
            self->step = 0x6e;
        }
        break;
    case 40:
        if (data_ov006_021ec888->state == 9) {
            self->step = 100;
            return;
        }
        if (!ov006_Menu_GetEntryMask_021e60e8(6, 1)) {
            return;
        }
        self->unk50->vfunc_a8(UiList_GetItemById(self->unk50, self->unk4C));
        ov006_TaskD37_Select(self, self->unk4C);
        self->step = 0x1e;
        break;
    case 100:
        ov006_Menu_ShowObj(data_ov006_021ec888);
        self->step++;
    case 101:
        if (data_ov006_021ec888->state == 9) {
            return;
        }
        GfxSys_StartFadeOut(0x1e000, 0, 0);
        GfxSys_StartFadeOut(0x1e000, 0, 1);
        self->step++;
        break;
    case 102:
        if (ov006_IsMode4() && ov006_IsMode4b()) {
            self->unk50->flags |= 2;
            self->unk54->flags |= 2;
            ov006_Label_Close(self->unk58);
            self->unk_04 |= 6;
            self->step = 0x82;
        }
        break;
    }
}

}
}  // namespace m_021d4880

// ---- merged from ov006_021d4f64.cpp
namespace m_021d4f64 {

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk02046a50 {
    u8 unk0[4];
    u16 unk4;
} ov006_Unk02046a50;

extern "C" {

extern void *gWhMgr;

ov006_Info021daaa8 *ov006_GetCourseInfo(u16 id);
const void *func_0206ec8c(u16 id);
const void *Param_Get(u16 id);
void ov006_Label_Set_021dbfb8(ov006_Label *a, const char *b, int c, int d);
void ov006_Unk021e1ddc_SetLabel(ov006_Obj13C *a, const char *b, int c, int d);
void ov006_Unk021e1e6c_PlayText(ov006_Obj13C *a, const void *b);
ov006_Unk02046a50 *Wh_GetSharedData(void *a, int idx);
void ov006_Label_Update(ov006_Label *a);
void ov006_Label_Draw(ov006_Label *a);
void ov006_Caption_Update(ov006_Caption *self);
void func_ov006_021e0b80(ov006_Caption *self);
void ov006_Unk021e1af0_Update(ov006_Obj13C *a);
void ov006_Unk021e1bb4_Draw(ov006_Obj13C *a);
void Model0218fe1c_UpdateAnim(Model0218fe1c *a, int b);
BOOL Model021903b4_Draw(Model0218fe1c *a);
BOOL ov006_TaskD37_ApplyAnim(ov006_TaskD37 *self, Model0218fe1c *obj);
void ov006_Menu_SetOwnEntry(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void ov006_Manager_DispatchMenuCb(int a, int b, int c);
void ov006_Menu_ClearEntries(ov006_Unk021ec888 *self);
void ov006_Menu_ReleaseObj(ov006_Unk021ec888 *self);
int STD_TSNPrintf(char *dst, u32 size, const char *fmt, ...);

// The camera's vtable (Camera_vtbl) holds Camera_Apply in slot 0x00.
static inline void ov006_Camera_Apply(Camera *cam) {
    ((VObj *)cam)->vfunc_00();
}

static inline void ov006_Window_SetSel(UiList *w, u16 id) {
    UiListItem *item = UiList_GetItemById(w, id);
    w->vfunc_a8(item);
}

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = ov006_GetCourseInfo(id);
    if (self->param != 2) {
        Obj0215bb14_SetText(self->unk54, func_0206ec8c(id));
        self->unk54->vfunc_70();
    }
    ov006_Label_Set_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    ov006_Unk021e1ddc_SetLabel(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    ov006_Unk021e1e6c_PlayText(self->unk13C, Param_Get(id));
}

void ov006_TaskD37_PreUpdate(ov006_TaskD37 *self) {
    BOOL done = FALSE;
    if (self->state == 0xd && self->param != 0 && data_ov006_021ec888->state != 9) {
        ov006_Unk02046a50 *p;
        done = TRUE;
        p = Wh_GetSharedData(gWhMgr, 0);
        if (self->param == 2 && self->step == 0x28) {
            self->unk4C = p->unk4;
            if (self->unk4A != self->unk4C) {
                self->unk50->vfunc_a8(UiList_GetItemById(self->unk50, self->unk4C));
                ov006_TaskD37_Select(self, self->unk4C);
            }
        }
    }
    self->unk50->vfunc_1c();
    self->unk54->vfunc_1c();
    ov006_Label_Update(self->unk58);
    ov006_Caption_Update(self->unk138);
    ov006_Unk021e1af0_Update(self->unk13C);
    self->unk5C->vfunc_1c();
    Model0218fe1c_UpdateAnim(self->unk64, 0x1000);
    Model0218fe1c_UpdateAnim(self->unk6C, 0x1000);
    ov006_TaskD37_ApplyAnim(self, self->unk6C);
    if (!done) {
        return;
    }
    if (self->param == 1) {
        self->unk48 = self->unk4A;
    }
    ov006_Menu_SetOwnEntry(data_ov006_021ec888, self->unk44, 2, &self->unk46, 4);
}

void ov006_TaskD37_PostUpdate(ov006_TaskD37 *self) {
    if (self->state != 0) {
        return;
    }
    switch (self->step) {
    case 0x6e:
        ov006_Manager_DispatchMenuCb(6, 1, self->param);
        self->step++;
        break;
    case 0x78:
        ov006_Manager_DispatchMenuCb(6, 0, self->param);
        self->step++;
        break;
    case 0x82:
        TaskHost_RequestSwitch(gTaskHost, 0x26, 0);
        self->step++;
        break;
    }
    ov006_Menu_ClearEntries(data_ov006_021ec888);
}

void ov006_TaskD37_Draw(ov006_TaskD37 *self) {
    if (!self->vfunc_28()) {
        return;
    }
    func_ov006_021e0b80(self->unk138);
    ov006_Unk021e1bb4_Draw(self->unk13C);
    ov006_Label_Draw(self->unk58);
    self->unk50->vfunc_20();
    self->unk54->vfunc_20();
    self->unk5C->vfunc_20();
    ov006_Camera_Apply(&self->cam);
    Model021903b4_Draw(self->unk64);
    Model021903b4_Draw(self->unk6C);
    if (data_ov006_021ec888 != NULL) {
        ov006_Menu_ReleaseObj(data_ov006_021ec888);
    }
}

void ov006_TaskD37_PlayAnim(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop) {
    void **res;
    char buf[0x10];
    if (self->unk70 == NULL || name == NULL) {
        return;
    }
    if (self->anm == NULL) {
        self->anm = (ov006_Anm74 *)Heap_AllocHi(0x100, 4);
    }
    res = self->unk70->unk_48;
    MI_CpuFill8(buf, 0, sizeof(buf));
    STD_TSNPrintf(buf, sizeof(buf), "%s%s", self->unk70->unk_6c, name);
    self->anm->res = (typeof(self->anm->res))NNS_G3dGetAnmByName(*res, (const NNSG3dResName *)buf);
    self->anm->frame = 0;
    self->anm->speed = 0x1000;
    self->anm->func = (void *)NNS_G3dFuncAnmJntNsBcaDefault;
    self->anm->unk10 = 0;
    self->anm->unk14 = 0;
    self->anm->unk18 = 0x7f;
    self->anm->unk19 = 0;
    self->animLoop = loop;
    self->animSpeed = speed;
}

BOOL ov006_TaskD37_ApplyAnim(ov006_TaskD37 *self, Model0218fe1c *m) {
    BOOL r;
    int end;
    int frame;
    ov006_Anm74 *anm;
    u32 flag;
    NNSG3dRS rs;
    NNSG3dJntAnmResult result;
    if (self->anm == NULL) {
        return FALSE;
    }
    r = FALSE;
    NNS_G3dRS = &rs;
    MIi_CpuClearFast(0, &rs, sizeof(rs));
    rs.funcJntScale = NNS_G3dGetJointScale_FuncArray[0];
    NNS_G3dFuncAnmJntNsBcaDefault(&result, (const NNSG3dAnmObj *)self->anm, 0);
    flag = result.flag;
    if (flag & 2) {
        MTX_Identity33_(&result.rot);
    }
    if (flag & 4) {
        result.trans.x = 0;
        result.trans.y = 0;
        result.trans.z = 0;
    }
    if (flag & 1) {
        result.scale.x = 0x1000;
        result.scale.y = 0x1000;
        result.scale.z = 0x1000;
    }
    m->scale = result.scale;
    m->trans = result.trans;
    MI_Copy36B(&result.rot, &m->rot);
    NNS_G3dRS = NULL;
    anm = self->anm;
    end = (anm->res->numFrame << 12) - 0x1000;
    frame = anm->frame + self->animSpeed;
    if (self->animLoop) {
        frame = frame % end;
    } else if (frame >= end) {
        frame = end;
        r = TRUE;
    }
    anm->frame = frame;
    return r;
}

}
}  // namespace m_021d4f64
