#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003BxVec;

typedef struct {
    u16 x, y, z;
} Ov003BxRot;

typedef struct {
    u16 state;
    u16 timer;
} Ov003BxWork;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 flags2;
    s32 unk_58;
    u8 unk_5c[0x3e];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 1;
} Ov003BxCtl;

typedef struct {
    u8 unk_00[3];
    u8 unk_03;
    u8 unk_04[0x14];
    u8 unk_18_0 : 2;
    u8 unk_18_2 : 1;
} Ov003BxS4c;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003BxS44;

typedef struct {
    u8 unk_00;
    u8 unk_01;
} Ov003BxSb0;

class Ov003BxFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetSize(s32 size);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Ov003BxRot *rot);
    u8 unk_04[0x20];
    void *unk_24;
};

typedef struct {
    s16 id;
    s16 size;
    u16 unk_04;
    u8 unk_06;
    s16 ox, oy, oz;
    s16 unk_0e;
    s16 unk_10;
    u16 rx, ry, rz;
    s16 unk_18;
    s16 unk_1a;
} Ov003BxDef;

typedef struct {
    u8 unk_00[0x70];
    Ov003BxVec pos;
} Ov003BxPlayer;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003Game54;

typedef struct {
    u8 unk_00[0x1a];
    s16 unk_1a;
    s16 unk_1c;
    u8 unk_1e[0x1a];
    void *model;
    u8 unk_3c[4];
    Ov003BxWork *work;
    Ov003BxS44 *unk_44;
    Ov003BxCtl *ctl;
    Ov003BxS4c *unk_4c;
    u8 unk_50[0x14];
    s32 unk_64;
    u8 unk_68[8];
    Ov003BxVec pos;
    Ov003BxRot rot;
    u8 unk_82[0x10];
    u8 state;
    u8 unk_93[5];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    u8 unk_a4[0xc];
    Ov003BxSb0 *unk_b0;
    u8 unk_b4[8];
    void *unk_bc;
    u8 unk_c0[0xc];
    u16 unk_cc_0 : 6;
    u16 unk_cc_6 : 1;
} Ov003Bx;

extern "C" {

extern void *data_02097e4c;
extern char data_ov003_021fa1a4[];
extern void func_ov000_02196c40(Ov003Bx *self);
extern void *func_02049f44(void *mgr, s32 id, Ov003BxVec *pos, s32 a);
extern Ov003BxFx *func_02065f88(s32 id, Ov003BxVec *pos);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_0203f364(Ov003BxCtl *ctl);
extern void func_ov003_021f0c60(Ov003Bx *self, s32 a);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void func_ov000_021987b8(Ov003BxCtl *ctl, s32 a, s32 b, s32 c);

extern void *data_0214a420;
extern Ov003Game54 *data_ov000_021ccd54;
extern const Ov003BxDef data_ov003_021f6e60[];
extern Ov003BxPlayer *func_ov000_0219bf90(void);
extern void func_02065860(void *mgr, void *p);
extern s32 VEC_Distance(const Ov003BxVec *a, const Ov003BxVec *b);
extern void *func_0204a028(void *mgr, s32 id, Ov003BxVec *pos, s32 a);
extern BOOL func_ov000_0219aae8(Ov003Bx *a, Ov003Bx *b, u16 c, u8 d, s32 e, Ov003BxVec *pos, Ov003BxRot *rot, s32 f, s32 g, s32 h, s32 i);

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

static inline s32 Ov003Bx_MaxDist(const Ov003BxVec *a, const Ov003BxVec *b) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dx < dy) {
        dx = dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    if (dx < dz) {
        dx = dz;
    }
    return dx;
}

#define BXF(T, p, off) (*(T *)((u8 *)(p) + (off)))

typedef struct {
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 3;
    u16 unk_c2_4 : 1;
} Ov003BxMdlBits;

typedef struct {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
} Ov003BxSpawnInfo;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003BxSpawned;

extern void *data_ov000_021ccd64;
extern s32 func_02040528(s32 n);
extern s32 func_02040498(s32 n);
extern BOOL func_01ffc584(Ov003BxVec *a, Ov003BxVec *b, s32 r, s32 h);
extern void func_0203f324(Ov003BxCtl *ctl);
extern void *func_0206fef8(u16 id);
extern Ov003BxSpawned *func_ov000_0218bf1c(void *mgr, Ov003BxSpawnInfo *info, void *pos, Ov003BxRot *rot, u16 a);

static inline void Ov003Bx_SetScale(void *m, s32 s) {
    BXF(s32, m, 0xa8) = s;
    BXF(s32, m, 0xac) = s;
    BXF(s32, m, 0xb0) = s;
}

