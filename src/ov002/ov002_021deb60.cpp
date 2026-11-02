#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dedf0(Obj021efef0 *self);

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin);

static inline bool isState5(void *p) {
    return FIELD(p, 0x4, s32) == 5;
}

static inline void updateModel(u8 *m) {
    s32 v[3];
    func_ov002_021e3b40(v, FIELD(m, 0x74, s32), FIELD(m, 0x78, s32), (s32 *)(m + 0x7c));
    v[1] = FIELD(m, 0x84, s32);
    FIELD(m, 0x38, s32) = v[0];
    FIELD(m, 0x3c, s32) = v[1];
    FIELD(m, 0x40, s32) = v[2];
    if (FIELD(m, 0x1c, void *) != NULL && func_0203e63c((unsigned int)FIELD(m, 0x20, void *))) {
        NNS_G3dGlbSetBaseTrans((VecFx32 *)(m + 0x38));
        NNS_G3dGlbSetBaseScale((VecFx32 *)(m + 0x44));
        MI_Copy36B(m + 0x50, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw((NNSG3dRenderObj *)FIELD(m, 0x1c, void *));
        NNS_G3dGeFlushBuffer();
    }
}

void func_ov002_021deb60(Obj021efef0 *self, s32 a) {
    VObj *c;
    u8 *m;
    FIELD(self, 0x4, s32) = a;
    self->unk_08->vfunc_20();
    c = self->unk_0c;
    if (c != NULL) {
        BOOL s = isState5(c);
        if (!s) {
            c->vfunc_20();
            func_ov002_021dedf0(self);
        }
    }
    m = ((u8 *)self->unk_10);
    FIELD(m, 0x74, s32) = self->unk_2c;
    FIELD(m, 0x78, s32) = self->unk_30;
    updateModel(((u8 *)self->unk_10));
    self->unk_04 = NULL;
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
            u8 *w;
            func_0206ecd4(0x100, (u8 *)self + 0x38, FIELD(t, 0x38, u16));
            w = ((u8 *)self->unk_04);
            func_ov000_0215bb14(FIELD(w, 0x20, void *), (u8 *)self + 0x38);
            FIELD(w, 0x20, VObj *)->vfunc_70();
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
        u8 *w;
        func_ov002_021e34fc(self->unk_0c, data_ov002_021eef8c[k].fn);
        r = MsgRes_GetString(data_02149ef8, data_ov002_021eef90[k].id);
        w = ((u8 *)self->unk_04);
        func_ov000_0215bb14(FIELD(w, 0x20, void *), r);
        FIELD(w, 0x20, VObj *)->vfunc_70();
    }
}

}
