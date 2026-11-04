#include "ov015/ov015.h"
#include "ov000/ActorMarker.h"

extern "C" {

extern char data_ov015_022132ac[];
extern char data_ov015_022132bb[];
void Ov015Obj292c_MoveByPad(Ov015Obj292c *self);
s32 SndMgr_PlayPan(void *a, s32 b, s32 c);
extern u8 Ov015Obj290_vtbl[];
void *Model0218fe1c_FreeAnims(void *a);
void *ResSet_ReleaseAll(void *a);

void Ov015Obj292c_Init(Ov015Obj292c *self) {
    self->fx = NULL;
    self->marker = NULL;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    self->unk_24.x = 0;
    self->unk_24.y = 0;
    self->unk_24.z = 0;
    self->unk_30 = 0;
}

void Ov015Obj292c_DtorBase(Ov015Obj292c *self) {
    void *saved;
    ActorMarker *o;
    if (EffectMgr_Contains(gEffectMgr, self->fx)) {
        self->fx->state = 4;
        self->fx = NULL;
    }
    HEAP_PUSH(saved);
    o = self->marker;
    if (o != NULL) {
        if (o != NULL) {
            ActorMarker_Release(o);
            Heap_Free(o);
        }
        self->marker = NULL;
    }
    HEAP_POP(saved);
}

void Ov015Obj292c_Load(Ov015Obj292c *self) {
    ResMgr_Load(data_ov015_022132ac, 7, 0);
}

int Ov015Obj292c_IsLoaded(Ov015Obj292c *self) {
    return ResMgr_IsLoaded(data_ov015_022132ac, 7);
}

BOOL Ov015Obj292c_Setup(Ov015Obj292c *self) {
    ActorMarker *q;
    self->fx = Effect3D_Create(data_ov015_022132ac, data_ov015_022132bb, 0, &self->pos);
    self->fx->unk_d4 = 3;
    self->fx->unk_54 = 0;
    self->fx->unk_50 = -0xc8000;
    self->fx->loopCount = -1;
    self->fx->unk_28 = 0;
    self->fx->speed = 0x800;
    q = (ActorMarker *)Heap_Alloc(0xa8);
    if (q != NULL) {
        ActorMarker_Init(q);
    }
    self->marker = q;
    q->show = 0;
    self->unk_30 = 0x800;
    return TRUE;
}

void func_ov015_02212250(Ov015Obj292c *self, s32 a) {
    if (a == 0) {
        Ov015Obj292c_MoveByPad(self);
    }
}

void Ov015Obj292c_Draw(Ov015Obj292c *self) {
    ActorMarker *o;
    if (self->fx != NULL) {
        const MtxFx43 *m = NNS_G3dGlbGetInvV();
        Ov015Vec w;
        Ov015Vec v;

        v.x = 0;
        v.y = 0;
        v.z = 0xa000;
        MTX_MultVec33(&v, (MtxFx33 *)m, &v);
        VEC_Add(&v, (&self->pos), &w);
        self->fx->SetPos(&w);
        self->fx->SetScale(&self->scale);
        self->fx->SetRotXYZ(0xe00, FX_Atan2(v.x, v.z), 0);
    }
    o = self->marker;
    if (o != NULL) {
        o->unk_50.x = self->unk_24.x;
        o->unk_50.y = self->unk_24.y;
        o->unk_50.z = self->unk_24.z;
        ActorMarker_Update(self->marker);
        ActorMarker_Draw(self->marker);
    }
}

static inline BOOL Ov015_MarkerShown(ActorMarker *m) {
    return m->show == 1 ? TRUE : FALSE;
}

void Ov015Obj292c_ShowMarker(Ov015Obj292c *self) {
    ActorMarker *o = self->marker;
    if (o == NULL) {
        return;
    }
    if (Ov015_MarkerShown(o)) {
        return;
    }
    ActorMarker_SetKind(o, 4);
    self->marker->show = 1;
    SndMgr_PlayPan(gSndMgr, 0xe, 5);
    if (self->fx != NULL) {
        self->fx->speed = 0x2000;
    }
}

void Ov015Obj292c_HideMarker(Ov015Obj292c *self) {
    ActorMarker *o = self->marker;
    if (o == NULL) {
        return;
    }
    if (!Ov015_MarkerShown(o)) {
        return;
    }
    o->show = 0;
    SndMgr_PlayPan(gSndMgr, 0x1f, -3);
    if (self->fx != NULL) {
        self->fx->speed = 0x800;
    }
}

void Ov015Obj292c_MoveByPad(Ov015Obj292c *self) {
    u16 pad = gPad->cur;
    if (pad & 0x20) {
        self->pos.x -= self->unk_30;
        if (self->pos.x < -0x32000) self->pos.x = -0x32000;
    } else if (pad & 0x10) {
        self->pos.x += self->unk_30;
        if (self->pos.x > 0x32000) self->pos.x = 0x32000;
    }
    if (pad & 0x40) {
        self->pos.z -= self->unk_30;
        if (self->pos.z < -0x8c000) self->pos.z = -0x8c000;
    } else if (pad & 0x80) {
        self->pos.z += self->unk_30;
        if (self->pos.z > -0x4b000) self->pos.z = -0x4b000;
    }
}

BOOL Ov015Obj290_IsDone(Ov015Obj290 *self) {
    return self->step == 4 ? TRUE : FALSE;
}

void *Ov015Obj290_Dtor(Ov015Obj290 *self) {
    SET_VT(self, Ov015Obj290_vtbl);
    Model0218fe1c_FreeAnims(&self->model);
    ResSet_ReleaseAll(&self->res);
    return self;
}

}
