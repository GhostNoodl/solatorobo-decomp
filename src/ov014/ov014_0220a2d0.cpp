#include "ov014/ov014.h"

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, VecFx32 *pos, Ov014Vec16 *rot, u16 a);

void Ov014Act_02209280_SpawnShot(Ov014Act_02209280 *self, u16 a) {
    VecFx32 v;
    s32 spd;
    u16 ang;
    VecFx32 pos;
    Ov014SpawnDesc desc;
    Ov014Vec16 rot;
    Ov003Actor *o;
    s32 base;
    pos.x = 0;
    pos.y = 0x5000;
    pos.z = 0x2000;
    pos.x = Rand_PlusMinus(0x6000);
    pos.x += pos.x > 0 ? 0x3000 : -0x3000;
    pos.z += Rand_UpTo(0x1000);
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    base = pos.x > 0 ? 0xc000 : 0x4000;
    if (self->unk_f8 % 2 != 0) {
        ang = base + (u16)Rand_UpTo(0x4000);
    } else {
        ang = base - (u16)Rand_UpTo(0x4000);
    }
    spd = Rand_UpTo(0x3800) + 0x3800;
    v.x = FX_Mul(spd, OV014_SIN(ang));
    v.z = FX_Mul(spd, OV014_COS(ang)) + 0x8000;
    Ov014Spawn_Init(&desc, 0x481d);
    desc.unk_04[0] = a;
    self->target_id = 0xffff;
    o = Group_SpawnActor(gGroup, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
    o->unk_84.x = v.x;
    o->unk_84.y = 0;
    o->unk_84.z = v.z;
    o->flags_0 = 1;
    self->target_id = o->id;
}

void func_ov014_0220a490(Ov014Act_02209280 *self, VecFx32 *vel, u16 a, u16 b, u16 c) {
    Ov014SpawnDesc desc;
    VecFx32 pos;
    Ov014Vec16 rot;
    Ov003Actor *o;
    Ov014Spawn_Init(&desc, 0x4819);
    desc.unk_04[0] = a;
    desc.unk_04[1] = b;
    desc.unk_04[2] = c;
    desc.parent = -1;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    self->target_id = 0xffff;
    o = Group_SpawnActor(gGroup, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
    if (vel != NULL) {
        s32 x = vel->x; s32 y = vel->y; o->unk_84.x = x; s32 z = vel->z; o->unk_84.y = y; o->unk_84.z = z;
    } else {
        o->target = self->target;
    }
    o->flags_0 = 1;
    self->target_id = o->id;
}


extern char data_ov014_02217a48[];
extern char data_ov014_02217a4e[];
extern u8 data_ov014_02217a54[];
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
extern BOOL Interp_MoveTo(VecFx32 *out, s32 speed, const VecFx32 *from, const VecFx32 *to, s32 minDist);

void Ov014Act_02209280_StateIdle(Ov014Act_02209280 *self) {
    if (self->fsm->st == 0) {
        const void *anim;
        anim = data_ov014_02217a48;
        if (self->unk_1a5 == 0) {
            anim = data_ov014_02217a4e;
        }
        if (self->unk_ee_0) {
            anim = data_ov014_02217a54;
        }
        Model0218fe1c_SetAnim(self->model, (char *)anim, 0xcd, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0xc00);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    if (self->unk_1a5 == 0) {
        Interp_MoveTo(&self->pos, 0xcd, &self->pos, (VecFx32 *)((u8 *)self + 0x1a8), 0xcd);
    } else if (self->hit->unk_9a_4) {
        self->hit->unk_9a_5 = 1;
        if (!(self->hit->unk_50 & 0x20000000)) {
            History_SetState(self->fsm, 4, 0);
        }
    }
}


extern const VecFx32 data_ov014_02216aa8[];
extern char data_ov014_02217a48[];
extern u8 data_ov014_02217a5a[];
extern char data_ov014_02217a60[];
extern u8 data_ov014_02217a66[];
extern u8 data_ov014_02217a6c[];
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, s32 c, s32 d);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *p);
extern BOOL Interp_MoveTo(VecFx32 *out, s32 speed, const VecFx32 *from, const VecFx32 *to, s32 minDist);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);

static inline Ov003Actor *Ov014h_FindById(u16 id) {
    return gActorMgr != NULL ? ActorMgr_GetActor(gActorMgr, id) : NULL;
}

