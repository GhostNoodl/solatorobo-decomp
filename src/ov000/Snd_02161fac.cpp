#include "types.h"
#include "ov000/ModelViewer.h"

extern "C" {

void func_ov000_0218ec60(ActorRes *t, void *a, void *b, s32 c, s32 d);
void func_ov000_0218edf0(ActorRes *t, void *a, void *b, s32 c, s32 d);
BOOL func_ov000_0218f110(ActorRes *t);
BOOL func_0203e688(void);

void func_ov000_02161fac(ModelViewerRes *self) {
    u8 idx;
    switch (self->state) {
    case 0:
        idx = (self->cur & 1) ^ 1;
        func_ov000_0218ec60(&self->a[idx], self->mdlArc, self->mdlName, 1, 0);
        func_ov000_0218edf0(&self->a[idx], self->anmArc, self->anmName, 1, 0);
        if (self->useMdlForB != 0) {
            func_ov000_0218edf0(&self->b[idx], self->mdlArc, self->mdlName, 1, 0);
        } else {
            func_ov000_0218edf0(&self->b[idx], NULL, NULL, 1, 0);
            self->b[idx].unk_00 = 0;
        }
        self->reload = 0;
        self->state = 10;
        break;
    case 10:
        idx = (self->cur & 1) ^ 1;
        func_ov000_0218f110(&self->a[idx]);
        func_ov000_0218f110(&self->b[idx]);
        if (self->a[idx].unk_00 < 0 && self->b[idx].unk_00 < 0) {
            if (func_0203e688()) {
                if (self->reload != 0) {
                    self->state = 0;
                } else {
                    self->state = 20;
                }
            }
        }
        break;
    case 20:
        if (self->reload != 0) {
            self->state = 0;
        }
        break;
    }
}

}
