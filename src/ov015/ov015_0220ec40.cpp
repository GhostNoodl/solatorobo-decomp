#include "ov015/ov015.h"
#include "nitro/std.h"

extern "C" {



extern void *data_02149ef8;
extern u8 *data_0214a424;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb3a8[];
extern u8 data_ov000_021ccbe0[];
extern u8 data_ov000_021ccb54[];
extern u8 data_ov015_022131ac[];
extern u8 data_ov000_021cca40[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cae48[];
extern char data_ov015_02213100[];
void *MsgRes_GetString(void *a, s32 b);
void func_ov000_02157c90(void *a, void *b);
const char *func_0206ffa0(u16 id);
void func_ov000_021c3af4(void *p);
void func_ov000_021c54f4(void *p);
void func_ov000_021c22d8(void *p);
void func_ov000_021c5bac(void *p);
void *func_0206ec48(u16 id);
u8 *func_0206ee20(u16 id);
void func_ov000_021c3fd4(void *a, void *b);
void func_ov000_021c55e8(void *a, void *b);
void func_ov000_021c5630(void *a, void *b);
void func_ov000_021c5678(void *a, void *b);
void func_ov000_0215d980(void *a, s32 b, s32 c);


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
    return data_02149ef8;
}

void func_ov015_0220e634(Ov015ResultPanel *self, s32 mode) {
    Ov015Shared *sh;
    s32 i;
    UiObj *p;
    Ov015ItemEnt *items;
    void *res;
    res = GetRes0220e634();
    sh = data_ov015_02213368;
    self->mode = mode;
    p = (UiObj *)Heap_Alloc(0xf0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb4a8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb3a8);
        VCALL(p)->v28();
    }
    self->unk_04 = (Lo021cb3a8 *)p;
    p->width = 0xf8;
    self->unk_04->rows = 1;
    Ov015_SetUiPos(self->unk_04, 0, 0x19, -0xccd);
    self->unk_04->color = 0x28;
    Ov015_SetUiSlide(self->unk_04, -0x100, 0, -0xccd);
    self->unk_04->flags &= ~0x40000;
    self->unk_04->flags &= ~0x20000;
    VCALL(self->unk_04)->v10(MsgRes_GetString(res, 0xcc));
    VCALL(self->unk_04)->v14(MsgRes_GetString(res, 0xcd));
    self->unk_04->slideMode = 1;
    switch (mode) {
    case 0:
        STD_CopyLString(self->name, (const char *)MsgRes_GetString(res, 0xcf), 0x40);
        break;
    case 1:
        func_ov000_02157c90(self->unk_04, MsgRes_GetString(res, 0xce));
        STD_CopyLString(self->name, func_0206ffa0(sh->catchId), 0x40);
        break;
    default:
        STD_CopyLString(self->name, data_ov015_02213100, 0x40);
        break;
    }
    self->unk_04->srcStr = self->name;
    VCALL(self->unk_04)->v08();
    items = sh->items;
    p = (UiObj *)Heap_Alloc(0x100);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021ccbe0);
        func_ov000_021c3af4(p);
        SET_VT(p, data_ov000_021ccb54);
        func_ov000_021c54f4(p);
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
            u8 *d;
            if (items[i].count == 0) {
                break;
            }
            e = (Lo021cca40 *)Heap_Alloc(0x48);
            if (e != NULL) {
                SET_VT(e, data_ov015_022131ac);
                func_ov000_021c22d8(e);
                SET_VT(e, data_ov000_021cca40);
                func_ov000_021c5bac(e);
            }
            name = func_0206ec48(items[i].id);
            k = 0;
            d = func_0206ee20(items[i].id);
            if (d != NULL) {
                k = FLD(u16, d, 2);
            }
            n = items[i].count;
            e->unk_38 = name;
            e->unk_3c = n;
            e->unk_40 = k * n;
            func_ov000_021c3fd4(self->unk_08, e);
        }
    }
    func_ov000_021c55e8(self->unk_08, MsgRes_GetString(res, 0x9a));
    func_ov000_021c5630(self->unk_08, MsgRes_GetString(res, 0xd3));
    func_ov000_021c5678(self->unk_08, MsgRes_GetString(res, 0x3f));
    VCALL(self->unk_08)->v08();
    self->unk_08->flags |= 4;
    p = (UiObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb5a8);
        VCALL(p)->v28();
    }
    self->unk_14 = (UiList *)p;
    p->flags |= 0x4000000;
    self->unk_14->slideMode = 1;
    self->unk_14->flags |= 0x20000000;
    self->unk_14->flags |= 0x80000000;
    Ov015_SetUiSlide(self->unk_14, 0x100, 0, -0xcd);
    VCALL(self->unk_14)->vf4(1, MsgRes_GetString(res, 0x36));
    VCALL(self->unk_14)->v08();
    self->unk_14->flags |= 2;
    p = (UiObj *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    self->unk_0c = (Ov015UiNum *)p;
    Ov015_SetUiPos(p, 0x92, 0x78, -0x99a);
    Ov015_SetUiSlide(self->unk_0c, 0x100, 0, -0x99a);
    self->unk_0c->slideMode = 1;
    self->unk_0c->unk_84 = 1;
    VCALL(self->unk_0c)->v08();
    if (mode == 1) {
        func_ov000_0215d980(self->unk_0c, sh->total, 0);
    } else {
        func_ov000_0215d980(self->unk_0c, 0, 0);
    }
    p = (UiObj *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    self->unk_10 = (Ov015UiNum *)p;
    Ov015_SetUiPos(p, 0x92, 0x8c, -0x99a);
    Ov015_SetUiSlide(self->unk_10, 0x100, 0, -0x99a);
    self->unk_10->slideMode = 1;
    self->unk_10->unk_84 = 1;
    VCALL(self->unk_10)->v08();
    func_ov000_0215d980(self->unk_10, FLD(s32, data_0214a424, 0x618), 0);
}

void func_ov015_0220ec40(Ov015ResultPanel *self) {
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
