#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u16 state;
    u16 timer;
    u8 unk_04[0xf];
    u8 kind;
} Ov003Work;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 unk_54;
    u8 unk_58[0x42];
    u16 unk_9a;
} Ov003Ctl;

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

typedef struct {
    u8 unk_00[0x2c];
    u32 unk_2c;
} Ov003ColState;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    void *unk_00;
} Ov003ModelRes;

typedef struct {
    u8 unk_00[0xc];
    Ov003ModelRes *unk_0c;
} Ov003ModelHdr;

typedef struct {
    Ov003ModelHdr *unk_00;
    u8 unk_04[0xa4];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xe];
    u16 unk_c2_0 : 1;
} Ov003Model;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x32];
    u8 unk_ca;
    u8 unk_cb[9];
    void *unk_d4;
} Ov003Game54;

typedef struct {
    void *vtbl;
    u8 unk_04[0xa];
    u16 unk_0e;
    u8 unk_10[0x8];
    s16 unk_18;
    u8 unk_1a[2];
    s16 kind;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Model *model;
    u8 unk_3c[4];
    Ov003Work *work;
    void *unk_44;
    Ov003Ctl *ctl;
    u8 unk_4c[0x10];
    void *unk_5c;
    void *unk_60;
    u8 unk_64[0xc];
    Ov003Vec3 pos;
    u8 unk_7c[0x8];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x20];
    u16 unk_cc_0 : 3;
    u16 unk_cc_3 : 1;
    u16 unk_ce;
    s16 res;
    u8 unk_d2;
    u8 unk_d3;
    Ov003Vec3 unk_d4;
    u8 unk_e0[0xec];
    void **unk_1cc;
    u8 unk_1d0[0x20];
    u8 unk_1f0[0x18];
    void *unk_208;
    u8 unk_20c;
    u8 unk_20d[3];
    s32 unk_210;
} Ov003Obj;

extern "C" {

extern Ov003ColState data_02fe0f14;
extern Ov003HeapCtx *data_02097dd0;
extern char data_ov003_021f8768[];
extern char data_ov003_021f85b2[];
extern void func_ov000_02194758(void *self);
extern s32 func_ov000_0219a2f4(Ov003Vec3 *pos, s32 a, s32 b);
extern void func_ov000_02197ee0(void *self, s16 *res, s32 a, s32 b, s32 c);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_0218ddd4(void *self, Ov003Vec3 *v, s32 a);
extern void func_ov000_021987b8(Ov003Ctl *ctl, s32 a, s32 b, s32 c);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0214b598(void *p);
extern void func_0203de1c(void *p);
extern void func_ov000_0218ea20(void *p);
extern void func_ov000_0219429c(void *self);
extern Ov003Game54 *data_ov000_021ccd54;
extern void *const data_ov003_021f4c64[2];
extern char data_ov003_021f85b8[];
extern void func_ov000_0219433c(void *self);
extern void *func_0207011c(u16 id);
extern void func_0201e520(void *dst, const void *src);
extern void func_0201e78c(void *dst, const char *s);
extern void *func_02039674(void *p);
extern BOOL func_02018d58(void);
extern void *func_0203dd9c(u32 size);
extern void *func_ov000_0214b570(void *p);
extern void func_ov000_0214b5e8(void *p, void *t);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *res);
extern s32 func_ov000_0214b6d0(void *p);
extern BOOL func_ov000_0214b640(void *p);
extern void func_ov000_0214b5bc(void *p);
extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_021bd7a0(void *p);
extern void *data_ov000_021ccd64;
extern void *NNS_G3dGetTex(void *p);
extern void *func_ov000_0214b670(void *p);
extern void func_020394cc(void *a, void *b);
extern void *NNS_G3dGetMdlSet(void *p);
extern void NNS_G3dBindMdlSet(void *a, void *b);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern s32 func_02040528(s32 max);

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasD4(Ov003Game54 *g) {
    return g->unk_d4 != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasD4(data_ov000_021ccd54) ? TRUE : FALSE;
}

void func_ov003_021e57b8(Ov003Obj *self) {
    func_ov000_02194758(self);
    if (func_ov000_0219a2f4(&self->pos, 0x1000, -0xa000) == -0x1000) {
        return;
    }
    self->ctl->unk_54 |= data_02fe0f14.unk_2c;
}

void func_ov003_021e5804(Ov003Obj *self) {
    if (self->work->kind == 9) {
        return;
    }
    func_ov000_02197ee0(self, &self->res, 0x2cd, 0x333, 0x8800);
}

void func_ov003_021e5838(Ov003Obj *self) {
    Ov003Vec3 v;
    if (self->work->state == 0) {
        func_ov000_02190cb0(self->model, data_ov003_021f85b2, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->work->state++;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    }
    self->ctl->unk_9a |= 0x20;
    self->unk_9c = 0x2cd;
    v.x = self->unk_d4.x;
    v.y = self->unk_d4.y;
    v.z = self->unk_d4.z;
    func_ov000_0218ddd4(self, &v, 0x333);
    func_ov000_021987b8(self->ctl, 1, 0, 0);
    if (self->ctl->flags & 0x20000000) {
        return;
    }
    func_ov000_02198360(self->work, 4, 0);
}

Ov003Obj *func_ov003_021e5920(Ov003Obj *self) {
    void *old;
    void *p;
    self->vtbl = data_ov003_021f8768;
    old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    p = self->unk_208;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0214b598(p);
            func_0203de1c(p);
        }
        self->unk_208 = NULL;
    }
    data_02097dd0->cur = old;
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    return self;
}

