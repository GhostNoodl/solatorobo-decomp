#include "ov003/GmObj.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
} Ov003PropB0;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03[0x1b];
    s16 unk_1e;
} Ov003Prop4c;

typedef struct {
    u8 unk_00[0xc];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0xa];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 2;
    u16 unk_22_4 : 1;
} Ov003Prop44;

typedef struct {
    u16 state;
    u16 timer;
} Ov003PropWk;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06[4];
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Ov003Prop50;

typedef struct {
    u8 unk_00[0xb24];
    u32 unk_b24_0 : 12;
    u32 unk_b24_12 : 2;
    u8 unk_b28[6];
    u8 unk_b2e;
} Ov003Plr;

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u8 unk_20[0x18];
    void *model;
    u8 unk_3c[4];
    Ov003PropWk *work;
    Ov003Prop44 *unk_44;
    u8 unk_48[4];
    Ov003Prop4c *unk_4c;
    Ov003Prop50 *unk_50;
    u8 unk_54[0x1c];
    s32 pos[3];
    u16 unk_7c;
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003PropB0 *unk_b0;
    u8 unk_b4[0x18];
    u16 unk_cc_0 : 1;
} Ov003Prop;

class Ov003PropV {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
};

extern "C" {

extern void *data_02097e4c;
extern char data_ov003_021f8564[];
extern char data_ov003_021f856e[];
extern char data_ov003_021f8574[];
extern char data_ov003_021f857c[];
extern char data_ov003_021f8581[];
extern void func_ov000_02194758(void *self);
extern void *data_ov000_021ccd64;
extern char data_ov003_021f8587[];
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *self);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_021975b4(void *self);
extern void func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_02049f44(void *mgr, s32 id, void *pos, s32 a);
extern void func_0204a028(void *mgr, s32 id, void *pos, s32 a);

extern void *data_ov000_021ccd68;
extern void func_ov000_02191318(void *m, s32 a);
extern void func_ov000_02191690(void *model);
extern BOOL func_ov000_02191120(void *model);
extern void *func_ov000_02190a30(void *m, s32 a);
extern BOOL func_ov000_0218fd84(void *a);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_0203dd9c(u32 size);
extern Ov003Plr *func_ov000_0219bf90(void);

void func_ov003_021e3c80(Ov003Prop *self) {
    s16 n;
    func_ov000_021975b4(self);
    if (self->unk_18 >= self->unk_1a) {
        return;
    }
    n = self->unk_18 + 1;
    self->unk_18 = n;
    if (self->unk_1a <= n) {
        Ov003Prop44 *p;
        func_ov000_02190cb0(self->model, data_ov003_021f8581, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->unk_98 = self->unk_7e + 0x8000;
        self->unk_1e = 1;
        func_ov000_02197dec(self, self->unk_18, -1);
    } else {
        func_ov000_02190cb0(self->model, data_ov003_021f8587, 0x1000, 0);
    }
}

void func_ov003_021e3d34(Ov003Prop *self) {
    if (self->unk_1c == 0) {
        Ov003Prop44 *p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        func_ov000_02198360(self->work, 1, 0);
        self->unk_98 = self->unk_7e + 0x8000;
        return;
    }
    switch (self->work->state) {
    case 0: {
        Ov003Prop44 *p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->unk_a0 = 0;
        self->work->state++;
        break;
    }
    case 1: {
        Ov003PropWk *w;
        s32 v = self->unk_a0;
        v += (0x466 - v) >> 7;
        self->unk_a0 = v;
        self->pos[1] += v;
        self->unk_7c = func_01ffc128(0, self->unk_7c, 0x400, 1, 0x8000);
        w = self->work;
        w->timer++;
        if (w->timer > 0xb4) {
            func_ov000_02197dec(self, 0xf, -1);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((Ov003PropV *)self)->Destroy();
        }
        break;
    }
    }
}

void func_ov003_021e3e78(Ov003Prop *self) {
    s16 n;
    s16 lim;
    Ov003Prop50 *q;
    func_ov000_02194758(self);
    n = self->unk_18;
    lim = self->unk_1a;
    if (n > lim) {
        n = lim;
    }
    func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x1000, 0);
    if (n >= lim) {
        Ov003Prop44 *p;
        func_ov000_02198360(self->work, 1, 0);
        self->work->state = 0xffff;
        func_ov000_02191318(self->model, -1);
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->unk_cc_0 = 0;
    } else {
        func_ov000_02191690(self->model);
    }
    self->unk_44->unk_22_2 = 2;
    q = (Ov003Prop50 *)func_0203dd9c(sizeof(Ov003Prop50));
    if (q != NULL) {
        q->unk_00 = 100;
        q->unk_02 = 100;
        q->unk_04 = 0xffff;
        q->unk_0a = 0;
        q->unk_0e = 0;
        q->unk_0c = 0;
        q->unk_10 = 0;
        q->unk_14 = 0;
        q->unk_18 = 0;
    }
    self->unk_50 = q;
}

