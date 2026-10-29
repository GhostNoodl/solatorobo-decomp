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
#include "ov006/ov006.h"
#include "ov006/SlotManager.h"

// ---- merged from ov006_021ebabc.cpp
static const fx32 data_ov006_021ebba8 = FX_Div(256 * FX32_ONE, 15 * FX32_ONE);
static const char *data_ov006_021ebbac = "--------------------";

// ---- merged from ov006_021ce374.cpp
namespace m_021ce374 {

extern "C" {

extern char data_ov006_021ec864[];
extern char *data_0208ccc0;
extern char *data_0208cca0;

void func_ov006_021ce048(void);
void func_ov006_021ce3f0(ov006_Emblem *self);
void func_ov000_02173648(ov006_Emblem *self);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, const char *b);
void func_02041c20(ov006_Model *self, int a, void *b);
BOOL func_02054f10(ov006_Model *a, int b);

void func_ov006_021ce374(void) {
}

BOOL func_ov006_021ce378(void) {
    return TRUE;
}

void func_ov006_021ce380(ov006_Emblem *self) {
    self->unk4_1 = 0;
    if (VCALL(self, 28)) {
        return;
    }
    func_ov006_021ce3f0(self);
    self->unk44 = 1;
    self->unk2C = 0;
    func_ov000_02173648(self);
}

static inline BOOL ov006_Emblem_Bit4(ov006_Emblem *self) {
    return self->unk4_4 != 0;
}

BOOL func_ov006_021ce3cc(ov006_Emblem *self) {
    return ov006_Emblem_Bit4(self) ? TRUE : FALSE;
}

void func_ov006_021ce3f0(ov006_Emblem *self) {
    ov006_Model *model;
    ov006_Model *model2;

    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = "cefly1pic00";
        func_02041218(model->unk88);
        func_02041440(model, name, 0);
        STD_CopyString(model->unk2C, data_ov006_021ec864);
    }
    self->unk3C = model;
    func_020417e0(self->unk3C, func_02035de0(data_ov006_021ec864, "cefly1pic00"));
    self->unk3C->unk6C |= 2;
    self->unk3C->unk6C |= 0x80000;
    func_02041d9c(self->unk3C, 2, 0xffff);
    model2 = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model2 != NULL) {
        const char *file = data_0208cca0;
        const char *name = data_0208ccc0;
        func_02041218(model2->unk88);
        func_02041440(model2, name, 0);
        STD_CopyString(model2->unk2C, file);
    }
    self->unk40 = model2;
    func_020417e0(self->unk40, func_02034d88(func_02035d5c(data_0208cca0), data_0208ccc0));
    self->unk40->unk6C |= 2;
    func_02041d9c(self->unk40, 0, 0);
    ov006_Model_SetPos(self->unk40, 0, 0, 0);
    self->unk40->unk150 = 0xfffe019a;
    self->unk40->unk158 = (void *)func_ov006_021ce048;
    func_02041c20(self->unk40, 0, &self->unk48);
}

}
}  // namespace m_021ce374

// ---- merged from ov006_021ce560.cpp
namespace m_021ce560 {

extern "C" {

extern char data_ov006_021ec864[];
extern char *data_0208ccc0;
extern char *data_0208cca0;

void func_ov006_021ce3f0(ov006_Emblem *self);
void func_ov006_021ce048(void);
void func_ov000_02173648(ov006_Emblem *self);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, const char *b);
void func_02041c20(ov006_Model *self, int a, void *b);
BOOL func_02054f10(ov006_Model *a, int b);

void func_ov006_021ce560(void) {
}

void func_ov006_021ce564(ov006_Emblem *self) {
    int v = 0;
    if (self->unk48 < 0x1000000) {
        v = self->unk48 + 0x8000;
    }
    self->unk48 = v;
    self->unk4C = self->unk4C >= 0x1000000 ? 0 : self->unk4C + 0x8000;
}

void func_ov006_021ce590(ov006_Emblem *self) {
    if (!self->unk44) {
        return;
    }
    if (self->unk40 != NULL && func_02054f10(self->unk40, 0xffff)) {
        ov006_Model_PlayPart(self->unk40, 0);
    }
    if (self->unk3C != NULL && func_02054f10(self->unk3C, 0xffff)) {
        ov006_Model_PlayPart(self->unk3C, 0);
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

extern void *data_ov006_021ebd40;

void func_ov006_021cf360(ov006_TaskCE *self, u16 a);

static inline void ov006_TaskCE_Init(ov006_TaskCE *self) {
    OV006_TASKBASE_CTOR(&self->base);
    self->base.vtbl = &data_ov006_021ebd40;
    self->base.state = 0;
    self->base.subState = 0;
    self->unk44 = NULL;
    self->unk48 = NULL;
    self->unk4C = NULL;
    self->unk50 = NULL;
    self->unk54 = NULL;
}

ov006_TaskCE *func_ov006_021ce6bc(void) {
    ov006_TaskCE *self = (ov006_TaskCE *)func_0203dd9c(sizeof(ov006_TaskCE));
    if (self != NULL) {
        ov006_TaskCE_Init(self);
    }
    VCALL(self, 08, 0x26, 200);
    return self;
}

static inline void ov006_TaskCE_Open(ov006_TaskCE *self, int id) {
    OV006_DELETE_OBJECT(self->unk4C);
    self->unk4C = ov006_MsgBox_New();
    func_ov000_021632f0(self->unk4C, id, "script/other", "skyhelp.ccmes", 1);
    self->unk44->flags |= 4;
    self->unk48->flags |= 2;
}

BOOL func_ov006_021ce734(ov006_TaskOwner *owner, ov006_ListNode *arg) {
    ov006_TaskCE *self = (ov006_TaskCE *)owner->task;
    if (arg != NULL) {
        u16 id;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        id = arg->id;
        if (self->base.state == 3) {
            switch (id) {
            case 0:
                self->base.state = 4;
                self->base.subState = 0;
                break;
            case 1:
                self->base.state = 5;
                self->base.subState = 0;
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
                self->base.state = 6;
                self->base.subState = 0;
                break;
            }
        }
    }
    return TRUE;
}

BOOL func_ov006_021ce954(ov006_TaskOwner *owner, ov006_ListNode *arg) {
    ov006_TaskCE *self = (ov006_TaskCE *)owner->task;
    if (arg != NULL) {
        func_ov006_021cf360(self, arg->id);
    }
    return TRUE;
}

static inline void ov006_TaskCE_Dtor(ov006_TaskCE *self) {
    self->base.vtbl = &data_ov006_021ebd40;
    OV006_DELETE_OBJECT(self->unk44);
    OV006_DELETE_OBJECT(self->unk48);
    OV006_DELETE_OBJECT(self->unk4C);
    OV006_DELETE_OBJECT(self->unk50);
    OV006_DELETE_OBJECT(self->unk54);
    OV006_TASKBASE_DTOR(&self->base);
}

ov006_TaskCE *func_ov006_021ce974(ov006_TaskCE *self) {
    ov006_TaskCE_Dtor(self);
    return self;
}

ov006_MsgBox *func_ov006_021cead0(ov006_MsgBox *self) {
    self->vtbl = &data_ov006_021ebc70;
    func_ov000_02163254(self);
    func_0203de1c(self);
    return self;
}

ov006_TaskCE *func_ov006_021ceaf8(ov006_TaskCE *self) {
    ov006_TaskCE_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
}  // namespace m_021ce6bc

// ---- merged from ov006_021cec5c.cpp
namespace m_021cec5c {

extern "C" {

void func_ov006_021cec5c(void) {
}

BOOL func_ov006_021cec60(void) {
    return TRUE;
}

}
}  // namespace m_021cec5c

// ---- merged from ov006_021cec68.cpp
namespace m_021cec68 {

#define F(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct ov006_Entry021cec68 {
    u16 name;
} ov006_Entry021cec68;

typedef struct ov006_Bits8b0 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} ov006_Bits8b0;
extern "C" {

extern void *data_02149ef8;
extern u8 *data_02097d48;
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cadcc;
extern void *data_ov000_021ccbe0;
extern void *data_ov000_021ccb54;
extern void *data_ov000_021cca28;
extern void *data_ov006_021ebc80;

void *func_0204c0e8(void *a, int id);
void func_02043904(void *p);
void func_02043b20(void *p);
void func_ov000_02173648(void *self);
void func_ov006_021daea0(ov006_SlotManager *a);
u8 func_ov006_021db078(ov006_SlotManager *self);
void func_ov006_021d8f44(void);
ov006_Entry021cec68 *func_ov006_021d8f20(u32 id);
void func_ov000_021546ec(void *w, const char *a, const char *b, int c);
void func_ov000_021c3af4(void *self);
void func_ov000_021c54f4(void *self);
void func_ov000_021c55e8(void *self, const void *s);
void func_ov000_021c22d8(void *self);
void func_ov000_021c5fc4(void *self);
void func_ov000_021c5fd0(void *self, const void *s);
void func_ov000_021c3fd4(void *list, void *item);
void *func_ov006_021e29c4(void *self);
void func_ov006_021e2c14(void *self);
void func_ov006_021e341c(void *self, const void *s);
void func_ov006_021e34d8(void *self, const void *s, int idx);
BOOL func_ov006_021ce734(ov006_TaskOwner *owner, ov006_ListNode *arg);
BOOL func_ov006_021ce954(ov006_TaskOwner *owner, ov006_ListNode *arg);
}


extern "C" {

static inline ov006_Window *ov006_NewWindow_caec8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xd4);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cadcc(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x8c);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cadcc;
        VCALL(w, 28);
    }
    return w;
}

