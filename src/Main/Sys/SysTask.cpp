#include "Main/Sys/SysTask.h"

#define ST_FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

extern "C" {

void func_0206298c(void) {
    Unk0214a418 *p;
    if (data_0214a418 != NULL) {
        return;
    }
    data_02097dd0->cur = data_02097dd0->unk_04;
    p = (Unk0214a418 *)func_0203dd9c(sizeof(Unk0214a418));
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08 = NULL;
        p->unk_0c = NULL;
        p->unk_10 = NULL;
        p->unk_14 = NULL;
    }
    data_0214a418 = p;
    data_02097dd0->cur = data_02097dd0->unk_08;
    data_02097d4c = func_02062aa0;
    data_02097d44 = 0;
}

static inline void Unk0214a418_Dtor(Unk0214a418 *p) {
    func_02063374(p);
    p->unk_00 = 0;
    p->unk_04 = 0;
    p->unk_08 = NULL;
    p->unk_0c = NULL;
    p->unk_10 = NULL;
    p->unk_14 = NULL;
}

void func_02062a24(void) {
    void *saved = data_02097dd0->cur;
    Unk0214a418 *p;
    data_02097dd0->cur = data_02097dd0->unk_04;
    p = data_0214a418;
    if (p != NULL) {
        if (p != NULL) {
            Unk0214a418_Dtor(p);
            func_0203de1c(p);
        }
        data_0214a418 = NULL;
    }
    data_02097dd0->cur = saved;
}

s32 func_02062aa0(s32 arg) {
    if (data_0214a418 == NULL) {
        return 0;
    }
    return func_02062ac8(data_0214a418, arg);
}


typedef struct SysTaskArg {
    s32 unk_00;
    s32 state;
    s32 timer;
    s32 limit;
} SysTaskArg;

typedef struct StVec {
    s32 x;
    s32 y;
    s32 z;
} StVec;

struct SysTaskRes {
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0c(void);
    virtual void *vf10(void);
};

extern u8 *data_02097d48;
extern void *data_0208b3d0[];
extern u32 data_020828f8[];
extern char data_0208c1a0[];
extern char data_0208c1a4[];
extern char data_0208c1a8[];
extern BOOL func_02063484(Unk0214a418 *p);
extern BOOL func_02063650(Unk0214a418 *p);
extern void *func_ov000_0218fe1c(void *p);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_ov000_02191618(void *a);
extern void func_02041218(void *p);
extern void func_02041440(void *p, void *res, BOOL c);
extern void func_020417e0(void *a, void *b);
extern void func_02041d8c(void *a);
extern void func_02041d9c(void *a, s32 b, s32 c);
extern BOOL func_02054f10(void *a, u32 b);
extern void func_02043d20(void *a, s32 b);
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *data, u32 count);
extern void NNS_G3dGeSendDL(const void *src, u32 size);
extern void *NNS_G2dGetAnimSequenceByIdx(void *a, u16 b);
extern void *NNS_G2dGetCellDataByIdx(void *a, u16 b);
extern void func_02042628(void *a, void *b, void *c, s32 d);

static inline void ST_DrawModel(void *m) {
    void *anim;
    void *res = ST_FLD(void *, m, 0x28);
    void *arg;
    void *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (ST_FLD(s32, m, 0x80) > 0) {
        anim = ST_FLD(void *, m, 0x78);
    }
    if (anim != NULL && (t = ST_FLD(void *, anim, 0x4)) != NULL) {
        arg = ST_FLD(void *, t, 0x30);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(ST_FLD(void *, res, 0xc), 0);
        arg = NNS_G2dGetCellDataByIdx(ST_FLD(void *, res, 0x4), **(u16 **)ST_FLD(void *, e, 0xc));
    }
    func_02042628(m, arg, anim, 0);
}

static inline void ST_DrawBg(int idx, int x, int y, u32 color) {
    int scale[3];
    u32 c;
    scale[0] = x;
    scale[1] = y;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    c = color;
    NNS_G3dGeBufferOP_N(0x20, &c, 1);
    NNS_G3dGeSendDL(data_0208b3d0[idx], data_020828f8[idx]);
}

