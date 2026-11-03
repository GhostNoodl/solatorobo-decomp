#include "ov015/ov015.h"
#include "nitro/std.h"

extern "C" {



extern void *gMsgRes;
extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 Lo021cb3a8_vtbl[];
extern u8 Ov000Vt_021ccbe0_vtbl[];
extern u8 Ov000Vt_021ccb54_vtbl[];
extern u8 Ov015Vt_022131ac_vtbl[];
extern u8 Lo021cca40_vtbl[];
extern u8 Lo021cb5a8_vtbl[];
extern u8 Lo021cae48_vtbl[];
extern char data_ov015_02213100[];
void *MsgRes_GetString(void *a, s32 b);
void UiList021cb4a8_SetLabel(void *a, void *b);
const char *Tbl_GetText(u16 id);
void LoBase021ccb54_021ccbe0_CtorBase(void *p);
void Lo021ccb54_ClearLabels(void *p);
void ListRow_Init(void *p);
void Lo021cca40_Init(void *p);
void *Param_Get(u16 id);
Ov015ParamPrice *func_0206ee20(u16 id);
void LoBase021ccb54_021ccbe0_AppendRow(void *a, void *b);
void Obj021c55e8_SetLabel1(void *a, void *b);
void Obj021c55e8_SetLabel2(void *a, void *b);
void Obj021c55e8_SetLabel3(void *a, void *b);


static inline void Ov015_SetUiPos(UiObj *o, s16 x, s16 y, s16 z) {
    o->posX = x;
    o->posY = y;
    o->posZ = z;
}

static inline void Ov015_SetUiSlide(UiObj *o, s32 x, s32 y, s32 z) {
    o->slideX = x;
    o->slideY = y;
    o->slideZ = z;
}

static inline void *GetRes0220e634(void) {
    return gMsgRes;
}

void func_ov015_0220e634(Ov015ResultPanel *self, s32 mode) {
    Ov015Shared *sh;
    s32 i;
    UiObj *p;
    Ov015ItemEnt *items;
    void *res;
    res = GetRes0220e634();
    sh = gOv015Shared;
    self->mode = mode;
    p = (UiObj *)Heap_Alloc(0xf0);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList021cb4a8_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cb3a8_vtbl);
        p->vfunc_28();
    }
    self->unk_04 = (Lo021cb3a8 *)p;
    p->width = 0xf8;
    self->unk_04->rows = 1;
    Ov015_SetUiPos(self->unk_04, 0, 0x19, -0xccd);
    self->unk_04->color = 0x28;
    Ov015_SetUiSlide(self->unk_04, -0x100, 0, -0xccd);
    self->unk_04->flags &= ~0x40000;
    self->unk_04->flags &= ~0x20000;
    self->unk_04->vfunc_10(MsgRes_GetString(res, 0xcc));
    self->unk_04->vfunc_14(MsgRes_GetString(res, 0xcd));
    self->unk_04->slideMode = 1;
    switch (mode) {
    case 0:
        STD_CopyLString(self->name, (const char *)MsgRes_GetString(res, 0xcf), 0x40);
        break;
    case 1:
        UiList021cb4a8_SetLabel(self->unk_04, MsgRes_GetString(res, 0xce));
        STD_CopyLString(self->name, Tbl_GetText(sh->catchId), 0x40);
        break;
    default:
        STD_CopyLString(self->name, data_ov015_02213100, 0x40);
        break;
    }
    self->unk_04->srcStr = self->name;
    self->unk_04->vfunc_08();
    items = sh->items;
    p = (UiObj *)Heap_Alloc(0x100);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Ov000Vt_021ccbe0_vtbl);
        LoBase021ccb54_021ccbe0_CtorBase(p);
        SET_VT(p, Ov000Vt_021ccb54_vtbl);
        Lo021ccb54_ClearLabels(p);
    }
    self->unk_08 = p;
    p->width = 0xf8;
    self->unk_08->rows = 3;
    Ov015_SetUiPos(self->unk_08, 2, 0x3c, -0xccd);
    Ov015_SetUiSlide(self->unk_08, -0x100, 0, -0xccd);
    self->unk_08->slideMode = 1;
    self->unk_08->flags &= ~0x40000;
    FLD(u8, self->unk_08, 0xf0) = 0;
    if (mode == 1) {
        for (i = 0; i < 3; i++) {
            u16 n;
            void *name;
            u16 k;
            Lo021cca40 *e;
            Ov015ParamPrice *d;
            if (items[i].count == 0) {
                break;
            }
            e = (Lo021cca40 *)Heap_Alloc(0x48);
            if (e != NULL) {
                SET_VT(e, Ov015Vt_022131ac_vtbl);
                ListRow_Init(e);
                SET_VT(e, Lo021cca40_vtbl);
                Lo021cca40_Init(e);
            }
            name = Param_Get(items[i].id);
            k = 0;
            d = func_0206ee20(items[i].id);
            if (d != NULL) {
                k = d->price;
            }
            n = items[i].count;
            e->unk_38 = name;
            e->unk_3c = n;
            e->unk_40 = k * n;
            LoBase021ccb54_021ccbe0_AppendRow(self->unk_08, e);
        }
    }
    Obj021c55e8_SetLabel1(self->unk_08, MsgRes_GetString(res, 0x9a));
    Obj021c55e8_SetLabel2(self->unk_08, MsgRes_GetString(res, 0xd3));
    Obj021c55e8_SetLabel3(self->unk_08, MsgRes_GetString(res, 0x3f));
    self->unk_08->vfunc_08();
    self->unk_08->flags |= 4;
    p = (UiObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cb5a8_vtbl);
        p->vfunc_28();
    }
    self->unk_14 = (UiList *)p;
    p->flags |= 0x4000000;
    self->unk_14->slideMode = 1;
    self->unk_14->flags |= 0x20000000;
    self->unk_14->flags |= 0x80000000;
    Ov015_SetUiSlide(self->unk_14, 0x100, 0, -0xcd);
    self->unk_14->vfunc_f4(1, MsgRes_GetString(res, 0x36));
    self->unk_14->vfunc_08();
    self->unk_14->flags |= 2;
    p = (UiObj *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cae48_vtbl);
        p->vfunc_28();
    }
    self->unk_0c = (Ov015UiNum *)p;
    Ov015_SetUiPos(p, 0x92, 0x78, -0x99a);
    Ov015_SetUiSlide(self->unk_0c, 0x100, 0, -0x99a);
    self->unk_0c->slideMode = 1;
    self->unk_0c->unk_84 = 1;
    self->unk_0c->vfunc_08();
    if (mode == 1) {
        Lo021cae48_SetValue(self->unk_0c, sh->total, 0);
    } else {
        Lo021cae48_SetValue(self->unk_0c, 0, 0);
    }
    p = (UiObj *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cae48_vtbl);
        p->vfunc_28();
    }
    self->unk_10 = (Ov015UiNum *)p;
    Ov015_SetUiPos(p, 0x92, 0x8c, -0x99a);
    Ov015_SetUiSlide(self->unk_10, 0x100, 0, -0x99a);
    self->unk_10->slideMode = 1;
    self->unk_10->unk_84 = 1;
    self->unk_10->vfunc_08();
    Lo021cae48_SetValue(self->unk_10, gStageFlags->unk_618, 0);
}

void Ov015ResultPanel_DtorBase(Ov015ResultPanel *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_04);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_08);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_0c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_14);
    HEAP_POP(saved);
}

}
