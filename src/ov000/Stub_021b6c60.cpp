#include "types.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/FieldState.h"
#include "ov000/FieldMgr.h"

extern "C" {
Robo021ca458 *ActorMgr_FindPlayer(void);
void TouchQuad_Init(void *q, u16 a, u16 b, u16 c, u16 d);

void func_ov000_021b6c60(FieldMgr *self) {
    Robo021ca458 *pl = ActorMgr_FindPlayer();
    LangBlockB *r;
    FieldCam *cam;
    if (pl == NULL || (r = self->blockB) == NULL) {
        return;
    }
    cam = &data_ov000_021ccd54->cam;
    if (cam != NULL) {
        s32 d = pl->pos.x - cam->base.at.x;
        s32 q;
        if (d > 0x5000) {
            d = 0x5000;
        } else if (d < -0x5000) {
            d = -0x5000;
        }
        q = d / 7;
        TouchQuad_Init(pl->unk_b70, r->unk_0a - q, r->unk_0c, r->unk_0e - q, r->unk_10);
    } else {
        TouchQuad_Init(pl->unk_b70, r->unk_0a, r->unk_0c, r->unk_0e, r->unk_10);
    }
}

}
