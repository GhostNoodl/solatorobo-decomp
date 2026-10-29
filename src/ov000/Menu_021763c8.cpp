// ov000 Menu translation unit: .text 0x021763c8..0x02180350 and its string pool
// (.data 0x021cba18..0x021cbac0). The former files are kept as they were, each in its own
// namespace, so that their local typedefs, inlines and extern declarations do not clash.
#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov000/LoCommon.h"
#include "ov000/VObj.h"
#include "nitro/fx.h"
#include "types.h"
#include "ov000/HeapScope.h"
#include "ov000/ModelPart.h"
#include "Main/Sys/Pad.h"

namespace m_Lo_021763c8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void func_ov000_021763c8(void) {
    u8 buf[0x20];
    if (LFLD(s8, data_ov000_021ccd34, 1) == 0) {
        VObj *obj;
        LO_FREE_V(data_ov000_021ccd34, 0x14);
        obj = (VObj *)func_0203dd9c(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            func_0205a6a0(obj);
        }
        LFLD(VObj *, data_ov000_021ccd34, 0x14) = obj;
        STD_CopyString(buf, "script/");
        STD_ConcatenateString(buf, "shpinfo");
        func_0205a840(LFLD(VObj *, data_ov000_021ccd34, 0x14), buf, "shop.ccscp");
    }
    LFLD(s8, data_ov000_021ccd34, 1) = LFLD(s8, data_ov000_021ccd34, 1) + 1;
}

}

}  // namespace m_Lo_021763c8

// ---- Lo_021764c4
namespace m_Lo_021764c4 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_0205a9c8(void *p);
BOOL func_0206f66c(void *p);
s32 func_0206ec48(void *p);
u16 func_0206f080(void *p);
s32 func_0206f0f4(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd34, 0x14))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_021764c4(void) {
    LFLD(s8, data_ov000_021ccd34, 1) = LFLD(s8, data_ov000_021ccd34, 1) - 1;
    if (LFLD(s8, data_ov000_021ccd34, 1) != 0) {
        return;
    }
    LO_FREE_V(data_ov000_021ccd34, 0x14);
}

}

}  // namespace m_Lo_021764c4

// ---- Stub_02176538
namespace m_Stub_02176538 {

extern "C" {

extern u8 data_ov000_021ccd34[];
extern u8 data_02fe1534[];
s32 func_0205a9c8(void *p);
BOOL func_0205aa30(void *p);

BOOL func_ov000_02176538(void) {
    BOOL result = TRUE;
    if (func_0205a9c8(*(void **)(data_ov000_021ccd34 + 0x14)) == 0) {
        result = FALSE;
    }
    return result;
}

void func_ov000_02176560(void) {
    if ((*(VObj **)(data_ov000_021ccd34 + 0x14))->vfunc_34() == 0) {
        func_0205aa30(*(void **)(data_ov000_021ccd34 + 0x14));
    }
}


void func_ov000_02176590(s16 v) {
    *(s16 *)(data_02fe1534 + 0x7a) = v;
    (*(VObj **)(data_ov000_021ccd34 + 0x14))->vfunc_38(1);
    *(s16 *)(data_02fe1534 + 0x7a) = 0;
}
}

}  // namespace m_Stub_02176538

// ---- Lo_021765c8
namespace m_Lo_021765c8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void func_ov000_021765c8(void) {
    u8 buf[0x20];
    if (LFLD(s8, data_ov000_021ccd34, 1) == 0) {
        VObj *obj;
        LO_FREE_V(data_ov000_021ccd34, 0x14);
        obj = (VObj *)func_0203dd9c(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, data_0208b318);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, data_0208bf54);
            func_0205a6a0(obj);
        }
        LFLD(VObj *, data_ov000_021ccd34, 0x14) = obj;
        STD_CopyString(buf, "script/");
        STD_ConcatenateString(buf, "shpinfo");
        func_0205a840(LFLD(VObj *, data_ov000_021ccd34, 0x14), buf, "shop.ccscp");
    }
    LFLD(s8, data_ov000_021ccd34, 1) = LFLD(s8, data_ov000_021ccd34, 1) + 1;
}

}

}  // namespace m_Lo_021765c8

// ---- Lo_021766c4
namespace m_Lo_021766c4 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_0205a9c8(void *p);
BOOL func_0206f66c(void *p);
s32 func_0206ec48(void *p);
u16 func_0206f080(void *p);
s32 func_0206f0f4(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd34, 0x14))) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov000_021766c4(void) {
    BOOL r = TRUE;
    if (!LoIsLoaded()) {
        r = FALSE;
    }
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}

}  // namespace m_Lo_021766c4

// ---- Lo_02176714
namespace m_Lo_02176714 {

extern "C" {
extern void *data_02149ef8;
extern void *data_02fe152c;
extern u8 *data_0214a424;
extern u8 data_02fe1534[];
extern void *data_0208ccc8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
void *func_0204c0e8(void *g, u32 id);
BOOL func_0205aa30(void *p);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void func_ov000_0215d990(void *self, s32 a);
void func_ov000_0215bb14(void *o, void *s);
void func_ov000_02157c90(void *self, void *a);
void func_ov000_02157d2c(void *self, void *arg);
void func_ov000_021546ec(void *a, const void *b, const char *c, u16 d);
s32 func_ov000_02184a04(s32 x);
u8 *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u16 func_02059544(void *a, void *b, void *c, int d, u16 e);
void *func_0206ec48(u32 id);
u16 func_0206f080(u32 id);
u32 func_0206f0f4(u32 id);
BOOL func_ov000_021774a4(void);
s32 func_ov000_02177698(void);

typedef struct { u16 a; u16 b; } Pair02176714;

void func_ov000_02176714(VObj *self) {
    void *g;
    VObj *o;
    LFLD(u32, self, 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
    if (!LFLD(VObj *, data_ov000_021ccd34, 0x14)->vfunc_34()) {
        func_0205aa30(LFLD(void *, data_ov000_021ccd34, 0x14));
    }
    g = data_02149ef8;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x3c) = o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x3c), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0x11;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x20000000;
    LFLD(VObj *, self, 0x3c)->vfunc_f4(1, func_0204c0e8(g, 0x32));
    LFLD(VObj *, self, 0x3c)->vfunc_f4(2, func_0204c0e8(g, 0x33));
    LFLD(VObj *, self, 0x3c)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = o;
    LFLD(s16, o, 0x64) = 0x86;
    LFLD(s16, o, 0x66) = 0x78;
    LFLD(s16, o, 0x68) = -0x1ccd;
    func_ov000_0215d980(LFLD(void *, self, 0x40), LFLD(s32, data_0214a424, 0x20), 0);
    LFLD(s32, LFLD(void *, self, 0x40), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s32, s, 0x58) = 0x80;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    LFLD(VObj *, self, 0x40)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x50) = o;
    LFLD(s32, o, 0x24) = 0xf8;
    LFLD(s32, LFLD(void *, self, 0x50), 0x20) = 2;
    {
        u8 *s = LFLD(u8 *, self, 0x50);
        LFLD(s16, s, 0x64) = 8;
        LFLD(s16, s, 0x66) = 0x95;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    LFLD(s16, LFLD(void *, self, 0x50), 0x48) = 0xb;
    LFLD(s32, LFLD(void *, self, 0x50), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x50);
        LFLD(s32, s, 0x58) = 0;
        LFLD(s32, s, 0x5c) = 0x40;
        LFLD(s32, s, 0x60) = 0;
    }
    LFLD(VObj *, self, 0x50)->vfunc_08();
    switch (func_ov000_02184a04(LFLD(s32, self, 0xc))) {
    case 0:
        o = (VObj *)func_0203dd9c(0x98);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021cae48;
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x44) = o;
        LFLD(s32, o, 0x84) = 4;
        {
            u8 *s = LFLD(u8 *, self, 0x44);
            LFLD(s16, s, 0x64) = 0x1a;
            LFLD(s16, s, 0x66) = 0x78;
            LFLD(s16, s, 0x68) = -0x1ccd;
        }
        func_ov000_0215d980(LFLD(void *, self, 0x44), 0, 0);
        LFLD(s32, LFLD(void *, self, 0x44), 0x2c) = 1;
        {
            u8 *s = LFLD(u8 *, self, 0x44);
            LFLD(s32, s, 0x58) = 0x80;
            LFLD(s32, s, 0x5c) = 0;
            LFLD(s32, s, 0x60) = 0;
        }
        LFLD(VObj *, self, 0x44)->vfunc_08();
        func_ov000_0215d990(LFLD(void *, self, 0x44), 0x120);
        LFLD(s32, LFLD(void *, self, 0x44), 0x24) = 0x66;
        LFLD(s32, LFLD(void *, self, 0x44), 0x28) = 0x19;
        o = (VObj *)func_0203dd9c(0x98);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021cae48;
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x84) = 4;
        {
            u8 *s = LFLD(u8 *, self, 0x48);
            LFLD(s16, s, 0x64) = 0x1a;
            LFLD(s16, s, 0x66) = 0x83;
            LFLD(s16, s, 0x68) = -0x1ccd;
        }
        func_ov000_0215d980(LFLD(void *, self, 0x48), 0, 0);
        LFLD(s32, LFLD(void *, self, 0x48), 0x2c) = 1;
        {
            u8 *s = LFLD(u8 *, self, 0x48);
            LFLD(s32, s, 0x58) = 0x80;
            LFLD(s32, s, 0x5c) = 0;
            LFLD(s32, s, 0x60) = 0;
        }
        LFLD(VObj *, self, 0x48)->vfunc_08();
        func_ov000_0215d990(LFLD(void *, self, 0x48), 0x121);
        LFLD(s32, LFLD(void *, self, 0x48), 0x24) = 0x66;
        LFLD(s32, LFLD(void *, self, 0x48), 0x28) = 0;
        o = (VObj *)func_0203dd9c(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb4a8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb2a8;
        }
        LFLD(VObj *, self, 0x4c) = o;
        LFLD(VObj *, self, 0x4c)->vfunc_10(func_0204c0e8(g, 0x98));
        LFLD(VObj *, self, 0x4c)->vfunc_14(func_0204c0e8(g, 0x99));
        func_ov000_02157c90(LFLD(void *, self, 0x4c), func_0204c0e8(g, 0xa1));
        func_ov000_02157d2c(LFLD(void *, self, 0x4c), func_0204c0e8(g, 0x3e));
        func_ov000_021546ec(LFLD(void *, self, 0x4c), data_0208ccc8, "cem3d1icn00", 0xffff);
        break;
    case 1:
        o = (VObj *)func_0203dd9c(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb4a8;
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x4c) = o;
        LFLD(VObj *, self, 0x4c)->vfunc_10(func_0204c0e8(g, 0xa9));
        LFLD(VObj *, self, 0x4c)->vfunc_14(func_0204c0e8(g, 0x99));
        func_ov000_02157c90(LFLD(void *, self, 0x4c), func_0204c0e8(g, 0xa3));
        func_ov000_02157d2c(LFLD(void *, self, 0x4c), func_0204c0e8(g, 0x3e));
        {
            u8 *base;
            u16 i;
            u32 n;
            base = LFLD(u8 *, data_02fe152c, 0x4c) + 0x130;
            o = (VObj *)func_0205976c(data_02fe152c, 9);
            n = func_0205975c(data_02fe152c, 9);
            for (i = 0; i < n; i++) {
                BOOL a = func_02059544(data_02fe152c, base, o, 1, i) & 1 ? TRUE : FALSE;
                BOOL b = func_02059544(data_02fe152c, base, o, 0x101, i) == 0 ? TRUE : FALSE;
                if ((a & b) ? TRUE : FALSE) {
                    u16 id = ((Pair02176714 *)o)[i].b;
                    void *x = func_0206ec48(id);
                    s32 y = func_0206f080(id);
                    LFLD(VObj *, self, 0x4c)->vfunc_74(x, ((Pair02176714 *)o)[i].b, (u16)y, func_0206f0f4(id));
                }
            }
        }
        break;
    case 3:
        o = (VObj *)func_0203dd9c(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb4a8;
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x4c) = o;
        LFLD(VObj *, self, 0x4c)->vfunc_10(func_0204c0e8(g, 0xaa));
        LFLD(VObj *, self, 0x4c)->vfunc_14(func_0204c0e8(g, 0x99));
        func_ov000_02157c90(LFLD(void *, self, 0x4c), func_0204c0e8(g, 0xa6));
        func_ov000_02157d2c(LFLD(void *, self, 0x4c), func_0204c0e8(g, 0x3e));
        func_ov000_021546ec(LFLD(void *, self, 0x4c), data_0208ccc8, "cem3d1icn00", 0xffff);
        break;
    }
    {
        u8 *d = data_02fe1534;
        LFLD(vu16, d, 0x7a) = LFLD(s32, self, 0xc);
        LFLD(VObj *volatile, data_ov000_021ccd34, 0x14)->vfunc_38(1);
        LFLD(u16, d, 0x7a) = 0;
    }
    LFLD(void *, LFLD(void *, self, 0x4c), 0x8) = self;
    LFLD(s32, LFLD(void *, self, 0x4c), 0x20) = 4;
    {
        u8 *s = LFLD(u8 *, self, 0x4c);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0x2c;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    LFLD(u8, LFLD(void *, self, 0x4c), 0xc0) = 0x78;
    LFLD(u32, LFLD(void *, self, 0x4c), 0xc) |= 0x400000;
    LFLD(void *, LFLD(void *, self, 0x4c), 0x84) = (void *)func_ov000_021774a4;
    LFLD(void *, LFLD(void *, self, 0x4c), 0x88) = (void *)func_ov000_02177698;
    {
        VObj *t = LFLD(VObj *, self, 0x4c);
        t->vfunc_a8(LFLD(s32, t, 0x98));
    }
    LFLD(VObj *, self, 0x4c)->vfunc_08();
    if (LFLD(void *, self, 0x50) == NULL) {
        return;
    }
    if (LFLD(s16, LFLD(void *, self, 0x4c), 0x9c) != 0) {
        return;
    }
    func_ov000_0215bb14(LFLD(void *, self, 0x50), func_0204c0e8(g, 0x9d));
    LFLD(VObj *, self, 0x50)->vfunc_70();
}

}

}  // namespace m_Lo_02176714

// ---- Lo_02176ff4
namespace m_Lo_02176ff4 {

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_0205a9c8(void *p);
BOOL func_0206f66c(void *p);
s32 func_0206ec48(void *p);
u16 func_0206f080(void *p);
s32 func_0206f0f4(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd34, 0x14))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_02176ff4(void *self) {
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
    LFLD(s32, self, 0x58) = 0;
    LFLD(u8, self, 0x5c) = 0;
}

}

}  // namespace m_Lo_02176ff4

// ---- Lo_02177028
namespace m_Lo_02177028 {

extern "C" {

void func_ov000_02177028(u8 *self) {
    LO_FREE_V(self, 0x58);
    LO_FREE_V(self, 0x3c);
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x48);
    LO_FREE_V(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LFLD(s8, data_ov000_021ccd34, 1) = LFLD(s8, data_ov000_021ccd34, 1) - 1;
    if (LFLD(s8, data_ov000_021ccd34, 1) != 0) {
        return;
    }
    LO_FREE_V(data_ov000_021ccd34, 0x14);
}
}

}  // namespace m_Lo_02177028

// ---- Stub_02177224
namespace m_Stub_02177224 {

extern "C" {

void func_ov000_02177224(void *self) {
    u8 *p = *(u8 **)((u8 *)self + 0x4c);
    if (p != NULL) {
        *(u32 *)(p + 0xc) &= ~4;
    }
}

void func_ov000_0217723c(void) {
}

}

}  // namespace m_Stub_02177224

// ---- Lo_02177240
namespace m_Lo_02177240 {

extern "C" {

static inline void SetFlag02177240(VObj *self) {
    u8 *p = LFLD(u8 *, self, 0x4c);
    if (p != NULL) {
        LFLD(u32, p, 0xc) |= 4;
    }
}

static inline BOOL IsBusy02177240(VObj *o) {
    return o != NULL && o->vfunc_1c();
}

void func_ov000_02177240(VObj *self) {
    s32 n;
    if (LFLD(s32, self, 0x8) == 0xd) {
        VObj *o = LFLD(VObj *, self, 0x58);
        if (o != NULL) {
            if (o->vfunc_1c()) {
                SetFlag02177240(self);
            } else {
                HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x58), p->vfunc_04());
            }
        }
        n = 0;
        if (LFLD(VObj *, self, 0x3c) != NULL && LFLD(VObj *, self, 0x3c)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x40) != NULL && LFLD(VObj *, self, 0x40)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x44) != NULL && LFLD(VObj *, self, 0x44)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x48) != NULL && LFLD(VObj *, self, 0x48)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x4c) != NULL && LFLD(VObj *, self, 0x4c)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x50) != NULL && LFLD(VObj *, self, 0x50)->vfunc_1c()) {
            n++;
        }
        if (n == 0) {
            self->vfunc_0c(0);
        }
    }
    SetFlag02177240(self);
}
}

}  // namespace m_Lo_02177240

// ---- Lo_021773cc
namespace m_Lo_021773cc {

extern "C" {

extern u8 *data_ov000_021ccd54;
void *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);

void func_ov000_021773cc(void *self) {
    s32 s;
    if (LFLD(void *, self, 0x24) == NULL || (s = LFLD(s32, self, 8)) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (LFLD(VObj *, self, 0x3c)) {
        LFLD(VObj *, self, 0x3c)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x40)) {
        LFLD(VObj *, self, 0x40)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x44)) {
        LFLD(VObj *, self, 0x44)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x48)) {
        LFLD(VObj *, self, 0x48)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x4c)) {
        LFLD(VObj *, self, 0x4c)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x50)) {
        LFLD(VObj *, self, 0x50)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x58)) {
        LFLD(VObj *, self, 0x58)->vfunc_20();
    }
}

}

}  // namespace m_Lo_021773cc

// ---- Menu_021774a4
namespace m_Menu_021774a4 {

typedef struct {
    u8 pad_00[0x3c];
    u8 *unk_3c;
    u8 *unk_40;
    u8 *unk_44;
    u8 *unk_48;
    u8 *unk_4c;
    u8 *unk_50;
    u8 pad_54[4];
    VObj *unk_58;
} Menu021774a4;

typedef struct {
    u8 pad_00[8];
    Menu021774a4 *unk_08;
} Self021774a4;

extern "C" {
extern void *data_02097e4c;
extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void *func_0203dd9c(u32 size);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 func_0204c0e8(void *msg, s32 id);
void func_ov000_0215c1bc(void *p, s32 a, s32 b);
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
s32 func_ov000_02177bd8(void);

static inline u8 *List021774a4_Cur(u8 *list) {
    u8 *p = LFLD(u8 *, list, 0x98);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = LFLD(s8, list, 0xb1);
    while (n-- != 0) {
        p = LFLD(u8 *, p, 0x2c);
    }
    return p;
}

#define SET_HIDE(x) if ((x) != NULL) LFLD(u32, (x), 0xc) |= 2

BOOL func_ov000_021774a4(Self021774a4 *self, BOOL ok) {
    Menu021774a4 *m = self->unk_08;
    u8 *item = List021774a4_Cur(m->unk_4c);

    if (!ok) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        SET_HIDE(m->unk_3c);
        SET_HIDE(m->unk_40);
        SET_HIDE(m->unk_44);
        SET_HIDE(m->unk_48);
        SET_HIDE(m->unk_4c);
        SET_HIDE(m->unk_50);
        SET_HIDE((u8 *)m->unk_58);
        return FALSE;
    }
    if (LFLD(s32, item, 0xc) == -1 ? TRUE : FALSE) {
        if (m->unk_58 == NULL) {
            VObj *o = (VObj *)func_0203dd9c(0xe8);
            if (o != NULL) {
                VOBJ_SET_VTABLE(o, data_ov000_021cac60);
                o->vfunc_28();
                VOBJ_SET_VTABLE(o, data_ov000_021cad50);
                o->vfunc_28();
            }
            m->unk_58 = o;
        }
        LFLD(s32, m->unk_58, 0x1c) = 4;
        m->unk_58->vfunc_08();
        LFLD(u32, m->unk_58, 0xc) |= 0x20000;
        func_ov000_0215c1bc(m->unk_58, 0x8000, func_0204c0e8(data_02149ef8, 0x9f));
        LFLD(s16, m->unk_58, 0x68) = -0x199a;
        m->unk_58->vfunc_70();
    } else {
        func_ov000_02152294(self, 0x90, 0x18, (void *)func_ov000_02177bd8);
    }
    return TRUE;
}
}

}  // namespace m_Menu_021774a4
#undef SET_HIDE

