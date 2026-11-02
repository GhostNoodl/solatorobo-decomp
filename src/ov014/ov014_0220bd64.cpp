#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov014_02217a4e[];
extern char data_ov014_02217a48[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void func_ov000_021911c8(void *a, s32 b);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);

void func_ov014_0220bd64(Ov014Act_02209280 *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0: {
        u8 *g;
        Ov014Sub48 *q;
        func_020627a0(self->kind, self->id);
        func_020627dc(5);
        g = (u8 *)data_ov000_021ccd54;
        g[0xac] = 1;
        func_ov000_02182590(g + 0xac);
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a4e, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02191318(self->unk_38, 0);
        FLD(u16, self->unk_48, 0x9a) |= 0x12;
        q = self->unk_48;
        q->unk_9a_2 = 0;
        q->unk_9a_5 = 0;
        self->unk_40->state++;
        self->unk_ec_0 = 0;
        break;
    }
    case 1: {
        Ov014Actor *e;
        if (!Ov014_GameIdle()) {
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a48, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02191318(self->unk_38, 0);
        func_0204a028(data_02097e4c, 0x32, &self->pos, 4);
        func_02049f44(data_02097e4c, 0x52, &self->pos, 0);
        func_ov000_0218996c(0xf, 0x3c);
        e = func_02065f88(0x66, &self->pos);
        e->v14(0x2800, 0x4800, 0x2800);
        self->unk_40->state++;
        self->unk_1a5 = 1;
        break;
    }
    case 2: {
        Ov014Vec tgt;
        Ov014Vec d;
        tgt.x = 0;
        tgt.y = tgt.x + 0x1000;
        tgt.z = 0x3000;
        d.x = tgt.x - self->pos.x;
        d.y = tgt.y - self->pos.y;
        d.z = tgt.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &tgt) >= 0x19a) {
            break;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0x3c;
        break;
    }
    case 3:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->unk_40->state++;
        }
        break;
    case 4: {
        Ov014Sub48 *q;
        self->pos.y -= 0x52;
        q = self->unk_48;
        if (self->pos.y >= q->unk_68.y) {
            break;
        }
        self->pos.x = 0;
        self->pos.y = 0;
        self->unk_1a5 = 1;
        self->pos.z = 0x3000;
        FLD(u16, q, 0x9a) |= 0x24;
        self->unk_40->state++;
        break;
    }
    case 5:
        s->state = 0xffff;
        break;
    }
}

}

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

