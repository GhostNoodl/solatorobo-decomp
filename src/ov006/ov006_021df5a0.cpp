#include "ov006/Model.h"
#include <nitro/fx.h>

typedef struct ov006_Name021df5a0 {
    u16 c[4];
} ov006_Name021df5a0;

typedef struct ov006_Loader021df5a0 {
    void *vtbl;
    u8 ready;
    u8 unk5;
    ov006_Name021df5a0 name;
    u8 unkE;
    u8 unkF;
    s32 x;
    s32 y;
    s32 z;
    ov006_Model *model;
} ov006_Loader021df5a0;

typedef struct ov006_Unk021df5a0 {
    void *vtbl;
    u8 state;
    u8 unk5[3];
    int timer;
    u32 flags;
    VecFx32 pos;
    VecFx32 off;
    ov006_Name021df5a0 names[10];
    u8 kinds[10];
    u8 count;
    u8 unk83;
    int alpha;
    ov006_Loader021df5a0 *unk88;
    ov006_Model *unk8C;
    ov006_Model *unk90;
} ov006_Unk021df5a0;

extern "C" {

void func_0204918c(VecFx32 *out, fx32 t, const VecFx32 *from, const VecFx32 *to);
void func_02041c18(ov006_Model *m, const void *name);

static inline void ov006_Loader021df5a0_SetPos(ov006_Loader021df5a0 *l, s32 x, s32 y, s32 z) {
    l->x = x;
    l->y = y;
    l->z = z;
}

static inline void ov006_Loader021df5a0_SetName(ov006_Loader021df5a0 *l, const ov006_Name021df5a0 *name, u8 kind) {
    l->name.c[0] = name->c[0];
    l->name.c[1] = name->c[1];
    l->name.c[2] = name->c[2];
    l->name.c[3] = name->c[3];
    l->unkE = kind;
}

static inline void ov006_Loader021df5a0_Draw(ov006_Loader021df5a0 *l) {
    if (!l->ready) {
        return;
    }
    func_02041c18(l->model, &l->name);
    {
        ov006_Model *m = l->model;
        m->unkFC[0].x = l->x;
        m->unkFC[0].y = l->y;
    }
    l->model->unk150 = l->z;
    if (l->unkE) {
        ov006_Model_PlayPart(l->model, 0x1e);
    } else {
        ov006_Model_PlayPart(l->model, 0x24);
    }
    ov006_Model_PlayPart(l->model, 0x1f);
}

static inline fx32 ov006_Clamp021df5a0(fx32 t) {
    if (t > 0x1000) {
        t = 0x1000;
    } else if (t < 0) {
        t = 0;
    }
    return t;
}

void func_ov006_021df5a0(ov006_Unk021df5a0 *self) {
    VecFx32 from;
    VecFx32 out;
    int n;
    s32 base;
    int i;
    s32 x;
    s32 y;
    if (self->state == 0 || self->count == 0) {
        return;
    }
    self->off.z = self->pos.z;
    VEC_Add(&self->pos, &self->off, &from);
    base = (self->count + 1) * -9;
    func_0204918c(&out, ov006_Clamp021df5a0(FX_Div(self->alpha << 12, 0xa000)), &from, &self->pos);
    ov006_Model_SetPos(self->unk8C, 0, ((out.x >> 12) + 0x3e) << 12, (base + (out.y >> 12)) << 12);
    self->unk8C->unk150 = out.z;
    ov006_Model_PlayPart(self->unk8C, 0xe);
    n = self->count;
    for (i = 0; i < n; i++) {
        func_0204918c(&out, ov006_Clamp021df5a0(FX_Div((self->alpha - i * 2) << 12, 0xa000)), &from, &self->pos);
        x = out.x;
        y = out.y;
        x >>= 12;
        y = base + (i * 9 + (y >> 12) + 8);
        ov006_Model_SetPos(self->unk90, 0, x << 12, y << 12);
        self->unk90->unk150 = out.z;
        func_02041c18(self->unk90, (const void *)(i + 1));
        ov006_Model_PlayPart(self->unk90, 0x1e);
        ov006_Loader021df5a0_SetPos(self->unk88, (s16)(x + 0xc) << 12, (s16)y << 12, self->unk88->z);
        self->unk88->z = out.z;
        {
            ov006_Loader021df5a0_SetName(self->unk88, &self->names[i], self->kinds[i]);
        }
        ov006_Loader021df5a0_Draw(self->unk88);
    }
}

}
