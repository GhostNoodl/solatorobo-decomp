#include "ov014/ov014.h"

static inline void Ov014_VecSub(VecFx32 *d, const VecFx32 *a, const VecFx32 *b) {
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
}

struct Ov014Mtx33 {
    s32 m[9];
};

extern "C" {

extern u8 data_ov014_02217b44[];
extern void func_0203f364(ActorSub48 *p);
extern void func_ov000_02191690(Model0218fe1c *p);
extern void func_ov000_02191618(Model0218fe1c *p);

void func_ov014_0220dcf0(void) {
}

#pragma force_active on
Ov014ActEx_0220dcf4 *Ov014ActEx_0220dcf4_Ctor(Ov014ActEx_0220dcf4 *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov014_02217b44;
    self->unk_d0 = NULL;
    self->unk_d4 = 0;
    self->unk_d6 = 0;
    self->unk_d8 = 0;
    self->unk_da = 0;
    return self;
}
#pragma force_active reset

Ov014ActEx_0220dcf4 *Ov014ActEx_0220dcf4_Dtor(Ov014ActEx_0220dcf4 *self) {
    *(void **)self = data_ov014_02217b44;
    EffectMgr_Kill(data_0214a420, self->unk_d0);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_0220dcf4 *Ov014ActEx_0220dcf4_DtorDelete(Ov014ActEx_0220dcf4 *self) {
    *(void **)self = data_ov014_02217b44;
    EffectMgr_Kill(data_0214a420, self->unk_d0);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_0220dcf4_Draw(Ov014ActEx_0220dcf4 *self) {
    func_ov000_02194c08(self);
}

void Ov014ActEx_0220dcf4_Start(Ov014ActEx_0220dcf4 *self) {
    ActorSub44 *n;
    ActorSub48 *m;
    func_ov000_02194758(self);
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    func_ov000_02198360(self->fsm, 1, 0);
    func_ov000_02191690(self->model);
    func_ov000_02191618(self->model);
    self->unk_d4 = self->unk_18 != 0 ? 1 : 0;
}

extern EffectObj *func_ov014_0220f7f0(s32 k, VecFx32 *pos);
extern s32 Interp_SinLerp(s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void Math_DirToAngles(u16 *ang, VecFx32 *v);
extern void *Target_Get(void *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_ov000_02191708(Model0218fe1c *p);
extern void func_ov000_021911c8(Model0218fe1c *a, s16 b);
extern void HitSphere_Link(ActorSub48 *p);

void func_ov014_0220de34(Ov014ActEx_0220dcf4 *self) {
    ActorSub40 *st = self->fsm;
    Ov014Mtx33 m;
    VecFx32 dir;
    VecFx32 to;
    VecFx32 n;
    VecFx32 p;
    Ov014Mtx33 t;
    VecFx32 v;
    u16 ang[4];
    switch (st->st) {
    case 0: {
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        ry = self->rot_y;
        set = FALSE;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0x1000;
        rz = self->rot_z;
        rx = self->rot_x;
        MTX_Identity33_((MtxFx33 *)&m);
        if (ry != 0) {
            MTX_RotY33_((MtxFx33 *)&m, OV014_SIN(ry), OV014_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_((MtxFx33 *)&t, OV014_SIN(rx), OV014_COS(rx));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotX33_((MtxFx33 *)&m, OV014_SIN(rx), OV014_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_((MtxFx33 *)&t, OV014_SIN(rz), OV014_COS(rz));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotZ33_((MtxFx33 *)&m, OV014_SIN(rz), OV014_COS(rz));
                set = TRUE;
            }
        }
        MTX_MultVec33((VecFx32 *)&self->speed, (MtxFx33 *)&m, (VecFx32 *)&self->speed);
        self->speed = (s32)(((s64)self->speed * 0x29 + 0x800) >> 12);
        self->velY = (s32)(((s64)self->velY * 0x29 + 0x800) >> 12);
        self->friction = (s32)(((s64)self->friction * 0x29 + 0x800) >> 12);
        self->unk_d0 = func_ov014_0220f7f0(0, &self->pos)->id;
        self->fsm->st++;
        self->fsm->timer = 0x1e;
        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
    }
    case 1: {
        EffectObj *e;
        self->pos.y -= 0xcd;
        e = func_020657b0(data_0214a420, self->unk_d0);
        if (e != NULL) {
            s32 s = Interp_SinLerp(FX_Div(self->fsm->timer << 12, 0x1e000), 0x19a, 0x3000);
            e->SetPosXYZ(self->pos.x, self->pos.y - 0x1000, self->pos.z);
            e->SetScaleXYZ(s, s, s);
        }
        if (self->fsm->timer == 0xf) {
            func_ov000_0218996c(10, 10);
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        EffectMgr_Kill(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
        self->fsm->st = 10;
        self->fsm->timer = 0x1e;
        break;
    }
    case 10: {
        EffectObj *q;
        self->pos.y += (0x1e - st->timer) * 0x7b;
        if (st->timer == 0xf) {
            func_02049f44(data_02097e4c, 0x50, &self->pos, 0);
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        q = func_ov014_0220f7f0(0, &self->pos);
        q->SetScaleAll(0x1000);
        self->unk_d0 = q->id;
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    }
    case 0x14: {
        EffectObj *e;
        s32 oldy = self->pos.y;
        s32 mag = VEC_Mag((VecFx32 *)&self->speed);
        s32 sp;
        VEC_Normalize((VecFx32 *)&self->speed, &dir);
        to.x = self->unk_84.x - self->pos.x;
        to.y = self->unk_84.y - self->pos.y;
        to.z = self->unk_84.z - self->pos.z;
        VEC_Normalize(&to, &to);
        VEC_MultAdd(0x333, &to, &dir, &dir);
        VEC_Normalize(&dir, &dir);
        sp = mag + 0x52;
        if (sp > 0x800) {
            sp = 0x800;
        }
        self->speed = FX_Mul(dir.x, sp);
        self->velY = FX_Mul(dir.y, sp);
        self->friction = FX_Mul(dir.z, sp);
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        self->rot_x += 0x1ff;
        self->rot_y = self->unk_d8;
        self->rot_z = self->unk_da;
        n.x = -dir.x;
        n.y = -dir.y;
        n.z = -dir.z;
        e = func_020657b0(data_0214a420, self->unk_d0);
        if (e != NULL) {
            e->SetPos(&self->pos);
            Math_DirToAngles(ang, &n);
            e->SetRot((const EffectRot *)ang); // ang is u16[4]: Rot16 would shrink the frame
        }
        if (self->pos.y < 0x5000 && oldy >= 0x5000) {
            func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
        }
        self->fsm->timer++;
        if (!(self->hit->unk_50 & 0x60000000)) {
            return;
        }
        self->pos.y = self->height >> 3;
        func_ov000_0218996c(0x14, 0x14);
        func_02065f88(5, &self->pos)->SetScaleAll(0x4000);
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        EffectMgr_StopLoop(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
        if (self->unk_d4 == 0) {
            ActorSub44 *q4;
            self->model->visible = 0;
            q4 = self->unk_44;
            q4->unk_22_0 = 0;
            q4->unk_22_1 = 0;
        }
        self->fsm->st = 0x19;
        self->fsm->timer = 0x1e;
        break;
    }
    case 0x19: {
        u16 t = st->timer;
        if (t & 3) {
            void *a = Target_Get(self->targetObj);
            v.x = self->pos.x - FLD(s32, self, 0x70);
            v.y = self->pos.y - FLD(s32, self, 0x74);
            v.z = self->pos.z - FLD(s32, self, 0x78);
            func_ov000_0219aae8(self, a, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &v, 0,
                                0x4000, 0, 0x6a, 0x1000);
        }
        if (t % 15 == 0) {
            u16 a = Rand_UpTo(0xffff);
            p.x = self->pos.x + FX_Mul(OV014_SIN(a), 0x4000);
            p.y = self->pos.y;
            p.z = self->pos.z + FX_Mul(OV014_COS(a), 0x4000);
            func_02065f88(0x6d, &p);
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        if (self->unk_d4 == 0) {
            self->targetObj->unk_02 = 0;
            func_ov000_02198360(self->fsm, 0x15, 0);
            return;
        }
        func_ov000_02191708(self->model);
        func_ov000_02191618(self->model);
        func_ov000_021911c8(self->model, 0x19a);
        {
            ActorSub44 *q4 = self->unk_44;
            ActorSub48 *q8;
            q4->unk_22_0 = 1;
            q4->unk_22_1 = 1;
            q8 = self->hit;
            q8->unk_9a_0 = 1;
            q8->unk_9a_3 = 1;
            HitSphere_Link(q8);
        }
        self->fsm->st = 0x28;
        self->fsm->timer = 0x258;
        break;
    }
    case 0x28:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        func_ov000_02198360(self->fsm, 0x15, 0);
        break;
    }
}

}
