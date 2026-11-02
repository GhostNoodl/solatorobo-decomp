#include "types.h"

class Ov003VObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u32 unk_00;
    u64 flags;
} Ov003ActorState;

typedef struct {
    u8 unk_00[0x40];
    Ov003ActorState *state;
    u8 unk_44[0x2c];
    Ov003Vec pos;
    u8 unk_7c[8];
    Ov003Vec lastPos;
} Ov003Actor;

typedef struct {
    u8 unk_00[0x18];
    s16 mode;
    s16 unk_1a;
} Ov003Obj;

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov000_02197d80(void *self);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void func_ov000_02194758(void *self);
extern void func_0203de1c(void *p);
extern void *func_ov000_0219429c(void *p);

void Ov003ActVt_021f9d78_Start(Ov003Obj *self) {
    BOOL keep;
    s16 sub;
    s16 mode;
    func_ov000_02197d80(self);
    sub = self->unk_1a;
    mode = self->mode;
    keep = TRUE;
    if (sub == 0) {
        if (mode == 1 || mode == 3 || (u16)(s16)(mode - 5) <= 1) {
            keep = FALSE;
        }
    } else {
        if (mode == 2 || (u16)(s16)(mode - 4) <= 2) {
            keep = FALSE;
        }
    }
    if (!keep) {
        func_ov000_0218bed8(data_ov000_021ccd64, 2, self);
        ((Ov003VObj *)self)->Release();
        return;
    }
    func_ov000_02194758(self);
}

void *Ov003ActVt_021f9f40_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9f40_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov003ActVt_021f9ea8_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9ea8_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov003ActVt_021f9ce0_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9ce0_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov003ActVt_021f9d78_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9d78_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void Ov003ActVt_021fa07c_Start(Ov003Actor *self) {
    func_ov000_02194758(self);
    self->state->flags |= 0x100000000ULL;
    self->lastPos.x = self->pos.x;
    self->lastPos.y = self->pos.y;
    self->lastPos.z = self->pos.z;
}

}
