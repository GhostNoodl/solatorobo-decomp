#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x18];
    s32 unk_18;
    s32 unk_1c;
    u8 unk_20[0x10];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    void *unk_40;
    s32 unk_44;
    u8 unk_48[0x4];
    u16 unk_4c;
    u16 unk_4e;
    u8 unk_50;
    u8 unk_51;
    u8 unk_52;
    u8 unk_53;
    u8 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
} Obj021c2f10;

extern "C" {

extern u8 data_ov000_021cc9bc[];
extern u8 data_ov000_021cc9d3[];
extern u8 data_ov000_021cc9dc[];
void func_02035acc(void *a, void *b, s32 c);
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

void func_ov000_021c2f10(Obj021c2f10 *self) {
    self->unk_1c = 0xc8;
    self->unk_18 = 0x8c;
    self->unk_30 = 0;
    self->unk_34 = 0;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = data_ov000_021cc9bc;
    self->unk_44 = 0;
    self->unk_4c = 0;
    self->unk_4e = 0;
    self->unk_50 = 0;
    self->unk_51 = 0;
    self->unk_52 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0x99a;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0;
    self->unk_68 = 0;
    self->unk_6c = 0;
    self->unk_70 = 0;
    self->unk_74 = 0;
    self->unk_78 = 0;
}

void func_ov000_021c2f90(Obj021c2f10 *self) {
    HEAP_DELETE_MODEL(self->unk_38);
    HEAP_DELETE_MODEL(self->unk_3c);
    if (self->unk_68 != 0) {
        func_02035acc((void *)self->unk_30, (void *)self->unk_34, 2);
        func_02035acc(data_ov000_021cc9d3, data_ov000_021cc9dc, 2);
    }
    self->unk_6c = 0;
    self->unk_54 = 0;
    self->unk_58 = 0x99a;
}

}
