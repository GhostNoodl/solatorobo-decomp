#include "ov009/ov009.h"


// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// and effect names, the 16 pointers to them, and the offsets and sizes other functions read.
// The functions of 0x021ff730..0x0220413c (19 files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the 16 name pointers through the .rodata base plus an
// offset, and name them (data_ov009_02215d0c..02215d48) instead of a data_ov009_02215d0c[n] array
// view. Round dtD merged 0x0220413c..0x02204a10 (five files) too: Ov009ActVt_02216bc8_Start copies the
// zero vector data_ov009_02215d90 (base + 0x84) with struct assignments, into each trail entry and
// then into the model's position. Written as x/y/z field reads its y/z loads are CSE'd (42 lines).

extern const char *const data_ov009_02215d0c;
extern const s32 data_ov009_02215d54[2];
extern const s32 data_ov009_02215d5c[2];
extern const s16 data_ov009_02215d64[4];
extern const Ov009Blk12 data_ov009_02215d6c;
extern const VecFx32 data_ov009_02215d78;
extern const VecFx32 data_ov009_02215d84;
extern char data_ov009_02216ad4[];
extern char data_ov009_02216ada[];
extern char data_ov009_02216ae0[];
extern char data_ov009_02216ae6[];
extern char data_ov009_02216aec[];
extern char data_ov009_02216af2[];
extern char data_ov009_02216afe[];
extern char data_ov009_02216b04[];
extern char data_ov009_02216b0a[];
extern char data_ov009_02216b10[];
extern char data_ov009_02216b17[];
extern char data_ov009_02216b1e[];
extern char data_ov009_02216b25[];
extern char data_ov009_02216b2f[];
extern char data_ov009_02216b39[];
extern char data_ov009_02216b43[];
extern char data_ov009_02216b4f[];
static const char *const data_ov009_02215d44 = data_ov009_02216b17;
static const char *const data_ov009_02215d40 = data_ov009_02216b1e;
static const char *const data_ov009_02215d10 = data_ov009_02216b25;
char data_ov009_02216afe[] = "dmg12";
const char *const data_ov009_02215d0c = data_ov009_02216ae0;
static const char *const data_ov009_02215d38 = data_ov009_02216b39;
char data_ov009_02216b2f[] = "en/e1hun1";
static const char *const data_ov009_02215d48 = data_ov009_02216b2f;
static const char *const data_ov009_02215d18 = data_ov009_02216aec;
const s32 data_ov009_02215d54[2] = {0xe02, 0xf02};
char data_ov009_02216b4f[] = "ef3di1hdi10";
const s16 data_ov009_02215d64[4] = {0x1000, 0x1000, 0x2000, 0x1000};
char data_ov009_02216b0a[] = "run00";
static const char *const data_ov009_02215d34 = data_ov009_02216af2;
char data_ov009_02216ada[] = "nut10";
static const char *const data_ov009_02215d28 = data_ov009_02216ada;
char data_ov009_02216b43[] = "ef3di1hdi11";
char data_ov009_02216b17[] = "e1hun1";
const Ov009Blk12 data_ov009_02215d6c = {0x02520000, 0, 0xffff};
char data_ov009_02216ae6[] = "att01";
char data_ov009_02216af2[] = "dmg00";
static const char *const data_ov009_02215d1c = data_ov009_02216ae6;
const VecFx32 data_ov009_02215d84 = {0, 0x2f33, 0x2733};
char data_ov009_02216b1e[] = "e1top1";
static const VecFx32 data_ov009_02215d90 = {0, 0, 0};
char data_ov009_02216b39[] = "en/e1top1";
const s32 data_ov009_02215d5c[2] = {0xd02, 0x1002};
static const VecFx16 data_ov009_02215d4c = {0, 0, 0};
char data_ov009_02216ad4[] = "nut00";
char data_ov009_02216b10[] = "e1hdi2";
char data_ov009_02216b25[] = "en/e1hdi2";
static const char *const data_ov009_02215d30 = data_ov009_02216ad4;
static const VecFx16 data_ov009_02216af8 = data_ov009_02215d4c;
static const char *const data_ov009_02215d3c = data_ov009_02216b04;
static const char *const data_ov009_02215d20 = data_ov009_02216afe;
static const char *const data_ov009_02215d2c = data_ov009_02216b0a;
char data_ov009_02216ae0[] = "att00";
char data_ov009_02216aec[] = "att10";
static const char *const data_ov009_02215d14 = data_ov009_02216b10;
static const char *const data_ov009_02215d24 = data_ov009_02216ad4;
const VecFx32 data_ov009_02215d78 = {0, 0x3800, 0};
char data_ov009_02216b04[] = "nut01";
static const VecFx32 data_ov009_02216b5c = data_ov009_02215d90;

// ---- merged from ov009_021ff730.cpp
namespace m_021ff730 {
extern "C" {


void func_ov009_021ff730(Ov009ActVt_022171d4 *self) {
    if (self->unk_f4 != 0) {
        self->unk_f4--;
    } else {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
    self->v50();
}

void func_ov009_021ff770(Ov009ActVt_022171d4 *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    Ov009Vec *f8 = &self->unk_f8;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_b8 = self->pos;
        self->unk_f0 = 1;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_40->timer = 0x3c;
            *f8 = self->unk_b8;
            f8->x += Rand_PlusMinus(0x800);
            f8->z += Rand_PlusMinus(0x800);
            func_ov000_0219a2f4(f8, self->pos.y + 0x2000, -0xa000);
            f8->y = f8->y + Rand_PlusMinus(0x800) + 0x3000;
        }
        d.x = f8->x - self->pos.x;
        d.y = f8->y - self->pos.y;
        d.z = f8->z - self->pos.z;
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

extern void Actor_MoveToPos(Ov009Actor *self, Ov009Vec *v, s32 a);

void func_ov009_021ff908(Ov009ActVt_022171d4 *self) {
    Ov009Vec v;
    Ov009Vec p;
    s32 d;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    v = self->unk_b8;
    self->unk_9c = self->unk_b0->unk_00;
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    p = self->pos;
    d = self->pos.y + 0x2000;
    func_ov000_0219a2f4(&p, d, -0xa000);
    d = p.y + 0x3000;
    d -= self->pos.y;
    self->pos.y += FX_Mul(d, 0xcd);
    p.y += 0x3000;
    VEC_Distance(&self->pos, &p);
}

}
}  // namespace m_021ff730

// ---- merged from ov009_021ffa40.cpp
namespace m_021ffa40 {
extern "C" {

extern void *data_02097e4c;
extern const Ov009Vec data_ov009_02215da8;
extern const Ov009Vec data_ov009_02215d9c;
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void Actor_MoveToPos(Ov009Actor *self, Ov009Vec *v, s32 a);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218999c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, const Ov009Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_02191690(void *p);

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov009_Ground(Ov009Vec *out, Ov009Actor *self) {
    *out = self->pos;
    func_ov000_0219a2f4(out, self->pos.y + 0x2000, -0xa000);
}

static inline s32 Ov009_Hover(Ov009ActVt_022171d4 *self, s32 h, s64 rate) {
    Ov009Vec p;
    Ov009_Ground(&p, self);
    s32 d = p.y + h;
    d -= self->pos.y;
    self->pos.y += Ov009_FxMulL(d, rate);
    p.y += h;
    return VEC_Distance(&self->pos, &p);
}

void func_ov009_021ffa40(Ov009ActVt_022171d4 *self) {
    Ov009Vec tp;
    Ov009Vec b;
    Ov009Vec p3;
    Ov009Actor *t;
    Ov009Param *prm;
    Ov009Sub40 *st;
    t = Actor_GetTarget(self);
    tp.x = t->pos.x;
    tp.y = t->pos.y;
    tp.z = t->pos.z;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d2c, 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        prm = self->unk_b0;
        self->unk_9c = prm->unk_00 * 2;
        Actor_MoveToPos(self, &tp, prm->unk_02);
        Ov009_Hover(self, 0x4800, 0xcd);
        tp.y = self->pos.y;
        if (VEC_Distance(&self->pos, &tp) < 0x1000) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c, 0x400, 0);
            self->unk_b8.x = tp.x;
            self->unk_b8.y = tp.y;
            self->unk_b8.z = tp.z;
            func_02049f44(data_02097e4c, 0x39, &self->pos, 0x280);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 200) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    case 2:
        b.x = self->unk_b8.x;
        b.y = self->unk_b8.y;
        b.z = self->unk_b8.z;
        prm = self->unk_b0;
        self->unk_9c = prm->unk_00;
        Actor_MoveToPos(self, &b, prm->unk_02);
        Ov009_Hover(self, 0x6000, 0x148);
        if (self->unk_38->anim_state == 1) {
            Ov009_Ground(&self->unk_84, self);
            func_02049f44(data_02097e4c, 0x54, &self->pos, 0);
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_a0 = -0x800;
            self->unk_40->state++;
        }
        break;
    case 3:
        if (self->pos.y <= self->unk_84.y + 0x1b33) {
            func_ov000_0218999c(0xf, 0xf);
            Ov009_Ground(&p3, self);
            func_02065f88(0x68, &p3)->v20(&data_ov009_02215da8);
            func_02049f44(data_02097e4c, 0x7b, &self->pos, 0);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        } else {
            Actor_Move((Actor *)self, 0);
            if (*func_ov000_0219bf90()->unk_50 != 0 && Ov009_GameIdle()) {
                func_ov000_0219aae8(self, self, self->unk_f2, self->unk_4c->unk_0a, 2, &data_ov009_02215d9c, 0, 0x800, 0x2000, 0x64, 0x1000);
            }
        }
        break;
    case 4: {
        u16 tm;
        st = self->unk_40;
        st->timer++;
        tm = st->timer;
        if (tm > 200) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        if (tm == 0xbe) {
            func_ov000_02191690(self->unk_38);
        }
        break;
    }
    case 5:
        if (Ov009_Hover(self, 0x5000, 0x333) <= 0x333) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

}
}  // namespace m_021ffa40

// ---- merged from ov009_021ffff4.cpp
namespace m_021ffff4 {
extern "C" {

extern void *data_02097e4c;
extern u8 data_ov009_02215dc0[];
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, u16 ang);
extern void func_0203f2b8(void *p);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_021ffff4(Ov009ActVt_022171d4 *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x6b, &self->pos, 0);
    }
    func_ov003_021d5900(self);
}

void Ov009ActVt_02217128_Init(Ov009ActVt_02217128 *self) {
    u8 *p;
    func_ov003_021d0fc0(self);
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *b = (Ov009Byte *)(p + 0xa2);
        b->b0 = 0;
        b->b5 = 1;
    }
}

