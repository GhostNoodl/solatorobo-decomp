#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "ov000/Obj0216c954.h"

extern "C" {

void Heap_Free(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);

void func_ov000_021c216c(Obj021c2114 *self) {
    void *saved;
    void *p;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    p = self->model;
    if (p != NULL) {
        if (p != NULL) {
            Model0218fe1c_FreeAnims(p);
            Heap_Free(p);
        }
        self->model = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    p = self->res;
    if (p != NULL) {
        if (p != NULL) {
            ResSet_ReleaseAll(p);
            Heap_Free(p);
        }
        self->res = NULL;
    }
    data_02097dd0->cur = saved;
}

}
