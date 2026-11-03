#include "ov013/ov013.h"

struct Ov013SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov013Spawn_Init(Ov013SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

struct Ov013Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5be[];
extern char data_ov013_0220b5ca[];
extern const Ov013Rot16 data_ov013_0220ae48;
extern const VecFx32 data_ov013_0220ae7c;
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(ActorGroup *group, u16 kind);
extern VecFx32 Ov003Vec_DirXZ(const VecFx32 *a, const VecFx32 *b);
extern void Actor_TurnToPos(Ov003Actor *self, VecFx32 *p, s32 a);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
extern void SndMgr_Stop(void *p, s32 a);
extern u32 Rand_Fx(void);
extern u32 Rand_Get(void);
extern void HitSphere_Link(ActorSub48 *p);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, s32 r, s32 h);
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov013SpawnDesc *d, VecFx32 *pos, u16 *rot, u16 a);
extern void func_ov000_0218a358(void *a, const VecFx32 *b, Ov013Rot16 *c, s32 d, s32 e, s32 f, s32 g, s32 h);
}

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

static inline void Ov013_VecSwap(VecFx32 *a, VecFx32 *b) {
    s32 x = a->x;
    s32 y = a->y;
    s32 z = a->z;
    a->x = b->x;
    a->y = b->y;
    a->z = b->z;
    b->x = x;
    b->y = y;
    b->z = z;
}

static inline BOOL Ov013_Shown(ActorSub44 *n) {
    return (n->unk_22_0 == 1 && n->unk_22_1 == 1) ? TRUE : FALSE;
}

static inline void Ov013_Show(Ov003Actor *self) {
    ActorSub44 *n = self->unk_44;
    if (!Ov013_Shown(n) && self->pos.y < 0x3000) {
        ActorSub48 *m;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
    }
}

#define POLE(self, i) (&(self)->poles[i])

