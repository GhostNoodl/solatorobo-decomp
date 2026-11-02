#include "ov000/LoCommon.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


extern "C" {

u8 Gfx3DState_NextPolyId(void *p);
void func_ov000_0214d304(VObj *self, s32 a, s32 *pos, s32 d);
void func_ov000_0214d994(VObj *self);

struct Obj0214cb44 : public VObj {
    u8 unk_04[0x20];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0xc];
    void *unk_38;
    u8 unk_3c[0x2c];
    s16 unk_68;
    u8 unk_6a[0x1a];
    Model *unk_84;
    u8 unk_88[0x4];
    VObj *unk_8c;
    VObj unk_90;
    u8 unk_94[0x40];
    s32 unk_d4;
    u8 unk_d8[0x28];
    s32 unk_100;
    u8 unk_104[0xfc];
    VObj *unk_200;
};

void func_ov000_0214cb44(Obj0214cb44 *self, s32 a, s32 *pos, s32 d) {
    if (self->unk_38 != NULL) {
        s16 z;
        s32 x;
        s32 y;
        self->vfunc_64(a, pos, d);
        func_ov000_0214d304(self, a, pos, d);
        z = self->unk_68 - 0x110;
        x = (pos[0] + ((self->unk_24 - 0x80) + ((0x100 - self->unk_24) >> 1))) << 12;
        y = pos[1] + (((self->unk_28 >> 1) - 0x60) << 12);
        MODEL_FLAGS(self->unk_84)->polygon_id = Gfx3DState_NextPolyId(data_02097d48->unk_8b0);
        {
            u8 *o = (u8 *)self->unk_84;
            LFLD(s32, o, 0xfc) = x;
            LFLD(s32, o, 0x100) = y;
        }
        self->unk_84->unk_150 = z;
        Model_PlayPart(self->unk_84, 0);
        {
            s32 py = pos[1];
            s32 px = pos[0];
            self->unk_100 = self->unk_68;
            self->unk_90.vfunc_20(((self->unk_24 - self->unk_d4) >> 1) + (px >> 12),
                                            (py >> 12) + 2);
        }
        self->unk_90.vfunc_90();
    }
    if (self->unk_200 != NULL) {
        func_ov000_0214d994(self);
        self->unk_200->vfunc_90();
    }
    if (self->unk_8c != NULL) {
        self->unk_8c->vfunc_20();
    }
}

}
