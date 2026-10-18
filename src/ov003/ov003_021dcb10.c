#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x20];
    u16 unk_20;
    u8 unk_22[2];
    u8 unk_24[0x14];
    void *unk_38;
    u8 unk_3c[0x90];
    u16 unk_cc_0 : 3;
    u16 unk_cc_3 : 1;
} Ov003Obj24;

extern void *data_ov000_021ccd64;
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);
extern void func_ov000_0219433c(void *p);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021dcb10(Ov003Obj24 *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40(self->unk_24));
    }
}

void func_ov003_021dcb3c(void) {

}

void func_ov003_021dcb40(void) {

}

void func_ov003_021dcb44(void) {

}

void func_ov003_021dcb48(void) {

}

void func_ov003_021dcb4c(void) {

}

void func_ov003_021dcb50(void) {

}

void func_ov003_021dcb54(void) {

}

void *func_ov003_021dcb58(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021dcb74(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void func_ov003_021dcb88(Ov003Obj24 *self) {
    Ov003Unit *unit;
    func_ov000_0219433c(self);
    unit = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
}

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003GtMtx;

typedef struct {
    u8 unk_00[0xc2];
    u16 unk_c2_0 : 4;
    u16 unk_c2_4 : 1;
    u8 unk_c4[0x14];
    s32 unk_d8;
    s32 unk_dc;
} Ov003GtModel;

typedef struct {
    u8 unk_00[0x111];
    u8 unk_111_0 : 2;
    u8 unk_111_2 : 1;
} Ov003GtAnim;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003GtS44;

typedef struct {
    u16 state;
} Ov003GtWork;

typedef struct {
    u8 unk_00;
    u8 unk_01;
} Ov003GtB0;

typedef struct {
    u8 unk_00[0xca];
    u8 unk_ca;
} Ov003GtGame;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
    u8 unk_10[8];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x1c];
    Ov003GtModel *model;
    u8 unk_3c[4];
    Ov003GtWork *work;
    Ov003GtS44 *unk_44;
    u8 unk_48[0x10];
    void *unk_58;
    u8 unk_5c[0x14];
    s32 posX;
    s32 posY;
    s32 posZ;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk_82[0x11];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x1c];
    Ov003GtB0 *unk_b0;
    u8 unk_b4[0x18];
    u16 unk_cc_0 : 1;
    s16 unk_ce;
} Ov003Gate;

extern const s16 FX_SinCosTable_[];
extern Ov003GtGame *data_ov000_021ccd54;
extern char data_ov003_021f803c[];
extern char data_ov003_021f8041[];
extern char data_ov003_021f8046[];
extern char data_ov003_021f804b[];
extern void func_ov000_02194758(void *self);
extern void MTX_Identity43_(Ov003GtMtx *m);
extern void MTX_RotX43_(Ov003GtMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003GtMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003GtMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003GtMtx *a, Ov003GtMtx *b, Ov003GtMtx *out);
extern void func_0203f9dc(void *obj, Ov003GtMtx *m);
extern void func_0203f9b8(void *obj, s32 a);
extern void func_0203f920(void *obj);
extern void func_ov000_02197d80(void *self);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_02191318(void *model, s32 a);
extern void func_ov000_02191618(void *model);
extern Ov003GtAnim *func_ov000_02190a30(void *model, s32 n);

#define OV003GT_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003GT_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003GtS44_Clear(Ov003GtS44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

void func_ov003_021dcbc8(Ov003Gate *self) {
    void *obj;
    func_ov000_02194758(self);
    obj = self->unk_58;
    if (obj != NULL && (self->unk_0e == 0x460b || self->unk_0e == 0x4625)) {
        Ov003GtMtx t;
        Ov003GtMtx m;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set = FALSE;
        ry = self->rotY + 0x8000;
        rz = self->rotZ;
        rx = self->rotX;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003GT_SIN(rz), OV003GT_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003GT_SIN(ry), OV003GT_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003GT_SIN(ry), OV003GT_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003GT_SIN(rx), OV003GT_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003GT_SIN(rx), OV003GT_COS(rx));
                set = TRUE;
            }
        }
        m.tx = self->posX;
        m.ty = self->posY;
        m.tz = self->posZ;
        func_0203f9dc(obj, &m);
        if (data_ov000_021ccd54->unk_ca == 9) {
            func_0203f9b8(self->unk_58, 0x1b33);
        }
    }
    func_ov000_02197d80(self);
    switch (self->unk_18) {
    case 2:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f803c, 0x1000, 0);
        }
        self->unk_cc_0 = 0;
        if (self->unk_58 != NULL) {
            func_0203f920(self->unk_58);
        }
        Ov003GtS44_Clear(self->unk_44);
        break;
    case 1:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f8041, 0x1000, 0);
        }
        break;
    case 0:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f8046, 0x1000, 0);
        }
        break;
    case 3:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f8046, 0x1000, 0);
            func_ov000_02190cb0(self->model, data_ov003_021f804b, 0x1000, 0);
        }
        if (self->unk_1a != 1) {
            Ov003GtS44_Clear(self->unk_44);
        }
        break;
    }
    if (self->model != NULL) {
        Ov003GtAnim *a;
        func_ov000_02191318(self->model, -1);
        {
            Ov003GtModel *m = self->model;
            m->unk_d8 = 0;
            m->unk_dc = 0;
        }
        func_ov000_02191618(self->model);
        a = func_ov000_02190a30(self->model, 2);
        if (a != NULL) {
            a->unk_111_2 = 1;
        }
        if (self->unk_b0->unk_01 == 1) {
            self->model->unk_c2_4 = 0;
        }
    }
    self->work->state = 0;
    self->unk_93_1 = (u8)(u16)self->unk_18;
    self->unk_ce = 2;
}
