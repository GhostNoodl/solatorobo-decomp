#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003FxVec;

class Ov003FxObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetFrame(s32 frame);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(void *rot);
    u8 unk_04[0x20];
    u32 unk_24;
};

typedef struct {
    u8 unk_00[0x14];
    s16 effect;
    s16 frame;
    u8 unk_18[0x10];
} Ov003FxEntry;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
} Ov003FxUnit;

typedef struct {
    void *vtbl;
    u8 unk_04[0x16];
    s16 unk_1a;
    u16 unk_1c;
    u16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x4e];
    Ov003FxVec pos;
    u8 unk_7c[0x40];
    u32 unk_bc;
    u8 unk_c0[0x10];
    Ov003FxVec basePos;
    u16 unk_dc;
} Ov003FxProp;

extern "C" {

extern void *data_ov000_021ccd64;
extern const Ov003FxEntry data_ov003_021f6fc8[];
extern void func_ov000_02194758(void *self);
extern Ov003FxUnit *func_ov000_0218bd5c(void *mgr, u16 id);
extern Ov003FxObj *func_02065f88(s32 id, Ov003FxVec *pos);

void func_ov003_021f01a4(Ov003FxProp *self) {
    Ov003FxUnit *u;
    const Ov003FxEntry *e;
    Ov003FxObj *fx;
    func_ov000_02194758(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
    self->basePos = self->pos;
    self->unk_dc = 1;
    e = &data_ov003_021f6fc8[self->unk_1a];
    if (e->effect == -1) {
        return;
    }
    fx = func_02065f88(e->effect, &self->pos);
    if (fx == NULL) {
        return;
    }
    self->unk_bc = fx->unk_24;
    fx->SetRot(self->unk_7c);
    fx->SetFrame(e->frame);
}

}
