#include "ov000/LoCommon.h"

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
