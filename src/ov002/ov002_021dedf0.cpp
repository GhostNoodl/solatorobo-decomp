#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin);
void func_ov002_021e3a18(Vec2 *out, int rot, Vec2 *a, Vec2 *b, Vec2 *c);

typedef struct Bits021e0280 {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Bits021e0280;

static inline void updateModel(u8 *m) {
    s32 v[3];
    func_ov002_021e3b40(v, FIELD(m, 0x74, s32), FIELD(m, 0x78, s32), (s32 *)(m + 0x7c));
    v[1] = FIELD(m, 0x84, s32);
    FIELD(m, 0x38, s32) = v[0];
    FIELD(m, 0x3c, s32) = v[1];
    FIELD(m, 0x40, s32) = v[2];
    if (FIELD(m, 0x1c, void *) != NULL && func_0203e63c(FIELD(m, 0x20, void *))) {
        NNS_G3dGlbSetBaseTrans(m + 0x38);
        NNS_G3dGlbSetBaseScale(m + 0x44);
        MI_Copy36B(m + 0x50, data_020928b4);
        NNS_G3dGlb.fc &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw(FIELD(m, 0x1c, void *));
        NNS_G3dGeFlushBuffer();
    }
}

// Callers pass only self. The loop counter `i` is declared as an unused second
// parameter because that gives the target's register allocation.
void func_ov002_021dedf0(void *self, s32 i) {
    u8 *sh;
    s32 j;
    s32 rows;
    s32 cols;
    u8 *t;
    Vec2 pos;
    Vec2 org;
    Vec2 v;
    Vec2 out;
    sh = NULL;
    t = FIELD(FIELD(self, 0xc, u8 *), 0xa0, u8 *);
    if (t != NULL) {
        sh = (u8 *)func_02070dcc(func_0206ede8(FIELD(t, 0x38, u16))[1]);
    }
    pos.x = FIELD(self, 0x2c, s32);
    pos.y = FIELD(self, 0x30, s32);
    if (sh == NULL) {
        return;
    }
    func_ov002_021e38f8(&org.x, sh);
    rows = FIELD(sh, 0x4, Nibbles16).n3;
    cols = FIELD(sh, 0x4, Nibbles16).n2;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (FIELD(sh, 0x0, u8 *)[i * cols + j] == 1) {
                v.x = j;
                v.y = i;
                func_ov002_021e3a18(&out, (u8)FIELD(sh, 0x6, Bits021e0280).rot, &v, &org, &pos);
                u8 *m = FIELD(self, 0x14, u8 *);
                FIELD(m, 0x74, s32) = out.x;
                FIELD(m, 0x78, s32) = out.y;
                updateModel(FIELD(self, 0x14, u8 *));
            }
        }
    }
}

}
