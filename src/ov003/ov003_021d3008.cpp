#include "types.h"
#include "nitro/fx.h"

typedef struct {
    u16 state;
    u16 timer;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c[7];
    u8 kind;
} Ov003EnWork;

typedef struct {
    VecFx32 pos;
    s32 unk_0c;
    s32 unk_10;
    u8 unk_14[8];
    s32 unk_1c;
    u8 unk_20[2];
    u16 unk_22_0 : 4;
    u16 unk_22_4 : 1;
} Ov003EnSub44;

typedef struct {
    u8 unk_00;
    u8 unk_01[0x1b];
    u16 unk_1c;
} Ov003EnSub4c;

typedef struct {
    u8 unk_00[0x50];
    VecFx32 pos;
    s32 unk_5c;
} Ov003EnSub5c;

typedef struct {
    u8 unk_00[0xa];
    u16 unk_0a_0 : 5;
    u16 unk_0a_5 : 1;
    u16 unk_0a_6 : 1;
    u16 : 0;
    u16 unk_0c_0 : 5;
} Ov003EnParam;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x90 - 0xe];
    u16 unk_90;
    u8 unk_92[0xb90 - 0x92];
    VecFx32 unk_b90;
    s32 unk_b9c;
} Ov003EnPl;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003Game54;

typedef struct {
    u8 unk_00[0x5c];
    void *unk_5c;
    void *unk_60;
} Ov003Mgr11c;

typedef struct {
    u8 unk_00[0x11c];
    Ov003Mgr11c *unk_11c;
} Ov003Game30;

class Ov003EnFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void SetPos(const VecFx32 *pos);
    virtual void v1c();
    virtual void v20();
    virtual void SetScale(s32 x, s32 y, s32 z);
    u8 unk_04[0x18];
    s32 unk_1c;
    s32 unk_20;
};

class Ov003En {
public:
    void Update();

    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x20];
    u32 unk_30;
    u8 unk_34[0xc];
    Ov003EnWork *work;
    Ov003EnSub44 *unk_44;
    u8 unk_48[4];
    Ov003EnSub4c *unk_4c;
    u16 *unk_50;
    void *unk_54;
    u8 unk_58[4];
    Ov003EnSub5c *unk_5c;
    u8 unk_60[4];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    VecFx32 pos;
    u8 unk_7c[2];
    u16 unk_7e;
    u8 unk_80[0x14];
    u8 unk_94_0 : 1;
    u8 unk_94_1 : 2;
    u8 unk_95[0x1b];
    Ov003EnParam *unk_b0;
    u8 unk_b4[0x2c];
    void *unk_e0;
    void *unk_e4;
    u16 unk_e8;
    u16 unk_ea_0 : 6;
    u16 unk_ea_6 : 2;
    u16 unk_ea_8 : 5;
    u16 unk_ea_13 : 1;
    u8 unk_ec;
};

typedef void (Ov003En::*Ov003EnPmf)();

typedef struct {
    u32 kind;
    Ov003EnPmf fn;
} Ov003EnEntry;

