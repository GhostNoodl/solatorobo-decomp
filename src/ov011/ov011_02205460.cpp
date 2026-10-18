#include "ov011/ov011.h"

struct Ov011SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov011Spawn_Init(Ov011SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

struct Ov011Rot {
    s16 x, y, z;
};

struct Ov011B16 {
    u8 b0 : 1;
    u8 rest : 7;
};

extern "C" {

extern void *data_ov000_021ccd64;
extern const u16 data_ov011_0220751c[];
s32 func_02040498(s32 max);
void *func_ov000_0218bf1c(void *mgr, Ov011SpawnDesc *d, Ov011Vec *pos, Ov011Rot *rot, u16 a);
void *func_ov000_0214b670(void *p);

#pragma force_active on
void func_ov011_02205460(void *self, u16 t, BOOL b) {
    {
    s32 m = 0x5f;
    if (b) {
        m = 200;
    }
    if (t % m == 1) {
        Ov011Vec pos;
        Ov011Rot rot;
        Ov011SpawnDesc d;
        s32 r;
        u16 k;
        void *o;
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        rot.x = 0;
        rot.y = 0;
        rot.z = 0;
        r = func_02040498(7);
        k = data_ov011_0220751c[r];
        if (b && (k == 0x409b || k == 0x409c)) {
            k = 0x409d;
        }
        Ov011Spawn_Init(&d, k);
        if ((k == 0x409b || k == 0x409c)) {
            d.unk_04[2] = 3;
        }
        d.unk_04[3] = 1;
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &pos, &rot, 0xffff);
        if (o != NULL) {
            void *x;
            FLD(Ov011B16, o, 0x16).b0 = 1;
            x = NULL;
            if (r & 1) {
                if (FLD(void *, self, 0x364) != NULL && FLD(u8, self, 0x394) == 0) {
                    x = func_ov000_0214b670(FLD(void *, self, 0x364));
                }
            } else {
                if (FLD(void *, self, 0x368) != NULL && FLD(u8, self, 0x394) == 0) {
                    x = func_ov000_0214b670(FLD(void *, self, 0x368));
                }
            }
            FLD(void *, o, 0x60) = x;
        }
    }
    }
    {
    s32 m = 0x23;
    if (b) {
        m = 0x4b;
    }
    if (t % m == 1) {
        Ov011Vec pos;
        Ov011Rot rot;
        Ov011SpawnDesc d;
        void *o;
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        rot.x = 0;
        rot.y = 0;
        rot.z = 0;
        Ov011Spawn_Init(&d, 0x409e);
        d.unk_04[3] = 2;
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &pos, &rot, 0xffff);
        if (o != NULL) {
            FLD(Ov011B16, o, 0x16).b0 = 1;
        }
    }
    }
}
#pragma force_active reset


void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov011_02205460(void *self, u16 t, s32 c);

#pragma force_active on
void func_ov011_02205674(void *self) {
    u16 *st = FLD(u16 *, self, 0x40);
    switch (st[0]) {
    case 0:
        if (st[1] > 0x12c) {
            Ov011Game54 *g;
            func_020627a0(FLD(u16, self, 0xe), FLD(u16, self, 0xc));
            func_020627dc(4);
            g = data_ov000_021ccd54;
            FLD(u8, g, 0xac) = 1;
            func_ov000_02182590((u8 *)g + 0xac);
            FLD(u16 *, self, 0x40)[0]++;
        }
        break;
    case 1:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(st, 0x23, 0);
        }
        break;
    }
    FLD(u16 *, self, 0x40)[1]++;
    func_ov011_02205460(self, FLD(u16 *, self, 0x40)[1], 0);
}

extern Ov011Vec data_02092a50;
s32 *func_02027240(void);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);
void func_ov000_0218d46c(void *o, u16 id, s32 c);