void Ov009ActVt_02217128_Start(Ov009ActVt_02217128 *self) {
    Ov009Vec t;
    void *saved;
    func_ov003_021d112c(self);
    self->unk_f8 = self->pos;
    self->unk_84 = self->pos;
    self->unk_f0 = 0;
    func_01ffc9fc(&t, data_ov009_02215dc0, 0x5554);
    VEC_Add(&self->unk_84, &t, &self->pos);
    self->unk_b8 = self->pos;
    switch (self->kind) {
    case 0x5423:
        self->unk_f4 = 0x32000;
        break;
    case 0x5424:
        self->unk_f4 = 0x6000;
        break;
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->v04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *p = self->unk_48;
        if (p != NULL) {
            func_0203f2b8(p);
            Heap_Free(p);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_44 != NULL) {
        Heap_Free(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
}

extern Ov009Actor *func_ov000_0219bf90(void);
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, Ov009Vec *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov009V *func_02065f88(s32 id, Ov009Vec *pos);

struct Ov009Bits3 {
    u16 b0 : 3;
};

struct Ov009Bits32 {
    u32 b0 : 1;
    u32 b1 : 1;
};

struct Ov009HitMsg2 {
    u8 a;
    u16 b;
    u16 c;
};

static inline s32 Ov009_StateOf(Ov009Sub40 *s) {
    return s != NULL ? s->unk_13 : 0;
}

void Ov009ActVt_02217128_Update(Ov009ActVt_02217128 *self) {
    Ov009Vec v;
    Ov009HitMsg2 msg;
    Ov009Actor *pl;
    func_ov003_021d1e8c(self);
    pl = func_ov000_0219bf90();
    if (pl == NULL || *pl->unk_50 == 0) {
        return;
    }
    if (!(self->unk_f0 & 1)) {
        return;
    }
    if (Ov009_StateOf(pl->unk_40) == 7 || Ov009_StateOf(pl->unk_40) == 0x16 || Ov009_StateOf(pl->unk_40) == 0x10) {
        self->unk_f0 ^= 1;
        func_ov000_02198360(self->unk_40, 0x13, 0);
    } else if (FLD(Ov009Bits3, func_ov000_0219bf90(), 0xb22).b0 == 4) {
        self->unk_f0 ^= 1;
        func_ov000_02198360(self->unk_40, 0x13, 0);
    } else if (Ov009_GameIdle()) {
        s16 cnt = self->unk_18;
        switch (self->kind) {
        case 0x5424:
            msg.a = 1;
            msg.b = 0x333;
            msg.c = 0xf;
            Actor_SendMsg((Actor *)pl, self->id, 0xb, TRUE, 6, &msg);
            cnt++;
            if (cnt % 200 == 0) {
                Ov009V *e;
                cnt = 0;
                func_ov000_0219aae8(self, self, 0xa, 1, 2, NULL, 0, 0x2000, 0, -1, 0x1000);
                v.x = pl->pos.x;
                v.y = pl->pos.y;
                v.z = pl->pos.z;
                e = func_02065f88(0x38b, &v);
                e->v0c(0xb33);
                e->v24(0, 0x1000, 0);
                func_0204a028(data_02097e4c, 0x54, &v, -5);
            }
            self->unk_18 = cnt;
            break;
        case 0x5423:
            if (FLD(Ov009Bits32, pl, 0xb24).b1) {
                cnt++;
                if (cnt % 100 == 0) {
                    cnt = 0;
                    func_0204a028(data_02097e4c, 0x36, &self->pos, -10);
                }
                self->unk_18 = cnt;
                msg.a = 2;
                msg.c = 8;
                Actor_SendMsg((Actor *)pl, self->id, 0xb, TRUE, 6, &msg);
            }
            break;
        }
    }
    if (self->kind == 0x5423 && VEC_Distance(&self->pos, &self->unk_f8) > self->unk_f4) {
        self->unk_f0 ^= 1;
        func_ov000_02198360(self->unk_40, 0x13, 0);
    }
}

extern u8 data_ov009_02215dcc[];
extern void Actor_TurnToPos(Ov009Actor *self, const Ov009Vec *v, s32 a);

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline BOOL Ov009_TickTimer(Ov009Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
    return s->timer == 0;
}

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void func_ov009_02200534(Ov009ActVt_02217128 *self) {
    Ov009Vec plpos;
    Ov009Vec off;
    Ov009Vec d;
    Ov009Actor *pl;
    Ov009Sub40 *st;
    s32 speed;
    u16 ang;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    plpos = pl->pos;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_40->timer = 0x3c;
            self->unk_104 = self->unk_b8;
            self->unk_104.x += Rand_PlusMinus(0x800);
            self->unk_104.z += Rand_PlusMinus(0x800);
            self->unk_104.y += Rand_PlusMinus(0x800);
        }
        d.x = self->unk_104.x - self->pos.x;
        d.y = self->unk_104.y - self->pos.y;
        d.z = self->unk_104.z - self->pos.z;
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->unk_84, &plpos) <= self->unk_f4) {
            self->unk_40->state++;
        }
        break;
    case 2: {
        s64 sq;
        s32 dz;
        s32 dx;
        self->unk_84 = self->pos;
        func_01ffc9fc(&off, data_ov009_02215dcc, 0x5554);
        VEC_Add(&plpos, &off, &plpos);
        dz = self->pos.z - plpos.z;
        dx = self->pos.x - plpos.x;
        sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        ang = FX_Atan2(Ov009_Sqrt64(sq), plpos.y - self->pos.y);
        switch (self->kind) {
        case 0x5423:
            speed = 0x800;
            break;
        case 0x5424:
            speed = 0x333;
            break;
        }
        self->unk_9c = FX_Mul(speed, OV009_SIN(ang));
        self->unk_a0 = FX_Mul(speed, OV009_COS(ang));
        Actor_TurnToPos(self, &plpos, 0x1000);
        self->unk_98 = self->rot[1];
        Actor_Move((Actor *)self, 0);
        if (VEC_Distance(&self->pos, &plpos) > 0x1000) {
            return;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        if (self->kind == 0x5423) {
            self->unk_9c = 0x4cd;
        } else {
            self->unk_9c = speed;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        self->unk_f0 |= 1;
        break;
    }
    case 3:
        Actor_Move((Actor *)self, 0);
        self->pos.y = plpos.y + 0x2000;
        Actor_TurnToPos(self, &plpos, 0x19a);
        self->unk_98 = self->rot[1];
        self->unk_84 = plpos;
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        {
            s32 se = 0x80;
            if (self->kind == 0x5423) {
                se = 0xa;
            }
            func_02049f44(data_02097e4c, se, &self->pos, 0);
        }
        self->unk_40->timer = 0x1e;
        break;
    }
}

}
}  // namespace m_021ffff4

// ---- merged from ov009_022009c8.cpp
namespace m_022009c8 {
extern "C" {

extern void *data_02097e4c;
extern u8 data_ov009_02215dc0[];
extern void *data_ov009_02216d20;
extern char data_ov009_02216b89[];
extern char data_ov009_02216b90[];
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern Ov009Actor *func_ov000_02192b24(void *desc);
extern s32 func_ov000_021909a8(Ov009Sub38 *m, const char *a, const char *b);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
extern void func_ov009_021ff690(Ov009Actor *self);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

struct Ov009SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

void func_ov009_022009c8(Ov009ActVt_02217128 *self) {
    Ov009Vec t;
    Ov009Vec d;
    u8 msg;
    Ov009Actor *a;
    switch (self->unk_40->state) {
    case 0:
        if (self->kind == 0x5423) {
            self->unk_84 = self->unk_f8;
            msg = 2;
            a = func_ov000_0219bf90();
            if (a != NULL) {
                Actor_SendMsg((Actor *)a, self->id, 0xc, TRUE, 1, &msg);
            }
        }
        func_01ffc9fc(&t, data_ov009_02215dc0, 0x5554);
        VEC_Add(&self->unk_84, &t, &t);
        self->unk_b8 = t;
        func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 1:
        t = self->unk_b8;
        d.x = t.x - self->pos.x;
        d.y = t.y - self->pos.y;
        d.z = t.z - self->pos.z;
        VEC_MultAdd(0x29, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &t) <= 0x1000) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

#pragma force_active on
Ov009Act_02200b48 *Ov009Act_02200b48_Ctor(Ov009Act_02200b48 *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = &data_ov009_02216d20;
    MIi_CpuClear32(0, &FLD(u8, self, 0xf8), 0x34);
    return self;
}
#pragma force_active reset

void Ov009Act_02200b48_Init(Ov009Act_02200b48 *self) {
    Ov009SpawnDesc desc;
    Ov009Actor *o;
    s32 i;
    u8 *p;
    func_ov003_021d0fc0(self);
    self->unk_f4 = 0xffff;
    desc.kind = 0x408f;
    desc.flags = 0x4000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    o = func_ov000_02192b24(&desc);
    if (o != NULL) {
        self->unk_f4 = o->id;
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->v04();
        ((Ov009Byte *)&FLD(u8, o, 0x16))->b0 = 1;
        if (o->unk_4c != NULL) {
            o->unk_4c->target = self->id;
        }
    }
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *b = (Ov009Byte *)(p + 0xa2);
        b->b0 = 0;
        b->b5 = 1;
    }
}

void Ov009Act_02200b48_Start(Ov009Act_02200b48 *self) {
    Ov009Sub38 *m;
    func_ov003_021d112c(self);
    FLD(s32, self, 0xf8) = func_ov000_021909a8(self->unk_38, data_ov009_02216b89, data_ov009_02216b90);
    MTX_Identity43_((MtxFx43 *)(&self->unk_fc));
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov009_021ff690);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0xf8);
    self->unk_f0 = 0;
    self->unk_f6 = 0x1000;
}

void Ov009Act_02200b48_Update(Ov009Act_02200b48 *self) {
    if (self->unk_f0 & 1) {
        self->unk_ee_7 = 1;
    } else {
        self->unk_ee_7 = 0;
    }
    func_ov003_021d1e8c(self);
}

extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov003_021d3008(Ov009Actor *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

struct Ov009EaBits {
    u16 b0 : 3;
    u16 b3 : 8;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 b14 : 2;
};

struct Ov009PosMsg {
    Ov009Vec pos;
    u16 rot[3];
    u32 unk_14;
};

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov009Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

void func_ov009_02200d00(Ov009Act_02200b48 *self) {
    Ov009PosMsg msg;
    u8 mtx[0x30];
    Ov009Actor *a;
    u32 zero = 0;
    s16 t;
    if (!(self->unk_f0 & 1)) {
        u16 *p = self->unk_50;
        u16 v = self->unk_b0->unk_08;
        if (*p < v) {
            *p = v;
            self->unk_40->flags = zero;
            func_ov000_02198360(self->unk_40, 0x11, zero);
        }
        ((Ov009EaBits *)&self->unk_ea)->b11 = 0;
        a = Ov009_FindActor(self->unk_f4);
        if (a != NULL) {
            if (Ov009_Mode(a) == 9) {
                Ov009Sub44 *s = self->unk_44;
                if (!(s->unk_22_0 == 1 && s->unk_22_1 == 1)) {
                    s->unk_22_0 = 1;
                    s->unk_22_1 = 1;
                }
                func_ov000_02190cb0(self->unk_38, data_ov009_02215d34, 0x1000, zero);
                Ov009Pair_SetB((Ov009Pair *)&self->unk_50[4], 0x31);
                func_ov000_02198360(self->unk_40, 0x13, zero);
            } else {
                if (((Ov009EaBits *)&self->unk_ea)->b13) {
                    MI_Copy48B(&self->unk_fc, mtx);
                    Actor_SendMsg((Actor *)a, self->id, 8, TRUE, 0x30, mtx);
                    msg.pos = self->unk_120;
                } else {
                    msg.pos = self->pos;
                }
                msg.rot[0] = self->rot[0];
                msg.rot[1] = self->rot[1];
                msg.rot[2] = self->rot[2];
                msg.unk_14 = zero;
                Actor_SendMsg((Actor *)a, self->id, 7, TRUE, 0x18, &msg);
                ((Ov009EaBits *)&self->unk_ea)->b0 = 3;
                goto tail;
            }
        }
        self->unk_f4 = 0xffff;
        self->unk_f0 |= 1;
        self->unk_f6 = 0x1800;
    }
tail:
    func_ov003_021d3008(self);
    if (!(self->unk_f0 & 1)) {
        self->unk_94_1 = 1;
    }
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        return;
    }
    if (!(self->unk_48->unk_50 & 0x400)) {
        return;
    }
    t = self->unk_1a + 1;
    if (t % 20 == 0) {
        t = 0;
        func_02065f88(0x2bd, &self->pos)->v0c(FX_Mul(self->unk_38->scale.x, 0x199a));
    }
    self->unk_1a = t;
}

}
}  // namespace m_022009c8

