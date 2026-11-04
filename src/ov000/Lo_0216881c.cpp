#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
void StageVars_ClearChoice(void);
u32 Rand_GetGlobal(void);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

void Lo021cb894_PostUpdate(Lo021cb894 *self) {
    s32 s = self->unk_04;
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (self->unk_0c_1 ? TRUE : FALSE) {
            self->unk_04 = 2;
        }
    }
    switch (self->unk_04) {
    case 8:
        self->unk_b8 = -8;
        break;
    case 0xa:
        if (!((self->unk_0c & 0x10000) ? TRUE : FALSE)) {
            self->unk_0c_1 = 1;
        }
        if (--self->unk_b8 < -8) {
            self->unk_b8 = 4;
        }
        self->unk_0c_16 = 0;
        break;
    }
}

}
