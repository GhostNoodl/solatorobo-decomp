#include "ov000/LoCommon.h"
#include "ov000/LoTicker.h"

extern "C" {

// Destructor of LoTextHolder (the __cxa_vec_ctor / __cxa_vec_cleanup element dtor of LoTicker::res).
LoTextHolder *func_ov000_0217006c(LoTextHolder *self) {
    HEAP_DELETE(TextWin *, self->win, p->unk_vf04());
    return self;
}

}