// ---- merged from ov009_02200fd4.cpp
namespace m_02200fd4 {
extern "C" {

extern void *data_02097e4c;
extern void func_ov000_021911c8(Ov009Sub38 *m, s32 a);
extern void Actor_MoveToPos(Ov009Actor *self, Ov009Vec *v, s32 a);
extern void *func_ov000_02191318(Ov009Sub38 *m, s32 a);
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern BOOL func_ov000_0218fa28(Ov009Sub38 *m, void *a, void *b, void *c, const void *anim, s32 d, s32 e);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov009_0220189c(Ov009ActVt_0221707c *self);
extern void func_ov009_02201eac(Ov009ActVt_0221707c *self);

void func_ov009_02200fd4(Ov009Act_02200b48 *self) {
    Ov009Vec v;
    s32 a;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d2c, 0x400, 0);
        func_ov000_021911c8(self->unk_38, ((s16)self->unk_f6));
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    self->unk_48->unk_9a_5 = 1;
    a = self->unk_b0->unk_00;
    self->unk_9c = a;
    if ((self->unk_f0 & 1) && !(self->unk_48->unk_50 & 0x400)) {
        self->unk_9c = a << 1;
    }
    v = self->unk_b8;
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        func_ov000_02198360(self->unk_40, 4, 0);
    }
}

void func_ov009_022010f0(Ov009Act_02200b48 *self) {
    switch (self->unk_40->state) {
    case 0:
        self->unk_f2 = Rand_UpTo(0xf);
        break;
    case 1:
        if (self->unk_f2++ == 0x2d) {
            func_ov000_02191318(self->unk_38, 0x10000);
        }
        break;
    }
    func_ov003_021d4b68(self);
}


extern void func_ov000_02191780(Ov009Sub38 *m);
extern void ActorMgr_SendMsg(u16 a, u16 b, s32 c, s32 d, s32 e, u8 *f);

static inline void Ov009_Msg(Ov009Act_02200b48 *self, u8 v) {
    u8 f = v;
    ActorMgr_SendMsg(self->unk_f4, self->kind, 6, 1, 1, &f);
}

void func_ov009_02201150(Ov009Act_02200b48 *self) {
    Ov009Actor *a;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d28, 0x400, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        {
            u16 id = self->unk_f4;
            a = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        if (a != NULL) {
            Ov009Sub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
            q = a->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
            Ov009_Msg(self, 0);
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        } else {
            Ov009Sub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
            self->unk_f4 = 0xffff;
            self->unk_f0 |= 1;
            self->unk_f6 = 0x1800;
        }
    case 0x1e: {
        Ov009Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer == 0x96) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d28, 0x1000, 0);
            func_ov000_02191780(self->unk_38);
            {
                Ov009Sub44 *q = self->unk_44;
                q->unk_22_0 = 1;
                q->unk_22_1 = 1;
            }
            {
                u16 id = self->unk_f4;
                a = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
            }
            if (a != NULL) {
                Ov009Sub44 *q = a->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
                Ov009_Msg(self, 1);
            } else {
                self->unk_f4 = 0xffff;
                self->unk_f0 |= 1;
                self->unk_f6 = 0x1800;
            }
        } else if (w->timer >= 0xa5) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    }
}

}
}  // namespace m_02200fd4

// ---- merged from ov009_022013ac.cpp
namespace m_022013ac {
extern "C" {

extern void *data_02097e4c;
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern BOOL func_ov000_0218fa28(Ov009Sub38 *m, void *a, void *b, void *c, const void *anim, s32 d, s32 e);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov009_0220189c(Ov009ActVt_0221707c *self);
extern void func_ov009_02201eac(Ov009ActVt_0221707c *self);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_022013ac(Ov009Act_02200b48 *self) {
    Ov009Actor *a = Ov009_FindActor(self->unk_f4);
    if (a != NULL) {
        func_ov000_0218d46c(a, self->unk_f4, 0x15);
        self->unk_f4 = 0xffff;
    }
    func_ov003_021d6054(self);
}

static inline void Ov009_PlayAnim(Ov009Sub38 *m, const void *anim) {
    if (FLD(void *, m, 0x1c) != NULL) {
        func_ov000_0218fa28((Ov009Sub38 *)FLD(void *, m, 0x1c), &FLD(u8, m, 0x24), FLD(u8 *, m, 0), FLD(void *, FLD(u8 *, FLD(u8 *, m, 0), 0x48), 0x10), anim, 0x1000, 0);
    }
}

void func_ov009_02201400(Ov009ActVt_0221707c *self) {
    Ov009Sub38 *m = self->unk_38;
    const char *anim = self->unk_f4 != 0 ? data_ov009_02215d24 : data_ov009_02215d3c;
    Ov009_PlayAnim(m, anim);
    func_ov003_021d1b88(self);
}

}
}  // namespace m_022013ac

// ---- merged from ov009_02201470.cpp
namespace m_02201470 {
extern "C" {

extern void *data_02097e4c;
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern BOOL func_ov000_0218fa28(Ov009Sub38 *m, void *a, void *b, void *c, const void *anim, s32 d, s32 e);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov009_0220189c(Ov009ActVt_0221707c *self);
extern void func_ov009_02201eac(Ov009ActVt_0221707c *self);

void Ov009ActVt_0221707c_Init(Ov009ActVt_0221707c *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5047:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        self->unk_1a = 0;
        break;
    case 0x503f:
    case 0x5048:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        self->unk_1a = 1;
        break;
    case 0x5035:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        self->unk_1a = 2;
        break;
    case 0x5054:
        func_ov000_02187a20(data_ov000_021ccd54, 0x10);
        self->unk_1a = 3;
        break;
    }
    self->unk_ea_10 = 1;
    self->unk_108 = -1;
}

void Ov009ActVt_0221707c_Start(Ov009ActVt_0221707c *self) {
    u32 *p;
    func_ov003_021d112c(self);
    p = (u32 *)Heap_Alloc(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(u32 *, self, 0x104) = p;
    self->unk_f0 = 0;
    switch (self->kind) {
    case 0x503f:
    case 0x5048:
        self->unk_f5 = 0;
        self->unk_f2 = 0x78;
        break;
    case 0x5035:
    case 0x5047:
    case 0x5054:
        self->unk_f5 = 1;
        switch (self->kind) {
        case 0x5047:
            self->unk_f2 = 0x78;
            break;
        case 0x5035:
            self->unk_f2 = 0x96;
            break;
        case 0x5054:
            self->unk_f2 = 0x50;
            break;
        }
        self->unk_c8 = 0x16000;
        self->unk_cc = 0xc000;
        break;
    }
}

extern u8 data_ov009_02215dd8[];
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020639d4(void *p, s32 a, s32 b);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov003_021daa0c(void *mgr, s32 id);
extern void func_ov003_021da9ac(void *mgr, s32 id, void *obj);
extern void func_ov003_021daa6c(void *mgr, s32 id);
extern void func_ov003_021daae4(void *mgr, s32 id, const Ov009Vec *pos, s32 a, s32 b, const void *c, s32 d);
extern void func_ov003_021dacfc(void *mgr);
void Ov009ActVt_0221707c_Update(Ov009ActVt_0221707c *self) {
    Ov009V *obj;
    Ov009Vec v;
    func_ov003_021d1e8c(self);
    if (self->unk_f4 != 0) {
        self->unk_94_1 = 1;
        if (self->unk_f5 == 1) {
            if (!func_ov003_021daa0c(self->unk_104, 0xfd)) {
                if (self->unk_40->unk_13 != 0x15) {
                    obj = func_02065f88(0x322, &self->pos);
                    obj->v20(data_ov009_02215dd8);
                    obj->v0c(0xccd);
                    FLD(s32, obj, 0xc8) = -1;
                    func_020639d4(obj, 0x78, 0);
                    func_ov003_021da9ac(self->unk_104, 0xfd, obj);
                }
            } else {
                func_ov003_021daae4(self->unk_104, 0xfd, &self->pos, 0, 0, data_ov009_02215dd8, 0);
            }
            if (self->unk_40->unk_13 != 0xf && func_ov003_021daa0c(self->unk_104, 0xfb)) {
                func_ov003_021daa6c(self->unk_104, 0xfb);
                SndMgr_StopSeqArc(data_02097e4c, self->unk_108);
                self->unk_108 = -1;
            }
            if (func_ov003_021daa0c(self->unk_104, 0xfa)) {
                v = func_ov000_0219bf90()->pos;
                func_ov003_021daae4(self->unk_104, 0xfa, &v, 0, 0, 0, 0);
            }
        }
    } else if (self->unk_f5 == 1 && func_ov003_021daa0c(self->unk_104, 0xfd)) {
        func_ov003_021daa6c(self->unk_104, 0xfd);
    }
    func_ov003_021dacfc(self->unk_104);
}

}
}  // namespace m_02201470

// ---- merged from ov009_02201848.cpp
namespace m_02201848 {
extern "C" {

extern void func_ov009_0220189c(Ov009ActVt_0221707c *self);
extern void func_ov009_02201eac(Ov009ActVt_0221707c *self);

void func_ov009_02201848(Ov009ActVt_0221707c *self) {
    if (self->unk_40->state == 0) {
        self->unk_f0 = 0;
        self->unk_f4 = 1;
    }
    func_ov003_021d3524(self);
}

void func_ov009_02201870(Ov009ActVt_0221707c *self) {
    switch (self->unk_f5) {
    case 0:
        func_ov009_0220189c(self);
        break;
    case 1:
        func_ov009_02201eac(self);
        break;
    }
}

}
}  // namespace m_02201848

