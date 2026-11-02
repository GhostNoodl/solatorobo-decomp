#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217dc0[];
extern char data_ov014_02217d8e[];
extern char data_ov014_02217d95[];
extern void *func_ov000_0218e9c4(void *p);
extern void *func_ov000_0218fe1c(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void MIi_CpuClearFast(s32 v, void *p, u32 n);
extern BOOL func_ov000_0218cf5c(Ov003Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern s32 func_ov003_021d1c00(Ov003Actor *self, Ov014Msg *msg);

BOOL Ov014Act_0221267c_IsReady(Ov014Act_0221267c *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->unk_f0 >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0xf0)) ? TRUE : FALSE;
    }
    return r;
}

BOOL Ov014Act_0221267c_Draw(Ov014Act_0221267c *self) {
    return func_ov003_021d16cc(self);
}

extern char data_ov014_02217d9f[];
extern char data_ov014_02217da0[];
extern s32 func_ov000_021909a8(void *m, const char *a, const char *b);
extern void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
extern void func_ov014_0220f8e4(u8 *self);

void Ov014Act_0221267c_Start(Ov014Act_0221267c *self) {
    Model0218fe1c *m;
    func_ov003_021d112c(self);
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->unk_3c != NULL) {
            VObj *v = self->unk_3c;
            if (v != NULL) {
                v->vfunc_04();
            }
            self->unk_3c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->hit->unk_30 = 0;
    {
        ActorSub48 *q = self->hit;
        q->unk_9a_1 = 0;
        q->unk_9a_4 = 0;
    }
    {
        ActorSub48 *q = self->hit;
        q->unk_9a_2 = 0;
        q->unk_9a_5 = 0;
    }
    {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    FLD(s32, self, 0x314) = func_ov000_021909a8(self->model, data_ov014_02217d9f, data_ov014_02217da0);
    MTX_Identity43_((MtxFx43 *)((u8 *)self + 0x318));
    m = self->model;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov014_0220f8e4);
    m->clearInit = 0;
    self->model->flushVP = 1;
    self->model->renderUser = &FLD(u8, self, 0x314);
    self->model->alpha = 0;
    FLD(Ov014Flags, self->model, 0xc2).b4 = 0;
}

}
