#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "nitro/fx.h"
#include "ov000/ListRow.h"

extern "C" {

BOOL Model_IsReady(void *p, s32 a);
void func_ov000_021c34fc(ListRow021cca70 *self);

void ListRow021cca70_Draw(ListRow021cca70 *self) {
    void *p = self->unk_38;
    if (p == NULL) {
        return;
    }
    if (Model_IsReady(p, 0) == 0) {
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
    TexObj_DrawCell(model, anim, part, flag);
}

static inline void Put(ListRow021cca70 *self, Model **pm, VecFx32 *p, s32 i) {
    MODEL_FLAGS(*pm)->alpha = self->alpha;
    (*pm)->unk_150 = p->z;
    MTX_Identity22((*pm)->mtx);
    {
        MtxFx22 *m = (*pm)->mtx;
        MTX_ScaleApply22(m, m, self->scale, self->scale);
    }
    (*pm)->pos[0] = *(ModelPos *)p;
    Model_PlayPartEx(*pm, i, 1);
}

void func_ov000_021c34fc(ListRow021cca70 *self) {
    BOOL on;
    u16 mask;
    s32 i;
    s32 n;
    on = self->item.count == self->item.n && self->item.unk_0a != 0;
    if (!on) {
        self->unk_38->color = 0x2108;
        self->unk_3c->color = 0x2108;
    }
    n = self->item.n;
    mask = self->item.mask;
    for (i = 0; i < n; i++) {
        VecFx32 p = {self->ox + self->x, self->oy + self->y, self->partZ};
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
            Put(self, &self->unk_38, &p, i);
        } else {
            Put(self, &self->unk_3c, &p, i);
        }
    }
}

}
