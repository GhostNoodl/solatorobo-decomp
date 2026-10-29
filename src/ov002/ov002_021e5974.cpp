#include "ov002/ov002.h"

extern "C" {

// Kinds of the scene objects in the `+0xdc` list (the `+0x4` word). 7 is the camera
// (func_ov002_021e7390 reads its position, target, up vector and angle).
typedef enum Ov002ObjKind {
    OV002_OBJ_CAMERA = 7,
    OV002_OBJ_CAMERA2 = 8
} Ov002ObjKind;

BOOL func_ov002_021e5974(void *self) {
    Ov002ObjKind kind;
    u8 *p;
    NNS_G3dRenderObjInit((u8 *)self + 0x68, FIELD(self, 0x60, void *));
    FIELD(self, 0x64, void *) = NNS_G3dGetTex(*FIELD(self, 0x5c, void **));
    if (FIELD(self, 0x1f0, Bits8).b0) {
        kind = OV002_OBJ_CAMERA2;
    } else {
        kind = OV002_OBJ_CAMERA;
    }
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
