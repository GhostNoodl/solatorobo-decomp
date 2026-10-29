// ov000 .text 0x021763c8..0x0217a1f8, part of the Menu translation unit (.text 0x021763c8..0x02180350,
// string pool 0x021cba18..0x021cbac0). The former files are kept as they were, each in its own
// namespace, so that their local typedefs, inlines and extern declarations do not clash. The TU
// is split at the functions that do not match yet (0217a1f8, 0217b324); once they do,
// the three parts become one file and the pool can be claimed.
#include "ov000/LoCommon.h"
#include "ov000/VObj.h"
#include "nitro/fx.h"
#include "types.h"
#include "ov000/HeapScope.h"

// ---- Lo_021763c8
namespace m_Lo_021763c8 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
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
        STD_CopyString(buf, data_ov000_021cba18);
        STD_ConcatenateString(buf, data_ov000_021cba20);
        func_0205a840(LFLD(VObj *, data_ov000_021ccd34, 0x14), buf, data_ov000_021cba28);
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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_0205a9c8(void *p);
BOOL func_0206f66c(void *p);
s32 func_0206ec48(void *p);
s32 func_0206f080(void *p);
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
void func_0205aa30(void *p);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
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
        STD_CopyString(buf, data_ov000_021cba18);
        STD_ConcatenateString(buf, data_ov000_021cba20);
        func_0205a840(LFLD(VObj *, data_ov000_021ccd34, 0x14), buf, data_ov000_021cba28);
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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_0205a9c8(void *p);
BOOL func_0206f66c(void *p);
s32 func_0206ec48(void *p);
s32 func_0206f080(void *p);
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
extern u8 data_ov000_021cba33[];
void *func_0204c0e8(void *g, u32 id);
void func_0205aa30(void *p);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void func_ov000_0215d990(void *self, s32 a);
void func_ov000_0215bb14(void *o, void *s);
void func_ov000_02157c90(void *self, void *a);
void func_ov000_02157d2c(void *self, void *arg);
void func_ov000_021546ec(void *a, void *b, void *c, u16 d);
s32 func_ov000_02184a04(s32 x);
u8 *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u16 func_02059544(void *a, void *b, void *c, int d, u16 e);
void *func_0206ec48(u32 id);
u16 func_0206f080(u32 id);
u32 func_0206f0f4(u32 id);
void func_ov000_021774a4(void);
void func_ov000_02177698(void);

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
        func_ov000_021546ec(LFLD(void *, self, 0x4c), data_0208ccc8, data_ov000_021cba33, 0xffff);
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
        func_ov000_021546ec(LFLD(void *, self, 0x4c), data_0208ccc8, data_ov000_021cba33, 0xffff);
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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_0205a9c8(void *p);
BOOL func_0206f66c(void *p);
s32 func_0206ec48(void *p);
s32 func_0206f080(void *p);
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
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 func_0204c0e8(void *msg, s32 id);
void func_ov000_0215c1bc(void *p, s32 a, s32 b);
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
void func_ov000_02177bd8(void);

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
s32 func_0206d1d4(void *a, u16 b);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
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
extern u8 data_ov000_021cba33[];
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
void func_ov000_021546ec(void *a, void *b, void *c, u16 d);
s32 func_ov000_02154b58(void *p, s32 a);
s32 func_0206ec48(u16 id);
s32 func_0206f080(u16 id);
u32 func_0206f0f4(u16 id);
u8 *func_0206ede8(u16 id);
void func_ov000_02178100(void);
void func_ov000_02177f40(void);
void func_ov000_02178010(void);

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
    func_ov000_021546ec(LFLD(void *, self, 0x3c), data_0208ccc8, data_ov000_021cba33, 0xffff);
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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
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
void func_02049a48(void *p, s32 id, s32 a, s32 b, s32 c);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba20[];
extern u8 data_ov000_021cba28[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbe60[];
extern u8 *data_0214a424;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern u16 *data_02097dc8;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_0205a6a0(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0205a840(void *p, void *buf, const void *s);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_0206f3f0(u16 id, s32 v);
void func_0206d02c(void *a);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
    STD_CopyString(buf, data_ov000_021cba18);
    STD_ConcatenateString(buf, data_ov000_021cba3f);
    func_0204bfe4(LFLD(VObj *, self, 0x3c), buf, data_ov000_021cba45);
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
void func_0204c030(void *p);
void *func_0204c0e8(void *g, s32 id);
void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2334(void *self);
void func_ov000_021c2a88(void *self, void *a);
void func_ov000_021c3fd4(void *list, void *item);
void func_ov000_02179910(void);
void *func_0205976c(void *mgr, s32 kind);
u32 func_0205975c(void *mgr, s32 kind);
BOOL func_02059544(void *mgr, void *a, void *tbl, s32 b, u16 i);
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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
    STD_CopyString(buf, data_ov000_021cba18);
    STD_ConcatenateString(buf, data_ov000_021cba3f);
    func_0204bfe4(LFLD(VObj *, self, 0x3c), buf, data_ov000_021cba50);
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
void func_0204c030(void *p);
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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
void func_ov000_02175e6c(void);

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
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_0217a1d8(void) {
    LoTaskObj()->vfunc_2c();
}

}

}  // namespace m_Lo_0217a1d8

#ifdef NONMATCHING
// func_ov000_0217a1f8: 2 raw / 2 register-masked diffs (round o4C; was 3 / 3). The text argument is
// the "no text" id (func_ov000_0217a328 tests b != -1). As a literal, MWCC derives the -1 from the
// 0x78 argument (sub r2, r1, #0x79); as an enum local it is a fresh mvn r2, #0 as in the ROM. Left:
// the ROM lists mov r1, #0x78 before the mvn, we list it after. See docs/MATCHING.md, round o4C.
// Round qpK traced every refusal in the deriving pass (0x514140 / 0x510d40). In ARM code it is
// stopped only by a loop-preheader block, a K built straight into a physical register, or a
// different opcode or attribute word. None of these can happen in this loop-free call block.
// ---- Lo_0217a1f8
namespace m_Lo_0217a1f8 {

typedef enum { LO_TEXT_NONE = -1 } LoTextId;

extern "C" {
VObj *func_ov000_02176208(void);
void func_ov000_0217a328(VObj *self, s32 a, s32 b);
void func_ov000_02173648(VObj *self);

void func_ov000_0217a1f8(VObj *self) {
    VObj *o;
    LoTextId txt;
    LFLD(u32, self, 4) &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    txt = LO_TEXT_NONE;
    func_ov000_0217a328(self, 0x78, txt);
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
#endif