// ---- Lo_02177698
namespace m_Lo_02177698 {

typedef struct {
    u8 unk_00[0x72];
    u16 unk_72;
} Data02fe1534;

extern "C" {
extern Data02fe1534 data_02fe1534;
extern u8 *data_0214a424;
extern void *data_02097e4c;
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 func_0206d1d4(void *a, u16 b);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

static inline u8 *GetNth(u8 *m) {
    u8 *p = LFLD(u8 *, m, 0x98);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = LFLD(s8, m, 0xb1);
    while (n-- != 0) {
        p = LFLD(u8 *, p, 0x2c);
    }
    return p;
}


}

extern "C" {
extern void *data_02149ef8;
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);

s32 func_ov000_02177698(u8 *self, u8 *item) {
    u8 *o = LFLD(u8 *, self, 0x8);
    VObj *t = LFLD(VObj *, o, 0x50);
    if (t != NULL) {
        if (item != NULL) {
            u16 id;
            u8 *a;
            func_0206ecd4(0x100, o + 0x5c, LFLD(u16, item, 6));
            func_ov000_0215bb14(t, o + 0x5c);
            t->vfunc_70();
            id = LFLD(u16, item, 6);
            a = LFLD(u8 *, o, 0x44);
            if (id & 0x2000) {
                u8 *b;
                if (a != NULL) {
                    func_ov000_0215d980(a, LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a), 1);
                    LFLD(u32, a, 0xc) &= ~0x20;
                }
                b = LFLD(u8 *, o, 0x48);
                if (b != NULL) {
                    func_ov000_0215d980(b, func_0206d1d4(data_0214a424, LFLD(u16, item, 6)), 1);
                    LFLD(u32, b, 0xc) &= ~0x20;
                }
            } else {
                if (a != NULL) {
                    LFLD(u32, a, 0xc) |= 0x20;
                }
                if (LFLD(u8 *, o, 0x48) != NULL) {
                    LFLD(u32, LFLD(u8 *, o, 0x48), 0xc) |= 0x20;
                }
            }
        } else {
            func_ov000_0215bb14(t, func_0204c0e8(data_02149ef8, 0x9d));
            t->vfunc_70();
        }
    }
    return 1;
}

s32 func_ov000_021777d4(u8 *self, u16 id) {
    u8 *m = LFLD(u8 *, self, 0x4c);
    void *obj = LFLD(void *, self, 0x40);
    u8 *node = GetNth(m);
    u8 *g = data_0214a424;
    u32 t;
    data_02fe1534.unk_72 = id;
    t = LFLD(u32, node, 0xc);
    LFLD(u32, g, 0x20) = LFLD(u32, g, 0x20) > t ? LFLD(u32, g, 0x20) - t : 0;
    func_ov000_0215d980(obj, LFLD(u32, data_0214a424, 0x20), 0);
    if (id & 0x2000) {
        if (LFLD(void *, self, 0x44) != NULL) {
            func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a), 1);
        }
        void *o48 = LFLD(void *, self, 0x48);
        if (o48 != NULL) {
            func_ov000_0215d980(o48, func_0206d1d4(data_0214a424, id), 1);
        }
    }
    func_02049a48(data_02097e4c, 0x31, -1, -1, -1);
    return 0;
}
}

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
BOOL func_0206f21c(u16 a, s32 b);
void func_ov000_0215c1bc(void *self, s32 id, void *v);
void func_ov000_02153c48(u8 *self, s32 a, BOOL show, BOOL center, u8 d);

static inline void ShowMsg021778f0(u8 *self, s32 msg) {
    if (LFLD(VObj *, self, 0x58) == NULL) {
        VObj *o = (VObj *)func_0203dd9c(0xe8);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021cad50);
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x58) = o;
    }
    LFLD(s32, LFLD(VObj *, self, 0x58), 0x1c) = 4;
    LFLD(VObj *, self, 0x58)->vfunc_08();
    LFLD(u32, LFLD(VObj *, self, 0x58), 0xc) |= 0x20000;
    func_ov000_0215c1bc(LFLD(VObj *, self, 0x58), 0x8000, func_0204c0e8(data_02149ef8, msg));
    LFLD(s16, LFLD(VObj *, self, 0x58), 0x68) = -0x199a;
    LFLD(VObj *, self, 0x58)->vfunc_70();
}

static inline BOOL IsUnset021778f0(u8 *p) {
    return LFLD(s32, p, 0xc) == -1;
}

static inline BOOL IsCost021778f0(u32 c) {
    return c == (u32)-1;
}

static inline void Snd021778f0(s32 id) {
    func_02049a48(data_02097e4c, id, -1, -1, -1);
}

static inline void SetBit021778f0(void *p) {
    if (p != NULL) {
        LFLD(u32, p, 0xc) |= 2;
    }
}

static inline void AddCount021778f0(u16 n) {
    u8 *g = data_0214a424;
    LFLD(u16, g, 0x24) += n;
    if (LFLD(u16, g, 0x24) > 9999) {
        LFLD(u16, g, 0x24) = 9999;
    }
}

static inline void ResetItem021778f0(u8 *item) {
    if (LFLD(s32, item, 0x10) == 1) {
        LFLD(s32, item, 0x10) = 0;
        LFLD(s32, item, 0xc) = -1;
        LFLD(s32, item, 0x24) = 0xe;
        if (LFLD(void *, item, 0x1c) != NULL) {
            func_ov000_02153c48(item, 8, TRUE, 0, 0);
        }
    }
}

BOOL func_ov000_021778f0(u8 *self, u8 *item) {
    u16 id = LFLD(u16, item, 6);
    switch (((id >> 12) & 0xffff) - 1) {
    case 0:
        if (!func_ov000_021777d4(self, id)) {
            if (id == 0x1002) {
                AddCount021778f0(1);
            } else if (id == 0x1003) {
                AddCount021778f0(5);
            }
            return FALSE;
        }
        return TRUE;
    case 1:
        if (func_0206f21c(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                func_0206f21c(id, FALSE);
                return TRUE;
            }
            ResetItem021778f0(item);
        } else {
            ShowMsg021778f0(self, 0x9e);
        }
        break;
    case 4:
        if (func_0206f21c(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                func_0206f21c(id, FALSE);
                return TRUE;
            }
            LFLD(VObj *, self, 0x4c)->vfunc_70(item);
        }
        break;
    case 7:
        if (func_0206f21c(id, TRUE)) {
            if (func_ov000_021777d4(self, id)) {
                func_0206f21c(id, FALSE);
                return TRUE;
            }
            ResetItem021778f0(item);
        }
        break;
    }
    return FALSE;
}

static inline u8 *GetObj02177bd8(u8 *o) {
    return LFLD(u8 *, o, 0x40);
}

s32 func_ov000_02177bd8(VObj *self, u8 *item) {
    u8 *o = LFLD(u8 *, self, 8);
    u8 *m = LFLD(u8 *, o, 0x4c);
    u8 *obj = GetObj02177bd8(o);
    u8 *node = GetNth(m);
    u16 type;
    if (item == NULL) {
        Snd021778f0(0x1f);
        return 0;
    }
    type = LFLD(u16, item, 6);
    if (type == 0) {
        u32 cost = LFLD(u32, node, 0xc);
        if (IsCost021778f0(cost)) {
            ShowMsg021778f0(o, 0x9f);
        } else if (LFLD(u32, obj, 0x8c) >= cost) {
            if (func_ov000_021778f0(o, node)) {
                SetBit021778f0(LFLD(void *, o, 0x3c));
                SetBit021778f0(LFLD(void *, o, 0x40));
                SetBit021778f0(LFLD(void *, o, 0x44));
                SetBit021778f0(LFLD(void *, o, 0x48));
                SetBit021778f0(LFLD(void *, o, 0x4c));
                SetBit021778f0(LFLD(void *, o, 0x50));
                SetBit021778f0(LFLD(void *, o, 0x58));
                ((VObj *)o)->vfunc_3c();
                return 0;
            }
        } else {
            Snd021778f0(0x20);
            ShowMsg021778f0(o, 0x9b);
        }
        return 0;
    }
    if (type != 1) {
        return 1;
    }
    Snd021778f0(0x1f);
    return 0;
}
}

}  // namespace m_Lo_02177698

// ---- Lo_02177ec4
namespace m_Lo_02177ec4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

VObj *func_ov000_02177ec4(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x158);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbe60);
        LFLD(s32, obj, 0x3c) = 0;
        LFLD(s32, obj, 0x40) = 0;
        LFLD(s32, obj, 0x44) = 0;
        LFLD(s32, obj, 0x48) = 0;
        LFLD(s32, obj, 0x4c) = 0;
        LFLD(s32, obj, 0x50) = 0;
        LFLD(s32, obj, 0x54) = 0;
        LFLD(u8, obj, 0x58) = 0;
    }
    obj->vfunc_08(0xa, 0xc8);
    return obj;
}

}

}  // namespace m_Lo_02177ec4

// ---- Lo_02177f40
namespace m_Lo_02177f40 {

extern "C" {

extern u8 *data_0214a424;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

BOOL func_ov000_02177f40(void *self, void *msg) {
    u16 id;
    void *o;
    if (msg == NULL) {
        return FALSE;
    }
    id = LFLD(u16, msg, 6);
    o = LFLD(void *, self, 8);
    if (((u32)(id << 4) >> 16) - 1 == 1) {
        s32 c;
        u32 v;
        v = LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a);
        c = LFLD(s32, msg, 0xc);
        {
            u16 *p = &LFLD(u16, LFLD(void *, o, 0x54), 0x8a);
            *p = v > 1 ? v : 1;
        }
        LFLD(s32, LFLD(void *, o, 0x54), 0x8c) = c;
        LBIT(LFLD(void *, o, 0x54), 0xc).b2 = 0;
        LBIT(LFLD(void *, o, 0x54), 0xc).b1 = 0;
        LFLD(u16, LFLD(void *, o, 0x54), 0x88) = 1;
        LBIT(LFLD(void *, o, 0x3c), 0xc).b2 = 1;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
    }
    return TRUE;
}

}

}  // namespace m_Lo_02177f40

// ---- Lo_02178010
namespace m_Lo_02178010 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

BOOL func_ov000_02178010(void *self, void *msg) {
    void *o = LFLD(void *, self, 8);
    if (msg == NULL || LFLD(u16, msg, 6) == 0xffff) {
        VObj *p = LFLD(VObj *, o, 0x40);
        func_ov000_0215bb14(p, func_0204c0e8(data_02149ef8, 0x9d));
        p->vfunc_70();
    } else {
        VObj *p = LFLD(VObj *, o, 0x40);
        func_0206ecd4(0x100, (u8 *)o + 0x58, LFLD(u16, msg, 6));
        func_ov000_0215bb14(p, (u8 *)o + 0x58);
        p->vfunc_70();
        if (LFLD(void *, o, 0x48) != NULL) {
            func_ov000_0215d980(LFLD(void *, o, 0x48), LFLD(u8, data_0214a424 + (u16)(LFLD(u16, msg, 6) & 0xfff), 0x2a), 1);
        }
        o = LFLD(void *, o, 0x4c);
        if (o != NULL) {
            func_ov000_0215d980(o, func_0206d1d4(data_0214a424, LFLD(u16, msg, 6)), 1);
        }
    }
    return TRUE;
}

}

}  // namespace m_Lo_02178010

// ---- Lo_02178100
namespace m_Lo_02178100 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
BOOL func_0206f21c(u16 a, s32 b);
void *func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_02178100(void *self, BOOL add) {
    func_ov000_02178dcc(LFLD(void *, self, 8), add);
}

}

}  // namespace m_Lo_02178100

// ---- Lo_02178110
namespace m_Lo_02178110 {

extern "C" {

void func_ov000_02178110(u8 *self) {
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x3c), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x40), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x44), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x48), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x4c), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x50), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x54), p->vfunc_04());
}
}

}  // namespace m_Lo_02178110

// ---- Stub_021782b0
namespace m_Stub_021782b0 {

extern "C" {

extern u8 data_ov000_021ccd34[];

void func_ov000_021782b0(void) {
}

BOOL func_ov000_021782b4(void) {
    VObj *obj = (VObj *)(*(u8 **)(data_ov000_021ccd34 + 0x10) + 8);
    return obj->vfunc_2c() ? TRUE : FALSE;
}

}

}  // namespace m_Stub_021782b0

// ---- Lo_021782e0
namespace m_Lo_021782e0 {

extern "C" {
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern void *data_0208ccc8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
void *func_0204c0e8(void *g, u32 id);
void func_ov000_0215bb14(void *o, void *s);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void func_ov000_0215d990(void *self, s32 a);
void func_ov000_02160fc8(void *self);
void func_ov000_02157c90(void *self, void *a);
void func_ov000_02157d2c(void *self, void *arg);
void func_ov000_021546ec(void *a, const void *b, const char *c, u16 d);
s32 func_ov000_02154b58(void *p, s32 a);
s32 func_0206ec48(u16 id);
u16 func_0206f080(u16 id);
u32 func_0206f0f4(u16 id);
u8 *func_0206ede8(u16 id);
void func_ov000_02178100(void);
BOOL func_ov000_02177f40(void);
BOOL func_ov000_02178010(void);

static inline u16 ItemIdx021782e0(u16 v) { return v & 0xfff; }
/* `g` and `m` are unused register parameters reused as locals: as parameters their
 * values get the target's register order (g r4, 1 r6, vtable r8; m r8 in the loop). */
void func_ov000_021782e0(VObj *self, void *g, VObj *m) {
    s32 i;
    s32 a;
    s32 b;
    u16 id;
    u8 *e;
    VObj *o;
    g = data_02149ef8;
    func_ov000_02173648(self);
    o = (VObj *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = o;
    LFLD(s32, o, 0x24) = 0xf8;
    LFLD(s32, LFLD(void *, self, 0x40), 0x20) = 2;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s16, s, 0x64) = 4;
        LFLD(s16, s, 0x66) = 0x95;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s32, s, 0x58) = 0;
        LFLD(s32, s, 0x5c) = 0x54;
        LFLD(s32, s, 0x60) = -0x1ccd;
    }
    LFLD(s32, LFLD(void *, self, 0x40), 0x2c) = 1;
    LFLD(s16, LFLD(void *, self, 0x40), 0x48) = 0xb;
    LFLD(VObj *, self, 0x40)->vfunc_08();
    func_ov000_0215bb14(LFLD(void *, self, 0x40), func_0204c0e8(g, 0x9d));
    LFLD(VObj *, self, 0x40)->vfunc_70();
    o = (VObj *)func_0203dd9c(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x44) = o;
    LFLD(s16, o, 0x64) = 0x86;
    LFLD(s16, o, 0x66) = 0x78;
    LFLD(s16, o, 0x68) = -0x199a;
    {
        u8 *s = LFLD(u8 *, self, 0x44);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0x199a;
    }
    LFLD(s32, LFLD(void *, self, 0x44), 0x2c) = 1;
    func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(s32, data_0214a424, 0x20), 0);
    LFLD(VObj *, self, 0x44)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x48) = o;
    LFLD(s32, o, 0x84) = 4;
    {
        u8 *s = LFLD(u8 *, self, 0x48);
        LFLD(s16, s, 0x64) = 0x1a;
        LFLD(s16, s, 0x66) = 0x78;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    func_ov000_0215d980(LFLD(void *, self, 0x48), 0, 0);
    LFLD(s32, LFLD(void *, self, 0x48), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x48);
        LFLD(s32, s, 0x58) = 0x80;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    LFLD(VObj *, self, 0x48)->vfunc_08();
    func_ov000_0215d990(LFLD(void *, self, 0x48), 0x120);
    LFLD(s32, LFLD(void *, self, 0x48), 0x24) = 0x66;
    LFLD(s32, LFLD(void *, self, 0x48), 0x28) = 0x19;
    o = (VObj *)func_0203dd9c(0x98);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cae48;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x4c) = o;
    LFLD(s32, o, 0x84) = 4;
    {
        u8 *s = LFLD(u8 *, self, 0x4c);
        LFLD(s16, s, 0x64) = 0x1a;
        LFLD(s16, s, 0x66) = 0x83;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    func_ov000_0215d980(LFLD(void *, self, 0x4c), 0, 0);
    LFLD(s32, LFLD(void *, self, 0x4c), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x4c);
        LFLD(s32, s, 0x58) = 0x80;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    LFLD(VObj *, self, 0x4c)->vfunc_08();
    func_ov000_0215d990(LFLD(void *, self, 0x4c), 0x121);
    LFLD(s32, LFLD(void *, self, 0x4c), 0x24) = 0x66;
    LFLD(s32, LFLD(void *, self, 0x4c), 0x28) = 0;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x50) = o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x50), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x50);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0x11;
        LFLD(s16, s, 0x68) = -0x199a;
    }
    LFLD(u32, LFLD(void *, self, 0x50), 0xc) |= 0x20000000;
    {
        u8 *s = LFLD(u8 *, self, 0x50);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0x199a;
    }
    LFLD(VObj *, self, 0x50)->vfunc_f4(1, func_0204c0e8(g, 0x32));
    LFLD(VObj *, self, 0x50)->vfunc_f4(2, func_0204c0e8(g, 0x33));
    LFLD(VObj *, self, 0x50)->vfunc_08();
    o = (VObj *)func_0203dd9c(0xa0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cacd8;
        func_ov000_02160fc8(o);
    }
    LFLD(VObj *, self, 0x54) = o;
    LFLD(s16, o, 0x64) = 0x64;
    LFLD(s16, o, 0x66) = 0x50;
    LFLD(s16, o, 0x68) = -0x1666;
    LFLD(void *, LFLD(void *, self, 0x54), 0x8) = self;
    LFLD(void *, LFLD(void *, self, 0x54), 0x90) = (void *)func_ov000_02178100;
    LFLD(VObj *, self, 0x54)->vfunc_08();
    LFLD(u32, LFLD(void *, self, 0x54), 0xc) |= 2;
    LFLD(u32, LFLD(void *, self, 0x54), 0xc) |= 4;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb4a8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb2a8;
    }
    LFLD(VObj *, self, 0x3c) = o;
    LFLD(VObj *, self, 0x3c)->vfunc_10(func_0204c0e8(g, 0x11e));
    LFLD(VObj *, self, 0x3c)->vfunc_14(func_0204c0e8(g, 0x11f));
    LFLD(s32, LFLD(void *, self, 0x3c), 0x20) = 4;
    LFLD(s32, LFLD(void *, self, 0x3c), 0x24) = 0xf8;
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0x2c;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0x1ccd;
    }
    LFLD(s32, LFLD(void *, self, 0x3c), 0x2c) = 1;
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x400000;
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) &= ~0x800000;
    LFLD(u8, LFLD(void *, self, 0x3c), 0xc1) = 5;
    LFLD(u8, LFLD(void *, self, 0x3c), 0xc0) = 0x78;
    func_ov000_02157c90(LFLD(void *, self, 0x3c), func_0204c0e8(g, 0x9a));
    func_ov000_02157d2c(LFLD(void *, self, 0x3c), func_0204c0e8(g, 0x3e));
    LFLD(void *, LFLD(void *, self, 0x3c), 0x84) = (void *)func_ov000_02177f40;
    LFLD(void *, LFLD(void *, self, 0x3c), 0x88) = (void *)func_ov000_02178010;
    LFLD(void *, LFLD(void *, self, 0x3c), 0x8) = self;
    func_ov000_021546ec(LFLD(void *, self, 0x3c), data_0208ccc8, "cem3d1icn00", 0xffff);
    for (i = 0; i < 0x53; i++) {
        id = i + 0x2000;
        if (*(data_0214a424 + ItemIdx021782e0(id) + 0x2a) != 0) {
            m = LFLD(VObj *, LoFindTask(10), 0x3c);
            a = func_0206ec48(id);
            b = func_0206f080(id);
            e = (u8 *)m->vfunc_74(a, id, (u16)b, func_0206f0f4(id) >> 2);
            LFLD(s32, e, 0x10) = *func_0206ede8(id);
        }
    }
    {
        VObj *t = LFLD(VObj *, self, 0x3c);
        t->vfunc_a8(func_ov000_02154b58(t, 0));
    }
    LFLD(VObj *, self, 0x3c)->vfunc_08();
}

}

}  // namespace m_Lo_021782e0

