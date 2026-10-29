#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003AkVec;

typedef struct {
    u16 x, y, z;
} Ov003AkRot;

typedef struct {
    s32 m[9];
} Ov003AkMtx;

typedef struct {
    u8 unk_00[0xa];
    s16 fx;
    s16 ox;
    s16 oy;
    s16 oz;
    s16 scale;
    u8 unk_14[0xe];
    s16 sound;
    u8 unk_24[6];
    u16 unk_2a_0 : 6;
    u16 unk_2a_6 : 1;
    u16 unk_2a_7 : 3;
    u16 unk_2a_10 : 1;
    u8 unk_2c[4];
    u32 unk_30;
    u32 unk_34;
    void *unk_38;
} Ov003AkDef;

typedef struct {
    u8 unk_00[0x10];
    u32 unk_10;
} Ov003AkS44;

typedef struct {
    u8 unk_00[0x30];
    u32 unk_30;
    u8 unk_34[0x2c];
    u32 unk_60;
    u8 unk_64[0x36];
    u16 unk_9a_0 : 7;
    u16 unk_9a_7 : 1;
} Ov003AkCtl;

typedef struct {
    u8 unk_00[0xc2];
    u16 unk_c2_0 : 2;
    u16 unk_c2_2 : 1;
} Ov003AkModel;

class Ov003AkFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void SetOffset(Ov003AkVec *v);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Ov003AkRot *r);
};

typedef struct {
    u8 unk_00[0x18];
    s16 kind;
    u8 unk_1a[0x1e];
    Ov003AkModel *model;
    u8 unk_3c[4];
    void *work;
    Ov003AkS44 *unk_44;
    Ov003AkCtl *ctl;
    u8 unk_4c[0x14];
    Ov003AkDef *unk_60;
    u8 unk_64[0xc];
    Ov003AkVec pos;
    Ov003AkRot rot;
    u8 unk_82[0x4a];
    u16 unk_cc_0 : 2;
    u16 unk_cc_2 : 1;
    u8 unk_ce[2];
    Ov003AkDef *atk;
    void *unk_d4;
    u8 unk_d8[0x10];
    Ov003AkVec unk_e8;
} Ov003Ak;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern Ov003AkDef data_ov003_021f4a34[];
extern u8 data_ov003_021f49c4[];
extern Ov003AkVec data_02092a50;
extern void *data_02097e4c;
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003AkMtx *NNS_G3dGlbGetInvV(void);
extern void VEC_Add(Ov003AkVec *a, Ov003AkVec *b, Ov003AkVec *dst);
extern void *func_02049f44(void *mgr, s32 id, Ov003AkVec *pos, s32 a);
extern Ov003AkFx *func_02065f88(s32 id, Ov003AkVec *pos);
extern void MTX_Identity33_(Ov003AkMtx *m);
extern void MTX_RotX33_(Ov003AkMtx *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov003AkMtx *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov003AkMtx *m, s32 s, s32 c);
extern void MTX_Concat33(Ov003AkMtx *a, Ov003AkMtx *b, Ov003AkMtx *out);
extern void MTX_MultVec33(Ov003AkVec *v, Ov003AkMtx *m, Ov003AkVec *out);

#define OV003AK_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003AK_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021daec0(Ov003Ak *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->work, 0xb, 0);
    if (self->unk_60 != NULL) {
        self->atk = self->unk_60;
    } else {
        self->atk = &data_ov003_021f4a34[self->kind];
    }
    self->unk_d4 = self->atk->unk_38;
    if (self->unk_d4 == NULL) {
        self->unk_d4 = data_ov003_021f49c4;
    }
    if (self->atk->unk_2a_10) {
        Ov003AkMtx *m;
        s32 x;
        s32 y;
        s32 z;
        self->unk_e8.x = self->pos.x;
        self->unk_e8.y = self->pos.y;
        self->unk_e8.z = self->pos.z;
        m = NNS_G3dGlbGetInvV();
        y = self->pos.y;
        x = self->pos.x;
        z = self->pos.z;
        self->pos.x = (s32)(((s64)x * m->m[0] + (s64)y * m->m[3] + (s64)z * m->m[6]) >> 12);
        self->pos.y = (s32)(((s64)x * m->m[1] + (s64)y * m->m[4] + (s64)z * m->m[7]) >> 12);
        self->pos.z = (s32)(((s64)x * m->m[2] + (s64)y * m->m[5] + (s64)z * m->m[8]) >> 12);
        VEC_Add(&self->pos, &data_02092a50, &self->pos);
    }
    if (self->atk->sound >= 0) {
        func_02049f44(data_02097e4c, self->atk->sound, &self->pos, 0);
    }
    if (self->atk->fx != -1) {
        Ov003AkFx *e = func_02065f88(self->atk->fx, &self->pos);
        Ov003AkVec v;
        Ov003AkMtx m;
        Ov003AkMtx t;
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        s32 s;
        e->SetRot(&self->rot);
        set = FALSE;
        v.x = self->atk->ox << 4;
        v.y = self->atk->oy << 4;
        v.z = self->atk->oz << 4;
        ry = self->rot.y;
        rz = self->rot.z;
        rx = self->rot.x;
        MTX_Identity33_(&m);
        if (ry != 0) {
            MTX_RotY33_(&m, OV003AK_SIN(ry), OV003AK_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&t, OV003AK_SIN(rx), OV003AK_COS(rx));
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotX33_(&m, OV003AK_SIN(rx), OV003AK_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_(&t, OV003AK_SIN(rz), OV003AK_COS(rz));
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotZ33_(&m, OV003AK_SIN(rz), OV003AK_COS(rz));
                set = TRUE;
            }
        }
        MTX_MultVec33(&v, &m, &v);
        e->SetOffset(&v);
        s = self->atk->scale << 4;
        e->SetScale(s, s, s);
    }
    if (self->unk_44 != NULL) {
        self->unk_44->unk_10 = 0;
    }
    if (self->ctl != NULL) {
        self->ctl->unk_30 = self->atk->unk_30;
        self->ctl->unk_60 = 0;
        self->ctl->unk_9a_7 = 1;
    }
    if (self->atk->unk_2a_6 && self->model != NULL) {
        self->model->unk_c2_2 = 1;
    }
    if (self->atk->unk_2a_7 & 4) {
        self->unk_cc_2 = 1;
    }
}

}
