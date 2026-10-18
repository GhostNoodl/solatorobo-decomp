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
    u8 unk_00[0xac];
    u8 unk_ac;
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
    u8 unk_7c[0x52];
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
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0219b71c(Ov003Vec *pos, Ov003Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *func_ov000_02199ba0(Ov003GmPart *p);
extern void func_ov000_0218d398(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern void func_ov000_02194074(void *self);
extern void func_ov000_0218e9c4(Ov003GmRes *res);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(Ov003GmRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(Ov003GmRes *p);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021950e8(void *self, Ov003GmMsg *msg);
extern s32 func_02040498(s32 max);
extern Ov003GmEffect *func_02065f88(s32 id, const Ov003Vec *pos);
extern void func_ov003_021ec668(Ov003Gimmick *self);
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
}
