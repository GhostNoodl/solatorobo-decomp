#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 data_02fe1534[];
void func_0206281c(void);
u32 func_0204045c(void);
void func_ov000_0215f0ec(void *p, void *q);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

void func_ov000_0216881c(Lo021cb894 *self) {
    s32 s = self->unk_04;
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            self->unk_04 = 2;
        }
    }
    switch (self->unk_04) {
    case 8:
        self->unk_b8 = -8;
        break;
    case 0xa:
        if (!((self->unk_0c & 0x10000) ? TRUE : FALSE)) {
            LBIT(self, 0xc).b1 = 1;
        }
        if (--self->unk_b8 < -8) {
            self->unk_b8 = 4;
        }
        LBIT(self, 0xc).b16 = 0;
        break;
    }
}

}
