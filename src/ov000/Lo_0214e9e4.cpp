#include "ov000/LoCommon.h"

extern "C" {
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern u8 data_02fe1534[];
extern void *volatile data_02fe152c;
extern u8 data_ov000_021ccd24[];
extern void *data_ov000_021ca8d8[];
extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
extern void *data_0208cca0;
extern void *data_0208cb74;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021ca94c[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021caac8[];
void *func_0204c0e8(void *g, u32 id);
BOOL func_0205aa30(void *p);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *STD_CopyString(void *dst, void *src);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c20(void *model, s32 a, void *b);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_ov000_02157c90(void *self, void *a);
void func_ov000_021546ec(void *a, void *b, void *c, u16 d);
void *func_ov000_02173610(s32 kind);
u32 func_0205975c(void *a, s32 b);
u16 func_ov000_0214bcc4(u16 id, u16 index);
s32 func_02061e7c(u16 a);
void func_ov000_0214fcfc(void *self, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, const void *mtx);
BOOL func_ov000_0214ffac(void *self, void *msg);
BOOL func_ov000_02150104(void *self, void *p);

static inline void Setup0214e9e4(VObj *self) {
    VObj *t;
    void *g;
    u32 n;
    u16 k;
    void *name;
    u8 *p;
    void *arc;
    u8 *m;
    VObj *o;
    void *s;
    u16 i;
    u16 id;
    g = data_02149ef8;
    if (!LFLD(VObj *, data_ov000_021ccd24, 8)->vfunc_34()) {
        func_0205aa30(LFLD(void *, data_ov000_021ccd24, 8));
    }
    {
        u8 *d = data_02fe1534;
        u16 v = LFLD(u8, data_0214a424, 0x639);
        LFLD(u16, d, 0x70) = 1;
        LFLD(vu16, d, 0x7a) = v;
        LFLD(VObj *volatile, data_ov000_021ccd24, 8)->vfunc_38(1);
        LFLD(u16, d, 0x7a) = 0;
    }
    m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        name = data_ov000_021ca8d8[1];
        arc = data_ov000_021ca8d8[0];
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString(m + 0x2c, arc);
    }
    LFLD(u8 *, self, 0x40) = m;
    func_020417e0(LFLD(void *, self, 0x40), func_02034d88((void *)LFLD(VObj *, self, 0x3c)->vfunc_10(), LFLD(u8 *, self, 0x40) + 0x4c));
    LFLD(u32, LFLD(void *, self, 0x40), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, self, 0x40), 0, 1);
    LFLD(void *, LFLD(void *, self, 0x40), 0x158) = (void *)func_ov000_0214fcfc;
    func_02041c20(LFLD(void *, self, 0x40), 1, self);
    LFLD(u32, LFLD(void *, self, 0x40), 0x6c) |= 0x80000;
    LFLD(u32, LFLD(void *, self, 0x40), 0x6c) |= 0x200000;
    LFLD(s32, LFLD(void *, self, 0x40), 0x150) = -0x1ccd;
    s = func_0204c0e8(g, 0x114);
    p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    LFLD(s32, p, 0x28) = 8;
    LFLD(void *, p, 0x24) = s;
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), p + 0x44, p + 0x48, LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(s32, p, 0x2c) = 0;
    LFLD(u16, p, 0x74) = 0x77df;
    LFLD(u16, p, 0x76) = 0x67e;
    LFLD(u32, p, 0x4) |= 0x40;
    LFLD(u32, p, 0x4) |= 0x1400000;
    ((VObj *)p)->vfunc_14();
    LFLD(s32, p, 0x78) = 0x9000;
    LFLD(s32, p, 0x70) = -0x1ccd;
    LFLD(u32, p, 0x4) |= 0x40000004;
    LFLD(u8 *, self, 0x44) = p;
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
    LFLD(s32, LFLD(void *, self, 0x4c), 0x34) = 0xc000;
    {
        u8 *t = LFLD(u8 *, self, 0x4c);
        LFLD(s16, t, 0x64) = 0;
        LFLD(s16, t, 0x66) = 0x66;
        LFLD(s16, t, 0x68) = -0x1ccd;
    }
    LFLD(u32, LFLD(void *, self, 0x4c), 0xc) |= 0x20000000;
    LFLD(VObj *, self, 0x4c)->vfunc_f4(1, func_0204c0e8(g, 0x37));
    LFLD(VObj *, self, 0x4c)->vfunc_f4(2, func_0204c0e8(g, 0x33));
    LFLD(VObj *, self, 0x4c)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x21c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021ca94c;
        VOBJ_SET_VTABLE((u8 *)o + 0x90, data_0208ba70);
        func_0204c7d0((u8 *)o + 0x90);
        VOBJ_SET_VTABLE((u8 *)o + 0x148, data_0208ba70);
        func_0204c7d0((u8 *)o + 0x148);
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x60) = o;
    o->vfunc_08();
    LFLD(s16, LFLD(void *, self, 0x60), 0x68) = -0x1bcd;
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
    LFLD(VObj *, self, 0x50)->vfunc_10(func_0204c0e8(g, 0x10f));
    LFLD(VObj *, self, 0x50)->vfunc_14(func_0204c0e8(g, 0x110));
    func_ov000_02157c90(LFLD(void *, self, 0x50), func_0204c0e8(g, 0x111));
    func_ov000_021546ec(LFLD(void *, self, 0x50), data_0208cca0, data_0208cb74, 0xb);
    LFLD(void *, LFLD(void *, self, 0x50), 0x8) = self;
    LFLD(s32, LFLD(void *, self, 0x50), 0x20) = 4;
    {
        u8 *t = LFLD(u8 *, self, 0x50);
        LFLD(s16, t, 0x64) = 0;
        LFLD(s16, t, 0x66) = 0x18;
        LFLD(s16, t, 0x68) = -0x1ccd;
    }
    LFLD(u8, LFLD(void *, self, 0x50), 0xc0) = 0x94;
    LFLD(s32, LFLD(void *, self, 0x50), 0x34) = 0xc000;
    LFLD(u32, LFLD(void *, self, 0x50), 0xc) |= 0x400000;
    LFLD(u8, LFLD(void *, self, 0x50), 0xc1) = 2;
    LFLD(void *, LFLD(void *, self, 0x50), 0x84) = (void *)func_ov000_0214ffac;
    LFLD(void *, LFLD(void *, self, 0x50), 0x88) = (void *)func_ov000_02150104;
    id = LFLD(s32, self, 0xc);
    {
        u8 *d = data_02fe1534;
        LFLD(u16, d, 0x70) = 0;
        LFLD(vu16, d, 0x7a) = id;
        LFLD(VObj *volatile, data_ov000_021ccd24, 8)->vfunc_38(1);
        LFLD(vu16, d, 0x7a) = 0;
    }
    n = func_0205975c(data_02fe152c, 1);
    for (i = 0; i < n; i++) {
        k = func_ov000_0214bcc4(id, i);
        if (k != 0xffff) {
            t = LFLD(VObj *, func_ov000_02173610(0xe), 0x50);
            t->vfunc_74(func_02061e7c(k), k, 0xffff, 0xffff);
        }
    }
    LFLD(s16, self, 0x64) = LFLD(u16, data_02fe1534, 0x68);
    LFLD(VObj *, self, 0x50)->vfunc_a8(LFLD(s32, LFLD(void *, self, 0x50), 0x98));
    LFLD(VObj *, self, 0x50)->vfunc_08();
    {
        u8 *t = LFLD(u8 *, self, 0x50);
        LFLD(s32, t, 0x58) = 0x100;
        LFLD(s32, t, 0x5c) = 0;
        LFLD(s32, t, 0x60) = 0;
    }
}

void func_ov000_0214e9e4(VObj *self) {
    LFLD(u32, self, 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
    Setup0214e9e4(self);
}

}