static inline void *ov006_NewList_ccb54(void) {
    void *w = func_0203dd9c(0x100);
    if (w != NULL) {
        *(void **)w = &data_ov000_021cac60;
        VCALL(w, 28);
        *(void **)w = &data_ov000_021ccbe0;
        func_ov000_021c3af4(w);
        *(void **)w = &data_ov000_021ccb54;
        func_ov000_021c54f4(w);
    }
    return w;
}

static inline u8 ov006_SlotManager_Get14A(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->unk14A[i];
    }
    return 0;
}

// The list items are constructed in place through `item` (round jkH): with a `NewItem` inline
// the inline's result is a compiler temp, numbered below `res`, and the two swap registers.
void func_ov006_021cec68(ov006_TaskCE *self) {
    u8 n;
    u8 i;
    u8 k;
    ov006_Entry021cec68 *e;
    void *item;
    u8 *g;
    if (VCALL(self, 28)) {
        return;
    }
    {
        g = data_02097d48;
        func_02043904(g + 0x8b0);
        ((ov006_Bits8b0 *)(g + 0x8b0))->b4 = 1;
        ((ov006_Bits8b0 *)(g + 0x8b0))->b5 = 1;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        func_02043b20(g + 0x8b0);
    }
    self->base.flags &= ~2;
    func_ov006_021daea0(data_ov006_021ec884);
    self->base.unk20 = 0x19000;
    VCALL(self, 3C);
    void *res = data_02149ef8;
    self->unk44 = ov006_NewWindow_caec8();
    VCALL(self->unk44, 10, func_0204c0e8(res, 0x122));
    VCALL(self->unk44, 14, func_0204c0e8(res, 0x123));
    self->unk44->unk4A = 0x2c00;
    self->unk44->unk24 = 0xac;
    self->unk44->unk20 = 4;
    ov006_Window_SetRot(self->unk44, 0, 0x1e, -0x2000);
    ov006_Window_SetPos(self->unk44, 0, -0x100, -0x2000);
    self->unk44->unk2C = 1;
    self->unk44->flags &= ~0x400000;
    self->unk44->flags &= ~0x800000;
    self->unk44->flags &= ~0x20000;
    self->unk44->flags &= ~0x80000;
    self->unk44->flags &= ~0x40000;
    self->unk44->flags &= ~0x10000;
    func_ov000_021546ec(self->unk44, (char *)"menu/net", (char *)"wireless_on", 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x124), 0, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x126), 1, 0, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x140), 2, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x142), 3, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x144), 4, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x146), 5, 0xffff, 0xffff);
    {
        ov006_Window *w = self->unk44;
        VCALL(w, A8, func_ov000_02154b58(w, 0));
    }
    self->unk44->unk84 = (ov006_WindowFunc)func_ov006_021ce734;
    self->unk44->unk88 = (ov006_WindowFunc)func_ov006_021ce954;
    self->unk44->owner = self;
    VCALL(self->unk44, 08);
    self->unk48 = ov006_NewWindow_cadcc();
    self->unk48->unk24 = 0xf8;
    self->unk48->unk20 = 2;
    ov006_Window_SetRot(self->unk48, 4, 0x95, -0x2000);
    ov006_Window_SetPos(self->unk48, -0x100, 0, -0x2000);
    self->unk48->unk2C = 1;
    VCALL(self->unk48, 08);
    self->unk48->flags |= 4;
    ov006_TaskCE_ShowMenus(self);
    func_ov006_021d8f44();
    n = func_ov006_021db078(data_ov006_021ec884);
    if (n != 0) {
        if (data_ov006_021ec884->unk149 == 0) {
            self->unk50 = (ov006_Window *)ov006_NewList_ccb54();
            func_ov000_021c55e8(self->unk50, func_0204c0e8(res, 0x183));
            self->unk50->unk20 = (n == 1) ? 2 : n;
            self->unk50->unk24 = 0xc0;
            ov006_Window_SetRot(self->unk50, 0x20, 0x3c, -0x1ccd);
            for (i = 0; i < 3; i++) {
                e = func_ov006_021d8f20(ov006_SlotManager_Get14A(data_ov006_021ec884, i));
                if (e != NULL) {
                    item = func_0203dd9c(0x34);
                    if (item != NULL) {
                        *(void **)item = &data_ov006_021ebc80;
                        func_ov000_021c22d8(item);
                        *(void **)item = &data_ov000_021cca28;
                        func_ov000_021c5fc4(item);
                    }
                    func_ov000_021c5fd0(item, func_0204c0e8(res, e->name));
                    func_ov000_021c3fd4(self->unk50, item);
                }
            }
            self->unk50->flags &= ~0x40000;
            F(self->unk50, 0xf0, u8) = 0;
            self->unk50->flags |= 4;
            VCALL(self->unk50, 08);
            self->unk50->flags |= 2;
        }
        {
            void *p = func_0203dd9c(0x24);
            if (p != NULL) {
                p = func_ov006_021e29c4(p);
            }
            self->unk54 = (Object *)p;
        }
        func_ov006_021e2c14(self->unk54);
        func_ov006_021e341c(self->unk54, func_0204c0e8(res, 0x183));
        {
            k = 0;
            for (i = 0; i < 3; i++) {
                e = func_ov006_021d8f20(ov006_SlotManager_Get14A(data_ov006_021ec884, i));
                if (e != NULL) {
                    func_ov006_021e34d8(self->unk54, func_0204c0e8(res, e->name), k);
                    k++;
                }
            }
        }
    }
    data_ov006_021ec884->unk149 = 1;
    self->base.state = 0;
    self->base.subState = 0;
    func_0203cb78(0x14000, 0, 0);
    func_0203cb78(0x14000, 0, 1);
    func_ov000_02173648(self);
}

}
}  // namespace m_021cec68
#undef F

