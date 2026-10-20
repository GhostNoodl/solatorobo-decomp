#include "types.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

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
