#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02fe152c;
extern u8 data_ov000_021ccd24[];
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
u16 func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL func_0205a9c8(void *p);
void func_0204c7d0(void *p);
void *func_ov000_02173610(s32 kind);
void *func_ov000_0219bf90(void *p);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd24, 8))) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov000_021502d8(void *self) {
    BOOL r = TRUE;
    if (LFLD(u16, self, 0x42) == 0xffff) {
        if (!LoIsLoaded24()) {
            r = FALSE;
        }
    }
    if (!LFLD(VObj *, self, 0x3c)->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}


extern "C" {
extern void *data_02149ef8;
extern u8 data_ov000_021ccd24[];
extern void *data_ov000_021ca8d8[];
extern u8 *data_02097ce0;
extern void *data_0208cca0;
extern void *data_0208cb74;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021caac8[];
extern u8 *data_ov000_021ccd54;
extern char data_ov000_021ca93e[];
void *func_0204c0e8(void *g, u32 id);
BOOL func_0205aa30(void *p);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void STD_CopyString(void *dst, void *src);
void STD_ConcatenateString(void *dst, void *src);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);
s32 func_02061e7c(u16 a);
void *func_0204c08c(void *a, u16 id, void *out, s32 n);
void func_0204c6bc(void *a, void *b, void *c, void *fn);
void func_02040a98(char *buf, s32 n);
void *func_ov000_021824d0(void *a, s32 b);
void func_ov000_02153f90(void *p);
void func_ov000_0214dc20(void *self, s32 *msg);
s32 func_ov000_02151610(void);
void func_ov000_0215158c(void);

static inline void LoTextInit(u8 *t) {
    LFLD(s32, t, 0x4c) = func_0204c4fc(LFLD(s32, t, 0x28), LFLD(s32, t, 0x38), LFLD(s32, t, 0x24), t + 0x44, t + 0x48, LFLD(s8, t, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, t, 0x28);
}

void func_ov000_02150338(VObj *self) {
    u8 *m;
    void *arc;
    void *name;
        VObj *o;
    void *g;
    u8 *p;
    void *out[2];
    char buf[0x100];
    LFLD(u32, self, 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
    if (LFLD(u16, self, 0x42) == 0xffff) {
        if (!LFLD(VObj *, data_ov000_021ccd24, 8)->vfunc_34()) {
            func_0205aa30(LFLD(void *, data_ov000_021ccd24, 8));
        }
    }
    m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        arc = data_ov000_021ca8d8[0];
        name = data_ov000_021ca8d8[1];
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString(m + 0x2c, arc);
    }
    LFLD(u8 *, self, 0x44) = m;
    func_020417e0(LFLD(void *, self, 0x44), func_02034d88((void *)LFLD(VObj *, self, 0x3c)->vfunc_10(), LFLD(u8 *, self, 0x44) + 0x4c));
    LFLD(u32, LFLD(void *, self, 0x44), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, self, 0x44), 0, 0);
    m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        arc = data_0208cca0;
        name = data_0208cb74;
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString(m + 0x2c, arc);
    }
    LFLD(u8 *, self, 0x48) = m;
    func_020417e0(LFLD(void *, self, 0x48), func_02034d88(func_02035d5c(m + 0x2c), LFLD(u8 *, self, 0x48) + 0x4c));
    LFLD(u32, LFLD(void *, self, 0x48), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, self, 0x48), 0, 0xb);
    g = data_02149ef8;
    if (LFLD(u16, self, 0x42) == 0xffff) {
        o = (VObj *)func_0203dd9c(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb5a8;
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x4c) = o;
        LFLD(u32, o, 0xc) |= 0x4000000;
        LFLD(s32, LFLD(void *, self, 0x4c), 0x2c) = 1;
        {
            u8 *t = LFLD(u8 *, self, 0x4c);
            LFLD(s32, t, 0x58) = 0x100;
            LFLD(s32, t, 0x5c) = 0;
            LFLD(s32, t, 0x60) = 0;
        }
        LFLD(s32, LFLD(void *, self, 0x4c), 0x34) = 0x6000;
        {
            u8 *t = LFLD(u8 *, self, 0x4c);
            LFLD(s16, t, 0x64) = 0;
            LFLD(s16, t, 0x66) = 0x11;
            LFLD(s16, t, 0x68) = -0x1ccd;
        }
        LFLD(u32, LFLD(void *, self, 0x4c), 0xc) |= 0x20000000;
        LFLD(u32, LFLD(void *, self, 0x4c), 0xc) |= 0x80000000;
        LFLD(VObj *, self, 0x4c)->vfunc_f4(2, func_0204c0e8(g, 0x33));
        LFLD(VObj *, self, 0x4c)->vfunc_08();
    }
    o = (VObj *)func_0203dd9c(0xe4);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb4a8;
        o->vfunc_28();
        *(void **)o = data_ov000_021caac8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x50) = o;
    if (LFLD(u16, self, 0x42) == 0xffff) {
        LFLD(VObj *, self, 0x50)->vfunc_10(func_0204c0e8(g, 0x112));
        LFLD(VObj *, self, 0x50)->vfunc_14(func_0204c0e8(g, 0x113));
    }
    LFLD(void *, LFLD(void *, self, 0x50), 0x8) = self;
    LFLD(s32, LFLD(void *, self, 0x50), 0x20) = 3;
    {
        u8 *t = LFLD(u8 *, self, 0x50);
        LFLD(s16, t, 0x64) = 0;
        LFLD(s16, t, 0x66) = 0;
        LFLD(s16, t, 0x68) = -0x199a;
    }
    LFLD(u8, LFLD(void *, self, 0x50), 0xdc) = 0x20;
    LFLD(s32, LFLD(void *, self, 0x50), 0x34) = 0x6000;
    LFLD(void *, LFLD(void *, self, 0x50), 0x7c) = (void *)func_ov000_02151610;
    LFLD(void *, LFLD(void *, self, 0x50), 0x78) = (void *)func_ov000_0215158c;
    LFLD(VObj *, self, 0x50)->vfunc_a8(LFLD(s32, LFLD(void *, self, 0x50), 0x98));
    LFLD(VObj *, self, 0x50)->vfunc_08();
    {
        u8 *t = LFLD(u8 *, self, 0x50);
        LFLD(s16, t, 0x64) = 0;
        LFLD(s16, t, 0x66) = 0;
        LFLD(s16, t, 0x68) = -0x199a;
    }
    p = (u8 *)func_0203dd9c(0x38);
    if (p != NULL) {
        func_ov000_02153f90(p);
        LFLD(u16, p, 0x30) = 0;
        LFLD(u16, p, 0x32) = 0;
        LFLD(u16, p, 0x34) = 0;
        LFLD(u16, p, 0x36) = 0;
    }
    LFLD(u8 *, self, 0x54) = p;
    if (LFLD(u16, self, 0x42) != 0xffff) {
        LFLD(u16, p, 6) = LFLD(u16, self, 0x42);
    } else {
        LFLD(u16, LFLD(void *, self, 0x54), 6) = LFLD(u16, func_ov000_021824d0(data_ov000_021ccd54 + 0xac, 0), 0xc6);
    }
    {
        void *r = func_0204c08c(LFLD(void *, LFLD(void *, data_ov000_021ccd24, 8), 0xbc), LFLD(u16, LFLD(void *, self, 0x54), 6), out, 2);
        func_0204c6bc(out[0], r, LFLD(void *, self, 0x54), (void *)func_ov000_0214dc20);
    }

    LFLD(s32, self, 0x88) = 8;
    LFLD(s32, self, 0x84) = func_02061e7c(LFLD(u16, LFLD(void *, self, 0x54), 6));
    LoTextInit((u8 *)self + 0x60);
    LFLD(u16, self, 0xd4) = 0x7fff;
    LFLD(u16, self, 0xd6) = 0x67f;
    LFLD(s32, self, 0xd8) = 0x9000;
    LFLD(u32, self, 0x64) |= 0x40;
    LFLD(u32, self, 0x64) |= 0x1400000;
    LFLD(u32, self, 0x64) |= 0x40000004;
    func_0204ca70((u8 *)self + 0x60);

    LFLD(s32, self, 0x150) = 3;
    LFLD(s32, self, 0x140) = 8;
    LFLD(void *, self, 0x13c) = func_0204c0e8(LFLD(void *, LFLD(void *, data_ov000_021ccd24, 8), 0xbc), LFLD(u16, LFLD(void *, self, 0x54), 6));
    LoTextInit((u8 *)self + 0x118);
    LFLD(u32, self, 0x11c) |= 0x40;
    LFLD(u32, self, 0x11c) |= 0x1000000;
    LFLD(u32, self, 0x11c) |= 0x40000004;
    func_0204ca70((u8 *)self + 0x118);

    LFLD(s32, self, 0x1f8) = 8;
    LFLD(void *, self, 0x1f4) = func_0204c0e8(g, 0x115);
    LoTextInit((u8 *)self + 0x1d0);
    LFLD(u16, self, 0x244) = 0x7fff;
    LFLD(u16, self, 0x246) = 0x67f;
    LFLD(s32, self, 0x248) = 0x9000;
    LFLD(u32, self, 0x1d4) |= 0x40;
    LFLD(u32, self, 0x1d4) |= 0x1400000;
    LFLD(u32, self, 0x1d4) |= 0x40000004;
    func_0204ca70((u8 *)self + 0x1d0);

    if (LFLD(u16, LFLD(void *, self, 0x54), 0x32) != 0) {
        func_02040a98(buf, LFLD(u16, LFLD(void *, self, 0x54), 0x32));
        STD_ConcatenateString(buf, data_ov000_021ca93e);
        STD_ConcatenateString(buf, func_0204c0e8(g, 0x3e));
    } else {
        STD_CopyString(buf, out[1]);
    }
    LFLD(char *, self, 0x2ac) = buf;
    LFLD(s32, self, 0x2b0) = 8;
    LoTextInit((u8 *)self + 0x288);
    LFLD(u32, self, 0x28c) |= 0x40;
    LFLD(u32, self, 0x28c) |= 0x1000000;
    LFLD(u32, self, 0x28c) |= 0x4;
    func_0204ca70((u8 *)self + 0x288);

    LFLD(s32, self, 0x368) = 8;
    LFLD(void *, self, 0x364) = func_0204c0e8(g, 0x116);
    LoTextInit((u8 *)self + 0x340);
    LFLD(u16, self, 0x3b4) = 0x7fff;
    LFLD(u16, self, 0x3b6) = 0x67f;
    LFLD(s32, self, 0x3b8) = 0x9000;
    LFLD(u32, self, 0x344) |= 0x40;
    LFLD(u32, self, 0x344) |= 0x1400000;
    LFLD(u32, self, 0x344) |= 0x40000004;
    func_0204ca70((u8 *)self + 0x340);

    {
        u16 n = LFLD(u16, LFLD(void *, self, 0x54), 0x34);
        if (n == 0) {
            n = 1;
        }
        func_02040a98(buf, n);
    }
    LFLD(s32, self, 0x420) = 8;
    LFLD(char *, self, 0x41c) = buf;
    LoTextInit((u8 *)self + 0x3f8);
    LFLD(u32, self, 0x3fc) |= 0x40;
    LFLD(u32, self, 0x3fc) |= 0x1000000;
    LFLD(u32, self, 0x3fc) |= 0x40000004;
    func_0204ca70((u8 *)self + 0x3f8);
}

}
