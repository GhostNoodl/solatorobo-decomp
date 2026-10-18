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
    u8 pad_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003S44;

typedef struct {
    u8 pad_00[0x9a];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
} Ov003Ctl;

typedef struct {
    u8 pad_00[0xe];
    u16 unk_0e;
    u8 pad_10[0xa];
    s16 unk_1a;
    u8 pad_1c[0x1c];
    Ov003M *model;
    u8 pad_3c[4];
    Ov003W *work;
    Ov003S44 *unk_44;
    Ov003Ctl *ctl;
    Ov003P4c *unk_4c;
    u8 pad_50[0x14];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov003Pos pos;
    u8 pad_7c[0x74];
    void *unk_f0;
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
    virtual void SetSize(s32 v);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetRot(s32 x, s32 y, s32 z);
    u8 pad_04[0x20];
    void *unk_24;
    u8 pad_28[0x14];
    s32 unk_3c;
};

extern "C" {

extern void *data_02097e4c;
extern char data_ov003_021f7cb6[];
extern Ov003Pl *func_ov000_0219bf90(void);
extern void func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern s32 VEC_Distance(const Ov003Pos *a, const Ov003Pos *b);
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
        if (VEC_Distance(&self->pos, &v) < 0xc000) {
            func_ov000_02198360(self->work, 1, 0);
        }
        break;
    }
    default:
        return;
    }
}

extern void *data_0214a420;
extern void func_ov000_021911c8(void *model, s32 v);
extern void func_0203f364(Ov003Ctl *ctl);
extern void func_ov000_0219b71c(Ov003Pos *pos, Ov003Pos *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern void func_020639d4(Ov003Eff *e, s32 a, s32 b);
extern void *func_020657b0(void *mgr, void *handle);
extern void func_ov003_021d6a3c(Ov003Act *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov003Act *self, u8 a);

void func_ov003_021d73dc(Ov003Act *self) {
    switch (self->work->state) {
    case 0: {
        Ov003Ctl *ctl;
        Ov003S44 *s;
        func_ov000_02190cb0(self->model, data_ov003_021f7cb6, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0xccd);
        ctl = self->ctl;
        ctl->unk_9a_0 = 0;
        ctl->unk_9a_3 = 0;
        func_0203f364(ctl);
        s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
        self->unk_4c->unk_1c = 0xffff;
        self->work->state++;
    }
    case 1: {
        Ov003Eff *e;
        if (self->work->timer % 20 == 0) {
            Ov003Pos p;
            Ov003Pos v;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += self->unk_6c;
            v.x = self->unk_64;
            v.y = self->unk_68 >> 2;
            v.z = self->unk_64 + (self->unk_64 >> 2);
            func_ov000_0219b71c(&p, &v, 0x733, 0xccd, 6, 100);
            func_ov000_0218996c(8, 10);
            func_02049f44(data_02097e4c, 0x35, &p, 0);
        }
        self->work->timer++;
        if (self->work->timer <= 0x78) {
            return;
        }
        e = func_02065f88(0x384, &self->pos);
        e->SetRot(0, self->unk_6c, 0);
        e->SetSize(0x1800);
        MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
        func_020639d4(e, 0x42, 5);
        self->unk_f0 = e->unk_24;
        self->work->timer = 0;
        self->work->state++;
        break;
    }
    case 2: {
        Ov003W *w;
        if (self->unk_1a == 0 && func_020657b0(data_0214a420, self->unk_f0) == NULL) {
            Ov003Eff *e = func_02065f88(6, &self->pos);
            e->SetRot(0, self->unk_6c, 0);
            e->SetSize(0x2000);
            e->unk_3c = 0xc00;
            e = func_02065f88(0x69, &self->pos);
            e->SetRot(0, self->unk_6c, 0);
            e->SetSize(0x2000);
            e = func_02065f88(0x57d, &self->pos);
            e->SetRot(0, self->unk_6c, 0);
            e->SetSize(0x2000);
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_ov000_0218996c(0xc, 0x14);
            self->unk_1a = 1;
        }
        w = self->work;
        w->timer++;
        if (w->timer > 0x3c) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            return;
        }
        func_ov003_021d6954(self, 0x1f - (self->work->timer >> 1));
        break;
    }
    }
}

}
