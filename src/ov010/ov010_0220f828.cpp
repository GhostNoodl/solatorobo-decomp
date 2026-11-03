#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"

// A header's zero rotation and vector, plus copies made at startup, next to this TU's effect
// names and the pointers to them. Other functions read the first pointer, an offset, the zero
// vector and the rotation copy.
// The functions of 0x021fff80..0x0220166c (six files, merged in round dtB, each in its own namespace)
// are part of this TU: they read its name pointers and vectors through the section base plus an
// offset, and now name them (data_ov010_0220ef6c/ef70/ef74, the static sinit copy 0x0220fd90)
// instead of FLD views of data_ov010_0220ef68/fd70.
extern const char *const data_ov010_0220ef68;
extern const VecFx32 data_ov010_0220ef80;
extern const VecFx32 data_ov010_0220ef8c;
extern const VecFx16 data_ov010_0220fd70;
extern char data_ov010_0220fd76[];
extern char data_ov010_0220fd82[];
extern char data_ov010_0220fd9c[];
extern char data_ov010_0220fdab[];
static const char *const data_ov010_0220ef74 = data_ov010_0220fdab;
static const char *const data_ov010_0220ef70 = data_ov010_0220fd82;
static const char *const data_ov010_0220ef6c = data_ov010_0220fd76;
const char *const data_ov010_0220ef68 = data_ov010_0220fd9c;
static const VecFx16 data_ov010_0220ef78 = {0, 0, 0};
const VecFx32 data_ov010_0220ef80 = {0, FX32_ONE, 0};
const VecFx32 data_ov010_0220ef8c = {0, 0, 0};
const VecFx16 data_ov010_0220fd70 = data_ov010_0220ef78;
char data_ov010_0220fd76[] = "ef3di1cas10";
char data_ov010_0220fd82[] = "ef3di1cas11";
static const VecFx32 data_ov010_0220fd90 = data_ov010_0220ef8c;

