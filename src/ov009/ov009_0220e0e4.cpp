#include "ov009/ov009.h"

extern "C" {

struct Ov009Mtx33 {
    s32 m[3][3];
};

extern void func_ov003_021d6868(Ov009Actor *self, s32 a);
extern void MTX_Identity33_(Ov009Mtx33 *m);
extern void MTX_RotZ33_(Ov009Mtx33 *m, s32 s, s32 c);
extern void MTX_RotX33_(Ov009Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov009Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(const Ov009Mtx33 *a, const Ov009Mtx33 *b, Ov009Mtx33 *out);
extern void MI_Copy36B(const Ov009Mtx33 *src, void *dst);
extern void func_ov000_0218cea4(Ov009Actor *self);

void func_ov009_0220e0e4(Ov009Actor *self) {
    Ov009Mtx33 m;
    Ov009Mtx33 t;
    if (self->unk_50 != NULL && *self->unk_50 == 0) {
        func_ov003_021d6868(self, 0x3def);
    }
    self->unk_93_0 = 1;
    MTX_Identity33_(&m);
    MTX_RotZ33_(&t, OV009_SIN(self->rot[2]), OV009_COS(self->rot[2]));
    MTX_Concat33(&m, &t, &m);
    MTX_RotX33_(&t, OV009_SIN(self->rot[0]), OV009_COS(self->rot[0]));
    MTX_Concat33(&m, &t, &m);
    MTX_RotY33_(&t, OV009_SIN(self->rot[1]), OV009_COS(self->rot[1]));
    MTX_Concat33(&m, &t, &m);
    MI_Copy36B(&m, (u8 *)self->unk_38 + 0x84);
    self->unk_38->unk_78 = self->pos;
    func_ov000_0218cea4(self);
}

}
