#include "ov015/ov015.h"

extern "C" {

s32 func_ov000_0218f110(void *a);
extern u8 *data_ov002_021f0f9c;
extern const Ov015ShipCfg data_ov015_02212db0;
extern char data_ov015_02212e14[];
extern char data_ov015_02212e15[];
s32 func_ov000_021909a8(void *a, const void *b, const void *c);
u8 *func_0206fef8(u16 id);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02191618(void *a);
void func_ov000_02191690(void *a);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_02190a80(void *a, s32 b);
void *func_ov002_021e4ee4(void *self, s32 a, s32 b);
void func_ov002_021e6360(void *p);
void func_ov002_021e61b4(void *p);
BOOL func_ov000_021903b4(void *a);
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212f64[];
void func_ov002_021e4d4c(void *self);

BOOL func_ov015_0220e024(Ov015StageMdl *self) {
    BOOL r = TRUE;
    if (self->res0.unk_00 >= 0) {
        if (func_ov000_0218f110(&self->res0) == 0) r = FALSE;
    }
    if (self->res1.unk_00 >= 0) {
        if (func_ov000_0218f110(&self->res1) == 0) r = FALSE;
    }
    return r;
}

BOOL func_ov015_0220e074(Ov015StageMdl *self) {
    s32 i;
    s32 cur;
    Ov002Obj *n;
    func_ov000_0218ffdc(&self->mdl0, &self->res0, 0, 1);
    self->mdl0.boxTest = 0;
    func_ov000_021915a0(&self->mdl0);
    self->mdl0.visible = 1;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)self->mdl0.renderObj, func_ov015_022090fc);
    self->mdl0.clearInit = 0;
    self->mdl0.renderUser = &self->unk_49c;
    self->mdl0.flushVP = 1;
    self->unk_4cc = func_ov000_021909a8(&self->mdl0, data_ov015_02212e14, data_ov015_02212e15);
    self->unk_50c = FLD(s16, func_0206fef8(self->unk_498), 0x10);
    func_ov000_0218ffdc(&self->mdl1, &self->res1, 0, 1);
    if (self->unk_3a4 != 0) {
        func_ov000_02190cb0(&self->mdl1, data_ov015_02212db0.name, 0x1000, 0);
        func_ov000_02191690(&self->mdl1);
        func_ov000_02191618(&self->mdl1);
        func_ov000_02191318(&self->mdl1, self->unk_3a4 << 12);
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
        func_ov000_02190cb0(&self->mdl0, self->slots[cur].anim, 0x1000, 0);
        if (self->slots[self->slot].c) {
            func_ov000_021915a0(&self->mdl0);
        } else {
            func_ov000_02191618(&self->mdl0);
        }
        self->unk_490 = self->slots[self->slot].speed;
    }
    for (n = FLD(Ov002Obj *, data_ov002_021f0f9c, 0xdc); n != NULL; n = n->next) {
        if (n->unk_04 == 7) {
            if (FLD(s32, n, 0x4c) == 2) {
                self->unk_518 = (Ov015V *)n;
            } else if (FLD(s32, n, 0x4c) == 3) {
                self->unk_51c = (Ov015V *)n;
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

    void *found;
    void *o;
    t = FLD(s32, data_ov002_021f0f9c, 0xd0);
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
        func_ov000_02190cb0(&self->mdl0, self->slots[sel].anim, 0x1000, 0);
        if (self->slots[sel].c) {
            func_ov000_021915a0(&self->mdl0);
        } else {
            func_ov000_02191618(&self->mdl0);
        }
        self->unk_490 = self->slots[sel].speed;
    }
    self->slot = sel;
    found = NULL;
    o = self->unk_520;
    if (o == NULL) {
        found = func_ov002_021e4ee4(self, 3, -1);
    } else if (FLD(Ov015Bits8e294, o, 0xe8).b1) {
        found = func_ov002_021e4ee4(self, 3, FLD(s32, o, 0x18));
    }
    if (found != NULL) {
        if (self->unk_520 != NULL) {
            func_ov002_021e6360(self->unk_520);
        }
        func_ov002_021e61b4(found);
        self->unk_520 = (Ov002Obj *)found;
    }
    o = self->unk_520;
    if (o != NULL) {
        self->unk_4d0 = FLD(VecFx32, o, 0xdc);
        MI_Copy36B((u8 *)o + 0xb8, &self->unk_4dc);
        self->unk_500 = FLD(VecFx32, self->unk_520, 0x94);
    }
    func_ov000_02190a80(&self->mdl0, self->unk_490);
    func_ov000_02190a80(&self->mdl1, self->unk_490);
    return TRUE;
}

void func_ov015_0220e434(Ov015StageMdl *self) {
    void *o;
    s32 c;
    if (VCALL(self)->v08() == 0) {
        return;
    }
    c = FLD(s32, data_ov002_021f0f9c, 0xc);
    if (c == 1 && self->unk_518 != NULL) {
        self->unk_518->v20();
    } else if (c == 2 && self->unk_51c != NULL) {
        self->unk_51c->v20();
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
    func_ov000_021903b4(&self->mdl0);
    self->mdl1.trans = self->unk_4c0;
    MI_Copy36B(&self->unk_49c, &self->mdl1.rot);
    func_ov000_021903b4(&self->mdl1);
    NNS_G3dGeFlushBuffer();
}

BOOL func_ov015_0220e55c(Ov015StageMdl *self) {
    return self->unk_0c >= 3;
}

void func_ov015_0220e570(Ov015StageMdl *self, const char *anim, s32 endTime, u8 c, s16 speed) {
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
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *func_ov015_0220e5c8(Ov002Obj *self) {
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);
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

void *func_ov015_0220e614(Ov002Obj *self) {
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);
    return self;
}

}