// ---- merged from ov010_021fff80.cpp
namespace m_021fff80 {
struct Ov010Rot {
    u16 v[3];
};

struct Ov010Toggle {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};


extern "C" {

extern const VecFx32 data_ov010_0220ec80;
extern const VecFx32 data_ov010_0220ec74;
extern void Obj021984c8_UpdatePos(void *a, s32 b, s32 c);
extern void ActorSub48_UpdatePos(void *a, s32 b, s32 c);

static inline void Ov010_SetSky(void) {
    FieldState *g = gSceneCmd;
    g->cam.unk_dc.x = 0;
    g->cam.unk_dc.y = 0x5580;
    g->cam.unk_dc.z = 0;
    g->cam.unk_da_0 = 1;
    g = gSceneCmd;
    g->cam.unk_f4 = 0x5c00;
    g->cam.unk_da_2 = 2;
}

BOOL Ov010Vt_0220fcac_Init(Ov010Toggle *o) {
    o->b0 = 1;
    o->b1 = 0;
    return TRUE;
}

void Ov010ActorBase_UpdateSub44(Actor *self) {
    if (self->unk_44 != NULL) {
        Obj021984c8_UpdatePos(self->unk_44, 0, 0);
    }
}

void Ov010Actor_UpdateHit(Ov003Actor *self) {
    if (self->hit != NULL) {
        ActorSub48_UpdatePos(self->hit, 0, 0);
    }
}

void Ov010ActorBase_UpdateMode3(void) {
}

void func_ov010_021fffe4(void) {
}

void Ov010Actor_State25(void) {
}

void Ov010Actor_State24(void) {
}

void Ov010Actor_State23(void) {
}

void Ov010Actor_State22(void) {
}

void Ov010Actor_State21(void) {
}

void Ov010Actor_State16(Ov003Actor *self) {
    self->vfunc_54();
}

void Ov010Actor_Shoot2(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void func_ov010_02200030(void) {
}

void Ov010Vt_0220fcac_Dtor(void) {
}

void Ov010Vt_0220fc8c_Dtor(void) {
}

void Ov010State3_Dtor(void) {
}

void Ov010Shake_Dtor(void) {
}

void Ov010Wobble_Dtor(void) {
}

BOOL Ov010FxObj_Init(Ov010FxObj *o, u16 a, u16 b, u8 c, u16 d) {
    o->b0 = 1;
    o->b1 = 0;
    o->unk_01 = c;
    o->unk_02 = b;
    o->unk_04 = d;
    o->unk_06 = 0;
    o->unk_08 = 0;
    o->unk_0a = 0;
    o->timer = 0;
    o->rx = 0;
    o->ry = 0;
    o->targetId = a;
    o->fx0 = 0;
    o->fx1 = 0;
    o->fx2 = 0;
    o->unk_20 = 0;
    o->pos = data_ov010_0220ef8c;
    Ov003ActorSub40_ForceState(&o->st, 0);
    return TRUE;
}

}


struct Ov010FxRot {
    u16 x;
    u16 y;
    u16 z;
};

extern "C" {

extern void *gActorMgr;
extern BOOL History_SetState(void *p, s32 a, s32 b);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Actor *Obj021984c8_GetActor(void *hit);
extern s32 func_ov000_0219a5c8(Actor *self, u16 mask, VecFx32 *pos, Ov010FxRot *rot, s32 r, s32 a, VecFx32 **list);
extern BOOL Hit_Apply(void *hit, void *a, void *b, s32 c, u8 d, const VecFx32 *pos, s16 h, s32 i, s32 scale);

static inline s32 Ov010g_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline Actor *Ov010g_Find(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline BOOL Ov010g_Idle(const Ov010FxObj *o) {
    BOOL r = TRUE;
    if (o->b0 && o->st.current != 0) {
        r = FALSE;
    }
    return r;
}

void Ov010FxObj_Update(Ov010FxObj *o) {
    if (!o->b0) {
        return;
    }
    if (Ov010g_Idle(o)) {
        return;
    }
    o->unk_20 = 0;
    if (o->st.current == 1) {
        switch (o->st.st) {
        case 0: {
            const char *m = data_ov010_0220ef68;
            EffectObj *e;
            e = Effect3D_Create(m, data_ov010_0220ef70, 0, &o->pos);
            e->unk_28 = 0;
            e->loopCount = -1;
            o->fx0 = e->id;
            e = Effect3D_Create(m, data_ov010_0220ef6c, 0, &o->pos);
            e->unk_28 = 0;
            e->loopCount = -1;
            o->fx1 = e->id;
            o->unk_08 = 0x80;
            o->st.st = 0xa;
            break;
        }
        case 0xa: {
            s32 v;
            s32 t;
            Actor *a;
            o->unk_08 += (s16)Ov010g_FxMul(o->unk_06 - o->unk_08, 0x4cd);
            v = o->unk_08;
            o->unk_08 = (v > o->unk_06) ? o->unk_06 : ((v < 0) ? 0 : v);
            t = o->timer - 1;
            if (t > 0xffff) {
                t = 0xffff;
            } else if (t < 0) {
                t = 0;
            }
            o->timer = t;
            a = Ov010g_Find(o->targetId);
            if (a != NULL) {
                VecFx32 *list[32];
                VecFx32 p;
                Ov010FxRot rot = {0, 0, 0};
                s32 n;
                s32 j;
                rot.x = o->rx + 0x4000;
                rot.y = o->ry;
                n = func_ov000_0219a5c8(a, o->unk_04, &o->pos, &rot, Ov010_FxMul(o->unk_08, 0x500), Ov010_FxMul(o->unk_0a, 0xf000), list);
                if (n > 0) {
                    Actor *b;
                    const char *m3 = data_ov010_0220ef74;
                    const char *m0 = data_ov010_0220ef68;
                    j = 0;
                    do {
                        if (list[j] == NULL) {
                            continue;
                        }
                        if (!Hit_Apply(list[j], a, a, o->unk_02, o->unk_01, &data_ov010_0220ef8c, -1, o->unk_06, 0x1000)) {
                            continue;
                        }
                        b = Obj021984c8_GetActor(list[j]);
                        if (b == NULL) {
                            continue;
                        }
                        if (b->targetObj != NULL && b->targetObj->type != 0xb) {
                            continue;
                        }
                        p = *list[j];
                        if (b->unk_93_5) {
                            EffectObj *e = Effect_SpawnId(0x327, &p);
                            e->SetScaleAll(b->radius << 1);
                        } else {
                            EffectObj *e = EffectGroup_Create(m0, m3, &p);
                            e->SetScaleXYZ(o->unk_06, o->unk_06, o->unk_06);
                        }
                    } while (++j < n);
                }
            }
            if (!o->b1 && o->timer == 0) {
                o->st.st = 0x64;
            }
            break;
        }
        case 0x64:
            History_SetState(&o->st, 2, 1);
            break;
        }
    } else if (o->st.current == 2) {
        switch (o->st.st) {
        case 0:
        case 1:
            if (o->st.st == 0) {
                o->unk_20 = 1;
                o->st.st = 1;
            }
            o->unk_08 = Ov010g_FxMul(o->unk_08, 0xb33);
            if (o->unk_08 < 0x80) {
                o->unk_08 = 0;
                EffectMgr_Kill(gEffectMgr, o->fx0);
                EffectMgr_Kill(gEffectMgr, o->fx1);
                o->st.st = 0x14;
            }
            break;
        case 0xa: {
            EffectObj *e = Effect_SpawnId(0x25d, &o->pos);
            e->SetPos(&o->pos);
            e->SetScaleXYZ(o->unk_06, o->unk_06, o->unk_0a);
            e->SetRotXYZ(0, o->ry, 0);
            o->fx2 = e->id;
            o->st.st = 0xb;
            break;
        }
        case 0xb:
            if (Effect_Find_020657b0(gEffectMgr, o->fx2) == NULL) {
                o->st.st = 0x14;
            }
            break;
        case 0x14:
            EffectMgr_StopLoop(gEffectMgr, o->fx0);
            EffectMgr_StopLoop(gEffectMgr, o->fx1);
            EffectMgr_StopLoop(gEffectMgr, o->fx2);
            o->fx0 = 0;
            o->fx1 = 0;
            o->fx2 = 0;
            History_SetState(&o->st, 0, 1);
            break;
        }
    }
    {
    s32 h[2];
    u32 i;
    h[0] = o->fx0;
    h[1] = o->fx1;
    for (i = 0; i < 2; i++) {
        EffectObj *e = Effect_Find_020657b0(gEffectMgr, h[i]);
        if (e != NULL) {
            e->SetPos(&o->pos);
            e->SetScaleXYZ(o->unk_08, o->unk_08, o->unk_0a);
            e->SetRotXYZ(o->rx, o->ry, 0);
        }
    }
    }
}

}
}  // namespace m_021fff80

// ---- merged from ov010_02200670.cpp
namespace m_02200670 {
extern "C" {

extern BOOL History_SetState(void *a, s32 b, s32 c);
extern void *History_Init(void *p);
extern void Ov010BeamSet_Release(Ov010BeamSet *p);
BOOL Ov010Beam_Init(Ov010Beam *o, u16 a, u16 b, u8 c, u16 d);

void Ov010FxObj_Start(Ov010FxObj *o, const VecFx32 *v, u16 a, u16 b, s16 c, s16 d, u8 e, u16 g) {
    if (!o->b0) {
        return;
    }
    if (o->st.current != 0) {
        return;
    }
    o->b1 = e;
    o->unk_06 = c;
    o->unk_08 = 0;
    o->unk_0a = d;
    o->timer = g;
    o->rx = a;
    o->ry = b;
    o->fx0 = 0;
    o->fx1 = 0;
    o->fx2 = 0;
    o->pos = *v;
    Ov003ActorSub40_ForceState(&o->st, 1);
}

BOOL Ov010Beam_Init(Ov010Beam *o, u16 a, u16 b, u8 c, u16 d) {
    o->on = 1;
    o->unk_01 = 0;
    o->unk_02 = c;
    o->unk_04 = a;
    o->unk_06 = b;
    o->unk_08 = d;
    o->unk_0a = 0;
    o->unk_0c = 0;
    o->len = 0;
    o->rx = 0;
    o->ry = 0;
    o->alpha = 0;
    o->mode = 0;
    o->pos = data_ov010_0220fd90;
    Ov003ActorSub40_ForceState(&o->st, 0);
    o->st.timer = 0;
    History_SetState(&o->st, 5, 0);
    return TRUE;
}

extern void *gSndMgr;
extern BOOL Ov010FxObj_Init(Ov010FxObj *o, u16 a, u16 b, u8 c, u16 d);
extern BOOL Ov010Beam_FadeIn(Ov010Beam *o);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, void *c, s32 d);
extern void Ov010FxObj_Update(Ov010FxObj *o);

static inline BOOL Ov010Beam_IsDone(Ov010FxObj *s) {
    BOOL r = TRUE;
    if (s->b0 && s->st.current != 0) {
        r = FALSE;
    }
    return r;
}

void Ov010Beam_Update(Ov010Beam *o) {
    s32 k;
    if (o->on == 0) {
        return;
    }
    o->mode = 0;
    switch (o->st.current) {
    case 5:
        o->alpha = 0;
        break;
    case 0:
        if (o->fx.b0) {
            o->fx.b0 = 0;
            EffectMgr_Kill(gEffectMgr, o->fx.fx0);
            EffectMgr_Kill(gEffectMgr, o->fx.fx1);
            EffectMgr_Kill(gEffectMgr, o->fx.fx2);
            o->fx.fx0 = 0;
            o->fx.fx1 = 0;
            o->fx.fx2 = 0;
        }
        Ov010FxObj_Init(&o->fx, o->unk_04, o->unk_06, o->unk_02, o->unk_08);
        History_SetState(&o->st, 1, 0);
        break;
    case 1:
        if (Ov010Beam_FadeIn(o)) {
            History_SetState(&o->st, 2, 0);
        }
        break;
    case 2:
        o->st.timer++;
        if (o->st.timer > 10) {
            o->st.timer = 0;
            History_SetState(&o->st, 3, 0);
        }
        break;
    case 3:
        if (o->st.st == 0) {
            o->mode = 1;
            Ov010FxObj_Start(&o->fx, &o->pos, o->rx, o->ry, o->unk_0c, o->len, 0, o->unk_0a);
            if (o->unk_01 != 0) {
                FieldState *g = gSceneCmd;
                g->cam.base.flags |= 0x1c;
                g->cam.base.shakeTime = 0xf;
                g->cam.base.shakeLen = 10;
                g->cam.base.shakeCur = 10;
                SndMgr_PlayAtPitch(gSndMgr, 0x5c, &o->pos, 5);
            }
            o->st.st++;
        } else if (Ov010Beam_IsDone(&o->fx)) {
            o->mode = 2;
            History_SetState(&o->st, 4, 0);
        }
        break;
    case 4:
        if (o->fx.b0 && o->fx.st.current == 1) {
            Ov003ActorSub40_ForceState(&o->fx.st, 2);
        }
        History_SetState(&o->st, 5, 0);
        break;
    }
    k = 0;
    if (o->fx.b0) {
        if (!Ov010Beam_IsDone(&o->fx)) {
            k = o->fx.unk_20;
        }
    }
    if (k == 1) {
        o->mode = 2;
    }
    Ov010FxObj_Update(&o->fx);
}

extern u8 data_020928b4[];
extern u8 NNS_G3dGlb[];
extern void NNS_G3dGlbSetBaseTrans(VecFx32 *v);
extern void NNS_G3dGlbSetBaseScale(VecFx32 *v);
extern void NNS_G3dGlbFlushVP(void);
extern void NNS_G3dGeBufferOP_N(s32 cmd, const void *data, s32 n);
extern u8 Gfx3DState_NextPolyId(void *p);
extern void NNS_G3dGeFlushBuffer(void);

static inline void Ov010_G3End(void) {
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

}
}  // namespace m_02200670

// ---- merged from ov010_02200a00.cpp
namespace m_02200a00 {
#include "nnsys/g3d.h"

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);

void Ov010Beam_Draw(Ov010Beam *self) {
    MtxFx33 m;
    VecFx32 v;
    MtxFx33 rx;
    MtxFx33 ry;
    VecFx32 s;
    u32 alpha;
    if (self->on == 0) {
        return;
    }
    alpha = (self->alpha >> 12) & 0xff;
    if (alpha == 0) {
        return;
    }
    MTX_Identity33(&m);
    NNS_G3dGlbSetBaseRot(&m);
    VEC_Set(&v, 0, 0, 0);
    NNS_G3dGlbSetBaseTrans(&v);
    VEC_Set(&v, FX32_ONE, FX32_ONE, FX32_ONE);
    NNS_G3dGlbSetBaseScale(&v);
    NNS_G3dGlbFlushVP();
    NNS_G3dGeMtxMode(GX_MTXMODE_POSITION_VECTOR);
    NNS_G3dGePushMtx();
    NNS_G3dGeIdentity();
    NNS_G3dGeTranslateVec(&self->pos);
    MTX_RotX33(&rx, FX_SinIdx(self->rx), FX_CosIdx(self->rx));
    MTX_RotY33(&ry, FX_SinIdx(self->ry), FX_CosIdx(self->ry));
    NNS_G3dGeMultMtx33(&ry);
    NNS_G3dGeMultMtx33(&rx);
    VEC_Set(&s, FX32_ONE, FX32_ONE, FX_Mul(self->len, 0xf000));
    NNS_G3dGeScaleVec(&s);
    NNS_G3dGePolygonAttr(0, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, Gfx3DState_NextPolyId(gGfxSys->unk_8b0), alpha, 0);
    NNS_G3dGeTexImageParam(GX_TEXFMT_NONE, GX_TEXGEN_NONE, GX_TEXSIZE_S8, GX_TEXSIZE_T8, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_TRNS, 0);
    NNS_G3dGeBegin(GX_BEGIN_TRIANGLES);
    NNS_G3dGeColor(GX_RGB(31, 0, 0));
    NNS_G3dGeVtx(0, 0, 0);
    NNS_G3dGeVtxXY(0, 0);
    NNS_G3dGeVtx(0, 0, FX16_ONE);
    NNS_G3dGeEnd();
    NNS_G3dGePopMtx(1);
    NNS_G3dGeFlushBuffer();
}

}
}  // namespace m_02200a00

