#include "ov000/LoCommon.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 rest : 25;
} LoF2;

extern "C" {

void func_ov000_0215a8c8(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);

void UiObj_Release(VObj *self) {
    self->vfunc_48(1, 0);
    LO_FREE_M(self, 0x10);
    LO_FREE_V(self, 0x14);
    LO_FREE_V(self, 0x18);
}

}
