#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void Ov002_ProjectToScreen(s32 *out, s32 *v, void *m);

static inline void setPos(Obj021efe5c *self, s32 x, s32 y) {
    self->model.x = x << 12;
    self->model.unk_150 = self->pos.z;
    self->model.y = y << 12;
}

void Obj021efe5c_Draw(Obj021efe5c *self) {
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    s32 v[3];
    u8 m[0x40];
    s32 out[2];
    if (self->unk_1d4 == 0) {
        x = self->pos.x;
        y = self->pos.y;
        z = self->pos.z;
        s = 0x800;
    } else {
        x = self->pos.x + 0x147;
        y = self->pos.y;
        z = self->pos.z;
        s = 0x1000;
    }
    self->mdl.scale.x = s;
    self->mdl.scale.y = s;
    self->mdl.scale.z = s;
    self->mdl.trans.x = x;
    self->mdl.trans.y = y;
    self->mdl.trans.z = z;
    if (self->mdl.renderObj != NULL && Vram_IsTransferDone(self->mdl.texTask)) {
        NNS_G3dGlbSetBaseTrans(&self->mdl.trans);
        NNS_G3dGlbSetBaseScale(&self->mdl.scale);
        MI_Copy36B(&self->mdl.rot, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw(self->mdl.renderObj);
        NNS_G3dGeFlushBuffer();
    }
    if (self->unk_1d4 != 0) {
        return;
    }
    v[1] = y + 0x40;
    v[0] = x;
    v[2] = z;
    {
        u32 t = self->unk_1d8;
        t %= 30;
        v[0] = x - ((t / 5) * 0xda / 6 + 0xda);
    }
    MTX_Copy43To44_((MtxFx43 *)data_02092844, (MtxFx44 *)m);
    MTX_Concat44((MtxFx44 *)m, (MtxFx44 *)data_02092800, (MtxFx44 *)m);
    Ov002_ProjectToScreen(out, v, m);
    setPos(self, out[0], out[1]);
    Model_PlayPartF(&self->model, 4, 1);
}

}
