#include "ov000/VObj.h"
#include "nitro/std.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern u8 data_ov000_021ccd24[];
extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern char data_ov000_021ca8f7[];
extern char data_ov000_021ca8ff[];
extern char data_ov000_021ca917[];
extern void *data_ov000_021ca8d8;
void *func_0203dd9c(u32 size);
void func_020708fc(s32 a, void *out);
void func_02070b98(s32 a, void *out, s32 b, s32 c);
void func_020359fc(void *a, void *b, s32 c, s32 d);
void func_0205a6a0(void *res);
void func_0205a840(void *res, char *name, char *path);

void func_ov000_0214e7f0(u8 *self) {
    u8 b[0x10];
    u8 a[0x10];
    char name[0x20];
    VObj *o;

    func_020708fc(0x1000, a);
    func_02070b98(0x1000, b, 1, 2);
    func_020359fc(a, b, 2, 0);
    data_ov000_021ccd24[0] = 1;
    o = (VObj *)func_0203dd9c(0xc4);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208b318);
        o->vfunc_08();
        VOBJ_SET_VTABLE(o, data_0208bf54);
        func_0205a6a0(o);
    }
    LFLD(VObj *, data_ov000_021ccd24, 8) = o;
    STD_CopyString(name, data_ov000_021ca8f7);
    STD_ConcatenateString(name, data_ov000_021ca8ff);
    func_0205a840(LFLD(VObj *, data_ov000_021ccd24, 8), name, data_ov000_021ca917);
    o = (VObj *)func_0203dd9c(0x4c);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208b318);
        o->vfunc_08();
    }
    LFLD(VObj *, self, 0x3c) = o;
    LFLD(s32, o, 0x44) = 7;
    LFLD(VObj *, self, 0x3c)->vfunc_1c(data_ov000_021ca8d8);
}
}
