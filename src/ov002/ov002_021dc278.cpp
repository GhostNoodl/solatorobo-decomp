#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dc730(Obj021eff10 *self);
void func_ov002_021dc83c(Obj021eff10 *self);
void func_ov002_021dcf00(Obj021eff10 *self);
void func_ov002_021dd130(Obj021eff10 *self);
void func_ov002_021dd29c(Obj021eff10 *self);
void func_ov002_021dd434(Obj021eff10 *self);
void func_ov002_021dd9dc(Obj021eff10 *self);

static inline void ov002_Anim_Tick(Ov002Mdl021efe3c *mdl) {
    s32 v = mdl->frame;
    if (mdl->anm[0] != NULL) {
        mdl->anm[0]->frame = v;
    }
    if (mdl->anm[1] != NULL) {
        mdl->anm[1]->frame = v;
    }
    if (mdl->anm[2] != NULL) {
        mdl->anm[2]->frame = v;
    }
    mdl->frame = (mdl->frame + 0x1000) % mdl->frameCount;
}

static inline BOOL ov002_Msg_IsDone(void *m) {
    return FIELD(m, 4, s32) == 5;
}

void func_ov002_021dc278(Obj021eff10 *self, Obj021eff50 *other) {
    self->owner = other;
    ov002_Anim_Tick(&self->unk_14->mdl);
    if (self->unk_0c != NULL) {
        self->unk_0c->vfunc_1c();
    }
    {
        Obj021efe5c *m = self->unk_08;
        ov002_Anim_Tick(&m->mdl);
        m->unk_1d8 = (u16)(m->unk_1d8 + 1);
    }
    switch (self->unk_18 / 10 * 10) {
    case 0:
        func_ov002_021dc730(self);
        break;
    case 10:
        func_ov002_021dc83c(self);
        break;
    case 20:
        func_ov002_021dcf00(self);
        break;
    case 30:
        func_ov002_021dd130(self);
        break;
    case 40:
        func_ov002_021dd29c(self);
        break;
    case 50:
        func_ov002_021dd434(self);
        break;
    case 60:
        if (ov002_Msg_IsDone(self->unk_0c)) {
            s32 r = self->unk_1c;
            if (r == 1 || r == -1) {
                SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
            } else if (r == 0) {
                self->unk_18 = 0x46;
                break;
            } else if (r == 2) {
                func_ov002_021dd9dc(self);
            } else {
                break;
            }
            self->unk_18 = 10;
        }
        break;
    case 70: {
        u8 *o4 = ((u8 *)self->owner->board);
        s32 row = self->unk_28;
        void *q = FIELD(o4, 4, void *);
        s32 col = self->unk_24;
        u8 *base;
        u8 *e;
        if (q == NULL || (base = FIELD(o4, 0x70, u8 *)) == NULL) {
            e = NULL;
        } else {
            e = base + (row * FIELD(FIELD(q, 0x6c, u8 *), 4, Nibbles16).n3 + col) * 0xc;
        }
        if (e[2] == 1) {
            u8 *t = FIELD(e, 8, u8 *);
            FIELD(t, 0xcd, u8) = 0;
            FIELD(t, 0x9c, s32) = 0xf85;
        } else if (e[2] == 2) {
            FIELD(FIELD(e, 8, u8 *), 0x9c, u8) = 0;
        }
        {
            void *o = self->owner;
            FIELD(o, 0x10, s32) = 0;
            FIELD(o, 0xc, s32) = 0x28;
        }
        self->unk_18 = 0x50;
        break;
    }
    }
    self->owner = NULL;
}

}
