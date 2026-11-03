#include "ov002/ov002.h"

extern "C" {

Obj021efef0 *Ov002Vt_021efef0_Ctor(Obj021efef0 *self) {
    *(VFunc **)self = Ov002Vt_021efef0_vtbl;
    Obj021efef0_Init(self);
    return self;
}

}
