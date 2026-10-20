#include "ov013/ov013.h"

struct Ov013SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov013Spawn_Init(Ov013SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern char data_ov013_0220b5d0[];
extern char data_ov013_0220b5b8[];
extern Ov013Vec data_ov013_0220ae70;
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(void *self, Ov013Actor *a, s32 b);
extern void func_ov000_0219a210(Ov013Vec *v, Ov013Vec *off, u16 rot);
extern Ov013Actor *func_ov000_0218bf1c(void *mgr, Ov013SpawnDesc *d, Ov013Vec *pos, u16 *rot, u16 a);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_021fbd20(Ov013Actor *self) {
    Ov013Sub40 *w;
    Ov013Actor *a = Ov013_FindActor(self->unk_90);
    if (a == NULL) {
        return;
    }
    w = self->unk_40;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5d0, 0x2ab, 1);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    case 0x14: {
        Ov013SpawnDesc d;
        Ov013Vec pos;
        Ov013Actor *o;
        func_ov000_0218d988(self, a, self->unk_b0->unk_02);
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        Ov013Spawn_Init(&d, 0x4820);
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z;
        func_ov000_0219a210(&pos, &data_ov013_0220ae70, self->rot[1]);
        pos.y = 0;
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &pos, self->rot, 0xffff);
        FLD(Ov013Flags8, o, 0x16).b0 = 1;
        o->unk_90 = self->unk_90;
        if (FLD(u8, self, 0xf0) != 0) {
            o->unk_9c = 0x11f;
            o->unk_a0 = 0;
            o->unk_a4 = 0;
            o->unk_a8 = 0;
        }
        if (FLD(void *, o, 0x4c) != NULL) {
            FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
        }
        FLD(u16, self, 0xde) = o->id;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
        break;
    }
    case 0x63:
        if (FLD(u8, self, 0xf1) != 0) {
            w->timer++;
            if (w->timer > 60) {
                FLD(u8, self, 0xf1)--;
                self->unk_40->state = 0;
                self->unk_40->timer = 0;
            }
        } else {
            w->timer++;
            if (w->timer > 20) {
            FLD(u8, self, 0xf0) = 0;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
}

extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_0203f364(Ov013Sub48 *p);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02065860(void *a, s32 b);
extern void func_ov000_0219b71c(Ov013Vec *pos, Ov013Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d6a3c(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov013Actor *self, u8 a);

void func_ov013_021fbf84(Ov013Actor *self) {
    Ov013Sub40 *w = self->unk_40;
    switch (w->state) {
    case 0: {
        Ov013Sub48 *m48;
        Ov013Sub44 *n;
        Ov013V *o;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x5c17, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4823, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4820, 0x15);
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_50[0] = 0;
        m48 = self->unk_48;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        func_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        o = func_02065f88(0x390, &self->pos);
        if (o != NULL) {
            FLD(s32, self, 0xf8) = FLD(s32, o, 0x24);
            o->v24(0, FLD(s32, self, 0x68), 0);
            o->v0c(0x1800);
        }
        o = func_02065f88(0x69, &self->pos);
        if (o != NULL) {
            o->v24(0, FLD(s32, self, 0x68), 0);
            o->v0c(0x5000);
        }
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        func_ov000_0218996c(0xc, 0x28);
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    }
    case 0x14: {
        u16 t;
        w->timer++;
        t = w->timer;
        if (t >= 0x78) {
            if (t % 30 == 0) {
                Ov013Vec v;
                v.x = self->unk_64 << 1;
                v.y = FLD(s32, self, 0x68) >> 1;
                v.z = self->unk_64;
                func_ov000_0219b71c(&self->pos, &v, 0x99a, 0x1333, 0x38b, 0x32);
                func_ov000_0218996c(8, 8);
                func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
            }
            if (t >= 0x12b) {
                func_ov000_0218996c(0x14, 0x78);
                self->unk_40->state = 0x63;
                self->unk_40->timer = 0;
            }
            self->pos.y -= 0x66;
        } else {
            if (t % 25 == 0) {
                func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            }
            if (t == 0x6e) {
                func_02065860(data_0214a420, FLD(s32, self, 0xf8));
                FLD(s32, self, 0xf8) = 0;
            }
        }
        break;
    }
    case 0x63: {
        Ov013Vec p;
        Ov013V *o;
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += FLD(s32, self, 0x68);
        o = func_02065f88(0x38b, &p);
        if (o != NULL) {
            o->v0c(0x3000);
        }
        o = func_02065f88(0x69, &p);
        if (o != NULL) {
            o->v0c(0x5000);
            FLD(s32, o, 0x3c) = 0xccd;
        }
        func_0204a028(data_02097e4c, 0x56, &self->pos, -8);
        func_0204a028(data_02097e4c, 0x41, &self->pos, 4);
        self->unk_40->state = 0x64;
        self->unk_40->timer = 0;
        break;
    }
    case 0x64:
        w->timer++;
        if (w->timer > 0x78) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            break;
        }
        if (self->unk_40->timer <= 0x3c) {
            func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        } else {
            func_ov003_021d6954(self, 0);
        }
        break;
    }
}
}
