#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char data_0214b105[];
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *gTaskHost;
extern u8 Ov000Vt_021cb940_vtbl[];
extern u8 Ov000Vt_021cb6d0_vtbl[];
void func_ov000_0216f23c(void *p, s32 a);
BOOL TaskHost_Update(void *p);
void ListBuffer021cb940_Release(void *p);

typedef struct { u32 lo : 4; } LoNib;

BOOL TimedBuffer021cb920_IsReady(TimedBuffer021cb920 *self) {
    if (((s32)self->unk_20) == 0) {
        return TRUE;
    }
    if (((VObj *)self->unk_30) == NULL) {
        return FALSE;
    }
    return ((VObj *)self->unk_30)->vfunc_08();
}

}
