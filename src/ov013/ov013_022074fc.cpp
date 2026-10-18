#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be94[];
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);

void func_ov013_022074fc(Ov013Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be94, 0x2ab, 0);
        func_ov000_02191418(self->unk_38, 5, 1);
        FLD(u16, self, 0xb4) = 0;
        self->unk_b6 = 0;
        func_0204a028(data_02097e4c, 0x6a, &self->pos, -3);
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        break;
    case 10:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
            self->unk_b6 = 0x3c;
        }
        break;
    }
}

extern void *data_ov000_021ccd68;
extern char data_ov013_0220be7c[];
extern char data_ov013_0220be9a[];
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 c);
extern void func_0203f364(void *p);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0219b71c(Ov013Vec *pos, Ov013Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov003_021d6a3c(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov013Actor *self, u8 a);

void func_ov013_022075b8(Ov013Actor *self) {
    Ov013Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov013V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x540c, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4811, 10);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4813, 10);
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be94, 0x19a, 0);
        self->unk_50[0] = 0;
        {
            Ov013Sub48 *c = self->unk_48;
            c->unk_9a_0 = 0;
            c->unk_9a_3 = 0;
            func_0203f364(c);
        }
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        func_0204a028(data_02097e4c, 0x6a, &self->pos, -3);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x5800);
            e->v24(0, FLD(s32, self, 0x6c), 0);
        }
        self->unk_40->timer = 0;
        self->unk_40->state = 1;
    }
    case 1:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        self->unk_40->state = 9;
        self->unk_40->timer = 0;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0xccd);
        break;
    case 9:
        st->timer++;
        if (st->timer > 0xb4) {
            func_02049a48(data_02097e4c, 0x53, -1, -1, -1);
            func_ov000_02190cb0(self->unk_38, data_ov013_0220be9a, 0x19a, 0);
            func_ov000_021911c8(self->unk_38, 0xccd);
            self->unk_40->state = 8;
            self->unk_40->timer = 0;
        }
        if (self->unk_40->timer % 20 == 0) {
            Ov013Vec v;
            Ov013Vec r;
            v = self->pos;
            v.y -= FLD(s32, self, 0x68) >> 1;
            r.x = self->unk_64 + (self->unk_64 >> 1);
            r.y = FLD(s32, self, 0x68) >> 2;
            r.z = self->unk_64;
            func_ov000_0219b71c(&v, &r, 0xccd, 0x1666, 0x38b, 0x32);
            func_ov000_0218996c(10, 0xf);
            func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        }
        break;
    case 8:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_0204a028(data_02097e4c, 0x42, &self->pos, -2);
        func_ov000_0218996c(10, 0x3c);
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        break;
    case 10:
        st->timer++;
        if (st->timer > 0x50) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            return;
        }
        func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
}

}