void func_ov003_021e3f78(Ov003Prop *self) {
    switch (self->work->state) {
    case 0: {
        s16 n;
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        n = self->unk_18;
        if (n >= self->unk_1a) {
            Ov003Plr *p = func_ov000_0219bf90();
            Ov003Prop44 *s;
            if (p == NULL || p->unk_b24_12 != 0) {
                self->unk_18 = n - 1;
                return;
            }
            if (p->unk_b2e < 1) {
                p->unk_b2e = 1;
            }
            func_ov000_02197dec(self, self->unk_18, 5);
            func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x1000, 0);
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x540b, 0x15);
            self->work->state++;
        } else {
            func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x1000, 0);
            func_ov000_02191690(self->model);
            self->work->state = 0xff;
        }
        break;
    }
    case 1: {
        void *a = func_ov000_02190a30(self->model, 0);
        if (a == NULL) {
            return;
        }
        if (!func_ov000_0218fd84(a)) {
            return;
        }
        self->unk_cc_0 = 0;
        self->work->state = 0xff;
        break;
    }
    }
}

void func_ov003_021e40d4(Ov003Prop *self) {
    Ov003Plr *p = func_ov000_0219bf90();
    u16 x;
    s16 n;
    s16 lim;
    if (p == NULL) {
        return;
    }
    if (p->unk_b24_12 != 0) {
        return;
    }
    x = self->unk_50->unk_04;
    if (x == 0xffff || (x >> 12) != 5) {
        func_ov000_02198360(self->work, 1, 0);
        return;
    }
    n = self->unk_18 + 1;
    lim = self->unk_1a;
    if (n >= lim) {
        n = lim;
        if (p->unk_b2e < 0x78) {
            p->unk_b2e = 0x78;
        }
    }
    self->unk_18 = n;
    func_ov000_02190cb0(self->model, data_ov003_021f856e, 0x1000, 0);
    func_02049f44(data_02097e4c, 0x6a, self->pos, 0);
    func_ov000_0218996c(8, 0xf);
    func_ov000_02198360(self->work, 1, 0);
}

void func_ov003_021e41bc(Ov003Prop *self) {
    Ov003Prop44 *p;
    func_ov000_02194758(self);
    p = self->unk_44;
    p->unk_0c = 0;
    p->unk_10 = -0x1800;
    p->unk_14 = 0x3000;
}

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003Spawned;

extern char data_ov003_021f858d[];
extern Ov003Spawned *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, void *rot, u16 a);
extern void func_ov000_0219b71c(Ov003Vec3 *pos, Ov003Vec3 *v, s32 a, s32 b, s32 c, s32 d);
extern s32 func_02040498(s32 max);

void func_ov003_021e41e8(Ov003Obj *self) {
    switch (self->work->state) {
    case 0: {
        Ov003Sub44 *s;
        func_ov000_02190cb0(self->model, data_ov003_021f858d, 0x333, 0);
        func_ov000_021911c8(self->model, 0x800);
        func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
        s16 n;
        s16 lim;
        lim = self->unk_1a;
        n = self->unk_18 + 1;
        self->unk_18 = n;
        if (n >= lim) {
            self->unk_cc_0 = 0;
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            self->work->state = 10;
            return;
        }
        self->work->timer = 0;
        self->work->state++;
        return;
    }
    case 1: {
        Ov003Work *w = self->work;
        w->timer++;
        if (w->timer <= 10) {
            return;
        }
        func_ov000_02198360(self->work, 1, 0);
        func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x111, 0);
        return;
    }
    case 10:
        if (func_ov000_02191120(self->model)) {
            if (self->kind == 0) {
                Ov003SpawnInfo info;
                Ov003Vec3 p;
                Ov003Spawned *o;
                s32 id;
                s32 i;
                id = 0x5810;
                if (self->unk_0e == 0x4056) {
                    id++;
                }
                info.id = id;
                info.kind = id & 0xf000;
                for (i = 0; i < 4; i++) {
                    info.unk_04[i] = 0;
                }
                info.unk_0c = -1;
                p.x = self->unk_44->pos.x;
                p.y = self->unk_44->pos.y;
                p.z = self->unk_44->pos.z;
                o = func_ov000_0218bf1c(data_ov000_021ccd64, &info, &p, self->unk_7c, 0xffff);
                if (o != NULL) {
                    o->unk_16_0 = 1;
                }
            }
            self->unk_64 = 0x1000;
            func_ov000_02198360(self->work, 0x15, 0);
            return;
        }
        if ((self->work->timer & 0xf) == 0) {
            Ov003Vec3 sc;
            Ov003Vec3 p;
            sc.x = 0x3000;
            sc.y = 0x2000;
            sc.z = 0x3000;
            p.x = self->unk_44->pos.x;
            p.y = self->unk_44->pos.y;
            p.z = self->unk_44->pos.z;
            func_ov000_0219b71c(&p, &sc, 0x99a, 0x1000, 0x38b, 0x32);
            func_ov000_0218996c(5, 10);
            func_02049f44(data_02097e4c, 0x3b, &self->pos, 0);
            if (func_02040498(1)) {
                func_02049f44(data_02097e4c, 0x3c, &self->pos, 0);
            } else {
                func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
            }
        }
        self->work->timer++;
        return;
    }
}

}
