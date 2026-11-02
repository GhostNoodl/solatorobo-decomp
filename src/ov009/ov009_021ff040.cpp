#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern char data_ov009_02216ab6[];
extern char data_ov009_02216ace[];
extern void SndMgr_LoadHeapState(SndMgr *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Obj021984c8_UpdatePos(void *a, s32 b, s32 c);
extern void ActorSub48_UpdatePos(ActorSub48 *a, VecFx32 *b, u16 *c);

void Ov009ActVt_022165f8_StateKnockBack(Ov009ActVt_022165f8 *self) {
    Ov003Actor_StateKnockBack(self);
    if (self->velY < -0x133) {
        History_SetState(self->fsm, 1, 0);
    }
}

void Ov009ActVt_022165f8_StateThrown(Ov009ActVt_022165f8 *self) {
    if (self->fsm->st == 0 && self->unk_18 == 0) {
        self->hit->unk_30 = 0;
    }
    Ov003Actor_StateThrown(self);
}

void Ov009ActVt_022165f8_StateDown(Ov009ActVt_022165f8 *self) {
    if (self->fsm->st == 0 && self->unk_f4 == 0x5045) {
        EffectMgr_Kill(data_0214a420, self->unk_f8);
        self->unk_f8 = 0;
    }
    Ov003Actor_StateDown(self);
}

void Ov009ActVt_022165f8_StateDie(Ov009ActVt_022165f8 *self) {
    if (self->fsm->st == 0 && self->unk_f4 == 0x5045) {
        EffectMgr_Kill(data_0214a420, self->unk_f8);
        self->unk_f8 = 0;
    }
    Ov003Actor_StateDie(self);
}

void Ov009ActVt_0221654c_Init(Ov003Actor *self) {
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 0xe);
    self->unk_ea_10 = 1;
}

void Ov009ActVt_0221654c_State20(Ov003Actor *self) {
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
            Model0218fe1c_SetAnim(self->model, data_ov009_02216ace, 0x1000, 0);
            self->fsm->st++;
        }
        break;
    case 2:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

void Ov009ActVt_0221654c_StateDie(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_02216ab6, 0xcd, 0);
        Model0218fe1c_SetLoop(self->model);
    }
    Ov003Actor_StateDie(self);
}

void Ov009ActorBase_UpdateSub44(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        Obj021984c8_UpdatePos(self->unk_44, 0, 0);
    }
}

void Ov009Actor_UpdateHit(Ov003Actor *self) {
    if (self->hit != NULL) {
        ActorSub48_UpdatePos(self->hit, 0, 0);
    }
}

void Ov009ActorBase_UpdateMode1(void) {
}

void Ov009ActorBase_UpdateMode3(void) {
}

void func_ov009_021ff364(void) {
}

void Ov009Actor_State25(void) {
}

void Ov009Actor_State24(void) {
}

void Ov009Actor_State23(void) {
}

void Ov009Actor_State22(void) {
}

void Ov009Actor_State21(void) {
}

void Ov009Actor_State16(Ov003Actor *self) {
    self->vfunc_54();
}

void Ov009Actor_Shoot2(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void Ov009Actor_StateAttack3(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}

void Ov009Actor_StateAttack2(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}

void Ov009ActVt_0221654c_StateMove(Ov003Actor *self) {
    Ov003Actor_StateIdle(self);
}

void Ov009ActVt_022165f8_StateHurt(Ov009ActVt_022165f8 *self) {
    self->vfunc_80();
}

void Ov009ActVt_02216750_StateKnockBack(Ov009ActVt_02216750 *self) {
    self->vfunc_7c();
}

Ov009ActVt_022163f4 *Ov009ActVt_022163f4_DtorDelete(Ov009ActVt_022163f4 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022163f4 *Ov009ActVt_022163f4_Dtor(Ov009ActVt_022163f4 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

void Ov009ActVt_022166a4_StateHurt(Ov009ActVt_022166a4 *self) {
    self->vfunc_80();
}

Ov009ActVt_02216a00 *Ov009ActVt_02216a00_Dtor(Ov009ActVt_02216a00 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02216a00 *Ov009ActVt_02216a00_DtorDelete(Ov009ActVt_02216a00 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_02216954_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_02216954_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022164a0 *Ov009ActVt_022164a0_Dtor(Ov009ActVt_022164a0 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022164a0 *Ov009ActVt_022164a0_DtorDelete(Ov009ActVt_022164a0 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_022168a8_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_022168a8_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022166a4 *Ov009ActVt_022166a4_Dtor(Ov009ActVt_022166a4 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022166a4 *Ov009ActVt_022166a4_DtorDelete(Ov009ActVt_022166a4 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216348 *Ov009ActVt_02216348_Dtor(Ov009ActVt_02216348 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02216348 *Ov009ActVt_02216348_DtorDelete(Ov009ActVt_02216348 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_022167fc_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_022167fc_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216750 *Ov009ActVt_02216750_Dtor(Ov009ActVt_02216750 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02216750 *Ov009ActVt_02216750_DtorDelete(Ov009ActVt_02216750 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_022165f8 *Ov009ActVt_022165f8_Dtor(Ov009ActVt_022165f8 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022165f8 *Ov009ActVt_022165f8_DtorDelete(Ov009ActVt_022165f8 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_0221654c_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_0221654c_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov009Part_CaptureMtx(Ov003Actor *self) {
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

void Ov009Part_StartCapture(Ov003Actor *self) {
    FLD(void *, self, 0x24) = (void *)Ov009Part_CaptureMtx;
    self->unk_92 = 3;
}

void Ov009ActVt_022171d4_Start(Ov009ActVt_022171d4 *self) {
    Ov003Actor_Start(self);
    self->unk_f0 = 0;
    self->unk_f4 = 0;
    switch (self->kind) {
    case 0x5421:
        self->unk_f2 = 0x50;
        if (self->unk_1a == 0) {
            History_SetState(self->fsm, 0x20, 0);
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