// ---- merged from ov006_021cf350.cpp
namespace m_021cf350 {

typedef struct ov006_Unk021cf350 {
    void *vtbl;
    u32 unk4_0 : 7;
    u32 unk4_7 : 1;
    u32 unk4_8 : 24;
} ov006_Unk021cf350;

extern "C" {

void func_ov006_021cf350(ov006_Unk021cf350 *self) {
    self->unk4_7 = 1;
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

extern void *data_02149ef8;
extern ov006_DataRes *data_02fe152c;

void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021cf7c8(ov006_TaskCE *self);
void func_ov006_021cf89c(ov006_TaskCE *self);
void func_ov006_021cfa80(ov006_TaskCE *self);
void func_ov006_021cfc60(ov006_TaskCE *self);
void func_ov006_021db65c(void);
void *func_0205976c(ov006_DataRes *res, u32 idx);
u32 func_0205975c(ov006_DataRes *res, u32 idx);
u16 func_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void func_ov006_021e2f3c(Object *a);

void func_ov006_021cf360(ov006_TaskCE *self, u16 id) {
    const void *str;
    void *res = data_02149ef8;
    switch (id) {
    case 0:
        str = func_0204c0e8(res, 0x125);
        break;
    case 1:
        str = func_0204c0e8(res, 0x127);
        break;
    case 2:
        str = func_0204c0e8(res, 0x141);
        break;
    case 3:
        str = func_0204c0e8(res, 0x143);
        break;
    case 4:
        str = func_0204c0e8(res, 0x145);
        break;
    case 5:
        str = func_0204c0e8(res, 0x147);
        break;
    default:
        str = "";
        break;
    }
    if (self->unk48 != NULL) {
        func_ov000_0215bb14(self->unk48, str);
        VCALL(self->unk48, 70);
    }
}

}
}  // namespace m_021cf360

// ---- merged from ov006_021cf414.cpp
namespace m_021cf414 {

extern "C" {

// Both tests have no effect, so MWCC drops the second load and compare but keeps the first.
void func_ov006_021cf414(ov006_TaskCE *self) {
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

extern ov006_DataRes *data_02fe152c;
void func_ov006_021cf7c8(ov006_TaskCE *self);
void func_ov006_021cf89c(ov006_TaskCE *self);
void func_ov006_021cfa80(ov006_TaskCE *self);
void func_ov006_021cfc60(ov006_TaskCE *self);
void func_ov006_021db65c(void);
void *func_0205976c(ov006_DataRes *res, u32 idx);
u32 func_0205975c(ov006_DataRes *res, u32 idx);
u16 func_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void func_ov006_021e2f3c(Object *a);

void func_ov006_021cf420(ov006_TaskCE *self) {
    u8 *block;
    u16 n;
    u16 i;
    void *ent;
    switch (self->base.state) {
    case 0:
        func_ov006_021cf7c8(self);
        break;
    case 1:
        switch (self->base.subState) {
        case 0:
            OV006_DELETE_OBJECT(self->unk4C);
            self->unk4C = ov006_MsgBox_New();
            func_ov000_021632f0(self->unk4C, 1, "script/other", "skyhelp.ccmes", 0);
            self->unk44->flags |= 4;
            self->unk48->flags |= 2;
            self->unk44->flags |= 4;
            self->unk44->flags |= 2;
            self->unk48->flags |= 2;
            self->base.subState++;
            break;
        case 1:
            if (!func_ov000_021633ac(self->unk4C)) {
                OV006_DELETE_OBJECT(self->unk4C);
                self->unk44->flags &= ~4;
                self->unk48->flags &= ~2;
                if (self->unk50 == NULL) {
                    self->base.state = 3;
                    self->base.subState = 0;
                } else {
                    self->base.state = 2;
                    self->base.subState = 0;
                }
            }
            break;
        }
        break;
    case 2:
        func_ov006_021cf89c(self);
        break;
    case 3:
        func_ov006_021cfa80(self);
        break;
    case 4: {
        func_ov006_021db65c();
        block = data_02fe152c->unk4C + 0x1d0;
        ent = func_0205976c(data_02fe152c, 0xe);
        n = func_0205975c(data_02fe152c, 0xe);
        for (i = 0; i < n; i++) {
            if (func_02059544(data_02fe152c, block, ent, 1, i)) {
                func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unkC = i | 0x7000;
                break;
            }
        }
        func_ov000_0218084c(data_ov000_021ccd44, 0x29, 0);
        data_ov006_021ec860->unk1C = 0;
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->base.state = 7;
        self->base.flags |= 6;
        self->base.subState = 0;
        break;
    }
    case 5:
        func_ov000_0218084c(data_ov000_021ccd44, 0x27, TRUE);
        data_ov006_021ec860->unk1C = TRUE;
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->base.flags |= 6;
        self->base.state = 7;
        self->base.subState = 0;
        break;
    case 6:
        func_ov006_021cfc60(self);
        break;
    case 7:
        break;
    }
    VCALL(self->unk44, 1C);
    VCALL(self->unk48, 1C);
    if (self->unk50 != NULL) {
        VCALL(self->unk50, 1C);
    }
    func_ov006_021e2f3c(self->unk54);
}

}
}  // namespace m_021cf420

// ---- merged from ov006_021cf7c4.cpp
namespace m_021cf7c4 {

extern "C" {

void func_ov006_021cf7c4(void) {
}

}
}  // namespace m_021cf7c4

// ---- merged from ov006_021cf7c8.cpp
namespace m_021cf7c8 {

extern "C" {

BOOL func_ov006_021e4c5c(ov006_Unk021ec888 *self);
void func_ov006_021cf360(ov006_TaskCE *self, u16 id);

void func_ov006_021cf7c8(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        func_ov006_021e4c5c(data_ov006_021ec888);
        self->base.subState++;
        break;
    case 1:
        if (data_ov006_021ec888->unk8 == 1) {
            self->base.subState++;
        }
        break;
    case 2:
        if (!data_0214a424->unk620_0) {
            data_0214a424->unk620_0 = 1;
            self->base.state = 1;
            self->base.subState = 0;
        } else if (self->unk50 == NULL) {
            self->base.state = 3;
            self->base.subState = 0;
        } else {
            self->base.state = 2;
            self->base.subState = 0;
        }
        self->base.unk20 = self->unk44->unk34;
        break;
    }
}

void func_ov006_021cf89c(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->unk50->flags &= ~2;
        func_02049a48(data_02097e4c, 0x26, -1, -1, -1);
        self->base.subState++;
        break;
    case 1:
        if (!VCALL(self->unk50, 0C)) {
            return;
        }
        if (!(data_02097dc8->unk12 & 1)) {
            return;
        }
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        self->unk50->flags |= 2;
        self->base.subState++;
        break;
    case 2:
        if (!ov006_Window_IsState5(self->unk50)) {
            return;
        }
        ov006_TaskCE_HideMenus(self);
        func_ov006_021cf360(self, ov006_Window_GetSelected(self->unk44)->id);
        self->base.state = 3;
        self->base.subState = 0;
        break;
    }
}

static inline BOOL ov006_Task_IsState2(ov006_Window *self) {
    return self->state == 2;
}

BOOL func_ov006_021cfa60(ov006_Window *self) {
    return ov006_Task_IsState2(self) ? TRUE : FALSE;
}

void func_ov006_021cfa80(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        ov006_TaskCE_HideMenus(self);
        func_ov006_021cf360(self, ov006_Window_GetSelected(self->unk44)->id);
        self->base.subState++;
        break;
    case 1:
        if (self->unk4C != NULL) {
            self->base.subState++;
            return;
        }
        if (!(data_02097dc8->unk12 & 2)) {
            return;
        }
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        {
            ov006_Window *w = self->unk44;
            VCALL(w, A8, func_ov000_02154b58(w, 5));
        }
        break;
    case 2:
        if (func_ov000_021633ac(self->unk4C)) {
            return;
        }
        OV006_DELETE_OBJECT(self->unk4C);
        self->unk44->flags &= ~4;
        self->unk48->flags &= ~2;
        func_ov006_021cf360(self, ov006_Window_GetSelected(self->unk44)->id);
        self->base.subState = 1;
        break;
    }
}

void func_ov006_021cfc60(ov006_TaskCE *self) {
    switch (self->base.subState) {
    case 0:
        ov006_TaskCE_ShowMenus(self);
        self->base.subState++;
        break;
    case 1:
        if (!ov006_Window_IsState5(self->unk44)) {
            return;
        }
        if (!ov006_Window_IsState5(self->unk48)) {
            return;
        }
        func_ov000_0218084c(data_ov000_021ccd44, 7, 1);
        VCALL(self, 4C);
        self->base.subState++;
        break;
    case 2:
        if (!VCALL(self, 54)) {
            return;
        }
        self->base.flags |= 6;
        self->base.subState++;
        break;
    case 3:
        if (self->base.unk8 != 0) {
            return;
        }
        func_0203cc58(0x14000, 1, 0);
        func_0203cc58(0x14000, 1, 1);
        self->base.subState++;
        break;
    case 4:
        if (!ov006_IsMode4()) {
            return;
        }
        data_ov006_021ec860->taskType = 3;
        self->base.state = 7;
        self->base.subState = 0;
        break;
    }
}

BOOL func_ov006_021cfe08(ov006_TaskCE *self) {
    if (VCALL(self, 54)) {
        ov006_SetCurrent021ccd40(NULL);
    }
    return TRUE;
}

static inline BOOL ov006_IsCurrent(void *p) {
    return data_ov000_021ccd40 == p;
}

BOOL func_ov006_021cfe5c(void *p) {
    return ov006_IsCurrent(p) ? TRUE : FALSE;
}

}
}  // namespace m_021cf7c8

