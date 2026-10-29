#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Work {
    u16 state;
    u16 timer;
};

struct Ov003GmPart {
    u8 unk_00[0x18];
    u8 unk_18_0 : 5;
    u8 hidden : 1;
    u8 unk_19[3];
    u16 unk_1c;
};

struct Ov003GmCtl {
    u8 unk_00[0x50];
    u32 flags;
};

struct Ov003GmModel {
    u8 unk_00[0xc4];
    s16 dir;
};

struct Ov003GmGlobal {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
    u8 unk_ad[0x27];
    s32 unk_d4;
};

struct Ov003GmRot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov003GmSig {
    u8 idx;
    u8 on;
};

class Ov003GmFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(const Ov003GmRot *r);
    u8 unk_04[0x18];
    s32 unk_1c;
    u8 unk_20[4];
    void *handle;
};

struct Ov003GmRes {
    s16 handle;
    u8 unk_02[0x136];
};

struct Ov003GmMsg {
    u8 unk_00[5];
    u8 type;
    u8 unk_06[2];
    u8 idx;
    u8 val;
};

struct Ov003GmTable {
    void *res[4];
};

class Ov003GmEffect {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetRot(s32 x, s32 y, s32 z);
    u8 unk_04[0x38];
    s32 unk_3c;
};

struct Ov003Gimmick {
    void *vtbl;
    u8 unk_04[8];
    u16 unk_0c;
    u16 id;
    u8 unk_10[8];
    s16 kind;
    s16 mode;
    s16 unk_1c;
    s16 unk_1e;
    u8 unk_20[0x10];
    u32 flags;
    u8 unk_34[4];
    Ov003GmModel *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[4];
    Ov003GmCtl *ctl;
    Ov003GmPart *part;
    u8 unk_50[0x14];
    s32 scale;
    u8 unk_68[4];
    s32 rotY;
    Ov003Vec pos;
    Ov003GmRot rot;
    u8 unk_82[0x3a];
    void *fx;
    Ov003Vec ofs;
    u8 unk_cc[2];
    u8 count;
    u8 state;
    u16 unk_d0;
    u16 unk_d2;
    u16 unk_d4;
    u16 unk_d6;
    u8 vals[3];
    u8 unk_db;
    Ov003GmRes res;
};

