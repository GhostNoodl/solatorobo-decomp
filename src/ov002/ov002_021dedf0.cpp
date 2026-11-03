#include "ov002/ov002.h"

extern "C" {

void Ov002_CellXZToPos(s32 *out, s32 x, s32 z, s32 *origin);
void Ov002_RotateAbout(Vec2 *out, int rot, Vec2 *a, Vec2 *b, Vec2 *c);

typedef struct Bits021e0280 {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Bits021e0280;

static inline void updateModel(Obj021efe8c *m) {
    s32 v[3];
    Ov002_CellXZToPos(v, m->unk_74, m->unk_78, &m->unk_7c);
    v[1] = m->unk_84;
    m->mdl.trans.x = v[0];
    m->mdl.trans.y = v[1];
    m->mdl.trans.z = v[2];
    if (m->mdl.renderObj != NULL && Vram_IsTransferDone(m->mdl.texTask)) {
        NNS_G3dGlbSetBaseTrans(&m->mdl.trans);
        NNS_G3dGlbSetBaseScale(&m->mdl.scale);
        MI_Copy36B(&m->mdl.rot, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw(m->mdl.renderObj);
        NNS_G3dGeFlushBuffer();
    }
}

void func_ov002_021dedf0(Obj021efef0 *self);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match declared the loop counter i as an unused second
// parameter (callers pass only self); as a local the registers differ. This file is the function's whole .text, so it
// has no delinks entry. The score is in docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void func_ov002_021dedf0(Obj021efef0 *self) {
    s32 i;
    Ov002Shape *sh;
    s32 j;
    s32 rows;
    s32 cols;
    Obj021f002c *t;
    Vec2 pos;
    Vec2 org;
    Vec2 v;
    Vec2 out;
    sh = NULL;
    t = (Obj021f002c *)self->unk_0c->unk_a0;
    if (t != NULL) {
        sh = func_02070dcc(Param_GetEntry(t->id)[1]);
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
                Ov002_RotateAbout(&out, (u8)sh->rot, &v, &org, &pos);
                Obj021efe8c *m = self->unk_14;
                m->unk_74 = out.x;
                m->unk_78 = out.y;
                updateModel(self->unk_14);
            }
        }
    }
}
#endif

}
