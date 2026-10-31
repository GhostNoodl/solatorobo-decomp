#include "ov014/ov014.h"

typedef s16 fx16;
typedef s32 fx32;
typedef Ov014Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };
#define FX32_ONE 0x1000

// This TU's .rodata from its base to the last vector the static initialiser copies, and its .data
// up to the second copy. The copied vectors and their sources are weak: the stub loads each through
// its own pool word, not from the section base. Everything follows the empty asm function, so it
// keeps definition (address) order.
// ov014_02201dcc.cpp and ov014_02202964.cpp (0x02201dcc..0x02202f1c) were merged in round dtB,
// each in its own namespace (02202964 read the same vector as data_ov014_02216500[0x4c..0x4e]). The first
// reads data_ov014_02216630 through the .rodata base (it was an FLD view at data_ov014_02216500 +
// 0x130), so that source is not weak; the stub still matches with it non-weak.
struct Ov014Rot { u16 x, y, z; };
struct Ov014Res { const char *name; s32 n; };

extern "C" {

extern const char *const data_ov014_02216500[4];
extern const s16 data_ov014_02216510[3];
extern const Ov014Rot data_ov014_02216516;
extern const s32 data_ov014_0221651c[2];
extern const s32 data_ov014_02216524[2];
extern const s32 data_ov014_0221652c[2];
extern const s32 data_ov014_02216534[2];
extern const s32 data_ov014_0221653c[2];
extern const s32 data_ov014_02216544[2];
extern const s32 data_ov014_0221654c[2];
extern const s32 data_ov014_02216554[2];
extern const s32 data_ov014_0221655c[2];
extern const VecFx32 data_ov014_02216564;
extern const VecFx32 data_ov014_02216570;
extern const VecFx32 data_ov014_0221657c;
extern const s32 data_ov014_02216588[6];
extern const s32 data_ov014_022165a0[6];
extern const VecFx32 data_ov014_022165b8;
extern const s32 data_ov014_022165c4[6];
extern const VecFx32 data_ov014_022165dc;
extern const VecFx32 data_ov014_022165e8;
extern const s32 data_ov014_022165f4[1];
extern const s32 data_ov014_022165f8[2];
extern const VecFx32 data_ov014_02216600;
extern const s32 data_ov014_0221660c[6];
extern const VecFx32 data_ov014_02216624;
extern const VecFx32 data_ov014_02216630;
extern char data_ov014_02217354[];
extern char data_ov014_02217360[];
extern char data_ov014_02217366[];
extern char data_ov014_0221736c[];
extern char data_ov014_02217372[];
extern char data_ov014_0221737e[];
extern char data_ov014_02217398[];
extern char data_ov014_022173a7[];
extern char data_ov014_022173b9[];
extern char data_ov014_022173c8[];
extern char data_ov014_022173ce[];
extern char data_ov014_022173d9[];
extern Ov014Res data_ov014_022173e0;
extern const VecFx32 data_ov014_0221738c;
extern const VecFx32 data_ov014_022173e8;

static asm void Ov014_Dummy(void) {}

const char *const data_ov014_02216500[4] = {data_ov014_02217354, data_ov014_02217360, data_ov014_0221736c, data_ov014_02217366};
const s16 data_ov014_02216510[3] = {0x0, 0x5554, -0x5558};
const Ov014Rot data_ov014_02216516 = {0, 0, 0};
const s32 data_ov014_0221651c[2] = {0x2, 0x1f40000};
const s32 data_ov014_02216524[2] = {0xb, 0x1e0000};
const s32 data_ov014_0221652c[2] = {0xa, 0x0};
const s32 data_ov014_02216534[2] = {0x780000, 0x3};
const s32 data_ov014_0221653c[2] = {0x960001, 0x3};
const s32 data_ov014_02216544[2] = {0xa0002, 0x20004};
const s32 data_ov014_0221654c[2] = {0x18001800, 0x18001800};
const s32 data_ov014_02216554[2] = {0x18001800, 0x18001800};
const s32 data_ov014_0221655c[2] = {0x96000c, 0x1e0000};
__declspec(weak) const VecFx32 data_ov014_02216564 = {0x0, 0x0, 0x1000};
const VecFx32 data_ov014_02216570 = {0x0, -0x1000, 0x0};
const VecFx32 data_ov014_0221657c = {0x0, 0x2000, 0x0};
const s32 data_ov014_02216588[6] = {0x0, 0x4759a, 0x0, 0x0, -0x5000, 0x4000};
const s32 data_ov014_022165a0[6] = {0x0, 0x0, 0x1800, 0x0, 0x1000, 0x4000};
const VecFx32 data_ov014_022165b8 = {0x0, 0x0, 0x1800};
const s32 data_ov014_022165c4[6] = {0x0, 0x0, 0x1800, 0x0, 0x1800, 0x1000};
const VecFx32 data_ov014_022165dc = {0x0, 0x4759a, 0x0};
const VecFx32 data_ov014_022165e8 = {0x0, 0x4719a, 0xf000};
const s32 data_ov014_022165f4[1] = {0x0};
const s32 data_ov014_022165f8[2] = {0x1000, 0x0};
const VecFx32 data_ov014_02216600 = {0x0, 0x0, 0x9000};
const s32 data_ov014_0221660c[6] = {0x0, -0x1000, 0x0, 0x0, 0x0, -0x1800};
const VecFx32 data_ov014_02216624 = {0x0, 0x0, 0x1800};
const VecFx32 data_ov014_02216630 = {0x0, 0x0, 0x0};
char data_ov014_02217354[6] = "run00";
static const Ov014Rot data_ov014_0221735a = data_ov014_02216516;
char data_ov014_02217360[] = "att00";
char data_ov014_02217366[] = "nut00";
char data_ov014_0221736c[] = "att01";
char data_ov014_02217372[] = "ef3di1lcr11";
char data_ov014_0221737e[] = "ef3di1lcr10";
__declspec(weak) const VecFx32 data_ov014_0221738c = data_ov014_02216630;
char data_ov014_02217398[] = "ef/effect3dlcr";
char data_ov014_022173a7[] = "ef3di1lcr12.cceff";
char data_ov014_022173b9[] = "ef/effect3dlcr";
char data_ov014_022173c8[] = "nut01";
char data_ov014_022173ce[] = "blt/b1sha1";
char data_ov014_022173d9[] = "b1sha1";
Ov014Res data_ov014_022173e0 = {data_ov014_02217398, 0x37};
__declspec(weak) const VecFx32 data_ov014_022173e8 = data_ov014_02216564;

}