// ---- merged from ov009_0220189c.cpp
namespace m_0220189c {
struct Ov009Rot {
    u16 x, y, z;
};

extern "C" {

extern void *data_02097e4c;
extern s32 data_ov009_02215e14[];
extern Ov009Vec data_ov009_02215de4;
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_01ffc9fc(Ov009Vec *dst, const Ov009Vec *src, u16 angle);
extern void func_ov003_021da9ac(void *mgr, s32 id, void *obj);
extern void func_ov003_021daa6c(void *mgr, s32 id);
extern void func_ov003_021daae4(void *mgr, s32 id, const Ov009Vec *pos, const void *a, s32 b, const void *c, const void *d);
extern s32 func_02049afc(void *mgr, s32 id);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void Actor_TurnToPos(Ov009Actor *self, Ov009Vec *v, s32 a);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);

static inline void Ov009_VSet(Ov009Vec *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
void func_ov009_0220189c(Ov009ActVt_0221707c *self) {
    Ov009Vec v;
    Ov009Rot r;
    Ov009V *o;
    u16 tm;
    Ov009Actor *t;
    t = Actor_GetTarget(self);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c, 0x400, 0);
        self->unk_f4 = 1;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        if (self->unk_38->anim_state == 1) {
            func_02049f44(data_02097e4c, data_ov009_02215e14[self->unk_1a], &self->pos, 0);
            self->unk_40->state++;
        }
        break;
    case 2:
        if (self->unk_38->anim_state == 2) {
            o = func_02065f88(0x25a, &self->pos);
            o->v30(self->rot);
            func_01ffc9fc(&v, &data_ov009_02215de4, self->rot[1]);
            o->v20(&v);
            o->v0c(0x1800);
            func_ov003_021da9ac(self->unk_104, 0xff, o);
            self->unk_108 = func_02049afc(data_02097e4c, 0x4c);
            self->unk_40->state++;
        }
        break;
    case 3: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        tm = st->timer;
        if (tm % 50 == 0 || tm == 1) {
            v.x = 0x3000;
            v.y = 0;
            v.z = 0x3000;
            self->unk_f0 ^= 4;
            if (self->unk_f0 & 4) {
                v.x = -v.x;
            }
            func_01ffc9fc(&v, &v, self->rot[1]);
            VEC_Add(&self->pos, &v, &self->unk_84);
        }
        Actor_TurnToPos(self, &self->unk_84, 0x52);
        func_ov003_021daae4(self->unk_104, 0xff, &self->pos, self->rot, 0, &data_ov009_02215de4, self->rot);
        if (*func_ov000_0219bf90()->unk_50 != 0) {
            r.x = self->rot[0];
            r.y = self->rot[1];
            r.z = self->rot[2];
            r.x += 0x4000;
            func_ov000_0219aae8(self, self, self->unk_f2, self->unk_4c->unk_0a, 2, &data_ov009_02215de4, &r, 0x99a, 0x6000, 0x258, 0x2800);
        }
        if (t->unk_50 != NULL && *t->unk_50 == 0) {
            tm = 200;
        }
        if (!Ov009_GameIdle()) {
            tm = 200;
        }
        if (tm >= 200) {
            u8 i;
            func_ov003_021daa6c(self->unk_104, 0xff);
            SndMgr_StopSeqArc(data_02097e4c, self->unk_108);
            self->unk_108 = -1;
            func_ov000_02191690(self->unk_38);
            for (i = 0; i < 2; i++) {
                o = func_02065f88(0x25e, &self->pos);
                o->v34(0x8aaa, self->rot[1], 0);
                v.x = 0x1000;
                v.y = 0x4000;
                v.z = 0xb33;
                if (i == 1) {
                    v.x = -v.x;
                }
                func_01ffc9fc(&v, &v, self->rot[1]);
                o->v20(&v);
                func_ov003_021da9ac(self->unk_104, 0xfe, o);
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 4: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer == 100) {
            func_ov003_021daa6c(self->unk_104, 0xfe);
            func_ov000_02191708(self->unk_38);
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            o = func_02065f88(0x12f, &self->pos);
            o->v24(0, 0x2000, 0);
            o->v0c(0x99a);
            self->unk_f4 = 0;
            func_02049f44(data_02097e4c, 0x73, &self->pos, 0);
        } else if (st->timer == 300) {
            void *m = self->unk_38;
            self->unk_f8 = FLD(s32, m, 0xa8);
            self->unk_fc = FLD(s32, m, 0xac);
            self->unk_100 = FLD(s32, m, 0xb0);
            self->unk_f4 = 1;
            o = func_02065f88(0x12f, &self->pos);
            o->v24(0, 0x2000, 0);
            o->v0c(0x99a);
            {
                s32 a = FX_Mul(self->unk_f8, 0x14cd);
                s32 b = self->unk_fc;
                void *mm = self->unk_38;
                FLD(s32, mm, 0xa8) = a;
                FLD(s32, mm, 0xac) = b;
                FLD(s32, mm, 0xb0) = a;
            }
            func_02049f44(data_02097e4c, 0x72, &self->pos, 0);
            self->unk_40->state = 0x1e;
        }
        break;
    }
    case 0x1e: {
        s32 x = self->unk_38->scale.x;
        if (x > self->unk_f8) {
            x -= 0x19a;
            if (x <= self->unk_f8) {
                x = self->unk_f8;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            Ov009_VSet(&self->unk_38->scale, x, self->unk_fc, x);
        }
        break;
    }
    }
    if ((s32)self->unk_40->state >= 1) {
        self->unk_ea_0 = 3;
    }
}

extern Ov009Vec data_ov009_02215dd8;
extern void *data_0214a420;
extern BOOL func_ov003_021daa0c(void *mgr, s32 id);
extern s32 func_ov003_021daa3c(void *mgr, s32 id);
extern Ov009V *func_020657b0(void *mgr, s32 h);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern s32 func_ov000_0219a510(Ov009Obj *self, u16 mask, Ov009Vec *pos, s32 r, s32 a, Ov009Actor **list);
extern Ov009Actor *func_ov000_021985c0(Ov009Actor *p);
extern Ov009Actor *Target_Get(void *p);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);

struct Ov009B24 {
    u32 b0 : 5;
    u32 b5 : 2;
    u32 b7 : 25;
};

void func_ov009_02201eac(Ov009ActVt_0221707c *self) {
    Ov009Actor *list[32];
    Ov009Vec v;
    Ov009Vec w;
    Ov009V *o;
    Ov009Sub38 *m;
    s32 i;
    s32 n;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c, 0x400, 0);
        self->unk_f4 = 1;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        if (self->unk_38->anim_state != 1) {
            return;
        }
        o = func_02065f88(0x5e2, &self->pos);
        o->v20(&data_ov009_02215dd8);
        func_ov003_021da9ac(self->unk_104, 0xfc, o);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    case 2:
        if (func_ov003_021daa0c(self->unk_104, 0xfc)) {
            return;
        }
        func_02049f44(data_02097e4c, data_ov009_02215e14[self->unk_1a], &self->pos, 0);
        o = func_02065f88(0x321, &self->pos);
        o->v20(&data_ov009_02215d78);
        o->v0c(0x19a);
        FLD(s32, o, 0x7c) = FX_Div(0x10000, 0x1f000);
        func_ov003_021da9ac(self->unk_104, 0xfb, o);
        self->unk_40->state++;
        return;
    case 3: {
        s32 a;
        o = func_020657b0(data_0214a420, func_ov003_021daa3c(self->unk_104, 0xfb));
        if (o == NULL) {
            return;
        }
        a = FLD(s32, o, 0x40);
        o->v0c(a + 0x666);
        if (a + 0x666 < 0x3333) {
            return;
        }
        self->unk_108 = func_02049afc(data_02097e4c, 0x76);
        m = self->unk_38;
        FLD(u16, m, 0xb6) = 0x7c00;
        FLD(u16, m, 0xb8) = 0x7c00;
        FLD(u16, m, 0xba) = 0xc9;
        FLD(u16, m, 0xbc) = 0xc8;
        m = self->unk_38;
        m->unk_c2_9 = 2;
        NNSi_G3dModifyPolygonAttrMask(m->unk_04, 0, 0xc0);
        self->unk_40->state++;
        return;
    }
    case 4:
        if (*func_ov000_0219bf90()->unk_50 != 0 && Ov009_GameIdle()) {
            if (func_ov000_0219aae8(self, self, self->unk_f2, self->unk_4c->unk_0a, 2, &data_ov009_02215d78, NULL, 0x4ccd, 0, 0x322, 0xccd)) {
                v = func_ov000_0219bf90()->pos;
                func_02049f44(data_02097e4c, 0x77, &v, 0);
            }
        } else {
            self->unk_40->timer = 200;
            m = self->unk_38;
            FLD(u16, m, 0xb6) = 0x7c00;
            FLD(u16, m, 0xb8) = 0x7c00;
            FLD(u16, m, 0xba) = 2;
            FLD(u16, m, 0xbc) = 1;
        }
        {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 200) {
            func_ov003_021daa6c(self->unk_104, 0xfb);
            SndMgr_StopSeqArc(data_02097e4c, self->unk_108);
            self->unk_108 = -1;
            o = func_02065f88(0x69, &self->pos);
            o->v20(&data_ov009_02215d78);
            o->v0c(0x2000);
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            m = self->unk_38;
            m->unk_c2_9 = 3;
            NNSi_G3dModifyPolygonAttrMask(m->unk_04, 1, 0xc0);
            self->unk_f4 = 0;
            func_02049f44(data_02097e4c, 0x73, &self->pos, 0);
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        }
        }
        VEC_Add(&self->pos, &data_ov009_02215d78, &w);
        n = func_ov000_0219a510(self, 0x10, &w, 0x4ccd, 0, list);
        if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov009Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
                Ov009Target *s = q->unk_4c;
                if (s != NULL && (u8)(s->unk_02 + 0xff) <= 1) {
                    Ov009Actor *b = Target_Get(s);
                    if (b != NULL && b->kind == 0x1000 && FLD(Ov009B24, func_ov000_0219bf90(), 0xb24).b5 == 0) {
                        func_ov000_0218d46c(q, q->id, 0x15);
                    }
                }
            }
        }
        }
        return;
    case 0x1e: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 300) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        return;
    }
    }
}

}
}  // namespace m_0220189c

// ---- merged from ov009_0220244c.cpp
namespace m_0220244c {
extern "C" {

extern void *data_02097e4c;
extern void func_ov003_021daab0(void *p);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void func_ov003_021d3d28(Ov009Actor *self);
extern void func_ov000_02191618(Ov009Sub38 *m);
extern void func_ov003_021d4fd8(Ov009Actor *self);
extern void *data_ov009_02216e78;
extern char data_ov009_02216b98[];
extern void *data_02097cdc;
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern BOOL func_02035b90(const char *name, s32 a);
extern void func_02036838(void *mgr, const char *name, s32 a, s32 b);
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void HitMesh_Link(void *p);
extern void *func_ov000_0219bf90(void);

static inline void Ov009_StopEffect(Ov009ActVt_0221707c *self) {
    Ov009Sub38 *m;
    self->unk_f4 = 0;
    func_ov003_021daab0(self->unk_104);
    SndMgr_StopSeqArc(data_02097e4c, self->unk_108);
    self->unk_108 = -1;
    m = self->unk_38;
    m->unk_c2_9 = 3;
    NNSi_G3dModifyPolygonAttrMask(m->unk_04, 1, 0xc0);
}

void func_ov009_0220244c(Ov009ActVt_0221707c *self) {
    if (self->unk_40->state == 0) {
        self->unk_f4 = 1;
    }
    func_ov003_021d3600(self);
}

void func_ov009_0220246c(Ov009ActVt_0221707c *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
    }
    func_ov003_021d5900(self);
    if (self->unk_40->unk_13 == 4) {
        self->unk_f0 |= 0x800;
    }
}

void func_ov009_022024f8(Ov009ActVt_0221707c *self) {
    func_ov003_021d3d28(self);
    if (self->unk_40->state < 1) {
        return;
    }
    if (!(self->unk_f0 & 0x800)) {
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov009_02215d20, 0x1000, 0);
    self->unk_f4 = 0;
    func_ov000_02191618(self->unk_38);
    if (self->unk_40->state == 2) {
        self->unk_f0 = 0;
    }
}

void func_ov009_02202560(Ov009ActVt_0221707c *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
        self->unk_64 >>= 2;
    }
    func_ov003_021d6054(self);
}

