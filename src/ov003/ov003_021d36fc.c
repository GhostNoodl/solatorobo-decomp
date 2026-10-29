#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003DwVec;

typedef struct {
    u16 x, y, z;
} Ov003DwRot;

typedef struct {
    s32 m[9];
    Ov003DwVec t;
} Ov003DwMtx;

typedef struct {
    u16 state;
    u16 timer;
} Ov003DwWork;

typedef struct {
    u8 unk_00[0x50];
    s32 unk_50[3];
    u8 unk_5c[0x3e];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
} Ov003DwCtl;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003DwS44;

typedef struct {
    u8 unk_00[0xc];
    const char *name;
    u8 unk_10[8];
    u8 unk_18_0 : 1;
    u8 unk_19[7];
    u8 mtx[0x30];
} Ov003DwS4c;

typedef struct {
    u8 unk_00[0x78];
    Ov003DwVec trans;
    u8 mtx[0x24];
} Ov003DwModel;

typedef struct {
    u8 unk_00[0x7c];
    Ov003DwRot rot;
} Ov003DwTgt;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003DwP40;

typedef struct {
    u8 unk_00[0x40];
    Ov003DwP40 *unk_40;
    u8 unk_44[0xad8];
    u16 unk_b1c;
    u16 unk_b1e;
    u8 unk_b20[4];
    u32 unk_b24_0 : 5;
    u32 unk_b24_5 : 2;
    u32 unk_b24_7 : 2;
    u32 unk_b24_9 : 1;
} Ov003DwPl;

typedef struct {
    u16 a;
    u8 b;
    u16 c;
} Ov003DwArg;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x2a];
    Ov003DwModel *model;
    u8 unk_3c[4];
    Ov003DwWork *work;
    Ov003DwS44 *unk_44;
    Ov003DwCtl *ctl;
    Ov003DwS4c *unk_4c;
    u16 *unk_50;
    u8 unk_54[0x1c];
    Ov003DwVec pos;
    Ov003DwRot rot;
    u8 unk_82[0x11];
    u8 unk_93_0 : 1;
    u8 unk_94[8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[8];
    s16 unk_b4;
    s16 unk_b6;
} Ov003Dw;

extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a78[];
extern char data_ov003_021f7a7f[];
extern Ov003DwTgt *func_ov000_02199ba0(Ov003DwS4c *p);
extern u16 func_ov000_02199bc8(Ov003DwS4c *p, Ov003DwVec *pos, s32 a, s32 b);
extern int STD_CompareString(const char *a, const char *b);
extern void func_ov000_02191008(Ov003DwModel *model);
extern BOOL func_ov000_02190cb0(Ov003DwModel *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(Ov003DwModel *model);
extern void func_ov000_021911c8(Ov003DwModel *model, s32 v);
extern void func_0203f364(Ov003DwCtl *ctl);
extern BOOL func_ov000_02198360(Ov003DwWork *w, s32 a, s32 b);
extern Ov003DwPl *func_ov000_0219bf90(void);
extern void func_ov000_0218d398(Ov003DwPl *p, u16 id, s32 a, s32 b, s32 c, Ov003DwArg *arg);
extern void func_ov000_021b4560(Ov003DwPl *p, Ov003Dw *self);
extern void MI_Copy36B(const void *src, void *dst);
extern void MI_Copy48B(const void *src, void *dst);

static inline void Ov003DwCtl_Clear(Ov003DwCtl *c) {
    if (c != NULL) {
        c->unk_9a_4 = 0;
    }
}

void func_ov003_021d36fc(Ov003Dw *self) {
    Ov003DwTgt *t;
    Ov003DwCtl *ctl;
    Ov003DwCtl_Clear(self->ctl);
    t = func_ov000_02199ba0(self->unk_4c);
    switch (self->work->state) {
    case 0: {
        const char *name;
        Ov003DwS44 *s;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        name = self->unk_4c->name;
        if (name != NULL) {
            if (STD_CompareString(name, data_ov003_021f7a78) == 0) {
                func_ov000_02191008(self->model);
            } else {
                func_ov000_02190cb0(self->model, name, 0x1000, 0);
            }
        } else {
            func_ov000_02190cb0(self->model, data_ov003_021f7a7f, 0x1000, 0);
        }
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x1400);
        ctl = self->ctl;
        if (ctl != NULL) {
            ctl->unk_9a_0 = 0;
            ctl->unk_9a_3 = 0;
            func_0203f364(ctl);
            ctl = self->ctl;
            ctl->unk_50[0] = 0;
            ctl->unk_50[1] = 0;
            ctl->unk_50[2] = 0;
        }
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->timer = 0;
        self->work->state++;
        break;
    }
    case 1:
        if (t != NULL) {
            u32 r = func_ov000_02199bc8(self->unk_4c, &self->pos, self->work->timer, 10);
            self->rot.x = t->rot.x;
        self->rot.y = t->rot.y;
        self->rot.z = t->rot.z;
            if (r < 10) {
                self->work->timer = r;
                return;
            }
            self->work->state++;
            self->work->timer = 0;
        } else {
            func_ov000_02198360(self->work, 4, 0);
        }
        break;
    case 2:
        if (*self->unk_50 != 0) {
            Ov003DwWork *w = self->work;
            w->timer++;
            if (w->timer > 0xb4) {
                Ov003DwPl *p;
                self->work->timer = 0xb4;
                p = func_ov000_0219bf90();
                if (p != NULL) {
                    s32 kind = p->unk_40 != NULL ? p->unk_40->kind : 0;
                    if (p->unk_b24_5 != 0 && kind != 0xb && kind != 0x11) {
                        Ov003DwArg arg;
                        p->unk_b1c = 0xffff;
                        p->unk_b1e = 0xffff;
                        p->unk_b24_5 = 0;
                        p->unk_b24_7 = p->unk_b24_9;
                        arg.a = 10;
                        arg.b = 0x50;
                        arg.c = 0xffff;
                        func_ov000_0218d398(p, self->unk_0c, 9, 0, 6, &arg);
                        func_ov000_021b4560(p, self);
                        func_ov000_02190cb0(self->model, data_ov003_021f7a60, 0x400, 0);
                        func_ov000_02198360(self->work, 10, 0);
                        return;
                    }
                }
            }
        }
        func_ov000_02199bc8(self->unk_4c, &self->pos, 10, 10);
        self->rot.x = t->rot.x;
        self->rot.y = t->rot.y;
        self->rot.z = t->rot.z;
        if (self->unk_4c->unk_18_0) {
            Ov003DwMtx m;
            Ov003DwModel *mdl;
            MI_Copy48B(self->unk_4c->mtx, &m);
            m.t.x = self->pos.x;
            m.t.y = self->pos.y;
            m.t.z = self->pos.z;
            mdl = self->model;
            MI_Copy36B(&m, mdl->mtx);
            mdl->trans.x = m.t.x;
            mdl->trans.y = m.t.y;
            mdl->trans.z = m.t.z;
            self->unk_93_0 = 1;
        }
        break;
    }
}
