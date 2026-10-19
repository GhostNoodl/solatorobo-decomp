#include "ov000/LoCommon.h"

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