void func_ov009_022025e0(Ov009ActVt_0221707c *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
    }
    func_ov003_021d4fd8(self);
}

void func_ov009_02202654(Ov009ActVt_0221707c *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
    }
    func_ov003_021d5348(self);
}

void func_ov009_022026c8(Ov009Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_02070558(res);
    const char *s;
    char *t;
    STD_CopyString(self->mdlDir, a);
    STD_CopyString(self->mdlName, b);
    self->ownMdl = 1;
    s = data_ov009_02215d10;
    STD_CopyString(self->anmDir, s);
    STD_CopyString(self->anmName, data_ov009_02215d14);
    self->ownAnm = 1;
    t = FLD(char *, c, 0x28);
    if (t != NULL) {
        STD_CopyString(self->evDir, s);
        STD_CopyString(self->evName, t);
        self->ownEv = 1;
    }
    self->unk_00 = 0;
}

#pragma force_active on
Ov009Act_02202788 *Ov009Act_02202788_Ctor(Ov009Act_02202788 *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = &data_ov009_02216e78;
    MIi_CpuClear32(0, &FLD(u8, self, 0xf8), 0x34);
    return self;
}
#pragma force_active reset

Ov009Act_02202788 *Ov009Act_02202788_Dtor(Ov009Act_02202788 *self) {
    FLD(void *, self, 0) = &data_ov009_02216e78;
    if (self->kind == 0x5055 && func_02035b90(data_ov009_02216b98, 7)) {
        func_02036838(data_02097cdc, data_ov009_02216b98, 7, 0);
    }
    func_ov003_021d0edc(self);
    return self;
}

Ov009Act_02202788 *Ov009Act_02202788_DtorDelete(Ov009Act_02202788 *self) {
    FLD(void *, self, 0) = &data_ov009_02216e78;
    if (self->kind == 0x5055 && func_02035b90(data_ov009_02216b98, 7)) {
        func_02036838(data_02097cdc, data_ov009_02216b98, 7, 0);
    }
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

BOOL Ov009Act_02202788_Draw(Ov009Act_02202788 *self) {
    BOOL r = func_ov003_021d16cc(self);
    self->unk_1e = r ? 1 : 0;
    return r;
}

}
}  // namespace m_0220244c

// ---- merged from ov009_022028c8.cpp
namespace m_022028c8 {
extern "C" {

extern void *data_02097e4c;
extern char data_ov009_02216b98[];
extern Ov009Actor *func_ov000_02192b24(void *desc);
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void *func_020359d0(const char *name, s32 a, s32 b);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
void func_ov009_022026c8(Ov009Names *self, void *res);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

struct Ov009SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
    Ov009SpawnDesc() {
        s32 i;
        kind = 0xffff;
        flags = 0xf000;
        for (i = 0; i < 4; i++) {
            unk_04[i] = 0;
        }
    }
};

void Ov009Act_02202788_Init(Ov009Act_02202788 *self) {
    Ov009Names *n;
    Ov009Actor *o;
    u8 *p;
    u16 kind;
    char *a;
    char *b;
    u32 k;
    if (self->kind == 0x5055) {
        self->unk_d8 = (void *)func_ov009_022026c8;
    }
    func_ov003_021d0fc0(self);
    kind = self->kind;
    a = func_0207011c((void *)kind);
    b = func_020701d4((void *)kind);
    n = ((Ov009Names *)self->unk_34);
    STD_CopyString(&FLD(char, n, 0x88), a);
    STD_CopyString(&FLD(char, n, 0xa8), b);
    n->unk_03_3 = 1;
    ((Ov009Names *)self->unk_34)->unk_00 = 0;
    k = 0x4083;
    if (self->kind == 0x5055) {
        k += 0x13;
    }
    {
        Ov009SpawnDesc desc;
        desc.parent = -1;
        desc.kind = k;
        desc.flags = k & 0xf000;
        o = func_ov000_02192b24(&desc);
    }
    if (o != NULL) {
        self->unk_f0 = o->id;
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->v04();
        ((Ov009Byte *)&FLD(u8, o, 0x16))->b0 = 1;
        if (o->unk_4c != NULL) {
            o->unk_4c->target = self->id;
        }
    }
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *bb = (Ov009Byte *)(p + 0xa2);
        bb->b0 = 0;
        bb->b5 = 1;
    }
    if (self->kind == 0x5055) {
        func_020359d0(data_ov009_02216b98, 7, 0);
    }
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5049:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        self->unk_1a = 0;
        break;
    case 0x5055:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        self->unk_1a = 1;
        break;
    }
}

}
}  // namespace m_022028c8

// ---- merged from ov009_02202acc.cpp
namespace m_02202acc {
extern "C" {

extern char data_ov009_02216b98[];
extern BOOL func_02035b90(const char *name, s32 a);
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void HitMesh_Link(void *p);

BOOL Ov009Act_02202788_IsReady(Ov009Act_02202788 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->kind == 0x5055) {
        r = (r & func_02035b90(data_ov009_02216b98, 7)) ? TRUE : FALSE;
    }
    return r;
}

void func_ov009_02202b14(Ov009Act_02202788 *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
    if (self->unk_58 != NULL) {
        HitMesh_Link(self->unk_58);
    }
}

extern char data_ov009_02216ba7[];
extern void func_0203f80c(void *p);
extern void HitMesh_SetRes(void *p, s32 v);
extern void HitMesh_SetScale(void *p, s32 v);
extern s32 func_ov000_021909a8(Ov009Sub38 *m, const char *a, const char *b);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
extern void func_ov009_021ff690(Ov009Actor *self);
extern u8 *func_0206fef8(void *res);
extern void HitMesh_SetMtx(void *mesh, const void *mtx);
struct Ov009Mtx43 {
    s32 m[9];
    Ov009Vec t;
};

void Ov009Act_02202788_Start(Ov009Act_02202788 *self) {
    Ov009Sub38 *m;
    u8 *c;
    u32 *o;
    u32 v;
    func_ov003_021d112c(self);
    {
        Ov009Sub48 *s48 = self->unk_48;
        s48->unk_5c = 0;
        s48->unk_60 = 0x1800;
        s48->unk_64 = 0;
    }
    FLD(s32, self, 0xf8) = func_ov000_021909a8(self->unk_38, func_020701d4((void *)self->kind), data_ov009_02216ba7);
    MTX_Identity43_((MtxFx43 *)(&self->unk_fc));
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov009_021ff690);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0xf8);
    {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    self->unk_ea_6 = 1;
    c = func_0206fef8((void *)self->kind);
    o = FLD(u32 *, self->unk_34, 0x84);
    v = o != NULL ? *o : 0;
    if (v != 0) {
        void *p = Heap_Alloc(0x98);
        if (p != NULL) {
            func_0203f80c(p);
        }
        self->unk_58 = p;
        o = FLD(u32 *, self->unk_34, 0x84);
        HitMesh_SetRes(self->unk_58, o != NULL ? *o : 0);
        HitMesh_SetScale(self->unk_58, FLD(s16, c, 0x10));
        {
            void *obj;
            Ov009Mtx43 t;
            Ov009Mtx43 mt;
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot[2];
            obj = self->unk_58;
            ry = self->rot[1];
            rx = self->rot[0];
            MTX_Identity43_((MtxFx43 *)&mt);
            if (rz != 0) {
                MTX_RotZ43_((MtxFx43 *)&mt, OV009_SIN(rz), OV009_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY43_((MtxFx43 *)&t, OV009_SIN(ry), OV009_COS(ry));
                    MTX_Concat43((MtxFx43 *)&t, (MtxFx43 *)&mt, (MtxFx43 *)&mt);
                } else {
                    MTX_RotY43_((MtxFx43 *)&mt, OV009_SIN(ry), OV009_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX43_((MtxFx43 *)&t, OV009_SIN(rx), OV009_COS(rx));
                    MTX_Concat43((MtxFx43 *)&t, (MtxFx43 *)&mt, (MtxFx43 *)&mt);
                } else {
                    MTX_RotX43_((MtxFx43 *)&mt, OV009_SIN(rx), OV009_COS(rx));
                    set = TRUE;
                }
            }
            mt.t.x = self->pos.x;
            mt.t.y = self->pos.y;
            mt.t.z = self->pos.z;
            HitMesh_SetMtx(obj, &mt);
        }
    }
    self->unk_cc = 0xc000;
}

}
}  // namespace m_02202acc

// ---- merged from ov009_02202db4.cpp
namespace m_02202db4 {
extern "C" {

extern void *func_ov000_0219bf90(void);

void Ov009Act_02202788_Update(Ov009Act_02202788 *self) {
    u16 *p;
    u16 v;
    Ov009Sub38 *m;
    func_ov003_021d1e8c(self);
    if (!self->unk_93_4) {
        return;
    }
    func_ov000_0219bf90();
    p = self->unk_50;
    v = self->unk_b0->unk_08;
    if (*p >= v) {
        return;
    }
    *p = v;
    m = self->unk_38;
    FLD(u16, m, 0xb6) = 0x14bf;
    FLD(u16, m, 0xb8) = 0x14bf;
    FLD(u16, m, 0xba) = 1;
    FLD(u16, m, 0xbc) = 0;
}

extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void HitMesh_SetMtx(void *mesh, const void *mtx);
extern void func_ov003_021d3008(Ov009Actor *self);
static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov009Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

struct Ov009PosMsg {
    Ov009Vec pos;
    u16 rot[3];
    u32 unk_14;
};

void func_ov009_02202e18(Ov009Act_02202788 *self) {
    Ov009PosMsg msg;
    u8 mtx[0x30];
    Ov009Actor *a;
    func_ov003_021d3008(self);
    a = Ov009_FindActor(self->unk_f0);
    if (a == NULL || Ov009_Mode(a) == 9) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
    if (a == NULL || self->unk_40->unk_13 == 0x15) {
        return;
    }
    if (self->unk_58 != NULL) {
        HitMesh_SetMtx(self->unk_58, &self->unk_fc);
    }
    if (Ov009_Mode(a) != 1) {
        return;
    }
    if (self->unk_1e == 0) {
        return;
    }
    msg.pos = self->unk_120;
    msg.rot[0] = self->rot[0];
    msg.rot[1] = self->rot[1];
    msg.rot[2] = self->rot[2];
    msg.unk_14 = 0;
    Actor_SendMsg((Actor *)a, self->id, 7, TRUE, 0x18, &msg);
    MI_Copy48B(&self->unk_fc, mtx);
    Actor_SendMsg((Actor *)a, self->id, 8, TRUE, 0x30, mtx);
}

}
}  // namespace m_02202db4

