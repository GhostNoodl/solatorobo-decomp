#include "ov014/ov014.h"


// A header's zero rotation and vector, plus copies made at startup, next to this TU's name,
// scale and offsets. The pointer to the name and two offsets are read by other functions.
// The functions of 0x021fc220..0x021fcf00 (ov014_021fc220.cpp, merged in round dtB in its own
// namespace) are part of this TU: they read the name pointer and the zero vector through the
// .rodata base plus an offset, and name them (data_ov014_022164a0, data_ov014_022164d0) instead of
// an Ov014Vec array view of data_ov014_022164a0.
// ov014_021fcf00.cpp (0x021fcf00..0x021fd2bc, which reads the name pointer) joined in round dtD.
extern const char *const data_ov014_022164a0;
extern const VecFx32 data_ov014_022164b8;
extern const VecFx32 data_ov014_022164c4;
extern char data_ov014_022171be[];
const char *const data_ov014_022164a0 = data_ov014_022171be;
static const VecFx16 data_ov014_022164a4 = {0, 0, 0};
const VecFx32 data_ov014_022164b8 = {0, FX32_ONE, 0};
static const VecFx32 data_ov014_022164ac = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov014_022164c4 = {2 * FX32_ONE, 0, 0};
static const VecFx32 data_ov014_022164d0 = {0, 0, 0};
static const VecFx16 data_ov014_022171b8 = data_ov014_022164a4;
char data_ov014_022171be[] = "nut00";
static const VecFx32 data_ov014_022171c4 = data_ov014_022164d0;

