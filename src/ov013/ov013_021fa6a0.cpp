#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern char data_ov013_0220ae4e[];
extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5ca[];
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov013Actor *self, const void *p);
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern BOOL func_ov003_021d1c00(Ov013Actor *self, Ov013Msg *msg);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern u16 func_ov000_0218dfb4(Ov013Actor *a, u16 id);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
s32 func_ov013_021fc400(Ov013Actor *self);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

void func_ov013_021fa6a0(Ov013Actor *self) {
    Ov013Sub48 *m;
    Ov013Sub44 *n;
    Ov013Actor *p;
    func_ov003_021d112c(self);
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_48, 0x5c), 0, 0x2000, 0);
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_44, 0xc), 0, 0x2000, 0);
    self->unk_93_4 = 1;
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = -0x14000;
    FLD(s32, self->unk_3c, 0x14) = self->unk_64 << 1;
    FLD(u8, self, 0xf1) = 0;
    FLD(u8, self, 0xf0) = 0;
    FLD(u8, self, 0xf2) = 0;
    FLD(u16, self, 0xf4) = 0x1000;
    FLD(s32, self, 0xf8) = 0;
    self->unk_b6 = 0x3c;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov013_0220ae4e);
        FLD(u16, self, 0xf4) = 0x1800;
    }
}

void func_ov013_021fa78c(Ov013Actor *self) {
    Ov013Actor *p;
    s32 n;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    n = func_ov013_021fc400(self);
    self->unk_40->flags |= 1ull << n;
    self->unk_b6 = 0x96;
    if (n == 0x10) {
        self->unk_b6 = 0xb4;
    }
}

void func_ov013_021fa888(Ov013Actor *self, Ov013Msg *msg) {
    if (msg->type == 9) {
        func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x40, &self->pos, 0);
    }
    func_ov003_021d1c00(self, msg);
}

void func_ov013_021fa8e4(Ov013Actor *self) {
    Ov013Sub40 *s = self->unk_40;
    Ov013Sub44 *n;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u8, self->unk_38, 0xbe) = 0;
        self->rot[1] = 0;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    case 0x14: {
        u8 a = FLD(u8, self->unk_38, 0xbe);
        if (a < 0x1f) {
            s->timer++;
            if (s->timer % 6 == 0) {
                FLD(u8, self->unk_38, 0xbe) = a + 1;
            }
        } else {
            s->state = 0x63;
            n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        break;
    }
    case 0x63:
        s->timer++;
        if (s->timer > 0x14) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov013_021faa40(Ov013Actor *self) {
    Ov013Actor *t;
    if (self->unk_40->state == 0) {
        Ov013Sub44 *n;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
    }
    t = func_ov000_0218d240(self);
    if (t != NULL) {
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
    }
}


extern char data_ov013_0220b5be[];
extern char data_ov013_0220b5c4[];
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov013Vec func_ov003_021dadc0(const Ov013Vec *a, const Ov013Vec *b);
extern void func_ov000_0218d918(Ov013Actor *self, Ov013Vec *p, s32 a);
extern void func_ov000_0218ddd4(Ov013Actor *self, Ov013Vec *v, s32 a);
extern s32 FX_Div(s32 a, s32 b);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
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

void func_ov013_021faae8(Ov013Actor *self) {
    Ov013Vec v;
    v.x = self->unk_b8.x;
    v.y = self->unk_b8.y;
    v.z = self->unk_b8.z;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5be, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_a0 = 0xa4;
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y = 0x1333;
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        self->unk_40->state = 1;
        self->unk_40->timer = 0;
        break;
    case 1:
        func_ov000_0218ddd4(self, &v, 0);
        if (VEC_Distance(&self->pos, &v) == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov013_0220b5c4, 0x2ab, 0);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state = 2;
            self->unk_40->timer = 0;
            break;
        }
        if (self->pos.x == v.x && self->pos.z == v.z) {
            self->pos.y += self->unk_a0;
            if (self->pos.y > v.y) {
                self->pos.y = v.y;
            }
        }
        break;
    case 2: {
        Ov013Actor *t;
        s32 r;
        if (FLD(s16, self->unk_38, 0xc4) == 0) {
            break;
        }
        t = Ov013_FindActor(self->unk_90);
        if (t == NULL) {
            break;
        }
        v.x = t->pos.x;
        v.y = t->pos.y;
        v.z = t->pos.z;
        v.y = 0x99a;
        Ov013Vec d = func_ov003_021dadc0(&v, &self->pos);
        VEC_MultAdd(0x7800, &d, &v, &v);
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        self->unk_9c = 0x600;
        r = FX_Div(Ov013_DistXZ(&self->pos, &v), self->unk_9c);
        self->unk_a0 = -FX_Div(self->pos.y - v.y, r);
        self->unk_40->state = 0x14;
        break;
    }
    case 0x14:
        func_ov000_0218ddd4(self, &v, 0);
        if (VEC_Distance(&self->pos, &v) == 0) {
            self->unk_a0 = 0;
            self->unk_40->state = 0x15;
            self->unk_40->timer = 0;
            break;
        }
        if (self->pos.x == v.x && self->pos.z == v.z) {
            self->pos.y += self->unk_a0;
            if (self->pos.y < v.y) {
                self->pos.y = v.y;
            }
            break;
        }
        if (func_01ffc198(&self->pos, &v, 0x333)) {
            self->pos.x = v.x;
            self->pos.y = v.y;
            self->pos.z = v.z;
        }
        break;
    case 0x15:
        func_ov000_0218dbe0(self, 0);
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->state = 0x16;
            self->unk_40->timer = 0;
        }
        break;
    case 0x16:
        func_ov000_0218dbe0(self, 0);
        self->unk_9c = Ov013_FxMul(self->unk_9c, 0xf33);
        {
            Ov013Sub40 *q = self->unk_40;
            q->timer++;
            if (q->timer <= 0x1e) {
                break;
            }
        }
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5be, 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_a0 = 0x333;
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x17;
        self->unk_40->timer = 0;
        break;
    case 0x17:
        func_ov000_0218dbe0(self, 0);
        if (self->pos.y > 0x3000) {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->pos.y <= 0x8000) {
            break;
        }
        self->pos.y = 0x8000;
        v.y = 0x8000;
        v.x = 0;
        v.z = -0x14000;
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        func_ov000_0218d918(self, &v, 0x1000);
        self->unk_9c = 0x4cd;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x62;
        self->unk_40->timer = 0;
        break;
    case 0x62:
        func_ov000_0218ddd4(self, &v, 0);
        if (VEC_Distance(&v, &self->pos) != 0) {
            break;
        }
        self->unk_a0 = -0x19a;
        self->rot[1] = 0;
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
        break;
    case 0x63:
        if (self->pos.y > 0) {
            Ov013Sub44 *n;
            func_ov000_0218dbe0(self, 0);
            if (self->pos.y >= 0x3000) {
                break;
            }
            n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
            break;
        }
        self->pos.y = 0;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 0x64;
        self->unk_40->timer = 0;
        break;
    case 0x64: {
        Ov013Sub40 *q = self->unk_40;
        q->timer++;
        if (q->timer <= 0x14) {
            break;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}
}
