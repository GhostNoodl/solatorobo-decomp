#include "types.h"

typedef struct {
    u8 unk_00[0xa8];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xa];
    u8 unk_be;
    u8 unk_bf[3];
    u16 unk_c2_0 : 1;
} Ov003Model;

typedef struct {
    u16 state;
    u16 timer;
} Ov003PropWk;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x28];
    Ov003Model *unk_38;
    u8 unk_3c[4];
    Ov003PropWk *work;
    u8 unk_44[0x30];
    s32 unk_74;
} Ov003Prop;

extern void *data_ov000_021ccd68;
extern void func_ov000_02194758(void *self);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);

void func_ov003_021e0800(Ov003Prop *self) {
    func_ov000_02194758(self);
    self->unk_38->unk_c2_0 = 0;
    func_ov000_0218e8ec(data_ov000_021ccd68, 0x400c, 0x15);
    self->unk_74 -= 0x14000;
}

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003G54;

extern char data_ov003_021f852b[];
extern char data_ov003_021f8516[];
extern Ov003G54 *data_ov000_021ccd54;
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 a);
extern void func_ov000_021915a0(void *model);
extern BOOL func_ov000_02191120(void *model);
extern void *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(void *p);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02182590(u8 *p);
extern s32 func_02040498(s32 max);

#define OV003_FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))

void func_ov003_021e0848(Ov003Prop *self) {
    Ov003PropWk *w = self->work;
    switch (w->state) {
    case 0: {
        Ov003Model *m = self->unk_38;
        m->unk_a8 = 0;
        m->unk_ac = 0;
        m->unk_b0 = 0;
        self->unk_38->unk_be = 0;
        self->unk_38->unk_c2_0 = 1;
        func_ov000_02190cb0(self->unk_38, data_ov003_021f852b, 0x1000, 0);
        func_ov000_021911c8(self->unk_38, 0xc00);
        self->work->state++;
        break;
    }
    case 1:
        w->timer++;
        if (w->timer < 0xf0) {
            u16 t = self->work->timer;
            s32 sc = OV003_FX32_CONST(3.0f * t / 240.0f) + 0x800;
            Ov003Model *m = self->unk_38;
            m->unk_a8 = sc;
            m->unk_ac = sc;
            m->unk_b0 = sc;
            self->unk_38->unk_be = self->work->timer * 26 / 240;
        } else {
            Ov003Model *m = self->unk_38;
            m->unk_a8 = 0x3800;
            m->unk_ac = 0x3800;
            m->unk_b0 = 0x3800;
            self->unk_38->unk_be = 26;
            self->work->timer = 0;
            self->work->state++;
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov003_021f8516, 0xcd, 0);
            func_ov000_021915a0(self->unk_38);
            func_ov000_021911c8(self->unk_38, 0xccd);
        }
        break;
    case 2: {
        void *pl;
        w->timer++;
        if (w->timer <= 0x3c) {
            return;
        }
        pl = func_ov000_0219bf90();
        if (pl != NULL && !func_ov000_021b4738(pl)) {
            Ov003G54 *g;
            func_020627a0(self->unk_0e, self->unk_0c);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            g->unk_ac = 1;
            func_ov000_02182590(&g->unk_ac);
            self->work->timer = 0;
            self->work->state++;
        } else {
            self->work->timer = 0x3c;
        }
        break;
    }
    case 3: {
        u8 n = (u8)func_02040498(0xf) + 10;
        u8 v = self->unk_38->unk_be;
        if (n > v) {
            v++;
        } else if (n < v) {
            v--;
        }
        self->unk_38->unk_be = v;
        break;
    }
    }
}
