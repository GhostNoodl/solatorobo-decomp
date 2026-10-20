#include "ov012/ov012.h"

extern "C" {
void func_ov012_021fd708(Ov012Actor *self);
void func_ov012_021fdfa0(Ov012Actor *self);
void func_ov012_021fcf1c(Ov012Actor *self) {
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        func_ov012_021fd708(self);
        break;
    case 1:
        func_ov012_021fdfa0(self);
        break;
    }
}
}

extern "C" {
extern char data_ov012_0220ab21[];
extern const Ov012Vec data_ov012_0220a414;
void func_ov012_021fcf48(Ov012Actor *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab21, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0xe, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1: {
        u8 i;
        for (i = 0; i < 4; i++) {
            Ov012SpawnDesc d;
            Ov012Actor *o;
            Ov012Spawn_Init(&d, 0xffff);
            Ov012Spawn_Set(&d, 0x480f);
            o = func_ov000_02192b24(&d);
            if (o != NULL) {
                Ov012Vec t;
                VEC_Add(&self->pos, &data_ov012_0220a414, &t);
                o->pos = t;
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
                FLD(u16, o, 0x18) = i;
                o->unk_90 = self->unk_90;
                o->v04();
                FLD(Ov012Flags8, o, 0x16).b0 = 1;
                func_ov000_0219bebc(o, FLD(s16, self, 0x170));
                if (FLD(void *, o, 0x4c) != NULL) {
                    FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
                }
            }
        }
        func_02049f44(data_02097e4c, 0x501, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 2:
        s->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        FLD(u8, self, 0x110) = 0;
        FLD(u32, self, 0x10c) |= 1;
        break;
    }
}
}

extern "C" {
void func_ov012_021fd148(Ov012Actor *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        s->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 5) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}
}

