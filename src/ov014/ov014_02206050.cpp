#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_0214a420;
extern Ov014Vec data_ov014_022169ec;
extern void func_0203f364(Ov014Sub48 *p);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern BOOL func_020657b0(void *a, void *b);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_01ffc9fc(Ov014Vec *a, Ov014Vec *b, u16 ang);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *t, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern void func_ov014_02206b5c(Ov014Actor *self);
extern void func_ov014_02206734(Ov014Actor *self);

#define OV014F_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014F_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014F_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_02206050(Ov014Actor *self) {
    Ov014Actor *t = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    Ov014Actor *pl;
    if (t != NULL) {
    {
        Ov014Sub48 *m = t->unk_48;
        if (m != NULL && m->unk_9a_3) {
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
    }
    if (t->kind == 0x1000) {
        func_ov014_02206734(self);
        return;
    }
    pl = func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e;
        {
            Ov014Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        e = func_02065f88(0x68, &self->pos);
        e->v0c(0xb33);
        e->v34(0xbfff, self->rot[1], 0);
        func_02065f88(0x579, &self->pos)->v0c(0x2000);
        func_0204a028(data_02097e4c, 0x32, &self->pos, 0xa);
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014V *e;
        s32 r;
        Ov014Vec v = data_ov014_022169ec;
        v.y = (0x47000 - self->pos.y) / 6;
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Add(&self->pos, &v, &v);
        self->unk_84.x = v.x;
        self->unk_84.y = v.y;
        self->unk_84.z = v.z;
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        {
            s64 sq;
            s32 dx;
            s32 dz;
            dx = self->pos.x - self->unk_84.x;
            dz = self->pos.z - self->unk_84.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV014F_SQRTCNT = 1;
            OV014F_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV014F_SQRTCNT & 0x8000) {
        }
        self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, (s32)(OV014F_SQRT_RESULT + 1) >> 1);
        func_02065f88(0x192, &self->pos)->v30(self->rot);
        e = func_02065f88(0x68, &self->pos);
        e->v0c(0xb33);
        e->v34((u16)(self->rot[0] + 0xbfff), self->rot[1], 0);
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        self->unk_40->state++;
        break;
    }
    case 2: {
        Ov014Vec d;
        Ov014Sub40 *s;
        d.x = self->unk_84.x - self->pos.x;
        d.y = self->unk_84.y - self->pos.y;
        d.z = self->unk_84.z - self->pos.z;
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        func_ov014_02206b5c(self);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 0x1e) {
            return;
        }
        self->unk_9c = 0xf6;
        self->unk_a0 = -0x52;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 3: {
        Ov014Sub40 *s;
        func_ov000_0218d988(self, pl, 0x19a);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        s = self->unk_40;
        s->timer++;
        if (s->timer > 0x1e) {
            self->unk_40->timer = 0;
            self->unk_40->state = 1;
        }
        if (self->pos.y > 0x4b000) {
            return;
        }
        {
            Ov014V *e = func_02065f88(0x69, &self->pos);
            e->v0c(0x800);
            FLD(s32, self, 0xe8) = FLD(s32, e, 0x24);
        }
        self->unk_40->timer = 0;
        self->unk_40->state = 10;
        break;
    }
    case 10: {
        Ov014Actor *o;
        Ov014V *e;
        s32 r;
        u16 ang;
        func_ov000_0218d988(self, pl, 0x400);
        if (func_020657b0(data_0214a420, FLD(void *, self, 0xe8))) {
            return;
        }
        o = func_ov000_0218d240(self);
        {
            s64 sq;
            s32 dx;
            s32 dz;
            Ov014Vec p;
            Ov014_VecCopyYZ(&p, &o->pos);
            dx = self->pos.x - p.x;
            dz = self->pos.z - p.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            self->unk_84.y = 0x48000;
            self->unk_84.z = p.z;
            self->unk_84.x = p.x;
            OV014F_SQRTCNT = 1;
            OV014F_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV014F_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV014F_SQRT_RESULT + 1) >> 1;
        ang = FX_Atan2(r, self->unk_84.y - self->pos.y);
        self->unk_9c = (s32)(((s64)OV014_SIN(ang) * (s64)0x4cd + 0x800) >> 12);
        self->unk_a0 = (s32)(((s64)OV014_COS(ang) * (s64)0x4cd + 0x800) >> 12);
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
        func_02065f88(0x192, &self->pos)->v30(self->rot);
        e = func_02065f88(0x68, &self->pos);
        e->v0c(0xb33);
        e->v34((u16)(self->rot[0] + 0xbfff), self->rot[1], 0);
        FLD(u8, self, 0xe4) = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 11:
        if (self->pos.y - self->unk_84.y > 0x1000) {
            func_ov000_0218d918(self, &self->unk_84, 0x266);
            self->unk_98 = self->rot[1];
        }
        func_ov000_0218dbe0(self, 0);
        func_ov014_02206b5c(self);
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            if (++FLD(u8, self, 0xe4) < 100) {
                return;
            }
        }
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
    } else {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

}
