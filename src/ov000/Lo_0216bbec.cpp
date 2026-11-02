#include "ov000/LoCommon.h"
#include "ov000/LoTicker.h"

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
BOOL func_02054f10(void *a, s32 b);
BOOL func_0203e63c(void *p);
void func_ov000_0215eab4(void *p);

static inline BOOL LoResDone(u8 *o) {
    if (LFLD(void *, o, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, o, 0x6c))) {
        LFLD(void *, o, 0x6c) = NULL;
    } else {
        return LBIT(o, 4).b6 ? FALSE : TRUE;
    }
    return TRUE;
}

void func_ov000_0216bbec(LoTicker *self) {
    void *r = data_02149ef8;
    func_ov000_0216bae4(&self->res[1], MsgRes_GetString(r, 0x44));
    self->res[2].text = MsgRes_GetString(r, 0x45);
    self->res[3].text = MsgRes_GetString(r, 0x46);
    func_ov000_0216bae4(&self->res[4], MsgRes_GetString(r, 0x47));
    self->res[5].text = MsgRes_GetString(r, 0x43);
    func_ov000_0216bae4(&self->res[6], MsgRes_GetString(r, 0x3d));
    func_ov000_0216bae4(&self->res[7], MsgRes_GetString(r, 0x3e));
    func_ov000_0216bae4(&self->res[8], MsgRes_GetString(r, 0x3f));
    self->res[9].text = MsgRes_GetString(r, 0x42);
}

}