void Ov014Act_02209280_StateMove(Ov014Act_02209280 *self) {
    switch (self->fsm->st) {
    case 0: {
        const Ov003Step *p = self->step;
        VecFx32 a;
        VecFx32 b;
        VecFx32 c;
        u16 ang;
        s32 d;
        const void *anim;
        EffectObj *e;
        if (p->op == 0xb) {
            self->unk_b8 = data_ov014_02216aa8[p->a];
        } else {
            s32 i = Rand_UpTo(6);
            self->unk_b8 = data_ov014_02216aa8[i];
        }
        self->speed = self->unk_b0->unk_00;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        a = self->pos;
        b = self->unk_b8;
        if (Hit_DiffInCylinder(&a, &b, 0x1800, 0x2800)) {
            self->fsm->st = 0x14;
            self->fsm->timer = 0x1e;
            break;
        }
        d = FX_Atan2(b.x - self->pos.x, b.z - self->pos.z) - self->rot_y;
        if (self->unk_ee_0) {
            anim = data_ov014_02217a5a;
        } else if ((d < 0 ? -d : d) < 0x1fff) {
            anim = data_ov014_02217a60;
        } else if ((d < 0 ? -d : d) > 0x5ffd) {
            anim = data_ov014_02217a60;
        } else if (d > 0) {
            anim = data_ov014_02217a66;
        } else {
            anim = data_ov014_02217a6c;
        }
        Model0218fe1c_SetAnim(self->model, (char *)anim, 0x2ab, 0);
        Model0218fe1c_ClearLoop(self->model);
        self->unk_1b4 = self->pos;
        c = self->hit->check;
        ang = FX_Atan2(b.x - self->pos.x, b.z - self->pos.z);
        e = Effect_SpawnId(0x67, &c);
        e->SetScaleAll(0x2000);
        e->SetRotXYZ(0, ang, 0);
        self->fsm->st = 0xa;
        self->fsm->timer = 0x5a;
        break;
    }
    case 0xa: {
        VecFx32 t;
        VecFx32 p;
        VecFx32 d;
        BOOL near = FALSE;
        s32 s;
        ActorSub40 *m;
        self->hit->unk_9a_5 = 1;
        t = self->unk_b8;
        p = self->pos;
        d.x = t.x - p.x;
        d.y = t.y - p.y;
        d.z = t.z - p.z;
        VEC_Normalize(&d, &d);
        s = FX_Mul(VEC_Distance(&p, &self->unk_1b4), 0x19a);
        if (s < 0x4cd) {
            s = 0x4cd;
        } else if (s > 0x99a) {
            s = 0x99a;
        }
        VEC_MultAdd(s, &d, &p, &p);
        self->pos = p;
        if (VEC_Distance(&p, &t) < 0x3000) {
            near = TRUE;
        }
        if (self->fsm->timer == 0x46) {
            EffectObj *e = Effect_SpawnId(0x192, &self->pos);
            e->SetScaleAll(0x3000);
            e->SetRotXYZ(0, FX_Atan2(t.x - self->pos.x, t.z - self->pos.z), 0);
        }
        if (near) {
            self->unk_1e4 = 0;
            self->fsm->timer = 0x1e;
            self->fsm->st = 0x14;
            break;
        }
        m = self->fsm;
        if (m->timer != 0) {
            m->timer--;
        }
        if (m->timer == 0) {
            self->unk_1e4 = 0;
            self->fsm->st = 0x14;
        }
        break;
    }
    case 0x14:
        Model0218fe1c_SetAnim(self->model, data_ov014_02217a48, 0xcd, 0);
        self->fsm->st++;
        self->fsm->timer = 0x1e;
    case 0x15: {
        VecFx32 q;
        VecFx32 r;
        Ov003Actor *o;
        ActorSub40 *m;
        q = self->unk_b8;
        r = self->pos;
        Interp_MoveTo(&r, 0x19a, &r, &q, 0x800);
        self->pos = r;
        o = Ov014h_FindById(self->target);
        if (o != NULL) {
            Actor_TurnToActor(self, o, self->unk_b0->unk_02);
        }
        m = self->fsm;
        if (m->timer != 0) {
            m->timer--;
        }
        if (m->timer == 0) {
            self->fsm->st++;
        }
        break;
    }
    case 0x16:
        self->fsm->st = 0xffff;
        break;
    }
    Body_Update(self->hit, 1, 0, 0);
}

}
