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
        void *m;
        if (!(keys & 2)) {
            return;
        }
        self->unk_3c->flags |= 4;
        m = FIELD(self->unk_3c, 0x88, void *);
        if (m != NULL) {
            data_ov002_021f0f84[2] = FIELD(m, 0x4, s32);
        }
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        self->vfunc_0c(0);
    }
}

void func_ov002_021d1f20(Task021ef69c *self) {
    if (self->unk_3c != NULL) {
        TASK_VOBJ(self, 0x3c)->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
    if (self->unk_48 != 0) {
        func_ov002_021d1f70(self);
    }
}


static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

// Model_PlayPart with the resource pointer held by the caller (the same shape as SlidePanel's
// Model_GetPartTexR). func_ov002_021d1f70 passes its own res only for the PlayPart(8) of the count
// drawing; that gives the target's register colouring (rounds raC/raE).
static inline void ov002_Model_PlayPartR(void *model, int idx, void *&res) {
    void *part;
    void *anim;
    res = FIELD(model, 0x28, void *);
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628((Model *)model, anim, (ModelPart *)part, 0);
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
    void *res;
    ov002_Model_PlayPartR(model, idx, res);
}

static inline void ov002_SetPos(void *o, s32 x, s32 y) {
    FIELD(o, 0xfc, s32) = x;
    FIELD(o, 0x100, s32) = y;
}

void func_ov002_021d1f70(Task021ef69c *self) {
    s32 v44;
    s32 d;
    s32 n;
    void *m;
    s32 x;
    u8 *o;
    s32 y;
    s32 z;
    s32 bx;
    void *num;
    void *res;
    s32 fy;
    o = FIELD(self->unk_3c, 0x88, u8 *);
    x = self->unk_50 - 0x6c;
    y = self->unk_54 - 0x44;
    v44 = FIELD(o, 0x44, s32);
    n = o[0x51];
    d = n - o[0x50];
    z = self->unk_58 + 0x20;
    ov002_SetPos(self->unk_4c, x << 12, (y + 9) << 12);
    FIELD(self->unk_4c, 0x150, s32) = z;
    m = self->unk_4c;
    ov002_Model_PlayPart(m, 4);
    ov002_SetPos(self->unk_48, (x + 0x10) << 12, y << 12);
    FIELD(self->unk_48, 0x150, s32) = z;
    func_02041c20((Model *)self->unk_48, 6, (void *)v44);
    ov002_Model_PlayPart(self->unk_48, 6);
    func_02041c20((Model *)self->unk_48, 6, (void *)0);
    bx = self->unk_50 + 0x50;
    fy = (self->unk_54 - 0x44) << 12;
    FIELD(self->unk_48, 0x150, s32) = self->unk_58 + 0x20;
    ov002_SetPos(self->unk_48, bx << 12, fy);
    func_02041c20((Model *)self->unk_48, 6, (void *)(n - d));
    ov002_Model_PlayPart(self->unk_48, 6);
    ov002_SetPos(self->unk_48, (bx + 10) << 12, fy);
    num = self->unk_48;
    ov002_Model_PlayPartR(num, 8, res);
    ov002_SetPos(self->unk_48, (bx + 0x14) << 12, fy);
    func_02041c20((Model *)self->unk_48, 6, (void *)n);
    ov002_Model_PlayPart(self->unk_48, 6);
    func_02041c20((Model *)self->unk_48, 6, (void *)0);
}

}
