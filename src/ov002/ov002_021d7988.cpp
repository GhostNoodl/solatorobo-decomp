#include "ov002/ov002.h"

extern "C" {

void MTX_Copy43To44_(void *src, void *dst);
void MTX_Concat44(void *a, void *b, void *ab);
void func_ov002_021e3b6c(s32 *out, s32 *v, void *m);

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx, int flag) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, flag);
}

static inline void setPos(u8 *self, s32 x, s32 y) {
    FIELD(self, 0x170, s32) = x << 12;
    FIELD(self, 0x1c4, s32) = FIELD(self, 0x1e4, s32);
    FIELD(self, 0x174, s32) = y << 12;
}

void func_ov002_021d7988(void *selfp) {
    u8 *self = (u8 *)selfp;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    s32 v[3];
    u8 m[0x40];
    s32 out[2];
    if (FIELD(self, 0x1d4, u8) == 0) {
        x = FIELD(self, 0x1dc, s32);
        y = FIELD(self, 0x1e0, s32);
        z = FIELD(self, 0x1e4, s32);
        s = 0x800;
    } else {
        x = FIELD(self, 0x1dc, s32) + 0x147;
        y = FIELD(self, 0x1e0, s32);
        z = FIELD(self, 0x1e4, s32);
        s = 0x1000;
    }
    FIELD(self, 0x44, s32) = s;
    FIELD(self, 0x48, s32) = s;
    FIELD(self, 0x4c, s32) = s;
    FIELD(self, 0x38, s32) = x;
    FIELD(self, 0x3c, s32) = y;
    FIELD(self, 0x40, s32) = z;
    if (FIELD(self, 0x1c, void *) != NULL && func_0203e63c(FIELD(self, 0x20, void *))) {
        NNS_G3dGlbSetBaseTrans(self + 0x38);
        NNS_G3dGlbSetBaseScale(self + 0x44);
        MI_Copy36B(self + 0x50, data_020928b4);
        NNS_G3dGlb.fc &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw(FIELD(self, 0x1c, void *));
        NNS_G3dGeFlushBuffer();
    }
    if (FIELD(self, 0x1d4, u8) != 0) {
        return;
    }
    v[1] = y + 0x40;
    v[0] = x;
    v[2] = z;
    {
        u32 t = FIELD(self, 0x1d8, u32);
        t %= 30;
        v[0] = x - ((t / 5) * 0xda / 6 + 0xda);
    }
    MTX_Copy43To44_(data_02092844, m);
    MTX_Concat44(m, data_02092800, m);
    func_ov002_021e3b6c(out, v, m);
    setPos(self, out[0], out[1]);
    ov002_Model_PlayPart(self + 0x74, 4, 1);
}

}