extern "C" {
extern void func_02065804(void *a, s32 b);
extern void func_ov000_02184508(void *g);
extern void func_ov000_02184548(void *g);
extern void func_ov000_0219b71c(Ov012Vec *pos, Ov012Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d6a3c(Ov012Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov012Actor *self, u8 a);

struct Ov012Bits32 {
    u32 b0 : 1;
    u32 b1 : 31;
};

struct Ov012CamDa {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 3;
};

static inline void Ov012_Flash(u8 a, u8 b, u8 c) {
    u8 *g = (u8 *)data_ov000_021ccd54;
    FLD(Ov012Flags8, g, 0x190).b2 = 1;
    FLD(Ov012Flags8, g, 0x190).b3 = 1;
    FLD(Ov012Flags8, g, 0x190).b4 = 1;
    g[0x18d] = a;
    g[0x18e] = b;
    g[0x18f] = c;
}

static inline void Ov012_SetTgt(Ov012Actor *self) {
    s32 y = FLD(s32, self, 0xf8);
    s32 z = FLD(s32, self, 0xfc);
    FLD(s32, self, 0x108) = z;
    FLD(s32, self, 0x100) = self->pos.x;
    FLD(s32, self, 0x104) = y + 0x4800;
}
static inline BOOL Ov012_PlBusy(Ov012Actor *pl) {
    return FLD(Ov012Bits32, pl, 0xb24).b0 ? TRUE : FALSE;
}

void func_ov012_021fd1b0(Ov012Actor *self) {
    Ov012Vec p;
    Ov012Vec q;
    Ov012Vec s;
    Ov012Vec d;
    Ov012Sub40 *w = self->unk_40;
    u16 st = w->state;
    switch (st) {
    case 0: {
        Ov012Actor *o;
        Ov012Sub48 *m48;
        Ov012Sub44 *n;
        Ov012V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480f, 0x15);
        o = Ov012_FindActor(FLD(u16, self, 0xde));
        if (o != NULL) {
            o->unk_1a = 1;
        }
        self->unk_50[0] = 0;
        m48 = self->unk_48;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        func_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += 0x5000;
        FLD(s32, self, 0x13c) = FLD(s32, func_02065f88(0x390, &p), 0x24);
        func_02065f88(5, &p)->v0c(0x5800);
        switch (FLD(s16, self, 0xf0)) {
        case 0:
            FLD(s32, self, 0x114) = 0x3000;
            break;
        case 1:
            FLD(s32, self, 0x114) = -0x4000;
            break;
        }
        self->unk_1a = 0x28;
        Ov012_SetTgt(self);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x4000);
            e->v24(0, FLD(s32, self, 0x6c), 0);
        }
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        func_ov000_0218996c(0x19, 0x64);
        self->unk_40->state++;
    }
    case 1: {
        u16 t;
        {
            Ov012Sub40 *q = self->unk_40;
            q->timer++;
            t = q->timer;
        }
        if (t >= 0x96) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        if (t == 10) {
            func_ov000_02184508(data_ov000_021ccd54);
        }
        if (t == 0x1e || t == 0x3c || t == 0x5a || t == 0x78) {
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        }
        break;
    }
    case 2: {
        u16 t;
        w->timer++;
        t = w->timer;
        if (t == 0x32) {
            func_02065804(data_0214a420, FLD(s32, self, 0x13c));
        }
        if (t >= 0x8c) {
            {
                s32 y = self->pos.y;
                s32 z = self->pos.z;
                s32 x = self->pos.x;
                d.x = x - FLD(s32, self, 0x70);
                d.y = (y - 0x11000) - FLD(s32, self, 0x74);
                d.z = z - FLD(s32, self, 0x78);
            }
            VEC_MultAdd(0xe, &d, &self->pos, &self->pos);
            if (t >= 0x12c) {
                Ov012_Flash(10, 0x3c, 0x3c);
                func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
                self->unk_40->timer = 0;
                self->unk_40->state++;
                break;
            }
            if (t % 8 == 0) {
                self->rot[2] += 0xb6;
            }
        }
        if (t % 20 == 0) {
            q.x = self->pos.x;
            q.y = self->pos.y;
            q.z = self->pos.z;
            q.y += FLD(s32, self, 0x68) >> 1;
            s.x = self->unk_64;
            s.y = FLD(s32, self, 0x68) >> 2;
            s.z = self->unk_64;
            func_ov000_0219b71c(&q, &s, 0x99a, 0x1000, 2, 0x32);
            Ov012_Flash(0x14, 10, 10);
            func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        }
        break;
    }
    case 3:
        w->timer++;
        if (w->timer > 0x3c) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            func_ov000_02184548(data_ov000_021ccd54);
        } else {
            func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        }
        break;
    }
    if (st < 1) {
        return;
    }
    {
        Ov012Actor *pl = func_ov000_0219bf90();
        u8 *cam;
        s16 r;
        if (pl == NULL) {
            return;
        }
        if (Ov012_PlBusy(pl)) {
            return;
        }
        cam = (u8 *)data_ov000_021ccd54 + 0xf4;
        r = self->unk_1c;
        if (st == 1) {
            s16 c = self->unk_1a - 1;
            if (c <= 0) {
                FLD(s32, self, 0x114) -= 0xb8;
                if (r < 0xb60) {
                    r = r + 0x16;
                    if (r >= 0xb60) {
                        r = 0xb60;
                    }
                    self->unk_1c = r;
                }
            } else {
                self->unk_1a = c;
            }
        } else {
            Ov012_SetTgt(self);
        }
        FLD(Ov012Vec, cam, 0xe8) = FLD(Ov012Vec, self, 0x100);
        FLD(Ov012CamDa, cam, 0xda).b1 = 1;
        FLD(s32, cam, 0xf4) = FLD(s32, self, 0x114);
        FLD(Ov012CamDa, cam, 0xda).b2 = 2;
        FLD(u16, cam, 0xf8) = r + 0x5b0;
        FLD(Ov012CamDa, cam, 0xda).b4 = 1;
    }
}
}
