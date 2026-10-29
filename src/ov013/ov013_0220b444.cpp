#include "ov013/ov013.h"

typedef Ov013Vec VecFx32;

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// spot block. The objects before the empty asm function are the TU's size-sorted group (definition
// order found with solve2.py); the vectors after it keep definition order. The spot block is one
// object: its far[] entries are initialised before the separate near-spot array.
// func_ov013_021fee10 at the end is part of this TU: it reads data_ov013_0220aee0 and
// data_ov013_0220af28 through the .rodata base plus an offset. The second read of af28's x is
// reloaded in the target, so it goes through a cast view of the vector (a second access path that
// MWCC does not merge with the first read).
struct Ov013Rot { u16 x, y, z; };
struct Ov013Spot { VecFx32 pos; u16 rot; };
typedef void (*Ov013Fn)(void);
struct Ov013SpotBlock { char name[16]; Ov013Fn fn[6]; Ov013Spot far[4]; };

extern "C" {

void func_ov013_02204450(void);
void *func_ov013_021fed50(void *self);
BOOL func_ov013_02204448(void);
void func_ov013_02204444(void);
void func_ov013_0220428c(void *self);
void func_ov013_022043f8(void *self, u32 *p);

extern const s32 data_ov013_0220aedc;
extern const s32 data_ov013_0220aef8;
extern const s32 data_ov013_0220af0c;
extern const Ov013Rot data_ov013_0220af18;
extern const s16 data_ov013_0220af1e[4];
extern const VecFx32 data_ov013_0220af28;
extern const VecFx32 data_ov013_0220af34;
extern const VecFx32 data_ov013_0220af40[2];
extern const VecFx32 data_ov013_0220af58[3];
extern char data_ov013_0220b89c[];
extern char data_ov013_0220b8a2[];
extern char data_ov013_0220b8a8[];
extern char data_ov013_0220b8ae[];
extern char data_ov013_0220b8b4[];
extern char data_ov013_0220b8ba[];
extern char data_ov013_0220b8c0[];
extern char data_ov013_0220b8c6[];
extern const Ov013Rot data_ov013_0220b8cc;
extern char data_ov013_0220b8d2[];
extern const VecFx32 data_ov013_0220b8d8;
extern char data_ov013_0220b8e4[];
extern char data_ov013_0220b8f0[];
extern const Ov013SpotBlock data_ov013_0220b930;
extern const Ov013Spot data_ov013_0220b900[3];
extern const VecFx32 data_ov013_0220af7c;
extern const VecFx32 data_ov013_0220af88;
extern const VecFx32 data_ov013_0220af94;
extern const VecFx32 data_ov013_0220afa0;
extern const VecFx32 data_ov013_0220afac;
extern const VecFx32 data_ov013_0220afb8;
extern const VecFx32 data_ov013_0220afc4;
extern const char *const data_ov013_0220aee0;
extern const char *const data_ov013_0220aee4;
extern const char *const data_ov013_0220aee8;
extern const char *const data_ov013_0220aeec;
extern const char *const data_ov013_0220aef0;
extern const char *const data_ov013_0220aef4;
extern const char *const data_ov013_0220aefc;
extern const char *const data_ov013_0220af00;
extern const char *const data_ov013_0220af04;
extern const char *const data_ov013_0220af08;
extern const char *const data_ov013_0220af10;
extern const char *const data_ov013_0220af14;

const char *const data_ov013_0220af14 = data_ov013_0220b8ba;
const Ov013Rot data_ov013_0220b8cc = data_ov013_0220af18;
const Ov013Rot data_ov013_0220af18 = {0, 0, 0};
const VecFx32 data_ov013_0220af58[3] = {{0, 0, -0x7000}, {-0x1464a, 0x2000, -0xad64}, {0xa89c, 0xc642, 0xc4cd}};
const VecFx32 data_ov013_0220b8d8 = data_ov013_0220af28;
const VecFx32 data_ov013_0220af40[2] = {{0, 0x2000, -0x2666}, {-0x14d1, 0x4cd, 0}};
const char *const data_ov013_0220aefc = data_ov013_0220b8c0;
char data_ov013_0220b8f0[] = "ef/effect3dhsn";
const char *const data_ov013_0220aee0 = data_ov013_0220b89c;
const Ov013SpotBlock data_ov013_0220b930 = {"SHR2", {(Ov013Fn)func_ov013_02204450, (Ov013Fn)func_ov013_021fed50, (Ov013Fn)func_ov013_02204448, (Ov013Fn)func_ov013_02204444, (Ov013Fn)func_ov013_0220428c, (Ov013Fn)func_ov013_022043f8}, {{data_ov013_0220afa0, 0xde4e}, {data_ov013_0220afac, 0x1b00}, {data_ov013_0220afb8, 0xaa65}, {data_ov013_0220afc4, 0x6b00}}};
const char *const data_ov013_0220aef4 = data_ov013_0220b8ae;
char data_ov013_0220b8b4[] = "att01";
const char *const data_ov013_0220aee8 = data_ov013_0220b8e4;
const s32 data_ov013_0220aedc = 0xff00;
const Ov013Spot data_ov013_0220b900[3] = {{data_ov013_0220af94, 0}, {data_ov013_0220afa0, 0xde4e}, {data_ov013_0220afac, 0x1b00}};
const VecFx32 data_ov013_0220af34 = {0, 0, -0x3000};
const s32 data_ov013_0220af0c = 0x2000;
const char *const data_ov013_0220af10 = data_ov013_0220b8a2;
const char *const data_ov013_0220aef0 = data_ov013_0220b8d2;
char data_ov013_0220b8c0[] = "att10";
const char *const data_ov013_0220af04 = data_ov013_0220b8a8;
char data_ov013_0220b89c[] = "nut00";
char data_ov013_0220b8d2[] = "nut01";
char data_ov013_0220b8a8[] = "run00";
const char *const data_ov013_0220aee4 = data_ov013_0220b8f0;
const VecFx32 data_ov013_0220af28 = {0, 0, 0};
char data_ov013_0220b8ba[] = "att02";
const s32 data_ov013_0220aef8 = 8;
char data_ov013_0220b8e4[] = "ef3di1hsn00";
const char *const data_ov013_0220af00 = data_ov013_0220b8c6;
const s16 data_ov013_0220af1e[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const char *const data_ov013_0220af08 = data_ov013_0220b8b4;
char data_ov013_0220b8c6[] = "dmg00";
char data_ov013_0220b8ae[] = "att00";
const char *const data_ov013_0220aeec = data_ov013_0220b89c;
char data_ov013_0220b8a2[] = "nut10";

static asm void ov013_0220b444_order() {
}

const VecFx32 data_ov013_0220af7c = {0x6000, 0x6000, 0x6000};
const VecFx32 data_ov013_0220af88 = {0x9000, 0x6000, 0x9000};
const VecFx32 data_ov013_0220af94 = {-0x212b, 0x2000, -0xb3a2};
const VecFx32 data_ov013_0220afa0 = {0xf189, 0x2000, -0x9c21};
const VecFx32 data_ov013_0220afac = {-0xd66a, 0x2000, -0x9323};
const VecFx32 data_ov013_0220afb8 = {0x56bc, 0x2000, 0xa9ec};
const VecFx32 data_ov013_0220afc4 = {-0xa8c9, 0x2000, 0xa91f};

}

extern "C" {
struct Ov013Area {
    void *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 id;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    Ov013Vec pos;
};

struct Ov013Opt120B {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 pad;
    u16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

struct Ov013Opt124 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 unk_02;
    s32 unk_04;
    Ov013Vec v;
    s32 unk_14;
    void *fn;
};

extern const u8 data_ov003_021f4340;
extern u8 data_ov013_0220b150[];
extern int func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_0203f324(Ov013Sub48 *p);
extern BOOL func_ov003_021d8f4c(void *p);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_ov003_021d8980(void *p);
extern void func_ov003_021d8a30(void *p, s32 a, void *b);
extern void func_ov013_02204428(void *dst, const void *src, void *owner);
extern void *func_ov000_02190a30(void *a, s32 b);
extern BOOL func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern void func_ov000_021bd228(void *p);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov013Actor *self, const void *p);

static inline void Ov013B_PartFlag(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline void Ov013Area_Set(Ov013Area *ar, u16 id) {
    ar->b0 = 1;
    ar->b1 = 1;
    ar->id = id;
    ar->unk_08 = -0x1464a;
    ar->unk_0c = 0x2000;
    ar->unk_10 = -0xad64;
    ar->unk_14 = 0xa89c;
    ar->unk_18 = 0xc642;
    ar->unk_1c = 0xc4cd;
}

void func_ov013_021fee10(Ov013Actor *self) {
    Ov013Sub48 *m48;
    Ov013Area *ar;
    Ov013Opt120B *o2;
    Ov013Opt124 *o3;
    const char *anim;
    void *m;
    s32 x;
    s32 y;
    s32 z;
    func_ov003_021d112c(self);
    FLD(Ov013Flags8, self, 0xf0).b3 = 1;
    func_ov003_021cf330((u8 *)self + 0x13c, data_ov013_0220b930.name, data_ov003_021f4340);
    m48 = self->unk_48;
    m48->unk_9a_1 = 0;
    m48->unk_9a_4 = 0;
    m48 = self->unk_48;
    m48->unk_9a_0 = 1;
    m48->unk_9a_3 = 1;
    func_0203f324(m48);
    {
        Ov013Sub44 *n = self->unk_44;
        n->unk_1c = Ov013_FxMul(n->unk_1c, 0x1800);
    }
    func_ov003_021d8f4c((u8 *)self + 0x14c);
    func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b150, 0xf);
    self->unk_90 = func_ov000_0219bf90()->id;
    ar = (Ov013Area *)func_0203dd9c(0x2c);
    if (ar != NULL) {
        ar->vt = (void *)data_ov013_0220b930.fn;
        ar->b0 = 0;
    }
    FLD(Ov013Area *, self, 0x128) = ar;
    Ov013Area_Set(ar, self->id);
    ar->pos.x = x = data_ov013_0220af28.x;
    ar->pos.y = y = data_ov013_0220af28.y;
    ar->pos.z = z = data_ov013_0220af28.z;
    func_ov003_021d8980((u8 *)self + 0x12c);
    func_ov003_021d8a30((u8 *)self + 0x12c, 0, FLD(void *, self, 0x128));
    o2 = (Ov013Opt120B *)func_0203dd9c(0x1c);
    if (o2 != NULL) {
        o2->b0 = 0;
    }
    FLD(Ov013Opt120B *, self, 0x120) = o2;
    o2->b0 = 1;
    o2->unk_02 = 0;
    {
        s32 x2 = ((const VecFx32 *)&data_ov013_0220af28)->x;
        o2->v.x = x2;
        o2->v.y = y;
        o2->v.z = z;
        o2->w.x = x2;
        o2->w.y = y;
        o2->w.z = z;
    }
    o3 = (Ov013Opt124 *)func_0203dd9c(0x1c);
    if (o3 != NULL) {
        o3->b0 = 0;
    }
    FLD(Ov013Opt124 *, self, 0x124) = o3;
    o3->b0 = 0;
    o3->b1 = 0;
    o3->unk_02 = 0x1000;
    o3->unk_04 = 0;
    o3->v.x = x;
    o3->v.y = y;
    o3->v.z = z;
    o3->unk_14 = 0;
    o3->fn = (void *)func_ov013_02204428;
    o3->b0 = 1;
    anim = data_ov013_0220aee0;
    func_ov000_02190cb0(self->unk_38, anim, 0x1000, 1);
    m = self->unk_38;
    if (FLD(void *, m, 0x14) != NULL) {
        void *o = FLD(void *, m, 0);
        func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 8), anim, 0x1000, 0);
    }
    FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
    m = self->unk_38;
    if (m != NULL) {
        Ov013B_PartFlag(m, 0);
        Ov013B_PartFlag(m, 1);
        Ov013B_PartFlag(m, 3);
        Ov013B_PartFlag(m, 4);
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (FLD(void *, self, 0x5c) != NULL) {
            void *p = FLD(void *, self, 0x5c);
            if (p != NULL) {
                func_ov000_021bd228(p);
                func_0203de1c(p);
            }
            FLD(void *, self, 0x5c) = NULL;
        }
        data_02097dd0->cur = saved;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov013_0220af1e);
    }
    self->pos.y -= 0x1000;
}

}

