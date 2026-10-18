#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u8 pad_00[0x28];
    s32 unk_28;
    u8 pad_2c[4];
    void *unk_30;
} Sub021bbcac;

typedef struct {
    u8 pad_00[0x118];
    Sub021bbcac *unk_118;
} Game021bbcac;

typedef struct {
    s32 unk_00;
    u8 unk_04[0x4c];
    s32 unk_50;
    u16 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    s32 unk_70;
    u8 unk_74;
    u8 unk_75;
    u8 unk_76;
} Obj021bbc68;

extern "C" {

extern Game021bbcac *data_ov000_021ccd30;
void func_ov000_02165d78(void *p);

void func_ov000_021bbc68(Obj021bbc68 *self, u8 a, u8 b, u8 c) {
    self->unk_00 = 0;
    self->unk_50 = 1;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0;
    self->unk_68 = 0;
    self->unk_6c = 0;
    self->unk_70 = 0;
    self->unk_74 = a;
    self->unk_75 = b;
    self->unk_76 = c;
}

static inline void *GetSub021bbcac(void) {
    Sub021bbcac *q = data_ov000_021ccd30->unk_118;
    if (q == NULL) {
        return NULL;
    }
    if (q->unk_28 != 1) {
        return NULL;
    }
    return q->unk_30;
}

void func_ov000_021bbcac(Obj021bbc68 *self) {
    void *p = GetSub021bbcac();
    if (p != NULL) {
        func_ov000_02165d78(p);
    }
    VOBJ_AT(self, 0x4)->vfunc_0c();
    HEAP_DELETE_MODEL(self->unk_58);
    HEAP_DELETE_VOBJ(self->unk_5c);
}

}