// ---- merged from ov010_02200c98.cpp
namespace m_02200c98 {
extern "C" {

static inline s32 Ov010_ClampS(s32 x, s32 lo, s32 hi) {
    if (x > hi) {
        return hi;
    }
    if (x < lo) {
        return lo;
    }
    return x;
}

BOOL Ov010Beam_FadeIn(Ov010Beam *o) {
    BOOL r = FALSE;
    s32 v;
    switch (o->st.st) {
    case 0:
        o->alpha = 0;
        o->st.timer = 0;
        o->st.st = 1;
    case 1:
        if (o->st.timer < 9) {
            o->alpha += 0x238e;
            v = Ov010_ClampS(o->alpha, 0, 0x14000);
            o->alpha = v;
            o->st.timer++;
            break;
        }
        o->st.st = 2;
    case 2:
        if (o->st.timer < 0xb) {
            v = 0x14000;
            o->alpha = v;
            o->st.timer = ((const Ov010Beam *)o)->st.timer + 1;
            break;
        }
        o->st.st = 3;
    case 3:
        if (o->st.timer < 0x14) {
            o->alpha -= 0x238e;
            v = Ov010_ClampS(o->alpha, 0, 0x14000);
            o->alpha = v;
            o->st.timer++;
            break;
        }
        o->st.timer = 0;
        o->st.st = 4;
        break;
    case 4:
        o->alpha = 0;
        r = TRUE;
        break;
    }
    return r;
}

}
}  // namespace m_02200c98

