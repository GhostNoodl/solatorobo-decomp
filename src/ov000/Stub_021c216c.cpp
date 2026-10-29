#include "ov000/VObj.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct {
    u8 pad_00[8];
    void *unk_08;
    void *unk_0c;
} Obj021c216c;

extern "C" {

extern HeapState *data_02097dd0;
void func_0203de1c(void *p);
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);

void func_ov000_021c216c(Obj021c216c *self) {
    void *saved;
    void *p;

    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    p = self->unk_0c;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218fee4(p);
            func_0203de1c(p);
        }
        self->unk_0c = NULL;
    }
    data_02097dd0->current = saved;

    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    p = self->unk_08;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218ea20(p);
            func_0203de1c(p);
        }
        self->unk_08 = NULL;
    }
    data_02097dd0->current = saved;
}

}
