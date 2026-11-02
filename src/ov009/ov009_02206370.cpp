#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov009_0221707c;
extern char data_ov009_02216bb4[];
extern char data_ov009_02216bba[];
extern void *Ov003FxList_Dtor(void *p);
extern void *SndMgr_PlayAtPitch(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);

static inline void Ov009_SpawnSparks(Ov009ActVt_02216dcc *self) {
    EffectObj *e;
    Rot16 r;
    SndMgr_PlayAtPitch(data_02097e4c, 0x54, &self->pos, 3);
    e = Effect_SpawnId(0x25d, &self->pos);
    e->AddPosXYZ(0, 0x1333, 0);
    e->SetScaleAll(0xb33);
    r.y = self->rot_y + 0x6000;
    r.x = 0x800;
    r.z = 0;
    e->SetRot(&r);
    e = Effect_SpawnId(0x25d, &self->pos);
    e->AddPosXYZ(0, 0x1333, 0);
    e->SetScaleAll(0xb33);
    r.y = self->rot_y - 0x6000;
    r.x = 0x800;
    r.z = 0;
    e->SetRot(&r);
}

void Ov009ActVt_02216dcc_StateAttack(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->unk_ee_2 = 0;
        self->unk_c4 = 0;
        self->unk_f0++;
    }
    Ov003Actor_StateAttack(self);
    if (self->fsm->current != 1) {
        return;
    }
    if (self->unk_f0 < 3) {
        return;
    }
    self->unk_b6 = 0x96;
    self->unk_f0 = 0;
    Ov009_SpawnSparks(self);
}

void Ov009ActVt_02216dcc_StateAttack2(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->unk_ee_2 = 1;
        self->unk_f0 = 0;
        self->unk_c4 = 0;
        if (self->unk_f2 != 0) {
            Model0218fe1c_SetAnim(self->model, data_ov009_02216bb4, 0x400, 0);
            Model0218fe1c_SetAnimFrame(self->model, 0x2c000);
        }
    }
    Ov003Actor_StateAttack(self);
    if (self->fsm->current != 1) {
        return;
    }
    self->unk_f2++;
    if (self->unk_f2 < 3) {
        History_SetState(self->fsm, 0x10, 0);
        return;
    }
    self->unk_f2 = 0;
    self->unk_b6 = 0x96;
    Model0218fe1c_SetAnim(self->model, data_ov009_02216bba, 0x22, 0);
    Ov009_SpawnSparks(self);
}

void Ov009ActVt_02216dcc_StateAttack3(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->unk_ee_2 = 2;
        self->unk_f0 = 0;
        self->unk_f6 = 0;
        self->unk_c4 = Ov003_LookupEntry(0x3000);
    }
    if (self->unk_f6 != 0) {
        self->unk_94_1 = 0;
        self->unk_94_0 = 1;
    } else if (self->model->anim_state > 1) {
        self->unk_f6 = 1;
    }
    Ov003Actor_StateAttack(self);
}

void Ov009ActVt_02216dcc_StateDie(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->radius >>= 1;
    }
    Ov003Actor_StateDie(self);
}

void Ov009ActVt_02216dcc_StateKnockBack(Ov009ActVt_02216dcc *self) {
    self->unk_94_1 = 0;
    Ov003Actor_StateKnockBack(self);
}

Ov009ActVt_0221707c *Ov009ActVt_0221707c_DtorDelete(Ov009ActVt_0221707c *self) {
    void *saved;
    *(void **)self = &data_ov009_0221707c;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_104 != NULL) {
        void *p = self->unk_104;
        if (p != NULL) {
            Ov003FxList_Dtor(p);
            Heap_Free(p);
        }
        self->unk_104 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_0221707c *Ov009ActVt_0221707c_Dtor(Ov009ActVt_0221707c *self) {
    void *saved;
    *(void **)self = &data_ov009_0221707c;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_104 != NULL) {
        void *p = self->unk_104;
        if (p != NULL) {
            Ov003FxList_Dtor(p);
            Heap_Free(p);
        }
        self->unk_104 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022171d4 *Ov009ActVt_022171d4_Dtor(Ov009ActVt_022171d4 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_022171d4 *Ov009ActVt_022171d4_DtorDelete(Ov009ActVt_022171d4 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217128 *Ov009ActVt_02217128_Dtor(Ov009ActVt_02217128 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02217128 *Ov009ActVt_02217128_DtorDelete(Ov009ActVt_02217128 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009Act_02200b48 *Ov009Act_02200b48_Dtor(Ov009Act_02200b48 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009Act_02200b48 *Ov009Act_02200b48_DtorDelete(Ov009Act_02200b48 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216c74 *Ov009ActVt_02216c74_Dtor(Ov009ActVt_02216c74 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02216c74 *Ov009ActVt_02216c74_DtorDelete(Ov009ActVt_02216c74 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216bc8 *Ov009ActVt_02216bc8_Dtor(Ov009ActVt_02216bc8 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02216bc8 *Ov009ActVt_02216bc8_DtorDelete(Ov009ActVt_02216bc8 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_02216fd0_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_02216fd0_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov009ActVt_02216f24_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov009ActVt_02216f24_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216dcc *Ov009ActVt_02216dcc_Dtor(Ov009ActVt_02216dcc *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009ActVt_02216dcc *Ov009ActVt_02216dcc_DtorDelete(Ov009ActVt_02216dcc *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}
extern void HitSphere_Unlink_0203f2b8(void *p);

static inline void Ov009_VecSet3(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void Ov009ActVt_022178f0_Start(Ov009ActVt_022178f0 *self) {
    GroupNode *p;
    Ov003Actor_Start(self);
    self->unk_f0 = self->pos;
    self->pos.y -= 0xc000;
    self->unk_fc = self->unk_f0;
    self->pos.z += 0x18000;
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->hit != NULL) {
            void *q = self->hit;
            if (q != NULL) {
                HitSphere_Unlink_0203f2b8(q);
                Heap_Free(q);
            }
            self->hit = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_108 = 0;
    self->unk_10a = 0;
    Ov009_VecSet3(&self->unk_44->unk_0c, 0x3800, self->centerY, 0);
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
    }
    self->unk_10c = -1;
}

}