extern void *data_0214a420;
extern char data_ov014_02217a8a[];
extern Ov014Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_0218db58(Ov014Actor *self, u16 a, u16 b, s32 c, s32 d);
extern void func_ov000_02191618(void *a);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov000_02191690(void *a);
extern void func_ov000_02191708(void *a);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern Ov014Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, Ov014Vec *pos, u16 *rot, u16 a);
extern void func_ov000_0218d46c(Ov014Actor *a, u16 id, s32 msg);
extern Ov014Actor *func_ov000_0219bf90(void);
extern Ov014Actor *Target_Get(void *p);
extern void func_ov000_0218a358(void *a, const Ov014Vec *b, Ov014Rot16 *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_02049de8(void *a, s32 b);
extern s32 Interp_SinLerp(s32 a, s32 b, s32 c);
extern Ov014Actor *func_ov014_0220f7f0(s32 k, Ov014Vec *pos);
extern void func_020639d4(void *e, s32 a, s32 b);
extern Ov014V *func_020657b0(void *a, s32 b);
extern BOOL func_ov000_0219a8bc(void *p, Ov014Obj *a, Ov014Obj *b, s32 c, s32 d, const Ov014Vec *pos, s32 e, s32 f, s32 g);

static inline Ov014Actor *Ov014e_FindById(u16 id) {
    return data_ov000_021ccd68 != NULL ? ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
}

static inline s32 Ov014e_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline void Ov014e_Aim(Ov014Actor *self, Ov014Actor *t) {
    u16 a;
    if (t != NULL && t != self) {
        a = FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
    } else {
        a = self->rot[1];
    }
    func_ov000_0218db58(self, a, FX_Atan2(-self->pos.x, 0x8000 - self->pos.z), 0x1fff, self->unk_b0->unk_02);
}

static inline void Ov014e_Clr(u16 *q) {
    q[3] = 0;
    FLD(u8, q, 8) = 0;
    FLD(u8, q, 9) = 0;
}

static inline void Ov014e_Shake(u8 *g, u8 a, u8 b, u8 c) {
    g[0x190] |= 0x1c;
    g[0x18d] = a;
    g[0x18e] = b;
    g[0x18f] = c;
}

void func_ov014_0220c09c(Ov014Act_02209280 *self) {
    Ov014Vec v;
    Ov014Vec w;
    Ov014Vec p;
    Ov014SpawnDesc desc;
    Ov014Vec d;
    Ov014Vec d2;
    Ov014Rot16 rot;
    Ov014Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0: {
        Ov014V *e = (Ov014V *)func_02065f88(0x391, &self->pos);
        e->v0c(0x3800);
        e->v24(0, 0x5000, 0);
        FLD(s32, e, 0x3c) = 0x2000;
        func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
        func_02049f44(data_02097e4c, 0xc03, &self->pos, 0);
        self->unk_40->timer = 0x1e;
        self->unk_40->state++;
    }
    case 1: {
        Ov014Actor *t = Ov014e_FindById(self->unk_90);
        Ov014Sub40 *w;
        if (t != NULL) {
            Ov014e_Aim(self, t);
        } else {
            self->unk_40->state++;
        }
        w = self->unk_40;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->unk_40->state++;
        }
        break;
    }
    case 2:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a8a, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_f4 = (u16)Rand_UpTo(0xffff);
        self->unk_f8 = self->step->unk_04;
        self->unk_fc = 1;
        self->unk_40->state = 10;
        break;
    case 10: {
        Ov014Actor *t = Ov014e_FindById(self->unk_90);
        Ov014Actor *o;
        if (t != NULL) {
            Ov014e_Aim(self, t);
        }
        self->unk_fc = 1;
        if (self->unk_38->unk_c4 != 1) {
            return;
        }
        func_02049f44(data_02097e4c, 0xc02, &self->pos, 0);
        self->unk_84 = self->unk_12c;
        self->target_id = 0xffff;
        Ov014Spawn_Init(&desc, 0x481f);
        o = Group_SpawnActor(data_ov000_021ccd64, &desc, &self->unk_84, self->rot, 0xffff);
        if (o != NULL) {
            if (o->unk_4c != NULL) {
                o->unk_4c->unk_18 |= 0x10;
            }
            o->flags_0 = 1;
            func_ov000_0218d46c(o, self->id, 1);
            self->target_id = o->id;
            ((Ov014V *)func_02065f88(0x66, &self->unk_84))->v0c(0x159a);
            ((Ov014V *)func_02065f88(0x2bd, &self->unk_84))->v0c(0x2000);
        }
        self->unk_40->state++;
        self->unk_40->timer = 2;
        break;
    }
    case 11: {
        Ov014Actor *o;
        Ov014Actor *pl;
        if (s->timer != 0 && self->unk_38->unk_c4 == 5) {
            s32 v = 0;
            s32 *p = *func_ov000_02190a30(self->unk_38, 0);
            Ov014Sub40 *w;
            if (p != NULL) {
                v = *p;
            }
            func_ov000_02191318(self->unk_38, v - 0x14000);
            self->unk_38->unk_c4 = 0;
            w = self->unk_40;
            if (w->timer != 0) {
                w->timer--;
            }
        }
        self->unk_84 = self->unk_12c;
        o = Ov014e_FindById(self->target_id);
        if (o != NULL) {
            o->pos.x = self->unk_84.x;
            o->pos.y = self->unk_84.y;
            o->pos.z = self->unk_84.z;
            if (o->unk_44 != NULL) {
                o->unk_44->unk_1c = 0xa000;
            }
        }
        pl = func_ov000_0219bf90();
        if (pl != NULL && self->target_id == FLD(u16, pl, 0xb1e)) {
            func_ov000_021911c8(self->unk_38, 0x2000);
            self->unk_f4 = Rand_UpTo(0xffff);
            self->unk_40->state = 0x14;
            self->unk_40->timer = 0xa0;
            return;
        }
        if (self->unk_38->unk_c4 != 2) {
            return;
        }
        self->unk_1f4 = o->unk_4c->unk_08;
        self->unk_1f6 = o->unk_4c->unk_0a;
        o->v08();
        self->target_id = 0xffff;
        self->unk_40->state = 0x1e;
        break;
    }
    case 0x14: {
        Ov014Actor *o;
        u8 *g;
        Ov014Actor *pl;
        u16 t;
        s32 v0;
        o = Ov014e_FindById(self->target_id);
        if (o != NULL) {
            o->unk_38->unk_c2_0 = 0;
        }
        pl = func_ov000_0219bf90();
        if (self->unk_38->unk_c4 == 3) {
            s32 *p;
            v0 = 0;
            p = *func_ov000_02190a30(self->unk_38, 0);
            if (p != NULL) {
                v0 = *p;
            }
            func_ov000_02191318(self->unk_38, v0 - 0x5000);
            func_ov000_021911c8(self->unk_38, 0x1000);
        }
        t = self->unk_40->timer;
        g = (u8 *)data_ov000_021ccd54;
        if (t % 30 == 0) {
            if (t < 0x35) {
                func_02065f88(0x6c, &self->unk_84);
                Ov014e_Shake(g, 3, 30, 30);
            } else if (t < 0x6a) {
                func_02065f88(0x6c, &self->unk_84);
                Ov014e_Shake(g, 3, 30, 30);
            } else {
                Ov014e_Shake(g, 1, 30, 30);
            }
        }
        {
            s32 ux = self->unk_84.x;
            s32 uz = self->unk_84.z;
            s32 ty = (pl->pos.y + pl->unk_6c) >> 1;
            Ov014_VecCopy(&v, &self->pos);
            v.y += 0x5000;
            {
                s32 x = ux - v.x;
                s32 y = ty - v.y;
                s32 z = uz - v.z;
                d.x = x;
                d.y = y;
                d.z = z;
            }
            VEC_MultAdd(0x99a, &d, &v, &v);
            rot.y = FX_Atan2(v.x - ux, v.z - uz) - 0x8000;
            if (rot.y <= 0x8000) {
                rot.y = rot.y >> 1;
            } else {
                rot.y = -rot.y;
                rot.y = rot.y >> 1;
                rot.y = -rot.y;
            }
            rot.y += 0x8000;
            rot.x = 0x200;
            rot.z = 0;
            func_ov000_0218a358(g + 0xf4, &v, &rot, 0xe000, 0, 0xccd, 0x99a, 1);
        }
        if ((s32)t == 0xa0) {
            func_02049f44(data_02097e4c, 0x38, &self->unk_84, 0);
        } else if ((s32)t == 0x50) {
            func_02049f44(data_02097e4c, 0xc09, &self->unk_84, 0);
        }
        if (o != NULL && Target_Get(o->unk_4c) == pl) {
            o->v08();
            self->target_id = 0xffff;
            func_ov000_0218d46c(self, self->id, 0x14);
            if (self->unk_50 != NULL) {
                self->unk_50[2] = self->id;
                Ov014e_Clr(self->unk_50);
            }
            func_ov000_021911c8(self->unk_38, 0x159a);
            func_ov000_02191708(self->unk_38);
            Ov014_VecCopy(&w, &self->pos);
            {
                s32 z = o->pos.z;
                s32 y = o->pos.y;
                s32 x = o->pos.x;
                d2.x = x - w.x;
                d2.y = y - w.y;
                d2.z = z - w.z;
            }
            VEC_MultAdd(0x99a, &d2, &w, &w);
            Ov014_VecCopy(&self->pos, &w);
            func_02049de8(data_02097e4c, 0x38);
            return;
        }
        {
            Ov014Sub40 *w = self->unk_40;
            if (w->timer != 0) {
                w->timer--;
            }
            if (w->timer != 0 && self->target_id == FLD(u16, pl, 0xb1e)) {
                return;
            }
        }
        if (o == NULL) {
            self->unk_40->state = 0x28;
            return;
        }
        self->unk_40->state = 0x1e;
        func_ov000_02191708(self->unk_38);
        func_02049de8(data_02097e4c, 0x38);
        self->unk_1f4 = o->unk_4c->unk_08;
        self->unk_1f6 = o->unk_4c->unk_0a;
        o->v08();
        self->target_id = 0xffff;
        break;
    }
    case 0x1e:
        func_ov000_02191418(self->unk_38, 0, 0);
        if (self->unk_38->unk_c4 != 4) {
            return;
        }
        func_ov000_02191690(self->unk_38);
        self->unk_40->timer = 0x78;
        self->unk_40->state++;
        break;
    case 0x1f: {
        u16 t = self->unk_40->timer;
        s32 k = FX_Div((t - 0x3c) << 12, 0x78000);
        s32 r;
        if (k < 0) {
            k = 0;
        }
        r = Interp_SinLerp(k, 0x9000, 0x5000);
        if (t == 0x78) {
            Ov014Actor *e = func_ov014_0220f7f0(3, &self->unk_84);
            e->v0c(r);
            FLD(s32, e, 0x3c) = 0x800;
            func_020639d4(e, 0x56, 4);
            func_020639d4(e, 0x53, 0x14);
            func_020639d4(e, 0x53, 0x28);
            self->unk_1e4 = FLD(s32, e, 0x24);
            ((Ov014V *)func_02065f88(0x69, &self->unk_84))->v0c(0x3000);
        } else {
            Ov014V *e = func_020657b0(data_0214a420, self->unk_1e4);
            if (e != NULL) {
                e->v0c(r);
            }
        }
        if (t % 10 == 0) {
            u16 a = Rand_PlusMinus(0x3fff);
            p.x = self->unk_84.x + FX_Mul(OV014_SIN(a), r);
            p.y = self->unk_84.y;
            p.z = self->unk_84.z + FX_Mul(OV014_COS(a), r);
            ((Ov014V *)func_02065f88(0x6d, &p))->v0c(0x1000);
        }
        if (t % 4 == 0) {
            s32 rad;
            Ov014Actor *o;
            if (t >= 0x3c) {
                rad = r / 2;
            } else {
                rad = Ov014e_FxMul64(r / 2, 0x1800);
            }
            o = Ov014e_FindById(self->unk_90);
            if (o != NULL && func_01ffc198(&o->pos, &self->unk_84, rad + o->unk_64)) {
                func_ov000_0219a8bc(o->unk_44, self, self, self->unk_1f4, (u8)self->unk_1f6, NULL, 0x64, 0x1000, 0x1000);
            }
        }
        if (t == 0x78) {
            Ov014e_Shake((u8 *)data_ov000_021ccd54, 0x28, 0x3c, 0x3c);
        } else if (t == 0x3c) {
            Ov014e_Shake((u8 *)data_ov000_021ccd54, 0x14, 0x3c, 0x3c);
        }
        {
            Ov014Sub40 *w = self->unk_40;
            if (w->timer != 0) {
                w->timer--;
            }
            if (w->timer == 0) {
                self->unk_1e4 = 0;
                self->unk_40->state = 0x28;
            }
        }
        break;
    }
    case 0x28:
        s->state = 0xffff;
        break;
    }
}