extern "C" {

extern const Ov003EnEntry data_ov003_021f4750[];
extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003Game30 *data_ov000_021ccd30;
extern void *data_0214a420;
extern u8 *func_02070558(u16 id);
extern void func_ov000_0219a088(void *p);
extern void func_ov000_0219af3c(Ov003En *self, Ov003EnSub5c *icon);
extern void func_ov000_0219a210(VecFx32 *v, const VecFx32 *a, u16 rot);
extern void func_ov000_021bd624(Ov003EnSub5c *p);
extern void func_ov000_021697dc(void *p, u16 a, u16 b);
extern void func_ov000_0216912c(void *p, u16 id, s32 a, u16 b, u16 c, const VecFx32 *pos);
extern Ov003EnPl *func_ov000_0219bf90(void);
extern Ov003EnFx *func_020657b0(void *mgr, void *h);

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdleP(Ov003Game54 *g) {
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline void Ov003_Call5c(u16 a, u16 b) {
    Ov003Mgr11c *m = data_ov000_021ccd30->unk_11c;
    if (m != NULL && m->unk_5c != NULL) {
        func_ov000_021697dc(m->unk_5c, a, b);
    }
}

static inline void Ov003_Call60(u16 id, u16 a, u16 b, const VecFx32 *pos) {
    Ov003Mgr11c *m = data_ov000_021ccd30->unk_11c;
    if (m != NULL && m->unk_60 != NULL) {
        func_ov000_0216912c(m->unk_60, id, 0, a, b, pos);
    }
}

static inline void Dispatch(Ov003En *self, u32 kind) {
    s32 i;
    for (i = 0; i < 0x15; i++) {
        if (data_ov003_021f4750[i].kind != kind) {
            continue;
        }
        (self->*data_ov003_021f4750[i].fn)();
        return;
    }
}

void func_ov003_021d3008(Ov003En *self) {
    u16 *p50;
    u8 kind;
    s32 i;
    self->unk_ec = 0;
    switch (self->unk_b0->unk_0c_0) {
    case 1:
        self->unk_94_1 = 1;
        break;
    case 2:
        if (self->work->kind != 0x14) {
            self->unk_94_1 = 2;
        }
        break;
    case 5:
        self->unk_94_1 = 3;
        break;
    }
    Dispatch(self, self->work->kind);
    if (self->unk_e8 != 0 && *self->unk_50 != 0 && self->work->kind != 0x14) {
        self->unk_e8 = 0;
        self->unk_4c->unk_00 = *func_02070558(self->unk_0e);
    }
    if (self->unk_e8 != 0) {
        self->unk_94_0 = 1;
    }
    p50 = self->unk_50;
    if (p50 != NULL && p50[5] != 0) {
        p50[5]--;
    }
    func_ov000_0219a088(self->unk_54);
    if (self->unk_ea_13) {
        if (self->unk_5c != NULL && Ov003_GameIdleP(data_ov000_021ccd54)) {
            VecFx32 pos;
            s32 r;
            func_ov000_0219af3c(self, self->unk_5c);
            if (self->unk_44 != NULL) {
                pos = self->unk_44->pos;
                if (self->unk_44->unk_22_4) {
                    VecFx32 v;
                    v.z = self->unk_44->unk_1c;
                    v.x = 0;
                    v.y = 0;
                    func_ov000_0219a210(&pos, &v, self->unk_7e);
                }
                r = self->unk_44->unk_10;
                if (r == 0) {
                    r = self->unk_44->unk_1c;
                }
            } else {
                pos = self->pos;
                r = self->unk_68;
                if (r == 0) {
                    r = self->unk_64;
                }
            }
            if (self->work->kind == 0x13 || self->work->kind == 0x14 || self->unk_94_0) {
                r >>= 2;
            }
            self->unk_5c->pos = pos;
            self->unk_5c->unk_5c = r;
            func_ov000_021bd624(self->unk_5c);
        }
        if (self->unk_ea_6 != 1) {
            if (self->unk_b0->unk_0a_5) {
                Ov003_Call5c(self->unk_50[0], self->unk_50[1]);
            } else {
                BOOL b = FALSE;
                if (self->unk_ea_6 == 2) {
                    b = TRUE;
                } else if (self->work->kind != 9) {
                    Ov003EnPl *pl;
                    if (self->unk_4c != NULL && (self->unk_30 & 0x200)) {
                        b = TRUE;
                    }
                    pl = func_ov000_0219bf90();
                    if (pl != NULL && (pl->unk_90 == self->unk_0c || self->unk_4c->unk_1c == pl->unk_0c)) {
                        b = TRUE;
                    }
                }
                if (b) {
                    Ov003_Call60(self->unk_0c, self->unk_50[0], self->unk_50[1], &self->pos);
                }
            }
        }
    }
    if (self->unk_e4 != NULL) {
        Ov003EnFx *fx = func_020657b0(data_0214a420, self->unk_e4);
        if (fx != NULL) {
            if (self->unk_e8 == 0 || (self->work->kind != 0x14 && self->work->kind != 0xb && self->work->kind != 4)) {
                fx->unk_1c = 4;
                self->unk_e4 = NULL;
            } else {
                s32 s;
                fx->SetPos(&self->pos);
                s = self->unk_68;
                switch (fx->unk_20) {
                default:
                    s -= (s >> 1) + (s >> 3);
                    break;
                case 0x385:
                case 0x387:
                    s >>= 3;
                    break;
                case 0x386:
                case 0x388:
                    break;
                }
                fx->SetScale(0, s, 0);
            }
        } else {
            self->unk_e4 = NULL;
        }
    }
    if (self->unk_e0 != NULL) {
        Ov003EnFx *fx = func_020657b0(data_0214a420, self->unk_e0);
        if (fx == NULL) {
            self->unk_e0 = NULL;
        } else {
            fx->SetPos(&self->pos);
            fx->SetScale(0, self->unk_6c, 0);
        }
    }
    if (self->unk_b0->unk_0a_6) {
        Ov003EnPl *pl = func_ov000_0219bf90();
        if (pl != NULL) {
            pl->unk_b90 = self->pos;
            pl->unk_b9c = 0x4b8;
        }
    }
    {
        Ov003EnWork *w = self->work;
        w->unk_04 = 0;
        w->unk_08 = 0;
    }
}

}
