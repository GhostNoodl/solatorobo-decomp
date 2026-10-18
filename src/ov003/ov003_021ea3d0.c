#include "types.h"

typedef struct {
    u8 unk_00[0x18];
    s16 kind;
    u8 unk_1a[0x26];
    void *work;
} Ov003Spin2;

extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

typedef struct {
    s32 m[9];
} Ov003EaMtx;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003EaRot;

extern const s16 FX_SinCosTable_[];
extern void MTX_Identity33_(Ov003EaMtx *m);
extern void MTX_RotX33_(Ov003EaMtx *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov003EaMtx *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov003EaMtx *m, s32 s, s32 c);
extern void MTX_Concat33(Ov003EaMtx *a, Ov003EaMtx *b, Ov003EaMtx *out);

#define OV003EA_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003EA_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021ea234(void *self, Ov003EaMtx *m, Ov003EaRot *rot, s32 ang) {
    Ov003EaMtx t;
    BOOL set = FALSE;
    MTX_Identity33_(m);
    if (ang != 0) {
        MTX_RotY33_(m, OV003EA_SIN(ang), OV003EA_COS(ang));
        set = TRUE;
    }
    if (rot->x != 0) {
        if (set) {
            MTX_RotX33_(&t, OV003EA_SIN(rot->x), OV003EA_COS(rot->x));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, OV003EA_SIN(rot->x), OV003EA_COS(rot->x));
            set = TRUE;
        }
    }
    if (rot->z != 0) {
        if (set) {
            MTX_RotZ33_(&t, OV003EA_SIN(rot->z), OV003EA_COS(rot->z));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, OV003EA_SIN(rot->z), OV003EA_COS(rot->z));
            set = TRUE;
        }
    }
    if (rot->y != 0) {
        if (set) {
            MTX_RotY33_(&t, OV003EA_SIN(rot->y), OV003EA_COS(rot->y));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotY33_(m, OV003EA_SIN(rot->y), OV003EA_COS(rot->y));
            set = TRUE;
        }
    }
}

BOOL func_ov003_021ea3d0(Ov003Spin2 *self) {
    BOOL r = func_ov000_02194c08(self);
    if (self->kind == 1 && r == FALSE) {
        func_ov000_02198360(self->work, 0x15, 0);
    }
    return r;
}

typedef struct {
    s32 x, y, z;
} Ov003EaVec;

typedef struct {
    u8 unk_00[0x10];
    Ov003EaVec pos;
    u8 unk_1c[0x24];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
} Ov003EaCam;

typedef struct {
    u8 unk_00[0xf4];
    Ov003EaCam cam;
} Ov003EaGame;

typedef struct {
    Ov003EaVec pos;
    u16 angle;
    u8 unk_0e[2];
} Ov003EaSpot;

typedef struct {
    u8 unk_00[0x30];
    s32 unk_30;
    u8 unk_34[0x66];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
} Ov003EaCtl;

typedef struct {
    u8 unk_00[0x1a];
    s16 kind;
    u8 unk_1c[0x24];
    void *work;
    u8 unk_44[4];
    Ov003EaCtl *ctl;
    u8 unk_4c[0x24];
    Ov003EaVec pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_82[0x16];
    u16 unk_98;
} Ov003EaObj;

extern Ov003EaGame *data_ov000_021ccd54;
extern const Ov003EaSpot data_ov003_021f6b8c[];
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov003EaCtl *ctl);
extern u16 func_0204bfa8(Ov003EaCam *cam);
extern s32 func_02040528(s32 n);

static inline s32 Ov003Ea_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline u16 Ov003EaCam_Angle(Ov003EaCam *cam) {
    if (cam->unk_40 != 0) {
        return cam->unk_44;
    }
    return func_0204bfa8(cam);
}

void func_ov003_021ea408(Ov003EaObj *self) {
    Ov003EaCtl *ctl;
    func_ov000_02194758(self);
    ctl = self->ctl;
    ctl->unk_9a_0 = 0;
    ctl->unk_9a_3 = 0;
    func_0203f364(ctl);
    self->ctl->unk_30 = 0;
    if (self->kind == 0) {
        Ov003EaCam *cam = &data_ov000_021ccd54->cam;
        u16 a = Ov003EaCam_Angle(cam);
        a = a + (u16)(func_02040528(3) * 0xb6);
        self->pos.x = cam->pos.x;
        self->pos.y = cam->pos.y;
        self->pos.z = cam->pos.z;
        self->pos.x += Ov003Ea_FxMul(FX_SinCosTable_[(a >> 4) * 2], 0x14000);
        self->pos.z += Ov003Ea_FxMul(FX_SinCosTable_[(a >> 4) * 2 + 1], 0x14000);
        self->pos.y += 0x4000;
    } else {
        const Ov003EaSpot *sp = &data_ov003_021f6b8c[self->kind - 1];
        self->pos.x = sp->pos.x;
        self->pos.y = sp->pos.y;
        self->pos.z = sp->pos.z;
        self->rot_y += (u16)(sp->angle * 0xb6);
    }
    self->unk_98 = self->rot_y;
    func_ov000_02198360(self->work, 6, 0);
}
