#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern u8 data_ov009_022179a8[];
extern u8 data_ov009_022179b4[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_02191708(void *p);
extern void func_ov000_02191690(void *p);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0219aae8(Ov009Actor *self, Ov009Actor *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_0218996c(s32 a, s32 b);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov009Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

static inline void Ov009_Sub(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

void func_ov009_0220fea4(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec d;
    Ov009Actor *t;
    Ov009Actor *o;
    Ov009Sub40 *st;
    Ov009Sub44 *s;
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    o = Ov009_FindActor(FLD(u16, self, 0xde));
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179a8, 0x200, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer == 0x13) {
            func_ov000_02191708(self->unk_38);
            self->unk_a0 = 0x8cd;
            self->unk_a8 = 0x29;
            func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            self->unk_40->state++;
        }
        break;
    case 2:
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += FLD(s32, self, 0x68) + 0x1000;
            o = func_ov003_021d69f0(self, 0x482f, &p, self->rot, t);
            o->unk_9c = 0;
            o->unk_a0 = 0;
            o->unk_a4 = 0;
            func_ov000_0218d46c(o, self->id, 9);
            { s32 tx = t->pos.x; s32 ty = t->pos.y; s32 tz = t->pos.z; d.x = tx - self->pos.x; d.y = ty - self->pos.y; d.z = tz - self->pos.z; }
            d.y = 0;
            VEC_MultAdd(0xe66, &d, &self->pos, &self->pos);
            func_ov000_0218d988(self, t, 0x1000);
            self->unk_38->unk_c2_0 = 0;
            func_ov000_02191690(self->unk_38);
        }
        if (self->unk_a0 < 0) {
            self->unk_a8 = 0x7b;
            self->unk_38->unk_c2_0 = true;
        }
        if (self->unk_48->unk_50 & 0x20000000) {
            func_02065f88(0x66, &self->pos)->v14(0x1c00, 0x1c00, 0x1c00);
            if (t != NULL) {
                func_ov000_0219aae8(self, self, 0x1e, 0x20, (u16)(1 << (t->id >> 12)), 0, 0, 0x3400, 0x2800, 0x64, 0x1000);
            }
            func_ov000_0218996c(0xf, 0x1e);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            self->unk_40->state++;
            self->unk_40->timer = 0;
            self->unk_48->unk_9a_5 = 1;
            s = self->unk_44;
            s->unk_22_0 = true;
            s->unk_22_1 = 1;
        }
        break;
    case 3:
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xf) {
            func_ov000_02191708(self->unk_38);
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    case 4:
        if (FLD(s16, self->unk_38, 0xc4) == 2 && o != NULL) {
            func_ov000_0218d46c(o, self->id, 0xb);
            o->unk_90 = self->unk_90;
            o->rot[0] = self->rot[0];
            o->rot[1] = self->rot[1];
            o->rot[2] = self->rot[2];
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    case 5:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    if (o != NULL && Ov009_Mode(o) == 9) {
        Ov009Vec q;
        q.x = self->pos.x; q.y = self->pos.y; q.z = self->pos.z;
        q.y += FLD(s32, self, 0x68) + 0x1000;
        o->pos.x = q.x; o->pos.y = q.y; o->pos.z = q.z;
        o->unk_9c = 0;
        o->unk_a0 = 0;
        o->unk_a4 = 0;
    }
}

}