// ---- merged from ov014_02201dcc.cpp
namespace m_02201dcc {
extern "C" {

extern u8 data_ov014_02217430[];
extern void func_ov003_021ceedc(void *p);
extern void *func_ov003_021cef0c(void *p);
extern void *func_ov003_021da940(void *p);
extern void *func_ov003_021d7f0c(void *p);
extern void *func_ov003_021d7fc0(void *p);
extern void *func_ov000_0218e9c4(void *p);
extern void *func_ov000_0218fe1c(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218ea20(void *p);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d883c(void *p, Ov014Vec *a, Ov014Vec *b, s32 c);
extern BOOL func_ov000_021903b4(void *p);
extern void func_ov003_021d3008(Ov014Actor *self);
extern BOOL func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);
extern void *data_ov000_021ccd64;
extern void func_ov003_021d112c(Ov014Actor *self);
extern BOOL func_ov003_021d8198(void *p);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov003_021cf1f0(void *p, s32 a, s32 b, const void *c);
extern BOOL func_ov000_0218ffdc(void *anim, void *res, s32 a, s32 b);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *a);

BOOL func_ov014_02201dcc(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0x150) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0x150)) ? TRUE : FALSE;
    }
    return r;
}

BOOL func_ov014_02201e08(Ov014Actor *self) {
    s32 f;
    BOOL r;
    Ov014Vec saved = self->pos;
    if (!func_ov003_021d8820((u8 *)self + 0x100)) {
        func_ov003_021d883c((u8 *)self + 0x100, &self->pos, &self->pos, 0x200);
    }
    r = func_ov003_021d16cc(self);
    f = FLD(s32, self, 0xf4);
    if ((f & 0x40) || (f & 0x1000)) {
        FLD(Ov014Vec, self, 0x300) = self->pos;
        r = func_ov000_021903b4((u8 *)self + 0x288);
    }
    self->pos = saved;
    return r;
}