static inline void ST_Draw(Unk0214a418 *p, u32 size) {
    StVec s;
    u32 tex;
    u32 poly;
    StVec t;
    int scale[3];
    u32 c;
    u32 one;
    func_02043d20(data_02097d48 + 0x8b0, 0);
    s.x = 0x1000;
    s.y = 0x1000;
    s.z = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, &s, 3);
    tex = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &tex, 1);
    poly = 0x1f00d0;
    NNS_G3dGeBufferOP_N(0x29, &poly, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    t.z = -0x3d3;
    t.x = 0;
    t.y = 0;
    NNS_G3dGeBufferOP_N(0x1c, &t, 3);
    scale[0] = 0x100000;
    scale[1] = 0xc0000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    c = 0;
    NNS_G3dGeBufferOP_N(0x20, &c, 1);
    NNS_G3dGeSendDL(data_0208b3d0[1], size);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    ST_FLD(s32, p->unk_14, 0x150) = -0x3b3;
    ST_DrawModel(p->unk_14);
}

static inline BOOL ST_IsReady(Unk0214a418 *p) {
    BOOL ok = TRUE;
    if (p->unk_0c == NULL) {
        ok = FALSE;
    }
    if (p->unk_14 == NULL) {
        ok = FALSE;
    }
    return ok;
}

static inline void ST_ModelCtor(void *m, void *res, BOOL f) {
    func_02041218((u8 *)m + 0x88);
    func_02041440(m, (u8 *)res + 4, f);
}
static inline void *ST_NewModel(void *res, BOOL f) {
    void *m = func_0203dd9c(0x160);
    if (m != NULL) {
        ST_ModelCtor(m, res, f);
    }
    return m;
}
static inline void *ST_NewModel2(Unk0214a418 *p) {
    void *m = func_0203dd9c(0x160);
    if (m != NULL) {
        ST_ModelCtor(m, p->unk_10, p->unk_14 != NULL);
    }
    return m;
}
s32 func_02062ac8(Unk0214a418 *p, s32 argv) {
    SysTaskArg *arg = (SysTaskArg *)argv;
    u8 again;
    u32 size;
    if (!ST_IsReady(p)) {
        if (func_02063484(p)) {
            if (p->unk_0c == NULL) {
                void *o = func_0203dd9c(0xe8);
                if (o != NULL) {
                    o = func_ov000_0218fe1c(o);
                }
                p->unk_0c = o;
                func_ov000_0218ffdc(o, p->unk_08, 0, 1);
                ST_FLD(u16, p->unk_0c, 0xb4) = 0;
            }
            if (p->unk_14 == NULL) {
                void *res;
                void *m = func_0203dd9c(0x160);
                if (m != NULL) {
                    BOOL f;
                    res = p->unk_10;
                    f = p->unk_14 != NULL;
                    func_02041218((u8 *)m + 0x88);
                    func_02041440(m, (u8 *)res + 4, f);
                }
                p->unk_14 = m;
                func_020417e0(p->unk_14, ((SysTaskRes *)p->unk_10)->vf10());
                ST_FLD(u32, p->unk_14, 0x6c) |= 2;
                func_02041d9c(p->unk_14, 0, 0xffff);
            }
        }
        return arg->state;
    }
    arg->timer += 0x1000;
    size = data_020828f8[1];
    do {
        again = FALSE;
        switch (p->unk_00) {
        case 0:
            if (func_02054f10(p->unk_14, 0xffff)) {
                func_02041d8c(p->unk_14);
                func_ov000_02190cb0(p->unk_0c, data_0208c1a0, 0, 1);
                func_ov000_02191618(p->unk_0c);
                p->unk_00 = 1;
                again = TRUE;
            }
            break;
        case 1:
            if (arg->state == 1) {
                ST_Draw(p, size);
            }
            if (func_02063650(p)) {
                func_ov000_02190cb0(p->unk_0c, data_0208c1a4, 0, 1);
                func_ov000_021915a0(p->unk_0c);
                p->unk_00 = 2;
            }
            break;
        case 2:
            ST_Draw(p, size);
            func_02063650(p);
            func_ov000_02190cb0(p->unk_0c, data_0208c1a8, 0, 1);
            func_ov000_02191618(p->unk_0c);
            p->unk_00 = 3;
            break;
        case 3:
            if (arg->state == 3) {
                ST_Draw(p, size);
            }
            if (func_02063650(p)) {
                if (arg->state == 3) {
                    p->unk_00 = 4;
                    if (arg->timer >= arg->limit) {
                        arg->state = 4;
                    }
                } else {
                    p->unk_00 = 5;
                    again = TRUE;
                }
            }
            break;
        case 4:
            ST_Draw(p, size);
            if (arg->state == 1) {
                p->unk_00 = 0;
            } else if (arg->timer >= arg->limit) {
                arg->state = 4;
            }
            break;
        case 5:
            func_02063374(p);
            p->unk_00 = 0;
            arg->state = 0;
            break;
        }
    } while (again);
    return arg->state;
}

}
