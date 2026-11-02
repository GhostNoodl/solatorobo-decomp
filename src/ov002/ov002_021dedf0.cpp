#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin);
void func_ov002_021e3a18(Vec2 *out, int rot, Vec2 *a, Vec2 *b, Vec2 *c);

typedef struct Bits021e0280 {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Bits021e0280;

static inline void updateModel(Obj021efe8c *m) {
    s32 v[3];
    func_ov002_021e3b40(v, m->unk_74, m->unk_78, &m->unk_7c);
    v[1] = m->unk_84;
    m->mdl.trans.x = v[0];
    m->mdl.trans.y = v[1];
    m->mdl.trans.z = v[2];
    if (m->mdl.renderObj != NULL && func_0203e63c(m->mdl.texTask)) {
        NNS_G3dGlbSetBaseTrans(&m->mdl.trans);
        NNS_G3dGlbSetBaseScale(&m->mdl.scale);
        MI_Copy36B(&m->mdl.rot, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw(m->mdl.renderObj);
        NNS_G3dGeFlushBuffer();
    }
}

// Callers pass only self. The loop counter `i` is declared as an unused second
// parameter because that gives the target's register allocation.
void func_ov002_021dedf0(Obj021efef0 *self, s32 i) {
    Ov002Shape *sh;
    s32 j;
    s32 rows;
    s32 cols;
    u8 *t;
    Vec2 pos;
    Vec2 org;
    Vec2 v;
    Vec2 out;
    sh = NULL;
    t = FIELD(((u8 *)self->unk_0c), 0xa0, u8 *);
    if (t != NULL) {
        sh = func_02070dcc(func_0206ede8(FIELD(t, 0x38, u16))[1]);
    }
    pos.x = self->unk_2c;
    pos.y = self->unk_30;
    if (sh == NULL) {
        return;
    }
    func_ov002_021e38f8(&org.x, sh);
    rows = sh->h;
    cols = sh->w;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sh->grid[i * cols + j] == 1) {
                v.x = j;
                v.y = i;
                func_ov002_021e3a18(&out, (u8)sh->rot, &v, &org, &pos);
                Obj021efe8c *m = self->unk_14;
                m->unk_74 = out.x;
                m->unk_78 = out.y;
                updateModel(self->unk_14);
            }
        }
    }
}

}
