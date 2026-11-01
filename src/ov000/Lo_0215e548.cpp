#include "ov000/LoCommon.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 data_02fe1534[];
void func_0206281c(void);
u32 func_0204045c(void);
void func_ov000_0215f0ec(void *p, void *q);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

struct Obj0215e548 {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x74];
    LoMsgFn unk_84;
};

BOOL func_ov000_0215e548(Obj0215e548 *self, void *msg) {
    LoMsgFn fn = self->unk_84;
    if (fn) {
        return fn(self, msg);
    }
    if (msg == NULL) {
        if (self->unk_0c & 0x4000000) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            return TRUE;
        }
        func_0206281c();
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        return FALSE;
    }
    LFLD(u16, data_02fe1534, 0x7c) = LFLD(u16, msg, 6);
    func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    return FALSE;
}

}