// ---- merged from ov010_02200d94.cpp
namespace m_02200d94 {
extern "C" {

extern void *History_Init(void *p);
extern void Ov010BeamSet_Release(Ov010BeamSet *p);
extern BOOL Ov010Beam_Init(Ov010Beam *o, u16 a, u16 b, u8 c, u16 d);

static inline s32 Ov010_ClampS(s32 x, s32 lo, s32 hi) {
    if (x > hi) {
        return hi;
    }
    if (x < lo) {
        return lo;
    }
    return x;
}

struct Ov010BeamSt {
    u16 state;
    u16 timer;
};

Ov010BeamSet *Ov010BeamSet_Ctor(Ov010BeamSet *o) {
    o->flags.b0 = 0;
    History_Init(&o->st);
    return o;
}

Ov010BeamSet *Ov010BeamSet_Dtor(Ov010BeamSet *o) {
    Ov010BeamSet_Release(o);
    return o;
}

static inline Ov010BeamNode *Ov010Beam_New(void) {
    Ov010BeamNode *n = (Ov010BeamNode *)Heap_Alloc(0x8c);
    if (n != NULL) {
        n->beam.on = 0;
        n->beam.fx.b0 = 0;
        History_Init(&n->beam.fx.st);
        History_Init(&n->beam.st);
    }
    return n;
}

static inline Ov010BeamNode *Ov010List_Push(Ov010BeamNode *head, Ov010BeamNode *n) {
    if (n != NULL) {
        n->next = head;
        return n;
    }
    return head;
}

BOOL Ov010BeamSet_Init(Ov010BeamSet *o, u16 a, u16 b, u8 c, u16 d) {
    s32 i;
    o->flags.b0 = 1;
    o->unk_01 = c;
    o->unk_02 = a;
    o->unk_04 = b;
    o->unk_06 = d;
    o->unk_08 = 0;
    o->unk_0a = 0;
    o->unk_0c = 0;
    o->beams = NULL;
    o->unk_14 = data_ov010_0220fd90;
    o->unk_20 = o->unk_14;
    Ov003ActorSub40_ForceState(&o->st, 0);
    o->st.st = 0x65;
    for (i = 0; i < 3; i++) {
        Ov010BeamNode *n = Ov010Beam_New();
        Ov010Beam_Init(&n->beam, a, b, c, d);
        n->next = NULL;
        o->beams = Ov010List_Push(o->beams, n);
        if (i == 0) {
            n->beam.unk_01 = 1;
        }
    }
    return TRUE;
}

}
}  // namespace m_02200d94