// ---- merged from ov006_021cfe84.cpp
namespace m_021cfe84 {

extern "C" {

extern void *data_ov006_021ebcc0;

void func_ov006_021e309c(Object *a);
void MI_CpuFill8(void *dst, u8 value, u32 size);

void func_ov006_021cfe84(ov006_TaskCE *self) {
    if (self->unk44 != NULL) {
        VCALL(self->unk44, 20);
    }
    if (self->unk48 != NULL) {
        VCALL(self->unk48, 20);
    }
    if (self->unk4C != NULL) {
        func_ov000_02163594(self->unk4C);
    }
    if (self->unk50 != NULL) {
        VCALL(self->unk50, 20);
    }
    if (self->base.state == 3) {
        func_ov006_021e309c(self->unk54);
    }
}

static inline void ov006_TaskD0_Init(ov006_TaskD0 *self) {
    OV006_TASKBASE_CTOR(&self->base);
    self->base.vtbl = &data_ov006_021ebcc0;
    self->base.state = 0;
    self->base.subState = 0;
    MI_CpuFill8(self->names, 0, sizeof(self->names));
    self->unk104 = NULL;
    self->unk108 = NULL;
    self->unk10C = NULL;
    self->unk110 = 0;
}

ov006_TaskD0 *func_ov006_021cfefc(void) {
    ov006_TaskD0 *self = (ov006_TaskD0 *)func_0203dd9c(sizeof(ov006_TaskD0));
    if (self != NULL) {
        ov006_TaskD0_Init(self);
    }
    VCALL(self, 08, 0x27, 200);
    return self;
}

static inline void ov006_TaskD0_Dtor(ov006_TaskD0 *self) {
    self->base.vtbl = &data_ov006_021ebcc0;
    OV006_DELETE_OBJECT(self->unk104);
    OV006_DELETE_OBJECT(self->unk108);
    OV006_DELETE_OBJECT(self->unk10C);
    OV006_TASKBASE_DTOR(&self->base);
}

ov006_TaskD0 *func_ov006_021cff80(ov006_TaskD0 *self) {
    ov006_TaskD0_Dtor(self);
    return self;
}

ov006_TaskD0 *func_ov006_021d0080(ov006_TaskD0 *self) {
    ov006_TaskD0_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
}  // namespace m_021cfe84

// ---- merged from ov006_021d0188.cpp
namespace m_021d0188 {

extern "C" {

BOOL func_ov006_021e4c5c(ov006_Unk021ec888 *self);

void func_ov006_021d0188(void) {
    if (data_ov006_021ec888->unk8 != 1) {
        func_ov006_021e4c5c(data_ov006_021ec888);
    }
}

}
}  // namespace m_021d0188

// ---- merged from ov006_021d01ac.cpp
namespace m_021d01ac {


extern "C" {

extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021cad50;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cb4a8;
extern void *data_ov000_021cadcc;
extern void *data_ov006_021ebf40;

BOOL func_0201fd04(void);
BOOL func_ov006_021e4c38(ov006_Unk021ec888 *self);
BOOL func_ov006_021e4c84(ov006_Unk021ec888 *self);
BOOL func_ov006_021e4c5c(ov006_Unk021ec888 *self);
BOOL func_ov006_021e4cb4(ov006_Unk021ec888 *self);
BOOL func_ov006_021e4ce8(ov006_Unk021ec888 *self, ov006_MenuData *data);
void func_ov006_021e463c(ov006_Unk021ec888 *self);
ov006_MenuNode *func_ov006_021e48c0(ov006_Unk021ec888 *self, int id);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(void *a, int b, const void *c);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov000_02157c90(void *a, const void *b);
void func_ov000_02157d2c(void *a, const void *b);
void func_ov000_02173648(void *self);
void func_ov000_02153c48(ov006_ListNode *a, int b, int c, int d, int e);
void MIi_CpuClear32(int value, void *dst, u32 size);
void func_02040b0c(void *dst, int *dstLen, const void *src, int *srcLen);
int STD_CopyLString(void *dst, const void *src, u32 size);
void func_ov006_021d0ab8(ov006_TaskD0 *self);

BOOL func_ov006_021d01ac(ov006_TaskD0 *self) {
    BOOL r = FALSE;
    switch (self->base.state) {
    case 0:
        if (!func_0201fd04()) {
            self->base.state = 0;
            r = TRUE;
            self->unk110 = TRUE;
        } else if (data_ov006_021ec888->unk8 == 1) {
            func_ov006_021e4c38(data_ov006_021ec888);
            self->base.state = 1;
        }
        break;
    case 1:
        if (data_ov006_021ec888->unk8 == 3) {
            func_ov006_021e4c84(data_ov006_021ec888);
            self->base.state = 2;
        }
        break;
    default:
        r = TRUE;
        break;
    }
    return r;
}

static inline ov006_Window *ov006_NewWindow_cad50(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe8);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cad50;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cb4a8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe0);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb4a8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cadcc(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x8c);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cadcc;
        VCALL(w, 28);
    }
    return w;
}

void func_ov006_021d023c(ov006_TaskD0 *self) {
    ov006_ListNode *item;
    u16 i;
    void *res;
    if (VCALL(self, 28)) {
        return;
    }
    res = data_02149ef8;
    if (self->unk110) {
        self->unk10C = ov006_NewWindow_cad50();
        VCALL(self->unk10C, 08);
        func_ov000_0215c1bc(self->unk10C, 0x8000, func_0204c0e8(res, 0x19e));
        VCALL(self->unk10C, 70);
        self->base.flags &= ~2;
        func_ov000_02173648(self);
        return;
    }
    self->unk104 = ov006_NewWindow_cb4a8();
    VCALL(self->unk104, 10, func_0204c0e8(res, 0x12d));
    VCALL(self->unk104, 14, func_0204c0e8(res, 0x12e));
    func_ov000_02157c90(self->unk104, func_0204c0e8(res, 0x12f));
    func_ov000_02157d2c(self->unk104, func_0204c0e8(res, 0x130));
    self->unk104->unk4A = 0x2c00;
    self->unk104->unk20 = 5;
    ov006_Window_SetRot(self->unk104, 0, 0x2c, -0x1ccd);
    ov006_Window_SetPos(self->unk104, -0x100, 0, -0x1ccd);
    self->unk104->flags |= 0x400000;
    self->unk104->flags &= ~0x800000;
    self->unk104->unkC0 = 0x8c;
    self->unk104->unkC1 = 1;
    self->unk104->flags &= ~0x20000;
    self->unk104->flags &= ~0x40000;
    self->unk104->flags &= ~0x10000;
    for (i = 0; i < 4; i++) {
        item = (ov006_ListNode *)VCALL(self->unk104, 74, " ", i, 0xffff, 0);
        item->unk10 = 0;
    }
    item = (ov006_ListNode *)VCALL(self->unk104, 74, func_0204c0e8(res, 0x131), i, 0xffff, 0xffff);
    item->unk24 = 4;
    item->unk10 = 0;
    {
        ov006_Window *w = self->unk104;
        VCALL(w, A8, func_ov000_02154b58(w, 0));
    }
    VCALL(self->unk104, 08);
    self->unk104->flags &= ~2;
    self->unk108 = ov006_NewWindow_cadcc();
    self->unk108->unk24 = 0xf8;
    self->unk108->unk20 = 2;
    ov006_Window_SetRot(self->unk108, 4, 0x95, -0x199a);
    ov006_Window_SetPos(self->unk108, -0x100, 0, -0x199a);
    self->unk108->unk2C = 1;
    VCALL(self->unk108, 08);
    func_ov000_0215bb14(self->unk108, func_0204c0e8(res, 0x132));
    VCALL(self->unk108, 70);
    self->base.unk20 = self->unk104->unk34;
    self->base.flags &= ~2;
    func_ov000_02173648(self);
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
    self->base.flags |= 6;
    self->base.f.b0 = 1;
}

void func_ov006_021d065c(ov006_TaskD0 *self) {
    u16 trg = data_02097dc8->unk12;
    if (self->unk110) {
        if (trg & 1) {
            ov006_TaskD0_Close(self);
            ov006_TaskD0_HideWindows(self);
        }
    } else if (trg & 2) {
        self->base.subState = 0;
        self->unk104->flags &= ~0x2000000;
        ov006_TaskD0_Close(self);
        ov006_TaskD0_HideWindows(self);
        func_ov006_021e4c5c(data_ov006_021ec888);
    } else if (trg & 1) {
        ov006_ListNode *node = ov006_Window_GetSelected(self->unk104);
        if (node->unk10 == 0) {
            if (node->id == 4) {
                func_ov006_021e4cb4(data_ov006_021ec888);
                data_ov006_021ec888->unk15E = 2;
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                ov006_TaskD0_Close(self);
                self->base.subState = 2;
                ov006_TaskD0_HideWindows(self);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
        } else if (node->unkC >= 4) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            ov006_MenuNode *menu = func_ov006_021e48c0(data_ov006_021ec888, node->unk10);
            if (menu != NULL) {
                func_ov006_021e4ce8(data_ov006_021ec888, &menu->data);
                data_ov006_021ec888->unk15E = 2;
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                self->base.subState = 1;
                ov006_TaskD0_Close(self);
                ov006_TaskD0_HideWindows(self);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
                func_ov006_021d0ab8(self);
            }
        }
    }
}

void func_ov006_021d0938(ov006_TaskD0 *self) {
    if (self->unk110) {
        VCALL(self->unk10C, 1C);
        return;
    }
    if (!data_ov006_021ec888->unk2C && data_ov006_021ec888->unk26) {
        func_ov006_021d0ab8(self);
        data_ov006_021ec888->unk26 = 0;
    }
    VCALL(self->unk104, 1C);
    VCALL(self->unk108, 1C);
}

void func_ov006_021d09b8(ov006_TaskD0 *self) {
    if (self->base.unk8 != 0) {
        return;
    }
    if (self->base.subState == 3) {
        return;
    }
    switch (self->base.subState) {
    case 0:
        func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
        break;
    case 1:
        func_ov000_0218084c(data_ov000_021ccd44, 0x28, 2);
        break;
    case 2:
        func_ov000_0218084c(data_ov000_021ccd44, 0x28, 1);
        break;
    }
    self->base.subState = 3;
}

void func_ov006_021d0a40(ov006_TaskD0 *self) {
    if (!VCALL(self, 28)) {
        return;
    }
    if (self->unk110) {
        VCALL(self->unk10C, 20);
        return;
    }
    VCALL(self->unk104, 20);
    VCALL(self->unk108, 20);
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

void func_ov006_021d0ab8(ov006_TaskD0 *self) {
    u16 j;
    ov006_ListNode *item;
    int id;
    u16 i;
    ov006_MenuNode *node;
    int ids[4];
    if (self->unk104 == NULL) {
        return;
    }
    i = 0;
    MIi_CpuClear32(0, ids, sizeof(ids));
    for (node = data_ov006_021ec888->nodes; node != NULL; node = node->next) {
        ids[i] = node->id;
        i++;
        if (i >= 4) {
            break;
        }
    }
    for (j = 0; j < 4; j++) {
        u32 v;
        item = (ov006_ListNode *)func_ov000_02154b58(self->unk104, j);
        id = ids[j];
        if (id != 0) {
            int srcLen;
            int dstLen;
            ov006_MenuNode *menu = func_ov006_021e48c0(data_ov006_021ec888, id);
            srcLen = 0xb;
            dstLen = 0x30;
            func_02040b0c(self->names[j], &dstLen, (u8 *)menu + 0x60, &srcLen);
            v = ((u8 *)menu)[0x77];
        } else {
            STD_CopyLString(self->names[j], data_ov006_021ebbac, 0x30);
            v = 0;
        }
        item->unkC = v;
        item->unk10 = id;
        item->unk24 = v < 4 ? 0 : 0xe;
        item->text = NULL;
        OV006_DELETE_OBJECT(item->unk1C);
        item->text = self->names[j];
        func_ov000_02153c48(item, 8, 0, 1, 1);
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
    self->vtbl = &data_ov006_021ebf40;
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

ov006_TaskD0C *func_ov006_021d0c64(void) {
    ov006_TaskD0C *self = (ov006_TaskD0C *)func_0203dd9c(sizeof(ov006_TaskD0C));
    if (self != NULL) {
        ov006_TaskD0C_Init(self);
    }
    VCALL(self, 08, 0x28, 200);
    return self;
}

static inline void ov006_TaskD0C_Dtor(ov006_TaskD0C *self) {
    self->vtbl = &data_ov006_021ebf40;
    OV006_DELETE_OBJECT(self->unk11C);
    OV006_DELETE_OBJECT(self->unk120);
    OV006_DELETE_OBJECT(self->unk124);
    OV006_TASKBASE_DTOR(self);
}

ov006_TaskD0C *func_ov006_021d0d3c(ov006_TaskD0C *self) {
    ov006_TaskD0C_Dtor(self);
    return self;
}

ov006_TaskD0C *func_ov006_021d0e3c(ov006_TaskD0C *self) {
    ov006_TaskD0C_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
}  // namespace m_021d01ac

// ---- merged from ov006_021d0f44.cpp
namespace m_021d0f44 {

extern "C" {

void func_ov006_021d0f44(void) {
}

BOOL func_ov006_021d0f48(void) {
    return TRUE;
}

extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021cad50;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cb4a8;
extern void *data_ov000_021cadcc;
extern u8 *data_02097e40;

void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(void *a, int b, const void *c);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov000_02157c90(void *a, const void *b);
void func_ov000_02157d2c(void *a, const void *b);
void func_ov000_02173648(void *self);
void func_ov006_021daea0(ov006_SlotManager *a);
BOOL func_ov006_021db0a8(ov006_SlotManager *a, int b);
u32 func_ov006_021e60b4(void *a, int b);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);

static inline ov006_Window *ov006_NewWindow_cad50(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe8);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cad50;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cb4a8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe0);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb4a8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cadcc(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x8c);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cadcc;
        VCALL(w, 28);
    }
    return w;
}

static inline void ov006_SlotPacked_Clear(ov006_SlotPacked *self) {
    self->active = 0;
    self->isType1 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk0_8 = 0;
    MI_CpuFill8(self->name, 0, sizeof(self->name));
}

static inline void *ov006_GetRes(void) {
    return data_02149ef8;
}

void func_ov006_021d0f50(ov006_TaskD0C *self) {
    u16 i;
    void *res;
    if (VCALL(self, 28)) {
        return;
    }
    res = ov006_GetRes();
    self->unk11C = ov006_NewWindow_cb4a8();
    VCALL(self->unk11C, 10, func_0204c0e8(res, 0x133));
    VCALL(self->unk11C, 14, func_0204c0e8(res, 0x134));
    func_ov000_02157c90(self->unk11C, func_0204c0e8(res, 0x135));
    func_ov000_02157d2c(self->unk11C, func_0204c0e8(res, 0x136));
    self->unk11C->unk4A = 0x2c00;
    self->unk11C->unk20 = 4;
    ov006_Window_SetRot(self->unk11C, 0, 0x2c, -0x1ccd);
    ov006_Window_SetPos(self->unk11C, -0x100, 0, -0x1ccd);
    self->unk11C->flags |= 0x400000;
    self->unk11C->flags &= ~0x800000;
    self->unk11C->unkC0 = 0x8c;
    self->unk11C->unkC1 = 1;
    self->unk11C->flags &= ~0x20000;
    self->unk11C->flags &= ~0x40000;
    self->unk11C->flags &= ~0x10000;
    self->unk11C->flags |= 4;
    for (i = 0; i < 4; i++) {
        VCALL(self->unk11C, 74, " ", i, 0xffff, 0xffff);
    }
    self->unk11C->flags &= ~0x2000000;
    VCALL(self->unk11C, A8, 0);
    VCALL(self->unk11C, 08);
    self->unk11C->flags &= ~2;
    self->unk120 = ov006_NewWindow_cadcc();
    self->unk120->unk24 = 0xf8;
    self->unk120->unk20 = 2;
    ov006_Window_SetRot(self->unk120, 4, 0x95, -0x199a);
    ov006_Window_SetPos(self->unk120, -0x100, 0, -0x199a);
    self->unk120->unk2C = 1;
    VCALL(self->unk120, 08);
    func_ov000_0215bb14(self->unk120, func_0204c0e8(res, 0x138));
    VCALL(self->unk120, 70);
    self->unk124 = ov006_NewWindow_cad50();
    self->unk124->flags |= 0x10000;
    self->unk124->flags |= 0x20000;
    self->unk124->flags |= 2;
    func_ov000_0215c1bc(self->unk124, 0x8000, func_0204c0e8(res, 0x198));
    func_ov006_021daea0(data_ov006_021ec884);
    data_ov006_021ec860->unk1C = 1;
    MI_CpuFill8(data_02097e40 + 0x18e0, 0, 0x200);
    ov006_SlotPacked_Clear(&self->unk102);
    func_ov006_021e60b4(self->unk102.name, sizeof(self->unk102.name));
    self->unk102.active = 1;
    self->unk102.isType1 = 1;
    self->unk102.unkC = 0;
    self->unk102.unk10 = 0;
    if (func_ov006_021db0a8(data_ov006_021ec884, 9)) {
        self->unk102.unk10 = 1;
    } else if (func_ov006_021db0a8(data_ov006_021ec884, 10)) {
        self->unk102.unk10 = 2;
    }
    func_ov006_021e4a80(data_ov006_021ec888, self->unk101, 1, &self->unk102, 0x18);
    if (self->unkC == 1) {
        self->unk101 = 0;
    } else {
        self->unk101 = 1;
    }
    *(int *)&self->unk10[0x10] = self->unk11C->unk34;
    self->flags &= ~2;
    func_ov000_02173648(self);
}

}
}  // namespace m_021d0f44