// ---- Lo_02178a5c
namespace m_Lo_02178a5c {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);

void func_ov000_02178a5c(void *self) {
    u16 v;
    if (LFLD(s32, LFLD(void *, self, 0x54), 4) != 5) {
        return;
    }
    v = data_02097dc8[9];
    if (v & 1) {
        func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(s32, LFLD(void *, self, 0x44), 0x8c), 1);
        return;
    }
    if (!(v & 2)) {
        return;
    }
    LBIT(LFLD(void *, self, 0x3c), 0xc).b1 = 1;
    LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 1;
    LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 1;
    if (LFLD(void *, self, 0x48) != NULL) {
        LBIT(LFLD(void *, self, 0x48), 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x4c) != NULL) {
        LBIT(LFLD(void *, self, 0x4c), 0xc).b1 = 1;
    }
    LBIT(LFLD(void *, self, 0x50), 0xc).b1 = 1;
}

}

}  // namespace m_Lo_02178a5c

// ---- Lo_02178b10
namespace m_Lo_02178b10 {

extern "C" {
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 id, s32 a, s32 b, s32 c);

void func_ov000_02178b10(VObj *self) {
    switch (LFLD(s32, self, 0x8)) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 13: {
        bool done;
        LFLD(VObj *, self, 0x54)->vfunc_1c();
        if (LFLD(s32, LFLD(VObj *, self, 0x54), 0x4) == 5) {
            LFLD(u32, LFLD(VObj *, self, 0x3c), 0xc) &= ~4;
        } else {
            LFLD(u32, LFLD(VObj *, self, 0x3c), 0xc) |= 4;
        }
        done = true;
        done &= !LFLD(VObj *, self, 0x3c)->vfunc_1c();
        done &= !LFLD(VObj *, self, 0x40)->vfunc_1c();
        done &= !LFLD(VObj *, self, 0x44)->vfunc_1c();
        if (LFLD(VObj *, self, 0x48) != NULL) {
            done &= !LFLD(VObj *, self, 0x48)->vfunc_1c();
        }
        if (LFLD(VObj *, self, 0x4c) != NULL) {
            done &= !LFLD(VObj *, self, 0x4c)->vfunc_1c();
        }
        done &= !LFLD(VObj *, self, 0x50)->vfunc_1c();
        if (done) {
            self->vfunc_0c(0);
        }
        break;
    }
    case 10:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
}
}

}  // namespace m_Lo_02178b10

// ---- Stub_02178ccc
namespace m_Stub_02178ccc {

extern "C" {

void func_ov000_02178ccc(void) {
}

}

}  // namespace m_Stub_02178ccc

// ---- Lo_02178cd0
namespace m_Lo_02178cd0 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
u8 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_0206f3f0(u16 id, s32 v);
u16 func_0206d02c(void *a);

void func_ov000_02178cd0(void *self) {
    s32 scale[3];
    if (LFLD(s32, self, 0x24) == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    LFLD(s32, self, 0x28) = FX_SinCosTable_[((LFLD(s32, self, 0x24) << 14) >> 16) * 2];
    LFLD(VObj *, self, 0x3c)->vfunc_20();
    LFLD(VObj *, self, 0x40)->vfunc_20();
    LFLD(VObj *, self, 0x44)->vfunc_20();
    if (LFLD(VObj *, self, 0x48) != NULL) {
        LFLD(VObj *, self, 0x48)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x4c) != NULL) {
        LFLD(VObj *, self, 0x4c)->vfunc_20();
    }
    LFLD(VObj *, self, 0x50)->vfunc_20();
    LFLD(VObj *, self, 0x54)->vfunc_20();
}

static inline u16 ItemKind(u16 v) { return v >> 12; }
static inline u16 ItemIdx(u16 v) { return v & 0xfff; }

void func_ov000_02178dcc(void *p, BOOL on) {
    u8 *self = (u8 *)p;
    u32 n;
    if (on && (n = LFLD(u32, LFLD(u8 *, self, 0x54), 0x8c) * LFLD(u16, LFLD(u8 *, self, 0x54), 0x88)) != 0) {
        s32 rest;
        u8 *node;
        u8 *list;
        {
            u8 *g = data_0214a424;
            if ((LFLD(u32, g, 0x20) += n) > 99999) {
                LFLD(u32, g, 0x20) = 99999;
            }
        }
        node = NULL;
        func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(u32, data_0214a424, 0x20), 0);
        func_02049a48(data_02097e4c, 0x30, -1, -1, -1);
        list = LFLD(u8 *, LFLD(u8 *, self, 0x3c), 0x98);
        if (list != NULL) {
            s32 i = LFLD(s8, LFLD(u8 *, self, 0x3c), 0xb1);
            while (i-- != 0) {
                list = LFLD(u8 *, list, 0x2c);
            }
            node = list;
        }
        rest = LFLD(u16, LFLD(u8 *, self, 0x54), 0x8a) - LFLD(u16, LFLD(u8 *, self, 0x54), 0x88);
        if (ItemKind(LFLD(u16, node, 6)) - 1 == 1) {
            s32 c = rest;
            if (c < 0) {
                c = 0;
            }
            func_0206f3f0(LFLD(u16, node, 6), c);
            func_0206d02c(data_0214a424);
        }
        if (LFLD(void *, self, 0x48) != NULL) {
            func_ov000_0215d980(LFLD(void *, self, 0x48), *(data_0214a424 + ItemIdx(LFLD(u16, node, 6)) + 0x2a), 1);
        }
        if (LFLD(void *, self, 0x4c) != NULL) {
            func_ov000_0215d980(LFLD(void *, self, 0x4c), func_0206d1d4(data_0214a424, LFLD(u16, node, 6)), 1);
        }
        if (rest <= 0) {
            LFLD(VObj *, self, 0x3c)->vfunc_70(node);
        }
    }
    LFLD(u32, LFLD(u8 *, self, 0x54), 0xc) |= 4;
    LFLD(u32, LFLD(u8 *, self, 0x54), 0xc) |= 2;
    LFLD(u32, LFLD(u8 *, self, 0x3c), 0xc) &= ~4;
}

}

}  // namespace m_Lo_02178cd0

// ---- Dtor_02178f70
namespace m_Dtor_02178f70 {

extern "C" {

extern u8 data_ov000_021cbde0[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

VObj *func_ov000_02178f70(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x54);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbde0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x5, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_02178f70

// ---- Lo_02178fd8
namespace m_Lo_02178fd8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_02178fd8(void *self) {
    u8 buf[0x20];
    VObj *obj = (VObj *)func_0203dd9c(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, data_0208ba30);
        func_0204bfcc(obj);
    }
    LFLD(VObj *, self, 0x3c) = obj;
    STD_CopyString(buf, "script/");
    STD_ConcatenateString(buf, "other");
    func_0204bfe4(LFLD(VObj *, self, 0x3c), buf, "help.ccmes");
}

BOOL func_ov000_02179064(void *self) {
    BOOL r = TRUE;
    if (!LFLD(VObj *, self, 0x3c)->vfunc_2c()) {
        r = FALSE;
    }
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

extern void *data_02149ef8;
extern u8 *data_02fe152c;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021ccbe0[];
extern u8 data_ov000_021cbac8[];
extern u8 data_ov000_021cca10[];
void func_ov000_02173648(void *self);
BOOL func_0204c030(void *p);
void *func_0204c0e8(void *g, s32 id);
void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2334(void *self);
void func_ov000_021c2a88(void *self, void *a);
void func_ov000_021c3fd4(void *list, void *item);
BOOL func_ov000_02179910(void);
void *func_0205976c(void *mgr, s32 kind);
u32 func_0205975c(void *mgr, s32 kind);
u16 func_02059544(void *mgr, void *a, void *tbl, s32 b, u16 i);
void *func_02062138(u16 id);
void MI_CpuFill8(void *dst, u8 val, u32 size);

void func_ov000_021790ac(void *self) {
    VObj *p;
    void *g;
    u8 *s;
    LFLD(u32, self, 0x4) &= ~2;
    if (((VObj *)self)->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
    func_0204c030(LFLD(void *, self, 0x3c));
    g = data_02149ef8;
    p = (VObj *)func_0203dd9c(0xe0);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_ov000_021cac60);
        p->vfunc_28();
        VOBJ_SET_VTABLE(p, data_ov000_021caec8);
        p->vfunc_28();
        VOBJ_SET_VTABLE(p, data_ov000_021cb5a8);
        p->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = p;
    LFLD(u32, p, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x40), 0x2c) = 1;
    s = LFLD(u8 *, self, 0x40);
    LFLD(s32, s, 0x58) = 0x100;
    LFLD(s32, s, 0x5c) = 0;
    LFLD(s32, s, 0x60) = 0;
    s = LFLD(u8 *, self, 0x40);
    LFLD(s16, s, 0x64) = 0;
    LFLD(s16, s, 0x66) = 0x11;
    LFLD(s16, s, 0x68) = -0x1ccd;
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) |= 0x20000000;
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) |= 0x80000000;
    LFLD(VObj *, self, 0x40)->vfunc_f4(1, func_0204c0e8(g, 0x34));
    LFLD(VObj *, self, 0x40)->vfunc_f4(2, func_0204c0e8(g, 0x33));
    LFLD(VObj *, self, 0x40)->vfunc_08();
    p = (VObj *)func_0203dd9c(0xf4);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_ov000_021cac60);
        p->vfunc_28();
        VOBJ_SET_VTABLE(p, data_ov000_021ccbe0);
        func_ov000_021c3af4(p);
    }
    LFLD(VObj *, self, 0x44) = p;
    LFLD(VObj *, self, 0x44)->vfunc_10(func_0204c0e8(g, 0x118));
    LFLD(VObj *, self, 0x44)->vfunc_14(func_0204c0e8(g, 0x119));
    LFLD(void *, LFLD(void *, self, 0x44), 0x8) = self;
    LFLD(s32, LFLD(void *, self, 0x44), 0x20) = 7;
    LFLD(s32, LFLD(void *, self, 0x44), 0x24) = 0xf9;
    s = LFLD(u8 *, self, 0x44);
    LFLD(s16, s, 0x64) = 4;
    LFLD(s16, s, 0x66) = 0x23;
    LFLD(s16, s, 0x68) = -0x1ccd;
    LFLD(void *, LFLD(void *, self, 0x44), 0xe4) = (void *)func_ov000_02179910;
    {
        u8 *base = LFLD(u8 *, data_02fe152c, 0x4c);
        u16 i;
        u8 *tbl = (u8 *)func_0205976c(data_02fe152c, 3);
        u32 n = func_0205975c(data_02fe152c, 3);
        u16 used[0x40];
        MI_CpuFill8(used, 0, sizeof(used));
        for (i = 0; i < n; i++) {
            if (func_02059544(data_02fe152c, base + 0x70, tbl, 1, i)) {
                used[LFLD(u16, tbl + i * 4, 2)] = i + 1;
            }
        }
        for (i = 0; i < 0x40; i++) {
            if (used[i] != 0) {
                u8 *it = (u8 *)func_0203dd9c(0x48);
                if (it != NULL) {
                    VOBJ_SET_VTABLE(it, data_ov000_021cbac8);
                    func_ov000_021c22d8(it);
                    VOBJ_SET_VTABLE(it, data_ov000_021cca10);
                    func_ov000_021c2334(it);
                }
                LFLD(s32, it, 0x4) = i;
                LFLD(s32, it, 0x3c) = i + 1;
                func_ov000_021c2a88(it, func_02062138(i));
                func_ov000_021c3fd4(LFLD(void *, self, 0x44), it);
            }
        }
    }
    LFLD(VObj *, self, 0x44)->vfunc_08();
}

}

}  // namespace m_Lo_02178fd8

// ---- Lo_0217942c
namespace m_Lo_0217942c {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_0217942c(void *self) {
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(u16, self, 0x4c) = 0xffff;
}

void func_ov000_0217945c(void *self) {
    LO_FREE_V(self, 0x50);
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x3c);
}

}

}  // namespace m_Lo_0217942c

// ---- Dtor_02179560
namespace m_Dtor_02179560 {

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ccbe0[];
void func_0203de1c(void *ptr);
void func_ov000_021c3bb0(void *ptr);

VObj *func_ov000_02179560(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    func_ov000_021c3bb0(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

}

}  // namespace m_Dtor_02179560

// ---- Lo_021795a4
namespace m_Lo_021795a4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_021795a4(void *self) {
    void *p = LFLD(void *, self, 0x44);
    u16 v;
    if (p == NULL) {
        return;
    }
    LBIT(p, 0xc).b2 = 0;
    if ((LBIT(LFLD(void *, self, 0x44), 0xc).b0 == 0 ? TRUE : FALSE) == FALSE) {
        return;
    }
    if (LFLD(u16, self, 0x4c) != 0xffff) {
        return;
    }
    v = data_02097dc8[9];
    if (v & 1) {
        return;
    }
    if (!(v & 2)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    if (LFLD(void *, self, 0x40) != NULL) {
        LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x44) != NULL) {
        LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 1;
    }
}

}

}  // namespace m_Lo_021795a4

// ---- Stub_02179680
namespace m_Stub_02179680 {

extern "C" {

void func_ov000_02179680(void) {
}

}

}  // namespace m_Stub_02179680

// ---- Win_02179684
namespace m_Win_02179684 {

typedef struct {
    VObj base;
    s32 unk_04_;
    s32 unk_08;
    u8 pad_0c[0x30];
    void *unk_3c;
    VObj *unk_40;
    VObj *unk_44;
    s32 unk_48;
    u16 unk_4c;
    u8 pad_4e[2];
    VObj *unk_50;
} Win02179684;

extern "C" {
extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
void *func_0203dd9c(u32 size);
s32 func_0204c08c(void *res, u16 id, s32 *out, s32 d);
void func_0204c7d0(void *p);
void func_02050f70(void *p);

void func_ov000_02179684(Win02179684 *self) {
    if (self->unk_08 == 0xd) {
        switch (self->unk_48) {
        case 0: {
            s32 busy = 0;
            if (self->unk_40 != NULL && self->unk_40->vfunc_1c()) {
                busy++;
            }
            if (self->unk_44 != NULL && self->unk_44->vfunc_1c()) {
                busy++;
            }
            if (busy != 0) {
                break;
            }
            if (self->unk_4c != 0xffff) {
                s32 ofs;
                s32 n = func_0204c08c(self->unk_3c, self->unk_4c, &ofs, 1);
                VObj *o = (VObj *)func_0203dd9c(0xb80);
                if (o != NULL) {
                    VOBJ_SET_VTABLE(o, data_0208ba70);
                    func_0204c7d0(o);
                    VOBJ_SET_VTABLE(o, data_0208bbc8);
                    func_02050f70(o);
                }
                self->unk_50 = o;
                LFLD(s32, o, 0x28) = 8;
                {
                    u8 *p = (u8 *)self->unk_50;
                    LFLD(s32, p, 0xb7c) = ofs;
                    LFLD(s32, p, 0xb70) = 0;
                    LFLD(s32, p, 0xb74) = n;
                }
                LFLD(u32, self->unk_50, 0xb8) = (LFLD(u32, self->unk_50, 0xb8) & ~0xf) | 4;
                LFLD(u32, self->unk_50, 0xbc) |= 0x80;
                LFLD(u32, self->unk_50, 0x4) |= 4;
                self->unk_4c = 0xffff;
                self->unk_48 = 1;
            } else {
                self->base.vfunc_0c(0);
            }
            break;
        }
        case 1:
            if (!self->unk_50->vfunc_8c()) {
                HEAP_DELETE_VOBJ(self->unk_50);
                if (self->unk_40 != NULL) {
                    LFLD(u32, self->unk_40, 0xc) &= ~2;
                }
                if (self->unk_44 != NULL) {
                    LFLD(u32, self->unk_44, 0xc) &= ~2;
                }
                self->unk_48 = 0;
            }
            break;
        }
    }
    if (self->unk_44 != NULL) {
        LFLD(u32, self->unk_44, 0xc) |= 4;
    }
}
}

}  // namespace m_Win_02179684

// ---- Lo_0217987c
namespace m_Lo_0217987c {

extern "C" {

extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0216f23c(void *p, s32 a);

void func_ov000_0217987c(void *self) {
    s32 s;
    if (LFLD(s32, self, 0x24) == 0 || (s = LFLD(s32, self, 8)) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    switch (LFLD(s32, self, 0x48)) {
    case 0:
        if (LFLD(VObj *, self, 0x40) != NULL) {
            LFLD(VObj *, self, 0x40)->vfunc_20();
        }
        if (LFLD(VObj *, self, 0x44) != NULL) {
            LFLD(VObj *, self, 0x44)->vfunc_20();
        }
        break;
    case 1:
        if (LFLD(VObj *, self, 0x50) != NULL) {
            LFLD(VObj *, self, 0x50)->vfunc_90();
        }
        break;
    }
}

BOOL func_ov000_02179910(void *self, void *msg) {
    void *o = LFLD(void *, self, 8);
    if (msg == NULL) {
        return FALSE;
    }
    LFLD(u16, o, 0x4c) = LFLD(s32, msg, 4);
    if (LFLD(void *, o, 0x40) != NULL) {
        LBIT(LFLD(void *, o, 0x40), 0xc).b1 = 1;
    }
    if (LFLD(void *, o, 0x44) != NULL) {
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
    }
    func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    return TRUE;
}

}

}  // namespace m_Lo_0217987c

// ---- Dtor_0217997c
namespace m_Dtor_0217997c {

extern "C" {

extern u8 data_ov000_021cbd60[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

VObj *func_ov000_0217997c(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x48);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbd60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x6, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217997c

// ---- Lo_021799e4
namespace m_Lo_021799e4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_021799e4(void *self) {
    u8 buf[0x20];
    VObj *obj = (VObj *)func_0203dd9c(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, data_0208ba30);
        func_0204bfcc(obj);
    }
    LFLD(VObj *, self, 0x3c) = obj;
    STD_CopyString(buf, "script/");
    STD_ConcatenateString(buf, "other");
    func_0204bfe4(LFLD(VObj *, self, 0x3c), buf, "memory.ccmes");
}

BOOL func_ov000_02179a70(void *self) {
    BOOL r = TRUE;
    if (!LFLD(VObj *, self, 0x3c)->vfunc_2c()) {
        r = FALSE;
    }
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}

}  // namespace m_Lo_021799e4

// ---- Obj_02179ab8
namespace m_Obj_02179ab8 {

typedef struct {
    u32 b0 : 8;
    u32 b8 : 8;
    u32 rest : 16;
} Bits02179ab8;

extern "C" {
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021c9c46[];
void *func_0203dd9c(u32 size);
BOOL func_0204c030(void *p);
void *func_0204c0e8(void *g, u32 id);
void func_ov000_0215bb14(void *o, void *s);
void func_ov000_02173648(void *self);

void func_ov000_02179ab8(VObj *self) {
    VObj *o;
    void *g;
    u16 n;
    LFLD(u32, self, 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    func_0204c030(LFLD(void *, self, 0x3c));
    g = data_02149ef8;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x44) = o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x44), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x44);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x44);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 0x20000000;
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 0x80000000;
    LFLD(VObj *, self, 0x44)->vfunc_f4(2, func_0204c0e8(g, 0x33));
    LFLD(VObj *, self, 0x44)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = o;
    LFLD(s32, o, 0x88) = 0xe;
    LFLD(s32, LFLD(void *, self, 0x40), 0x24) = 0xf8;
    LFLD(s32, LFLD(void *, self, 0x40), 0x20) = 6;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s16, s, 0x64) = 4;
        LFLD(s16, s, 0x66) = 0x2e;
        LFLD(s16, s, 0x68) = -0x1ccd;
    }
    LFLD(s16, LFLD(void *, self, 0x40), 0x48) = 0;
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) |= 0x10;
    LFLD(s32, LFLD(void *, self, 0x40), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = 0;
    }
    LFLD(VObj *, self, 0x40)->vfunc_10(func_0204c0e8(g, 0xc2));
    LFLD(VObj *, self, 0x40)->vfunc_14(func_0204c0e8(g, 0xc3));
    LFLD(VObj *, self, 0x40)->vfunc_08();
    LFLD(u32, LFLD(void *, self, 0x40), 0xc) |= 0x80000;
    n = LFLD(Bits02179ab8, data_0214a424, 0x518).b8;
    if (n != 0) {
        func_ov000_0215bb14(LFLD(void *, self, 0x40), func_0204c0e8(LFLD(void *, self, 0x3c), (u16)(n - 1)));
    }
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(void *, s, 0x6c) = data_ov000_021c9c46;
        LFLD(s32, s, 0x70) = 6;
    }
    func_ov000_02173648(self);
}
}

}  // namespace m_Obj_02179ab8

