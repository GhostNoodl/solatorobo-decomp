#include "ov014/ov014.h"

extern "C" {

extern void *data_ov014_02216500[];
extern void *data_02097e4c;
extern void func_ov000_02191690(void *a);
extern void func_ov000_02191708(void *a);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *v);
extern void func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);

void func_ov014_022006e4(Ov014Actor *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x1000, 0);
        func_ov000_02191690(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        if (FLD(u8, self, 0xf8) == 1) {
            FLD(u8, self, 0xf8) = 0;
            s->state++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer > (u16)(FLD(s16, self, 0xf0) * 30)) {
            func_02065f88(0x68, &self->pos)->v34(0xbfff, self->rot[1], 0);
            func_ov000_02191708(self->unk_38);
            func_0204a028(data_02097e4c, 0x71, &self->pos, 5);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 3:
        if (func_ov000_02191120(self->unk_38)) {
            void *a = data_ov014_02216500[3];
            func_ov000_02190cb0(self->unk_38, a, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            if (FLD(s16, self, 0xf0) == 4) {
                u8 b = 1;
                func_ov000_0219bd20(0x5c0e, self->kind, 6, 1, 1, &b);
            }
            func_ov000_02190cb0(self->unk_38, a, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e:
        if (FLD(u8, self, 0xf8) == 2) {
            FLD(u8, self, 0xf8) = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}


extern void *data_ov014_02216500[];
extern void func_ov000_02191780(void *a);
extern u8 *func_ov000_02190a30(void *a, s32 b);
extern void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *target, s32 a);
extern void func_ov000_0218dab0(Ov014Actor *self, Ov014Actor *target, s32 a);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov000_0218d46c(Ov014Actor *a, u16 id, s32 msg);

void func_ov014_022008f4(Ov014Actor *self) {
    Ov014Actor *list[0x20];
    Ov014Actor *t;
    s32 i;
    s32 n;
    if (self->unk_40->state == 0) {
        Ov014Sub44 *s44;
        u8 *q;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x89, 0);
        func_ov000_02191780(self->unk_38);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        q = func_ov000_02190a30(self->unk_38, 3);
        if (q != NULL) {
            FLD(Ov014Flags, self->unk_38, 0xc2).b6 = 1;
            func_ov000_02191920(self->unk_38, 0, 0x1000, 0);
            if (FLD(s32 *, q, 0) != NULL) {
                *FLD(s32 *, q, 0) = 0;
            }
            FLD(u8, q, 0x111) |= 8;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    t = func_ov000_0218d240(self);
    func_ov000_0218d988(self, t, 0xcd);
    func_ov000_0218dab0(self, t, 0xcd);
    n = func_ov000_0219a510(self, 0x10, &self->pos, self->unk_64, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov014Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
                if ((u16)(FLD(u16, FLD(u8 *, q, 0x4c), 0x1c) & 0xf000) != 0x5000) {
                    func_ov000_0218d46c(q, q->id, 0x15);
                    return;
                }
            }
        }
    }
}

struct Ov014SpawnDescA {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014SpawnA_Init(Ov014SpawnDescA *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern u8 data_ov014_022173e0[];
extern const u8 data_ov014_0221663c[];
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern void func_ov000_021917f8(void *a);
extern void func_ov003_021da9ac(void *p, s32 a, void *e);
extern BOOL func_ov003_021daa0c(void *p, s32 a);
extern void func_ov003_021daa6c(void *p, s32 a);
extern void func_ov000_0218d9e8(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014SpawnDescA *d, Ov014Vec *pos, void *rot, u16 a);
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_01ffc9fc(Ov014Vec *a, Ov014Vec *b, u16 ang);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *c);

static inline Ov014Actor *Ov014_FindById(u16 id) {
    return data_ov000_021ccd68 != NULL ? func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
}

void func_ov014_02200a88(Ov014Actor *self) {
    Ov014Actor *t = func_ov000_0218d240(self);
    u8 *tbl = data_ov014_022173e0;
    Ov014Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0: {
        Ov014V *e;
        s->timer++;
        if (s->timer < data_ov014_0221663c[FLD(s16, self, 0xf0) * 3]) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x89, 0);
        func_ov000_021917f8(self->unk_38);
        func_0204a028(data_02097e4c, 0x71, &self->pos, 5);
        e = func_02065f88(0x324, &self->pos);
        e->v0c(0x4000);
        e->v24(0, 0x4cd, 0x2800);
        func_ov003_021da9ac(FLD(void *, self, 0x100), 0xff, e);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014Sub44 *s44;
        u8 *q;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        q = func_ov000_02190a30(self->unk_38, 3);
        if (q != NULL) {
            FLD(Ov014Flags, self->unk_38, 0xc2).b6 = 1;
            func_ov000_02191920(self->unk_38, 0, 0x1000, 0);
            if (FLD(s32 *, q, 0) != NULL) {
                *FLD(s32 *, q, 0) = 0x1000;
            }
            FLD(u8, q, 0x111) |= 8;
        }
        self->unk_40->state++;
        break;
    }
    case 2:
        func_ov000_0218d988(self, t, 0xcd);
        func_ov000_0218dab0(self, t, 0xcd);
        {
            Ov014Sub40 *q = self->unk_40;
            q->timer++;
            if (q->timer != 0x32) {
                return;
            }
        }
        func_ov003_021da9ac(FLD(void *, self, 0x100), 0xfe, func_02065f88(0x196, &self->pos));
        func_0204a028(data_02097e4c, 0x5b, &self->pos, 2);
        self->unk_84.x = 0;
        self->unk_84.y = -0x5000;
        self->unk_84.z = 0x4000;
        func_01ffc9fc(&self->unk_84, &self->unk_84, self->rot[1]);
        VEC_Add(&self->unk_84, &self->pos, &self->unk_84);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 3: {
        Ov014SpawnDescA desc;
        Ov014Actor *o;
        func_ov000_0218d988(self, t, 0x19a);
        func_ov000_0218d9e8(self, &self->unk_84, 0xcd);
        if (func_ov003_021daa0c(FLD(void *, self, 0x100), 0xfe)) {
            return;
        }
        func_ov000_0218996c(8, 0x28);
        Ov014SpawnA_Init(&desc, 0x483c);
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &self->pos, self->rot, 0xffff);
        if (o != NULL) {
            FLD(void *, o, 0x60) = tbl;
            FLD(Ov014Flags8, o, 0x16).b0 = 1;
            o->unk_90 = self->unk_90;
            if (FLD(void *, o, 0x4c) != NULL) {
                FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
            }
            FLD(u16, self, 0xfa) = o->id;
        }
        self->unk_84.x = 0;
        self->unk_84.y = 0x1000;
        self->unk_84.z = 0x4000;
        func_01ffc9fc(&self->unk_84, &self->unk_84, self->rot[1]);
        VEC_Add(&self->unk_84, &self->pos, &self->unk_84);
        func_ov003_021daa6c(FLD(void *, self, 0x100), 0xff);
        self->unk_40->state++;
        break;
    }
    case 4: {
        Ov014Actor *o;
        Ov014V *e;
        u16 n;
        func_ov000_0218d9e8(self, &self->unk_84, 0x19a);
        o = Ov014_FindById(FLD(u16, self, 0xfa));
        if (o != NULL) {
            o->rot[0] = self->rot[0];
            o->rot[1] = self->rot[1];
            o->rot[2] = self->rot[2];
        }
        {
            Ov014Sub40 *q = self->unk_40;
            u16 lim = FLD(u16, tbl, 4);
            q->timer++;
            if (lim != q->timer) {
                return;
            }
        }
        self->unk_40->timer = 0;
        e = func_02065f88(0x324, &self->pos);
        e->v0c(0x4000);
        e->v24(0, 0x4cd, 0x2800);
        func_ov003_021da9ac(FLD(void *, self, 0x100), 0xff, e);
        n = 0;
        if (FLD(void *, self, 0x104) != NULL) {
            n = FLD(u16, FLD(void *, self, 0x104), 4);
        }
        if (++FLD(u8, self, 0xfe) < n) {
            self->unk_40->state = 10;
        } else {
            self->unk_40->state = 0x1e;
        }
        break;
    }
    case 10:
        func_ov000_0218d988(self, t, 0xcd);
        func_ov000_0218dab0(self, t, 0xcd);
        {
            Ov014Sub40 *q = self->unk_40;
            q->timer++;
            if (q->timer < FLD(u16, FLD(void *, self, 0x104), 2)) {
                return;
            }
        }
        self->unk_40->timer = 0;
        self->unk_40->state = 2;
        break;
    case 0x1e: {
        u16 lim = 0x3c;
        Ov014Sub44 *s44;
        if (FLD(void *, self, 0x104) != NULL) {
            lim = FLD(u16, FLD(void *, self, 0x104), 6);
        }
        s->timer++;
        if (lim != s->timer) {
            return;
        }
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        FLD(u32, self, 0xf4) |= 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        func_0204a028(data_02097e4c, 0x78, &self->pos, 2);
        self->unk_40->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

}