void func_ov014_02201ea4(Ov014Actor *self) {
    func_ov003_021d3008(self);
    ((Ov014V *)((u8 *)self + 0x100))->v0c();
}

void func_ov014_02201ec4(Ov014Actor *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80((u8 *)self + 0x288, func_0203db40((u8 *)self + 0x24));
}

void func_ov014_02201ee8(Ov014Actor *self, Ov014Msg *msg) {
    if (msg->type == 6) {
        FLD(u8, self, 0xf8) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    }
    func_ov003_021d1c00(self, msg);
}

void func_ov014_02201f24(Ov014Actor *self) {
    u8 *u;
    func_ov003_021d112c(self);
    FLD(s16, self, 0xf0) = (u8)self->unk_18;
    FLD(s32 *, self, 0xfc) = Ov014_NewFx();
    func_ov003_021d8198((u8 *)self + 0x100);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        FLD(Ov014Flags8, u, 0xa2).b0 = 0;
    }
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_6 = 1;
    {
        Ov014Sub48 *m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
    }
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        func_ov003_021cf1f0((u8 *)self + 0x134, 0, 1, data_ov014_02216534);
        break;
    case 1:
        func_ov003_021cf1f0((u8 *)self + 0x134, 1, 1, data_ov014_0221653c);
        break;
    case 2:
        func_ov003_021cf1f0((u8 *)self + 0x134, 2, 1, data_ov014_02216544);
        break;
    }
    func_ov000_0218ffdc((u8 *)self + 0x288, (u8 *)self + 0x150, 0, 1);
    FLD(Ov014Flags, self, 0x34a).b0 = 1;
    FLD(s32, self, 0x330) = data_ov014_02216630.x;
    FLD(s32, self, 0x334) = data_ov014_02216630.y;
    FLD(s32, self, 0x338) = data_ov014_02216630.z;
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        self->unk_48->unk_60 = -0x800;
        break;
    case 1: {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_48->unk_60 = -0x4cd;
        break;
    }
    case 2:
        FLD(u8, self, 0x12e) = func_02040498(5);
        break;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov014_02216554);
        FLD(u16, self, 0x12c) = 0x1800;
    }
}
extern void *data_02097e4c;
struct Ov014Blk12 {
    s32 a[3];
};
extern Ov014Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov014Actor *a);
extern void *func_ov003_021ceff4(void *p);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);

void func_ov014_02202100(Ov014Actor *self) {
    Ov014Actor *pl;
    Ov014Vec v;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
        if (func_ov000_021b4738(pl)) {
            return;
        }
    }
    if (self->unk_40->unk_13 == 1) {
        u32 f = FLD(u32, self, 0xf4);
        if (f == 0) {
            u8 *t = FLD(u8 *, self, 0x140);
            FLD(u8 *, self, 0x130) = FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
            func_ov003_021ceff4((u8 *)self + 0x134);
            switch (*FLD(s16 *, self, 0x130)) {
            case 0:
                FLD(u32, self, 0xf4) |= 4;
                self->unk_40->flags |= 0x8000;
                break;
            case 1:
                FLD(u32, self, 0xf4) |= 8;
                FLD(u32, self, 0xf4) |= 0x3000000;
                self->unk_40->flags |= 0x10000;
                break;
            case 2:
                FLD(u32, self, 0xf4) |= 0x20;
                self->unk_40->flags |= 0x4000;
                break;
            }
        } else if (f & 1) {
            self->unk_b6++;
            if (self->unk_b6 >= 10) {
                self->unk_b6 = 0;
                FLD(u32, self, 0xf4) = f ^ 1;
            }
        }
    }
    if (self->unk_30 & 0x200) {
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
    }
    func_ov003_021dacfc(FLD(void *, self, 0xfc));
    if (self->pos.y <= 0x4519a) {
        self->unk_40->flags |= 0x200000;
    }
    *(Ov014Blk12 *)&v = *(Ov014Blk12 *)&data_ov014_022165e8;
    v.y = self->pos.y;
    if (VEC_Distance(&self->pos, &v) > 0xf000) {
        self->unk_40->flags |= 0x200000;
    }
}

}
}  // namespace m_02201dcc

