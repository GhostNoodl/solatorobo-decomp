#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efb04_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021efb04;
    func_ov000_02163254(self);
    func_0203de1c(self);
    return self;
}

}
