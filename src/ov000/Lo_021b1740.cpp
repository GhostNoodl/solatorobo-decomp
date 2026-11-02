#include "ov000/VObj.h"
#include "Main/Res/StageFlags.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 flags;
} Obj02097e48;

typedef struct {
    u8 unk_00[0x18];
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 13;
} Save0214a424;

extern "C" {
extern Obj02097e48 *data_02097e48;
extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
Robo021ca458 *ActorMgr_FindPlayer(void);
void func_02062764(s32 a, s32 b);


void func_ov000_021b1740(Robo021ca458 *self, BOOL flag) {
    u32 st;
    if (self->unk_b22_0 == 0) {
        return;
    }
    if (self->unk_b22_9 != 0) {
        return;
    }
    st = 0;
    if (((Save0214a424 *)data_0214a424)->b1 == 1) {
        st = 2;
    }
    if (self->unk_b22_9 < 2) {
        self->unk_b22_6 = (u16)st;
        self->unk_b22_9 = 1;
        self->fsm->flags |= 0x80000000;
        History_SetState(self->fsm, 0x1f, 0);
    }
    func_02062764(0x30, 0x10);
    if (flag) {
        data_ov000_021ccd54->stageFlags = 1;
    }
}

}
