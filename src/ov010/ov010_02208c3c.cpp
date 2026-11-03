#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "ov000/FieldCam.h"
#include "ov000/ObjLayouts.h"

struct Ov010Sw {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05[3];
    VecFx32 unk_08;
    Rot16 unk_14;
    u16 unk_1a;
    s32 unk_1c;
};

extern "C" {

extern u8 data_ov010_0220f220[];
extern u8 data_ov010_0220f448[];
extern u8 data_ov010_0220f298[];
extern u8 Ov010Vt_0220ffc4_vtbl[];
extern u8 Ov010ActVt_02210154_vtbl[];
extern BOOL Ov003Sequence_HasEntries(void *p, void *d);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern s32 FX_Div(s32 a, s32 b);
extern void Ov010Obj02210154_Release(Ov010Obj02210154 *p);
extern void *Ov003Vt_021f7cd8_Dtor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);

static inline void Ov010_PlayIfIdle(Ov010Obj0221009c *self, void *anim, s32 n) {
    if (!Ov003Sequence_HasEntries(&self->seq, anim)) {
        Ov003Sequence_SetEntries(&self->seq, anim, n);
    }
}

void Ov010Obj0221009c_PlayHpAnim(Ov010Obj0221009c *self) {
    u16 *p = self->hp;
    s32 r = (p[0] << 12) / p[1];
    if (r <= 0x554) {
        Ov010_PlayIfIdle(self, data_ov010_0220f220, 0x14);
    } else if (r <= 0xccd) {
        Ov010_PlayIfIdle(self, data_ov010_0220f448, 0x27);
    } else if (r <= 0x1000) {
        Ov010_PlayIfIdle(self, data_ov010_0220f298, 0x14);
    }
}

BOOL Ov010Obj0221009c_GetType(Ov010Obj0221009c *self, s32 *out) {
    *out = 10;
    return TRUE;
}

void Ov010Obj0221009c_GetSfxIds(Ov010Obj0221009c *self, s32 *out) {
    out[0] = 0xa05;
    out[1] = 0xa06;
    out[2] = 0xa04;
    out[3] = 0xa01;
    out[5] = 0xa03;
    out[6] = 0xa01;
    out[7] = 0xa02;
    out[8] = 0xa01;
}

struct Obj02208d60 {
    void *unk_00;
};

void *Ov010Vt_0220ffc4_Dtor(Obj02208d60 *self) {
    self->unk_00 = Ov010Vt_0220ffc4_vtbl;
    ((VObj *)self)->vfunc_0c();
    return self;
}

void *Ov010Vt_0220ffc4_DtorDelete(Obj02208d60 *self) {
    self->unk_00 = Ov010Vt_0220ffc4_vtbl;
    ((VObj *)self)->vfunc_0c();
    Heap_Free(self);
    return self;
}

BOOL Ov010Sw_Init(Ov010Sw *self) {
    self->b0 = 1;
    return TRUE;
}

void Ov010Sw_Stop(Ov010Sw *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}

static inline BOOL Ov010_PlayerBusy(Robo021ca458 *p) {
    return p->unk_b24_0 ? TRUE : FALSE;
}

void Ov010Sw_Update(Ov010Sw *self) {
    Robo021ca458 *p;
    if (!self->b0) {
        return;
    }
    if (&gSceneCmd->cam == NULL) {
        return;
    }
    p = ActorMgr_FindPlayer();
    if (p == NULL) {
        return;
    }
    if (Ov010_PlayerBusy(p)) {
        return;
    }
    func_ov000_0218a358(&gSceneCmd->cam, &self->unk_08, &self->unk_14, self->unk_1c, 0, 0x1000, 0x1000, 1);
}

u16 Ov010_PhaseAngle(s32 a, s32 b) {
    s32 period = Ov010_FxMul(a, 0x3243) * 2;
    if (period == 0) {
        return 0;
    }
    while (b >= period) {
        b -= period;
    }
    return (u16)(Ov010_FxMul(FX_Div(b, period), 0xffff000) >> 12);
}

static inline void Ov010_02208f14_Body(Ov010Obj02210154 *self) {
    *(void **)self = Ov010ActVt_02210154_vtbl;
    func_ov003_021cf3fc(0);
    Ov010Obj02210154_Release(self);
    Ov003Vt_021f7cd8_Dtor(&self->timer);
    Ov003Vt_021f7d10_Dtor(&self->ticker);
    Ov010Coll_Dtor(&self->coll);
    Ov003Flag_Stop(&self->seq);
    Ov003Actor_DtorBase(self);
}

void *Ov010ActVt_0220ffe4_Dtor(Ov010Obj0220ffe4 *self) {
    Ov010_02208f14_Body(self);
    return self;
}

void *Ov010ActVt_0220ffe4_DtorDelete(Ov010Obj0220ffe4 *self) {
    Ov010_02208f14_Body(self);
    Heap_Free(self);
    return self;
}

void *Ov010ActVt_0221009c_Dtor(Ov010Obj0221009c *self) {
    Ov010_02208f14_Body(self);
    return self;
}

void *Ov010ActVt_0221009c_DtorDelete(Ov010Obj0221009c *self) {
    Ov010_02208f14_Body(self);
    Heap_Free(self);
    return self;
}

void Ov010_DelayKillFxCallback(EffectObj *p) {
    if (p == NULL) {
        return;
    }
    if (p->unk_04 > 0) {
        p->unk_04--;
        return;
    }
    EffectMgr_Kill(gEffectMgr, p->id);
    p->onUpdate = NULL;
}

extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);
BOOL Ov010_IsOutsideArea(s32 type, const s32 *rect, const Ov010Circle *circ, const VecFx32 *p) {
    BOOL r;
    switch (type) {
    case 0: {
        BOOL ox = (p->x < rect[0] || rect[2] < p->x);
        BOOL oz = (p->z < rect[1] || rect[3] < p->z);
        r = (ox || oz);
        break;
    }
    case 1: {
        VecFx32 a = {0, 0, 0};
        r = FALSE;
        a.x = p->x;
        a.z = p->z;
        VecFx32 b = {0, 0, 0};
        b.x = circ->centre.x;
        b.z = circ->centre.z;
        if (Ov003Vec_DistSq(&a, &b) > Ov010_FxMul(circ->radius, circ->radius)) {
            r = TRUE;
        }
        break;
    }
    }
    return r;
}

}