// ---- merged from ov014_02202964.cpp
namespace m_02202964 {
extern "C" {

extern void *data_02097e4c;
extern void func_ov003_021daab0(void *p);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d87d0(void *p, s32 a);
extern void func_0203f324(Ov014Sub48 *p);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *target, s32 a);

extern void func_ov000_021911c8(void *a, s32 b);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void func_ov003_021daa6c(void *p, s32 a);

static inline s32 Ov014e_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_02202330(Ov014Actor *self) {
    u8 *m38 = (u8 *)self->unk_38;
    Ov014Sub40 *s = self->unk_40;
    s32 hp = Ov014e_FxMul64(FLD(s32, m38, 0xa8), 0x1333);
    s32 v = FLD(s32, self, 0x330);
    switch (Ov014Sub40_State(s)) {
    case 0: {
        const char *anim = data_ov014_02216500[3];
        Ov014V *e;
        func_ov000_02190cb0((u8 *)self + 0x288, anim, 0x1000, 0);
        func_ov000_021911c8((u8 *)self + 0x288, 0xb33);
        func_ov000_021915a0((u8 *)self + 0x288);
        func_ov000_02190cb0(self->unk_38, anim, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u32, self, 0xf4) |= 0x300000;
        e = func_02065f88(0x648, &self->pos);
        hp >>= 1;
        e->v0c(hp);
        e = func_02065f88(0x322, &self->pos);
        e->v0c(hp + 0x800);
        FLD(s32, e, 0xc8) = -1;
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xff, e);
        self->unk_40->state++;
        break;
    }
    case 1:
        if (v >= hp) {
            break;
        }
        v += Ov014e_FxMul64(hp >> 1, 0x1ec);
        if (v >= hp) {
            s->state++;
        }
        FLD(s32, self, 0x330) = v;
        FLD(s32, self, 0x334) = v;
        FLD(s32, self, 0x338) = v;
        break;
    case 2:
        s->timer++;
        if (s->timer != 0x1e) {
            break;
        }
        func_02065f88(0x38a, &self->pos)->v0c(hp >> 1);
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        func_ov003_021daa6c(FLD(void *, self, 0xfc), 0xff);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 3: {
        u8 c = FLD(u8, m38, 0xbe);
        if (c < 0x1f) {
            c = c + 1;
            if (c >= 0x1f) {
                FLD(u32, self, 0xf4) ^= 0x100000;
                c = 0x1f;
                FLD(u8, m38, 0xbe) = c;
            }
            FLD(u8, self->unk_38, 0xbe) = c;
        }
        if (v > 0) {
            v -= Ov014e_FxMul64(hp >> 1, 0x266);
            if (v <= 0) {
                v = 0;
                FLD(u32, self, 0xf4) ^= 0x200000;
                FLD(Ov014Flags, self, 0x34a).b0 = 0;
            }
            FLD(s32, self, 0x330) = v;
            FLD(s32, self, 0x334) = v;
            FLD(s32, self, 0x338) = v;
        }
        if (FLD(u32, self, 0xf4) & 0x100000) {
            break;
        }
        if (FLD(u32, self, 0xf4) & 0x200000) {
            break;
        }
        self->unk_40->state++;
        break;
    }
    case 4:
        switch (FLD(s16, self, 0xf0)) {
        case 0:
            s->timer++;
            if (s->timer != 10) {
                break;
            }
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x52;
            self->unk_a0 = -0x148;
            self->unk_40->timer = 0;
            self->unk_40->state++;
            break;
        case 1: {
            Ov014Sub44 *n;
            s->timer++;
            if (s->timer != 10) {
                break;
            }
            self->unk_48->unk_30 = 0;
            n = self->unk_44;
            n->unk_22_0 = true;
            n->unk_22_1 = true;
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_a0 = -0x133;
            self->unk_40->timer = 0;
            self->unk_40->state++;
            break;
        }
        case 2:
            FLD(u32, self, 0xf4) ^= 0x40;
            func_ov000_02198360(s, 1, 0);
            break;
        }
        break;
    case 5:
        switch (FLD(s16, self, 0xf0)) {
        case 0: {
            Ov014Sub40 *w;
            func_ov000_0218dbe0(self, 0);
            w = self->unk_40;
            w->timer++;
            if (w->timer != 0x19) {
                break;
            }
            self->unk_40->timer = 0;
            FLD(u32, self, 0xf4) ^= 0x40;
            func_ov000_02198360(self->unk_40, 1, 0);
            break;
        }
        case 1: {
            Ov014Sub40 *w;
            Ov014Sub48 *m;
            func_ov000_0218dbe0(self, 0);
            w = self->unk_40;
            w->timer++;
            if (w->timer != 0x37) {
                break;
            }
            m = self->unk_48;
            m->unk_9a_0 = true;
            m->unk_9a_3 = true;
            func_0203f324(m);
            self->unk_40->timer = 0;
            FLD(u32, self, 0xf4) ^= 0x40;
            func_ov000_02198360(self->unk_40, 1, 0);
            break;
        }
        }
        break;
    }
}