// ---- merged from ov006_021d1490.cpp
namespace m_021d1490 {

extern "C" {

extern void *data_02149ef8;

u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov006_021db258(void);
void func_ov006_021d1b8c(ov006_TaskD0C *self);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, const void *b);

void func_ov006_021d1490(ov006_TaskD0C *self) {
    u16 trg = data_02097dc8->unk12;
    if (self->unk3C) {
        return;
    }
    if (trg & 2) {
        if (self->unkC == 2 && func_ov006_021e60e8(1, 1)) {
            return;
        }
        self->unk3C = 0x32;
        return;
    }
    if (!(trg & 1)) {
        return;
    }
    if (self->unkC != 1) {
        return;
    }
    if (self->unk40 < 2) {
        return;
    }
    if (data_ov006_021ec884->numActive >= 2) {
        self->unk3C = 5;
        return;
    }
    func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
}

void func_ov006_021d1570(ov006_TaskD0C *self) {
    if (self->unk8 == 9 || self->unk8 == 0xd) {
        if (data_ov006_021ec888->unk8 != 9) {
            u8 n;
            func_ov006_021e4a80(data_ov006_021ec888, self->unk101, 1, &self->unk102, 0x18);
            func_ov006_021db258();
            n = data_ov006_021ec884->numActive;
            if (self->unk40 != n) {
                func_ov006_021d1b8c(self);
                if (self->unkC == 1) {
                    void *res = data_02149ef8;
                    if (self->unk40 <= 1 && n >= 2) {
                        func_ov000_0215bb14(self->unk120, func_0204c0e8(res, 0x137));
                        VCALL(self->unk120, 70);
                    } else if (self->unk40 >= 2 && n <= 1) {
                        func_ov000_0215bb14(self->unk120, func_0204c0e8(res, 0x138));
                        VCALL(self->unk120, 70);
                    }
                }
                self->unk40 = n;
            }
        }
    }
    VCALL(self->unk11C, 1C);
    VCALL(self->unk120, 1C);
    VCALL(self->unk124, 1C);
}

}
}  // namespace m_021d1490

