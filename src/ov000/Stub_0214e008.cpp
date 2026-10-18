#include "ov000/VObj.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

extern "C" {

extern HeapState *data_02097dd0;
void func_02041558(void *obj);
void func_02041278(void *obj);
void func_0203de1c(void *ptr);

static inline void Obj0214e014_Delete(u8 *obj) {
    if (obj != NULL) {
        func_02041558(obj);
        func_02041278(obj + 0x88);
        func_0203de1c(obj);
    }
}

void func_ov000_0214e008(void *self) {
    *(s32 *)((u8 *)self + 0xe0) = 0x0;
}

void func_ov000_0214e014(void *self) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (*(u8 **)((u8 *)self + 0xe0) != NULL) {
        Obj0214e014_Delete(*(u8 **)((u8 *)self + 0xe0));
        *(u8 **)((u8 *)self + 0xe0) = NULL;
    }
    data_02097dd0->current = saved;
}

}
