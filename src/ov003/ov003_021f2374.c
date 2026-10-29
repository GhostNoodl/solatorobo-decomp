#include "types.h"

typedef struct {
    s16 res;
    u8 unk_02[0x136];
} Ov003MultiSlot;

typedef struct {
    u8 unk_00[4];
    void *mdl;
    u8 unk_08[0x1c];
    u8 rob[0x84];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xe];
    u16 unk_c2_0 : 4;
    u16 unk_c2_4 : 1;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 1;
    u16 unk_c2_7 : 1;
    u16 unk_c2_8 : 1;
    u8 unk_c4[0x24];
} Ov003MultiModel;

typedef struct {
    s32 m[12];
    u8 unk_30;
    u8 unk_31[3];
} Ov003MultiMtx;

typedef struct {
    s32 m[9];
} Ov003MultiMtx33;

typedef struct Ov003Multi Ov003Multi;
struct Ov003Multi {
    u8 unk_00[8];
    u32 flags;
    u8 unk_0c[0xc];
    s16 kind;
    u8 unk_1a[0xa];
    void (*func)(Ov003Multi *self);
    u8 unk_28[0x48];
    s32 posX;
    s32 posY;
    s32 posZ;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk_82[0x10];
    u8 state;
    u8 unk_93[0x1b];
    u8 group;
    u8 unk_af;
    Ov003MultiSlot slots[8];
    Ov003MultiModel models[6];
    Ov003MultiMtx mtx[6];
    u8 unk_1118;
    u8 unk_1119;
    u8 unk_111a[2];
    Ov003MultiMtx33 rot;
    s32 unk_1140[3];
    s32 unk_114c[3];
};

typedef struct {
    u8 unk_00[0x30];
    u8 group;
    u8 unk_31[3];
} Ov003MultiTarget;

typedef struct {
    u8 unk_00[0xfe0];
    Ov003MultiTarget targets[5];
    u8 unk_10e4[0x36];
    u8 cur;
} Ov003MultiMgr;

typedef struct {
    void *res;
    s32 x;
    s32 y;
    s32 z;
} Ov003MultiRes;

typedef struct {
    Ov003MultiRes *res;
    s8 *map;
    u16 count;
    u8 unk_0a[6];
} Ov003MultiDef;

extern Ov003MultiMgr *data_ov003_021fa680;
extern const Ov003MultiDef data_ov003_021f7470[];

extern void NNS_G3dGetCurrentMtx(void *p, s32 a);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0218f110(s16 *p);
extern BOOL func_ov000_0218ffdc(Ov003MultiModel *m, Ov003MultiSlot *slot, s32 a, s32 b);
extern void func_ov000_02190e98(Ov003MultiModel *m, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(Ov003MultiModel *m);
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, BOOL on, u32 mask);
extern void NNSi_G3dModifyMatFlag(void *mdl, BOOL on, u32 flag);
extern s32 func_ov000_021909a8(Ov003MultiModel *m, const void *a, const void *b);
extern void MTX_Identity43_(Ov003MultiMtx *m);
extern void NNS_G3dRenderObjSetInitFunc(void *rob, void *func);
extern char data_ov003_021fa2ce[];
extern const s16 FX_SinCosTable_[];
extern void MTX_Identity33_(Ov003MultiMtx33 *m);
extern void MTX_RotX33_(Ov003MultiMtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov003MultiMtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov003MultiMtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov003MultiMtx33 *a, Ov003MultiMtx33 *b, Ov003MultiMtx33 *out);
void func_ov003_021f23e0(Ov003Multi *self);

#define OV003MU_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003MU_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021f2374(Ov003Multi *self) {
    Ov003MultiMgr *mgr = data_ov003_021fa680;
    Ov003MultiTarget *t;
    s32 group;
    if (mgr == NULL) {
        return;
    }
    t = &mgr->targets[mgr->cur];
    if (self->flags & 0x10) {
        group = self->group;
    } else {
        group = -1;
    }
    if (t->group == 0xff) {
        return;
    }
    if (t->group != group) {
        return;
    }
    NNS_G3dGetCurrentMtx(t, 0);
    self->func = NULL;
    self->state = 0;
}

