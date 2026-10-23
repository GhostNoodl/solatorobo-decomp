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

struct Ov013Bits32 {
    u32 b0 : 1;
    u32 rest : 31;
};

struct Ov013Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov013Pole {
    Ov013Vec v;
    u8 on;
    u8 pad[3];
};

class Ov013Boss : public Ov013Actor {
public:
    u8 unk_f0;
    u8 unk_f1;
    u8 side;
    u8 unk_f3;
    u16 unk_f4;
    u8 unk_f6[2];
    s32 unk_f8;
    Ov013Pole poles[4];
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5be[];
extern char data_ov013_0220b5ca[];
extern const Ov013Rot16 data_ov013_0220ae48;
extern const Ov013Vec data_ov013_0220ae7c;
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern u16 func_ov000_0218dfb4(Ov013Actor *a, u16 id);
extern Ov013Vec func_ov003_021dadc0(const Ov013Vec *a, const Ov013Vec *b);
extern void func_ov000_0218d918(Ov013Actor *self, Ov013Vec *p, s32 a);
extern void func_ov000_0218ddd4(Ov013Actor *self, Ov013Vec *v, s32 a);
extern void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_02049de8(void *p, s32 a);
extern s32 func_020404e0(void);
extern u32 func_02040420(void);
extern void func_0203f324(Ov013Sub48 *p);
extern void func_0203f364(Ov013Sub48 *p);
extern BOOL func_01ffc584(Ov013Vec *a, Ov013Vec *b, s32 r, s32 h);
extern Ov013Actor *func_ov000_0218bf1c(void *mgr, Ov013SpawnDesc *d, Ov013Vec *pos, u16 *rot, u16 a);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern void func_ov000_0218a358(void *a, const Ov013Vec *b, Ov013Rot16 *c, s32 d, s32 e, s32 f, s32 g, s32 h);
}

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const Ov013Vec *a, const Ov013Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

