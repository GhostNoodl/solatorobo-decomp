#include "ov015/ov015.h"

extern "C" {

s32 ResSet_UpdateLoad(void *a);
extern const Ov015ShipCfg data_ov015_02212db0;
extern char data_ov015_02212e14[];
extern char data_ov015_02212e15[];
s32 Model_FindResIdxByName(void *a, const void *b, const void *c);
u8 *Tbl_FindEntry_0206fef8(u16 id);
BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void Model0218fe1c_ClearLoop(void *a);
void Model0218fe1c_PauseAnim(void *a);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
BOOL Model021903b4_Draw(void *a);
extern u8 Ov015FishState_vtbl[];
extern u8 Ov015Vt_02212f64_vtbl[];

BOOL func_ov015_0220e024(Ov015StageMdl *self) {
    BOOL r = TRUE;
    if (self->res0.unk_00 >= 0) {
        if (ResSet_UpdateLoad(&self->res0) == 0) r = FALSE;
    }
    if (self->res1.unk_00 >= 0) {
        if (ResSet_UpdateLoad(&self->res1) == 0) r = FALSE;
    }
    return r;
}

BOOL func_ov015_0220e074(Ov015StageMdl *self) {
    s32 i;
    s32 cur;
    Ov002Obj *n;
    Model0218fe1c_SetRes(&self->mdl0, &self->res0, 0, 1);
    self->mdl0.boxTest = 0;
    Model0218fe1c_SetLoop(&self->mdl0);
    self->mdl0.visible = 1;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)self->mdl0.renderObj, func_ov015_022090fc);
    self->mdl0.clearInit = 0;
    self->mdl0.renderUser = &self->unk_49c;
    self->mdl0.flushVP = 1;
    self->unk_4cc = Model_FindResIdxByName(&self->mdl0, data_ov015_02212e14, data_ov015_02212e15);
    self->unk_50c = FLD(s16, Tbl_FindEntry_0206fef8(self->unk_498), 0x10);
    Model0218fe1c_SetRes(&self->mdl1, &self->res1, 0, 1);
    if (self->unk_3a4 != 0) {
        Model0218fe1c_SetAnim(&self->mdl1, data_ov015_02212db0.name, 0x1000, 0);
        Model0218fe1c_PauseAnim(&self->mdl1);
        Model0218fe1c_ClearLoop(&self->mdl1);
        Model0218fe1c_SetAnimFrame(&self->mdl1, self->unk_3a4 << 12);
    }
    self->mdl1.boxTest = 0;
    self->mdl1.visible = 1;
    cur = self->slot;
    for (i = 0; i < 8; i++) {
        if (self->slots[i].endTime >= 0) {
            cur = i;
            break;
        }
    }
    self->slot = cur;
    if (cur >= 0) {
        Model0218fe1c_SetAnim(&self->mdl0, self->slots[cur].anim, 0x1000, 0);
        if (self->slots[self->slot].c) {
            Model0218fe1c_SetLoop(&self->mdl0);
        } else {
            Model0218fe1c_ClearLoop(&self->mdl0);
        }
        self->unk_490 = self->slots[self->slot].speed;
    }
    for (n = gOv002Stage->head; n != NULL; n = n->next) {
        if (n->unk_04 == 7) {
            if (((Ov002Cam021f0854 *)n)->unk_4c == 2) {
                self->unk_518 = (Ov002Cam021f0854 *)n;
            } else if (((Ov002Cam021f0854 *)n)->unk_4c == 3) {
                self->unk_51c = (Ov002Cam021f0854 *)n;
            }
        }
    }
    return TRUE;
}

