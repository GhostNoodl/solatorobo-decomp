#include "ov007/ov007.h"

extern "C" {

extern void *data_02097e3c;
extern char data_ov007_021cfbe7[];
BOOL func_02036328(void);
void func_020444b0(void *a, s32 b, int c, int d);
void func_02044524(void *a);
void func_0206e900(char *dst, const char *src);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02043d20(void *a, int b);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void func_02043db4(int a, s32 b, s32 c, s32 d);
void func_ov007_021cf474(Ov007Scene *s);

}

static inline s32 Ov007_Choice(Ov007Scene *s) {
    s32 r = -1;
    switch (s->unk_4d) {
    case 1:
        r = 0;
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

static inline void Ov007_DrawModel(void *m) {
    void *anim;
    void *res = FLD(void *, m, 0x28);
    void *arg;
    void *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (FLD(s32, m, 0x80) > 0) {
        anim = FLD(void *, m, 0x78);
    }
    if (anim != NULL && (t = FLD(void *, anim, 0x4)) != NULL) {
        arg = FLD(void *, t, 0x30);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0);
        arg = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, e, 0xc));
    }
    func_02042628(m, arg, anim, 0);
}

static inline void *Ov007_GetTex(void *m, void *res, void *anim) {
    if (anim != NULL && FLD(void *, anim, 0x4) != NULL) {
        return FLD(void *, FLD(void *, anim, 0x4), 0x30);
    }
    return NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0), 0xc));
}
static inline void Ov007_DrawModel2(void *m) {
    void *res = FLD(void *, m, 0x28);
    if (res != NULL) {
        void *anim = 0 >= FLD(s32, m, 0x80) ? NULL : FLD(void *, m, 0x78);
        func_02042628(m, Ov007_GetTex(m, res, anim), anim, 0);
    }
}

struct Ov007Vec {
    s32 x;
    s32 y;
    s32 z;
};

static inline void Ov007_SetupView(void) {
    u32 a;
    u32 b;
    Ov007Vec v;
    func_02043d20(data_02097d48 + 0x8b0, 0);
    a = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &a, 1);
    b = 0x141f00d0;
    NNS_G3dGeBufferOP_N(0x29, &b, 1);
    v.z = -0x3000;
    v.x = 0;
    v.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, &v, 3);
    func_02043db4(1, 0x100000, 0xc0000, 0x7fff);
}

static inline void Ov007_SetupView1(void) {
    u32 b;
    u32 a;
    Ov007Vec v;
    func_02043d20(data_02097d48 + 0x8b0, 0);
    a = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &a, 1);
    b = 0x141f00d0;
    NNS_G3dGeBufferOP_N(0x29, &b, 1);
    v.z = -0x3000;
    v.x = 0;
    v.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, &v, 3);
    func_02043db4(1, 0x100000, 0xc0000, 0x7fff);
}

struct Ov007Mdl6c {
    u32 b0 : 2;
    u32 b2 : 5;
    u32 rest : 25;
};

extern "C" {

void func_ov007_021cef80(Ov007Scene *s) {
    char buf[0x20];
    Ov007V *p;
    switch (s->sub) {
    case 0:
        if (Ov007_Choice(s) < 0) {
            s->sub = 3;
            return;
        }
        s->sub = 1;
        return;
    case 1:
        if (!func_02036328()) {
            return;
        }
        OV007_FREE_V(s->unk_14, v04);
        func_0203cb78(0x1e000, 0, -1);
        func_020444b0(data_02097e3c, Ov007_Choice(s), -1, 0);
        s->sub = 2;
        return;
    case 2:
        if (!Ov007_FadeIdle()) {
            return;
        }
        if (FLD(u8, data_02097e3c, 0x149) == 0) {
            func_0206e900(buf, data_ov007_021cfbe7);
            p = (Ov007V *)func_0203dd9c(0x4c);
            if (p != NULL) {
                FLD(void *, p, 0) = &data_0208b318;
                p->v08();
            }
            s->unk_14 = p;
            FLD(s32, p, 0x44) = 7;
            s->unk_14->v20(buf);
            func_0203cc58(0x3c000, 1, -1);
            s->sub = 3;
            return;
        }
        if (!(data_02097dc8->trg & 1)) {
            return;
        }
        func_02044524(data_02097e3c);
        return;
    case 3:
        if (!Ov007_FadeDone()) {
            return;
        }
        if (s->unk_14->v2c() != 0) {
            s->state = 5;
            s->sub = 0;
            s->idx = 0;
        }
        return;
    }
}

void func_ov007_021cf1d8(Ov007Scene *s) {
    switch (s->state) {
    case 3:
        if (Ov007_FadeDone()) {
            break;
        }
        if (s->unk_28 != NULL) {
            FLD(s32, s->unk_28, 0x150) = -0x3000;
            Ov007_DrawModel(s->unk_28);
        }
        if (s->unk_2c != NULL) {
            FLD(s32, s->unk_2c, 0x150) = -0x3000;
            FLD(u32, s->unk_2c, 0x6c) &= ~0x80000;
            FLD(Ov007Mdl6c, s->unk_2c, 0x6c).b2 = 0x1f;
            Ov007_DrawModel2(s->unk_2c);
            break;
        }
        Ov007_SetupView1();
        break;
    case 5:
        func_ov007_021cf474(s);
        break;
    case 7:
        Ov007_SetupView();
        break;
    }
    if (s->unk_68 != NULL) {
        s->unk_68->v20();
    }
}

}