// ---- Lo_02179d78
namespace m_Lo_02179d78 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_02179d78(void *self) {
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
}

void func_ov000_02179d94(void *self) {
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x3c);
}

void func_ov000_02179e68(void *self) {
    if (!(data_02097dc8[9] & 2)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    if (LFLD(void *, self, 0x40) != NULL) {
        LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x44) != NULL) {
        LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 1;
    }
    LBIT(self, 4).b0 = 1;
}

}

}  // namespace m_Lo_02179d78

// ---- Stub_02179ef0
namespace m_Stub_02179ef0 {

extern "C" {

void func_ov000_02179ef0(void) {
}

}

}  // namespace m_Stub_02179ef0

// ---- Lo_02179ef4
namespace m_Lo_02179ef4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_02179ef4(VObj *self) {
    s32 n;
    VObj *p;
    if (LFLD(s32, self, 8) != 0xd) {
        return;
    }
    n = 0;
    p = LFLD(VObj *, self, 0x40);
    if (p != NULL && p->vfunc_1c()) {
        n++;
    }
    p = LFLD(VObj *, self, 0x44);
    if (p != NULL && p->vfunc_1c()) {
        n++;
    }
    if (n != 0) {
        return;
    }
    self->vfunc_0c(0);
}

void func_ov000_02179f6c(void *self) {
    s32 s;
    if (LFLD(s32, self, 0x24) == 0 || (s = LFLD(s32, self, 8)) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (LFLD(VObj *, self, 0x40) != NULL) {
        LFLD(VObj *, self, 0x40)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_20();
    }
}

}

}  // namespace m_Lo_02179ef4

// ---- Dtor_02179fcc
namespace m_Dtor_02179fcc {

extern "C" {

extern u8 data_ov000_021cbc60[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

VObj *func_ov000_02179fcc(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x50);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbc60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x7, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_02179fcc

// ---- Win_0217a034
namespace m_Win_0217a034 {

class Win0217a034 : public VObj {
public:
    void *owner_pad;
    void *owner;
    u8 pad0c[0x3c];
    u16 unk_48;
    u8 pad4a[0x1e];
    s16 unk_68;
    u8 pad6a[0x1a];
    void *cb;
    u8 pad88[0x154];
    void *unk_1dc;
    u16 unk_1e0;
};

typedef struct {
    u8 pad[0x4c];
    s32 unk_4c;
} Sub0217a034;

class Obj0217a034 : public VObj {
public:
    u32 b0 : 1;
    u32 rest : 31;
    u8 pad08[0x24];
    Sub0217a034 *sub;
    u8 pad30[0xc];
    Win0217a034 *win;
    u8 pad40[4];
    u16 unk_44;
};

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *func_0204c0e8(void *a, s32 b);
void *func_0203dd9c(u32 size);
void *func_ov000_02154b58(Win0217a034 *w, s32 b);
BOOL func_ov000_02175e6c(void);

BOOL func_ov000_0217a034(Obj0217a034 *self, s32 msg) {
    Sub0217a034 *sub = self->sub;
    Win0217a034 *w;
    void *a;
    void *b;
    switch (msg) {
    case 0: {
        void *res = data_02149ef8;
        a = func_0204c0e8(res, 0x1b);
        b = func_0204c0e8(res, 0x8d);
        w = (Win0217a034 *)func_0203dd9c(0x1e4);
        if (w != NULL) {
            VOBJ_SET_VTABLE(w, data_ov000_021cac60);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021caec8);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb1b0);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb0b8);
            w->vfunc_28();
        }
        self->win = w;
        w->vfunc_10(b);
        self->win->unk_1dc = a;
        self->win->unk_1e0 = 1;
        self->win->owner = self;
        self->win->cb = (void *)func_ov000_02175e6c;
        self->win->vfunc_08();
        self->win->unk_68 = -0x1666;
        self->b0 = 1;
        w = self->win;
        w->vfunc_a8(func_ov000_02154b58(w, 0));
        w->unk_48 = 0x2803;
        break;
    }
    case 2:
        if (self->unk_44 == 0) {
            sub->unk_4c = self->unk_44;
            self->vfunc_0c(0);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}

}  // namespace m_Win_0217a034

// ---- Lo_0217a1d8
namespace m_Lo_0217a1d8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_0217a1d8(void) {
    LoTaskObj()->vfunc_2c();
}

}

}  // namespace m_Lo_0217a1d8

// ---- Lo_0217a1f8
namespace m_Lo_0217a1f8 {

// The text argument of func_ov000_0217a328 is a string id, -1 (all bits set) for "no text"
// (it tests b != -1). It is built as the complement of an empty id mask: the backend folds
// the `mvn` of the known zero into `mvn r2, #0` only after the local CSE, so the -1 is not
// derived from the 0x78 before it (a literal -1 gives sub r2, r1, #0x79). See round pmB.
typedef enum { LO_TEXT_MASK_EMPTY = 0 } LoTextMask;

extern "C" {
VObj *func_ov000_02176208(void);
void func_ov000_0217a328(VObj *self, s32 a, s32 b);
void func_ov000_02173648(VObj *self);

void func_ov000_0217a1f8(VObj *self) {
    VObj *o;
    LoTextMask mask;
    LFLD(u32, self, 4) &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    mask = LO_TEXT_MASK_EMPTY;
    func_ov000_0217a328(self, 0x78, ~mask);
    {
        LoCreateFn fn = LFLD(LoCreateFn, data_ov000_021ccd34, 0x18);
        if (fn == NULL) {
            LFLD(LoCreateFn, data_ov000_021ccd34, 0x18) = fn = (LoCreateFn)func_ov000_02176208;
        }
        o = (VObj *)fn();
    }
    LFLD(VObj *, self, 0x44) = o;
    o->vfunc_08();
    func_ov000_02173648(self);
}

}

}  // namespace m_Lo_0217a1f8

namespace m_Lo_0217a26c {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_0217a26c(void *self) {
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = -1;
}

void func_ov000_0217a294(void *self) {
    LO_FREE_V(self, 0x48);
    LO_FREE_V(self, 0x44);
}

}

}  // namespace m_Lo_0217a26c

// ---- Lo_0217a328
namespace m_Lo_0217a328 {

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
extern void *data_02149ef8;
void *func_0204c0e8(void *p, u16 a);
void func_ov000_0215c1bc(void *a, s32 b, void *c);
void func_ov000_0215ce8c(void *a, s32 b);

void func_ov000_0217a328(u8 *self, s32 a, s32 b) {
    if (LFLD(VObj *, self, 0x48) == NULL) {
        VObj *o = (VObj *)func_0203dd9c(0xe8);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021cad50);
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x48) = o;
    }
    if (a == 0x79 || b == 0x77) {
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) |= 0x10000;
    } else {
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) &= ~0x10000;
    }
    if (LFLD(s32, self, 0xc) != 1) {
        LFLD(u16, LFLD(VObj *, self, 0x48), 0x48) = 0x2803;
    } else {
        VObj *o = LFLD(VObj *, self, 0x48);
        LFLD(u32, o, 0xc) |= 8;
        LFLD(u16, o, 0x48) = 0x14a5;
        LFLD(s32, o, 0x54) = 0x1c;
    }
    LFLD(s32, LFLD(VObj *, self, 0x48), 0x1c) = 4;
    LFLD(VObj *, self, 0x48)->vfunc_08();
    if (b != -1) {
        func_ov000_0215c1bc(LFLD(VObj *, self, 0x48), 0x8000, func_0204c0e8(data_02149ef8, b));
    } else {
        func_ov000_0215ce8c(LFLD(VObj *, self, 0x48), a);
    }
    LFLD(s16, LFLD(VObj *, self, 0x48), 0x68) = -0x1ccd;
    LFLD(VObj *, self, 0x48)->vfunc_70();
}
}

}  // namespace m_Lo_0217a328

// ---- Stub_0217a478
namespace m_Stub_0217a478 {

extern "C" {

void func_ov000_0217a478(void) {
}

void func_ov000_0217a47c(void) {
}

}

}  // namespace m_Stub_0217a478

// ---- Lo_0217a480
namespace m_Lo_0217a480 {

typedef struct {
    u32 lo : 16;
    u32 b16 : 8;
    u32 hi : 8;
} W518_0217a480;

extern "C" {
extern u8 *data_0214a424;
extern void *data_02097e4c;
void func_0206c620(void *p);
void func_0206c670(void *p);
void func_ov000_0217a328(u8 *self, s32 a, s32 b);
BOOL func_ov000_0217a034(void *self, s32 msg);
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);

static inline u8 Raw0217a480(u8 *g) {
    return LFLD(W518_0217a480, g, 0x518).b16;
}

static inline u8 Lvl0217a480(u8 *g) {
    return Raw0217a480(g) & ~0xc0;
}

static inline BOOL IsB1_0217a480(void *p) {
    return LBIT(p, 0x48).b1 ? TRUE : FALSE;
}

static inline BOOL IsB2_0217a480(void *p) {
    return LBIT(p, 0x48).b2 ? TRUE : FALSE;
}

void func_ov000_0217a480(u8 *self) {
    if (LFLD(VObj *, self, 0x48) != NULL && !LFLD(VObj *, self, 0x48)->vfunc_1c()) {
        LO_FREE_V(self, 0x48);
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_0c();
    }
    switch (LFLD(s32, self, 0x3c)) {
    case 0:
        if (LFLD(s32, self, 0xc) == 0) {
            if (LFLD(VObj *, self, 0x48) != NULL) {
                return;
            }
            LFLD(void *, LoSwitchTaskC(3, 0), 0x30) = (void *)func_ov000_0217a034;
            ((VObj *)self)->vfunc_48();
            LFLD(s32, self, 0x3c) = 1;
        } else if (LFLD(s32, self, 0xc) == 1) {
            LFLD(s32, self, 0x3c) = 2;
        }
        break;
    case 1:
        if (LBIT(self, 4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x4c) != -1) {
            LFLD(s32, self, 0x3c) = 2;
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        LFLD(s32, self, 0x3c) = 6;
        break;
    case 2: {
        u8 *g;
        LFLD(u8, data_02097dd0, 0x31) = 1;
        LFLD(s32, self, 0x40) = 0;
        if (LFLD(s32, self, 0xc) == 0) {
            func_0206c620(data_0214a424);
        } else if (LFLD(s32, self, 0xc) == 1) {
            func_0206c670(data_0214a424);
        }
        LBIT(LFLD(void *, self, 0x44), 0x48).b0 = TRUE;
        LFLD(u32, LFLD(void *, self, 0x44), 0x48) |= 0x20;
        g = data_0214a424;
        if (Lvl0217a480(g) > 0x14) {
            u16 n = LFLD(u8, g, 8);
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(u32, q, 0x48) |= 0x210;
            LFLD(s32, q, 0x40) = n;
        } else {
            u16 n = LFLD(u8, g, 8);
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(u32, q, 0x48) |= 0x200;
            LFLD(s32, q, 0x40) = n;
        }
        func_ov000_0217a328(self, 0x79, -1);
        LFLD(s32, self, 0x3c) = 3;
        break;
    }
    case 3:
        LFLD(s32, self, 0x40)++;
        if (IsB1_0217a480(LFLD(void *, self, 0x44))) {
            if (LFLD(s32, self, 0x40) <= 0x3c) {
                return;
            }
            LFLD(u32, LFLD(void *, self, 0x48), 0xc) |= 0x40000;
            LFLD(s32, self, 0x3c) = 4;
        } else {
            if (!IsB2_0217a480(LFLD(void *, self, 0x44))) {
                return;
            }
            func_ov000_0217a328(self, 0x8000, 0x77);
            LFLD(s32, self, 0x3c) = 5;
        }
        break;
    case 4:
        if (LFLD(VObj *, self, 0x48) != NULL) {
            return;
        }
        if (LFLD(s32, self, 0xc) == 0) {
            func_02049a48(data_02097e4c, 0x85, -1, -1, -1);
            func_ov000_0217a328(self, 0x7a, -1);
        }
        LFLD(s32, self, 0x3c) = 5;
        break;
    case 5:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        if (LFLD(VObj *, self, 0x48) != NULL) {
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        LFLD(s32, self, 0x3c) = 6;
        break;
    }
}

}

}  // namespace m_Lo_0217a480

// ---- Dtor_0217a88c
namespace m_Dtor_0217a88c {

extern "C" {

extern u8 data_ov000_021cbb60[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

void func_ov000_0217a86c(void *self) {
    VObj *obj = *(VObj **)((u8 *)self + 0x48);
    if (obj != NULL) {
        obj->vfunc_20();
    }
}

VObj *func_ov000_0217a88c(void) {
    VObj *obj = (VObj *)func_0203dd9c(0xc4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbb60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x8, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217a88c

// ---- Win_0217a8f4
namespace m_Win_0217a8f4 {

class Win0217a8f4 : public VObj {
public:
    void *owner_pad;
    void *owner;
    u32 unk_0c;
    u8 pad10[0x38];
    u16 unk_48;
    u8 pad4a[0xa];
    s32 unk_54;
    u8 pad58[0x10];
    s16 unk_68;
    u8 pad6a[0x1a];
    void *cb;
    u8 pad88[0x154];
    void *unk_1dc;
    u16 unk_1e0;
};

typedef struct {
    u8 pad[0x4c];
    s32 unk_4c;
    u8 pad50[4];
    u32 unk_54;
} Sub0217a8f4;

class Obj0217a8f4 : public VObj {
public:
    u32 b0 : 1;
    u32 rest : 31;
    u8 pad08[0x24];
    Sub0217a8f4 *sub;
    u8 pad30[0xc];
    Win0217a8f4 *win;
    u8 pad40[4];
    u16 unk_44;
};

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *func_0204c0e8(void *a, s32 b);
void *func_0203dd9c(u32 size);
BOOL func_ov000_02175e6c(void);

BOOL func_ov000_0217a8f4(Obj0217a8f4 *self, s32 msg) {
    Sub0217a8f4 *sub = self->sub;
    s32 idx = sub->unk_4c;
    u16 lo = sub->unk_54;
    u16 hi = sub->unk_54 >> 16;
    Win0217a8f4 *w;
    void *a;
    void *b;
    s32 id;
    switch (msg) {
    case 0: {
        switch (idx) {
        case 1: id = 0x91; break;
        case 2: id = 0x92; break;
        case 3: id = 0x93; break;
        case 4: if (hi == 0) id = 0x94; else id = 0x95; break;
        default: id = 0x8d; break;
        }
        void *res = data_02149ef8;
        a = func_0204c0e8(res, 0x18);
        b = func_0204c0e8(res, id);
        w = (Win0217a8f4 *)func_0203dd9c(0x1e4);
        if (w != NULL) {
            VOBJ_SET_VTABLE(w, data_ov000_021cac60);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021caec8);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb1b0);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb0b8);
            w->vfunc_28();
        }
        self->win = w;
        w->unk_0c |= 8;
        w->unk_48 = 0x14a5;
        w->unk_54 = 0x1c;
        self->win->vfunc_10(b);
        self->win->unk_1dc = a;
        self->win->unk_1e0 = lo;
        self->win->owner = self;
        self->win->cb = (void *)func_ov000_02175e6c;
        self->win->vfunc_08();
        self->win->unk_68 = -0x1666;
        self->b0 = 1;
        break;
    }
    case 1:
        break;
    case 2: {
        u16 c = self->unk_44;
        self->vfunc_0c(0);
        if (c == 0) {
            sub->unk_54 = c;
            self->vfunc_0c(0);
            return TRUE;
        }
        sub->unk_54 = -1;
        self->vfunc_0c(0);
        return FALSE;
    }
    }
    return FALSE;
}

}

}  // namespace m_Win_0217a8f4

// ---- Lo_0217ab30
namespace m_Lo_0217ab30 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
BOOL func_0206f21c(u16 a, s32 b);
void *func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ab30(void *self) {
    VObj *obj = (VObj *)func_0203dd9c(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
    }
    LFLD(VObj *, self, 0x3c) = obj;
    LFLD(s32, obj, 0x44) = 7;
    LFLD(VObj *, self, 0x3c)->vfunc_1c(data_0208cc9c);
}

BOOL func_ov000_0217ab8c(void *self) {
    BOOL r = TRUE;
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    if (!LFLD(VObj *, self, 0x3c)->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}

}  // namespace m_Lo_0217ab30

// ---- Lo_0217abd8
namespace m_Lo_0217abd8 {

extern "C" {
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
extern void *data_0208cb78;
extern void *data_0208cc9c;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void STD_CopyString(void *dst, void *src);
VObj *func_ov000_02176208(void);

static inline void ModelInit(u8 *m, void *s, void *nm) {
    func_02041218(m + 0x88);
    func_02041440(m, nm, 0);
    STD_CopyString(m + 0x2c, s);
}

class Model {
public:
    u8 data[0x160];
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Model(void *nm, void *s) {
        func_02041218(data + 0x88);
        func_02041440(data, nm, 0);
        STD_CopyString(data + 0x2c, s);
    }
};

void func_ov000_0217abd8(VObj *self) {
    u8 *m;
    VObj *o;
    LFLD(u32, self, 4) &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    {
        LoCreateFn fn = LFLD(LoCreateFn, data_ov000_021ccd34, 0x18);
        if (fn == NULL) {
            LFLD(LoCreateFn, data_ov000_021ccd34, 0x18) = fn = (LoCreateFn)func_ov000_02176208;
        }
        o = (VObj *)fn();
    }
    LFLD(VObj *, self, 0x5c) = o;
    o->vfunc_08();
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        ModelInit(m, data_0208cc9c, data_0208cb78);
    }
    LFLD(u8 *, self, 0xa0) = m;
    func_020417e0(LFLD(u8 *, self, 0xa0), func_02034d88(func_02035d5c(m + 0x2c), LFLD(u8 *, self, 0xa0) + 0x4c));
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 1);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 2);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 3);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 4);
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 0x200000;
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 0x80000;
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) = (LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) & ~0x7c) | 0x78;
    func_ov000_02173648(self);
    LFLD(u32, self, 4) |= 0x10000;
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = 1;
        LFLD(s32, self, 0x48) = 0;
    }
}

}

}  // namespace m_Lo_0217abd8