struct Ov015Bits8e294 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};
BOOL func_ov015_0220e294(Ov015StageMdl *self) {
    s32 sel;
    s32 i;
    s32 t;
    s32 cur;

    Ov002Obj021f075c *found;
    Ov002Obj021f075c *o;
    t = gOv002Stage->unk_d0;
    if (t >= self->unk_1c) return FALSE;

    cur = self->slot;
    sel = cur;
    for (i = 0; i < 8; i++) {
        if (self->slots[i].endTime >= t) {
            sel = i;
            break;
        }
    }
    if (sel >= 0 && sel != cur) {
        Model0218fe1c_SetAnim(&self->mdl0, self->slots[sel].anim, 0x1000, 0);
        if (self->slots[sel].c) {
            Model0218fe1c_SetLoop(&self->mdl0);
        } else {
            Model0218fe1c_ClearLoop(&self->mdl0);
        }
        self->unk_490 = self->slots[sel].speed;
    }
    self->slot = sel;
    found = NULL;
    o = self->unk_520;
    if (o == NULL) {
        found = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, -1);
    } else if (o->done) {
        found = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, o->unk_18);
    }
    if (found != NULL) {
        if (self->unk_520 != NULL) {
            Ov002Obj021f075c_RemoveAnims(self->unk_520);
        }
        Ov002Obj021f075c_LoadAnim(found);
        self->unk_520 = found;
    }
    o = self->unk_520;
    if (o != NULL) {
        self->unk_4d0 = o->jnt.trans;
        MI_Copy36B(&o->jnt.rot, &self->unk_4dc);
        self->unk_500 = self->unk_520->jnt.scale;
    }
    Model0218fe1c_UpdateAnim(&self->mdl0, self->unk_490);
    Model0218fe1c_UpdateAnim(&self->mdl1, self->unk_490);
    return TRUE;
}

void func_ov015_0220e434(Ov015StageMdl *self) {
    s32 c;
    if (self->vfunc_08() == 0) {
        return;
    }
    c = gOv002Stage->unk_0c;
    if (c == 1 && self->unk_518 != NULL) {
        self->unk_518->vfunc_20();
    } else if (c == 2 && self->unk_51c != NULL) {
        self->unk_51c->vfunc_20();
    }

    {
        s32 k = self->unk_50c;
        s32 x = FX_Mul(self->unk_500.x, k);
        s32 y = FX_Mul(self->unk_500.y, k);
        s32 z = FX_Mul(self->unk_500.z, k);
        self->mdl0.trans = self->unk_4d0;
        MI_Copy36B(&self->unk_4dc, &self->mdl0.rot);
        self->mdl0.scale.x = x;
        self->mdl0.scale.y = y;
        self->mdl0.scale.z = z;
    }
    Model021903b4_Draw(&self->mdl0);
    self->mdl1.trans = self->unk_4c0;
    MI_Copy36B(&self->unk_49c, &self->mdl1.rot);
    Model021903b4_Draw(&self->mdl1);
    NNS_G3dGeFlushBuffer();
}

BOOL func_ov015_0220e55c(Ov015StageMdl *self) {
    return self->unk_0c >= 3;
}

void Ov015StageMdl_QueueAnim(Ov015StageMdl *self, const char *anim, s32 endTime, u8 c, s16 speed) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (self->slots[i].anim == NULL) {
            self->slots[i].anim = anim;
            self->slots[i].endTime = endTime;
            self->slots[i].c = c;
            self->slots[i].speed = speed;
            return;
        }
    }
}

void *Ov015FishState_Dtor(Ov015FishState *self) {
    SET_VT(self, Ov015FishState_vtbl);
    return self;
}

void *Ov015Vt_02212f64_DtorDelete(Ov002Obj *self) {
    SET_VT(self, Ov015Vt_02212f64_vtbl);
    Ov002Obj_Detach(self);
    Heap_Free(self);
    return self;
}

void func_ov015_0220e5f0(void) {
}

BOOL func_ov015_0220e5f4(void) {
    return FALSE;
}

BOOL func_ov015_0220e5fc(void) {
    return TRUE;
}

BOOL func_ov015_0220e604(void) {
    return TRUE;
}

BOOL func_ov015_0220e60c(void) {
    return TRUE;
}

void *Ov015Vt_02212f64_Dtor(Ov002Obj *self) {
    SET_VT(self, Ov015Vt_02212f64_vtbl);
    Ov002Obj_Detach(self);
    return self;
}

}
