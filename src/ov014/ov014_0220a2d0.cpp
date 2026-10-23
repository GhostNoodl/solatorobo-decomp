#include "ov014/ov014.h"

struct Ov014Vec16 {
    s16 x;
    s16 y;
    s16 z;
};

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

extern void *data_ov000_021ccd64;
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014SpawnDesc *d, Ov014Vec *pos, Ov014Vec16 *rot, u16 a);

void func_ov014_0220a2d0(Ov014Actor *self, u16 a) {
    Ov014Vec v;
    s32 spd;
    u16 ang;
    Ov014Vec pos;
    Ov014SpawnDesc desc;
    Ov014Vec16 rot;
    Ov014Actor *o;
    s32 base;
    pos.x = 0;
    pos.y = 0x5000;
    pos.z = 0x2000;
    pos.x = func_02040528(0x6000);
    pos.x += pos.x > 0 ? 0x3000 : -0x3000;
    pos.z += func_02040498(0x1000);
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    base = pos.x > 0 ? 0xc000 : 0x4000;
    if (FLD(u16, self, 0xf8) % 2 != 0) {
        ang = base + (u16)func_02040498(0x4000);
    } else {
        ang = base - (u16)func_02040498(0x4000);
    }
    spd = func_02040498(0x3800) + 0x3800;
    v.x = Ov014_FxMul(spd, OV014_SIN(ang));
    v.z = Ov014_FxMul(spd, OV014_COS(ang)) + 0x8000;
    Ov014Spawn_Init(&desc, 0x481d);
    desc.unk_04[0] = a;
    FLD(u16, self, 0xde) = 0xffff;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    o->unk_84.x = v.x;
    o->unk_84.y = 0;
    o->unk_84.z = v.z;
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    FLD(u16, self, 0xde) = o->id;
}

void func_ov014_0220a490(Ov014Actor *self, Ov014Vec *vel, u16 a, u16 b, u16 c) {
    Ov014SpawnDesc desc;
    Ov014Vec pos;
    Ov014Vec16 rot;
    Ov014Actor *o;
    Ov014Spawn_Init(&desc, 0x4819);
    desc.unk_04[0] = a;
    desc.unk_04[1] = b;
    desc.unk_04[2] = c;
    desc.parent = -1;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    FLD(u16, self, 0xde) = 0xffff;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    if (vel != NULL) {
        s32 x = vel->x; s32 y = vel->y; o->unk_84.x = x; s32 z = vel->z; o->unk_84.y = y; o->unk_84.z = z;
    } else {
        o->unk_90 = self->unk_90;
    }
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    FLD(u16, self, 0xde) = o->id;
}


extern u8 data_ov014_02217a48[];
extern u8 data_ov014_02217a4e[];
extern u8 data_ov014_02217a54[];
extern void func_ov000_021911c8(void *a, s32 b);
extern BOOL func_02049244(Ov014Vec *out, s32 speed, const Ov014Vec *from, const Ov014Vec *to, s32 minDist);

void func_ov014_0220a588(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        const void *anim;
        anim = data_ov014_02217a48;
        if (FLD(u8, self, 0x1a5) == 0) {
            anim = data_ov014_02217a4e;
        }
        if (self->unk_ee_0) {
            anim = data_ov014_02217a54;
        }
        func_ov000_02190cb0(self->unk_38, anim, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0xc00);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    if (FLD(u8, self, 0x1a5) == 0) {
        func_02049244(&self->pos, 0xcd, &self->pos, (Ov014Vec *)((u8 *)self + 0x1a8), 0xcd);
    } else if (self->unk_48->unk_9a_4) {
        self->unk_48->unk_9a_5 = 1;
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            func_ov000_02198360(self->unk_40, 4, 0);
        }
    }
}


extern const Ov014Vec data_ov014_02216aa8[];
extern u8 data_ov014_02217a48[];
extern u8 data_ov014_02217a5a[];
extern u8 data_ov014_02217a60[];
extern u8 data_ov014_02217a66[];
extern u8 data_ov014_02217a6c[];
extern void *data_ov000_021ccd68;
extern u16 FX_Atan2(s32 y, s32 x);
extern BOOL func_01ffc584(Ov014Vec *a, Ov014Vec *b, s32 c, s32 d);
extern void func_ov000_02191618(void *p);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void VEC_Normalize(const Ov014Vec *a, Ov014Vec *b);
extern BOOL func_02049244(Ov014Vec *out, s32 speed, const Ov014Vec *from, const Ov014Vec *to, s32 minDist);
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *t, s32 a);

