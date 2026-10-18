#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    s32 m[9];
} Ov003Mtx33;

typedef struct {
    u8 unk_00[0x78];
    Ov003Vec pos;
    u8 unk_84[0x24];
} Ov003SpinModel;

typedef struct {
    u8 unk_00[0x38];
    Ov003SpinModel *model;
    u8 unk_3c[0x34];
    Ov003Vec pos;
    u8 rot[0x17];
    u8 visible : 1;
    u8 unk_94[0x60];
    Ov003Vec offset;
    u8 unk_100[0];
    u16 angle;
} Ov003Spin;

extern void func_ov003_021ea234(Ov003Spin *self, Ov003Mtx33 *m, void *rot, u16 angle);
extern void func_02016dbc(Ov003Mtx33 *src, void *dst);
extern void func_02012be8(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern BOOL func_ov000_02194c08(void *self);

BOOL func_ov003_021e9af4(Ov003Spin *self) {
    Ov003Mtx33 m;
    Ov003Vec v;
    Ov003SpinModel *model;
    self->visible = 1;
    func_ov003_021ea234(self, &m, self->rot, self->angle);
    func_02016dbc(&m, self->model->unk_84);
    func_02012be8(&self->offset, &self->pos, &v);
    model = self->model;
    model->pos.x = v.x;
    model->pos.y = v.y;
    model->pos.z = v.z;
    return func_ov000_02194c08(self);
}
