// ov000 .text 0x0217e9c8..0x02180350, part of the Menu translation unit (.text 0x021763c8..0x02180350,
// string pool 0x021cba18..0x021cbac0). The former files are kept as they were, each in its own
// namespace, so that their local typedefs, inlines and extern declarations do not clash. The TU
// is split at the functions that do not match yet (0217a1f8, 0217b324, 0217e560); once they do,
// the four parts become one file and the pool can be claimed.
#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "ov000/HeapScope.h"
#include "types.h"

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
BOOL func_02059454(void *a, s32 b, s32 c, s32 d);
void func_ov000_02175e6c(void);

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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
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
extern char data_ov000_021cba75[];
extern char data_ov000_021cba7f[];
extern char data_ov000_021cba8b[];
extern char data_ov000_021cba97[];
extern char data_ov000_021cbaa3[];
extern void *data_02097e4c;
extern u8 *data_02097dc8;
BOOL func_02059454(void *p, s32 a, s32 b, s32 c);
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

static inline u8 *NewModel2(char *nm, char *arc) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        char *n = nm;
        char *a = arc;
        if (n) {
            func_02041218(m + 0x88);
            func_02041440(m, n, 0);
            STD_CopyString(m + 0x2c, a);
        }
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
        func_0206e900(buf, data_ov000_021cba75);
        o = NewLoader();
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x48)->vfunc_24(buf, data_ov000_021cba7f);
        o = NewLoader();
        LFLD(VObj *, self, 0x50) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x50)->vfunc_24(buf, data_ov000_021cba8b);
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
        m = NewModel2(data_ov000_021cba97, data_ov000_021cbaa3);
        LFLD(u8 *, self, 0x4c) = m;
        func_020417e0(LFLD(void *, self, 0x4c), (void *)LFLD(VObj *, self, 0x48)->vfunc_10());
        func_02041d9c(LFLD(void *, self, 0x4c), 2, 0xffff);
        m = NewModel2(data_ov000_021cba97, data_ov000_021cbaa3);
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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
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
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
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
extern u8 data_ov000_021cbab1[];
extern u8 data_ov000_021cba33[];
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
void func_ov000_021546ec(void *a, void *b, void *c, u16 d);
s32 func_ov000_02154b58(void *p, s32 a);
s32 func_0206ec48(u16 id);
s32 func_0206f080(u16 id);
u8 *func_0206ede8(u16 id);
void func_ov000_0217f958(void);
void func_ov000_0217f9e8(void);
void func_ov000_0217fa34(void);

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
    func_ov000_021546ec(LFLD(void *, self, 0x3c), data_ov000_021cbab1, data_ov000_021cba33, 0xffff);
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
