#include "types.h"
#include "ov003/Unit.h"
#include "Main/Gfx/SlidePanel.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"

extern "C" {

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003Plr;

extern void *data_ov000_021ccd64;
extern s32 Ov003CntSelf_CountLiving(void *p);
extern void func_020627b4(void);
extern s32 StageRes_HasQueued(void);
extern Ov003Plr *ActorMgr_FindPlayer(void);
extern char data_ov003_021f803c[];
extern char data_ov003_021f8046[];
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern BOOL Model0218fe1c_SetAnim(void *model, const void *name, s32 a, s32 b);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void HitMesh_Unlink_0203f920(void *p);
extern void HitMesh_Link(void *p);
extern void *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *m, s32 a);

void Ov003ActVt_021f7f14_Init(Ov003Switch *self) {
    Ov003Unit *u;
    ActorEx_Init(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
}

void Ov003ActVt_021f7f14_Start(Ov003Switch *self) {
    AnimCtrl *a;
    ActorEx_Start(self);
    Obj02197d80_LoadValue(self);
    switch (self->unk_18) {
    case 2:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f803c, 0x1000, 0);
        if (self->unk_1c == 1) {
            NNSi_G3dModifyPolygonAttrMask(self->model->mdl, 0, 0x1f0000);
            self->model->alpha = 0;
        }
        if (self->unk_1c != 2) {
            self->unk_cc_0 = 0;
            if (self->hitMesh != NULL) {
                HitMesh_Unlink_0203f920(self->hitMesh);
            }
        }
        break;
    case 0:
    case 1:
    case 3:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f8046, 0x1000, 0);
        if (self->unk_1c == 1) {
            NNSi_G3dModifyPolygonAttrMask(self->model->mdl, 1, 0x1f0000);
        }
        self->unk_cc_0 = 1;
        if (self->hitMesh != NULL) {
            HitMesh_Link(self->hitMesh);
        }
        break;
    }
    Model0218fe1c_SetAnimFrame(self->model, -1);
    self->fsm->st = 0;
    a = Model0218fe1c_GetAnimCtrl(self->model, 2);
    if (a != NULL) {
        s16 s;
        a->loop = 1;
        s = self->unk_1e;
        if (s != 0 && s != 0x1000) {
            s = (s16)((s * 0x800) >> 12);
        } else {
            s = 0x800;
        }
        a->speed = s;
    }
    self->unk_93_1 = (u16)self->unk_18;
}

void Ov003ActVt_021f7f14_Update(Ov003Switch *self) {
    switch (self->unk_1a) {
    case 3: {
        BOOL changed;
        s16 v;
        Ov003Plr *p;
        s32 r = Ov003CntSelf_CountLiving(self->targetObj);
        changed = FALSE;
        switch (r) {
        case 3:
        case 4:
            if (self->unk_18 != 2 && self->fsm->st != 0x14) {
                self->fsm->st = 0x14;
                self->unk_18 = 2;
                changed = TRUE;
            }
            break;
        case 1:
        case 2:
            if (self->unk_18 != 0 && self->fsm->st != 10) {
                self->fsm->st = 10;
                self->unk_18 = 0;
                changed = TRUE;
            }
            break;
        }
        if (!changed) {
            return;
        }
        v = self->unk_18;
        self->unk_93_1 = (u16)v;
        func_020627b4();
        func_ov000_02197dec(self, v, v);
        if (StageRes_HasQueued() != 1) {
            return;
        }
        p = ActorMgr_FindPlayer();
        if (p == NULL) {
            return;
        }
        if (p->unk_b28_0 != 0) {
            return;
        }
        p->unk_15 = 3;
        p->unk_b28_0 = 0;
        p->unk_b28_2 = 1;
        break;
    }
    case 1: {
        s16 v;
        if (self->unk_93_1 == self->unk_18) {
            return;
        }
        switch (self->unk_18) {
        case 2:
            if (self->fsm->st != 0x14) {
                self->fsm->st = 0x14;
                self->unk_18 = 2;
            }
            break;
        case 0:
        case 1:
        case 3:
            if (self->fsm->st != 10) {
                self->fsm->st = 10;
                self->unk_18 = 0;
            }
            break;
        }
        self->unk_93_1 = (u16)self->unk_18;
        func_ov000_02197dec(self, self->unk_18, -1);
        break;
    }
    }
}

