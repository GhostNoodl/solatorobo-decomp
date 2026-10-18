#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    s32 m[3][3];
} Ov003Mtx33;

typedef struct {
    s32 m[3][3];
    Ov003Vec t;
} Ov003Mtx43;

typedef struct {
    u8 unk_00[4];
    void *res;
    u8 unk_08[0x70];
    Ov003Vec pos;
    Ov003Mtx33 rot;
    u8 unk_a8[0x16];
    u8 alpha;
    u8 unk_bf[0x29];
} Ov003TrailModel;

typedef struct {
    Ov003Mtx43 mtx;
    u8 group;
    u8 unk_31[3];
} Ov003TrailHist;

typedef struct {
    u8 unk_00[0x70];
    Ov003Vec pos;
    u8 unk_7c[0x20];
    s32 fade;
    u8 unk_a0[0x9d0];
    Ov003TrailModel models[6];
    Ov003TrailHist hist[6];
    u8 unk_1118;
    u8 head;
    u8 cur;
    u8 unk_111b;
    Ov003Mtx33 rot;
    u8 unk_1140[0];
    Ov003Vec base;
    Ov003Vec out;
} Ov003Trail;

extern Ov003Trail *data_ov003_021fa680;
extern void MTX_Copy33To43_(const Ov003Mtx33 *src, Ov003Mtx43 *dst);
extern void NNSi_G3dModifyPolygonAttrMask(void *res, BOOL on, u32 mask);
extern void MI_Copy36B(const void *src, void *dst);
extern void MI_Copy48B(const void *src, void *dst);
extern void func_ov000_021903b4(Ov003TrailModel *model);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);

static inline void VSub(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *o) { o->x = a->x - b->x; o->y = a->y - b->y; o->z = a->z - b->z; }
BOOL func_ov003_021f2dd0(Ov003Trail *self) {
    Ov003Mtx43 m;
    Ov003Vec d;
    u8 idx;
    s32 i;
    Ov003TrailModel *mdl;
    idx = self->head;
    if (idx == 0xff) {
        idx = 0;
    }
    MTX_Copy33To43_(&self->rot, &m);
    m.t.x = self->pos.x;
    m.t.y = self->pos.y;
    m.t.z = self->pos.z;
    for (i = 0; i < 6; i++) {
        mdl = &self->models[idx];
        if (i == 5) {
            u8 a = (self->fade * 31) >> 12;
            if (a > 26) {
                a = 26;
            }
            mdl->alpha = a;
            NNSi_G3dModifyPolygonAttrMask(mdl->res, FALSE, 0x1f0000);
        } else {
            mdl->alpha = 31;
            NNSi_G3dModifyPolygonAttrMask(mdl->res, TRUE, 0x1f0000);
        }
        data_ov003_021fa680 = self;
        self->cur = idx;
        MI_Copy36B(&m, &mdl->rot);
        mdl->pos.x = m.t.x;
        mdl->pos.y = m.t.y;
        mdl->pos.z = m.t.z;
        func_ov000_021903b4(mdl);
        MI_Copy48B(&self->hist[idx], &m);
        idx++;
        if (idx >= 6) {
            idx = 0;
        }
    }
    if (self->head == 0xff) {
        self->head = 0;
        VSub(&self->pos, &self->hist[self->head].mtx.t, &d);
        VEC_Add(&self->base, &d, &self->out);
    }
    return TRUE;
}
