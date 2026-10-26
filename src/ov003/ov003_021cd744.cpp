#include "types.h"

#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))

class Ov003VObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
};

typedef struct {
    u8 unk_00[0x24];
    s32 unk_24;
    u8 unk_28[0x14];
    Ov003VObj *unk_3c;
    Ov003VObj *unk_40;
    void *unk_44;
    void *unk_48;
    void *unk_4c;
    u8 unk_50[0xc];
    s32 unk_5c;
    u8 unk_60[6];
    u16 unk_66;
    u8 unk_68;
    u8 unk_69;
} Ov003Menu2;

extern "C" {

void *NNS_G2dGetAnimSequenceByIdx(void *a, u16 b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);

static inline void *Ov003_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void Ov003_Model_PlayPart(void *model, u16 idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov003_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 1);
}

static inline void Ov003_Model_PlayPartChk(void *model, u16 idx) {
    void *res;
    void *part;
    void *anim;
    if (FIELD(model, 0x28, void *) == NULL) {
        return;
    }
    res = FIELD(model, 0x28, void *);
    part = Ov003_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 1);
}

void func_ov003_021cd744(Ov003Menu2 *self) {
    u16 i;
    u16 count;
    u16 mask;
    if (self->unk_24 == 0) {
        return;
    }
    self->unk_3c->v20();
    if (self->unk_40 != NULL) {
        self->unk_40->v20();
    }
    Ov003_Model_PlayPart(self->unk_44, (u16)self->unk_5c);
    mask = self->unk_66;
    count = (u32)self->unk_69;
    for (i = 0; i < count; i++) {
        if (i == self->unk_5c) {
            continue;
        }
        if (mask & (1 << i)) {
            Ov003_Model_PlayPartChk(self->unk_48, i);
        } else {
            Ov003_Model_PlayPartChk(self->unk_4c, i);
        }
    }
}

}