// ---- merged from ov009_02202f68.cpp
namespace m_02202f68 {
extern "C" {

extern void *data_02097e4c;
extern void *data_0214a420;
extern const Ov009Vec data_ov009_02215db4;
extern u8 data_ov009_02215e60[];
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009V *func_020657b0(void *mgr, s32 h);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov009_0220387c(Ov009Act_02202788 *self);
extern void Actor_TurnToPos(Ov009Actor *self, const Ov009Vec *v, s32 a);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov009_02202f68(Ov009Act_02202788 *self) {
    Ov009Vec tmp;
    Ov009Vec tp;
    Ov009Vec off;
    Ov009Actor *t;
    s32 lim;
    u16 id;
    Ov009V *e;
    u8 *c;
    Ov009Sub40 *st;
    Ov009Actor *a;
    t = Ov009_FindActor(self->unk_90);
    tp.x = t->pos.x;
    tp.y = t->pos.y;
    tp.z = t->pos.z;
    func_01ffc9fc(&off, &data_ov009_02215d84, self->rot[1]);
    st = self->unk_40;
    lim = self->pos.y + self->unk_68;
    switch (st->state) {
    case 0:
        if (self->kind == 0x5055 && tp.y <= lim) {
            e = func_02065f88(0x640, &self->pos);
            e->v0c(0xccd);
            e->v20(&off);
            self->unk_f4 = FLD(s32, e, 0x24);
        }
        func_02049f44(data_02097e4c, 0x46, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        e = func_020657b0(data_0214a420, self->unk_f4);
        if (e != NULL) {
            VEC_Add(&off, &self->pos, &tmp);
            e->v18(&tmp);
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x32) {
            func_02049f44(data_02097e4c, 0x73, &self->pos, 0);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        if (tp.y > lim) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    case 2:
        st->timer++;
        if (st->timer > 10) {
            func_02049f44(data_02097e4c, data_ov009_02215d54[self->unk_1a], &self->pos, 0);
            func_ov000_0218996c(10, 0xf);
            self->unk_40->timer = 0;
            if (self->kind == 0x5055) {
                self->unk_40->state = 10;
            } else {
                self->unk_40->state++;
            }
        }
        break;
    case 3:
        c = func_02070558((void *)self->kind);
        if (c != NULL) {
            u16 *p = (u16 *)(c + 0x3a);
            if (p != NULL) {
                u16 k = *p;
                if (k != 0xffff) {
                    id = k;
                }
                VEC_Add(&off, &self->pos, &tmp);
                a = func_ov003_021d69f0(self, id, &tmp, self->rot, t);
                if (a != NULL) {
                    a->unk_60 = data_ov009_02215e60;
                    func_ov000_0218d46c(a, self->id, 0xb);
                }
            }
        }
        self->unk_40->state = 0x1e;
        break;
    case 10: {
        func_ov000_02191690(self->unk_38);
        func_ov009_0220387c(self);
        tp.x -= self->pos.x;
        tp.y -= self->pos.y;
        tp.z -= self->pos.z;
        func_01ffc9fc(&tp, &tp, (u16)(0xffff - self->rot[1]));
        Ov009Vec v = data_ov009_02215db4;
        if (tp.x <= 0) {
            v.x = Ov009_FxMulL(v.x, -0x1000);
        }
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Add(&v, &self->pos, &v);
        self->unk_84.x = v.x;
        self->unk_84.y = v.y;
        self->unk_84.z = v.z;
        self->unk_40->state++;
    }
    case 11:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xf) {
            Actor_TurnToPos(self, &self->unk_84, 0x3d);
            a = Ov009_FindActor(self->target_id);
            if (a != NULL) {
                a->rot[1] = self->rot[1];
            } else {
                func_ov000_02191708(self->unk_38);
                self->unk_40->state = 0x1e;
            }
        }
        break;
    case 0x1e:
        st->timer++;
        if (st->timer >= 200) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    self->unk_ea_0 = 3;
}

}
}  // namespace m_02202f68

// ---- merged from ov009_02203428.cpp
namespace m_02203428 {
extern "C" {

extern void *data_02097e4c;
extern void *data_0214a420;
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_0203f920(void *p);
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02065804(void *a, s32 b);
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0219b400(void *a, void *b, s32 c, Ov009Vec *pos, u16 *rot, s32 d);
extern void func_ov000_0219b5dc(u16 id, const Ov009Vec *pos, const u16 *rot);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    Ov009Actor *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return a;
}

void func_ov009_02203428(Ov009Act_02202788 *self) {
    Ov009V *e;
    Ov009Actor *a;
    Ov009Sub40 *st;
    u8 *c;
    if (self->unk_58 != NULL) {
        func_0203f920(self->unk_58);
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub48 *m;
        Ov009Sub44 *s;
        *self->unk_50 = 0;
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
        self->unk_4c->target = 0xffff;
        e = func_02065f88(0x322, &self->pos);
        e->v24(0, self->unk_6c, 0);
        e->v0c(0x2000);
        FLD(s32, e, 0xc8) = -1;
        self->unk_f4 = FLD(s32, e, 0x24);
        switch (self->kind) {
        case 0x5049:
            a = Ov009_FindActor(self->target_id);
            if (a != NULL) {
                func_ov000_0218d46c(a, self->id, 0x15);
            }
            break;
        case 0x5055:
            a = Ov009_FindActor(self->target_id);
            if (a != NULL) {
                a->unk_1a = 1;
            }
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x4003, 0x15);
            break;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        u16 t;
        st = self->unk_40;
        st->timer++;
        t = st->timer;
        if (t >= 0x78) {
            func_ov000_0218996c(10, 0x3c);
            func_02065804(data_0214a420, self->unk_f4);
            func_02065f88(1, &self->pos)->v24(0, self->unk_6c, 0);
            e = func_02065f88(5, &self->pos);
            e->v24(0, self->unk_6c, 0);
            e->v0c(0x4000);
            a = Ov009_FindActor(self->unk_f0);
            if (a != NULL) {
                func_ov000_0218d46c(a, self->unk_f0, 0x15);
            }
            self->unk_40->state = 10;
            break;
        }
        if (t >= 0x28 && t % 10 == 0) {
            Ov009Vec p;
            Ov009Vec v;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += self->unk_6c;
            v.x = self->unk_64;
            v.y = self->unk_68 >> 2;
            v.z = self->unk_64;
            func_ov000_0219b71c(&p, &v, 0x733, 0xccd, 4, 0x32);
            func_ov000_0218996c(8, 8);
            func_02049f44(data_02097e4c, 0x35, &p, 0);
        }
        break;
    }
    case 10:
        c = func_02070558((void *)self->kind);
        func_ov000_0219b400(c + 0x3e, c + 0x42, 2, &self->pos, self->rot, 1);
        func_ov000_0219b5dc(FLD(u16, self->unk_b0, 6), &self->pos, self->rot);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 11:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            func_ov000_02199f48(self->unk_50, func_ov000_0219bf90());
            func_ov003_021d6a3c(self, 1, 1, 1);
            break;
        }
        func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        break;
    }
}

}
}  // namespace m_02203428

// ---- merged from ov009_0220387c.cpp
namespace m_0220387c {
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

static inline void Ov009Spawn_Init(Ov009SpawnDesc2 *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern u8 data_ov009_02215e9c[];
extern Ov009Actor *Group_SpawnActor(void *mgr, Ov009SpawnDesc2 *d, Ov009Vec *pos, Ov009Rot16 *rot, u16 a);

void func_ov009_0220387c(Ov009Act_02202788 *self) {
    Ov009SpawnDesc2 desc;
    Ov009Vec p;
    Ov009Actor *o;
    u8 *tmpl = data_ov009_02215e9c;
    Ov009Spawn_Init(&desc, 0x483c);
    {
        s32 z;
        p.x = self->pos.x;
        p.y = self->pos.y;
        z = self->pos.z;
        p.y += 0x4e66;
        p.z = z;
    }
    Ov009Rot16 r = *(Ov009Rot16 *)self->rot;
    r.x = 0x1c70;
    o = Group_SpawnActor(data_ov000_021ccd64, &desc, &p, &r, 0xffff);
    if (o == NULL) {
        return;
    }
    o->unk_60 = tmpl;
    o->unk_90 = self->unk_90;
    if (o->unk_4c != NULL) {
        o->unk_4c->target = self->id;
    }
    self->target_id = o->id;
    ((Ov009Flag8 *)((u8 *)o + 0x16))->b0 = 1;
}

}
}  // namespace m_0220387c

// ---- merged from ov009_0220397c.cpp
namespace m_0220397c {
extern "C" {

extern void *data_02097e4c;
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(FieldState *g, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_0220397c(Ov009Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_02070558(res);
    const char *s;
    char *t;
    STD_CopyString(self->mdlDir, a);
    STD_CopyString(self->mdlName, b);
    self->ownMdl = 1;
    s = data_ov009_02215d38;
    STD_CopyString(self->anmDir, s);
    STD_CopyString(self->anmName, data_ov009_02215d40);
    self->ownAnm = 1;
    t = FLD(char *, c, 0x28);
    if (t != NULL) {
        STD_CopyString(self->evDir, s);
        STD_CopyString(self->evName, t);
        self->ownEv = 1;
    }
    self->unk_00 = 0;
}

extern void func_ov003_021d6bac(Ov009Actor *self, const void *a);

void Ov009ActVt_02216c74_Init(Ov009ActVt_02216c74 *self) {
    u8 *p;
    if (self->kind == 0x5053) {
        self->unk_d8 = (void *)func_ov009_0220397c;
    }
    func_ov003_021d0fc0(self);
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *bb = (Ov009Byte *)(p + 0xa2);
        bb->b0 = 0;
        bb->b5 = 1;
    }
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x502e:
    case 0x5033:
    case 0x504c:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        self->unk_1a = 0;
        break;
    case 0x5053:
        func_ov000_02187a20(data_ov000_021ccd54, 0x10);
        self->unk_1a = 1;
        break;
    case 0x5059:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        self->unk_1a = 0;
        func_ov003_021d6bac(self, data_ov009_02215d64);
        break;
    }
    self->unk_c8 = 0x1e000;
    self->unk_cc = 0xc000;
    FLD(s32, self, 0xf0) = 0;
}

}
}  // namespace m_0220397c

