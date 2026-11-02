#include "ov000/ModelPart.h"
#include "ov000/MessageQueue.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    s32 x;
    s32 y;
} Lim0216b880;

extern "C" {
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern u8 data_ov000_021c9a9c[];

static inline void Model_PlayPartEx(Model *model, s32 idx, s32 flag) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, anim, part, flag);
}

static inline BOOL IsShown(ObjBase021cac0c_021cb6f0 *p) {
    return p->unk_0c_3 ? TRUE : FALSE;
}

static inline Lo021cb798 *GetA0216b880(MessageQueue021cb980 *mgr) {
    return mgr->unk_11c != NULL ? mgr->unk_11c->unk_58 : NULL;
}

static inline Lo021cb744 *GetB0216b880(MessageQueue021cb980 *mgr) {
    return mgr->unk_11c != NULL ? mgr->unk_11c->unk_64 : NULL;
}

void func_ov000_0216b880(Lo0216b474 *self) {
    s32 off;
    Model *m;
    Lo021cb798 *a;
    Lo021cb744 *b;
    s32 y;
    s32 v;
    if (self->state != 7 && self->state != 8) {
        return;
    }
    v = self->ratio;
    y = LO_FX_MUL(v, 0x40000) + 0x55000;
    y -= 0xb000;
    a = GetA0216b880(data_ov000_021ccd30);
    b = GetB0216b880(data_ov000_021ccd30);
    Lim0216b880 lim = LFLD(Lim0216b880, data_ov000_021c9a9c, 0x20);
    off = 0;
    if (b != NULL && IsShown(b) && (m = b->unk_9c) != NULL) {
        lim.x = m->x;
        lim.y = m->y - 0x15000;
        off = -0x12000;
    } else if (a != NULL && IsShown(a) && (m = a->unk_a4) != NULL) {
        lim.x = m->x;
        lim.y = m->y - 0x15000;
        off = -0xa000;
    }
    if (v == 0) {
        if (y > lim.y) {
            y = lim.y;
        }
    } else if (y > lim.y) {
        y += off;
    }
    Model_SetPos(self->model, -0x7d000, y & ~0xfff);
    self->model->unk_150 = -0x2000;
    if (self->part22) {
        Model_PlayPartEx(self->model, 0x22, 0);
    } else {
        Model_PlayPartEx(self->model, 0x23, 0);
    }
}

}
