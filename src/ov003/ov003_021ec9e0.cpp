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
    u8 unk_44[4];
    Ov003GmCtl *ctl;
    Ov003GmPart *part;
    u8 unk_50[0x14];
    s32 scale;
    s32 unk_68_s;
    s32 rotY;
    Ov003Vec pos;
    u8 unk_7c[0x40];
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
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 v);
extern void func_ov000_02191618(void *model);
extern void func_ov000_02191318(void *model, s32 v);
extern void func_ov000_02191708(void *model);
extern void func_ov000_02191690(void *model);
extern BOOL func_ov000_02191120(void *model);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003GmPlayer *func_ov000_0219bf90(void);
extern void func_ov000_0219aae8(void *a, void *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0219a8bc(void *a, void *b, void *c, s32 d, s32 e, Ov003Vec *f, s32 g, s32 h, s32 i);
extern void func_02065804(void *mgr, void *handle);
extern void func_ov000_0219bd20(s32 id, u16 a, s32 b, s32 c, s32 d, Ov003GmArg *arg);
extern void func_ov000_02195d88(void *self);

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
}