// ---- merged from ov010_02200ee0.cpp
namespace m_02200ee0 {
struct Ov010PlFlags {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 18;
};

extern "C" {

extern BOOL History_SetState(void *a, s32 b, s32 c);
extern void Ov010Beam_Draw(Ov010Beam *o);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);

static inline void Ov010Fx_Free(Ov010FxObj *s) {
    if (s->b0) {
        s->b0 = 0;
        EffectMgr_Kill(gEffectMgr, s->fx0);
        EffectMgr_Kill(gEffectMgr, s->fx1);
        EffectMgr_Kill(gEffectMgr, s->fx2);
        s->fx0 = 0;
        s->fx1 = 0;
        s->fx2 = 0;
    }
}

static inline void Ov010Beam_Reset(Ov010Beam *b) {
    if (b->on != 0) {
        Ov010Fx_Free(&b->fx);
        b->on = 0;
    }
}

void Ov010BeamSet_Release(Ov010BeamSet *o) {
    Ov010BeamNode *next;
    Ov010BeamNode *n;
    if (!o->flags.b0) {
        return;
    }
    for (n = o->beams; n != NULL; n = next) {
        void *saved;
        next = n->next;
        Ov010Beam_Reset(&n->beam);
        saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (n != NULL) {
            if (n != NULL) {
                Ov010Beam_Reset(&n->beam);
                Ov010Fx_Free(&n->beam.fx);
                Heap_Free(n);
            }
        }
        gSysState->cur = saved;
    }
    o->beams = NULL;
    o->flags.b0 = 0;
}

}

