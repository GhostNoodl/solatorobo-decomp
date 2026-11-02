#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/SlideWin.h"
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
void ListBuffer021cb940_Release(void *p);

s32 func_ov000_02170100(ListBuffer021cb940 *self) {
    if (self->win == NULL) {
        Message *m = MessageQueue_FindById((MessageQueue *)self->unk_0c, 6);
        return m != NULL ? (s32)(m->unk_0c >> 16) : -1;
    }
    return self->win->mode;
}

}
