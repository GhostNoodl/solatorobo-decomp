#include "ov002/ov002.h"

extern "C" {


BOOL Model021903b4_Draw(Model0218fe1c *a);

void Obj021efe7c_Draw(Obj021efe7c *self) {
    Obj021efe6c *w = self->board;
    Ov002CamPos *cam = w->cam;
    Obj021efe4c *q;
    Obj021efeb8 *n;
    NNS_G3dGlb.camPos = cam->eye;
    NNS_G3dGlb.camUp = cam->up;
    NNS_G3dGlb.camTarget = cam->at;
    MTX_LookAt(&cam->eye, &cam->up, &cam->at, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MTX_PerspectiveW(FX_SINCOS(0x2aa), FX_SINCOS(0x2ab), 0x1548, 0x333, 0x19000, 0x1000, (MtxFx44 *)data_02092800);
    NNS_G3dGlb.flag &= ~0x50;
    q = w->field;
    if (q->visible != 0) {
        MI_Copy36B(&q->rot, &q->unk_08->rot);
        q->unk_08->trans = q->trans;
        q->unk_08->scale = q->scale;
        Model021903b4_Draw(q->unk_08);
        MI_Copy36B(&q->rot, &q->unk_10->rot);
        q->unk_10->trans = q->trans;
        q->unk_10->scale = q->scale;
        Model021903b4_Draw(q->unk_10);
    }
    for (n = w->pieces; n != NULL; n = n->next) {
        if (n->unk_4a == 2) {
            Obj021efed4 *p = (Obj021efed4 *)n;
            p->unk_ac = p->unk_a8 <= (u16)w->unk_8a ? 2 : 1;
        }
        n->vfunc_10();
    }
    if (self->unk_08 != NULL) {
        self->unk_08->vfunc_14();
    }
}


void func_ov002_021dab58(Obj021efe7c *self, s32 mode) {
    if (((void *)self->unk_08) != NULL && self->unk_0c == mode) {
        return;
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->unk_08);
        HEAP_POP(saved);
    }
    switch (mode) {
    case 0: {
        Obj021eff74 *p = (Obj021eff74 *)Heap_Alloc(sizeof(Obj021eff74));
        if (p != NULL) {
            p->board = NULL;
            *(VFunc **)p = Ov002Vt_021eff74_vtbl;
            p->unk_08 = 0;
            p->unk_0c = NULL;
            p->unk_10 = NULL;
            p->unk_14 = 0;
            p->unk_18 = 0;
            p->unk_1c = 0;
            p->unk_20 = 0;
        }
        self->unk_08 = p;
        p->board = self->board;
        self->unk_08->vfunc_08();
        break;
    }
    case 1: {
        Obj021eff50 *p = (Obj021eff50 *)Heap_Alloc(sizeof(Obj021eff50));
        if (p != NULL) {
            p->board = NULL;
            *(VFunc **)p = Ov002Vt_021eff50_vtbl;
            p->unk_08 = 1;
            p->unk_0c = -1;
            p->unk_10 = NULL;
            p->unk_14 = 0;
            p->unk_18 = NULL;
            p->unk_20 = NULL;
            p->unk_24 = NULL;
            p->unk_34 = 0;
        }
        self->unk_08 = p;
        p->board = self->board;
        self->unk_08->vfunc_08();
        break;
    }
    case 2:
        break;
    case 3:
        break;
    }
    self->unk_0c = mode;
}

}