void func_ov014_022027d0(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Sub44 *n;
        Ov014Sub48 *m;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        switch (FLD(s16, self, 0xf0)) {
        case 0:
            self->unk_48->unk_60 = -0x800;
            break;
        case 1:
            self->unk_48->unk_60 = -0x4cd;
            break;
        }
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    case 1: {
        u32 f = FLD(u32, self, 0xf4);
        if (!(f & 1) && f != 0) {
            s32 off = 0;
            switch (FLD(s16, self, 0xf0)) {
            case 0:
                off = 0x1000;
                break;
            case 1:
                off = 0x800;
                break;
            }
            if (self->pos.y < off + (self->unk_64 + 0x4719a)) {
                self->unk_a0 = 0x333;
                func_ov000_0218dbe0(self, 0);
            } else {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
                FLD(u32, self, 0xf4) = 1;
            }
        }
        break;
    }
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), 0xcd);
}

void func_ov014_02202964(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

void func_ov014_02202988(Ov014Actor *self) {
    func_ov003_021daab0(FLD(void *, self, 0xfc));
    self->unk_48->unk_30 = 0x40000000;
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        self->unk_48->unk_60 = 0;
        if (!func_ov003_021d8820((u8 *)self + 0x100)) {
            func_ov003_021d87d0((u8 *)self + 0x100, 1);
        }
    }
    func_ov003_021d5900(self);
    if (self->unk_40->state == 0 && FLD(u16, self, 0xe8) == 0) {
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0x29;
    }
}

extern void *data_0214a420;
extern void *data_ov000_021ccd64;
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern void *func_ov003_021daa3c(void *p, u8 id);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern Ov014V *func_020657b0(void *a, void *b);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

