#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov010/ObjLayouts.h"

struct Ov010Sw {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05[3];
    VecFx32 unk_08;
    u16 unk_14[4];
    s32 unk_1c;
};

extern "C" {

extern u8 data_ov010_0220f220[];
extern u8 data_ov010_0220f448[];
extern u8 data_ov010_0220f298[];
extern u8 data_ov010_0220ffc4[];
extern u8 data_ov010_02210154[];
extern void *data_0214a420;
extern BOOL Ov003Sequence_HasEntries(void *p, void *d);
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void func_ov000_0218a358(void *a, const void *b, void *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern s32 FX_Div(s32 a, s32 b);
extern void func_ov010_022075bc(void *p);
extern void *Ov003Vt_021f7cd8_Dtor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void *Ov010Coll_Dtor(void *p);
extern void EffectMgr_Kill(void *a, s32 b);

static inline void Ov010_PlayIfIdle(Ov010Obj0221009c *self, void *anim, s32 n) {
    if (!Ov003Sequence_HasEntries((u8 *)self + 0x160, anim)) {
        func_ov003_021d95e8((u8 *)self + 0x160, anim, n);
    }
}

void func_ov010_02208c3c(Ov010Obj0221009c *self) {
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

BOOL func_ov010_02208d10(Ov010Obj0221009c *self, s32 *out) {
    *out = 10;
    return TRUE;
}

void func_ov010_02208d20(Ov010Obj0221009c *self, s32 *out) {
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
    self->unk_00 = data_ov010_0220ffc4;
    ((VObj *)self)->vfunc_0c();
    return self;
}

void *Ov010Vt_0220ffc4_DtorDelete(Obj02208d60 *self) {
    self->unk_00 = data_ov010_0220ffc4;
    ((VObj *)self)->vfunc_0c();
    Heap_Free(self);
    return self;
}

BOOL func_ov010_02208db8(Ov010Sw *self) {
    self->b0 = 1;
    return TRUE;
}

void func_ov010_02208dd0(Ov010Sw *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}

static inline BOOL Ov010_PlayerBusy(Robo021ca458 *p) {
    return p->unk_b24_0 ? TRUE : FALSE;
}

void func_ov010_02208de8(Ov010Sw *self) {
    Robo021ca458 *p;
    if (!self->b0) {
        return;
    }
    if ((u8 *)data_ov000_021ccd54 + 0xf4 == NULL) {
        return;
    }
    p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (Ov010_PlayerBusy(p)) {
        return;
    }
    func_ov000_0218a358((u8 *)data_ov000_021ccd54 + 0xf4, &self->unk_08, self->unk_14, self->unk_1c, 0, 0x1000, 0x1000, 1);
}

u16 func_ov010_02208e90(s32 a, s32 b) {
    s32 period = Ov010_FxMul(a, 0x3243) * 2;
    if (period == 0) {
        return 0;
    }
    while (b >= period) {
        b -= period;
    }
    return (u16)(Ov010_FxMul(FX_Div(b, period), 0xffff000) >> 12);
}

static inline void Ov010_02208f14_Body(void *self) {
    FLD(void *, self, 0) = data_ov010_02210154;
    func_ov003_021cf3fc(0);
    func_ov010_022075bc(self);
    Ov003Vt_021f7cd8_Dtor((u8 *)self + 0x1dc);
    Ov003Vt_021f7d10_Dtor((u8 *)self + 0x1b0);
    Ov010Coll_Dtor((u8 *)self + 0x174);
    func_ov003_021d8f34((u8 *)self + 0x160);
    func_ov003_021d0edc(self);
}

void *Ov010ActVt_0220ffe4_Dtor(void *self) {
    Ov010_02208f14_Body(self);
    return self;
}

void *Ov010ActVt_0220ffe4_DtorDelete(void *self) {
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

void func_ov010_02209074(void *p) {
    if (p == NULL) {
        return;
    }
    if (FLD(s32, p, 4) > 0) {
        FLD(s32, p, 4)--;
        return;
    }
    EffectMgr_Kill(data_0214a420, FLD(s32, p, 0x24));
    FLD(s32, p, 0xdc) = 0;
}

extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);
BOOL func_ov010_022090b4(s32 type, const s32 *rect, const s32 *circ, const VecFx32 *p) {
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
        b.x = circ[0];
        b.z = circ[2];
        if (Ov003Vec_DistSq(&a, &b) > Ov010_FxMul(circ[3], circ[3])) {
            r = TRUE;
        }
        break;
    }
    }
    return r;
}

}
