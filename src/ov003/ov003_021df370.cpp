#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u8 unk_00[0xa8];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
} Ov003Model;

typedef struct {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0xa];
    s16 unk_1a;
    u8 unk_1c[0x4];
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Model *unk_38;
    u8 unk_3c[0x4];
    u16 *unk_40;
    u8 unk_44[0x2c];
    Ov003Vec3 unk_70;
    u16 unk_7c;
    u8 unk_7e[0x6];
    Ov003Vec3 unk_84;
    u8 unk_90[0x40];
    s32 unk_d0;
} Ov003Prop;

class Ov003DfEffect {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetSpeed(s32 v);
    virtual void v10();
    virtual void SetScaleAll(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetOffset(s32 x, s32 y, s32 z);
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void SetScale(s32 x, s32 y, s32 z);
};

typedef struct {
    u8 unk_00[0x18];
    u16 unk_18;
} Ov003DfSpawn;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003DfKind;

typedef struct {
    u8 unk_00[0x40];
    Ov003DfKind *unk_40;
    u8 unk_44[0x2c];
    Ov003Vec3 pos;
} Ov003DfActor;

typedef struct {
    u8 unk_00[0x40];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
} Ov003DfCam;

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
    u8 unk_ad[0x47];
    Ov003DfCam cam;
} Ov003DfGlobal;

typedef struct {
    u8 unk_00[0x3c];
    s32 unk_3c;
} Ov003DfEffectData;

typedef struct {
    u16 state;
    u16 timer;
} Ov003BgWk;

typedef struct {
    u8 unk_00[0x40];
    Ov003BgWk *work;
    u8 unk_44[0x2c];
    Ov003Vec3 pos;
    u8 unk_7c[0x4];
    u16 unk_80;
} Ov003BgProp;

class Ov003DfObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
};

extern "C" {

extern const s16 FX_SinCosTable_[];
extern void *data_ov000_021ccd68;
extern Ov003DfGlobal *data_ov000_021ccd54;
extern const Ov003Vec3 data_ov003_021f4c58;
extern const u8 data_ov003_021f4c50[];
extern void VEC_Add(const Ov003Vec3 *a, const Ov003Vec3 *b, Ov003Vec3 *out);
extern Ov003DfSpawn *func_ov000_0219be1c(s32 id, const void *pos, const void *rot, u16 a, u16 b);
extern Ov003DfEffect *func_02065f88(s32 id, const Ov003Vec3 *pos);
extern Ov003DfActor *func_ov000_0218e6d0(void *mgr, s32 a, s32 b);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern u16 func_0204bfa8(Ov003DfCam *cam);
extern void func_01ffc9fc(Ov003Vec3 *src, Ov003Vec3 *dst, u16 angle);
extern void func_ov000_02191008(void *p);
extern void func_ov000_0219b71c(Ov003Vec3 *pos, Ov003Vec3 *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern char data_ov003_021f8350[];
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);
extern void func_ov000_02194758(void *p);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049bb4(void *mgr, s32 id);
extern s32 func_02049afc(void *mgr, s32 v);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(Ov003Unit *u, s32 a, s32 b);

void func_ov003_021df0c8(Ov003BgProp *self) {
    Ov003BgWk *w = self->work;
    switch (w->state) {
    case 0:
        w->timer++;
        if (w->timer > 0x3c) {
            Ov003DfEffect *e;
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x4035, 0x15);
            func_ov000_0218996c(0x3c, 0x78);
            e = func_02065f88(5, &self->pos);
            if (e != NULL) {
                e->SetScaleAll(0x9800, 0x9800, 0x9800);
                e->SetOffset(0, -0x32000, 0x1e000);
                ((Ov003DfEffectData *)e)->unk_3c = 0xccd;
            }
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02049a48(data_02097e4c, 0x53, -1, -1, -1);
            self->work->timer = 0;
            self->work->state++;
        } else {
            self->pos.y -= 0xa8f;
        }
        break;
    case 1:
        if (w->timer == 0x5a) {
            func_ov000_02197dec(self, 0xf, 4);
        }
        if (self->work->timer > 0x96) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((Ov003DfObj *)self)->Destroy();
            return;
        }
        if ((self->work->timer & 0xf) == 0) {
            Ov003Vec3 p;
            Ov003Vec3 sc;
            s32 a = -1;
            s32 b = 100;
            switch (self->work->timer & 0x3f) {
            case 0:
                func_02049a48(data_02097e4c, 0x19, a, a, a);
                func_ov000_0218996c(0xf, 0x1e);
                a = 3;
                break;
            case 0x10:
                b = 100;
                break;
            case 0x30:
                b = 100;
                break;
            case 0x20:
                func_02049a48(data_02097e4c, 0x19, a, a, a);
                func_ov000_0218996c(0xf, 0x1e);
                break;
            }
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y -= 0x32000;
            p.z += 0x28000;
            sc.x = 0x5000;
            sc.y = 0x2800;
            sc.z = 0x1800;
            func_ov000_0219b71c(&p, &sc, 0x2800, 0x3800, a, b);
        }
        self->work->timer++;
        self->pos.y -= 0xcd;
        self->unk_80 += 3;
        break;
    }
}

Ov003Prop *func_ov003_021df370(Ov003Prop *self) {
    self->vtbl = data_ov003_021f8350;
    if (self->unk_d0 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_d0);
    }
    func_ov000_0219429c(self);
    return self;
}

