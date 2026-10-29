#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Work {
    u16 state;
    u16 timer;
    s64 unk_04;
    u8 unk_0c;
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
    u32 flags2;
    u8 unk_58[0x42];
    union {
        struct {
            u16 unk_9a_0 : 1;
            u16 unk_9a_1 : 2;
            u16 unk_9a_3 : 1;
        };
        u16 unk_9a;
    };
};

struct Ov003GmSub {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
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

struct Ov003GmPlayer {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x36];
    void *unk_44;
    u8 unk_48[0xad6];
    u16 target;
};

struct Ov003GmArg {
    u8 a;
    u8 b;
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
    Ov003GmSub *sub;
    Ov003GmCtl *ctl;
    Ov003GmPart *part;
    u8 unk_50[0x14];
    s32 scale;
    s32 unk_68_s;
    s32 rotY;
    Ov003Vec pos;
    u8 unk_7c[0x24];
    s32 unk_a0;
    u8 unk_a4[4];
    s32 unk_a8;
    u8 unk_ac[0x10];
    void *fx;
    u8 unk_c0[0xe];
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

extern void *data_0214a420;
extern char data_ov003_021f99d8[];
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 v);
extern void func_ov000_02191618(void *model);
extern void *func_ov000_02191318(void *model, s32 v);
extern void func_ov000_02191708(void *model);
extern void func_ov000_02191690(void *model);
extern BOOL func_ov000_02191120(void *model);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003GmPlayer *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern BOOL func_ov000_0219a8bc(void *a, void *b, void *c, s32 d, s32 e, Ov003Vec *f, s32 g, s32 h, s32 i);
extern void func_02065804(void *mgr, void *handle);
extern void func_ov000_0219bd20(s32 id, u16 a, s32 b, s32 c, s32 d, Ov003GmArg *arg);
extern void func_ov000_02195d88(void *self);
extern void *data_02097e4c;
extern void func_ov000_0219763c(void *self);
extern void *func_0206fef8(u16 id);
extern void func_ov000_0219badc(void *model, void *p, void *info);
extern Ov003GmEffect *func_02065f88(s32 id, const Ov003Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_0203f324(Ov003GmCtl *ctl);
extern void func_ov000_02197ad0(void *self, s32 a);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void func_ov000_021987b8(Ov003GmCtl *ctl, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_0218996c(s32 a, s32 b);

void func_ov003_021ec9e0(Ov003Gimmick *self) {
    Ov003Work *w = self->work;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
        func_ov000_021911c8(self->model, 0x800);
        func_ov000_02191618(self->model);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191708(self->model);
        self->work->state++;
        break;
    case 1:
        w->timer++;
        if (w->timer >= 0xf && w->timer <= 0x64) {
            Ov003GmPlayer *pl = func_ov000_0219bf90();
            u16 id;
            func_ov000_0219aae8(self, self, 0x78, 0x11, (u16)(1 << (pl->unk_0c >> 12)), 0, 0,
                                self->scale + (self->scale >> 1), self->unk_68_s, 0x6d, 0xccd);
            id = pl->target;
            if (id != 0xffff && id == self->unk_0c) {
                func_ov000_0219a8bc(pl->unk_44, self, self, 0xa, 0x11, &self->pos, 0x6d, 0xccd, 0x1000);
            }
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02198360(self->work, 1, 1);
        break;
    }
}

void func_ov003_021ecb6c(Ov003Gimmick *self) {
    if (self->work->state == 0) {
        if (self->id == 0x4064) {
            if (self->state != 1) {
                self->state = 0;
            }
            self->unk_d2 = 0;
            self->unk_d4 = 0;
            self->unk_d0 = 0x4000;
            if (self->fx != NULL) {
                Ov003GmArg arg;
                func_02065804(data_0214a420, self->fx);
                self->fx = NULL;
                arg.a = self->unk_1c;
                arg.b = 0;
                func_ov000_0219bd20(0x4064, self->unk_0c, 0xe, 1, 2, &arg);
            }
        } else if (self->id == 0x4065 && self->state == 0) {
            func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
            func_ov000_02191690(self->model);
            func_ov000_02191318(self->model, 0);
        }
    }
    func_ov000_02195d88(self);
}

void func_ov003_021ecc68(Ov003Gimmick *self) {
    Ov003GmArg arg;
    Ov003Work *w = self->work;
    if (w->state == 0 && w->unk_0c != 10 && self->count != 0) {
        self->count--;
    }
    if (self->count == 0 && self->state == 1) {
        if (self->fx != NULL) {
            func_02065804(data_0214a420, self->fx);
            self->fx = NULL;
        }
        func_ov000_0219763c(self);
        return;
    }
    switch (self->work->state) {
    case 0:
        if (self->count == 0) {
            s16 m;
            Ov003GmEffect *e;
            if (self->fx != NULL) {
                func_02065804(data_0214a420, self->fx);
                self->fx = NULL;
                if (self->id == 0x4064) {
                    arg.a = self->unk_1c;
                    arg.b = 0;
                    func_ov000_0219bd20(0x4064, self->unk_0c, 0xe, 1, 2, &arg);
                }
            }
            self->state = 1;
            self->count = self->mode;
            if (self->count == 0) {
                self->count = 1;
            }
            func_ov000_0219badc(self->model, (u8 *)self + 0xdc, func_0206fef8(self->id));
            e = func_02065f88(0x6d, &self->pos);
            e->SetScale(self->scale + (self->scale >> 3), self->scale + (self->scale >> 3), self->scale + (self->scale >> 3));
            e = func_02065f88(4, &self->pos);
            e->SetScale(self->scale + (self->scale >> 3), self->scale + (self->scale >> 3), self->scale + (self->scale >> 3));
            e->SetRot(0, self->rotY, 0);
            func_02049f44(data_02097e4c, 0x16, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        }
        {
            Ov003GmCtl *c = self->ctl;
            c->unk_9a_0 = 1;
            c->unk_9a_3 = 1;
            func_0203f324(c);
            self->ctl->unk_9a |= 0x12;
        }
        self->unk_a0 = 0x2cd;
        self->unk_a8 = 0x52;
        self->work->state++;
    case 1:
        func_ov000_02197ad0(self, 0);
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->ctl, 1, 0, 0);
        if (self->ctl->flags & 0x20000000) {
            Ov003GmSub *s = self->sub;
            s->unk_22_0 = 1;
            s->unk_22_1 = 1;
            func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
            func_ov000_021915a0(self->model);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            func_ov000_0218996c(0xf, 0x14);
            self->unk_a0 = 0;
            self->work->state++;
            self->work->timer = 0;
            return;
        }
        if (self->unk_a0 >= 0) {
            return;
        }
        w = self->work;
        w->timer++;
        if (w->timer <= 0x46) {
            return;
        }
        self->work->timer = 0x46;
        if (self->ctl->flags2 & 0x20000000) {
            return;
        }
        func_ov000_02198360(self->work, 0x15, 1);
        break;
    case 2:
        self->ctl->unk_9a |= 0x20;
        w = self->work;
        w->timer++;
        if (w->timer < 6) {
            return;
        }
        self->work->timer = 6;
        if (!func_ov000_02191120(self->model) && self->work->unk_04 == 0) {
            return;
        }
        self->part->unk_1c = 0xffff;
        func_ov000_02198360(self->work, 1, 0);
        break;
    }
}
}
