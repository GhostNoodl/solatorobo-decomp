#include "ov013/ov013.h"

extern "C" {

extern void *data_0214a420;
extern void *data_02097cdc;
extern char data_ov013_0220b860[];
extern void *data_ov013_0220b7d0[];
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021d6a3c(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void *func_020657b0(void *a, s32 b);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_02036838(void *a, void *b, s32 c, s32 d);
extern void func_020359d0(void *a, s32 b, s32 c);
extern void func_ov000_0219433c(void *self);
extern BOOL func_ov000_021946f8(void *self);
extern void func_ov000_02194758(void *self);
extern Ov013Actor *func_ov000_0219bf90(void);

void func_ov013_021fd258(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        func_02065804(data_0214a420, FLD(s32, self, 0xf4));
    }
    if (self->unk_40->unk_0c[0] == 2) {
        func_ov003_021d6a3c(self, 1, 1, 1);
        return;
    }
    func_ov003_021d6054(self);
}

void func_ov013_021fd2b8(Ov013Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov013_021fd2d8(Ov013Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}

void func_ov013_021fd2f8(void) {
}

void func_ov013_021fd2fc(void) {
}

void func_ov013_021fd300(void) {
}

void func_ov013_021fd304(void) {
}

void func_ov013_021fd308(void) {
}

void func_ov013_021fd30c(void) {
}

void func_ov013_021fd310(void) {
}

void func_ov013_021fd314(void) {
}

void func_ov013_021fd318(Ov013Actor *self) {
    self->v54();
}

void func_ov013_021fd32c(Ov013Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}

void func_ov013_021fd34c(Ov013Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}

void func_ov013_021fd370(Ov013Actor *self) {
    self->unk_ee_2 = 1;
    self->v64();
}

Ov013Actor *func_ov013_021fd394(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_021fd3a8(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_021fd3c4(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_021fd3d8(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

static inline void Ov013_StopHtr(Ov013Actor *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        void *p = func_020657b0(data_0214a420, FLD(s32, (u8 *)self + i * 4, 0xd0));
        if (p != NULL) {
            FLD(s32, p, 0x1c) = 4;
        }
    }
    if (func_02035b90(data_ov013_0220b860, 7)) {
        func_02036838(data_02097cdc, data_ov013_0220b860, 7, 0);
    }
}

Ov013Actor *func_ov013_021fd3f4(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220b7d0;
    Ov013_StopHtr(self);
    func_ov000_0219429c(self);
    return self;
}

Ov013Actor *func_ov013_021fd488(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220b7d0;
    Ov013_StopHtr(self);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov013_021fd524(Ov013Actor *self) {
    func_ov000_0219433c(self);
    func_020359d0(data_ov013_0220b860, 7, 0);
}

BOOL func_ov013_021fd544(Ov013Actor *self) {
    BOOL r = func_ov000_021946f8(self);
    return (r & func_02035b90(data_ov013_0220b860, 7)) ? TRUE : FALSE;
}

void func_ov013_021fd570(Ov013Actor *self) {
    Ov013Actor *p;
    s32 i;
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0xb, 0);
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    for (i = 0; i < 2; i++) {
        FLD(s32, (u8 *)self + i * 4, 0xd0) = -1;
    }
    FLD(u16, self, 0xce) = 0x96;
    FLD(s32, self, 0xd8) = 0xccd;
    if (self->unk_9c == 0) {
        self->unk_9c = 0x19a;
    }
    if (self->unk_a0 == 0) {
        self->unk_a0 = -0xcd;
    }
}

}
