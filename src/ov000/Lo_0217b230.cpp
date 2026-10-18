#include "ov000/VObj.h"

class Obj0217b230 : public VObj {
public:
    u32 b0 : 2;
    u32 b2 : 1;
    u32 b3 : 3;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 5;
    u32 b13 : 9;
    u32 b22 : 1;
    u32 b23 : 1;
    u32 b24 : 1;
    u32 b25 : 7;
    u8 pad_08[0x1c];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0xa];
    u8 unk_36;
    s8 unk_37;
    s32 unk_38;
    u8 pad_3c[8];
    u8 unk_44[4];
    u8 unk_48[4];
    s32 unk_4c;
    u8 pad_50[0x20];
    s32 unk_70;
    s16 unk_74;
    s16 unk_76;
    s32 unk_78;
};

typedef struct {
    s32 unk_00;
    s32 unk_04;
} Data02097ce0;

extern "C" {
extern u8 data_0208ba70[];
extern Data02097ce0 *data_02097ce0;
void *func_0203dd9c(u32 size);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void func_0204ca70(void *p);

Obj0217b230 *func_ov000_0217b230(void *unused, s32 a1, s32 a2) {
    Obj0217b230 *o = (Obj0217b230 *)func_0203dd9c(0xb8);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208ba70);
        func_0204c7d0(o);
    }
    o->unk_37 = 1;
    o->unk_28 = a2;
    o->unk_24 = a1;
    o->unk_4c = func_0204c4fc(o->unk_28, o->unk_38, o->unk_24, o->unk_44, o->unk_48, o->unk_37 ? 1 : 0);
    data_02097ce0->unk_04 = o->unk_28;
    o->unk_70 = -0x1c8d;
    o->b8 = 0x1e;
    o->unk_74 = 0x7fff;
    o->unk_76 = 0x2adf;
    o->unk_78 = 0x8000;
    o->unk_36 = 1;
    o->b6 = 1;
    o->b22 = 1;
    o->b24 = 1;
    o->vfunc_14();
    o->b2 = 1;
    func_0204ca70(o);
    return o;
}

}