// ---- Lo_0217ad54
namespace m_Lo_0217ad54 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
BOOL func_0206f21c(u16 a, s32 b);
void *func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ad54(void *self) {
    s32 i;
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
    LFLD(s32, self, 0x58) = 0;
    LFLD(s32, self, 0x5c) = 0;
    LFLD(s32, self, 0x60) = 0;
    LFLD(s32, self, 0x64) = 0;
    LFLD(s32, self, 0x68) = 0;
    LFLD(s32, self, 0x6c) = 0;
    LFLD(u8, self, 0x70) = 0;
    LFLD(u8, self, 0x71) = 0;
    LFLD(s32, self, 0x74) = 0;
    LFLD(s32, self, 0x78) = 0;
    LFLD(s32, self, 0x80) = 0;
    LFLD(s32, self, 0x7c) = 0;
    LFLD(s32, self, 0x88) = 0;
    LFLD(s32, self, 0x84) = 0;
    LFLD(s32, self, 0x90) = 0;
    LFLD(s32, self, 0x8c) = 0;
    LFLD(s32, self, 0x98) = 0;
    LFLD(s32, self, 0x94) = 0;
    LFLD(s32, self, 0x9c) = 0;
    LFLD(s32, self, 0xa0) = 0;
    LFLD(s32, self, 0xa4) = 0;
    for (i = 0; i < 4; i++) {
        ((s32 *)((u8 *)self + 0xa8))[i] = 0;
    }
    LFLD(u16, self, 0xb8) = 0;
    LFLD(u16, self, 0xba) = 0;
    LFLD(s32, self, 0xbc) = 0;
    LFLD(s32, self, 0xc0) = 0;
}

}

}  // namespace m_Lo_0217ad54

// ---- Lo_0217adfc
namespace m_Lo_0217adfc {

typedef struct {
    u8 pad[0xa8];
    VObj *objs[4];
} Arr0217adfc;

extern "C" {
void *func_ov000_0214b724(void *p);

void func_ov000_0217adfc(u8 *self) {
    s32 i;
    LO_FREE_V(self, 0x60);
    LO_FREE_V(self, 0x5c);
    LO_FREE_V(self, 0x64);
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(void *, self, 0x6c) != NULL) {
            void *p = LFLD(void *, self, 0x6c);
            if (p != NULL) {
                func_ov000_0214b724(p);
                func_0203de1c(p);
            }
            LFLD(void *, self, 0x6c) = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x74);
    LO_FREE_V(self, 0x78);
    LO_FREE_V(self, 0x7c);
    LO_FREE_V(self, 0x80);
    LO_FREE_V(self, 0x84);
    LO_FREE_V(self, 0x88);
    LO_FREE_V(self, 0x8c);
    LO_FREE_V(self, 0x90);
    LO_FREE_V(self, 0x94);
    LO_FREE_V(self, 0x98);
    LO_FREE_V(self, 0x9c);
    LFLD(u8, self, 0x71) = 0;
    LO_FREE_M(self, 0xa0);
    for (i = 0; i < 4; i++) {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (((Arr0217adfc *)self)->objs[i] != NULL) {
            VObj *p_ = ((Arr0217adfc *)self)->objs[i];
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            ((Arr0217adfc *)self)->objs[(u32)i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x3c);
}
}

}  // namespace m_Lo_0217adfc

// ---- Lo_0217b230
namespace m_Lo_0217b230 {

class Obj0217b230 : public VObj {
public:
    u32 b0 : 2;
    u32 b2 : 1;
    u32 b3 : 3;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 5;
    u32 b13 : 9;
    u32 b22 : 1;
    u32 b23 : 1;
    u32 b24 : 1;
    u32 b25 : 7;
    u8 pad_08[0x1c];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0xa];
    u8 unk_36;
    s8 unk_37;
    s32 unk_38;
    u8 pad_3c[8];
    u8 unk_44[4];
    u8 unk_48[4];
    s32 unk_4c;
    u8 pad_50[0x20];
    s32 unk_70;
    s16 unk_74;
    s16 unk_76;
    s32 unk_78;
};

typedef struct {
    s32 unk_00;
    s32 unk_04;
} Data02097ce0;

extern "C" {
extern u8 data_0208ba70[];
extern Data02097ce0 *data_02097ce0;
void *func_0203dd9c(u32 size);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void func_0204ca70(void *p);

Obj0217b230 *func_ov000_0217b230(void *unused, s32 a1, s32 a2) {
    Obj0217b230 *o = (Obj0217b230 *)func_0203dd9c(0xb8);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208ba70);
        func_0204c7d0(o);
    }
    o->unk_37 = 1;
    o->unk_28 = a2;
    o->unk_24 = a1;
    o->unk_4c = func_0204c4fc(o->unk_28, o->unk_38, o->unk_24, o->unk_44, o->unk_48, o->unk_37 ? 1 : 0);
    data_02097ce0->unk_04 = o->unk_28;
    o->unk_70 = -0x1c8d;
    o->b8 = 0x1e;
    o->unk_74 = 0x7fff;
    o->unk_76 = 0x2adf;
    o->unk_78 = 0x8000;
    o->unk_36 = 1;
    o->b6 = 1;
    o->b22 = 1;
    o->b24 = 1;
    o->vfunc_14();
    o->b2 = 1;
    func_0204ca70(o);
    return o;
}

}

}  // namespace m_Lo_0217b230

// ---- Menu_0217b324
namespace m_Menu_0217b324 {

typedef struct {
    u16 language_color;
    u16 birthday;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OwnerInfo;

typedef struct {
    u8 unk_00;
    u8 flags;
    u8 pad_02[6];
    u32 time;
    s32 unk_0c;
    u32 lo : 8;
    u32 lv : 8;
    u32 b16 : 8;
    u32 b24 : 4;
    u32 hi : 4;
} SaveRec;

typedef struct {
    u8 unk_00[0x28];
    u8 *recs;
    u8 pad_2c[4];
    s32 stride;
} SaveList;

typedef struct {
    u8 b70;
    u8 b71;
    u8 pad_72[2];
    VObj *p74;
    VObj *p78;
    VObj *p7c;
    VObj *p80;
    VObj *p84;
    VObj *p88;
    VObj *p8c;
    VObj *p90;
    VObj *p94;
    VObj *p98;
    VObj *p9c;
} Slot;

typedef struct {
    u8 pad_00[0x70];
    s32 unk_70;
    s16 unk_74;
    s16 unk_76;
    u8 pad_78[0x20];
    char name[0x20];
} Item;

typedef struct {
    u8 pad_00[0x5c];
    SaveList *list;
    u8 pad_60[0x10];
    Slot slots[1];
    u8 pad_a0[8];
    Item *items[4];
    s16 count;
    s16 unk_ba;
} Self;


extern "C" {
extern void *data_02149ef8;
char *func_0204c0e8(void *msg, s32 id);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_02040a98(char *dst, s32 n);
void func_02070874(char *dst, const char *src, const char *arg);
char *func_02061df0(u16 lv);
char *func_020620ac(u16 id);
void func_0200779c(char *dst, const char *fmt, ...);
void OS_GetOwnerInfo(OwnerInfo *info);
void func_02040b0c(char *dst, s32 *dstLen, const u16 *src, s32 *srcLen);
BOOL OS_IsRunOnTwl(void);
Item *func_ov000_0217b230(Self *self, const char *str, s32 a2);

#define FREE_SLOT(f)                         \
    do {                                     \
        u32 saved;                           \
        LO_HEAP_PUSH(saved);                 \
        if (self->slots[idx].f != NULL) {               \
            VObj *p_ = self->slots[idx].f;              \
            if (p_ != NULL) {                \
                p_->vfunc_04();              \
            }                                \
            self->slots[idx].f = NULL;                  \
        }                                    \
        LO_HEAP_POP(saved);                  \
    } while (0)

#define ADD_ITEM(id, str)                                                                  \
    self->items[self->count] = func_ov000_0217b230(self, func_0204c0e8(msg, id), 4);       \
    STD_CopyString(self->items[self->count]->name, str);                                   \
    self->items[self->count]->unk_74 = 0x7fff;                                             \
    self->items[self->count]->unk_76 = 0x7fff;                                             \
    self->items[self->count]->unk_70 = -0x1c4d;                                            \
    self->count++

// The three time parts reuse the scratch variable n (the level number above). Its first two defs are then
// not forwarded into the calls, so the division is listed before the num/format arguments, as in the ROM
// (round pmA). STD_CopyString is void in this TU; its char * form adds a result copy that moves the
// automatic 100-instruction block split from before OS_GetOwnerInfo to after it.
void func_ov000_0217b324(Self *self, s32 idx) {
    char buf[0x80];
    char tmp[0x80];
    OwnerInfo info;
    char num[0x10];
    s32 max;
    s32 len;
    BOOL flag;
    SaveRec *rec;
    u8 lv;
    void *msg;
    s32 n;
    long i;

    msg = data_02149ef8;
    rec = (SaveRec *)(self->list->recs + (idx * self->list->stride + 0x14));
    flag = FALSE;
    FREE_SLOT(p74);
    FREE_SLOT(p78);
    FREE_SLOT(p7c);
    FREE_SLOT(p80);
    FREE_SLOT(p84);
    FREE_SLOT(p88);
    FREE_SLOT(p8c);
    FREE_SLOT(p90);
    FREE_SLOT(p94);
    FREE_SLOT(p98);
    FREE_SLOT(p9c);
    self->slots[idx].b71 = 0;
    self->slots[idx].b70 = rec->flags;
    self->slots[idx].b71 = rec->hi;
    lv = rec->lv & ~0xc0;
    if (lv > 20) {
        buf[0] = 0;
    } else if (lv <= 10) {
        buf[0] = 0;
    } else {
        STD_CopyString(buf, func_0204c0e8(msg, 0xb3));
        func_02040a98(num, 2);
        func_02070874(buf, buf, num);
        STD_ConcatenateString(buf, " ");
    }
    STD_CopyString(tmp, func_0204c0e8(msg, 0xb4));
    if (lv > 21) {
        n = -1;
    } else if (lv > 20) {
        n = lv - 20;
        if (rec->hi) {
            flag = TRUE;
        }
    } else {
        n = lv > 10 ? lv - 10 : lv;
    }
    if (n != -1) {
        if (flag) {
            STD_CopyString(tmp, func_0204c0e8(msg, 0xb7));
        } else if (n != 0) {
            func_02040a98(num, n);
            func_02070874(tmp, tmp, num);
        } else {
            STD_CopyString(tmp, func_0204c0e8(msg, 0xb5));
        }
        STD_ConcatenateString(buf, tmp);
        self->slots[idx].p74 = (VObj *)func_ov000_0217b230(self, buf, 4);
        STD_CopyString(buf, func_02061df0(lv));
        self->slots[idx].p78 = (VObj *)func_ov000_0217b230(self, buf, 8);
    }
    func_0200779c(buf, "%d", rec->lo);
    self->slots[idx].p80 = (VObj *)func_ov000_0217b230(self, buf, 4);
    self->slots[idx].p7c = (VObj *)func_ov000_0217b230(self, func_0204c0e8(msg, 0xae), 4);
    func_0200779c(buf, "%d", rec->unk_0c);
    self->slots[idx].p88 = (VObj *)func_ov000_0217b230(self, buf, 4);
    self->slots[idx].p84 = (VObj *)func_ov000_0217b230(self, func_0204c0e8(msg, 0xaf), 4);
    {
        u8 b = rec->b16;
        if (b == 0xff) {
            self->slots[idx].p90 = (VObj *)func_ov000_0217b230(self, "DEBUG", 4);
        } else {
            self->slots[idx].p90 = (VObj *)func_ov000_0217b230(self, func_020620ac(b), 4);
        }
    }
    self->slots[idx].p8c = (VObj *)func_ov000_0217b230(self, func_0204c0e8(msg, 0xb0), 4);
    STD_CopyString(buf, func_0204c0e8(msg, 0xb2));
    n = rec->time / 216000;
    func_0200779c(num, "%.2d", n);
    func_02070874(buf, buf, num);
    n = rec->time % 216000 / 3600;
    func_0200779c(num, "%.2d", n);
    func_02070874(buf, buf, num);
    n = rec->time % 216000 % 3600 / 60;
    func_0200779c(num, "%.2d", n);
    func_02070874(buf, buf, num);
    self->slots[idx].p98 = (VObj *)func_ov000_0217b230(self, buf, 4);
    self->slots[idx].p94 = (VObj *)func_ov000_0217b230(self, func_0204c0e8(msg, 0xb1), 4);
    OS_GetOwnerInfo(&info);
    max = 0x80;
    len = info.nickNameLength;
    func_02040b0c(buf, &max, info.nickName, &len);
    self->slots[idx].p9c = (VObj *)func_ov000_0217b230(self, buf, 4);
    ((Item *)self->slots[idx].p9c)->unk_70 = -0x1c4d;
    self->count = 0;
    for (i = 0; i < 4; i++) {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->items[i] != NULL) {
            VObj *p_ = (VObj *)self->items[i];
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            self->items[i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    if (rec->flags & 8) {
        ADD_ITEM(0xab, "3");
        self->unk_ba = 1;
    }
    ADD_ITEM(0xac, "1");
    if (OS_IsRunOnTwl()) {
        ADD_ITEM(0xad, "2");
    }
    ADD_ITEM(0x19c, "4");
}

}

}  // namespace m_Menu_0217b324

namespace m_Win_0217bd88 {

class Win0217bd88 : public VObj {
public:
    u8 pad04[8];
    u32 flags;
    u8 pad10[0xc];
    s32 unk_1c;
    u8 pad20[0x28];
    u16 unk_48;
    u8 pad4a[0xa];
    s32 unk_54;
    u8 pad58[0x10];
    s16 unk_68;
};

typedef struct {
    u8 pad[0x64];
    Win0217bd88 *win;
    s32 timer;
} Obj0217bd88;

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void *func_0204c0e8(void *a, u16 b);
void *func_0203dd9c(u32 size);
void func_ov000_0215c1bc(Win0217bd88 *w, s32 a, void *b);
void func_ov000_0215ce8c(Win0217bd88 *w, s32 a);

static inline BOOL Win_IsHidden(Win0217bd88 *w) {
    return (w->flags & 0x10000) == 0 ? TRUE : FALSE;
}

BOOL func_ov000_0217bd88(Obj0217bd88 *self, s32 a, s32 id) {
    Win0217bd88 *w;
    if (self->win != NULL) {
        BOOL busy = FALSE;
        if (self->timer != 0) {
            busy = TRUE;
        }
        if (self->win != NULL && Win_IsHidden(self->win)) {
            busy = TRUE;
        }
        if (!busy) {
            self->win->flags |= 0x40000;
        }
        return FALSE;
    }
    self->timer = 0x3c;
    w = (Win0217bd88 *)func_0203dd9c(0xe8);
    if (w != NULL) {
        VOBJ_SET_VTABLE(w, data_ov000_021cac60);
        w->vfunc_28();
        VOBJ_SET_VTABLE(w, data_ov000_021cad50);
        w->vfunc_28();
    }
    self->win = w;
    if (id == 0x6f || id == 0x74 || id == 0x86 || id == 0x82 || id == 0x84 || id == 0x75 || id == 0x76 || id == 0x6d) {
        self->win->flags |= 0x10000;
    } else {
        w->flags &= ~0x10000;
    }
    w = self->win;
    w->flags |= 8;
    w->unk_48 = 0x14a5;
    w->unk_54 = 0x1c;
    self->win->flags |= 0x20000;
    self->win->unk_1c = 4;
    self->win->vfunc_08();
    if (id != -1) {
        func_ov000_0215c1bc(self->win, 0x8000, func_0204c0e8(data_02149ef8, id));
    } else {
        func_ov000_0215ce8c(self->win, a);
    }
    self->win->unk_68 = -0x199a;
    self->win->vfunc_70();
    return TRUE;
}

}

}  // namespace m_Win_0217bd88

// ---- Lo_0217bf34
namespace m_Lo_0217bf34 {

struct LoDE { s32 d; s32 *e; };
extern "C" {

u32 func_0204045c(void);
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

BOOL func_ov000_0217bf34(void *self) {
    VObj *o = LFLD(VObj *, self, 0x64);
    if (o == NULL) {
        return FALSE;
    }
    if (!o->vfunc_1c()) {
        LFLD(s32, self, 0x68) = 0;
        LO_FREE_V(self, 0x64);
    } else {
        if (!LFLD(VObj *, self, 0x64)->vfunc_0c()) {
            return TRUE;
        }
        if (--LFLD(s32, self, 0x68) < 0) {
            LFLD(s32, self, 0x68) = 0;
        }
    }
    return FALSE;
}

}

}  // namespace m_Lo_0217bf34

// ---- Stub_0217c004
namespace m_Stub_0217c004 {

extern "C" {

BOOL func_ov000_0217bfe4(void *self) {
    if (*(void **)((u8 *)self + 0x64) != NULL) {
        return (BOOL)self;
    }
    return (*(u32 *)((u8 *)self + 0x4) & 0x10000) ? TRUE : FALSE;
}

void func_ov000_0217c004(void) {
}

}

}  // namespace m_Stub_0217c004

// ---- Lo_0217c008
namespace m_Lo_0217c008 {

extern "C" {
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);
BOOL func_ov000_0217a8f4(void);
typedef void (*LoCb0217c008)(void *self, void *arg);
BOOL func_ov000_0217bf34(void *self);
void func_ov000_0217c3b0(u8 *self);
void func_ov000_0217c5a8(u8 *self);
void func_ov000_0217c7b8(u8 *self);
void func_ov000_0217cddc(u8 *self);
void func_ov000_0217cf10(u8 *self);
void func_ov000_0217d0c4(u8 *self);
void func_ov000_0217d66c(u8 *self);
void func_ov000_0217dba4(u8 *self);
void func_ov000_0217ddd4(u8 *self);
extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208c994[];

static inline BOOL Lo0217c3b0_Busy(u8 *self) {
    u8 *p = LFLD(u8 *, self, 0x64);
    if (p == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!((LFLD(u32, p, 0xc) & 0x10000) == 0 ? TRUE : FALSE)) {
            LFLD(u32, p, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

static inline void Lo0217c008_SetMode(u8 *self, s32 m) {
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = m;
        LFLD(s32, self, 0x48) = 0;
    }
}

static inline BOOL Lo0217c008_Flag(VObj *o) {
    return LBIT(o, 0x48).b2 ? TRUE : FALSE;
}

void func_ov000_0217c008(u8 *self) {
    if (LFLD(s32, self, 0x8) != 0xd) {
        return;
    }
    if (!(LFLD(u32, self, 0x4) & 0x20000)) {
        LFLD(s32, self, 0x40) += 0x1000;
        if (LFLD(s32, self, 0x40) >= 0x5a000) {
            LFLD(s32, self, 0x40) -= 0x5a000;
        }
    }
    if (func_ov000_0217bf34(self)) {
        return;
    }
    switch (LFLD(s32, self, 0x4c)) {
    case 1:
        func_ov000_0217c3b0(self);
        break;
    case 2:
        switch (LFLD(s32, self, 0x50)) {
        case 0:
            LFLD(s32, self, 0x54) = 0;
            LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
            ((VObj *)self)->vfunc_48();
            LFLD(s32, self, 0x50) = 1;
            break;
        case 1:
            if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
                break;
            }
            if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
                break;
            }
            if (!((VObj *)self)->vfunc_54()) {
                break;
            }
            if (LFLD(s32, self, 0x54) == 0) {
                LFLD(u32, self, 0x4) |= 0x800000;
                Lo0217c008_SetMode(self, 5);
            }
            LFLD(s32, self, 0x4c) = 0;
            LFLD(s32, self, 0x50) = 0;
            LFLD(s32, self, 0x58) = -1;
            LFLD(s32, self, 0x54) = 0;
            break;
        }
        break;
    case 3:
        func_ov000_0217c5a8(self);
        break;
    case 4:
        func_ov000_0217c7b8(self);
        break;
    }
    if (LFLD(VObj *, self, 0x5c) != NULL) {
        LFLD(VObj *, self, 0x5c)->vfunc_0c();
        if (Lo0217c008_Flag(LFLD(VObj *, self, 0x5c))) {
            Lo0217c008_SetMode(self, 7);
        } else if (LFLD(VObj *, self, 0x60) != NULL) {
            LFLD(VObj *, self, 0x60)->vfunc_0c();
            if (Lo0217c008_Flag(LFLD(VObj *, self, 0x60))) {
                Lo0217c008_SetMode(self, 7);
            }
        }
    }
    switch (LFLD(s32, self, 0x44)) {
    case 1:
        func_ov000_0217cddc(self);
        break;
    case 2:
        func_ov000_0217cf10(self);
        break;
    case 3:
        func_ov000_0217d0c4(self);
        break;
    case 4:
        func_ov000_0217d66c(self);
        break;
    case 5:
        func_ov000_0217dba4(self);
        break;
    case 6:
        if (LFLD(s32, self, 0x48) != 0) {
            break;
        }
        if (Lo0217c3b0_Busy(self)) {
            break;
        }
        if (LFLD(LoCb0217c008, self, 0xbc) != NULL) {
            LFLD(LoCb0217c008, self, 0xbc)(self, LFLD(void *, self, 0xc0));
        }
        ((VObj *)self)->vfunc_0c(0);
        Lo0217c008_SetMode(self, 8);
        break;
    case 7:
        func_ov000_0217ddd4(self);
        break;
    }
}

void func_ov000_0217c3b0(u8 *self) {
    switch (LFLD(s32, self, 0x50)) {
    case 0:
        if (func_ov000_0217bd88(self, 0x8000, 0x72)) {
            LFLD(s32, self, 0x50) = 2;
        }
        break;
    case 2:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LFLD(s32, self, 0x54) = 1;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 3;
        break;
    case 3:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(u32, self, 0x4) |= 0x8000000;
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
        }
        LFLD(s32, self, 0x4c) = 0;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        break;
    }
}

void func_ov000_0217c5a8(u8 *self) {
    switch (LFLD(s32, self, 0x50)) {
    case 0:
        if (func_ov000_0217bd88(self, 0x8000, 0x7f)) {
            LFLD(s32, self, 0x50) = 1;
        }
        break;
    case 1:
        if (func_ov000_0217bd88(self, 0x8000, 0x80)) {
            LFLD(s32, self, 0x50) = 2;
        }
        break;
    case 2:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LFLD(s32, self, 0x54) = 1;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 3;
        break;
    case 3:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(u32, self, 0x4) |= 0x400000;
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
        }
        LFLD(s32, self, 0x4c) = 0;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        break;
    }
}

static inline void Lo0217c7b8_Reset(u8 *self) {
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x58) = -1;
    LFLD(s32, self, 0x54) = 0;
}