// ---- merged from ov006_021d1694.cpp
namespace m_021d1694 {

extern "C" {

void func_ov006_021d16a0(void *self);

void func_ov006_021d1694(void *self) {
    func_ov006_021d16a0(self);
}

}
}  // namespace m_021d1694

// ---- merged from ov006_021d16a0.cpp
namespace m_021d16a0 {

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021ccd34;

u16 func_ov006_021e60e8(int type, u16 mask);
BOOL func_ov006_021e4bec(ov006_Unk021ec888 *self, int a);
BOOL func_ov006_021e4c5c(ov006_Unk021ec888 *self);
void func_ov006_021e5e00(ov006_Unk021ec888 *self);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(ov006_Window *w, int a, void *str);

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
    for (i = 0; i < data_ov006_021ec884->numActive; i++) {
        ov006_Slot *slot = func_ov006_021db060(data_ov006_021ec884, i);
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

// The original reloads data_ov006_021ec884 after every block, so this function is built without CSE
#pragma opt_common_subs off
void func_ov006_021d16a0(ov006_TaskD0C *self) {
    switch (self->unk3C) {
    case 0:
        if (data_ov006_021ec888->unk8 == 9) {
            data_ov000_021ccd34 = 1;
            self->unk11C->flags |= 4;
            self->unk120->flags |= 4;
            self->unk3C = 30;
        }
        if (self->unkC != 2) {
            return;
        }
        if (!func_ov006_021e60e8(1, 1)) {
            return;
        }
        self->unk3C = 5;
    case 5:
        self->unk101 = 1;
        func_ov006_021e4bec(data_ov006_021ec888, 0);
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
            data_ov006_021ec884->unk14A[0] = 9;
        } else if (mn == 2) {
            data_ov006_021ec884->unk14A[0] = 10;
            func_ov000_0215c1bc(self->unk124, 0x8000, func_0204c0e8(data_02149ef8, 0x199));
        }
        VCALL(self->unk124, 70);
        self->unk124->flags &= ~2;
        *(u16 *)self->unk3E = 0;
        func_02049a48(data_02097e4c, 0x26, -1, -1, -1);
        self->unk3C++;
        break;
    }
    case 11:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk124->flags |= 2;
            self->unk3C = 30;
            return;
        }
        if ((*(u16 *)self->unk3E)++ > 0xb4) {
            self->unk3C = 20;
        }
        break;
    case 20:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk3C = 30;
            return;
        }
        if (!VCALL(self, 54)) {
            return;
        }
        func_0203cc58(0x14000, 0, 0);
        func_0203cc58(0x14000, 0, 1);
        *(int *)&self->unk10[0x10] = 0x50000;
        self->unk3C = 60;
        break;
    case 30:
        func_ov006_021e5e00(data_ov006_021ec888);
        self->unk3C++;
    case 31:
        if (data_ov006_021ec888->unk8 != 9) {
            self->unk3C = 50;
        }
        break;
    case 50:
        ov006_TaskD0C_ShowAll(self);
        self->flags |= 6;
        func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
        func_ov006_021e4c5c(data_ov006_021ec888);
        self->unk3C = 70;
        break;
    case 60:
        ov006_TaskD0C_ShowAll(self);
        self->flags |= 6;
        func_ov000_0218084c(data_ov000_021ccd44, 0x29, self->unkC);
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