static inline void Ov013_VecSwap(Ov013Vec *a, Ov013Vec *b) {
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

static inline BOOL Ov013_Shown(Ov013Sub44 *n) {
    return (n->unk_22_0 == 1 && n->unk_22_1 == 1) ? TRUE : FALSE;
}

static inline void Ov013_Show(Ov013Actor *self) {
    Ov013Sub44 *n = self->unk_44;
    if (!Ov013_Shown(n) && self->pos.y < 0x3000) {
        Ov013Sub48 *m;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
    }
}

#define POLE(self, i) (&(self)->poles[i])

extern "C" {

void func_ov013_021fb1b4(Ov013Boss *self, const Ov013Vec *pos, Ov013Vec *prev, Ov013Vec *cur) {
    BOOL shake = FALSE;
    Ov013Vec v_1[1];
    s32 z_0;
    u8 on;
    u8 i;
    Ov013Sub40 *s = self->unk_40;
    u8 cnt_1[1];
    s32 range;
    switch (s->state) {
    case 0: {
        Ov013Actor *a_0;
        u16 n_0;
        Ov013Actor *p_0;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5be, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0x19a;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0xcd;
        self->unk_b8.x = self->pos.x;
        self->unk_b8.y = 0x3000;
        self->unk_b8.z = self->pos.z - 0x2000;
        self->rot[1] = 0;
        a_0 = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
        n_0 = func_ov000_0218dfb4(a_0, 0x5c17);
        for (p_0 = FLD(Ov013Actor *, a_0, 0xc); p_0 != NULL && n_0 != 0; p_0 = FLD(Ov013Actor *, p_0, 0x8)) {
            if (p_0->kind == 0x5c17) {
                n_0--;
                FLD(u8, p_0, 0xf0) = 1;
            }
        }
        self->unk_40->state = 1;
        self->unk_40->timer = 0;
        break;
    }
    case 1:
        Ov013_VecCopy(&v_1[0], &self->unk_b8);
        func_ov000_0218ddd4(self, &v_1[0], 0);
        if (VEC_Distance(&self->pos, &v_1[0]) == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov013_0220b5ca, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            func_02049a48(data_02097e4c, 0x4f, -1, -1, -1);
            range = 0xf000 - (self->unk_64 << 3);
            z_0 = Ov013_FxMul(func_02040528(0x1000), range) - 0x7800;
            for (cnt_1[0] = 0, i = 0; i < 4; i++) {
                POLE(self, i)->v.x = Ov013_FxMul(func_020404e0(), 0x3800) + i * 0x3800 - 0x7000;
                on = 0;
                POLE(self, i)->v.y = 0;
                POLE(self, i)->v.z = z_0 + Ov013_FxMul(func_02040528(0x1000), self->unk_64);
                if (cnt_1[0] < 2 && (!(func_02040420() & 1) || i > 1)) {
                    cnt_1[0]++;
                    on = 1;
                }
                POLE(self, i)->on = on;
                if (i != 0) {
                    prev = &POLE(self, i - 1)->v;
                    cur = &POLE(self, i)->v;
                    if (Ov013_DistXZ(prev, cur) < 0x1800) {
                        Ov013Vec dir = func_ov003_021dadc0(prev, cur);
                        VEC_MultAdd(0x2000, &dir, prev, cur);
                    }
                }
            }
            if (func_02040498(0x63) % 2 == 0) {
                self->side = 1;
                Ov013_VecSet(&v_1[0], -0xc000, 0x8800, z_0);
            } else {
                self->side = 0;
                Ov013_VecSet(&v_1[0], 0xc000, 0x8800, z_0);
                {
                    u8 a_1;
                    u8 b;
                    for (a_1 = 0, b = 3; b > a_1; a_1++, b--) {
                        Ov013_VecSwap(&POLE(self, a_1)->v, &POLE(self, b)->v);
                    }
                }
            }
            Ov013_VecCopy(&self->unk_b8, &v_1[0]);
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x4cd;
            self->unk_a0 = 0x11f;
            self->unk_40->state = 0x13;
            self->unk_40->timer = 0;
            break;
        }
        if (self->pos.x == v_1[0].x && self->pos.z == v_1[0].z) {
            self->pos.y += self->unk_a0;
            if (self->pos.y > v_1[0].y) {
                self->pos.y = v_1[0].y;
            }
        }
        break;
    case 0x13:
        Ov013_VecCopy(&v_1[0], &self->unk_b8);
        func_ov000_0218ddd4(self, &v_1[0], 0);
        func_ov000_0218d918(self, &v_1[0], 0x400);
        if (self->pos.y > 0x3000) {
            Ov013Sub44 *n_1 = self->unk_44;
            Ov013Sub48 *m;
            n_1->unk_22_0 = 0;
            n_1->unk_22_1 = 0;
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            shake = TRUE;
        }
        if (VEC_Distance(&self->pos, &v_1[0]) == 0) {
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x266;
            self->unk_a0 = -0x11f;
            {
                s32 z_1 = v_1[0].z;
                if (self->side != 0) {
                    Ov013_VecSet(&v_1[0], 0xc000, 0x8800, z_1);
                } else {
                    Ov013_VecSet(&v_1[0], -0xc000, 0x8800, z_1);
                }
            }
            Ov013_VecCopy(&self->unk_b8, &v_1[0]);
            func_ov000_0218d918(self, &v_1[0], 0x400);
            self->unk_40->state = 0x14;
            self->unk_40->timer = 0;
            break;
        }
        if (self->pos.x == v_1[0].x && self->pos.z == v_1[0].z) {
            self->pos.y += self->unk_a0;
            if (self->pos.y > v_1[0].y) {
                self->pos.y = v_1[0].y;
            }
        }
        break;
    case 0x14: {
        s32 d;
        s32 k;
        Ov013_VecCopy(&v_1[0], &self->unk_b8);
        func_ov000_0218ddd4(self, &v_1[0], 0);
        func_ov000_0218d918(self, &v_1[0], 0x400);
        shake = TRUE;
        if (self->side != 0) {
            d = self->pos.x + 0xc000;
        } else {
            d = 0xc000 - self->pos.x;
        }
        if (d > 0x6000 && self->unk_a0 < 0) {
            self->unk_a0 = 0;
        }
        if (d > 0x12000 && self->unk_a0 == 0) {
            self->unk_a0 = 0x11f;
        }
        pos = &self->pos;
        if (Ov013_DistXZ(pos, &v_1[0]) == 0) {
            Ov013_VecSet(&v_1[0], 0, 0, -0x14000);
            Ov013_VecCopy(&self->unk_b8, &v_1[0]);
            func_ov000_0218d918(self, &v_1[0], 0x1000);
            self->unk_98 = self->rot[1];
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x333;
            self->unk_a0 = -0x11f;
            self->unk_40->state = 0x63;
            self->unk_40->timer = 0;
        }
        k = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000), 0x4823);
        if (k < 4) {
            s32 dx;
            if (self->pos.x >= POLE(self, k)->v.x) {
                dx = self->pos.x - POLE(self, k)->v.x;
            } else {
                dx = POLE(self, k)->v.x - self->pos.x;
            }
            if (dx < self->unk_9c * 2) {
                Ov013SpawnDesc sd;
                Ov013Vec p_1;
                Ov013Actor *o;
                Ov013Spawn_Init(&sd, 0x4823);
                Ov013_VecCopy(&p_1, &POLE(self, k)->v);
                p_1.y = self->pos.y + 0x1800;
                o = func_ov000_0218bf1c(data_ov000_021ccd64, &sd, &p_1, self->rot, 0xffff);
                FLD(Ov013Flags8, o, 0x16).b0 = 1;
                o->unk_90 = self->unk_90;
                if (POLE(self, k)->on) {
                    FLD(u8, o, 0xd4) = 1;
                } else {
                    FLD(u8, o, 0xd4) = 0;
                }
                if (FLD(void *, o, 0x4c) != NULL) {
                    FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
                }
                FLD(u16, self, 0xde) = o->id;
            }
        }
        break;
    }
    case 0x63:
        Ov013_VecCopy(&v_1[0], &self->unk_b8);
        func_ov000_0218d918(self, &v_1[0], 0x400);
        Ov013_Show(self);
        if (self->pos.y > 0x3000) {
            shake = TRUE;
        }
        if (func_01ffc584(&self->pos, &v_1[0], self->unk_9c, 0x5000)) {
            self->pos.x = v_1[0].x;
            self->pos.z = v_1[0].z;
            self->rot[1] = func_01ffc128(0, self->rot[1], self->unk_b0->unk_02, 1, 0x8000);
            self->unk_9c = 0;
            self->unk_a0 = -0xcd;
            func_ov000_02190cb0(self->unk_38, data_ov013_0220b5be, 0x155, 0);
            func_ov000_021915a0(self->unk_38);
            func_02049de8(data_02097e4c, 0x4f);
            self->unk_40->state = 0x64;
            self->unk_40->timer = 0;
        } else {
            func_ov000_0218dbe0(self, 0);
        }
        break;
    case 0x64:
        if (self->pos.y > 0) {
            self->rot[1] = func_01ffc128(0, self->rot[1], self->unk_b0->unk_02, 1, 0x8000);
            func_ov000_0218dbe0(self, 0);
            Ov013_Show(self);
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x155, 0);
            func_ov000_021915a0(self->unk_38);
            self->rot[1] = 0;
            self->unk_40->state = 0x65;
            self->unk_40->timer = 0;
        }
        break;
    case 0x65:
        s->timer++;
        if (s->timer > 0x14) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    if (shake) {
        u8 *cam = (u8 *)data_ov000_021ccd54 + 0xf4;
        Ov013Actor *pl;
        if (cam == NULL) {
            return;
        }
        pl = func_ov000_0219bf90();
        if (pl == NULL) {
            return;
        }
        if ((FLD(Ov013Bits32, pl, 0xb24).b0 ? TRUE : FALSE)) {
            return;
        }
        {
            Ov013Vec cp = data_ov013_0220ae7c;
            Ov013Rot16 rot = data_ov013_0220ae48;
            func_ov000_0218a358(cam, &cp, &rot, 0x13000, 1, 0x1000, 0x1000, 1);
        }
    }
}
}
