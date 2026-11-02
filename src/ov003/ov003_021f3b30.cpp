#include "types.h"
#include "Main/Effect/Effect.h"
#include "nitro/std.h"
#include "Main/Res/StageFlags.h"


struct Ov003Res {
    s16 handle;
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 hasName : 1;
    u8 hasAltName : 1;
    u8 unk_04[0xc];
    char name[0x20];
    char name2[0x1c];
    char altName[0x20];
    char altName2[0xcc];
};

struct Ov003Names {
    const char *name;
    const char *name2;
    const char *altName;
    const char *altName2;
    u8 unk_10[8];
    u8 count;
};

struct Ov003FxPlayer {
    u8 unk_00[0xba0];
    Ov003Names *names;
};

struct Ov003Info {
    u8 unk_00[0x12];
    u16 unk_12_0 : 12;
    u16 shadow : 2;
};

struct Ov003Shadow {
    u8 unk_00[0x1b];
    u8 state;
};

struct Ov003Model {
    u8 unk_00[0xc2];
    u16 unk_c2_0 : 6;
    u16 unk_c2_6 : 1;
};

struct Ov003AnimFrames {
    u8 unk_00[4];
    u16 count;
};

struct Ov003AnimCtl {
    s32 frame;
    u8 unk_04[4];
    Ov003AnimFrames *frames;
};

struct Ov003AnimLayer {
    Ov003AnimCtl *ctl;
    u8 unk_04[0x10d];
    u8 unk_111_0 : 3;
    u8 loop : 1;
};


struct Ov003Prop {
    u8 unk_00[0xe];
    u16 id;
    u8 unk_10[0x24];
    Ov003Res *res;
    Ov003Model *model;
    Ov003Shadow *shadow;
    void *task;
    u8 unk_44[0x2c];
    VecFx32 pos;
    u8 unk_7c[0x30];
    s32 unk_ac;
    Ov003Res altRes;
    u8 count;
    u8 unk_1e9;
    u16 unk_1ea;
    u16 unk_1ec;
    u8 unk_1ee[0xe2];
    u16 timer;
};

extern "C" {
extern s32 Rand_PlusMinus(s32 max);
extern u32 Rand_UpTo(u32 max);
extern Ov003FxPlayer *func_ov000_0219bf90(void);
extern Ov003Info *func_0206fef8(u16 id);
extern u8 *func_020705fc(s32 id);
extern void *Heap_Alloc(u32 size);
extern void *func_ov000_0218e9c4(void *p);
extern Ov003Shadow *func_ov000_021919c8(void *p);
extern void Shadow_Load(Ov003Shadow *p);
extern BOOL func_ov000_02191b9c(Ov003Shadow *p);
extern BOOL func_ov000_0218f110(s16 *p);
extern char data_ov003_021fa662[];
extern void Ov000ActVt_021cc7cc_Start(void *self);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_02191870(void *model, Ov003Res *res);
extern Ov003AnimLayer *func_ov000_02190a30(void *model, s32 n);
extern void func_ov000_02191920(void *model, s32 a, s32 b, s32 c);
extern void *History_Init(void *p);

void func_ov003_021f3b30(Ov003Prop *self) {
    EffectObj *e;
    s32 id;
    s32 s;
    s32 a;
    s32 b;
    self->timer++;
    if (!(self->timer & 0x3f)) {
        e = func_02065f88(0x325, &self->pos);
        if (e != NULL) {
            e->SetRotXYZ(0xc000, 0, 0);
            e->SetScaleXYZ(0x666, 0x733, 0x666);
            a = Rand_PlusMinus(0x8cd);
            b = Rand_PlusMinus(0x8cd);
            e->AddPosXYZ(a, 0x59a, b);
        }
    }
    if ((self->timer & 0x7f) != 0x10) {
        return;
    }
    id = 0x322;
    if (Rand_UpTo(3) == 0) {
        id = 4;
    }
    e = func_02065f88(id, &self->pos);
    if (e == NULL) {
        return;
    }
    s = Rand_PlusMinus(0x19a) + 0x666;
    e->SetScaleXYZ(s, s, s);
    a = Rand_PlusMinus(0xb33);
    b = Rand_UpTo(0x1000 - 0xb33);
    e->AddPosXYZ(a, b + 0x800, Rand_PlusMinus(0xb33));
}

}
