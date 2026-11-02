#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"

extern "C" {

void Heap_Free(void *ptr);

static inline void Obj0214e014_Delete(Model *obj) {
    if (obj != NULL) {
        func_02041558(obj);
        func_02041278(&obj->pltt);
        Heap_Free(obj);
    }
}

void func_ov000_0214e008(void *self) {
    *(s32 *)((u8 *)self + 0xe0) = 0x0;
}

void func_ov000_0214e014(void *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*(u8 **)((u8 *)self + 0xe0) != NULL) {
        Obj0214e014_Delete(*(Model **)((u8 *)self + 0xe0));
        *(u8 **)((u8 *)self + 0xe0) = NULL;
    }
    data_02097dd0->cur = saved;
}

}
