#include "ov000/LoCommon.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


typedef struct {
    u16 id;
    u8 pad_02[0x16];
} Entry0215f334;

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Flags0215f334;

typedef struct {
    Flags0215f334 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 pad_1c[8];
    VObj *unk_24;
    Model *unk_28;
} Win0215f334;

extern "C" {

extern Entry0215f334 data_02fe0188[];
BOOL func_02054f10(void *model, u32 id);
void func_ov000_0215f970(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx0);
void func_ov000_0215f618(Win0215f334 *self, s32 *pos);

void func_ov000_0215f334(Win0215f334 *self) {
    s32 pos[3];
    VObj *t;
    Entry0215f334 *e;

    if (!func_02054f10(self->unk_28, 0xffff)) {
        return;
    }
    e = &data_02fe0188[self->unk_04];
    pos[0] = self->unk_08;
    pos[1] = self->unk_0c;
    pos[2] = self->unk_10;
    if (self->unk_00.b0) {
        pos[0] -= self->unk_14 >> 1;
    }
    self->unk_28->unk_158 = (void *)func_ov000_0215f970;
    self->unk_28->flags |= 0x80000;
    self->unk_28->flags |= 0x200000;
    MODEL_FLAGS(self->unk_28)->alpha = 0x1e;
    {
        s32 px = pos[0];
        s32 py = pos[1];
        u8 *o = (u8 *)self->unk_28;
        LFLD(s32, o, 0xfc) = px << 12;
        LFLD(s32, o, 0x100) = py << 12;
    }
    self->unk_28->unk_150 = pos[2] - 0x40;
    Model_PlayPart(self->unk_28, e->id);
    self->unk_28->unk_158 = NULL;
    pos[2] -= 0x80;
    func_ov000_0215f618(self, pos);
    t = self->unk_24;
    pos[0] += (self->unk_14 - LFLD(s32, t, 0x44)) >> 1;
    pos[1] += (self->unk_18 - LFLD(s32, t, 0x48)) >> 1;
    LFLD(s32, t, 0x70) = self->unk_10;
    self->unk_24->vfunc_20(pos[0] - 1, pos[1] - 1);
    self->unk_24->vfunc_90();
}

}
