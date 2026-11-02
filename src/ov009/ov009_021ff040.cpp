#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov009_02216ab6[];
extern char data_ov009_02216ace[];
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);

void func_ov009_021ff040(Ov009ActVt_022165f8 *self) {
    func_ov003_021d5348(self);
    if (self->velY < -0x133) {
        func_ov000_02198360(self->fsm, 1, 0);
    }
}

void func_ov009_021ff074(Ov009ActVt_022165f8 *self) {
    if (self->fsm->st == 0 && self->unk_18 == 0) {
        self->hit->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

void func_ov009_021ff0a0(Ov009ActVt_022165f8 *self) {
    if (self->fsm->st == 0 && self->unk_f4 == 0x5045) {
        EffectMgr_Kill(data_0214a420, self->unk_f8);
        self->unk_f8 = 0;
    }
    func_ov003_021d5900(self);
}

void func_ov009_021ff0f0(Ov009ActVt_022165f8 *self) {
    if (self->fsm->st == 0 && self->unk_f4 == 0x5045) {
        EffectMgr_Kill(data_0214a420, self->unk_f8);
        self->unk_f8 = 0;
    }
    func_ov003_021d6054(self);
}

void func_ov009_021ff140(Ov003Actor *self) {
    func_ov003_021d0fc0(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 0xe);
    self->unk_ea_10 = 1;
}

void func_ov009_021ff188(Ov003Actor *self) {
    BOOL go;
    Ov003Actor *target;
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *s48 = self->hit;
        ActorSub44 *s44;
        s48->unk_9a_1 = 0;
        s48->unk_9a_4 = 0;
        self->model->visible = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->fsm->st++;
    }
        break;
    case 1:
        go = FALSE;
        if (self->unk_1a == 0) {
            go = TRUE;
        } else {
            target = Actor_GetTarget(self);
            if (target != NULL && Hit_DiffInSphere(&target->pos, &self->pos, target->radius + 0x8000)) {
                go = TRUE;
            }
        }
        if (go) {
            self->model->visible = 1;
            func_ov000_02190cb0(self->model, data_ov009_02216ace, 0x1000, 0);
            self->fsm->st++;
        }
        break;
    case 2:
        if (func_ov000_02191120(self->model)) {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

void func_ov009_021ff2d8(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov009_02216ab6, 0xcd, 0);
        func_ov000_021915a0(self->model);
    }
    func_ov003_021d6054(self);
}

void func_ov009_021ff31c(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov009_021ff33c(Ov003Actor *self) {
    if (self->hit != NULL) {
        func_ov000_0219864c(self->hit, 0, 0);
    }
}

void func_ov009_021ff35c(void) {
}

void func_ov009_021ff360(void) {
}

void func_ov009_021ff364(void) {
}

void func_ov009_021ff368(void) {
}

void func_ov009_021ff36c(void) {
}

void func_ov009_021ff370(void) {
}

void func_ov009_021ff374(void) {
}

void func_ov009_021ff378(void) {
}

void func_ov009_021ff37c(Ov003Actor *self) {
    self->vfunc_54();
}

void func_ov009_021ff390(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void func_ov009_021ff3b0(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}

void func_ov009_021ff3d4(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}

void func_ov009_021ff3f8(Ov003Actor *self) {
    func_ov003_021d3524(self);
}

void func_ov009_021ff404(Ov009ActVt_022165f8 *self) {
    self->vfunc_80();
}

void func_ov009_021ff418(Ov009ActVt_02216750 *self) {
    self->vfunc_7c();
}

Ov009ActVt_022163f4 *Ov009ActVt_022163f4_DtorDelete(Ov009ActVt_022163f4 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022163f4 *Ov009ActVt_022163f4_Dtor(Ov009ActVt_022163f4 *self) {
    func_ov003_021d0edc(self);
    return self;
}

void func_ov009_021ff45c(Ov009ActVt_022166a4 *self) {
    self->vfunc_80();
}

Ov009ActVt_02216a00 *Ov009ActVt_02216a00_Dtor(Ov009ActVt_02216a00 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_02216a00 *Ov009ActVt_02216a00_DtorDelete(Ov009ActVt_02216a00 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *func_ov009_021ff4a0(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *func_ov009_021ff4b4(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022164a0 *Ov009ActVt_022164a0_Dtor(Ov009ActVt_022164a0 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_022164a0 *Ov009ActVt_022164a0_DtorDelete(Ov009ActVt_022164a0 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *func_ov009_021ff500(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *func_ov009_021ff514(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022166a4 *Ov009ActVt_022166a4_Dtor(Ov009ActVt_022166a4 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_022166a4 *Ov009ActVt_022166a4_DtorDelete(Ov009ActVt_022166a4 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216348 *Ov009ActVt_02216348_Dtor(Ov009ActVt_02216348 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_02216348 *Ov009ActVt_02216348_DtorDelete(Ov009ActVt_02216348 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *func_ov009_021ff590(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *func_ov009_021ff5a4(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216750 *Ov009ActVt_02216750_Dtor(Ov009ActVt_02216750 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_02216750 *Ov009ActVt_02216750_DtorDelete(Ov009ActVt_02216750 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022165f8 *Ov009ActVt_022165f8_Dtor(Ov009ActVt_022165f8 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_022165f8 *Ov009ActVt_022165f8_DtorDelete(Ov009ActVt_022165f8 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *func_ov009_021ff620(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *func_ov009_021ff634(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

void func_ov009_021ff650(Ov003Actor *self) {
    // This method reads 0x04 as an owner and 0x08 as flag bits, not as Actor::prev/next.
    u8 *p = FLD(u8 *, self->prev, 0x2c);
    s32 v;
    if (p == NULL) {
        return;
    }
    if ((u32)self->next & 0x10) {
        v = self->unk_ae;
    } else {
        v = -1;
    }
    if (v == FLD(s32, p, 0)) {
        NNS_G3dGetCurrentMtx((MtxFx43 *)(p + 4), NULL);
    }
}

void func_ov009_021ff690(Ov003Actor *self) {
    FLD(void *, self, 0x24) = (void *)func_ov009_021ff650;
    self->unk_92 = 3;
}

void Ov009ActVt_022171d4_Start(Ov009ActVt_022171d4 *self) {
    func_ov003_021d112c(self);
    self->unk_f0 = 0;
    self->unk_f4 = 0;
    switch (self->kind) {
    case 0x5421:
        self->unk_f2 = 0x50;
        if (self->unk_1a == 0) {
            func_ov000_02198360(self->fsm, 0x20, 0);
            self->unk_f4 = 0xf0;
        }
        break;
    case 0x5031:
        self->unk_f2 = 0x64;
        break;
    }
    {
        VecFx32 *v = &self->hit->check;
        s32 x = v->x;
        s32 y = v->y;
        s32 z = v->z;
        self->unk_b8.x = x;
        self->unk_b8.y = y;
        self->unk_b8.z = z;
    }
}

}
