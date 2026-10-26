#include "ov006/Model.h"
#include "nitro/fx.h"

typedef struct ov006_Pair021de6bc {
    void *vtbl;
    u8 visible;
    s8 sel;
    u8 unk6[6];
    ov006_Model *m1;
    ov006_Model *m2;
    VecFx32 pos;
} ov006_Pair021de6bc;

typedef struct ov006_Obj021de6bc {
    u8 unk0[0x74];
    s32 x;
    s32 y;
    s32 z;
} ov006_Obj021de6bc;

typedef struct ov006_Item021de6bc {
    void *vtbl;
    int visible;
    u8 unk8[4];
    VecFx32 pos;
    ov006_Obj021de6bc *obj;
    ov006_Model *model;
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
    ov006_Model *unk20;
    ov006_Model *unk24;
    s32 x;
    s32 y;
    u8 unk30[4];
    ov006_Model *unk34;
} ov006_Hud021de6bc;

extern "C" {

void func_ov000_0216df28(void *p);

static inline void ov006_Model_SetPosV(ov006_Model *self, const VecFx32 *p) {
    self->unkFC[0].x = p->x;
    self->unkFC[0].y = p->y;
}

static inline void ov006_Obj_SetPos(ov006_Obj021de6bc *self, s32 x, s32 y, s32 z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

static inline void ov006_Model_PlayPartF(ov006_Model *model, int idx, int flag) {
    ov006_ModelRes *res = model->unk28;
    ov006_ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov006_Model_GetPart(model, idx);
    if (part != NULL && part->unk4 != NULL) {
        anim = part->unk4->unk30;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->unk4, **((ov006_Unk02023390 *)NNS_G2dGetAnimSequenceByIdx(res->unkC, idx))->unkC);
    }
    func_02042628(model, anim, part, flag);
}

static inline void ov006_Model_PlayPartChk(ov006_Model *model, int idx) {
    ov006_ModelRes *res;
    ov006_ModelPart *part;
    void *anim;
    if (model->unk28 == NULL) {
        return;
    }
    res = model->unk28;
    part = ov006_Model_GetPart(model, idx);
    if (part != NULL && part->unk4 != NULL) {
        anim = part->unk4->unk30;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->unk4, **((ov006_Unk02023390 *)NNS_G2dGetAnimSequenceByIdx(res->unkC, idx))->unkC);
    }
    func_02042628(model, anim, part, 0);
}

void func_ov006_021de6bc(ov006_Hud021de6bc *self) {
    ov006_Model *m0;
    ov006_Pair021de6bc *pair;
    ov006_Item021de6bc *item;
    ov006_Model *m1;

    if (!self->enabled) {
        return;
    }
    pair = self->pair;
    if (pair->visible) {
        ov006_Model_SetPosV(pair->m1, &pair->pos);
        pair->m1->unk150 = pair->pos.z;
        m0 = pair->m1;
        ov006_Model_PlayPartChk(m0, 0);
        pair->m1->unk150 = pair->pos.z + 0x20;
        ov006_Model_PlayPartChk(pair->m1, 1);
        if (pair->sel >= 0) {
            ov006_Model_SetPos(pair->m2, 0, pair->pos.x - 0x6a000, pair->pos.y - 0x4a000);
            pair->m2->unk150 = pair->pos.z + 0x10;
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
        VCALL(item->obj, 10);
        ov006_Model_SetPosV(item->model, &item->pos);
        item->model->unk150 = item->pos.z;
        ov006_Model_PlayPartChk(item->model, 2);
    }
    func_ov000_0216df28(self->unk1C);
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
        ov006_Model *m = self->unk24;
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
