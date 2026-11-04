#include "ov000/LoCommon.h"
#include "ov000/LoTicker.h"

extern "C" {

extern void *gMsgRes;
void *MsgRes_GetString(void *a, s32 b);

void LoTicker_InitTexts(LoTicker *self) {
    void *r = gMsgRes;
    LoTextHolder_SetText(&self->res[1], MsgRes_GetString(r, 0x44));
    self->res[2].text = MsgRes_GetString(r, 0x45);
    self->res[3].text = MsgRes_GetString(r, 0x46);
    LoTextHolder_SetText(&self->res[4], MsgRes_GetString(r, 0x47));
    self->res[5].text = MsgRes_GetString(r, 0x43);
    LoTextHolder_SetText(&self->res[6], MsgRes_GetString(r, 0x3d));
    LoTextHolder_SetText(&self->res[7], MsgRes_GetString(r, 0x3e));
    LoTextHolder_SetText(&self->res[8], MsgRes_GetString(r, 0x3f));
    self->res[9].text = MsgRes_GetString(r, 0x42);
}

}
