#include "ov011/ov011.h"

struct Ov011SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov011Spawn_Init(Ov011SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

struct Ov011Rot {
    s16 x, y, z;
};

extern "C" {

extern const u16 data_ov011_0220751c[];
s32 Rand_UpTo(s32 max);
void *Group_SpawnActor(void *mgr, Ov011SpawnDesc *d, VecFx32 *pos, Ov011Rot *rot, u16 a);
void *func_ov000_0214b670(void *p);

#pragma force_active on
void func_ov011_02205460(Ov011Act7da4 *self, u16 t, BOOL b) {
    {
    s32 m = 0x5f;
    if (b) {
        m = 200;
    }
    if (t % m == 1) {
        VecFx32 pos;
        Ov011Rot rot;
        Ov011SpawnDesc d;
        s32 r;
        u16 k;
        Ov011Obj *o;
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        rot.x = 0;
        rot.y = 0;
        rot.z = 0;
        r = Rand_UpTo(7);
        k = data_ov011_0220751c[r];
        if (b && (k == 0x409b || k == 0x409c)) {
            k = 0x409d;
        }
        Ov011Spawn_Init(&d, k);
        if ((k == 0x409b || k == 0x409c)) {
            d.unk_04[2] = 3;
        }
        d.unk_04[3] = 1;
        o = (Ov011Obj *)Group_SpawnActor(data_ov000_021ccd64, &d, &pos, &rot, 0xffff);
        if (o != NULL) {
            void *x;
            o->unk_16_0 = 1;
            x = NULL;
            if (r & 1) {
                if (self->unk_364 != NULL && self->unk_394 == 0) {
                    x = func_ov000_0214b670(self->unk_364);
                }
            } else {
                if (self->unk_368 != NULL && self->unk_394 == 0) {
                    x = func_ov000_0214b670(self->unk_368);
                }
            }
            o->unk_60 = x;
        }
    }
    }
    {
    s32 m = 0x23;
    if (b) {
        m = 0x4b;
    }
    if (t % m == 1) {
        VecFx32 pos;
        Ov011Rot rot;
        Ov011SpawnDesc d;
        Ov011Obj *o;
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        rot.x = 0;
        rot.y = 0;
        rot.z = 0;
        Ov011Spawn_Init(&d, 0x409e);
        d.unk_04[3] = 2;
        o = (Ov011Obj *)Group_SpawnActor(data_ov000_021ccd64, &d, &pos, &rot, 0xffff);
        if (o != NULL) {
            o->unk_16_0 = 1;
        }
    }
    }
}
#pragma force_active reset

void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);
void func_ov011_02205460(Ov011Act7da4 *self, u16 t, s32 c);

#pragma force_active on
void func_ov011_02205674(Ov011Act7da4 *self) {
    Ov011Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        if (st->timer > 0x12c) {
            FieldState *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            g->unk_ac = 1;
            func_ov000_02182590(&g->unk_ac);
            self->unk_40->state++;
        }
        break;
    case 1:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(st, 0x23, 0);
        }
        break;
    }
    self->unk_40->timer++;
    func_ov011_02205460(self, self->unk_40->timer, 0);
}

extern VecFx32 data_02092a50;

void func_ov011_0220576c(Ov011Act7da4 *self) {
    Ov011Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        VecFx32 v;
        Ov011Rot rot;
        Ov011SpawnDesc d;
        Ov011Obj *o;
        v.x = 0;
        v.y = -0xa000;
        v.z = -0xa000;
        Ov011_MulVec33(&v, NNS_G3dGlbGetInvV(), &v);
        VEC_Add(&v, &data_02092a50, &v);
        rot.x = 0;
        rot.y = 0;
        rot.z = 0;
        Ov011Spawn_Init(&d, 0x406a);
        d.unk_04[1] = 2;
        o = (Ov011Obj *)Group_SpawnActor(data_ov000_021ccd64, &d, &v, &rot, 0xffff);
        if (o != NULL) {
            self->unk_36c = o->id;
            o->unk_16_0 = 1;
            func_ov000_0218d46c((StageObj3D *)o, self->id, 6);
        }
        self->unk_40->state++;
    }
    case 1:
        if (self->unk_40->timer > 0x96) {
            Ov011Obj *a = Ov011_FindActor(self->unk_36c);
            FieldState *g;
            if (a != NULL) {
                a->unk_18 = 2;
            }
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            g->unk_ac = 1;
            func_ov000_02182590(&g->unk_ac);
            self->unk_40->state++;
        }
        break;
    case 2:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(st, 0x24, 0);
        }
        break;
    }
    self->unk_40->timer++;
    func_ov011_02205460(self, self->unk_40->timer, 1);
}

void func_ov011_022059f8(Ov011Act7da4 *self) {
    Ov011Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov011Obj *a;
        Ov011Sub38 *p = self->unk_38;
        p->scale.x = 0;
        p->scale.y = 0;
        p->scale.z = 0;
        self->unk_38->alpha = 0;
        self->unk_38->unk_c2_0 = 1;
        a = Ov011_FindActor(self->unk_36c);
        if (a != NULL) {
            a->unk_18 = 3;
        }
        self->unk_40->state++;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer >= 0xb4) {
            Ov011V *a = (Ov011V *)Ov011_FindActor(self->unk_36c);
            if (a != NULL) {
                a->v08();
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x3c) {
            FieldState *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            g->unk_ac = 1;
            func_ov000_02182590(&g->unk_ac);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 3:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(st, 0x22, 0);
        }
        break;
    }
}

void NNSi_G3dModifyPolygonAttrMask(void *mdl, u32 a, u32 mask);

#define OV011_F32_TO_FX32(f) ((s32)(((f) > 0) ? (f) * 4096.0f + 0.5f : (f) * 4096.0f - 0.5f))

void func_ov011_02205bc4(Ov011Act7da4 *self) {
    Ov011Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov011Sub38 *p = self->unk_38;
        p->scale.x = 0;
        p->scale.y = 0;
        p->scale.z = 0;
        self->unk_38->alpha = 0;
        self->unk_38->unk_c2_0 = 1;
        self->unk_40->state++;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer < 0xb4) {
            u16 t = self->unk_40->timer;
            s32 sc = OV011_F32_TO_FX32(0.11f * t / 180.0f) + 0x1c3;
            Ov011Sub38 *p = self->unk_38;
            p->scale.x = sc;
            p->scale.y = sc;
            p->scale.z = sc;
            self->unk_38->alpha = self->unk_40->timer * 31 / 180;
        } else {
            Ov011Sub38 *p = self->unk_38;
            p->scale.x = 0x385;
            p->scale.y = 0x385;
            p->scale.z = 0x385;
            self->unk_38->alpha = 0x1f;
            NNSi_G3dModifyPolygonAttrMask(self->unk_38->unk_04, 1, 0x1f0000);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x3c) {
            FieldState *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            g->unk_ac = 1;
            func_ov000_02182590(&g->unk_ac);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 3:
        st->timer++;
        if (st->timer > 0x78 && Ov011_GameIdle()) {
            Ov011Sub44 *q;
            self->unk_ea_6 = 0;
            q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}
#pragma force_active reset
}
