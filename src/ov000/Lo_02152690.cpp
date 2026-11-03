#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
void func_0206281c(void);
u32 Rand_GetGlobal(void);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

s32 UiObj_GetSlide(UiObj *self, s32 *out, s32 *outS, s32 ang) {
    s32 s;
    s32 t;
    if (ang == -1) {
        ang = self->openRatio;
    }
    s = FX_SinCosTable_[((ang << 14) >> 16) * 2];
    t = self->slideMode;
    if (t == 0) {
        if (outS) {
            *outS = s;
        }
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
    } else if (t == 1) {
        s32 k;
        if (outS) {
            *outS = 0x1000;
        }
        k = 0x1000 - s;
        out[0] = LO_FX_MUL(k, self->slideX << 12);
        out[1] = LO_FX_MUL(k, self->slideY << 12);
        out[2] = 0;
    }
    return s;
}

}
