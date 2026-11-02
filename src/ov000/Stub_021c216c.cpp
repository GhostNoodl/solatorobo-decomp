#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"

typedef struct {
    u8 pad_00[8];
    void *unk_08;
    void *unk_0c;
} Obj021c216c;

extern "C" {

void Heap_Free(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);

void func_ov000_021c216c(Obj021c216c *self) {
    void *saved;
    void *p;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    p = self->unk_0c;
    if (p != NULL) {
        if (p != NULL) {
            Model0218fe1c_FreeAnims(p);
            Heap_Free(p);
        }
        self->unk_0c = NULL;
    }
    data_02097dd0->cur = saved;

    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    p = self->unk_08;
    if (p != NULL) {
        if (p != NULL) {
            ResSet_ReleaseAll(p);
            Heap_Free(p);
        }
        self->unk_08 = NULL;
    }
    data_02097dd0->cur = saved;
}

}