Ov003Prop *func_ov003_021df3b0(Ov003Prop *self) {
    self->vtbl = data_ov003_021f8350;
    if (self->unk_d0 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_d0);
    }
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021df3f8(Ov003Prop *self) {
    Ov003Unit *u;
    s32 s;
    func_ov000_02194758(self);
    s = self->unk_1a;
    if (s != 0) {
        Ov003Model *m = self->unk_38;
        m->unk_a8 = s;
        m->unk_ac = s;
        m->unk_b0 = s;
    }
    self->unk_84.x = self->unk_70.x;
    self->unk_84.y = self->unk_70.y;
    self->unk_84.z = self->unk_70.z;
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
        func_ov000_0218b700(u, 0x5000, 0);
    }
    self->unk_d0 = func_02049afc(data_02097e4c, 0x3f);
}

void func_ov003_021df484(Ov003Prop *self) {
    s32 d;
    s32 diff;
    u16 a;
    u16 shift = 9;
    u16 *st = self->unk_40;
    a = st[1] + 0x80;
    st[1] = a;
    if (self->unk_1a != 0) {
        shift -= 3;
    }
    d = FX_SinCosTable_[(a >> 4) * 2] >> shift;
    if (d > 1 || d < -1) {
        self->unk_70.y += d;
    }
    diff = self->unk_70.y - self->unk_84.y;
    if (diff < -0x99a) {
        self->unk_70.y = self->unk_84.y - 0x99a;
    }
    if (diff > 0x99a) {
        self->unk_70.y = self->unk_84.y + 0x99a;
    }
}

void func_ov003_021df528(Ov003Prop *self) {
    func_ov003_021df484(self);
}

static inline s32 Ov003DfKind_Get(Ov003DfKind *k) {
    return k != NULL ? k->kind : 0;
}

void func_ov003_021df534(Ov003Prop *self) {
    switch (self->unk_40[0]) {
    case 0: {
        Ov003Vec3 v;
        Ov003DfSpawn *sp;
        VEC_Add(&self->unk_70, &data_ov003_021f4c58, &v);
        sp = func_ov000_0219be1c(0x480b, &v, data_ov003_021f4c50, self->unk_0c, 0xffff);
        if (sp != NULL) {
            sp->unk_18 = 7;
            func_02065f88(0x325, &v)->SetScale(0, 0x3800, 0);
        }
        self->unk_40[0]++;
        break;
    }
    case 1: {
        Ov003DfActor *a;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x480b);
        }
        if (a != NULL && Ov003DfKind_Get(a->unk_40) != 0x15) {
            goto end;
        }
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        if (a != NULL) {
            Ov003Vec3 p;
            Ov003DfEffect *e;
            p.x = a->pos.x;
            p.y = a->pos.y;
            p.z = a->pos.z;
            e = func_02065f88(0x325, &p);
            if (e != NULL) {
                e->SetSpeed(0x1c00);
                e->SetScale(0, 0x3800, 0);
            }
            func_02065f88(3, &p);
        }
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        data_ov000_021ccd54->unk_ac = 1;
        self->unk_40[0]++;
        break;
    }
    }
end:
    func_ov003_021df484(self);
}

static inline u16 Ov003DfCam_GetAngle(Ov003DfCam *cam) {
    return cam->unk_40 != 0 ? cam->unk_44 : func_0204bfa8(cam);
}

void func_ov003_021df6f4(Ov003Prop *self) {
    Ov003DfCam *cam = &data_ov000_021ccd54->cam;
    switch (self->unk_40[0]) {
    case 0: {
        Ov003Vec3 v;
        v.x = 0x2c00;
        v.y = -0x1000;
        v.z = 0x4000;
        func_01ffc9fc(&v, &v, Ov003DfCam_GetAngle(cam));
        VEC_Add(&self->unk_70, &v, &self->unk_70);
        self->unk_7c = 0xfff0;
        func_ov000_02191008(self->unk_38);
        func_02049bb4(data_02097e4c, self->unk_d0);
        self->unk_d0 = -1;
        self->unk_40[0]++;
    }
    case 1:
        if ((self->unk_40[1] & 0xf) == 0) {
            Ov003Vec3 p;
            Ov003Vec3 sc;
            s32 a = -1;
            s32 b = 100;
            switch (self->unk_40[1] & 0x3f) {
            case 0:
                a = 3;
                break;
            case 0x10:
                break;
            case 0x20:
                a = 3;
                b = 75;
                break;
            case 0x30:
                a = 3;
                b = 25;
                break;
            }
            p.x = self->unk_70.x;
            p.y = self->unk_70.y;
            p.z = self->unk_70.z;
            p.y += 0x3000;
            sc.x = 0x2800;
            sc.y = 0x2800;
            sc.z = 0x2800;
            func_ov000_0219b71c(&p, &sc, 0xccd, 0x159a, a, b);
        }
        if (self->unk_40[1] > 0x1c2) {
            func_ov000_02197dec(self, 0xf, 4);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((Ov003DfObj *)self)->Destroy();
            return;
        }
        ((volatile u16 *)self->unk_40)[1]++;
        self->unk_70.x -= 0x66;
        self->unk_70.y -= 0x3d;
        if (self->unk_7c > 0xe800) {
            self->unk_7c -= 0x1c;
        }
        break;
    }
}

}