static inline BOOL Lo0217c7b8_Ready(u8 *self) {
    if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
        return FALSE;
    }
    if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
        return FALSE;
    }
    if (!((VObj *)self)->vfunc_54()) {
        return FALSE;
    }
    return TRUE;
}

void func_ov000_0217c7b8(u8 *self) {
    switch (LFLD(s32, self, 0x50)) {
    case 0:
        if (LFLD(s32, self, 0x58) == 1) {
            LFLD(s32, self, 0x50) = 1;
        } else {
            LFLD(s32, self, 0x50) = 5;
        }
        break;
    case 1:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LFLD(s32, self, 0x54) = 1;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 2;
        break;
    case 2:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(s32, self, 0x50) = 3;
            return;
        }
        Lo0217c7b8_Reset(self);
        break;
    case 3:
        LFLD(s32, self, 0x54) = 0x10001;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 4;
        break;
    case 4:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(s32, self, 0x50) = 5;
            return;
        }
        Lo0217c7b8_Reset(self);
        break;
    case 5:
        if (!func_ov000_0217bd88(self, 0x8000, 0x82)) {
            return;
        }
        LFLD(u8, data_02097dd0, 0x31) = 1;
        LFLD(u32, self, 0x4) |= 0x10000000;
        LFLD(s32, self, 0x50) = 6;
    case 6: {
        u8 *p = LFLD(u8 *, self, 0x5c);
        LFLD(u32, p, 0x48) |= 0x4000;
        LFLD(s32, p, 0x40) = 0;
        LFLD(s32, self, 0x50) = 7;
        break;
    }
    case 7:
        if (!(LBIT(LFLD(u8 *, self, 0x5c), 0x48).b1 ? TRUE : FALSE)) {
            return;
        }
        if (LFLD(s32, self, 0x58) == 1) {
            LFLD(s32, self, 0x50) = 9;
            return;
        }
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        func_ov000_0217bd88(self, 0x8000, 0x83);
        LFLD(s32, self, 0x50) = 8;
        break;
    case 8:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        if (!((LFLD(u32, self, 0x4) & 0x4000000) ? TRUE : FALSE)) {
            Lo0217c008_SetMode(self, 5);
        }
        Lo0217c7b8_Reset(self);
        break;
    case 9: {
        VObj *o = (VObj *)func_0203dd9c(0x58);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_0208b614);
            o->vfunc_14();
            VOBJ_SET_VTABLE(o, data_0208ca9c);
            o->vfunc_14();
            VOBJ_SET_VTABLE(o, data_0208c994);
            o->vfunc_14();
        }
        LFLD(VObj *, self, 0x60) = o;
        o->vfunc_08();
        LFLD(u32, LFLD(u8 *, self, 0x60), 0x48) |= 0x40;
        LBIT(LFLD(u8 *, self, 0x60), 0x48).b0 = 1;
        LFLD(s32, self, 0x50) = 10;
    }
    case 10: {
        u8 *p = LFLD(u8 *, self, 0x60);
        if (!(LBIT(p, 0x48).b7 ? TRUE : FALSE)) {
            return;
        }
        LFLD(u32, p, 0x48) |= 0x4000;
        LFLD(s32, p, 0x40) = 0;
        LFLD(s32, self, 0x50) = 11;
        break;
    }
    case 11:
        if (!(LBIT(LFLD(u8 *, self, 0x60), 0x48).b1 ? TRUE : FALSE)) {
            return;
        }
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LO_FREE_V(self, 0x60);
        func_ov000_0217bd88(self, 0x8000, 0x83);
        LFLD(s32, self, 0x50) = 8;
        break;
    }
}
}

}  // namespace m_Lo_0217c008

// ---- Lo_0217cddc
namespace m_Lo_0217cddc {

extern "C" {

extern void *data_ov000_021c9bf4[];
void *func_0203dd9c(u32 size);
void func_ov000_0214b810(void *p);
void *func_ov000_0214b724(void *p);
void *func_ov000_0214b6d8(void *p);
void func_ov000_0214b88c(void *p, void *name);
BOOL func_ov000_0214b8d8(void *p);
u8 func_ov000_0214b8f4(void *p);
s32 func_ov000_0214b6d0(void *p);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL HasFlag0217cddc(u8 *self, u32 bit) {
    return (LFLD(u32, self, 0x4) & bit) ? TRUE : FALSE;
}

static inline BOOL Has2_0217cddc(u8 *self, u32 bit) {
    return HasFlag0217cddc(self, bit) ? TRUE : FALSE;
}

void func_ov000_0217cddc(u8 *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0:
        if (LFLD(s32, self, 0xc) != 3) {
            if (!func_ov000_0217bd88(self, 0x8000, 0x6f)) {
                break;
            }
        }
        LFLD(u32, self, 0x4) &= 0xc00fffff;
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        if (LFLD(s32, self, 0xc) == 1) {
            LFLD(u32, self, 0x4) |= 0x1000000;
        } else if (LFLD(s32, self, 0xc) == 2) {
            LFLD(u32, self, 0x4) |= 0x2000000;
        } else if (LFLD(s32, self, 0xc) == 3) {
            LFLD(u32, self, 0x4) |= 0x4000000;
        }
        LFLD(s32, self, 0x48) = 1;
        break;
    case 1:
        if (Has2_0217cddc(self, 0x1000000) | Has2_0217cddc(self, 0x2000000) | Has2_0217cddc(self, 0x4000000)) {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 3;
                LFLD(s32, self, 0x48) = 0;
            }
        } else {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 2;
                LFLD(s32, self, 0x48) = 0;
            }
        }
        break;
    }
}

static inline BOOL IsSet0217cf10(u8 *self) {
    return LFLD(s32, self, 0x4c) != 0 ? TRUE : FALSE;
}

void func_ov000_0217cf10(u8 *self) {
    if (LFLD(void *, self, 0x6c) != NULL) {
        func_ov000_0214b810(LFLD(void *, self, 0x6c));
    }
    switch (LFLD(s32, self, 0x48)) {
    case 0: {
        void *p;
        HEAP_DELETE(void *, LFLD(void *, self, 0x6c), func_ov000_0214b724(p); func_0203de1c(p));
        p = func_0203dd9c(0x3c);
        if (p != NULL) {
            p = func_ov000_0214b6d8(p);
        }
        LFLD(void *, self, 0x6c) = p;
        func_ov000_0214b88c(p, data_ov000_021c9bf4[1]);
        LFLD(s32, self, 0x48) = 1;
        break;
    }
    case 1:
        if (!func_ov000_0214b8d8(LFLD(void *, self, 0x6c))) {
            break;
        }
        if (!func_ov000_0214b8f4(LFLD(void *, self, 0x6c))) {
            if (func_ov000_0214b6d0((u8 *)LFLD(void *, self, 0x6c) + 0x20) == 3) {
                LFLD(s32, self, 0x48) = 3;
            } else {
                LFLD(s32, self, 0x48) = 2;
            }
            break;
        }
        if (LFLD(s32, self, 0x44) != 7) {
            LFLD(s32, self, 0x44) = 3;
            LFLD(s32, self, 0x48) = 0;
        }
        break;
    case 3:
        if (func_ov000_0217bd88(self, 0x8000, 0x70)) {
            LFLD(s32, self, 0x48) = 2;
        }
        break;
    case 2:
        if (!func_ov000_0217bd88(self, 0x8000, 0x71)) {
            break;
        }
        LFLD(s32, self, 0x4c) = 1;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 4;
        break;
    case 4:
        if (IsSet0217cf10(self)) {
            break;
        }
        func_ov000_0217bd88(self, 0x8000, 0x6f);
        if (LFLD(s32, self, 0x44) != 7) {
            LFLD(s32, self, 0x44) = 3;
            LFLD(s32, self, 0x48) = 0;
        }
        break;
    }
}

}

}  // namespace m_Lo_0217cddc

// ---- Lo_0217d0c4
namespace m_Lo_0217d0c4 {

extern "C" {

extern void *data_0214a424;
void func_020473ac(void *s, s32 state);
void func_0206c4c4(void *p);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL Ready0217d0c4(void *o) {
    return (LFLD(u32, o, 0xc) & 0x10000) ? FALSE : TRUE;
}

static inline BOOL Busy0217d0c4(u8 *self) {
    void *o = LFLD(void *, self, 0x64);
    if (o == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!Ready0217d0c4(o)) {
            LFLD(u32, o, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

static inline BOOL Flag0217d0c4(u32 flags, u32 bit) {
    return (flags & bit) ? TRUE : FALSE;
}

static inline BOOL Waiting0217d0c4(u8 *self) {
    return LFLD(s32, self, 0x4c) != 0 ? TRUE : FALSE;
}

static inline BOOL B7_0217d0c4(void *o) { return LBIT(o, 0x48).b7 ? TRUE : FALSE; }
static inline BOOL B11_0217d0c4(void *o) { return LBIT(o, 0x48).b11 ? TRUE : FALSE; }
static inline BOOL B1_0217d0c4(void *o) { return LBIT(o, 0x48).b1 ? TRUE : FALSE; }
static inline BOOL B13_0217d0c4(void *o) { return LBIT(o, 0x48).b13 ? TRUE : FALSE; }
static inline BOOL B3_0217d0c4(void *o) { return LBIT(o, 0x48).b3 ? TRUE : FALSE; }

static inline void Exit0217d0c4(u8 *self, s32 next) {
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = next;
        LFLD(s32, self, 0x48) = 0;
    }
}

void func_ov000_0217d0c4(u8 *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0:
        func_020473ac(LFLD(void *, self, 0x5c), 1);
        LFLD(u32, LFLD(void *, self, 0x5c), 0x48) |= 0x40;
        LBIT(LFLD(void *, self, 0x5c), 0x48).b0 = 1;
        LFLD(s32, self, 0x48) = 1;
        break;
    case 1: {
        void *o = LFLD(void *, self, 0x5c);
        void *q;
        u32 flags;
        u8 b;
        if (!B7_0217d0c4(o)) {
            return;
        }
        q = LFLD(void *, o, 0x28);
        if (B11_0217d0c4(o)) {
            LFLD(s32, self, 0x48) = 9;
            return;
        }
        flags = LFLD(u32, self, 0x4);
        if (Flag0217d0c4(flags, 0x4000000)) {
            LFLD(s32, self, 0x48) = 0x13;
            return;
        }
        b = LFLD(u8, q, 0x15);
        if (!(b & 1)) {
            if (Flag0217d0c4(flags, 0x1000000)) {
                LFLD(s32, self, 0x48) = 0x16;
                return;
            }
            if (Flag0217d0c4(flags, 0x2000000)) {
                LFLD(s32, self, 0x48) = 0x16;
            } else {
                LFLD(s32, self, 0x48) = 2;
            }
        } else {
            if (b & 4) {
                LFLD(s32, self, 0x48) = 6;
            } else {
                LFLD(s32, self, 0x48) = 7;
            }
        }
        break;
    }
    case 2: {
        BOOL busy = FALSE;
        void *o = LFLD(void *, self, 0x64);
        if (LFLD(s32, self, 0x68) != 0) {
            busy = TRUE;
        }
        if (o != NULL && Ready0217d0c4(o)) {
            busy = TRUE;
        }
        if (busy) {
            return;
        }
        LFLD(u32, o, 0xc) |= 0x40000;
        LFLD(u32, self, 0x4) |= 0x100000;
        func_0206c4c4(data_0214a424);
        Exit0217d0c4(self, 5);
        break;
    }
    case 6:
        LFLD(u32, self, 0x4) |= 0x200000;
        func_0206c4c4(data_0214a424);
        Exit0217d0c4(self, 4);
        break;
    case 7: {
        void *o = LFLD(void *, self, 0x5c);
        LFLD(u32, o, 0x48) |= 0x400;
        LFLD(s32, o, 0x40) = 0;
        LFLD(s32, self, 0x48) = 8;
        break;
    }
    case 8: {
        void *o = LFLD(void *, self, 0x5c);
        if (B1_0217d0c4(o)) {
            Exit0217d0c4(self, 4);
            return;
        }
        if (B11_0217d0c4(o)) {
            LFLD(s32, self, 0x48) = 9;
        }
        break;
    }
    case 9:
        if (func_ov000_0217bd88(self, 0x8000, 0x85)) {
            LFLD(s32, self, 0x48) = 0xa;
        }
        break;
    case 10:
        if (func_ov000_0217bd88(self, 0x8000, 0x86)) {
            LFLD(s32, self, 0x48) = 0xb;
        }
        break;
    case 11:
        LFLD(u32, LFLD(void *, self, 0x5c), 0x48) |= 0x1000;
        LFLD(s32, self, 0x48) = 0xc;
        break;
    case 12: {
        void *o;
        if (Busy0217d0c4(self)) {
            return;
        }
        o = LFLD(void *, self, 0x5c);
        if (B1_0217d0c4(o)) {
            func_ov000_0217bd88(self, 0x8000, 0x87);
            LFLD(s32, self, 0x48) = 0xd;
            return;
        }
        if (B13_0217d0c4(o)) {
            func_ov000_0217bd88(self, 0x8000, 0x88);
            LFLD(s32, self, 0x48) = 0xe;
        }
        break;
    }
    case 13:
        Exit0217d0c4(self, 4);
        break;
    case 14:
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        func_020473ac(LFLD(void *, self, 0x5c), 4);
        LFLD(s32, self, 0x48) = 0xf;
        break;
    case 15:
        LFLD(s32, self, 0x4c) = 4;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = 0;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 0x11;
        break;
    case 17:
        if (Waiting0217d0c4(self)) {
            return;
        }
        Exit0217d0c4(self, 4);
        break;
    case 19:
        if (!(LFLD(u8, LFLD(void *, self, 0x5c), 0x8) == 0 ? TRUE : FALSE)) {
            LFLD(s32, self, 0x48) = 0x14;
            return;
        }
        Exit0217d0c4(self, 6);
        break;
    case 20:
        if (!func_ov000_0217bd88(self, 0x8000, 0x6d)) {
            return;
        }
        LFLD(u32, LFLD(void *, self, 0x5c), 0x48) |= 0x8;
        LFLD(s32, self, 0x48) = 0x15;
        break;
    case 21:
        if (B3_0217d0c4(LFLD(void *, self, 0x5c))) {
            return;
        }
        if (Busy0217d0c4(self)) {
            return;
        }
        Exit0217d0c4(self, 6);
        break;
    case 22:
        if (func_ov000_0217bd88(self, 0x8000, 0x174)) {
            LFLD(s32, self, 0x48) = 0x17;
        }
        break;
    case 23:
        if (Flag0217d0c4(LFLD(u32, self, 0x4), 0x1000000)) {
            if (!func_ov000_0217bd88(self, 0x8000, 0x148)) {
                break;
            }
        } else {
            if (!func_ov000_0217bd88(self, 0x8000, 0x175)) {
                break;
            }
        }
        Exit0217d0c4(self, 6);
        break;
    }
}

}

}  // namespace m_Lo_0217d0c4

// ---- Lo_0217d66c
namespace m_Lo_0217d66c {

extern "C" {

extern void *data_02097e4c;
BOOL func_0203e688(void);
void func_020473ac(void *s, s32 state);
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov000_0217b324(void *self, s32 a);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL Ready0217d66c(void *o) {
    return (LFLD(u32, o, 0xc) & 0x10000) ? FALSE : TRUE;
}

static inline BOOL Busy0217d66c(u8 *self) {
    void *o = LFLD(void *, self, 0x64);
    if (o == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!Ready0217d66c(o)) {
            LFLD(u32, o, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

static inline BOOL Flag0217d66c(u32 flags, u32 bit) {
    return (flags & bit) ? TRUE : FALSE;
}

static inline BOOL Waiting0217d66c(u8 *self) {
    return LFLD(s32, self, 0x4c) != 0 ? TRUE : FALSE;
}

static inline void SePlay0217d66c(s32 id) {
    func_02049a48(data_02097e4c, id, -1, -1, -1);
}

void func_ov000_0217d66c(u8 *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0: {
        u32 flags;
        if (Busy0217d66c(self)) {
            return;
        }
        flags = LFLD(u32, self, 0x4);
        if (Flag0217d66c(flags, 0x4000000)) {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 6;
                LFLD(s32, self, 0x48) = 0;
            }
            return;
        }
        if (Flag0217d66c(flags, 0x1000000) || Flag0217d66c(flags, 0x2000000)) {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
            return;
        }
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        func_020473ac(LFLD(void *, self, 0x5c), 4);
        func_ov000_0217b324(self, 0);
        LFLD(s32, self, 0x48) = 1;
        break;
    }
    case 1:
        if (!func_0203e688()) {
            return;
        }
        SePlay0217d66c(0x27);
        LFLD(s32, self, 0x48) = 2;
        break;
    case 2:
        LFLD(s32, self, 0xa4) += 0x1000;
        if (LFLD(s32, self, 0xa4) < 0x18000) {
            return;
        }
        LFLD(s32, self, 0xa4) = 0x18000;
        LFLD(u32, self, 0x4) &= ~0x10000;
        LFLD(s32, self, 0x48) = 3;
        break;
    case 3: {
        Pad *pad;
        if (Flag0217d66c(LFLD(u32, self, 0x4), 0x10000)) {
            return;
        }
        pad = data_02097dc8;
        if ((pad->cur & 0x548) == 0x548) {
            LFLD(s32, self, 0x48) = 0xc;
            return;
        }
        if (pad->trig & 1) {
            switch (LFLD(s8, LFLD(u8 *, self + LFLD(s16, self, 0xba) * 4, 0xa8), 0x98)) {
            case '1':
                LFLD(s32, self, 0x48) = 4;
                return;
            case '2':
                LFLD(s32, self, 0x48) = 6;
                return;
            case '3':
                LFLD(s32, self, 0x48) = 8;
                return;
            case '4':
                LFLD(s32, self, 0x48) = 10;
                return;
            }
            break;
        }
        if (pad->trig & 2) {
            SePlay0217d66c(0x28);
            LFLD(u32, self, 0x4) |= 0x20000000;
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
            return;
        }
        if (pad->repeat & 0x80) {
            LFLD(s16, self, 0xba)++;
            if (LFLD(s16, self, 0xba) >= LFLD(s16, self, 0xb8)) {
                LFLD(s16, self, 0xba) = LFLD(s16, self, 0xb8) - 1;
                return;
            }
            SePlay0217d66c(0x1d);
            return;
        }
        if (pad->repeat & 0x40) {
            LFLD(s16, self, 0xba)--;
            if (LFLD(s16, self, 0xba) < 0) {
                LFLD(s16, self, 0xba) = 0;
                return;
            }
            SePlay0217d66c(0x1d);
        }
        break;
    }
    case 4:
        LFLD(s32, self, 0x4c) = 2;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 5;
        break;
    case 5:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 6:
        LFLD(s32, self, 0x4c) = 1;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 7;
        break;
    case 7:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 8:
        LFLD(s32, self, 0x4c) = 3;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 9;
        break;
    case 9:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 10:
        if (func_ov000_0217bd88(self, 0x8000, 0x19d)) {
            LFLD(s32, self, 0x48) = 0xb;
        }
        break;
    case 11:
        if (LFLD(VObj *, self, 0x64) != NULL && LFLD(VObj *, self, 0x64)->vfunc_0c() &&
            (data_02097dc8->cur & 0x548) == 0x548) {
            LFLD(u32, LFLD(void *, self, 0x64), 0xc) |= 0x40000;
            LFLD(s32, self, 0x48) = 0xc;
            return;
        }
        if (!Busy0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 12:
        if (Busy0217d66c(self)) {
            return;
        }
        LFLD(s32, self, 0x4c) = 4;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = 1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 9;
        break;
    case 13:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    }
}

}

}  // namespace m_Lo_0217d66c

// ---- Lo_0217dba4
namespace m_Lo_0217dba4 {

extern "C" {
extern void *data_ov000_021ccd54;
extern void *data_0214a424;
void func_0206c994(void *p);
void func_ov000_02186204(void *p, s32 a);
void func_ov000_0218781c(void *p, s32 a);
void func_ov000_02187588(void *p);
void func_ov000_0218283c(void *p, s32 a);
void func_ov000_02182920(void *p);
void func_ov000_021829f8(void *p);

static inline BOOL Bit(u32 f, u32 m) {
    return (f & m) ? TRUE : FALSE;
}

static inline BOOL IsFree(u8 *sub) {
    return (LFLD(u32, sub, 0xc) & 0x10000) ? FALSE : TRUE;
}

static inline BOOL CheckSub(u8 *self) {
    u8 *sub = LFLD(u8 *, self, 0x64);
    if (sub == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!IsFree(sub)) {
            LFLD(u32, sub, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

void func_ov000_0217dba4(VObj *self) {
    u32 f;
    LFLD(u32, self, 4) |= 0x10000;
    if (CheckSub((u8 *)self)) {
        return;
    }
    if (LFLD(s32, self, 0xa4) != 0) {
        LFLD(s32, self, 0xa4) -= 0x1000;
        if (LFLD(s32, self, 0xa4) <= 0) {
            LFLD(s32, self, 0xa4) = 0;
        }
        return;
    }
    LFLD(VObj *, self, 0x5c)->vfunc_74();
    f = LFLD(u32, self, 4);
    if (f & 0x10000000) {
        if (LFLD(s32, self, 0x44) != 7) {
            LFLD(s32, self, 0x44) = 1;
            LFLD(s32, self, 0x48) = 0;
        }
        return;
    }
    if (!(f & 0x20000000)) {
        if (Bit(f, 0x1000000)) {
            if (!Bit(f, 0x200000)) {
                func_0206c994(data_0214a424);
            }
            func_ov000_02186204(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x2000000)) {
            if (!Bit(f, 0x200000)) {
                func_0206c994(data_0214a424);
            }
            func_ov000_0218781c(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x8000000)) {
            func_ov000_02187588(data_ov000_021ccd54);
        } else if (Bit(f, 0x100000) || Bit(f, 0x200000)) {
            func_ov000_0218283c(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x400000)) {
            func_ov000_02182920(data_ov000_021ccd54);
        } else if (Bit(f, 0x800000)) {
            func_ov000_021829f8(data_ov000_021ccd54);
        }
        LFLD(u8, data_ov000_021ccd34, 0) = 1;
        LFLD(LoTaskFlags, LFLD(void *, data_ov000_021ccd34, 0x10), 0).b0 = 1;
    }
    self->vfunc_0c(0);
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = 8;
        LFLD(s32, self, 0x48) = 0;
    }
}
}

}  // namespace m_Lo_0217dba4

// ---- Lo_0217ddd4
namespace m_Lo_0217ddd4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
BOOL func_0206f21c(u16 a, s32 b);
void *func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ddd4(void *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0: {
        u32 fl;
        s32 k;
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        if (LFLD(VObj *, self, 0x60) != NULL) {
            LFLD(VObj *, self, 0x60)->vfunc_74();
        }
        fl = LFLD(u32, self, 4);
        if (fl & 0x10000000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x84);
        } else if (fl & 0x100000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x75);
        } else {
            k = func_ov000_0217bd88(self, 0x8000, 0x76);
        }
        if (!k) {
            return;
        }
        LFLD(s32, self, 0x48) = 1;
    }
    case 1:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        break;
    }
}

extern s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
typedef struct { s32 x, y, z; } V0217de7c;
void func_ov000_0217df5c(void *self, V0217de7c *v);
void func_ov000_0217e560(void *self, V0217de7c *v);

void func_ov000_0217de7c(void *self) {
    s32 st;
    if (LFLD(void *, self, 0x24) == NULL) {
        return;
    }
    st = LFLD(s32, self, 0x44);
    if ((st == 4 || st == 5 || st == 7) && LFLD(s32, self, 0xa4) != 0) {
        s32 t = FX_Div(LFLD(s32, self, 0xa4), 0x18000);
        s32 c = 0x1000 - FX_SinCosTable_[((t * 0x4000) >> 16) * 2];
        V0217de7c v;
        v.x = LO_FX_MUL(c, 0x140000);
        v.y = 0;
        v.x &= ~0xfff;
        v.y &= ~0xfff;
        func_ov000_0217df5c(self, &v);
        func_ov000_0217e560(self, &v);
    }
    if (LFLD(VObj *, self, 0x64) != NULL) {
        LFLD(VObj *, self, 0x64)->vfunc_20();
    }
}

}

}  // namespace m_Lo_0217ddd4

