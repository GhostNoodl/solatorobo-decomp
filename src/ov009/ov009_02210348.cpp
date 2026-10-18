#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern u8 data_ov009_022179a8[];
extern u8 data_ov009_022179b4[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern void func_ov000_021911c8(void *m, s32 a);
extern BOOL func_ov000_02191120(void *m);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
static inline Ov009Actor *Ov009_FindActor5(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_02210348(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec q;
    Ov009Actor *t = func_ov000_0218d240(self);
    Ov009Actor *h;
    if (t == NULL) {
        return;
    }
    Ov009_FindActor5(FLD(u16, self, 0xde));
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179a8, 0x2ab, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 1: {
        Ov009Sub44 *s44;
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer != 0x16) {
            return;
        }
        self->unk_a0 = 0x8cd;
        self->unk_a8 = 0x3e;
        func_02049a48(data_02097e4c, 0x42, -1, -1, -1);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->state++;
        return;
    }
    case 2: {
        Ov009Sub44 *s44;
        func_ov000_0218dbe0(self, 0);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            func_ov000_021911c8(self->unk_38, 0x200);
        }
        if (self->unk_a0 < 0) {
            self->unk_a8 = 0x52;
        }
        if (FLD(s32, self, 0xf0) < self->pos.y) {
            return;
        }
        if (self->unk_a0 >= 0) {
            return;
        }
        func_02065f88(0x66, &self->pos)->v14(0x2000, 0x2000, 0x2000);
        func_ov000_0218996c(0x12, 0x3c);
        func_02049a48(data_02097e4c, 0x17, -1, -1, -1);
        p.x = t->pos.x;
        p.y = t->pos.y;
        p.z = t->pos.z;
        p.y += FLD(s32, self, 0x68) + 0x1000;
        h = func_ov003_021d69f0(self, 0x482f, &p, self->rot, t);
        h->unk_9c = 0;
        h->unk_a0 = -0x19a;
        h->unk_a4 = 0;
        h->unk_a8 = 0x52;
        func_ov000_0218d46c(h, self->id, 4);
        h->unk_90 = self->unk_90;
        func_ov000_021911c8(self->unk_38, 0x1400);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    }
    case 3:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        q.x = t->pos.x;
        q.y = t->pos.y;
        q.z = t->pos.z;
        q.y += FLD(s32, self, 0x68) + 0x1000;
        h = func_ov003_021d69f0(self, 0x482f, &q, self->rot, t);
        h->unk_9c = 0;
        h->unk_a0 = -0x19a;
        h->unk_a4 = 0;
        h->unk_a8 = 0x52;
        func_ov000_0218d46c(h, self->id, 4);
        h->unk_90 = self->unk_90;
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 4: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
    }
    }
}

}
