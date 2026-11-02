#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"

extern "C" {

Robo021ca458 *func_ov000_0219bf90(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 func_02043d84(void *a);

struct Obj02165da0 {
    u8 unk_00[0x30];
    void *unk_30;
};

void func_ov000_02165da0(Obj02165da0 *self) {
    void *o = self->unk_30;
    void *q;
    if (o == NULL || (q = LFLD(void *, o, 0xcdc)) == NULL) {
        return;
    }
    if (LFLD(u16, q, 0x10a) != 0) {
        return;
    }
    LFLD(u16, q, 0x10a) = 1;
    LFLD(u16, LFLD(void *, o, 0xcdc), 0x10c) = LFLD(u8, LFLD(void *, o, 0xcdc), 0x108) - 1;
    LFLD(u16, LFLD(void *, o, 0xcdc), 0x10e) = 0;
}

struct Obj02165df4 {
    u8 unk_00[0x30];
    void *unk_30;
};

BOOL func_ov000_02165df4(Obj02165df4 *self) {
    void *o = self->unk_30;
    void *q;
    if (o == NULL || (q = LFLD(void *, o, 0xcdc)) == NULL) {
        return TRUE;
    }
    return LFLD(u16, q, 0x10a) == 0xffff ? TRUE : FALSE;
}

}
