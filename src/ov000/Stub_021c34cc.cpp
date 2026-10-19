#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "nitro/fx.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} P3;

typedef struct {
    u8 unk_00[0xc];
    s32 x;
    s32 y;
    u8 unk_14[0x24];
    Model *a;
    Model *b;
    u8 unk_40[0xe];
    u16 mask;
    u8 b50;
    u8 n;
    u8 b52;
    u8 unk_53;
    u8 alpha;
    u8 unk_55[3];
    s32 scale;
    s32 ox;
    s32 oy;
    s32 z;
} Obj021c34fc;


extern "C" {

BOOL func_02054f10(void *p, s32 a);
void func_ov000_021c34fc(Obj021c34fc *self);

void func_ov000_021c34cc(Obj021c34fc *self) {
    void *p = *(void **)((u8 *)self + 0x38);
    if (p == NULL) {
        return;
    }
    if (func_02054f10(p, 0) == 0) {
        return;
    }
    func_ov000_021c34fc(self);
}

static inline void Model_PlayPartEx(Model *model, s32 idx, s32 flag) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Model_GetPart(model, idx & 0xffff);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, (u16)idx) + 0xc));
    }
    func_02042628(model, anim, part, flag);
}

static inline void Put(Obj021c34fc *self, Model **pm, P3 *p, s32 i) {
    MODEL_FLAGS(*pm)->alpha = self->alpha;
    (*pm)->unk_150 = p->z;
    MTX_Identity22((MtxFx22 *)((u8 *)*pm + 0x114));
    {
        u8 *m = (u8 *)*pm + 0x114;
        MTX_ScaleApply22((MtxFx22 *)m, (MtxFx22 *)m, self->scale, self->scale);
    }
    (*pm)->pos[0] = *(ModelPos *)p;
    Model_PlayPartEx(*pm, i, 1);
}

void func_ov000_021c34fc(Obj021c34fc *self) {
    BOOL on;
    u16 mask;
    s32 i;
    s32 n;
    on = self->b50 == self->n && self->b52 != 0;
    if (!on) {
        self->a->color = 0x2108;
        self->b->color = 0x2108;
    }
    n = self->n;
    mask = self->mask;
    for (i = 0; i < n; i++) {
        P3 p = {self->ox + self->x, self->oy + self->y, self->z};
        if (!on) {
            switch (i) {
            case 0:
                p.x -= 0x2000;
                p.y -= 0x2000;
                break;
            case 1:
                p.x += 0x2000;
                p.y -= 0x2000;
                break;
            case 2:
                p.x -= 0x2000;
                p.y += 0x2000;
                break;
            case 3:
                p.x += 0x2000;
                p.y += 0x2000;
                break;
            }
        }
        if (mask & (1 << i)) {
            Put(self, &self->a, &p, i);
        } else {
            Put(self, &self->b, &p, i);
        }
    }
}

}
