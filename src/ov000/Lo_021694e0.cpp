#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
extern u8 data_02fe1534[];
void func_0206281c(void);
u32 Rand_GetGlobal(void);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

void Lo021cb7ec_PostUpdate(Lo021cb7ec *self) {
    s32 s = self->unk_04;
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (self->unk_0c_1 ? TRUE : FALSE) {
            self->unk_04 = 2;
        }
    }
    if (self->unk_04 == 0xa) {
        if (!((self->unk_0c & 0x10000) ? TRUE : FALSE)) {
            self->unk_0c_1 = 1;
        }
        self->unk_0c_16 = 0;
    }
    if (self->unk_a8 == 0) {
        return;
    }
    if (self->unk_a8 & 1) {
        self->unk_a4 = Rand_GetGlobal();
    }
    self->unk_a8--;
}

}
