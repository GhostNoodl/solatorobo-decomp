#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
void func_ov000_0216bae4(void *dst, void *src);
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

struct Obj0216bbec {
    u8 unk_00[0x37c];
    void *unk_37c;
    u8 unk_380[0x8];
    void *unk_388;
    u8 unk_38c[0x14];
    void *unk_3a0;
    u8 unk_3a4[0x2c];
    void *unk_3d0;
};

void func_ov000_0216bbec(Obj0216bbec *self) {
    void *r = data_02149ef8;
    func_ov000_0216bae4((u8 *)self + 0x36c, MsgRes_GetString(r, 0x44));
    self->unk_37c = MsgRes_GetString(r, 0x45);
    self->unk_388 = MsgRes_GetString(r, 0x46);
    func_ov000_0216bae4((u8 *)self + 0x390, MsgRes_GetString(r, 0x47));
    self->unk_3a0 = MsgRes_GetString(r, 0x43);
    func_ov000_0216bae4((u8 *)self + 0x3a8, MsgRes_GetString(r, 0x3d));
    func_ov000_0216bae4((u8 *)self + 0x3b4, MsgRes_GetString(r, 0x3e));
    func_ov000_0216bae4((u8 *)self + 0x3c0, MsgRes_GetString(r, 0x3f));
    self->unk_3d0 = MsgRes_GetString(r, 0x42);
}

}