extern void *data_02149ef8;
extern const int data_ov006_021eb77c[];
extern const u8 data_ov006_021eb6fe[];
extern const u8 data_ov006_021eb710[][3];
extern const u16 data_ov006_021eb78c[];
extern void *data_ov006_021ebec0;

void func_ov006_021e463c(ov006_Unk021ec888 *self);
void func_02040b0c(void *dst, int *dstLen, const void *src, int *srcLen);
void func_ov000_02153c48(ov006_ListNode *a, int b, int c, int d, int e);
void func_ov000_021548cc(void *a, int b);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021d3498(ov006_TaskD1F *self, u16 id, BOOL dir);
ov006_Unk020706a0 *func_020706a0(u16 id);
void func_ov006_021e139c(ov006_Unk021e139c *self, int a, int b, u8 c);
ov006_TaskD1F *func_ov006_021d1f68(ov006_TaskD1F *self);

void func_ov006_021d1b24(ov006_TaskD0C *self) {
    if (!VCALL(self, 28)) {
        return;
    }
    VCALL(self->unk11C, 20);
    VCALL(self->unk120, 20);
    VCALL(self->unk124, 20);
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

static inline bool ov006_Window_Bit1(ov006_Window *self) {
    return (self->flags << 30) >> 31;
}

static inline BOOL ov006_Window_IsBit1(ov006_Window *self) {
    return ov006_Window_Bit1(self) ? TRUE : FALSE;
}

void func_ov006_021d1b8c(ov006_TaskD0C *self) {
    u8 i;
    ov006_Slot *slot;
    ov006_ListNode *item;
    for (i = 0; i < 4; i++) {
        slot = func_ov006_021db060(data_ov006_021ec884, i);
        item = (ov006_ListNode *)func_ov000_02154b58(self->unk11C, i);
        if (slot->active) {
            int srcLen = 0xb;
            int dstLen = 0x30;
            func_02040b0c(self->names[i], &dstLen, slot->name, &srcLen);
            OV006_LISTNODE_SETTEXT(item, self->names[i]);
            item->unk24 = data_ov006_021eb77c[i];
            func_ov000_02153c48(item, 8, 0, 1, 1);
            item->unkC = (u16)(i + 1);
            if (i == data_ov006_021ec884->unk5) {
                ov006_Window *w = self->unk11C;
                if (!(ov006_Window_IsBit1(w) ? TRUE : FALSE)) {
                    w->flags |= 0x2000000;
                }
                VCALL(self->unk11C, A8, item);
                func_ov000_021548cc(self->unk11C, data_ov006_021eb6fe[i]);
                {
                    const u8 *c = data_ov006_021eb710[i];
                    self->unk11C->unk48 = c[0] | (c[1] << 5) | (c[2] << 10);
                }
            }
        } else {
            OV006_LISTNODE_SETTEXT(item, data_ov006_021ebbac);
            item->unk24 = 0;
            func_ov000_02153c48(item, 8, 0, 0, 0);
            item->unkC = 0xffff;
        }
    }
}

ov006_TaskD1F *func_ov006_021d1dbc(void) {
    ov006_TaskD1F *obj = (ov006_TaskD1F *)func_0203dd9c(sizeof(ov006_TaskD1F));
    if (obj != NULL) {
        obj = func_ov006_021d1f68(obj);
    }
    VCALL(obj, 08, 0x29, 0xc8);
    return obj;
}

BOOL func_ov006_021d1df8(ov006_Window *window, ov006_ListNode *node) {
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
        str = func_0204c0e8(data_02149ef8, data_ov006_021eb78c[(u16)(id & 0xfff)]);
        if (t->unk5C != NULL && str != NULL) {
            func_ov000_0215bb14(t->unk5C, str);
            VCALL(t->unk5C, 70);
        }
        func_ov006_021d3498(t, id, old > id);
        p = func_020706a0(id);
        func_ov006_021e139c(t->gauges[0], p->unk4 << 12, 0xa000, 1);
        func_ov006_021e139c(t->gauges[1], p->unk5 << 12, 0xa000, 1);
        func_ov006_021e139c(t->gauges[2], p->unk6 << 12, 0xa000, 1);
        func_ov006_021e139c(t->gauges[3], p->unk7 << 12, 0xa000, 1);
    }
    return TRUE;
}

