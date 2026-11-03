#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char data_0214b105[];
extern const char *data_0208cca0;
extern const char *data_0208cc94;
extern void *data_ov000_021ccd44;
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb6d0[];
void func_ov000_0216f23c(void *p, s32 a);
BOOL func_ov000_02180900(void *p);
void ListBuffer021cb940_Release(void *p);

typedef struct { u32 lo : 4; } LoNib;

void func_ov000_02172078(MessageQueue021cb980 *self) {
    BOOL r;
    if (!self->unk_04) {
        self->unk_04 = 1;
        self->vfunc_0c(2, 1, 0, 0);
    }
    if (!self->flag0) {
        return;
    }
    r = TRUE;
    if (!ResMgr_IsLoaded(data_0214b105, 7)) {
        r = FALSE;
    }
    if (!ResMgr_IsLoaded(data_0208cca0, 7)) {
        r = FALSE;
    }
    if (!ResMgr_IsLoaded(data_0208cc94, 7)) {
        r = FALSE;
    }
    if (r) {
        self->flag0 = 0;
    }
}

void func_ov000_02172124(VObj *self) {
    u8 buf[0x10];
    self->vfunc_1c();
    while (self->vfunc_14(buf, 1)) {
        self->vfunc_10(buf);
    }
    func_ov000_0216f23c((u8 *)self + 8, 0);
    if (data_ov000_021ccd44 != NULL) {
        func_ov000_02180900(data_ov000_021ccd44);
    }
}

}
