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
const char *func_0207011c(u16 id);
const char *func_020701d4(u16 id);
s16 *func_020706a0(u16 id);
void func_ov000_02162b40(ov006_Chr021d3498 *chr, const char *a, const char *b, const char *c, const char *d,
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
    a = func_0207011c(id);
    b = func_020701d4(id);
    c = func_0207011c(id);
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
        s16 g = *func_020706a0(id);
        func_ov000_02162b40(self->unk58, a, b, c, d, "nut00", 0, g);
    }
}

}
}  // namespace m_021d3498
#undef OV006_FX_MUL

// ---- merged from ov006_021d3794.cpp
namespace m_021d3794 {

extern "C" {

void *func_ov006_021d3874(void *self);

void *func_ov006_021d3794(void) {
    void *obj = func_0203dd9c(0x140);
    if (obj != NULL) {
        obj = func_ov006_021d3874(obj);
    }
    VCALL(obj, 08, 0x2a, 0xc8);
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

extern void *data_ov006_021ebdc0;

ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
void func_0204b370(void *self);
void func_0204b420(void *self);
void func_ov000_0218ea20(void *self);
void func_ov000_0218fee4(void *self);
ov006_Model60 *func_ov000_0218e9c4(void *self);
void func_0203df0c(void *p);
void func_02035acc(const char *a, const char *b, int c);
const char *func_0207011c(u16 id);
const char *func_020701d4(u16 id);
int func_ov000_0218f110(ov006_Model60 *self);

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

BOOL func_ov006_021d37d0(ov006_Window *window, ov006_ListNode *node) {
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
    OV006_TASKBASE_CTOR(&self->head);
    self->head.vtbl = &data_ov006_021ebdc0;
    func_0204b370(self->unk7C);
    self->unk3C = 0;
    self->unk44 = 0;
    self->unk46 = 0;
    self->unk48 = 0;
    self->unk3D = 1;
    self->unk4C = self->unk4A = data_ov006_021ec884->unk6;
    self->unk50 = NULL;
    self->unk54 = NULL;
    self->unk58 = NULL;
    self->unk5C = NULL;
    self->unk60 = NULL;
    self->unk64 = NULL;
    self->unk68 = NULL;
    self->unk6C = NULL;
    self->unk70 = NULL;
    self->unk74 = NULL;
    self->unk138 = NULL;
    self->unk13C = NULL;
    return self;
}

#define OV006_DELETE_WITH(obj, dtor)                             \
    do {                                                         \
        void *saved_ = data_02097dd0->current;                   \
        data_02097dd0->current = data_02097dd0->unk8;            \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                void *p_ = (obj);                                \
                dtor(p_);                                        \
                func_0203de1c(p_);                               \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        data_02097dd0->current = saved_;                         \
    } while (0)

static inline void ov006_TaskD37_Dtor(ov006_TaskD37 *self) {
    self->head.vtbl = &data_ov006_021ebdc0;
    OV006_DELETE_OBJECT(self->unk50);
    OV006_DELETE_OBJECT(self->unk54);
    OV006_DELETE_OBJECT(self->unk58);
    OV006_DELETE_OBJECT(self->unk5C);
    OV006_DELETE_WITH(self->unk60, func_ov000_0218ea20);
    OV006_DELETE_WITH(self->unk64, func_ov000_0218fee4);
    OV006_DELETE_WITH(self->unk68, func_ov000_0218ea20);
    OV006_DELETE_WITH(self->unk6C, func_ov000_0218fee4);
    OV006_DELETE_WITH(self->unk70, func_ov000_0218ea20);
    if (self->unk74 != NULL) {
        func_0203df0c(self->unk74);
        self->unk74 = NULL;
    }
    OV006_DELETE_OBJECT(self->unk138);
    OV006_DELETE_OBJECT(self->unk13C);
    func_02035acc("ac/c1dum1", "c1dum1", 6);
    func_0204b420(self->unk7C);
    OV006_TASKBASE_DTOR(&self->head);
}

ov006_TaskD37 *func_ov006_021d3914(ov006_TaskD37 *self) {
    ov006_TaskD37_Dtor(self);
    return self;
}

ov006_TaskD37 *func_ov006_021d3c08(ov006_TaskD37 *self) {
    ov006_TaskD37_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
}  // namespace m_021d37d0
#undef OV006_DELETE_WITH

// ---- merged from ov006_021d3f04.cpp
namespace m_021d3f04 {


extern "C" {


ov006_Model60 *func_ov000_0218e9c4(void *self);
const char *func_0207011c(u16 id);
const char *func_020701d4(u16 id);

static inline ov006_Model60 *ov006_NewModel60(void) {
    void *p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    return (ov006_Model60 *)p;
}

static inline void ov006_Model60_SetName1(ov006_Model60 *m, const char *a, const char *b) {
    STD_CopyString(m->unk10, a);
    STD_CopyString(m->unk30, b);
    m->unk3 |= 2;
}

static inline void ov006_Model60_SetName2(ov006_Model60 *m, const char *a, const char *b) {
    STD_CopyString(m->unk4C, a);
    STD_CopyString(m->unk6C, b);
    m->unk3 |= 4;
}

void func_ov006_021d3f04(ov006_TaskD37 *self) {
    ov006_Model60 *m;
    u16 id;
    const char *a;
    const char *b;
    const char *c;
    const char *d;
    m = ov006_NewModel60();
    self->unk60 = m;
    ov006_Model60_SetName1(m, "menu/worldmap", "u3map1cld00");
    ov006_Model60_SetName2(self->unk60, "menu/worldmap", "u3map1cld00");
    self->unk60->unk0 = 0;
    self->unk68 = ov006_NewModel60();
    id = func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unkC;
    a = func_0207011c(id);
    b = func_020701d4(id);
    c = func_0207011c(id);
    d = func_020701d4(id);
    ov006_Model60_SetName1(self->unk68, a, b);
    ov006_Model60_SetName2(self->unk68, c, d);
    self->unk68->unk0 = 0;
    m = ov006_NewModel60();
    self->unk70 = m;
    ov006_Model60_SetName2(m, "ac/c1dum1", "c1dum1");
    self->unk70->unk0 = 0;
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

extern void *data_ov006_021ebdc0;

ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
void func_0204b370(void *self);
void func_0204b420(void *self);
void func_ov000_0218ea20(void *self);
void func_ov000_0218fee4(void *self);
ov006_Model60 *func_ov000_0218e9c4(void *self);
void func_0203df0c(void *p);
void func_02035acc(const char *a, const char *b, int c);
const char *func_0207011c(u16 id);
const char *func_020701d4(u16 id);
int func_ov000_0218f110(ov006_Model60 *self);

BOOL func_ov006_021d40a8(ov006_TaskD37 *self) {
    BOOL r = TRUE;
    if (self->unk60->unk0 >= 0) {
        r = (r & func_ov000_0218f110(self->unk60)) ? TRUE : FALSE;
    }
    if (self->unk68->unk0 >= 0) {
        r = (r & func_ov000_0218f110(self->unk68)) ? TRUE : FALSE;
    }
    if (self->unk70->unk0 >= 0) {
        r = (r & func_ov000_0218f110(self->unk70)) ? TRUE : FALSE;
    }
    return r;
}

}
}  // namespace m_021d40a8

// ---- merged from ov006_021d4118.cpp
namespace m_021d4118 {

#define F(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk020706a0 {
    s16 unk0;
} ov006_Unk020706a0;

typedef struct ov006_Rot021d4118 {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021d4118;

extern "C" {

extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cadcc;
extern void *data_ov000_021cb1b0;
extern void *data_ov000_021cb0b8;
extern const u16 data_ov006_021eb6fc;
extern const u8 data_ov006_021eb6fe[4];
extern const ov006_Rot021d4118 data_ov006_021eb702;
extern const ov006_Vec32 data_ov006_021eb764;
extern const ov006_Vec32 data_ov006_021eb734;

const u16 data_ov006_021eb6fc = 0x1000;
const u8 data_ov006_021eb6fe[4] = {0, 1, 3, 2};
const ov006_Rot021d4118 data_ov006_021eb702 = {0xfa80, 0x8200, 0};

void *func_0204c0e8(void *a, int id);
void func_ov006_021cd580(int a, void *b, int c);
void func_ov000_021548cc(void *a, int b);
void *func_ov000_02154b80(void *a, int b);
BOOL func_ov006_021d37d0(ov006_Window *window, ov006_ListNode *node);
BOOL func_ov006_021d1f00(ov006_Window *window, ov006_ListNode *node);
void func_ov000_0215bb14(void *a, const void *b);
ov006_Obj58 *func_ov006_021dbcb8(void *p);
ov006_Model64 *func_ov000_0218fe1c(void *p);
void func_ov000_0218ffdc(ov006_Model64 *a, ov006_Model60 *b, int c, int d);
void func_ov000_02190cb0(void *a, const void *b, int c, int d);
void func_ov000_021915a0(void *a);
void *func_ov000_02190a30(void *a, int b);
void func_ov000_021911c8(void *a, int b);
ov006_Unk020706a0 *func_020706a0(u16 id);
void func_ov006_021d526c(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop);
void *func_ov006_021e07b0(void *p);
void func_ov006_021e0954(void *p);
void func_ov006_021e0ca8(void *p, void *a, int b);
ov006_Obj13C *func_ov006_021e1484(void *p);
void func_ov006_021e16b0(ov006_Obj13C *p);
ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
void func_ov006_021e4b90(ov006_Unk021ec888 *self);
void func_ov000_02173648(void *self);

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

static inline ov006_Window *ov006_NewWindow_cb0b8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x1e4);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb1b0;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb0b8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Model64 *ov006_NewModel64(void) {
    void *p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    return (ov006_Model64 *)p;
}

static inline void ov006_SetPos3(void *p, int x, int y, int z) {
    F(p, 0xb0, int) = x;
    F(p, 0xb4, int) = y;
    F(p, 0xb8, int) = z;
}

static inline void ov006_SetPair(void *p, int off, int x, int y) {
    F(p, off, int) = x;
    F(p, off + 4, int) = y;
}

static inline void ov006_SetPair2(void *p, int x, int y) {
    F(p, 0x10, int) = x;
    F(p, 0x14, int) = y;
}

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

static inline void ov006_SetCam(void *self, const ov006_Vec32 *at, const ov006_Vec32 *up, const ov006_Rot021d4118 *rot, int fovy) {
    F(self, 0x8c, ov006_Vec32) = *at;
    F(self, 0x98, ov006_Vec32) = *up;
    F(self, 0xbe, ov006_Rot021d4118) = *rot;
    F(self, 0xc4, int) = fovy;
    F(self, 0xbc, u16) = 1;
}

static inline void ov006_SetCam2(void *self, ov006_Vec32 at, ov006_Vec32 up, ov006_Rot021d4118 rot, int fovy) {
    F(self, 0x8c, ov006_Vec32) = at;
    F(self, 0x98, ov006_Vec32) = up;
    F(self, 0xbe, ov006_Rot021d4118) = rot;
    F(self, 0xc4, int) = fovy;
    F(self, 0xbc, u16) = 1;
}

void func_ov006_021d4118(ov006_TaskD37 *self) {
    s32 kq;
    void *res;
    ov006_Info021daaa8 *info;
    u16 id;
    if (VCALL(self, 28)) {
        return;
    }
    res = data_02149ef8;
    self->unk50 = ov006_NewWindow_caec8();
    VCALL(self->unk50, 10, func_0204c0e8(res, 0x12a));
    VCALL(self->unk50, 14, func_0204c0e8(res, 0x12b));
    self->unk50->unk4A = 0x2c00;
    self->unk50->unk20 = 5;
    self->unk50->unk24 = 0x9c;
    ov006_Window_SetRot(self->unk50, 0, 0x1e, -0x199a);
    self->unk50->unk68 = -0x199a;
    ov006_Window_SetPos(self->unk50, -0xff, 0, -0x199a);
    self->unk50->flags &= ~0x400000;
    self->unk50->flags &= ~0x800000;
    self->unk50->flags &= ~0x80000;
    self->unk50->flags &= ~0x20000;
    self->unk50->flags &= ~0x40000;
    self->unk50->flags &= ~0x10000;
    func_ov006_021cd580(5, self->unk50, 0);
    kq = 0xffff;
    if ((u32)self & 3) {
        kq = 0xffff;
    }
    VCALL(self->unk50, 08);
    func_ov000_021548cc(self->unk50, data_ov006_021eb6fe[data_ov006_021ec884->unk5]);
    if (self->unk4A != kq && self->head.unkC == 0) {
        ov006_Window *w = self->unk50;
        VCALL(w, A8, func_ov000_02154b58(w, self->unk4A));
    } else {
        ov006_Window *w = self->unk50;
        VCALL(w, A8, func_ov000_02154b80(w, 0));
    }
    self->unk50->owner = self;
    self->unk50->unk88 = func_ov006_021d37d0;
    self->unk50->flags |= 4;
    self->unk54 = ov006_NewWindow_cadcc();
    self->unk54->unk24 = 0xf8;
    self->unk54->unk20 = 2;
    ov006_Window_SetRot(self->unk54, 4, 0x95, -0x199a);
    ov006_Window_SetPos(self->unk54, -0x100, 0, -0x199a);
    self->unk54->unk2C = 1;
    VCALL(self->unk54, 08);
    if (self->head.unkC == 2) {
        func_ov000_0215bb14(self->unk54, func_0204c0e8(res, 0x13f));
        VCALL(self->unk54, 70);
    }
    {
        void *p = func_0203dd9c(0xec);
        if (p != NULL) {
            p = func_ov006_021dbcb8(p);
        }
        self->unk58 = (ov006_Obj58 *)p;
    }
    ov006_SetPos3(self->unk58, 0xbf000, 0x50000, F(self->unk58, 0xb8, int));
    F(self->unk58, 0xb8, int) = -0x1fccd;
    self->unk64 = ov006_NewModel64();
    func_ov000_0218ffdc(self->unk64, self->unk60, 0, 1);
    func_ov000_02190cb0(self->unk64, "s00", 0, 1);
    F(self->unk64, 0xb4, s16) = 0;
    func_ov000_021915a0(self->unk64);
    F(func_ov000_02190a30(self->unk64, 0), 0x112, s16) = 0x400;
    self->unk6C = ov006_NewModel64();
    func_ov000_0218ffdc(self->unk6C, self->unk68, 0, 1);
    func_ov000_02190cb0(self->unk6C, "nut00", 0, 1);
    F(self->unk6C, 0xb4, s16) = 0;
    func_ov000_021915a0(self->unk6C);
    func_ov000_021911c8(self->unk6C, func_020706a0(func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unkC)->unk0);
    func_ov006_021d526c(self, "s00", 0x400, 1);
    {
        ov006_Vec32 at = data_ov006_021eb764;
        ov006_Vec32 up = data_ov006_021eb734;
        ov006_Rot021d4118 rot = data_ov006_021eb702;
        ov006_SetCam(self, &at, &up, &rot, 0x4400);
    }
    {
        void *p = func_0203dd9c(0x2c);
        if (p != NULL) {
            p = func_ov006_021e07b0(p);
        }
        self->unk138 = (ov006_Unk68 *)p;
    }
    F(self->unk138, 0x20, int) = 1;
    func_ov006_021e0954(self->unk138);
    ov006_SetPair(self->unk138, 0x8, -0xa0, -0x61);
    ov006_SetPair2(self->unk138, 0x11, 0);
    func_ov006_021e0ca8(self->unk138, func_0204c0e8(res, 0x12a), 4);
    F(self->unk138, 0x1c, int) = -0x1e;
    {
        void *p = func_0203dd9c(0x30);
        if (p != NULL) {
            p = func_ov006_021e1484(p);
        }
        self->unk13C = (ov006_Obj13C *)p;
    }
    ov006_SetPair(self->unk13C, 0x8, 0, 0xc);
    func_ov006_021e16b0(self->unk13C);
    self->unk5C = ov006_NewWindow_cb0b8();
    F(self->unk5C, 0x1d8, u16) = 0x12c;
    F(self->unk5C, 0x1dc, void *) = func_0204c0e8(res, 0x18);
    F(self->unk5C, 0x1e0, u16) = 1;
    self->unk5C->unk84 = func_ov006_021d1f00;
    self->unk5C->owner = (u8 *)self + 0x40;
    VCALL(self->unk5C, 08);
    self->unk5C->unk68 = -0x1666;
    self->unk5C->flags |= 2;
    if (self->head.unkC != 0) {
        self->unk3D = 0;
    }
    id = ov006_Window_GetSelected(self->unk50)->id;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
    self->unk4C = self->unk4A;
    func_ov006_021e4b90(data_ov006_021ec888);
    self->unk44 = 4;
    self->unk48 = self->unk4A;
    func_ov000_02173648(self);
    self->head.flags &= ~2;
}

}
}  // namespace m_021d4118
#undef F

// ---- merged from ov006_021d4880.cpp
namespace m_021d4880 {

#define F(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *data_02097e40;

u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021dc048(ov006_Obj58 *p);
void func_ov006_021e5e00(ov006_Unk021ec888 *self);
void func_ov000_02190cb0(void *a, const void *b, int c, int d);
void *func_ov000_02190a30(void *a, int b);
void func_ov006_021d526c(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop);
ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

static inline BOOL ov006_IsUnlocked(int type, u16 mask) {
    BOOL r = TRUE;
    if (func_ov006_021e60e8(type, mask) == 0) {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov006_Anm_InRange(ov006_Anm74 *a, int start, int len) {
    return a->frame >= start && a->frame < start + len;
}

void func_ov006_021d4880(ov006_TaskD37 *self) {
    switch (self->unk3C) {
    case 0:
        if (self->head.unkC != 0) {
            if (data_ov006_021ec888->unk8 == 9) {
                self->unk3C = 100;
                return;
            }
            if (self->head.unkC == 1) {
                BOOL ok = ov006_IsUnlocked(5, 1);
                if (!ok) {
                    u16 m = data_02097e40->unk32;
                    if (m == func_ov006_021e60e8(4, m)) {
                        self->unk44 = 5;
                    }
                }
                if (ok) {
                    self->unk3C++;
                }
            } else if (self->head.unkC == 2) {
                if (ov006_IsUnlocked(5, 1)) {
                    self->unk3C++;
                }
            }
        } else {
            self->unk3C = 10;
        }
        break;
    case 1:
        self->unk44 = 0;
        if (self->head.unkC == 2) {
            self->unk3C = 0x28;
        } else {
            self->unk3C = 10;
        }
        break;
    case 10:
        self->unk50->flags &= ~4;
        self->unk3C++;
    case 11: {
        u16 trg;
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk50->flags |= 4;
            self->unk3C = 100;
            return;
        }
        trg = data_02097dc8->unk12;
        if (trg & 2) {
            if (self->unk3D) {
                func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
                self->unk50->flags |= 2;
                self->unk54->flags |= 2;
                func_ov006_021dc048(self->unk58);
                if (self->unk138->unk4 == 1) {
                    self->unk138->unk4 = 2;
                }
                self->head.flags |= 6;
                self->unk3C = 0x78;
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
        } else if (trg & 1) {
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            self->unk3C = 0x14;
        }
        break;
    }
    case 20:
        self->unk50->flags |= 4;
        self->unk5C->flags &= ~2;
        {
            ov006_Window *w = self->unk5C;
            VCALL(w, A8, func_ov000_02154b58(w, 1));
        }
        self->unk3C++;
        break;
    case 21:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk5C->flags |= 2;
            self->unk3C = 100;
            return;
        }
        if (!ov006_Window_IsState5(self->unk5C)) {
            return;
        }
        if (F(self, 0x40, int) == 0) {
            self->unk44 = 6;
            self->unk3C = 0x1e;
        } else {
            self->unk3C = 10;
        }
        break;
    case 30:
        self->unk50->flags |= 2;
        self->unk54->flags |= 2;
        func_ov006_021dc048(self->unk58);
        func_ov000_02190cb0(self->unk64, "s01", 0, 1);
        F(func_ov000_02190a30(self->unk64, 0), 0x112, u16) = 0xb33;
        func_ov006_021d526c(self, "s01", 0x1000, 0);
        {
            ov006_Info021daaa8 *info = func_ov006_021daaa8(self->unk4A);
            ov006_SlotManager *m = data_ov006_021ec884;
            m->unk6 = self->unk4A;
            m->unk8 = (ov006_SlotManagerInfo *)info;
        }
        self->unk3C++;
        break;
    case 31:
        if (data_ov006_021ec888->unk8 == 9) {
            func_ov006_021dc048(self->unk58);
            self->unk3C = 100;
            return;
        }
        {
            int f = self->unk74->frame;
            s16 len = self->unk7A;
            if ((f >= 0x10000 && f < 0x10000 + len) || (f >= 0x1e000 && f < 0x1e000 + len)) {
                func_02049a48(data_02097e4c, 0x32, -1, -1, -1);
            } else if (f >= 0xb000 && f < 0xb000 + len) {
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
            }
        }
        if (self->unk74->frame >= (self->unk74->res->numFrame << 12) - 0x1000) {
            self->head.flags |= 6;
            func_0203cc58(0x14000, 0, 0);
            func_0203cc58(0x14000, 0, 1);
            self->unk3C = 0x6e;
        }
        break;
    case 40:
        if (data_ov006_021ec888->unk8 == 9) {
            self->unk3C = 100;
            return;
        }
        if (!func_ov006_021e60e8(6, 1)) {
            return;
        }
        VCALL(self->unk50, A8, func_ov000_02154b58(self->unk50, self->unk4C));
        ov006_TaskD37_Select(self, self->unk4C);
        self->unk3C = 0x1e;
        break;
    case 100:
        func_ov006_021e5e00(data_ov006_021ec888);
        self->unk3C++;
    case 101:
        if (data_ov006_021ec888->unk8 == 9) {
            return;
        }
        func_0203cc58(0x1e000, 0, 0);
        func_0203cc58(0x1e000, 0, 1);
        self->unk3C++;
        break;
    case 102:
        if (ov006_IsMode4() && ov006_IsMode4b()) {
            self->unk50->flags |= 2;
            self->unk54->flags |= 2;
            func_ov006_021dc048(self->unk58);
            self->head.flags |= 6;
            self->unk3C = 0x82;
        }
        break;
    }
}

}
}  // namespace m_021d4880
#undef F

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

typedef struct ov006_Model64Obj {
    u8 unk0[0x78];
    VecFx32 trans;
    MtxFx33 rot;
    VecFx32 scale;
} ov006_Model64Obj;

extern "C" {

extern void *data_02097e40;

ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
ov006_Unk02046a50 *func_02046a50(void *a, int idx);
void func_ov006_021dc054(ov006_Obj58 *a);
void func_ov006_021dc578(ov006_Obj58 *a);
void func_ov006_021e0af4(ov006_Unk68 *self);
void func_ov006_021e0b80(ov006_Unk68 *self);
void func_ov006_021e1af0(ov006_Obj13C *a);
void func_ov006_021e1bb4(ov006_Obj13C *a);
void func_ov000_02190a80(ov006_Model64 *a, int b);
void func_ov000_021903b4(ov006_Model64 *a);
BOOL func_ov006_021d5368(ov006_TaskD37 *self, ov006_Model64 *obj);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov006_021cd580(int a, int b, int c);
void func_ov006_021e4b90(ov006_Unk021ec888 *self);
void func_ov006_021e463c(ov006_Unk021ec888 *self);
void *func_0203de84(u32 size, int align);
void MI_CpuFill8(void *dst, u8 value, u32 size);
int STD_TSNPrintf(char *dst, u32 size, const char *fmt, ...);
void MIi_CpuClearFast(u32 data, void *destp, u32 size);

static inline void ov006_Window_SetSel(ov006_Window *w, u16 id) {
    int idx = func_ov000_02154b58(w, id);
    VCALL(w, A8, idx);
}

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, "menu/skyrace_menu", info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, "menu/skyrace_map", info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

void func_ov006_021d4f64(ov006_TaskD37 *self) {
    BOOL done = FALSE;
    if (self->head.unk8 == 0xd && self->head.unkC != 0 && data_ov006_021ec888->unk8 != 9) {
        ov006_Unk02046a50 *p;
        done = TRUE;
        p = func_02046a50(data_02097e40, 0);
        if (self->head.unkC == 2 && self->unk3C == 0x28) {
            self->unk4C = p->unk4;
            if (self->unk4A != self->unk4C) {
                VCALL(self->unk50, A8, func_ov000_02154b58(self->unk50, self->unk4C));
                ov006_TaskD37_Select(self, self->unk4C);
            }
        }
    }
    VCALL(self->unk50, 1C);
    VCALL(self->unk54, 1C);
    func_ov006_021dc054(self->unk58);
    func_ov006_021e0af4(self->unk138);
    func_ov006_021e1af0(self->unk13C);
    VCALL(self->unk5C, 1C);
    func_ov000_02190a80(self->unk64, 0x1000);
    func_ov000_02190a80(self->unk6C, 0x1000);
    func_ov006_021d5368(self, self->unk6C);
    if (!done) {
        return;
    }
    if (self->head.unkC == 1) {
        self->unk48 = self->unk4A;
    }
    func_ov006_021e4a80(data_ov006_021ec888, self->unk44, 2, &self->unk46, 4);
}

void func_ov006_021d513c(ov006_TaskD37 *self) {
    if (self->head.unk8 != 0) {
        return;
    }
    switch (self->unk3C) {
    case 0x6e:
        func_ov006_021cd580(6, 1, self->head.unkC);
        self->unk3C++;
        break;
    case 0x78:
        func_ov006_021cd580(6, 0, self->head.unkC);
        self->unk3C++;
        break;
    case 0x82:
        func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
        self->unk3C++;
        break;
    }
    func_ov006_021e4b90(data_ov006_021ec888);
}

void func_ov006_021d51cc(ov006_TaskD37 *self) {
    if (!VCALL(self, 28)) {
        return;
    }
    func_ov006_021e0b80(self->unk138);
    func_ov006_021e1bb4(self->unk13C);
    func_ov006_021dc578(self->unk58);
    VCALL(self->unk50, 20);
    VCALL(self->unk54, 20);
    VCALL(self->unk5C, 20);
    VCALL(self->unk7C, 00);
    func_ov000_021903b4(self->unk64);
    func_ov000_021903b4(self->unk6C);
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

void func_ov006_021d526c(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop) {
    void **res;
    char buf[0x10];
    if (self->unk70 == NULL || name == NULL) {
        return;
    }
    if (self->unk74 == NULL) {
        self->unk74 = (ov006_Anm74 *)func_0203de84(0x100, 4);
    }
    res = self->unk70->unk48;
    MI_CpuFill8(buf, 0, sizeof(buf));
    STD_TSNPrintf(buf, sizeof(buf), "%s%s", self->unk70->unk6C, name);
    self->unk74->res = (typeof(self->unk74->res))NNS_G3dGetAnmByName(*res, (const NNSG3dResName *)buf);
    self->unk74->frame = 0;
    self->unk74->speed = 0x1000;
    self->unk74->func = (void *)NNS_G3dFuncAnmJntNsBcaDefault;
    self->unk74->unk10 = 0;
    self->unk74->unk14 = 0;
    self->unk74->unk18 = 0x7f;
    self->unk74->unk19 = 0;
    self->unk78 = loop;
    self->unk7A = speed;
}

BOOL func_ov006_021d5368(ov006_TaskD37 *self, ov006_Model64 *m) {
    BOOL r;
    int end;
    int frame;
    ov006_Anm74 *anm;
    ov006_Model64Obj *obj;
    u32 flag;
    NNSG3dRS rs;
    NNSG3dJntAnmResult result;
    obj = (ov006_Model64Obj *)m;
    if (self->unk74 == NULL) {
        return FALSE;
    }
    r = FALSE;
    NNS_G3dRS = &rs;
    MIi_CpuClearFast(0, &rs, sizeof(rs));
    rs.funcJntScale = NNS_G3dGetJointScale_FuncArray[0];
    NNS_G3dFuncAnmJntNsBcaDefault(&result, (const NNSG3dAnmObj *)self->unk74, 0);
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
    obj->scale = result.scale;
    obj->trans = result.trans;
    MI_Copy36B(&result.rot, &obj->rot);
    NNS_G3dRS = NULL;
    anm = self->unk74;
    end = (anm->res->numFrame << 12) - 0x1000;
    frame = anm->frame + self->unk7A;
    if (self->unk78) {
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
