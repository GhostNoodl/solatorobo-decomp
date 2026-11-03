#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217dc0[];
extern char data_ov014_02217d8e[];
extern char data_ov014_02217d95[];
extern ResSet *ResSet_Init(ResSet *p);
extern Model0218fe1c *Model0218fe1c_Init(Model0218fe1c *p);
extern Model0218fe1c *Model0218fe1c_FreeAnims(Model0218fe1c *p);
extern ResSet *ResSet_ReleaseAll(ResSet *p);
extern BOOL Actor_IsReady(Ov003Actor *self);
extern BOOL ResSet_UpdateLoad(void *p);
extern s32 Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);

BOOL Ov014Act_0221267c_IsReady(Ov014Act_0221267c *self) {
    BOOL r = Actor_IsReady(self);
    if (self->unk_f0.unk_00 >= 0) {
        r = (r & ResSet_UpdateLoad(&self->unk_f0)) ? TRUE : FALSE;
    }
    return r;
}

BOOL Ov014Act_0221267c_Draw(Ov014Act_0221267c *self) {
    return Ov003Actor_Draw(self);
}

extern char data_ov014_02217d9f[];
extern char data_ov014_02217da0[];
extern s32 Model_FindResIdxByName(void *m, const char *a, const char *b);
extern void Ov014Part_StartCapture_0220f8e4(u8 *self);

void Ov014Act_0221267c_Start(Ov014Act_0221267c *self) {
    Model0218fe1c *m;
    Ov003Actor_Start(self);
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
    self->unk_314.joint = Model_FindResIdxByName(self->model, data_ov014_02217d9f, data_ov014_02217da0);
    MTX_Identity43_(&self->unk_314.mtx);
    m = self->model;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)m->unk_24, (NNSG3dSbcCallBackFunc)Ov014Part_StartCapture_0220f8e4);
    m->clearInit = 0;
    self->model->flushVP = 1;
    self->model->renderUser = &self->unk_314;
    self->model->alpha = 0;
    self->model->boxTest = 0;
}

}