extern "C" {

void Ov013Boss_StateAttack2(Ov013Boss *self, const VecFx32 *pos, VecFx32 *prev, VecFx32 *cur) {
    BOOL shake = FALSE;
    VecFx32 v_1;
    s32 z_0;
    u8 on;
    u8 i;
    ActorSub40 *s = self->fsm;
    u8 cnt_1;
    s32 range;
    switch (s->st) {
    case 0: {
        ActorGroup *a_0;
        u16 n_0;
        Actor *p_0;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220b5be, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0x19a;
        self->friction = 0;
        self->gravity = 0;
        self->velY = 0xcd;
        self->unk_b8.x = self->pos.x;
        self->unk_b8.y = 0x3000;
        self->unk_b8.z = self->pos.z - 0x2000;
        self->rot_y = 0;
        a_0 = ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000);
        n_0 = ActorGroup_CountKind(a_0, 0x5c17);
        for (p_0 = a_0->head; p_0 != NULL && n_0 != 0; p_0 = p_0->next) {
            if (p_0->kind == 0x5c17) {
                n_0--;
                static_cast<Ov013ActVt_0220b5e0 *>(p_0)->unk_f0 = 1;
            }
        }
        self->fsm->st = 1;
        self->fsm->timer = 0;
        break;
    }
    case 1:
        Ov013_VecCopy(&v_1, &self->unk_b8);
        Actor_MoveToPos(self, &v_1, 0);
        if (VEC_Distance(&self->pos, &v_1) == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov013_0220b5ca, 0x89, 0);
            Model0218fe1c_SetLoop(self->model);
            SndMgr_PlayVolume(data_02097e4c, 0x4f, -1, -1, -1);
            range = 0xf000 - (self->radius << 3);
            z_0 = FX_Mul(Rand_PlusMinus(0x1000), range) - 0x7800;
            for (cnt_1 = 0, i = 0; i < 4; i++) {
                POLE(self, i)->v.x = FX_Mul(Rand_Fx(), 0x3800) + i * 0x3800 - 0x7000;
                on = 0;
                POLE(self, i)->v.y = 0;
                POLE(self, i)->v.z = z_0 + FX_Mul(Rand_PlusMinus(0x1000), self->radius);
                if (cnt_1 < 2 && (!(Rand_Get() & 1) || i > 1)) {
                    cnt_1++;
                    on = 1;
                }
                POLE(self, i)->on = on;
                if (i != 0) {
                    prev = &POLE(self, i - 1)->v;
                    cur = &POLE(self, i)->v;
                    if (Ov013_DistXZ(prev, cur) < 0x1800) {
                        VecFx32 dir = Ov003Vec_DirXZ(prev, cur);
                        VEC_MultAdd(0x2000, &dir, prev, cur);
                    }
                }
            }
            if (Rand_UpTo(0x63) % 2 == 0) {
                self->side = 1;
                Ov013_VecSet(&v_1, -0xc000, 0x8800, z_0);
            } else {
                self->side = 0;
                Ov013_VecSet(&v_1, 0xc000, 0x8800, z_0);
                {
                    u8 a_1;
                    u8 b;
                    for (a_1 = 0, b = 3; b > a_1; a_1++, b--) {
                        Ov013_VecSwap(&POLE(self, a_1)->v, &POLE(self, b)->v);
                    }
                }
            }
            Ov013_VecCopy(&self->unk_b8, &v_1);
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x4cd;
            self->velY = 0x11f;
            self->fsm->st = 0x13;
            self->fsm->timer = 0;
            break;
        }
        if (self->pos.x == v_1.x && self->pos.z == v_1.z) {
            self->pos.y += self->velY;
            if (self->pos.y > v_1.y) {
                self->pos.y = v_1.y;
            }
        }
        break;
    case 0x13:
        Ov013_VecCopy(&v_1, &self->unk_b8);
        Actor_MoveToPos(self, &v_1, 0);
        Actor_TurnToPos(self, &v_1, 0x400);
        if (self->pos.y > 0x3000) {
            ActorSub44 *n_1 = self->unk_44;
            ActorSub48 *m;
            n_1->unk_22_0 = 0;
            n_1->unk_22_1 = 0;
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            shake = TRUE;
        }
        if (VEC_Distance(&self->pos, &v_1) == 0) {
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x266;
            self->velY = -0x11f;
            {
                s32 z_1 = v_1.z;
                if (self->side != 0) {
                    Ov013_VecSet(&v_1, 0xc000, 0x8800, z_1);
                } else {
                    Ov013_VecSet(&v_1, -0xc000, 0x8800, z_1);
                }
            }
            Ov013_VecCopy(&self->unk_b8, &v_1);
            Actor_TurnToPos(self, &v_1, 0x400);
            self->fsm->st = 0x14;
            self->fsm->timer = 0;
            break;
        }
        if (self->pos.x == v_1.x && self->pos.z == v_1.z) {
            self->pos.y += self->velY;
            if (self->pos.y > v_1.y) {
                self->pos.y = v_1.y;
            }
        }
        break;
    case 0x14: {
        s32 d;
        s32 k;
        Ov013_VecCopy(&v_1, &self->unk_b8);
        Actor_MoveToPos(self, &v_1, 0);
        Actor_TurnToPos(self, &v_1, 0x400);
        shake = TRUE;
        if (self->side != 0) {
            d = self->pos.x + 0xc000;
        } else {
            d = 0xc000 - self->pos.x;
        }
        if (d > 0x6000 && self->velY < 0) {
            self->velY = 0;
        }
        if (d > 0x12000 && self->velY == 0) {
            self->velY = 0x11f;
        }
        pos = &self->pos;
        if (Ov013_DistXZ(pos, &v_1) == 0) {
            Ov013_VecSet(&v_1, 0, 0, -0x14000);
            Ov013_VecCopy(&self->unk_b8, &v_1);
            Actor_TurnToPos(self, &v_1, 0x1000);
            self->moveYaw = self->rot_y;
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x333;
            self->velY = -0x11f;
            self->fsm->st = 0x63;
            self->fsm->timer = 0;
        }
        k = ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000), 0x4823);
        if (k < 4) {
            s32 dx;
            if (self->pos.x >= POLE(self, k)->v.x) {
                dx = self->pos.x - POLE(self, k)->v.x;
            } else {
                dx = POLE(self, k)->v.x - self->pos.x;
            }
            if (dx < self->speed * 2) {
                Ov013SpawnDesc sd;
                VecFx32 p_1;
                Ov013ActEx_021fdb70 *o;
                Ov013Spawn_Init(&sd, 0x4823);
                Ov013_VecCopy(&p_1, &POLE(self, k)->v);
                p_1.y = self->pos.y + 0x1800;
                o = (Ov013ActEx_021fdb70 *)Group_SpawnActor(data_ov000_021ccd64, &sd, &p_1, &self->rot_x, 0xffff);
                o->flags_0 = 1;
                o->target = self->target;
                if (POLE(self, k)->on) {
                    o->unk_d4 = 1;
                } else {
                    o->unk_d4 = 0;
                }
                if (o->targetObj != NULL) {
                    o->targetObj->target = self->id;
                }
                self->target_id = o->id;
            }
        }
        break;
    }
    case 0x63:
        Ov013_VecCopy(&v_1, &self->unk_b8);
        Actor_TurnToPos(self, &v_1, 0x400);
        Ov013_Show(self);
        if (self->pos.y > 0x3000) {
            shake = TRUE;
        }
        if (Hit_DiffInCylinder(&self->pos, &v_1, self->speed, 0x5000)) {
            self->pos.x = v_1.x;
            self->pos.z = v_1.z;
            self->rot_y = Angle_Approach(0, self->rot_y, self->unk_b0->unk_02, 1, 0x8000);
            self->speed = 0;
            self->velY = -0xcd;
            Model0218fe1c_SetAnim(self->model, data_ov013_0220b5be, 0x155, 0);
            Model0218fe1c_SetLoop(self->model);
            SndMgr_Stop(data_02097e4c, 0x4f);
            self->fsm->st = 0x64;
            self->fsm->timer = 0;
        } else {
            Actor_Move(self, 0);
        }
        break;
    case 0x64:
        if (self->pos.y > 0) {
            self->rot_y = Angle_Approach(0, self->rot_y, self->unk_b0->unk_02, 1, 0x8000);
            Actor_Move(self, 0);
            Ov013_Show(self);
        } else {
            Model0218fe1c_SetAnim(self->model, data_ov013_0220b5b8, 0x155, 0);
            Model0218fe1c_SetLoop(self->model);
            self->rot_y = 0;
            self->fsm->st = 0x65;
            self->fsm->timer = 0;
        }
        break;
    case 0x65:
        s->timer++;
        if (s->timer > 0x14) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    if (shake) {
        FieldCam *cam = &data_ov000_021ccd54->cam;
        Robo021ca458 *pl;
        if (cam == NULL) {
            return;
        }
        pl = (Robo021ca458 *)ActorMgr_FindPlayer();
        if (pl == NULL) {
            return;
        }
        if ((pl->unk_b24_0 ? TRUE : FALSE)) {
            return;
        }
        {
            VecFx32 cp = data_ov013_0220ae7c;
            Ov013Rot16 rot = data_ov013_0220ae48;
            func_ov000_0218a358(cam, &cp, &rot, 0x13000, 1, 0x1000, 0x1000, 1);
        }
    }
}
}
