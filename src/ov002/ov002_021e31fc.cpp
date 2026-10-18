#include "ov002/ov002.h"

extern "C" {

typedef struct Bits021e31fc {
    u8 b0 : 1;
    u8 rest : 7;
} Bits021e31fc;

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
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
    func_02042628(model, anim, part, 0);
}

static inline void ov002_Model_SetPos(void *m, s32 x, s32 y) {
    FIELD(m, 0xfc, s32) = x;
    FIELD(m, 0x100, s32) = y;
}
static inline void ov002_Model_SetPos2(void *m, s32 x, s32 y) {
    FIELD(m, 0xfc, s32) = (x - 0x7b) << 12;
    FIELD(m, 0x100, s32) = (y - 0x59) << 12;
}
void func_ov002_021e31fc(void *self) {
    void *model;
    s32 x;
    s32 y;
    s32 z;
    if (FIELD(self, 0x48, s32) != 1) {
        return;
    }
    if (!FIELD(self, 0x20, Bits021e31fc).b0) {
        return;
    }
    y = FIELD(self, 0x10, s32) + ((FIELD(self, 0x18, s32) - FIELD(FIELD(self, 0x34, void *), 0x48, s32)) << 11);
    z = FIELD(self, 0x14, s32);
    x = FIELD(self, 0xc, s32);
    if (FIELD(self, 0x30, void *) != NULL) {
        ov002_Model_SetPos(FIELD(self, 0x30, void *), ((x >> 12) - 0x7b) << 12, ((y >> 12) - 0x59) << 12);
        FIELD(FIELD(self, 0x30, void *), 0x150, s32) = z;
        model = FIELD(self, 0x30, void *);
        ov002_Model_PlayPart(model, FIELD(self, 0x3a, u16));
        x += 0xc000;
    }
    FIELD(self, 0x34, VObject *)->v0x20(x >> 12, y >> 12);
    FIELD(FIELD(self, 0x34, void *), 0x70, s32) = z;
    FIELD(self, 0x34, VObject *)->v0x90();
}

}
