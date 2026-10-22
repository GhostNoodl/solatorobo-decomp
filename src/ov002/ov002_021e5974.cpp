#include "ov002/ov002.h"

extern "C" {

// p is an unused register parameter used as the loop pointer (locals-as-parameters lever).
BOOL func_ov002_021e5974(void *self, u8 *p) {
    s32 kind;
    NNS_G3dRenderObjInit((u8 *)self + 0x68, FIELD(self, 0x60, void *));
    FIELD(self, 0x64, void *) = NNS_G3dGetTex(*FIELD(self, 0x5c, void **));
    kind = FIELD(self, 0x1f0, Bits8).b0 ? 8 : 7;
    for (p = FIELD(data_ov002_021f0f98[1], 0xdc, u8 *); p != NULL; p = FIELD(p, 0x24, u8 *)) {
        if (kind == FIELD(p, 0x4, s32)) {
            s32 st = FIELD(p, 0x8, s32);
            switch (st) {
            case 1:
                FIELD(self, 0x1e0, u8 *) = p;
                break;
            case 2:
                FIELD(self, 0x1e4, u8 *) = p;
                break;
            default:
                FIELD(self, 0x1e0, u8 *) = p;
                break;
            }
            FIELD(p, 0x8, s32) = st;
        }
    }
    return TRUE;
}

}
