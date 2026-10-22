#define func_ov000_0217ea30 func_ov000_0217ea30_hdr
#include "ov000/LoCommon.h"

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

#undef func_ov000_0217ea30
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
