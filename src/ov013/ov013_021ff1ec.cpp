#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

struct Ov013Pair {
    u8 a;
    u8 b;
};

extern "C" {

extern BOOL func_ov003_021da03c(Ov013Actor *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov013Pair func_ov003_021d9644(void *p);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov013Actor *self, s32 a);
extern void func_ov003_021d6548(Ov013Actor *self, void *p);
extern void func_ov003_021d68e0(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(Ov013Actor *self, Ov013Msg *msg);

void func_ov013_021ff1ec(void) {
}

void func_ov013_021ff1f0(Ov013Actor *self) {
    Ov013Pair p;
    if (!func_ov003_021da03c(self)) {
        return;
    }
    self->unk_93_4 = 1;
    self->unk_c4 = 0;
    FLD(Ov013Flags8, self, 0xf0).b0 = 0;
    func_ov003_021d8fc0((u8 *)self + 0x14c);
    if (!func_ov003_021d9878((u8 *)self + 0x14c)) {
        return;
    }
    p = func_ov003_021d9644((u8 *)self + 0x14c);
    FLD(u8, self, 0x15c) = p.a;
    FLD(u8, self, 0x15d) = p.b;
    func_ov000_02198360(self->unk_40, p.a, 1);
}

void func_ov013_021ff288(Ov013Actor *self) {
    func_ov003_021da40c(self->unk_40);
    func_ov000_0218d7e8(self, self->unk_40->unk_13);
}

static inline void Ov013_Ack(Ov013Actor *self, Ov013Msg *msg) {
    self->unk_30 |= 1 << msg->type;
    msg->type = 0;
}

static inline BOOL Ov013_Ignore(Ov013Actor *self, Ov013Msg *msg) {
    if (FLD(Ov013Flags8, self, 0xf0).b0 && msg->type == 9) {
        Ov013_Ack(self, msg);
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Ov013_IsInvul(u16 *hp) {
    return hp[5] != 0;
}

static inline BOOL Ov013_IsBusy(u8 s) {
    BOOL r = FALSE;
    switch (s) {
    case 2:
    case 0xf:
    case 0x15:
    case 0x20:
    case 0x29:
    case 0x2a:
        r = TRUE;
        break;
    }
    return r;
}

static inline BOOL Ov013_CanFlinch(Ov013Actor *self, Ov013Msg *msg) {
    BOOL r = FALSE;
    if (msg->type == 9) {
        if (!Ov013_IsBusy(self->unk_40->unk_13)) {
            r = TRUE;
        }
    }
    return r;
}

BOOL func_ov013_021ff2ac(Ov013Actor *self, Ov013Msg *msg) {
    if (FLD(Ov013Flags8, self, 0xf0).b0 && msg->type == 9) {
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    if (msg->type == 9) {
        if (!Ov013_IsInvul(self->unk_50) && self->unk_40->unk_13 != 0x20) {
            self->unk_50[2] = FLD(u16, msg, 6);
            func_ov003_021d6548(self, (u8 *)msg + 8);
            func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
            self->unk_50[5] = 5;
            func_ov000_02191418(self->unk_38, 5, 0);
            if (self->unk_50[0] == 0) {
                self->unk_40->flags |= 0x200000;
            } else if (Ov013_CanFlinch(self, msg)) {
                func_ov000_02198360(self->unk_40, 0x12, 1);
            }
        }
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

}
