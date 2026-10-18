#include "types.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 1;
} Ov003PropDef;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x8e];
    Ov003PropDef *unk_b0;
    u8 unk_b4[0x1c];
    s16 unk_d0;
    u8 unk_d2;
    u8 unk_d3;
    u8 unk_d4[0x84];
    char unk_158[0x20];
    char unk_178[0x20];
} Ov003Prop;

extern BOOL func_ov000_021946f8(void *self);
extern void *data_ov000_021ccd64;
extern char data_ov003_021f857a[];
extern void func_ov000_0219433c(void *self);
extern char *func_0207011c(u16 id);
extern char *func_02039674(char *p);
extern void func_0201e520(char *dst, const char *src);
extern void func_0201e78c(char *dst, const char *s);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e2090(Ov003Prop *self) {
    Ov003PropDef *def;
    Ov003Unit *u;
    func_ov000_0219433c(self);
    def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1) {
        char buf[0x18];
        char *name = func_0207011c(self->unk_0e);
        func_0201e520(buf, func_02039674(name));
        func_0201e78c(buf, data_ov003_021f857a);
        func_0201e520(self->unk_158, name);
        func_0201e520(self->unk_178, buf);
        self->unk_d3 |= 8;
        self->unk_d0 = 0;
    }
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

extern BOOL func_ov000_0218f110(s16 *p);

BOOL func_ov003_021e2148(Ov003Prop *self) {
    BOOL r = func_ov000_021946f8(self);
    Ov003PropDef *def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1 && self->unk_d0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_d0)) {
            r = FALSE;
        }
    }
    return r;
}

typedef struct {
    s32 x, y, z;
} Ov003LtVec;

typedef struct {
    s32 m[9];
    Ov003LtVec t;
} Ov003LtMtx;

typedef struct {
    Ov003LtVec ofs;
    u8 unk_0c[4];
    const char *name;
    u8 unk_14[0x18];
} Ov003LtDef;

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x1c];
    void *model;
    u8 unk_3c[0x1c];
    void *unk_58;
    u8 unk_5c[0x14];
    Ov003LtVec pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_82[2];
    Ov003LtVec prev;
} Ov003Lt;

extern const s16 FX_SinCosTable_[];
extern Ov003LtDef data_ov003_021f67c0[];
extern void func_ov000_02194758(void *self);
extern void VEC_Add(const Ov003LtVec *a, const Ov003LtVec *b, Ov003LtVec *out);
extern void MTX_Identity43_(Ov003LtMtx *m);
extern void MTX_RotX43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003LtMtx *a, Ov003LtMtx *b, Ov003LtMtx *out);
extern void func_0203f9dc(void *obj, Ov003LtMtx *m);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);

#define OV003LT_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003LT_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021e219c(Ov003Lt *self) {
    Ov003LtDef *def;
    void *obj;
    func_ov000_02194758(self);
    self->prev.x = self->pos.x;
    self->prev.y = self->pos.y;
    self->prev.z = self->pos.z;
    def = &data_ov003_021f67c0[self->unk_1a];
    if (self->unk_18 != 0) {
        VEC_Add(&self->pos, &def->ofs, &self->pos);
    }
    obj = self->unk_58;
    if (obj != NULL) {
        Ov003LtMtx t;
        Ov003LtMtx m;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set = FALSE;
        rz = self->rot_z;
        ry = self->rot_y;
        rx = self->rot_x;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003LT_SIN(rz), OV003LT_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003LT_SIN(ry), OV003LT_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003LT_SIN(ry), OV003LT_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003LT_SIN(rx), OV003LT_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003LT_SIN(rx), OV003LT_COS(rx));
                set = TRUE;
            }
        }
        m.t.x = self->pos.x;
        m.t.y = self->pos.y;
        m.t.z = self->pos.z;
        func_0203f9dc(obj, &m);
    }
    func_ov000_02190cb0(self->model, def->name, 0x1000, 0);
    func_ov000_021915a0(self->model);
}
