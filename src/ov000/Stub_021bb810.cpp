#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    s32 unk_0c;
    VObj *unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
} Obj021bb810;

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

extern "C" {

extern HeapState *data_02097dd0;
extern void *data_0214a420;
BOOL func_02065748(void *p, VObj *obj);

static inline void Obj021bb810_Init(Obj021bb810 *self, s32 a) {
    self->unk_00 = 1;
    self->unk_04 = a;
    self->unk_08 = 1;
    self->unk_0c = -1;
    self->unk_10 = NULL;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

void func_ov000_021bb810(Obj021bb810 *self, s32 a) {
    self->unk_00 = 1;
    self->unk_04 = a;
    self->unk_08 = 1;
    self->unk_0c = -1;
    self->unk_10 = NULL;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
}

void func_ov000_021bb840(Obj021bb810 *self) {
    if (func_02065748(data_0214a420, self->unk_10)) {
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (self->unk_10 != NULL) {
            if (self->unk_10 != NULL) {
                self->unk_10->vfunc_04();
            }
            self->unk_10 = NULL;
        }
        data_02097dd0->current = saved;
    }
    Obj021bb810_Init(self, 0);
}

}
