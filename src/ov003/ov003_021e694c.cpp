#include "ov003/GmObj.h"

extern "C" {

extern BOOL func_ov000_02194c08(void *self);

BOOL func_ov003_021e694c(Ov003Obj *self) {
    BOOL r = FALSE;
    if (self->model->unk_be != 0) {
        r = func_ov000_02194c08(self);
    }
    return r;
}

}
