#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003Pos;

typedef struct {
    u16 state;
    u16 timer;
    u64 flags;
    u8 pad_0c[0x7];
    u8 kind;
} Ov003W;

typedef struct {
    u8 pad_00[0xbe];
    u8 alpha;
} Ov003M;

typedef struct {
    u8 pad_00[0x1c];
    u16 unk_1c;
} Ov003P4c;

typedef struct {
    u8 pad_00[0xe];
    u16 unk_0e;
    u8 pad_10[0x28];
    Ov003M *model;
    u8 pad_3c[4];
    Ov003W *work;
    u8 pad_44[8];
    Ov003P4c *unk_4c;
    u8 pad_50[0x1c];
    s32 unk_6c;
    Ov003Pos pos;
} Ov003Act;

typedef struct {
    u8 pad_00[0x70];
    Ov003Pos pos;
    u8 pad_7c[0xaa8];
    u32 unk_b24_0 : 1;
} Ov003Pl;

class Ov003Eff {
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
    virtual void SetRot(s32 x, s32 y, s32 z);
    u8 pad_04[0x38];
    s32 unk_3c;
};

extern "C" {

extern void *data_02097e4c;
extern char data_ov003_021f7cb6[];
extern Ov003Pl *func_ov000_0219bf90(void);
extern void func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern s32 func_02013068(const Ov003Pos *a, const Ov003Pos *b);
extern void func_02049f44(void *mgr, s32 id, Ov003Pos *pos, s32 a);
extern Ov003Eff *func_02065f88(s32 id, const Ov003Pos *pos);
extern void func_ov003_021d6054(Ov003Act *self);
extern void func_ov003_021d1e8c(Ov003Act *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

void func_ov003_021d71c8(Ov003Act *self) {
    if (self->work->state == 0 && self->unk_0e == 0x5815) {
        Ov003Eff *fx = func_02065f88(6, &self->pos);
        fx->SetRot(0, self->unk_6c, 0);
        fx->unk_3c = 0xc00;
        fx = func_02065f88(0x69, &self->pos);
        fx->SetRot(0, self->unk_6c, 0);
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
    }
    func_ov003_021d6054(self);
}

void func_ov003_021d7270(Ov003Act *self) {
    u8 a;
    Ov003Pl *p;
    func_ov003_021d1e8c(self);
    if (self->work->kind == 0x15) {
        return;
    }
    a = self->model->alpha;
    p = func_ov000_0219bf90();
    if (p == NULL || p->unk_b24_0) {
        if (self->work->kind != 1) {
            self->unk_4c->unk_1c = 0xffff;
            self->work->flags |= 2;
        }
        if (a != 0) {
            Ov003W *w = self->work;
            w->timer++;
            if (w->timer & 1) {
                a--;
            }
        }
    } else if (a < 0x1f) {
        a++;
    }
    self->model->alpha = a;
}

void func_ov003_021d732c(Ov003Act *self) {
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f7cb6, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->work->state++;
    case 1: {
        Ov003Pl *p = func_ov000_0219bf90();
        Ov003Pos v;
        v.x = p->pos.x;
        v.y = p->pos.y;
        v.z = p->pos.z;
        v.y = self->pos.y;
        if (func_02013068(&self->pos, &v) < 0xc000) {
            func_ov000_02198360(self->work, 1, 0);
        }
        break;
    }
    default:
        return;
    }
}

}