// ---- merged from ov009_02203b8c.cpp
namespace m_02203b8c {
extern "C" {

extern void *data_0214a420;
extern void func_02065804(void *mgr, void *p);

void Ov009ActVt_02216c74_Update(Ov009ActVt_02216c74 *self) {
    func_ov003_021d1e8c(self);
    if (self->unk_40->unk_13 == 0xf) {
        return;
    }
    func_02065804(data_0214a420, self->unk_f0);
    self->unk_f0 = NULL;
}

extern void *data_02097e4c;
extern const Ov009Vec data_ov009_02215e08;
extern char data_ov009_02216bae[];
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern s32 func_020658cc(void *mgr, s32 id);
extern Ov009V *func_020657b0(void *mgr, void *p);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);

void func_ov009_02203bc8(Ov009ActVt_02216c74 *self) {
    Ov009Actor *t;
    s32 state;
    Ov009Sub40 *st;
    Ov009V *e;
    state = self->unk_40->state;
    t = Actor_GetTarget(self);
    switch (state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c, 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        e = func_02065f88(0x3ea, &self->pos);
        e->v20(&data_ov009_02215e08);
        e->v30(self->rot);
        e->v0c(0x5800);
        FLD(s32, e, 0x3c) = 0x1800;
        FLD(s32, e, 0xc8) = -1;
        self->unk_f0 = FLD(void *, e, 0x24);
        func_02049f44(data_02097e4c, data_ov009_02215d5c[self->unk_1a], &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        if (func_020658cc(data_0214a420, 0x2bd) == 0) {
            e = func_02065f88(0x2bd, &self->pos);
            e->v24(0, 0x19a, 0);
            e->v0c(0x2000);
            FLD(s32, e, 0x3c) = 0x4000;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x50) {
            self->unk_a0 = 0x266;
            self->unk_a8 = 0x29;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        Actor_TurnToActor(self, t, 0x400);
        self->unk_98 = self->rot[1];
        break;
    case 2:
        if (self->unk_48->unk_50 & 0x20000000) {
            func_02049f44(data_02097e4c, 0x7e, &self->pos, 0);
            func_ov000_0218996c(3, 5);
            self->unk_a0 = 0x666;
            self->unk_9c = 0x266;
            self->unk_a8 = 0x52;
            self->unk_40->state++;
        }
        Actor_TurnToActor(self, t, 0x400);
        self->unk_98 = self->rot[1];
        break;
    case 3:
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            break;
        }
        func_02049f44(data_02097e4c, 0x7e, &self->pos, 0);
        func_ov000_0218996c(3, 5);
        func_02065f88(0x12f, &self->pos)->v0c(0x800);
        st = self->unk_40;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        st->state++;
        break;
    case 4: {
        u16 tm;
        st = self->unk_40;
        st->timer++;
        tm = st->timer;
        if (tm == 0x32) {
            func_02065804(data_0214a420, self->unk_f0);
            self->unk_f0 = NULL;
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d1c, 0x400, 0);
        }
        if (tm > 0x32 && self->unk_38->anim_state == 1) {
            self->unk_40->timer = 0;
            if (Rand_UpTo(9) > 1) {
                e = func_02065f88(0x44d, &self->pos);
                e->v24(0, 0x1800, 0);
                FLD(s32, e, 0xc8) = 1;
                st = self->unk_40;
                st->state++;
            } else {
                self->unk_40->state = 10;
            }
        }
        break;
    }
    case 5:
        if (self->unk_38->anim_state == 2) {
            self->unk_40->state++;
        }
        break;
    case 6:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xc8) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02216bae, 0x111, 0);
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        }
        break;
    case 10:
        if (self->unk_38->anim_state == 2) {
            func_02065f88(0x68, &self->pos)->v24(0, 0x19a, 0);
            func_02049f44(data_02097e4c, 8, &self->pos, 0);
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    case 0x1e:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    Actor_Move((Actor *)self, 0);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    e = func_020657b0(data_0214a420, self->unk_f0);
    if (e != NULL) {
        e->v18(&self->pos);
        e->v20(&data_ov009_02215e08);
        e->v30(self->rot);
    }
    if (state < 4) {
        self->unk_94_1 = 1;
    }
}

}
}  // namespace m_02203b8c

// ---- merged from ov009_022040f0.cpp
namespace m_022040f0 {
extern "C" {

extern void *data_0214a420;
extern void func_02065804(void *mgr, void *p);

void func_ov009_022040f0(Ov009ActVt_02216c74 *self) {
    if (self->unk_40->state == 0) {
        self->unk_64 >>= 1;
        func_02065804(data_0214a420, self->unk_f0);
        self->unk_f0 = NULL;
    }
    func_ov003_021d6054(self);
}

}
}  // namespace m_022040f0

// ---- merged from ov009_0220413c.cpp
namespace m_0220413c {
extern "C" {

extern void *data_02097e4c;
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(FieldState *g, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_0220397c(Ov009Names *self, void *res);

void Ov009ActVt_02216bc8_Init(Ov009ActVt_02216bc8 *self) {
    u8 *p;
    if (self->kind != 0x5810 && self->kind != 0x5811) {
        self->unk_d8 = (void *)func_ov009_0220397c;
    }
    func_ov003_021d0fc0(self);
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *bb = (Ov009Byte *)(p + 0xa2);
        bb->b0 = 0;
        bb->b5 = 1;
    }
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x503e:
        self->unk_ea |= 0x400;
    case 0x504d:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        break;
    case 0x5027:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        self->unk_ea |= 0x400;
        break;
    }
    self->unk_f8 = 0;
}

extern const Ov009Vec data_ov009_02215e24[];
struct Ov009Trail {
    u8 unk_00[0x10c];
    Ov009Vec trail[5];
};

void Ov009ActVt_02216bc8_Start(Ov009ActVt_02216bc8 *self) {
    s16 n;
    u8 i;
    func_ov003_021d112c(self);
    self->unk_f3 = 0;
    if (!(self->kind != 0x5810 && self->kind != 0x5811)) {
        self->unk_f2 = 1;
        self->unk_f6 = 0x50;
        self->unk_fc = 0x2000;
    } else {
        self->unk_f2 = 0;
        self->unk_fc = 0x3000;
        self->unk_c8 = 0x16800;
        self->unk_cc = 0xc000;
    }
    n = self->unk_1a;
    if (n != 0) {
        if (n >= 10 && n < 15) {
            n = n - 10;
            self->unk_f3 = 1;
            if (self->unk_f2 == 1 && self->unk_18 != 0) {
                self->pos = data_ov009_02215e24[n];
            }
        }
        self->unk_18 = n;
    }
    self->unk_f1 = self->unk_18;
    self->unk_100 = self->unk_38->scale;
    for (i = 0; i < 5; i++) {
        ((Ov009Trail *)self)->trail[i] = data_ov009_02215d90;
    }
    if (self->unk_f2 != 1) {
        self->unk_48->unk_60 = 0x1000;
    } else {
        self->unk_48->unk_60 = -0x400;
        self->unk_48->unk_48 = 0x1000;
        Ov009Vec *dst = &self->unk_38->scale;
        *dst = data_ov009_02215d90;
        self->pos.y += 0x2000;
        self->unk_ea_6 = 1;
        func_ov000_02198360(self->unk_40, 0x20, 0);
    }
    self->unk_f0 = 0;
    self->unk_1c = 0x38e;
}

}
}  // namespace m_0220413c

// ---- merged from ov009_02204410.cpp
namespace m_02204410 {
extern "C" {

struct Ov009Msg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    u8 idx;
    u8 unk_09[0x3];
    Ov009Vec v;
};

extern BOOL func_ov003_021d1c00(Ov009Actor *self, Ov009Msg *msg);

void func_ov009_02204410(Ov009ActVt_02216bc8 *self, Ov009Msg *msg) {
    if (msg->type == 0xe) {
        Ov009Vec *dst = (Ov009Vec *)((u8 *)self + msg->idx * 0xc + 0x10c);
        dst->x = msg->v.x;
        dst->y = msg->v.y;
        dst->z = msg->v.z;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    }
    func_ov003_021d1c00(self, msg);
}

extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void func_0203f364(Ov009Sub48 *p);
extern void HitSphere_Link(Ov009Sub48 *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);
struct Ov009AngSrc {
    u8 unk_00[0x40];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern u16 Camera_GetYaw(Ov009AngSrc *p);

static inline s32 Ov009_GetAng(Ov009AngSrc *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return Camera_GetYaw(p);
}

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void func_ov009_02204468(Ov009ActVt_02216bc8 *self) {
    Ov009Vec v;
    Ov009V *obj;
    s32 ang;
    s32 h;
    Ov009Sub44 *s44;
    Ov009Sub48 *s48;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        if (!Ov009_GameIdle()) {
            return;
        }
        if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
            return;
        }
        obj = func_02065f88(0x389, &self->pos);
        obj->v0c(0x3000);
        ang = Ov009_GetAng((Ov009AngSrc *)((u8 *)data_ov000_021ccd54 + 0xf4));
        v.x = 0;
        v.y = 0;
        v.z = -0x800;
        func_01ffc9fc(&v, &v, ang);
        obj->v20(&v);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        self->unk_38->unk_c2_0 = 1;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer >= 0x32) {
            h = self->unk_38->scale.x + 0x266;
            if (h >= FLD(s32, self, 0x100)) {
                h = FLD(u32, self, 0x100);
                func_02065f88(0x69, &self->pos);
                func_02065f88(0x38a, &self->pos);
                s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                s48 = self->unk_48;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                HitSphere_Link(s48);
                self->unk_40->timer = 0;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            {
                Ov009Vec *s = &self->unk_38->scale;
                s->x = h;
                s->y = h;
                s->z = h;
            }
        }
        break;
    }
    Actor_TurnToActor(self, func_ov000_0219bf90(), 0x400);
}

}
}  // namespace m_02204410

// ---- merged from ov009_022046cc.cpp
namespace m_022046cc {
extern "C" {

void func_ov009_022046cc(Ov009ActVt_02216bc8 *self) {
    Ov009Vec p;
    Ov009Sub40 *st;
    if (self->unk_40->state == 0) {
        self->unk_f0 = 0;
        self->unk_48->unk_30 = 0x40000000;
    }
    if (self->unk_f2 == 0) {
        func_ov003_021d3524(self);
        return;
    }
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    p = self->pos;
    if (func_ov000_0219a2f4(&p, 0x3800, -0xa000) != -0x1000) {
        p.y += 0x2000;
    }
    {
        s32 y = self->pos.y;
        self->pos.y = y + FX_Mul(p.y - y, 0x19a);
    }
    VEC_Distance(&self->pos, &p);
    if (self->unk_48->unk_50 & 0x20000000) {
        return;
    }
    st = self->unk_40;
    st->timer++;
    if (st->timer > 0x46) {
        self->unk_40->timer = 0x46;
        if (!(self->unk_48->unk_54 & 0x20000000)) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
    }
}

}
}  // namespace m_022046cc