BOOL func_ov006_021d1f00(ov006_Window *window, ov006_ListNode *node) {
    int *out = (int *)window->owner;
    if (node != NULL) {
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        *out = node->id;
    } else {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        *out = -1;
    }
    return FALSE;
}

ov006_TaskD1F *func_ov006_021d1f68(ov006_TaskD1F *self) {
    ov006_Slot *slot;
    OV006_TASKBASE_CTOR(&self->base);
    self->base.vtbl = &data_ov006_021ebec0;
    self->base.state = 0;
    self->base.subState = 0;
    self->unk44 = 0;
    self->unk48 = 1;
    self->unk49 = 0;
    self->unk4A = 0xffff;
    slot = func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5);
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
    self->base.vtbl = &data_ov006_021ebec0;
    OV006_DELETE_OBJECT(self->unk54);
    OV006_DELETE_OBJECT(self->unk58);
    OV006_DELETE_OBJECT(self->unk5C);
    OV006_DELETE_OBJECT(self->unk60);
    OV006_DELETE_OBJECT(self->unk64);
    OV006_DELETE_OBJECT(self->unk68);
    for (i = 0; i < 4; i++) {
        OV006_DELETE_OBJECT(self->gauges[i]);
    }
    OV006_TASKBASE_DTOR(&self->base);
}

ov006_TaskD1F *func_ov006_021d2000(ov006_TaskD1F *self) {
    ov006_TaskD1F_Dtor(self);
    return self;
}

ov006_TaskD1F *func_ov006_021d21e4(ov006_TaskD1F *self) {
    ov006_TaskD1F_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
}  // namespace m_021d1b24
