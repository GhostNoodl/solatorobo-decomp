#include "ov000/VObj.h"

typedef struct Obj021c22d8 {
    u8 unk_00[4];
    s32 unk_04;
    u8 unk_08[4];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    u8 unk_20;
    s32 unk_24;
    struct Obj021c22d8 *unk_28;
    struct Obj021c22d8 *unk_2c;
} Obj021c22d8;

typedef struct {
    u8 unk_00[0x18];
    s32 unk_18;
    u8 unk_1c[0x14];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    void *unk_40;
    u8 unk_44;
} Obj021c2334;

extern "C" {

extern u8 data_ov000_021cc9bc[];
typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

extern HeapState *data_02097dd0;
void func_0203de1c(void *p);
void func_02041558(void *m);
void func_02041278(void *p);

#define HEAP_DELETE_MODEL(field)                          \
    {                                                     \
        void *saved = data_02097dd0->current;             \
        void *p;                                          \
        data_02097dd0->current = data_02097dd0->unk_08;   \
        p = (void *)(field);                              \
        if (p != NULL) {                                  \
            if (p != NULL) {                              \
                func_02041558(p);                         \
                func_02041278((u8 *)p + 0x88);            \
                func_0203de1c(p);                         \
            }                                             \
            (field) = 0;                                  \
        }                                                 \
        data_02097dd0->current = saved;                   \
    }

void func_ov000_021c22d8(Obj021c22d8 *self) {
    self->unk_04 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_1c = 0xa0;
    self->unk_18 = 0xc;
    self->unk_28 = NULL;
    self->unk_2c = NULL;
    self->unk_20 = 0;
    self->unk_24 = 0;
}

void func_ov000_021c2310(Obj021c22d8 *self) {
    if (self->unk_2c != NULL) {
        self->unk_2c->unk_28 = self->unk_28;
    }
    if (self->unk_28 != NULL) {
        self->unk_28->unk_2c = self->unk_2c;
    }
}

void func_ov000_021c2334(Obj021c2334 *self) {
    self->unk_18 = 0xf;
    self->unk_30 = 0;
    self->unk_34 = 0;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = data_ov000_021cc9bc;
    self->unk_44 = 0;
}

void func_ov000_021c2364(Obj021c2334 *self) {
    HEAP_DELETE_MODEL(self->unk_30);
    HEAP_DELETE_MODEL(self->unk_34);
    {
        void *saved = data_02097dd0->current;
        VObj *p;
        data_02097dd0->current = data_02097dd0->unk_08;
        p = (VObj *)self->unk_38;
        if (p != NULL) {
            if (p != NULL) {
                p->vfunc_04();
            }
            self->unk_38 = 0;
        }
        data_02097dd0->current = saved;
    }
}

}
