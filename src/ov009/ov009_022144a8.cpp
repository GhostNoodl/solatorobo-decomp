#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_02195d88(Ov009Actor *self);
extern void func_ov000_02196c40(Ov009Actor *self);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_022144a8(Ov009Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov009_022144c0(Ov009Actor *self) {
    func_ov000_02195d88(self);
    if (Ov009_FindActor(FLD(u16, self, 0xd2)) == NULL) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

void func_ov009_02214508(Ov009Actor *self) {
    if (self->unk_40->state == 0 && self->unk_9c == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov000_02196c40(self);
}

extern void *data_ov000_021ccd64;
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern u16 func_ov000_0218dfb4(Ov009Actor *a, u16 id);
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);
struct Ov009SpawnDesc2 {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov009Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov009Flag8 {
    u8 b0 : 1;
    u8 b1 : 7;
};

extern Ov009Actor *func_ov000_0218bf1c(void *mgr, Ov009SpawnDesc2 *d, Ov009Vec *pos, Ov009Rot16 *rot, u16 a);

static inline void Ov009Spawn_Init(Ov009SpawnDesc2 *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

void func_ov009_02214534(Ov009Actor *self) {
    Ov009Vec p;
    Ov009SpawnDesc2 desc;
    Ov009Rot16 r;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        u16 i;
        u16 n;
        Ov009Actor *e;
        s32 s;
        Ov009Spawn_Init(&desc, 0x4006);
        n = 3;
        e = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
        if (e != NULL) {
            u32 c = func_ov000_0218dfb4(e, 0x4006);
            if (c > 3) {
                c = 3;
            }
            n = 3 - c;
        }
        for (i = 0; i < n; i++) {
            Ov009Actor *o;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += 0x1000;
            r.x = self->rot[0];
            r.y = self->rot[1];
            r.z = self->rot[2];
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &p, &r, 0xffff);
            if (o != NULL) {
                FLD(Ov009Flag8, o, 0x16).b0 = 1;
                o->unk_90 = self->unk_90;
                o->unk_9c = 0;
                o->unk_a0 = 0x333;
                o->unk_a4 = 0;
                o->unk_a8 = 0x52;
                if (FLD(u8 *, o, 0x4c) != NULL) {
                    FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
                }
            }
        }
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += FLD(s32, self, 0x6c);
        {
            Ov009V *e2 = func_02065f88(0x1f7, &p);
            s = self->unk_64 + (self->unk_64 >> 3);
            e2->v14(s, s, s);
        }
        func_ov000_0218996c(0xc, 0x14);
        if (self->unk_44 != NULL) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        if (self->unk_48 != NULL) {
            Ov009Sub48 *s48;
            func_ov000_02198c8c(self->unk_48, 0xffff);
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s48 = self->unk_48;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer > 5) {
            func_ov000_02197dec(self, 0xf, 0x63);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
            return;
        }
        if (self->unk_38 != NULL) {
            FLD(u8, self->unk_38, 0xbe) = 0x1f - (self->unk_40->timer << 2);
        }
        break;
    }
}

}
