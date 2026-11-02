#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern u8 data_ov000_021cac0c[];
extern u8 data_ov000_021cca88[];
extern u8 data_ov000_021cc998[];
extern u8 data_ov000_021cc99e[];
void func_ov000_0215fdfc(void *p, s32 i, void *d);
void func_ov000_0215fe1c(void *p, s32 v);

static inline void SetClamped(VObj *o, s32 v, s32 max) {
    if (v > max) {
        v = max;
    }
    func_ov000_0215fe1c(o, v);
}

void func_ov000_021c2d48(ListRowGauge *self) {
    if (self->built == 0) {
        ObjBase021cac0c_021cb6f0 *o = (ObjBase021cac0c_021cb6f0 *)Heap_Alloc(sizeof(ObjBase021cac0c_021cb6f0));
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac0c);
            o->vfunc_14();
            VOBJ_SET_VTABLE(o, data_ov000_021cca88);
        }
        self->bar = o;
        o->unk_28 = 2;
        self->bar->unk_58 = 3;
        self->bar->unk_50 = 0x4a;
        self->bar->unk_54 = 6;
        func_ov000_0215fdfc(self->bar, 0, data_ov000_021cc998);
        func_ov000_0215fdfc(self->bar, 1, data_ov000_021cc99e);
        func_ov000_0215fdfc(self->bar, 2, data_ov000_021cc998 + ((self->value * 3) / self->max + 2) * 6);
        self->bar->unk_98 = 0x1f;
        SetClamped(self->bar, self->value, self->max);
        self->bar->unk_0c |= 8;
        self->built = 1;
    } else {
        self->bar->vfunc_0c();
    }
}
}
