#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern char data_ov013_0220be82[];
extern void func_ov003_021d36fc(Ov013Actor *self);
extern void func_ov003_021d3d28(Ov013Actor *self);
extern void func_ov003_021d4fd8(Ov013Actor *self);
extern void func_0203f324(Ov013Sub48 *p);
extern void func_ov000_02191318(void *a, s32 b);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 a);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov013_Land(Ov013Actor *self) {
    func_ov000_02190cb0(self->unk_38, data_ov013_0220be82, 0x155, 0);
    func_ov000_02191318(self->unk_38, 0x96000);
    func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
    FLD(u8, self, 0xf0) = 2;
    func_ov000_02198360(self->unk_40, 1, 0);
    self->unk_40->state = 7;
}

void func_ov013_02209674(Ov013Actor *self) {
    Ov013Sub48 *m;
    Ov013Sub44 *n;
    if (self->unk_40->state == 0) {
        FLD(u8, self, 0x110) = 0;
    }
    func_ov003_021d36fc(self);
    if (self->unk_40->unk_13 != 10) {
        return;
    }
    FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
    m = self->unk_48;
    m->unk_9a_0 = 1;
    m->unk_9a_3 = 1;
    func_0203f324(m);
    n = self->unk_44;
    n->unk_22_0 = 1;
    n->unk_22_1 = 1;
    Ov013_Land(self);
}

void func_ov013_0220976c(Ov013Actor *self) {
    Ov013Actor *t;
    func_ov003_021d3d28(self);
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    t = Ov013_FindActor(self->unk_90);
    if (t == NULL) {
        return;
    }
    func_ov000_0218d988(self, t, 0x1000);
    Ov013_Land(self);
}

void func_ov013_02209830(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        if (self->pos.y < 0x4800) {
            self->pos.y = 0x4800;
        }
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
    if (self->pos.y < 0x4800) {
        self->pos.y = 0x4800;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    Ov013_Land(self);
}

void func_ov013_02209908(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        if (self->pos.y < 0x4800) {
            self->pos.y = 0x4800;
        }
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
    if (self->pos.y < 0x4800) {
        self->pos.y = 0x4800;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    Ov013_Land(self);
}

void func_ov013_022099e0(Ov013Actor *self) {
    Ov013Sub48 *m;
    if (self->unk_40->state == 0) {
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        self->rot[0] = 0;
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d5900(self);
    if (self->unk_40->unk_13 == 0x14) {
        return;
    }
    Ov013_Land(self);
}

void func_ov013_02209aac(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        Ov013V *fx;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4811, 10);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4813, 10);
        fx = func_02065f88(0x69, &self->pos);
        if (fx != NULL) {
            fx->v0c(0x3000);
            fx->v24(0, FLD(s32, self, 0x6c), 0);
        }
    }
    func_ov003_021d6054(self);
}

}
