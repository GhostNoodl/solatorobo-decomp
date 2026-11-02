#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"



extern "C" {

extern u8 data_02fe1534[];
u8 Gfx3DState_NextPolyId(void *p);
void func_02041774(void *a, int b);
void func_02041c20(void *a, int b, int c);

static inline void LoSetPos(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

struct Obj0214d304 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    Model *unk_10;
    u8 unk_14[0x54];
    s16 unk_68;
    u8 unk_6a[0x1e];
    Model *unk_88;
    u8 unk_8c[0xbc];
    VObj unk_148;
    u8 unk_14c[0x40];
    s32 unk_18c;
    u8 unk_190[0x28];
    s32 unk_1b8;
    u8 unk_1bc[0x4c];
    u16 unk_208;
    u8 unk_20a[0x6];
    s32 unk_210;
    u8 unk_214[0x4];
    s32 unk_218;
};

void func_ov000_0214d304(Obj0214d304 *self, s32 a, s32 *pos, s32 d) {
    s32 i;
    s32 y;
    s32 s;
    GfxSys *g;
    s32 x;
    s32 py;
    s16 z;
    g = data_02097d48;
    z = self->unk_68 - 0x110;
    x = (pos[0] >> 12) - 0x80;
    y = (pos[1] >> 12) - 0x51;
    MODEL_FLAGS(self->unk_10)->unk_19 = 1;
    MODEL_FLAGS(self->unk_10)->alpha = 0x1e;
    MODEL_FLAGS(self->unk_10)->unk_20 = 1;
    MODEL_FLAGS(self->unk_10)->unk_21 = 1;
    MODEL_FLAGS(self->unk_10)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
    LoSetPos(self->unk_10, x << 12, y << 12);
    self->unk_10->unk_150 = z;
    Model_PlayPart(self->unk_10, 0xe);
    func_02041774(self->unk_10, 0xffff);
    self->unk_1b8 = self->unk_68;
    self->unk_148.vfunc_20(x + 0xb2 - (self->unk_18c >> 1), y + 0x62);
    self->unk_148.vfunc_90();
    MODEL_FLAGS(self->unk_10)->polygon_id = g->unk_8b0[1];
    LoSetPos(self->unk_10, (x + 0x74) << 12, (y + 8) << 12);
    self->unk_10->unk_150 = self->unk_68;
    Model_PlayPart(self->unk_10, 0xb);
    MODEL_FLAGS(self->unk_88)->unk_19 = 1;
    MODEL_FLAGS(self->unk_88)->alpha = 0x1e;
    LoSetPos(self->unk_88, (x + 0x7e) << 12, (y + 3) << 12);
    self->unk_88->unk_150 = self->unk_68;
    func_02041c20(self->unk_88, 6, LFLD(u16, data_02fe1534, 0x58));
    s = self->unk_218;
    if (s != 0) {
        {
            Model *m = self->unk_88;
            m->unk_144 = 0x800;
            m->unk_148 = 0x400;
            m->unk_14c = 0x800;
        }
        MTX_Identity22_(&self->unk_88->mtx[0]);
        MTX_ScaleApply22(&self->unk_88->mtx[0], &self->unk_88->mtx[0], s + 0x1000, s + 0x1000);
        Model_PlayPartF(self->unk_88, 6, 1);
    } else {
        Model_PlayPart(self->unk_88, 6);
    }
    self->unk_10->unk_150 = self->unk_68;
    py = (y + 0x14) << 12;
    y = x + 0x10;
    for (i = 0; i < 10; i++) {
        y += 0xb;
        LoSetPos(self->unk_10, y << 12, py);
        if (self->unk_0c & 0x10000) {
            if (i > self->unk_208) {
            } else if (i == self->unk_208) {
                u8 al = LO_FX_MUL(self->unk_210, 0x1f000) >> 12;
                if (al != 0) {
                    MODEL_FLAGS(self->unk_10)->unk_19 = 1;
                    MODEL_FLAGS(self->unk_10)->alpha = al;
                    MODEL_FLAGS(self->unk_10)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
                    self->unk_10->unk_150 = self->unk_68;
                    Model_PlayPart(self->unk_10, 0xd);
                    func_02041774(self->unk_10, 0xffff);
                }
            } else {
                self->unk_10->unk_150 = self->unk_68;
                Model_PlayPart(self->unk_10, 0xd);
            }
        } else if (i + 1 <= self->unk_208) {
            self->unk_10->unk_150 = self->unk_68;
            Model_PlayPart(self->unk_10, 0xd);
        }
        self->unk_10->unk_150 = self->unk_68 - 0x20;
        Model_PlayPart(self->unk_10, 0xc);
    }
}

}