void func_ov014_02202a34(Ov014Actor *self) {
    s32 off;
    u8 *m38 = (u8 *)self->unk_38;
    Ov014Sub40 *s = self->unk_40;
    s32 v = FLD(s32, self, 0x330);
    s32 hp = FLD(s32, m38, 0xa8);
    self->unk_94_1 = 1;
    switch (s->state) {
    case 0: {
        Ov014Sub48 *m;
        Ov014Sub44 *n;
        const char *anim;
        func_ov003_021daab0(FLD(void *, self, 0xfc));
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        FLD(Ov014Flags, self, 0x34a).b0 = 1;
        FLD(s32, self, 0x330) = data_ov014_02216630.x;
        FLD(s32, self, 0x334) = data_ov014_02216630.y;
        FLD(s32, self, 0x338) = data_ov014_02216630.z;
        anim = data_ov014_02216500[3];
        func_ov000_02190cb0((u8 *)self + 0x288, anim, 0x1000, 0);
        func_ov000_021911c8((u8 *)self + 0x288, 0xccd);
        func_ov000_021915a0((u8 *)self + 0x288);
        func_ov000_02190cb0(self->unk_38, anim, 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(u32, self, 0xf4) |= 0x1000;
        FLD(u32, self, 0xf4) |= 0x1300000;
        func_ov003_021d87d0((u8 *)self + 0x100, FALSE);
        off = 0x100;
        if ((u32)self & 3) {
            off = 0x100;
        }
        func_ov003_021d85c8((u8 *)self + off, FALSE, 0, TRUE, NULL);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (v >= hp) {
            break;
        }
        v += Ov014e_FxMul64(hp >> 1, 0x19a);
        if (v >= hp) {
            func_02049f44(data_02097e4c, 0x68, &self->pos, 0);
            self->unk_40->state++;
        }
        FLD(s32, self, 0x330) = v;
        FLD(s32, self, 0x334) = v;
        FLD(s32, self, 0x338) = v;
        break;
    case 2: {
        Ov014V *e;
        s->timer++;
        if (s->timer != 10) {
            break;
        }
        e = func_02065f88(0x322, &self->pos);
        hp >>= 1;
        e->v0c(hp);
        FLD(s32, e, 0xc8) = -1;
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xff, e);
        e = func_02065f88(0x648, &self->pos);
        e->v0c(hp);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfe, e);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 3: {
        u8 c = FLD(u8, m38, 0xbe);
        s32 h;
        Ov014V *e;
        if (c != 0) {
            c--;
            if (c == 0) {
                c = 0;
            }
            FLD(u8, m38, 0xbe) = c;
        }
        if (c == 0) {
            FLD(u32, self, 0xf4) &= ~0x100000;
        }
        m38 = (u8 *)self->unk_38;
        h = FLD(s32, m38, 0xa8);
        if (h > 0) {
            h -= Ov014e_FxMul64(hp >> 1, 0xcd);
            if (h <= 0) {
                h = 0;
            }
            FLD(s32, m38, 0xa8) = h;
            FLD(s32, m38, 0xac) = h;
            FLD(s32, m38, 0xb0) = h;
        }
        if (v > 0) {
            v -= Ov014e_FxMul64(hp >> 1, 0x19a);
            if (v <= 0) {
                v = 0;
                FLD(u32, self, 0xf4) ^= 0x200000;
                FLD(Ov014Flags, self, 0x34a).b0 = 0;
            }
            FLD(s32, self, 0x330) = v;
            FLD(s32, self, 0x334) = v;
            FLD(s32, self, 0x338) = v;
        }
        if ((FLD(u32, self, 0xf4) & 0x1000000) && !(FLD(u32, self, 0xf4) & 0x200000)) {
            e = func_02065f88(0x69, &self->pos);
            e->v0c(0x40);
            func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfd, e);
            FLD(u32, self, 0xf4) ^= 0x1000000;
            func_02049f44(data_02097e4c, 0x77, &self->pos, 0);
            func_ov003_021daa6c(FLD(void *, self, 0xfc), 0xff);
        }
        e = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xfc), 0xfd));
        if (e != NULL) {
            e->v0c(FLD(u8 *, e, 0x40) + 0x148);
        }
        if (FLD(u32, self, 0xf4) & 0x100000) {
            break;
        }
        if (FLD(u32, self, 0xf4) & 0x200000) {
            break;
        }
        if (func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xfe)) {
            break;
        }
        if (func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xfd)) {
            break;
        }
        {
            u8 b[4];
            b[0] = FLD(s16, self, 0xf0) + 1;
            func_ov000_0219bd20(0x5c0e, self->kind, 6, 1, 1, b);
        }
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        break;
    }
    }
}
}
}  // namespace m_02202964