// ---- merged from ov014_021fc220.cpp
namespace m_021fc220 {
extern "C" {

extern u8 data_ov014_0221722c[];
extern void Ov003FxList_KillAll(void *p);
extern void func_ov000_0219763c(void *self);
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov014Sub48 *p);

void func_ov014_021fc220(Ov014ActEx_021fbd64 *self) {
    if (self->unk_40->state == 0) {
        Ov003FxList_KillAll(self->unk_d0);
    }
    func_ov000_0219763c(self);
}

#pragma force_active on
Ov014ActEx_021fc24c *Ov014ActEx_021fc24c_Ctor(Ov014ActEx_021fc24c *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov014_0221722c;
    self->unk_f8 = 0;
    self->unk_100 = NULL;
    self->unk_f4 = 0;
    self->unk_fd = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free100(Ov014ActEx_021fc24c *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_100 != NULL) {
        void *p = self->unk_100;
        if (p != NULL) {
            func_ov003_021da940(p);
            Heap_Free(p);
        }
        self->unk_100 = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014ActEx_021fc24c *Ov014ActEx_021fc24c_Dtor(Ov014ActEx_021fc24c *self) {
    FLD(void *, self, 0) = data_ov014_0221722c;
    Ov014_Free100(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_021fc24c *Ov014ActEx_021fc24c_DtorDelete(Ov014ActEx_021fc24c *self) {
    FLD(void *, self, 0) = data_ov014_0221722c;
    Ov014_Free100(self);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_021fc24c_Start(Ov014ActEx_021fc24c *self) {
    s32 *p;
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    self->unk_fc = self->unk_18;
    self->unk_dc = 0x1000;
    self->unk_e0 = 0x1000;
    self->unk_e4 = 0x1000;
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
    }
    self->unk_44->unk_1c = FX_Mul(self->unk_64, 0x2800);
    p = (s32 *)Heap_Alloc(4);
    if (p != NULL) {
        *p = 0;
    }
    self->unk_100 = p;
    m = self->unk_38;
    {
        s32 y = m->unk_a8.y;
        s32 z = m->unk_a8.z;
        self->unk_e8.x = m->unk_a8.x;
        self->unk_e8.y = y;
        self->unk_e8.z = z;
    }
    Ov014_VecCopy(&m->unk_a8, &data_ov014_022164d0);
    func_ov000_02198360(self->unk_40, 1, 0);
}

extern Ov014Vec data_ov014_022164dc;
extern void *data_02097e4c;
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern BOOL Ov003FxList_Has(void *p, u8 id);
extern Ov014Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014f_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_021fc464(Ov014ActEx_021fc24c *self) {
    switch (self->unk_fc) {
    case 0: {
        Ov014Sub40 *s = self->unk_40;
        switch (s->state) {
        case 0: {
            Ov014V *e;
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            e = func_02065f88(0x322, &self->pos);
            FLD(s32, e, 0x3c) = 0x2000;
            func_ov003_021da9ac(self->unk_100, 0, e);
            {
                Ov014Vec v = {0, 0, 0};
                v.x = Rand_PlusMinus(0x9000);
                v.z = Rand_PlusMinus(0x259a);
                VEC_Add(&v, &data_ov014_022164dc, &self->unk_d0);
            }
            {
                s64 sq;
                dx = self->pos.x - self->unk_d0.x;
                dz = self->pos.z - self->unk_d0.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_d0.y - self->pos.y);
            self->unk_9c = Ov014f_FxMul64(OV014_SIN(a), 0x4cd);
            self->unk_a0 = Ov014f_FxMul64(OV014_COS(a), 0x4cd);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_d0.y, r);
            self->unk_40->state++;
            break;
        }
        case 1:
            self->unk_f4 += 0xcd;
            if (self->unk_f4 >= self->unk_e8.x) {
                self->unk_f4 = self->unk_e8.x;
                s->state++;
            }
            {
                u8 *m = (u8 *)self->unk_38;
                s32 f = self->unk_f4;
                FLD(s32, m, 0xa8) = f;
                FLD(s32, m, 0xac) = f;
                FLD(s32, m, 0xb0) = f;
            }
            break;
        case 2:
            if (!Ov003FxList_Has(self->unk_100, 0)) {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = true;
                n->unk_22_1 = true;
                func_ov000_02198360(self->unk_40, 0xb, 0);
            }
            break;
        }
        break;
    }
    case 1: {
        Ov014Sub40 *s = self->unk_40;
        switch (s->state) {
        case 0: {
            Ov014V *e;
            Ov014Actor *t;
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            VEC_Add(&self->pos, &data_ov014_022164b8, &self->pos);
            e = func_02065f88(0x322, &self->pos);
            e->v0c(0x2000);
            FLD(s32, e, 0xc8) = -1;
            func_ov003_021da9ac(self->unk_100, 0xff, e);
            {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 0;
                n->unk_22_1 = 0;
            }
            t = data_ov000_021ccd68 != NULL ? ActorMgr_FindKind(data_ov000_021ccd68, 0x1000, 0x1000) : NULL;
            self->unk_d0.x = t->pos.x;
            self->unk_d0.y = t->pos.y;
            self->unk_d0.z = t->pos.z;
            {
                s64 sq;
                dx = self->pos.x - self->unk_d0.x;
                dz = self->pos.z - self->unk_d0.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_d0.y - self->pos.y);
            self->unk_9c = Ov014f_FxMul64(OV014_SIN(a), 0x4cd);
            self->unk_a0 = Ov014f_FxMul64(OV014_COS(a), 0x4cd);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_d0.y, r);
            func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x77, &self->pos, 0);
            self->unk_40->state++;
            break;
        }
        case 1:
            self->unk_f4 += 0x52;
            if (self->unk_f4 >= self->unk_e8.x + 0x1000) {
                s->timer = 0;
                self->unk_40->state++;
            }
            {
                u8 *m = (u8 *)self->unk_38;
                s32 f = self->unk_f4;
                FLD(s32, m, 0xa8) = f;
                FLD(s32, m, 0xac) = f;
                FLD(s32, m, 0xb0) = f;
            }
            {
                Ov014Sub40 *w = self->unk_40;
                w->timer++;
                if (w->timer % 15 == 0) {
                    u8 *m = (u8 *)self->unk_38;
                    FLD(u16, m, 0xb6) = 0x7c1f;
                    FLD(u16, m, 0xb8) = 0x7c1f;
                    FLD(u16, m, 0xba) = 6;
                    FLD(u16, m, 0xbc) = 5;
                }
            }
            break;
        case 2: {
            u16 t;
            s->timer++;
            t = s->timer;
            if (t > 100) {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = true;
                n->unk_22_1 = true;
                self->unk_40->timer = 0;
                func_ov000_02198360(self->unk_40, 0xb, 0);
            }
            if (t % 15 == 0) {
                u8 *m = (u8 *)self->unk_38;
                FLD(u16, m, 0xb6) = 0x7c1f;
                FLD(u16, m, 0xb8) = 0x7c1f;
                FLD(u16, m, 0xba) = 6;
                FLD(u16, m, 0xbc) = 5;
            }
            break;
        }
        }
        break;
    }
    }
    func_ov003_021dacfc(self->unk_100);
}


extern u8 data_ov014_02217209[];
extern u8 data_ov014_02217218[];
extern Ov014Actor *Target_Get(void *p);
extern void func_ov014_021fcf00(Ov014ActEx_021fc24c *self);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov003_021daae4(void *p, s32 a, Ov014Vec *v, void *b, s32 c, s32 d, s32 e);
extern void Actor_TurnToPos(Ov014Obj *self, Ov014Vec *v, s32 a);
extern s32 func_ov000_0219a510(Ov014Obj *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov003_021f0c60(Ov014Obj *self, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov014V *Effect3D_Create(const void *a, const void *b, s32 c, Ov014Vec *pos);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern BOOL func_ov000_0219aca8(Ov014Obj *a, Ov014Obj *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov014Actor *Actor_GetTarget(Ov014Obj *self);

void func_ov014_021fc9c8(Ov014ActEx_021fc24c *self) {
    Ov014Actor *list[0x20];
    Ov014Actor *o = Target_Get(self->unk_4c);
    if (o != NULL) {
        {
            Ov014Sub48 *m = o->unk_48;
            if (m != NULL && m->unk_9a_3) {
                m->unk_9a_3 = 0;
                func_0203f364(m);
            }
        }
        if (o->kind == 0x1000) {
            func_ov014_021fcf00(self);
        } else {
            switch (self->unk_40->state) {
            case 0: {
                Ov014Sub48 *m;
                func_ov000_02190cb0(self->unk_38, data_ov014_022164a0, 0x1000, 0);
                func_ov000_021915a0(self->unk_38);
                m = self->unk_48;
                m->unk_50 = 0;
                m->unk_54 = 0;
                FLD(u32, m, 0x58) = 0;
                if (self->unk_fc != 0) {
                    func_0204a028(data_02097e4c, 0x79, &self->pos, -10);
                }
                func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
                self->unk_fe = 0;
                self->unk_40->state++;
            }
            case 1: {
                s32 rad;
                u16 team;
                s32 i;
                s32 n;
                if (self->unk_fc != 0) {
                    Ov014Sub40 *w;
                    func_ov003_021daae4(self->unk_100, 0xff, &self->pos, NULL, 0, 0, 0);
                    w = self->unk_40;
                    w->timer++;
                    if (w->timer % 15 == 0) {
                        u8 *m = (u8 *)self->unk_38;
                        FLD(u16, m, 0xb6) = 0x7c1f;
                        FLD(u16, m, 0xb8) = 0x7c1f;
                        FLD(u16, m, 0xba) = 6;
                        FLD(u16, m, 0xbc) = 5;
                    }
                }
                Actor_TurnToPos(self, &self->unk_d0, 0xcd);
                self->unk_98 = self->rot[1];
                Actor_Move((Actor *)self, 0);
                self->unk_fe++;
                rad = self->unk_64;
                team = Target_Get(self->unk_4c)->id & 0xf000;
                n = func_ov000_0219a510(self, (u16)~(1 << (team >> 12)), &self->pos, rad, 0, list);
                if (n != 0) {
                    for (i = 0; i < n; i++) {
                        Ov014Actor *a;
                        if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
                            if (a->unk_4c == NULL || (u16)(a->unk_4c->target & 0xf000) != team ||
                                self->unk_fe >= 200) {
                                if (self->unk_fc == 0) {
                                    func_ov003_021f0c60(self, 0);
                                }
                                func_ov000_02198360(self->unk_40, 0x15, 0);
                                break;
                            }
                        }
                    }
                }
                func_ov000_021987b8(self->unk_48, 1, 0, 0);
                if (self->unk_48->unk_50 & 0x20000000) {
                    Ov014Sub44 *q = self->unk_44;
                    Ov014Sub48 *m;
                    q->unk_22_0 = 0;
                    q->unk_22_1 = 0;
                    m = self->unk_48;
                    m->unk_9a_1 = 0;
                    m->unk_9a_4 = 0;
                    self->unk_38->unk_c2_0 = 0;
                    func_ov000_0218996c(0x1e, 0x32);
                    self->unk_f8 |= 0x100000;
                    self->unk_40->state++;
                }
                break;
            }
            case 2: {
                Ov014V *e;
                u8 k;
                e = Effect3D_Create(data_ov014_02217209, data_ov014_02217218, 0, &self->pos);
                e->v0c(0x8800);
                FLD(u8, e, 0x28) = 0;
                MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
                func_ov003_021da9ac(self->unk_100, 0xfe, e);
                func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
                func_02049f44(data_02097e4c, 0x5a, &self->pos, 0);
                {
                    Ov014Vec b2 = data_ov014_022164c4;
                    Ov014Vec lv;
                    for (k = 0; k < 2; k++) {
                        Ov014_VecCopy(&lv, &b2);
                        if (k != 0) {
                            lv.x = -lv.x;
                        }
                        VEC_Add(&lv, &self->pos, &lv);
                        e = func_02065f88(0x1f9, &lv);
                        e->v0c(0xb33);
                        MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
                    }
                }
                if (func_ov000_0219aca8(self, self, self->unk_4c->unk_08, self->unk_4c->unk_0a, 0, 0, 0x5ccd, 0, 0x6b, 0x1000)) {
                    Ov014Actor *t = Actor_GetTarget(self);
                    Ov014Vec pp;
                    if (t != NULL) {
                        pp = t->pos;
                        func_02049f44(data_02097e4c, 0x10, &pp, 0);
                    }
                }
                self->unk_40->state++;
                break;
            }
            case 3:
                if (!Ov003FxList_Has(self->unk_100, 0xfe)) {
                    func_ov000_02198360(self->unk_40, 0x15, 0);
                }
                break;
            }
        }
    } else {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    func_ov003_021dacfc(self->unk_100);
}
}
}  // namespace m_021fc220

// ---- merged from ov014_021fcf00.cpp
namespace m_021fcf00 {
extern "C" {

extern Ov014Vec *func_ov000_0218d2e0(void *self);
extern Ov014Actor *Target_Get(void *p);
extern void Actor_TurnToPos(Ov014Obj *self, Ov014Vec *v, s32 a);
extern s32 func_ov000_0219a510(Ov014Obj *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov003_021f0c60(Ov014Obj *self, s32 a);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_021fcf00(Ov014ActEx_021fc24c *self) {
    Ov014Vec d;
    Ov014Actor *list[0x20];
    switch (self->unk_40->state) {
    case 0: {
        Ov014Vec *p;
        s32 r;
        s32 dx;
        s32 dz;
        func_ov000_02190cb0(self->unk_38, data_ov014_022164a0, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        p = func_ov000_0218d2e0(self);
        d = *p;
        self->unk_d0.x = d.x;
        self->unk_d0.y = d.y;
        self->unk_d0.z = d.z;
        d.y = d.y - self->pos.y;
        {
            s64 sq;
            dx = self->pos.x - d.x;
            dz = self->pos.z - d.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV014_SQRTCNT = 1;
            OV014_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV014_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
        d.x = FX_Mul(r, OV014_SIN(self->rot[1])) - 0x2000;
        d.z = FX_Mul(r, OV014_COS(self->rot[1]));
        VEC_Normalize(&d, &d);
        self->unk_9c = FX_Mul(d.x, 0x400);
        self->unk_a0 = FX_Mul(d.y, 0x400);
        self->unk_a4 = FX_Mul(d.z, 0x400);
        FX_Atan2(r, self->unk_d0.y - self->pos.y);
        self->rot[0] = FX_Atan2(self->pos.y - self->unk_d0.y, r);
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_fe = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        s32 rad;
        s32 n;
        u16 team;
        s32 i;
        d = self->unk_d0;
        d.x -= 0x2000;
        Actor_TurnToPos(self, &d, 0xcd);
        VEC_Add(&self->pos, (Ov014Vec *)&self->unk_9c, &self->pos);
        self->unk_fe++;
        rad = self->unk_64 + 0x4cd;
        if (rad < 0xccd) {
            rad = 0xccd;
        }
        self->unk_48->unk_44 = rad;
        team = Target_Get(self->unk_4c)->id & 0xf000;
        n = func_ov000_0219a510(self, (u16)~(1 << (team >> 12)), &self->pos, rad, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov014Actor *a;
                if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
                    if (a->unk_4c == NULL || (u16)(a->unk_4c->target & 0xf000) != team ||
                        ++self->unk_fe >= 200) {
                        func_ov003_021f0c60(self, 0);
                        func_ov000_02198360(self->unk_40, 0x15, 0);
                        break;
                    }
                }
            }
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 1) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    }
}

}
}  // namespace m_021fcf00
