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

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

extern const char *const data_ov014_02216430[];
extern const Ov014Vec data_ov014_02216444;
extern const s32 data_ov014_022164e8[];
extern u8 data_ov014_022172c4[];
extern void *data_ov000_021ccd68;
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov003_021d6a3c(Ov014Actor *self, s32 a, s32 b, s32 c);
extern Ov014Actor *func_ov000_02192b24(Ov014SpawnDesc *desc);
extern void func_ov000_0219bebc(Ov014Actor *a, s32 b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void *func_ov000_02194074(void *self);
extern void *func_ov003_021da940(void *p);
extern void func_ov000_02194758(void *self);

void func_ov014_021fb8dc(Ov014Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    FLD(u16, self, 0x312) = 0x14bf;
    FLD(u16, self, 0x314) = 0x14bf;
    FLD(u16, self, 0x316) = 0xb;
    FLD(u16, self, 0x318) = 0xa;
    FLD(s32, self, 0xf4) = 1;
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov014_021fb92c(Ov014Actor *self) {
    FLD(s32, self, 0xf4) = 1;
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov014_021fb948(Ov014Actor *self) {
    const char *anim;
    Ov014Sub40 *st;
    FLD(Ov014Flags, self, 0xea).b9 = 1;
    switch (self->unk_40->state) {
    case 0:
        anim = data_ov014_02216430[0];
        func_ov000_02190cb0(self->unk_38, anim, 0x111, 0);
        func_ov000_021911c8(self->unk_38, 0x1ec);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02190cb0((u8 *)self + 0x25c, anim, 0x111, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
        func_ov000_021915a0((u8 *)self + 0x25c);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4821, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4822, 0x15);
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        {
            Ov014Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            func_ov003_021d6a3c(self, 0, 1, 1);
            self->unk_40->state++;
        }
        break;
    }
}

void func_ov014_021fbab8(Ov014Actor *self, s16 n) {
    Ov014SpawnDesc desc;
    Ov014Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x4821);
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    o->unk_18 = n;
    o->pos = FLD(Ov014Vec, self, 0x110);
    func_ov000_0219bebc(o, FLD(s16, self, 0x364));
    o->v04();
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    o->unk_90 = self->unk_90;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
}

void func_ov014_021fbb90(Ov014Actor *self, s16 n) {
    Ov014SpawnDesc desc;
    Ov014Vec v;
    Ov014Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x4822);
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    VEC_Add(&self->pos, &data_ov014_02216444, &v);
    o->pos = v;
    o->unk_18 = n;
    func_ov000_0219bebc(o, FLD(s16, self, 0x364));
    o->v04();
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    o->unk_90 = self->unk_90;
    FLD(u16, self, 0xde) = o->id;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
}

void func_ov014_021fbc88(Ov014Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov014_021fbca8(Ov014Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}

void func_ov014_021fbcc8(void) {
}

void func_ov014_021fbccc(void) {
}

void func_ov014_021fbcd0(void) {
}

void func_ov014_021fbcd4(void) {
}

void func_ov014_021fbcd8(void) {
}

void func_ov014_021fbcdc(void) {
}

void func_ov014_021fbce0(void) {
}

void func_ov014_021fbce4(Ov014Actor *self) {
    self->v54();
}

void func_ov014_021fbcf8(Ov014Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}

void func_ov014_021fbd18(Ov014Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}

void func_ov014_021fbd3c(Ov014Actor *self) {
    self->v60();
}

void func_ov014_021fbd50(Ov014Actor *self) {
    self->v7c();
}

#pragma force_active on
Ov014Actor *func_ov014_021fbd64(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_022172c4;
    FLD(u8, self, 0xce) = 0;
    FLD(void *, self, 0xd0) = NULL;
    return self;
}
#pragma force_active reset

static inline void Ov014_FreeD0(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xd0) != NULL) {
        void *p = FLD(void *, self, 0xd0);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0xd0) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_021fbd90(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022172c4;
    Ov014_FreeD0(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_021fbe00(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022172c4;
    Ov014_FreeD0(self);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_021fbe78(Ov014Actor *self) {
    s16 n;
    s32 *p;
    func_ov000_02194758(self);
    n = self->unk_18;
    if (self->pos.y > 0x5000) {
        self->pos.y = 0x5000;
    }
    if (n < 10) {
        self->pos.x = self->pos.x + data_ov014_022164e8[n];
    } else {
        self->pos.x = self->pos.x - data_ov014_022164e8[(s16)(n % 10)];
    }
    p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(s32 *, self, 0xd0) = p;
}


extern void *data_02097e4c;
extern char data_ov014_022171d0[];
extern char data_ov014_022171df[];
extern char data_ov014_022171f1[];
extern char data_ov014_022171fd[];
extern Ov014V *func_02066900(const char *arc, const char *name, Ov014Vec *pos);
extern Ov014V *func_02066774(const void *a, const void *b, s32 c, Ov014Vec *pos);
extern void MIi_CpuClear32(u32 data, void *dst, u32 size);
extern void func_ov003_021da9ac(void *p, s32 id, void *e);
extern BOOL func_ov003_021daa0c(void *p, s32 id);
extern void func_ov003_021daa6c(void *p, s32 id);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern s32 FX_Div(s32 a, s32 b);
extern void func_020639d4(void *e, s32 a, s32 b);
extern BOOL func_ov000_0219aca8(Ov014Actor *a, Ov014Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);

struct Ov014Ccd190 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

void func_ov014_021fbf0c(Ov014Actor *self) {
    Ov014V *e;
    switch (self->unk_40->state) {
    case 0:
        e = func_02066900(data_ov014_022171d0, data_ov014_022171df, &self->pos);
        e->v24(0, 0xcd, 0);
        e->v0c(0x1333);
        MIi_CpuClear32(0xffffffff, (u8 *)e + 0x84, 0x40);
        func_ov003_021da9ac(FLD(void *, self, 0xd0), 0xff, e);
        func_0204a028(data_02097e4c, 0x11, &self->pos, 0xa);
        e = func_02066774(data_ov014_022171d0, data_ov014_022171f1, 0, &self->pos);
        e->v24(0, 0xcd, 0);
        e->v0c(0x2000);
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = 1;
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        func_ov003_021da9ac(FLD(void *, self, 0xd0), 0xfe, e);
        self->unk_40->state++;
    case 1:
        if (func_ov003_021daa0c(FLD(void *, self, 0xd0), 0xfe)) {
            break;
        }
        func_ov003_021daa6c(FLD(void *, self, 0xd0), 0xff);
        self->unk_40->state++;
    case 2: {
        Ov014Game54 *g;
        e = func_02066774(data_ov014_022171d0, data_ov014_022171fd, 0, &self->pos);
        e->v14(0x14cd, 0x1800, 0x14cd);
        FLD(s32, e, 0x3c) = 0x1800;
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        FLD(u8, e, 0x28) = 0;
        func_020639d4(e, 0x79, 3);
        func_ov003_021da9ac(FLD(void *, self, 0xd0), 0xfd, e);
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0x140);
        g = data_ov000_021ccd54;
        FLD(Ov014Ccd190, g, 0x190).b2 = 0;
        FLD(Ov014Ccd190, g, 0x190).b3 = 1;
        FLD(Ov014Ccd190, g, 0x190).b4 = 0;
        FLD(u8, g, 0x18d) = 0xf;
        FLD(u8, g, 0x18e) = 5;
        FLD(u8, g, 0x18f) = 5;
        self->unk_40->state++;
    }
    case 3: {
        Ov014Param *pr = FLD(Ov014Param *, self, 0x4c);
        if (func_ov000_0219aca8(self, self, pr->unk_08, FLD(u16, pr, 0xa), 0, 0, 0x119a, 0x5000, 0x6b, 0x1000)) {
            Ov014Actor *o = func_ov000_0218d240(self);
            if (o != NULL) {
                Ov014Vec v;
                v.x = o->pos.x;
                v.y = o->pos.y;
                v.z = o->pos.z;
                func_02049f44(data_02097e4c, 0x10, &v, 0);
            }
        }
        if (!func_ov003_021daa0c(FLD(void *, self, 0xd0), 0xfd)) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    }
    func_ov003_021dacfc(FLD(void *, self, 0xd0));
}

}
