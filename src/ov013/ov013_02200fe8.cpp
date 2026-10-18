#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern const Ov013Vec data_ov013_0220af34;
extern u8 data_ov013_0220b090[];
extern u8 data_ov013_0220b0cc[];
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void func_02012be8(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov013_02203494(Ov013Actor *self, BOOL a, BOOL b, s32 c, void *d);
extern void func_ov003_021d64f0(Ov013Actor *self);

static inline Ov013V *Ov013_SpawnFx(s32 id, const Ov013Vec &pos) {
    return func_02065f88(id, (Ov013Vec *)&pos);
}

static inline Ov013Vec Ov013_FrontPos(Ov013Actor *self, const Ov013Vec *off) {
    Ov013Vec v;
    func_ov003_021d9980(&v, self->rot[1], off);
    func_02012be8(&v, &self->pos, &v);
    return v;
}

void func_ov013_02200fe8(Ov013Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov000_02191418(self->unk_38, 0x28, 1);
    Ov013_SpawnFx(0x196, Ov013_FrontPos(self, &data_ov013_0220af34))->v0c(0x2000);
    func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
    func_02049f44(data_02097e4c, 0x36, &self->pos, 0);
    self->unk_40->state++;
}

void func_ov013_022010b8(Ov013Actor *self) {
    s32 c = 0;
    BOOL a = TRUE;
    BOOL b = TRUE;
    void *d = NULL;
    switch (FLD(u8, self, 0x15d)) {
    case 1:
        d = data_ov013_0220b090;
        break;
    case 2:
        b = FALSE;
        d = data_ov013_0220b090;
        break;
    case 3:
        a = FALSE;
        d = data_ov013_0220b090;
        break;
    case 4:
        b = FALSE;
        c = 0xd00;
        d = data_ov013_0220b0cc;
        break;
    case 5:
        a = FALSE;
        c = 0xd00;
        d = data_ov013_0220b0cc;
        break;
    case 6:
        d = data_ov013_0220b0cc;
        c = 0xd00;
        break;
    }
    func_ov013_02203494(self, a, b, c, d);
}

void func_ov013_02201144(Ov013Actor *self) {
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_18) {
    case 0:
        func_ov003_021d64f0(self);
        break;
    case 1: {
        Ov013Sub40 *s = self->unk_40;
        if (s->state == 0) {
            self->pos.x = -0x212b;
            self->pos.y = 0x2000;
            self->pos.z = -0xb3a2;
            self->rot[1] = 0;
            s->state++;
        } else {
            s->timer++;
            if (self->unk_40->timer > 0x1e) {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
    }
}

}
