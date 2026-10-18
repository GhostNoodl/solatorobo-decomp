#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd30;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d398(Ov009Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void func_0203f9dc(void *mesh, const void *mtx);
extern void func_ov003_021d3008(Ov009Actor *self);
extern u16 FX_Atan2(s32 y, s32 x);
struct Ov009AngSrc2 {
    u8 unk_00[4];
    s32 x;
    u8 unk_08[4];
    s32 z;
    u8 unk_10[0x30];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern s32 func_0204bfa8(Ov009AngSrc2 *p);
extern void func_ov000_0216912c(void *o, u16 id, s32 a, u16 b, u16 c, const Ov009Vec *pos);

struct Ov009EaBits {
    u16 b0 : 13;
    u16 b13 : 1;
    u16 b14 : 2;
};

struct Ov009Notifier {
    u8 unk_00[0x60];
    void *unk_60;
};

static inline s32 Ov009_GetAng2(Ov009AngSrc2 *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return func_0204bfa8(p);
}

static inline void Ov009_Notify(u16 id, u16 b, u16 c, const Ov009Vec *pos) {
    Ov009Notifier *o = FLD(Ov009Notifier *, data_ov000_021ccd30, 0x11c);
    void *q;
    if (o != NULL && (q = o->unk_60) != NULL) {
        func_ov000_0216912c(q, id, 0, b, c, pos);
    }
}

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov009Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

struct Ov009PosMsg {
    Ov009Vec pos;
    u16 rot[3];
    u32 unk_14;
};

extern void func_0203f8d8(void *mesh);
extern void func_0203f920(void *mesh);

struct Ov009Bit84 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_02212d78(Ov009Actor *self) {
    Ov009PosMsg msg;
    Ov009Actor *a;
    if (FLD(Ov009EaBits, self, 0xea).b13) {
        Ov009AngSrc2 *p = (Ov009AngSrc2 *)((u8 *)data_ov000_021ccd54 + 0xf4);
        s32 px = p->x;
        s32 pz = p->z;
        s32 ang = Ov009_GetAng2(p);
        if ((u16)(FX_Atan2(FLD(s32, self, 0x11c) - px, FLD(s32, self, 0x124) - pz) - ang + 0x4000) <= 0x8000 &&
            self->unk_ea_6 != 1) {
            self->unk_ea_6 = 1;
            Ov009_Notify(self->id, self->unk_50[0], self->unk_50[1], &FLD(Ov009Vec, self, 0x11c));
        }
    }
    func_ov003_021d3008(self);
    if (FLD(void *, self, 0x58) != NULL) {
        func_0203f9dc(FLD(void *, self, 0x58), &FLD(u8, self, 0xf8));
        if (self->unk_93_4) {
            if (FLD(Ov009Bit84, FLD(void *, self, 0x58), 0x84).b0 != 1) {
                func_0203f8d8(FLD(void *, self, 0x58));
            }
        } else {
            if (FLD(Ov009Bit84, FLD(void *, self, 0x58), 0x84).b0) {
                func_0203f920(FLD(void *, self, 0x58));
            }
        }
    }
    a = Ov009_FindActor(FLD(u16, self, 0xf0));
    if (a == NULL) {
        return;
    }
    msg.pos = FLD(Ov009Vec, self, 0x11c);
    {
        u16 x = a->rot[0];
        u16 y = a->rot[1];
        u16 z = a->rot[2];
        msg.rot[0] = x;
        msg.rot[1] = y;
        msg.rot[2] = z;
    }
    func_ov000_0218d398(a, self->id, 7, TRUE, 0x18, &msg);
}

}
