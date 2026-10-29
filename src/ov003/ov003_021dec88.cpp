#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003LpVec;

typedef struct {
    u16 state;
    u16 timer;
} Ov003LpWork;

typedef struct {
    void *res;
    u8 unk_04[0xb2];
    u16 unk_b6;
    u16 unk_b8;
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be[2];
    u8 mode;
    u8 unk_c1;
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 1;
} Ov003LpModel;

class Ov003LpFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetScale(s32 s);
    u8 unk_04[0x38];
    s32 unk_3c;
};

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    u8 unk_1a[0x1e];
    Ov003LpModel *model;
    u8 unk_3c[4];
    Ov003LpWork *work;
    u8 unk_44[0x2c];
    Ov003LpVec pos;
    u8 unk_7c[0x54];
    s32 unk_d0;
} Ov003Lamp2;

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern char data_ov003_021f8510[];
extern char data_ov003_021f8516[];
extern BOOL func_ov000_02190cb0(Ov003LpModel *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(Ov003LpModel *model, s32 v);
extern void func_ov000_021915a0(Ov003LpModel *model);
extern BOOL func_ov000_0218ffdc(Ov003LpModel *model, void *res, s32 a, s32 b);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_02049bb4(void *mgr, s32 id);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, Ov003LpVec *pos, s32 a);
extern Ov003LpFx *func_02065f88(s32 id, const Ov003LpVec *pos);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern BOOL func_ov000_02198360(Ov003LpWork *w, s32 a, s32 b);
extern void *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(void);

static inline void Ov003LpModel_SetMode(Ov003LpModel *m, s32 mode) {
    if (m->mode != mode) {
        func_ov000_0218ffdc(m, m->res, mode, m->unk_c2_1 ? TRUE : FALSE);
    }
}

void func_ov003_021dec88(Ov003Lamp2 *self) {
    Ov003LpWork *w;
    switch (self->work->state) {
    case 0: {
        s16 n = self->unk_18 + 1;
        if (n >= 3) {
            Ov003LpFx *fx;
            func_ov000_02190cb0(self->model, data_ov003_021f8510, 0x1000, 0);
            func_ov000_021911c8(self->model, 0x333);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x5011, 0x15);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x4801, 0x15);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x5013, 0x15);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x400c, 0x15);
            func_02049bb4(data_02097e4c, self->unk_d0);
            func_ov000_0218996c(0x19, 0x3c);
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            fx = func_02065f88(5, &self->pos);
            if (fx != NULL) {
                fx->SetScale(0x7800);
                fx->unk_3c = 0x800;
            }
            self->work->state = 10;
            return;
        }
        Ov003LpModel_SetMode(self->model, 1);
        func_ov000_02190cb0(self->model, data_ov003_021f8516, 0x1000, 0);
        func_ov000_021915a0(self->model);
        {
            Ov003LpModel *m = self->model;
            m->unk_b6 = 0x5adf;
            m->unk_b8 = 0x739f;
            m->unk_ba = 0xb;
            m->unk_bc = 10;
        }
        self->unk_18 = n;
        func_ov000_02197dec(self, n, -1);
        self->work->state++;
        break;
    }
    case 1:
        w = self->work;
        w->timer++;
        if (w->timer < 10) {
            return;
        }
        Ov003LpModel_SetMode(self->model, 0);
        func_ov000_02190cb0(self->model, data_ov003_021f8516, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_02198360(self->work, 1, 0);
        break;
    case 10:
        w = self->work;
        w->timer++;
        if (w->timer < 0x2d) {
            return;
        }
        self->work->timer = 0x2d;
        if (func_ov000_0219bf90() == NULL) {
            return;
        }
        if (func_ov000_021b4738()) {
            return;
        }
        self->unk_18 = 3;
        func_ov000_02197dec(self, 3, 2);
        func_ov000_02198360(self->work, 1, 0);
        break;
    }
}

}
