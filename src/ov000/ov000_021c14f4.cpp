#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ActorMarker.h"

typedef struct {
    u8 pad[0x428];
    s32 a;
    u8 pad2[0xc];
    s32 b;
    s32 c;
} CamSub_021c14f4;

typedef struct {
    u8 pad[0x400];
    CamSub_021c14f4 sub;
} Cam_021c14f4;

typedef struct {
    u8 pad[0x1ec];
    Cam_021c14f4 cam;
} Gfx_021c14f4;

extern "C" {
extern Gfx_021c14f4 *gGfxSys;
typedef struct G3dGlb14f4 {
    u32 cmd0;
    u32 mtxmode;
    MtxFx44 projMtx;
    u32 cmd1;
    MtxFx43 cameraMtx;
} G3dGlb14f4;
extern G3dGlb14f4 NNS_G3dGlb;
extern char data_ov000_021cc929[];
void func_ov000_021c14dc(void *self);
void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
void *ResSet_ReleaseAll(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void *Model0218fe1c_Init(void *p);
BOOL Model0218fe1c_SetRes(void *m, void *res, u8 mode, s32 e);
BOOL Model0218fe1c_SetAnim(void *m, const char *name, s32 blend, s32 force);
void Model0218fe1c_SetLoop(void *m);
void Model0218fe1c_UpdateAnim(void *m, s32 a);

static inline s32 Mul_021c14f4(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 CalcSub_021c14f4(CamSub_021c14f4 *s, s32 q) {
    s32 r = q - 0x1000;
    r = LO_FX_MUL(r, s->c);
    return FX_Div(r - s->b, s->a);
}

void ActorMarker_UpdateKind0b(ActorMarker3D *self) {
    BOOL ok = FALSE;

    switch (self->work.state) {
    case 0:
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    case 5: {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->unk_8c != NULL) {
            void *p = self->unk_8c;
            if (p != NULL) {
                ResSet_ReleaseAll(p);
                Heap_Free(p);
            }
            self->unk_8c = NULL;
        }
        LO_HEAP_POP(saved);
        LO_HEAP_PUSH(saved);
        if (self->unk_90 != NULL) {
            void *p = self->unk_90;
            if (p != NULL) {
                Model0218fe1c_FreeAnims(p);
                Heap_Free(p);
            }
            self->unk_90 = NULL;
        }
        LO_HEAP_POP(saved);
        break;
    }
    case 1: {
        ActorRes *res = self->res;
        void *m;
        Model0218fe1c *model;
        self->res = NULL;
        self->unk_8c = res;
        m = Heap_Alloc(0xe8);
        if (m != NULL) {
            m = Model0218fe1c_Init(m);
        }
        self->unk_90 = (Model0218fe1c *)m;
        Model0218fe1c_SetRes(m, self->unk_8c, 0, 1);
        Model0218fe1c_SetAnim(self->unk_90, data_ov000_021cc929, 0, 1);
        self->unk_90->actor_id = 0;
        model = self->unk_90;
        NNS_G3dRenderObjSetInitFunc(model->renderObj, (void *)func_ov000_021c14dc);
        model->clearInit = 0;
        Model0218fe1c_SetLoop(self->unk_90);
        self->work.state = 4;
    }
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (!(self->show == 1 ? TRUE : ok)) {
            return;
        }
        if (!(self->change == 1 ? TRUE : FALSE)) {
            self->work.state = 10;
        }
        break;
    case 10: {
        VecFx32 v;
        VecFx32 out;
        MtxFx44 *proj;
        s32 a;
        s32 b;
        s32 q;
        if (ActorMarker_UpdateFade(self, 0x6000)) {
            return;
        }
        v.x = self->unk_50.x;
        v.y = self->unk_50.y;
        v.z = self->unk_50.z;
        ActorMarker_UpdateScreenPos(self, &v);
        proj = &NNS_G3dGlb.projMtx;
        MTX_MultVec43(&v, &NNS_G3dGlb.cameraMtx, &out);
        out.z += 0x3000;
        a = Mul_021c14f4(out.z, -0x1000);
        b = LO_FX_MUL(LFLD(s32, proj, 0x28), out.z) + proj->_32;
        q = FX_Div(b + a, a << 1);
        self->work.z = CalcSub_021c14f4(&gGfxSys->cam.sub, Mul_021c14f4(q, 0x2000));
        Model0218fe1c_UpdateAnim(self->unk_90, 0x1000);
        break;
    }
    }
}
}