static inline Ov014Actor *Ov014h_FindById(u16 id) {
    return data_ov000_021ccd68 != NULL ? func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
}

void func_ov014_0220a67c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        s16 *p = FLD(s16 *, self, 0xf0);
        Ov014Vec a;
        Ov014Vec b;
        Ov014Vec c;
        u16 ang;
        s32 d;
        const void *anim;
        Ov014V *e;
        if (p[0] == 0xb) {
            self->unk_b8 = data_ov014_02216aa8[(u16)p[2]];
        } else {
            s32 i = func_02040498(6);
            self->unk_b8 = data_ov014_02216aa8[i];
        }
        self->unk_9c = self->unk_b0->unk_00;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        a = self->pos;
        b = self->unk_b8;
        if (func_01ffc584(&a, &b, 0x1800, 0x2800)) {
            self->unk_40->state = 0x14;
            self->unk_40->timer = 0x1e;
            break;
        }
        d = FX_Atan2(b.x - self->pos.x, b.z - self->pos.z) - self->rot[1];
        if (self->unk_ee_0) {
            anim = data_ov014_02217a5a;
        } else if ((d < 0 ? -d : d) < 0x1fff) {
            anim = data_ov014_02217a60;
        } else if ((d < 0 ? -d : d) > 0x5ffd) {
            anim = data_ov014_02217a60;
        } else if (d > 0) {
            anim = data_ov014_02217a66;
        } else {
            anim = data_ov014_02217a6c;
        }
        func_ov000_02190cb0(self->unk_38, anim, 0x2ab, 0);
        func_ov000_02191618(self->unk_38);
        FLD(Ov014Vec, self, 0x1b4) = self->pos;
        c = self->unk_48->unk_68;
        ang = FX_Atan2(b.x - self->pos.x, b.z - self->pos.z);
        e = func_02065f88(0x67, &c);
        e->v0c(0x2000);
        e->v34(0, ang, 0);
        self->unk_40->state = 0xa;
        self->unk_40->timer = 0x5a;
        break;
    }
    case 0xa: {
        Ov014Vec t;
        Ov014Vec p;
        Ov014Vec d;
        BOOL near = FALSE;
        s32 s;
        Ov014Sub40 *m;
        self->unk_48->unk_9a_5 = 1;
        t = self->unk_b8;
        p = self->pos;
        d.x = t.x - p.x;
        d.y = t.y - p.y;
        d.z = t.z - p.z;
        VEC_Normalize(&d, &d);
        s = Ov014_FxMul(VEC_Distance(&p, &FLD(Ov014Vec, self, 0x1b4)), 0x19a);
        if (s < 0x4cd) {
            s = 0x4cd;
        } else if (s > 0x99a) {
            s = 0x99a;
        }
        VEC_MultAdd(s, &d, &p, &p);
        self->pos = p;
        if (VEC_Distance(&p, &t) < 0x3000) {
            near = TRUE;
        }
        if (self->unk_40->timer == 0x46) {
            Ov014V *e = func_02065f88(0x192, &self->pos);
            e->v0c(0x3000);
            e->v34(0, FX_Atan2(t.x - self->pos.x, t.z - self->pos.z), 0);
        }
        if (near) {
            FLD(s32, self, 0x1e4) = 0;
            self->unk_40->timer = 0x1e;
            self->unk_40->state = 0x14;
            break;
        }
        m = self->unk_40;
        if (m->timer != 0) {
            m->timer--;
        }
        if (m->timer == 0) {
            FLD(s32, self, 0x1e4) = 0;
            self->unk_40->state = 0x14;
        }
        break;
    }
    case 0x14:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a48, 0xcd, 0);
        self->unk_40->state++;
        self->unk_40->timer = 0x1e;
    case 0x15: {
        Ov014Vec q;
        Ov014Vec r;
        Ov014Actor *o;
        Ov014Sub40 *m;
        q = self->unk_b8;
        r = self->pos;
        func_02049244(&r, 0x19a, &r, &q, 0x800);
        self->pos = r;
        o = Ov014h_FindById(self->unk_90);
        if (o != NULL) {
            func_ov000_0218d988(self, o, self->unk_b0->unk_02);
        }
        m = self->unk_40;
        if (m->timer != 0) {
            m->timer--;
        }
        if (m->timer == 0) {
            self->unk_40->state++;
        }
        break;
    }
    case 0x16:
        self->unk_40->state = 0xffff;
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

}