void func_ov003_021ef70c(Ov003Bx *self) {
    BOOL ok = FALSE;
    Ov003BxPlayer *pl;
    switch (self->work->state) {
    case 0: {
        Ov003BxS44 *s;
        Ov003BxCtl *ctl;
        BXF(Ov003BxMdlBits, self->model, 0xc2).unk_c2_0 = 0;
        BXF(Ov003BxMdlBits, self->model, 0xc2).unk_c2_4 = 0;
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        ctl = self->ctl;
        ctl->unk_9a_0 = 0;
        ctl->unk_9a_3 = 0;
        func_0203f364(ctl);
        BXF(s32, self->ctl, 0x30) = 0;
        BXF(s32, self->ctl, 0x4c) = 0x14000;
        BXF(s32, BXF(void *, self, 0x3c), 0xc) = 0x14000;
        if (self->unk_1a >= 1) {
            s32 r = self->unk_1c << 4;
            self->pos.x += func_02040528(r);
            self->pos.z += func_02040528(r);
        }
        if (self->unk_b0->unk_01 == 0) {
            self->rot.y = func_02040498(0xffff);
        }
        self->work->state++;
    }
    case 1:
        if (BXF(s16, self, 0x1e) != 0) {
            self->work->timer = func_02040498(0x15);
            ok = TRUE;
        } else {
            pl = func_ov000_0219bf90();
            if (pl != NULL) {
                Ov003BxVec v;
                v.x = self->pos.x;
                v.y = self->pos.y;
                v.z = self->pos.z;
                v.y -= 0x4000;
                if (func_01ffc584(&pl->pos, &v, BXF(s32, pl, 0x64) + 0x8000, 0x8000)) {
                    func_ov000_0218996c(6, 0x16);
                    func_02049f44(data_02097e4c, 0x53, &self->pos, 0);
                    if (self->unk_1a < 0) {
                        self->pos = pl->pos;
                    }
                    ok = TRUE;
                }
            }
        }
        if (!ok) {
            return;
        }
        BXF(Ov003BxMdlBits, self->model, 0xc2).unk_c2_0 = true;
        Ov003Bx_SetScale(self->model, 0);
        self->pos.y += 0x7800;
        self->work->state++;
        return;
    case 2: {
        Ov003BxS44 *s;
        Ov003BxCtl *ctl;
        self->work->timer++;
        if (self->work->timer == 0x16) {
            func_ov000_0218996c(10, 0x19);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            return;
        }
        if (self->work->timer <= 0x23) {
            return;
        }
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = true;
            s->unk_22_1 = 1;
        }
        ctl = self->ctl;
        ctl->unk_9a_0 = true;
        ctl->unk_9a_3 = 1;
        func_0203f324(ctl);
        {
            u8 *info = (u8 *)func_0206fef8(BXF(u16, self, 0xe));
            void *m = self->model;
            Ov003Bx_SetScale(m, BXF(s16, info, 0x10));
        }
        BXF(u16, self->unk_4c, 0x1c) = BXF(u16, self, 0xc);
        self->unk_a0 = -0x59a;
        BXF(s32, self, 0xa8) = 0x52;
        func_ov000_02198360(self->work, 4, 0);
        if (self->unk_1a > 1) {
            Ov003BxSpawnInfo info;
            Ov003BxSpawned *o;
            s32 i;
            info.id = BXF(u16, self, 0xe);
            info.kind = BXF(u16, self, 0xe) & 0xf000;
            for (i = 0; i < 4; i++) {
                info.unk_04[i] = 0;
            }
            info.unk_0c = -1;
            info.unk_04[1] = self->unk_1a - 1;
            info.unk_04[2] = self->unk_1c;
            info.unk_04[3] = 1;
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &info, (u8 *)self + 0x84, &self->rot, 0xffff);
            if (o != NULL) {
                o->unk_16_0 = true;
            }
        }
        return;
    }
    }
}

static inline BOOL Ov003Bx_Flag(Ov003BxS4c *p) {
    return p->unk_18_2 ? TRUE : FALSE;
}

