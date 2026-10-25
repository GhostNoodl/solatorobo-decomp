#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// names, the pointers to them, two angle tables and six vectors. Other functions read the
// pointers, the tables and the named vectors; the unnamed ones are read through offsets.
// func_ov003_021e83d0 at the end is part of this TU: it copies data_ov003_021f6ae4 through the
// .rodata base plus an offset.
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Ov003Blk12;

extern const char *const data_ov003_021f6a80;
extern const s16 data_ov003_021f6a96[4];
extern const s16 data_ov003_021f6a9e[5];
extern const Ov003Blk12 data_ov003_021f6aa8;
extern const Ov003Blk12 data_ov003_021f6ab4;
extern const Ov003Blk12 data_ov003_021f6ac0;
extern const VecFx32 data_ov003_021f6acc;
extern const VecFx32 data_ov003_021f6ad8;
extern char data_ov003_021f90e0[];
extern char data_ov003_021f90e6[];
extern char data_ov003_021f90ec[];
extern char data_ov003_021f90f8[];
const s16 data_ov003_021f6a9e[5] = {0x2d, 0x5b, 0xb6, 0x16c, 0x2d8};
static const char *const data_ov003_021f6a88 = data_ov003_021f90e0;
static const char *const data_ov003_021f6a8c = data_ov003_021f90ec;
const VecFx32 data_ov003_021f6ad8 = {0, 0, 0};
const char *const data_ov003_021f6a80 = data_ov003_021f90f8;
static const char *const data_ov003_021f6a84 = data_ov003_021f90e6;
const s16 data_ov003_021f6a96[4] = {0x5b, 0xb6, 0x16c, 0x2d8};
const Ov003Blk12 data_ov003_021f6ab4 = {0xe66, 0xe66, 0xe66};
char data_ov003_021f90f8[] = "act00";
const VecFx32 data_ov003_021f6acc = {0, FX32_ONE, 0};
char data_ov003_021f90e6[] = "run00";
char data_ov003_021f90ec[] = "att00";
const Ov003Blk12 data_ov003_021f6aa8 = {0x2000, 0x1000, 0x2000};
const Ov003Blk12 data_ov003_021f6ac0 = {0x8cd, 0x8cd, 0x8cd};
char data_ov003_021f90e0[] = "nut00";
static const VecFx32 data_ov003_021f6ae4 = {0, 0, 0};
static const VecFx16 data_ov003_021f6a90 = {0, 0, 0};
static const VecFx16 data_ov003_021f90f2 = data_ov003_021f6a90;
static const VecFx32 data_ov003_021f9100 = data_ov003_021f6ae4;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003Rot;

typedef struct {
    u16 state;
    u16 timer;
} Ov003Work;

typedef struct {
    u8 unk_00[0x50];
    u16 *input;
    u8 unk_54[0x1c];
    Ov003Vec pos;
} Ov003RtPlayer;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003Game54;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u8 unk_54[0xc];
    s32 unk_60;
} Ov003RtCtl;

typedef struct {
    u8 unk_00[8];
    u16 a;
    u16 b;
} Ov003RtLink;

typedef struct {
    u8 unk_00[0x18];
    s16 kind;
    s16 mode;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x12];
    void *res;
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[4];
    Ov003RtCtl *ctl;
    Ov003RtLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    Ov003Rot rot;
    u8 unk_82[0x1a];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x20];
    u16 unk_cc_0 : 2;
    u16 spin : 1;
    u8 unk_ce[2];
    u8 anim[0x78];
    Ov003Vec animPos;
    u8 unk_154[0x24];
    Ov003Vec scale;
    u8 unk_184[0xe];
    u16 active : 1;
    u8 unk_194[0x24];
    u8 count;
    u8 unk_1b9;
    u16 speed;
    u16 angle;
    u16 step;
} Ov003Rotor;

extern "C" {
extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003RtPlayer *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);

static inline BOOL Ov003Game54_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game54_IsIdle(Ov003Game54 *g) {
    if (Ov003Game54_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_Game54Idle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game54_IsIdle(g);
    }
    return TRUE;
}

BOOL func_ov003_021e83d0(Ov003Rotor *self) {
    BOOL r = FALSE;
    if (func_ov000_0219bf90()->input[0] != 0 && Ov003_Game54Idle()) {
        VecFx32 v;
        Ov003Rot rot;
        u8 i;
        v = data_ov003_021f6ae4;
        v.y = 0x1666;
        rot = self->rot;
        rot.x += 0x4000;
        rot.y += self->angle;
        for (i = 0; i < self->count; i++) {
            r = func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &v, &rot, 0x400, 0x3000, 100, 0x1000);
            if (r) {
                return r;
            }
            rot.y += self->step;
        }
    }
    return r;
}
}
