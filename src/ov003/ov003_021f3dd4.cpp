#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

class Ov003Effect {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetRot(s32 x, s32 y, s32 z);
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void SetColor(s32 a, s32 b, s32 c);
};

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

struct Ov003Save {
    u8 unk_00[0x18];
    u16 unk_18_0 : 1;
    u16 unk_18_1 : 2;
    u16 unk_18_3 : 4;
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
    Ov003Vec pos;
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
extern Ov003Effect *func_02065f88(s32 id, const Ov003Vec *pos);
extern s32 func_02040528(s32 max);
extern s32 func_02040498(s32 max);
extern Ov003FxPlayer *func_ov000_0219bf90(void);
extern Ov003Info *func_0206fef8(u16 id);
extern s32 func_020705fc(u16 id);
extern void *func_0203dd9c(u32 size);
extern Ov003Res *func_ov000_0218e9c4(void *p);
extern Ov003Shadow *func_ov000_021919c8(void *p);
extern void func_ov000_02191b70(Ov003Shadow *p);
extern BOOL func_ov000_02191b9c(Ov003Shadow *p);
extern void func_0201e520(char *dst, const char *src);
extern BOOL func_ov000_0218f110(s16 *p);
extern Ov003Save *data_0214a424;
extern char data_ov003_021fa662[];
extern void func_ov000_021b4c60(void *self);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_02191870(void *model, Ov003Res *res);
extern Ov003AnimLayer *func_ov000_02190a30(void *model, s32 n);
extern void func_ov000_02191920(void *model, s32 a, s32 b, s32 c);
extern u32 func_0200aeec(s32 v);
extern u32 func_0200b854(u32 a, u32 b);
extern u32 func_0200ba84(u32 a, u32 b);
extern s32 func_0200b574(u32 v);
extern void *func_ov000_02198328(void *p);

static inline BOOL Ov003Shadow_IsIdle(Ov003Shadow *sh) {
    BOOL r = TRUE;
    if (sh->state != 3 && sh->state != 0) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov003_021f3dd4(Ov003Prop *self) {
    BOOL r = TRUE;
    if (self->res->handle >= 0 && !func_ov000_0218f110(&self->res->handle)) {
        r = FALSE;
    }
    if (self->count != 0 && self->altRes.handle >= 0 && !func_ov000_0218f110(&self->altRes.handle)) {
        r = FALSE;
    }
    if (self->shadow != NULL && !Ov003Shadow_IsIdle(self->shadow)) {
        if (!func_ov000_02191b9c(self->shadow)) {
            r = FALSE;
        }
    }
    return r;
}

void func_ov003_021f3e60(Ov003Prop *self) {
    Ov003AnimLayer *layer;
    func_ov000_021b4c60(self);
    func_ov000_02190cb0(self->model, data_ov003_021fa662, 0x1000, 1);
    if (self->count != 0) {
        func_ov000_02191870(self->model, &self->altRes);
        layer = func_ov000_02190a30(self->model, 3);
        if (layer != NULL) {
            s32 frame;
            s32 n;
            Ov003AnimCtl *ctl;
            func_ov000_02191920(self->model, 0, 0x1000, 0);
            n = self->count << 12;
            if (self->count != 0) {
                frame = func_0200b574(func_0200b854(0x3f000000, func_0200aeec(n)));
            } else {
                frame = func_0200b574(func_0200ba84(func_0200aeec(n), 0x3f000000));
            }
            ctl = layer->ctl;
            if (ctl != NULL) {
                if (frame >= 0) {
                    ctl->frame = frame;
                } else {
                    ctl->frame = (ctl->frames->count << 12) - 1;
                }
            }
            layer->loop = 1;
        }
        self->model->unk_c2_6 = 1;
    }
    void *task = func_0203dd9c(0x14);
    if (task != NULL) {
        task = func_ov000_02198328(task);
    }
    self->task = task;
}
}
