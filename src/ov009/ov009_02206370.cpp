#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov009_0221707c;
extern char data_ov009_02216bb4[];
extern char data_ov009_02216bba[];
extern void *func_ov003_021da940(void *p);
extern void *func_0204a028(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern s16 *func_ov000_02191318(Model0218fe1c *m, s32 a);

static inline void Ov009_SpawnSparks(Ov009ActVt_02216dcc *self) {
    EffectObj *e;
    Rot16 r;
    func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
    e = func_02065f88(0x25d, &self->pos);
    e->AddPosXYZ(0, 0x1333, 0);
    e->SetScaleAll(0xb33);
    r.y = self->rot_y + 0x6000;
    r.x = 0x800;
    r.z = 0;
    e->SetRot(&r);
    e = func_02065f88(0x25d, &self->pos);
    e->AddPosXYZ(0, 0x1333, 0);
    e->SetScaleAll(0xb33);
    r.y = self->rot_y - 0x6000;
    r.x = 0x800;
    r.z = 0;
    e->SetRot(&r);
}

void func_ov009_02206370(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->unk_ee_2 = 0;
        self->unk_c4 = 0;
        self->unk_f0++;
    }
    func_ov003_021d452c(self);
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

void func_ov009_022064f0(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->unk_ee_2 = 1;
        self->unk_f0 = 0;
        self->unk_c4 = 0;
        if (self->unk_f2 != 0) {
            func_ov000_02190cb0(self->model, data_ov009_02216bb4, 0x400, 0);
            func_ov000_02191318(self->model, 0x2c000);
        }
    }
    func_ov003_021d452c(self);
    if (self->fsm->current != 1) {
        return;
    }
    self->unk_f2++;
    if (self->unk_f2 < 3) {
        func_ov000_02198360(self->fsm, 0x10, 0);
        return;
    }
    self->unk_f2 = 0;
    self->unk_b6 = 0x96;
    func_ov000_02190cb0(self->model, data_ov009_02216bba, 0x22, 0);
    Ov009_SpawnSparks(self);
}

void func_ov009_022066cc(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->unk_ee_2 = 2;
        self->unk_f0 = 0;
        self->unk_f6 = 0;
        self->unk_c4 = func_ov003_021d1e30(0x3000);
    }
    if (self->unk_f6 != 0) {
        self->unk_94_1 = 0;
        self->unk_94_0 = 1;
    } else if (self->model->anim_state > 1) {
        self->unk_f6 = 1;
    }
    func_ov003_021d452c(self);
}

void func_ov009_02206754(Ov009ActVt_02216dcc *self) {
    if (self->fsm->st == 0) {
        self->radius >>= 1;
    }
    func_ov003_021d6054(self);
}

void func_ov009_02206778(Ov009ActVt_02216dcc *self) {
    self->unk_94_1 = 0;
    func_ov003_021d5348(self);
}

Ov009ActVt_0221707c *Ov009ActVt_0221707c_DtorDelete(Ov009ActVt_0221707c *self) {
    void *saved;
    *(void **)self = &data_ov009_0221707c;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_104 != NULL) {
        void *p = self->unk_104;
        if (p != NULL) {
            func_ov003_021da940(p);
            Heap_Free(p);
        }
        self->unk_104 = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021d0edc(self);
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
            func_ov003_021da940(p);
            Heap_Free(p);
        }
        self->unk_104 = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_022171d4 *Ov009ActVt_022171d4_Dtor(Ov009ActVt_022171d4 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_022171d4 *Ov009ActVt_022171d4_DtorDelete(Ov009ActVt_022171d4 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02217128 *Ov009ActVt_02217128_Dtor(Ov009ActVt_02217128 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_02217128 *Ov009ActVt_02217128_DtorDelete(Ov009ActVt_02217128 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009Act_02200b48 *Ov009Act_02200b48_Dtor(Ov009Act_02200b48 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Act_02200b48 *Ov009Act_02200b48_DtorDelete(Ov009Act_02200b48 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216c74 *Ov009ActVt_02216c74_Dtor(Ov009ActVt_02216c74 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_02216c74 *Ov009ActVt_02216c74_DtorDelete(Ov009ActVt_02216c74 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216bc8 *Ov009ActVt_02216bc8_Dtor(Ov009ActVt_02216bc8 *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_02216bc8 *Ov009ActVt_02216bc8_DtorDelete(Ov009ActVt_02216bc8 *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *func_ov009_02206968(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *func_ov009_0220697c(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *func_ov009_02206998(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *func_ov009_022069ac(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov009ActVt_02216dcc *Ov009ActVt_02216dcc_Dtor(Ov009ActVt_02216dcc *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009ActVt_02216dcc *Ov009ActVt_02216dcc_DtorDelete(Ov009ActVt_02216dcc *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_0203f2b8(void *p);

struct Ov009ByteA2 {
    u8 b0 : 1;
    u8 b1 : 7;
};

static inline void Ov009_VecSet3(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void Ov009ActVt_022178f0_Start(Ov009ActVt_022178f0 *self) {
    u8 *p;
    func_ov003_021d112c(self);
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
                func_0203f2b8(q);
                Heap_Free(q);
            }
            self->hit = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_108 = 0;
    self->unk_10a = 0;
    Ov009_VecSet3(&FLD(VecFx32, self->unk_44, 0xc), 0x3800, self->centerY, 0);
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009ByteA2 *)(p + 0xa2))->b0 = 0;
    }
    self->unk_10c = -1;
}

}