static inline void Ov011_MulVec33(const Ov011Vec *v, const s32 *m, Ov011Vec *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m[0] + (s64)y * m[3] + (s64)z * m[6]) >> 12);
    out->y = (s32)(((s64)x * m[1] + (s64)y * m[4] + (s64)z * m[7]) >> 12);
    out->z = (s32)(((s64)x * m[2] + (s64)y * m[5] + (s64)z * m[8]) >> 12);
}

void func_ov011_0220576c(void *self) {
    u16 *st = FLD(u16 *, self, 0x40);
    switch (st[0]) {
    case 0: {
        Ov011Vec v;
        Ov011Rot rot;
        Ov011SpawnDesc d;
        void *o;
        v.x = 0;
        v.y = -0xa000;
        v.z = -0xa000;
        Ov011_MulVec33(&v, func_02027240(), &v);
        VEC_Add(&v, &data_02092a50, &v);
        rot.x = 0;
        rot.y = 0;
        rot.z = 0;
        Ov011Spawn_Init(&d, 0x406a);
        d.unk_04[1] = 2;
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, &rot, 0xffff);
        if (o != NULL) {
            FLD(u16, self, 0x36c) = FLD(u16, o, 0xc);
            FLD(Ov011B16, o, 0x16).b0 = 1;
            func_ov000_0218d46c(o, FLD(u16, self, 0xc), 6);
        }
        FLD(u16 *, self, 0x40)[0]++;
    }
    case 1:
        if (FLD(u16 *, self, 0x40)[1] > 0x96) {
            void *a = Ov011_FindActor(FLD(u16, self, 0x36c));
            Ov011Game54 *g;
            if (a != NULL) {
                FLD(u16, a, 0x18) = 2;
            }
            func_020627a0(FLD(u16, self, 0xe), FLD(u16, self, 0xc));
            func_020627dc(4);
            g = data_ov000_021ccd54;
            FLD(u8, g, 0xac) = 1;
            func_ov000_02182590((u8 *)g + 0xac);
            FLD(u16 *, self, 0x40)[0]++;
        }
        break;
    case 2:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(st, 0x24, 0);
        }
        break;
    }
    FLD(u16 *, self, 0x40)[1]++;
    func_ov011_02205460(self, FLD(u16 *, self, 0x40)[1], 1);
}

struct Ov011C2 {
    u16 b0 : 1;
    u16 rest : 15;
};

void func_ov011_022059f8(void *self) {
    u16 *st = FLD(u16 *, self, 0x40);
    switch (st[0]) {
    case 0: {
        void *a;
        void *p = FLD(void *, self, 0x38);
        FLD(s32, p, 0xa8) = 0;
        FLD(s32, p, 0xac) = 0;
        FLD(s32, p, 0xb0) = 0;
        FLD(u8, FLD(void *, self, 0x38), 0xbe) = 0;
        FLD(Ov011C2, FLD(void *, self, 0x38), 0xc2).b0 = 1;
        a = Ov011_FindActor(FLD(u16, self, 0x36c));
        if (a != NULL) {
            FLD(u16, a, 0x18) = 3;
        }
        FLD(u16 *, self, 0x40)[0]++;
        break;
    }
    case 1:
        st[1]++;
        if (st[1] >= 0xb4) {
            Ov011V *a = (Ov011V *)Ov011_FindActor(FLD(u16, self, 0x36c));
            if (a != NULL) {
                a->v08();
            }
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0]++;
        }
        break;
    case 2:
        st[1]++;
        if (st[1] > 0x3c) {
            Ov011Game54 *g;
            func_020627a0(FLD(u16, self, 0xe), FLD(u16, self, 0xc));
            func_020627dc(4);
            g = data_ov000_021ccd54;
            FLD(u8, g, 0xac) = 1;
            func_ov000_02182590((u8 *)g + 0xac);
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0]++;
        }
        break;
    case 3:
        if (Ov011_GameIdle()) {
            func_ov000_02198360(st, 0x22, 0);
        }
        break;
    }
}
#pragma force_active reset
}
