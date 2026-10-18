#include "ov011/ov011.h"

extern "C" {

extern void *data_02097e4c;
extern Ov011Vec data_02092a50;
void func_ov000_0218996c(s32 a, s32 b);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);
void func_ov003_021d6054(void *p);
s32 *func_02027240(void);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);

static inline void Ov011_MulVec33(const Ov011Vec *v, const s32 *m, Ov011Vec *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m[0] + (s64)y * m[3] + (s64)z * m[6]) >> 12);
    out->y = (s32)(((s64)x * m[1] + (s64)y * m[4] + (s64)z * m[7]) >> 12);
    out->z = (s32)(((s64)x * m[2] + (s64)y * m[5] + (s64)z * m[8]) >> 12);
}

#pragma force_active on
void func_ov011_02204a8c(Ov011Actor *self) {
    Ov011Vec v;
    if (self->unk_40->state == 0) {
        func_ov000_0218996c(0xf, 0x3c);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        func_02065f88(4, &self->pos)->v0c(0x3800);
    }
    func_ov003_021d6054(self);
    Ov011_MulVec33(&FLD(Ov011Vec, self, 0xf0), func_02027240(), &v);
    VEC_Add(&v, &data_02092a50, &self->pos);
}
#pragma force_active reset
}
