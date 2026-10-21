#include "ov000/LoCommon.h"

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
