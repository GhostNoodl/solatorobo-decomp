#include "ov000/LoCommon.h"
#include "ov000/LoTicker.h"

extern "C" {

// Destructor of LoTextHolder (the __cxa_vec_ctor / __cxa_vec_cleanup element dtor of LoTicker::res).
LoTextHolder *LoTextHolder_Dtor(LoTextHolder *self) {
    HEAP_DELETE(TextWin *, self->win, p->unk_vf04());
    return self;
}

}