// ---- Lo_0217df5c
namespace m_Lo_0217df5c {

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0217df5c;

#define MF(m) LFLD(LoMdlFlags0217df5c, m, 0x6c)

typedef struct {
    s32 x, y, z;
} LoVec0217df5c;

extern "C" {

extern u8 *data_02097d48;
extern u8 data_0208b3d0[];
extern LoVec0217df5c data_ov000_021c9c10;
int func_02043d48(void *p);
void func_02043d20(void *p, s32 a);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
s32 func_ov000_0214b8ec(void *p);
void func_ov000_0214b1a0(LoVec0217df5c *pos, LoVec0217df5c *col, s32 a, s32 b);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPart(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

static inline void LoSetPosFx0217df5c(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

static inline void LoSetPosV0217df5c(void *m, LoVec0217df5c *p) {
    LFLD(s32, m, 0xfc) = p->x;
    LFLD(s32, m, 0x100) = p->y;
}

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

void func_ov000_0217df5c(u8 *self, LoVec0217df5c *pos) {
    LoVec0217df5c v;
    u8 *g = data_02097d48;
    u32 size;
    u8 i;
    MF(LFLD(void *, self, 0xa0)).b19 = 1;
    MF(LFLD(void *, self, 0xa0)).f7 = func_02043d48(g + 0x8b0);
    MF(LFLD(void *, self, 0xa0)).f2 = 0x1c;
    LoSetPosV0217df5c(LFLD(void *, self, 0xa0), pos);
    LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1ccd;
    LoModelPlayPart(LFLD(void *, self, 0xa0), 1);
    if (LFLD(u8, self, 0x71) != 0) {
        v.x = pos->x - 0x6f000;
        v.y = pos->y - 0x4a000;
        v.z = pos->z;
        MF(LFLD(void *, self, 0xa0)).b19 = 0;
        MF(LFLD(void *, self, 0xa0)).f2 = 0x1f;
        for (i = 0; i < 3; i++) {
            LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c8d;
            LoSetPosV0217df5c(LFLD(void *, self, 0xa0), &v);
            LoModelPlayPart(LFLD(void *, self, 0xa0), 2);
            if (i < LFLD(u8, self, 0x71)) {
                LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c4d;
                LoSetPosV0217df5c(LFLD(void *, self, 0xa0), &v);
                LoModelPlayPart(LFLD(void *, self, 0xa0), 3);
            }
            v.x += 0xc000;
        }
    }
    func_02043d20(g + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x1f00d0);
    G3_Cmd1(0x20, 0);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0x16000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0xc000, 0x1000);
    size = *(u32 *)0x020828f8;
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xc000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xf4000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0xaf000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0x2000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xbe000, pos->y + 0x74000, -0x1c8d);
    G3_Vec(0x1b, 0x66000, 0x71000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    {
    LoVec0217df5c c = data_ov000_021c9c10;
    v.x = pos->x + 0xbe000;
    v.y = pos->y + 0x6e000;
    v.z = -0x1c4d;
    func_ov000_0214b1a0(&v, &c, 0x1f, func_ov000_0214b8ec(LFLD(void *, self, 0x6c)));
    }
}

}

}  // namespace m_Lo_0217df5c
#undef MF

// ---- Lo_0217e560
namespace m_Lo_0217e560 {

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0217e560;

#define MF(m) LFLD(LoMdlFlags0217e560, m, 0x6c)

extern "C" {

extern u8 *data_02097d48;
int func_02043d48(void *p);
extern s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPart(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

static inline void LoSetPosFx0217e560(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

// The menu items (func_ov000_0217b230) are 0xb8-byte TextWins. Main/Gfx/TextWin.h clashes with
// LoCommon.h, so this is its vtable up to Render (0x90). SetPos (0x20) and Render return void.
struct LoTextWin {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void OnSkip();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20(int a, int b);
    virtual char *unk_vf24(char *p);
    virtual char *unk_vf28(char *p);
    virtual char *unk_vf2c(char *p);
    virtual char *unk_vf30(char *p);
    virtual char *unk_vf34(char *p);
    virtual char *unk_vf38(char *p);
    virtual char *unk_vf3c(char *p);
    virtual char *unk_vf40(char *p);
    virtual char *unk_vf44(char *p);
    virtual char *unk_vf48(char *p);
    virtual char *ParseEscape(char *p);
    virtual char *unk_vf50(char *p);
    virtual char *unk_vf54(char *p);
    virtual char *unk_vf58(char *p);
    virtual char *unk_vf5c(char *p);
    virtual char *unk_vf60(char *p);
    virtual char *unk_vf64(char *p);
    virtual char *unk_vf68(char *p);
    virtual char *unk_vf6c(char *p);
    virtual char *unk_vf70(char *p);
    virtual char *unk_vf74(char *p);
    virtual char *unk_vf78(char *p);
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void Render();
};
#define OBJ(off) LFLD(LoTextWin *, self, off)

static inline void Row0217e560(u8 *self, int off, s32 x, s32 y) {
    OBJ(off)->unk_vf20(x + 0x12, y);
    OBJ(off)->Render();
    OBJ(off + 4)->unk_vf20(x + 0x87 - LFLD(s32, OBJ(off + 4), 0x44), y);
    OBJ(off + 4)->Render();
}
void func_ov000_0217e560(u8 *self, s32 *pos) {
    s32 x = pos[0] >> 12;
    u8 *g = data_02097d48;
    s32 step;
    s32 a;
    s32 s;
    s16 i;
    s32 y = pos[1] >> 12;
    s32 y0;
    s32 t;
    s32 lx;
    if (OBJ(0x74) != NULL) {
        OBJ(0x74)->unk_vf20(x + 0x80 - (LFLD(s32, OBJ(0x74), 0x44) >> 1), y + 0x1e);
        OBJ(0x74)->Render();
    }
    if (OBJ(0x78) != NULL) {
        OBJ(0x78)->unk_vf20(x + 0x80 - (LFLD(s32, OBJ(0x78), 0x44) >> 1), y + 0x2b);
        OBJ(0x78)->Render();
    }
    Row0217e560(self, 0x7c, x, y + 0x3d);
    Row0217e560(self, 0x84, x, y + 0x4a);
    Row0217e560(self, 0x8c, x, y + 0x57);
    Row0217e560(self, 0x94, x, y + 0x64);
    OBJ(0x9c)->unk_vf20(x + 0xbd - (LFLD(s32, OBJ(0x9c), 0x44) >> 1), y + 0xa0);
    OBJ(0x9c)->Render();
    t = LFLD(s32, self, 0x40) % 0x5a000;
    if (t <= 0x1e000) {
        s32 r = FX_Div(t, 0x1e000);
        if (r > 0x1000) {
            r = 0x1000;
        }
        s = FX_SinCosTable_[((r << 14) >> 16) * 2];
    } else if (t <= 0x5a000) {
        s32 r = FX_Div(t - 0x1e000, 0x3c000);
        if (r > 0x1000) {
            r = 0x1000;
        }
        s = FX_SinCosTable_[((r << 14) >> 16) * 2 + 1];
    } else {
        s = 0;
    }
    a = (LO_FX_MUL(s, 0x10000) >> 12) + 0xf;
    lx = x + 0x4c;
    step = 0;
    if (LFLD(s16, self, 0xb8) == 4) {
        y0 = y + 0x75;
        step = 0xe;
    } else if (LFLD(s16, self, 0xb8) == 3) {
        y0 = y + 0x79;
        step = 0x10;
    } else if (LFLD(s16, self, 0xb8) == 2) {
        y0 = y + 0x80;
        step = 0x12;
    } else {
        y0 = y + 0x89;
    }
    for (i = 0; i < LFLD(s16, self, 0xb8); i++) {
        ((LoTextWin **)(self + 0xa8))[i]->unk_vf20(lx - (LFLD(s32, ((LoTextWin **)(self + 0xa8))[i], 0x44) >> 1), y0 + i * step);
        ((LoTextWin **)(self + 0xa8))[i]->Render();
    }
    {
        s32 py = (LFLD(s16, self, 0xba) * step + y0 - 0x5a) << 12;
        MF(LFLD(void *, self, 0xa0)).b19 = 1;
        MF(LFLD(void *, self, 0xa0)).f7 = func_02043d48(g + 0x8b0);
        MF(LFLD(void *, self, 0xa0)).f2 = (u8)a;
        LoSetPosFx0217e560(LFLD(void *, self, 0xa0), (lx - 0x80) << 12, py);
    }
    LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c8d;
    LoModelPlayPart(LFLD(void *, self, 0xa0), 4);
}

}

}  // namespace m_Lo_0217e560
#undef MF


// ---- Dtor_0217e9c8
namespace m_Dtor_0217e9c8 {

extern "C" {

extern u8 data_ov000_021cbae0[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

VObj *func_ov000_0217e9c8(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbae0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x9, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217e9c8

// ---- Lo_0217ea30
namespace m_Lo_0217ea30 {

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits0217ea30;

extern "C" {
extern void *data_02149ef8;
extern void *data_02fe152c;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *func_0204c0e8(void *g, u32 id);
BOOL func_0206c4a0(void);
u16 func_02059454(void *a, s32 b, s32 c, s32 d);
BOOL func_ov000_02175e6c(void);

class Obj0217ea30 {
public:
    u8 data[0x1e4];
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Obj0217ea30() {
        *(void **)this = data_ov000_021cac60;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021caec8;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021cb1b0;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021cb0b8;
        ((VObj *)this)->vfunc_28();
    }
};

// `b` is declared as an unused third parameter and `a` as a one-element array
// because that gives the target's register allocation. Each arm ends with its
// own copy of the `new`/store/`vfunc_10` tail to get the target's branch layout.
s32 func_ov000_0217ea30(VObj *self, s32 msg, void *b) {
    u8 *p = LFLD(u8 *, self, 0x2c);
    void *g;
    VObj *o;
    void *a[1];
    switch (msg) {
    case 0:
        if (func_0206c4a0()) {
            if (func_02059454(data_02fe152c, 5, 1, 4)) {
                g = data_02149ef8;
                a[0] = func_0204c0e8(g, 0x1d);
                b = func_0204c0e8(g, 0x8d);
                o = (VObj *)new Obj0217ea30;
                LFLD(VObj *, self, 0x3c) = o;
                o->vfunc_10(b);
            } else {
                g = data_02149ef8;
                a[0] = func_0204c0e8(g, 0x1c);
                b = func_0204c0e8(g, 0x8d);
                o = (VObj *)new Obj0217ea30;
                LFLD(VObj *, self, 0x3c) = o;
                o->vfunc_10(b);
            }
        } else {
            g = data_02149ef8;
            a[0] = func_0204c0e8(g, 0x1e);
            b = func_0204c0e8(g, 0x8d);
            o = (VObj *)new Obj0217ea30;
            LFLD(VObj *, self, 0x3c) = o;
            o->vfunc_10(b);
        }
        LFLD(void *, LFLD(void *, self, 0x3c), 0x1dc) = a[0];
        LFLD(s16, LFLD(void *, self, 0x3c), 0x1e0) = 0;
        LFLD(void *, LFLD(void *, self, 0x3c), 0x8) = self;
        LFLD(void *, LFLD(void *, self, 0x3c), 0x84) = (void *)func_ov000_02175e6c;
        LFLD(VObj *, self, 0x3c)->vfunc_08();
        LFLD(s16, LFLD(void *, self, 0x3c), 0x68) = -0x1666;
        LFLD(Bits0217ea30, self, 0x4).b0 = true;
        LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x4000000;
        break;
    case 2:
        if (func_0206c4a0()) {
            if (func_02059454(data_02fe152c, 5, 1, 4)) {
                if (LFLD(u16, self, 0x44) == 0) {
                    LFLD(s32, p, 0x44) = 0;
                } else if (LFLD(u16, self, 0x44) == 1) {
                    LFLD(s32, p, 0x44) = 1;
                } else {
                    return 0;
                }
                self->vfunc_0c(0);
                return 1;
            } else {
                if (LFLD(u16, self, 0x44) == 0) {
                    LFLD(s32, p, 0x44) = 0;
                } else {
                    return 0;
                }
                self->vfunc_0c(0);
                return 1;
            }
        }
        LFLD(s32, p, 0x44) = 2;
        break;
    }
    return 0;
}

}

}  // namespace m_Lo_0217ea30

// ---- Lo_0217ed94
namespace m_Lo_0217ed94 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
BOOL func_0206f21c(u16 a, s32 b);
void *func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ed94(void) {
    LoTaskObj()->vfunc_2c();
}

void func_ov000_0217edb4(VObj *self) {
    LBIT(self, 4).b1 = 0;
    if (self->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
}

void func_ov000_0217ede8(void *self) {
    LFLD(s32, self, 0x20) = 0x8000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = -1;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
}

void func_ov000_0217ee18(void *self) {
    LO_FREE_V(self, 0x48);
    LO_FREE_M(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LO_FREE_M(self, 0x54);
}

}

}  // namespace m_Lo_0217ed94

// ---- Stub_0217ef34
namespace m_Stub_0217ef34 {

extern "C" {

void func_ov000_0217ef34(void) {
}

void func_ov000_0217ef38(void) {
}

}

}  // namespace m_Stub_0217ef34

// ---- Lo_0217ef3c
namespace m_Lo_0217ef3c {

extern "C" {

extern s32 data_02097d78[];
extern u8 *data_02097e48;
extern void *data_02fe152c;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd64;
extern u8 data_0208b318[];
extern void *data_02097e4c;
extern u8 *data_02097dc8;
u16 func_02059454(void *p, s32 a, s32 b, s32 c);
s32 func_ov000_0217ea30(VObj *self, s32 msg, void *b);
void func_ov000_0216f42c(void *a, void *b);
void func_020656b4(void *p);
void func_ov000_0218e514(void *p, s32 a);
void func_0206e900(char *dst, const char *src);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void STD_CopyString(void *dst, void *src);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_0204a2e0(void *mgr, s32 a);
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0204aab0(void *p);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_ov000_02187150(void *p, s32 a);
void func_ov000_02182b0c(void *p);
void *func_ov000_0219bf90(void);
void func_ov000_021b4774(void);
void func_020623fc(void);
void func_ov000_02182590(void *p);

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
} SndBits;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 2;
} Bits0e;

typedef struct {
    u8 b0 : 1;
} LoBits8;

#define STATE LFLD(s32, self, 0x3c)

static inline BOOL FadeIs4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

static inline BOOL FadeIs3(void) {
    BOOL r = FALSE;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else if (data_02097d78[0] == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL FadeIdle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline void SndStop(void) {
    u8 *p = data_02097e48;
    if (LFLD(SndBits, p, 0).b3) {
        LFLD(u16, p, 6) = 0x8000;
        LFLD(u16, p, 8) = 0x3c;
        LFLD(u16, p, 2) = 0;
    }
    p = data_02097e48;
    LFLD(u16, p, 0x74) = 0x8000;
    LFLD(u16, p, 0x70) = 0;
}

static inline BOOL LoBit1(VObj *self) {
    return LBIT(self, 4).b1 ? TRUE : FALSE;
}

static inline VObj *NewLoader(void) {
    VObj *o = (VObj *)func_0203dd9c(0x4c);
    if (o != NULL) {
        *(void **)o = data_0208b318;
        o->vfunc_08();
    }
    return o;
}

static inline u8 *NewWorldMapModel(void) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        char *n = "cewor1map00";
        char *a = "menu/worldmap";
        func_02041218(m + 0x88);
        func_02041440(m, n, 0);
        STD_CopyString(m + 0x2c, a);
    }
    return m;
}

void func_ov000_0217ef3c(VObj *self) {
    char buf[0x20];
    switch (STATE) {
    case 0:
        if (func_02059454(data_02fe152c, 5, 1, 3)) {
            LFLD(void *, LoSwitchTaskC(3, 0), 0x30) = (void *)func_ov000_0217ea30;
            self->vfunc_48();
            STATE = 1;
        } else {
            STATE = 3;
        }
        return;
    case 1:
        if (LoBit1(self)) {
            return;
        }
        if (!self->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x44) == 2) {
            STATE = 2;
        } else if (LFLD(s32, self, 0x44) == -1) {
            STATE = 3;
        } else if (LFLD(s32, self, 0x44) == 0) {
            STATE = 8;
        } else if (LFLD(s32, self, 0x44) == 1) {
            STATE = 10;
        }
        return;
    case 2:
    case 3:
        SndStop();
        if (!FadeIs3() && !FadeIs4()) {
            func_0203cc58(0xb4000, 1, -1);
        }
        if (STATE == 3) {
            STATE = 4;
        } else {
            STATE = 7;
            return;
        }
        LFLD(s32, self, 0x40) = 0;
    case 4: {
        VObj *o;
        if (!FadeIs4()) {
            return;
        }
        {
            u8 **pmq = &data_ov000_021ccd30;
            u8 *mq = *pmq;
            func_ov000_0216f42c(mq, LFLD(void *, mq, 0x11c));
            LFLD(void *, mq, 0x11c) = NULL;
            mq = *pmq;
            func_ov000_0216f42c(mq, LFLD(void *, mq, 0x118));
            LFLD(void *, mq, 0x118) = NULL;
        }
        LFLD(Bits0e, data_ov000_021ccd54, 0xe).b2 = 2;
        func_020656b4(data_0214a420);
        func_ov000_0218e514(data_ov000_021ccd68, 0xf000);
        LFLD(LoBits8, data_ov000_021ccd64, 0xc).b0 = 0;
        func_0206e900(buf, "pic/title");
        o = NewLoader();
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x48)->vfunc_24(buf, "celog1gov00");
        o = NewLoader();
        LFLD(VObj *, self, 0x50) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x50)->vfunc_24(buf, "celog1gov01");
        STATE = 5;
    }
    case 5: {
        BOOL ok = TRUE;
        u8 *m;
        u8 *p;
        if (!LFLD(VObj *, self, 0x48)->vfunc_2c()) {
            ok = FALSE;
        }
        if (!LFLD(VObj *, self, 0x50)->vfunc_2c()) {
            ok = FALSE;
        }
        if (!ok) {
            return;
        }
        if (++LFLD(s32, self, 0x40) < 0x1e) {
            return;
        }
        LFLD(s32, self, 0x40) = 0;
        m = NewWorldMapModel();
        LFLD(u8 *, self, 0x4c) = m;
        func_020417e0(LFLD(void *, self, 0x4c), (void *)LFLD(VObj *, self, 0x48)->vfunc_10());
        func_02041d9c(LFLD(void *, self, 0x4c), 2, 0xffff);
        m = NewWorldMapModel();
        LFLD(u8 *, self, 0x54) = m;
        func_020417e0(LFLD(void *, self, 0x54), (void *)LFLD(VObj *, self, 0x50)->vfunc_10());
        func_02041d9c(LFLD(void *, self, 0x54), 0, 0xffff);
        LFLD(s32, LFLD(void *, self, 0x54), 0x150) = -0x1ccd;
        func_0204a2e0(data_02097e4c, 0);
        func_0203cb78(0x3c000, 0, -1);
        p = data_02097e48;
        if (LFLD(SndBits, p, 0).b0) {
            if (LFLD(u16, p, 6) != 0xffff || LFLD(u16, p, 4) != 0x2f) {
                if (LFLD(u16, p, 2) != 10 && LFLD(u16, p, 2) != 0) {
                    if (LFLD(u16, p, 6) != 0xffff) {
                        func_0204aab0(p);
                    }
                    LFLD(u16, p, 2) = 1;
                } else {
                    LFLD(u16, p, 2) = 0;
                }
                LFLD(u16, p, 6) = 0x2f;
                LFLD(u16, p, 8) = 10;
            }
        }
        STATE = 6;
    }
    case 6:
        if (!FadeIdle()) {
            return;
        }
        if (++LFLD(s32, self, 0x40) <= 600) {
            if (!(LFLD(u16, data_02097dc8, 0x12) & 3)) {
                return;
            }
        }
        func_0203cc58(0xf000, 1, -1);
        STATE = 7;
        return;
    case 7:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        func_ov000_02187150(data_ov000_021ccd54, 0);
        STATE = 12;
        return;
    case 8:
        SndStop();
        func_0203cc58(0x3c000, 1, -1);
        STATE = 9;
    case 9:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        func_ov000_02182b0c(data_ov000_021ccd54);
        STATE = 12;
        return;
    case 10:
        SndStop();
        func_0203cc58(0x3c000, 1, -1);
        STATE = 11;
    case 11:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        if (func_ov000_0219bf90()) {
            func_ov000_021b4774();
        }
        func_020623fc();
        { u8 *q = data_ov000_021ccd54; q[0xac] = 1;
        func_ov000_02182590(q + 0xac); }
        STATE = 12;
        break;
    }
}

}

}  // namespace m_Lo_0217ef3c
#undef STATE

// ---- Lo_0217f778
namespace m_Lo_0217f778 {

typedef struct {
    u8 pad_00[0x24];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0x20];
    Model *unk_4c;
    u8 pad_50[4];
    Model *unk_54;
} Obj0217f778;

extern "C" {
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02043d20(void *obj, int a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

void func_ov000_0217f778(Obj0217f778 *self) {
    Model *m;
    if (self->unk_24 == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    self->unk_28 = FX_SinCosTable_[((s32)(self->unk_24 << 14) >> 16) * 2];
    m = self->unk_4c;
    if (m != NULL) {
        Model_PlayPart(m, 0);
    }
    {
        Model *m2 = self->unk_54;
        if (m2 != NULL) {
            Model_PlayPart(m2, 0);
        }
    }
}

}

}  // namespace m_Lo_0217f778

// ---- Lo_0217f8d0
namespace m_Lo_0217f8d0 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
BOOL func_0206f21c(u16 a, s32 b);
void *func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

VObj *func_ov000_0217f8d0(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x160);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbf60);
        LFLD(s32, obj, 0x3c) = 0;
        LFLD(s32, obj, 0x40) = 0;
        LFLD(s32, obj, 0x44) = 0;
        LFLD(s32, obj, 0x48) = 0;
        LFLD(s32, obj, 0x4c) = 0;
        LFLD(s32, obj, 0x50) = 0;
        LFLD(s32, obj, 0x54) = 0;
        LFLD(s32, obj, 0x58) = 0;
        LFLD(u16, obj, 0x5c) = 0;
        LFLD(u8, obj, 0x5e) = 0;
        LFLD(u8, obj, 0x5f) = 0;
    }
    obj->vfunc_08(0xc, 0xc8);
    return obj;
}

