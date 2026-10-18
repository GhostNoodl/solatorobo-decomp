#include "ov012/ov012.h"

extern "C" {
extern const u8 data_ov012_0220b406[];
void func_ov012_02209f80(Ov012Actor *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220b406, 0x400, 0);
        self->unk_9c = 0x59a;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0x700, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 0x2d || VEC_Distance(&self->pos, &self->unk_b8) < 0x1800) {
            self->unk_a4 = 0xc00;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        {
            Ov012Vec v;
            v.x = self->unk_b8.x;
            v.y = self->unk_b8.y;
            v.z = self->unk_b8.z;
            func_ov000_0218ddd4(self, &v, 0);
        }
        break;
    case 2:
        s->timer++;
        if (s->timer > 0x3c) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        func_ov000_0218dbe0(self, 0);
        break;
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), 0x400);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}
}

extern "C" {
void func_ov012_0220a0f4(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012Actor *o = Ov012_FindActor(FLD(u16, FLD(void *, self, 0xd0), 0x62));
        if (o != NULL) {
            void *p;
            func_ov000_0218d46c(o, self->id, 10);
            p = FLD(void *, o, 0x4c);
            if (p != NULL) {
                FLD(Ov012Flags8, p, 0x18).b0 = 0;
            }
            FLD(u16, FLD(void *, self, 0xd0), 0x62) = 0xffff;
        }
        if (*self->unk_50 == 0) {
            func_02049f44(data_02097e4c, 0x704, &self->pos, 0);
        }
    }
    func_ov003_021d5900(self);
}
}

extern "C" {
void func_ov012_0220a1ac(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4009, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4801, 0x15);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x2400);
            e->v24(0, FLD(s32, self, 0x6c), 0);
        }
    }
    func_ov003_021d6054(self);
}
}

extern "C" {
void func_ov012_0220a244(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012Actor *o = Ov012_FindActor(FLD(u16, FLD(void *, self, 0xd0), 0x62));
        if (o != NULL) {
            void *p;
            func_ov000_0218d46c(o, self->id, 10);
            p = FLD(void *, o, 0x4c);
            if (p != NULL) {
                FLD(Ov012Flags8, p, 0x18).b0 = 0;
            }
            FLD(u16, FLD(void *, self, 0xd0), 0x62) = 0xffff;
        }
        func_02049f44(data_02097e4c, 0x703, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
}
}

extern "C" {
void func_ov012_0220a2ec(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012Actor *o = Ov012_FindActor(FLD(u16, FLD(void *, self, 0xd0), 0x62));
        if (o != NULL) {
            void *p;
            func_ov000_0218d46c(o, self->id, 10);
            p = FLD(void *, o, 0x4c);
            if (p != NULL) {
                FLD(Ov012Flags8, p, 0x18).b0 = 0;
            }
            FLD(u16, FLD(void *, self, 0xd0), 0x62) = 0xffff;
        }
        func_02049f44(data_02097e4c, 0x704, &self->pos, 0);
    }
    func_ov003_021d5348(self);
}
}

extern "C" {
void *func_ov012_0220a394(void *self) {
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
void *func_ov012_0220a3a8(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}
