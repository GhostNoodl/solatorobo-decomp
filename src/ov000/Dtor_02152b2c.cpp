#include "ov000/VObj.h"
#include "nitro/fx.h"

#define LFLD_U32(o, off) (*(u32 *)((u8 *)(o) + (off)))
#define LFLD_S32(o, off) (*(s32 *)((u8 *)(o) + (off)))
#define LFLD_S16(o, off) (*(s16 *)((u8 *)(o) + (off)))
#define LFLD_FN(o, off) (*(Filter02152bb0 *)((u8 *)(o) + (off)))
#define LFLD_OBJ(o, off) (*(VObj **)((u8 *)(o) + (off)))

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
void func_0203de1c(void *ptr);
extern u8 *data_02097d48;
void func_02043d20(void *p, s32 a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

typedef BOOL (*Filter02152bb0)(VObj *self, s32 id, VecFx32 *pos, s32 extra);

VObj *func_ov000_02152b2c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

void func_ov000_02152bb0(VObj *self) {
    s32 extra;
    VecFx32 pos;
    VecFx32 scale;
    VecFx32 ofs;
    BOOL draw = TRUE;
    s32 id;
    u8 *gfx = data_02097d48;
    LFLD_U32(self, 0xc) &= ~0x200;
    func_02043d20(gfx + 0x8b0, 0);
    scale.x = 0x1000;
    scale.y = 0x1000;
    scale.z = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
    id = self->vfunc_18(&pos, &extra, LFLD_S32(self, 0x38));
    ofs.x = LFLD_S16(self, 0x64) << 12;
    ofs.y = LFLD_S16(self, 0x66) << 12;
    ofs.z = 0;
    VecAdd(&pos, &ofs, &pos);
    if (LFLD_FN(self, 0x7c) != NULL) {
        draw = LFLD_FN(self, 0x7c)(self, id, &pos, extra);
    }
    if (draw) {
        self->vfunc_5c(id, &pos, extra);
    }
    if (LFLD_OBJ(self, 0x74) != NULL) {
        LFLD_OBJ(self, 0x74)->vfunc_20();
    }
}

}
