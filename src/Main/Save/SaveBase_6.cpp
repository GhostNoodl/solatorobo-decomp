#include "Main/Save/SaveBase.h"

extern "C" {

void *func_02048b8c(SaveBase *s) {
    *(u32 **)s = data_0208b614;
    s->Finalize();
    func_0203de1c(s);
    return s;
}

void *func_02048bbc(SaveBase *s) {
    *(u32 **)s = data_0208b614;
    s->Finalize();
    return s;
}

}