BOOL func_ov000_0217f958(void *self, void *msg) {
    if (msg != NULL) {
        void *o = LFLD(void *, self, 8);
        VObj *p;
        LBIT(LFLD(void *, o, 0x3c), 0xc).b2 = 1;
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 0;
        LBIT(LFLD(void *, o, 0x44), 0xc).b2 = 0;
        p = LFLD(VObj *, o, 0x44);
        p->vfunc_a8(func_ov000_02154b58(p, 1));
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    }
    return TRUE;
}

BOOL func_ov000_0217f9e8(void *self, void *msg) {
    if (msg != NULL) {
        void *o = LFLD(void *, self, 8);
        func_0206ecd4(0x100, (u8 *)o + 0x5f, LFLD(u16, msg, 6));
        if (LFLD(VObj *, o, 0x40) != NULL) {
            func_ov000_0215bb14(LFLD(VObj *, o, 0x40), (u8 *)o + 0x5f);
            LFLD(VObj *, o, 0x40)->vfunc_70();
        }
    }
    return TRUE;
}

BOOL func_ov000_0217fa34(void *self, void *msg) {
    void *o = LFLD(void *, self, 8);
    if (msg != NULL) {
        if (LFLD(u16, msg, 6) == 0) {
            void *a = LFLD(void *, o, 0x3c);
            void *n = LFLD(void *, a, 0x98);
            if (n == NULL) {
                n = NULL;
            } else {
                s32 c = LFLD(s8, a, 0xb1);
                while (c-- != 0) {
                    n = LFLD(void *, n, 0x2c);
                }
            }
            if (LFLD(u16, n, 6) != LFLD(u16, o, 0x5c)) {
                func_0206f21c(LFLD(u16, n, 6), 0);
                if (LFLD(u16, o, 0x5c) != 0) {
                    func_0206f21c(LFLD(u16, o, 0x5c), 1);
                }
            }
            LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
            LFLD(u8, o, 0x5e) = 1;
        }
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
        LBIT(LFLD(void *, o, 0x44), 0xc).b2 = 1;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    } else {
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
        LBIT(LFLD(void *, o, 0x44), 0xc).b2 = 1;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
    return FALSE;
}

}

}  // namespace m_Lo_0217f8d0

// ---- Heap_0217fb44
namespace m_Heap_0217fb44 {

typedef struct {
    u8 pad[0x3c];
    VObj *unk_3c;
    VObj *unk_40;
    VObj *unk_44;
    VObj *unk_48;
    void *unk_4c;
} Obj0217fb44;

extern "C" {

extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
void func_02036838(void *a, void *b, s32 c, s32 d);

void func_ov000_0217fb44(Obj0217fb44 *self) {
    HEAP_DELETE_VOBJ(self->unk_3c);
    HEAP_DELETE_VOBJ(self->unk_40);
    HEAP_DELETE_VOBJ(self->unk_44);
    HEAP_DELETE_VOBJ(self->unk_48);
    HEAP_DELETE_MODEL(self->unk_4c);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
}

}

}  // namespace m_Heap_0217fb44

// ---- Lo_0217fcc4
namespace m_Lo_0217fcc4 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
BOOL func_0206f21c(u16 a, s32 b);
void *func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217fcc4(void) {
    func_020359d0(data_0208cca0, 7, 0);
    func_020359d0(data_0208cc94, 7, 0);
}

BOOL func_ov000_0217fd04(void) {
    BOOL r = LoTaskObj()->vfunc_2c() ? TRUE : FALSE;
    r = (r & func_02035b90(data_0208cca0, 7)) ? TRUE : FALSE;
    return (r & func_02035b90(data_0208cc94, 7)) ? TRUE : FALSE;
}

}

}  // namespace m_Lo_0217fcc4

// ---- Lo_0217fd70
namespace m_Lo_0217fd70 {

extern "C" {
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern void *data_0208cb7c;
extern u8 data_0214b105[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cafc0[];
void *func_0203dd9c(u32 size);
void *func_0204c0e8(void *g, u32 id);
void func_ov000_0215bb14(void *o, void *s);
void func_ov000_02173648(void *self);
void func_ov000_021547e8(void *a, void *b, void *c, int d);
void func_ov000_021546ec(void *a, const void *b, const char *c, u16 d);
s32 func_ov000_02154b58(void *p, s32 a);
s32 func_0206ec48(u16 id);
u16 func_0206f080(u16 id);
u8 *func_0206ede8(u16 id);
BOOL func_ov000_0217f958(void);
BOOL func_ov000_0217f9e8(void);
BOOL func_ov000_0217fa34(void);

static inline s32 ItemCat0217fd70(u16 id) {
    return ((u16)(id & 0xf000) >> 12) - 1;
}

void func_ov000_0217fd70(VObj *self) {
    u8 *e;
    s32 i;
    s32 b;
    s32 n;
    u16 id;
    VObj *o;
    u16 iid;
    void *g;
    u8 *base;
    s32 a;
    if (self->vfunc_28()) {
        return;
    }
    g = data_02149ef8;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb4a8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb2a8;
    }
    LFLD(VObj *, self, 0x3c) = o;
    LFLD(VObj *, self, 0x3c)->vfunc_10(func_0204c0e8(g, 0x11a));
    LFLD(VObj *, self, 0x3c)->vfunc_14(func_0204c0e8(g, 0x11b));
    LFLD(s32, LFLD(void *, self, 0x3c), 0x20) = 5;
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0x2c;
        LFLD(s16, s, 0x68) = -0xccd;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s32, s, 0x58) = -0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0xccd;
    }
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x400000;
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x800000;
    LFLD(u8, LFLD(void *, self, 0x3c), 0xc0) = 0x80;
    LFLD(u8, LFLD(void *, self, 0x3c), 0xc1) = 3;
    func_ov000_021547e8(LFLD(void *, self, 0x3c), data_0214b105, data_0208cb7c, 0xb);
    func_ov000_021546ec(LFLD(void *, self, 0x3c), "menu/menu3d", "cem3d1icn00", 0xffff);
    if (LFLD(s32, self, 0xc) != 0) {
        LFLD(u16, self, 0x5c) = LFLD(s32, self, 0xc);
    }
    id = LFLD(u16, self, 0x5c);
    if (ItemCat0217fd70(id) == 1) {
        a = func_0206ec48(id);
        b = func_0206f080(id);
        e = (u8 *)LFLD(VObj *, self, 0x3c)->vfunc_74(a, id, (u16)b, 1);
        LFLD(s32, e, 0x10) = *func_0206ede8(LFLD(u16, self, 0x5c));
        LFLD(s16, e, 0xa) = 0xb;
        LFLD(s32, e, 0x24) = 4;
    }
    {
        base = data_0214a424 + 0x2a;
        for (i = 0; i < 100; i++) {
            n = base[i];
            iid = i | 0x2000;
            if (n > 0) {
                a = func_0206ec48(iid);
                b = func_0206f080(iid);
                e = (u8 *)LFLD(VObj *, self, 0x3c)->vfunc_74(a, iid, (u16)b, n);
                LFLD(s32, e, 0x10) = *func_0206ede8(LFLD(u16, self, 0x5c));
            }
        }
    }
    LFLD(void *, LFLD(void *, self, 0x3c), 0x8) = self;
    LFLD(void *, LFLD(void *, self, 0x3c), 0x84) = (void *)func_ov000_0217f958;
    LFLD(void *, LFLD(void *, self, 0x3c), 0x88) = (void *)func_ov000_0217f9e8;
    {
        VObj *t = LFLD(VObj *, self, 0x3c);
        t->vfunc_a8(func_ov000_02154b58(t, 0));
    }
    LFLD(VObj *, self, 0x3c)->vfunc_08();
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) &= ~2;
    o = (VObj *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = o;
    LFLD(s32, o, 0x20) = 2;
    LFLD(s32, LFLD(void *, self, 0x40), 0x24) = 0xf8;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s16, s, 0x64) = 4;
        LFLD(s16, s, 0x66) = 0x96;
        LFLD(s16, s, 0x68) = -0xccd;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s32, s, 0x58) = -0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0xccd;
    }
    LFLD(s32, LFLD(void *, self, 0x40), 0x2c) = 1;
    func_ov000_0215bb14(LFLD(void *, self, 0x40), func_0204c0e8(g, 0x11d));
    LFLD(VObj *, self, 0x40)->vfunc_70();
    LFLD(VObj *, self, 0x40)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x1e4);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb1b0;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb0b8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cafc0;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x44) = o;
    LFLD(VObj *, self, 0x44)->vfunc_10(func_0204c0e8(g, 0x11c));
    LFLD(s16, LFLD(void *, self, 0x44), 0x68) = -0x666;
    LFLD(VObj *, self, 0x44)->vfunc_08();
    LFLD(void *, LFLD(void *, self, 0x44), 0x8) = self;
    LFLD(void *, LFLD(void *, self, 0x44), 0x84) = (void *)func_ov000_0217fa34;
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 2;
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 4;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x48) = o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x48), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x48);
        LFLD(s16, s, 0x64) = 0xa5;
        LFLD(s16, s, 0x66) = 0x12;
        LFLD(s16, s, 0x68) = -0x99a;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x48);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0x99a;
    }
    LFLD(u32, LFLD(void *, self, 0x48), 0xc) |= 0x20000000;
    LFLD(VObj *, self, 0x48)->vfunc_f4(1, func_0204c0e8(g, 0x32));
    LFLD(VObj *, self, 0x48)->vfunc_08();
    func_ov000_02173648(self);
}

}

}  // namespace m_Lo_0217fd70
