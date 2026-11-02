#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dedf0(Obj021efef0 *self);

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin);

static inline bool isState5(void *p) {
    return FIELD(p, 0x4, s32) == 5;
}

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

void func_ov002_021deb60(Obj021efef0 *self, Obj021eff50 *a) {
    VObj *c;
    Obj021efe8c *m;
    self->owner = a;
    self->unk_08->vfunc_20();
    c = self->unk_0c;
    if (c != NULL) {
        BOOL s = isState5(c);
        if (!s) {
            c->vfunc_20();
            func_ov002_021dedf0(self);
        }
    }
    m = self->unk_10;
    m->unk_74 = self->unk_2c;
    m->unk_78 = self->unk_30;
    updateModel(self->unk_10);
    self->owner = NULL;
}

typedef struct Fn021dec74 {
    s32 (*fn)(void *, void *);
    u32 pad;
} Fn021dec74;

typedef struct Id021dec74 {
    u16 id;
    u8 pad[6];
} Id021dec74;

extern Fn021dec74 data_ov002_021eef8c[];

extern Id021dec74 data_ov002_021eef90[];

void func_0206ecd4(int a, void *b, u16 c);

void func_ov002_021e34fc(void *self, s32 (*cmp)(void *, void *));

void func_ov002_021dec74(Obj021efef0 *self) {
    u16 btn = data_02097dc8->trig;
    BOOL ch;
    if (btn & 2) {
        self->unk_24 = 0;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        self->unk_1c = 0;
        return;
    }
    if (self->unk_23) {
        self->unk_24 = FIELD(self->unk_0c, 0xa4, s32);
        self->unk_23 = 0;
        self->unk_1c = 0x14;
        return;
    }
    if (self->unk_22) {
        void *t = FIELD(self->unk_0c, 0xa0, void *);
        if (t != NULL) {
            Obj021eff50 *w;
            func_0206ecd4(0x100, (u8 *)self + 0x38, FIELD(t, 0x38, u16));
            w = self->owner;
            func_ov000_0215bb14(((void *)w->unk_20), (u8 *)self + 0x38);
            w->unk_20->vfunc_70();
        }
        self->unk_22 = 0;
        return;
    }
    ch = FALSE;
    if (btn & 0x800) {
        ch = TRUE;
        self->unk_34 = (self->unk_34 + 1) % 2;
        func_02049a48(data_02097e4c, 0x66, -1, -1, -1);
    }
    if (ch) {
        s32 k = self->unk_34;
        void *r;
        Obj021eff50 *w;
        func_ov002_021e34fc(self->unk_0c, data_ov002_021eef8c[k].fn);
        r = MsgRes_GetString(data_02149ef8, data_ov002_021eef90[k].id);
        w = self->owner;
        func_ov000_0215bb14(((void *)w->unk_20), r);
        w->unk_20->vfunc_70();
    }
}

}
