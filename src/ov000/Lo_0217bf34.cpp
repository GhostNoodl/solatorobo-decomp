#include "ov000/LoCommon.h"

struct LoDE { s32 d; s32 *e; };
extern "C" {

u16 func_0204045c(void);
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

BOOL func_ov000_0217bf34(void *self) {
    VObj *o = LFLD(VObj *, self, 0x64);
    if (o == NULL) {
        return FALSE;
    }
    if (!o->vfunc_1c()) {
        LFLD(s32, self, 0x68) = 0;
        LO_FREE_V(self, 0x64);
    } else {
        if (!LFLD(VObj *, self, 0x64)->vfunc_0c()) {
            return TRUE;
        }
        if (--LFLD(s32, self, 0x68) < 0) {
            LFLD(s32, self, 0x68) = 0;
        }
    }
    return FALSE;
}

}
