#include "ov013/ov013.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern char data_ov013_0220b88d[];
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_0203f324(Ov013Sub48 *p);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern u32 _ffltu(u32 a);
extern u32 _fmul(u32 a, u32 b);
extern s32 func_0200b5a8(u32 a);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_021fdc30(Ov013Actor *self) {
    Ov013Actor *t = Ov013_FindActor(self->unk_90);
    if (t == NULL) {
        return;
    }
    if (self->unk_40->state == 0) {
        Ov013Sub48 *m;
        Ov013Sub44 *n;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0x14;
        self->unk_48->unk_30 = 0;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_94_1 = 1;
        func_02049f44(data_02097e4c, 0x34, &self->pos, 0);
        self->unk_40->state++;
        self->unk_40->timer = 0;
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 8), 0x20, 1 << (t->id >> 12), NULL, NULL, self->unk_64, 0, 100, 0x1000);
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        return;
    }
    {
        Ov013Sub44 *n;
        u16 w = func_0200b5a8(_fmul(0x3f4ccccd, _ffltu(FLD(u16, FLD(void *, self, 0x4c), 8))));
        func_ov000_0219aae8(self, self, w, 0x20, 1 << (t->id >> 12), NULL, NULL, self->unk_64 + 0x1000, 0xccd, 100, 0x1000);
        func_02065f88(0x66, &self->pos);
        func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
        func_ov000_0218996c(0xc, 0x14);
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        func_ov000_021984f4(self->unk_44, 0, 0);
        self->unk_94_1 = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

extern char data_ov013_0220b893[];
extern char data_ov013_0220aec4[];
extern void *data_0214a420;
extern void *data_ov000_021ccd64;
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov013Actor *p);
extern void func_ov000_02191690(void *p);
extern void *func_020657b0(void *a, s32 b);

struct Ov013Stat8 {
    u16 a;
    u16 b;
};

struct Ov013Stat {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 h4;
    u16 h6;
    Ov013Stat8 s;
    u32 c;
};

struct Ov013Blk12 {
    u32 w[3];
};

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

extern Ov013Actor *func_ov000_0218bf1c(void *mgr, Ov013SpawnDesc *d, Ov013Vec *pos, void *rot, u16 a);

