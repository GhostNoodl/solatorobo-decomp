#include "ov006/Model.h"
#include "ov000/ObjLayouts.h"
#include "nitro/fx.h"

typedef struct ov006_Pair021de6bc {
    void *vtbl;
    u8 visible;
    s8 sel;
    u8 unk6[6];
    Model *m1;
    Model *m2;
    VecFx32 pos;
} ov006_Pair021de6bc;

typedef struct ov006_Item021de6bc {
    void *vtbl;
    int visible;
    u8 unk8[4];
    VecFx32 pos;
    ObjBase021cac0c_021cb6f0 *obj;
    Model *model;
} ov006_Item021de6bc;

typedef struct ov006_Hud021de6bc {
    void *vtbl;
    u8 enabled;
    u8 unk5[0xb];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    ov006_Pair021de6bc *pair;
    ov006_Item021de6bc *item;
    void *unk1C;
    Model *unk20;
    Model *unk24;
    s32 x;
    s32 y;
    u8 unk30[4];
    Model *unk34;
} ov006_Hud021de6bc;

extern "C" {

void LoTimer_Draw(void *p);

static inline void ov006_Model_SetPosV(Model *self, const VecFx32 *p) {
    self->pos[0].x = p->x;
    self->pos[0].y = p->y;
}

static inline void ov006_Obj_SetPos(ObjBase021cac0c_021cb6f0 *self, s32 x, s32 y, s32 z) {
    self->unk_74 = x;
    self->unk_78 = y;
    self->unk_7c = z;
}

static inline void ov006_Model_PlayPartF(Model *model, int idx, int flag) {
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
        anim = NNS_G2dGetCellDataByIdx(res->texRes, **((ov006_Unk02023390 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx))->unkC);
    }
    TexObj_DrawCell(model, anim, part, flag);
}

static inline void ov006_Model_PlayPartChk(Model *model, int idx) {
    ModelRes *res;
    ModelPart *part;
    void *anim;
    if (model->res == NULL) {
        return;
    }
    res = model->res;
    part = Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, **((ov006_Unk02023390 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx))->unkC);
    }
    TexObj_DrawCell(model, anim, part, 0);
}

void ov006_Hud021de6bc_Draw(ov006_Hud021de6bc *self) {
    Model *m0;
    ov006_Pair021de6bc *pair;
    ov006_Item021de6bc *item;
    Model *m1;

    if (!self->enabled) {
        return;
    }
    pair = self->pair;
    if (pair->visible) {
        ov006_Model_SetPosV(pair->m1, &pair->pos);
        pair->m1->unk_150 = pair->pos.z;
        m0 = pair->m1;
        ov006_Model_PlayPartChk(m0, 0);
        pair->m1->unk_150 = pair->pos.z + 0x20;
        ov006_Model_PlayPartChk(pair->m1, 1);
        if (pair->sel >= 0) {
            ov006_Model_SetPos(pair->m2, 0, pair->pos.x - 0x6a000, pair->pos.y - 0x4a000);
            pair->m2->unk_150 = pair->pos.z + 0x10;
            ov006_Model_PlayPartF(pair->m2, pair->sel, 1);
        }
    }
    item = self->item;
    if (item->visible) {
        {
            s32 py = item->pos.y >> 12;
            s32 px = item->pos.x >> 12;
            s32 pz = item->pos.z;
            ov006_Obj_SetPos(item->obj, px + 0x55, py + 8, pz + 0x10);
        }
        item->obj->vfunc_10();
        ov006_Model_SetPosV(item->model, &item->pos);
        item->model->unk_150 = item->pos.z;
        ov006_Model_PlayPartChk(item->model, 2);
    }
    LoTimer_Draw(self->unk1C);
    {
        if (self->unk34 != NULL) {
            s32 x = self->x >> 12;
            s32 y = self->y >> 12;
            ov006_Model_SetPos(self->unk34, 0, x << 12, y << 12);
            ov006_Model_PlayPartChk(self->unk34, 0x10);
            ov006_Model_SetPos(self->unk34, 0, (x + 0x1c) << 12, y << 12);
            ov006_Model_PlayPartChk(self->unk34, self->unk10);
            ov006_Model_SetPos(self->unk34, 0, (x + 0x29) << 12, y << 12);
            m1 = self->unk34;
            ov006_Model_PlayPartChk(m1, 10);
            ov006_Model_SetPos(self->unk34, 0, (x + 0x34) << 12, y << 12);
            ov006_Model_PlayPartChk(self->unk34, self->unk11);
        }
    }
    {
        Model *m = self->unk24;
        if (m != NULL) {
            ov006_Model_PlayPartChk(m, (u16)(self->unk12 + 2));
        }
    }
    if (self->unk20 != NULL) {
        if (self->unk13) {
            ov006_Model_PlayPartChk(self->unk20, 7);
        } else {
            ov006_Model_PlayPartChk(self->unk20, 8);
        }
    }
}

}