extern "C" {

extern Ov003GmGlobal *data_ov000_021ccd54;
extern void *data_02097e4c;
extern u8 data_ov003_021f99e8[];
extern char data_ov003_021f99d8[];
extern const Ov003GmTable data_ov003_021f99c8;
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627b4(void);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void *func_ov000_0219b71c(Ov003Vec *pos, Ov003Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *func_ov000_02199ba0(Ov003GmPart *p);
extern void func_ov000_0218d398(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern void *func_ov000_02194074(void *self);
extern void *func_ov000_0218e9c4(Ov003GmRes *res);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(Ov003GmRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(Ov003GmRes *p);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern BOOL func_ov000_021950e8(void *self, Ov003GmMsg *msg);
extern s32 func_02040498(s32 max);
extern Ov003GmEffect *func_02065f88(s32 id, const Ov003Vec *pos);
extern void func_ov003_021ec668(Ov003Gimmick *self);
extern void *data_0214a420;
extern void func_02065804(void *mgr, void *handle);
extern Ov003GmFx *func_020657b0(void *mgr, void *handle);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern void func_ov000_0219bd20(u16 id, u16 a, s32 type, s32 b, s32 c, Ov003GmSig *sig);
extern void *func_0204a028(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov003_021ec9e0(Ov003Gimmick *self);

static inline void Ov003Gimmick_Finish(Ov003Gimmick *self) {
    func_020627a0(self->id, self->unk_0c);
    func_020627dc(4);
    data_ov000_021ccd54->unk_ac = 1;
    func_ov000_02198360(self->work, 1, 0);
}

void func_ov003_021ec130(Ov003Gimmick *self) {
    Ov003Work *w = self->work;
    u16 t;
    w->timer++;
    t = w->timer;
    if (t % 30 == 0) {
        Ov003Vec pos;
        Ov003Vec v;
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z;
        v.x = 0x1333;
        v.y = 0x2000;
        v.z = 0x7800;
        func_ov000_0219b71c(&pos, &v, 0x666, 0x1000, 0, 0x3c);
        func_ov000_0218996c(8, 8);
        func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
    }
    if (t <= 0xf0) {
        return;
    }
    switch (self->mode) {
    case 0:
        Ov003Gimmick_Finish(self);
        break;
    case 1:
        self->work->timer = 0;
        break;
    }
}

void func_ov003_021ec270(Ov003Gimmick *self) {
    void *p;
    if (self->work->state != 0) {
        return;
    }
    func_020627b4();
    p = func_ov000_02199ba0(self->part);
    if (p != NULL) {
        func_ov000_0218d398(p, self->unk_0c, 3, 1, 0, 0);
    }
    self->part->unk_1c = 0xffff;
    self->work->state++;
    Ov003Gimmick_Finish(self);
}

Ov003Gimmick *func_ov003_021ec31c(Ov003Gimmick *self) {
    func_ov000_02194074(self);
    self->vtbl = data_ov003_021f99e8;
    func_ov000_0218e9c4(&self->res);
    self->count = 1;
    self->state = 3;
    return self;
}

void func_ov003_021ec354(Ov003Gimmick *self) {
    Ov003GmTable tbl = data_ov003_021f99c8;
    func_ov000_0219433c(self);
    func_ov000_0218f074(&self->res, tbl.res[self->id - 0x4063], 1, 0, 0, 0);
    self->res.handle = 0;
}

BOOL func_ov003_021ec3b8(Ov003Gimmick *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->res.handle >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    return r;
}

void func_ov003_021ec3ec(Ov003Gimmick *self) {
    s16 k;
    u8 i;
    func_ov000_02194758(self);
    k = self->kind;
    self->count = k;
    if (!(k & 0xff)) {
        self->count = 1;
    }
    self->state = 0;
    self->unk_d2 = 0;
    self->unk_d4 = 0;
    self->unk_d0 = 0x4000;
    self->unk_d6 = 0;
    if (self->id == 0x4064) {
        func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
        func_ov000_021915a0(self->model);
        if (self->unk_1e == 0) {
            self->unk_1e = 0x78;
        }
        if (self->unk_1c == 1) {
            self->unk_d6 = self->unk_1e;
        }
    }
    for (i = 0; i < 3; i++) {
        self->vals[i] = 0;
    }
    if (self->part != NULL) {
        self->part->hidden = 1;
    }
}

void func_ov003_021ec4ac(Ov003Gimmick *self, Ov003GmMsg *msg) {
    if (msg->type == 0xe) {
        self->vals[msg->idx] = msg->val;
        self->flags |= 1 << msg->type;
        msg->type = 0;
    }
    func_ov000_021950e8(self, msg);
}

void func_ov003_021ec4f0(Ov003Gimmick *self) {
    if (self->id != 0x4064) {
        return;
    }
    if (self->state == 1) {
        return;
    }
    switch (self->model->dir) {
    case 1:
        self->state = 0;
        break;
    case 2:
        self->state = 3;
        break;
    case 3:
        self->state = 2;
        break;
    }
    switch (self->state) {
    case 2:
        self->unk_d2 += 0x333;
        break;
    case 3:
        self->unk_d2 -= 0x333;
        break;
    }
}

void func_ov003_021ec580(Ov003Gimmick *self) {
    if (self->state == 1) {
        Ov003Work *w = self->work;
        w->timer++;
        if (w->timer >= 0x96) {
            Ov003GmEffect *e;
            self->work->timer = func_02040498(0xf);
            e = func_02065f88(0x322, &self->pos);
            e->SetRot(0, self->rotY, 0);
            e->SetScale(self->scale, self->scale, self->scale);
            e->unk_3c = 0x4000;
        }
    } else {
        switch (self->id) {
        case 0x4064:
            func_ov003_021ec668(self);
            break;
        case 0x4065:
            func_ov003_021ec9e0(self);
            break;
        }
    }
    if (!(self->ctl->flags & 0x20000000)) {
        func_ov000_02198360(self->work, 4, 0);
    }
}

static inline BOOL Ov003GmGlobal_IsBusy(Ov003GmGlobal *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003GmGlobal_IsIdle(Ov003GmGlobal *g) {
    if (Ov003GmGlobal_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Gm_GameIdle(void) {
    Ov003GmGlobal *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003GmGlobal_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003GmGlobal_Flag(Ov003GmGlobal *g) {
    return g->unk_d4 != 0 ? TRUE : FALSE;
}

void func_ov003_021ec668(Ov003Gimmick *self) {
    Ov003Vec v;
    Ov003GmRot r;
    Ov003GmSig sig0;
    Ov003GmSig sig1;
    Ov003GmFx *fx;
    if (!Ov003Gm_GameIdle() || Ov003GmGlobal_Flag(data_ov000_021ccd54)) {
        if (self->fx != NULL) {
            func_02065804(data_0214a420, self->fx);
            self->fx = NULL;
        }
        return;
    }
    if (self->unk_d6 != 0) {
        self->unk_d6--;
        if (self->unk_d6 != 0) {
            return;
        }
    }
    switch (self->work->state) {
    case 0: {
        u8 n = 0;
        u8 i;
        func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
        func_ov000_021915a0(self->model);
        for (i = 0; i < 3; i++) {
            if (i != self->unk_1c && self->unk_1c < 3 && self->vals[i] != 0) {
                n++;
            }
        }
        if (n >= 2) {
            return;
        }
        self->ofs.x = 0;
        self->ofs.y = 0x1333;
        self->ofs.z = 0;
        VEC_Add(&self->pos, &self->ofs, &v);
        fx = (Ov003GmFx *)func_02065f88(0x25e, &v);
        if (fx == NULL) {
            return;
        }
        r.x = self->unk_d0 + self->rot.x;
        r.y = self->unk_d2 + self->rot.y;
        r.z = self->unk_d4 + self->rot.z;
        self->fx = fx->handle;
        fx->SetRot(&r);
        self->work->state++;
        sig0.idx = self->unk_1c;
        sig0.on = 1;
        func_ov000_0219bd20(0x4064, self->unk_0c, 0xe, 1, 2, &sig0);
        func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
        break;
    }
    case 1:
        fx = func_020657b0(data_0214a420, self->fx);
        if (fx != NULL) {
            s16 lim = self->unk_1e;
            Ov003Work *w = self->work;
            w->timer++;
            if (w->timer <= lim) {
                goto attack;
            }
        }
        {
            if (fx != NULL) {
                fx->unk_1c = 4;
            }
            self->fx = NULL;
            self->work->state = 0;
            self->work->timer = 0;
            sig1.idx = self->unk_1c;
            sig1.on = 0;
            func_ov000_0219bd20(0x4064, self->unk_0c, 0xe, 1, 2, &sig1);
            self->unk_d6 = self->unk_1e;
            return;
        }
    attack:
        r.x = self->rot.x + self->unk_d0;
        r.y = self->rot.y + self->unk_d2;
        r.z = self->rot.z + self->unk_d4;
        func_ov000_0219aae8(self, self, 0x3c, 0x11, 2, &self->ofs, &r, 0x800, 0x5400, 100, 0x1000);
        r.x = 0;
        fx->SetRot(&r);
        break;
    }
}
}
