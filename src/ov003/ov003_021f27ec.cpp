#include "types.h"

extern "C" {

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003MVec;

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
    s32 m[9];
    Ov003MVec t;
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
    Ov003MVec pos;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk_82[0x10];
    u8 state;
    u8 unk_93[9];
    s32 unk_9c;
    u8 unk_a0[0xe];
    u8 group;
    u8 unk_af;
    Ov003MultiSlot slots[8];
    Ov003MultiModel models[6];
    Ov003MultiMtx mtx[6];
    u8 unk_1118;
    u8 unk_1119;
    u8 unk_111a[2];
    Ov003MultiMtx33 rot;
    Ov003MVec unk_1140;
    Ov003MVec unk_114c;
};

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
    u8 unk_0a[2];
    s32 speed;
} Ov003MultiDef;

typedef struct {
    u8 unk_00[0x42];
    u16 unk_42;
    u16 unk_44;
    u8 unk_46[0x94];
    u8 unk_da_0 : 4;
    u8 unk_da_4 : 1;
    u8 unk_da_5 : 1;
    u8 unk_da_6 : 1;
    u8 unk_db[0x1d];
    u16 unk_f8;
    u16 unk_fa;
    s16 unk_fc;
} Ov003MCam;

typedef struct {
    u8 r, g, b;
} Ov003MCol;

typedef struct {
    u8 unk_00[0x90];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x32];
    Ov003MCol unk_ca;
} Ov003MGame;

typedef struct {
    u8 unk_00[0x14];
    u8 unk_14;
} Ov003MLv;

typedef struct {
    u8 unk_00[0x44];
    Ov003MCol col44;
    u8 unk_47;
} Ov003MArea;

typedef struct {
    u8 unk_00[0xa];
    u8 unk_0a;
    u8 unk_0b[9];
    Ov003MLv *lv;
    Ov003MArea *area;
} Ov003MCtx;

typedef struct {
    u8 unk_00[0x16];
    u16 unk_16;
} Ov003MActor;

#define OV003M_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV003M_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV003M_SQRT_PARAM (*(volatile u64 *)0x40002b8)

extern const Ov003MultiDef data_ov003_021f7470[];
extern char data_ov003_021fa2ce[];
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern Ov003MCtx *data_ov000_021ccd6c;

extern BOOL func_01ffc198(Ov003MVec *a, Ov003MVec *b, s32 r);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218ffdc(Ov003MultiModel *m, Ov003MultiSlot *slot, s32 a, s32 b);
extern void func_ov000_02190e98(Ov003MultiModel *m, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(Ov003MultiModel *m);
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, BOOL on, u32 mask);
extern void NNSi_G3dModifyMatFlag(void *mdl, BOOL on, u32 flag);
extern u8 func_ov000_021909a8(Ov003MultiModel *m, const void *a, const void *b);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Identity43_(Ov003MultiMtx *m);
extern void NNS_G3dRenderObjSetInitFunc(void *rob, void *func);
extern void VEC_Add(const Ov003MVec *a, const Ov003MVec *b, Ov003MVec *out);
extern void VEC_MultAdd(s32 scale, const Ov003MVec *dir, const Ov003MVec *base, Ov003MVec *out);
extern void MTX_MultVec43(const Ov003MVec *v, const Ov003MultiMtx *m, Ov003MVec *out);
extern u16 FX_Atan2(s32 y, s32 x);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern Ov003MActor *func_ov000_0218e4cc(void *mgr, u16 id);
extern void *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern void func_0203cc58(s32 a, s32 b, s32 c);
extern void func_ov000_02188140(void *g, s32 a, s32 b, s32 c);
extern void func_ov000_02188ca0(Ov003MCol *c, s32 a);
void func_ov003_021f23e0(Ov003Multi *self);

static inline void VSub(const Ov003MVec *a, const Ov003MVec *b, Ov003MVec *o) { o->x = a->x - b->x; o->y = a->y - b->y; o->z = a->z - b->z; }
static inline u8 Ov003M_Level(Ov003MLv *lv) {
    return lv != NULL ? lv->unk_14 : 0;
}

static inline BOOL Ov003M_Busy(Ov003MGame *g) {
    return g->unk_90 != g->unk_94;
}

