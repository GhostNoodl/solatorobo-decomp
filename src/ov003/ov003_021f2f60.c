#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u8 unk_00[0x78];
    Ov003Vec pos;
    u8 unk_84[0x24];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u8 unk_b4[0xa];
    u8 alpha;
    u8 unk_bf[3];
    u16 visible : 1;
    u16 unk_c2_1 : 2;
    u16 flip : 1;
    u16 shadow : 1;
} Ov003BlinkModel;

typedef struct {
    u8 unk_00[0x10];
    s16 scale;
    u16 unk_12_0 : 11;
    u16 flip : 1;
} Ov003BlinkInfo;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    u8 unk_10[8];
    u16 pattern;
    u16 angleA;
    u16 angleB;
    s16 unk_1e;
    u8 unk_20[0x18];
    Ov003BlinkModel *model;
    u8 unk_3c[0x34];
    Ov003Vec pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[0x30];
    union {
        struct {
            Ov003Vec offset;
            s32 phase;
        } drift;
        struct {
            s32 radius;
            u16 phase;
        } blink;
    } u;
} Ov003Blink;

typedef struct {
    u8 unk_00[0x70];
    Ov003Vec pos;
} Ov003BlinkTarget;

extern void *data_ov003_021f738c[];
extern Ov003BlinkTarget *func_ov000_0219bf90(void);
extern BOOL func_ov000_02191120(void *model);
extern char data_ov003_021fa2d2[];

extern void func_ov000_021b4c60(void *self);
extern void func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern s32 func_02040528(s32 max);
extern void VEC_MultAdd(s32 scale, const Ov003Vec *dir, const Ov003Vec *base, Ov003Vec *out);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern Ov003BlinkInfo *func_0206fef8(u16 id);
extern BOOL func_ov000_0218cea4(void *self);
extern void func_ov000_021903b4(void *model);

static inline s32 Ov003_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov003_021f3198(Ov003Blink *self);

void func_ov003_021f2f60(Ov003Blink *self) {
    func_ov000_021b4c60(self);
    self->u.blink.phase = 0;
    if (!((s16)self->pattern & 0xff00)) {
        self->u.blink.phase = 2;
    }
    func_ov003_021f3198(self);
    self->model->shadow = 0;
    self->u.blink.radius = self->unk_1e << 4;
}

