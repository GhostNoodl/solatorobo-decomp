#include "ov009/ov009.h"

extern "C" {

struct Ov009Mtx33 {
    s32 m[3][3];
};

extern void func_ov003_021d6868(Ov009Actor *self, s32 a);
extern void func_02011340(Ov009Mtx33 *m);
extern void func_020114a4(Ov009Mtx33 *m, s32 s, s32 c);
extern void func_0201146c(Ov009Mtx33 *m, s32 s, s32 c);
extern void func_02011488(Ov009Mtx33 *m, s32 s, s32 c);
extern void func_02011610(const Ov009Mtx33 *a, const Ov009Mtx33 *b, Ov009Mtx33 *out);
extern void func_02016dbc(const Ov009Mtx33 *src, void *dst);
extern void func_ov000_0218cea4(Ov009Actor *self);

void func_ov009_0220e0e4(Ov009Actor *self) {
    Ov009Mtx33 m;
    Ov009Mtx33 t;
    if (self->unk_50 != NULL && *self->unk_50 == 0) {
        func_ov003_021d6868(self, 0x3def);
    }
    self->unk_93_0 = 1;
    func_02011340(&m);
    func_020114a4(&t, OV009_SIN(self->rot[2]), OV009_COS(self->rot[2]));
    func_02011610(&m, &t, &m);
    func_0201146c(&t, OV009_SIN(self->rot[0]), OV009_COS(self->rot[0]));
    func_02011610(&m, &t, &m);
    func_02011488(&t, OV009_SIN(self->rot[1]), OV009_COS(self->rot[1]));
    func_02011610(&m, &t, &m);
    func_02016dbc(&m, (u8 *)self->unk_38 + 0x84);
    self->unk_38->unk_78 = self->pos;
    func_ov000_0218cea4(self);
}

}
