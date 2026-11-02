#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin);

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

void func_ov002_021dc58c(Obj021eff10 *self, Obj021eff50 *ev) {
    if (self->unk_10 != NULL) {
        func_02041c20(self->unk_10, 6, FIELD(((u8 *)ev->board), 0x6c, void *));
        Model_PlayPart(self->unk_10, 6);
    }
    if (self->unk_18 != 20 && self->unk_18 / 10 != 0) {
        Obj021efe8c *m = self->unk_14;
        m->unk_74 = self->unk_24;
        m->unk_78 = self->unk_28;
        updateModel(self->unk_14);
    }
    if (self->unk_0c != NULL) {
        self->unk_0c->vfunc_20();
    }
    self->unk_08->unk_1d4 = self->unk_18 == 20;
    func_ov002_021d7988(self->unk_08);
}


void func_ov002_021dd7f0(Obj021eff10 *self, void *a, void *b, int c);

void func_ov002_021dc730(Obj021eff10 *self) {
    BOOL done;
    Obj021efe6c *w;
    Obj021efe9c *a;
    Obj021efe9c *next;
    w = self->owner->board;
    switch (self->unk_18) {
    case 0:
        for (a = (Obj021efe9c *)w->pieces; a != NULL; a = (Obj021efe9c *)a->next) {
            if (a->unk_4a == 1 && a->unk_6c && a->unk_a4 == 0) {
                a->unk_a4 = 0xd2;
                a->unk_a8 = 0xd2;
                a->unk_ac = 10;
            }
        }
        self->unk_18++;
    case 1:
        done = TRUE;
        a = (Obj021efe9c *)w->pieces;
        while (a != NULL) {
            next = (Obj021efe9c *)a->next;
            if (a->unk_4a == 1 && a->unk_6c) {
                if (a->unk_ac == 3) {
                    func_ov002_021d9ed8(w, a, 1);
                } else {
                    done = FALSE;
                }
            }
            a = next;
        }
        if (done) {
            func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
            self->unk_18 = 10;
        }
        break;
    }
}

}
