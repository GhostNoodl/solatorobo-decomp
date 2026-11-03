#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022179b4[];
extern u8 data_ov009_02216148[];
extern u8 data_ov009_02216058[];
extern u8 data_ov009_02216188[];
extern u8 data_ov009_02216070[];
extern Ov003Actor *ActorMgr_FindPlayer(void);

void Ov009ActVt_02217aac_Start(Ov009ActVt_02217aac *self) {
    GroupNode *p;
    Ov003Actor *a;
    FieldState *g;
    Ov003Actor_Start(self);
    p = Group_FindNode(gGroup, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
    }
    self->unk_93_4 = 1;
    self->target = 0xffff;
    a = ActorMgr_FindPlayer();
    if (a != NULL) {
        self->target = a->id;
    }
    Model0218fe1c_SetAnim(self->model, data_ov009_022179b4, 0x1000, 0);
    Model0218fe1c_SetLoop(self->model);
    self->unk_fc = 0;
    self->unk_fd = 0;
    self->unk_fe = 0;
    self->hit->offset.y = 0x1800;
    self->unk_44->unk_0c.y = 0x1800;
    self->unk_ff = 0;
    self->unk_100 = data_ov009_02216148;
    self->unk_104 = data_ov009_02216058;
    g = gSceneCmd;
    if (g->unk_ca.c[0] == 0x11 && g->unk_ca.c[1] == 0 && g->unk_ca.c[2] == 0) {
        self->unk_ff = 1;
        self->unk_100 = data_ov009_02216188;
        self->unk_104 = data_ov009_02216070;
    }
}

}