// ---- merged from ov009_0220487c.cpp
namespace m_0220487c {
extern "C" {

extern void Actor_MoveToPos(Ov009Actor *self, Ov009Vec *v, s32 a);

void func_ov009_0220487c(Ov009ActVt_02216bc8 *self) {
    Ov009Vec v;
    Ov009Vec p;
    if (self->unk_f2 == 0) {
        func_ov003_021d3600(self);
        return;
    }
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    v = self->unk_b8;
    self->unk_9c = self->unk_b0->unk_00;
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    p = self->pos;
    if (func_ov000_0219a2f4(&p, 0x3800, -0xa000) != -0x1000) {
        if (p.y < v.y) {
            p.y = v.y;
        }
        p.y += 0x2000;
    }
    {
        s32 y = self->pos.y;
        self->pos.y = y + FX_Mul(p.y - y, 0x19a);
    }
    VEC_Distance(&self->pos, &p);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

}
}  // namespace m_0220487c

// ---- merged from ov009_022049e4.cpp
namespace m_022049e4 {
extern "C" {

void func_ov009_022049e4(Ov009ActVt_02216bc8 *self) {
    if (self->unk_40->state == 0 && self->unk_f3 == 1) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

}

#ifdef NONMATCHING
// Status (round drA): func_ov009_02204a10 is 295 / 283 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: the hoisted self + 0x10c base is kept in fp, the ROM spills it (every stack
// offset from 0x10 up is 4 low); the 57-67 drafts need a volatile base pointer. History: docs/MATCHING.md rounds
// qpD, qpG, qpL, svB, cvA (search for the address); the full list is docs/UNMATCHED.md.
// func_ov009_02204a10: 153 / 279 (register-masked / raw, honest_search scorer; was 151 / 379),
// no fake parameters, volatile or junk locals. Round qpD: the trail loop reads self->trail[i]
// directly, which gives the ROM's code shape there (one i * 12 shared by the VEC_Distance
// argument and the [self + i * 12, #0x10c] loads, with self + 0x10c hoisted). What is left:
// - the ROM spills that hoisted self + 0x10c to [sp, #0x10] (frame 0x104, no pushed r3); our
//   colouring keeps it in fp and spills the hoisted &v instead, so every stack offset from
//   0x10 up is 4 bytes low. In our graph &v costs 13 and the base 17; the ROM needs one more
//   value live across the loop (or a base cost of 13 or less). The ROM's
//   "mov r0, #0; mov r4, r0" before the loop suggests that value is a hoisted zero.
// - the 0x666 block after VEC_Normalize(&d, &d): the ROM loads d.z into the register of the
//   stored d.x (so it is not hoisted after allocation) and stores d.y between them.
// Round qpG: the three trail-loop zeros (g.y and the two mla high words of x * 0x666) stay separate
// nodes because the ROM-like merge is refused twice: local CSE will not merge cheap constants in a
// loop preheader, and move-constant-loads stops reusing at the multi-def `i = 0` zero in block 64.
// Merging them by hand under gdb puts the zero in fp, not a spill (42 aligned, worse). "mov r0, #0;
// mov r4, r0" is post-allocation CSE of a constant move. See docs/MATCHING.md, round qpG.
// See docs/MATCHING.md, round qpD.
// Round qpL: a toy loop (Normalize, x/z * 0x666, y = 0, VEC_Add) also keeps the g.y zero and the
// two lowered high-word zeros as three preheader nodes, and no matched object has the ROM's
// "mov rA, #0; mov rB, rA; <rA redefined>" shape, so no source for the merged zero was found. A
// `tr = trail` base local set before the 0219a510 call (raH: a call between def and use keeps the
// object vreg) is 31 aligned / 326 raw, but tr is then live across the list loop and stays in fp.
// Reusing v for g (wrong layout, diagnostic only) does flip the spill to the base at [sp, #0x10].
extern "C" {

extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_01ffc9fc(Ov009Vec *dst, const Ov009Vec *src, s32 angle);
extern void func_020639d4(Ov009V *o, s32 a, s32 b);
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void Actor_MoveToPos(Ov009Actor *self, Ov009Vec *v, s32 a);
extern s32 func_ov000_0219a510(Ov009Obj *self, u16 mask, Ov009Vec *pos, s32 r, s32 a, Ov009Actor **list);
extern Ov009Actor *func_ov000_021985c0(Ov009Actor *p);
extern void func_ov000_0219bd20(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_02191690(void *model);

struct Ov009AngSrc {
    u8 unk_00[0x40];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern u16 Camera_GetYaw(Ov009AngSrc *p);

static inline s32 Ov009_GetAng(Ov009AngSrc *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return Camera_GetYaw(p);
}

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

static inline void Ov009_VecSub(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

struct Ov009Trail {
    u8 unk_00[0x10c];
    Ov009Vec trail[5];
};

struct Ov009HitMsg {
    u8 idx;
    Ov009Vec pos;
};

void func_ov009_02204a10(Ov009ActVt_02216bc8 *self) {
    Ov009Vec v;
    Ov009Vec pp;
    Ov009Vec d;
    Ov009Vec f;
    Ov009Vec g;
    Ov009HitMsg msg;
    Ov009Vec x;
    Ov009Vec d2;
    Ov009Vec w;
    Ov009Actor *list[32];
    Ov009Actor *pl;
    Ov009Sub40 *st;
    Ov009V *o;
    Ov009Sub44 *s44;
    Ov009Sub48 *s48;
    s32 h;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    pl = func_ov000_0219bf90();
    pp = pl->pos;
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        s32 t;
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c, 0x400, 0);
        v = self->pos;
        v.y += 0x2000;
        self->unk_b8 = v;
        t = 0x3c;
        if (self->unk_f2 == 1) {
            t = 0x28;
        }
        self->unk_f4 = t + Rand_UpTo(0x32);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        if (self->unk_f2 == 0) {
            self->unk_40->state++;
        } else {
            self->unk_40->state = 10;
        }
    }
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer == 5) {
            o = func_02065f88(0x192, &self->pos);
            o->v24(0, 0x4000, 0);
            o->v34(0xbfff, 0, 0);
            func_020639d4(o, 0x54, 0);
            o = func_02065f88(0x68, &self->pos);
            o->v24(0, 0x400, 0);
            FLD(s32, o, 0x7c) = FX_Div(0x1e000, 0x1f000);
            func_02065f88(0x12f, &self->pos)->v0c(0x800);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 2: {
        s32 sy;
        Ov009Sub38 *m = self->unk_38;
        h = FLD(s32, m, 0xa8);
        sy = FLD(s32, m, 0xac);
        h -= 0x19a;
        if (h <= 0) {
            h = 0;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d30, 0x1000, 0);
            self->unk_38->unk_c2_0 = 0;
            self->unk_40->timer = 0;
            self->unk_40->state = 0x14;
        }
        m = self->unk_38;
        FLD(s32, m, 0xa8) = h;
        FLD(s32, m, 0xac) = sy + 0xcd;
        FLD(s32, m, 0xb0) = h;
        v = self->unk_b8;
        Ov009_VecSub(&v, &self->pos, &d2);
        VEC_MultAdd(0x19a, &d2, &self->pos, &self->pos);
        break;
    }
    case 10:
        o = func_02065f88(0x389, &self->pos);
        o->v0c(0x3000);
        h = Ov009_GetAng((Ov009AngSrc *)((u8 *)data_ov000_021ccd54 + 0xf4));
        v.x = 0;
        v.y = 0;
        v.z = -0x800;
        func_01ffc9fc(&v, &v, h);
        o->v20(&v);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 11: {
        Ov009Sub38 *m;
        h = self->unk_38->scale.x - 0x52;
        if (h <= 0) {
            func_02065f88(0x38a, &self->pos);
            h = 0;
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            self->unk_38->unk_c2_0 = 0;
            self->unk_40->timer = 0;
            self->unk_40->state = 0x14;
        }
        m = self->unk_38;
        FLD(s32, m, 0xa8) = h;
        FLD(s32, m, 0xac) = h;
        FLD(s32, m, 0xb0) = h;
        break;
    }
    case 0x14: {
        u32 t;
        s32 dist;
        st->timer++;
        t = st->timer;
        if (!(self->unk_48->unk_50 & 0x40000000)) {
            s32 off;
            s32 n;
            u8 i;
            dist = VEC_Distance(&self->pos, &pp);
            self->unk_9c = 0x1ec;
            if (dist < 0x2800) {
                self->unk_9c = -self->unk_9c;
            }
            Actor_MoveToPos(self, &pp, 0x1000);
            off = 0x2333;
            if (self->unk_f2 == 1) {
                off = 0x2000;
            }
            w = self->pos;
            if (func_ov000_0219a2f4(&w, off + 0x1800, -0xa000) != -0x1000) {
                if (w.y < pp.y) {
                    w.y = pp.y;
                }
                w.y += off;
            }
            self->pos.y += FX_Mul(w.y - self->pos.y, 0x1000);
            VEC_Distance(&self->pos, &w);
            Ov009_VecSub(&self->pos, &pp, &d);
            func_01ffc9fc(&d, &d, (u16)(self->unk_1c + 0xffff));
            VEC_Add(&d, &pp, &d);
            d.y = self->pos.y;
            Ov009_VecSub(&d, &self->pos, &d);
            VEC_Normalize(&d, &d);
            d.x = FX_Mul(d.x, 0x666);
            d.z = FX_Mul(d.z, 0x666);
            d.y = 0;
            VEC_Add(&self->pos, &d, &self->pos);
            n = func_ov000_0219a510(self, 0x20, &self->pos, 0x2000, 0, list);
            if (n != 0) {
                s32 k;
                for (k = 0; k < n; k++) {
                    Ov009Actor *q;
                    if (list[k] != NULL && (q = func_ov000_021985c0(list[k])) != NULL) {
                        v = q->pos;
                        Ov009_VecSub(&self->pos, &v, &v);
                        VEC_Normalize(&v, &v);
                        f.x = FX_Mul(v.x, 0x666);
                        f.y = 0;
                        f.z = FX_Mul(v.z, 0x666);
                        VEC_Add(&self->pos, &f, &self->pos);
                        break;
                    }
                }
            }
            for (i = 0; i < 5; i++) {
                if (self->unk_f1 == i) {
                    continue;
                }
                if (VEC_Distance(&self->pos, &((Ov009Trail *)self)->trail[i]) <= self->unk_fc) {
                    v.x = self->pos.x - ((Ov009Trail *)self)->trail[i].x;
                    v.y = self->pos.y - ((Ov009Trail *)self)->trail[i].y;
                    v.z = self->pos.z - ((Ov009Trail *)self)->trail[i].z;
                    VEC_Normalize(&v, &v);
                    g.x = FX_Mul(v.x, 0x666);
                    g.y = 0;
                    g.z = FX_Mul(v.z, 0x666);
                    VEC_Add(&self->pos, &g, &self->pos);
                    self->unk_1c = -self->unk_1c;
                }
            }
            msg.idx = self->unk_f1;
            msg.pos = self->pos;
            func_ov000_0219bd20(self->kind, self->kind, 0xe, 1, 0x10, &msg);
            if (t >= self->unk_f4 && dist <= 0x3000) {
                func_ov000_02198360(self->unk_40, 0x10, 0);
            }
        } else {
            self->unk_1c = -self->unk_1c;
        }
        if (t >= 0xd2) {
            func_ov000_02198360(self->unk_40, 0x10, 0);
        }
        if (self->unk_f2 == 0) {
            u8 *b = Group_FindNode(data_ov000_021ccd64, self->unk_20);
            if (b != NULL) {
                x = FLD(Ov009Vec, b, 0x88);
            }
            x.y = self->pos.y;
            if (VEC_Distance(&self->pos, &x) > self->unk_c8 + 0x4800) {
                if (b != NULL) {
                    x = FLD(Ov009Vec, b, 0x88);
                }
                x.y += 0x2000;
                self->pos = x;
                self->unk_f0 = 1;
                func_ov000_02198360(self->unk_40, 0x10, 0);
            }
        }
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        break;
    }
    }
    self->unk_ea_0 = 3;
    self->unk_94_1 = 1;
    if ((s32)self->unk_40->state <= 2 && self->unk_38->anim_state == 1) {
        func_ov000_02191690(self->unk_38);
    }
}

}
#endif
}  // namespace m_022049e4
