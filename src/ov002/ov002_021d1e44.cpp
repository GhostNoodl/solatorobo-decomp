#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d1e44(void) {
}

void func_ov002_021d1e48(Task021ef69c *self) {
    u16 keys = data_02097dc8->trig;
    void *ev = self->unk_44;
    if (ev != NULL) {
        if (!(keys & 2)) {
            return;
        }
        if (FIELD(ev, 0x58, s32) < 0x1000) {
            return;
        }
        FIELD(ev, 0x6c, u8) = 0;
        self->unk_44 = NULL;
        func_ov000_021c701c(self->unk_3c);
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    } else {
        ListRow *m;
        if (!(keys & 2)) {
            return;
        }
        self->unk_3c->flags |= 4;
        m = self->unk_3c->unk_88;
        if (m != NULL) {
            data_ov002_021f0f84[2] = m->index;
        }
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        self->vfunc_0c(0);
    }
}

void func_ov002_021d1f20(Task021ef69c *self) {
    if (self->unk_3c != NULL) {
        self->unk_3c->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
    if (self->unk_48 != 0) {
        func_ov002_021d1f70(self);
    }
}


static inline ModelPart *ov002_Model_GetPart(Model *self, int idx) {
    if (idx >= self->numParts) {
        return NULL;
    }
    return &self->parts[idx];
}

// Model_PlayPart with the resource pointer held by the caller (the same shape as SlidePanel's
// Model_GetPartTexR). func_ov002_021d1f70 passes its own res only for the PlayPart(8) of the count
// drawing; that gives the target's register colouring (rounds raC/raE).
static inline void ov002_Model_PlayPartR(Model *model, int idx, ModelRes *&res) {
    ModelPart *part;
    void *anim;
    res = model->res;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 0);
}

static inline void ov002_Model_PlayPart(Model *model, int idx) {
    ModelRes *res;
    ov002_Model_PlayPartR(model, idx, res);
}

static inline void ov002_SetPos(Model *o, s32 x, s32 y) {
    o->x = x;
    o->y = y;
}

void func_ov002_021d1f70(Task021ef69c *self) {
    s32 v44;
    s32 d;
    s32 n;
    Model *m;
    s32 x;
    ListRow021cca70 *o;
    s32 y;
    s32 z;
    s32 bx;
    Model *num;
    ModelRes *res;
    s32 fy;
    o = (ListRow021cca70 *)self->unk_3c->unk_88;
    x = self->unk_50 - 0x6c;
    y = self->unk_54 - 0x44;
    v44 = o->unk_44;
    n = o->item.n;
    d = n - o->item.count;
    z = self->unk_58 + 0x20;
    ov002_SetPos(self->unk_4c, x << 12, (y + 9) << 12);
    self->unk_4c->unk_150 = z;
    m = self->unk_4c;
    ov002_Model_PlayPart(m, 4);
    ov002_SetPos(self->unk_48, (x + 0x10) << 12, y << 12);
    self->unk_48->unk_150 = z;
    func_02041c20(self->unk_48, 6, (void *)v44);
    ov002_Model_PlayPart(self->unk_48, 6);
    func_02041c20(self->unk_48, 6, (void *)0);
    bx = self->unk_50 + 0x50;
    fy = (self->unk_54 - 0x44) << 12;
    self->unk_48->unk_150 = self->unk_58 + 0x20;
    ov002_SetPos(self->unk_48, bx << 12, fy);
    func_02041c20(self->unk_48, 6, (void *)(n - d));
    ov002_Model_PlayPart(self->unk_48, 6);
    ov002_SetPos(self->unk_48, (bx + 10) << 12, fy);
    num = self->unk_48;
    ov002_Model_PlayPartR(num, 8, res);
    ov002_SetPos(self->unk_48, (bx + 0x14) << 12, fy);
    func_02041c20(self->unk_48, 6, (void *)n);
    ov002_Model_PlayPart(self->unk_48, 6);
    func_02041c20(self->unk_48, 6, (void *)0);
}

}
