#include "ov000/VObj.h"

extern "C" {
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021ca9c4[];
extern u8 data_0208ba70[];
void *func_0203dd9c(u32 size);
void func_0204c7d0(void *p);

#define SUB(o, off) VOBJ_SET_VTABLE((u8 *)(o) + (off), data_0208ba70); func_0204c7d0((u8 *)(o) + (off))

VObj *func_ov000_0215012c(void) {
    VObj *o = (VObj *)func_0203dd9c(0x4b0);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_ov000_021cc060);
        o->vfunc_58();
        VOBJ_SET_VTABLE(o, data_ov000_021ca9c4);
        SUB(o, 0x60);
        SUB(o, 0x118);
        SUB(o, 0x1d0);
        SUB(o, 0x288);
        SUB(o, 0x340);
        SUB(o, 0x3f8);
        o->vfunc_58();
    }
    o->vfunc_08(0xf, 0xb4);
    return o;
}

}