void func_ov003_021efad8(Ov003Bx *self) {
    Ov003BxWork *w;
    u32 flags;
    if (self->unk_b0->unk_01 == 0) {
        func_ov000_02196c40(self);
        return;
    }
    self->ctl->unk_9a_6 = 0;
    w = self->work;
    switch (w->state) {
    case 0:
        self->state = 0;
        self->unk_cc_6 = 0;
        self->unk_98 = self->rot.y;
        w->state++;
    case 1:
        flags = self->ctl->flags;
        if (flags & 0x400) {
            Ov003BxFx *e;
            if (self->unk_cc_6) {
                break;
            }
            self->unk_cc_6 = 1;
            self->unk_9c = 0;
            self->state = 3;
            func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
            e = func_02065f88(0x2bd, &self->pos);
            if (self->unk_64 > 0x1000) {
                e->SetSize(self->unk_64);
            }
            break;
        }
        if ((flags & 0x20000000) && self->unk_a0 < 0) {
            if (self->state < 3) {
                if (self->state == 0) {
                    self->unk_9c = 0x266 - self->state * 0x29;
                }
                self->unk_a0 = (3 - self->state) * 0x133 + 0x266;
                func_ov000_0218996c(8, 0xc);
                func_02065f88(0x12e, &self->pos)->SetSize(self->unk_64);
                func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            }
            self->state++;
        }
        if (self->state >= 3 || ((flags & 0x40000000) && !Ov003Bx_Flag(self->unk_4c)) || self->ctl->unk_58 != 0) {
            Ov003BxS44 *s = self->unk_44;
            Ov003BxCtl *ctl;
            if (s != NULL) {
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
            }
            ctl = self->ctl;
            if (ctl != NULL) {
                ctl->unk_9a_0 = 0;
                ctl->unk_9a_3 = 0;
                func_0203f364(ctl);
                ctl = self->ctl;
                ctl->unk_9a_1 = 0;
                ctl->unk_9a_4 = 0;
            }
            if (self->unk_4c->unk_03 != 0) {
                func_ov003_021f0c60(self, 0);
            }
            self->unk_64 *= 2;
            func_ov000_02198360(self->work, 0x15, 0);
        } else if (self->unk_a0 < 0) {
            func_ov000_02190cb0(self->model, data_ov003_021fa1a4, 0x1000, 0);
            func_ov000_021915a0(self->model);
            w = self->work;
            w->timer++;
            if (w->timer > 0x46) {
                self->work->timer = 0x46;
                if (!(self->ctl->flags2 & 0x20000000)) {
                    func_ov000_02198360(self->work, 0x15, 0);
                }
            }
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->ctl, 1, 0, 0);
}

static inline s32 Ov003Bx_MaxDist2(const Ov003BxVec *a, const Ov003BxVec *b) {
    s32 dx = b->x;
    s32 dy = b->y;
    s32 dz = b->z;
    dx = a->x - dx;
    dy = a->y - dy;
    dz = a->z - dz;
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dx < dy) {
        dx = dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    if (dx < dz) {
        dx = dz;
    }
    return dx;
}

void func_ov003_021efde8(Ov003Bx *self) {
    const Ov003BxDef *def = &data_ov003_021f6e60[self->unk_b0->unk_01];
    Ov003BxPlayer *pl = func_ov000_0219bf90();
    s32 d = Ov003Bx_MaxDist2(&self->pos, &pl->pos);
    Ov003BxWork *w;
    if (d > 0x20000) {
        if (self->unk_bc != NULL) {
            func_02065860(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        self->work->state = 0;
    }
    w = self->work;
    switch (w->state) {
    case 0:
        if (self->unk_1a < 0 && VEC_Distance(&self->pos, &pl->pos) > 0x3000) {
            return;
        }
        self->work->state = 10;
        return;
    case 10: {
        Ov003BxFx *e = func_02065f88(def->id, &self->pos);
        if (e == NULL) {
            return;
        }
        self->unk_bc = e->unk_24;
        e->SetRot(&self->rot);
        e->SetSize(def->size);
        if (self->unk_1a != 0 && d <= 0xc000 && Ov003_GameIdle()) {
            s32 snd = 0x54;
            s32 a = 3;
            if (def->id == 0x25a) {
                snd = 0x80;
                a = -0xc;
            }
            func_0204a028(data_02097e4c, snd, &self->pos, a);
        }
        self->work->state++;
        return;
    }
    case 11: {
        s32 n = self->unk_1a;
        if (n > 0 && ++w->timer > n) {
            {
                if (self->unk_bc != NULL) {
                    func_02065860(data_0214a420, self->unk_bc);
                }
                self->unk_bc = NULL;
                self->work->state++;
                self->work->timer = 0;
            }
        }
        if (!Ov003_GameIdle()) {
            return;
        }
        {
            Ov003BxVec pos;
            Ov003BxRot rot;
            rot.x = self->rot.x + def->rx;
            rot.y = self->rot.y + def->ry;
            rot.z = self->rot.z + def->rz;
            pos.x = def->ox << 4;
            pos.y = def->oy << 4;
            pos.z = def->oz << 4;
            func_ov000_0219aae8(self, self, def->unk_04, def->unk_06, 2, &pos, &rot, def->unk_0e << 4, def->unk_10 << 4, def->unk_18, def->unk_1a);
        }
        return;
    }
    case 12: {
        s32 lim = self->unk_1c;
        w->timer++;
        if (lim == 0) {
            lim = 0x3c;
        }
        if (w->timer > lim) {
            self->work->state = 10;
            self->work->timer = 0;
        }
        return;
    }
    }
}

}