Ov003Obj *func_ov003_021e5998(Ov003Obj *self) {
    void *old;
    void *p;
    self->vtbl = data_ov003_021f8768;
    old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    p = self->unk_208;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0214b598(p);
            func_0203de1c(p);
        }
        self->unk_208 = NULL;
    }
    data_02097dd0->cur = old;
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021e5a18(Ov003Obj *self) {
    u8 buf[0x20];
    func_ov000_0219433c(self);
    if (self->kind != 0) {
        u16 id = self->unk_0e;
        void *r;
        void *t;
        if (self->kind == 3) {
            id = 0x4053;
        }
        func_0201e520(buf, func_0207011c(id));
        func_0201e78c(buf, data_ov003_021f85b8);
        r = func_02039674(buf);
        func_0201e520(self->unk_1d0, buf);
        func_0201e520(self->unk_1f0, r);
        t = NULL;
        self->res = 0;
        self->unk_d3 |= 0x20;
        if (func_02018d58()) {
            if ((u16)(s16)(self->kind - 1) <= 1) {
                if (id == 0x4053) {
                    t = data_ov003_021f4c64[1];
                } else if (id == 0x4054) {
                    t = data_ov003_021f4c64[0];
                }
                if (t != NULL) {
                    void *p = func_0203dd9c(0x1c);
                    if (p != NULL) {
                        p = func_ov000_0214b570(p);
                    }
                    self->unk_208 = p;
                    func_ov000_0214b5e8(p, t);
                }
            }
        }
    }
    self->unk_210 = 0;
    self->unk_20c = 0;
}

BOOL func_ov003_021e5b34(Ov003Obj *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->kind != 0 && self->unk_20c == 0) {
        if (self->res >= 0 && !func_ov000_0218f110(&self->res)) {
            r = FALSE;
        }
        if (self->unk_208 != NULL) {
            if (func_ov000_0214b6d0(self->unk_208) == 2) {
                r = FALSE;
                self->unk_20c = 1;
            }
            if (r && !func_ov000_0214b640(self->unk_208)) {
                func_ov000_0214b5bc(self->unk_208);
                r = FALSE;
            }
        }
    }
    return r;
}

void func_ov003_021e5bc4(Ov003Obj *self) {
    Ov003Unit *u;
    func_ov000_02194758(self);
    if (self->kind != 0 && self->unk_20c == 0) {
        void *h;
        if (self->unk_1cc == NULL) {
            h = NULL;
        } else {
            h = NNS_G3dGetTex(*self->unk_1cc);
        }
        if (h != NULL) {
            if (self->kind != 3) {
                if (self->unk_208 != NULL) {
                    void *x = func_ov000_0214b670(self->unk_208);
                    if (x != NULL) {
                        func_020394cc(*self->unk_1cc, x);
                    }
                }
            } else if (self->unk_60 != NULL) {
                func_020394cc(*self->unk_1cc, self->unk_60);
            }
            NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(self->model->unk_00->unk_0c != NULL ? self->model->unk_00->unk_0c->unk_00 : NULL), h);
        }
    }
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
    if (self->unk_1e != 0) {
        s32 x;
        s32 y;
        s32 z;
        if (self->unk_44 != NULL) {
            void *old = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->alt;
            if (self->unk_44 != NULL) {
                func_0203de1c(self->unk_44);
                self->unk_44 = NULL;
            }
            data_02097dd0->cur = old;
        }
        if (self->unk_1e == 2) {
            y = func_02040528(0x4000) - 0x2000;
            x = func_02040528(0x9000);
            z = -0x32000;
            self->unk_84 = x;
            self->unk_88 = y;
            self->unk_8c = z;
        } else {
            y = func_02040528(0x2000) - 0x4000;
            x = func_02040528(0x6000);
            z = -0x14000;
            self->unk_84 = x;
            self->unk_88 = y;
            self->unk_8c = z;
        }
    } else if (self->unk_18 <= 0) {
        self->model->unk_c2_0 = 0;
    } else {
        func_ov000_02198360(self->work, 6, 0);
        self->unk_93_1 = (u8)self->unk_18;
    }
    if (self->unk_0e == 0x406a && data_ov000_021ccd54->unk_ca == 0x10) {
        Ov003Model *m = self->model;
        m->unk_a8 = 0x1800;
        m->unk_ac = 0x1800;
        m->unk_b0 = 0x1800;
    }
}

BOOL func_ov003_021e5dd0(Ov003Obj *self) {
    BOOL r = func_ov000_02194c08(self);
    if (self->unk_5c != NULL && Ov003_GameIdle() && !Ov003_GameHasD4()) {
        func_ov000_021bd7a0(self->unk_5c);
    }
    return r;
}

}