void func_ov003_021f23e0(Ov003Multi *self) {
    self->func = func_ov003_021f2374;
    self->state = 3;
}

void func_ov003_021f23f8(Ov003Multi *self) {
    const Ov003MultiDef *def = &data_ov003_021f7470[self->kind];
    s32 i;
    u16 n = def->count;
    if (n > 8) {
        n = 8;
    }
    for (i = 0; i < n; i++) {
        func_ov000_0218f074(&self->slots[i].res, def->res[i].res, 1, 1, 0, 0);
        self->slots[i].res = 0;
    }
}

BOOL func_ov003_021f247c(Ov003Multi *self) {
    const Ov003MultiDef *def = &data_ov003_021f7470[self->kind];
    BOOL r = TRUE;
    s32 i = 0;
    for (; i < def->count; i++) {
        if (self->slots[i].res >= 0) {
            if (!func_ov000_0218f110(&self->slots[i].res)) {
                r = FALSE;
            }
        }
    }
    return r;
}


void func_ov003_021f24ec(Ov003Multi *self) {
    const Ov003MultiDef *def = &data_ov003_021f7470[self->kind];
    Ov003MultiRes *res;
    s8 *map;
    s32 idx;
    Ov003MultiModel *m;
    s32 i;
    BOOL set;
    Ov003MultiMtx33 t;
    u16 rz;
    u16 ry;
    u16 rx;
    map = def->map;
    for (i = 0; i < 6; i++) {
        idx = map[i];
        if (idx < 0) {
            idx = 0;
        }
        m = &self->models[i];
        func_ov000_0218ffdc(m, &self->slots[idx], 0, 1);
        m->unk_c2_4 = 0;
        func_ov000_02190e98(m, 0, 0x1000, 0);
        func_ov000_021915a0(m);
        m->unk_a8 = def->res[idx].x;
        m->unk_ac = def->res[idx].y;
        m->unk_b0 = def->res[idx].z;
        NNSi_G3dModifyPolygonAttrMask(m->mdl, TRUE, 0x3f000000);
        NNSi_G3dModifyMatFlag(m->mdl, TRUE, 0x40);
        NNSi_G3dModifyMatFlag(m->mdl, TRUE, 0x80);
        NNSi_G3dModifyMatFlag(m->mdl, TRUE, 0x200);
        NNSi_G3dModifyMatFlag(m->mdl, TRUE, 0x400);
        m->unk_c2_7 = 1;
        NNSi_G3dModifyPolygonAttrMask(m->mdl, TRUE, 0x1f0000);
        {
            u8 r = func_ov000_021909a8(m, 0, data_ov003_021fa2ce);
            self->mtx[i].unk_30 = r;
        }
        MTX_Identity43_(&self->mtx[i]);
        NNS_G3dRenderObjSetInitFunc(m->rob, func_ov003_021f23e0);
        m->unk_c2_5 = 0;
        m->unk_c2_8 = 1;
    }
    self->unk_1118 = 5;
    self->unk_1119 = 0xff;
    rz = self->rotZ;
    ry = self->rotY;
    rx = self->rotX;
    set = FALSE;
    MTX_Identity33_(&self->rot);
    if (rz != 0) {
        MTX_RotZ33_(&self->rot, OV003MU_SIN(rz), OV003MU_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY33_(&t, OV003MU_SIN(ry), OV003MU_COS(ry));
            MTX_Concat33(&t, &self->rot, &self->rot);
        } else {
            MTX_RotY33_(&self->rot, OV003MU_SIN(ry), OV003MU_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX33_(&t, OV003MU_SIN(rx), OV003MU_COS(rx));
            MTX_Concat33(&t, &self->rot, &self->rot);
        } else {
            MTX_RotX33_(&self->rot, OV003MU_SIN(rx), OV003MU_COS(rx));
            set = TRUE;
        }
    }
    self->unk_1140[0] = self->posX;
    self->unk_1140[1] = self->posY;
    self->unk_1140[2] = self->posZ;
    self->unk_114c[0] = self->posX;
    self->unk_114c[1] = self->posY;
    self->unk_114c[2] = self->posZ;
}
