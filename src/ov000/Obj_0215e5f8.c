#include "types.h"

typedef struct {
    u8 unk_00[0x6];
    u16 unk_06;
} Msg0215e634;

typedef struct {
    u8 unk_00[0x7c];
    u16 unk_7c;
} Dtcm02fe1534;

typedef struct Obj0215e5f8 {
    u8 unk_00[0x84];
    BOOL (*unk_84)(struct Obj0215e5f8 *self, Msg0215e634 *msg);
    u8 unk_88[0x154];
    void *unk_1dc;
} Obj0215e5f8;

extern void *gMsgRes;
extern void *gSndMgr;
extern Dtcm02fe1534 data_02fe1534;

void *func_02061d54(s32 a);
void *MsgRes_GetString(void *a, void *b);
void Lo021cb0b8_Setup(Obj0215e5f8 *self);
void func_0206281c(void);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);

void Ov000Vt_021cafc0_Setup(Obj0215e5f8 *self) {
    self->unk_1dc = MsgRes_GetString(gMsgRes, func_02061d54(0x18));
    Lo021cb0b8_Setup(self);
}

void Ov000Vt_021cafc0_Init(void) {
}

void Ov000Vt_021cafc0_Release(void) {
}

BOOL Ov000Vt_021cafc0_OnDecide(Obj0215e5f8 *self, Msg0215e634 *msg) {
    if (self->unk_84 != NULL) {
        return self->unk_84(self, msg);
    }
    if (msg == NULL) {
        func_0206281c();
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        return FALSE;
    }
    if (msg->unk_06 == 0) {
        data_02fe1534.unk_7c = 1;
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
    } else if (msg->unk_06 == 1) {
        data_02fe1534.unk_7c = 0;
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    }
    return FALSE;
}
