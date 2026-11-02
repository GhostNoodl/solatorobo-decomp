#include "ov000/VObj.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/UiObj.h"

extern "C" {
static inline void VecAdd(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab) {
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
void Heap_Free(void *ptr);
void func_02043d20(void *p, s32 a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

VObj *Ov000Vt_021cb0b8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

void UiObj_Draw(UiObj *self) {
    s32 extra;
    VecFx32 pos;
    VecFx32 scale;
    VecFx32 ofs;
    BOOL draw = TRUE;
    s32 id;
    GfxSys *gfx = data_02097d48;
    self->flags &= ~0x200;
    func_02043d20(gfx->unk_8b0, 0);
    scale.x = 0x1000;
    scale.y = 0x1000;
    scale.z = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
    id = self->vfunc_18(&pos, &extra, self->openRatio);
    ofs.x = self->posX << 12;
    ofs.y = self->posY << 12;
    ofs.z = 0;
    VecAdd(&pos, &ofs, &pos);
    if (self->onDraw != NULL) {
        draw = self->onDraw(self, id, &pos, extra);
    }
    if (draw) {
        self->vfunc_5c(id, &pos, extra);
    }
    if (self->child != NULL) {
        self->child->vfunc_20();
    }
}

}