extern char data_ov014_02217a60[];
extern char data_ov014_02217a90[];
extern char data_ov014_02217a96[];
extern void func_02065860(void *a, void *b);
extern void Actor_TurnToActor(Ov014Obj *self, Ov014Obj *t, s32 a);
extern void Actor_MoveToPos(Ov014Obj *self, Ov014Vec *p, s32 a);

void func_ov014_0220cd74(Ov014Act_02209280 *self) {
    Ov014Vec p2;
    Ov014Vec p1;
    Ov014Vec p0;
    Ov014Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a60, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_fc = 1;
        func_02065860(data_0214a420, self->unk_1dc);
        self->unk_1dc = NULL;
        func_02065860(data_0214a420, self->unk_1e0);
        self->unk_1e0 = NULL;
        self->unk_40->state++;
        self->unk_40->timer = 0x14;
        break;
    case 1: {
        Ov014Actor *t = Ov014e_FindById(self->unk_90);
        Ov014Sub40 *w;
        if (self->unk_40->timer == 0x14) {
            u16 a;
            Ov014V *e;
            p2 = self->unk_48->unk_68;
            if (t != NULL) {
                a = (t != NULL && t != self) ? FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z) : self->rot[1];
            }
            e = (Ov014V *)func_02065f88(0x67, &p2);
            e->v34(0, a, 0);
            e->v0c(0x2000);
        }
        FLD(u16, self->unk_48, 0x9a) |= 0x20;
        FLD(u16, self->unk_48, 0x9a) |= 0x20;
        self->unk_9c = FX_Mul(self->unk_b0->unk_00, FX_Div(self->unk_40->timer << 12, 0x14000)) + 0x333;
        if (t != NULL) {
            Actor_TurnToActor(self, t, self->unk_b0->unk_02);
            p1 = t->pos;
            Actor_MoveToPos(self, &p1, 0);
        }
        w = self->unk_40;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            break;
        }
        p0 = self->unk_48->unk_68;
        ((Ov014V *)func_02065f88(0x6d, &p0))->v0c(0x2000);
        self->unk_40->state = 10;
        break;
    }
    case 10:
        self->unk_f4 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a90, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_f8 = self->step->unk_04;
        self->unk_40->state++;
        break;
    case 11:
        self->unk_f8--;
        self->unk_f4 ^= 1;
        s->state++;
        self->unk_40->timer = 0x14;
    case 12: {
        Ov014Sub40 *w;
        if (self->unk_38->unk_c4 == 1) {
            Ov014e_Shake((u8 *)data_ov000_021ccd54, 0x14, 10, 10);
        }
        w = self->unk_40;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            Ov014Actor *t = Ov014e_FindById(self->unk_90);
            if (t != NULL) {
                Actor_TurnToActor(self, t, self->unk_b0->unk_02);
            }
        }
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        if (self->unk_f8 != 0) {
            s32 sp;
            func_ov000_02190cb0(self->unk_38, self->unk_f4 != 0 ? data_ov014_02217a96 : data_ov014_02217a90, 0xcd, 0);
            sp = FX_Div(0x50000, self->step->time << 12);
            if (sp > 0x2000) {
                sp = 0x2000;
            } else if (sp < 0x800) {
                sp = 0x800;
            }
            func_ov000_021911c8(self->unk_38, (s16)sp);
            func_ov000_02191318(self->unk_38, 0);
            func_ov000_02191618(self->unk_38);
            self->unk_40->state = 11;
        } else {
            self->unk_40->state = 0x14;
            self->unk_40->timer = 0xf;
        }
        break;
    }
    case 0x14: {
        Ov014Sub40 *w;
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        w = self->unk_40;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->unk_fc = 0;
            self->unk_40->state = 0xffff;
        }
        break;
    }
    }
}
}
