#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char data_0214b105[];
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_ov000_021ccd44;
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb6d0[];
void func_ov000_0216f23c(void *p, s32 a);
BOOL func_ov000_02180900(void *p);
void func_ov000_0216fb14(void *p);

typedef struct { u32 lo : 4; } LoNib;

BOOL func_ov000_02172bb4(TimedBuffer021cb920 *self) {
    if (((s32)self->unk_20) == 0) {
        return TRUE;
    }
    if (((VObj *)self->unk_30) == NULL) {
        return FALSE;
    }
    return ((VObj *)self->unk_30)->vfunc_08();
}

}
