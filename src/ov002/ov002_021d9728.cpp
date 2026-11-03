#include "ov002/ov002.h"

extern "C" {

void Model0218fe1c_UpdateAnim(void *a, s32 b);

s32 **Model0218fe1c_GetAnimCtrl(void *a, int b);


void Interp_SinLerpVec(VecFx32 *out, s32 t, void *a, void *b);

void Obj021efe6c_Update(Obj021efe6c *self) {
    VecFx32 a;
    VecFx32 b;
    Obj021efe4c *o;
    s32 x;
    Obj021efeb8 *n;
    Task021efba4 *t;
    o = self->field;
    Model0218fe1c_UpdateAnim(o->unk_08, 0x1000);
    Model0218fe1c_UpdateAnim(o->unk_10, 0x1000);
    {
        s32 **pp = Model0218fe1c_GetAnimCtrl(o->unk_10, 0);
        x = 0;
        if (*pp != NULL) {
            x = **pp;
        }
    }
    func_ov002_021d7320(o, x, 0x1000);
    for (n = self->pieces; n != NULL; n = n->next) {
        n->vfunc_0c();
    }
    t = (Task021efba4 *)Task_FindById(0x1b);
    if (t != NULL && self->unk_75) {
        Ov002Hud *m = t->hud;
        u8 k = self->unk_74;
        if (m != NULL) {
            Ov002Hud_SetRow(m, k, 0);
        }
        self->unk_75 = 0;
    }
    t = (Task021efba4 *)Task_FindById(0x1b);
    if (t != NULL && t->hud != NULL) {
        MI_CpuCopy8((u8 *)self + 0x76, t->hud->unk_2c, 0x14);
    }
    if (self->unk_90 < 0) {
        return;
    }
    {
        s32 f = FX_Div((self->unk_94 - self->unk_90) << 12, self->unk_94 << 12);
        Interp_SinLerpVec(&a, f, &self->unk_98, &self->unk_b0);
        Interp_SinLerpVec(&b, f, &self->unk_a4, &self->unk_bc);
    }
    self->cam->eye = a;
    self->cam->at = b;
    self->unk_90--;
}

}