void func_ov013_021fdedc(Ov013Actor *self) {
    Ov013Sub40 *q = self->unk_40;
    switch (q->state) {
    case 0: {
        Ov013Sub44 *n;
        Ov013Actor *r;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_94_1 = 0;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_90 = 0xffff;
        r = func_ov000_0219bf90();
        if (r != NULL) {
            self->unk_90 = r->id;
        }
        if (FLD(u8, self, 0xd4) == 0) {
            Ov013Stat *p;
            Ov013Stat v;
            func_ov000_02191690(self->unk_38);
            p = FLD(Ov013Stat *, self, 0x4c);
            v = *p;
            v.h4 = func_0200b5a8(_fmul(0x3fa66666, _ffltu(p->h4)));
            // fake match: re-reading byte 0 after the call keeps it out of a callee-saved register
            v.b0 = FLD(u8, p, 0);
            *p = v;
        }
        self->unk_40->state = 0xa;
        self->unk_40->timer = 0;
        break;
    }
    case 0xa: {
        Ov013Actor *r = func_ov000_0219bf90();
        if (r == NULL || func_ov000_021b4738(r)) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
            break;
        }
        FLD(u16, self, 0xce)--;
        if (FLD(u16, self, 0xce) != 0) {
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b893, 0x2ab, 0);
        if (FLD(u8, self, 0xd4) == 0) {
            func_ov000_02191690(self->unk_38);
        }
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    }
    case 0x14:
        q->timer++;
        if (q->timer <= 0x4d) {
            break;
        }
        if (FLD(u8, self, 0xd4) == 0) {
            Ov013Sub44 *n;
            Ov013Vec v;
            Ov013V *o;
            FLD(u8, FLD(void *, self, 0x4c), 0) = 1;
            self->unk_94_1 = 1;
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            func_ov000_02191690(self->unk_38);
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            v.y += self->unk_64;
            o = func_02065f88(0x390, &v);
            FLD(s32, self, 0xd0) = FLD(s32, o, 0x24);
            o->v14(0x333, 0x333, 0x333);
            FLD(s32, o, 0x3c) = 0x14cd;
            self->unk_40->state = 0x28;
            self->unk_40->timer = 0;
        } else {
            self->unk_40->state = 0x15;
            self->unk_40->timer = 0;
        }
        break;
    case 0x15: {
        Ov013Sub44 *n;
        Ov013Vec v;
        if (FLD(s16, self->unk_38, 0xc4) != 2) {
            break;
        }
        FLD(u8, FLD(void *, self, 0x4c), 0) = 1;
        self->unk_94_1 = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0x1000;
        func_02065f88(0x12c, &v)->v14(0x1800, 0x1800, 0x1800);
        func_02049f44(data_02097e4c, 0x11, &self->pos, 0);
        self->unk_40->state = 0x1e;
        self->unk_40->timer = 0;
        break;
    }
    case 0x1e: {
        Ov013SpawnDesc desc;
        Ov013Vec v;
        Ov013Actor *o;
        q->timer++;
        if (q->timer <= 0xa) {
            break;
        }
        Ov013Spawn_Init(&desc, 0x5c17);
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0xccd;
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &v, self->rot, 0xffff);
        FLD(Ov013Flags8, o, 0x16).b0 = 1;
        o->unk_90 = self->unk_90;
        if (FLD(void *, o, 0x4c) != NULL) {
            FLD(u16, FLD(void *, o, 0x4c), 0x1c) = FLD(u16, FLD(void *, self, 0x4c), 0x1c);
        }
        self->unk_40->state = 0x3c;
        self->unk_40->timer = 0;
        break;
    }
    case 0x28: {
        void *p;
        Ov013Vec v;
        Ov013V *o;
        q->timer++;
        if (q->timer <= 0x5a) {
            break;
        }
        p = func_020657b0(data_0214a420, FLD(s32, self, 0xd0));
        if (p != NULL) {
            FLD(s32, p, 0x1c) = 4;
            FLD(s32, self, 0xd0) = -1;
        }
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0x666;
        o = func_02065f88(0x196, &v);
        func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        o->v14(0x800, 0x800, 0x800);
        self->unk_94_1 = 1;
        self->unk_40->state = 0x29;
        self->unk_40->timer = 0;
        break;
    }
    case 0x29:
        q->timer++;
        if (q->timer <= 0x38) {
            break;
        }
        self->unk_40->state = 0x32;
        self->unk_40->timer = 0;
        break;
    case 0x32: {
        Ov013Vec v;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0x666;
        func_02065f88(5, &v)->v14(0x3000, 0x3000, 0x3000);
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        func_ov000_0218996c(0xa, 0xf);
        self->unk_40->state = 0x33;
        self->unk_40->timer = 0;
        break;
    }
    case 0x33: {
        Ov013Actor *t = Ov013_FindActor(self->unk_90);
        if (t != NULL) {
            u16 w = func_0200b5a8(_fmul(0x3f99999a, _ffltu(FLD(u16, FLD(void *, self, 0x4c), 8))));
            Ov013Blk12 b = *(Ov013Blk12 *)data_ov013_0220aec4;
            func_ov000_0219aae8(self, self, w, 0x20, 1 << (t->id >> 12), &b, NULL, 0x3000, 0, 100, 0x1000);
        }
        if (self->unk_38 != NULL && FLD(u8, self->unk_38, 0xbe) != 0) {
            u8 a;
            Ov013Sub40 *r = self->unk_40;
            r->timer++;
            a = 0x1f - r->timer * 2;
            if (a > 0x1f) {
                a = 0;
            }
            FLD(u8, self->unk_38, 0xbe) = a;
        }
        {
            Ov013Sub40 *r = self->unk_40;
            r->timer++;
            if (r->timer <= 0x14) {
                break;
            }
        }
        self->unk_40->state = 0x3c;
        self->unk_40->timer = 0;
        break;
    }
    case 0x3c:
        if (self->unk_38 == NULL) {
            break;
        }
        if (FLD(u8, self->unk_38, 0xbe) != 0) {
            u8 a;
            q->timer++;
            a = 0x1f - q->timer * 4;
            if (a > 0x1f) {
                a = 0;
            }
            FLD(u8, self->unk_38, 0xbe) = a;
        } else {
            FLD(u8, FLD(void *, self, 0x4c), 2) = 0;
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
}
}
