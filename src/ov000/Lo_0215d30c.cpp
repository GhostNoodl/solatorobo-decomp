#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 data_02fe1534[];
void func_0206281c(void);
u32 func_0204045c(void);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

void func_ov000_0215d30c(Lo021cad50 *self) {
    VObj *o;
    if (self->state != 2) {
        return;
    }
    self->openTime = self->openLen;
    self->openRatio = 0x1000;
    o = self->unk_98[0];
    if (o) {
        if (!(self->flags & 0x10000)) {
            LFLD(u32, o, 4) |= 0x4000000;
        }
        self->unk_98[0]->vfunc_8c();
        if (!LBIT(self, 0xc).b1) {
            if (self->unk_98[0]->vfunc_10() || (self->flags & 0x40000)) {
                LBIT(self, 0xc).b1 = 1;
            }
        }
    }
    if (LBIT(self, 0xc).b1 == 1) {
        self->state = 1;
    }
}

}