void func_ov003_021f27ec(Ov003Multi *self) {
    const Ov003MultiDef *def;
    Ov003MultiModel *m;
    s32 idx;
    Ov003MVec v;
    Ov003MVec d;
    Ov003MVec w;
    Ov003MCam *cam;
    Ov003MCtx *ctx;
    Ov003MArea *area;
    Ov003MGame *gm;
    Ov003MActor *a;
    void *mgr;
    u16 rx;
    u16 ry;
    u16 ang;
    s32 r;
    u8 cr, cg, cb;
    Ov003MCol col;

    if (self->unk_1119 == 0xff) {
        return;
    }
    def = &data_ov003_021f7470[self->kind];
    if (func_01ffc198(&self->unk_114c, &self->pos, 0x1000)) {
        idx = def->map[++self->unk_1118];
        if (idx < 0) {
            self->unk_1118 = 0;
            idx = def->map[self->unk_1118];
        }
        m = &self->models[self->unk_1119];
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
        self->mtx[self->unk_1119].unk_30 = func_ov000_021909a8(m, 0, data_ov003_021fa2ce);
        MI_Copy36B(&self->mtx[self->unk_1119], &self->rot);
        MTX_Identity43_(&self->mtx[self->unk_1119]);
        NNS_G3dRenderObjSetInitFunc(m->rob, func_ov003_021f23e0);
        m->unk_c2_5 = 0;
        m->unk_c2_8 = 1;
        if (++self->unk_1119 >= 6) {
            self->unk_1119 = 0;
        }
        v.x = self->unk_1140.x - self->unk_114c.x;
        v.y = self->unk_1140.y - self->unk_114c.y;
        v.z = self->unk_1140.z - self->unk_114c.z;
        VEC_Add(&self->pos, &v, &self->pos);
        VSub(&self->pos, &self->mtx[self->unk_1119].t, &v);
        VEC_Add(&self->unk_1140, &v, &self->unk_114c);
        self->unk_9c = 0;
        if (self->unk_1119 == 0 || self->unk_1119 == 3) {
            func_02049a48(data_02097e4c, 0x51, -1, -1, -1);
        }
    }
    self->unk_9c += def->speed;
    d.x = self->unk_114c.x - self->unk_1140.x;
    d.y = self->unk_114c.y - self->unk_1140.y;
    d.z = self->unk_114c.z - self->unk_1140.z;
    VEC_MultAdd(self->unk_9c, &d, &self->unk_1140, &v);
    w.x = v.x - self->pos.x;
    w.y = v.y - self->pos.y;
    w.z = v.z - self->pos.z;
    VEC_MultAdd(0x800, &w, &self->pos, &self->pos);

    cam = (Ov003MCam *)(data_ov000_021ccd54 + 0xf4);
    if (cam != NULL) {
        rx = cam->unk_42;
        ry = cam->unk_44;
        v.z = 0x1000;
        v.x = 0;
        v.y = 0;
        MTX_MultVec43(&v, &self->mtx[self->unk_1119], &v);
        ang = FX_Atan2(v.x, v.z);
        if (ang != ry) {
            ang = func_01ffc128(ang, ry, 0x400, 1, 0x8000);
            cam->unk_fa = ang;
            cam->unk_da_5 = 1;
            cam->unk_fc = (s16)((s16)ang - (s16)ry) >> 1;
            cam->unk_da_6 = 1;
        }
        {
            s64 sq = (s64)v.x * v.x;
            sq += (s64)v.z * v.z;
            OV003M_SQRTCNT = 1;
            OV003M_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV003M_SQRTCNT & 0x8000) {
        }
        ang = FX_Atan2(-v.y >> 1, (s32)(OV003M_SQRT_RESULT + 1) >> 1) + 0x400;
        if (ang != rx) {
            cam->unk_f8 = func_01ffc128(ang, rx, 0x400, 1, 0x8000);
            cam->unk_da_4 = 1;
        }
    }

    a = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
    if (a != NULL && a->unk_16 != 0) {
        return;
    }
    mgr = data_ov000_021ccd68;
    if ((mgr == NULL ? NULL : func_ov000_0218e6d0(mgr, 0x4000, 0x400c)) != NULL) {
        return;
    }
    ctx = data_ov000_021ccd6c;
    area = ctx->area;
    if (Ov003M_Level(ctx->lv) < 1) {
        return;
    }
    gm = (Ov003MGame *)data_ov000_021ccd54;
    if (Ov003M_Busy(gm)) {
        return;
    }
    cr = area->col44.r;
    cg = area->col44.g;
    cb = area->col44.b;
    if (cr == 0xff) {
        cr = gm->unk_ca.r;
    }
    if (cg == 0xff) {
        cg = gm->unk_ca.g;
    }
    if (cb == 0xff) {
        cb = gm->unk_ca.b;
    }
    ctx->unk_0a = area->unk_47;
    func_0203cc58(0x3c000, 2, 0);
    func_ov000_02188140(data_ov000_021ccd54, 1, 0, 0);
    col.r = cr;
    col.g = cg;
    col.b = cb;
    func_ov000_02188ca0(&col, 1);
}

}