extern BOOL AnimCtrl_SetAnim(void *ctrl, void *obj, ResSet *res, void *file, const char *name, s16 blend, u8 force);
extern void Field_ShakeCamera(u8 a, u8 b);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *m);
extern void *Target_Get(ActorSub4c *def);
extern void Actor_SendMsg(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);

static inline void Model0218fe1c_PlayAnim0(Model0218fe1c *m, const char *name, s16 blend, u8 force) {
    const char *n = name;
    if (m->unk_0c != NULL) {
        AnimCtrl_SetAnim(m->unk_0c, m->renderObj, m->res, m->res->anims->list[0], n, blend, force);
    }
}

void Ov003ActVt_021f7f14_StateIdle(Ov003Switch *self) {
    switch (self->fsm->st) {
    case 0:
        break;
    case 10:
        Model0218fe1c_PlayAnim0(self->model, data_ov003_021f8046, 0x22, 0);
        Model0218fe1c_GetAnimCtrl(self->model, 2)->speed = 0x800;
        if (self->unk_1c == 1 && self->fsm->timer == 0) {
            NNSi_G3dModifyPolygonAttrMask(self->model->mdl, 0, 0x1f0000);
            self->model->alpha = 0;
        }
        self->unk_cc_0 = 1;
        if (self->hitMesh != NULL) {
            HitMesh_Link(self->hitMesh);
        }
        SndMgr_PlayVolume(data_02097e4c, 0x3e, -1, -1, -1);
        Field_ShakeCamera(2, 0x3c);
        self->fsm->timer = 0x50;
        self->fsm->st++;
        break;
    case 11:
        if (self->unk_1c == 1) {
            ActorSub40 *w = self->fsm;
            if (w->timer != 0) {
                w->timer--;
            }
            if (w->timer < 0x2c) {
                u8 a = 0x2c - self->fsm->timer;
                NNSi_G3dModifyPolygonAttrMask(self->model->mdl, 0, 0x1f0000);
                self->model->alpha = a / 2;
            }
        }
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        NNSi_G3dModifyPolygonAttrMask(self->model->mdl, 1, 0x1f0000);
        self->fsm->st = 0x32;
        break;
    case 20:
        Model0218fe1c_PlayAnim0(self->model, data_ov003_021f803c, 0x1b, 0);
        Model0218fe1c_GetAnimCtrl(self->model, 2)->speed = 0xc00;
        if (self->unk_1c != 2) {
            self->unk_cc_0 = 0;
            if (self->hitMesh != NULL) {
                HitMesh_Unlink_0203f920(self->hitMesh);
            }
        }
        SndMgr_PlayVolume(data_02097e4c, 0x3e, -1, -1, -1);
        Field_ShakeCamera(2, 0x3c);
        self->fsm->timer = 0x50;
        self->fsm->st++;
        break;
    case 21:
        if (self->unk_1c == 1) {
            ActorSub40 *w = self->fsm;
            if (w->timer != 0) {
                w->timer--;
            }
            if (w->timer <= 0x2c) {
                NNSi_G3dModifyPolygonAttrMask(self->model->mdl, 0, 0x1f0000);
                self->model->alpha = self->fsm->timer >> 1;
            }
        }
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (self->unk_1c == 1) {
            NNSi_G3dModifyPolygonAttrMask(self->model->mdl, 0, 0x1f0000);
            self->model->alpha = 0;
        }
        self->fsm->st = 0x32;
        self->fsm->timer = 0;
        break;
    case 0x32: {
        void *p = Target_Get(self->targetObj);
        if (p != NULL) {
            Actor_SendMsg(p, self->id, 3, 1, 0, 0);
            self->fsm->st = 0;
        }
        self->targetObj->target = 0xffff;
        break;
    }
    }
}

} // extern "C"
