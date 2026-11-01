#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);

void func_ov000_021682fc(Lo021cb6f0 *self) {
    s32 s = self->unk_04;
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            self->unk_04 = 2;
        }
    }
    if (self->unk_04 != 0xa) {
        return;
    }
    if (!((self->unk_0c & 0x10000) ? TRUE : FALSE)) {
        LBIT(self, 0xc).b1 = 1;
    }
    LBIT(self, 0xc).b16 = 0;
}

}
