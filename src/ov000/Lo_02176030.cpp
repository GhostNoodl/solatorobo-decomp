#include "ov000/LoCommon.h"

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

void func_ov000_02176030(void *self) {
    BOOL a = FALSE;
    BOOL b = a;
    if (LFLD(VObj *, self, 0x3c) != NULL) {
        if (!LFLD(VObj *, self, 0x3c)->vfunc_1c()) {
            LO_FREE_V(self, 0x3c);
        } else {
            a = TRUE;
        }
    }
    if (LFLD(VObj *, self, 0x40) != NULL) {
        if (!LFLD(VObj *, self, 0x40)->vfunc_1c()) {
            u32 saved;
            LO_HEAP_PUSH(saved);
            if (LFLD(VObj *, self, 0x40) != NULL) {
                VObj *p = LFLD(VObj *, self, 0x40);
                if (p != NULL) {
                    p->vfunc_04();
                }
                LFLD(VObj *, self, 0x40) = NULL;
            }
            b = TRUE;
            LO_HEAP_POP(saved);
        } else {
            a = TRUE;
        }
    }
    if (LBIT(self, 4).b2) {
        return;
    }
    if (a) {
        LFLD(LoCbFn, self, 0x30)(self, 3);
    }
    if (b) {
        LFLD(LoCbFn, self, 0x30)(self, 1);
    }
}

void func_ov000_02176164(void *self) {
    if (LFLD(VObj *, self, 0x3c) != NULL) {
        LFLD(VObj *, self, 0x3c)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x40) != NULL) {
        LFLD(VObj *, self, 0x40)->vfunc_20();
    }
}

VObj *func_ov000_021761a0(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b614);
        obj->vfunc_14();
        VOBJ_SET_VTABLE(obj, data_0208ca9c);
        obj->vfunc_14();
    }
    return obj;
}

}