// Ov010BeamSet_Update (round raD). Ov010Beam_Idle sets its flag from the mode compare (`r = b[0x7f] == 5`)
// rather than clearing it under an && test: the compare's value is a late temporary, numbered below the CSE'd
// state-byte reads, which is the colouring the ROM has in the beam walks. Each beam register update reads the
// old value into `cur` first, which puts GetB's value first in the add.
extern "C" {

extern s32 Rand_UpTo(s32 max);
extern s32 Rand_PlusMinus(s32 n);
extern s32 Rand_Fx(void);
extern u16 Ov003Vec_YawTo(VecFx32 *a, VecFx32 *b);
extern u16 Ov003Vec_Pitch(VecFx32 *v);
extern u16 Ov003Vec_Yaw(VecFx32 *v);
extern void Ov010Beam_Update(Ov010Beam *p);

static inline s32 Ov010k_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

// Idle/Mode/GetRx/GetRy read `on` through a const view: as b->on they change the code of
// Ov010BeamSet_Update (SetRx/SetRy take the member).
static inline u8 Ov010Beam_On(const Ov010Beam *b) {
    return b->on;
}

static inline BOOL Ov010Beam_Idle(Ov010Beam *b) {
    BOOL r = TRUE;
    if (Ov010Beam_On(b) != 0) {
        r = b->st.current == 5;
    }
    return r;
}

static inline s32 Ov010Beam_Mode(Ov010Beam *b) {
    s32 r = 0;
    if (Ov010Beam_On(b) != 0) {
        r = b->mode;
    }
    return r;
}

static inline u16 Ov010Beam_GetRx(Ov010Beam *b) {
    u16 r = 0;
    if (Ov010Beam_On(b) != 0 && !Ov010Beam_Idle(b)) {
        r = b->rx;
    }
    return r;
}

static inline void Ov010Beam_SetRx(Ov010Beam *b, u16 v) {
    if (b->on != 0 && !Ov010Beam_Idle(b)) {
        b->rx = v;
        if (b->fx.b0) {
            b->fx.rx = v;
        }
    }
}

static inline u16 Ov010Beam_GetRy(Ov010Beam *b) {
    u16 r = 0;
    if (Ov010Beam_On(b) != 0 && !Ov010Beam_Idle(b)) {
        r = b->ry;
    }
    return r;
}

static inline void Ov010Beam_SetRy(Ov010Beam *b, u16 v) {
    if (b->on != 0 && !Ov010Beam_Idle(b)) {
        b->ry = v;
        if (b->fx.b0) {
            b->fx.ry = v;
        }
    }
}

void Ov010BeamSet_Update(Ov010BeamSet *self) {
    BOOL all;
    u16 ang;
    Ov010BeamNode *n;
    Ov010BeamNode *n1;
    Ov010BeamNode *n2;
    VecFx32 tmp;
    VecFx32 res;
    VecFx32 d;
    VecFx32 v;
    if (!self->flags.b0) {
        return;
    }
    switch (self->st.st) {
    case 0:
        self->unk_0a = 0;
        self->unk_0c = 0;
        self->st.st = 10;
        break;
    case 10: {
        Ov010BeamNode *last = NULL;
        for (n1 = self->beams; n1 != NULL; n1 = n1->next) {
            if (Ov010Beam_Idle(&n1->beam)) {
                last = n1;
            }
        }
        if (last != NULL) {
            BOOL flag = self->st.timer % 3 == 0;
            s32 len;
            u16 ry;
            u16 rx;
            u16 t;
            if ((s32)self->unk_0a >= 3) {
                u16 r = Rand_UpTo(2);
                self->unk_0a = 0;
                self->unk_0c = r;
                self->unk_0a++;
            } else {
                self->unk_0c++;
                if ((s32)self->unk_0c >= 3) {
                    self->unk_0c = 0;
                }
                self->unk_0a++;
            }
            {
                u16 c = self->unk_0c;
                ang = c * 0x5555 + Rand_UpTo(0x5555);
            }
            if (flag) {
                len = Ov010k_Mul(Rand_Fx(), 0x2cd);
            } else {
                len = Ov010k_Mul(Rand_Fx(), 0xb33) + 0x4cd;
            }
            if (len > 0x1000) {
                len = 0x1000;
            } else if (len < 0) {
                len = 0;
            }
            Ov003Vec_RotateZ(&v, ang, &data_ov010_0220ef80);
            len = Ov010k_Mul(len, 0xc000);
            v.x = Ov010_FxMul(v.x, len);
            v.y = Ov010_FxMul(v.y, len);
            v.z = Ov010_FxMul(v.z, len);
            v.y = Ov010k_Mul(v.y, 0x980);
            Ov003Vec_RotateY(&v, Ov003Vec_YawTo(&self->unk_14, &self->unk_20), &v);
            OV010_BLKCPY(&tmp, &v);
            VEC_Add(&self->unk_14, &tmp, &res);
            d.x = res.x - self->unk_20.x;
            d.y = res.y - self->unk_20.y;
            d.z = res.z - self->unk_20.z;
            VEC_Normalize(&d, &d);
            ry = Ov003Vec_Pitch(&d);
            rx = Ov003Vec_Yaw(&d);
            t = Rand_UpTo(10) + 10;
            {
                s32 s = Rand_PlusMinus(2);
                s = s > 0 ? s + 0x16 : s - 0x16;
                last->unk_00 = 0;
                last->unk_02 = 0;
                last->unk_04 = 0;
                last->unk_06 = s;
            }
            if (last->beam.on != 0 && last->beam.st.current == 5) {
                last->beam.st.timer = 0;
                History_SetState(&last->beam.st, 0, 0);
                last->beam.pos.x = self->unk_20.x;
                last->beam.pos.y = self->unk_20.y;
                last->beam.pos.z = self->unk_20.z;
                last->beam.rx = ry;
                last->beam.ry = rx;
                last->beam.unk_0c = 0xc20;
                last->beam.len = 0x4000;
                last->beam.unk_0a = t;
            }
        }
        for (n2 = self->beams; n2 != NULL; n2 = n2->next) {
            Ov010Beam *b = &n2->beam;
            if (Ov010Beam_Idle(b)) {
                continue;
            }
            if (Ov010Beam_Mode(b) == 1) {
                n2->unk_00 = 1;
            } else if (Ov010Beam_Mode(b) == 2) {
                n2->unk_00 = 0;
            }
            if (n2->unk_00 != 0) {
                n2->unk_02 += 4;
                n2->unk_02 = n2->unk_02 > 0x24 ? 0x24 : n2->unk_02;
                n2->unk_04 = n2->unk_06;
            } else {
                n2->unk_02 = Ov010k_Mul(n2->unk_02 << 12, 0x1000) >> 12;
                n2->unk_04 = 0;
            }
            {
                u16 dd = 0xffff - n2->unk_02;
                u16 cur = Ov010Beam_GetRx(b);
                Ov010Beam_SetRx(b, cur + dd);
            }
            {
                u16 dd = n2->unk_04;
                u16 cur = Ov010Beam_GetRy(b);
                Ov010Beam_SetRy(b, cur + dd);
            }
        }
        if (self->unk_08 < ((const Ov010BeamSet *)self)->st.timer) {
            self->st.timer = 0;
            self->st.st = 100;
        } else {
            self->st.timer++;
        }
        break;
    }
    case 100: {
        all = TRUE;
        for (n = self->beams; n != NULL; n = n->next) {
            if (!Ov010Beam_Idle(&n->beam)) {
                all = FALSE;
            }
        }
        if (all) {
            self->st.st = 101;
        }
        break;
    }
    case 101:
        break;
    }
    for (n = self->beams; n != NULL; n = n->next) {
        Ov010Beam_Update(&n->beam);
    }
}


}
}  // namespace m_02200ee0
