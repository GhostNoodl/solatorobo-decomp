#include "ov000/LoCommon.h"
#include "nitro/fx.h"

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
