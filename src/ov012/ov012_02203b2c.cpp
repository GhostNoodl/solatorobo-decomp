#include "ov012/ov012.h"

extern "C" {

extern char data_ov012_0220afc4[];
extern char data_ov012_0220afca[];
extern Ov012Vec data_ov012_0220a624[];
extern u8 data_ov012_0220a68c[];
extern void func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov000_021911c8(void *p, s32 a);

extern Ov012Vec data_ov012_0220a5ac;
extern Ov012Vec data_ov012_0220a618;
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov012_02205254(Ov012Actor *self);

struct Ov012bEA2 {
    u16 b0 : 3;
};

void func_ov012_02203b2c(Ov012Actor *self) {
    Ov012Vec p;
    p = func_ov000_0218d240(self)->pos;
    switch (self->unk_40->state) {
    case 0:
        func_02049f44(data_02097e4c, 0x401, &self->pos, 0);
        switch (FLD(u8, self, 0xf9)) {
        case 0:
            func_ov000_02190cb0(self->unk_38, data_ov012_0220afc4, 0x400, 0);
            break;
        case 1:
            func_ov000_02190cb0(self->unk_38, data_ov012_0220afca, 0x400, 0);
            break;
        }
        if ((u16)(FLD(u16 *, self, 0x50)[0] * 100 / FLD(u16 *, self, 0x50)[1]) < 0x23) {
            func_ov000_021911c8(self->unk_38, 0x1333);
        }
        self->unk_40->state++;
        break;
    case 1:
        if (!(FLD(u32, self, 0xf0) & 0x100000)) {
            func_ov000_0218d918(self, &p, 0x19a);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 3) {
            func_0204a028(data_02097e4c, 0x12, &self->pos, 0xf);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov012Vec v;
            Ov012SpawnDesc d;
            Ov012Actor *o;
            FLD(u32, self, 0xf0) |= 0x100000;
            Ov012Spawn_Init(&d, 0x480d);
            v = data_ov012_0220a624[FLD(u8, self, 0xf9)];
            func_01ffc9fc(&v, &v, self->rot[1]);
            VEC_Add(&self->pos, &v, &v);
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
            if (o != NULL) {
                FLD(void *, o, 0x60) = data_ov012_0220a68c;
                func_ov000_0219bebc(o, FLD(s16, self, 0x124));
                FLD(Ov012Flags8, o, 0x16).b0 = 1;
                o->unk_90 = self->unk_90;
                if (FLD(void *, o, 0x4c) != NULL) {
                    FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
                }
            }
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        if (++FLD(u8, self, 0xf9) >= 2) {
            FLD(u8, self, 0xf9) = 0;
        }
        {
            u16 n = 0;
            if (FLD(void *, self, 0x104) != NULL) {
                n = FLD(u16, FLD(void *, self, 0x104), 4);
            }
            if (++FLD(u8, self, 0xfb) >= n) {
                self->unk_40->state = 0x1e;
            } else {
                func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c[0], 0x111, 0);
                func_ov000_021915a0(self->unk_38);
                self->unk_40->state = 10;
            }
        }
        FLD(u32, self, 0xf0) ^= 0x100000;
        break;
    case 10: {
        Ov012Sub40 *w;
        func_ov000_0218d918(self, &p, 0xcd);
        w = self->unk_40;
        w->timer++;
        if (w->timer >= FLD(u16, FLD(void *, self, 0x104), 2)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    case 0x1e:
        if (FLD(u32, self, 0xf0) & 0x20) {
            FLD(u32, self, 0xf0) ^= 0x20;
        }
        FLD(u32, self, 0xf0) |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

void func_ov012_02203ed4(Ov012Actor *self) {
    Ov012Vec v;
    switch (self->unk_40->state) {
    case 0:
        FLD(Ov012bEA2, self, 0xea).b0 = 4;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220afca, 0x111, 0);
        self->unk_40->state++;
        break;
    case 1: {
        Ov012V *e;
        if (FLD(s16, self->unk_38, 0xc4) != 2) {
            break;
        }
        e = func_02065f88(0x644, &self->pos);
        v.x = -0x1000;
        v.y = 0x2ccd;
        v.z = 0x4000;
        func_01ffc9fc(&v, &v, self->rot[1]);
        e->v20(&v);
        func_ov003_021da9ac(FLD(void *, self, 0x100), 0, e);
        func_ov000_02191690(self->unk_38);
        func_0204a028(data_02097e4c, 0x12, &self->pos, 0xa);
        self->unk_40->state++;
        break;
    }
    case 2:
        if (func_ov003_021daa0c(FLD(void *, self, 0x100), 0)) {
            break;
        }
        func_02049f44(data_02097e4c, 0x402, &self->pos, 0);
        func_ov000_02191708(self->unk_38);
        self->unk_40->state++;
        break;
    case 3:
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov012V *e;
            func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
            func_ov012_02205254(self);
            e = func_02065f88(0x12d, &self->pos);
            v.x = -0x1000;
            v.y = 0x2ccd;
            v.z = 0x4000;
            func_01ffc9fc(&v, &v, self->rot[1]);
            e->v20(&v);
            e = func_02065f88(0x6b, &self->pos);
            v.x = -0x1000;
            v.y = 0x2ccd;
            v.z = 0x4000;
            func_01ffc9fc(&v, &v, self->rot[1]);
            e->v20(&v);
        }
        if (func_ov000_02191120(self->unk_38)) {
            FLD(Ov012bEA2, self, 0xea).b0 = self->unk_b0->unk_0a_7;
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c[0], 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e: {
        s32 n = func_ov003_021d9edc(0x4824);
        if (((u8)(FLD(u8, self, 0xf8) + 0xff) <= 1 && n <= 1) || n == 0) {
            FLD(u8, self, 0xf8) = 0;
            if (FLD(u32, self, 0xf0) & 4) {
                FLD(u32, self, 0xf0) ^= 4;
            }
            FLD(u32, self, 0xf0) |= 1;
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    }
    switch (FLD(u8, data_ov000_021ccd54, 0xca)) {
    case 8:
        func_ov000_0218d918(self, &data_ov012_0220a618, 0x400);
        break;
    case 3:
        func_ov000_0218d918(self, &data_ov012_0220a5ac, 0x400);
        break;
    }

}



extern char data_ov012_0220afd0[];
extern Ov012Vec data_ov012_0220a60c;
extern Ov012Vec data_ov012_0220a600;
extern void func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);

struct Ov012Blk12R {
    s32 w[3];
};

struct Ov012bEA3 {
    u16 b0 : 3;
};

#define OV012R_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012R_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012R_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov012_0220422c(Ov012Actor *self) {
    Ov012Vec t;
    Ov012Vec *pos;
    Ov012Vec q;
    Ov012Vec c;
    Ov012Vec d2;
    Ov012Vec v;
    Ov012SpawnDesc d;
    Ov012Vec d14;
    Ov012Sub40 *s;
    pos = &self->pos;
    self->unk_94_1 = 1;
    FLD(Ov012bEA3, self, 0xea).b0 = 4;
    s = self->unk_40;
    switch (s->state) {
    case 0: {
        func_ov000_02190cb0(self->unk_38, data_ov012_0220afd0, 0x111, 0);
        VEC_Add(pos, &data_ov012_0220a60c, &t);
        self->unk_b8 = t;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            break;
        }
        func_02065f88(0x12f, pos);
        self->unk_40->state++;
        break;
    case 2: {
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            func_ov000_02191690(self->unk_38);
        }
        t = self->unk_b8;
        d2.x = t.x - self->pos.x;
        d2.y = t.y - self->pos.y;
        d2.z = t.z - self->pos.z;
        VEC_MultAdd(0x19a, &d2, pos, pos);
        if (VEC_Distance(pos, &self->unk_b8) > 0x4cd) {
            break;
        }
        func_ov000_02191708(self->unk_38);
        self->unk_40->state++;
        break;
    }
    case 3:
        if (FLD(s16, self->unk_38, 0xc4) != 3) {
            break;
        }
        func_02049f44(data_02097e4c, 0x403, pos, 0);
        func_0204a028(data_02097e4c, 0x12, pos, 0xa);
        func_ov000_02191690(self->unk_38);
        self->unk_40->state++;
        break;
    case 4: {
        Ov012Actor *o;
        Ov012V *e;
        s->timer++;
        if (s->timer <= 10) {
            break;
        }
        func_ov000_02191708(self->unk_38);
        func_02049f44(data_02097e4c, 0x2b, pos, 0);
        Ov012Spawn_Init(&d, 0x4825);
        v.x = -0xccd;
        v.y = 0;
        v.z = 0x2000;
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Add(pos, &v, &v);
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
        if (o != NULL) {
            FLD(Ov012Flags8, o, 0x16).b0 = 1;
            o->rot[1] = self->rot[1];
            o->unk_90 = self->unk_90;
            func_ov000_0219bebc(o, FLD(s16, self, 0x124));
            if (FLD(void *, o, 0x4c) != NULL) {
                FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
            }
        }
        e = func_02065f88(0x68, pos);
        q.x = -0xccd;
        q.y = 0;
        q.z = 0x2000;
        func_01ffc9fc(&q, &q, self->rot[1]);
        e->v20(&q);
        e->v34(0xeaaa, self->rot[1], self->rot[2]);
        e = func_02065f88(0x12d, pos);
        q.x = -0xccd;
        q.y = 0;
        q.z = 0x2000;
        func_01ffc9fc(&q, &q, self->rot[1]);
        e->v20(&q);
        e = func_02065f88(0x6a, pos);
        q.x = -0xccd;
        q.y = 0;
        q.z = 0x2000;
        func_01ffc9fc(&q, &q, self->rot[1]);
        e->v20(&q);
        q.x = 0;
        q.y = 0x1800;
        q.z = -0x1800;
        func_01ffc9fc(&q, &q, self->rot[1]);
        VEC_Add(pos, &q, &t);
        self->unk_b8 = t;
        self->unk_84 = self->pos;
        self->unk_40->timer = 0;
        self->unk_40->state = 0x14;

        break;
    }
    case 0x14: {
        s32 r;
        u16 ang;
        t = self->unk_b8;
        d14.x = t.x - self->pos.x;
        d14.y = t.y - self->pos.y;
        d14.z = t.z - self->pos.z;
        VEC_MultAdd(0x4cd, &d14, pos, pos);
        if (VEC_Distance(pos, &self->unk_b8) > 0x4cd) {
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c[0], 0x52, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        {
            s64 sq;
            s32 dx = self->pos.x - self->unk_84.x;
            s32 dz = self->pos.z - self->unk_84.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;

            OV012R_SQRTCNT = 1;
            OV012R_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV012R_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV012R_SQRT_RESULT + 1) >> 1;
        ang = FX_Atan2(r, self->unk_84.y - self->pos.y);
        self->unk_9c = Ov012_FxMul(OV012_SIN(ang), 0x19a);
        self->unk_a0 = Ov012_FxMul(OV012_COS(ang), 0x19a);
        self->unk_b8 = self->unk_84;
        self->unk_40->state++;
        break;
    }
    case 0x15: {
        t = self->unk_b8;
        func_ov000_0218ddd4(self, &t, 0);
        if (VEC_Distance(pos, &self->unk_b8) > 0x19a) {
            break;
        }
        FLD(Ov012bEA3, self, 0xea).b0 = self->unk_b0->unk_0a_7;
        func_ov000_02198360(self->unk_40, 4, 0);
        break;
    }
    }
    {
        u8 *cam = (u8 *)data_ov000_021ccd54 + 0xf4;
        *(Ov012Blk12R *)&c = *(Ov012Blk12R *)&data_ov012_0220a600;
        c.y = self->pos.y;
        FLD(Ov012Vec, cam, 0xdc) = c;
        FLD(Ov012Flags8, cam, 0xda).b0 = 1;
        FLD(u16, cam, 0xf8) = 0xe39;
        FLD(Ov012Flags8, cam, 0xda).b4 = 1;
    }
}

}
